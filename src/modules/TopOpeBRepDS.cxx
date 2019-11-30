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
#include <TopOpeBRepDS_DataStructure.hxx>
#include <TopOpeBRepTool_ShapeClassifier.hxx>
#include <TopOpeBRepDS_Kind.hxx>
#include <TopOpeBRepDS_Config.hxx>
#include <TopOpeBRepDS_CheckStatus.hxx>
#include <Standard.hxx>
#include <TopAbs_State.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <TopAbs_Orientation.hxx>
#include <Standard_TypeDef.hxx>
#include <TopOpeBRepDS_Transition.hxx>
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <TopOpeBRepDS_Interference.hxx>
#include <Standard_Std.hxx>
#include <Standard_Type.hxx>
#include <Geom2d_Curve.hxx>
#include <TopOpeBRepDS_SurfaceCurveInterference.hxx>
#include <TopOpeBRepDS_CurvePointInterference.hxx>
#include <Geom_Surface.hxx>
#include <TopOpeBRepDS_Surface.hxx>
#include <NCollection_List.hxx>
#include <TopOpeBRepDS_ListOfInterference.hxx>
#include <TopOpeBRepDS_GeometryData.hxx>
#include <TopOpeBRepDS_SurfaceData.hxx>
#include <NCollection_DataMap.hxx>
#include <TColStd_MapIntegerHasher.hxx>
#include <TopOpeBRepDS_MapOfSurface.hxx>
#include <Geom_Curve.hxx>
#include <TopoDS_Shape.hxx>
#include <TopOpeBRepDS_Curve.hxx>
#include <TopOpeBRepDS_CurveData.hxx>
#include <TopOpeBRepDS_MapOfCurve.hxx>
#include <gp_Pnt.hxx>
#include <TopOpeBRepDS_Point.hxx>
#include <TopOpeBRepDS_PointData.hxx>
#include <TopOpeBRepDS_MapOfPoint.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TopOpeBRepDS_ShapeData.hxx>
#include <NCollection_IndexedDataMap.hxx>
#include <TopTools_ShapeMapHasher.hxx>
#include <TopOpeBRepDS_MapOfShapeData.hxx>
#include <TopOpeBRepDS_ShapeSurface.hxx>
#include <TopOpeBRepDS_ShapeWithState.hxx>
#include <TopOpeBRepDS_IndexedDataMapOfShapeWithState.hxx>
#include <TopoDS_Edge.hxx>
#include <TopTools_IndexedMapOfShape.hxx>
#include <TopOpeBRepDS_SurfaceExplorer.hxx>
#include <TopOpeBRepDS_CurveExplorer.hxx>
#include <TopOpeBRepDS_PointExplorer.hxx>
#include <TopOpeBRepTool_OutCurveType.hxx>
#include <TopOpeBRepTool_GeomTool.hxx>
#include <TopoDS_Vertex.hxx>
#include <TopoDS_Face.hxx>
#include <TopOpeBRepDS_HDataStructure.hxx>
#include <BRep_Builder.hxx>
#include <TopOpeBRepTool_CurveTool.hxx>
#include <TopOpeBRepDS_BuildTool.hxx>
#include <TopOpeBRepDS_ListOfShapeOn1State.hxx>
#include <TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State.hxx>
#include <TopOpeBRepDS_DataMapOfShapeState.hxx>
#include <TopOpeBRepDS_ShapeShapeInterference.hxx>
#include <TopOpeBRepDS_EdgeVertexInterference.hxx>
#include <TopOpeBRepDS_FaceEdgeInterference.hxx>
#include <TopOpeBRepDS_InterferenceIterator.hxx>
#include <TopOpeBRepDS_CurveIterator.hxx>
#include <TopOpeBRepDS_PointIterator.hxx>
#include <TopOpeBRepDS_SurfaceIterator.hxx>
#include <TCollection_AsciiString.hxx>
#include <TopOpeBRepDS_PDataStructure.hxx>
#include <Standard_OStream.hxx>
#include <TopOpeBRepDS_TKI.hxx>
#include <TopOpeBRepDS_SolidSurfaceInterference.hxx>
#include <TopOpeBRepDS_InterferenceTool.hxx>
#include <TopOpeBRepDS_Dumper.hxx>
#include <TopOpeBRepDS_Marker.hxx>
#include <TopOpeBRepDS_EdgeInterferenceTool.hxx>
#include <TopOpeBRepDS_Edge3dInterferenceTool.hxx>
#include <TopOpeBRepDS_FaceInterferenceTool.hxx>
#include <TopOpeBRepDS_Filter.hxx>
#include <TopOpeBRepDS_Reducer.hxx>
#include <TopOpeBRepDS_TOOL.hxx>
#include <TopOpeBRepDS_FIR.hxx>
#include <TopOpeBRepDS_EIR.hxx>
#include <TopOpeBRepDS_Check.hxx>
#include <TopOpeBRepDS_GapFiller.hxx>
#include <TopOpeBRepDS_GapTool.hxx>
#include <TopOpeBRepDS_Association.hxx>
#include <TopOpeBRepDS_Explorer.hxx>
#include <TopOpeBRepDS.hxx>
#include <TopOpeBRepDS_DataMapOfIntegerListOfInterference.hxx>
#include <NCollection_Array1.hxx>
#include <TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference.hxx>
#include <TColStd_MapTransientHasher.hxx>
#include <TopOpeBRepDS_DataMapOfInterferenceListOfInterference.hxx>
#include <TopOpeBRepDS_DataMapOfCheckStatus.hxx>
#include <TopOpeBRepDS_DataMapOfInterferenceShape.hxx>
#include <TopOpeBRepDS_MapOfIntegerShapeData.hxx>
#include <NCollection_DoubleMap.hxx>
#include <TopOpeBRepDS_DoubleMapOfIntegerShape.hxx>
#include <TopTrans_SurfaceTransition.hxx>
#include <gp_Dir.hxx>
#include <TopTrans_CurveTransition.hxx>
#include <TopOpeBRepTool_PShapeClassifier.hxx>
#include <TColStd_MapOfInteger.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference.hxx>
#include <TopOpeBRepDS_IndexedDataMapOfVertexPoint.hxx>
#include <TColStd_HArray1OfBoolean.hxx>
#include <bind_NCollection_List.hxx>
#include <bind_NCollection_TListIterator.hxx>
#include <bind_NCollection_DataMap.hxx>
#include <bind_NCollection_IndexedDataMap.hxx>
#include <bind_NCollection_Array1.hxx>
#include <bind_NCollection_DoubleMap.hxx>

PYBIND11_MODULE(TopOpeBRepDS, mod) {

py::module::import("OCCT.TopOpeBRepTool");
py::module::import("OCCT.Standard");
py::module::import("OCCT.TopAbs");
py::module::import("OCCT.Geom2d");
py::module::import("OCCT.Geom");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.gp");
py::module::import("OCCT.TopTools");
py::module::import("OCCT.BRep");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.TopTrans");

// ENUM: TOPOPEBREPDS_KIND
py::enum_<TopOpeBRepDS_Kind>(mod, "TopOpeBRepDS_Kind", "different types of objects in DataStructure")
	.value("TopOpeBRepDS_POINT", TopOpeBRepDS_Kind::TopOpeBRepDS_POINT)
	.value("TopOpeBRepDS_CURVE", TopOpeBRepDS_Kind::TopOpeBRepDS_CURVE)
	.value("TopOpeBRepDS_SURFACE", TopOpeBRepDS_Kind::TopOpeBRepDS_SURFACE)
	.value("TopOpeBRepDS_VERTEX", TopOpeBRepDS_Kind::TopOpeBRepDS_VERTEX)
	.value("TopOpeBRepDS_EDGE", TopOpeBRepDS_Kind::TopOpeBRepDS_EDGE)
	.value("TopOpeBRepDS_WIRE", TopOpeBRepDS_Kind::TopOpeBRepDS_WIRE)
	.value("TopOpeBRepDS_FACE", TopOpeBRepDS_Kind::TopOpeBRepDS_FACE)
	.value("TopOpeBRepDS_SHELL", TopOpeBRepDS_Kind::TopOpeBRepDS_SHELL)
	.value("TopOpeBRepDS_SOLID", TopOpeBRepDS_Kind::TopOpeBRepDS_SOLID)
	.value("TopOpeBRepDS_COMPSOLID", TopOpeBRepDS_Kind::TopOpeBRepDS_COMPSOLID)
	.value("TopOpeBRepDS_COMPOUND", TopOpeBRepDS_Kind::TopOpeBRepDS_COMPOUND)
	.value("TopOpeBRepDS_UNKNOWN", TopOpeBRepDS_Kind::TopOpeBRepDS_UNKNOWN)
	.export_values();


// ENUM: TOPOPEBREPDS_CONFIG
py::enum_<TopOpeBRepDS_Config>(mod, "TopOpeBRepDS_Config", "None")
	.value("TopOpeBRepDS_UNSHGEOMETRY", TopOpeBRepDS_Config::TopOpeBRepDS_UNSHGEOMETRY)
	.value("TopOpeBRepDS_SAMEORIENTED", TopOpeBRepDS_Config::TopOpeBRepDS_SAMEORIENTED)
	.value("TopOpeBRepDS_DIFFORIENTED", TopOpeBRepDS_Config::TopOpeBRepDS_DIFFORIENTED)
	.export_values();


// ENUM: TOPOPEBREPDS_CHECKSTATUS
py::enum_<TopOpeBRepDS_CheckStatus>(mod, "TopOpeBRepDS_CheckStatus", "None")
	.value("TopOpeBRepDS_OK", TopOpeBRepDS_CheckStatus::TopOpeBRepDS_OK)
	.value("TopOpeBRepDS_NOK", TopOpeBRepDS_CheckStatus::TopOpeBRepDS_NOK)
	.export_values();


// CLASS: TOPOPEBREPDS_TRANSITION
py::class_<TopOpeBRepDS_Transition> cls_TopOpeBRepDS_Transition(mod, "TopOpeBRepDS_Transition", "None");

// Constructors
cls_TopOpeBRepDS_Transition.def(py::init<>());
cls_TopOpeBRepDS_Transition.def(py::init<const TopAbs_State, const TopAbs_State>(), py::arg("StateBefore"), py::arg("StateAfter"));
cls_TopOpeBRepDS_Transition.def(py::init<const TopAbs_State, const TopAbs_State, const TopAbs_ShapeEnum>(), py::arg("StateBefore"), py::arg("StateAfter"), py::arg("ShapeBefore"));
cls_TopOpeBRepDS_Transition.def(py::init<const TopAbs_State, const TopAbs_State, const TopAbs_ShapeEnum, const TopAbs_ShapeEnum>(), py::arg("StateBefore"), py::arg("StateAfter"), py::arg("ShapeBefore"), py::arg("ShapeAfter"));
cls_TopOpeBRepDS_Transition.def(py::init<const TopAbs_Orientation>(), py::arg("O"));

// Methods
// cls_TopOpeBRepDS_Transition.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepDS_Transition::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepDS_Transition.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepDS_Transition::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_Transition.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepDS_Transition::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepDS_Transition.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepDS_Transition::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_Transition.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepDS_Transition::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepDS_Transition.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepDS_Transition::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepDS_Transition.def("Set", [](TopOpeBRepDS_Transition &self, const TopAbs_State a0, const TopAbs_State a1) -> void { return self.Set(a0, a1); });
cls_TopOpeBRepDS_Transition.def("Set", [](TopOpeBRepDS_Transition &self, const TopAbs_State a0, const TopAbs_State a1, const TopAbs_ShapeEnum a2) -> void { return self.Set(a0, a1, a2); });
cls_TopOpeBRepDS_Transition.def("Set", (void (TopOpeBRepDS_Transition::*)(const TopAbs_State, const TopAbs_State, const TopAbs_ShapeEnum, const TopAbs_ShapeEnum)) &TopOpeBRepDS_Transition::Set, "None", py::arg("StateBefore"), py::arg("StateAfter"), py::arg("ShapeBefore"), py::arg("ShapeAfter"));
cls_TopOpeBRepDS_Transition.def("StateBefore", (void (TopOpeBRepDS_Transition::*)(const TopAbs_State)) &TopOpeBRepDS_Transition::StateBefore, "None", py::arg("S"));
cls_TopOpeBRepDS_Transition.def("StateAfter", (void (TopOpeBRepDS_Transition::*)(const TopAbs_State)) &TopOpeBRepDS_Transition::StateAfter, "None", py::arg("S"));
cls_TopOpeBRepDS_Transition.def("ShapeBefore", (void (TopOpeBRepDS_Transition::*)(const TopAbs_ShapeEnum)) &TopOpeBRepDS_Transition::ShapeBefore, "None", py::arg("SE"));
cls_TopOpeBRepDS_Transition.def("ShapeAfter", (void (TopOpeBRepDS_Transition::*)(const TopAbs_ShapeEnum)) &TopOpeBRepDS_Transition::ShapeAfter, "None", py::arg("SE"));
cls_TopOpeBRepDS_Transition.def("Before", [](TopOpeBRepDS_Transition &self, const TopAbs_State a0) -> void { return self.Before(a0); });
cls_TopOpeBRepDS_Transition.def("Before", (void (TopOpeBRepDS_Transition::*)(const TopAbs_State, const TopAbs_ShapeEnum)) &TopOpeBRepDS_Transition::Before, "None", py::arg("S"), py::arg("ShapeBefore"));
cls_TopOpeBRepDS_Transition.def("After", [](TopOpeBRepDS_Transition &self, const TopAbs_State a0) -> void { return self.After(a0); });
cls_TopOpeBRepDS_Transition.def("After", (void (TopOpeBRepDS_Transition::*)(const TopAbs_State, const TopAbs_ShapeEnum)) &TopOpeBRepDS_Transition::After, "None", py::arg("S"), py::arg("ShapeAfter"));
cls_TopOpeBRepDS_Transition.def("Index", (void (TopOpeBRepDS_Transition::*)(const Standard_Integer)) &TopOpeBRepDS_Transition::Index, "None", py::arg("I"));
cls_TopOpeBRepDS_Transition.def("IndexBefore", (void (TopOpeBRepDS_Transition::*)(const Standard_Integer)) &TopOpeBRepDS_Transition::IndexBefore, "None", py::arg("I"));
cls_TopOpeBRepDS_Transition.def("IndexAfter", (void (TopOpeBRepDS_Transition::*)(const Standard_Integer)) &TopOpeBRepDS_Transition::IndexAfter, "None", py::arg("I"));
cls_TopOpeBRepDS_Transition.def("Before", (TopAbs_State (TopOpeBRepDS_Transition::*)() const) &TopOpeBRepDS_Transition::Before, "None");
cls_TopOpeBRepDS_Transition.def("ONBefore", (TopAbs_ShapeEnum (TopOpeBRepDS_Transition::*)() const) &TopOpeBRepDS_Transition::ONBefore, "None");
cls_TopOpeBRepDS_Transition.def("After", (TopAbs_State (TopOpeBRepDS_Transition::*)() const) &TopOpeBRepDS_Transition::After, "None");
cls_TopOpeBRepDS_Transition.def("ONAfter", (TopAbs_ShapeEnum (TopOpeBRepDS_Transition::*)() const) &TopOpeBRepDS_Transition::ONAfter, "None");
cls_TopOpeBRepDS_Transition.def("ShapeBefore", (TopAbs_ShapeEnum (TopOpeBRepDS_Transition::*)() const) &TopOpeBRepDS_Transition::ShapeBefore, "None");
cls_TopOpeBRepDS_Transition.def("ShapeAfter", (TopAbs_ShapeEnum (TopOpeBRepDS_Transition::*)() const) &TopOpeBRepDS_Transition::ShapeAfter, "None");
cls_TopOpeBRepDS_Transition.def("Index", (Standard_Integer (TopOpeBRepDS_Transition::*)() const) &TopOpeBRepDS_Transition::Index, "None");
cls_TopOpeBRepDS_Transition.def("IndexBefore", (Standard_Integer (TopOpeBRepDS_Transition::*)() const) &TopOpeBRepDS_Transition::IndexBefore, "None");
cls_TopOpeBRepDS_Transition.def("IndexAfter", (Standard_Integer (TopOpeBRepDS_Transition::*)() const) &TopOpeBRepDS_Transition::IndexAfter, "None");
cls_TopOpeBRepDS_Transition.def("Set", (void (TopOpeBRepDS_Transition::*)(const TopAbs_Orientation)) &TopOpeBRepDS_Transition::Set, "set the transition corresponding to orientation <O>", py::arg("O"));
cls_TopOpeBRepDS_Transition.def("Orientation", [](TopOpeBRepDS_Transition &self, const TopAbs_State a0) -> TopAbs_Orientation { return self.Orientation(a0); });
cls_TopOpeBRepDS_Transition.def("Orientation", (TopAbs_Orientation (TopOpeBRepDS_Transition::*)(const TopAbs_State, const TopAbs_ShapeEnum) const) &TopOpeBRepDS_Transition::Orientation, "returns the orientation corresponding to state <S>", py::arg("S"), py::arg("T"));
cls_TopOpeBRepDS_Transition.def("Complement", (TopOpeBRepDS_Transition (TopOpeBRepDS_Transition::*)() const) &TopOpeBRepDS_Transition::Complement, "None");
cls_TopOpeBRepDS_Transition.def("IsUnknown", (Standard_Boolean (TopOpeBRepDS_Transition::*)() const) &TopOpeBRepDS_Transition::IsUnknown, "returns True if both states are UNKNOWN");

// CLASS: TOPOPEBREPDS_INTERFERENCE
py::class_<TopOpeBRepDS_Interference, opencascade::handle<TopOpeBRepDS_Interference>, Standard_Transient> cls_TopOpeBRepDS_Interference(mod, "TopOpeBRepDS_Interference", "An interference is the description of the attachment of a new geometry on a geometry. For example an intersection point on an Edge or on a Curve.");

// Constructors
cls_TopOpeBRepDS_Interference.def(py::init<>());
cls_TopOpeBRepDS_Interference.def(py::init<const TopOpeBRepDS_Transition &, const TopOpeBRepDS_Kind, const Standard_Integer, const TopOpeBRepDS_Kind, const Standard_Integer>(), py::arg("Transition"), py::arg("SupportType"), py::arg("Support"), py::arg("GeometryType"), py::arg("Geometry"));
cls_TopOpeBRepDS_Interference.def(py::init<const opencascade::handle<TopOpeBRepDS_Interference> &>(), py::arg("I"));

// Methods
cls_TopOpeBRepDS_Interference.def("Transition", (const TopOpeBRepDS_Transition & (TopOpeBRepDS_Interference::*)() const) &TopOpeBRepDS_Interference::Transition, "None");
cls_TopOpeBRepDS_Interference.def("ChangeTransition", (TopOpeBRepDS_Transition & (TopOpeBRepDS_Interference::*)()) &TopOpeBRepDS_Interference::ChangeTransition, "None");
cls_TopOpeBRepDS_Interference.def("Transition", (void (TopOpeBRepDS_Interference::*)(const TopOpeBRepDS_Transition &)) &TopOpeBRepDS_Interference::Transition, "None", py::arg("T"));
cls_TopOpeBRepDS_Interference.def("GKGSKS", [](TopOpeBRepDS_Interference &self, TopOpeBRepDS_Kind & GK, Standard_Integer & G, TopOpeBRepDS_Kind & SK, Standard_Integer & S){ self.GKGSKS(GK, G, SK, S); return std::tuple<Standard_Integer &, Standard_Integer &>(G, S); }, "return GeometryType + Geometry + SupportType + Support", py::arg("GK"), py::arg("G"), py::arg("SK"), py::arg("S"));
cls_TopOpeBRepDS_Interference.def("SupportType", (TopOpeBRepDS_Kind (TopOpeBRepDS_Interference::*)() const) &TopOpeBRepDS_Interference::SupportType, "None");
cls_TopOpeBRepDS_Interference.def("Support", (Standard_Integer (TopOpeBRepDS_Interference::*)() const) &TopOpeBRepDS_Interference::Support, "None");
cls_TopOpeBRepDS_Interference.def("GeometryType", (TopOpeBRepDS_Kind (TopOpeBRepDS_Interference::*)() const) &TopOpeBRepDS_Interference::GeometryType, "None");
cls_TopOpeBRepDS_Interference.def("Geometry", (Standard_Integer (TopOpeBRepDS_Interference::*)() const) &TopOpeBRepDS_Interference::Geometry, "None");
cls_TopOpeBRepDS_Interference.def("SetGeometry", (void (TopOpeBRepDS_Interference::*)(const Standard_Integer)) &TopOpeBRepDS_Interference::SetGeometry, "None", py::arg("GI"));
cls_TopOpeBRepDS_Interference.def("SupportType", (void (TopOpeBRepDS_Interference::*)(const TopOpeBRepDS_Kind)) &TopOpeBRepDS_Interference::SupportType, "None", py::arg("ST"));
cls_TopOpeBRepDS_Interference.def("Support", (void (TopOpeBRepDS_Interference::*)(const Standard_Integer)) &TopOpeBRepDS_Interference::Support, "None", py::arg("S"));
cls_TopOpeBRepDS_Interference.def("GeometryType", (void (TopOpeBRepDS_Interference::*)(const TopOpeBRepDS_Kind)) &TopOpeBRepDS_Interference::GeometryType, "None", py::arg("GT"));
cls_TopOpeBRepDS_Interference.def("Geometry", (void (TopOpeBRepDS_Interference::*)(const Standard_Integer)) &TopOpeBRepDS_Interference::Geometry, "None", py::arg("G"));
cls_TopOpeBRepDS_Interference.def("HasSameSupport", (Standard_Boolean (TopOpeBRepDS_Interference::*)(const opencascade::handle<TopOpeBRepDS_Interference> &) const) &TopOpeBRepDS_Interference::HasSameSupport, "None", py::arg("Other"));
cls_TopOpeBRepDS_Interference.def("HasSameGeometry", (Standard_Boolean (TopOpeBRepDS_Interference::*)(const opencascade::handle<TopOpeBRepDS_Interference> &) const) &TopOpeBRepDS_Interference::HasSameGeometry, "None", py::arg("Other"));
cls_TopOpeBRepDS_Interference.def_static("get_type_name_", (const char * (*)()) &TopOpeBRepDS_Interference::get_type_name, "None");
cls_TopOpeBRepDS_Interference.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TopOpeBRepDS_Interference::get_type_descriptor, "None");
cls_TopOpeBRepDS_Interference.def("DynamicType", (const opencascade::handle<Standard_Type> & (TopOpeBRepDS_Interference::*)() const) &TopOpeBRepDS_Interference::DynamicType, "None");

// CLASS: TOPOPEBREPDS_SURFACECURVEINTERFERENCE
py::class_<TopOpeBRepDS_SurfaceCurveInterference, opencascade::handle<TopOpeBRepDS_SurfaceCurveInterference>, TopOpeBRepDS_Interference> cls_TopOpeBRepDS_SurfaceCurveInterference(mod, "TopOpeBRepDS_SurfaceCurveInterference", "an interference with a 2d curve");

// Constructors
cls_TopOpeBRepDS_SurfaceCurveInterference.def(py::init<>());
cls_TopOpeBRepDS_SurfaceCurveInterference.def(py::init<const TopOpeBRepDS_Transition &, const TopOpeBRepDS_Kind, const Standard_Integer, const TopOpeBRepDS_Kind, const Standard_Integer, const opencascade::handle<Geom2d_Curve> &>(), py::arg("Transition"), py::arg("SupportType"), py::arg("Support"), py::arg("GeometryType"), py::arg("Geometry"), py::arg("PC"));
cls_TopOpeBRepDS_SurfaceCurveInterference.def(py::init<const opencascade::handle<TopOpeBRepDS_Interference> &>(), py::arg("I"));

// Methods
cls_TopOpeBRepDS_SurfaceCurveInterference.def("PCurve", (const opencascade::handle<Geom2d_Curve> & (TopOpeBRepDS_SurfaceCurveInterference::*)() const) &TopOpeBRepDS_SurfaceCurveInterference::PCurve, "None");
cls_TopOpeBRepDS_SurfaceCurveInterference.def("PCurve", (void (TopOpeBRepDS_SurfaceCurveInterference::*)(const opencascade::handle<Geom2d_Curve> &)) &TopOpeBRepDS_SurfaceCurveInterference::PCurve, "None", py::arg("PC"));
cls_TopOpeBRepDS_SurfaceCurveInterference.def_static("get_type_name_", (const char * (*)()) &TopOpeBRepDS_SurfaceCurveInterference::get_type_name, "None");
cls_TopOpeBRepDS_SurfaceCurveInterference.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TopOpeBRepDS_SurfaceCurveInterference::get_type_descriptor, "None");
cls_TopOpeBRepDS_SurfaceCurveInterference.def("DynamicType", (const opencascade::handle<Standard_Type> & (TopOpeBRepDS_SurfaceCurveInterference::*)() const) &TopOpeBRepDS_SurfaceCurveInterference::DynamicType, "None");

// CLASS: TOPOPEBREPDS_CURVEPOINTINTERFERENCE
py::class_<TopOpeBRepDS_CurvePointInterference, opencascade::handle<TopOpeBRepDS_CurvePointInterference>, TopOpeBRepDS_Interference> cls_TopOpeBRepDS_CurvePointInterference(mod, "TopOpeBRepDS_CurvePointInterference", "An interference with a parameter.");

// Constructors
cls_TopOpeBRepDS_CurvePointInterference.def(py::init<const TopOpeBRepDS_Transition &, const TopOpeBRepDS_Kind, const Standard_Integer, const TopOpeBRepDS_Kind, const Standard_Integer, const Standard_Real>(), py::arg("T"), py::arg("ST"), py::arg("S"), py::arg("GT"), py::arg("G"), py::arg("P"));

// Methods
cls_TopOpeBRepDS_CurvePointInterference.def("Parameter", (Standard_Real (TopOpeBRepDS_CurvePointInterference::*)() const) &TopOpeBRepDS_CurvePointInterference::Parameter, "None");
cls_TopOpeBRepDS_CurvePointInterference.def("Parameter", (void (TopOpeBRepDS_CurvePointInterference::*)(const Standard_Real)) &TopOpeBRepDS_CurvePointInterference::Parameter, "None", py::arg("P"));
cls_TopOpeBRepDS_CurvePointInterference.def_static("get_type_name_", (const char * (*)()) &TopOpeBRepDS_CurvePointInterference::get_type_name, "None");
cls_TopOpeBRepDS_CurvePointInterference.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TopOpeBRepDS_CurvePointInterference::get_type_descriptor, "None");
cls_TopOpeBRepDS_CurvePointInterference.def("DynamicType", (const opencascade::handle<Standard_Type> & (TopOpeBRepDS_CurvePointInterference::*)() const) &TopOpeBRepDS_CurvePointInterference::DynamicType, "None");

// CLASS: TOPOPEBREPDS_SURFACE
py::class_<TopOpeBRepDS_Surface> cls_TopOpeBRepDS_Surface(mod, "TopOpeBRepDS_Surface", "A Geom surface and a tolerance.");

// Constructors
cls_TopOpeBRepDS_Surface.def(py::init<>());
cls_TopOpeBRepDS_Surface.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Real>(), py::arg("P"), py::arg("T"));
cls_TopOpeBRepDS_Surface.def(py::init<const TopOpeBRepDS_Surface &>(), py::arg("Other"));

// Methods
// cls_TopOpeBRepDS_Surface.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepDS_Surface::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepDS_Surface.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepDS_Surface::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_Surface.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepDS_Surface::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepDS_Surface.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepDS_Surface::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_Surface.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepDS_Surface::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepDS_Surface.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepDS_Surface::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepDS_Surface.def("Assign", (void (TopOpeBRepDS_Surface::*)(const TopOpeBRepDS_Surface &)) &TopOpeBRepDS_Surface::Assign, "None", py::arg("Other"));
// cls_TopOpeBRepDS_Surface.def("operator=", (void (TopOpeBRepDS_Surface::*)(const TopOpeBRepDS_Surface &)) &TopOpeBRepDS_Surface::operator=, "None", py::arg("Other"));
cls_TopOpeBRepDS_Surface.def("Surface", (const opencascade::handle<Geom_Surface> & (TopOpeBRepDS_Surface::*)() const) &TopOpeBRepDS_Surface::Surface, "None");
cls_TopOpeBRepDS_Surface.def("Tolerance", (Standard_Real (TopOpeBRepDS_Surface::*)() const) &TopOpeBRepDS_Surface::Tolerance, "None");
cls_TopOpeBRepDS_Surface.def("Tolerance", (void (TopOpeBRepDS_Surface::*)(Standard_Real)) &TopOpeBRepDS_Surface::Tolerance, "Update the tolerance", py::arg("theTol"));
cls_TopOpeBRepDS_Surface.def("Keep", (Standard_Boolean (TopOpeBRepDS_Surface::*)() const) &TopOpeBRepDS_Surface::Keep, "None");
cls_TopOpeBRepDS_Surface.def("ChangeKeep", (void (TopOpeBRepDS_Surface::*)(Standard_Boolean)) &TopOpeBRepDS_Surface::ChangeKeep, "None", py::arg("theToKeep"));

// TYPEDEF: TOPOPEBREPDS_LISTOFINTERFERENCE
bind_NCollection_List<opencascade::handle<TopOpeBRepDS_Interference> >(mod, "TopOpeBRepDS_ListOfInterference", py::module_local(false));

// TYPEDEF: TOPOPEBREPDS_LISTITERATOROFLISTOFINTERFERENCE
bind_NCollection_TListIterator<opencascade::handle<TopOpeBRepDS_Interference> >(mod, "TopOpeBRepDS_ListIteratorOfListOfInterference", py::module_local(false));

// CLASS: TOPOPEBREPDS_GEOMETRYDATA
py::class_<TopOpeBRepDS_GeometryData> cls_TopOpeBRepDS_GeometryData(mod, "TopOpeBRepDS_GeometryData", "mother-class of SurfaceData, CurveData, PointData");

// Constructors
cls_TopOpeBRepDS_GeometryData.def(py::init<>());
cls_TopOpeBRepDS_GeometryData.def(py::init<const TopOpeBRepDS_GeometryData &>(), py::arg("Other"));

// Methods
// cls_TopOpeBRepDS_GeometryData.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepDS_GeometryData::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepDS_GeometryData.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepDS_GeometryData::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_GeometryData.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepDS_GeometryData::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepDS_GeometryData.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepDS_GeometryData::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_GeometryData.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepDS_GeometryData::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepDS_GeometryData.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepDS_GeometryData::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepDS_GeometryData.def("Assign", (void (TopOpeBRepDS_GeometryData::*)(const TopOpeBRepDS_GeometryData &)) &TopOpeBRepDS_GeometryData::Assign, "None", py::arg("Other"));
// cls_TopOpeBRepDS_GeometryData.def("operator=", (void (TopOpeBRepDS_GeometryData::*)(const TopOpeBRepDS_GeometryData &)) &TopOpeBRepDS_GeometryData::operator=, "None", py::arg("Other"));
cls_TopOpeBRepDS_GeometryData.def("Interferences", (const TopOpeBRepDS_ListOfInterference & (TopOpeBRepDS_GeometryData::*)() const) &TopOpeBRepDS_GeometryData::Interferences, "None");
cls_TopOpeBRepDS_GeometryData.def("ChangeInterferences", (TopOpeBRepDS_ListOfInterference & (TopOpeBRepDS_GeometryData::*)()) &TopOpeBRepDS_GeometryData::ChangeInterferences, "None");
cls_TopOpeBRepDS_GeometryData.def("AddInterference", (void (TopOpeBRepDS_GeometryData::*)(const opencascade::handle<TopOpeBRepDS_Interference> &)) &TopOpeBRepDS_GeometryData::AddInterference, "None", py::arg("I"));

// CLASS: TOPOPEBREPDS_SURFACEDATA
py::class_<TopOpeBRepDS_SurfaceData, TopOpeBRepDS_GeometryData> cls_TopOpeBRepDS_SurfaceData(mod, "TopOpeBRepDS_SurfaceData", "None");

// Constructors
cls_TopOpeBRepDS_SurfaceData.def(py::init<>());
cls_TopOpeBRepDS_SurfaceData.def(py::init<const TopOpeBRepDS_Surface &>(), py::arg("S"));

// Methods
// cls_TopOpeBRepDS_SurfaceData.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepDS_SurfaceData::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepDS_SurfaceData.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepDS_SurfaceData::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_SurfaceData.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepDS_SurfaceData::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepDS_SurfaceData.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepDS_SurfaceData::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_SurfaceData.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepDS_SurfaceData::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepDS_SurfaceData.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepDS_SurfaceData::operator delete, "None", py::arg(""), py::arg(""));

// TYPEDEF: TOPOPEBREPDS_MAPOFSURFACE
bind_NCollection_DataMap<int, TopOpeBRepDS_SurfaceData, NCollection_DefaultHasher<int> >(mod, "TopOpeBRepDS_MapOfSurface", py::module_local(false));

// TYPEDEF: TOPOPEBREPDS_DATAMAPITERATOROFMAPOFSURFACE

// CLASS: TOPOPEBREPDS_CURVE
py::class_<TopOpeBRepDS_Curve> cls_TopOpeBRepDS_Curve(mod, "TopOpeBRepDS_Curve", "A Geom curve and a tolerance.");

// Constructors
cls_TopOpeBRepDS_Curve.def(py::init<>());
cls_TopOpeBRepDS_Curve.def(py::init<const opencascade::handle<Geom_Curve> &, const Standard_Real>(), py::arg("P"), py::arg("T"));
cls_TopOpeBRepDS_Curve.def(py::init<const opencascade::handle<Geom_Curve> &, const Standard_Real, const Standard_Boolean>(), py::arg("P"), py::arg("T"), py::arg("IsWalk"));

// Methods
// cls_TopOpeBRepDS_Curve.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepDS_Curve::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepDS_Curve.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepDS_Curve::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_Curve.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepDS_Curve::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepDS_Curve.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepDS_Curve::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_Curve.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepDS_Curve::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepDS_Curve.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepDS_Curve::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepDS_Curve.def("DefineCurve", (void (TopOpeBRepDS_Curve::*)(const opencascade::handle<Geom_Curve> &, const Standard_Real, const Standard_Boolean)) &TopOpeBRepDS_Curve::DefineCurve, "None", py::arg("P"), py::arg("T"), py::arg("IsWalk"));
cls_TopOpeBRepDS_Curve.def("Tolerance", (void (TopOpeBRepDS_Curve::*)(const Standard_Real)) &TopOpeBRepDS_Curve::Tolerance, "Update the tolerance", py::arg("tol"));
cls_TopOpeBRepDS_Curve.def("SetSCI", (void (TopOpeBRepDS_Curve::*)(const opencascade::handle<TopOpeBRepDS_Interference> &, const opencascade::handle<TopOpeBRepDS_Interference> &)) &TopOpeBRepDS_Curve::SetSCI, "define the interferences face/curve.", py::arg("I1"), py::arg("I2"));
cls_TopOpeBRepDS_Curve.def("GetSCI1", (const opencascade::handle<TopOpeBRepDS_Interference> & (TopOpeBRepDS_Curve::*)() const) &TopOpeBRepDS_Curve::GetSCI1, "None");
cls_TopOpeBRepDS_Curve.def("GetSCI2", (const opencascade::handle<TopOpeBRepDS_Interference> & (TopOpeBRepDS_Curve::*)() const) &TopOpeBRepDS_Curve::GetSCI2, "None");
cls_TopOpeBRepDS_Curve.def("GetSCI", (void (TopOpeBRepDS_Curve::*)(opencascade::handle<TopOpeBRepDS_Interference> &, opencascade::handle<TopOpeBRepDS_Interference> &) const) &TopOpeBRepDS_Curve::GetSCI, "None", py::arg("I1"), py::arg("I2"));
cls_TopOpeBRepDS_Curve.def("SetShapes", (void (TopOpeBRepDS_Curve::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &TopOpeBRepDS_Curve::SetShapes, "None", py::arg("S1"), py::arg("S2"));
cls_TopOpeBRepDS_Curve.def("GetShapes", (void (TopOpeBRepDS_Curve::*)(TopoDS_Shape &, TopoDS_Shape &) const) &TopOpeBRepDS_Curve::GetShapes, "None", py::arg("S1"), py::arg("S2"));
cls_TopOpeBRepDS_Curve.def("Shape1", (const TopoDS_Shape & (TopOpeBRepDS_Curve::*)() const) &TopOpeBRepDS_Curve::Shape1, "None");
cls_TopOpeBRepDS_Curve.def("ChangeShape1", (TopoDS_Shape & (TopOpeBRepDS_Curve::*)()) &TopOpeBRepDS_Curve::ChangeShape1, "None");
cls_TopOpeBRepDS_Curve.def("Shape2", (const TopoDS_Shape & (TopOpeBRepDS_Curve::*)() const) &TopOpeBRepDS_Curve::Shape2, "None");
cls_TopOpeBRepDS_Curve.def("ChangeShape2", (TopoDS_Shape & (TopOpeBRepDS_Curve::*)()) &TopOpeBRepDS_Curve::ChangeShape2, "None");
cls_TopOpeBRepDS_Curve.def("Curve", (const opencascade::handle<Geom_Curve> & (TopOpeBRepDS_Curve::*)() const) &TopOpeBRepDS_Curve::Curve, "None");
cls_TopOpeBRepDS_Curve.def("SetRange", (void (TopOpeBRepDS_Curve::*)(const Standard_Real, const Standard_Real)) &TopOpeBRepDS_Curve::SetRange, "None", py::arg("First"), py::arg("Last"));
cls_TopOpeBRepDS_Curve.def("Range", [](TopOpeBRepDS_Curve &self, Standard_Real & First, Standard_Real & Last){ Standard_Boolean rv = self.Range(First, Last); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, First, Last); }, "None", py::arg("First"), py::arg("Last"));
cls_TopOpeBRepDS_Curve.def("Tolerance", (Standard_Real (TopOpeBRepDS_Curve::*)() const) &TopOpeBRepDS_Curve::Tolerance, "None");
cls_TopOpeBRepDS_Curve.def("ChangeCurve", (opencascade::handle<Geom_Curve> & (TopOpeBRepDS_Curve::*)()) &TopOpeBRepDS_Curve::ChangeCurve, "None");
cls_TopOpeBRepDS_Curve.def("Curve", (void (TopOpeBRepDS_Curve::*)(const opencascade::handle<Geom_Curve> &, const Standard_Real)) &TopOpeBRepDS_Curve::Curve, "None", py::arg("C3D"), py::arg("Tol"));
cls_TopOpeBRepDS_Curve.def("Curve1", (const opencascade::handle<Geom2d_Curve> & (TopOpeBRepDS_Curve::*)() const) &TopOpeBRepDS_Curve::Curve1, "None");
cls_TopOpeBRepDS_Curve.def("Curve1", (void (TopOpeBRepDS_Curve::*)(const opencascade::handle<Geom2d_Curve> &)) &TopOpeBRepDS_Curve::Curve1, "None", py::arg("PC1"));
cls_TopOpeBRepDS_Curve.def("Curve2", (const opencascade::handle<Geom2d_Curve> & (TopOpeBRepDS_Curve::*)() const) &TopOpeBRepDS_Curve::Curve2, "None");
cls_TopOpeBRepDS_Curve.def("Curve2", (void (TopOpeBRepDS_Curve::*)(const opencascade::handle<Geom2d_Curve> &)) &TopOpeBRepDS_Curve::Curve2, "None", py::arg("PC2"));
cls_TopOpeBRepDS_Curve.def("IsWalk", (Standard_Boolean (TopOpeBRepDS_Curve::*)() const) &TopOpeBRepDS_Curve::IsWalk, "None");
cls_TopOpeBRepDS_Curve.def("ChangeIsWalk", (void (TopOpeBRepDS_Curve::*)(const Standard_Boolean)) &TopOpeBRepDS_Curve::ChangeIsWalk, "None", py::arg("B"));
cls_TopOpeBRepDS_Curve.def("Keep", (Standard_Boolean (TopOpeBRepDS_Curve::*)() const) &TopOpeBRepDS_Curve::Keep, "None");
cls_TopOpeBRepDS_Curve.def("ChangeKeep", (void (TopOpeBRepDS_Curve::*)(const Standard_Boolean)) &TopOpeBRepDS_Curve::ChangeKeep, "None", py::arg("B"));
cls_TopOpeBRepDS_Curve.def("Mother", (Standard_Integer (TopOpeBRepDS_Curve::*)() const) &TopOpeBRepDS_Curve::Mother, "None");
cls_TopOpeBRepDS_Curve.def("ChangeMother", (void (TopOpeBRepDS_Curve::*)(const Standard_Integer)) &TopOpeBRepDS_Curve::ChangeMother, "None", py::arg("I"));
cls_TopOpeBRepDS_Curve.def("DSIndex", (Standard_Integer (TopOpeBRepDS_Curve::*)() const) &TopOpeBRepDS_Curve::DSIndex, "None");
cls_TopOpeBRepDS_Curve.def("ChangeDSIndex", (void (TopOpeBRepDS_Curve::*)(const Standard_Integer)) &TopOpeBRepDS_Curve::ChangeDSIndex, "None", py::arg("I"));

// CLASS: TOPOPEBREPDS_CURVEDATA
py::class_<TopOpeBRepDS_CurveData, TopOpeBRepDS_GeometryData> cls_TopOpeBRepDS_CurveData(mod, "TopOpeBRepDS_CurveData", "None");

// Constructors
cls_TopOpeBRepDS_CurveData.def(py::init<>());
cls_TopOpeBRepDS_CurveData.def(py::init<const TopOpeBRepDS_Curve &>(), py::arg("C"));

// Methods
// cls_TopOpeBRepDS_CurveData.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepDS_CurveData::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepDS_CurveData.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepDS_CurveData::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_CurveData.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepDS_CurveData::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepDS_CurveData.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepDS_CurveData::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_CurveData.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepDS_CurveData::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepDS_CurveData.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepDS_CurveData::operator delete, "None", py::arg(""), py::arg(""));

// TYPEDEF: TOPOPEBREPDS_MAPOFCURVE
bind_NCollection_DataMap<int, TopOpeBRepDS_CurveData, NCollection_DefaultHasher<int> >(mod, "TopOpeBRepDS_MapOfCurve", py::module_local(false));

// TYPEDEF: TOPOPEBREPDS_DATAMAPITERATOROFMAPOFCURVE

// CLASS: TOPOPEBREPDS_POINT
py::class_<TopOpeBRepDS_Point> cls_TopOpeBRepDS_Point(mod, "TopOpeBRepDS_Point", "A Geom point and a tolerance.");

// Constructors
cls_TopOpeBRepDS_Point.def(py::init<>());
cls_TopOpeBRepDS_Point.def(py::init<const gp_Pnt &, const Standard_Real>(), py::arg("P"), py::arg("T"));
cls_TopOpeBRepDS_Point.def(py::init<const TopoDS_Shape &>(), py::arg("S"));

// Methods
// cls_TopOpeBRepDS_Point.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepDS_Point::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepDS_Point.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepDS_Point::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_Point.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepDS_Point::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepDS_Point.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepDS_Point::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_Point.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepDS_Point::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepDS_Point.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepDS_Point::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepDS_Point.def("IsEqual", (Standard_Boolean (TopOpeBRepDS_Point::*)(const TopOpeBRepDS_Point &) const) &TopOpeBRepDS_Point::IsEqual, "None", py::arg("other"));
cls_TopOpeBRepDS_Point.def("Point", (const gp_Pnt & (TopOpeBRepDS_Point::*)() const) &TopOpeBRepDS_Point::Point, "None");
cls_TopOpeBRepDS_Point.def("ChangePoint", (gp_Pnt & (TopOpeBRepDS_Point::*)()) &TopOpeBRepDS_Point::ChangePoint, "None");
cls_TopOpeBRepDS_Point.def("Tolerance", (Standard_Real (TopOpeBRepDS_Point::*)() const) &TopOpeBRepDS_Point::Tolerance, "None");
cls_TopOpeBRepDS_Point.def("Tolerance", (void (TopOpeBRepDS_Point::*)(const Standard_Real)) &TopOpeBRepDS_Point::Tolerance, "None", py::arg("Tol"));
cls_TopOpeBRepDS_Point.def("Keep", (Standard_Boolean (TopOpeBRepDS_Point::*)() const) &TopOpeBRepDS_Point::Keep, "None");
cls_TopOpeBRepDS_Point.def("ChangeKeep", (void (TopOpeBRepDS_Point::*)(const Standard_Boolean)) &TopOpeBRepDS_Point::ChangeKeep, "None", py::arg("B"));

// CLASS: TOPOPEBREPDS_POINTDATA
py::class_<TopOpeBRepDS_PointData, TopOpeBRepDS_GeometryData> cls_TopOpeBRepDS_PointData(mod, "TopOpeBRepDS_PointData", "None");

// Constructors
cls_TopOpeBRepDS_PointData.def(py::init<>());
cls_TopOpeBRepDS_PointData.def(py::init<const TopOpeBRepDS_Point &>(), py::arg("P"));
cls_TopOpeBRepDS_PointData.def(py::init<const TopOpeBRepDS_Point &, const Standard_Integer, const Standard_Integer>(), py::arg("P"), py::arg("I1"), py::arg("I2"));

// Methods
// cls_TopOpeBRepDS_PointData.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepDS_PointData::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepDS_PointData.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepDS_PointData::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_PointData.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepDS_PointData::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepDS_PointData.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepDS_PointData::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_PointData.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepDS_PointData::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepDS_PointData.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepDS_PointData::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepDS_PointData.def("SetShapes", (void (TopOpeBRepDS_PointData::*)(const Standard_Integer, const Standard_Integer)) &TopOpeBRepDS_PointData::SetShapes, "None", py::arg("I1"), py::arg("I2"));
cls_TopOpeBRepDS_PointData.def("GetShapes", [](TopOpeBRepDS_PointData &self, Standard_Integer & I1, Standard_Integer & I2){ self.GetShapes(I1, I2); return std::tuple<Standard_Integer &, Standard_Integer &>(I1, I2); }, "None", py::arg("I1"), py::arg("I2"));

// TYPEDEF: TOPOPEBREPDS_MAPOFPOINT
bind_NCollection_DataMap<int, TopOpeBRepDS_PointData, NCollection_DefaultHasher<int> >(mod, "TopOpeBRepDS_MapOfPoint", py::module_local(false));

// TYPEDEF: TOPOPEBREPDS_DATAMAPITERATOROFMAPOFPOINT

// CLASS: TOPOPEBREPDS_SHAPEDATA
py::class_<TopOpeBRepDS_ShapeData> cls_TopOpeBRepDS_ShapeData(mod, "TopOpeBRepDS_ShapeData", "None");

// Constructors
cls_TopOpeBRepDS_ShapeData.def(py::init<>());

// Methods
// cls_TopOpeBRepDS_ShapeData.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepDS_ShapeData::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepDS_ShapeData.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepDS_ShapeData::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_ShapeData.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepDS_ShapeData::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepDS_ShapeData.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepDS_ShapeData::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_ShapeData.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepDS_ShapeData::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepDS_ShapeData.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepDS_ShapeData::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepDS_ShapeData.def("Interferences", (const TopOpeBRepDS_ListOfInterference & (TopOpeBRepDS_ShapeData::*)() const) &TopOpeBRepDS_ShapeData::Interferences, "None");
cls_TopOpeBRepDS_ShapeData.def("ChangeInterferences", (TopOpeBRepDS_ListOfInterference & (TopOpeBRepDS_ShapeData::*)()) &TopOpeBRepDS_ShapeData::ChangeInterferences, "None");
cls_TopOpeBRepDS_ShapeData.def("Keep", (Standard_Boolean (TopOpeBRepDS_ShapeData::*)() const) &TopOpeBRepDS_ShapeData::Keep, "None");
cls_TopOpeBRepDS_ShapeData.def("ChangeKeep", (void (TopOpeBRepDS_ShapeData::*)(const Standard_Boolean)) &TopOpeBRepDS_ShapeData::ChangeKeep, "None", py::arg("B"));

// TYPEDEF: TOPOPEBREPDS_MAPOFSHAPEDATA
bind_NCollection_IndexedDataMap<TopoDS_Shape, TopOpeBRepDS_ShapeData, TopTools_ShapeMapHasher>(mod, "TopOpeBRepDS_MapOfShapeData", py::module_local(false));

// TYPEDEF: TOPOPEBREPDS_SHAPESURFACE
bind_NCollection_DataMap<TopoDS_Shape, opencascade::handle<Geom_Surface>, TopTools_ShapeMapHasher>(mod, "TopOpeBRepDS_ShapeSurface", py::module_local(false));

// TYPEDEF: TOPOPEBREPDS_DATAMAPITERATOROFSHAPESURFACE

// CLASS: TOPOPEBREPDS_SHAPEWITHSTATE
py::class_<TopOpeBRepDS_ShapeWithState> cls_TopOpeBRepDS_ShapeWithState(mod, "TopOpeBRepDS_ShapeWithState", "None");

// Constructors
cls_TopOpeBRepDS_ShapeWithState.def(py::init<>());

// Methods
// cls_TopOpeBRepDS_ShapeWithState.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepDS_ShapeWithState::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepDS_ShapeWithState.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepDS_ShapeWithState::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_ShapeWithState.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepDS_ShapeWithState::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepDS_ShapeWithState.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepDS_ShapeWithState::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_ShapeWithState.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepDS_ShapeWithState::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepDS_ShapeWithState.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepDS_ShapeWithState::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepDS_ShapeWithState.def("Part", (const TopTools_ListOfShape & (TopOpeBRepDS_ShapeWithState::*)(const TopAbs_State) const) &TopOpeBRepDS_ShapeWithState::Part, "None", py::arg("aState"));
cls_TopOpeBRepDS_ShapeWithState.def("AddPart", (void (TopOpeBRepDS_ShapeWithState::*)(const TopoDS_Shape &, const TopAbs_State)) &TopOpeBRepDS_ShapeWithState::AddPart, "None", py::arg("aShape"), py::arg("aState"));
cls_TopOpeBRepDS_ShapeWithState.def("AddParts", (void (TopOpeBRepDS_ShapeWithState::*)(const TopTools_ListOfShape &, const TopAbs_State)) &TopOpeBRepDS_ShapeWithState::AddParts, "None", py::arg("aListOfShape"), py::arg("aState"));
cls_TopOpeBRepDS_ShapeWithState.def("SetState", (void (TopOpeBRepDS_ShapeWithState::*)(const TopAbs_State)) &TopOpeBRepDS_ShapeWithState::SetState, "None", py::arg("aState"));
cls_TopOpeBRepDS_ShapeWithState.def("State", (TopAbs_State (TopOpeBRepDS_ShapeWithState::*)() const) &TopOpeBRepDS_ShapeWithState::State, "None");
cls_TopOpeBRepDS_ShapeWithState.def("SetIsSplitted", (void (TopOpeBRepDS_ShapeWithState::*)(const Standard_Boolean)) &TopOpeBRepDS_ShapeWithState::SetIsSplitted, "None", py::arg("anIsSplitted"));
cls_TopOpeBRepDS_ShapeWithState.def("IsSplitted", (Standard_Boolean (TopOpeBRepDS_ShapeWithState::*)() const) &TopOpeBRepDS_ShapeWithState::IsSplitted, "None");

// TYPEDEF: TOPOPEBREPDS_INDEXEDDATAMAPOFSHAPEWITHSTATE
bind_NCollection_IndexedDataMap<TopoDS_Shape, TopOpeBRepDS_ShapeWithState, TopTools_ShapeMapHasher>(mod, "TopOpeBRepDS_IndexedDataMapOfShapeWithState", py::module_local(false));

// CLASS: TOPOPEBREPDS_DATASTRUCTURE
py::class_<TopOpeBRepDS_DataStructure> cls_TopOpeBRepDS_DataStructure(mod, "TopOpeBRepDS_DataStructure", "The DataStructure stores :");

// Constructors
cls_TopOpeBRepDS_DataStructure.def(py::init<>());

// Methods
// cls_TopOpeBRepDS_DataStructure.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepDS_DataStructure::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepDS_DataStructure.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepDS_DataStructure::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_DataStructure.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepDS_DataStructure::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepDS_DataStructure.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepDS_DataStructure::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_DataStructure.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepDS_DataStructure::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepDS_DataStructure.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepDS_DataStructure::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepDS_DataStructure.def("Init", (void (TopOpeBRepDS_DataStructure::*)()) &TopOpeBRepDS_DataStructure::Init, "reset the data structure");
cls_TopOpeBRepDS_DataStructure.def("AddSurface", (Standard_Integer (TopOpeBRepDS_DataStructure::*)(const TopOpeBRepDS_Surface &)) &TopOpeBRepDS_DataStructure::AddSurface, "Insert a new surface. Returns the index.", py::arg("S"));
cls_TopOpeBRepDS_DataStructure.def("RemoveSurface", (void (TopOpeBRepDS_DataStructure::*)(const Standard_Integer)) &TopOpeBRepDS_DataStructure::RemoveSurface, "None", py::arg("I"));
cls_TopOpeBRepDS_DataStructure.def("KeepSurface", (Standard_Boolean (TopOpeBRepDS_DataStructure::*)(const Standard_Integer) const) &TopOpeBRepDS_DataStructure::KeepSurface, "None", py::arg("I"));
cls_TopOpeBRepDS_DataStructure.def("KeepSurface", (Standard_Boolean (TopOpeBRepDS_DataStructure::*)(TopOpeBRepDS_Surface &) const) &TopOpeBRepDS_DataStructure::KeepSurface, "None", py::arg("S"));
cls_TopOpeBRepDS_DataStructure.def("ChangeKeepSurface", (void (TopOpeBRepDS_DataStructure::*)(const Standard_Integer, const Standard_Boolean)) &TopOpeBRepDS_DataStructure::ChangeKeepSurface, "None", py::arg("I"), py::arg("FindKeep"));
cls_TopOpeBRepDS_DataStructure.def("ChangeKeepSurface", (void (TopOpeBRepDS_DataStructure::*)(TopOpeBRepDS_Surface &, const Standard_Boolean)) &TopOpeBRepDS_DataStructure::ChangeKeepSurface, "None", py::arg("S"), py::arg("FindKeep"));
cls_TopOpeBRepDS_DataStructure.def("AddCurve", (Standard_Integer (TopOpeBRepDS_DataStructure::*)(const TopOpeBRepDS_Curve &)) &TopOpeBRepDS_DataStructure::AddCurve, "Insert a new curve. Returns the index.", py::arg("S"));
cls_TopOpeBRepDS_DataStructure.def("RemoveCurve", (void (TopOpeBRepDS_DataStructure::*)(const Standard_Integer)) &TopOpeBRepDS_DataStructure::RemoveCurve, "None", py::arg("I"));
cls_TopOpeBRepDS_DataStructure.def("KeepCurve", (Standard_Boolean (TopOpeBRepDS_DataStructure::*)(const Standard_Integer) const) &TopOpeBRepDS_DataStructure::KeepCurve, "None", py::arg("I"));
cls_TopOpeBRepDS_DataStructure.def("KeepCurve", (Standard_Boolean (TopOpeBRepDS_DataStructure::*)(const TopOpeBRepDS_Curve &) const) &TopOpeBRepDS_DataStructure::KeepCurve, "None", py::arg("C"));
cls_TopOpeBRepDS_DataStructure.def("ChangeKeepCurve", (void (TopOpeBRepDS_DataStructure::*)(const Standard_Integer, const Standard_Boolean)) &TopOpeBRepDS_DataStructure::ChangeKeepCurve, "None", py::arg("I"), py::arg("FindKeep"));
cls_TopOpeBRepDS_DataStructure.def("ChangeKeepCurve", (void (TopOpeBRepDS_DataStructure::*)(TopOpeBRepDS_Curve &, const Standard_Boolean)) &TopOpeBRepDS_DataStructure::ChangeKeepCurve, "None", py::arg("C"), py::arg("FindKeep"));
cls_TopOpeBRepDS_DataStructure.def("AddPoint", (Standard_Integer (TopOpeBRepDS_DataStructure::*)(const TopOpeBRepDS_Point &)) &TopOpeBRepDS_DataStructure::AddPoint, "Insert a new point. Returns the index.", py::arg("PDS"));
cls_TopOpeBRepDS_DataStructure.def("AddPointSS", (Standard_Integer (TopOpeBRepDS_DataStructure::*)(const TopOpeBRepDS_Point &, const TopoDS_Shape &, const TopoDS_Shape &)) &TopOpeBRepDS_DataStructure::AddPointSS, "Insert a new point. Returns the index.", py::arg("PDS"), py::arg("S1"), py::arg("S2"));
cls_TopOpeBRepDS_DataStructure.def("RemovePoint", (void (TopOpeBRepDS_DataStructure::*)(const Standard_Integer)) &TopOpeBRepDS_DataStructure::RemovePoint, "None", py::arg("I"));
cls_TopOpeBRepDS_DataStructure.def("KeepPoint", (Standard_Boolean (TopOpeBRepDS_DataStructure::*)(const Standard_Integer) const) &TopOpeBRepDS_DataStructure::KeepPoint, "None", py::arg("I"));
cls_TopOpeBRepDS_DataStructure.def("KeepPoint", (Standard_Boolean (TopOpeBRepDS_DataStructure::*)(const TopOpeBRepDS_Point &) const) &TopOpeBRepDS_DataStructure::KeepPoint, "None", py::arg("P"));
cls_TopOpeBRepDS_DataStructure.def("ChangeKeepPoint", (void (TopOpeBRepDS_DataStructure::*)(const Standard_Integer, const Standard_Boolean)) &TopOpeBRepDS_DataStructure::ChangeKeepPoint, "None", py::arg("I"), py::arg("FindKeep"));
cls_TopOpeBRepDS_DataStructure.def("ChangeKeepPoint", (void (TopOpeBRepDS_DataStructure::*)(TopOpeBRepDS_Point &, const Standard_Boolean)) &TopOpeBRepDS_DataStructure::ChangeKeepPoint, "None", py::arg("P"), py::arg("FindKeep"));
cls_TopOpeBRepDS_DataStructure.def("AddShape", (Standard_Integer (TopOpeBRepDS_DataStructure::*)(const TopoDS_Shape &)) &TopOpeBRepDS_DataStructure::AddShape, "Insert a shape S. Returns the index.", py::arg("S"));
cls_TopOpeBRepDS_DataStructure.def("AddShape", (Standard_Integer (TopOpeBRepDS_DataStructure::*)(const TopoDS_Shape &, const Standard_Integer)) &TopOpeBRepDS_DataStructure::AddShape, "Insert a shape S which ancestor is I = 1 or 2. Returns the index.", py::arg("S"), py::arg("I"));
cls_TopOpeBRepDS_DataStructure.def("KeepShape", [](TopOpeBRepDS_DataStructure &self, const Standard_Integer a0) -> Standard_Boolean { return self.KeepShape(a0); });
cls_TopOpeBRepDS_DataStructure.def("KeepShape", (Standard_Boolean (TopOpeBRepDS_DataStructure::*)(const Standard_Integer, const Standard_Boolean) const) &TopOpeBRepDS_DataStructure::KeepShape, "None", py::arg("I"), py::arg("FindKeep"));
cls_TopOpeBRepDS_DataStructure.def("KeepShape", [](TopOpeBRepDS_DataStructure &self, const TopoDS_Shape & a0) -> Standard_Boolean { return self.KeepShape(a0); });
cls_TopOpeBRepDS_DataStructure.def("KeepShape", (Standard_Boolean (TopOpeBRepDS_DataStructure::*)(const TopoDS_Shape &, const Standard_Boolean) const) &TopOpeBRepDS_DataStructure::KeepShape, "None", py::arg("S"), py::arg("FindKeep"));
cls_TopOpeBRepDS_DataStructure.def("ChangeKeepShape", (void (TopOpeBRepDS_DataStructure::*)(const Standard_Integer, const Standard_Boolean)) &TopOpeBRepDS_DataStructure::ChangeKeepShape, "None", py::arg("I"), py::arg("FindKeep"));
cls_TopOpeBRepDS_DataStructure.def("ChangeKeepShape", (void (TopOpeBRepDS_DataStructure::*)(const TopoDS_Shape &, const Standard_Boolean)) &TopOpeBRepDS_DataStructure::ChangeKeepShape, "None", py::arg("S"), py::arg("FindKeep"));
cls_TopOpeBRepDS_DataStructure.def("InitSectionEdges", (void (TopOpeBRepDS_DataStructure::*)()) &TopOpeBRepDS_DataStructure::InitSectionEdges, "None");
cls_TopOpeBRepDS_DataStructure.def("AddSectionEdge", (Standard_Integer (TopOpeBRepDS_DataStructure::*)(const TopoDS_Edge &)) &TopOpeBRepDS_DataStructure::AddSectionEdge, "None", py::arg("E"));
cls_TopOpeBRepDS_DataStructure.def("SurfaceInterferences", (const TopOpeBRepDS_ListOfInterference & (TopOpeBRepDS_DataStructure::*)(const Standard_Integer) const) &TopOpeBRepDS_DataStructure::SurfaceInterferences, "None", py::arg("I"));
cls_TopOpeBRepDS_DataStructure.def("ChangeSurfaceInterferences", (TopOpeBRepDS_ListOfInterference & (TopOpeBRepDS_DataStructure::*)(const Standard_Integer)) &TopOpeBRepDS_DataStructure::ChangeSurfaceInterferences, "None", py::arg("I"));
cls_TopOpeBRepDS_DataStructure.def("CurveInterferences", (const TopOpeBRepDS_ListOfInterference & (TopOpeBRepDS_DataStructure::*)(const Standard_Integer) const) &TopOpeBRepDS_DataStructure::CurveInterferences, "None", py::arg("I"));
cls_TopOpeBRepDS_DataStructure.def("ChangeCurveInterferences", (TopOpeBRepDS_ListOfInterference & (TopOpeBRepDS_DataStructure::*)(const Standard_Integer)) &TopOpeBRepDS_DataStructure::ChangeCurveInterferences, "None", py::arg("I"));
cls_TopOpeBRepDS_DataStructure.def("PointInterferences", (const TopOpeBRepDS_ListOfInterference & (TopOpeBRepDS_DataStructure::*)(const Standard_Integer) const) &TopOpeBRepDS_DataStructure::PointInterferences, "None", py::arg("I"));
cls_TopOpeBRepDS_DataStructure.def("ChangePointInterferences", (TopOpeBRepDS_ListOfInterference & (TopOpeBRepDS_DataStructure::*)(const Standard_Integer)) &TopOpeBRepDS_DataStructure::ChangePointInterferences, "None", py::arg("I"));
cls_TopOpeBRepDS_DataStructure.def("ShapeInterferences", [](TopOpeBRepDS_DataStructure &self, const TopoDS_Shape & a0) -> const TopOpeBRepDS_ListOfInterference & { return self.ShapeInterferences(a0); });
cls_TopOpeBRepDS_DataStructure.def("ShapeInterferences", (const TopOpeBRepDS_ListOfInterference & (TopOpeBRepDS_DataStructure::*)(const TopoDS_Shape &, const Standard_Boolean) const) &TopOpeBRepDS_DataStructure::ShapeInterferences, "None", py::arg("S"), py::arg("FindKeep"));
cls_TopOpeBRepDS_DataStructure.def("ChangeShapeInterferences", (TopOpeBRepDS_ListOfInterference & (TopOpeBRepDS_DataStructure::*)(const TopoDS_Shape &)) &TopOpeBRepDS_DataStructure::ChangeShapeInterferences, "None", py::arg("S"));
cls_TopOpeBRepDS_DataStructure.def("ShapeInterferences", [](TopOpeBRepDS_DataStructure &self, const Standard_Integer a0) -> const TopOpeBRepDS_ListOfInterference & { return self.ShapeInterferences(a0); });
cls_TopOpeBRepDS_DataStructure.def("ShapeInterferences", (const TopOpeBRepDS_ListOfInterference & (TopOpeBRepDS_DataStructure::*)(const Standard_Integer, const Standard_Boolean) const) &TopOpeBRepDS_DataStructure::ShapeInterferences, "None", py::arg("I"), py::arg("FindKeep"));
cls_TopOpeBRepDS_DataStructure.def("ChangeShapeInterferences", (TopOpeBRepDS_ListOfInterference & (TopOpeBRepDS_DataStructure::*)(const Standard_Integer)) &TopOpeBRepDS_DataStructure::ChangeShapeInterferences, "None", py::arg("I"));
cls_TopOpeBRepDS_DataStructure.def("ShapeSameDomain", (const TopTools_ListOfShape & (TopOpeBRepDS_DataStructure::*)(const TopoDS_Shape &) const) &TopOpeBRepDS_DataStructure::ShapeSameDomain, "None", py::arg("S"));
cls_TopOpeBRepDS_DataStructure.def("ChangeShapeSameDomain", (TopTools_ListOfShape & (TopOpeBRepDS_DataStructure::*)(const TopoDS_Shape &)) &TopOpeBRepDS_DataStructure::ChangeShapeSameDomain, "None", py::arg("S"));
cls_TopOpeBRepDS_DataStructure.def("ShapeSameDomain", (const TopTools_ListOfShape & (TopOpeBRepDS_DataStructure::*)(const Standard_Integer) const) &TopOpeBRepDS_DataStructure::ShapeSameDomain, "None", py::arg("I"));
cls_TopOpeBRepDS_DataStructure.def("ChangeShapeSameDomain", (TopTools_ListOfShape & (TopOpeBRepDS_DataStructure::*)(const Standard_Integer)) &TopOpeBRepDS_DataStructure::ChangeShapeSameDomain, "None", py::arg("I"));
cls_TopOpeBRepDS_DataStructure.def("ChangeShapes", (TopOpeBRepDS_MapOfShapeData & (TopOpeBRepDS_DataStructure::*)()) &TopOpeBRepDS_DataStructure::ChangeShapes, "None");
cls_TopOpeBRepDS_DataStructure.def("AddShapeSameDomain", (void (TopOpeBRepDS_DataStructure::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &TopOpeBRepDS_DataStructure::AddShapeSameDomain, "None", py::arg("S"), py::arg("SSD"));
cls_TopOpeBRepDS_DataStructure.def("RemoveShapeSameDomain", (void (TopOpeBRepDS_DataStructure::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &TopOpeBRepDS_DataStructure::RemoveShapeSameDomain, "None", py::arg("S"), py::arg("SSD"));
cls_TopOpeBRepDS_DataStructure.def("SameDomainRef", (Standard_Integer (TopOpeBRepDS_DataStructure::*)(const Standard_Integer) const) &TopOpeBRepDS_DataStructure::SameDomainRef, "None", py::arg("I"));
cls_TopOpeBRepDS_DataStructure.def("SameDomainRef", (Standard_Integer (TopOpeBRepDS_DataStructure::*)(const TopoDS_Shape &) const) &TopOpeBRepDS_DataStructure::SameDomainRef, "None", py::arg("S"));
cls_TopOpeBRepDS_DataStructure.def("SameDomainRef", (void (TopOpeBRepDS_DataStructure::*)(const Standard_Integer, const Standard_Integer)) &TopOpeBRepDS_DataStructure::SameDomainRef, "None", py::arg("I"), py::arg("Ref"));
cls_TopOpeBRepDS_DataStructure.def("SameDomainRef", (void (TopOpeBRepDS_DataStructure::*)(const TopoDS_Shape &, const Standard_Integer)) &TopOpeBRepDS_DataStructure::SameDomainRef, "None", py::arg("S"), py::arg("Ref"));
cls_TopOpeBRepDS_DataStructure.def("SameDomainOri", (TopOpeBRepDS_Config (TopOpeBRepDS_DataStructure::*)(const Standard_Integer) const) &TopOpeBRepDS_DataStructure::SameDomainOri, "None", py::arg("I"));
cls_TopOpeBRepDS_DataStructure.def("SameDomainOri", (TopOpeBRepDS_Config (TopOpeBRepDS_DataStructure::*)(const TopoDS_Shape &) const) &TopOpeBRepDS_DataStructure::SameDomainOri, "None", py::arg("S"));
cls_TopOpeBRepDS_DataStructure.def("SameDomainOri", (void (TopOpeBRepDS_DataStructure::*)(const Standard_Integer, const TopOpeBRepDS_Config)) &TopOpeBRepDS_DataStructure::SameDomainOri, "None", py::arg("I"), py::arg("Ori"));
cls_TopOpeBRepDS_DataStructure.def("SameDomainOri", (void (TopOpeBRepDS_DataStructure::*)(const TopoDS_Shape &, const TopOpeBRepDS_Config)) &TopOpeBRepDS_DataStructure::SameDomainOri, "None", py::arg("S"), py::arg("Ori"));
cls_TopOpeBRepDS_DataStructure.def("SameDomainInd", (Standard_Integer (TopOpeBRepDS_DataStructure::*)(const Standard_Integer) const) &TopOpeBRepDS_DataStructure::SameDomainInd, "None", py::arg("I"));
cls_TopOpeBRepDS_DataStructure.def("SameDomainInd", (Standard_Integer (TopOpeBRepDS_DataStructure::*)(const TopoDS_Shape &) const) &TopOpeBRepDS_DataStructure::SameDomainInd, "None", py::arg("S"));
cls_TopOpeBRepDS_DataStructure.def("SameDomainInd", (void (TopOpeBRepDS_DataStructure::*)(const Standard_Integer, const Standard_Integer)) &TopOpeBRepDS_DataStructure::SameDomainInd, "None", py::arg("I"), py::arg("Ind"));
cls_TopOpeBRepDS_DataStructure.def("SameDomainInd", (void (TopOpeBRepDS_DataStructure::*)(const TopoDS_Shape &, const Standard_Integer)) &TopOpeBRepDS_DataStructure::SameDomainInd, "None", py::arg("S"), py::arg("Ind"));
cls_TopOpeBRepDS_DataStructure.def("AncestorRank", (Standard_Integer (TopOpeBRepDS_DataStructure::*)(const Standard_Integer) const) &TopOpeBRepDS_DataStructure::AncestorRank, "None", py::arg("I"));
cls_TopOpeBRepDS_DataStructure.def("AncestorRank", (Standard_Integer (TopOpeBRepDS_DataStructure::*)(const TopoDS_Shape &) const) &TopOpeBRepDS_DataStructure::AncestorRank, "None", py::arg("S"));
cls_TopOpeBRepDS_DataStructure.def("AncestorRank", (void (TopOpeBRepDS_DataStructure::*)(const Standard_Integer, const Standard_Integer)) &TopOpeBRepDS_DataStructure::AncestorRank, "None", py::arg("I"), py::arg("Ianc"));
cls_TopOpeBRepDS_DataStructure.def("AncestorRank", (void (TopOpeBRepDS_DataStructure::*)(const TopoDS_Shape &, const Standard_Integer)) &TopOpeBRepDS_DataStructure::AncestorRank, "None", py::arg("S"), py::arg("Ianc"));
cls_TopOpeBRepDS_DataStructure.def("AddShapeInterference", (void (TopOpeBRepDS_DataStructure::*)(const TopoDS_Shape &, const opencascade::handle<TopOpeBRepDS_Interference> &)) &TopOpeBRepDS_DataStructure::AddShapeInterference, "None", py::arg("S"), py::arg("I"));
cls_TopOpeBRepDS_DataStructure.def("RemoveShapeInterference", (void (TopOpeBRepDS_DataStructure::*)(const TopoDS_Shape &, const opencascade::handle<TopOpeBRepDS_Interference> &)) &TopOpeBRepDS_DataStructure::RemoveShapeInterference, "None", py::arg("S"), py::arg("I"));
cls_TopOpeBRepDS_DataStructure.def("FillShapesSameDomain", [](TopOpeBRepDS_DataStructure &self, const TopoDS_Shape & a0, const TopoDS_Shape & a1) -> void { return self.FillShapesSameDomain(a0, a1); });
cls_TopOpeBRepDS_DataStructure.def("FillShapesSameDomain", (void (TopOpeBRepDS_DataStructure::*)(const TopoDS_Shape &, const TopoDS_Shape &, const Standard_Boolean)) &TopOpeBRepDS_DataStructure::FillShapesSameDomain, "None", py::arg("S1"), py::arg("S2"), py::arg("refFirst"));
cls_TopOpeBRepDS_DataStructure.def("FillShapesSameDomain", [](TopOpeBRepDS_DataStructure &self, const TopoDS_Shape & a0, const TopoDS_Shape & a1, const TopOpeBRepDS_Config a2, const TopOpeBRepDS_Config a3) -> void { return self.FillShapesSameDomain(a0, a1, a2, a3); });
cls_TopOpeBRepDS_DataStructure.def("FillShapesSameDomain", (void (TopOpeBRepDS_DataStructure::*)(const TopoDS_Shape &, const TopoDS_Shape &, const TopOpeBRepDS_Config, const TopOpeBRepDS_Config, const Standard_Boolean)) &TopOpeBRepDS_DataStructure::FillShapesSameDomain, "None", py::arg("S1"), py::arg("S2"), py::arg("c1"), py::arg("c2"), py::arg("refFirst"));
cls_TopOpeBRepDS_DataStructure.def("UnfillShapesSameDomain", (void (TopOpeBRepDS_DataStructure::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &TopOpeBRepDS_DataStructure::UnfillShapesSameDomain, "None", py::arg("S1"), py::arg("S2"));
cls_TopOpeBRepDS_DataStructure.def("NbSurfaces", (Standard_Integer (TopOpeBRepDS_DataStructure::*)() const) &TopOpeBRepDS_DataStructure::NbSurfaces, "None");
cls_TopOpeBRepDS_DataStructure.def("NbCurves", (Standard_Integer (TopOpeBRepDS_DataStructure::*)() const) &TopOpeBRepDS_DataStructure::NbCurves, "None");
cls_TopOpeBRepDS_DataStructure.def("ChangeNbCurves", (void (TopOpeBRepDS_DataStructure::*)(const Standard_Integer)) &TopOpeBRepDS_DataStructure::ChangeNbCurves, "None", py::arg("N"));
cls_TopOpeBRepDS_DataStructure.def("NbPoints", (Standard_Integer (TopOpeBRepDS_DataStructure::*)() const) &TopOpeBRepDS_DataStructure::NbPoints, "None");
cls_TopOpeBRepDS_DataStructure.def("NbShapes", (Standard_Integer (TopOpeBRepDS_DataStructure::*)() const) &TopOpeBRepDS_DataStructure::NbShapes, "None");
cls_TopOpeBRepDS_DataStructure.def("NbSectionEdges", (Standard_Integer (TopOpeBRepDS_DataStructure::*)() const) &TopOpeBRepDS_DataStructure::NbSectionEdges, "None");
cls_TopOpeBRepDS_DataStructure.def("Surface", (const TopOpeBRepDS_Surface & (TopOpeBRepDS_DataStructure::*)(const Standard_Integer) const) &TopOpeBRepDS_DataStructure::Surface, "Returns the surface of index <I>.", py::arg("I"));
cls_TopOpeBRepDS_DataStructure.def("ChangeSurface", (TopOpeBRepDS_Surface & (TopOpeBRepDS_DataStructure::*)(const Standard_Integer)) &TopOpeBRepDS_DataStructure::ChangeSurface, "Returns the surface of index <I>.", py::arg("I"));
cls_TopOpeBRepDS_DataStructure.def("Curve", (const TopOpeBRepDS_Curve & (TopOpeBRepDS_DataStructure::*)(const Standard_Integer) const) &TopOpeBRepDS_DataStructure::Curve, "Returns the Curve of index <I>.", py::arg("I"));
cls_TopOpeBRepDS_DataStructure.def("ChangeCurve", (TopOpeBRepDS_Curve & (TopOpeBRepDS_DataStructure::*)(const Standard_Integer)) &TopOpeBRepDS_DataStructure::ChangeCurve, "Returns the Curve of index <I>.", py::arg("I"));
cls_TopOpeBRepDS_DataStructure.def("Point", (const TopOpeBRepDS_Point & (TopOpeBRepDS_DataStructure::*)(const Standard_Integer) const) &TopOpeBRepDS_DataStructure::Point, "Returns the point of index <I>.", py::arg("I"));
cls_TopOpeBRepDS_DataStructure.def("ChangePoint", (TopOpeBRepDS_Point & (TopOpeBRepDS_DataStructure::*)(const Standard_Integer)) &TopOpeBRepDS_DataStructure::ChangePoint, "Returns the point of index <I>.", py::arg("I"));
cls_TopOpeBRepDS_DataStructure.def("Shape", [](TopOpeBRepDS_DataStructure &self, const Standard_Integer a0) -> const TopoDS_Shape & { return self.Shape(a0); });
cls_TopOpeBRepDS_DataStructure.def("Shape", (const TopoDS_Shape & (TopOpeBRepDS_DataStructure::*)(const Standard_Integer, const Standard_Boolean) const) &TopOpeBRepDS_DataStructure::Shape, "returns the shape of index I stored in the map myShapes, accessing a list of interference.", py::arg("I"), py::arg("FindKeep"));
cls_TopOpeBRepDS_DataStructure.def("Shape", [](TopOpeBRepDS_DataStructure &self, const TopoDS_Shape & a0) -> Standard_Integer { return self.Shape(a0); });
cls_TopOpeBRepDS_DataStructure.def("Shape", (Standard_Integer (TopOpeBRepDS_DataStructure::*)(const TopoDS_Shape &, const Standard_Boolean) const) &TopOpeBRepDS_DataStructure::Shape, "returns the index of shape <S> stored in the map myShapes, accessing a list of interference. returns 0 if <S> is not in the map.", py::arg("S"), py::arg("FindKeep"));
cls_TopOpeBRepDS_DataStructure.def("SectionEdge", [](TopOpeBRepDS_DataStructure &self, const Standard_Integer a0) -> const TopoDS_Edge & { return self.SectionEdge(a0); });
cls_TopOpeBRepDS_DataStructure.def("SectionEdge", (const TopoDS_Edge & (TopOpeBRepDS_DataStructure::*)(const Standard_Integer, const Standard_Boolean) const) &TopOpeBRepDS_DataStructure::SectionEdge, "None", py::arg("I"), py::arg("FindKeep"));
cls_TopOpeBRepDS_DataStructure.def("SectionEdge", [](TopOpeBRepDS_DataStructure &self, const TopoDS_Edge & a0) -> Standard_Integer { return self.SectionEdge(a0); });
cls_TopOpeBRepDS_DataStructure.def("SectionEdge", (Standard_Integer (TopOpeBRepDS_DataStructure::*)(const TopoDS_Edge &, const Standard_Boolean) const) &TopOpeBRepDS_DataStructure::SectionEdge, "None", py::arg("E"), py::arg("FindKeep"));
cls_TopOpeBRepDS_DataStructure.def("IsSectionEdge", [](TopOpeBRepDS_DataStructure &self, const TopoDS_Edge & a0) -> Standard_Boolean { return self.IsSectionEdge(a0); });
cls_TopOpeBRepDS_DataStructure.def("IsSectionEdge", (Standard_Boolean (TopOpeBRepDS_DataStructure::*)(const TopoDS_Edge &, const Standard_Boolean) const) &TopOpeBRepDS_DataStructure::IsSectionEdge, "None", py::arg("E"), py::arg("FindKeep"));
cls_TopOpeBRepDS_DataStructure.def("HasGeometry", (Standard_Boolean (TopOpeBRepDS_DataStructure::*)(const TopoDS_Shape &) const) &TopOpeBRepDS_DataStructure::HasGeometry, "Returns True if <S> has new geometries, i.e : True si : HasShape(S) True S a une liste d'interferences non vide. S = SOLID, FACE, EDGE : true/false S = SHELL, WIRE, VERTEX : false.", py::arg("S"));
cls_TopOpeBRepDS_DataStructure.def("HasShape", [](TopOpeBRepDS_DataStructure &self, const TopoDS_Shape & a0) -> Standard_Boolean { return self.HasShape(a0); });
cls_TopOpeBRepDS_DataStructure.def("HasShape", (Standard_Boolean (TopOpeBRepDS_DataStructure::*)(const TopoDS_Shape &, const Standard_Boolean) const) &TopOpeBRepDS_DataStructure::HasShape, "Returns True if <S> est dans myShapes", py::arg("S"), py::arg("FindKeep"));
cls_TopOpeBRepDS_DataStructure.def("SetNewSurface", (void (TopOpeBRepDS_DataStructure::*)(const TopoDS_Shape &, const opencascade::handle<Geom_Surface> &)) &TopOpeBRepDS_DataStructure::SetNewSurface, "None", py::arg("F"), py::arg("S"));
cls_TopOpeBRepDS_DataStructure.def("HasNewSurface", (Standard_Boolean (TopOpeBRepDS_DataStructure::*)(const TopoDS_Shape &) const) &TopOpeBRepDS_DataStructure::HasNewSurface, "None", py::arg("F"));
cls_TopOpeBRepDS_DataStructure.def("NewSurface", (const opencascade::handle<Geom_Surface> & (TopOpeBRepDS_DataStructure::*)(const TopoDS_Shape &) const) &TopOpeBRepDS_DataStructure::NewSurface, "None", py::arg("F"));
cls_TopOpeBRepDS_DataStructure.def("Isfafa", (void (TopOpeBRepDS_DataStructure::*)(const Standard_Boolean)) &TopOpeBRepDS_DataStructure::Isfafa, "None", py::arg("isfafa"));
cls_TopOpeBRepDS_DataStructure.def("Isfafa", (Standard_Boolean (TopOpeBRepDS_DataStructure::*)() const) &TopOpeBRepDS_DataStructure::Isfafa, "None");
cls_TopOpeBRepDS_DataStructure.def("ChangeMapOfShapeWithStateObj", (TopOpeBRepDS_IndexedDataMapOfShapeWithState & (TopOpeBRepDS_DataStructure::*)()) &TopOpeBRepDS_DataStructure::ChangeMapOfShapeWithStateObj, "None");
cls_TopOpeBRepDS_DataStructure.def("ChangeMapOfShapeWithStateTool", (TopOpeBRepDS_IndexedDataMapOfShapeWithState & (TopOpeBRepDS_DataStructure::*)()) &TopOpeBRepDS_DataStructure::ChangeMapOfShapeWithStateTool, "None");
cls_TopOpeBRepDS_DataStructure.def("ChangeMapOfShapeWithState", [](TopOpeBRepDS_DataStructure &self, const TopoDS_Shape & aShape, Standard_Boolean & aFlag){ TopOpeBRepDS_IndexedDataMapOfShapeWithState & rv = self.ChangeMapOfShapeWithState(aShape, aFlag); return std::tuple<TopOpeBRepDS_IndexedDataMapOfShapeWithState &, Standard_Boolean &>(rv, aFlag); }, "None", py::arg("aShape"), py::arg("aFlag"));
cls_TopOpeBRepDS_DataStructure.def("GetShapeWithState", (const TopOpeBRepDS_ShapeWithState & (TopOpeBRepDS_DataStructure::*)(const TopoDS_Shape &) const) &TopOpeBRepDS_DataStructure::GetShapeWithState, "None", py::arg("aShape"));
cls_TopOpeBRepDS_DataStructure.def("ChangeMapOfRejectedShapesObj", (TopTools_IndexedMapOfShape & (TopOpeBRepDS_DataStructure::*)()) &TopOpeBRepDS_DataStructure::ChangeMapOfRejectedShapesObj, "None");
cls_TopOpeBRepDS_DataStructure.def("ChangeMapOfRejectedShapesTool", (TopTools_IndexedMapOfShape & (TopOpeBRepDS_DataStructure::*)()) &TopOpeBRepDS_DataStructure::ChangeMapOfRejectedShapesTool, "None");

// CLASS: TOPOPEBREPDS_BUILDTOOL
py::class_<TopOpeBRepDS_BuildTool> cls_TopOpeBRepDS_BuildTool(mod, "TopOpeBRepDS_BuildTool", "Provides a Tool to build topologies. Used to instantiate the Builder algorithm.");

// Constructors
cls_TopOpeBRepDS_BuildTool.def(py::init<>());
cls_TopOpeBRepDS_BuildTool.def(py::init<const TopOpeBRepTool_OutCurveType>(), py::arg("OutCurveType"));
cls_TopOpeBRepDS_BuildTool.def(py::init<const TopOpeBRepTool_GeomTool &>(), py::arg("GT"));

// Methods
// cls_TopOpeBRepDS_BuildTool.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepDS_BuildTool::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepDS_BuildTool.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepDS_BuildTool::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_BuildTool.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepDS_BuildTool::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepDS_BuildTool.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepDS_BuildTool::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_BuildTool.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepDS_BuildTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepDS_BuildTool.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepDS_BuildTool::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepDS_BuildTool.def("GetGeomTool", (const TopOpeBRepTool_GeomTool & (TopOpeBRepDS_BuildTool::*)() const) &TopOpeBRepDS_BuildTool::GetGeomTool, "None");
cls_TopOpeBRepDS_BuildTool.def("ChangeGeomTool", (TopOpeBRepTool_GeomTool & (TopOpeBRepDS_BuildTool::*)()) &TopOpeBRepDS_BuildTool::ChangeGeomTool, "None");
cls_TopOpeBRepDS_BuildTool.def("MakeVertex", (void (TopOpeBRepDS_BuildTool::*)(TopoDS_Shape &, const TopOpeBRepDS_Point &) const) &TopOpeBRepDS_BuildTool::MakeVertex, "None", py::arg("V"), py::arg("P"));
cls_TopOpeBRepDS_BuildTool.def("MakeEdge", (void (TopOpeBRepDS_BuildTool::*)(TopoDS_Shape &, const TopOpeBRepDS_Curve &) const) &TopOpeBRepDS_BuildTool::MakeEdge, "None", py::arg("E"), py::arg("C"));
cls_TopOpeBRepDS_BuildTool.def("MakeEdge", (void (TopOpeBRepDS_BuildTool::*)(TopoDS_Shape &, const TopOpeBRepDS_Curve &, const TopOpeBRepDS_DataStructure &) const) &TopOpeBRepDS_BuildTool::MakeEdge, "None", py::arg("E"), py::arg("C"), py::arg("DS"));
cls_TopOpeBRepDS_BuildTool.def("MakeEdge", (void (TopOpeBRepDS_BuildTool::*)(TopoDS_Shape &, const opencascade::handle<Geom_Curve> &, const Standard_Real) const) &TopOpeBRepDS_BuildTool::MakeEdge, "None", py::arg("E"), py::arg("C"), py::arg("Tol"));
cls_TopOpeBRepDS_BuildTool.def("MakeEdge", (void (TopOpeBRepDS_BuildTool::*)(TopoDS_Shape &) const) &TopOpeBRepDS_BuildTool::MakeEdge, "None", py::arg("E"));
cls_TopOpeBRepDS_BuildTool.def("MakeWire", (void (TopOpeBRepDS_BuildTool::*)(TopoDS_Shape &) const) &TopOpeBRepDS_BuildTool::MakeWire, "None", py::arg("W"));
cls_TopOpeBRepDS_BuildTool.def("MakeFace", (void (TopOpeBRepDS_BuildTool::*)(TopoDS_Shape &, const TopOpeBRepDS_Surface &) const) &TopOpeBRepDS_BuildTool::MakeFace, "None", py::arg("F"), py::arg("S"));
cls_TopOpeBRepDS_BuildTool.def("MakeShell", (void (TopOpeBRepDS_BuildTool::*)(TopoDS_Shape &) const) &TopOpeBRepDS_BuildTool::MakeShell, "None", py::arg("Sh"));
cls_TopOpeBRepDS_BuildTool.def("MakeSolid", (void (TopOpeBRepDS_BuildTool::*)(TopoDS_Shape &) const) &TopOpeBRepDS_BuildTool::MakeSolid, "None", py::arg("S"));
cls_TopOpeBRepDS_BuildTool.def("CopyEdge", (void (TopOpeBRepDS_BuildTool::*)(const TopoDS_Shape &, TopoDS_Shape &) const) &TopOpeBRepDS_BuildTool::CopyEdge, "Make an edge <Eou> with the curve of the edge <Ein>", py::arg("Ein"), py::arg("Eou"));
cls_TopOpeBRepDS_BuildTool.def("GetOrientedEdgeVertices", [](TopOpeBRepDS_BuildTool &self, TopoDS_Edge & E, TopoDS_Vertex & Vmin, TopoDS_Vertex & Vmax, Standard_Real & Parmin, Standard_Real & Parmax){ self.GetOrientedEdgeVertices(E, Vmin, Vmax, Parmin, Parmax); return std::tuple<Standard_Real &, Standard_Real &>(Parmin, Parmax); }, "None", py::arg("E"), py::arg("Vmin"), py::arg("Vmax"), py::arg("Parmin"), py::arg("Parmax"));
cls_TopOpeBRepDS_BuildTool.def("UpdateEdgeCurveTol", [](TopOpeBRepDS_BuildTool &self, const TopoDS_Face & F1, const TopoDS_Face & F2, TopoDS_Edge & E, const opencascade::handle<Geom_Curve> & C3Dnew, const Standard_Real tol3d, const Standard_Real tol2d1, const Standard_Real tol2d2, Standard_Real & newtol, Standard_Real & newparmin, Standard_Real & newparmax){ self.UpdateEdgeCurveTol(F1, F2, E, C3Dnew, tol3d, tol2d1, tol2d2, newtol, newparmin, newparmax); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(newtol, newparmin, newparmax); }, "None", py::arg("F1"), py::arg("F2"), py::arg("E"), py::arg("C3Dnew"), py::arg("tol3d"), py::arg("tol2d1"), py::arg("tol2d2"), py::arg("newtol"), py::arg("newparmin"), py::arg("newparmax"));
cls_TopOpeBRepDS_BuildTool.def("ApproxCurves", [](TopOpeBRepDS_BuildTool &self, const TopOpeBRepDS_Curve & C, TopoDS_Edge & E, Standard_Integer & inewC, const opencascade::handle<TopOpeBRepDS_HDataStructure> & HDS){ self.ApproxCurves(C, E, inewC, HDS); return inewC; }, "None", py::arg("C"), py::arg("E"), py::arg("inewC"), py::arg("HDS"));
cls_TopOpeBRepDS_BuildTool.def("ComputePCurves", (void (TopOpeBRepDS_BuildTool::*)(const TopOpeBRepDS_Curve &, TopoDS_Edge &, TopOpeBRepDS_Curve &, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean) const) &TopOpeBRepDS_BuildTool::ComputePCurves, "None", py::arg("C"), py::arg("E"), py::arg("newC"), py::arg("CompPC1"), py::arg("CompPC2"), py::arg("CompC3D"));
cls_TopOpeBRepDS_BuildTool.def("PutPCurves", (void (TopOpeBRepDS_BuildTool::*)(const TopOpeBRepDS_Curve &, TopoDS_Edge &, const Standard_Boolean, const Standard_Boolean) const) &TopOpeBRepDS_BuildTool::PutPCurves, "None", py::arg("newC"), py::arg("E"), py::arg("CompPC1"), py::arg("CompPC2"));
cls_TopOpeBRepDS_BuildTool.def("RecomputeCurves", [](TopOpeBRepDS_BuildTool &self, const TopOpeBRepDS_Curve & C, const TopoDS_Edge & oldE, TopoDS_Edge & E, Standard_Integer & inewC, const opencascade::handle<TopOpeBRepDS_HDataStructure> & HDS){ self.RecomputeCurves(C, oldE, E, inewC, HDS); return inewC; }, "None", py::arg("C"), py::arg("oldE"), py::arg("E"), py::arg("inewC"), py::arg("HDS"));
cls_TopOpeBRepDS_BuildTool.def("CopyFace", (void (TopOpeBRepDS_BuildTool::*)(const TopoDS_Shape &, TopoDS_Shape &) const) &TopOpeBRepDS_BuildTool::CopyFace, "Make a face <Fou> with the surface of the face <Fin>", py::arg("Fin"), py::arg("Fou"));
cls_TopOpeBRepDS_BuildTool.def("AddEdgeVertex", (void (TopOpeBRepDS_BuildTool::*)(const TopoDS_Shape &, TopoDS_Shape &, const TopoDS_Shape &) const) &TopOpeBRepDS_BuildTool::AddEdgeVertex, "None", py::arg("Ein"), py::arg("Eou"), py::arg("V"));
cls_TopOpeBRepDS_BuildTool.def("AddEdgeVertex", (void (TopOpeBRepDS_BuildTool::*)(TopoDS_Shape &, const TopoDS_Shape &) const) &TopOpeBRepDS_BuildTool::AddEdgeVertex, "None", py::arg("E"), py::arg("V"));
cls_TopOpeBRepDS_BuildTool.def("AddWireEdge", (void (TopOpeBRepDS_BuildTool::*)(TopoDS_Shape &, const TopoDS_Shape &) const) &TopOpeBRepDS_BuildTool::AddWireEdge, "None", py::arg("W"), py::arg("E"));
cls_TopOpeBRepDS_BuildTool.def("AddFaceWire", (void (TopOpeBRepDS_BuildTool::*)(TopoDS_Shape &, const TopoDS_Shape &) const) &TopOpeBRepDS_BuildTool::AddFaceWire, "None", py::arg("F"), py::arg("W"));
cls_TopOpeBRepDS_BuildTool.def("AddShellFace", (void (TopOpeBRepDS_BuildTool::*)(TopoDS_Shape &, const TopoDS_Shape &) const) &TopOpeBRepDS_BuildTool::AddShellFace, "None", py::arg("Sh"), py::arg("F"));
cls_TopOpeBRepDS_BuildTool.def("AddSolidShell", (void (TopOpeBRepDS_BuildTool::*)(TopoDS_Shape &, const TopoDS_Shape &) const) &TopOpeBRepDS_BuildTool::AddSolidShell, "None", py::arg("S"), py::arg("Sh"));
cls_TopOpeBRepDS_BuildTool.def("Parameter", (void (TopOpeBRepDS_BuildTool::*)(const TopoDS_Shape &, const TopoDS_Shape &, const Standard_Real) const) &TopOpeBRepDS_BuildTool::Parameter, "Sets the parameter <P> for the vertex <V> on the edge <E>.", py::arg("E"), py::arg("V"), py::arg("P"));
cls_TopOpeBRepDS_BuildTool.def("Range", (void (TopOpeBRepDS_BuildTool::*)(const TopoDS_Shape &, const Standard_Real, const Standard_Real) const) &TopOpeBRepDS_BuildTool::Range, "Sets the range of edge <E>.", py::arg("E"), py::arg("first"), py::arg("last"));
cls_TopOpeBRepDS_BuildTool.def("UpdateEdge", (void (TopOpeBRepDS_BuildTool::*)(const TopoDS_Shape &, TopoDS_Shape &) const) &TopOpeBRepDS_BuildTool::UpdateEdge, "Sets the range of edge <Eou> from <Ein> only when <Ein> has a closed geometry.", py::arg("Ein"), py::arg("Eou"));
cls_TopOpeBRepDS_BuildTool.def("Parameter", (void (TopOpeBRepDS_BuildTool::*)(const TopOpeBRepDS_Curve &, TopoDS_Shape &, TopoDS_Shape &) const) &TopOpeBRepDS_BuildTool::Parameter, "Compute the parameter of the vertex <V>, supported by the edge <E>, on the curve <C>.", py::arg("C"), py::arg("E"), py::arg("V"));
cls_TopOpeBRepDS_BuildTool.def("Curve3D", (void (TopOpeBRepDS_BuildTool::*)(TopoDS_Shape &, const opencascade::handle<Geom_Curve> &, const Standard_Real) const) &TopOpeBRepDS_BuildTool::Curve3D, "Sets the curve <C> for the edge <E>", py::arg("E"), py::arg("C"), py::arg("Tol"));
cls_TopOpeBRepDS_BuildTool.def("PCurve", (void (TopOpeBRepDS_BuildTool::*)(TopoDS_Shape &, TopoDS_Shape &, const opencascade::handle<Geom2d_Curve> &) const) &TopOpeBRepDS_BuildTool::PCurve, "Sets the pcurve <C> for the edge <E> on the face <F>. If OverWrite is True the old pcurve if there is one is overwritten, else the two pcurves are set.", py::arg("F"), py::arg("E"), py::arg("C"));
cls_TopOpeBRepDS_BuildTool.def("PCurve", (void (TopOpeBRepDS_BuildTool::*)(TopoDS_Shape &, TopoDS_Shape &, const TopOpeBRepDS_Curve &, const opencascade::handle<Geom2d_Curve> &) const) &TopOpeBRepDS_BuildTool::PCurve, "None", py::arg("F"), py::arg("E"), py::arg("CDS"), py::arg("C"));
cls_TopOpeBRepDS_BuildTool.def("Orientation", (void (TopOpeBRepDS_BuildTool::*)(TopoDS_Shape &, const TopAbs_Orientation) const) &TopOpeBRepDS_BuildTool::Orientation, "None", py::arg("S"), py::arg("O"));
cls_TopOpeBRepDS_BuildTool.def("Orientation", (TopAbs_Orientation (TopOpeBRepDS_BuildTool::*)(const TopoDS_Shape &) const) &TopOpeBRepDS_BuildTool::Orientation, "None", py::arg("S"));
cls_TopOpeBRepDS_BuildTool.def("Closed", (void (TopOpeBRepDS_BuildTool::*)(TopoDS_Shape &, const Standard_Boolean) const) &TopOpeBRepDS_BuildTool::Closed, "None", py::arg("S"), py::arg("B"));
cls_TopOpeBRepDS_BuildTool.def("Approximation", (Standard_Boolean (TopOpeBRepDS_BuildTool::*)() const) &TopOpeBRepDS_BuildTool::Approximation, "None");
cls_TopOpeBRepDS_BuildTool.def("UpdateSurface", (void (TopOpeBRepDS_BuildTool::*)(const TopoDS_Shape &, const opencascade::handle<Geom_Surface> &) const) &TopOpeBRepDS_BuildTool::UpdateSurface, "None", py::arg("F"), py::arg("SU"));
cls_TopOpeBRepDS_BuildTool.def("UpdateSurface", (void (TopOpeBRepDS_BuildTool::*)(const TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Shape &) const) &TopOpeBRepDS_BuildTool::UpdateSurface, "None", py::arg("E"), py::arg("oldF"), py::arg("newF"));
cls_TopOpeBRepDS_BuildTool.def("OverWrite", (Standard_Boolean (TopOpeBRepDS_BuildTool::*)() const) &TopOpeBRepDS_BuildTool::OverWrite, "None");
cls_TopOpeBRepDS_BuildTool.def("OverWrite", (void (TopOpeBRepDS_BuildTool::*)(const Standard_Boolean)) &TopOpeBRepDS_BuildTool::OverWrite, "None", py::arg("O"));
cls_TopOpeBRepDS_BuildTool.def("Translate", (Standard_Boolean (TopOpeBRepDS_BuildTool::*)() const) &TopOpeBRepDS_BuildTool::Translate, "None");
cls_TopOpeBRepDS_BuildTool.def("Translate", (void (TopOpeBRepDS_BuildTool::*)(const Standard_Boolean)) &TopOpeBRepDS_BuildTool::Translate, "None", py::arg("T"));

// CLASS: TOPOPEBREPDS_LISTOFSHAPEON1STATE
py::class_<TopOpeBRepDS_ListOfShapeOn1State> cls_TopOpeBRepDS_ListOfShapeOn1State(mod, "TopOpeBRepDS_ListOfShapeOn1State", "represent a list of shape");

// Constructors
cls_TopOpeBRepDS_ListOfShapeOn1State.def(py::init<>());

// Methods
// cls_TopOpeBRepDS_ListOfShapeOn1State.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepDS_ListOfShapeOn1State::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepDS_ListOfShapeOn1State.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepDS_ListOfShapeOn1State::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_ListOfShapeOn1State.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepDS_ListOfShapeOn1State::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepDS_ListOfShapeOn1State.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepDS_ListOfShapeOn1State::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_ListOfShapeOn1State.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepDS_ListOfShapeOn1State::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepDS_ListOfShapeOn1State.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepDS_ListOfShapeOn1State::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepDS_ListOfShapeOn1State.def("ListOnState", (const TopTools_ListOfShape & (TopOpeBRepDS_ListOfShapeOn1State::*)() const) &TopOpeBRepDS_ListOfShapeOn1State::ListOnState, "None");
cls_TopOpeBRepDS_ListOfShapeOn1State.def("ChangeListOnState", (TopTools_ListOfShape & (TopOpeBRepDS_ListOfShapeOn1State::*)()) &TopOpeBRepDS_ListOfShapeOn1State::ChangeListOnState, "None");
cls_TopOpeBRepDS_ListOfShapeOn1State.def("IsSplit", (Standard_Boolean (TopOpeBRepDS_ListOfShapeOn1State::*)() const) &TopOpeBRepDS_ListOfShapeOn1State::IsSplit, "None");
cls_TopOpeBRepDS_ListOfShapeOn1State.def("Split", [](TopOpeBRepDS_ListOfShapeOn1State &self) -> void { return self.Split(); });
cls_TopOpeBRepDS_ListOfShapeOn1State.def("Split", (void (TopOpeBRepDS_ListOfShapeOn1State::*)(const Standard_Boolean)) &TopOpeBRepDS_ListOfShapeOn1State::Split, "None", py::arg("B"));
cls_TopOpeBRepDS_ListOfShapeOn1State.def("Clear", (void (TopOpeBRepDS_ListOfShapeOn1State::*)()) &TopOpeBRepDS_ListOfShapeOn1State::Clear, "None");

// TYPEDEF: TOPOPEBREPDS_DATAMAPOFSHAPELISTOFSHAPEON1STATE
bind_NCollection_DataMap<TopoDS_Shape, TopOpeBRepDS_ListOfShapeOn1State, TopTools_ShapeMapHasher>(mod, "TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State", py::module_local(false));

// TYPEDEF: TOPOPEBREPDS_DATAMAPITERATOROFDATAMAPOFSHAPELISTOFSHAPEON1STATE

// TYPEDEF: TOPOPEBREPDS_DATAMAPOFSHAPESTATE
bind_NCollection_DataMap<TopoDS_Shape, TopAbs_State, TopTools_ShapeMapHasher>(mod, "TopOpeBRepDS_DataMapOfShapeState", py::module_local(false));

// TYPEDEF: TOPOPEBREPDS_DATAMAPITERATOROFDATAMAPOFSHAPESTATE

// CLASS: TOPOPEBREPDS_SHAPESHAPEINTERFERENCE
py::class_<TopOpeBRepDS_ShapeShapeInterference, opencascade::handle<TopOpeBRepDS_ShapeShapeInterference>, TopOpeBRepDS_Interference> cls_TopOpeBRepDS_ShapeShapeInterference(mod, "TopOpeBRepDS_ShapeShapeInterference", "Interference");

// Constructors
cls_TopOpeBRepDS_ShapeShapeInterference.def(py::init<const TopOpeBRepDS_Transition &, const TopOpeBRepDS_Kind, const Standard_Integer, const TopOpeBRepDS_Kind, const Standard_Integer, const Standard_Boolean, const TopOpeBRepDS_Config>(), py::arg("T"), py::arg("ST"), py::arg("S"), py::arg("GT"), py::arg("G"), py::arg("GBound"), py::arg("C"));

// Methods
cls_TopOpeBRepDS_ShapeShapeInterference.def("Config", (TopOpeBRepDS_Config (TopOpeBRepDS_ShapeShapeInterference::*)() const) &TopOpeBRepDS_ShapeShapeInterference::Config, "None");
cls_TopOpeBRepDS_ShapeShapeInterference.def("GBound", (Standard_Boolean (TopOpeBRepDS_ShapeShapeInterference::*)() const) &TopOpeBRepDS_ShapeShapeInterference::GBound, "None");
cls_TopOpeBRepDS_ShapeShapeInterference.def("SetGBound", (void (TopOpeBRepDS_ShapeShapeInterference::*)(const Standard_Boolean)) &TopOpeBRepDS_ShapeShapeInterference::SetGBound, "None", py::arg("b"));
cls_TopOpeBRepDS_ShapeShapeInterference.def_static("get_type_name_", (const char * (*)()) &TopOpeBRepDS_ShapeShapeInterference::get_type_name, "None");
cls_TopOpeBRepDS_ShapeShapeInterference.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TopOpeBRepDS_ShapeShapeInterference::get_type_descriptor, "None");
cls_TopOpeBRepDS_ShapeShapeInterference.def("DynamicType", (const opencascade::handle<Standard_Type> & (TopOpeBRepDS_ShapeShapeInterference::*)() const) &TopOpeBRepDS_ShapeShapeInterference::DynamicType, "None");

// CLASS: TOPOPEBREPDS_EDGEVERTEXINTERFERENCE
py::class_<TopOpeBRepDS_EdgeVertexInterference, opencascade::handle<TopOpeBRepDS_EdgeVertexInterference>, TopOpeBRepDS_ShapeShapeInterference> cls_TopOpeBRepDS_EdgeVertexInterference(mod, "TopOpeBRepDS_EdgeVertexInterference", "An interference with a parameter (ShapeShapeInterference).");

// Constructors
cls_TopOpeBRepDS_EdgeVertexInterference.def(py::init<const TopOpeBRepDS_Transition &, const TopOpeBRepDS_Kind, const Standard_Integer, const Standard_Integer, const Standard_Boolean, const TopOpeBRepDS_Config, const Standard_Real>(), py::arg("T"), py::arg("ST"), py::arg("S"), py::arg("G"), py::arg("GIsBound"), py::arg("C"), py::arg("P"));
cls_TopOpeBRepDS_EdgeVertexInterference.def(py::init<const TopOpeBRepDS_Transition &, const Standard_Integer, const Standard_Integer, const Standard_Boolean, const TopOpeBRepDS_Config, const Standard_Real>(), py::arg("T"), py::arg("S"), py::arg("G"), py::arg("GIsBound"), py::arg("C"), py::arg("P"));

// Methods
cls_TopOpeBRepDS_EdgeVertexInterference.def("Parameter", (Standard_Real (TopOpeBRepDS_EdgeVertexInterference::*)() const) &TopOpeBRepDS_EdgeVertexInterference::Parameter, "None");
cls_TopOpeBRepDS_EdgeVertexInterference.def("Parameter", (void (TopOpeBRepDS_EdgeVertexInterference::*)(const Standard_Real)) &TopOpeBRepDS_EdgeVertexInterference::Parameter, "None", py::arg("P"));
cls_TopOpeBRepDS_EdgeVertexInterference.def_static("get_type_name_", (const char * (*)()) &TopOpeBRepDS_EdgeVertexInterference::get_type_name, "None");
cls_TopOpeBRepDS_EdgeVertexInterference.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TopOpeBRepDS_EdgeVertexInterference::get_type_descriptor, "None");
cls_TopOpeBRepDS_EdgeVertexInterference.def("DynamicType", (const opencascade::handle<Standard_Type> & (TopOpeBRepDS_EdgeVertexInterference::*)() const) &TopOpeBRepDS_EdgeVertexInterference::DynamicType, "None");

// CLASS: TOPOPEBREPDS_FACEEDGEINTERFERENCE
py::class_<TopOpeBRepDS_FaceEdgeInterference, opencascade::handle<TopOpeBRepDS_FaceEdgeInterference>, TopOpeBRepDS_ShapeShapeInterference> cls_TopOpeBRepDS_FaceEdgeInterference(mod, "TopOpeBRepDS_FaceEdgeInterference", "ShapeShapeInterference");

// Constructors
cls_TopOpeBRepDS_FaceEdgeInterference.def(py::init<const TopOpeBRepDS_Transition &, const Standard_Integer, const Standard_Integer, const Standard_Boolean, const TopOpeBRepDS_Config>(), py::arg("T"), py::arg("S"), py::arg("G"), py::arg("GIsBound"), py::arg("C"));

// Methods
cls_TopOpeBRepDS_FaceEdgeInterference.def_static("get_type_name_", (const char * (*)()) &TopOpeBRepDS_FaceEdgeInterference::get_type_name, "None");
cls_TopOpeBRepDS_FaceEdgeInterference.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TopOpeBRepDS_FaceEdgeInterference::get_type_descriptor, "None");
cls_TopOpeBRepDS_FaceEdgeInterference.def("DynamicType", (const opencascade::handle<Standard_Type> & (TopOpeBRepDS_FaceEdgeInterference::*)() const) &TopOpeBRepDS_FaceEdgeInterference::DynamicType, "None");

// CLASS: TOPOPEBREPDS_INTERFERENCEITERATOR
py::class_<TopOpeBRepDS_InterferenceIterator> cls_TopOpeBRepDS_InterferenceIterator(mod, "TopOpeBRepDS_InterferenceIterator", "Iterate on interferences of a list, matching conditions on interferences. Nota : inheritance of ListIteratorOfListOfInterference from TopOpeBRepDS has not been done because of the impossibility of naming the classical More, Next methods which are declared as static in TCollection_ListIteratorOfList ... . ListIteratorOfList has benn placed as a field of InterferenceIterator.");

// Constructors
cls_TopOpeBRepDS_InterferenceIterator.def(py::init<>());
cls_TopOpeBRepDS_InterferenceIterator.def(py::init<const TopOpeBRepDS_ListOfInterference &>(), py::arg("L"));

// Methods
// cls_TopOpeBRepDS_InterferenceIterator.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepDS_InterferenceIterator::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepDS_InterferenceIterator.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepDS_InterferenceIterator::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_InterferenceIterator.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepDS_InterferenceIterator::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepDS_InterferenceIterator.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepDS_InterferenceIterator::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_InterferenceIterator.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepDS_InterferenceIterator::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepDS_InterferenceIterator.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepDS_InterferenceIterator::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepDS_InterferenceIterator.def("Init", (void (TopOpeBRepDS_InterferenceIterator::*)(const TopOpeBRepDS_ListOfInterference &)) &TopOpeBRepDS_InterferenceIterator::Init, "re-initialize interference iteration process on the list of interference <L>. Conditions are not modified.", py::arg("L"));
cls_TopOpeBRepDS_InterferenceIterator.def("GeometryKind", (void (TopOpeBRepDS_InterferenceIterator::*)(const TopOpeBRepDS_Kind)) &TopOpeBRepDS_InterferenceIterator::GeometryKind, "define a condition on interference iteration process. Interference must match the Geometry Kind <ST>", py::arg("GK"));
cls_TopOpeBRepDS_InterferenceIterator.def("Geometry", (void (TopOpeBRepDS_InterferenceIterator::*)(const Standard_Integer)) &TopOpeBRepDS_InterferenceIterator::Geometry, "define a condition on interference iteration process. Interference must match the Geometry <G>", py::arg("G"));
cls_TopOpeBRepDS_InterferenceIterator.def("SupportKind", (void (TopOpeBRepDS_InterferenceIterator::*)(const TopOpeBRepDS_Kind)) &TopOpeBRepDS_InterferenceIterator::SupportKind, "define a condition on interference iteration process. Interference must match the Support Kind <ST>", py::arg("ST"));
cls_TopOpeBRepDS_InterferenceIterator.def("Support", (void (TopOpeBRepDS_InterferenceIterator::*)(const Standard_Integer)) &TopOpeBRepDS_InterferenceIterator::Support, "define a condition on interference iteration process. Interference must match the Support <S>", py::arg("S"));
cls_TopOpeBRepDS_InterferenceIterator.def("Match", (void (TopOpeBRepDS_InterferenceIterator::*)()) &TopOpeBRepDS_InterferenceIterator::Match, "reach for an interference matching the conditions (if defined).");
cls_TopOpeBRepDS_InterferenceIterator.def("MatchInterference", (Standard_Boolean (TopOpeBRepDS_InterferenceIterator::*)(const opencascade::handle<TopOpeBRepDS_Interference> &) const) &TopOpeBRepDS_InterferenceIterator::MatchInterference, "Returns True if the Interference <I> matches the conditions (if defined). If no conditions defined, returns True.", py::arg("I"));
cls_TopOpeBRepDS_InterferenceIterator.def("More", (Standard_Boolean (TopOpeBRepDS_InterferenceIterator::*)() const) &TopOpeBRepDS_InterferenceIterator::More, "Returns True if there is a current Interference in the iteration.");
cls_TopOpeBRepDS_InterferenceIterator.def("Next", (void (TopOpeBRepDS_InterferenceIterator::*)()) &TopOpeBRepDS_InterferenceIterator::Next, "Move to the next Interference.");
cls_TopOpeBRepDS_InterferenceIterator.def("Value", (const opencascade::handle<TopOpeBRepDS_Interference> & (TopOpeBRepDS_InterferenceIterator::*)() const) &TopOpeBRepDS_InterferenceIterator::Value, "Returns the current Interference, matching the conditions (if defined).");
cls_TopOpeBRepDS_InterferenceIterator.def("ChangeIterator", (TopOpeBRepDS_ListIteratorOfListOfInterference & (TopOpeBRepDS_InterferenceIterator::*)()) &TopOpeBRepDS_InterferenceIterator::ChangeIterator, "None");

// CLASS: TOPOPEBREPDS_HDATASTRUCTURE
py::class_<TopOpeBRepDS_HDataStructure, opencascade::handle<TopOpeBRepDS_HDataStructure>, Standard_Transient> cls_TopOpeBRepDS_HDataStructure(mod, "TopOpeBRepDS_HDataStructure", "None");

// Constructors
cls_TopOpeBRepDS_HDataStructure.def(py::init<>());

// Methods
cls_TopOpeBRepDS_HDataStructure.def("AddAncestors", (void (TopOpeBRepDS_HDataStructure::*)(const TopoDS_Shape &)) &TopOpeBRepDS_HDataStructure::AddAncestors, "None", py::arg("S"));
cls_TopOpeBRepDS_HDataStructure.def("AddAncestors", (void (TopOpeBRepDS_HDataStructure::*)(const TopoDS_Shape &, const TopAbs_ShapeEnum, const TopAbs_ShapeEnum)) &TopOpeBRepDS_HDataStructure::AddAncestors, "Update the data structure with shapes of type T1 containing a subshape of type T2 which is stored in the DS. Used by the previous one.", py::arg("S"), py::arg("T1"), py::arg("T2"));
cls_TopOpeBRepDS_HDataStructure.def("ChkIntg", (void (TopOpeBRepDS_HDataStructure::*)()) &TopOpeBRepDS_HDataStructure::ChkIntg, "Check the integrity of the DS");
cls_TopOpeBRepDS_HDataStructure.def("DS", (const TopOpeBRepDS_DataStructure & (TopOpeBRepDS_HDataStructure::*)() const) &TopOpeBRepDS_HDataStructure::DS, "None");
cls_TopOpeBRepDS_HDataStructure.def("ChangeDS", (TopOpeBRepDS_DataStructure & (TopOpeBRepDS_HDataStructure::*)()) &TopOpeBRepDS_HDataStructure::ChangeDS, "None");
cls_TopOpeBRepDS_HDataStructure.def("NbSurfaces", (Standard_Integer (TopOpeBRepDS_HDataStructure::*)() const) &TopOpeBRepDS_HDataStructure::NbSurfaces, "None");
cls_TopOpeBRepDS_HDataStructure.def("NbCurves", (Standard_Integer (TopOpeBRepDS_HDataStructure::*)() const) &TopOpeBRepDS_HDataStructure::NbCurves, "None");
cls_TopOpeBRepDS_HDataStructure.def("NbPoints", (Standard_Integer (TopOpeBRepDS_HDataStructure::*)() const) &TopOpeBRepDS_HDataStructure::NbPoints, "None");
cls_TopOpeBRepDS_HDataStructure.def("Surface", (const TopOpeBRepDS_Surface & (TopOpeBRepDS_HDataStructure::*)(const Standard_Integer) const) &TopOpeBRepDS_HDataStructure::Surface, "Returns the surface of index <I>.", py::arg("I"));
cls_TopOpeBRepDS_HDataStructure.def("SurfaceCurves", (TopOpeBRepDS_CurveIterator (TopOpeBRepDS_HDataStructure::*)(const Standard_Integer) const) &TopOpeBRepDS_HDataStructure::SurfaceCurves, "Returns an iterator on the curves on the surface <I>.", py::arg("I"));
cls_TopOpeBRepDS_HDataStructure.def("Curve", (const TopOpeBRepDS_Curve & (TopOpeBRepDS_HDataStructure::*)(const Standard_Integer) const) &TopOpeBRepDS_HDataStructure::Curve, "Returns the Curve of index <I>.", py::arg("I"));
cls_TopOpeBRepDS_HDataStructure.def("ChangeCurve", (TopOpeBRepDS_Curve & (TopOpeBRepDS_HDataStructure::*)(const Standard_Integer)) &TopOpeBRepDS_HDataStructure::ChangeCurve, "Returns the Curve of index <I>.", py::arg("I"));
cls_TopOpeBRepDS_HDataStructure.def("CurvePoints", (TopOpeBRepDS_PointIterator (TopOpeBRepDS_HDataStructure::*)(const Standard_Integer) const) &TopOpeBRepDS_HDataStructure::CurvePoints, "Returns an iterator on the points on the curve <I>.", py::arg("I"));
cls_TopOpeBRepDS_HDataStructure.def("Point", (const TopOpeBRepDS_Point & (TopOpeBRepDS_HDataStructure::*)(const Standard_Integer) const) &TopOpeBRepDS_HDataStructure::Point, "Returns the point of index <I>.", py::arg("I"));
cls_TopOpeBRepDS_HDataStructure.def("NbShapes", (Standard_Integer (TopOpeBRepDS_HDataStructure::*)() const) &TopOpeBRepDS_HDataStructure::NbShapes, "None");
cls_TopOpeBRepDS_HDataStructure.def("Shape", [](TopOpeBRepDS_HDataStructure &self, const Standard_Integer a0) -> const TopoDS_Shape & { return self.Shape(a0); });
cls_TopOpeBRepDS_HDataStructure.def("Shape", (const TopoDS_Shape & (TopOpeBRepDS_HDataStructure::*)(const Standard_Integer, const Standard_Boolean) const) &TopOpeBRepDS_HDataStructure::Shape, "Returns the shape of index <I> in the DS", py::arg("I"), py::arg("FindKeep"));
cls_TopOpeBRepDS_HDataStructure.def("Shape", [](TopOpeBRepDS_HDataStructure &self, const TopoDS_Shape & a0) -> Standard_Integer { return self.Shape(a0); });
cls_TopOpeBRepDS_HDataStructure.def("Shape", (Standard_Integer (TopOpeBRepDS_HDataStructure::*)(const TopoDS_Shape &, const Standard_Boolean) const) &TopOpeBRepDS_HDataStructure::Shape, "Returns the index of shape <S> in the DS returns 0 if <S> is not in the DS", py::arg("S"), py::arg("FindKeep"));
cls_TopOpeBRepDS_HDataStructure.def("HasGeometry", (Standard_Boolean (TopOpeBRepDS_HDataStructure::*)(const TopoDS_Shape &) const) &TopOpeBRepDS_HDataStructure::HasGeometry, "Returns True if <S> has new geometries.", py::arg("S"));
cls_TopOpeBRepDS_HDataStructure.def("HasShape", [](TopOpeBRepDS_HDataStructure &self, const TopoDS_Shape & a0) -> Standard_Boolean { return self.HasShape(a0); });
cls_TopOpeBRepDS_HDataStructure.def("HasShape", (Standard_Boolean (TopOpeBRepDS_HDataStructure::*)(const TopoDS_Shape &, const Standard_Boolean) const) &TopOpeBRepDS_HDataStructure::HasShape, "Returns True if <S> has new geometries (SOLID,FACE,EDGE) or if <S> (SHELL,WIRE) has sub-shape (FACE,EDGE) with new geometries", py::arg("S"), py::arg("FindKeep"));
cls_TopOpeBRepDS_HDataStructure.def("HasSameDomain", [](TopOpeBRepDS_HDataStructure &self, const TopoDS_Shape & a0) -> Standard_Boolean { return self.HasSameDomain(a0); });
cls_TopOpeBRepDS_HDataStructure.def("HasSameDomain", (Standard_Boolean (TopOpeBRepDS_HDataStructure::*)(const TopoDS_Shape &, const Standard_Boolean) const) &TopOpeBRepDS_HDataStructure::HasSameDomain, "Returns True if <S> share a geometrical domain with some other shapes.", py::arg("S"), py::arg("FindKeep"));
cls_TopOpeBRepDS_HDataStructure.def("SameDomain", (TopTools_ListIteratorOfListOfShape (TopOpeBRepDS_HDataStructure::*)(const TopoDS_Shape &) const) &TopOpeBRepDS_HDataStructure::SameDomain, "Returns an iterator on the SameDomain shapes attached to the shape <S>.", py::arg("S"));
cls_TopOpeBRepDS_HDataStructure.def("SameDomainOrientation", (TopOpeBRepDS_Config (TopOpeBRepDS_HDataStructure::*)(const TopoDS_Shape &) const) &TopOpeBRepDS_HDataStructure::SameDomainOrientation, "Returns orientation of shape <S> compared with its reference shape", py::arg("S"));
cls_TopOpeBRepDS_HDataStructure.def("SameDomainReference", (Standard_Integer (TopOpeBRepDS_HDataStructure::*)(const TopoDS_Shape &) const) &TopOpeBRepDS_HDataStructure::SameDomainReference, "Returns orientation of shape <S> compared with its reference shape", py::arg("S"));
cls_TopOpeBRepDS_HDataStructure.def("SolidSurfaces", (TopOpeBRepDS_SurfaceIterator (TopOpeBRepDS_HDataStructure::*)(const TopoDS_Shape &) const) &TopOpeBRepDS_HDataStructure::SolidSurfaces, "Returns an iterator on the surfaces attached to the solid <S>.", py::arg("S"));
cls_TopOpeBRepDS_HDataStructure.def("SolidSurfaces", (TopOpeBRepDS_SurfaceIterator (TopOpeBRepDS_HDataStructure::*)(const Standard_Integer) const) &TopOpeBRepDS_HDataStructure::SolidSurfaces, "Returns an iterator on the surfaces attached to the solid <I>.", py::arg("I"));
cls_TopOpeBRepDS_HDataStructure.def("FaceCurves", (TopOpeBRepDS_CurveIterator (TopOpeBRepDS_HDataStructure::*)(const TopoDS_Shape &) const) &TopOpeBRepDS_HDataStructure::FaceCurves, "Returns an iterator on the curves attached to the face <F>.", py::arg("F"));
cls_TopOpeBRepDS_HDataStructure.def("FaceCurves", (TopOpeBRepDS_CurveIterator (TopOpeBRepDS_HDataStructure::*)(const Standard_Integer) const) &TopOpeBRepDS_HDataStructure::FaceCurves, "Returns an iterator on the curves attached to the face <I>.", py::arg("I"));
cls_TopOpeBRepDS_HDataStructure.def("EdgePoints", (TopOpeBRepDS_PointIterator (TopOpeBRepDS_HDataStructure::*)(const TopoDS_Shape &) const) &TopOpeBRepDS_HDataStructure::EdgePoints, "Returns an iterator on the points attached to the edge <E>.", py::arg("E"));
cls_TopOpeBRepDS_HDataStructure.def("MakeCurve", (Standard_Integer (TopOpeBRepDS_HDataStructure::*)(const TopOpeBRepDS_Curve &, TopOpeBRepDS_Curve &)) &TopOpeBRepDS_HDataStructure::MakeCurve, "None", py::arg("C1"), py::arg("C2"));
cls_TopOpeBRepDS_HDataStructure.def("RemoveCurve", (void (TopOpeBRepDS_HDataStructure::*)(const Standard_Integer)) &TopOpeBRepDS_HDataStructure::RemoveCurve, "None", py::arg("iC"));
cls_TopOpeBRepDS_HDataStructure.def("NbGeometry", (Standard_Integer (TopOpeBRepDS_HDataStructure::*)(const TopOpeBRepDS_Kind) const) &TopOpeBRepDS_HDataStructure::NbGeometry, "None", py::arg("K"));
cls_TopOpeBRepDS_HDataStructure.def("NbTopology", (Standard_Integer (TopOpeBRepDS_HDataStructure::*)(const TopOpeBRepDS_Kind) const) &TopOpeBRepDS_HDataStructure::NbTopology, "None", py::arg("K"));
cls_TopOpeBRepDS_HDataStructure.def("NbTopology", (Standard_Integer (TopOpeBRepDS_HDataStructure::*)() const) &TopOpeBRepDS_HDataStructure::NbTopology, "None");
cls_TopOpeBRepDS_HDataStructure.def("EdgesSameParameter", (Standard_Boolean (TopOpeBRepDS_HDataStructure::*)() const) &TopOpeBRepDS_HDataStructure::EdgesSameParameter, "returns True if all the edges stored as shapes in the DS are SameParameter, otherwise False.");
cls_TopOpeBRepDS_HDataStructure.def("SortOnParameter", (void (TopOpeBRepDS_HDataStructure::*)(const TopOpeBRepDS_ListOfInterference &, TopOpeBRepDS_ListOfInterference &) const) &TopOpeBRepDS_HDataStructure::SortOnParameter, "None", py::arg("L1"), py::arg("L2"));
cls_TopOpeBRepDS_HDataStructure.def("SortOnParameter", (void (TopOpeBRepDS_HDataStructure::*)(TopOpeBRepDS_ListOfInterference &) const) &TopOpeBRepDS_HDataStructure::SortOnParameter, "None", py::arg("L"));
cls_TopOpeBRepDS_HDataStructure.def("MinMaxOnParameter", [](TopOpeBRepDS_HDataStructure &self, const TopOpeBRepDS_ListOfInterference & L, Standard_Real & Min, Standard_Real & Max){ self.MinMaxOnParameter(L, Min, Max); return std::tuple<Standard_Real &, Standard_Real &>(Min, Max); }, "None", py::arg("L"), py::arg("Min"), py::arg("Max"));
cls_TopOpeBRepDS_HDataStructure.def("ScanInterfList", (Standard_Boolean (TopOpeBRepDS_HDataStructure::*)(TopOpeBRepDS_ListIteratorOfListOfInterference &, const TopOpeBRepDS_Point &) const) &TopOpeBRepDS_HDataStructure::ScanInterfList, "Search, among a list of interferences accessed by the iterator <IT>, a geometry <G> whose 3D point is identical to the 3D point of the TheDSPoint <PDS>. returns True if such an interference has been found, False else. if True, iterator It points (by the Value() method) on the first interference accessing an identical 3D point.", py::arg("IT"), py::arg("PDS"));
cls_TopOpeBRepDS_HDataStructure.def("GetGeometry", [](TopOpeBRepDS_HDataStructure &self, TopOpeBRepDS_ListIteratorOfListOfInterference & IT, const TopOpeBRepDS_Point & PDS, Standard_Integer & G, TopOpeBRepDS_Kind & K){ Standard_Boolean rv = self.GetGeometry(IT, PDS, G, K); return std::tuple<Standard_Boolean, Standard_Integer &>(rv, G); }, "Get the geometry of a DS point <PDS>. Search for it with ScanInterfList (previous method). if found, set <G,K> to the geometry,kind of the interference found. returns the value of ScanInterfList().", py::arg("IT"), py::arg("PDS"), py::arg("G"), py::arg("K"));
cls_TopOpeBRepDS_HDataStructure.def("StoreInterference", [](TopOpeBRepDS_HDataStructure &self, const opencascade::handle<TopOpeBRepDS_Interference> & a0, TopOpeBRepDS_ListOfInterference & a1) -> void { return self.StoreInterference(a0, a1); });
cls_TopOpeBRepDS_HDataStructure.def("StoreInterference", (void (TopOpeBRepDS_HDataStructure::*)(const opencascade::handle<TopOpeBRepDS_Interference> &, TopOpeBRepDS_ListOfInterference &, const TCollection_AsciiString &)) &TopOpeBRepDS_HDataStructure::StoreInterference, "Add interference <I> to list <LI>.", py::arg("I"), py::arg("LI"), py::arg("str"));
cls_TopOpeBRepDS_HDataStructure.def("StoreInterference", [](TopOpeBRepDS_HDataStructure &self, const opencascade::handle<TopOpeBRepDS_Interference> & a0, const TopoDS_Shape & a1) -> void { return self.StoreInterference(a0, a1); });
cls_TopOpeBRepDS_HDataStructure.def("StoreInterference", (void (TopOpeBRepDS_HDataStructure::*)(const opencascade::handle<TopOpeBRepDS_Interference> &, const TopoDS_Shape &, const TCollection_AsciiString &)) &TopOpeBRepDS_HDataStructure::StoreInterference, "Add interference <I> to list of interference of shape <S>.", py::arg("I"), py::arg("S"), py::arg("str"));
cls_TopOpeBRepDS_HDataStructure.def("StoreInterference", [](TopOpeBRepDS_HDataStructure &self, const opencascade::handle<TopOpeBRepDS_Interference> & a0, const Standard_Integer a1) -> void { return self.StoreInterference(a0, a1); });
cls_TopOpeBRepDS_HDataStructure.def("StoreInterference", (void (TopOpeBRepDS_HDataStructure::*)(const opencascade::handle<TopOpeBRepDS_Interference> &, const Standard_Integer, const TCollection_AsciiString &)) &TopOpeBRepDS_HDataStructure::StoreInterference, "Add interference <I> to list of interference of shape <IS>.", py::arg("I"), py::arg("IS"), py::arg("str"));
cls_TopOpeBRepDS_HDataStructure.def("StoreInterferences", [](TopOpeBRepDS_HDataStructure &self, const TopOpeBRepDS_ListOfInterference & a0, const TopoDS_Shape & a1) -> void { return self.StoreInterferences(a0, a1); });
cls_TopOpeBRepDS_HDataStructure.def("StoreInterferences", (void (TopOpeBRepDS_HDataStructure::*)(const TopOpeBRepDS_ListOfInterference &, const TopoDS_Shape &, const TCollection_AsciiString &)) &TopOpeBRepDS_HDataStructure::StoreInterferences, "None", py::arg("LI"), py::arg("S"), py::arg("str"));
cls_TopOpeBRepDS_HDataStructure.def("StoreInterferences", [](TopOpeBRepDS_HDataStructure &self, const TopOpeBRepDS_ListOfInterference & a0, const Standard_Integer a1) -> void { return self.StoreInterferences(a0, a1); });
cls_TopOpeBRepDS_HDataStructure.def("StoreInterferences", (void (TopOpeBRepDS_HDataStructure::*)(const TopOpeBRepDS_ListOfInterference &, const Standard_Integer, const TCollection_AsciiString &)) &TopOpeBRepDS_HDataStructure::StoreInterferences, "None", py::arg("LI"), py::arg("IS"), py::arg("str"));
cls_TopOpeBRepDS_HDataStructure.def("ClearStoreInterferences", [](TopOpeBRepDS_HDataStructure &self, const TopOpeBRepDS_ListOfInterference & a0, const TopoDS_Shape & a1) -> void { return self.ClearStoreInterferences(a0, a1); });
cls_TopOpeBRepDS_HDataStructure.def("ClearStoreInterferences", (void (TopOpeBRepDS_HDataStructure::*)(const TopOpeBRepDS_ListOfInterference &, const TopoDS_Shape &, const TCollection_AsciiString &)) &TopOpeBRepDS_HDataStructure::ClearStoreInterferences, "None", py::arg("LI"), py::arg("S"), py::arg("str"));
cls_TopOpeBRepDS_HDataStructure.def("ClearStoreInterferences", [](TopOpeBRepDS_HDataStructure &self, const TopOpeBRepDS_ListOfInterference & a0, const Standard_Integer a1) -> void { return self.ClearStoreInterferences(a0, a1); });
cls_TopOpeBRepDS_HDataStructure.def("ClearStoreInterferences", (void (TopOpeBRepDS_HDataStructure::*)(const TopOpeBRepDS_ListOfInterference &, const Standard_Integer, const TCollection_AsciiString &)) &TopOpeBRepDS_HDataStructure::ClearStoreInterferences, "None", py::arg("LI"), py::arg("IS"), py::arg("str"));
cls_TopOpeBRepDS_HDataStructure.def_static("get_type_name_", (const char * (*)()) &TopOpeBRepDS_HDataStructure::get_type_name, "None");
cls_TopOpeBRepDS_HDataStructure.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TopOpeBRepDS_HDataStructure::get_type_descriptor, "None");
cls_TopOpeBRepDS_HDataStructure.def("DynamicType", (const opencascade::handle<Standard_Type> & (TopOpeBRepDS_HDataStructure::*)() const) &TopOpeBRepDS_HDataStructure::DynamicType, "None");

// TYPEDEF: TOPOPEBREPDS_PDATASTRUCTURE

// CLASS: TOPOPEBREPDS
py::class_<TopOpeBRepDS> cls_TopOpeBRepDS(mod, "TopOpeBRepDS", "This package provides services used by the TopOpeBRepBuild package performing topological operations on the BRep data structure.");

// Constructors
cls_TopOpeBRepDS.def(py::init<>());

// Methods
// cls_TopOpeBRepDS.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepDS::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepDS.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepDS::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepDS.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepDS::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepDS.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepDS::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepDS.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepDS::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepDS.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepDS::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepDS.def_static("SPrint_", (TCollection_AsciiString (*)(const TopAbs_State)) &TopOpeBRepDS::SPrint, "IN OU ON UN", py::arg("S"));
cls_TopOpeBRepDS.def_static("Print_", (Standard_OStream & (*)(const TopAbs_State, Standard_OStream &)) &TopOpeBRepDS::Print, "None", py::arg("S"), py::arg("OS"));
cls_TopOpeBRepDS.def_static("SPrint_", (TCollection_AsciiString (*)(const TopOpeBRepDS_Kind)) &TopOpeBRepDS::SPrint, "<K>", py::arg("K"));
cls_TopOpeBRepDS.def_static("SPrint_", [](const TopOpeBRepDS_Kind a0, const Standard_Integer a1) -> TCollection_AsciiString { return TopOpeBRepDS::SPrint(a0, a1); });
cls_TopOpeBRepDS.def_static("SPrint_", [](const TopOpeBRepDS_Kind a0, const Standard_Integer a1, const TCollection_AsciiString & a2) -> TCollection_AsciiString { return TopOpeBRepDS::SPrint(a0, a1, a2); });
cls_TopOpeBRepDS.def_static("SPrint_", (TCollection_AsciiString (*)(const TopOpeBRepDS_Kind, const Standard_Integer, const TCollection_AsciiString &, const TCollection_AsciiString &)) &TopOpeBRepDS::SPrint, "S1(<K>,<I>)S2", py::arg("K"), py::arg("I"), py::arg("B"), py::arg("A"));
cls_TopOpeBRepDS.def_static("Print_", (Standard_OStream & (*)(const TopOpeBRepDS_Kind, Standard_OStream &)) &TopOpeBRepDS::Print, "None", py::arg("K"), py::arg("S"));
cls_TopOpeBRepDS.def_static("Print_", [](const TopOpeBRepDS_Kind a0, const Standard_Integer a1, Standard_OStream & a2) -> Standard_OStream & { return TopOpeBRepDS::Print(a0, a1, a2); });
cls_TopOpeBRepDS.def_static("Print_", [](const TopOpeBRepDS_Kind a0, const Standard_Integer a1, Standard_OStream & a2, const TCollection_AsciiString & a3) -> Standard_OStream & { return TopOpeBRepDS::Print(a0, a1, a2, a3); });
cls_TopOpeBRepDS.def_static("Print_", (Standard_OStream & (*)(const TopOpeBRepDS_Kind, const Standard_Integer, Standard_OStream &, const TCollection_AsciiString &, const TCollection_AsciiString &)) &TopOpeBRepDS::Print, "None", py::arg("K"), py::arg("I"), py::arg("S"), py::arg("B"), py::arg("A"));
cls_TopOpeBRepDS.def_static("SPrint_", (TCollection_AsciiString (*)(const TopAbs_ShapeEnum)) &TopOpeBRepDS::SPrint, "None", py::arg("T"));
cls_TopOpeBRepDS.def_static("SPrint_", (TCollection_AsciiString (*)(const TopAbs_ShapeEnum, const Standard_Integer)) &TopOpeBRepDS::SPrint, "(<T>,<I>)", py::arg("T"), py::arg("I"));
cls_TopOpeBRepDS.def_static("Print_", (Standard_OStream & (*)(const TopAbs_ShapeEnum, const Standard_Integer, Standard_OStream &)) &TopOpeBRepDS::Print, "None", py::arg("T"), py::arg("I"), py::arg("S"));
cls_TopOpeBRepDS.def_static("SPrint_", (TCollection_AsciiString (*)(const TopAbs_Orientation)) &TopOpeBRepDS::SPrint, "None", py::arg("O"));
cls_TopOpeBRepDS.def_static("SPrint_", (TCollection_AsciiString (*)(const TopOpeBRepDS_Config)) &TopOpeBRepDS::SPrint, "None", py::arg("C"));
cls_TopOpeBRepDS.def_static("Print_", (Standard_OStream & (*)(const TopOpeBRepDS_Config, Standard_OStream &)) &TopOpeBRepDS::Print, "None", py::arg("C"), py::arg("S"));
cls_TopOpeBRepDS.def_static("IsGeometry_", (Standard_Boolean (*)(const TopOpeBRepDS_Kind)) &TopOpeBRepDS::IsGeometry, "None", py::arg("K"));
cls_TopOpeBRepDS.def_static("IsTopology_", (Standard_Boolean (*)(const TopOpeBRepDS_Kind)) &TopOpeBRepDS::IsTopology, "None", py::arg("K"));
cls_TopOpeBRepDS.def_static("KindToShape_", (TopAbs_ShapeEnum (*)(const TopOpeBRepDS_Kind)) &TopOpeBRepDS::KindToShape, "None", py::arg("K"));
cls_TopOpeBRepDS.def_static("ShapeToKind_", (TopOpeBRepDS_Kind (*)(const TopAbs_ShapeEnum)) &TopOpeBRepDS::ShapeToKind, "None", py::arg("S"));

// TYPEDEF: TOPOPEBREPDS_DATAMAPOFINTEGERLISTOFINTERFERENCE
bind_NCollection_DataMap<int, NCollection_List<opencascade::handle<TopOpeBRepDS_Interference> >, NCollection_DefaultHasher<int> >(mod, "TopOpeBRepDS_DataMapOfIntegerListOfInterference", py::module_local(false));

// TYPEDEF: TOPOPEBREPDS_DATAMAPITERATOROFDATAMAPOFINTEGERLISTOFINTERFERENCE
py::class_<NCollection_DataMap<int, NCollection_List<opencascade::handle<TopOpeBRepDS_Interference> >, NCollection_DefaultHasher<int> >::Iterator, NCollection_BaseMap::Iterator> cls_NCollection_DataMap_TopOpeBRepDS_DataMapIteratorOfDataMapOfIntegerListOfInterference(mod, "TopOpeBRepDS_DataMapIteratorOfDataMapOfIntegerListOfInterference", "None");

// Constructors
cls_NCollection_DataMap_TopOpeBRepDS_DataMapIteratorOfDataMapOfIntegerListOfInterference.def(py::init<>());
cls_NCollection_DataMap_TopOpeBRepDS_DataMapIteratorOfDataMapOfIntegerListOfInterference.def(py::init<const NCollection_DataMap<int, NCollection_List<opencascade::handle<TopOpeBRepDS_Interference> >, NCollection_DefaultHasher<int> > &>(), py::arg("theMap"));

// Methods
cls_NCollection_DataMap_TopOpeBRepDS_DataMapIteratorOfDataMapOfIntegerListOfInterference.def("More", (Standard_Boolean (NCollection_DataMap<int, NCollection_List<opencascade::handle<TopOpeBRepDS_Interference> >, NCollection_DefaultHasher<int> >::Iterator::*)() const) &NCollection_DataMap<int, NCollection_List<opencascade::handle<TopOpeBRepDS_Interference> >, NCollection_DefaultHasher<int> >::Iterator::More, "Query if the end of collection is reached by iterator");
cls_NCollection_DataMap_TopOpeBRepDS_DataMapIteratorOfDataMapOfIntegerListOfInterference.def("Next", (void (NCollection_DataMap<int, NCollection_List<opencascade::handle<TopOpeBRepDS_Interference> >, NCollection_DefaultHasher<int> >::Iterator::*)()) &NCollection_DataMap<int, NCollection_List<opencascade::handle<TopOpeBRepDS_Interference> >, NCollection_DefaultHasher<int> >::Iterator::Next, "Make a step along the collection");
cls_NCollection_DataMap_TopOpeBRepDS_DataMapIteratorOfDataMapOfIntegerListOfInterference.def("Value", (const NCollection_List<opencascade::handle<TopOpeBRepDS_Interference> > & (NCollection_DataMap<int, NCollection_List<opencascade::handle<TopOpeBRepDS_Interference> >, NCollection_DefaultHasher<int> >::Iterator::*)() const) &NCollection_DataMap<int, NCollection_List<opencascade::handle<TopOpeBRepDS_Interference> >, NCollection_DefaultHasher<int> >::Iterator::Value, "Value inquiry");
cls_NCollection_DataMap_TopOpeBRepDS_DataMapIteratorOfDataMapOfIntegerListOfInterference.def("ChangeValue", (NCollection_List<opencascade::handle<TopOpeBRepDS_Interference> > & (NCollection_DataMap<int, NCollection_List<opencascade::handle<TopOpeBRepDS_Interference> >, NCollection_DefaultHasher<int> >::Iterator::*)() const) &NCollection_DataMap<int, NCollection_List<opencascade::handle<TopOpeBRepDS_Interference> >, NCollection_DefaultHasher<int> >::Iterator::ChangeValue, "Value change access");
cls_NCollection_DataMap_TopOpeBRepDS_DataMapIteratorOfDataMapOfIntegerListOfInterference.def("Key", (const int & (NCollection_DataMap<int, NCollection_List<opencascade::handle<TopOpeBRepDS_Interference> >, NCollection_DefaultHasher<int> >::Iterator::*)() const) &NCollection_DataMap<int, NCollection_List<opencascade::handle<TopOpeBRepDS_Interference> >, NCollection_DefaultHasher<int> >::Iterator::Key, "Key");

// TYPEDEF: TOPOPEBREPDS_ARRAY1OFDATAMAPOFINTEGERLISTOFINTERFERENCE
bind_NCollection_Array1<NCollection_DataMap<int, NCollection_List<opencascade::handle<TopOpeBRepDS_Interference> >, NCollection_DefaultHasher<int> > >(mod, "TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference", py::module_local(false));

// TYPEDEF: TOPOPEBREPDS_DATAMAPOFINTERFERENCELISTOFINTERFERENCE
bind_NCollection_DataMap<opencascade::handle<TopOpeBRepDS_Interference>, NCollection_List<opencascade::handle<TopOpeBRepDS_Interference> >, NCollection_DefaultHasher<opencascade::handle<Standard_Transient> > >(mod, "TopOpeBRepDS_DataMapOfInterferenceListOfInterference", py::module_local(false));

// TYPEDEF: TOPOPEBREPDS_DATAMAPITERATOROFDATAMAPOFINTERFERENCELISTOFINTERFERENCE

// CLASS: TOPOPEBREPDS_ASSOCIATION
py::class_<TopOpeBRepDS_Association, opencascade::handle<TopOpeBRepDS_Association>, Standard_Transient> cls_TopOpeBRepDS_Association(mod, "TopOpeBRepDS_Association", "None");

// Constructors
cls_TopOpeBRepDS_Association.def(py::init<>());

// Methods
cls_TopOpeBRepDS_Association.def("Associate", (void (TopOpeBRepDS_Association::*)(const opencascade::handle<TopOpeBRepDS_Interference> &, const opencascade::handle<TopOpeBRepDS_Interference> &)) &TopOpeBRepDS_Association::Associate, "None", py::arg("I"), py::arg("K"));
cls_TopOpeBRepDS_Association.def("Associate", (void (TopOpeBRepDS_Association::*)(const opencascade::handle<TopOpeBRepDS_Interference> &, const TopOpeBRepDS_ListOfInterference &)) &TopOpeBRepDS_Association::Associate, "None", py::arg("I"), py::arg("LI"));
cls_TopOpeBRepDS_Association.def("HasAssociation", (Standard_Boolean (TopOpeBRepDS_Association::*)(const opencascade::handle<TopOpeBRepDS_Interference> &) const) &TopOpeBRepDS_Association::HasAssociation, "None", py::arg("I"));
cls_TopOpeBRepDS_Association.def("Associated", (TopOpeBRepDS_ListOfInterference & (TopOpeBRepDS_Association::*)(const opencascade::handle<TopOpeBRepDS_Interference> &)) &TopOpeBRepDS_Association::Associated, "None", py::arg("I"));
cls_TopOpeBRepDS_Association.def("AreAssociated", (Standard_Boolean (TopOpeBRepDS_Association::*)(const opencascade::handle<TopOpeBRepDS_Interference> &, const opencascade::handle<TopOpeBRepDS_Interference> &) const) &TopOpeBRepDS_Association::AreAssociated, "None", py::arg("I"), py::arg("K"));
cls_TopOpeBRepDS_Association.def_static("get_type_name_", (const char * (*)()) &TopOpeBRepDS_Association::get_type_name, "None");
cls_TopOpeBRepDS_Association.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TopOpeBRepDS_Association::get_type_descriptor, "None");
cls_TopOpeBRepDS_Association.def("DynamicType", (const opencascade::handle<Standard_Type> & (TopOpeBRepDS_Association::*)() const) &TopOpeBRepDS_Association::DynamicType, "None");

// TYPEDEF: TOPOPEBREPDS_DATAMAPOFCHECKSTATUS
bind_NCollection_DataMap<int, TopOpeBRepDS_CheckStatus, NCollection_DefaultHasher<int> >(mod, "TopOpeBRepDS_DataMapOfCheckStatus", py::module_local(false));

// TYPEDEF: TOPOPEBREPDS_DATAMAPITERATOROFDATAMAPOFCHECKSTATUS

// CLASS: TOPOPEBREPDS_CHECK
py::class_<TopOpeBRepDS_Check, opencascade::handle<TopOpeBRepDS_Check>, Standard_Transient> cls_TopOpeBRepDS_Check(mod, "TopOpeBRepDS_Check", "a tool verifing integrity and structure of DS");

// Constructors
cls_TopOpeBRepDS_Check.def(py::init<>());
cls_TopOpeBRepDS_Check.def(py::init<const opencascade::handle<TopOpeBRepDS_HDataStructure> &>(), py::arg("HDS"));

// Methods
cls_TopOpeBRepDS_Check.def("ChkIntg", (Standard_Boolean (TopOpeBRepDS_Check::*)()) &TopOpeBRepDS_Check::ChkIntg, "Check integrition of DS");
cls_TopOpeBRepDS_Check.def("ChkIntgInterf", (Standard_Boolean (TopOpeBRepDS_Check::*)(const TopOpeBRepDS_ListOfInterference &)) &TopOpeBRepDS_Check::ChkIntgInterf, "Check integrition of interferences (les supports et les geometries de LI)", py::arg("LI"));
cls_TopOpeBRepDS_Check.def("CheckDS", (Standard_Boolean (TopOpeBRepDS_Check::*)(const Standard_Integer, const TopOpeBRepDS_Kind)) &TopOpeBRepDS_Check::CheckDS, "Verifie que le ieme element de la DS existe, et pour un K de type topologique, verifie qu'il est du bon type (VERTEX, EDGE, WIRE, FACE, SHELL ou SOLID)", py::arg("i"), py::arg("K"));
cls_TopOpeBRepDS_Check.def("ChkIntgSamDom", (Standard_Boolean (TopOpeBRepDS_Check::*)()) &TopOpeBRepDS_Check::ChkIntgSamDom, "Check integrition des champs SameDomain de la DS");
cls_TopOpeBRepDS_Check.def("CheckShapes", (Standard_Boolean (TopOpeBRepDS_Check::*)(const TopTools_ListOfShape &) const) &TopOpeBRepDS_Check::CheckShapes, "Verifie que les Shapes existent bien dans la DS Utile pour les Shapes SameDomain si la liste est vide, renvoie vrai", py::arg("LS"));
cls_TopOpeBRepDS_Check.def("OneVertexOnPnt", (Standard_Boolean (TopOpeBRepDS_Check::*)()) &TopOpeBRepDS_Check::OneVertexOnPnt, "Verifie que les Vertex non SameDomain sont bien nonSameDomain, que les vertex sameDomain sont bien SameDomain, que les Points sont non confondus ni entre eux, ni avec des Vertex.");
cls_TopOpeBRepDS_Check.def("HDS", (const opencascade::handle<TopOpeBRepDS_HDataStructure> & (TopOpeBRepDS_Check::*)() const) &TopOpeBRepDS_Check::HDS, "None");
cls_TopOpeBRepDS_Check.def("ChangeHDS", (opencascade::handle<TopOpeBRepDS_HDataStructure> & (TopOpeBRepDS_Check::*)()) &TopOpeBRepDS_Check::ChangeHDS, "None");
cls_TopOpeBRepDS_Check.def("PrintIntg", (Standard_OStream & (TopOpeBRepDS_Check::*)(Standard_OStream &)) &TopOpeBRepDS_Check::PrintIntg, "None", py::arg("S"));
cls_TopOpeBRepDS_Check.def("Print", (Standard_OStream & (TopOpeBRepDS_Check::*)(const TopOpeBRepDS_CheckStatus, Standard_OStream &)) &TopOpeBRepDS_Check::Print, "Prints the name of CheckStatus <stat> as a String", py::arg("stat"), py::arg("S"));
cls_TopOpeBRepDS_Check.def("PrintShape", (Standard_OStream & (TopOpeBRepDS_Check::*)(const TopAbs_ShapeEnum, Standard_OStream &)) &TopOpeBRepDS_Check::PrintShape, "Prints the name of CheckStatus <stat> as a String", py::arg("SE"), py::arg("S"));
cls_TopOpeBRepDS_Check.def("PrintShape", (Standard_OStream & (TopOpeBRepDS_Check::*)(const Standard_Integer, Standard_OStream &)) &TopOpeBRepDS_Check::PrintShape, "Prints the name of CheckStatus <stat> as a String", py::arg("index"), py::arg("S"));
cls_TopOpeBRepDS_Check.def_static("get_type_name_", (const char * (*)()) &TopOpeBRepDS_Check::get_type_name, "None");
cls_TopOpeBRepDS_Check.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TopOpeBRepDS_Check::get_type_descriptor, "None");
cls_TopOpeBRepDS_Check.def("DynamicType", (const opencascade::handle<Standard_Type> & (TopOpeBRepDS_Check::*)() const) &TopOpeBRepDS_Check::DynamicType, "None");

// CLASS: TOPOPEBREPDS_CURVEEXPLORER
py::class_<TopOpeBRepDS_CurveExplorer> cls_TopOpeBRepDS_CurveExplorer(mod, "TopOpeBRepDS_CurveExplorer", "None");

// Constructors
cls_TopOpeBRepDS_CurveExplorer.def(py::init<>());
cls_TopOpeBRepDS_CurveExplorer.def(py::init<const TopOpeBRepDS_DataStructure &>(), py::arg("DS"));
cls_TopOpeBRepDS_CurveExplorer.def(py::init<const TopOpeBRepDS_DataStructure &, const Standard_Boolean>(), py::arg("DS"), py::arg("FindOnlyKeep"));

// Methods
// cls_TopOpeBRepDS_CurveExplorer.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepDS_CurveExplorer::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepDS_CurveExplorer.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepDS_CurveExplorer::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_CurveExplorer.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepDS_CurveExplorer::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepDS_CurveExplorer.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepDS_CurveExplorer::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_CurveExplorer.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepDS_CurveExplorer::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepDS_CurveExplorer.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepDS_CurveExplorer::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepDS_CurveExplorer.def("Init", [](TopOpeBRepDS_CurveExplorer &self, const TopOpeBRepDS_DataStructure & a0) -> void { return self.Init(a0); });
cls_TopOpeBRepDS_CurveExplorer.def("Init", (void (TopOpeBRepDS_CurveExplorer::*)(const TopOpeBRepDS_DataStructure &, const Standard_Boolean)) &TopOpeBRepDS_CurveExplorer::Init, "None", py::arg("DS"), py::arg("FindOnlyKeep"));
cls_TopOpeBRepDS_CurveExplorer.def("More", (Standard_Boolean (TopOpeBRepDS_CurveExplorer::*)() const) &TopOpeBRepDS_CurveExplorer::More, "None");
cls_TopOpeBRepDS_CurveExplorer.def("Next", (void (TopOpeBRepDS_CurveExplorer::*)()) &TopOpeBRepDS_CurveExplorer::Next, "None");
cls_TopOpeBRepDS_CurveExplorer.def("Curve", (const TopOpeBRepDS_Curve & (TopOpeBRepDS_CurveExplorer::*)() const) &TopOpeBRepDS_CurveExplorer::Curve, "None");
cls_TopOpeBRepDS_CurveExplorer.def("IsCurve", (Standard_Boolean (TopOpeBRepDS_CurveExplorer::*)(const Standard_Integer) const) &TopOpeBRepDS_CurveExplorer::IsCurve, "None", py::arg("I"));
cls_TopOpeBRepDS_CurveExplorer.def("IsCurveKeep", (Standard_Boolean (TopOpeBRepDS_CurveExplorer::*)(const Standard_Integer) const) &TopOpeBRepDS_CurveExplorer::IsCurveKeep, "None", py::arg("I"));
cls_TopOpeBRepDS_CurveExplorer.def("Curve", (const TopOpeBRepDS_Curve & (TopOpeBRepDS_CurveExplorer::*)(const Standard_Integer) const) &TopOpeBRepDS_CurveExplorer::Curve, "None", py::arg("I"));
cls_TopOpeBRepDS_CurveExplorer.def("NbCurve", (Standard_Integer (TopOpeBRepDS_CurveExplorer::*)()) &TopOpeBRepDS_CurveExplorer::NbCurve, "None");
cls_TopOpeBRepDS_CurveExplorer.def("Index", (Standard_Integer (TopOpeBRepDS_CurveExplorer::*)() const) &TopOpeBRepDS_CurveExplorer::Index, "None");

// CLASS: TOPOPEBREPDS_CURVEITERATOR
py::class_<TopOpeBRepDS_CurveIterator, TopOpeBRepDS_InterferenceIterator> cls_TopOpeBRepDS_CurveIterator(mod, "TopOpeBRepDS_CurveIterator", "None");

// Constructors
cls_TopOpeBRepDS_CurveIterator.def(py::init<const TopOpeBRepDS_ListOfInterference &>(), py::arg("L"));

// Methods
// cls_TopOpeBRepDS_CurveIterator.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepDS_CurveIterator::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepDS_CurveIterator.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepDS_CurveIterator::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_CurveIterator.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepDS_CurveIterator::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepDS_CurveIterator.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepDS_CurveIterator::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_CurveIterator.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepDS_CurveIterator::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepDS_CurveIterator.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepDS_CurveIterator::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepDS_CurveIterator.def("MatchInterference", (Standard_Boolean (TopOpeBRepDS_CurveIterator::*)(const opencascade::handle<TopOpeBRepDS_Interference> &) const) &TopOpeBRepDS_CurveIterator::MatchInterference, "Returns True if the Interference <I> has a GeometryType() TopOpeBRepDS_CURVE returns False else.", py::arg("I"));
cls_TopOpeBRepDS_CurveIterator.def("Current", (Standard_Integer (TopOpeBRepDS_CurveIterator::*)() const) &TopOpeBRepDS_CurveIterator::Current, "Index of the curve in the data structure.");
cls_TopOpeBRepDS_CurveIterator.def("Orientation", (TopAbs_Orientation (TopOpeBRepDS_CurveIterator::*)(const TopAbs_State) const) &TopOpeBRepDS_CurveIterator::Orientation, "None", py::arg("S"));
cls_TopOpeBRepDS_CurveIterator.def("PCurve", (const opencascade::handle<Geom2d_Curve> & (TopOpeBRepDS_CurveIterator::*)() const) &TopOpeBRepDS_CurveIterator::PCurve, "None");

// TYPEDEF: TOPOPEBREPDS_DATAMAPOFINTERFERENCESHAPE
bind_NCollection_DataMap<opencascade::handle<TopOpeBRepDS_Interference>, TopoDS_Shape, NCollection_DefaultHasher<opencascade::handle<Standard_Transient> > >(mod, "TopOpeBRepDS_DataMapOfInterferenceShape", py::module_local(false));

// TYPEDEF: TOPOPEBREPDS_DATAMAPITERATOROFDATAMAPOFINTERFERENCESHAPE

// TYPEDEF: TOPOPEBREPDS_MAPOFINTEGERSHAPEDATA
bind_NCollection_DataMap<int, TopOpeBRepDS_ShapeData, NCollection_DefaultHasher<int> >(mod, "TopOpeBRepDS_MapOfIntegerShapeData", py::module_local(false));

// TYPEDEF: TOPOPEBREPDS_DATAMAPITERATOROFMAPOFINTEGERSHAPEDATA

// TYPEDEF: TOPOPEBREPDS_DOUBLEMAPOFINTEGERSHAPE
bind_NCollection_DoubleMap<int, TopoDS_Shape, NCollection_DefaultHasher<int>, TopTools_ShapeMapHasher>(mod, "TopOpeBRepDS_DoubleMapOfIntegerShape", py::module_local(false));

// TYPEDEF: TOPOPEBREPDS_DOUBLEMAPITERATOROFDOUBLEMAPOFINTEGERSHAPE

// CLASS: TOPOPEBREPDS_DUMPER
py::class_<TopOpeBRepDS_Dumper> cls_TopOpeBRepDS_Dumper(mod, "TopOpeBRepDS_Dumper", "None");

// Constructors
cls_TopOpeBRepDS_Dumper.def(py::init<const opencascade::handle<TopOpeBRepDS_HDataStructure> &>(), py::arg("HDS"));

// Methods
// cls_TopOpeBRepDS_Dumper.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepDS_Dumper::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepDS_Dumper.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepDS_Dumper::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_Dumper.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepDS_Dumper::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepDS_Dumper.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepDS_Dumper::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_Dumper.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepDS_Dumper::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepDS_Dumper.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepDS_Dumper::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepDS_Dumper.def("SDumpRefOri", (TCollection_AsciiString (TopOpeBRepDS_Dumper::*)(const TopOpeBRepDS_Kind, const Standard_Integer) const) &TopOpeBRepDS_Dumper::SDumpRefOri, "None", py::arg("K"), py::arg("I"));
cls_TopOpeBRepDS_Dumper.def("SDumpRefOri", (TCollection_AsciiString (TopOpeBRepDS_Dumper::*)(const TopoDS_Shape &) const) &TopOpeBRepDS_Dumper::SDumpRefOri, "None", py::arg("S"));
cls_TopOpeBRepDS_Dumper.def("SPrintShape", (TCollection_AsciiString (TopOpeBRepDS_Dumper::*)(const Standard_Integer) const) &TopOpeBRepDS_Dumper::SPrintShape, "None", py::arg("I"));
cls_TopOpeBRepDS_Dumper.def("SPrintShape", (TCollection_AsciiString (TopOpeBRepDS_Dumper::*)(const TopoDS_Shape &) const) &TopOpeBRepDS_Dumper::SPrintShape, "None", py::arg("S"));
cls_TopOpeBRepDS_Dumper.def("SPrintShapeRefOri", [](TopOpeBRepDS_Dumper &self, const TopoDS_Shape & a0) -> TCollection_AsciiString { return self.SPrintShapeRefOri(a0); });
cls_TopOpeBRepDS_Dumper.def("SPrintShapeRefOri", (TCollection_AsciiString (TopOpeBRepDS_Dumper::*)(const TopoDS_Shape &, const TCollection_AsciiString &) const) &TopOpeBRepDS_Dumper::SPrintShapeRefOri, "None", py::arg("S"), py::arg("B"));
cls_TopOpeBRepDS_Dumper.def("SPrintShapeRefOri", [](TopOpeBRepDS_Dumper &self, const TopTools_ListOfShape & a0) -> TCollection_AsciiString { return self.SPrintShapeRefOri(a0); });
cls_TopOpeBRepDS_Dumper.def("SPrintShapeRefOri", (TCollection_AsciiString (TopOpeBRepDS_Dumper::*)(const TopTools_ListOfShape &, const TCollection_AsciiString &) const) &TopOpeBRepDS_Dumper::SPrintShapeRefOri, "None", py::arg("L"), py::arg("B"));

// CLASS: TOPOPEBREPDS_EDGE3DINTERFERENCETOOL
py::class_<TopOpeBRepDS_Edge3dInterferenceTool> cls_TopOpeBRepDS_Edge3dInterferenceTool(mod, "TopOpeBRepDS_Edge3dInterferenceTool", "a tool computing edge / face complex transition, Interferences of edge reference are given by I = (T on face, G = point or vertex, S = edge)");

// Constructors
cls_TopOpeBRepDS_Edge3dInterferenceTool.def(py::init<>());

// Methods
// cls_TopOpeBRepDS_Edge3dInterferenceTool.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepDS_Edge3dInterferenceTool::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepDS_Edge3dInterferenceTool.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepDS_Edge3dInterferenceTool::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_Edge3dInterferenceTool.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepDS_Edge3dInterferenceTool::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepDS_Edge3dInterferenceTool.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepDS_Edge3dInterferenceTool::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_Edge3dInterferenceTool.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepDS_Edge3dInterferenceTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepDS_Edge3dInterferenceTool.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepDS_Edge3dInterferenceTool::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepDS_Edge3dInterferenceTool.def("InitPointVertex", (void (TopOpeBRepDS_Edge3dInterferenceTool::*)(const Standard_Integer, const TopoDS_Shape &)) &TopOpeBRepDS_Edge3dInterferenceTool::InitPointVertex, "None", py::arg("IsVertex"), py::arg("VonOO"));
cls_TopOpeBRepDS_Edge3dInterferenceTool.def("Init", (void (TopOpeBRepDS_Edge3dInterferenceTool::*)(const TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Shape &, const opencascade::handle<TopOpeBRepDS_Interference> &)) &TopOpeBRepDS_Edge3dInterferenceTool::Init, "None", py::arg("Eref"), py::arg("E"), py::arg("F"), py::arg("I"));
cls_TopOpeBRepDS_Edge3dInterferenceTool.def("Add", (void (TopOpeBRepDS_Edge3dInterferenceTool::*)(const TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Shape &, const opencascade::handle<TopOpeBRepDS_Interference> &)) &TopOpeBRepDS_Edge3dInterferenceTool::Add, "None", py::arg("Eref"), py::arg("E"), py::arg("F"), py::arg("I"));
cls_TopOpeBRepDS_Edge3dInterferenceTool.def("Transition", (void (TopOpeBRepDS_Edge3dInterferenceTool::*)(const opencascade::handle<TopOpeBRepDS_Interference> &) const) &TopOpeBRepDS_Edge3dInterferenceTool::Transition, "None", py::arg("I"));

// CLASS: TOPOPEBREPDS_EDGEINTERFERENCETOOL
py::class_<TopOpeBRepDS_EdgeInterferenceTool> cls_TopOpeBRepDS_EdgeInterferenceTool(mod, "TopOpeBRepDS_EdgeInterferenceTool", "a tool computing complex transition on Edge.");

// Constructors
cls_TopOpeBRepDS_EdgeInterferenceTool.def(py::init<>());

// Methods
// cls_TopOpeBRepDS_EdgeInterferenceTool.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepDS_EdgeInterferenceTool::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepDS_EdgeInterferenceTool.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepDS_EdgeInterferenceTool::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_EdgeInterferenceTool.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepDS_EdgeInterferenceTool::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepDS_EdgeInterferenceTool.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepDS_EdgeInterferenceTool::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_EdgeInterferenceTool.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepDS_EdgeInterferenceTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepDS_EdgeInterferenceTool.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepDS_EdgeInterferenceTool::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepDS_EdgeInterferenceTool.def("Init", (void (TopOpeBRepDS_EdgeInterferenceTool::*)(const TopoDS_Shape &, const opencascade::handle<TopOpeBRepDS_Interference> &)) &TopOpeBRepDS_EdgeInterferenceTool::Init, "None", py::arg("E"), py::arg("I"));
cls_TopOpeBRepDS_EdgeInterferenceTool.def("Add", (void (TopOpeBRepDS_EdgeInterferenceTool::*)(const TopoDS_Shape &, const TopoDS_Shape &, const opencascade::handle<TopOpeBRepDS_Interference> &)) &TopOpeBRepDS_EdgeInterferenceTool::Add, "None", py::arg("E"), py::arg("V"), py::arg("I"));
cls_TopOpeBRepDS_EdgeInterferenceTool.def("Add", (void (TopOpeBRepDS_EdgeInterferenceTool::*)(const TopoDS_Shape &, const TopOpeBRepDS_Point &, const opencascade::handle<TopOpeBRepDS_Interference> &)) &TopOpeBRepDS_EdgeInterferenceTool::Add, "None", py::arg("E"), py::arg("P"), py::arg("I"));
cls_TopOpeBRepDS_EdgeInterferenceTool.def("Transition", (void (TopOpeBRepDS_EdgeInterferenceTool::*)(const opencascade::handle<TopOpeBRepDS_Interference> &) const) &TopOpeBRepDS_EdgeInterferenceTool::Transition, "None", py::arg("I"));

// CLASS: TOPOPEBREPDS_EIR
py::class_<TopOpeBRepDS_EIR> cls_TopOpeBRepDS_EIR(mod, "TopOpeBRepDS_EIR", "EdgeInterferenceReducer");

// Constructors
cls_TopOpeBRepDS_EIR.def(py::init<const opencascade::handle<TopOpeBRepDS_HDataStructure> &>(), py::arg("HDS"));

// Methods
// cls_TopOpeBRepDS_EIR.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepDS_EIR::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepDS_EIR.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepDS_EIR::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_EIR.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepDS_EIR::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepDS_EIR.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepDS_EIR::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_EIR.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepDS_EIR::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepDS_EIR.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepDS_EIR::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepDS_EIR.def("ProcessEdgeInterferences", (void (TopOpeBRepDS_EIR::*)()) &TopOpeBRepDS_EIR::ProcessEdgeInterferences, "None");
cls_TopOpeBRepDS_EIR.def("ProcessEdgeInterferences", (void (TopOpeBRepDS_EIR::*)(const Standard_Integer)) &TopOpeBRepDS_EIR::ProcessEdgeInterferences, "None", py::arg("I"));

// CLASS: TOPOPEBREPDS_EXPLORER
py::class_<TopOpeBRepDS_Explorer> cls_TopOpeBRepDS_Explorer(mod, "TopOpeBRepDS_Explorer", "None");

// Constructors
cls_TopOpeBRepDS_Explorer.def(py::init<>());
cls_TopOpeBRepDS_Explorer.def(py::init<const opencascade::handle<TopOpeBRepDS_HDataStructure> &>(), py::arg("HDS"));
cls_TopOpeBRepDS_Explorer.def(py::init<const opencascade::handle<TopOpeBRepDS_HDataStructure> &, const TopAbs_ShapeEnum>(), py::arg("HDS"), py::arg("T"));
cls_TopOpeBRepDS_Explorer.def(py::init<const opencascade::handle<TopOpeBRepDS_HDataStructure> &, const TopAbs_ShapeEnum, const Standard_Boolean>(), py::arg("HDS"), py::arg("T"), py::arg("findkeep"));

// Methods
// cls_TopOpeBRepDS_Explorer.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepDS_Explorer::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepDS_Explorer.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepDS_Explorer::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_Explorer.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepDS_Explorer::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepDS_Explorer.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepDS_Explorer::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_Explorer.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepDS_Explorer::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepDS_Explorer.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepDS_Explorer::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepDS_Explorer.def("Init", [](TopOpeBRepDS_Explorer &self, const opencascade::handle<TopOpeBRepDS_HDataStructure> & a0) -> void { return self.Init(a0); });
cls_TopOpeBRepDS_Explorer.def("Init", [](TopOpeBRepDS_Explorer &self, const opencascade::handle<TopOpeBRepDS_HDataStructure> & a0, const TopAbs_ShapeEnum a1) -> void { return self.Init(a0, a1); });
cls_TopOpeBRepDS_Explorer.def("Init", (void (TopOpeBRepDS_Explorer::*)(const opencascade::handle<TopOpeBRepDS_HDataStructure> &, const TopAbs_ShapeEnum, const Standard_Boolean)) &TopOpeBRepDS_Explorer::Init, "None", py::arg("HDS"), py::arg("T"), py::arg("findkeep"));
cls_TopOpeBRepDS_Explorer.def("Type", (TopAbs_ShapeEnum (TopOpeBRepDS_Explorer::*)() const) &TopOpeBRepDS_Explorer::Type, "None");
cls_TopOpeBRepDS_Explorer.def("More", (Standard_Boolean (TopOpeBRepDS_Explorer::*)() const) &TopOpeBRepDS_Explorer::More, "None");
cls_TopOpeBRepDS_Explorer.def("Next", (void (TopOpeBRepDS_Explorer::*)()) &TopOpeBRepDS_Explorer::Next, "None");
cls_TopOpeBRepDS_Explorer.def("Current", (const TopoDS_Shape & (TopOpeBRepDS_Explorer::*)() const) &TopOpeBRepDS_Explorer::Current, "None");
cls_TopOpeBRepDS_Explorer.def("Index", (Standard_Integer (TopOpeBRepDS_Explorer::*)() const) &TopOpeBRepDS_Explorer::Index, "None");
cls_TopOpeBRepDS_Explorer.def("Face", (const TopoDS_Face & (TopOpeBRepDS_Explorer::*)() const) &TopOpeBRepDS_Explorer::Face, "None");
cls_TopOpeBRepDS_Explorer.def("Edge", (const TopoDS_Edge & (TopOpeBRepDS_Explorer::*)() const) &TopOpeBRepDS_Explorer::Edge, "None");
cls_TopOpeBRepDS_Explorer.def("Vertex", (const TopoDS_Vertex & (TopOpeBRepDS_Explorer::*)() const) &TopOpeBRepDS_Explorer::Vertex, "None");

// CLASS: TOPOPEBREPDS_FACEINTERFERENCETOOL
py::class_<TopOpeBRepDS_FaceInterferenceTool> cls_TopOpeBRepDS_FaceInterferenceTool(mod, "TopOpeBRepDS_FaceInterferenceTool", "a tool computing complex transition on Face.");

// Constructors
cls_TopOpeBRepDS_FaceInterferenceTool.def(py::init<const TopOpeBRepDS_PDataStructure &>(), py::arg("P"));

// Methods
// cls_TopOpeBRepDS_FaceInterferenceTool.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepDS_FaceInterferenceTool::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepDS_FaceInterferenceTool.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepDS_FaceInterferenceTool::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_FaceInterferenceTool.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepDS_FaceInterferenceTool::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepDS_FaceInterferenceTool.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepDS_FaceInterferenceTool::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_FaceInterferenceTool.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepDS_FaceInterferenceTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepDS_FaceInterferenceTool.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepDS_FaceInterferenceTool::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepDS_FaceInterferenceTool.def("Init", (void (TopOpeBRepDS_FaceInterferenceTool::*)(const TopoDS_Shape &, const TopoDS_Shape &, const Standard_Boolean, const opencascade::handle<TopOpeBRepDS_Interference> &)) &TopOpeBRepDS_FaceInterferenceTool::Init, "Eisnew = true if E is a new edge built on edge I->Geometry() false if E is shape <=> I->Geometry()", py::arg("FI"), py::arg("E"), py::arg("Eisnew"), py::arg("I"));
cls_TopOpeBRepDS_FaceInterferenceTool.def("Add", (void (TopOpeBRepDS_FaceInterferenceTool::*)(const TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Shape &, const Standard_Boolean, const opencascade::handle<TopOpeBRepDS_Interference> &)) &TopOpeBRepDS_FaceInterferenceTool::Add, "Eisnew = true if E is a new edge built on edge I->Geometry() false if E is shape <=> I->Geometry()", py::arg("FI"), py::arg("F"), py::arg("E"), py::arg("Eisnew"), py::arg("I"));
cls_TopOpeBRepDS_FaceInterferenceTool.def("Add", (void (TopOpeBRepDS_FaceInterferenceTool::*)(const TopoDS_Shape &, const TopOpeBRepDS_Curve &, const opencascade::handle<TopOpeBRepDS_Interference> &)) &TopOpeBRepDS_FaceInterferenceTool::Add, "None", py::arg("E"), py::arg("C"), py::arg("I"));
cls_TopOpeBRepDS_FaceInterferenceTool.def("SetEdgePntPar", (void (TopOpeBRepDS_FaceInterferenceTool::*)(const gp_Pnt &, const Standard_Real)) &TopOpeBRepDS_FaceInterferenceTool::SetEdgePntPar, "None", py::arg("P"), py::arg("par"));
cls_TopOpeBRepDS_FaceInterferenceTool.def("GetEdgePntPar", [](TopOpeBRepDS_FaceInterferenceTool &self, gp_Pnt & P, Standard_Real & par){ self.GetEdgePntPar(P, par); return par; }, "None", py::arg("P"), py::arg("par"));
cls_TopOpeBRepDS_FaceInterferenceTool.def("IsEdgePntParDef", (Standard_Boolean (TopOpeBRepDS_FaceInterferenceTool::*)() const) &TopOpeBRepDS_FaceInterferenceTool::IsEdgePntParDef, "None");
cls_TopOpeBRepDS_FaceInterferenceTool.def("Transition", (void (TopOpeBRepDS_FaceInterferenceTool::*)(const opencascade::handle<TopOpeBRepDS_Interference> &) const) &TopOpeBRepDS_FaceInterferenceTool::Transition, "None", py::arg("I"));

// CLASS: TOPOPEBREPDS_FILTER
py::class_<TopOpeBRepDS_Filter> cls_TopOpeBRepDS_Filter(mod, "TopOpeBRepDS_Filter", "None");

// Constructors
cls_TopOpeBRepDS_Filter.def(py::init<const opencascade::handle<TopOpeBRepDS_HDataStructure> &>(), py::arg("HDS"));
cls_TopOpeBRepDS_Filter.def(py::init<const opencascade::handle<TopOpeBRepDS_HDataStructure> &, const TopOpeBRepTool_PShapeClassifier &>(), py::arg("HDS"), py::arg("pClassif"));

// Methods
// cls_TopOpeBRepDS_Filter.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepDS_Filter::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepDS_Filter.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepDS_Filter::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_Filter.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepDS_Filter::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepDS_Filter.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepDS_Filter::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_Filter.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepDS_Filter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepDS_Filter.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepDS_Filter::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepDS_Filter.def("ProcessInterferences", (void (TopOpeBRepDS_Filter::*)()) &TopOpeBRepDS_Filter::ProcessInterferences, "None");
cls_TopOpeBRepDS_Filter.def("ProcessFaceInterferences", (void (TopOpeBRepDS_Filter::*)(const TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State &)) &TopOpeBRepDS_Filter::ProcessFaceInterferences, "None", py::arg("MEsp"));
cls_TopOpeBRepDS_Filter.def("ProcessFaceInterferences", (void (TopOpeBRepDS_Filter::*)(const Standard_Integer, const TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State &)) &TopOpeBRepDS_Filter::ProcessFaceInterferences, "None", py::arg("I"), py::arg("MEsp"));
cls_TopOpeBRepDS_Filter.def("ProcessEdgeInterferences", (void (TopOpeBRepDS_Filter::*)()) &TopOpeBRepDS_Filter::ProcessEdgeInterferences, "None");
cls_TopOpeBRepDS_Filter.def("ProcessEdgeInterferences", (void (TopOpeBRepDS_Filter::*)(const Standard_Integer)) &TopOpeBRepDS_Filter::ProcessEdgeInterferences, "None", py::arg("I"));
cls_TopOpeBRepDS_Filter.def("ProcessCurveInterferences", (void (TopOpeBRepDS_Filter::*)()) &TopOpeBRepDS_Filter::ProcessCurveInterferences, "None");
cls_TopOpeBRepDS_Filter.def("ProcessCurveInterferences", (void (TopOpeBRepDS_Filter::*)(const Standard_Integer)) &TopOpeBRepDS_Filter::ProcessCurveInterferences, "None", py::arg("I"));

// CLASS: TOPOPEBREPDS_FIR
py::class_<TopOpeBRepDS_FIR> cls_TopOpeBRepDS_FIR(mod, "TopOpeBRepDS_FIR", "FaceInterferenceReducer");

// Constructors
cls_TopOpeBRepDS_FIR.def(py::init<const opencascade::handle<TopOpeBRepDS_HDataStructure> &>(), py::arg("HDS"));

// Methods
// cls_TopOpeBRepDS_FIR.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepDS_FIR::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepDS_FIR.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepDS_FIR::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_FIR.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepDS_FIR::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepDS_FIR.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepDS_FIR::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_FIR.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepDS_FIR::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepDS_FIR.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepDS_FIR::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepDS_FIR.def("ProcessFaceInterferences", (void (TopOpeBRepDS_FIR::*)(const TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State &)) &TopOpeBRepDS_FIR::ProcessFaceInterferences, "None", py::arg("M"));
cls_TopOpeBRepDS_FIR.def("ProcessFaceInterferences", (void (TopOpeBRepDS_FIR::*)(const Standard_Integer, const TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State &)) &TopOpeBRepDS_FIR::ProcessFaceInterferences, "None", py::arg("I"), py::arg("M"));

// CLASS: TOPOPEBREPDS_GAPFILLER
py::class_<TopOpeBRepDS_GapFiller> cls_TopOpeBRepDS_GapFiller(mod, "TopOpeBRepDS_GapFiller", "None");

// Constructors
cls_TopOpeBRepDS_GapFiller.def(py::init<const opencascade::handle<TopOpeBRepDS_HDataStructure> &>(), py::arg("HDS"));

// Methods
// cls_TopOpeBRepDS_GapFiller.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepDS_GapFiller::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepDS_GapFiller.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepDS_GapFiller::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_GapFiller.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepDS_GapFiller::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepDS_GapFiller.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepDS_GapFiller::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_GapFiller.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepDS_GapFiller::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepDS_GapFiller.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepDS_GapFiller::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepDS_GapFiller.def("Perform", (void (TopOpeBRepDS_GapFiller::*)()) &TopOpeBRepDS_GapFiller::Perform, "None");
cls_TopOpeBRepDS_GapFiller.def("FindAssociatedPoints", (void (TopOpeBRepDS_GapFiller::*)(const opencascade::handle<TopOpeBRepDS_Interference> &, TopOpeBRepDS_ListOfInterference &)) &TopOpeBRepDS_GapFiller::FindAssociatedPoints, "Recherche parmi l'ensemble des points d'Interference la Liste <LI> des points qui correspondent au point d'indice <Index>", py::arg("I"), py::arg("LI"));
cls_TopOpeBRepDS_GapFiller.def("CheckConnexity", (Standard_Boolean (TopOpeBRepDS_GapFiller::*)(TopOpeBRepDS_ListOfInterference &)) &TopOpeBRepDS_GapFiller::CheckConnexity, "Enchaine les sections via les points d'Interferences deja associe; Renvoit dans <L> les points extremites des Lignes. Methodes pour construire la liste des Points qui peuvent correspondre a une Point donne.", py::arg("LI"));
cls_TopOpeBRepDS_GapFiller.def("AddPointsOnShape", (void (TopOpeBRepDS_GapFiller::*)(const TopoDS_Shape &, TopOpeBRepDS_ListOfInterference &)) &TopOpeBRepDS_GapFiller::AddPointsOnShape, "None", py::arg("S"), py::arg("LI"));
cls_TopOpeBRepDS_GapFiller.def("AddPointsOnConnexShape", (void (TopOpeBRepDS_GapFiller::*)(const TopoDS_Shape &, const TopOpeBRepDS_ListOfInterference &)) &TopOpeBRepDS_GapFiller::AddPointsOnConnexShape, "Methodes pour reduire la liste des Points qui peuvent correspondre a une Point donne.", py::arg("F"), py::arg("LI"));
cls_TopOpeBRepDS_GapFiller.def("FilterByFace", (void (TopOpeBRepDS_GapFiller::*)(const TopoDS_Face &, TopOpeBRepDS_ListOfInterference &)) &TopOpeBRepDS_GapFiller::FilterByFace, "None", py::arg("F"), py::arg("LI"));
cls_TopOpeBRepDS_GapFiller.def("FilterByEdge", (void (TopOpeBRepDS_GapFiller::*)(const TopoDS_Edge &, TopOpeBRepDS_ListOfInterference &)) &TopOpeBRepDS_GapFiller::FilterByEdge, "None", py::arg("E"), py::arg("LI"));
cls_TopOpeBRepDS_GapFiller.def("FilterByIncidentDistance", (void (TopOpeBRepDS_GapFiller::*)(const TopoDS_Face &, const opencascade::handle<TopOpeBRepDS_Interference> &, TopOpeBRepDS_ListOfInterference &)) &TopOpeBRepDS_GapFiller::FilterByIncidentDistance, "None", py::arg("F"), py::arg("I"), py::arg("LI"));
cls_TopOpeBRepDS_GapFiller.def("IsOnFace", (Standard_Boolean (TopOpeBRepDS_GapFiller::*)(const opencascade::handle<TopOpeBRepDS_Interference> &, const TopoDS_Face &) const) &TopOpeBRepDS_GapFiller::IsOnFace, "Return TRUE si I a ete obtenu par une intersection avec <F>.", py::arg("I"), py::arg("F"));
cls_TopOpeBRepDS_GapFiller.def("IsOnEdge", (Standard_Boolean (TopOpeBRepDS_GapFiller::*)(const opencascade::handle<TopOpeBRepDS_Interference> &, const TopoDS_Edge &) const) &TopOpeBRepDS_GapFiller::IsOnEdge, "Return TRUE si I ou une de ses representaions a pour support <E>. Methodes de reconstructions des geometries des point et des courbes de section", py::arg("I"), py::arg("E"));
cls_TopOpeBRepDS_GapFiller.def("BuildNewGeometries", (void (TopOpeBRepDS_GapFiller::*)()) &TopOpeBRepDS_GapFiller::BuildNewGeometries, "None");
cls_TopOpeBRepDS_GapFiller.def("ReBuildGeom", (void (TopOpeBRepDS_GapFiller::*)(const opencascade::handle<TopOpeBRepDS_Interference> &, TColStd_MapOfInteger &)) &TopOpeBRepDS_GapFiller::ReBuildGeom, "None", py::arg("I1"), py::arg("Done"));

// CLASS: TOPOPEBREPDS_GAPTOOL
py::class_<TopOpeBRepDS_GapTool, opencascade::handle<TopOpeBRepDS_GapTool>, Standard_Transient> cls_TopOpeBRepDS_GapTool(mod, "TopOpeBRepDS_GapTool", "None");

// Constructors
cls_TopOpeBRepDS_GapTool.def(py::init<>());
cls_TopOpeBRepDS_GapTool.def(py::init<const opencascade::handle<TopOpeBRepDS_HDataStructure> &>(), py::arg("HDS"));

// Methods
cls_TopOpeBRepDS_GapTool.def("Init", (void (TopOpeBRepDS_GapTool::*)(const opencascade::handle<TopOpeBRepDS_HDataStructure> &)) &TopOpeBRepDS_GapTool::Init, "None", py::arg("HDS"));
cls_TopOpeBRepDS_GapTool.def("Interferences", (const TopOpeBRepDS_ListOfInterference & (TopOpeBRepDS_GapTool::*)(const Standard_Integer) const) &TopOpeBRepDS_GapTool::Interferences, "None", py::arg("IndexPoint"));
cls_TopOpeBRepDS_GapTool.def("SameInterferences", (const TopOpeBRepDS_ListOfInterference & (TopOpeBRepDS_GapTool::*)(const opencascade::handle<TopOpeBRepDS_Interference> &) const) &TopOpeBRepDS_GapTool::SameInterferences, "None", py::arg("I"));
cls_TopOpeBRepDS_GapTool.def("ChangeSameInterferences", (TopOpeBRepDS_ListOfInterference & (TopOpeBRepDS_GapTool::*)(const opencascade::handle<TopOpeBRepDS_Interference> &)) &TopOpeBRepDS_GapTool::ChangeSameInterferences, "None", py::arg("I"));
cls_TopOpeBRepDS_GapTool.def("Curve", (Standard_Boolean (TopOpeBRepDS_GapTool::*)(const opencascade::handle<TopOpeBRepDS_Interference> &, TopOpeBRepDS_Curve &) const) &TopOpeBRepDS_GapTool::Curve, "None", py::arg("I"), py::arg("C"));
cls_TopOpeBRepDS_GapTool.def("EdgeSupport", (Standard_Boolean (TopOpeBRepDS_GapTool::*)(const opencascade::handle<TopOpeBRepDS_Interference> &, TopoDS_Shape &) const) &TopOpeBRepDS_GapTool::EdgeSupport, "None", py::arg("I"), py::arg("E"));
cls_TopOpeBRepDS_GapTool.def("FacesSupport", (Standard_Boolean (TopOpeBRepDS_GapTool::*)(const opencascade::handle<TopOpeBRepDS_Interference> &, TopoDS_Shape &, TopoDS_Shape &) const) &TopOpeBRepDS_GapTool::FacesSupport, "Return les faces qui ont genere la section origine de I", py::arg("I"), py::arg("F1"), py::arg("F2"));
cls_TopOpeBRepDS_GapTool.def("ParameterOnEdge", [](TopOpeBRepDS_GapTool &self, const opencascade::handle<TopOpeBRepDS_Interference> & I, const TopoDS_Shape & E, Standard_Real & U){ Standard_Boolean rv = self.ParameterOnEdge(I, E, U); return std::tuple<Standard_Boolean, Standard_Real &>(rv, U); }, "None", py::arg("I"), py::arg("E"), py::arg("U"));
cls_TopOpeBRepDS_GapTool.def("SetPoint", (void (TopOpeBRepDS_GapTool::*)(const opencascade::handle<TopOpeBRepDS_Interference> &, const Standard_Integer)) &TopOpeBRepDS_GapTool::SetPoint, "None", py::arg("I"), py::arg("IndexPoint"));
cls_TopOpeBRepDS_GapTool.def("SetParameterOnEdge", (void (TopOpeBRepDS_GapTool::*)(const opencascade::handle<TopOpeBRepDS_Interference> &, const TopoDS_Shape &, const Standard_Real)) &TopOpeBRepDS_GapTool::SetParameterOnEdge, "None", py::arg("I"), py::arg("E"), py::arg("U"));
cls_TopOpeBRepDS_GapTool.def_static("get_type_name_", (const char * (*)()) &TopOpeBRepDS_GapTool::get_type_name, "None");
cls_TopOpeBRepDS_GapTool.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TopOpeBRepDS_GapTool::get_type_descriptor, "None");
cls_TopOpeBRepDS_GapTool.def("DynamicType", (const opencascade::handle<Standard_Type> & (TopOpeBRepDS_GapTool::*)() const) &TopOpeBRepDS_GapTool::DynamicType, "None");

// CLASS: TOPOPEBREPDS_HARRAY1OFDATAMAPOFINTEGERLISTOFINTERFERENCE
py::class_<TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference, opencascade::handle<TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference>, Standard_Transient> cls_TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference(mod, "TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference", "None", py::multiple_inheritance());

// Constructors
cls_TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference.def(py::init<>());
cls_TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference.def(py::init<const Standard_Integer, const Standard_Integer, const TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference.def(py::init<const TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference &>(), py::arg("theOther"));

// Methods
// cls_TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference::operator delete, "None", py::arg(""), py::arg(""));
// cls_TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference.def("Array1", (const TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference & (TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference::*)() const) &TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference::Array1, "None");
cls_TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference.def("ChangeArray1", (TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference & (TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference::*)()) &TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference::ChangeArray1, "None");
cls_TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference.def_static("get_type_name_", (const char * (*)()) &TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference::get_type_name, "None");
cls_TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference::get_type_descriptor, "None");
cls_TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference.def("DynamicType", (const opencascade::handle<Standard_Type> & (TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference::*)() const) &TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference::DynamicType, "None");

// TYPEDEF: TOPOPEBREPDS_INDEXEDDATAMAPOFVERTEXPOINT
bind_NCollection_IndexedDataMap<TopoDS_Shape, TopOpeBRepDS_Point, TopTools_ShapeMapHasher>(mod, "TopOpeBRepDS_IndexedDataMapOfVertexPoint", py::module_local(false));

// CLASS: TOPOPEBREPDS_INTERFERENCETOOL
py::class_<TopOpeBRepDS_InterferenceTool> cls_TopOpeBRepDS_InterferenceTool(mod, "TopOpeBRepDS_InterferenceTool", "None");

// Constructors
cls_TopOpeBRepDS_InterferenceTool.def(py::init<>());

// Methods
// cls_TopOpeBRepDS_InterferenceTool.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepDS_InterferenceTool::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepDS_InterferenceTool.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepDS_InterferenceTool::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_InterferenceTool.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepDS_InterferenceTool::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepDS_InterferenceTool.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepDS_InterferenceTool::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_InterferenceTool.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepDS_InterferenceTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepDS_InterferenceTool.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepDS_InterferenceTool::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepDS_InterferenceTool.def_static("MakeEdgeInterference_", (opencascade::handle<TopOpeBRepDS_Interference> (*)(const TopOpeBRepDS_Transition &, const TopOpeBRepDS_Kind, const Standard_Integer, const TopOpeBRepDS_Kind, const Standard_Integer, const Standard_Real)) &TopOpeBRepDS_InterferenceTool::MakeEdgeInterference, "None", py::arg("T"), py::arg("SK"), py::arg("SI"), py::arg("GK"), py::arg("GI"), py::arg("P"));
cls_TopOpeBRepDS_InterferenceTool.def_static("MakeCurveInterference_", (opencascade::handle<TopOpeBRepDS_Interference> (*)(const TopOpeBRepDS_Transition &, const TopOpeBRepDS_Kind, const Standard_Integer, const TopOpeBRepDS_Kind, const Standard_Integer, const Standard_Real)) &TopOpeBRepDS_InterferenceTool::MakeCurveInterference, "None", py::arg("T"), py::arg("SK"), py::arg("SI"), py::arg("GK"), py::arg("GI"), py::arg("P"));
cls_TopOpeBRepDS_InterferenceTool.def_static("DuplicateCurvePointInterference_", (opencascade::handle<TopOpeBRepDS_Interference> (*)(const opencascade::handle<TopOpeBRepDS_Interference> &)) &TopOpeBRepDS_InterferenceTool::DuplicateCurvePointInterference, "duplicate I in a new interference with Complement() transition.", py::arg("I"));
cls_TopOpeBRepDS_InterferenceTool.def_static("MakeFaceCurveInterference_", (opencascade::handle<TopOpeBRepDS_Interference> (*)(const TopOpeBRepDS_Transition &, const Standard_Integer, const Standard_Integer, const opencascade::handle<Geom2d_Curve> &)) &TopOpeBRepDS_InterferenceTool::MakeFaceCurveInterference, "None", py::arg("Transition"), py::arg("FaceI"), py::arg("CurveI"), py::arg("PC"));
cls_TopOpeBRepDS_InterferenceTool.def_static("MakeSolidSurfaceInterference_", (opencascade::handle<TopOpeBRepDS_Interference> (*)(const TopOpeBRepDS_Transition &, const Standard_Integer, const Standard_Integer)) &TopOpeBRepDS_InterferenceTool::MakeSolidSurfaceInterference, "None", py::arg("Transition"), py::arg("SolidI"), py::arg("SurfaceI"));
cls_TopOpeBRepDS_InterferenceTool.def_static("MakeEdgeVertexInterference_", (opencascade::handle<TopOpeBRepDS_Interference> (*)(const TopOpeBRepDS_Transition &, const Standard_Integer, const Standard_Integer, const Standard_Boolean, const TopOpeBRepDS_Config, const Standard_Real)) &TopOpeBRepDS_InterferenceTool::MakeEdgeVertexInterference, "None", py::arg("Transition"), py::arg("EdgeI"), py::arg("VertexI"), py::arg("VertexIsBound"), py::arg("Config"), py::arg("param"));
cls_TopOpeBRepDS_InterferenceTool.def_static("MakeFaceEdgeInterference_", (opencascade::handle<TopOpeBRepDS_Interference> (*)(const TopOpeBRepDS_Transition &, const Standard_Integer, const Standard_Integer, const Standard_Boolean, const TopOpeBRepDS_Config)) &TopOpeBRepDS_InterferenceTool::MakeFaceEdgeInterference, "None", py::arg("Transition"), py::arg("FaceI"), py::arg("EdgeI"), py::arg("EdgeIsBound"), py::arg("Config"));
cls_TopOpeBRepDS_InterferenceTool.def_static("Parameter_", (Standard_Real (*)(const opencascade::handle<TopOpeBRepDS_Interference> &)) &TopOpeBRepDS_InterferenceTool::Parameter, "None", py::arg("CPI"));
cls_TopOpeBRepDS_InterferenceTool.def_static("Parameter_", (void (*)(const opencascade::handle<TopOpeBRepDS_Interference> &, const Standard_Real)) &TopOpeBRepDS_InterferenceTool::Parameter, "None", py::arg("CPI"), py::arg("Par"));

// CLASS: TOPOPEBREPDS_MARKER
py::class_<TopOpeBRepDS_Marker, opencascade::handle<TopOpeBRepDS_Marker>, Standard_Transient> cls_TopOpeBRepDS_Marker(mod, "TopOpeBRepDS_Marker", "None");

// Constructors
cls_TopOpeBRepDS_Marker.def(py::init<>());

// Methods
cls_TopOpeBRepDS_Marker.def("Reset", (void (TopOpeBRepDS_Marker::*)()) &TopOpeBRepDS_Marker::Reset, "None");
cls_TopOpeBRepDS_Marker.def("Set", (void (TopOpeBRepDS_Marker::*)(const Standard_Integer, const Standard_Boolean)) &TopOpeBRepDS_Marker::Set, "None", py::arg("i"), py::arg("b"));
cls_TopOpeBRepDS_Marker.def("Set", (void (TopOpeBRepDS_Marker::*)(const Standard_Boolean, const Standard_Integer, const Standard_Address)) &TopOpeBRepDS_Marker::Set, "None", py::arg("b"), py::arg("n"), py::arg("a"));
cls_TopOpeBRepDS_Marker.def("GetI", (Standard_Boolean (TopOpeBRepDS_Marker::*)(const Standard_Integer) const) &TopOpeBRepDS_Marker::GetI, "None", py::arg("i"));
cls_TopOpeBRepDS_Marker.def("Allocate", (void (TopOpeBRepDS_Marker::*)(const Standard_Integer)) &TopOpeBRepDS_Marker::Allocate, "None", py::arg("n"));
cls_TopOpeBRepDS_Marker.def_static("get_type_name_", (const char * (*)()) &TopOpeBRepDS_Marker::get_type_name, "None");
cls_TopOpeBRepDS_Marker.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TopOpeBRepDS_Marker::get_type_descriptor, "None");
cls_TopOpeBRepDS_Marker.def("DynamicType", (const opencascade::handle<Standard_Type> & (TopOpeBRepDS_Marker::*)() const) &TopOpeBRepDS_Marker::DynamicType, "None");

// CLASS: TOPOPEBREPDS_POINTEXPLORER
py::class_<TopOpeBRepDS_PointExplorer> cls_TopOpeBRepDS_PointExplorer(mod, "TopOpeBRepDS_PointExplorer", "None");

// Constructors
cls_TopOpeBRepDS_PointExplorer.def(py::init<>());
cls_TopOpeBRepDS_PointExplorer.def(py::init<const TopOpeBRepDS_DataStructure &>(), py::arg("DS"));
cls_TopOpeBRepDS_PointExplorer.def(py::init<const TopOpeBRepDS_DataStructure &, const Standard_Boolean>(), py::arg("DS"), py::arg("FindOnlyKeep"));

// Methods
// cls_TopOpeBRepDS_PointExplorer.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepDS_PointExplorer::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepDS_PointExplorer.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepDS_PointExplorer::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_PointExplorer.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepDS_PointExplorer::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepDS_PointExplorer.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepDS_PointExplorer::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_PointExplorer.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepDS_PointExplorer::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepDS_PointExplorer.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepDS_PointExplorer::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepDS_PointExplorer.def("Init", [](TopOpeBRepDS_PointExplorer &self, const TopOpeBRepDS_DataStructure & a0) -> void { return self.Init(a0); });
cls_TopOpeBRepDS_PointExplorer.def("Init", (void (TopOpeBRepDS_PointExplorer::*)(const TopOpeBRepDS_DataStructure &, const Standard_Boolean)) &TopOpeBRepDS_PointExplorer::Init, "None", py::arg("DS"), py::arg("FindOnlyKeep"));
cls_TopOpeBRepDS_PointExplorer.def("More", (Standard_Boolean (TopOpeBRepDS_PointExplorer::*)() const) &TopOpeBRepDS_PointExplorer::More, "None");
cls_TopOpeBRepDS_PointExplorer.def("Next", (void (TopOpeBRepDS_PointExplorer::*)()) &TopOpeBRepDS_PointExplorer::Next, "None");
cls_TopOpeBRepDS_PointExplorer.def("Point", (const TopOpeBRepDS_Point & (TopOpeBRepDS_PointExplorer::*)() const) &TopOpeBRepDS_PointExplorer::Point, "None");
cls_TopOpeBRepDS_PointExplorer.def("IsPoint", (Standard_Boolean (TopOpeBRepDS_PointExplorer::*)(const Standard_Integer) const) &TopOpeBRepDS_PointExplorer::IsPoint, "None", py::arg("I"));
cls_TopOpeBRepDS_PointExplorer.def("IsPointKeep", (Standard_Boolean (TopOpeBRepDS_PointExplorer::*)(const Standard_Integer) const) &TopOpeBRepDS_PointExplorer::IsPointKeep, "None", py::arg("I"));
cls_TopOpeBRepDS_PointExplorer.def("Point", (const TopOpeBRepDS_Point & (TopOpeBRepDS_PointExplorer::*)(const Standard_Integer) const) &TopOpeBRepDS_PointExplorer::Point, "None", py::arg("I"));
cls_TopOpeBRepDS_PointExplorer.def("NbPoint", (Standard_Integer (TopOpeBRepDS_PointExplorer::*)()) &TopOpeBRepDS_PointExplorer::NbPoint, "None");
cls_TopOpeBRepDS_PointExplorer.def("Index", (Standard_Integer (TopOpeBRepDS_PointExplorer::*)() const) &TopOpeBRepDS_PointExplorer::Index, "None");

// CLASS: TOPOPEBREPDS_POINTITERATOR
py::class_<TopOpeBRepDS_PointIterator, TopOpeBRepDS_InterferenceIterator> cls_TopOpeBRepDS_PointIterator(mod, "TopOpeBRepDS_PointIterator", "None");

// Constructors
cls_TopOpeBRepDS_PointIterator.def(py::init<const TopOpeBRepDS_ListOfInterference &>(), py::arg("L"));

// Methods
// cls_TopOpeBRepDS_PointIterator.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepDS_PointIterator::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepDS_PointIterator.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepDS_PointIterator::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_PointIterator.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepDS_PointIterator::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepDS_PointIterator.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepDS_PointIterator::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_PointIterator.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepDS_PointIterator::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepDS_PointIterator.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepDS_PointIterator::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepDS_PointIterator.def("MatchInterference", (Standard_Boolean (TopOpeBRepDS_PointIterator::*)(const opencascade::handle<TopOpeBRepDS_Interference> &) const) &TopOpeBRepDS_PointIterator::MatchInterference, "Returns True if the Interference <I> has a GeometryType() TopOpeBRepDS_POINT or TopOpeBRepDS_VERTEX returns False else.", py::arg("I"));
cls_TopOpeBRepDS_PointIterator.def("Current", (Standard_Integer (TopOpeBRepDS_PointIterator::*)() const) &TopOpeBRepDS_PointIterator::Current, "Index of the point in the data structure.");
cls_TopOpeBRepDS_PointIterator.def("Orientation", (TopAbs_Orientation (TopOpeBRepDS_PointIterator::*)(const TopAbs_State) const) &TopOpeBRepDS_PointIterator::Orientation, "None", py::arg("S"));
cls_TopOpeBRepDS_PointIterator.def("Parameter", (Standard_Real (TopOpeBRepDS_PointIterator::*)() const) &TopOpeBRepDS_PointIterator::Parameter, "None");
cls_TopOpeBRepDS_PointIterator.def("IsVertex", (Standard_Boolean (TopOpeBRepDS_PointIterator::*)() const) &TopOpeBRepDS_PointIterator::IsVertex, "None");
cls_TopOpeBRepDS_PointIterator.def("IsPoint", (Standard_Boolean (TopOpeBRepDS_PointIterator::*)() const) &TopOpeBRepDS_PointIterator::IsPoint, "None");
cls_TopOpeBRepDS_PointIterator.def("DiffOriented", (Standard_Boolean (TopOpeBRepDS_PointIterator::*)() const) &TopOpeBRepDS_PointIterator::DiffOriented, "None");
cls_TopOpeBRepDS_PointIterator.def("SameOriented", (Standard_Boolean (TopOpeBRepDS_PointIterator::*)() const) &TopOpeBRepDS_PointIterator::SameOriented, "None");
cls_TopOpeBRepDS_PointIterator.def("Support", (Standard_Integer (TopOpeBRepDS_PointIterator::*)() const) &TopOpeBRepDS_PointIterator::Support, "None");

// CLASS: TOPOPEBREPDS_REDUCER
py::class_<TopOpeBRepDS_Reducer> cls_TopOpeBRepDS_Reducer(mod, "TopOpeBRepDS_Reducer", "reduce interferences of a data structure (HDS) used in topological operations.");

// Constructors
cls_TopOpeBRepDS_Reducer.def(py::init<const opencascade::handle<TopOpeBRepDS_HDataStructure> &>(), py::arg("HDS"));

// Methods
// cls_TopOpeBRepDS_Reducer.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepDS_Reducer::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepDS_Reducer.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepDS_Reducer::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_Reducer.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepDS_Reducer::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepDS_Reducer.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepDS_Reducer::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_Reducer.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepDS_Reducer::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepDS_Reducer.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepDS_Reducer::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepDS_Reducer.def("ProcessFaceInterferences", (void (TopOpeBRepDS_Reducer::*)(const TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State &)) &TopOpeBRepDS_Reducer::ProcessFaceInterferences, "None", py::arg("M"));
cls_TopOpeBRepDS_Reducer.def("ProcessEdgeInterferences", (void (TopOpeBRepDS_Reducer::*)()) &TopOpeBRepDS_Reducer::ProcessEdgeInterferences, "None");

// CLASS: TOPOPEBREPDS_SOLIDSURFACEINTERFERENCE
py::class_<TopOpeBRepDS_SolidSurfaceInterference, opencascade::handle<TopOpeBRepDS_SolidSurfaceInterference>, TopOpeBRepDS_Interference> cls_TopOpeBRepDS_SolidSurfaceInterference(mod, "TopOpeBRepDS_SolidSurfaceInterference", "Interference");

// Constructors
cls_TopOpeBRepDS_SolidSurfaceInterference.def(py::init<const TopOpeBRepDS_Transition &, const TopOpeBRepDS_Kind, const Standard_Integer, const TopOpeBRepDS_Kind, const Standard_Integer>(), py::arg("Transition"), py::arg("SupportType"), py::arg("Support"), py::arg("GeometryType"), py::arg("Geometry"));

// Methods
cls_TopOpeBRepDS_SolidSurfaceInterference.def_static("get_type_name_", (const char * (*)()) &TopOpeBRepDS_SolidSurfaceInterference::get_type_name, "None");
cls_TopOpeBRepDS_SolidSurfaceInterference.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TopOpeBRepDS_SolidSurfaceInterference::get_type_descriptor, "None");
cls_TopOpeBRepDS_SolidSurfaceInterference.def("DynamicType", (const opencascade::handle<Standard_Type> & (TopOpeBRepDS_SolidSurfaceInterference::*)() const) &TopOpeBRepDS_SolidSurfaceInterference::DynamicType, "None");

// CLASS: TOPOPEBREPDS_SURFACEEXPLORER
py::class_<TopOpeBRepDS_SurfaceExplorer> cls_TopOpeBRepDS_SurfaceExplorer(mod, "TopOpeBRepDS_SurfaceExplorer", "None");

// Constructors
cls_TopOpeBRepDS_SurfaceExplorer.def(py::init<>());
cls_TopOpeBRepDS_SurfaceExplorer.def(py::init<const TopOpeBRepDS_DataStructure &>(), py::arg("DS"));
cls_TopOpeBRepDS_SurfaceExplorer.def(py::init<const TopOpeBRepDS_DataStructure &, const Standard_Boolean>(), py::arg("DS"), py::arg("FindOnlyKeep"));

// Methods
// cls_TopOpeBRepDS_SurfaceExplorer.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepDS_SurfaceExplorer::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepDS_SurfaceExplorer.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepDS_SurfaceExplorer::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_SurfaceExplorer.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepDS_SurfaceExplorer::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepDS_SurfaceExplorer.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepDS_SurfaceExplorer::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_SurfaceExplorer.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepDS_SurfaceExplorer::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepDS_SurfaceExplorer.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepDS_SurfaceExplorer::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepDS_SurfaceExplorer.def("Init", [](TopOpeBRepDS_SurfaceExplorer &self, const TopOpeBRepDS_DataStructure & a0) -> void { return self.Init(a0); });
cls_TopOpeBRepDS_SurfaceExplorer.def("Init", (void (TopOpeBRepDS_SurfaceExplorer::*)(const TopOpeBRepDS_DataStructure &, const Standard_Boolean)) &TopOpeBRepDS_SurfaceExplorer::Init, "None", py::arg("DS"), py::arg("FindOnlyKeep"));
cls_TopOpeBRepDS_SurfaceExplorer.def("More", (Standard_Boolean (TopOpeBRepDS_SurfaceExplorer::*)() const) &TopOpeBRepDS_SurfaceExplorer::More, "None");
cls_TopOpeBRepDS_SurfaceExplorer.def("Next", (void (TopOpeBRepDS_SurfaceExplorer::*)()) &TopOpeBRepDS_SurfaceExplorer::Next, "None");
cls_TopOpeBRepDS_SurfaceExplorer.def("Surface", (const TopOpeBRepDS_Surface & (TopOpeBRepDS_SurfaceExplorer::*)() const) &TopOpeBRepDS_SurfaceExplorer::Surface, "None");
cls_TopOpeBRepDS_SurfaceExplorer.def("IsSurface", (Standard_Boolean (TopOpeBRepDS_SurfaceExplorer::*)(const Standard_Integer) const) &TopOpeBRepDS_SurfaceExplorer::IsSurface, "None", py::arg("I"));
cls_TopOpeBRepDS_SurfaceExplorer.def("IsSurfaceKeep", (Standard_Boolean (TopOpeBRepDS_SurfaceExplorer::*)(const Standard_Integer) const) &TopOpeBRepDS_SurfaceExplorer::IsSurfaceKeep, "None", py::arg("I"));
cls_TopOpeBRepDS_SurfaceExplorer.def("Surface", (const TopOpeBRepDS_Surface & (TopOpeBRepDS_SurfaceExplorer::*)(const Standard_Integer) const) &TopOpeBRepDS_SurfaceExplorer::Surface, "None", py::arg("I"));
cls_TopOpeBRepDS_SurfaceExplorer.def("NbSurface", (Standard_Integer (TopOpeBRepDS_SurfaceExplorer::*)()) &TopOpeBRepDS_SurfaceExplorer::NbSurface, "None");
cls_TopOpeBRepDS_SurfaceExplorer.def("Index", (Standard_Integer (TopOpeBRepDS_SurfaceExplorer::*)() const) &TopOpeBRepDS_SurfaceExplorer::Index, "None");

// CLASS: TOPOPEBREPDS_SURFACEITERATOR
py::class_<TopOpeBRepDS_SurfaceIterator, TopOpeBRepDS_InterferenceIterator> cls_TopOpeBRepDS_SurfaceIterator(mod, "TopOpeBRepDS_SurfaceIterator", "None");

// Constructors
cls_TopOpeBRepDS_SurfaceIterator.def(py::init<const TopOpeBRepDS_ListOfInterference &>(), py::arg("L"));

// Methods
// cls_TopOpeBRepDS_SurfaceIterator.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepDS_SurfaceIterator::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepDS_SurfaceIterator.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepDS_SurfaceIterator::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_SurfaceIterator.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepDS_SurfaceIterator::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepDS_SurfaceIterator.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepDS_SurfaceIterator::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_SurfaceIterator.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepDS_SurfaceIterator::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepDS_SurfaceIterator.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepDS_SurfaceIterator::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepDS_SurfaceIterator.def("Current", (Standard_Integer (TopOpeBRepDS_SurfaceIterator::*)() const) &TopOpeBRepDS_SurfaceIterator::Current, "Index of the surface in the data structure.");
cls_TopOpeBRepDS_SurfaceIterator.def("Orientation", (TopAbs_Orientation (TopOpeBRepDS_SurfaceIterator::*)(const TopAbs_State) const) &TopOpeBRepDS_SurfaceIterator::Orientation, "None", py::arg("S"));

// CLASS: TOPOPEBREPDS_TKI
py::class_<TopOpeBRepDS_TKI> cls_TopOpeBRepDS_TKI(mod, "TopOpeBRepDS_TKI", "None");

// Constructors
cls_TopOpeBRepDS_TKI.def(py::init<>());

// Methods
// cls_TopOpeBRepDS_TKI.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepDS_TKI::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepDS_TKI.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepDS_TKI::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_TKI.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepDS_TKI::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepDS_TKI.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepDS_TKI::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_TKI.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepDS_TKI::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepDS_TKI.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepDS_TKI::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepDS_TKI.def("Clear", (void (TopOpeBRepDS_TKI::*)()) &TopOpeBRepDS_TKI::Clear, "None");
cls_TopOpeBRepDS_TKI.def("FillOnGeometry", (void (TopOpeBRepDS_TKI::*)(const TopOpeBRepDS_ListOfInterference &)) &TopOpeBRepDS_TKI::FillOnGeometry, "None", py::arg("L"));
cls_TopOpeBRepDS_TKI.def("FillOnSupport", (void (TopOpeBRepDS_TKI::*)(const TopOpeBRepDS_ListOfInterference &)) &TopOpeBRepDS_TKI::FillOnSupport, "None", py::arg("L"));
cls_TopOpeBRepDS_TKI.def("IsBound", (Standard_Boolean (TopOpeBRepDS_TKI::*)(const TopOpeBRepDS_Kind, const Standard_Integer) const) &TopOpeBRepDS_TKI::IsBound, "None", py::arg("K"), py::arg("G"));
cls_TopOpeBRepDS_TKI.def("Interferences", (const TopOpeBRepDS_ListOfInterference & (TopOpeBRepDS_TKI::*)(const TopOpeBRepDS_Kind, const Standard_Integer) const) &TopOpeBRepDS_TKI::Interferences, "None", py::arg("K"), py::arg("G"));
cls_TopOpeBRepDS_TKI.def("ChangeInterferences", (TopOpeBRepDS_ListOfInterference & (TopOpeBRepDS_TKI::*)(const TopOpeBRepDS_Kind, const Standard_Integer)) &TopOpeBRepDS_TKI::ChangeInterferences, "None", py::arg("K"), py::arg("G"));
cls_TopOpeBRepDS_TKI.def("HasInterferences", (Standard_Boolean (TopOpeBRepDS_TKI::*)(const TopOpeBRepDS_Kind, const Standard_Integer) const) &TopOpeBRepDS_TKI::HasInterferences, "None", py::arg("K"), py::arg("G"));
cls_TopOpeBRepDS_TKI.def("Add", (void (TopOpeBRepDS_TKI::*)(const TopOpeBRepDS_Kind, const Standard_Integer)) &TopOpeBRepDS_TKI::Add, "None", py::arg("K"), py::arg("G"));
cls_TopOpeBRepDS_TKI.def("Add", (void (TopOpeBRepDS_TKI::*)(const TopOpeBRepDS_Kind, const Standard_Integer, const opencascade::handle<TopOpeBRepDS_Interference> &)) &TopOpeBRepDS_TKI::Add, "None", py::arg("K"), py::arg("G"), py::arg("HI"));
cls_TopOpeBRepDS_TKI.def("DumpTKIIterator", [](TopOpeBRepDS_TKI &self) -> void { return self.DumpTKIIterator(); });
cls_TopOpeBRepDS_TKI.def("DumpTKIIterator", [](TopOpeBRepDS_TKI &self, const TCollection_AsciiString & a0) -> void { return self.DumpTKIIterator(a0); });
cls_TopOpeBRepDS_TKI.def("DumpTKIIterator", (void (TopOpeBRepDS_TKI::*)(const TCollection_AsciiString &, const TCollection_AsciiString &)) &TopOpeBRepDS_TKI::DumpTKIIterator, "None", py::arg("s1"), py::arg("s2"));
cls_TopOpeBRepDS_TKI.def("Init", (void (TopOpeBRepDS_TKI::*)()) &TopOpeBRepDS_TKI::Init, "None");
cls_TopOpeBRepDS_TKI.def("More", (Standard_Boolean (TopOpeBRepDS_TKI::*)() const) &TopOpeBRepDS_TKI::More, "None");
cls_TopOpeBRepDS_TKI.def("Next", (void (TopOpeBRepDS_TKI::*)()) &TopOpeBRepDS_TKI::Next, "None");
cls_TopOpeBRepDS_TKI.def("Value", [](TopOpeBRepDS_TKI &self, TopOpeBRepDS_Kind & K, Standard_Integer & G){ const TopOpeBRepDS_ListOfInterference & rv = self.Value(K, G); return std::tuple<const TopOpeBRepDS_ListOfInterference &, Standard_Integer &>(rv, G); }, "None", py::arg("K"), py::arg("G"));
cls_TopOpeBRepDS_TKI.def("ChangeValue", [](TopOpeBRepDS_TKI &self, TopOpeBRepDS_Kind & K, Standard_Integer & G){ TopOpeBRepDS_ListOfInterference & rv = self.ChangeValue(K, G); return std::tuple<TopOpeBRepDS_ListOfInterference &, Standard_Integer &>(rv, G); }, "None", py::arg("K"), py::arg("G"));

// CLASS: TOPOPEBREPDS_TOOL
py::class_<TopOpeBRepDS_TOOL> cls_TopOpeBRepDS_TOOL(mod, "TopOpeBRepDS_TOOL", "None");

// Constructors
cls_TopOpeBRepDS_TOOL.def(py::init<>());

// Methods
// cls_TopOpeBRepDS_TOOL.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepDS_TOOL::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepDS_TOOL.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepDS_TOOL::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_TOOL.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepDS_TOOL::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepDS_TOOL.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepDS_TOOL::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_TOOL.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepDS_TOOL::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepDS_TOOL.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepDS_TOOL::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepDS_TOOL.def_static("EShareG_", (Standard_Integer (*)(const opencascade::handle<TopOpeBRepDS_HDataStructure> &, const TopoDS_Edge &, TopTools_ListOfShape &)) &TopOpeBRepDS_TOOL::EShareG, "None", py::arg("HDS"), py::arg("E"), py::arg("lEsd"));
cls_TopOpeBRepDS_TOOL.def_static("ShareG_", (Standard_Boolean (*)(const opencascade::handle<TopOpeBRepDS_HDataStructure> &, const Standard_Integer, const Standard_Integer)) &TopOpeBRepDS_TOOL::ShareG, "None", py::arg("HDS"), py::arg("is1"), py::arg("is2"));
cls_TopOpeBRepDS_TOOL.def_static("GetEsd_", [](const opencascade::handle<TopOpeBRepDS_HDataStructure> & HDS, const TopoDS_Shape & S, const Standard_Integer ie, Standard_Integer & iesd){ Standard_Boolean rv = TopOpeBRepDS_TOOL::GetEsd(HDS, S, ie, iesd); return std::tuple<Standard_Boolean, Standard_Integer &>(rv, iesd); }, "None", py::arg("HDS"), py::arg("S"), py::arg("ie"), py::arg("iesd"));
cls_TopOpeBRepDS_TOOL.def_static("ShareSplitON_", (Standard_Boolean (*)(const opencascade::handle<TopOpeBRepDS_HDataStructure> &, const TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State &, const Standard_Integer, const Standard_Integer, TopoDS_Shape &)) &TopOpeBRepDS_TOOL::ShareSplitON, "None", py::arg("HDS"), py::arg("MspON"), py::arg("i1"), py::arg("i2"), py::arg("spON"));
cls_TopOpeBRepDS_TOOL.def_static("GetConfig_", [](const opencascade::handle<TopOpeBRepDS_HDataStructure> & HDS, const TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State & MEspON, const Standard_Integer ie, const Standard_Integer iesd, Standard_Integer & conf){ Standard_Boolean rv = TopOpeBRepDS_TOOL::GetConfig(HDS, MEspON, ie, iesd, conf); return std::tuple<Standard_Boolean, Standard_Integer &>(rv, conf); }, "None", py::arg("HDS"), py::arg("MEspON"), py::arg("ie"), py::arg("iesd"), py::arg("conf"));


}
