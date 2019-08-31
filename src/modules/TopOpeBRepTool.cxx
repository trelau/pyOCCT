/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC
Copyright (C) 2019 Trevor Laughlin and the pyOCCT contributors

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/
#include <pyOCCT_Common.hxx>
#include <TopOpeBRepTool_OutCurveType.hxx>
#include <TopExp_Explorer.hxx>
#include <TopoDS_Shape.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_OStream.hxx>
#include <TopAbs.hxx>
#include <TopOpeBRepTool_ShapeExplorer.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <TopOpeBRepTool_HBoxTool.hxx>
#include <Bnd_HArray1OfBox.hxx>
#include <Bnd_Box.hxx>
#include <TColStd_ListOfInteger.hxx>
#include <Bnd_BoundSortBox.hxx>
#include <TColStd_HArray1OfInteger.hxx>
#include <TopOpeBRepTool_BoxSort.hxx>
#include <TopOpeBRepTool_ShapeClassifier.hxx>
#include <TopOpeBRepTool_PShapeClassifier.hxx>
#include <TopOpeBRepTool_GeomTool.hxx>
#include <Geom_Curve.hxx>
#include <Geom2d_Curve.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <TopOpeBRepTool_CurveTool.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TopOpeBRepTool_Plos.hxx>
#include <BRepClass3d_SolidClassifier.hxx>
#include <TopOpeBRepTool_PSoClassif.hxx>
#include <TopoDS_Solid.hxx>
#include <TopAbs_State.hxx>
#include <gp_Pnt.hxx>
#include <TopoDS_Shell.hxx>
#include <TopTools_IndexedDataMapOfShapeAddress.hxx>
#include <BRep_Builder.hxx>
#include <TopOpeBRepTool_SolidClassifier.hxx>
#include <gp_Pnt2d.hxx>
#include <TopTools_IndexedMapOfShape.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Face.hxx>
#include <TopTools_DataMapOfShapeInteger.hxx>
#include <TopTools_IndexedMapOfOrientedShape.hxx>
#include <TopTools_DataMapOfShapeListOfShape.hxx>
#include <TopOpeBRepTool_AncestorsTool.hxx>
#include <TopOpeBRepTool_C2DF.hxx>
#include <TopOpeBRepTool_ShapeTool.hxx>
#include <TopOpeBRepTool_connexity.hxx>
#include <TopOpeBRepTool_face.hxx>
#include <TopOpeBRepTool_CLASSI.hxx>
#include <TopOpeBRepTool_TOOL.hxx>
#include <TopOpeBRepTool_CORRISO.hxx>
#include <TopOpeBRepTool_REGUW.hxx>
#include <TopOpeBRepTool_REGUS.hxx>
#include <TopOpeBRepTool_makeTransition.hxx>
#include <TopOpeBRepTool_mkTondgE.hxx>
#include <TopOpeBRepTool_PurgeInternalEdges.hxx>
#include <TopOpeBRepTool_FuseEdges.hxx>
#include <TopOpeBRepTool.hxx>
#include <TopTools_IndexedDataMapOfShapeListOfShape.hxx>
#include <NCollection_IndexedDataMap.hxx>
#include <TopTools_OrientedShapeMapHasher.hxx>
#include <TopOpeBRepTool_IndexedDataMapOfShapeBox.hxx>
#include <Standard_Transient.hxx>
#include <Standard_Type.hxx>
#include <Bnd_Box2d.hxx>
#include <TopOpeBRepTool_IndexedDataMapOfShapeBox2d.hxx>
#include <TopoDS_Wire.hxx>
#include <NCollection_DataMap.hxx>
#include <TopTools_ShapeMapHasher.hxx>
#include <TopOpeBRepTool_DataMapOfShapeface.hxx>
#include <TopTools_Array1OfListOfShape.hxx>
#include <TopOpeBRepTool_DataMapOfOrientedShapeC2DF.hxx>
#include <GeomAdaptor_Surface.hxx>
#include <TopTools_DataMapOfOrientedShapeInteger.hxx>
#include <TopoDS_Vertex.hxx>
#include <NCollection_List.hxx>
#include <TopOpeBRepTool_ListOfC2DF.hxx>
#include <TopOpeBRepTool_DataMapOfShapeListOfC2DF.hxx>
#include <TopTools_DataMapOfIntegerListOfShape.hxx>
#include <TopTools_DataMapOfIntegerShape.hxx>
#include <TopTools_DataMapOfShapeShape.hxx>
#include <TopTools_MapOfShape.hxx>
#include <TopOpeBRepTool_IndexedDataMapOfShapeconnexity.hxx>
#include <TopOpeBRepTool_IndexedDataMapOfSolidClassifier.hxx>
#include <gp_Dir.hxx>
#include <TopTools_DataMapOfShapeReal.hxx>
#include <gp_Dir2d.hxx>
#include <Geom_Surface.hxx>
#include <BRepAdaptor_Surface.hxx>
#include <BRepAdaptor_Curve.hxx>
#include <TopTools_Array1OfShape.hxx>
#include <gp_Vec.hxx>
#include <gp_Vec2d.hxx>
#include <bind_NCollection_IndexedDataMap.hxx>
#include <bind_NCollection_DataMap.hxx>
#include <bind_NCollection_List.hxx>
#include <bind_NCollection_TListIterator.hxx>

PYBIND11_MODULE(TopOpeBRepTool, mod) {

py::module::import("OCCT.TopExp");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.TopAbs");
py::module::import("OCCT.Standard");
py::module::import("OCCT.Bnd");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.Geom");
py::module::import("OCCT.Geom2d");
py::module::import("OCCT.TColgp");
py::module::import("OCCT.TopTools");
py::module::import("OCCT.BRepClass3d");
py::module::import("OCCT.gp");
py::module::import("OCCT.BRep");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.GeomAdaptor");
py::module::import("OCCT.BRepAdaptor");

// ENUM: TOPOPEBREPTOOL_OUTCURVETYPE
py::enum_<TopOpeBRepTool_OutCurveType>(mod, "TopOpeBRepTool_OutCurveType", "None")
	.value("TopOpeBRepTool_BSPLINE1", TopOpeBRepTool_OutCurveType::TopOpeBRepTool_BSPLINE1)
	.value("TopOpeBRepTool_APPROX", TopOpeBRepTool_OutCurveType::TopOpeBRepTool_APPROX)
	.value("TopOpeBRepTool_INTERPOL", TopOpeBRepTool_OutCurveType::TopOpeBRepTool_INTERPOL)
	.export_values();


// CLASS: TOPOPEBREPTOOL_SHAPEEXPLORER
py::class_<TopOpeBRepTool_ShapeExplorer, TopExp_Explorer> cls_TopOpeBRepTool_ShapeExplorer(mod, "TopOpeBRepTool_ShapeExplorer", "Extends TopExp_Explorer by counting index of current item (for tracing and debug)");

// Constructors
cls_TopOpeBRepTool_ShapeExplorer.def(py::init<>());
cls_TopOpeBRepTool_ShapeExplorer.def(py::init<const TopoDS_Shape &, const TopAbs_ShapeEnum>(), py::arg("S"), py::arg("ToFind"));
cls_TopOpeBRepTool_ShapeExplorer.def(py::init<const TopoDS_Shape &, const TopAbs_ShapeEnum, const TopAbs_ShapeEnum>(), py::arg("S"), py::arg("ToFind"), py::arg("ToAvoid"));

// Methods
cls_TopOpeBRepTool_ShapeExplorer.def("Init", [](TopOpeBRepTool_ShapeExplorer &self, const TopoDS_Shape & a0, const TopAbs_ShapeEnum a1) -> void { return self.Init(a0, a1); });
cls_TopOpeBRepTool_ShapeExplorer.def("Init", (void (TopOpeBRepTool_ShapeExplorer::*)(const TopoDS_Shape &, const TopAbs_ShapeEnum, const TopAbs_ShapeEnum)) &TopOpeBRepTool_ShapeExplorer::Init, "None", py::arg("S"), py::arg("ToFind"), py::arg("ToAvoid"));
cls_TopOpeBRepTool_ShapeExplorer.def("Next", (void (TopOpeBRepTool_ShapeExplorer::*)()) &TopOpeBRepTool_ShapeExplorer::Next, "Moves to the next Shape in the exploration.");
cls_TopOpeBRepTool_ShapeExplorer.def("Index", (Standard_Integer (TopOpeBRepTool_ShapeExplorer::*)() const) &TopOpeBRepTool_ShapeExplorer::Index, "Index of current sub-shape");
cls_TopOpeBRepTool_ShapeExplorer.def("DumpCurrent", (Standard_OStream & (TopOpeBRepTool_ShapeExplorer::*)(Standard_OStream &) const) &TopOpeBRepTool_ShapeExplorer::DumpCurrent, "Dump info on current shape to stream", py::arg("OS"));

// CLASS: TOPOPEBREPTOOL_BOXSORT
py::class_<TopOpeBRepTool_BoxSort> cls_TopOpeBRepTool_BoxSort(mod, "TopOpeBRepTool_BoxSort", "None");

// Constructors
cls_TopOpeBRepTool_BoxSort.def(py::init<>());
cls_TopOpeBRepTool_BoxSort.def(py::init<const opencascade::handle<TopOpeBRepTool_HBoxTool> &>(), py::arg("T"));

// Methods
// cls_TopOpeBRepTool_BoxSort.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepTool_BoxSort::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepTool_BoxSort.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepTool_BoxSort::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepTool_BoxSort.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepTool_BoxSort::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepTool_BoxSort.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepTool_BoxSort::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepTool_BoxSort.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepTool_BoxSort::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepTool_BoxSort.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepTool_BoxSort::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepTool_BoxSort.def("SetHBoxTool", (void (TopOpeBRepTool_BoxSort::*)(const opencascade::handle<TopOpeBRepTool_HBoxTool> &)) &TopOpeBRepTool_BoxSort::SetHBoxTool, "None", py::arg("T"));
cls_TopOpeBRepTool_BoxSort.def("HBoxTool", (const opencascade::handle<TopOpeBRepTool_HBoxTool> & (TopOpeBRepTool_BoxSort::*)() const) &TopOpeBRepTool_BoxSort::HBoxTool, "None");
cls_TopOpeBRepTool_BoxSort.def("Clear", (void (TopOpeBRepTool_BoxSort::*)()) &TopOpeBRepTool_BoxSort::Clear, "None");
cls_TopOpeBRepTool_BoxSort.def("AddBoxes", [](TopOpeBRepTool_BoxSort &self, const TopoDS_Shape & a0, const TopAbs_ShapeEnum a1) -> void { return self.AddBoxes(a0, a1); });
cls_TopOpeBRepTool_BoxSort.def("AddBoxes", (void (TopOpeBRepTool_BoxSort::*)(const TopoDS_Shape &, const TopAbs_ShapeEnum, const TopAbs_ShapeEnum)) &TopOpeBRepTool_BoxSort::AddBoxes, "None", py::arg("S"), py::arg("TS"), py::arg("TA"));
cls_TopOpeBRepTool_BoxSort.def("MakeHAB", [](TopOpeBRepTool_BoxSort &self, const TopoDS_Shape & a0, const TopAbs_ShapeEnum a1) -> void { return self.MakeHAB(a0, a1); });
cls_TopOpeBRepTool_BoxSort.def("MakeHAB", (void (TopOpeBRepTool_BoxSort::*)(const TopoDS_Shape &, const TopAbs_ShapeEnum, const TopAbs_ShapeEnum)) &TopOpeBRepTool_BoxSort::MakeHAB, "None", py::arg("S"), py::arg("TS"), py::arg("TA"));
cls_TopOpeBRepTool_BoxSort.def("HAB", (const opencascade::handle<Bnd_HArray1OfBox> & (TopOpeBRepTool_BoxSort::*)() const) &TopOpeBRepTool_BoxSort::HAB, "None");
cls_TopOpeBRepTool_BoxSort.def_static("MakeHABCOB_", (void (*)(const opencascade::handle<Bnd_HArray1OfBox> &, Bnd_Box &)) &TopOpeBRepTool_BoxSort::MakeHABCOB, "None", py::arg("HAB"), py::arg("COB"));
cls_TopOpeBRepTool_BoxSort.def("HABShape", (const TopoDS_Shape & (TopOpeBRepTool_BoxSort::*)(const Standard_Integer) const) &TopOpeBRepTool_BoxSort::HABShape, "None", py::arg("I"));
cls_TopOpeBRepTool_BoxSort.def("MakeCOB", [](TopOpeBRepTool_BoxSort &self, const TopoDS_Shape & a0, const TopAbs_ShapeEnum a1) -> void { return self.MakeCOB(a0, a1); });
cls_TopOpeBRepTool_BoxSort.def("MakeCOB", (void (TopOpeBRepTool_BoxSort::*)(const TopoDS_Shape &, const TopAbs_ShapeEnum, const TopAbs_ShapeEnum)) &TopOpeBRepTool_BoxSort::MakeCOB, "None", py::arg("S"), py::arg("TS"), py::arg("TA"));
cls_TopOpeBRepTool_BoxSort.def("AddBoxesMakeCOB", [](TopOpeBRepTool_BoxSort &self, const TopoDS_Shape & a0, const TopAbs_ShapeEnum a1) -> void { return self.AddBoxesMakeCOB(a0, a1); });
cls_TopOpeBRepTool_BoxSort.def("AddBoxesMakeCOB", (void (TopOpeBRepTool_BoxSort::*)(const TopoDS_Shape &, const TopAbs_ShapeEnum, const TopAbs_ShapeEnum)) &TopOpeBRepTool_BoxSort::AddBoxesMakeCOB, "None", py::arg("S"), py::arg("TS"), py::arg("TA"));
cls_TopOpeBRepTool_BoxSort.def("Compare", (const TColStd_ListIteratorOfListOfInteger & (TopOpeBRepTool_BoxSort::*)(const TopoDS_Shape &)) &TopOpeBRepTool_BoxSort::Compare, "None", py::arg("S"));
cls_TopOpeBRepTool_BoxSort.def("TouchedShape", (const TopoDS_Shape & (TopOpeBRepTool_BoxSort::*)(const TColStd_ListIteratorOfListOfInteger &) const) &TopOpeBRepTool_BoxSort::TouchedShape, "None", py::arg("I"));
cls_TopOpeBRepTool_BoxSort.def("Box", (const Bnd_Box & (TopOpeBRepTool_BoxSort::*)(const TopoDS_Shape &) const) &TopOpeBRepTool_BoxSort::Box, "None", py::arg("S"));

// TYPEDEF: TOPOPEBREPTOOL_PSHAPECLASSIFIER

// CLASS: TOPOPEBREPTOOL_GEOMTOOL
py::class_<TopOpeBRepTool_GeomTool> cls_TopOpeBRepTool_GeomTool(mod, "TopOpeBRepTool_GeomTool", "None");

// Constructors
cls_TopOpeBRepTool_GeomTool.def(py::init<>());
cls_TopOpeBRepTool_GeomTool.def(py::init<const TopOpeBRepTool_OutCurveType>(), py::arg("TypeC3D"));
cls_TopOpeBRepTool_GeomTool.def(py::init<const TopOpeBRepTool_OutCurveType, const Standard_Boolean>(), py::arg("TypeC3D"), py::arg("CompC3D"));
cls_TopOpeBRepTool_GeomTool.def(py::init<const TopOpeBRepTool_OutCurveType, const Standard_Boolean, const Standard_Boolean>(), py::arg("TypeC3D"), py::arg("CompC3D"), py::arg("CompPC1"));
cls_TopOpeBRepTool_GeomTool.def(py::init<const TopOpeBRepTool_OutCurveType, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean>(), py::arg("TypeC3D"), py::arg("CompC3D"), py::arg("CompPC1"), py::arg("CompPC2"));

// Methods
// cls_TopOpeBRepTool_GeomTool.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepTool_GeomTool::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepTool_GeomTool.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepTool_GeomTool::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepTool_GeomTool.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepTool_GeomTool::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepTool_GeomTool.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepTool_GeomTool::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepTool_GeomTool.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepTool_GeomTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepTool_GeomTool.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepTool_GeomTool::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepTool_GeomTool.def("Define", (void (TopOpeBRepTool_GeomTool::*)(const TopOpeBRepTool_OutCurveType, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean)) &TopOpeBRepTool_GeomTool::Define, "None", py::arg("TypeC3D"), py::arg("CompC3D"), py::arg("CompPC1"), py::arg("CompPC2"));
cls_TopOpeBRepTool_GeomTool.def("Define", (void (TopOpeBRepTool_GeomTool::*)(const TopOpeBRepTool_OutCurveType)) &TopOpeBRepTool_GeomTool::Define, "None", py::arg("TypeC3D"));
cls_TopOpeBRepTool_GeomTool.def("DefineCurves", (void (TopOpeBRepTool_GeomTool::*)(const Standard_Boolean)) &TopOpeBRepTool_GeomTool::DefineCurves, "None", py::arg("CompC3D"));
cls_TopOpeBRepTool_GeomTool.def("DefinePCurves1", (void (TopOpeBRepTool_GeomTool::*)(const Standard_Boolean)) &TopOpeBRepTool_GeomTool::DefinePCurves1, "None", py::arg("CompPC1"));
cls_TopOpeBRepTool_GeomTool.def("DefinePCurves2", (void (TopOpeBRepTool_GeomTool::*)(const Standard_Boolean)) &TopOpeBRepTool_GeomTool::DefinePCurves2, "None", py::arg("CompPC2"));
cls_TopOpeBRepTool_GeomTool.def("Define", (void (TopOpeBRepTool_GeomTool::*)(const TopOpeBRepTool_GeomTool &)) &TopOpeBRepTool_GeomTool::Define, "None", py::arg("GT"));
cls_TopOpeBRepTool_GeomTool.def("GetTolerances", [](TopOpeBRepTool_GeomTool &self, Standard_Real & tol3d, Standard_Real & tol2d){ self.GetTolerances(tol3d, tol2d); return std::tuple<Standard_Real &, Standard_Real &>(tol3d, tol2d); }, "None", py::arg("tol3d"), py::arg("tol2d"));
cls_TopOpeBRepTool_GeomTool.def("SetTolerances", (void (TopOpeBRepTool_GeomTool::*)(const Standard_Real, const Standard_Real)) &TopOpeBRepTool_GeomTool::SetTolerances, "None", py::arg("tol3d"), py::arg("tol2d"));
cls_TopOpeBRepTool_GeomTool.def("NbPntMax", (Standard_Integer (TopOpeBRepTool_GeomTool::*)() const) &TopOpeBRepTool_GeomTool::NbPntMax, "None");
cls_TopOpeBRepTool_GeomTool.def("SetNbPntMax", (void (TopOpeBRepTool_GeomTool::*)(const Standard_Integer)) &TopOpeBRepTool_GeomTool::SetNbPntMax, "None", py::arg("NbPntMax"));
cls_TopOpeBRepTool_GeomTool.def("TypeC3D", (TopOpeBRepTool_OutCurveType (TopOpeBRepTool_GeomTool::*)() const) &TopOpeBRepTool_GeomTool::TypeC3D, "None");
cls_TopOpeBRepTool_GeomTool.def("CompC3D", (Standard_Boolean (TopOpeBRepTool_GeomTool::*)() const) &TopOpeBRepTool_GeomTool::CompC3D, "None");
cls_TopOpeBRepTool_GeomTool.def("CompPC1", (Standard_Boolean (TopOpeBRepTool_GeomTool::*)() const) &TopOpeBRepTool_GeomTool::CompPC1, "None");
cls_TopOpeBRepTool_GeomTool.def("CompPC2", (Standard_Boolean (TopOpeBRepTool_GeomTool::*)() const) &TopOpeBRepTool_GeomTool::CompPC2, "None");

// CLASS: TOPOPEBREPTOOL_CURVETOOL
py::class_<TopOpeBRepTool_CurveTool> cls_TopOpeBRepTool_CurveTool(mod, "TopOpeBRepTool_CurveTool", "None");

// Constructors
cls_TopOpeBRepTool_CurveTool.def(py::init<>());
cls_TopOpeBRepTool_CurveTool.def(py::init<const TopOpeBRepTool_OutCurveType>(), py::arg("OCT"));
cls_TopOpeBRepTool_CurveTool.def(py::init<const TopOpeBRepTool_GeomTool &>(), py::arg("GT"));

// Methods
// cls_TopOpeBRepTool_CurveTool.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepTool_CurveTool::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepTool_CurveTool.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepTool_CurveTool::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepTool_CurveTool.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepTool_CurveTool::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepTool_CurveTool.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepTool_CurveTool::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepTool_CurveTool.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepTool_CurveTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepTool_CurveTool.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepTool_CurveTool::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepTool_CurveTool.def("ChangeGeomTool", (TopOpeBRepTool_GeomTool & (TopOpeBRepTool_CurveTool::*)()) &TopOpeBRepTool_CurveTool::ChangeGeomTool, "None");
cls_TopOpeBRepTool_CurveTool.def("GetGeomTool", (const TopOpeBRepTool_GeomTool & (TopOpeBRepTool_CurveTool::*)() const) &TopOpeBRepTool_CurveTool::GetGeomTool, "None");
cls_TopOpeBRepTool_CurveTool.def("SetGeomTool", (void (TopOpeBRepTool_CurveTool::*)(const TopOpeBRepTool_GeomTool &)) &TopOpeBRepTool_CurveTool::SetGeomTool, "None", py::arg("GT"));
cls_TopOpeBRepTool_CurveTool.def("MakeCurves", [](TopOpeBRepTool_CurveTool &self, const Standard_Real min, const Standard_Real max, const opencascade::handle<Geom_Curve> & C3D, const opencascade::handle<Geom2d_Curve> & PC1, const opencascade::handle<Geom2d_Curve> & PC2, const TopoDS_Shape & S1, const TopoDS_Shape & S2, opencascade::handle<Geom_Curve> & C3DN, opencascade::handle<Geom2d_Curve> & PC1N, opencascade::handle<Geom2d_Curve> & PC2N, Standard_Real & Tol3d, Standard_Real & Tol2d){ Standard_Boolean rv = self.MakeCurves(min, max, C3D, PC1, PC2, S1, S2, C3DN, PC1N, PC2N, Tol3d, Tol2d); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, Tol3d, Tol2d); }, "Approximates curves. Returns False in the case of failure", py::arg("min"), py::arg("max"), py::arg("C3D"), py::arg("PC1"), py::arg("PC2"), py::arg("S1"), py::arg("S2"), py::arg("C3DN"), py::arg("PC1N"), py::arg("PC2N"), py::arg("Tol3d"), py::arg("Tol2d"));
cls_TopOpeBRepTool_CurveTool.def_static("MakeBSpline1fromPnt_", (opencascade::handle<Geom_Curve> (*)(const TColgp_Array1OfPnt &)) &TopOpeBRepTool_CurveTool::MakeBSpline1fromPnt, "None", py::arg("P"));
cls_TopOpeBRepTool_CurveTool.def_static("MakeBSpline1fromPnt2d_", (opencascade::handle<Geom2d_Curve> (*)(const TColgp_Array1OfPnt2d &)) &TopOpeBRepTool_CurveTool::MakeBSpline1fromPnt2d, "None", py::arg("P"));
cls_TopOpeBRepTool_CurveTool.def_static("IsProjectable_", (Standard_Boolean (*)(const TopoDS_Shape &, const opencascade::handle<Geom_Curve> &)) &TopOpeBRepTool_CurveTool::IsProjectable, "None", py::arg("S"), py::arg("C"));
cls_TopOpeBRepTool_CurveTool.def_static("MakePCurveOnFace_", [](const TopoDS_Shape & S, const opencascade::handle<Geom_Curve> & C, Standard_Real & TolReached2d, const Standard_Real first, const Standard_Real last){ opencascade::handle<Geom2d_Curve> rv = TopOpeBRepTool_CurveTool::MakePCurveOnFace(S, C, TolReached2d, first, last); return std::tuple<opencascade::handle<Geom2d_Curve>, Standard_Real &>(rv, TolReached2d); }, "None", py::arg("S"), py::arg("C"), py::arg("TolReached2d"), py::arg("first"), py::arg("last"));

// TYPEDEF: TOPOPEBREPTOOL_PLOS

// TYPEDEF: TOPOPEBREPTOOL_PSOCLASSIF

// CLASS: TOPOPEBREPTOOL_SOLIDCLASSIFIER
py::class_<TopOpeBRepTool_SolidClassifier> cls_TopOpeBRepTool_SolidClassifier(mod, "TopOpeBRepTool_SolidClassifier", "None");

// Constructors
cls_TopOpeBRepTool_SolidClassifier.def(py::init<>());

// Methods
// cls_TopOpeBRepTool_SolidClassifier.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepTool_SolidClassifier::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepTool_SolidClassifier.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepTool_SolidClassifier::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepTool_SolidClassifier.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepTool_SolidClassifier::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepTool_SolidClassifier.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepTool_SolidClassifier::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepTool_SolidClassifier.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepTool_SolidClassifier::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepTool_SolidClassifier.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepTool_SolidClassifier::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepTool_SolidClassifier.def("Clear", (void (TopOpeBRepTool_SolidClassifier::*)()) &TopOpeBRepTool_SolidClassifier::Clear, "None");
cls_TopOpeBRepTool_SolidClassifier.def("LoadSolid", (void (TopOpeBRepTool_SolidClassifier::*)(const TopoDS_Solid &)) &TopOpeBRepTool_SolidClassifier::LoadSolid, "None", py::arg("S"));
cls_TopOpeBRepTool_SolidClassifier.def("Classify", (TopAbs_State (TopOpeBRepTool_SolidClassifier::*)(const TopoDS_Solid &, const gp_Pnt &, const Standard_Real)) &TopOpeBRepTool_SolidClassifier::Classify, "compute the position of point <P> regarding with the geometric domain of the solid <S>.", py::arg("S"), py::arg("P"), py::arg("Tol"));
cls_TopOpeBRepTool_SolidClassifier.def("LoadShell", (void (TopOpeBRepTool_SolidClassifier::*)(const TopoDS_Shell &)) &TopOpeBRepTool_SolidClassifier::LoadShell, "None", py::arg("S"));
cls_TopOpeBRepTool_SolidClassifier.def("Classify", (TopAbs_State (TopOpeBRepTool_SolidClassifier::*)(const TopoDS_Shell &, const gp_Pnt &, const Standard_Real)) &TopOpeBRepTool_SolidClassifier::Classify, "compute the position of point <P> regarding with the geometric domain of the shell <S>.", py::arg("S"), py::arg("P"), py::arg("Tol"));
cls_TopOpeBRepTool_SolidClassifier.def("State", (TopAbs_State (TopOpeBRepTool_SolidClassifier::*)() const) &TopOpeBRepTool_SolidClassifier::State, "None");

// CLASS: TOPOPEBREPTOOL_SHAPECLASSIFIER
py::class_<TopOpeBRepTool_ShapeClassifier> cls_TopOpeBRepTool_ShapeClassifier(mod, "TopOpeBRepTool_ShapeClassifier", "None");

// Constructors
cls_TopOpeBRepTool_ShapeClassifier.def(py::init<>());
cls_TopOpeBRepTool_ShapeClassifier.def(py::init<const TopoDS_Shape &>(), py::arg("SRef"));

// Methods
// cls_TopOpeBRepTool_ShapeClassifier.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepTool_ShapeClassifier::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepTool_ShapeClassifier.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepTool_ShapeClassifier::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepTool_ShapeClassifier.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepTool_ShapeClassifier::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepTool_ShapeClassifier.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepTool_ShapeClassifier::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepTool_ShapeClassifier.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepTool_ShapeClassifier::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepTool_ShapeClassifier.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepTool_ShapeClassifier::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepTool_ShapeClassifier.def("ClearAll", (void (TopOpeBRepTool_ShapeClassifier::*)()) &TopOpeBRepTool_ShapeClassifier::ClearAll, "reset all internal data (SolidClassifier included)");
cls_TopOpeBRepTool_ShapeClassifier.def("ClearCurrent", (void (TopOpeBRepTool_ShapeClassifier::*)()) &TopOpeBRepTool_ShapeClassifier::ClearCurrent, "reset all internal data (except SolidClassified)");
cls_TopOpeBRepTool_ShapeClassifier.def("SetReference", (void (TopOpeBRepTool_ShapeClassifier::*)(const TopoDS_Shape &)) &TopOpeBRepTool_ShapeClassifier::SetReference, "Set SRef as reference shape the next StateShapeReference(S,AvoidS) calls will classify S with SRef.", py::arg("SRef"));
cls_TopOpeBRepTool_ShapeClassifier.def("StateShapeShape", [](TopOpeBRepTool_ShapeClassifier &self, const TopoDS_Shape & a0, const TopoDS_Shape & a1) -> TopAbs_State { return self.StateShapeShape(a0, a1); });
cls_TopOpeBRepTool_ShapeClassifier.def("StateShapeShape", (TopAbs_State (TopOpeBRepTool_ShapeClassifier::*)(const TopoDS_Shape &, const TopoDS_Shape &, const Standard_Integer)) &TopOpeBRepTool_ShapeClassifier::StateShapeShape, "classify shape S compared with shape SRef. samedomain = 0 : S1,S2 are not same domain samedomain = 1 : S1,S2 are same domain", py::arg("S"), py::arg("SRef"), py::arg("samedomain"));
cls_TopOpeBRepTool_ShapeClassifier.def("SameDomain", (Standard_Integer (TopOpeBRepTool_ShapeClassifier::*)() const) &TopOpeBRepTool_ShapeClassifier::SameDomain, "None");
cls_TopOpeBRepTool_ShapeClassifier.def("SameDomain", (void (TopOpeBRepTool_ShapeClassifier::*)(const Standard_Integer)) &TopOpeBRepTool_ShapeClassifier::SameDomain, "set mode for next StateShapeShape call samedomain = true --> S,Sref are same domain --> point on restriction (ON S) is used to classify S. samedomain = false --> S,Sref are not domain --> point not on restriction of S (IN S) is used to classify S. samedomain value is used only in next StateShapeShape call", py::arg("samedomain"));
cls_TopOpeBRepTool_ShapeClassifier.def("StateShapeShape", (TopAbs_State (TopOpeBRepTool_ShapeClassifier::*)(const TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Shape &)) &TopOpeBRepTool_ShapeClassifier::StateShapeShape, "classify shape S compared with shape SRef. AvoidS is not used in classification; AvoidS may be IsNull(). (usefull to avoid ON or UNKNOWN state in special cases)", py::arg("S"), py::arg("AvoidS"), py::arg("SRef"));
cls_TopOpeBRepTool_ShapeClassifier.def("StateShapeShape", (TopAbs_State (TopOpeBRepTool_ShapeClassifier::*)(const TopoDS_Shape &, const TopTools_ListOfShape &, const TopoDS_Shape &)) &TopOpeBRepTool_ShapeClassifier::StateShapeShape, "classify shape S compared with shape SRef. LAvoidS is list of S subshapes to avoid in classification AvoidS is not used in classification; AvoidS may be IsNull(). (usefull to avoid ON or UNKNOWN state in special cases)", py::arg("S"), py::arg("LAvoidS"), py::arg("SRef"));
cls_TopOpeBRepTool_ShapeClassifier.def("StateShapeReference", (TopAbs_State (TopOpeBRepTool_ShapeClassifier::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &TopOpeBRepTool_ShapeClassifier::StateShapeReference, "classify shape S compared with reference shape. AvoidS is not used in classification; AvoidS may be IsNull(). (usefull to avoid ON or UNKNOWN state in special cases)", py::arg("S"), py::arg("AvoidS"));
cls_TopOpeBRepTool_ShapeClassifier.def("StateShapeReference", (TopAbs_State (TopOpeBRepTool_ShapeClassifier::*)(const TopoDS_Shape &, const TopTools_ListOfShape &)) &TopOpeBRepTool_ShapeClassifier::StateShapeReference, "classify shape S compared with reference shape. LAvoidS is list of S subshapes to avoid in classification (usefull to avoid ON or UNKNOWN state in special cases)", py::arg("S"), py::arg("LAvoidS"));
cls_TopOpeBRepTool_ShapeClassifier.def("ChangeSolidClassifier", (TopOpeBRepTool_SolidClassifier & (TopOpeBRepTool_ShapeClassifier::*)()) &TopOpeBRepTool_ShapeClassifier::ChangeSolidClassifier, "None");
cls_TopOpeBRepTool_ShapeClassifier.def("StateP2DReference", (void (TopOpeBRepTool_ShapeClassifier::*)(const gp_Pnt2d &)) &TopOpeBRepTool_ShapeClassifier::StateP2DReference, "classify point P2D with myRef", py::arg("P2D"));
cls_TopOpeBRepTool_ShapeClassifier.def("StateP3DReference", (void (TopOpeBRepTool_ShapeClassifier::*)(const gp_Pnt &)) &TopOpeBRepTool_ShapeClassifier::StateP3DReference, "classify point P3D with myRef", py::arg("P3D"));
cls_TopOpeBRepTool_ShapeClassifier.def("State", (TopAbs_State (TopOpeBRepTool_ShapeClassifier::*)() const) &TopOpeBRepTool_ShapeClassifier::State, "return field myState");
cls_TopOpeBRepTool_ShapeClassifier.def("P2D", (const gp_Pnt2d & (TopOpeBRepTool_ShapeClassifier::*)() const) &TopOpeBRepTool_ShapeClassifier::P2D, "None");
cls_TopOpeBRepTool_ShapeClassifier.def("P3D", (const gp_Pnt & (TopOpeBRepTool_ShapeClassifier::*)() const) &TopOpeBRepTool_ShapeClassifier::P3D, "None");

// CLASS: TOPOPEBREPTOOL
py::class_<TopOpeBRepTool> cls_TopOpeBRepTool(mod, "TopOpeBRepTool", "This package provides services used by the TopOpeBRep package performing topological operations on the BRep data structure.");

// Methods
// cls_TopOpeBRepTool.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepTool::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepTool.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepTool::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepTool.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepTool::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepTool.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepTool::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepTool.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepTool.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepTool::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepTool.def_static("PurgeClosingEdges_", (Standard_Boolean (*)(const TopoDS_Face &, const TopoDS_Face &, const TopTools_DataMapOfShapeInteger &, TopTools_IndexedMapOfOrientedShape &)) &TopOpeBRepTool::PurgeClosingEdges, "Fuse edges (in a wire) of a shape where we have useless vertex. In case face <FF> is built on UV-non-connexed wires (with the two closing edges FORWARD and REVERSED, in spite of one only), we find out the faulty edge, add the faulty shapes (edge,wire,face) to <MshNOK>. <FF> is a face descendant of <F>. <MWisOld>(wire) = 1 if wire is wire of <F> 0 wire results from <F>'s wire splitted. returns false if purge fails", py::arg("F"), py::arg("FF"), py::arg("MWisOld"), py::arg("MshNOK"));
cls_TopOpeBRepTool.def_static("PurgeClosingEdges_", (Standard_Boolean (*)(const TopoDS_Face &, const TopTools_ListOfShape &, const TopTools_DataMapOfShapeInteger &, TopTools_IndexedMapOfOrientedShape &)) &TopOpeBRepTool::PurgeClosingEdges, "None", py::arg("F"), py::arg("LOF"), py::arg("MWisOld"), py::arg("MshNOK"));
cls_TopOpeBRepTool.def_static("CorrectONUVISO_", (Standard_Boolean (*)(const TopoDS_Face &, TopoDS_Face &)) &TopOpeBRepTool::CorrectONUVISO, "None", py::arg("F"), py::arg("Fsp"));
cls_TopOpeBRepTool.def_static("MakeFaces_", (Standard_Boolean (*)(const TopoDS_Face &, const TopTools_ListOfShape &, const TopTools_IndexedMapOfOrientedShape &, TopTools_ListOfShape &)) &TopOpeBRepTool::MakeFaces, "Builds up the correct list of faces <LOFF> from <LOF>, using faulty shapes from map <MshNOK>. <LOF> is the list of <F>'s descendant faces. returns false if building fails", py::arg("F"), py::arg("LOF"), py::arg("MshNOK"), py::arg("LOFF"));
cls_TopOpeBRepTool.def_static("Regularize_", (Standard_Boolean (*)(const TopoDS_Face &, TopTools_ListOfShape &, TopTools_DataMapOfShapeListOfShape &)) &TopOpeBRepTool::Regularize, "Returns <False> if the face is valid (the UV representation of the face is a set of pcurves connexed by points with connexity 2). Else, splits <aFace> in order to return a list of valid faces.", py::arg("aFace"), py::arg("aListOfFaces"), py::arg("ESplits"));
cls_TopOpeBRepTool.def_static("RegularizeWires_", (Standard_Boolean (*)(const TopoDS_Face &, TopTools_DataMapOfShapeListOfShape &, TopTools_DataMapOfShapeListOfShape &)) &TopOpeBRepTool::RegularizeWires, "Returns <False> if the face is valid (the UV representation of the face is a set of pcurves connexed by points with connexity 2). Else, splits wires of the face, these are boundaries of the new faces to build up; <OldWiresNewWires> describes (wire, splits of wire); <ESplits> describes (edge, edge's splits)", py::arg("aFace"), py::arg("OldWiresNewWires"), py::arg("ESplits"));
cls_TopOpeBRepTool.def_static("RegularizeFace_", (Standard_Boolean (*)(const TopoDS_Face &, const TopTools_DataMapOfShapeListOfShape &, TopTools_ListOfShape &)) &TopOpeBRepTool::RegularizeFace, "Classify wire's splits of map <OldWiresnewWires> in order to compute <aListOfFaces>, the splits of <aFace>.", py::arg("aFace"), py::arg("OldWiresnewWires"), py::arg("aListOfFaces"));
cls_TopOpeBRepTool.def_static("RegularizeShells_", (Standard_Boolean (*)(const TopoDS_Solid &, TopTools_DataMapOfShapeListOfShape &, TopTools_DataMapOfShapeListOfShape &)) &TopOpeBRepTool::RegularizeShells, "Returns <False> if the shell is valid (the solid is a set of faces connexed by edges with connexity 2). Else, splits faces of the shell; <OldFacesnewFaces> describes (face, splits of face).", py::arg("aSolid"), py::arg("OldSheNewShe"), py::arg("FSplits"));
cls_TopOpeBRepTool.def_static("Print_", (Standard_OStream & (*)(const TopOpeBRepTool_OutCurveType, Standard_OStream &)) &TopOpeBRepTool::Print, "Prints <OCT> as string on stream <S>; returns <S>.", py::arg("OCT"), py::arg("S"));

// CLASS: TOPOPEBREPTOOL_ANCESTORSTOOL
py::class_<TopOpeBRepTool_AncestorsTool> cls_TopOpeBRepTool_AncestorsTool(mod, "TopOpeBRepTool_AncestorsTool", "Describes the ancestors tool needed by the class DSFiller from TopOpeInter.");

// Methods
// cls_TopOpeBRepTool_AncestorsTool.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepTool_AncestorsTool::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepTool_AncestorsTool.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepTool_AncestorsTool::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepTool_AncestorsTool.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepTool_AncestorsTool::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepTool_AncestorsTool.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepTool_AncestorsTool::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepTool_AncestorsTool.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepTool_AncestorsTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepTool_AncestorsTool.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepTool_AncestorsTool::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepTool_AncestorsTool.def_static("MakeAncestors_", (void (*)(const TopoDS_Shape &, const TopAbs_ShapeEnum, const TopAbs_ShapeEnum, TopTools_IndexedDataMapOfShapeListOfShape &)) &TopOpeBRepTool_AncestorsTool::MakeAncestors, "same as package method TopExp::MapShapeListOfShapes()", py::arg("S"), py::arg("TS"), py::arg("TA"), py::arg("M"));

// TYPEDEF: TOPOPEBREPTOOL_INDEXEDDATAMAPOFSHAPEBOX
bind_NCollection_IndexedDataMap<TopoDS_Shape, Bnd_Box, TopTools_OrientedShapeMapHasher>(mod, "TopOpeBRepTool_IndexedDataMapOfShapeBox", py::module_local(false));

// CLASS: TOPOPEBREPTOOL_HBOXTOOL
py::class_<TopOpeBRepTool_HBoxTool, opencascade::handle<TopOpeBRepTool_HBoxTool>, Standard_Transient> cls_TopOpeBRepTool_HBoxTool(mod, "TopOpeBRepTool_HBoxTool", "None");

// Constructors
cls_TopOpeBRepTool_HBoxTool.def(py::init<>());

// Methods
cls_TopOpeBRepTool_HBoxTool.def("Clear", (void (TopOpeBRepTool_HBoxTool::*)()) &TopOpeBRepTool_HBoxTool::Clear, "None");
cls_TopOpeBRepTool_HBoxTool.def("AddBoxes", [](TopOpeBRepTool_HBoxTool &self, const TopoDS_Shape & a0, const TopAbs_ShapeEnum a1) -> void { return self.AddBoxes(a0, a1); });
cls_TopOpeBRepTool_HBoxTool.def("AddBoxes", (void (TopOpeBRepTool_HBoxTool::*)(const TopoDS_Shape &, const TopAbs_ShapeEnum, const TopAbs_ShapeEnum)) &TopOpeBRepTool_HBoxTool::AddBoxes, "None", py::arg("S"), py::arg("TS"), py::arg("TA"));
cls_TopOpeBRepTool_HBoxTool.def("AddBox", (void (TopOpeBRepTool_HBoxTool::*)(const TopoDS_Shape &)) &TopOpeBRepTool_HBoxTool::AddBox, "None", py::arg("S"));
cls_TopOpeBRepTool_HBoxTool.def_static("ComputeBox_", (void (*)(const TopoDS_Shape &, Bnd_Box &)) &TopOpeBRepTool_HBoxTool::ComputeBox, "None", py::arg("S"), py::arg("B"));
cls_TopOpeBRepTool_HBoxTool.def_static("ComputeBoxOnVertices_", (void (*)(const TopoDS_Shape &, Bnd_Box &)) &TopOpeBRepTool_HBoxTool::ComputeBoxOnVertices, "None", py::arg("S"), py::arg("B"));
cls_TopOpeBRepTool_HBoxTool.def_static("DumpB_", (void (*)(const Bnd_Box &)) &TopOpeBRepTool_HBoxTool::DumpB, "None", py::arg("B"));
cls_TopOpeBRepTool_HBoxTool.def("Box", (const Bnd_Box & (TopOpeBRepTool_HBoxTool::*)(const TopoDS_Shape &)) &TopOpeBRepTool_HBoxTool::Box, "None", py::arg("S"));
cls_TopOpeBRepTool_HBoxTool.def("Box", (const Bnd_Box & (TopOpeBRepTool_HBoxTool::*)(const Standard_Integer) const) &TopOpeBRepTool_HBoxTool::Box, "None", py::arg("I"));
cls_TopOpeBRepTool_HBoxTool.def("HasBox", (Standard_Boolean (TopOpeBRepTool_HBoxTool::*)(const TopoDS_Shape &) const) &TopOpeBRepTool_HBoxTool::HasBox, "None", py::arg("S"));
cls_TopOpeBRepTool_HBoxTool.def("Shape", (const TopoDS_Shape & (TopOpeBRepTool_HBoxTool::*)(const Standard_Integer) const) &TopOpeBRepTool_HBoxTool::Shape, "None", py::arg("I"));
cls_TopOpeBRepTool_HBoxTool.def("Index", (Standard_Integer (TopOpeBRepTool_HBoxTool::*)(const TopoDS_Shape &) const) &TopOpeBRepTool_HBoxTool::Index, "None", py::arg("S"));
cls_TopOpeBRepTool_HBoxTool.def("Extent", (Standard_Integer (TopOpeBRepTool_HBoxTool::*)() const) &TopOpeBRepTool_HBoxTool::Extent, "None");
cls_TopOpeBRepTool_HBoxTool.def("ChangeIMS", (TopOpeBRepTool_IndexedDataMapOfShapeBox & (TopOpeBRepTool_HBoxTool::*)()) &TopOpeBRepTool_HBoxTool::ChangeIMS, "None");
cls_TopOpeBRepTool_HBoxTool.def("IMS", (const TopOpeBRepTool_IndexedDataMapOfShapeBox & (TopOpeBRepTool_HBoxTool::*)() const) &TopOpeBRepTool_HBoxTool::IMS, "None");
cls_TopOpeBRepTool_HBoxTool.def_static("get_type_name_", (const char * (*)()) &TopOpeBRepTool_HBoxTool::get_type_name, "None");
cls_TopOpeBRepTool_HBoxTool.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TopOpeBRepTool_HBoxTool::get_type_descriptor, "None");
cls_TopOpeBRepTool_HBoxTool.def("DynamicType", (const opencascade::handle<Standard_Type> & (TopOpeBRepTool_HBoxTool::*)() const) &TopOpeBRepTool_HBoxTool::DynamicType, "None");

// CLASS: TOPOPEBREPTOOL_C2DF
py::class_<TopOpeBRepTool_C2DF> cls_TopOpeBRepTool_C2DF(mod, "TopOpeBRepTool_C2DF", "None");

// Constructors
cls_TopOpeBRepTool_C2DF.def(py::init<>());
cls_TopOpeBRepTool_C2DF.def(py::init<const opencascade::handle<Geom2d_Curve> &, const Standard_Real, const Standard_Real, const Standard_Real, const TopoDS_Face &>(), py::arg("PC"), py::arg("f2d"), py::arg("l2d"), py::arg("tol"), py::arg("F"));

// Methods
// cls_TopOpeBRepTool_C2DF.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepTool_C2DF::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepTool_C2DF.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepTool_C2DF::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepTool_C2DF.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepTool_C2DF::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepTool_C2DF.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepTool_C2DF::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepTool_C2DF.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepTool_C2DF::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepTool_C2DF.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepTool_C2DF::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepTool_C2DF.def("SetPC", (void (TopOpeBRepTool_C2DF::*)(const opencascade::handle<Geom2d_Curve> &, const Standard_Real, const Standard_Real, const Standard_Real)) &TopOpeBRepTool_C2DF::SetPC, "None", py::arg("PC"), py::arg("f2d"), py::arg("l2d"), py::arg("tol"));
cls_TopOpeBRepTool_C2DF.def("SetFace", (void (TopOpeBRepTool_C2DF::*)(const TopoDS_Face &)) &TopOpeBRepTool_C2DF::SetFace, "None", py::arg("F"));
cls_TopOpeBRepTool_C2DF.def("PC", [](TopOpeBRepTool_C2DF &self, Standard_Real & f2d, Standard_Real & l2d, Standard_Real & tol){ const opencascade::handle<Geom2d_Curve> & rv = self.PC(f2d, l2d, tol); return std::tuple<const opencascade::handle<Geom2d_Curve> &, Standard_Real &, Standard_Real &, Standard_Real &>(rv, f2d, l2d, tol); }, "None", py::arg("f2d"), py::arg("l2d"), py::arg("tol"));
cls_TopOpeBRepTool_C2DF.def("Face", (const TopoDS_Face & (TopOpeBRepTool_C2DF::*)() const) &TopOpeBRepTool_C2DF::Face, "None");
cls_TopOpeBRepTool_C2DF.def("IsPC", (Standard_Boolean (TopOpeBRepTool_C2DF::*)(const opencascade::handle<Geom2d_Curve> &) const) &TopOpeBRepTool_C2DF::IsPC, "None", py::arg("PC"));
cls_TopOpeBRepTool_C2DF.def("IsFace", (Standard_Boolean (TopOpeBRepTool_C2DF::*)(const TopoDS_Face &) const) &TopOpeBRepTool_C2DF::IsFace, "None", py::arg("F"));

// TYPEDEF: TOPOPEBREPTOOL_INDEXEDDATAMAPOFSHAPEBOX2D
bind_NCollection_IndexedDataMap<TopoDS_Shape, Bnd_Box2d, TopTools_OrientedShapeMapHasher>(mod, "TopOpeBRepTool_IndexedDataMapOfShapeBox2d", py::module_local(false));

// CLASS: TOPOPEBREPTOOL_FACE
py::class_<TopOpeBRepTool_face> cls_TopOpeBRepTool_face(mod, "TopOpeBRepTool_face", "None");

// Constructors
cls_TopOpeBRepTool_face.def(py::init<>());

// Methods
// cls_TopOpeBRepTool_face.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepTool_face::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepTool_face.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepTool_face::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepTool_face.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepTool_face::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepTool_face.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepTool_face::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepTool_face.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepTool_face::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepTool_face.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepTool_face::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepTool_face.def("Init", (Standard_Boolean (TopOpeBRepTool_face::*)(const TopoDS_Wire &, const TopoDS_Face &)) &TopOpeBRepTool_face::Init, "None", py::arg("W"), py::arg("Fref"));
cls_TopOpeBRepTool_face.def("W", (const TopoDS_Wire & (TopOpeBRepTool_face::*)() const) &TopOpeBRepTool_face::W, "None");
cls_TopOpeBRepTool_face.def("IsDone", (Standard_Boolean (TopOpeBRepTool_face::*)() const) &TopOpeBRepTool_face::IsDone, "None");
cls_TopOpeBRepTool_face.def("Finite", (Standard_Boolean (TopOpeBRepTool_face::*)() const) &TopOpeBRepTool_face::Finite, "None");
cls_TopOpeBRepTool_face.def("Ffinite", (const TopoDS_Face & (TopOpeBRepTool_face::*)() const) &TopOpeBRepTool_face::Ffinite, "None");
cls_TopOpeBRepTool_face.def("RealF", (TopoDS_Face (TopOpeBRepTool_face::*)() const) &TopOpeBRepTool_face::RealF, "None");

// TYPEDEF: TOPOPEBREPTOOL_DATAMAPOFSHAPEFACE
bind_NCollection_DataMap<TopoDS_Shape, TopOpeBRepTool_face, TopTools_ShapeMapHasher>(mod, "TopOpeBRepTool_DataMapOfShapeface", py::module_local(false));

// TYPEDEF: TOPOPEBREPTOOL_DATAMAPITERATOROFDATAMAPOFSHAPEFACE

// CLASS: TOPOPEBREPTOOL_CLASSI
py::class_<TopOpeBRepTool_CLASSI> cls_TopOpeBRepTool_CLASSI(mod, "TopOpeBRepTool_CLASSI", "None");

// Constructors
cls_TopOpeBRepTool_CLASSI.def(py::init<>());

// Methods
// cls_TopOpeBRepTool_CLASSI.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepTool_CLASSI::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepTool_CLASSI.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepTool_CLASSI::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepTool_CLASSI.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepTool_CLASSI::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepTool_CLASSI.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepTool_CLASSI::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepTool_CLASSI.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepTool_CLASSI::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepTool_CLASSI.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepTool_CLASSI::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepTool_CLASSI.def("Init2d", (void (TopOpeBRepTool_CLASSI::*)(const TopoDS_Face &)) &TopOpeBRepTool_CLASSI::Init2d, "None", py::arg("Fref"));
cls_TopOpeBRepTool_CLASSI.def("HasInit2d", (Standard_Boolean (TopOpeBRepTool_CLASSI::*)() const) &TopOpeBRepTool_CLASSI::HasInit2d, "None");
cls_TopOpeBRepTool_CLASSI.def("Add2d", (Standard_Boolean (TopOpeBRepTool_CLASSI::*)(const TopoDS_Shape &)) &TopOpeBRepTool_CLASSI::Add2d, "None", py::arg("S"));
cls_TopOpeBRepTool_CLASSI.def("GetBox2d", (Standard_Boolean (TopOpeBRepTool_CLASSI::*)(const TopoDS_Shape &, Bnd_Box2d &)) &TopOpeBRepTool_CLASSI::GetBox2d, "None", py::arg("S"), py::arg("Box2d"));
cls_TopOpeBRepTool_CLASSI.def("ClassiBnd2d", (Standard_Integer (TopOpeBRepTool_CLASSI::*)(const TopoDS_Shape &, const TopoDS_Shape &, const Standard_Real, const Standard_Boolean)) &TopOpeBRepTool_CLASSI::ClassiBnd2d, "None", py::arg("S1"), py::arg("S2"), py::arg("tol"), py::arg("checklarge"));
cls_TopOpeBRepTool_CLASSI.def("Classip2d", (Standard_Integer (TopOpeBRepTool_CLASSI::*)(const TopoDS_Shape &, const TopoDS_Shape &, const Standard_Integer)) &TopOpeBRepTool_CLASSI::Classip2d, "None", py::arg("S1"), py::arg("S2"), py::arg("stabnd2d12"));
cls_TopOpeBRepTool_CLASSI.def("Getface", (Standard_Boolean (TopOpeBRepTool_CLASSI::*)(const TopoDS_Shape &, TopOpeBRepTool_face &) const) &TopOpeBRepTool_CLASSI::Getface, "None", py::arg("S"), py::arg("fa"));
cls_TopOpeBRepTool_CLASSI.def("Classilist", (Standard_Boolean (TopOpeBRepTool_CLASSI::*)(const TopTools_ListOfShape &, TopTools_DataMapOfShapeListOfShape &)) &TopOpeBRepTool_CLASSI::Classilist, "None", py::arg("lS"), py::arg("mapgreasma"));

// CLASS: TOPOPEBREPTOOL_CONNEXITY
py::class_<TopOpeBRepTool_connexity> cls_TopOpeBRepTool_connexity(mod, "TopOpeBRepTool_connexity", "None");

// Constructors
cls_TopOpeBRepTool_connexity.def(py::init<>());
cls_TopOpeBRepTool_connexity.def(py::init<const TopoDS_Shape &>(), py::arg("Key"));

// Methods
// cls_TopOpeBRepTool_connexity.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepTool_connexity::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepTool_connexity.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepTool_connexity::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepTool_connexity.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepTool_connexity::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepTool_connexity.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepTool_connexity::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepTool_connexity.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepTool_connexity::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepTool_connexity.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepTool_connexity::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepTool_connexity.def("SetKey", (void (TopOpeBRepTool_connexity::*)(const TopoDS_Shape &)) &TopOpeBRepTool_connexity::SetKey, "None", py::arg("Key"));
cls_TopOpeBRepTool_connexity.def("Key", (const TopoDS_Shape & (TopOpeBRepTool_connexity::*)() const) &TopOpeBRepTool_connexity::Key, "None");
cls_TopOpeBRepTool_connexity.def("Item", (Standard_Integer (TopOpeBRepTool_connexity::*)(const Standard_Integer, TopTools_ListOfShape &) const) &TopOpeBRepTool_connexity::Item, "None", py::arg("OriKey"), py::arg("Item"));
cls_TopOpeBRepTool_connexity.def("AllItems", (Standard_Integer (TopOpeBRepTool_connexity::*)(TopTools_ListOfShape &) const) &TopOpeBRepTool_connexity::AllItems, "None", py::arg("Item"));
cls_TopOpeBRepTool_connexity.def("AddItem", (void (TopOpeBRepTool_connexity::*)(const Standard_Integer, const TopTools_ListOfShape &)) &TopOpeBRepTool_connexity::AddItem, "None", py::arg("OriKey"), py::arg("Item"));
cls_TopOpeBRepTool_connexity.def("AddItem", (void (TopOpeBRepTool_connexity::*)(const Standard_Integer, const TopoDS_Shape &)) &TopOpeBRepTool_connexity::AddItem, "None", py::arg("OriKey"), py::arg("Item"));
cls_TopOpeBRepTool_connexity.def("RemoveItem", (Standard_Boolean (TopOpeBRepTool_connexity::*)(const Standard_Integer, const TopoDS_Shape &)) &TopOpeBRepTool_connexity::RemoveItem, "None", py::arg("OriKey"), py::arg("Item"));
cls_TopOpeBRepTool_connexity.def("RemoveItem", (Standard_Boolean (TopOpeBRepTool_connexity::*)(const TopoDS_Shape &)) &TopOpeBRepTool_connexity::RemoveItem, "None", py::arg("Item"));
cls_TopOpeBRepTool_connexity.def("ChangeItem", (TopTools_ListOfShape & (TopOpeBRepTool_connexity::*)(const Standard_Integer)) &TopOpeBRepTool_connexity::ChangeItem, "None", py::arg("OriKey"));
cls_TopOpeBRepTool_connexity.def("IsMultiple", (Standard_Boolean (TopOpeBRepTool_connexity::*)() const) &TopOpeBRepTool_connexity::IsMultiple, "None");
cls_TopOpeBRepTool_connexity.def("IsFaulty", (Standard_Boolean (TopOpeBRepTool_connexity::*)() const) &TopOpeBRepTool_connexity::IsFaulty, "None");
cls_TopOpeBRepTool_connexity.def("IsInternal", (Standard_Integer (TopOpeBRepTool_connexity::*)(TopTools_ListOfShape &) const) &TopOpeBRepTool_connexity::IsInternal, "None", py::arg("Item"));

// TYPEDEF: TOPOPEBREPTOOL_DATAMAPOFORIENTEDSHAPEC2DF
bind_NCollection_DataMap<TopoDS_Shape, TopOpeBRepTool_C2DF, TopTools_OrientedShapeMapHasher>(mod, "TopOpeBRepTool_DataMapOfOrientedShapeC2DF", py::module_local(false));

// TYPEDEF: TOPOPEBREPTOOL_DATAMAPITERATOROFDATAMAPOFORIENTEDSHAPEC2DF

// CLASS: TOPOPEBREPTOOL_CORRISO
py::class_<TopOpeBRepTool_CORRISO> cls_TopOpeBRepTool_CORRISO(mod, "TopOpeBRepTool_CORRISO", "Fref is built on x-periodic surface (x=u,v). S built on Fref's geometry, should be UVClosed.");

// Constructors
cls_TopOpeBRepTool_CORRISO.def(py::init<>());
cls_TopOpeBRepTool_CORRISO.def(py::init<const TopoDS_Face &>(), py::arg("FRef"));

// Methods
// cls_TopOpeBRepTool_CORRISO.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepTool_CORRISO::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepTool_CORRISO.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepTool_CORRISO::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepTool_CORRISO.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepTool_CORRISO::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepTool_CORRISO.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepTool_CORRISO::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepTool_CORRISO.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepTool_CORRISO::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepTool_CORRISO.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepTool_CORRISO::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepTool_CORRISO.def("Fref", (const TopoDS_Face & (TopOpeBRepTool_CORRISO::*)() const) &TopOpeBRepTool_CORRISO::Fref, "None");
cls_TopOpeBRepTool_CORRISO.def("GASref", (const GeomAdaptor_Surface & (TopOpeBRepTool_CORRISO::*)() const) &TopOpeBRepTool_CORRISO::GASref, "None");
cls_TopOpeBRepTool_CORRISO.def("Refclosed", [](TopOpeBRepTool_CORRISO &self, const Standard_Integer x, Standard_Real & xperiod){ Standard_Boolean rv = self.Refclosed(x, xperiod); return std::tuple<Standard_Boolean, Standard_Real &>(rv, xperiod); }, "None", py::arg("x"), py::arg("xperiod"));
cls_TopOpeBRepTool_CORRISO.def("Init", (Standard_Boolean (TopOpeBRepTool_CORRISO::*)(const TopoDS_Shape &)) &TopOpeBRepTool_CORRISO::Init, "None", py::arg("S"));
cls_TopOpeBRepTool_CORRISO.def("S", (const TopoDS_Shape & (TopOpeBRepTool_CORRISO::*)() const) &TopOpeBRepTool_CORRISO::S, "None");
cls_TopOpeBRepTool_CORRISO.def("Eds", (const TopTools_ListOfShape & (TopOpeBRepTool_CORRISO::*)() const) &TopOpeBRepTool_CORRISO::Eds, "None");
cls_TopOpeBRepTool_CORRISO.def("UVClosed", (Standard_Boolean (TopOpeBRepTool_CORRISO::*)() const) &TopOpeBRepTool_CORRISO::UVClosed, "None");
cls_TopOpeBRepTool_CORRISO.def("Tol", (Standard_Real (TopOpeBRepTool_CORRISO::*)(const Standard_Integer, const Standard_Real) const) &TopOpeBRepTool_CORRISO::Tol, "None", py::arg("I"), py::arg("tol3d"));
cls_TopOpeBRepTool_CORRISO.def("PurgeFyClosingE", (Standard_Boolean (TopOpeBRepTool_CORRISO::*)(const TopTools_ListOfShape &, TopTools_ListOfShape &) const) &TopOpeBRepTool_CORRISO::PurgeFyClosingE, "None", py::arg("ClEds"), py::arg("fyClEds"));
cls_TopOpeBRepTool_CORRISO.def("EdgeOUTofBoundsUV", [](TopOpeBRepTool_CORRISO &self, const TopoDS_Edge & E, const Standard_Boolean onU, const Standard_Real tolx, Standard_Real & parspE){ Standard_Integer rv = self.EdgeOUTofBoundsUV(E, onU, tolx, parspE); return std::tuple<Standard_Integer, Standard_Real &>(rv, parspE); }, "None", py::arg("E"), py::arg("onU"), py::arg("tolx"), py::arg("parspE"));
cls_TopOpeBRepTool_CORRISO.def("EdgesOUTofBoundsUV", (Standard_Boolean (TopOpeBRepTool_CORRISO::*)(const TopTools_ListOfShape &, const Standard_Boolean, const Standard_Real, TopTools_DataMapOfOrientedShapeInteger &) const) &TopOpeBRepTool_CORRISO::EdgesOUTofBoundsUV, "None", py::arg("EdsToCheck"), py::arg("onU"), py::arg("tolx"), py::arg("FyEds"));
cls_TopOpeBRepTool_CORRISO.def("EdgeWithFaultyUV", [](TopOpeBRepTool_CORRISO &self, const TopoDS_Edge & E, Standard_Integer & Ivfaulty){ Standard_Boolean rv = self.EdgeWithFaultyUV(E, Ivfaulty); return std::tuple<Standard_Boolean, Standard_Integer &>(rv, Ivfaulty); }, "None", py::arg("E"), py::arg("Ivfaulty"));
cls_TopOpeBRepTool_CORRISO.def("EdgesWithFaultyUV", [](TopOpeBRepTool_CORRISO &self, const TopTools_ListOfShape & a0, const Standard_Integer a1, TopTools_DataMapOfOrientedShapeInteger & a2) -> Standard_Boolean { return self.EdgesWithFaultyUV(a0, a1, a2); });
cls_TopOpeBRepTool_CORRISO.def("EdgesWithFaultyUV", (Standard_Boolean (TopOpeBRepTool_CORRISO::*)(const TopTools_ListOfShape &, const Standard_Integer, TopTools_DataMapOfOrientedShapeInteger &, const Standard_Boolean) const) &TopOpeBRepTool_CORRISO::EdgesWithFaultyUV, "None", py::arg("EdsToCheck"), py::arg("nfybounds"), py::arg("FyEds"), py::arg("stopatfirst"));
cls_TopOpeBRepTool_CORRISO.def("EdgeWithFaultyUV", [](TopOpeBRepTool_CORRISO &self, const TopTools_ListOfShape & EdsToCheck, const Standard_Integer nfybounds, TopoDS_Shape & fyE, Standard_Integer & Ifaulty){ Standard_Boolean rv = self.EdgeWithFaultyUV(EdsToCheck, nfybounds, fyE, Ifaulty); return std::tuple<Standard_Boolean, Standard_Integer &>(rv, Ifaulty); }, "None", py::arg("EdsToCheck"), py::arg("nfybounds"), py::arg("fyE"), py::arg("Ifaulty"));
cls_TopOpeBRepTool_CORRISO.def("TrslUV", (Standard_Boolean (TopOpeBRepTool_CORRISO::*)(const Standard_Boolean, const TopTools_DataMapOfOrientedShapeInteger &)) &TopOpeBRepTool_CORRISO::TrslUV, "None", py::arg("onU"), py::arg("FyEds"));
cls_TopOpeBRepTool_CORRISO.def("GetnewS", (Standard_Boolean (TopOpeBRepTool_CORRISO::*)(TopoDS_Face &) const) &TopOpeBRepTool_CORRISO::GetnewS, "None", py::arg("newS"));
cls_TopOpeBRepTool_CORRISO.def("UVRep", (Standard_Boolean (TopOpeBRepTool_CORRISO::*)(const TopoDS_Edge &, TopOpeBRepTool_C2DF &) const) &TopOpeBRepTool_CORRISO::UVRep, "None", py::arg("E"), py::arg("C2DF"));
cls_TopOpeBRepTool_CORRISO.def("SetUVRep", (Standard_Boolean (TopOpeBRepTool_CORRISO::*)(const TopoDS_Edge &, const TopOpeBRepTool_C2DF &)) &TopOpeBRepTool_CORRISO::SetUVRep, "None", py::arg("E"), py::arg("C2DF"));
cls_TopOpeBRepTool_CORRISO.def("Connexity", (Standard_Boolean (TopOpeBRepTool_CORRISO::*)(const TopoDS_Vertex &, TopTools_ListOfShape &) const) &TopOpeBRepTool_CORRISO::Connexity, "None", py::arg("V"), py::arg("Eds"));
cls_TopOpeBRepTool_CORRISO.def("SetConnexity", (Standard_Boolean (TopOpeBRepTool_CORRISO::*)(const TopoDS_Vertex &, const TopTools_ListOfShape &)) &TopOpeBRepTool_CORRISO::SetConnexity, "None", py::arg("V"), py::arg("Eds"));
cls_TopOpeBRepTool_CORRISO.def("AddNewConnexity", (Standard_Boolean (TopOpeBRepTool_CORRISO::*)(const TopoDS_Vertex &, const TopoDS_Edge &)) &TopOpeBRepTool_CORRISO::AddNewConnexity, "None", py::arg("V"), py::arg("E"));
cls_TopOpeBRepTool_CORRISO.def("RemoveOldConnexity", (Standard_Boolean (TopOpeBRepTool_CORRISO::*)(const TopoDS_Vertex &, const TopoDS_Edge &)) &TopOpeBRepTool_CORRISO::RemoveOldConnexity, "None", py::arg("V"), py::arg("E"));

// TYPEDEF: TOPOPEBREPTOOL_LISTOFC2DF
bind_NCollection_List<TopOpeBRepTool_C2DF>(mod, "TopOpeBRepTool_ListOfC2DF", py::module_local(false));

// TYPEDEF: TOPOPEBREPTOOL_LISTITERATOROFLISTOFC2DF
bind_NCollection_TListIterator<TopOpeBRepTool_C2DF>(mod, "TopOpeBRepTool_ListIteratorOfListOfC2DF", py::module_local(false));

// TYPEDEF: TOPOPEBREPTOOL_DATAMAPOFSHAPELISTOFC2DF
bind_NCollection_DataMap<TopoDS_Shape, NCollection_List<TopOpeBRepTool_C2DF>, TopTools_ShapeMapHasher>(mod, "TopOpeBRepTool_DataMapOfShapeListOfC2DF", py::module_local(false));

// TYPEDEF: TOPOPEBREPTOOL_DATAMAPITERATOROFDATAMAPOFSHAPELISTOFC2DF

// CLASS: TOPOPEBREPTOOL_FUSEEDGES
py::class_<TopOpeBRepTool_FuseEdges> cls_TopOpeBRepTool_FuseEdges(mod, "TopOpeBRepTool_FuseEdges", "This class can detect vertices in a face that can be considered useless and then perform the fuse of the edges and remove the useless vertices. By useles vertices, we mean : * vertices that have exactly two connex edges * the edges connex to the vertex must have exactly the same 2 connex faces . * The edges connex to the vertex must have the same geometric support.");

// Constructors
cls_TopOpeBRepTool_FuseEdges.def(py::init<const TopoDS_Shape &>(), py::arg("theShape"));
cls_TopOpeBRepTool_FuseEdges.def(py::init<const TopoDS_Shape &, const Standard_Boolean>(), py::arg("theShape"), py::arg("PerformNow"));

// Methods
// cls_TopOpeBRepTool_FuseEdges.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepTool_FuseEdges::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepTool_FuseEdges.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepTool_FuseEdges::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepTool_FuseEdges.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepTool_FuseEdges::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepTool_FuseEdges.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepTool_FuseEdges::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepTool_FuseEdges.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepTool_FuseEdges::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepTool_FuseEdges.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepTool_FuseEdges::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepTool_FuseEdges.def("AvoidEdges", (void (TopOpeBRepTool_FuseEdges::*)(const TopTools_IndexedMapOfShape &)) &TopOpeBRepTool_FuseEdges::AvoidEdges, "set edges to avoid being fused", py::arg("theMapEdg"));
cls_TopOpeBRepTool_FuseEdges.def("Edges", (void (TopOpeBRepTool_FuseEdges::*)(TopTools_DataMapOfIntegerListOfShape &)) &TopOpeBRepTool_FuseEdges::Edges, "returns all the list of edges to be fused each list of the map represent a set of connex edges that can be fused.", py::arg("theMapLstEdg"));
cls_TopOpeBRepTool_FuseEdges.def("ResultEdges", (void (TopOpeBRepTool_FuseEdges::*)(TopTools_DataMapOfIntegerShape &)) &TopOpeBRepTool_FuseEdges::ResultEdges, "returns all the fused edges. each integer entry in the map corresponds to the integer in the DataMapOfIntegerListOfShape we get in method Edges. That is to say, to the list of edges in theMapLstEdg(i) corresponds the resulting edge theMapEdge(i)", py::arg("theMapEdg"));
cls_TopOpeBRepTool_FuseEdges.def("Faces", (void (TopOpeBRepTool_FuseEdges::*)(TopTools_DataMapOfShapeShape &)) &TopOpeBRepTool_FuseEdges::Faces, "returns the map of modified faces.", py::arg("theMapFac"));
cls_TopOpeBRepTool_FuseEdges.def("Shape", (TopoDS_Shape & (TopOpeBRepTool_FuseEdges::*)()) &TopOpeBRepTool_FuseEdges::Shape, "returns myShape modified with the list of internal edges removed from it.");
cls_TopOpeBRepTool_FuseEdges.def("NbVertices", (Standard_Integer (TopOpeBRepTool_FuseEdges::*)()) &TopOpeBRepTool_FuseEdges::NbVertices, "returns the number of vertices candidate to be removed");
cls_TopOpeBRepTool_FuseEdges.def("Perform", (void (TopOpeBRepTool_FuseEdges::*)()) &TopOpeBRepTool_FuseEdges::Perform, "Using map of list of connex edges, fuse each list to one edge and then update myShape");

// TYPEDEF: TOPOPEBREPTOOL_INDEXEDDATAMAPOFSHAPECONNEXITY
bind_NCollection_IndexedDataMap<TopoDS_Shape, TopOpeBRepTool_connexity, TopTools_ShapeMapHasher>(mod, "TopOpeBRepTool_IndexedDataMapOfShapeconnexity", py::module_local(false));

// TYPEDEF: TOPOPEBREPTOOL_INDEXEDDATAMAPOFSOLIDCLASSIFIER
/*
bind_NCollection_IndexedDataMap<TopoDS_Shape, BRepClass3d_SolidClassifier, TopTools_ShapeMapHasher>(mod, "TopOpeBRepTool_IndexedDataMapOfSolidClassifier", py::module_local(false));
*/

// CLASS: TOPOPEBREPTOOL_MAKETRANSITION
py::class_<TopOpeBRepTool_makeTransition> cls_TopOpeBRepTool_makeTransition(mod, "TopOpeBRepTool_makeTransition", "None");

// Constructors
cls_TopOpeBRepTool_makeTransition.def(py::init<>());

// Methods
// cls_TopOpeBRepTool_makeTransition.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepTool_makeTransition::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepTool_makeTransition.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepTool_makeTransition::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepTool_makeTransition.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepTool_makeTransition::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepTool_makeTransition.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepTool_makeTransition::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepTool_makeTransition.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepTool_makeTransition::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepTool_makeTransition.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepTool_makeTransition::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepTool_makeTransition.def("Initialize", (Standard_Boolean (TopOpeBRepTool_makeTransition::*)(const TopoDS_Edge &, const Standard_Real, const Standard_Real, const Standard_Real, const TopoDS_Face &, const gp_Pnt2d &, const Standard_Real)) &TopOpeBRepTool_makeTransition::Initialize, "None", py::arg("E"), py::arg("pbef"), py::arg("paft"), py::arg("parE"), py::arg("FS"), py::arg("uv"), py::arg("factor"));
cls_TopOpeBRepTool_makeTransition.def("Setfactor", (void (TopOpeBRepTool_makeTransition::*)(const Standard_Real)) &TopOpeBRepTool_makeTransition::Setfactor, "None", py::arg("factor"));
cls_TopOpeBRepTool_makeTransition.def("Getfactor", (Standard_Real (TopOpeBRepTool_makeTransition::*)() const) &TopOpeBRepTool_makeTransition::Getfactor, "None");
cls_TopOpeBRepTool_makeTransition.def("IsT2d", (Standard_Boolean (TopOpeBRepTool_makeTransition::*)() const) &TopOpeBRepTool_makeTransition::IsT2d, "None");
cls_TopOpeBRepTool_makeTransition.def("SetRest", (Standard_Boolean (TopOpeBRepTool_makeTransition::*)(const TopoDS_Edge &, const Standard_Real)) &TopOpeBRepTool_makeTransition::SetRest, "None", py::arg("ES"), py::arg("parES"));
cls_TopOpeBRepTool_makeTransition.def("HasRest", (Standard_Boolean (TopOpeBRepTool_makeTransition::*)() const) &TopOpeBRepTool_makeTransition::HasRest, "None");
cls_TopOpeBRepTool_makeTransition.def("MkT2donE", (Standard_Boolean (TopOpeBRepTool_makeTransition::*)(TopAbs_State &, TopAbs_State &) const) &TopOpeBRepTool_makeTransition::MkT2donE, "None", py::arg("stb"), py::arg("sta"));
cls_TopOpeBRepTool_makeTransition.def("MkT3onE", (Standard_Boolean (TopOpeBRepTool_makeTransition::*)(TopAbs_State &, TopAbs_State &) const) &TopOpeBRepTool_makeTransition::MkT3onE, "None", py::arg("stb"), py::arg("sta"));
cls_TopOpeBRepTool_makeTransition.def("MkT3dproj", (Standard_Boolean (TopOpeBRepTool_makeTransition::*)(TopAbs_State &, TopAbs_State &) const) &TopOpeBRepTool_makeTransition::MkT3dproj, "None", py::arg("stb"), py::arg("sta"));
cls_TopOpeBRepTool_makeTransition.def("MkTonE", (Standard_Boolean (TopOpeBRepTool_makeTransition::*)(TopAbs_State &, TopAbs_State &)) &TopOpeBRepTool_makeTransition::MkTonE, "None", py::arg("stb"), py::arg("sta"));

// CLASS: TOPOPEBREPTOOL_MKTONDGE
py::class_<TopOpeBRepTool_mkTondgE> cls_TopOpeBRepTool_mkTondgE(mod, "TopOpeBRepTool_mkTondgE", "None");

// Constructors
cls_TopOpeBRepTool_mkTondgE.def(py::init<>());

// Methods
// cls_TopOpeBRepTool_mkTondgE.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepTool_mkTondgE::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepTool_mkTondgE.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepTool_mkTondgE::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepTool_mkTondgE.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepTool_mkTondgE::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepTool_mkTondgE.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepTool_mkTondgE::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepTool_mkTondgE.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepTool_mkTondgE::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepTool_mkTondgE.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepTool_mkTondgE::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepTool_mkTondgE.def("Initialize", (Standard_Boolean (TopOpeBRepTool_mkTondgE::*)(const TopoDS_Edge &, const TopoDS_Face &, const gp_Pnt2d &, const TopoDS_Face &)) &TopOpeBRepTool_mkTondgE::Initialize, "None", py::arg("dgE"), py::arg("F"), py::arg("uvi"), py::arg("Fi"));
cls_TopOpeBRepTool_mkTondgE.def("SetclE", (Standard_Boolean (TopOpeBRepTool_mkTondgE::*)(const TopoDS_Edge &)) &TopOpeBRepTool_mkTondgE::SetclE, "None", py::arg("clE"));
cls_TopOpeBRepTool_mkTondgE.def("IsT2d", (Standard_Boolean (TopOpeBRepTool_mkTondgE::*)() const) &TopOpeBRepTool_mkTondgE::IsT2d, "None");
cls_TopOpeBRepTool_mkTondgE.def("SetRest", (Standard_Boolean (TopOpeBRepTool_mkTondgE::*)(const Standard_Real, const TopoDS_Edge &)) &TopOpeBRepTool_mkTondgE::SetRest, "None", py::arg("pari"), py::arg("Ei"));
cls_TopOpeBRepTool_mkTondgE.def("GetAllRest", (Standard_Integer (TopOpeBRepTool_mkTondgE::*)(TopTools_ListOfShape &)) &TopOpeBRepTool_mkTondgE::GetAllRest, "None", py::arg("lEi"));
cls_TopOpeBRepTool_mkTondgE.def("MkTonE", [](TopOpeBRepTool_mkTondgE &self, Standard_Integer & mkT, Standard_Real & par1, Standard_Real & par2){ Standard_Boolean rv = self.MkTonE(mkT, par1, par2); return std::tuple<Standard_Boolean, Standard_Integer &, Standard_Real &, Standard_Real &>(rv, mkT, par1, par2); }, "None", py::arg("mkT"), py::arg("par1"), py::arg("par2"));
cls_TopOpeBRepTool_mkTondgE.def("MkTonE", [](TopOpeBRepTool_mkTondgE &self, const TopoDS_Edge & Ei, Standard_Integer & mkT, Standard_Real & par1, Standard_Real & par2){ Standard_Boolean rv = self.MkTonE(Ei, mkT, par1, par2); return std::tuple<Standard_Boolean, Standard_Integer &, Standard_Real &, Standard_Real &>(rv, mkT, par1, par2); }, "None", py::arg("Ei"), py::arg("mkT"), py::arg("par1"), py::arg("par2"));

// CLASS: TOPOPEBREPTOOL_PURGEINTERNALEDGES
py::class_<TopOpeBRepTool_PurgeInternalEdges> cls_TopOpeBRepTool_PurgeInternalEdges(mod, "TopOpeBRepTool_PurgeInternalEdges", "remove from a shape, the internal edges that are not connected to any face in the shape. We can get the list of the edges as a DataMapOfShapeListOfShape with a Face of the Shape as the key and a list of internal edges as the value. The list of internal edges means edges that are not connected to any face in the shape.");

// Constructors
cls_TopOpeBRepTool_PurgeInternalEdges.def(py::init<const TopoDS_Shape &>(), py::arg("theShape"));
cls_TopOpeBRepTool_PurgeInternalEdges.def(py::init<const TopoDS_Shape &, const Standard_Boolean>(), py::arg("theShape"), py::arg("PerformNow"));

// Methods
// cls_TopOpeBRepTool_PurgeInternalEdges.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepTool_PurgeInternalEdges::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepTool_PurgeInternalEdges.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepTool_PurgeInternalEdges::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepTool_PurgeInternalEdges.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepTool_PurgeInternalEdges::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepTool_PurgeInternalEdges.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepTool_PurgeInternalEdges::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepTool_PurgeInternalEdges.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepTool_PurgeInternalEdges::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepTool_PurgeInternalEdges.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepTool_PurgeInternalEdges::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepTool_PurgeInternalEdges.def("Faces", (void (TopOpeBRepTool_PurgeInternalEdges::*)(TopTools_DataMapOfShapeListOfShape &)) &TopOpeBRepTool_PurgeInternalEdges::Faces, "returns the list internal edges associated with the faces of the myShape. If PerformNow was False when created, then call the private Perform method that do the main job.", py::arg("theMapFacLstEdg"));
cls_TopOpeBRepTool_PurgeInternalEdges.def("Shape", (TopoDS_Shape & (TopOpeBRepTool_PurgeInternalEdges::*)()) &TopOpeBRepTool_PurgeInternalEdges::Shape, "returns myShape modified with the list of internal edges removed from it.");
cls_TopOpeBRepTool_PurgeInternalEdges.def("NbEdges", (Standard_Integer (TopOpeBRepTool_PurgeInternalEdges::*)() const) &TopOpeBRepTool_PurgeInternalEdges::NbEdges, "returns the number of edges candidate to be removed");
cls_TopOpeBRepTool_PurgeInternalEdges.def("IsDone", (Standard_Boolean (TopOpeBRepTool_PurgeInternalEdges::*)() const) &TopOpeBRepTool_PurgeInternalEdges::IsDone, "returns False if the list of internal edges has not been extracted");
cls_TopOpeBRepTool_PurgeInternalEdges.def("Perform", (void (TopOpeBRepTool_PurgeInternalEdges::*)()) &TopOpeBRepTool_PurgeInternalEdges::Perform, "Using the list of internal edge from each face, rebuild myShape by removing thoses edges.");

// CLASS: TOPOPEBREPTOOL_REGUS
py::class_<TopOpeBRepTool_REGUS> cls_TopOpeBRepTool_REGUS(mod, "TopOpeBRepTool_REGUS", "None");

// Constructors
cls_TopOpeBRepTool_REGUS.def(py::init<>());

// Methods
// cls_TopOpeBRepTool_REGUS.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepTool_REGUS::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepTool_REGUS.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepTool_REGUS::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepTool_REGUS.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepTool_REGUS::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepTool_REGUS.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepTool_REGUS::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepTool_REGUS.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepTool_REGUS::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepTool_REGUS.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepTool_REGUS::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepTool_REGUS.def("Init", (void (TopOpeBRepTool_REGUS::*)(const TopoDS_Shape &)) &TopOpeBRepTool_REGUS::Init, "None", py::arg("S"));
cls_TopOpeBRepTool_REGUS.def("S", (const TopoDS_Shape & (TopOpeBRepTool_REGUS::*)() const) &TopOpeBRepTool_REGUS::S, "None");
cls_TopOpeBRepTool_REGUS.def("MapS", (Standard_Boolean (TopOpeBRepTool_REGUS::*)()) &TopOpeBRepTool_REGUS::MapS, "None");
cls_TopOpeBRepTool_REGUS.def_static("WireToFace_", (Standard_Boolean (*)(const TopoDS_Face &, const TopTools_ListOfShape &, TopTools_ListOfShape &)) &TopOpeBRepTool_REGUS::WireToFace, "None", py::arg("Fanc"), py::arg("nWs"), py::arg("nFs"));
cls_TopOpeBRepTool_REGUS.def_static("SplitF_", (Standard_Boolean (*)(const TopoDS_Face &, TopTools_ListOfShape &)) &TopOpeBRepTool_REGUS::SplitF, "None", py::arg("Fanc"), py::arg("FSplits"));
cls_TopOpeBRepTool_REGUS.def("SplitFaces", (Standard_Boolean (TopOpeBRepTool_REGUS::*)()) &TopOpeBRepTool_REGUS::SplitFaces, "None");
cls_TopOpeBRepTool_REGUS.def("REGU", (Standard_Boolean (TopOpeBRepTool_REGUS::*)()) &TopOpeBRepTool_REGUS::REGU, "None");
cls_TopOpeBRepTool_REGUS.def("SetFsplits", (void (TopOpeBRepTool_REGUS::*)(TopTools_DataMapOfShapeListOfShape &)) &TopOpeBRepTool_REGUS::SetFsplits, "None", py::arg("Fsplits"));
cls_TopOpeBRepTool_REGUS.def("GetFsplits", (void (TopOpeBRepTool_REGUS::*)(TopTools_DataMapOfShapeListOfShape &) const) &TopOpeBRepTool_REGUS::GetFsplits, "None", py::arg("Fsplits"));
cls_TopOpeBRepTool_REGUS.def("SetOshNsh", (void (TopOpeBRepTool_REGUS::*)(TopTools_DataMapOfShapeListOfShape &)) &TopOpeBRepTool_REGUS::SetOshNsh, "None", py::arg("OshNsh"));
cls_TopOpeBRepTool_REGUS.def("GetOshNsh", (void (TopOpeBRepTool_REGUS::*)(TopTools_DataMapOfShapeListOfShape &) const) &TopOpeBRepTool_REGUS::GetOshNsh, "None", py::arg("OshNsh"));
cls_TopOpeBRepTool_REGUS.def("InitBlock", (Standard_Boolean (TopOpeBRepTool_REGUS::*)()) &TopOpeBRepTool_REGUS::InitBlock, "None");
cls_TopOpeBRepTool_REGUS.def("NextinBlock", (Standard_Boolean (TopOpeBRepTool_REGUS::*)()) &TopOpeBRepTool_REGUS::NextinBlock, "None");
cls_TopOpeBRepTool_REGUS.def("NearestF", (Standard_Boolean (TopOpeBRepTool_REGUS::*)(const TopoDS_Edge &, const TopTools_ListOfShape &, TopoDS_Face &) const) &TopOpeBRepTool_REGUS::NearestF, "None", py::arg("e"), py::arg("lof"), py::arg("ffound"));

// CLASS: TOPOPEBREPTOOL_REGUW
py::class_<TopOpeBRepTool_REGUW> cls_TopOpeBRepTool_REGUW(mod, "TopOpeBRepTool_REGUW", "None");

// Constructors
cls_TopOpeBRepTool_REGUW.def(py::init<const TopoDS_Face &>(), py::arg("FRef"));

// Methods
// cls_TopOpeBRepTool_REGUW.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepTool_REGUW::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepTool_REGUW.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepTool_REGUW::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepTool_REGUW.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepTool_REGUW::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepTool_REGUW.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepTool_REGUW::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepTool_REGUW.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepTool_REGUW::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepTool_REGUW.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepTool_REGUW::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepTool_REGUW.def("Fref", (const TopoDS_Face & (TopOpeBRepTool_REGUW::*)() const) &TopOpeBRepTool_REGUW::Fref, "None");
cls_TopOpeBRepTool_REGUW.def("SetEsplits", (void (TopOpeBRepTool_REGUW::*)(TopTools_DataMapOfShapeListOfShape &)) &TopOpeBRepTool_REGUW::SetEsplits, "None", py::arg("Esplits"));
cls_TopOpeBRepTool_REGUW.def("GetEsplits", (void (TopOpeBRepTool_REGUW::*)(TopTools_DataMapOfShapeListOfShape &) const) &TopOpeBRepTool_REGUW::GetEsplits, "None", py::arg("Esplits"));
cls_TopOpeBRepTool_REGUW.def("SetOwNw", (void (TopOpeBRepTool_REGUW::*)(TopTools_DataMapOfShapeListOfShape &)) &TopOpeBRepTool_REGUW::SetOwNw, "None", py::arg("OwNw"));
cls_TopOpeBRepTool_REGUW.def("GetOwNw", (void (TopOpeBRepTool_REGUW::*)(TopTools_DataMapOfShapeListOfShape &) const) &TopOpeBRepTool_REGUW::GetOwNw, "None", py::arg("OwNw"));
cls_TopOpeBRepTool_REGUW.def("SplitEds", (Standard_Boolean (TopOpeBRepTool_REGUW::*)()) &TopOpeBRepTool_REGUW::SplitEds, "None");
cls_TopOpeBRepTool_REGUW.def("Init", (void (TopOpeBRepTool_REGUW::*)(const TopoDS_Shape &)) &TopOpeBRepTool_REGUW::Init, "None", py::arg("S"));
cls_TopOpeBRepTool_REGUW.def("S", (const TopoDS_Shape & (TopOpeBRepTool_REGUW::*)() const) &TopOpeBRepTool_REGUW::S, "None");
cls_TopOpeBRepTool_REGUW.def("HasInit", (Standard_Boolean (TopOpeBRepTool_REGUW::*)() const) &TopOpeBRepTool_REGUW::HasInit, "None");
cls_TopOpeBRepTool_REGUW.def("MapS", (Standard_Boolean (TopOpeBRepTool_REGUW::*)()) &TopOpeBRepTool_REGUW::MapS, "None");
cls_TopOpeBRepTool_REGUW.def("REGU", (Standard_Boolean (TopOpeBRepTool_REGUW::*)(const Standard_Integer, const TopoDS_Shape &, TopTools_ListOfShape &)) &TopOpeBRepTool_REGUW::REGU, "None", py::arg("istep"), py::arg("Scur"), py::arg("Splits"));
cls_TopOpeBRepTool_REGUW.def("REGU", (Standard_Boolean (TopOpeBRepTool_REGUW::*)()) &TopOpeBRepTool_REGUW::REGU, "None");
cls_TopOpeBRepTool_REGUW.def("GetSplits", (Standard_Boolean (TopOpeBRepTool_REGUW::*)(TopTools_ListOfShape &) const) &TopOpeBRepTool_REGUW::GetSplits, "None", py::arg("Splits"));
cls_TopOpeBRepTool_REGUW.def("InitBlock", (Standard_Boolean (TopOpeBRepTool_REGUW::*)()) &TopOpeBRepTool_REGUW::InitBlock, "None");
cls_TopOpeBRepTool_REGUW.def("NextinBlock", (Standard_Boolean (TopOpeBRepTool_REGUW::*)()) &TopOpeBRepTool_REGUW::NextinBlock, "None");
cls_TopOpeBRepTool_REGUW.def("NearestE", (Standard_Boolean (TopOpeBRepTool_REGUW::*)(const TopTools_ListOfShape &, TopoDS_Edge &) const) &TopOpeBRepTool_REGUW::NearestE, "None", py::arg("loe"), py::arg("efound"));
cls_TopOpeBRepTool_REGUW.def("Connexity", (Standard_Boolean (TopOpeBRepTool_REGUW::*)(const TopoDS_Vertex &, TopOpeBRepTool_connexity &) const) &TopOpeBRepTool_REGUW::Connexity, "None", py::arg("v"), py::arg("co"));
cls_TopOpeBRepTool_REGUW.def("AddNewConnexity", (Standard_Boolean (TopOpeBRepTool_REGUW::*)(const TopoDS_Vertex &, const Standard_Integer, const TopoDS_Edge &)) &TopOpeBRepTool_REGUW::AddNewConnexity, "None", py::arg("v"), py::arg("OriKey"), py::arg("e"));
cls_TopOpeBRepTool_REGUW.def("RemoveOldConnexity", (Standard_Boolean (TopOpeBRepTool_REGUW::*)(const TopoDS_Vertex &, const Standard_Integer, const TopoDS_Edge &)) &TopOpeBRepTool_REGUW::RemoveOldConnexity, "None", py::arg("v"), py::arg("OriKey"), py::arg("e"));
cls_TopOpeBRepTool_REGUW.def("UpdateMultiple", (Standard_Boolean (TopOpeBRepTool_REGUW::*)(const TopoDS_Vertex &)) &TopOpeBRepTool_REGUW::UpdateMultiple, "None", py::arg("v"));

// CLASS: TOPOPEBREPTOOL_SHAPETOOL
py::class_<TopOpeBRepTool_ShapeTool> cls_TopOpeBRepTool_ShapeTool(mod, "TopOpeBRepTool_ShapeTool", "None");

// Methods
// cls_TopOpeBRepTool_ShapeTool.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepTool_ShapeTool::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepTool_ShapeTool.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepTool_ShapeTool::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepTool_ShapeTool.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepTool_ShapeTool::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepTool_ShapeTool.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepTool_ShapeTool::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepTool_ShapeTool.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepTool_ShapeTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepTool_ShapeTool.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepTool_ShapeTool::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepTool_ShapeTool.def_static("Tolerance_", (Standard_Real (*)(const TopoDS_Shape &)) &TopOpeBRepTool_ShapeTool::Tolerance, "Returns the tolerance of the shape <S>. If the shape <S> is Null, returns 0.", py::arg("S"));
cls_TopOpeBRepTool_ShapeTool.def_static("Pnt_", (gp_Pnt (*)(const TopoDS_Shape &)) &TopOpeBRepTool_ShapeTool::Pnt, "Returns 3D point of vertex <S>.", py::arg("S"));
cls_TopOpeBRepTool_ShapeTool.def_static("BASISCURVE_", (opencascade::handle<Geom_Curve> (*)(const opencascade::handle<Geom_Curve> &)) &TopOpeBRepTool_ShapeTool::BASISCURVE, "None", py::arg("C"));
cls_TopOpeBRepTool_ShapeTool.def_static("BASISCURVE_", (opencascade::handle<Geom_Curve> (*)(const TopoDS_Edge &)) &TopOpeBRepTool_ShapeTool::BASISCURVE, "None", py::arg("E"));
cls_TopOpeBRepTool_ShapeTool.def_static("BASISSURFACE_", (opencascade::handle<Geom_Surface> (*)(const opencascade::handle<Geom_Surface> &)) &TopOpeBRepTool_ShapeTool::BASISSURFACE, "None", py::arg("S"));
cls_TopOpeBRepTool_ShapeTool.def_static("BASISSURFACE_", (opencascade::handle<Geom_Surface> (*)(const TopoDS_Face &)) &TopOpeBRepTool_ShapeTool::BASISSURFACE, "None", py::arg("F"));
cls_TopOpeBRepTool_ShapeTool.def_static("UVBOUNDS_", [](const opencascade::handle<Geom_Surface> & S, Standard_Boolean & UPeri, Standard_Boolean & VPeri, Standard_Real & Umin, Standard_Real & Umax, Standard_Real & Vmin, Standard_Real & Vmax){ TopOpeBRepTool_ShapeTool::UVBOUNDS(S, UPeri, VPeri, Umin, Umax, Vmin, Vmax); return std::tuple<Standard_Boolean &, Standard_Boolean &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(UPeri, VPeri, Umin, Umax, Vmin, Vmax); }, "None", py::arg("S"), py::arg("UPeri"), py::arg("VPeri"), py::arg("Umin"), py::arg("Umax"), py::arg("Vmin"), py::arg("Vmax"));
cls_TopOpeBRepTool_ShapeTool.def_static("UVBOUNDS_", [](const TopoDS_Face & F, Standard_Boolean & UPeri, Standard_Boolean & VPeri, Standard_Real & Umin, Standard_Real & Umax, Standard_Real & Vmin, Standard_Real & Vmax){ TopOpeBRepTool_ShapeTool::UVBOUNDS(F, UPeri, VPeri, Umin, Umax, Vmin, Vmax); return std::tuple<Standard_Boolean &, Standard_Boolean &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(UPeri, VPeri, Umin, Umax, Vmin, Vmax); }, "None", py::arg("F"), py::arg("UPeri"), py::arg("VPeri"), py::arg("Umin"), py::arg("Umax"), py::arg("Vmin"), py::arg("Vmax"));
cls_TopOpeBRepTool_ShapeTool.def_static("AdjustOnPeriodic_", [](const TopoDS_Shape & S, Standard_Real & u, Standard_Real & v){ TopOpeBRepTool_ShapeTool::AdjustOnPeriodic(S, u, v); return std::tuple<Standard_Real &, Standard_Real &>(u, v); }, "ajust u,v values in UVBounds of the domain of the geometric shape <S>, according to Uperiodicity and VPeriodicity of the domain. <S> is assumed to be a face. u and/or v is/are not modified when the domain is not periodic in U and/or V .", py::arg("S"), py::arg("u"), py::arg("v"));
cls_TopOpeBRepTool_ShapeTool.def_static("Closed_", (Standard_Boolean (*)(const TopoDS_Shape &, const TopoDS_Shape &)) &TopOpeBRepTool_ShapeTool::Closed, "indicates wheter shape S1 is a closing shape on S2 or not.", py::arg("S1"), py::arg("S2"));
cls_TopOpeBRepTool_ShapeTool.def_static("PeriodizeParameter_", (Standard_Real (*)(const Standard_Real, const TopoDS_Shape &, const TopoDS_Shape &)) &TopOpeBRepTool_ShapeTool::PeriodizeParameter, "None", py::arg("par"), py::arg("EE"), py::arg("FF"));
cls_TopOpeBRepTool_ShapeTool.def_static("ShapesSameOriented_", (Standard_Boolean (*)(const TopoDS_Shape &, const TopoDS_Shape &)) &TopOpeBRepTool_ShapeTool::ShapesSameOriented, "None", py::arg("S1"), py::arg("S2"));
cls_TopOpeBRepTool_ShapeTool.def_static("SurfacesSameOriented_", (Standard_Boolean (*)(const BRepAdaptor_Surface &, const BRepAdaptor_Surface &)) &TopOpeBRepTool_ShapeTool::SurfacesSameOriented, "None", py::arg("S1"), py::arg("S2"));
cls_TopOpeBRepTool_ShapeTool.def_static("FacesSameOriented_", (Standard_Boolean (*)(const TopoDS_Shape &, const TopoDS_Shape &)) &TopOpeBRepTool_ShapeTool::FacesSameOriented, "None", py::arg("F1"), py::arg("F2"));
cls_TopOpeBRepTool_ShapeTool.def_static("CurvesSameOriented_", (Standard_Boolean (*)(const BRepAdaptor_Curve &, const BRepAdaptor_Curve &)) &TopOpeBRepTool_ShapeTool::CurvesSameOriented, "None", py::arg("C1"), py::arg("C2"));
cls_TopOpeBRepTool_ShapeTool.def_static("EdgesSameOriented_", (Standard_Boolean (*)(const TopoDS_Shape &, const TopoDS_Shape &)) &TopOpeBRepTool_ShapeTool::EdgesSameOriented, "None", py::arg("E1"), py::arg("E2"));
cls_TopOpeBRepTool_ShapeTool.def_static("EdgeData_", [](const BRepAdaptor_Curve & BRAC, const Standard_Real P, gp_Dir & T, gp_Dir & N, Standard_Real & C){ Standard_Real rv = TopOpeBRepTool_ShapeTool::EdgeData(BRAC, P, T, N, C); return std::tuple<Standard_Real, Standard_Real &>(rv, C); }, "Compute tangent T, normal N, curvature C at point of parameter P on curve BRAC. Returns the tolerance indicating if T,N are null.", py::arg("BRAC"), py::arg("P"), py::arg("T"), py::arg("N"), py::arg("C"));
cls_TopOpeBRepTool_ShapeTool.def_static("EdgeData_", [](const TopoDS_Shape & E, const Standard_Real P, gp_Dir & T, gp_Dir & N, Standard_Real & C){ Standard_Real rv = TopOpeBRepTool_ShapeTool::EdgeData(E, P, T, N, C); return std::tuple<Standard_Real, Standard_Real &>(rv, C); }, "Same as previous on edge E.", py::arg("E"), py::arg("P"), py::arg("T"), py::arg("N"), py::arg("C"));
cls_TopOpeBRepTool_ShapeTool.def_static("Resolution3dU_", (Standard_Real (*)(const opencascade::handle<Geom_Surface> &, const Standard_Real)) &TopOpeBRepTool_ShapeTool::Resolution3dU, "None", py::arg("SU"), py::arg("Tol2d"));
cls_TopOpeBRepTool_ShapeTool.def_static("Resolution3dV_", (Standard_Real (*)(const opencascade::handle<Geom_Surface> &, const Standard_Real)) &TopOpeBRepTool_ShapeTool::Resolution3dV, "None", py::arg("SU"), py::arg("Tol2d"));
cls_TopOpeBRepTool_ShapeTool.def_static("Resolution3d_", (Standard_Real (*)(const opencascade::handle<Geom_Surface> &, const Standard_Real)) &TopOpeBRepTool_ShapeTool::Resolution3d, "None", py::arg("SU"), py::arg("Tol2d"));
cls_TopOpeBRepTool_ShapeTool.def_static("Resolution3d_", (Standard_Real (*)(const TopoDS_Face &, const Standard_Real)) &TopOpeBRepTool_ShapeTool::Resolution3d, "None", py::arg("F"), py::arg("Tol2d"));

// CLASS: TOPOPEBREPTOOL_TOOL
py::class_<TopOpeBRepTool_TOOL> cls_TopOpeBRepTool_TOOL(mod, "TopOpeBRepTool_TOOL", "None");

// Methods
// cls_TopOpeBRepTool_TOOL.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepTool_TOOL::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepTool_TOOL.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepTool_TOOL::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepTool_TOOL.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepTool_TOOL::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepTool_TOOL.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepTool_TOOL::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepTool_TOOL.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepTool_TOOL::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepTool_TOOL.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepTool_TOOL::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepTool_TOOL.def_static("OriinSor_", [](const TopoDS_Shape & a0, const TopoDS_Shape & a1) -> Standard_Integer { return TopOpeBRepTool_TOOL::OriinSor(a0, a1); });
cls_TopOpeBRepTool_TOOL.def_static("OriinSor_", (Standard_Integer (*)(const TopoDS_Shape &, const TopoDS_Shape &, const Standard_Boolean)) &TopOpeBRepTool_TOOL::OriinSor, "None", py::arg("sub"), py::arg("S"), py::arg("checkclo"));
cls_TopOpeBRepTool_TOOL.def_static("OriinSorclosed_", (Standard_Integer (*)(const TopoDS_Shape &, const TopoDS_Shape &)) &TopOpeBRepTool_TOOL::OriinSorclosed, "None", py::arg("sub"), py::arg("S"));
cls_TopOpeBRepTool_TOOL.def_static("ClosedE_", (Standard_Boolean (*)(const TopoDS_Edge &, TopoDS_Vertex &)) &TopOpeBRepTool_TOOL::ClosedE, "None", py::arg("E"), py::arg("vclo"));
cls_TopOpeBRepTool_TOOL.def_static("ClosedS_", (Standard_Boolean (*)(const TopoDS_Face &)) &TopOpeBRepTool_TOOL::ClosedS, "None", py::arg("F"));
cls_TopOpeBRepTool_TOOL.def_static("IsClosingE_", (Standard_Boolean (*)(const TopoDS_Edge &, const TopoDS_Face &)) &TopOpeBRepTool_TOOL::IsClosingE, "None", py::arg("E"), py::arg("F"));
cls_TopOpeBRepTool_TOOL.def_static("IsClosingE_", (Standard_Boolean (*)(const TopoDS_Edge &, const TopoDS_Shape &, const TopoDS_Face &)) &TopOpeBRepTool_TOOL::IsClosingE, "None", py::arg("E"), py::arg("W"), py::arg("F"));
cls_TopOpeBRepTool_TOOL.def_static("Vertices_", (void (*)(const TopoDS_Edge &, TopTools_Array1OfShape &)) &TopOpeBRepTool_TOOL::Vertices, "None", py::arg("E"), py::arg("Vces"));
cls_TopOpeBRepTool_TOOL.def_static("Vertex_", (TopoDS_Vertex (*)(const Standard_Integer, const TopoDS_Edge &)) &TopOpeBRepTool_TOOL::Vertex, "None", py::arg("Iv"), py::arg("E"));
cls_TopOpeBRepTool_TOOL.def_static("ParE_", (Standard_Real (*)(const Standard_Integer, const TopoDS_Edge &)) &TopOpeBRepTool_TOOL::ParE, "None", py::arg("Iv"), py::arg("E"));
cls_TopOpeBRepTool_TOOL.def_static("OnBoundary_", (Standard_Integer (*)(const Standard_Real, const TopoDS_Edge &)) &TopOpeBRepTool_TOOL::OnBoundary, "None", py::arg("par"), py::arg("E"));
cls_TopOpeBRepTool_TOOL.def_static("UVF_", (gp_Pnt2d (*)(const Standard_Real, const TopOpeBRepTool_C2DF &)) &TopOpeBRepTool_TOOL::UVF, "None", py::arg("par"), py::arg("C2DF"));
cls_TopOpeBRepTool_TOOL.def_static("ParISO_", [](const gp_Pnt2d & p2d, const TopoDS_Edge & e, const TopoDS_Face & f, Standard_Real & pare){ Standard_Boolean rv = TopOpeBRepTool_TOOL::ParISO(p2d, e, f, pare); return std::tuple<Standard_Boolean, Standard_Real &>(rv, pare); }, "None", py::arg("p2d"), py::arg("e"), py::arg("f"), py::arg("pare"));
cls_TopOpeBRepTool_TOOL.def_static("ParE2d_", [](const gp_Pnt2d & p2d, const TopoDS_Edge & e, const TopoDS_Face & f, Standard_Real & par, Standard_Real & dist){ Standard_Boolean rv = TopOpeBRepTool_TOOL::ParE2d(p2d, e, f, par, dist); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, par, dist); }, "None", py::arg("p2d"), py::arg("e"), py::arg("f"), py::arg("par"), py::arg("dist"));
cls_TopOpeBRepTool_TOOL.def_static("Getduv_", (Standard_Boolean (*)(const TopoDS_Face &, const gp_Pnt2d &, const gp_Vec &, const Standard_Real, gp_Dir2d &)) &TopOpeBRepTool_TOOL::Getduv, "None", py::arg("f"), py::arg("uv"), py::arg("dir"), py::arg("factor"), py::arg("duv"));
cls_TopOpeBRepTool_TOOL.def_static("uvApp_", (Standard_Boolean (*)(const TopoDS_Face &, const TopoDS_Edge &, const Standard_Real, const Standard_Real, gp_Pnt2d &)) &TopOpeBRepTool_TOOL::uvApp, "None", py::arg("f"), py::arg("e"), py::arg("par"), py::arg("eps"), py::arg("uvapp"));
cls_TopOpeBRepTool_TOOL.def_static("TolUV_", (Standard_Real (*)(const TopoDS_Face &, const Standard_Real)) &TopOpeBRepTool_TOOL::TolUV, "None", py::arg("F"), py::arg("tol3d"));
cls_TopOpeBRepTool_TOOL.def_static("TolP_", (Standard_Real (*)(const TopoDS_Edge &, const TopoDS_Face &)) &TopOpeBRepTool_TOOL::TolP, "None", py::arg("E"), py::arg("F"));
cls_TopOpeBRepTool_TOOL.def_static("minDUV_", (Standard_Real (*)(const TopoDS_Face &)) &TopOpeBRepTool_TOOL::minDUV, "None", py::arg("F"));
cls_TopOpeBRepTool_TOOL.def_static("outUVbounds_", (Standard_Boolean (*)(const gp_Pnt2d &, const TopoDS_Face &)) &TopOpeBRepTool_TOOL::outUVbounds, "None", py::arg("uv"), py::arg("F"));
cls_TopOpeBRepTool_TOOL.def_static("stuvF_", [](const gp_Pnt2d & uv, const TopoDS_Face & F, Standard_Integer & onU, Standard_Integer & onV){ TopOpeBRepTool_TOOL::stuvF(uv, F, onU, onV); return std::tuple<Standard_Integer &, Standard_Integer &>(onU, onV); }, "None", py::arg("uv"), py::arg("F"), py::arg("onU"), py::arg("onV"));
cls_TopOpeBRepTool_TOOL.def_static("TggeomE_", (Standard_Boolean (*)(const Standard_Real, const BRepAdaptor_Curve &, gp_Vec &)) &TopOpeBRepTool_TOOL::TggeomE, "None", py::arg("par"), py::arg("BC"), py::arg("Tg"));
cls_TopOpeBRepTool_TOOL.def_static("TggeomE_", (Standard_Boolean (*)(const Standard_Real, const TopoDS_Edge &, gp_Vec &)) &TopOpeBRepTool_TOOL::TggeomE, "None", py::arg("par"), py::arg("E"), py::arg("Tg"));
cls_TopOpeBRepTool_TOOL.def_static("TgINSIDE_", [](const TopoDS_Vertex & v, const TopoDS_Edge & E, gp_Vec & Tg, Standard_Integer & OvinE){ Standard_Boolean rv = TopOpeBRepTool_TOOL::TgINSIDE(v, E, Tg, OvinE); return std::tuple<Standard_Boolean, Standard_Integer &>(rv, OvinE); }, "None", py::arg("v"), py::arg("E"), py::arg("Tg"), py::arg("OvinE"));
cls_TopOpeBRepTool_TOOL.def_static("Tg2d_", (gp_Vec2d (*)(const Standard_Integer, const TopoDS_Edge &, const TopOpeBRepTool_C2DF &)) &TopOpeBRepTool_TOOL::Tg2d, "None", py::arg("iv"), py::arg("E"), py::arg("C2DF"));
cls_TopOpeBRepTool_TOOL.def_static("Tg2dApp_", (gp_Vec2d (*)(const Standard_Integer, const TopoDS_Edge &, const TopOpeBRepTool_C2DF &, const Standard_Real)) &TopOpeBRepTool_TOOL::Tg2dApp, "None", py::arg("iv"), py::arg("E"), py::arg("C2DF"), py::arg("factor"));
cls_TopOpeBRepTool_TOOL.def_static("tryTg2dApp_", (gp_Vec2d (*)(const Standard_Integer, const TopoDS_Edge &, const TopOpeBRepTool_C2DF &, const Standard_Real)) &TopOpeBRepTool_TOOL::tryTg2dApp, "None", py::arg("iv"), py::arg("E"), py::arg("C2DF"), py::arg("factor"));
cls_TopOpeBRepTool_TOOL.def_static("XX_", (Standard_Boolean (*)(const gp_Pnt2d &, const TopoDS_Face &, const Standard_Real, const TopoDS_Edge &, gp_Dir &)) &TopOpeBRepTool_TOOL::XX, "None", py::arg("uv"), py::arg("f"), py::arg("par"), py::arg("e"), py::arg("xx"));
cls_TopOpeBRepTool_TOOL.def_static("Nt_", (Standard_Boolean (*)(const gp_Pnt2d &, const TopoDS_Face &, gp_Dir &)) &TopOpeBRepTool_TOOL::Nt, "None", py::arg("uv"), py::arg("f"), py::arg("normt"));
cls_TopOpeBRepTool_TOOL.def_static("NggeomF_", (Standard_Boolean (*)(const gp_Pnt2d &, const TopoDS_Face &, gp_Vec &)) &TopOpeBRepTool_TOOL::NggeomF, "None", py::arg("uv"), py::arg("F"), py::arg("ng"));
cls_TopOpeBRepTool_TOOL.def_static("NgApp_", (Standard_Boolean (*)(const Standard_Real, const TopoDS_Edge &, const TopoDS_Face &, const Standard_Real, gp_Dir &)) &TopOpeBRepTool_TOOL::NgApp, "None", py::arg("par"), py::arg("E"), py::arg("F"), py::arg("tola"), py::arg("ngApp"));
cls_TopOpeBRepTool_TOOL.def_static("tryNgApp_", (Standard_Boolean (*)(const Standard_Real, const TopoDS_Edge &, const TopoDS_Face &, const Standard_Real, gp_Dir &)) &TopOpeBRepTool_TOOL::tryNgApp, "None", py::arg("par"), py::arg("E"), py::arg("F"), py::arg("tola"), py::arg("ng"));
cls_TopOpeBRepTool_TOOL.def_static("tryOriEinF_", (Standard_Integer (*)(const Standard_Real, const TopoDS_Edge &, const TopoDS_Face &)) &TopOpeBRepTool_TOOL::tryOriEinF, "None", py::arg("par"), py::arg("E"), py::arg("F"));
cls_TopOpeBRepTool_TOOL.def_static("IsQuad_", (Standard_Boolean (*)(const TopoDS_Edge &)) &TopOpeBRepTool_TOOL::IsQuad, "None", py::arg("E"));
cls_TopOpeBRepTool_TOOL.def_static("IsQuad_", (Standard_Boolean (*)(const TopoDS_Face &)) &TopOpeBRepTool_TOOL::IsQuad, "None", py::arg("F"));
cls_TopOpeBRepTool_TOOL.def_static("CurvE_", [](const TopoDS_Edge & E, const Standard_Real par, const gp_Dir & tg0, Standard_Real & Curv){ Standard_Boolean rv = TopOpeBRepTool_TOOL::CurvE(E, par, tg0, Curv); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Curv); }, "None", py::arg("E"), py::arg("par"), py::arg("tg0"), py::arg("Curv"));
cls_TopOpeBRepTool_TOOL.def_static("CurvF_", [](const TopoDS_Face & F, const gp_Pnt2d & uv, const gp_Dir & tg0, Standard_Real & Curv, Standard_Boolean & direct){ Standard_Boolean rv = TopOpeBRepTool_TOOL::CurvF(F, uv, tg0, Curv, direct); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Boolean &>(rv, Curv, direct); }, "None", py::arg("F"), py::arg("uv"), py::arg("tg0"), py::arg("Curv"), py::arg("direct"));
cls_TopOpeBRepTool_TOOL.def_static("UVISO_", [](const opencascade::handle<Geom2d_Curve> & PC, Standard_Boolean & isou, Standard_Boolean & isov, gp_Dir2d & d2d, gp_Pnt2d & o2d){ Standard_Boolean rv = TopOpeBRepTool_TOOL::UVISO(PC, isou, isov, d2d, o2d); return std::tuple<Standard_Boolean, Standard_Boolean &, Standard_Boolean &>(rv, isou, isov); }, "None", py::arg("PC"), py::arg("isou"), py::arg("isov"), py::arg("d2d"), py::arg("o2d"));
cls_TopOpeBRepTool_TOOL.def_static("UVISO_", [](const TopOpeBRepTool_C2DF & C2DF, Standard_Boolean & isou, Standard_Boolean & isov, gp_Dir2d & d2d, gp_Pnt2d & o2d){ Standard_Boolean rv = TopOpeBRepTool_TOOL::UVISO(C2DF, isou, isov, d2d, o2d); return std::tuple<Standard_Boolean, Standard_Boolean &, Standard_Boolean &>(rv, isou, isov); }, "None", py::arg("C2DF"), py::arg("isou"), py::arg("isov"), py::arg("d2d"), py::arg("o2d"));
cls_TopOpeBRepTool_TOOL.def_static("UVISO_", [](const TopoDS_Edge & E, const TopoDS_Face & F, Standard_Boolean & isou, Standard_Boolean & isov, gp_Dir2d & d2d, gp_Pnt2d & o2d){ Standard_Boolean rv = TopOpeBRepTool_TOOL::UVISO(E, F, isou, isov, d2d, o2d); return std::tuple<Standard_Boolean, Standard_Boolean &, Standard_Boolean &>(rv, isou, isov); }, "None", py::arg("E"), py::arg("F"), py::arg("isou"), py::arg("isov"), py::arg("d2d"), py::arg("o2d"));
cls_TopOpeBRepTool_TOOL.def_static("IsonCLO_", (Standard_Boolean (*)(const opencascade::handle<Geom2d_Curve> &, const Standard_Boolean, const Standard_Real, const Standard_Real, const Standard_Real)) &TopOpeBRepTool_TOOL::IsonCLO, "None", py::arg("PC"), py::arg("onU"), py::arg("xfirst"), py::arg("xperiod"), py::arg("xtol"));
cls_TopOpeBRepTool_TOOL.def_static("IsonCLO_", (Standard_Boolean (*)(const TopOpeBRepTool_C2DF &, const Standard_Boolean, const Standard_Real, const Standard_Real, const Standard_Real)) &TopOpeBRepTool_TOOL::IsonCLO, "None", py::arg("C2DF"), py::arg("onU"), py::arg("xfirst"), py::arg("xperiod"), py::arg("xtol"));
cls_TopOpeBRepTool_TOOL.def_static("TrslUV_", (void (*)(const gp_Vec2d &, TopOpeBRepTool_C2DF &)) &TopOpeBRepTool_TOOL::TrslUV, "None", py::arg("t2d"), py::arg("C2DF"));
cls_TopOpeBRepTool_TOOL.def_static("TrslUVModifE_", (Standard_Boolean (*)(const gp_Vec2d &, const TopoDS_Face &, TopoDS_Edge &)) &TopOpeBRepTool_TOOL::TrslUVModifE, "None", py::arg("t2d"), py::arg("F"), py::arg("E"));
cls_TopOpeBRepTool_TOOL.def_static("Matter_", (Standard_Real (*)(const gp_Vec &, const gp_Vec &, const gp_Vec &)) &TopOpeBRepTool_TOOL::Matter, "None", py::arg("d1"), py::arg("d2"), py::arg("ref"));
cls_TopOpeBRepTool_TOOL.def_static("Matter_", (Standard_Real (*)(const gp_Vec2d &, const gp_Vec2d &)) &TopOpeBRepTool_TOOL::Matter, "None", py::arg("d1"), py::arg("d2"));
cls_TopOpeBRepTool_TOOL.def_static("Matter_", [](const gp_Dir & xx1, const gp_Dir & nt1, const gp_Dir & xx2, const gp_Dir & nt2, const Standard_Real tola, Standard_Real & Ang){ Standard_Boolean rv = TopOpeBRepTool_TOOL::Matter(xx1, nt1, xx2, nt2, tola, Ang); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Ang); }, "None", py::arg("xx1"), py::arg("nt1"), py::arg("xx2"), py::arg("nt2"), py::arg("tola"), py::arg("Ang"));
cls_TopOpeBRepTool_TOOL.def_static("Matter_", [](const TopoDS_Face & f1, const TopoDS_Face & f2, const TopoDS_Edge & e, const Standard_Real pare, const Standard_Real tola, Standard_Real & Ang){ Standard_Boolean rv = TopOpeBRepTool_TOOL::Matter(f1, f2, e, pare, tola, Ang); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Ang); }, "None", py::arg("f1"), py::arg("f2"), py::arg("e"), py::arg("pare"), py::arg("tola"), py::arg("Ang"));
cls_TopOpeBRepTool_TOOL.def_static("MatterKPtg_", [](const TopoDS_Face & f1, const TopoDS_Face & f2, const TopoDS_Edge & e, Standard_Real & Ang){ Standard_Boolean rv = TopOpeBRepTool_TOOL::MatterKPtg(f1, f2, e, Ang); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Ang); }, "None", py::arg("f1"), py::arg("f2"), py::arg("e"), py::arg("Ang"));
cls_TopOpeBRepTool_TOOL.def_static("Getstp3dF_", (Standard_Boolean (*)(const gp_Pnt &, const TopoDS_Face &, gp_Pnt2d &, TopAbs_State &)) &TopOpeBRepTool_TOOL::Getstp3dF, "None", py::arg("p"), py::arg("f"), py::arg("uv"), py::arg("st"));
cls_TopOpeBRepTool_TOOL.def_static("SplitE_", (Standard_Boolean (*)(const TopoDS_Edge &, TopTools_ListOfShape &)) &TopOpeBRepTool_TOOL::SplitE, "None", py::arg("Eanc"), py::arg("Splits"));
cls_TopOpeBRepTool_TOOL.def_static("MkShell_", (void (*)(const TopTools_ListOfShape &, TopoDS_Shape &)) &TopOpeBRepTool_TOOL::MkShell, "None", py::arg("lF"), py::arg("She"));
cls_TopOpeBRepTool_TOOL.def_static("Remove_", (Standard_Boolean (*)(TopTools_ListOfShape &, const TopoDS_Shape &)) &TopOpeBRepTool_TOOL::Remove, "None", py::arg("loS"), py::arg("toremove"));
cls_TopOpeBRepTool_TOOL.def_static("WireToFace_", (Standard_Boolean (*)(const TopoDS_Face &, const TopTools_DataMapOfShapeListOfShape &, TopTools_ListOfShape &)) &TopOpeBRepTool_TOOL::WireToFace, "None", py::arg("Fref"), py::arg("mapWlow"), py::arg("lFs"));
cls_TopOpeBRepTool_TOOL.def_static("EdgeONFace_", [](const Standard_Real par, const TopoDS_Edge & ed, const gp_Pnt2d & uv, const TopoDS_Face & fa, Standard_Boolean & isonfa){ Standard_Boolean rv = TopOpeBRepTool_TOOL::EdgeONFace(par, ed, uv, fa, isonfa); return std::tuple<Standard_Boolean, Standard_Boolean &>(rv, isonfa); }, "None", py::arg("par"), py::arg("ed"), py::arg("uv"), py::arg("fa"), py::arg("isonfa"));


}
