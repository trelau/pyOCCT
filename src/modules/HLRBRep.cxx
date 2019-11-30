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
#include <HLRBRep_TypeOfResultingEdge.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <HLRTopoBRep_OutLiner.hxx>
#include <Standard_Transient.hxx>
#include <Standard_TypeDef.hxx>
#include <HLRAlgo_EdgesBlock.hxx>
#include <HLRBRep_ShapeBounds.hxx>
#include <NCollection_Sequence.hxx>
#include <HLRBRep_SeqOfShapeBounds.hxx>
#include <HLRBRep_InternalAlgo.hxx>
#include <HLRAlgo_Projector.hxx>
#include <HLRBRep_Data.hxx>
#include <Standard_Std.hxx>
#include <Standard_Type.hxx>
#include <BRepTopAdaptor_MapOfShapeTool.hxx>
#include <HLRBRep_Algo.hxx>
#include <TopoDS_Shape.hxx>
#include <TopoDS_Edge.hxx>
#include <HLRBRep_Curve.hxx>
#include <HLRBRep_CurveTool.hxx>
#include <HLRBRep_BCurveTool.hxx>
#include <HLRBRep_SurfaceTool.hxx>
#include <HLRBRep_BSurfaceTool.hxx>
#include <HLRBRep_Surface.hxx>
#include <HLRBRep_CLPropsATool.hxx>
#include <HLRBRep_CLProps.hxx>
#include <HLRBRep_SLPropsATool.hxx>
#include <HLRBRep_SLProps.hxx>
#include <HLRBRep_CInter.hxx>
#include <HLRBRep_LineTool.hxx>
#include <HLRBRep_InterCSurf.hxx>
#include <HLRBRep_EdgeFaceTool.hxx>
#include <HLRBRep_Intersector.hxx>
#include <HLRBRep_EdgeData.hxx>
#include <HLRBRep_FaceData.hxx>
#include <HLRBRep_FaceIterator.hxx>
#include <HLRBRep_ShapeToHLR.hxx>
#include <HLRBRep_HLRToShape.hxx>
#include <HLRBRep_EdgeInterferenceTool.hxx>
#include <HLRBRep_VertexList.hxx>
#include <HLRBRep_EdgeIList.hxx>
#include <HLRBRep_AreaLimit.hxx>
#include <HLRBRep_EdgeBuilder.hxx>
#include <HLRBRep_Hider.hxx>
#include <HLRBRep_PolyAlgo.hxx>
#include <HLRBRep_BiPoint.hxx>
#include <HLRBRep_BiPnt2D.hxx>
#include <HLRBRep_PolyHLRToShape.hxx>
#include <HLRBRep_TheCurveLocatorOfTheProjPCurOfCInter.hxx>
#include <HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter.hxx>
#include <HLRBRep_TheLocateExtPCOfTheProjPCurOfCInter.hxx>
#include <HLRBRep_TheProjPCurOfCInter.hxx>
#include <HLRBRep_MyImpParToolOfTheIntersectorOfTheIntConicCurveOfCInter.hxx>
#include <HLRBRep_TheIntersectorOfTheIntConicCurveOfCInter.hxx>
#include <HLRBRep_TheIntConicCurveOfCInter.hxx>
#include <HLRBRep_IntConicCurveOfCInter.hxx>
#include <HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter.hxx>
#include <HLRBRep_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfCInter.hxx>
#include <HLRBRep_ExactIntersectionPointOfTheIntPCurvePCurveOfCInter.hxx>
#include <HLRBRep_TheIntPCurvePCurveOfCInter.hxx>
#include <HLRBRep_ThePolygonOfInterCSurf.hxx>
#include <HLRBRep_ThePolygonToolOfInterCSurf.hxx>
#include <HLRBRep_ThePolyhedronOfInterCSurf.hxx>
#include <HLRBRep_ThePolyhedronToolOfInterCSurf.hxx>
#include <HLRBRep_TheInterferenceOfInterCSurf.hxx>
#include <HLRBRep_TheCSFunctionOfInterCSurf.hxx>
#include <HLRBRep_TheExactInterCSurf.hxx>
#include <HLRBRep_TheQuadCurvFuncOfTheQuadCurvExactInterCSurf.hxx>
#include <HLRBRep_TheQuadCurvExactInterCSurf.hxx>
#include <HLRBRep.hxx>
#include <HLRAlgo_Intersection.hxx>
#include <TopAbs_State.hxx>
#include <BRepAdaptor_Curve.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Dir2d.hxx>
#include <GeomAbs_Shape.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <gp_Vec2d.hxx>
#include <GeomAbs_CurveType.hxx>
#include <gp_Lin2d.hxx>
#include <gp_Circ2d.hxx>
#include <gp_Elips2d.hxx>
#include <gp_Hypr2d.hxx>
#include <gp_Parab2d.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <Geom_BSplineCurve.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <gp_Lin.hxx>
#include <gp_Circ.hxx>
#include <gp_Elips.hxx>
#include <gp_Hypr.hxx>
#include <gp_Parab.hxx>
#include <Geom_BezierCurve.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <HLRAlgo_EdgeStatus.hxx>
#include <NCollection_Array1.hxx>
#include <HLRBRep_Array1OfEData.hxx>
#include <BRepAdaptor_Surface.hxx>
#include <TopoDS_Face.hxx>
#include <GeomAbs_SurfaceType.hxx>
#include <gp_Pln.hxx>
#include <gp_Cylinder.hxx>
#include <gp_Cone.hxx>
#include <gp_Sphere.hxx>
#include <gp_Torus.hxx>
#include <gp_Ax1.hxx>
#include <TColgp_Array2OfPnt.hxx>
#include <Adaptor3d_HSurface.hxx>
#include <Geom_BezierSurface.hxx>
#include <Geom_BSplineSurface.hxx>
#include <gp_Dir.hxx>
#include <Adaptor3d_HCurve.hxx>
#include <TopAbs_Orientation.hxx>
#include <HLRAlgo_WiresBlock.hxx>
#include <HLRBRep_Array1OfFData.hxx>
#include <gp_XY.hxx>
#include <IntRes2d_Intersection.hxx>
#include <IntRes2d_Domain.hxx>
#include <IntCurve_IConicTool.hxx>
#include <IntCurve_IntConicConic.hxx>
#include <LProp_Status.hxx>
#include <Geom2d_BezierCurve.hxx>
#include <Geom2d_BSplineCurve.hxx>
#include <IntCurveSurface_Intersection.hxx>
#include <Bnd_BoundSortBox.hxx>
#include <IntAna_IntConicQuad.hxx>
#include <Bnd_Box.hxx>
#include <IntRes2d_IntersectionPoint.hxx>
#include <IntCurveSurface_IntersectionPoint.hxx>
#include <IntRes2d_IntersectionSegment.hxx>
#include <IntCurveSurface_IntersectionSegment.hxx>
#include <TopTools_IndexedMapOfShape.hxx>
#include <HLRAlgo_Interference.hxx>
#include <HLRAlgo_InterferenceList.hxx>
#include <BRepTopAdaptor_TopolTool.hxx>
#include <math_FunctionSetWithDerivatives.hxx>
#include <math_Vector.hxx>
#include <math_Matrix.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <NCollection_List.hxx>
#include <HLRBRep_ListOfBPnt2D.hxx>
#include <HLRBRep_ListOfBPoint.hxx>
#include <math_FunctionWithDerivative.hxx>
#include <Extrema_POnCurv2d.hxx>
#include <TColStd_SequenceOfReal.hxx>
#include <TColStd_SequenceOfInteger.hxx>
#include <Extrema_SequenceOfPOnCurv2d.hxx>
#include <HLRAlgo_PolyAlgo.hxx>
#include <HLRAlgo_BiPoint.hxx>
#include <TColStd_Array1OfTransient.hxx>
#include <TopTools_MapOfShape.hxx>
#include <HLRAlgo_PolyInternalNode.hxx>
#include <HLRAlgo_Array1OfTData.hxx>
#include <HLRAlgo_Array1OfPISeg.hxx>
#include <HLRAlgo_Array1OfPINod.hxx>
#include <gp_XYZ.hxx>
#include <HLRAlgo_ListOfBPoint.hxx>
#include <TopTools_ListOfShape.hxx>
#include <HLRAlgo_PolyInternalData.hxx>
#include <HLRAlgo_TriangleData.hxx>
#include <TopTools_SequenceOfShape.hxx>
#include <Geom_Surface.hxx>
#include <BRepAdaptor_Curve2d.hxx>
#include <math_FunctionSetRoot.hxx>
#include <Intf_Interference.hxx>
#include <Intf_Array1OfLin.hxx>
#include <Intf_Polygon2d.hxx>
#include <Bnd_Box2d.hxx>
#include <Bnd_HArray1OfBox.hxx>
#include <IntSurf_Quadric.hxx>
#include <bind_NCollection_Sequence.hxx>
#include <bind_NCollection_Array1.hxx>
#include <bind_NCollection_List.hxx>
#include <bind_NCollection_TListIterator.hxx>

PYBIND11_MODULE(HLRBRep, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.HLRTopoBRep");
py::module::import("OCCT.HLRAlgo");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.BRepTopAdaptor");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.TopAbs");
py::module::import("OCCT.BRepAdaptor");
py::module::import("OCCT.gp");
py::module::import("OCCT.GeomAbs");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.TColgp");
py::module::import("OCCT.Geom");
py::module::import("OCCT.Adaptor3d");
py::module::import("OCCT.IntRes2d");
py::module::import("OCCT.IntCurve");
py::module::import("OCCT.LProp");
py::module::import("OCCT.Geom2d");
py::module::import("OCCT.IntCurveSurface");
py::module::import("OCCT.Bnd");
py::module::import("OCCT.IntAna");
py::module::import("OCCT.TopTools");
py::module::import("OCCT.math");
py::module::import("OCCT.Extrema");
py::module::import("OCCT.Intf");
py::module::import("OCCT.IntSurf");

// ENUM: HLRBREP_TYPEOFRESULTINGEDGE
py::enum_<HLRBRep_TypeOfResultingEdge>(mod, "HLRBRep_TypeOfResultingEdge", "Identifies the type of resulting edge of HLRBRep_Algo")
	.value("HLRBRep_Undefined", HLRBRep_TypeOfResultingEdge::HLRBRep_Undefined)
	.value("HLRBRep_IsoLine", HLRBRep_TypeOfResultingEdge::HLRBRep_IsoLine)
	.value("HLRBRep_OutLine", HLRBRep_TypeOfResultingEdge::HLRBRep_OutLine)
	.value("HLRBRep_Rg1Line", HLRBRep_TypeOfResultingEdge::HLRBRep_Rg1Line)
	.value("HLRBRep_RgNLine", HLRBRep_TypeOfResultingEdge::HLRBRep_RgNLine)
	.value("HLRBRep_Sharp", HLRBRep_TypeOfResultingEdge::HLRBRep_Sharp)
	.export_values();


// CLASS: HLRBREP_SHAPEBOUNDS
py::class_<HLRBRep_ShapeBounds> cls_HLRBRep_ShapeBounds(mod, "HLRBRep_ShapeBounds", "Contains a Shape and the bounds of its vertices, edges and faces in the DataStructure.");

// Constructors
cls_HLRBRep_ShapeBounds.def(py::init<>());
cls_HLRBRep_ShapeBounds.def(py::init<const opencascade::handle<HLRTopoBRep_OutLiner> &, const opencascade::handle<Standard_Transient> &, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("S"), py::arg("SData"), py::arg("nbIso"), py::arg("V1"), py::arg("V2"), py::arg("E1"), py::arg("E2"), py::arg("F1"), py::arg("F2"));
cls_HLRBRep_ShapeBounds.def(py::init<const opencascade::handle<HLRTopoBRep_OutLiner> &, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("S"), py::arg("nbIso"), py::arg("V1"), py::arg("V2"), py::arg("E1"), py::arg("E2"), py::arg("F1"), py::arg("F2"));

// Methods
// cls_HLRBRep_ShapeBounds.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_ShapeBounds::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_ShapeBounds.def_static("operator delete_", (void (*)(void *)) &HLRBRep_ShapeBounds::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_ShapeBounds.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_ShapeBounds::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_ShapeBounds.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_ShapeBounds::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_ShapeBounds.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_ShapeBounds::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_ShapeBounds.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_ShapeBounds::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_ShapeBounds.def("Translate", (void (HLRBRep_ShapeBounds::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer)) &HLRBRep_ShapeBounds::Translate, "None", py::arg("NV"), py::arg("NE"), py::arg("NF"));
cls_HLRBRep_ShapeBounds.def("Shape", (void (HLRBRep_ShapeBounds::*)(const opencascade::handle<HLRTopoBRep_OutLiner> &)) &HLRBRep_ShapeBounds::Shape, "None", py::arg("S"));
cls_HLRBRep_ShapeBounds.def("Shape", (const opencascade::handle<HLRTopoBRep_OutLiner> & (HLRBRep_ShapeBounds::*)() const) &HLRBRep_ShapeBounds::Shape, "None");
cls_HLRBRep_ShapeBounds.def("ShapeData", (void (HLRBRep_ShapeBounds::*)(const opencascade::handle<Standard_Transient> &)) &HLRBRep_ShapeBounds::ShapeData, "None", py::arg("SD"));
cls_HLRBRep_ShapeBounds.def("ShapeData", (const opencascade::handle<Standard_Transient> & (HLRBRep_ShapeBounds::*)() const) &HLRBRep_ShapeBounds::ShapeData, "None");
cls_HLRBRep_ShapeBounds.def("NbOfIso", (void (HLRBRep_ShapeBounds::*)(const Standard_Integer)) &HLRBRep_ShapeBounds::NbOfIso, "None", py::arg("nbIso"));
cls_HLRBRep_ShapeBounds.def("NbOfIso", (Standard_Integer (HLRBRep_ShapeBounds::*)() const) &HLRBRep_ShapeBounds::NbOfIso, "None");
cls_HLRBRep_ShapeBounds.def("Sizes", [](HLRBRep_ShapeBounds &self, Standard_Integer & NV, Standard_Integer & NE, Standard_Integer & NF){ self.Sizes(NV, NE, NF); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &>(NV, NE, NF); }, "None", py::arg("NV"), py::arg("NE"), py::arg("NF"));
cls_HLRBRep_ShapeBounds.def("Bounds", [](HLRBRep_ShapeBounds &self, Standard_Integer & V1, Standard_Integer & V2, Standard_Integer & E1, Standard_Integer & E2, Standard_Integer & F1, Standard_Integer & F2){ self.Bounds(V1, V2, E1, E2, F1, F2); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &>(V1, V2, E1, E2, F1, F2); }, "None", py::arg("V1"), py::arg("V2"), py::arg("E1"), py::arg("E2"), py::arg("F1"), py::arg("F2"));
cls_HLRBRep_ShapeBounds.def("UpdateMinMax", (void (HLRBRep_ShapeBounds::*)(const HLRAlgo_EdgesBlock::MinMaxIndices &)) &HLRBRep_ShapeBounds::UpdateMinMax, "None", py::arg("theTotMinMax"));
cls_HLRBRep_ShapeBounds.def("MinMax", (HLRAlgo_EdgesBlock::MinMaxIndices & (HLRBRep_ShapeBounds::*)()) &HLRBRep_ShapeBounds::MinMax, "None");

// TYPEDEF: HLRBREP_SEQOFSHAPEBOUNDS
bind_NCollection_Sequence<HLRBRep_ShapeBounds>(mod, "HLRBRep_SeqOfShapeBounds", py::module_local(false));

// CLASS: HLRBREP_INTERNALALGO
py::class_<HLRBRep_InternalAlgo, opencascade::handle<HLRBRep_InternalAlgo>, Standard_Transient> cls_HLRBRep_InternalAlgo(mod, "HLRBRep_InternalAlgo", "None");

// Constructors
cls_HLRBRep_InternalAlgo.def(py::init<>());
cls_HLRBRep_InternalAlgo.def(py::init<const opencascade::handle<HLRBRep_InternalAlgo> &>(), py::arg("A"));

// Methods
cls_HLRBRep_InternalAlgo.def("Projector", (void (HLRBRep_InternalAlgo::*)(const HLRAlgo_Projector &)) &HLRBRep_InternalAlgo::Projector, "set the projector.", py::arg("P"));
cls_HLRBRep_InternalAlgo.def("Projector", (HLRAlgo_Projector & (HLRBRep_InternalAlgo::*)()) &HLRBRep_InternalAlgo::Projector, "set the projector.");
cls_HLRBRep_InternalAlgo.def("Update", (void (HLRBRep_InternalAlgo::*)()) &HLRBRep_InternalAlgo::Update, "update the DataStructure.");
cls_HLRBRep_InternalAlgo.def("Load", [](HLRBRep_InternalAlgo &self, const opencascade::handle<HLRTopoBRep_OutLiner> & a0, const opencascade::handle<Standard_Transient> & a1) -> void { return self.Load(a0, a1); });
cls_HLRBRep_InternalAlgo.def("Load", (void (HLRBRep_InternalAlgo::*)(const opencascade::handle<HLRTopoBRep_OutLiner> &, const opencascade::handle<Standard_Transient> &, const Standard_Integer)) &HLRBRep_InternalAlgo::Load, "add the shape <S>.", py::arg("S"), py::arg("SData"), py::arg("nbIso"));
cls_HLRBRep_InternalAlgo.def("Load", [](HLRBRep_InternalAlgo &self, const opencascade::handle<HLRTopoBRep_OutLiner> & a0) -> void { return self.Load(a0); });
cls_HLRBRep_InternalAlgo.def("Load", (void (HLRBRep_InternalAlgo::*)(const opencascade::handle<HLRTopoBRep_OutLiner> &, const Standard_Integer)) &HLRBRep_InternalAlgo::Load, "add the shape <S>.", py::arg("S"), py::arg("nbIso"));
cls_HLRBRep_InternalAlgo.def("Index", (Standard_Integer (HLRBRep_InternalAlgo::*)(const opencascade::handle<HLRTopoBRep_OutLiner> &) const) &HLRBRep_InternalAlgo::Index, "return the index of the Shape <S> and return 0 if the Shape <S> is not found.", py::arg("S"));
cls_HLRBRep_InternalAlgo.def("Remove", (void (HLRBRep_InternalAlgo::*)(const Standard_Integer)) &HLRBRep_InternalAlgo::Remove, "remove the Shape of Index <I>.", py::arg("I"));
cls_HLRBRep_InternalAlgo.def("ShapeData", (void (HLRBRep_InternalAlgo::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &)) &HLRBRep_InternalAlgo::ShapeData, "Change the Shape Data of the Shape of index <I>.", py::arg("I"), py::arg("SData"));
cls_HLRBRep_InternalAlgo.def("SeqOfShapeBounds", (HLRBRep_SeqOfShapeBounds & (HLRBRep_InternalAlgo::*)()) &HLRBRep_InternalAlgo::SeqOfShapeBounds, "None");
cls_HLRBRep_InternalAlgo.def("NbShapes", (Standard_Integer (HLRBRep_InternalAlgo::*)() const) &HLRBRep_InternalAlgo::NbShapes, "None");
cls_HLRBRep_InternalAlgo.def("ShapeBounds", (HLRBRep_ShapeBounds & (HLRBRep_InternalAlgo::*)(const Standard_Integer)) &HLRBRep_InternalAlgo::ShapeBounds, "None", py::arg("I"));
cls_HLRBRep_InternalAlgo.def("InitEdgeStatus", (void (HLRBRep_InternalAlgo::*)()) &HLRBRep_InternalAlgo::InitEdgeStatus, "init the status of the selected edges depending of the back faces of a closed shell.");
cls_HLRBRep_InternalAlgo.def("Select", (void (HLRBRep_InternalAlgo::*)()) &HLRBRep_InternalAlgo::Select, "select all the DataStructure.");
cls_HLRBRep_InternalAlgo.def("Select", (void (HLRBRep_InternalAlgo::*)(const Standard_Integer)) &HLRBRep_InternalAlgo::Select, "select only the Shape of index <I>.", py::arg("I"));
cls_HLRBRep_InternalAlgo.def("SelectEdge", (void (HLRBRep_InternalAlgo::*)(const Standard_Integer)) &HLRBRep_InternalAlgo::SelectEdge, "select only the edges of the Shape <S>.", py::arg("I"));
cls_HLRBRep_InternalAlgo.def("SelectFace", (void (HLRBRep_InternalAlgo::*)(const Standard_Integer)) &HLRBRep_InternalAlgo::SelectFace, "select only the faces of the Shape <S>.", py::arg("I"));
cls_HLRBRep_InternalAlgo.def("ShowAll", (void (HLRBRep_InternalAlgo::*)()) &HLRBRep_InternalAlgo::ShowAll, "set to visible all the edges.");
cls_HLRBRep_InternalAlgo.def("ShowAll", (void (HLRBRep_InternalAlgo::*)(const Standard_Integer)) &HLRBRep_InternalAlgo::ShowAll, "set to visible all the edges of the Shape <S>.", py::arg("I"));
cls_HLRBRep_InternalAlgo.def("HideAll", (void (HLRBRep_InternalAlgo::*)()) &HLRBRep_InternalAlgo::HideAll, "set to hide all the edges.");
cls_HLRBRep_InternalAlgo.def("HideAll", (void (HLRBRep_InternalAlgo::*)(const Standard_Integer)) &HLRBRep_InternalAlgo::HideAll, "set to hide all the edges of the Shape <S>.", py::arg("I"));
cls_HLRBRep_InternalAlgo.def("PartialHide", (void (HLRBRep_InternalAlgo::*)()) &HLRBRep_InternalAlgo::PartialHide, "own hiding of all the shapes of the DataStructure without hiding by each other.");
cls_HLRBRep_InternalAlgo.def("Hide", (void (HLRBRep_InternalAlgo::*)()) &HLRBRep_InternalAlgo::Hide, "hide all the DataStructure.");
cls_HLRBRep_InternalAlgo.def("Hide", (void (HLRBRep_InternalAlgo::*)(const Standard_Integer)) &HLRBRep_InternalAlgo::Hide, "hide the Shape <S> by itself.", py::arg("I"));
cls_HLRBRep_InternalAlgo.def("Hide", (void (HLRBRep_InternalAlgo::*)(const Standard_Integer, const Standard_Integer)) &HLRBRep_InternalAlgo::Hide, "hide the Shape <S1> by the shape <S2>.", py::arg("I"), py::arg("J"));
cls_HLRBRep_InternalAlgo.def("Debug", (void (HLRBRep_InternalAlgo::*)(const Standard_Boolean)) &HLRBRep_InternalAlgo::Debug, "None", py::arg("deb"));
cls_HLRBRep_InternalAlgo.def("Debug", (Standard_Boolean (HLRBRep_InternalAlgo::*)() const) &HLRBRep_InternalAlgo::Debug, "None");
cls_HLRBRep_InternalAlgo.def("DataStructure", (opencascade::handle<HLRBRep_Data> (HLRBRep_InternalAlgo::*)() const) &HLRBRep_InternalAlgo::DataStructure, "None");
cls_HLRBRep_InternalAlgo.def_static("get_type_name_", (const char * (*)()) &HLRBRep_InternalAlgo::get_type_name, "None");
cls_HLRBRep_InternalAlgo.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &HLRBRep_InternalAlgo::get_type_descriptor, "None");
cls_HLRBRep_InternalAlgo.def("DynamicType", (const opencascade::handle<Standard_Type> & (HLRBRep_InternalAlgo::*)() const) &HLRBRep_InternalAlgo::DynamicType, "None");

// CLASS: HLRBREP_ALGO
py::class_<HLRBRep_Algo, opencascade::handle<HLRBRep_Algo>, HLRBRep_InternalAlgo> cls_HLRBRep_Algo(mod, "HLRBRep_Algo", "Inherited from InternalAlgo to provide methods with Shape from TopoDS. A framework to compute a shape as seen in a projection plane. This is done by calculating the visible and the hidden parts of the shape. HLRBRep_Algo works with three types of entity: - shapes to be visualized - edges in these shapes (these edges are the basic entities which will be visualized or hidden), and - faces in these shapes which hide the edges. HLRBRep_Algo is based on the principle of comparing each edge of the shape to be visualized with each of its faces, and calculating the visible and the hidden parts of each edge. For a given projection, HLRBRep_Algo calculates a set of lines characteristic of the object being represented. It is also used in conjunction with the HLRBRep_HLRToShape extraction utilities, which reconstruct a new, simplified shape from a selection of calculation results. This new shape is made up of edges, which represent the shape visualized in the projection. HLRBRep_Algo takes the shape itself into account whereas HLRBRep_PolyAlgo works with a polyhedral simplification of the shape. When you use HLRBRep_Algo, you obtain an exact result, whereas, when you use HLRBRep_PolyAlgo, you reduce computation time but obtain polygonal segments. In the case of complicated shapes, HLRBRep_Algo may be time-consuming. An HLRBRep_Algo object provides a framework for: - defining the point of view - identifying the shape or shapes to be visualized - calculating the outlines - calculating the visible and hidden lines of the shape. Warning - Superimposed lines are not eliminated by this algorithm. - There must be no unfinished objects inside the shape you wish to visualize. - Points are not treated. - Note that this is not the sort of algorithm used in generating shading, which calculates the visible and hidden parts of each face in a shape to be visualized by comparing each face in the shape with every other face in the same shape.");

// Constructors
cls_HLRBRep_Algo.def(py::init<>());
cls_HLRBRep_Algo.def(py::init<const opencascade::handle<HLRBRep_Algo> &>(), py::arg("A"));

// Methods
cls_HLRBRep_Algo.def("Add", [](HLRBRep_Algo &self, const TopoDS_Shape & a0, const opencascade::handle<Standard_Transient> & a1) -> void { return self.Add(a0, a1); });
cls_HLRBRep_Algo.def("Add", (void (HLRBRep_Algo::*)(const TopoDS_Shape &, const opencascade::handle<Standard_Transient> &, const Standard_Integer)) &HLRBRep_Algo::Add, "add the Shape <S>.", py::arg("S"), py::arg("SData"), py::arg("nbIso"));
cls_HLRBRep_Algo.def("Add", [](HLRBRep_Algo &self, const TopoDS_Shape & a0) -> void { return self.Add(a0); });
cls_HLRBRep_Algo.def("Add", (void (HLRBRep_Algo::*)(const TopoDS_Shape &, const Standard_Integer)) &HLRBRep_Algo::Add, "Adds the shape S to this framework, and specifies the number of isoparameters nbiso desired in visualizing S. You may add as many shapes as you wish. Use the function Add once for each shape.", py::arg("S"), py::arg("nbIso"));
cls_HLRBRep_Algo.def("Index", (Standard_Integer (HLRBRep_Algo::*)(const TopoDS_Shape &)) &HLRBRep_Algo::Index, "return the index of the Shape <S> and return 0 if the Shape <S> is not found.", py::arg("S"));
cls_HLRBRep_Algo.def("OutLinedShapeNullify", (void (HLRBRep_Algo::*)()) &HLRBRep_Algo::OutLinedShapeNullify, "nullify all the results of OutLiner from HLRTopoBRep.");
cls_HLRBRep_Algo.def_static("get_type_name_", (const char * (*)()) &HLRBRep_Algo::get_type_name, "None");
cls_HLRBRep_Algo.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &HLRBRep_Algo::get_type_descriptor, "None");
cls_HLRBRep_Algo.def("DynamicType", (const opencascade::handle<Standard_Type> & (HLRBRep_Algo::*)() const) &HLRBRep_Algo::DynamicType, "None");

// CLASS: HLRBREP
py::class_<HLRBRep> cls_HLRBRep(mod, "HLRBRep", "Hidden Lines Removal algorithms on the BRep DataStructure.");

// Constructors
cls_HLRBRep.def(py::init<>());

// Methods
// cls_HLRBRep.def_static("operator new_", (void * (*)(size_t)) &HLRBRep::operator new, "None", py::arg("theSize"));
// cls_HLRBRep.def_static("operator delete_", (void (*)(void *)) &HLRBRep::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep.def_static("MakeEdge_", (TopoDS_Edge (*)(const HLRBRep_Curve &, const Standard_Real, const Standard_Real)) &HLRBRep::MakeEdge, "None", py::arg("ec"), py::arg("U1"), py::arg("U2"));
cls_HLRBRep.def_static("MakeEdge3d_", (TopoDS_Edge (*)(const HLRBRep_Curve &, const Standard_Real, const Standard_Real)) &HLRBRep::MakeEdge3d, "None", py::arg("ec"), py::arg("U1"), py::arg("U2"));
cls_HLRBRep.def_static("PolyHLRAngleAndDeflection_", [](const Standard_Real InAngl, Standard_Real & OutAngl, Standard_Real & OutDefl){ HLRBRep::PolyHLRAngleAndDeflection(InAngl, OutAngl, OutDefl); return std::tuple<Standard_Real &, Standard_Real &>(OutAngl, OutDefl); }, "None", py::arg("InAngl"), py::arg("OutAngl"), py::arg("OutDefl"));

// CLASS: HLRBREP_AREALIMIT
py::class_<HLRBRep_AreaLimit, opencascade::handle<HLRBRep_AreaLimit>, Standard_Transient> cls_HLRBRep_AreaLimit(mod, "HLRBRep_AreaLimit", "The private nested class AreaLimit represents a -- vertex on the Edge with the state on the left and -- the right.");

// Constructors
cls_HLRBRep_AreaLimit.def(py::init<const HLRAlgo_Intersection &, const Standard_Boolean, const Standard_Boolean, const TopAbs_State, const TopAbs_State, const TopAbs_State, const TopAbs_State>(), py::arg("V"), py::arg("Boundary"), py::arg("Interference"), py::arg("StateBefore"), py::arg("StateAfter"), py::arg("EdgeBefore"), py::arg("EdgeAfter"));

// Methods
cls_HLRBRep_AreaLimit.def("StateBefore", (void (HLRBRep_AreaLimit::*)(const TopAbs_State)) &HLRBRep_AreaLimit::StateBefore, "None", py::arg("St"));
cls_HLRBRep_AreaLimit.def("StateAfter", (void (HLRBRep_AreaLimit::*)(const TopAbs_State)) &HLRBRep_AreaLimit::StateAfter, "None", py::arg("St"));
cls_HLRBRep_AreaLimit.def("EdgeBefore", (void (HLRBRep_AreaLimit::*)(const TopAbs_State)) &HLRBRep_AreaLimit::EdgeBefore, "None", py::arg("St"));
cls_HLRBRep_AreaLimit.def("EdgeAfter", (void (HLRBRep_AreaLimit::*)(const TopAbs_State)) &HLRBRep_AreaLimit::EdgeAfter, "None", py::arg("St"));
cls_HLRBRep_AreaLimit.def("Previous", (void (HLRBRep_AreaLimit::*)(const opencascade::handle<HLRBRep_AreaLimit> &)) &HLRBRep_AreaLimit::Previous, "None", py::arg("P"));
cls_HLRBRep_AreaLimit.def("Next", (void (HLRBRep_AreaLimit::*)(const opencascade::handle<HLRBRep_AreaLimit> &)) &HLRBRep_AreaLimit::Next, "None", py::arg("N"));
cls_HLRBRep_AreaLimit.def("Vertex", (const HLRAlgo_Intersection & (HLRBRep_AreaLimit::*)() const) &HLRBRep_AreaLimit::Vertex, "None");
cls_HLRBRep_AreaLimit.def("IsBoundary", (Standard_Boolean (HLRBRep_AreaLimit::*)() const) &HLRBRep_AreaLimit::IsBoundary, "None");
cls_HLRBRep_AreaLimit.def("IsInterference", (Standard_Boolean (HLRBRep_AreaLimit::*)() const) &HLRBRep_AreaLimit::IsInterference, "None");
cls_HLRBRep_AreaLimit.def("StateBefore", (TopAbs_State (HLRBRep_AreaLimit::*)() const) &HLRBRep_AreaLimit::StateBefore, "None");
cls_HLRBRep_AreaLimit.def("StateAfter", (TopAbs_State (HLRBRep_AreaLimit::*)() const) &HLRBRep_AreaLimit::StateAfter, "None");
cls_HLRBRep_AreaLimit.def("EdgeBefore", (TopAbs_State (HLRBRep_AreaLimit::*)() const) &HLRBRep_AreaLimit::EdgeBefore, "None");
cls_HLRBRep_AreaLimit.def("EdgeAfter", (TopAbs_State (HLRBRep_AreaLimit::*)() const) &HLRBRep_AreaLimit::EdgeAfter, "None");
cls_HLRBRep_AreaLimit.def("Previous", (opencascade::handle<HLRBRep_AreaLimit> (HLRBRep_AreaLimit::*)() const) &HLRBRep_AreaLimit::Previous, "None");
cls_HLRBRep_AreaLimit.def("Next", (opencascade::handle<HLRBRep_AreaLimit> (HLRBRep_AreaLimit::*)() const) &HLRBRep_AreaLimit::Next, "None");
cls_HLRBRep_AreaLimit.def("Clear", (void (HLRBRep_AreaLimit::*)()) &HLRBRep_AreaLimit::Clear, "None");
cls_HLRBRep_AreaLimit.def_static("get_type_name_", (const char * (*)()) &HLRBRep_AreaLimit::get_type_name, "None");
cls_HLRBRep_AreaLimit.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &HLRBRep_AreaLimit::get_type_descriptor, "None");
cls_HLRBRep_AreaLimit.def("DynamicType", (const opencascade::handle<Standard_Type> & (HLRBRep_AreaLimit::*)() const) &HLRBRep_AreaLimit::DynamicType, "None");

// CLASS: HLRBREP_CURVE
py::class_<HLRBRep_Curve> cls_HLRBRep_Curve(mod, "HLRBRep_Curve", "Defines a 2d curve by projection of a 3D curve on a plane with an optional perspective transformation.");

// Constructors
cls_HLRBRep_Curve.def(py::init<>());

// Methods
// cls_HLRBRep_Curve.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_Curve::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_Curve.def_static("operator delete_", (void (*)(void *)) &HLRBRep_Curve::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_Curve.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_Curve::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_Curve.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_Curve::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_Curve.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_Curve::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_Curve.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_Curve::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_Curve.def("Projector", (void (HLRBRep_Curve::*)(const HLRAlgo_Projector *)) &HLRBRep_Curve::Projector, "None", py::arg("Proj"));
cls_HLRBRep_Curve.def("Curve", (BRepAdaptor_Curve & (HLRBRep_Curve::*)()) &HLRBRep_Curve::Curve, "Returns the 3D curve.");
cls_HLRBRep_Curve.def("Curve", (void (HLRBRep_Curve::*)(const TopoDS_Edge &)) &HLRBRep_Curve::Curve, "Sets the 3D curve to be projected.", py::arg("E"));
cls_HLRBRep_Curve.def("GetCurve", (const BRepAdaptor_Curve & (HLRBRep_Curve::*)() const) &HLRBRep_Curve::GetCurve, "Returns the 3D curve.");
cls_HLRBRep_Curve.def("Parameter2d", (Standard_Real (HLRBRep_Curve::*)(const Standard_Real) const) &HLRBRep_Curve::Parameter2d, "Returns the parameter on the 2d curve from the parameter on the 3d curve.", py::arg("P3d"));
cls_HLRBRep_Curve.def("Parameter3d", (Standard_Real (HLRBRep_Curve::*)(const Standard_Real) const) &HLRBRep_Curve::Parameter3d, "Returns the parameter on the 3d curve from the parameter on the 2d curve.", py::arg("P2d"));
// cls_HLRBRep_Curve.def("Update", (Standard_Real (HLRBRep_Curve::*)(Standard_Real [16], Standard_Real [16])) &HLRBRep_Curve::Update, "Update the minmax and the internal data", py::arg("TotMin"), py::arg("TotMax"));
// cls_HLRBRep_Curve.def("UpdateMinMax", (Standard_Real (HLRBRep_Curve::*)(Standard_Real [16], Standard_Real [16])) &HLRBRep_Curve::UpdateMinMax, "Update the minmax returns tol for enlarge;", py::arg("TotMin"), py::arg("TotMax"));
cls_HLRBRep_Curve.def("Z", (Standard_Real (HLRBRep_Curve::*)(const Standard_Real) const) &HLRBRep_Curve::Z, "Computes the Z coordinate of the point of parameter U on the curve in the viewing coordinate system", py::arg("U"));
cls_HLRBRep_Curve.def("Value3D", (gp_Pnt (HLRBRep_Curve::*)(const Standard_Real) const) &HLRBRep_Curve::Value3D, "Computes the 3D point of parameter U on the curve.", py::arg("U"));
cls_HLRBRep_Curve.def("D0", (void (HLRBRep_Curve::*)(const Standard_Real, gp_Pnt &) const) &HLRBRep_Curve::D0, "Computes the 3D point of parameter U on the curve.", py::arg("U"), py::arg("P"));
cls_HLRBRep_Curve.def("D1", (void (HLRBRep_Curve::*)(const Standard_Real, gp_Pnt &, gp_Vec &) const) &HLRBRep_Curve::D1, "Computes the point of parameter U on the curve with its first derivative.", py::arg("U"), py::arg("P"), py::arg("V"));
cls_HLRBRep_Curve.def("Tangent", (void (HLRBRep_Curve::*)(const Standard_Boolean, gp_Pnt2d &, gp_Dir2d &) const) &HLRBRep_Curve::Tangent, "Depending on <AtStart> computes the 2D point and tangent on the curve at sart (or at end). If the first derivative is null look after at start (or before at end) with the second derivative.", py::arg("AtStart"), py::arg("P"), py::arg("D"));
cls_HLRBRep_Curve.def("FirstParameter", (Standard_Real (HLRBRep_Curve::*)() const) &HLRBRep_Curve::FirstParameter, "None");
cls_HLRBRep_Curve.def("LastParameter", (Standard_Real (HLRBRep_Curve::*)() const) &HLRBRep_Curve::LastParameter, "None");
cls_HLRBRep_Curve.def("Continuity", (GeomAbs_Shape (HLRBRep_Curve::*)() const) &HLRBRep_Curve::Continuity, "None");
cls_HLRBRep_Curve.def("NbIntervals", (Standard_Integer (HLRBRep_Curve::*)(const GeomAbs_Shape) const) &HLRBRep_Curve::NbIntervals, "If necessary, breaks the curve in intervals of continuity <S>. And returns the number of intervals.", py::arg("S"));
cls_HLRBRep_Curve.def("Intervals", (void (HLRBRep_Curve::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const) &HLRBRep_Curve::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("T"), py::arg("S"));
cls_HLRBRep_Curve.def("IsClosed", (Standard_Boolean (HLRBRep_Curve::*)() const) &HLRBRep_Curve::IsClosed, "None");
cls_HLRBRep_Curve.def("IsPeriodic", (Standard_Boolean (HLRBRep_Curve::*)() const) &HLRBRep_Curve::IsPeriodic, "None");
cls_HLRBRep_Curve.def("Period", (Standard_Real (HLRBRep_Curve::*)() const) &HLRBRep_Curve::Period, "None");
cls_HLRBRep_Curve.def("Value", (gp_Pnt2d (HLRBRep_Curve::*)(const Standard_Real) const) &HLRBRep_Curve::Value, "Computes the point of parameter U on the curve.", py::arg("U"));
cls_HLRBRep_Curve.def("D0", (void (HLRBRep_Curve::*)(const Standard_Real, gp_Pnt2d &) const) &HLRBRep_Curve::D0, "Computes the point of parameter U on the curve.", py::arg("U"), py::arg("P"));
cls_HLRBRep_Curve.def("D1", (void (HLRBRep_Curve::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &) const) &HLRBRep_Curve::D1, "Computes the point of parameter U on the curve with its first derivative. Raised if the continuity of the current interval is not C1.", py::arg("U"), py::arg("P"), py::arg("V"));
cls_HLRBRep_Curve.def("D2", (void (HLRBRep_Curve::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &) const) &HLRBRep_Curve::D2, "Raised if the continuity of the current interval is not C2.", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"));
cls_HLRBRep_Curve.def("D3", (void (HLRBRep_Curve::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &, gp_Vec2d &) const) &HLRBRep_Curve::D3, "Returns the point P of parameter U, the first, the second and the third derivative. Raised if the continuity of the current interval is not C3.", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"));
cls_HLRBRep_Curve.def("DN", (gp_Vec2d (HLRBRep_Curve::*)(const Standard_Real, const Standard_Integer) const) &HLRBRep_Curve::DN, "The returned vector gives the value of the derivative for the order of derivation N. Raised if the continuity of the current interval is not CN. Raised if N < 1.", py::arg("U"), py::arg("N"));
cls_HLRBRep_Curve.def("Resolution", (Standard_Real (HLRBRep_Curve::*)(const Standard_Real) const) &HLRBRep_Curve::Resolution, "Returns the parametric resolution corresponding to the real space resolution <R3d>.", py::arg("R3d"));
cls_HLRBRep_Curve.def("GetType", (GeomAbs_CurveType (HLRBRep_Curve::*)() const) &HLRBRep_Curve::GetType, "Returns the type of the curve in the current interval : Line, Circle, Ellipse, Hyperbola, Parabola, BezierCurve, BSplineCurve, OtherCurve.");
cls_HLRBRep_Curve.def("Line", (gp_Lin2d (HLRBRep_Curve::*)() const) &HLRBRep_Curve::Line, "None");
cls_HLRBRep_Curve.def("Circle", (gp_Circ2d (HLRBRep_Curve::*)() const) &HLRBRep_Curve::Circle, "None");
cls_HLRBRep_Curve.def("Ellipse", (gp_Elips2d (HLRBRep_Curve::*)() const) &HLRBRep_Curve::Ellipse, "None");
cls_HLRBRep_Curve.def("Hyperbola", (gp_Hypr2d (HLRBRep_Curve::*)() const) &HLRBRep_Curve::Hyperbola, "None");
cls_HLRBRep_Curve.def("Parabola", (gp_Parab2d (HLRBRep_Curve::*)() const) &HLRBRep_Curve::Parabola, "None");
cls_HLRBRep_Curve.def("IsRational", (Standard_Boolean (HLRBRep_Curve::*)() const) &HLRBRep_Curve::IsRational, "None");
cls_HLRBRep_Curve.def("Degree", (Standard_Integer (HLRBRep_Curve::*)() const) &HLRBRep_Curve::Degree, "None");
cls_HLRBRep_Curve.def("NbPoles", (Standard_Integer (HLRBRep_Curve::*)() const) &HLRBRep_Curve::NbPoles, "None");
cls_HLRBRep_Curve.def("Poles", (void (HLRBRep_Curve::*)(TColgp_Array1OfPnt2d &) const) &HLRBRep_Curve::Poles, "None", py::arg("TP"));
cls_HLRBRep_Curve.def("Poles", (void (HLRBRep_Curve::*)(const opencascade::handle<Geom_BSplineCurve> &, TColgp_Array1OfPnt2d &) const) &HLRBRep_Curve::Poles, "None", py::arg("aCurve"), py::arg("TP"));
cls_HLRBRep_Curve.def("PolesAndWeights", (void (HLRBRep_Curve::*)(TColgp_Array1OfPnt2d &, TColStd_Array1OfReal &) const) &HLRBRep_Curve::PolesAndWeights, "None", py::arg("TP"), py::arg("TW"));
cls_HLRBRep_Curve.def("PolesAndWeights", (void (HLRBRep_Curve::*)(const opencascade::handle<Geom_BSplineCurve> &, TColgp_Array1OfPnt2d &, TColStd_Array1OfReal &) const) &HLRBRep_Curve::PolesAndWeights, "None", py::arg("aCurve"), py::arg("TP"), py::arg("TW"));
cls_HLRBRep_Curve.def("NbKnots", (Standard_Integer (HLRBRep_Curve::*)() const) &HLRBRep_Curve::NbKnots, "None");
cls_HLRBRep_Curve.def("Knots", (void (HLRBRep_Curve::*)(TColStd_Array1OfReal &) const) &HLRBRep_Curve::Knots, "None", py::arg("kn"));
cls_HLRBRep_Curve.def("Multiplicities", (void (HLRBRep_Curve::*)(TColStd_Array1OfInteger &) const) &HLRBRep_Curve::Multiplicities, "None", py::arg("mu"));

// CLASS: HLRBREP_BCURVETOOL
py::class_<HLRBRep_BCurveTool> cls_HLRBRep_BCurveTool(mod, "HLRBRep_BCurveTool", "None");

// Constructors
cls_HLRBRep_BCurveTool.def(py::init<>());

// Methods
// cls_HLRBRep_BCurveTool.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_BCurveTool::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_BCurveTool.def_static("operator delete_", (void (*)(void *)) &HLRBRep_BCurveTool::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_BCurveTool.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_BCurveTool::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_BCurveTool.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_BCurveTool::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_BCurveTool.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_BCurveTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_BCurveTool.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_BCurveTool::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_BCurveTool.def_static("FirstParameter_", (Standard_Real (*)(const BRepAdaptor_Curve &)) &HLRBRep_BCurveTool::FirstParameter, "None", py::arg("C"));
cls_HLRBRep_BCurveTool.def_static("LastParameter_", (Standard_Real (*)(const BRepAdaptor_Curve &)) &HLRBRep_BCurveTool::LastParameter, "None", py::arg("C"));
cls_HLRBRep_BCurveTool.def_static("Continuity_", (GeomAbs_Shape (*)(const BRepAdaptor_Curve &)) &HLRBRep_BCurveTool::Continuity, "None", py::arg("C"));
cls_HLRBRep_BCurveTool.def_static("NbIntervals_", (Standard_Integer (*)(const BRepAdaptor_Curve &, const GeomAbs_Shape)) &HLRBRep_BCurveTool::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(myclass) >= <S>", py::arg("C"), py::arg("S"));
cls_HLRBRep_BCurveTool.def_static("Intervals_", (void (*)(const BRepAdaptor_Curve &, TColStd_Array1OfReal &, const GeomAbs_Shape)) &HLRBRep_BCurveTool::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("C"), py::arg("T"), py::arg("S"));
cls_HLRBRep_BCurveTool.def_static("IsClosed_", (Standard_Boolean (*)(const BRepAdaptor_Curve &)) &HLRBRep_BCurveTool::IsClosed, "None", py::arg("C"));
cls_HLRBRep_BCurveTool.def_static("IsPeriodic_", (Standard_Boolean (*)(const BRepAdaptor_Curve &)) &HLRBRep_BCurveTool::IsPeriodic, "None", py::arg("C"));
cls_HLRBRep_BCurveTool.def_static("Period_", (Standard_Real (*)(const BRepAdaptor_Curve &)) &HLRBRep_BCurveTool::Period, "None", py::arg("C"));
cls_HLRBRep_BCurveTool.def_static("Value_", (gp_Pnt (*)(const BRepAdaptor_Curve &, const Standard_Real)) &HLRBRep_BCurveTool::Value, "Computes the point of parameter U on the curve.", py::arg("C"), py::arg("U"));
cls_HLRBRep_BCurveTool.def_static("D0_", (void (*)(const BRepAdaptor_Curve &, const Standard_Real, gp_Pnt &)) &HLRBRep_BCurveTool::D0, "Computes the point of parameter U on the curve.", py::arg("C"), py::arg("U"), py::arg("P"));
cls_HLRBRep_BCurveTool.def_static("D1_", (void (*)(const BRepAdaptor_Curve &, const Standard_Real, gp_Pnt &, gp_Vec &)) &HLRBRep_BCurveTool::D1, "Computes the point of parameter U on the curve with its first derivative. Raised if the continuity of the current interval is not C1.", py::arg("C"), py::arg("U"), py::arg("P"), py::arg("V"));
cls_HLRBRep_BCurveTool.def_static("D2_", (void (*)(const BRepAdaptor_Curve &, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &)) &HLRBRep_BCurveTool::D2, "Returns the point P of parameter U, the first and second derivatives V1 and V2. Raised if the continuity of the current interval is not C2.", py::arg("C"), py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"));
cls_HLRBRep_BCurveTool.def_static("D3_", (void (*)(const BRepAdaptor_Curve &, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &)) &HLRBRep_BCurveTool::D3, "Returns the point P of parameter U, the first, the second and the third derivative. Raised if the continuity of the current interval is not C3.", py::arg("C"), py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"));
cls_HLRBRep_BCurveTool.def_static("DN_", (gp_Vec (*)(const BRepAdaptor_Curve &, const Standard_Real, const Standard_Integer)) &HLRBRep_BCurveTool::DN, "The returned vector gives the value of the derivative for the order of derivation N. Raised if the continuity of the current interval is not CN. Raised if N < 1.", py::arg("C"), py::arg("U"), py::arg("N"));
cls_HLRBRep_BCurveTool.def_static("Resolution_", (Standard_Real (*)(const BRepAdaptor_Curve &, const Standard_Real)) &HLRBRep_BCurveTool::Resolution, "Returns the parametric resolution corresponding to the real space resolution <R3d>.", py::arg("C"), py::arg("R3d"));
cls_HLRBRep_BCurveTool.def_static("GetType_", (GeomAbs_CurveType (*)(const BRepAdaptor_Curve &)) &HLRBRep_BCurveTool::GetType, "Returns the type of the curve in the current interval : Line, Circle, Ellipse, Hyperbola, Parabola, BezierCurve, BSplineCurve, OtherCurve.", py::arg("C"));
cls_HLRBRep_BCurveTool.def_static("Line_", (gp_Lin (*)(const BRepAdaptor_Curve &)) &HLRBRep_BCurveTool::Line, "None", py::arg("C"));
cls_HLRBRep_BCurveTool.def_static("Circle_", (gp_Circ (*)(const BRepAdaptor_Curve &)) &HLRBRep_BCurveTool::Circle, "None", py::arg("C"));
cls_HLRBRep_BCurveTool.def_static("Ellipse_", (gp_Elips (*)(const BRepAdaptor_Curve &)) &HLRBRep_BCurveTool::Ellipse, "None", py::arg("C"));
cls_HLRBRep_BCurveTool.def_static("Hyperbola_", (gp_Hypr (*)(const BRepAdaptor_Curve &)) &HLRBRep_BCurveTool::Hyperbola, "None", py::arg("C"));
cls_HLRBRep_BCurveTool.def_static("Parabola_", (gp_Parab (*)(const BRepAdaptor_Curve &)) &HLRBRep_BCurveTool::Parabola, "None", py::arg("C"));
cls_HLRBRep_BCurveTool.def_static("Bezier_", (opencascade::handle<Geom_BezierCurve> (*)(const BRepAdaptor_Curve &)) &HLRBRep_BCurveTool::Bezier, "None", py::arg("C"));
cls_HLRBRep_BCurveTool.def_static("BSpline_", (opencascade::handle<Geom_BSplineCurve> (*)(const BRepAdaptor_Curve &)) &HLRBRep_BCurveTool::BSpline, "None", py::arg("C"));
cls_HLRBRep_BCurveTool.def_static("Degree_", (Standard_Integer (*)(const BRepAdaptor_Curve &)) &HLRBRep_BCurveTool::Degree, "None", py::arg("C"));
cls_HLRBRep_BCurveTool.def_static("IsRational_", (Standard_Boolean (*)(const BRepAdaptor_Curve &)) &HLRBRep_BCurveTool::IsRational, "None", py::arg("C"));
cls_HLRBRep_BCurveTool.def_static("NbPoles_", (Standard_Integer (*)(const BRepAdaptor_Curve &)) &HLRBRep_BCurveTool::NbPoles, "None", py::arg("C"));
cls_HLRBRep_BCurveTool.def_static("NbKnots_", (Standard_Integer (*)(const BRepAdaptor_Curve &)) &HLRBRep_BCurveTool::NbKnots, "None", py::arg("C"));
cls_HLRBRep_BCurveTool.def_static("Poles_", (void (*)(const BRepAdaptor_Curve &, TColgp_Array1OfPnt &)) &HLRBRep_BCurveTool::Poles, "None", py::arg("C"), py::arg("T"));
cls_HLRBRep_BCurveTool.def_static("PolesAndWeights_", (void (*)(const BRepAdaptor_Curve &, TColgp_Array1OfPnt &, TColStd_Array1OfReal &)) &HLRBRep_BCurveTool::PolesAndWeights, "None", py::arg("C"), py::arg("T"), py::arg("W"));
cls_HLRBRep_BCurveTool.def_static("NbSamples_", (Standard_Integer (*)(const BRepAdaptor_Curve &, const Standard_Real, const Standard_Real)) &HLRBRep_BCurveTool::NbSamples, "None", py::arg("C"), py::arg("U0"), py::arg("U1"));

// CLASS: HLRBREP_EDGEDATA
py::class_<HLRBRep_EdgeData> cls_HLRBRep_EdgeData(mod, "HLRBRep_EdgeData", "None");

// Constructors
cls_HLRBRep_EdgeData.def(py::init<>());

// Methods
// cls_HLRBRep_EdgeData.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_EdgeData::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_EdgeData.def_static("operator delete_", (void (*)(void *)) &HLRBRep_EdgeData::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_EdgeData.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_EdgeData::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_EdgeData.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_EdgeData::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_EdgeData.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_EdgeData::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_EdgeData.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_EdgeData::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_EdgeData.def("Set", (void (HLRBRep_EdgeData::*)(const Standard_Boolean, const Standard_Boolean, const TopoDS_Edge &, const Standard_Integer, const Standard_Integer, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Real, const Standard_ShortReal, const Standard_Real, const Standard_ShortReal)) &HLRBRep_EdgeData::Set, "None", py::arg("Reg1"), py::arg("RegN"), py::arg("EG"), py::arg("V1"), py::arg("V2"), py::arg("Out1"), py::arg("Out2"), py::arg("Cut1"), py::arg("Cut2"), py::arg("Start"), py::arg("TolStart"), py::arg("End"), py::arg("TolEnd"));
cls_HLRBRep_EdgeData.def("Selected", (Standard_Boolean (HLRBRep_EdgeData::*)() const) &HLRBRep_EdgeData::Selected, "None");
cls_HLRBRep_EdgeData.def("Selected", (void (HLRBRep_EdgeData::*)(const Standard_Boolean)) &HLRBRep_EdgeData::Selected, "None", py::arg("B"));
cls_HLRBRep_EdgeData.def("Rg1Line", (Standard_Boolean (HLRBRep_EdgeData::*)() const) &HLRBRep_EdgeData::Rg1Line, "None");
cls_HLRBRep_EdgeData.def("Rg1Line", (void (HLRBRep_EdgeData::*)(const Standard_Boolean)) &HLRBRep_EdgeData::Rg1Line, "None", py::arg("B"));
cls_HLRBRep_EdgeData.def("RgNLine", (Standard_Boolean (HLRBRep_EdgeData::*)() const) &HLRBRep_EdgeData::RgNLine, "None");
cls_HLRBRep_EdgeData.def("RgNLine", (void (HLRBRep_EdgeData::*)(const Standard_Boolean)) &HLRBRep_EdgeData::RgNLine, "None", py::arg("B"));
cls_HLRBRep_EdgeData.def("Vertical", (Standard_Boolean (HLRBRep_EdgeData::*)() const) &HLRBRep_EdgeData::Vertical, "None");
cls_HLRBRep_EdgeData.def("Vertical", (void (HLRBRep_EdgeData::*)(const Standard_Boolean)) &HLRBRep_EdgeData::Vertical, "None", py::arg("B"));
cls_HLRBRep_EdgeData.def("Simple", (Standard_Boolean (HLRBRep_EdgeData::*)() const) &HLRBRep_EdgeData::Simple, "None");
cls_HLRBRep_EdgeData.def("Simple", (void (HLRBRep_EdgeData::*)(const Standard_Boolean)) &HLRBRep_EdgeData::Simple, "None", py::arg("B"));
cls_HLRBRep_EdgeData.def("OutLVSta", (Standard_Boolean (HLRBRep_EdgeData::*)() const) &HLRBRep_EdgeData::OutLVSta, "None");
cls_HLRBRep_EdgeData.def("OutLVSta", (void (HLRBRep_EdgeData::*)(const Standard_Boolean)) &HLRBRep_EdgeData::OutLVSta, "None", py::arg("B"));
cls_HLRBRep_EdgeData.def("OutLVEnd", (Standard_Boolean (HLRBRep_EdgeData::*)() const) &HLRBRep_EdgeData::OutLVEnd, "None");
cls_HLRBRep_EdgeData.def("OutLVEnd", (void (HLRBRep_EdgeData::*)(const Standard_Boolean)) &HLRBRep_EdgeData::OutLVEnd, "None", py::arg("B"));
cls_HLRBRep_EdgeData.def("CutAtSta", (Standard_Boolean (HLRBRep_EdgeData::*)() const) &HLRBRep_EdgeData::CutAtSta, "None");
cls_HLRBRep_EdgeData.def("CutAtSta", (void (HLRBRep_EdgeData::*)(const Standard_Boolean)) &HLRBRep_EdgeData::CutAtSta, "None", py::arg("B"));
cls_HLRBRep_EdgeData.def("CutAtEnd", (Standard_Boolean (HLRBRep_EdgeData::*)() const) &HLRBRep_EdgeData::CutAtEnd, "None");
cls_HLRBRep_EdgeData.def("CutAtEnd", (void (HLRBRep_EdgeData::*)(const Standard_Boolean)) &HLRBRep_EdgeData::CutAtEnd, "None", py::arg("B"));
cls_HLRBRep_EdgeData.def("VerAtSta", (Standard_Boolean (HLRBRep_EdgeData::*)() const) &HLRBRep_EdgeData::VerAtSta, "None");
cls_HLRBRep_EdgeData.def("VerAtSta", (void (HLRBRep_EdgeData::*)(const Standard_Boolean)) &HLRBRep_EdgeData::VerAtSta, "None", py::arg("B"));
cls_HLRBRep_EdgeData.def("VerAtEnd", (Standard_Boolean (HLRBRep_EdgeData::*)() const) &HLRBRep_EdgeData::VerAtEnd, "None");
cls_HLRBRep_EdgeData.def("VerAtEnd", (void (HLRBRep_EdgeData::*)(const Standard_Boolean)) &HLRBRep_EdgeData::VerAtEnd, "None", py::arg("B"));
cls_HLRBRep_EdgeData.def("AutoIntersectionDone", (Standard_Boolean (HLRBRep_EdgeData::*)() const) &HLRBRep_EdgeData::AutoIntersectionDone, "None");
cls_HLRBRep_EdgeData.def("AutoIntersectionDone", (void (HLRBRep_EdgeData::*)(const Standard_Boolean)) &HLRBRep_EdgeData::AutoIntersectionDone, "None", py::arg("B"));
cls_HLRBRep_EdgeData.def("Used", (Standard_Boolean (HLRBRep_EdgeData::*)() const) &HLRBRep_EdgeData::Used, "None");
cls_HLRBRep_EdgeData.def("Used", (void (HLRBRep_EdgeData::*)(const Standard_Boolean)) &HLRBRep_EdgeData::Used, "None", py::arg("B"));
cls_HLRBRep_EdgeData.def("HideCount", (Standard_Integer (HLRBRep_EdgeData::*)() const) &HLRBRep_EdgeData::HideCount, "None");
cls_HLRBRep_EdgeData.def("HideCount", (void (HLRBRep_EdgeData::*)(const Standard_Integer)) &HLRBRep_EdgeData::HideCount, "None", py::arg("I"));
cls_HLRBRep_EdgeData.def("VSta", (Standard_Integer (HLRBRep_EdgeData::*)() const) &HLRBRep_EdgeData::VSta, "None");
cls_HLRBRep_EdgeData.def("VSta", (void (HLRBRep_EdgeData::*)(const Standard_Integer)) &HLRBRep_EdgeData::VSta, "None", py::arg("I"));
cls_HLRBRep_EdgeData.def("VEnd", (Standard_Integer (HLRBRep_EdgeData::*)() const) &HLRBRep_EdgeData::VEnd, "None");
cls_HLRBRep_EdgeData.def("VEnd", (void (HLRBRep_EdgeData::*)(const Standard_Integer)) &HLRBRep_EdgeData::VEnd, "None", py::arg("I"));
cls_HLRBRep_EdgeData.def("UpdateMinMax", (void (HLRBRep_EdgeData::*)(const HLRAlgo_EdgesBlock::MinMaxIndices &)) &HLRBRep_EdgeData::UpdateMinMax, "None", py::arg("theTotMinMax"));
cls_HLRBRep_EdgeData.def("MinMax", (HLRAlgo_EdgesBlock::MinMaxIndices & (HLRBRep_EdgeData::*)()) &HLRBRep_EdgeData::MinMax, "None");
cls_HLRBRep_EdgeData.def("Status", (HLRAlgo_EdgeStatus & (HLRBRep_EdgeData::*)()) &HLRBRep_EdgeData::Status, "None");
cls_HLRBRep_EdgeData.def("ChangeGeometry", (HLRBRep_Curve & (HLRBRep_EdgeData::*)()) &HLRBRep_EdgeData::ChangeGeometry, "None");
cls_HLRBRep_EdgeData.def("Geometry", (const HLRBRep_Curve & (HLRBRep_EdgeData::*)() const) &HLRBRep_EdgeData::Geometry, "None");
cls_HLRBRep_EdgeData.def("Curve", (HLRBRep_Curve * (HLRBRep_EdgeData::*)()) &HLRBRep_EdgeData::Curve, "None");
cls_HLRBRep_EdgeData.def("Tolerance", (Standard_ShortReal (HLRBRep_EdgeData::*)() const) &HLRBRep_EdgeData::Tolerance, "None");

// TYPEDEF: HLRBREP_ARRAY1OFEDATA
bind_NCollection_Array1<HLRBRep_EdgeData>(mod, "HLRBRep_Array1OfEData", py::module_local(false));

// CLASS: HLRBREP_SURFACE
py::class_<HLRBRep_Surface> cls_HLRBRep_Surface(mod, "HLRBRep_Surface", "None");

// Constructors
cls_HLRBRep_Surface.def(py::init<>());

// Methods
// cls_HLRBRep_Surface.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_Surface::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_Surface.def_static("operator delete_", (void (*)(void *)) &HLRBRep_Surface::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_Surface.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_Surface::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_Surface.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_Surface::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_Surface.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_Surface::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_Surface.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_Surface::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_Surface.def("Projector", (void (HLRBRep_Surface::*)(const HLRAlgo_Projector *)) &HLRBRep_Surface::Projector, "None", py::arg("Proj"));
cls_HLRBRep_Surface.def("Surface", (BRepAdaptor_Surface & (HLRBRep_Surface::*)()) &HLRBRep_Surface::Surface, "Returns the 3D Surface.");
cls_HLRBRep_Surface.def("Surface", (void (HLRBRep_Surface::*)(const TopoDS_Face &)) &HLRBRep_Surface::Surface, "Sets the 3D Surface to be projected.", py::arg("F"));
cls_HLRBRep_Surface.def("IsSide", (Standard_Boolean (HLRBRep_Surface::*)(const Standard_Real, const Standard_Real) const) &HLRBRep_Surface::IsSide, "returns true if it is a side face", py::arg("tolf"), py::arg("toler"));
cls_HLRBRep_Surface.def("IsAbove", (Standard_Boolean (HLRBRep_Surface::*)(const Standard_Boolean, const HLRBRep_Curve *, const Standard_Real) const) &HLRBRep_Surface::IsAbove, "None", py::arg("back"), py::arg("A"), py::arg("tolC"));
cls_HLRBRep_Surface.def("FirstUParameter", (Standard_Real (HLRBRep_Surface::*)() const) &HLRBRep_Surface::FirstUParameter, "None");
cls_HLRBRep_Surface.def("LastUParameter", (Standard_Real (HLRBRep_Surface::*)() const) &HLRBRep_Surface::LastUParameter, "None");
cls_HLRBRep_Surface.def("FirstVParameter", (Standard_Real (HLRBRep_Surface::*)() const) &HLRBRep_Surface::FirstVParameter, "None");
cls_HLRBRep_Surface.def("LastVParameter", (Standard_Real (HLRBRep_Surface::*)() const) &HLRBRep_Surface::LastVParameter, "None");
cls_HLRBRep_Surface.def("UContinuity", (GeomAbs_Shape (HLRBRep_Surface::*)() const) &HLRBRep_Surface::UContinuity, "None");
cls_HLRBRep_Surface.def("VContinuity", (GeomAbs_Shape (HLRBRep_Surface::*)() const) &HLRBRep_Surface::VContinuity, "None");
cls_HLRBRep_Surface.def("NbUIntervals", (Standard_Integer (HLRBRep_Surface::*)(const GeomAbs_Shape)) &HLRBRep_Surface::NbUIntervals, "If necessary, breaks the surface in U intervals of continuity <S>. And returns the number of intervals.", py::arg("S"));
cls_HLRBRep_Surface.def("NbVIntervals", (Standard_Integer (HLRBRep_Surface::*)(const GeomAbs_Shape)) &HLRBRep_Surface::NbVIntervals, "If necessary, breaks the surface in V intervals of continuity <S>. And returns the number of intervals.", py::arg("S"));
// cls_HLRBRep_Surface.def("UIntervalContinuity", (GeomAbs_Shape (HLRBRep_Surface::*)() const) &HLRBRep_Surface::UIntervalContinuity, "None");
// cls_HLRBRep_Surface.def("VIntervalContinuity", (GeomAbs_Shape (HLRBRep_Surface::*)() const) &HLRBRep_Surface::VIntervalContinuity, "None");
cls_HLRBRep_Surface.def("IsUClosed", (Standard_Boolean (HLRBRep_Surface::*)() const) &HLRBRep_Surface::IsUClosed, "None");
cls_HLRBRep_Surface.def("IsVClosed", (Standard_Boolean (HLRBRep_Surface::*)() const) &HLRBRep_Surface::IsVClosed, "None");
cls_HLRBRep_Surface.def("IsUPeriodic", (Standard_Boolean (HLRBRep_Surface::*)() const) &HLRBRep_Surface::IsUPeriodic, "None");
cls_HLRBRep_Surface.def("UPeriod", (Standard_Real (HLRBRep_Surface::*)() const) &HLRBRep_Surface::UPeriod, "None");
cls_HLRBRep_Surface.def("IsVPeriodic", (Standard_Boolean (HLRBRep_Surface::*)() const) &HLRBRep_Surface::IsVPeriodic, "None");
cls_HLRBRep_Surface.def("VPeriod", (Standard_Real (HLRBRep_Surface::*)() const) &HLRBRep_Surface::VPeriod, "None");
cls_HLRBRep_Surface.def("Value", (gp_Pnt (HLRBRep_Surface::*)(const Standard_Real, const Standard_Real) const) &HLRBRep_Surface::Value, "Computes the point of parameters U,V on the surface.", py::arg("U"), py::arg("V"));
cls_HLRBRep_Surface.def("D0", (void (HLRBRep_Surface::*)(const Standard_Real, const Standard_Real, gp_Pnt &) const) &HLRBRep_Surface::D0, "Computes the point of parameters U,V on the surface.", py::arg("U"), py::arg("V"), py::arg("P"));
cls_HLRBRep_Surface.def("D1", (void (HLRBRep_Surface::*)(const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &) const) &HLRBRep_Surface::D1, "Computes the point and the first derivatives on the surface. Raised if the continuity of the current intervals is not C1.", py::arg("U"), py::arg("V"), py::arg("P"), py::arg("D1U"), py::arg("D1V"));
cls_HLRBRep_Surface.def("D2", (void (HLRBRep_Surface::*)(const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &) const) &HLRBRep_Surface::D2, "Computes the point, the first and second derivatives on the surface. Raised if the continuity of the current intervals is not C2.", py::arg("U"), py::arg("V"), py::arg("P"), py::arg("D1U"), py::arg("D1V"), py::arg("D2U"), py::arg("D2V"), py::arg("D2UV"));
cls_HLRBRep_Surface.def("D3", (void (HLRBRep_Surface::*)(const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &) const) &HLRBRep_Surface::D3, "Computes the point, the first, second and third derivatives on the surface. Raised if the continuity of the current intervals is not C3.", py::arg("U"), py::arg("V"), py::arg("P"), py::arg("D1U"), py::arg("D1V"), py::arg("D2U"), py::arg("D2V"), py::arg("D2UV"), py::arg("D3U"), py::arg("D3V"), py::arg("D3UUV"), py::arg("D3UVV"));
cls_HLRBRep_Surface.def("DN", (gp_Vec (HLRBRep_Surface::*)(const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Integer) const) &HLRBRep_Surface::DN, "Computes the derivative of order Nu in the direction U and Nv in the direction V at the point P(U, V). Raised if the current U interval is not not CNu and the current V interval is not CNv. Raised if Nu + Nv < 1 or Nu < 0 or Nv < 0.", py::arg("U"), py::arg("V"), py::arg("Nu"), py::arg("Nv"));
cls_HLRBRep_Surface.def("GetType", (GeomAbs_SurfaceType (HLRBRep_Surface::*)() const) &HLRBRep_Surface::GetType, "Returns the type of the surface : Plane, Cylinder, Cone, Sphere, Torus, BezierSurface, BSplineSurface, SurfaceOfRevolution, SurfaceOfExtrusion, OtherSurface");
cls_HLRBRep_Surface.def("Plane", (gp_Pln (HLRBRep_Surface::*)() const) &HLRBRep_Surface::Plane, "None");
cls_HLRBRep_Surface.def("Cylinder", (gp_Cylinder (HLRBRep_Surface::*)() const) &HLRBRep_Surface::Cylinder, "None");
cls_HLRBRep_Surface.def("Cone", (gp_Cone (HLRBRep_Surface::*)() const) &HLRBRep_Surface::Cone, "None");
cls_HLRBRep_Surface.def("Sphere", (gp_Sphere (HLRBRep_Surface::*)() const) &HLRBRep_Surface::Sphere, "None");
cls_HLRBRep_Surface.def("Torus", (gp_Torus (HLRBRep_Surface::*)() const) &HLRBRep_Surface::Torus, "None");
cls_HLRBRep_Surface.def("UDegree", (Standard_Integer (HLRBRep_Surface::*)() const) &HLRBRep_Surface::UDegree, "None");
cls_HLRBRep_Surface.def("NbUPoles", (Standard_Integer (HLRBRep_Surface::*)() const) &HLRBRep_Surface::NbUPoles, "None");
cls_HLRBRep_Surface.def("VDegree", (Standard_Integer (HLRBRep_Surface::*)() const) &HLRBRep_Surface::VDegree, "None");
cls_HLRBRep_Surface.def("NbVPoles", (Standard_Integer (HLRBRep_Surface::*)() const) &HLRBRep_Surface::NbVPoles, "None");
cls_HLRBRep_Surface.def("NbUKnots", (Standard_Integer (HLRBRep_Surface::*)() const) &HLRBRep_Surface::NbUKnots, "None");
cls_HLRBRep_Surface.def("NbVKnots", (Standard_Integer (HLRBRep_Surface::*)() const) &HLRBRep_Surface::NbVKnots, "None");
cls_HLRBRep_Surface.def("Axis", (gp_Ax1 (HLRBRep_Surface::*)() const) &HLRBRep_Surface::Axis, "None");

// CLASS: HLRBREP_BSURFACETOOL
py::class_<HLRBRep_BSurfaceTool> cls_HLRBRep_BSurfaceTool(mod, "HLRBRep_BSurfaceTool", "None");

// Constructors
cls_HLRBRep_BSurfaceTool.def(py::init<>());

// Methods
// cls_HLRBRep_BSurfaceTool.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_BSurfaceTool::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_BSurfaceTool.def_static("operator delete_", (void (*)(void *)) &HLRBRep_BSurfaceTool::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_BSurfaceTool.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_BSurfaceTool::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_BSurfaceTool.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_BSurfaceTool::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_BSurfaceTool.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_BSurfaceTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_BSurfaceTool.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_BSurfaceTool::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_BSurfaceTool.def_static("FirstUParameter_", (Standard_Real (*)(const BRepAdaptor_Surface &)) &HLRBRep_BSurfaceTool::FirstUParameter, "None", py::arg("S"));
cls_HLRBRep_BSurfaceTool.def_static("FirstVParameter_", (Standard_Real (*)(const BRepAdaptor_Surface &)) &HLRBRep_BSurfaceTool::FirstVParameter, "None", py::arg("S"));
cls_HLRBRep_BSurfaceTool.def_static("LastUParameter_", (Standard_Real (*)(const BRepAdaptor_Surface &)) &HLRBRep_BSurfaceTool::LastUParameter, "None", py::arg("S"));
cls_HLRBRep_BSurfaceTool.def_static("LastVParameter_", (Standard_Real (*)(const BRepAdaptor_Surface &)) &HLRBRep_BSurfaceTool::LastVParameter, "None", py::arg("S"));
cls_HLRBRep_BSurfaceTool.def_static("NbUIntervals_", (Standard_Integer (*)(const BRepAdaptor_Surface &, const GeomAbs_Shape)) &HLRBRep_BSurfaceTool::NbUIntervals, "None", py::arg("S"), py::arg("Sh"));
cls_HLRBRep_BSurfaceTool.def_static("NbVIntervals_", (Standard_Integer (*)(const BRepAdaptor_Surface &, const GeomAbs_Shape)) &HLRBRep_BSurfaceTool::NbVIntervals, "None", py::arg("S"), py::arg("Sh"));
cls_HLRBRep_BSurfaceTool.def_static("UIntervals_", (void (*)(const BRepAdaptor_Surface &, TColStd_Array1OfReal &, const GeomAbs_Shape)) &HLRBRep_BSurfaceTool::UIntervals, "None", py::arg("S"), py::arg("T"), py::arg("Sh"));
cls_HLRBRep_BSurfaceTool.def_static("VIntervals_", (void (*)(const BRepAdaptor_Surface &, TColStd_Array1OfReal &, const GeomAbs_Shape)) &HLRBRep_BSurfaceTool::VIntervals, "None", py::arg("S"), py::arg("T"), py::arg("Sh"));
cls_HLRBRep_BSurfaceTool.def_static("UTrim_", (opencascade::handle<Adaptor3d_HSurface> (*)(const BRepAdaptor_Surface &, const Standard_Real, const Standard_Real, const Standard_Real)) &HLRBRep_BSurfaceTool::UTrim, "If <First> >= <Last>", py::arg("S"), py::arg("First"), py::arg("Last"), py::arg("Tol"));
cls_HLRBRep_BSurfaceTool.def_static("VTrim_", (opencascade::handle<Adaptor3d_HSurface> (*)(const BRepAdaptor_Surface &, const Standard_Real, const Standard_Real, const Standard_Real)) &HLRBRep_BSurfaceTool::VTrim, "If <First> >= <Last>", py::arg("S"), py::arg("First"), py::arg("Last"), py::arg("Tol"));
cls_HLRBRep_BSurfaceTool.def_static("IsUClosed_", (Standard_Boolean (*)(const BRepAdaptor_Surface &)) &HLRBRep_BSurfaceTool::IsUClosed, "None", py::arg("S"));
cls_HLRBRep_BSurfaceTool.def_static("IsVClosed_", (Standard_Boolean (*)(const BRepAdaptor_Surface &)) &HLRBRep_BSurfaceTool::IsVClosed, "None", py::arg("S"));
cls_HLRBRep_BSurfaceTool.def_static("IsUPeriodic_", (Standard_Boolean (*)(const BRepAdaptor_Surface &)) &HLRBRep_BSurfaceTool::IsUPeriodic, "None", py::arg("S"));
cls_HLRBRep_BSurfaceTool.def_static("UPeriod_", (Standard_Real (*)(const BRepAdaptor_Surface &)) &HLRBRep_BSurfaceTool::UPeriod, "None", py::arg("S"));
cls_HLRBRep_BSurfaceTool.def_static("IsVPeriodic_", (Standard_Boolean (*)(const BRepAdaptor_Surface &)) &HLRBRep_BSurfaceTool::IsVPeriodic, "None", py::arg("S"));
cls_HLRBRep_BSurfaceTool.def_static("VPeriod_", (Standard_Real (*)(const BRepAdaptor_Surface &)) &HLRBRep_BSurfaceTool::VPeriod, "None", py::arg("S"));
cls_HLRBRep_BSurfaceTool.def_static("Value_", (gp_Pnt (*)(const BRepAdaptor_Surface &, const Standard_Real, const Standard_Real)) &HLRBRep_BSurfaceTool::Value, "None", py::arg("S"), py::arg("u"), py::arg("v"));
cls_HLRBRep_BSurfaceTool.def_static("D0_", (void (*)(const BRepAdaptor_Surface &, const Standard_Real, const Standard_Real, gp_Pnt &)) &HLRBRep_BSurfaceTool::D0, "None", py::arg("S"), py::arg("u"), py::arg("v"), py::arg("P"));
cls_HLRBRep_BSurfaceTool.def_static("D1_", (void (*)(const BRepAdaptor_Surface &, const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &)) &HLRBRep_BSurfaceTool::D1, "None", py::arg("S"), py::arg("u"), py::arg("v"), py::arg("P"), py::arg("D1u"), py::arg("D1v"));
cls_HLRBRep_BSurfaceTool.def_static("D2_", (void (*)(const BRepAdaptor_Surface &, const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &)) &HLRBRep_BSurfaceTool::D2, "None", py::arg("S"), py::arg("u"), py::arg("v"), py::arg("P"), py::arg("D1U"), py::arg("D1V"), py::arg("D2U"), py::arg("D2V"), py::arg("D2UV"));
cls_HLRBRep_BSurfaceTool.def_static("D3_", (void (*)(const BRepAdaptor_Surface &, const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &)) &HLRBRep_BSurfaceTool::D3, "None", py::arg("S"), py::arg("u"), py::arg("v"), py::arg("P"), py::arg("D1U"), py::arg("D1V"), py::arg("D2U"), py::arg("D2V"), py::arg("D2UV"), py::arg("D3U"), py::arg("D3V"), py::arg("D3UUV"), py::arg("D3UVV"));
cls_HLRBRep_BSurfaceTool.def_static("DN_", (gp_Vec (*)(const BRepAdaptor_Surface &, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Integer)) &HLRBRep_BSurfaceTool::DN, "None", py::arg("S"), py::arg("u"), py::arg("v"), py::arg("Nu"), py::arg("Nv"));
cls_HLRBRep_BSurfaceTool.def_static("UContinuity_", (GeomAbs_Shape (*)(const BRepAdaptor_Surface &)) &HLRBRep_BSurfaceTool::UContinuity, "None", py::arg("S"));
cls_HLRBRep_BSurfaceTool.def_static("VContinuity_", (GeomAbs_Shape (*)(const BRepAdaptor_Surface &)) &HLRBRep_BSurfaceTool::VContinuity, "None", py::arg("S"));
cls_HLRBRep_BSurfaceTool.def_static("UDegree_", (Standard_Integer (*)(const BRepAdaptor_Surface &)) &HLRBRep_BSurfaceTool::UDegree, "None", py::arg("S"));
cls_HLRBRep_BSurfaceTool.def_static("NbUPoles_", (Standard_Integer (*)(const BRepAdaptor_Surface &)) &HLRBRep_BSurfaceTool::NbUPoles, "None", py::arg("S"));
cls_HLRBRep_BSurfaceTool.def_static("NbUKnots_", (Standard_Integer (*)(const BRepAdaptor_Surface &)) &HLRBRep_BSurfaceTool::NbUKnots, "None", py::arg("S"));
cls_HLRBRep_BSurfaceTool.def_static("IsURational_", (Standard_Boolean (*)(const BRepAdaptor_Surface &)) &HLRBRep_BSurfaceTool::IsURational, "None", py::arg("S"));
cls_HLRBRep_BSurfaceTool.def_static("VDegree_", (Standard_Integer (*)(const BRepAdaptor_Surface &)) &HLRBRep_BSurfaceTool::VDegree, "None", py::arg("S"));
cls_HLRBRep_BSurfaceTool.def_static("NbVPoles_", (Standard_Integer (*)(const BRepAdaptor_Surface &)) &HLRBRep_BSurfaceTool::NbVPoles, "None", py::arg("S"));
cls_HLRBRep_BSurfaceTool.def_static("NbVKnots_", (Standard_Integer (*)(const BRepAdaptor_Surface &)) &HLRBRep_BSurfaceTool::NbVKnots, "None", py::arg("S"));
cls_HLRBRep_BSurfaceTool.def_static("IsVRational_", (Standard_Boolean (*)(const BRepAdaptor_Surface &)) &HLRBRep_BSurfaceTool::IsVRational, "None", py::arg("S"));
cls_HLRBRep_BSurfaceTool.def_static("UResolution_", (Standard_Real (*)(const BRepAdaptor_Surface &, const Standard_Real)) &HLRBRep_BSurfaceTool::UResolution, "None", py::arg("S"), py::arg("R3d"));
cls_HLRBRep_BSurfaceTool.def_static("VResolution_", (Standard_Real (*)(const BRepAdaptor_Surface &, const Standard_Real)) &HLRBRep_BSurfaceTool::VResolution, "None", py::arg("S"), py::arg("R3d"));
cls_HLRBRep_BSurfaceTool.def_static("GetType_", (GeomAbs_SurfaceType (*)(const BRepAdaptor_Surface &)) &HLRBRep_BSurfaceTool::GetType, "None", py::arg("S"));
cls_HLRBRep_BSurfaceTool.def_static("Plane_", (gp_Pln (*)(const BRepAdaptor_Surface &)) &HLRBRep_BSurfaceTool::Plane, "None", py::arg("S"));
cls_HLRBRep_BSurfaceTool.def_static("Cylinder_", (gp_Cylinder (*)(const BRepAdaptor_Surface &)) &HLRBRep_BSurfaceTool::Cylinder, "None", py::arg("S"));
cls_HLRBRep_BSurfaceTool.def_static("Cone_", (gp_Cone (*)(const BRepAdaptor_Surface &)) &HLRBRep_BSurfaceTool::Cone, "None", py::arg("S"));
cls_HLRBRep_BSurfaceTool.def_static("Torus_", (gp_Torus (*)(const BRepAdaptor_Surface &)) &HLRBRep_BSurfaceTool::Torus, "None", py::arg("S"));
cls_HLRBRep_BSurfaceTool.def_static("Sphere_", (gp_Sphere (*)(const BRepAdaptor_Surface &)) &HLRBRep_BSurfaceTool::Sphere, "None", py::arg("S"));
cls_HLRBRep_BSurfaceTool.def_static("Bezier_", (opencascade::handle<Geom_BezierSurface> (*)(const BRepAdaptor_Surface &)) &HLRBRep_BSurfaceTool::Bezier, "None", py::arg("S"));
cls_HLRBRep_BSurfaceTool.def_static("BSpline_", (opencascade::handle<Geom_BSplineSurface> (*)(const BRepAdaptor_Surface &)) &HLRBRep_BSurfaceTool::BSpline, "None", py::arg("S"));
cls_HLRBRep_BSurfaceTool.def_static("AxeOfRevolution_", (gp_Ax1 (*)(const BRepAdaptor_Surface &)) &HLRBRep_BSurfaceTool::AxeOfRevolution, "None", py::arg("S"));
cls_HLRBRep_BSurfaceTool.def_static("Direction_", (gp_Dir (*)(const BRepAdaptor_Surface &)) &HLRBRep_BSurfaceTool::Direction, "None", py::arg("S"));
cls_HLRBRep_BSurfaceTool.def_static("BasisCurve_", (opencascade::handle<Adaptor3d_HCurve> (*)(const BRepAdaptor_Surface &)) &HLRBRep_BSurfaceTool::BasisCurve, "None", py::arg("S"));
// cls_HLRBRep_BSurfaceTool.def_static("Axis_", (gp_Ax1 (*)(const BRepAdaptor_Surface &)) &HLRBRep_BSurfaceTool::Axis, "None", py::arg("S"));
cls_HLRBRep_BSurfaceTool.def_static("NbSamplesU_", (Standard_Integer (*)(const BRepAdaptor_Surface &)) &HLRBRep_BSurfaceTool::NbSamplesU, "None", py::arg("S"));
cls_HLRBRep_BSurfaceTool.def_static("NbSamplesV_", (Standard_Integer (*)(const BRepAdaptor_Surface &)) &HLRBRep_BSurfaceTool::NbSamplesV, "None", py::arg("S"));
cls_HLRBRep_BSurfaceTool.def_static("NbSamplesU_", (Standard_Integer (*)(const BRepAdaptor_Surface &, const Standard_Real, const Standard_Real)) &HLRBRep_BSurfaceTool::NbSamplesU, "None", py::arg("S"), py::arg("u1"), py::arg("u2"));
cls_HLRBRep_BSurfaceTool.def_static("NbSamplesV_", (Standard_Integer (*)(const BRepAdaptor_Surface &, const Standard_Real, const Standard_Real)) &HLRBRep_BSurfaceTool::NbSamplesV, "None", py::arg("S"), py::arg("v1"), py::arg("v2"));

// CLASS: HLRBREP_FACEDATA
py::class_<HLRBRep_FaceData> cls_HLRBRep_FaceData(mod, "HLRBRep_FaceData", "None");

// Constructors
cls_HLRBRep_FaceData.def(py::init<>());

// Methods
// cls_HLRBRep_FaceData.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_FaceData::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_FaceData.def_static("operator delete_", (void (*)(void *)) &HLRBRep_FaceData::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_FaceData.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_FaceData::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_FaceData.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_FaceData::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_FaceData.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_FaceData::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_FaceData.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_FaceData::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_FaceData.def("Set", (void (HLRBRep_FaceData::*)(const TopoDS_Face &, const TopAbs_Orientation, const Standard_Boolean, const Standard_Integer)) &HLRBRep_FaceData::Set, "<Or> is the orientation of the face. <Cl> is true if the face belongs to a closed volume. <NW> is the number of wires ( or block of edges ) of the face.", py::arg("FG"), py::arg("Or"), py::arg("Cl"), py::arg("NW"));
cls_HLRBRep_FaceData.def("SetWire", (void (HLRBRep_FaceData::*)(const Standard_Integer, const Standard_Integer)) &HLRBRep_FaceData::SetWire, "Set <NE> the number of edges of the wire number <WI>.", py::arg("WI"), py::arg("NE"));
cls_HLRBRep_FaceData.def("SetWEdge", (void (HLRBRep_FaceData::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer, const TopAbs_Orientation, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean)) &HLRBRep_FaceData::SetWEdge, "Set the edge number <EWI> of the wire <WI>.", py::arg("WI"), py::arg("EWI"), py::arg("EI"), py::arg("Or"), py::arg("OutL"), py::arg("Inte"), py::arg("Dble"), py::arg("IsoL"));
cls_HLRBRep_FaceData.def("Selected", (Standard_Boolean (HLRBRep_FaceData::*)() const) &HLRBRep_FaceData::Selected, "None");
cls_HLRBRep_FaceData.def("Selected", (void (HLRBRep_FaceData::*)(const Standard_Boolean)) &HLRBRep_FaceData::Selected, "None", py::arg("B"));
cls_HLRBRep_FaceData.def("Back", (Standard_Boolean (HLRBRep_FaceData::*)() const) &HLRBRep_FaceData::Back, "None");
cls_HLRBRep_FaceData.def("Back", (void (HLRBRep_FaceData::*)(const Standard_Boolean)) &HLRBRep_FaceData::Back, "None", py::arg("B"));
cls_HLRBRep_FaceData.def("Side", (Standard_Boolean (HLRBRep_FaceData::*)() const) &HLRBRep_FaceData::Side, "None");
cls_HLRBRep_FaceData.def("Side", (void (HLRBRep_FaceData::*)(const Standard_Boolean)) &HLRBRep_FaceData::Side, "None", py::arg("B"));
cls_HLRBRep_FaceData.def("Closed", (Standard_Boolean (HLRBRep_FaceData::*)() const) &HLRBRep_FaceData::Closed, "None");
cls_HLRBRep_FaceData.def("Closed", (void (HLRBRep_FaceData::*)(const Standard_Boolean)) &HLRBRep_FaceData::Closed, "None", py::arg("B"));
cls_HLRBRep_FaceData.def("Hiding", (Standard_Boolean (HLRBRep_FaceData::*)() const) &HLRBRep_FaceData::Hiding, "None");
cls_HLRBRep_FaceData.def("Hiding", (void (HLRBRep_FaceData::*)(const Standard_Boolean)) &HLRBRep_FaceData::Hiding, "None", py::arg("B"));
cls_HLRBRep_FaceData.def("Simple", (Standard_Boolean (HLRBRep_FaceData::*)() const) &HLRBRep_FaceData::Simple, "None");
cls_HLRBRep_FaceData.def("Simple", (void (HLRBRep_FaceData::*)(const Standard_Boolean)) &HLRBRep_FaceData::Simple, "None", py::arg("B"));
cls_HLRBRep_FaceData.def("Cut", (Standard_Boolean (HLRBRep_FaceData::*)() const) &HLRBRep_FaceData::Cut, "None");
cls_HLRBRep_FaceData.def("Cut", (void (HLRBRep_FaceData::*)(const Standard_Boolean)) &HLRBRep_FaceData::Cut, "None", py::arg("B"));
cls_HLRBRep_FaceData.def("WithOutL", (Standard_Boolean (HLRBRep_FaceData::*)() const) &HLRBRep_FaceData::WithOutL, "None");
cls_HLRBRep_FaceData.def("WithOutL", (void (HLRBRep_FaceData::*)(const Standard_Boolean)) &HLRBRep_FaceData::WithOutL, "None", py::arg("B"));
cls_HLRBRep_FaceData.def("Plane", (Standard_Boolean (HLRBRep_FaceData::*)() const) &HLRBRep_FaceData::Plane, "None");
cls_HLRBRep_FaceData.def("Plane", (void (HLRBRep_FaceData::*)(const Standard_Boolean)) &HLRBRep_FaceData::Plane, "None", py::arg("B"));
cls_HLRBRep_FaceData.def("Cylinder", (Standard_Boolean (HLRBRep_FaceData::*)() const) &HLRBRep_FaceData::Cylinder, "None");
cls_HLRBRep_FaceData.def("Cylinder", (void (HLRBRep_FaceData::*)(const Standard_Boolean)) &HLRBRep_FaceData::Cylinder, "None", py::arg("B"));
cls_HLRBRep_FaceData.def("Cone", (Standard_Boolean (HLRBRep_FaceData::*)() const) &HLRBRep_FaceData::Cone, "None");
cls_HLRBRep_FaceData.def("Cone", (void (HLRBRep_FaceData::*)(const Standard_Boolean)) &HLRBRep_FaceData::Cone, "None", py::arg("B"));
cls_HLRBRep_FaceData.def("Sphere", (Standard_Boolean (HLRBRep_FaceData::*)() const) &HLRBRep_FaceData::Sphere, "None");
cls_HLRBRep_FaceData.def("Sphere", (void (HLRBRep_FaceData::*)(const Standard_Boolean)) &HLRBRep_FaceData::Sphere, "None", py::arg("B"));
cls_HLRBRep_FaceData.def("Torus", (Standard_Boolean (HLRBRep_FaceData::*)() const) &HLRBRep_FaceData::Torus, "None");
cls_HLRBRep_FaceData.def("Torus", (void (HLRBRep_FaceData::*)(const Standard_Boolean)) &HLRBRep_FaceData::Torus, "None", py::arg("B"));
cls_HLRBRep_FaceData.def("Size", (Standard_Real (HLRBRep_FaceData::*)() const) &HLRBRep_FaceData::Size, "None");
cls_HLRBRep_FaceData.def("Size", (void (HLRBRep_FaceData::*)(const Standard_Real)) &HLRBRep_FaceData::Size, "None", py::arg("S"));
cls_HLRBRep_FaceData.def("Orientation", (TopAbs_Orientation (HLRBRep_FaceData::*)() const) &HLRBRep_FaceData::Orientation, "None");
cls_HLRBRep_FaceData.def("Orientation", (void (HLRBRep_FaceData::*)(const TopAbs_Orientation)) &HLRBRep_FaceData::Orientation, "None", py::arg("O"));
cls_HLRBRep_FaceData.def("Wires", (opencascade::handle<HLRAlgo_WiresBlock> & (HLRBRep_FaceData::*)()) &HLRBRep_FaceData::Wires, "None");
cls_HLRBRep_FaceData.def("Geometry", (HLRBRep_Surface & (HLRBRep_FaceData::*)()) &HLRBRep_FaceData::Geometry, "None");
cls_HLRBRep_FaceData.def("Tolerance", (Standard_ShortReal (HLRBRep_FaceData::*)() const) &HLRBRep_FaceData::Tolerance, "None");

// TYPEDEF: HLRBREP_ARRAY1OFFDATA
bind_NCollection_Array1<HLRBRep_FaceData>(mod, "HLRBRep_Array1OfFData", py::module_local(false));

// CLASS: HLRBREP_BIPNT2D
py::class_<HLRBRep_BiPnt2D> cls_HLRBRep_BiPnt2D(mod, "HLRBRep_BiPnt2D", "Contains the colors of a shape.");

// Constructors
cls_HLRBRep_BiPnt2D.def(py::init<>());
cls_HLRBRep_BiPnt2D.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const TopoDS_Shape &, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean>(), py::arg("x1"), py::arg("y1"), py::arg("x2"), py::arg("y2"), py::arg("S"), py::arg("reg1"), py::arg("regn"), py::arg("outl"), py::arg("intl"));
cls_HLRBRep_BiPnt2D.def(py::init<const gp_XY &, const gp_XY &, const TopoDS_Shape &, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean>(), py::arg("thePoint1"), py::arg("thePoint2"), py::arg("S"), py::arg("reg1"), py::arg("regn"), py::arg("outl"), py::arg("intl"));

// Methods
// cls_HLRBRep_BiPnt2D.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_BiPnt2D::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_BiPnt2D.def_static("operator delete_", (void (*)(void *)) &HLRBRep_BiPnt2D::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_BiPnt2D.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_BiPnt2D::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_BiPnt2D.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_BiPnt2D::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_BiPnt2D.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_BiPnt2D::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_BiPnt2D.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_BiPnt2D::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_BiPnt2D.def("P1", (const gp_Pnt2d & (HLRBRep_BiPnt2D::*)() const) &HLRBRep_BiPnt2D::P1, "None");
cls_HLRBRep_BiPnt2D.def("P2", (const gp_Pnt2d & (HLRBRep_BiPnt2D::*)() const) &HLRBRep_BiPnt2D::P2, "None");
cls_HLRBRep_BiPnt2D.def("Shape", (const TopoDS_Shape & (HLRBRep_BiPnt2D::*)() const) &HLRBRep_BiPnt2D::Shape, "None");
cls_HLRBRep_BiPnt2D.def("Shape", (void (HLRBRep_BiPnt2D::*)(const TopoDS_Shape &)) &HLRBRep_BiPnt2D::Shape, "None", py::arg("S"));
cls_HLRBRep_BiPnt2D.def("Rg1Line", (Standard_Boolean (HLRBRep_BiPnt2D::*)() const) &HLRBRep_BiPnt2D::Rg1Line, "None");
cls_HLRBRep_BiPnt2D.def("Rg1Line", (void (HLRBRep_BiPnt2D::*)(const Standard_Boolean)) &HLRBRep_BiPnt2D::Rg1Line, "None", py::arg("B"));
cls_HLRBRep_BiPnt2D.def("RgNLine", (Standard_Boolean (HLRBRep_BiPnt2D::*)() const) &HLRBRep_BiPnt2D::RgNLine, "None");
cls_HLRBRep_BiPnt2D.def("RgNLine", (void (HLRBRep_BiPnt2D::*)(const Standard_Boolean)) &HLRBRep_BiPnt2D::RgNLine, "None", py::arg("B"));
cls_HLRBRep_BiPnt2D.def("OutLine", (Standard_Boolean (HLRBRep_BiPnt2D::*)() const) &HLRBRep_BiPnt2D::OutLine, "None");
cls_HLRBRep_BiPnt2D.def("OutLine", (void (HLRBRep_BiPnt2D::*)(const Standard_Boolean)) &HLRBRep_BiPnt2D::OutLine, "None", py::arg("B"));
cls_HLRBRep_BiPnt2D.def("IntLine", (Standard_Boolean (HLRBRep_BiPnt2D::*)() const) &HLRBRep_BiPnt2D::IntLine, "None");
cls_HLRBRep_BiPnt2D.def("IntLine", (void (HLRBRep_BiPnt2D::*)(const Standard_Boolean)) &HLRBRep_BiPnt2D::IntLine, "None", py::arg("B"));

// CLASS: HLRBREP_BIPOINT
py::class_<HLRBRep_BiPoint> cls_HLRBRep_BiPoint(mod, "HLRBRep_BiPoint", "Contains the colors of a shape.");

// Constructors
cls_HLRBRep_BiPoint.def(py::init<>());
cls_HLRBRep_BiPoint.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const TopoDS_Shape &, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean>(), py::arg("x1"), py::arg("y1"), py::arg("z1"), py::arg("x2"), py::arg("y2"), py::arg("z2"), py::arg("S"), py::arg("reg1"), py::arg("regn"), py::arg("outl"), py::arg("intl"));

// Methods
// cls_HLRBRep_BiPoint.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_BiPoint::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_BiPoint.def_static("operator delete_", (void (*)(void *)) &HLRBRep_BiPoint::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_BiPoint.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_BiPoint::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_BiPoint.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_BiPoint::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_BiPoint.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_BiPoint::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_BiPoint.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_BiPoint::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_BiPoint.def("P1", (const gp_Pnt & (HLRBRep_BiPoint::*)() const) &HLRBRep_BiPoint::P1, "None");
cls_HLRBRep_BiPoint.def("P2", (const gp_Pnt & (HLRBRep_BiPoint::*)() const) &HLRBRep_BiPoint::P2, "None");
cls_HLRBRep_BiPoint.def("Shape", (const TopoDS_Shape & (HLRBRep_BiPoint::*)() const) &HLRBRep_BiPoint::Shape, "None");
cls_HLRBRep_BiPoint.def("Shape", (void (HLRBRep_BiPoint::*)(const TopoDS_Shape &)) &HLRBRep_BiPoint::Shape, "None", py::arg("S"));
cls_HLRBRep_BiPoint.def("Rg1Line", (Standard_Boolean (HLRBRep_BiPoint::*)() const) &HLRBRep_BiPoint::Rg1Line, "None");
cls_HLRBRep_BiPoint.def("Rg1Line", (void (HLRBRep_BiPoint::*)(const Standard_Boolean)) &HLRBRep_BiPoint::Rg1Line, "None", py::arg("B"));
cls_HLRBRep_BiPoint.def("RgNLine", (Standard_Boolean (HLRBRep_BiPoint::*)() const) &HLRBRep_BiPoint::RgNLine, "None");
cls_HLRBRep_BiPoint.def("RgNLine", (void (HLRBRep_BiPoint::*)(const Standard_Boolean)) &HLRBRep_BiPoint::RgNLine, "None", py::arg("B"));
cls_HLRBRep_BiPoint.def("OutLine", (Standard_Boolean (HLRBRep_BiPoint::*)() const) &HLRBRep_BiPoint::OutLine, "None");
cls_HLRBRep_BiPoint.def("OutLine", (void (HLRBRep_BiPoint::*)(const Standard_Boolean)) &HLRBRep_BiPoint::OutLine, "None", py::arg("B"));
cls_HLRBRep_BiPoint.def("IntLine", (Standard_Boolean (HLRBRep_BiPoint::*)() const) &HLRBRep_BiPoint::IntLine, "None");
cls_HLRBRep_BiPoint.def("IntLine", (void (HLRBRep_BiPoint::*)(const Standard_Boolean)) &HLRBRep_BiPoint::IntLine, "None", py::arg("B"));

// CLASS: HLRBREP_THEINTCONICCURVEOFCINTER
py::class_<HLRBRep_TheIntConicCurveOfCInter, IntRes2d_Intersection> cls_HLRBRep_TheIntConicCurveOfCInter(mod, "HLRBRep_TheIntConicCurveOfCInter", "None");

// Constructors
cls_HLRBRep_TheIntConicCurveOfCInter.def(py::init<>());
cls_HLRBRep_TheIntConicCurveOfCInter.def(py::init<const gp_Lin2d &, const IntRes2d_Domain &, const Standard_Address &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real>(), py::arg("L"), py::arg("D1"), py::arg("PCurve"), py::arg("D2"), py::arg("TolConf"), py::arg("Tol"));
cls_HLRBRep_TheIntConicCurveOfCInter.def(py::init<const gp_Circ2d &, const IntRes2d_Domain &, const Standard_Address &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("D1"), py::arg("PCurve"), py::arg("D2"), py::arg("TolConf"), py::arg("Tol"));
cls_HLRBRep_TheIntConicCurveOfCInter.def(py::init<const gp_Elips2d &, const IntRes2d_Domain &, const Standard_Address &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real>(), py::arg("E"), py::arg("D1"), py::arg("PCurve"), py::arg("D2"), py::arg("TolConf"), py::arg("Tol"));
cls_HLRBRep_TheIntConicCurveOfCInter.def(py::init<const gp_Parab2d &, const IntRes2d_Domain &, const Standard_Address &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real>(), py::arg("Prb"), py::arg("D1"), py::arg("PCurve"), py::arg("D2"), py::arg("TolConf"), py::arg("Tol"));
cls_HLRBRep_TheIntConicCurveOfCInter.def(py::init<const gp_Hypr2d &, const IntRes2d_Domain &, const Standard_Address &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real>(), py::arg("H"), py::arg("D1"), py::arg("PCurve"), py::arg("D2"), py::arg("TolConf"), py::arg("Tol"));

// Methods
// cls_HLRBRep_TheIntConicCurveOfCInter.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_TheIntConicCurveOfCInter::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_TheIntConicCurveOfCInter.def_static("operator delete_", (void (*)(void *)) &HLRBRep_TheIntConicCurveOfCInter::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_TheIntConicCurveOfCInter.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_TheIntConicCurveOfCInter::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_TheIntConicCurveOfCInter.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_TheIntConicCurveOfCInter::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_TheIntConicCurveOfCInter.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_TheIntConicCurveOfCInter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_TheIntConicCurveOfCInter.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_TheIntConicCurveOfCInter::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_TheIntConicCurveOfCInter.def("Perform", (void (HLRBRep_TheIntConicCurveOfCInter::*)(const gp_Lin2d &, const IntRes2d_Domain &, const Standard_Address &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real)) &HLRBRep_TheIntConicCurveOfCInter::Perform, "Intersection between a line and a parametric curve.", py::arg("L"), py::arg("D1"), py::arg("PCurve"), py::arg("D2"), py::arg("TolConf"), py::arg("Tol"));
cls_HLRBRep_TheIntConicCurveOfCInter.def("Perform", (void (HLRBRep_TheIntConicCurveOfCInter::*)(const gp_Circ2d &, const IntRes2d_Domain &, const Standard_Address &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real)) &HLRBRep_TheIntConicCurveOfCInter::Perform, "Intersection between a line and a parametric curve.", py::arg("C"), py::arg("D1"), py::arg("PCurve"), py::arg("D2"), py::arg("TolConf"), py::arg("Tol"));
cls_HLRBRep_TheIntConicCurveOfCInter.def("Perform", (void (HLRBRep_TheIntConicCurveOfCInter::*)(const gp_Elips2d &, const IntRes2d_Domain &, const Standard_Address &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real)) &HLRBRep_TheIntConicCurveOfCInter::Perform, "Intersection between an ellipse and a parametric curve.", py::arg("E"), py::arg("D1"), py::arg("PCurve"), py::arg("D2"), py::arg("TolConf"), py::arg("Tol"));
cls_HLRBRep_TheIntConicCurveOfCInter.def("Perform", (void (HLRBRep_TheIntConicCurveOfCInter::*)(const gp_Parab2d &, const IntRes2d_Domain &, const Standard_Address &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real)) &HLRBRep_TheIntConicCurveOfCInter::Perform, "Intersection between a parabola and a parametric curve.", py::arg("Prb"), py::arg("D1"), py::arg("PCurve"), py::arg("D2"), py::arg("TolConf"), py::arg("Tol"));
cls_HLRBRep_TheIntConicCurveOfCInter.def("Perform", (void (HLRBRep_TheIntConicCurveOfCInter::*)(const gp_Hypr2d &, const IntRes2d_Domain &, const Standard_Address &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real)) &HLRBRep_TheIntConicCurveOfCInter::Perform, "Intersection between the main branch of an hyperbola and a parametric curve.", py::arg("H"), py::arg("D1"), py::arg("PCurve"), py::arg("D2"), py::arg("TolConf"), py::arg("Tol"));

// CLASS: HLRBREP_THEINTERSECTOROFTHEINTCONICCURVEOFCINTER
py::class_<HLRBRep_TheIntersectorOfTheIntConicCurveOfCInter, IntRes2d_Intersection> cls_HLRBRep_TheIntersectorOfTheIntConicCurveOfCInter(mod, "HLRBRep_TheIntersectorOfTheIntConicCurveOfCInter", "None");

// Constructors
cls_HLRBRep_TheIntersectorOfTheIntConicCurveOfCInter.def(py::init<>());
cls_HLRBRep_TheIntersectorOfTheIntConicCurveOfCInter.def(py::init<const IntCurve_IConicTool &, const IntRes2d_Domain &, const Standard_Address &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real>(), py::arg("ITool"), py::arg("Dom1"), py::arg("PCurve"), py::arg("Dom2"), py::arg("TolConf"), py::arg("Tol"));

// Methods
// cls_HLRBRep_TheIntersectorOfTheIntConicCurveOfCInter.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_TheIntersectorOfTheIntConicCurveOfCInter::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_TheIntersectorOfTheIntConicCurveOfCInter.def_static("operator delete_", (void (*)(void *)) &HLRBRep_TheIntersectorOfTheIntConicCurveOfCInter::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_TheIntersectorOfTheIntConicCurveOfCInter.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_TheIntersectorOfTheIntConicCurveOfCInter::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_TheIntersectorOfTheIntConicCurveOfCInter.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_TheIntersectorOfTheIntConicCurveOfCInter::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_TheIntersectorOfTheIntConicCurveOfCInter.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_TheIntersectorOfTheIntConicCurveOfCInter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_TheIntersectorOfTheIntConicCurveOfCInter.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_TheIntersectorOfTheIntConicCurveOfCInter::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_TheIntersectorOfTheIntConicCurveOfCInter.def("Perform", (void (HLRBRep_TheIntersectorOfTheIntConicCurveOfCInter::*)(const IntCurve_IConicTool &, const IntRes2d_Domain &, const Standard_Address &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real)) &HLRBRep_TheIntersectorOfTheIntConicCurveOfCInter::Perform, "Intersection between an implicit curve and a parametrised curve. The exception ConstructionError is raised if the domain of the parametrised curve does not verify HasFirstPoint and HasLastPoint return True.", py::arg("ITool"), py::arg("Dom1"), py::arg("PCurve"), py::arg("Dom2"), py::arg("TolConf"), py::arg("Tol"));
cls_HLRBRep_TheIntersectorOfTheIntConicCurveOfCInter.def("FindU", (Standard_Real (HLRBRep_TheIntersectorOfTheIntConicCurveOfCInter::*)(const Standard_Real, gp_Pnt2d &, const Standard_Address &, const IntCurve_IConicTool &) const) &HLRBRep_TheIntersectorOfTheIntConicCurveOfCInter::FindU, "None", py::arg("parameter"), py::arg("point"), py::arg("TheParCurev"), py::arg("IntCurve_IConicTool"));
cls_HLRBRep_TheIntersectorOfTheIntConicCurveOfCInter.def("FindV", (Standard_Real (HLRBRep_TheIntersectorOfTheIntConicCurveOfCInter::*)(const Standard_Real, gp_Pnt2d &, const IntCurve_IConicTool &, const Standard_Address &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real, const Standard_Real) const) &HLRBRep_TheIntersectorOfTheIntConicCurveOfCInter::FindV, "None", py::arg("parameter"), py::arg("point"), py::arg("IntCurve_IConicTool"), py::arg("ParCurve"), py::arg("TheParCurveDomain"), py::arg("V0"), py::arg("V1"), py::arg("Tolerance"));
cls_HLRBRep_TheIntersectorOfTheIntConicCurveOfCInter.def("And_Domaine_Objet1_Intersections", [](HLRBRep_TheIntersectorOfTheIntConicCurveOfCInter &self, const IntCurve_IConicTool & IntCurve_IConicTool, const Standard_Address & TheParCurve, const IntRes2d_Domain & TheImpCurveDomain, const IntRes2d_Domain & TheParCurveDomain, Standard_Integer & NbResultats, TColStd_Array1OfReal & Inter2_And_Domain2, TColStd_Array1OfReal & Inter1, TColStd_Array1OfReal & Resultat1, TColStd_Array1OfReal & Resultat2, const Standard_Real EpsNul){ self.And_Domaine_Objet1_Intersections(IntCurve_IConicTool, TheParCurve, TheImpCurveDomain, TheParCurveDomain, NbResultats, Inter2_And_Domain2, Inter1, Resultat1, Resultat2, EpsNul); return NbResultats; }, "None", py::arg("IntCurve_IConicTool"), py::arg("TheParCurve"), py::arg("TheImpCurveDomain"), py::arg("TheParCurveDomain"), py::arg("NbResultats"), py::arg("Inter2_And_Domain2"), py::arg("Inter1"), py::arg("Resultat1"), py::arg("Resultat2"), py::arg("EpsNul"));

// CLASS: HLRBREP_THEINTPCURVEPCURVEOFCINTER
py::class_<HLRBRep_TheIntPCurvePCurveOfCInter, IntRes2d_Intersection> cls_HLRBRep_TheIntPCurvePCurveOfCInter(mod, "HLRBRep_TheIntPCurvePCurveOfCInter", "None");

// Constructors
cls_HLRBRep_TheIntPCurvePCurveOfCInter.def(py::init<>());

// Methods
// cls_HLRBRep_TheIntPCurvePCurveOfCInter.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_TheIntPCurvePCurveOfCInter::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_TheIntPCurvePCurveOfCInter.def_static("operator delete_", (void (*)(void *)) &HLRBRep_TheIntPCurvePCurveOfCInter::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_TheIntPCurvePCurveOfCInter.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_TheIntPCurvePCurveOfCInter::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_TheIntPCurvePCurveOfCInter.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_TheIntPCurvePCurveOfCInter::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_TheIntPCurvePCurveOfCInter.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_TheIntPCurvePCurveOfCInter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_TheIntPCurvePCurveOfCInter.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_TheIntPCurvePCurveOfCInter::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_TheIntPCurvePCurveOfCInter.def("Perform", (void (HLRBRep_TheIntPCurvePCurveOfCInter::*)(const Standard_Address &, const IntRes2d_Domain &, const Standard_Address &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real)) &HLRBRep_TheIntPCurvePCurveOfCInter::Perform, "None", py::arg("Curve1"), py::arg("Domain1"), py::arg("Curve2"), py::arg("Domain2"), py::arg("TolConf"), py::arg("Tol"));
cls_HLRBRep_TheIntPCurvePCurveOfCInter.def("Perform", (void (HLRBRep_TheIntPCurvePCurveOfCInter::*)(const Standard_Address &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real)) &HLRBRep_TheIntPCurvePCurveOfCInter::Perform, "None", py::arg("Curve1"), py::arg("Domain1"), py::arg("TolConf"), py::arg("Tol"));
cls_HLRBRep_TheIntPCurvePCurveOfCInter.def("SetMinNbSamples", (void (HLRBRep_TheIntPCurvePCurveOfCInter::*)(const Standard_Integer)) &HLRBRep_TheIntPCurvePCurveOfCInter::SetMinNbSamples, "Set / get minimum number of points in polygon for intersection.", py::arg("theMinNbSamples"));
cls_HLRBRep_TheIntPCurvePCurveOfCInter.def("GetMinNbSamples", (Standard_Integer (HLRBRep_TheIntPCurvePCurveOfCInter::*)() const) &HLRBRep_TheIntPCurvePCurveOfCInter::GetMinNbSamples, "None");

// CLASS: HLRBREP_CINTER
py::class_<HLRBRep_CInter, IntRes2d_Intersection> cls_HLRBRep_CInter(mod, "HLRBRep_CInter", "None");

// Constructors
cls_HLRBRep_CInter.def(py::init<>());
cls_HLRBRep_CInter.def(py::init<const Standard_Address &, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("TolConf"), py::arg("Tol"));
cls_HLRBRep_CInter.def(py::init<const Standard_Address &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("D"), py::arg("TolConf"), py::arg("Tol"));
cls_HLRBRep_CInter.def(py::init<const Standard_Address &, const Standard_Address &, const Standard_Real, const Standard_Real>(), py::arg("C1"), py::arg("C2"), py::arg("TolConf"), py::arg("Tol"));
cls_HLRBRep_CInter.def(py::init<const Standard_Address &, const IntRes2d_Domain &, const Standard_Address &, const Standard_Real, const Standard_Real>(), py::arg("C1"), py::arg("D1"), py::arg("C2"), py::arg("TolConf"), py::arg("Tol"));
cls_HLRBRep_CInter.def(py::init<const Standard_Address &, const Standard_Address &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real>(), py::arg("C1"), py::arg("C2"), py::arg("D2"), py::arg("TolConf"), py::arg("Tol"));
cls_HLRBRep_CInter.def(py::init<const Standard_Address &, const IntRes2d_Domain &, const Standard_Address &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real>(), py::arg("C1"), py::arg("D1"), py::arg("C2"), py::arg("D2"), py::arg("TolConf"), py::arg("Tol"));

// Methods
// cls_HLRBRep_CInter.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_CInter::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_CInter.def_static("operator delete_", (void (*)(void *)) &HLRBRep_CInter::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_CInter.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_CInter::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_CInter.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_CInter::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_CInter.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_CInter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_CInter.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_CInter::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_CInter.def("Perform", (void (HLRBRep_CInter::*)(const Standard_Address &, const IntRes2d_Domain &, const Standard_Address &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real)) &HLRBRep_CInter::Perform, "Intersection between 2 curves.", py::arg("C1"), py::arg("D1"), py::arg("C2"), py::arg("D2"), py::arg("TolConf"), py::arg("Tol"));
cls_HLRBRep_CInter.def("Perform", (void (HLRBRep_CInter::*)(const Standard_Address &, const Standard_Address &, const Standard_Real, const Standard_Real)) &HLRBRep_CInter::Perform, "Intersection between 2 curves.", py::arg("C1"), py::arg("C2"), py::arg("TolConf"), py::arg("Tol"));
cls_HLRBRep_CInter.def("Perform", (void (HLRBRep_CInter::*)(const Standard_Address &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real)) &HLRBRep_CInter::Perform, "Intersection between 2 curves.", py::arg("C1"), py::arg("D1"), py::arg("TolConf"), py::arg("Tol"));
cls_HLRBRep_CInter.def("Perform", (void (HLRBRep_CInter::*)(const Standard_Address &, const Standard_Real, const Standard_Real)) &HLRBRep_CInter::Perform, "Intersection between 2 curves.", py::arg("C1"), py::arg("TolConf"), py::arg("Tol"));
cls_HLRBRep_CInter.def("Perform", (void (HLRBRep_CInter::*)(const Standard_Address &, const IntRes2d_Domain &, const Standard_Address &, const Standard_Real, const Standard_Real)) &HLRBRep_CInter::Perform, "Intersection between 2 curves.", py::arg("C1"), py::arg("D1"), py::arg("C2"), py::arg("TolConf"), py::arg("Tol"));
cls_HLRBRep_CInter.def("Perform", (void (HLRBRep_CInter::*)(const Standard_Address &, const Standard_Address &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real)) &HLRBRep_CInter::Perform, "Intersection between 2 curves.", py::arg("C1"), py::arg("C2"), py::arg("D2"), py::arg("TolConf"), py::arg("Tol"));
cls_HLRBRep_CInter.def("ComputeDomain", (IntRes2d_Domain (HLRBRep_CInter::*)(const Standard_Address &, const Standard_Real) const) &HLRBRep_CInter::ComputeDomain, "Create a domain from a curve", py::arg("C1"), py::arg("TolDomain"));
cls_HLRBRep_CInter.def("SetMinNbSamples", (void (HLRBRep_CInter::*)(const Standard_Integer)) &HLRBRep_CInter::SetMinNbSamples, "Set / get minimum number of points in polygon intersection.", py::arg("theMinNbSamples"));
cls_HLRBRep_CInter.def("GetMinNbSamples", (Standard_Integer (HLRBRep_CInter::*)() const) &HLRBRep_CInter::GetMinNbSamples, "None");

// CLASS: HLRBREP_CLPROPS
py::class_<HLRBRep_CLProps> cls_HLRBRep_CLProps(mod, "HLRBRep_CLProps", "None");

// Constructors
// cls_HLRBRep_CLProps.def(py::init<const HLRBRep_Curve *&, const Standard_Integer, const Standard_Real>(), py::arg("C"), py::arg("N"), py::arg("Resolution"));
// cls_HLRBRep_CLProps.def(py::init<const HLRBRep_Curve *&, const Standard_Real, const Standard_Integer, const Standard_Real>(), py::arg("C"), py::arg("U"), py::arg("N"), py::arg("Resolution"));
cls_HLRBRep_CLProps.def(py::init<const Standard_Integer, const Standard_Real>(), py::arg("N"), py::arg("Resolution"));

// Methods
// cls_HLRBRep_CLProps.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_CLProps::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_CLProps.def_static("operator delete_", (void (*)(void *)) &HLRBRep_CLProps::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_CLProps.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_CLProps::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_CLProps.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_CLProps::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_CLProps.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_CLProps::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_CLProps.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_CLProps::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_CLProps.def("SetParameter", (void (HLRBRep_CLProps::*)(const Standard_Real)) &HLRBRep_CLProps::SetParameter, "Initializes the local properties of the curve for the parameter value <U>.", py::arg("U"));
// cls_HLRBRep_CLProps.def("SetCurve", (void (HLRBRep_CLProps::*)(const HLRBRep_Curve *&)) &HLRBRep_CLProps::SetCurve, "Initializes the local properties of the curve for the new curve.", py::arg("C"));
cls_HLRBRep_CLProps.def("Value", (const gp_Pnt2d & (HLRBRep_CLProps::*)() const) &HLRBRep_CLProps::Value, "Returns the Point.");
cls_HLRBRep_CLProps.def("D1", (const gp_Vec2d & (HLRBRep_CLProps::*)()) &HLRBRep_CLProps::D1, "Returns the first derivative. The derivative is computed if it has not been yet.");
cls_HLRBRep_CLProps.def("D2", (const gp_Vec2d & (HLRBRep_CLProps::*)()) &HLRBRep_CLProps::D2, "Returns the second derivative. The derivative is computed if it has not been yet.");
cls_HLRBRep_CLProps.def("D3", (const gp_Vec2d & (HLRBRep_CLProps::*)()) &HLRBRep_CLProps::D3, "Returns the third derivative. The derivative is computed if it has not been yet.");
cls_HLRBRep_CLProps.def("IsTangentDefined", (Standard_Boolean (HLRBRep_CLProps::*)()) &HLRBRep_CLProps::IsTangentDefined, "Returns True if the tangent is defined. For example, the tangent is not defined if the three first derivatives are all null.");
cls_HLRBRep_CLProps.def("Tangent", (void (HLRBRep_CLProps::*)(gp_Dir2d &)) &HLRBRep_CLProps::Tangent, "output the tangent direction <D>", py::arg("D"));
cls_HLRBRep_CLProps.def("Curvature", (Standard_Real (HLRBRep_CLProps::*)()) &HLRBRep_CLProps::Curvature, "Returns the curvature.");
cls_HLRBRep_CLProps.def("Normal", (void (HLRBRep_CLProps::*)(gp_Dir2d &)) &HLRBRep_CLProps::Normal, "Returns the normal direction <N>.", py::arg("N"));
cls_HLRBRep_CLProps.def("CentreOfCurvature", (void (HLRBRep_CLProps::*)(gp_Pnt2d &)) &HLRBRep_CLProps::CentreOfCurvature, "Returns the centre of curvature <P>.", py::arg("P"));

// CLASS: HLRBREP_CLPROPSATOOL
py::class_<HLRBRep_CLPropsATool> cls_HLRBRep_CLPropsATool(mod, "HLRBRep_CLPropsATool", "None");

// Constructors
cls_HLRBRep_CLPropsATool.def(py::init<>());

// Methods
// cls_HLRBRep_CLPropsATool.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_CLPropsATool::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_CLPropsATool.def_static("operator delete_", (void (*)(void *)) &HLRBRep_CLPropsATool::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_CLPropsATool.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_CLPropsATool::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_CLPropsATool.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_CLPropsATool::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_CLPropsATool.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_CLPropsATool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_CLPropsATool.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_CLPropsATool::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_CLPropsATool.def_static("Value_", (void (*)(const HLRBRep_Curve *, const Standard_Real, gp_Pnt2d &)) &HLRBRep_CLPropsATool::Value, "Computes the point <P> of parameter <U> on the Curve from HLRBRep <C>.", py::arg("A"), py::arg("U"), py::arg("P"));
cls_HLRBRep_CLPropsATool.def_static("D1_", (void (*)(const HLRBRep_Curve *, const Standard_Real, gp_Pnt2d &, gp_Vec2d &)) &HLRBRep_CLPropsATool::D1, "Computes the point <P> and first derivative <V1> of parameter <U> on the curve <C>.", py::arg("A"), py::arg("U"), py::arg("P"), py::arg("V1"));
cls_HLRBRep_CLPropsATool.def_static("D2_", (void (*)(const HLRBRep_Curve *, const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &)) &HLRBRep_CLPropsATool::D2, "Computes the point <P>, the first derivative <V1> and second derivative <V2> of parameter <U> on the curve <C>.", py::arg("A"), py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"));
cls_HLRBRep_CLPropsATool.def_static("D3_", (void (*)(const HLRBRep_Curve *, const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &, gp_Vec2d &)) &HLRBRep_CLPropsATool::D3, "Computes the point <P>, the first derivative <V1>, the second derivative <V2> and third derivative <V3> of parameter <U> on the curve <C>.", py::arg("A"), py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"));
cls_HLRBRep_CLPropsATool.def_static("Continuity_", (Standard_Integer (*)(const HLRBRep_Curve *)) &HLRBRep_CLPropsATool::Continuity, "returns the order of continuity of the curve <C>. returns 1 : first derivative only is computable returns 2 : first and second derivative only are computable. returns 3 : first, second and third are computable.", py::arg("A"));
cls_HLRBRep_CLPropsATool.def_static("FirstParameter_", (Standard_Real (*)(const HLRBRep_Curve *)) &HLRBRep_CLPropsATool::FirstParameter, "returns the first parameter bound of the curve.", py::arg("A"));
cls_HLRBRep_CLPropsATool.def_static("LastParameter_", (Standard_Real (*)(const HLRBRep_Curve *)) &HLRBRep_CLPropsATool::LastParameter, "returns the last parameter bound of the curve. FirstParameter must be less than LastParamenter.", py::arg("A"));

// CLASS: HLRBREP_CURVETOOL
py::class_<HLRBRep_CurveTool> cls_HLRBRep_CurveTool(mod, "HLRBRep_CurveTool", "None");

// Constructors
cls_HLRBRep_CurveTool.def(py::init<>());

// Methods
// cls_HLRBRep_CurveTool.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_CurveTool::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_CurveTool.def_static("operator delete_", (void (*)(void *)) &HLRBRep_CurveTool::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_CurveTool.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_CurveTool::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_CurveTool.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_CurveTool::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_CurveTool.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_CurveTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_CurveTool.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_CurveTool::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_CurveTool.def_static("FirstParameter_", (Standard_Real (*)(const Standard_Address)) &HLRBRep_CurveTool::FirstParameter, "None", py::arg("C"));
cls_HLRBRep_CurveTool.def_static("LastParameter_", (Standard_Real (*)(const Standard_Address)) &HLRBRep_CurveTool::LastParameter, "None", py::arg("C"));
cls_HLRBRep_CurveTool.def_static("Continuity_", (GeomAbs_Shape (*)(const Standard_Address)) &HLRBRep_CurveTool::Continuity, "None", py::arg("C"));
cls_HLRBRep_CurveTool.def_static("NbIntervals_", (Standard_Integer (*)(const Standard_Address)) &HLRBRep_CurveTool::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(myclass) >= <S>", py::arg("C"));
cls_HLRBRep_CurveTool.def_static("Intervals_", (void (*)(const Standard_Address, TColStd_Array1OfReal &)) &HLRBRep_CurveTool::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("C"), py::arg("T"));
cls_HLRBRep_CurveTool.def_static("GetInterval_", [](const Standard_Address C, const Standard_Integer Index, const TColStd_Array1OfReal & Tab, Standard_Real & U1, Standard_Real & U2){ HLRBRep_CurveTool::GetInterval(C, Index, Tab, U1, U2); return std::tuple<Standard_Real &, Standard_Real &>(U1, U2); }, "output the bounds of interval of index <Index> used if Type == Composite.", py::arg("C"), py::arg("Index"), py::arg("Tab"), py::arg("U1"), py::arg("U2"));
cls_HLRBRep_CurveTool.def_static("IsClosed_", (Standard_Boolean (*)(const Standard_Address)) &HLRBRep_CurveTool::IsClosed, "None", py::arg("C"));
cls_HLRBRep_CurveTool.def_static("IsPeriodic_", (Standard_Boolean (*)(const Standard_Address)) &HLRBRep_CurveTool::IsPeriodic, "None", py::arg("C"));
cls_HLRBRep_CurveTool.def_static("Period_", (Standard_Real (*)(const Standard_Address)) &HLRBRep_CurveTool::Period, "None", py::arg("C"));
cls_HLRBRep_CurveTool.def_static("Value_", (gp_Pnt2d (*)(const Standard_Address, const Standard_Real)) &HLRBRep_CurveTool::Value, "Computes the point of parameter U on the curve.", py::arg("C"), py::arg("U"));
cls_HLRBRep_CurveTool.def_static("D0_", (void (*)(const Standard_Address, const Standard_Real, gp_Pnt2d &)) &HLRBRep_CurveTool::D0, "Computes the point of parameter U on the curve.", py::arg("C"), py::arg("U"), py::arg("P"));
cls_HLRBRep_CurveTool.def_static("D1_", (void (*)(const Standard_Address, const Standard_Real, gp_Pnt2d &, gp_Vec2d &)) &HLRBRep_CurveTool::D1, "Computes the point of parameter U on the curve with its first derivative. Raised if the continuity of the current interval is not C1.", py::arg("C"), py::arg("U"), py::arg("P"), py::arg("V"));
cls_HLRBRep_CurveTool.def_static("D2_", (void (*)(const Standard_Address, const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &)) &HLRBRep_CurveTool::D2, "Returns the point P of parameter U, the first and second derivatives V1 and V2. Raised if the continuity of the current interval is not C2.", py::arg("C"), py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"));
cls_HLRBRep_CurveTool.def_static("D3_", (void (*)(const Standard_Address, const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &, gp_Vec2d &)) &HLRBRep_CurveTool::D3, "Returns the point P of parameter U, the first, the second and the third derivative. Raised if the continuity of the current interval is not C3.", py::arg("C"), py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"));
cls_HLRBRep_CurveTool.def_static("DN_", (gp_Vec2d (*)(const Standard_Address, const Standard_Real, const Standard_Integer)) &HLRBRep_CurveTool::DN, "The returned vector gives the value of the derivative for the order of derivation N. Raised if the continuity of the current interval is not CN. Raised if N < 1.", py::arg("C"), py::arg("U"), py::arg("N"));
cls_HLRBRep_CurveTool.def_static("Resolution_", (Standard_Real (*)(const Standard_Address, const Standard_Real)) &HLRBRep_CurveTool::Resolution, "Returns the parametric resolution corresponding to the real space resolution <R3d>.", py::arg("C"), py::arg("R3d"));
cls_HLRBRep_CurveTool.def_static("GetType_", (GeomAbs_CurveType (*)(const Standard_Address)) &HLRBRep_CurveTool::GetType, "Returns the type of the curve in the current interval : Line, Circle, Ellipse, Hyperbola, Parabola, BezierCurve, BSplineCurve, OtherCurve.", py::arg("C"));
cls_HLRBRep_CurveTool.def_static("TheType_", (GeomAbs_CurveType (*)(const Standard_Address)) &HLRBRep_CurveTool::TheType, "Returns the type of the curve in the current interval : Line, Circle, Ellipse, Hyperbola, Parabola, BezierCurve, BSplineCurve, OtherCurve.", py::arg("C"));
cls_HLRBRep_CurveTool.def_static("Line_", (gp_Lin2d (*)(const Standard_Address)) &HLRBRep_CurveTool::Line, "None", py::arg("C"));
cls_HLRBRep_CurveTool.def_static("Circle_", (gp_Circ2d (*)(const Standard_Address)) &HLRBRep_CurveTool::Circle, "None", py::arg("C"));
cls_HLRBRep_CurveTool.def_static("Ellipse_", (gp_Elips2d (*)(const Standard_Address)) &HLRBRep_CurveTool::Ellipse, "None", py::arg("C"));
cls_HLRBRep_CurveTool.def_static("Hyperbola_", (gp_Hypr2d (*)(const Standard_Address)) &HLRBRep_CurveTool::Hyperbola, "None", py::arg("C"));
cls_HLRBRep_CurveTool.def_static("Parabola_", (gp_Parab2d (*)(const Standard_Address)) &HLRBRep_CurveTool::Parabola, "None", py::arg("C"));
cls_HLRBRep_CurveTool.def_static("Bezier_", (opencascade::handle<Geom2d_BezierCurve> (*)(const Standard_Address)) &HLRBRep_CurveTool::Bezier, "None", py::arg("C"));
cls_HLRBRep_CurveTool.def_static("BSpline_", (opencascade::handle<Geom2d_BSplineCurve> (*)(const Standard_Address)) &HLRBRep_CurveTool::BSpline, "None", py::arg("C"));
cls_HLRBRep_CurveTool.def_static("EpsX_", (Standard_Real (*)(const Standard_Address)) &HLRBRep_CurveTool::EpsX, "None", py::arg("C"));
cls_HLRBRep_CurveTool.def_static("NbSamples_", (Standard_Integer (*)(const Standard_Address, const Standard_Real, const Standard_Real)) &HLRBRep_CurveTool::NbSamples, "None", py::arg("C"), py::arg("U0"), py::arg("U1"));
cls_HLRBRep_CurveTool.def_static("NbSamples_", (Standard_Integer (*)(const Standard_Address)) &HLRBRep_CurveTool::NbSamples, "None", py::arg("C"));
cls_HLRBRep_CurveTool.def_static("Degree_", (Standard_Integer (*)(const Standard_Address)) &HLRBRep_CurveTool::Degree, "None", py::arg("C"));

// CLASS: HLRBREP_SLPROPS
py::class_<HLRBRep_SLProps> cls_HLRBRep_SLProps(mod, "HLRBRep_SLProps", "None");

// Constructors
cls_HLRBRep_SLProps.def(py::init<const Standard_Address &, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Real>(), py::arg("S"), py::arg("U"), py::arg("V"), py::arg("N"), py::arg("Resolution"));
cls_HLRBRep_SLProps.def(py::init<const Standard_Address &, const Standard_Integer, const Standard_Real>(), py::arg("S"), py::arg("N"), py::arg("Resolution"));
cls_HLRBRep_SLProps.def(py::init<const Standard_Integer, const Standard_Real>(), py::arg("N"), py::arg("Resolution"));

// Methods
// cls_HLRBRep_SLProps.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_SLProps::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_SLProps.def_static("operator delete_", (void (*)(void *)) &HLRBRep_SLProps::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_SLProps.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_SLProps::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_SLProps.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_SLProps::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_SLProps.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_SLProps::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_SLProps.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_SLProps::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_SLProps.def("SetSurface", (void (HLRBRep_SLProps::*)(const Standard_Address &)) &HLRBRep_SLProps::SetSurface, "Initializes the local properties of the surface S for the new surface.", py::arg("S"));
cls_HLRBRep_SLProps.def("SetParameters", (void (HLRBRep_SLProps::*)(const Standard_Real, const Standard_Real)) &HLRBRep_SLProps::SetParameters, "Initializes the local properties of the surface S for the new parameter values (<U>, <V>).", py::arg("U"), py::arg("V"));
cls_HLRBRep_SLProps.def("Value", (const gp_Pnt & (HLRBRep_SLProps::*)() const) &HLRBRep_SLProps::Value, "Returns the point.");
cls_HLRBRep_SLProps.def("D1U", (const gp_Vec & (HLRBRep_SLProps::*)()) &HLRBRep_SLProps::D1U, "Returns the first U derivative. The derivative is computed if it has not been yet.");
cls_HLRBRep_SLProps.def("D1V", (const gp_Vec & (HLRBRep_SLProps::*)()) &HLRBRep_SLProps::D1V, "Returns the first V derivative. The derivative is computed if it has not been yet.");
cls_HLRBRep_SLProps.def("D2U", (const gp_Vec & (HLRBRep_SLProps::*)()) &HLRBRep_SLProps::D2U, "Returns the second U derivatives The derivative is computed if it has not been yet.");
cls_HLRBRep_SLProps.def("D2V", (const gp_Vec & (HLRBRep_SLProps::*)()) &HLRBRep_SLProps::D2V, "Returns the second V derivative. The derivative is computed if it has not been yet.");
cls_HLRBRep_SLProps.def("DUV", (const gp_Vec & (HLRBRep_SLProps::*)()) &HLRBRep_SLProps::DUV, "Returns the second UV cross-derivative. The derivative is computed if it has not been yet.");
cls_HLRBRep_SLProps.def("IsTangentUDefined", (Standard_Boolean (HLRBRep_SLProps::*)()) &HLRBRep_SLProps::IsTangentUDefined, "returns True if the U tangent is defined. For example, the tangent is not defined if the two first U derivatives are null.");
cls_HLRBRep_SLProps.def("TangentU", (void (HLRBRep_SLProps::*)(gp_Dir &)) &HLRBRep_SLProps::TangentU, "Returns the tangent direction <D> on the iso-V.", py::arg("D"));
cls_HLRBRep_SLProps.def("IsTangentVDefined", (Standard_Boolean (HLRBRep_SLProps::*)()) &HLRBRep_SLProps::IsTangentVDefined, "returns if the V tangent is defined. For example, the tangent is not defined if the two first V derivatives are null.");
cls_HLRBRep_SLProps.def("TangentV", (void (HLRBRep_SLProps::*)(gp_Dir &)) &HLRBRep_SLProps::TangentV, "Returns the tangent direction <D> on the iso-V.", py::arg("D"));
cls_HLRBRep_SLProps.def("IsNormalDefined", (Standard_Boolean (HLRBRep_SLProps::*)()) &HLRBRep_SLProps::IsNormalDefined, "Tells if the normal is defined.");
cls_HLRBRep_SLProps.def("Normal", (const gp_Dir & (HLRBRep_SLProps::*)()) &HLRBRep_SLProps::Normal, "Returns the normal direction.");
cls_HLRBRep_SLProps.def("IsCurvatureDefined", (Standard_Boolean (HLRBRep_SLProps::*)()) &HLRBRep_SLProps::IsCurvatureDefined, "returns True if the curvature is defined.");
cls_HLRBRep_SLProps.def("IsUmbilic", (Standard_Boolean (HLRBRep_SLProps::*)()) &HLRBRep_SLProps::IsUmbilic, "returns True if the point is umbilic (i.e. if the curvature is constant).");
cls_HLRBRep_SLProps.def("MaxCurvature", (Standard_Real (HLRBRep_SLProps::*)()) &HLRBRep_SLProps::MaxCurvature, "Returns the maximum curvature");
cls_HLRBRep_SLProps.def("MinCurvature", (Standard_Real (HLRBRep_SLProps::*)()) &HLRBRep_SLProps::MinCurvature, "Returns the minimum curvature");
cls_HLRBRep_SLProps.def("CurvatureDirections", (void (HLRBRep_SLProps::*)(gp_Dir &, gp_Dir &)) &HLRBRep_SLProps::CurvatureDirections, "Returns the direction of the maximum and minimum curvature <MaxD> and <MinD>", py::arg("MaxD"), py::arg("MinD"));
cls_HLRBRep_SLProps.def("MeanCurvature", (Standard_Real (HLRBRep_SLProps::*)()) &HLRBRep_SLProps::MeanCurvature, "Returns the mean curvature.");
cls_HLRBRep_SLProps.def("GaussianCurvature", (Standard_Real (HLRBRep_SLProps::*)()) &HLRBRep_SLProps::GaussianCurvature, "Returns the Gaussian curvature");

// CLASS: HLRBREP_FACEITERATOR
py::class_<HLRBRep_FaceIterator> cls_HLRBRep_FaceIterator(mod, "HLRBRep_FaceIterator", "None");

// Constructors
cls_HLRBRep_FaceIterator.def(py::init<>());

// Methods
// cls_HLRBRep_FaceIterator.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_FaceIterator::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_FaceIterator.def_static("operator delete_", (void (*)(void *)) &HLRBRep_FaceIterator::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_FaceIterator.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_FaceIterator::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_FaceIterator.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_FaceIterator::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_FaceIterator.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_FaceIterator::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_FaceIterator.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_FaceIterator::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_FaceIterator.def("InitEdge", (void (HLRBRep_FaceIterator::*)(HLRBRep_FaceData &)) &HLRBRep_FaceIterator::InitEdge, "Begin an exploration of the edges of the face <fd>", py::arg("fd"));
cls_HLRBRep_FaceIterator.def("MoreEdge", (Standard_Boolean (HLRBRep_FaceIterator::*)() const) &HLRBRep_FaceIterator::MoreEdge, "None");
cls_HLRBRep_FaceIterator.def("NextEdge", (void (HLRBRep_FaceIterator::*)()) &HLRBRep_FaceIterator::NextEdge, "None");
cls_HLRBRep_FaceIterator.def("BeginningOfWire", (Standard_Boolean (HLRBRep_FaceIterator::*)() const) &HLRBRep_FaceIterator::BeginningOfWire, "Returns True if the current edge is the first of a wire.");
cls_HLRBRep_FaceIterator.def("EndOfWire", (Standard_Boolean (HLRBRep_FaceIterator::*)() const) &HLRBRep_FaceIterator::EndOfWire, "Returns True if the current edge is the last of a wire.");
cls_HLRBRep_FaceIterator.def("SkipWire", (void (HLRBRep_FaceIterator::*)()) &HLRBRep_FaceIterator::SkipWire, "Skip the current wire in the exploration.");
cls_HLRBRep_FaceIterator.def("Wire", (opencascade::handle<HLRAlgo_EdgesBlock> (HLRBRep_FaceIterator::*)() const) &HLRBRep_FaceIterator::Wire, "Returns the edges of the current wire.");
cls_HLRBRep_FaceIterator.def("Edge", (Standard_Integer (HLRBRep_FaceIterator::*)() const) &HLRBRep_FaceIterator::Edge, "None");
cls_HLRBRep_FaceIterator.def("Orientation", (TopAbs_Orientation (HLRBRep_FaceIterator::*)() const) &HLRBRep_FaceIterator::Orientation, "None");
cls_HLRBRep_FaceIterator.def("OutLine", (Standard_Boolean (HLRBRep_FaceIterator::*)() const) &HLRBRep_FaceIterator::OutLine, "None");
cls_HLRBRep_FaceIterator.def("Internal", (Standard_Boolean (HLRBRep_FaceIterator::*)() const) &HLRBRep_FaceIterator::Internal, "None");
cls_HLRBRep_FaceIterator.def("Double", (Standard_Boolean (HLRBRep_FaceIterator::*)() const) &HLRBRep_FaceIterator::Double, "None");
cls_HLRBRep_FaceIterator.def("IsoLine", (Standard_Boolean (HLRBRep_FaceIterator::*)() const) &HLRBRep_FaceIterator::IsoLine, "None");

// CLASS: HLRBREP_INTERCSURF
py::class_<HLRBRep_InterCSurf, IntCurveSurface_Intersection> cls_HLRBRep_InterCSurf(mod, "HLRBRep_InterCSurf", "None");

// Constructors
cls_HLRBRep_InterCSurf.def(py::init<>());

// Methods
// cls_HLRBRep_InterCSurf.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_InterCSurf::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_InterCSurf.def_static("operator delete_", (void (*)(void *)) &HLRBRep_InterCSurf::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_InterCSurf.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_InterCSurf::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_InterCSurf.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_InterCSurf::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_InterCSurf.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_InterCSurf::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_InterCSurf.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_InterCSurf::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_InterCSurf.def("Perform", (void (HLRBRep_InterCSurf::*)(const gp_Lin &, const Standard_Address &)) &HLRBRep_InterCSurf::Perform, "Compute the Intersection between the curve and the surface", py::arg("Curve"), py::arg("Surface"));
cls_HLRBRep_InterCSurf.def("Perform", (void (HLRBRep_InterCSurf::*)(const gp_Lin &, const HLRBRep_ThePolygonOfInterCSurf &, const Standard_Address &)) &HLRBRep_InterCSurf::Perform, "Compute the Intersection between the curve and the surface. The Curve is already sampled and its polygon : <Polygon> is given.", py::arg("Curve"), py::arg("Polygon"), py::arg("Surface"));
cls_HLRBRep_InterCSurf.def("Perform", (void (HLRBRep_InterCSurf::*)(const gp_Lin &, const HLRBRep_ThePolygonOfInterCSurf &, const Standard_Address &, const HLRBRep_ThePolyhedronOfInterCSurf &)) &HLRBRep_InterCSurf::Perform, "Compute the Intersection between the curve and the surface. The Curve is already sampled and its polygon : <Polygon> is given. The Surface is also sampled and <Polyhedron> is given.", py::arg("Curve"), py::arg("ThePolygon"), py::arg("Surface"), py::arg("Polyhedron"));
cls_HLRBRep_InterCSurf.def("Perform", (void (HLRBRep_InterCSurf::*)(const gp_Lin &, const HLRBRep_ThePolygonOfInterCSurf &, const Standard_Address &, const HLRBRep_ThePolyhedronOfInterCSurf &, Bnd_BoundSortBox &)) &HLRBRep_InterCSurf::Perform, "Compute the Intersection between the curve and the surface. The Curve is already sampled and its polygon : <Polygon> is given. The Surface is also sampled and <Polyhedron> is given.", py::arg("Curve"), py::arg("ThePolygon"), py::arg("Surface"), py::arg("Polyhedron"), py::arg("BndBSB"));
cls_HLRBRep_InterCSurf.def("Perform", (void (HLRBRep_InterCSurf::*)(const gp_Lin &, const Standard_Address &, const HLRBRep_ThePolyhedronOfInterCSurf &)) &HLRBRep_InterCSurf::Perform, "Compute the Intersection between the curve and the surface. The Surface is already sampled and its polyhedron : <Polyhedron> is given.", py::arg("Curve"), py::arg("Surface"), py::arg("Polyhedron"));

// CLASS: HLRBREP_INTERSECTOR
py::class_<HLRBRep_Intersector> cls_HLRBRep_Intersector(mod, "HLRBRep_Intersector", "The Intersector computes 2D intersections of the projections of 3D curves.");

// Constructors
cls_HLRBRep_Intersector.def(py::init<>());

// Methods
// cls_HLRBRep_Intersector.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_Intersector::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_Intersector.def_static("operator delete_", (void (*)(void *)) &HLRBRep_Intersector::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_Intersector.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_Intersector::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_Intersector.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_Intersector::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_Intersector.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_Intersector::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_Intersector.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_Intersector::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_Intersector.def("Perform", (void (HLRBRep_Intersector::*)(const Standard_Address, const Standard_Real, const Standard_Real)) &HLRBRep_Intersector::Perform, "Performs the auto intersection of an edge. The edge domain is cutted at start with da1*(b-a) and at end with db1*(b-a).", py::arg("A1"), py::arg("da1"), py::arg("db1"));
cls_HLRBRep_Intersector.def("Perform", (void (HLRBRep_Intersector::*)(const Standard_Integer, const Standard_Address, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Address, const Standard_Real, const Standard_Real, const Standard_Boolean)) &HLRBRep_Intersector::Perform, "Performs the intersection between the two edges. The edges domains are cutted at start with da*(b-a) and at end with db*(b-a).", py::arg("nA"), py::arg("A1"), py::arg("da1"), py::arg("db1"), py::arg("nB"), py::arg("A2"), py::arg("da2"), py::arg("db2"), py::arg("NoBound"));
cls_HLRBRep_Intersector.def("SimulateOnePoint", (void (HLRBRep_Intersector::*)(const Standard_Address, const Standard_Real, const Standard_Address, const Standard_Real)) &HLRBRep_Intersector::SimulateOnePoint, "Create a single IntersectionPoint (U on A1) (V on A2) The point is middle on both curves.", py::arg("A1"), py::arg("U"), py::arg("A2"), py::arg("V"));
cls_HLRBRep_Intersector.def("Load", (void (HLRBRep_Intersector::*)(Standard_Address &)) &HLRBRep_Intersector::Load, "None", py::arg("A"));
cls_HLRBRep_Intersector.def("Perform", (void (HLRBRep_Intersector::*)(const gp_Lin &, const Standard_Real)) &HLRBRep_Intersector::Perform, "None", py::arg("L"), py::arg("P"));
cls_HLRBRep_Intersector.def("IsDone", (Standard_Boolean (HLRBRep_Intersector::*)() const) &HLRBRep_Intersector::IsDone, "None");
cls_HLRBRep_Intersector.def("NbPoints", (Standard_Integer (HLRBRep_Intersector::*)() const) &HLRBRep_Intersector::NbPoints, "None");
cls_HLRBRep_Intersector.def("Point", (const IntRes2d_IntersectionPoint & (HLRBRep_Intersector::*)(const Standard_Integer) const) &HLRBRep_Intersector::Point, "None", py::arg("N"));
cls_HLRBRep_Intersector.def("CSPoint", (const IntCurveSurface_IntersectionPoint & (HLRBRep_Intersector::*)(const Standard_Integer) const) &HLRBRep_Intersector::CSPoint, "None", py::arg("N"));
cls_HLRBRep_Intersector.def("NbSegments", (Standard_Integer (HLRBRep_Intersector::*)() const) &HLRBRep_Intersector::NbSegments, "None");
cls_HLRBRep_Intersector.def("Segment", (const IntRes2d_IntersectionSegment & (HLRBRep_Intersector::*)(const Standard_Integer) const) &HLRBRep_Intersector::Segment, "None", py::arg("N"));
cls_HLRBRep_Intersector.def("CSSegment", (const IntCurveSurface_IntersectionSegment & (HLRBRep_Intersector::*)(const Standard_Integer) const) &HLRBRep_Intersector::CSSegment, "None", py::arg("N"));
cls_HLRBRep_Intersector.def("Destroy", (void (HLRBRep_Intersector::*)()) &HLRBRep_Intersector::Destroy, "None");

// CLASS: HLRBREP_DATA
py::class_<HLRBRep_Data, opencascade::handle<HLRBRep_Data>, Standard_Transient> cls_HLRBRep_Data(mod, "HLRBRep_Data", "None");

// Constructors
cls_HLRBRep_Data.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("NV"), py::arg("NE"), py::arg("NF"));

// Methods
cls_HLRBRep_Data.def("Write", (void (HLRBRep_Data::*)(const opencascade::handle<HLRBRep_Data> &, const Standard_Integer, const Standard_Integer, const Standard_Integer)) &HLRBRep_Data::Write, "Write <DS> in me with a translation of <dv>,<de>,<df>.", py::arg("DS"), py::arg("dv"), py::arg("de"), py::arg("df"));
cls_HLRBRep_Data.def("EDataArray", (HLRBRep_Array1OfEData & (HLRBRep_Data::*)()) &HLRBRep_Data::EDataArray, "None");
cls_HLRBRep_Data.def("FDataArray", (HLRBRep_Array1OfFData & (HLRBRep_Data::*)()) &HLRBRep_Data::FDataArray, "None");
cls_HLRBRep_Data.def("Tolerance", (void (HLRBRep_Data::*)(const Standard_ShortReal)) &HLRBRep_Data::Tolerance, "Set the tolerance for the rejections during the exploration", py::arg("tol"));
cls_HLRBRep_Data.def("Tolerance", (Standard_ShortReal (HLRBRep_Data::*)() const) &HLRBRep_Data::Tolerance, "returns the tolerance for the rejections during the exploration");
cls_HLRBRep_Data.def("Update", (void (HLRBRep_Data::*)(const HLRAlgo_Projector &)) &HLRBRep_Data::Update, "end of building of the Data and updating all the informations linked to the projection.", py::arg("P"));
cls_HLRBRep_Data.def("Projector", (HLRAlgo_Projector & (HLRBRep_Data::*)()) &HLRBRep_Data::Projector, "None");
cls_HLRBRep_Data.def("NbVertices", (Standard_Integer (HLRBRep_Data::*)() const) &HLRBRep_Data::NbVertices, "None");
cls_HLRBRep_Data.def("NbEdges", (Standard_Integer (HLRBRep_Data::*)() const) &HLRBRep_Data::NbEdges, "None");
cls_HLRBRep_Data.def("NbFaces", (Standard_Integer (HLRBRep_Data::*)() const) &HLRBRep_Data::NbFaces, "None");
cls_HLRBRep_Data.def("EdgeMap", (TopTools_IndexedMapOfShape & (HLRBRep_Data::*)()) &HLRBRep_Data::EdgeMap, "None");
cls_HLRBRep_Data.def("FaceMap", (TopTools_IndexedMapOfShape & (HLRBRep_Data::*)()) &HLRBRep_Data::FaceMap, "None");
cls_HLRBRep_Data.def("InitBoundSort", (void (HLRBRep_Data::*)(const HLRAlgo_EdgesBlock::MinMaxIndices &, const Standard_Integer, const Standard_Integer)) &HLRBRep_Data::InitBoundSort, "to compare with only non rejected edges.", py::arg("MinMaxTot"), py::arg("e1"), py::arg("e2"));
cls_HLRBRep_Data.def("InitEdge", (void (HLRBRep_Data::*)(const Standard_Integer, BRepTopAdaptor_MapOfShapeTool &)) &HLRBRep_Data::InitEdge, "Begin an iteration only on visible Edges crossing the face number <FI>.", py::arg("FI"), py::arg("MST"));
cls_HLRBRep_Data.def("MoreEdge", (Standard_Boolean (HLRBRep_Data::*)()) &HLRBRep_Data::MoreEdge, "None");
cls_HLRBRep_Data.def("NextEdge", [](HLRBRep_Data &self) -> void { return self.NextEdge(); });
cls_HLRBRep_Data.def("NextEdge", (void (HLRBRep_Data::*)(const Standard_Boolean)) &HLRBRep_Data::NextEdge, "None", py::arg("skip"));
cls_HLRBRep_Data.def("Edge", (Standard_Integer (HLRBRep_Data::*)() const) &HLRBRep_Data::Edge, "Returns the current Edge");
cls_HLRBRep_Data.def("HidingTheFace", (Standard_Boolean (HLRBRep_Data::*)() const) &HLRBRep_Data::HidingTheFace, "Returns true if the current edge to be hidden belongs to the hiding face.");
cls_HLRBRep_Data.def("SimpleHidingFace", (Standard_Boolean (HLRBRep_Data::*)() const) &HLRBRep_Data::SimpleHidingFace, "Returns true if the current hiding face is not an auto-intersected one.");
cls_HLRBRep_Data.def("InitInterference", (void (HLRBRep_Data::*)()) &HLRBRep_Data::InitInterference, "Intersect the current Edge with the boundary of the hiding face. The interferences are given by the More, Next, and Value methods.");
cls_HLRBRep_Data.def("MoreInterference", (Standard_Boolean (HLRBRep_Data::*)() const) &HLRBRep_Data::MoreInterference, "None");
cls_HLRBRep_Data.def("NextInterference", (void (HLRBRep_Data::*)()) &HLRBRep_Data::NextInterference, "None");
cls_HLRBRep_Data.def("RejectedInterference", (Standard_Boolean (HLRBRep_Data::*)()) &HLRBRep_Data::RejectedInterference, "Returns True if the interference is rejected.");
cls_HLRBRep_Data.def("AboveInterference", (Standard_Boolean (HLRBRep_Data::*)()) &HLRBRep_Data::AboveInterference, "Returns True if the rejected interference is above the face.");
cls_HLRBRep_Data.def("Interference", (HLRAlgo_Interference & (HLRBRep_Data::*)()) &HLRBRep_Data::Interference, "None");
cls_HLRBRep_Data.def("LocalLEGeometry2D", [](HLRBRep_Data &self, const Standard_Real Param, gp_Dir2d & Tg, gp_Dir2d & Nm, Standard_Real & Cu){ self.LocalLEGeometry2D(Param, Tg, Nm, Cu); return Cu; }, "Returns the local description of the projection of the current LEdge at parameter <Param>.", py::arg("Param"), py::arg("Tg"), py::arg("Nm"), py::arg("Cu"));
cls_HLRBRep_Data.def("LocalFEGeometry2D", [](HLRBRep_Data &self, const Standard_Integer FE, const Standard_Real Param, gp_Dir2d & Tg, gp_Dir2d & Nm, Standard_Real & Cu){ self.LocalFEGeometry2D(FE, Param, Tg, Nm, Cu); return Cu; }, "Returns the local description of the projection of the current FEdge at parameter <Param>.", py::arg("FE"), py::arg("Param"), py::arg("Tg"), py::arg("Nm"), py::arg("Cu"));
cls_HLRBRep_Data.def("EdgeState", (void (HLRBRep_Data::*)(const Standard_Real, const Standard_Real, TopAbs_State &, TopAbs_State &)) &HLRBRep_Data::EdgeState, "Returns the local 3D state of the intersection between the current edge and the current face at the <p1> and <p2> parameters.", py::arg("p1"), py::arg("p2"), py::arg("stbef"), py::arg("staf"));
cls_HLRBRep_Data.def("EdgeOfTheHidingFace", (Standard_Boolean (HLRBRep_Data::*)(const Standard_Integer, const HLRBRep_EdgeData &) const) &HLRBRep_Data::EdgeOfTheHidingFace, "Returns the true if the Edge <ED> belongs to the Hiding Face.", py::arg("E"), py::arg("ED"));
cls_HLRBRep_Data.def("HidingStartLevel", (Standard_Integer (HLRBRep_Data::*)(const Standard_Integer, const HLRBRep_EdgeData &, const HLRAlgo_InterferenceList &)) &HLRBRep_Data::HidingStartLevel, "Returns the number of levels of hiding face above the first point of the edge <ED>. The InterferenceList is given to compute far away of the Interferences and then come back.", py::arg("E"), py::arg("ED"), py::arg("IL"));
cls_HLRBRep_Data.def("Compare", (TopAbs_State (HLRBRep_Data::*)(const Standard_Integer, const HLRBRep_EdgeData &)) &HLRBRep_Data::Compare, "Returns the state of the Edge <ED> after classification.", py::arg("E"), py::arg("ED"));
cls_HLRBRep_Data.def("SimplClassify", (TopAbs_State (HLRBRep_Data::*)(const Standard_Integer, const HLRBRep_EdgeData &, const Standard_Integer, const Standard_Real, const Standard_Real)) &HLRBRep_Data::SimplClassify, "Simple classification of part of edge [p1, p2] returns OUT if at least 1 of Nbp points of edge is out othewise returns IN It is used to check 'suspision' hided part of edge.", py::arg("E"), py::arg("ED"), py::arg("Nbp"), py::arg("p1"), py::arg("p2"));
cls_HLRBRep_Data.def("Classify", [](HLRBRep_Data &self, const Standard_Integer E, const HLRBRep_EdgeData & ED, const Standard_Boolean LevelFlag, Standard_Integer & Level, const Standard_Real param){ TopAbs_State rv = self.Classify(E, ED, LevelFlag, Level, param); return std::tuple<TopAbs_State, Standard_Integer &>(rv, Level); }, "Classification of an edge.", py::arg("E"), py::arg("ED"), py::arg("LevelFlag"), py::arg("Level"), py::arg("param"));
cls_HLRBRep_Data.def("IsBadFace", (Standard_Boolean (HLRBRep_Data::*)() const) &HLRBRep_Data::IsBadFace, "Returns true if the current face is bad.");
cls_HLRBRep_Data.def("Destroy", (void (HLRBRep_Data::*)()) &HLRBRep_Data::Destroy, "None");
cls_HLRBRep_Data.def_static("get_type_name_", (const char * (*)()) &HLRBRep_Data::get_type_name, "None");
cls_HLRBRep_Data.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &HLRBRep_Data::get_type_descriptor, "None");
cls_HLRBRep_Data.def("DynamicType", (const opencascade::handle<Standard_Type> & (HLRBRep_Data::*)() const) &HLRBRep_Data::DynamicType, "None");

// CLASS: HLRBREP_EDGEBUILDER
py::class_<HLRBRep_EdgeBuilder> cls_HLRBRep_EdgeBuilder(mod, "HLRBRep_EdgeBuilder", "None");

// Constructors
cls_HLRBRep_EdgeBuilder.def(py::init<HLRBRep_VertexList &>(), py::arg("VList"));

// Methods
// cls_HLRBRep_EdgeBuilder.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_EdgeBuilder::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_EdgeBuilder.def_static("operator delete_", (void (*)(void *)) &HLRBRep_EdgeBuilder::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_EdgeBuilder.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_EdgeBuilder::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_EdgeBuilder.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_EdgeBuilder::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_EdgeBuilder.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_EdgeBuilder::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_EdgeBuilder.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_EdgeBuilder::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_EdgeBuilder.def("InitAreas", (void (HLRBRep_EdgeBuilder::*)()) &HLRBRep_EdgeBuilder::InitAreas, "Initialize an iteration on the areas.");
cls_HLRBRep_EdgeBuilder.def("NextArea", (void (HLRBRep_EdgeBuilder::*)()) &HLRBRep_EdgeBuilder::NextArea, "Set the current area to the next area.");
cls_HLRBRep_EdgeBuilder.def("PreviousArea", (void (HLRBRep_EdgeBuilder::*)()) &HLRBRep_EdgeBuilder::PreviousArea, "Set the current area to the previous area.");
cls_HLRBRep_EdgeBuilder.def("HasArea", (Standard_Boolean (HLRBRep_EdgeBuilder::*)() const) &HLRBRep_EdgeBuilder::HasArea, "Returns True if there is a current area.");
cls_HLRBRep_EdgeBuilder.def("AreaState", (TopAbs_State (HLRBRep_EdgeBuilder::*)() const) &HLRBRep_EdgeBuilder::AreaState, "Returns the state of the current area.");
cls_HLRBRep_EdgeBuilder.def("AreaEdgeState", (TopAbs_State (HLRBRep_EdgeBuilder::*)() const) &HLRBRep_EdgeBuilder::AreaEdgeState, "Returns the edge state of the current area.");
cls_HLRBRep_EdgeBuilder.def("LeftLimit", (opencascade::handle<HLRBRep_AreaLimit> (HLRBRep_EdgeBuilder::*)() const) &HLRBRep_EdgeBuilder::LeftLimit, "Returns the AreaLimit beginning the current area. This is a NULL handle when the area is infinite on the left.");
cls_HLRBRep_EdgeBuilder.def("RightLimit", (opencascade::handle<HLRBRep_AreaLimit> (HLRBRep_EdgeBuilder::*)() const) &HLRBRep_EdgeBuilder::RightLimit, "Returns the AreaLimit ending the current area. This is a NULL handle when the area is infinite on the right.");
cls_HLRBRep_EdgeBuilder.def("Builds", (void (HLRBRep_EdgeBuilder::*)(const TopAbs_State)) &HLRBRep_EdgeBuilder::Builds, "Reinitialize the results iteration to the parts with State <ToBuild>. If this method is not called after construction the default is <ToBuild> = IN.", py::arg("ToBuild"));
cls_HLRBRep_EdgeBuilder.def("MoreEdges", (Standard_Boolean (HLRBRep_EdgeBuilder::*)() const) &HLRBRep_EdgeBuilder::MoreEdges, "Returns True if there are more new edges to build.");
cls_HLRBRep_EdgeBuilder.def("NextEdge", (void (HLRBRep_EdgeBuilder::*)()) &HLRBRep_EdgeBuilder::NextEdge, "Proceeds to the next edge to build. Skip all remaining vertices on the current edge.");
cls_HLRBRep_EdgeBuilder.def("MoreVertices", (Standard_Boolean (HLRBRep_EdgeBuilder::*)() const) &HLRBRep_EdgeBuilder::MoreVertices, "True if there are more vertices in the current new edge.");
cls_HLRBRep_EdgeBuilder.def("NextVertex", (void (HLRBRep_EdgeBuilder::*)()) &HLRBRep_EdgeBuilder::NextVertex, "Proceeds to the next vertex of the current edge.");
cls_HLRBRep_EdgeBuilder.def("Current", (const HLRAlgo_Intersection & (HLRBRep_EdgeBuilder::*)() const) &HLRBRep_EdgeBuilder::Current, "Returns the current vertex of the current edge.");
cls_HLRBRep_EdgeBuilder.def("IsBoundary", (Standard_Boolean (HLRBRep_EdgeBuilder::*)() const) &HLRBRep_EdgeBuilder::IsBoundary, "Returns True if the current vertex comes from the boundary of the edge.");
cls_HLRBRep_EdgeBuilder.def("IsInterference", (Standard_Boolean (HLRBRep_EdgeBuilder::*)() const) &HLRBRep_EdgeBuilder::IsInterference, "Returns True if the current vertex was an interference.");
cls_HLRBRep_EdgeBuilder.def("Orientation", (TopAbs_Orientation (HLRBRep_EdgeBuilder::*)() const) &HLRBRep_EdgeBuilder::Orientation, "Returns the new orientation of the current vertex.");
cls_HLRBRep_EdgeBuilder.def("Destroy", (void (HLRBRep_EdgeBuilder::*)()) &HLRBRep_EdgeBuilder::Destroy, "None");

// CLASS: HLRBREP_EDGEFACETOOL
py::class_<HLRBRep_EdgeFaceTool> cls_HLRBRep_EdgeFaceTool(mod, "HLRBRep_EdgeFaceTool", "The EdgeFaceTool computes the UV coordinates at a given parameter on a Curve and a Surface. It also compute the signed curvature value in a direction at a given u,v point on a surface.");

// Constructors
cls_HLRBRep_EdgeFaceTool.def(py::init<>());

// Methods
// cls_HLRBRep_EdgeFaceTool.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_EdgeFaceTool::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_EdgeFaceTool.def_static("operator delete_", (void (*)(void *)) &HLRBRep_EdgeFaceTool::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_EdgeFaceTool.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_EdgeFaceTool::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_EdgeFaceTool.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_EdgeFaceTool::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_EdgeFaceTool.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_EdgeFaceTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_EdgeFaceTool.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_EdgeFaceTool::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_EdgeFaceTool.def_static("CurvatureValue_", (Standard_Real (*)(const Standard_Address, const Standard_Real, const Standard_Real, const gp_Dir &)) &HLRBRep_EdgeFaceTool::CurvatureValue, "None", py::arg("F"), py::arg("U"), py::arg("V"), py::arg("Tg"));
cls_HLRBRep_EdgeFaceTool.def_static("UVPoint_", [](const Standard_Real Par, const Standard_Address E, const Standard_Address F, Standard_Real & U, Standard_Real & V){ Standard_Boolean rv = HLRBRep_EdgeFaceTool::UVPoint(Par, E, F, U, V); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, U, V); }, "return True if U and V are found.", py::arg("Par"), py::arg("E"), py::arg("F"), py::arg("U"), py::arg("V"));

// CLASS: HLRBREP_EDGEILIST
py::class_<HLRBRep_EdgeIList> cls_HLRBRep_EdgeIList(mod, "HLRBRep_EdgeIList", "None");

// Constructors
cls_HLRBRep_EdgeIList.def(py::init<>());

// Methods
// cls_HLRBRep_EdgeIList.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_EdgeIList::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_EdgeIList.def_static("operator delete_", (void (*)(void *)) &HLRBRep_EdgeIList::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_EdgeIList.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_EdgeIList::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_EdgeIList.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_EdgeIList::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_EdgeIList.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_EdgeIList::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_EdgeIList.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_EdgeIList::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_EdgeIList.def_static("AddInterference_", (void (*)(HLRAlgo_InterferenceList &, const HLRAlgo_Interference &, const HLRBRep_EdgeInterferenceTool &)) &HLRBRep_EdgeIList::AddInterference, "Add the interference <I> to the list <IL>.", py::arg("IL"), py::arg("I"), py::arg("T"));
cls_HLRBRep_EdgeIList.def_static("ProcessComplex_", (void (*)(HLRAlgo_InterferenceList &, const HLRBRep_EdgeInterferenceTool &)) &HLRBRep_EdgeIList::ProcessComplex, "Process complex transitions on the list IL.", py::arg("IL"), py::arg("T"));

// CLASS: HLRBREP_EDGEINTERFERENCETOOL
py::class_<HLRBRep_EdgeInterferenceTool> cls_HLRBRep_EdgeInterferenceTool(mod, "HLRBRep_EdgeInterferenceTool", "Implements the methods required to instantiates the EdgeInterferenceList from HLRAlgo.");

// Constructors
cls_HLRBRep_EdgeInterferenceTool.def(py::init<const opencascade::handle<HLRBRep_Data> &>(), py::arg("DS"));

// Methods
// cls_HLRBRep_EdgeInterferenceTool.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_EdgeInterferenceTool::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_EdgeInterferenceTool.def_static("operator delete_", (void (*)(void *)) &HLRBRep_EdgeInterferenceTool::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_EdgeInterferenceTool.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_EdgeInterferenceTool::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_EdgeInterferenceTool.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_EdgeInterferenceTool::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_EdgeInterferenceTool.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_EdgeInterferenceTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_EdgeInterferenceTool.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_EdgeInterferenceTool::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_EdgeInterferenceTool.def("LoadEdge", (void (HLRBRep_EdgeInterferenceTool::*)()) &HLRBRep_EdgeInterferenceTool::LoadEdge, "None");
cls_HLRBRep_EdgeInterferenceTool.def("InitVertices", (void (HLRBRep_EdgeInterferenceTool::*)()) &HLRBRep_EdgeInterferenceTool::InitVertices, "None");
cls_HLRBRep_EdgeInterferenceTool.def("MoreVertices", (Standard_Boolean (HLRBRep_EdgeInterferenceTool::*)() const) &HLRBRep_EdgeInterferenceTool::MoreVertices, "None");
cls_HLRBRep_EdgeInterferenceTool.def("NextVertex", (void (HLRBRep_EdgeInterferenceTool::*)()) &HLRBRep_EdgeInterferenceTool::NextVertex, "None");
cls_HLRBRep_EdgeInterferenceTool.def("CurrentVertex", (const HLRAlgo_Intersection & (HLRBRep_EdgeInterferenceTool::*)() const) &HLRBRep_EdgeInterferenceTool::CurrentVertex, "None");
cls_HLRBRep_EdgeInterferenceTool.def("CurrentOrientation", (TopAbs_Orientation (HLRBRep_EdgeInterferenceTool::*)() const) &HLRBRep_EdgeInterferenceTool::CurrentOrientation, "None");
cls_HLRBRep_EdgeInterferenceTool.def("CurrentParameter", (Standard_Real (HLRBRep_EdgeInterferenceTool::*)() const) &HLRBRep_EdgeInterferenceTool::CurrentParameter, "None");
cls_HLRBRep_EdgeInterferenceTool.def("IsPeriodic", (Standard_Boolean (HLRBRep_EdgeInterferenceTool::*)() const) &HLRBRep_EdgeInterferenceTool::IsPeriodic, "None");
cls_HLRBRep_EdgeInterferenceTool.def("EdgeGeometry", [](HLRBRep_EdgeInterferenceTool &self, const Standard_Real Param, gp_Dir & Tgt, gp_Dir & Nrm, Standard_Real & Curv){ self.EdgeGeometry(Param, Tgt, Nrm, Curv); return Curv; }, "Returns local geometric description of the Edge at parameter <Para>. See method Reset of class EdgeFaceTransition from TopCnx for other arguments.", py::arg("Param"), py::arg("Tgt"), py::arg("Nrm"), py::arg("Curv"));
cls_HLRBRep_EdgeInterferenceTool.def("ParameterOfInterference", (Standard_Real (HLRBRep_EdgeInterferenceTool::*)(const HLRAlgo_Interference &) const) &HLRBRep_EdgeInterferenceTool::ParameterOfInterference, "None", py::arg("I"));
cls_HLRBRep_EdgeInterferenceTool.def("SameInterferences", (Standard_Boolean (HLRBRep_EdgeInterferenceTool::*)(const HLRAlgo_Interference &, const HLRAlgo_Interference &) const) &HLRBRep_EdgeInterferenceTool::SameInterferences, "True if the two interferences are on the same geometric locus.", py::arg("I1"), py::arg("I2"));
cls_HLRBRep_EdgeInterferenceTool.def("SameVertexAndInterference", (Standard_Boolean (HLRBRep_EdgeInterferenceTool::*)(const HLRAlgo_Interference &) const) &HLRBRep_EdgeInterferenceTool::SameVertexAndInterference, "True if the Interference and the current Vertex are on the same geometric locus.", py::arg("I"));
cls_HLRBRep_EdgeInterferenceTool.def("InterferenceBoundaryGeometry", [](HLRBRep_EdgeInterferenceTool &self, const HLRAlgo_Interference & I, gp_Dir & Tang, gp_Dir & Norm, Standard_Real & Curv){ self.InterferenceBoundaryGeometry(I, Tang, Norm, Curv); return Curv; }, "Returns the geometry of the boundary at the interference <I>. See the AddInterference method of the class EdgeFaceTransition from TopCnx for the other arguments.", py::arg("I"), py::arg("Tang"), py::arg("Norm"), py::arg("Curv"));

// CLASS: HLRBREP_THEDISTBETWEENPCURVESOFTHEINTPCURVEPCURVEOFCINTER
py::class_<HLRBRep_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfCInter, math_FunctionSetWithDerivatives> cls_HLRBRep_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfCInter(mod, "HLRBRep_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfCInter", "None");

// Constructors
cls_HLRBRep_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfCInter.def(py::init<const Standard_Address &, const Standard_Address &>(), py::arg("curve1"), py::arg("curve2"));

// Methods
// cls_HLRBRep_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfCInter.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfCInter::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfCInter.def_static("operator delete_", (void (*)(void *)) &HLRBRep_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfCInter::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfCInter.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfCInter::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfCInter.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfCInter::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfCInter.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfCInter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfCInter.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfCInter::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfCInter.def("NbVariables", (Standard_Integer (HLRBRep_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfCInter::*)() const) &HLRBRep_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfCInter::NbVariables, "returns 2.");
cls_HLRBRep_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfCInter.def("NbEquations", (Standard_Integer (HLRBRep_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfCInter::*)() const) &HLRBRep_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfCInter::NbEquations, "returns 2.");
cls_HLRBRep_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfCInter.def("Value", (Standard_Boolean (HLRBRep_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfCInter::*)(const math_Vector &, math_Vector &)) &HLRBRep_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfCInter::Value, "computes the values <F> of the Functions for the variable <X>. returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"));
cls_HLRBRep_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfCInter.def("Derivatives", (Standard_Boolean (HLRBRep_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfCInter::*)(const math_Vector &, math_Matrix &)) &HLRBRep_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfCInter::Derivatives, "returns the values <D> of the derivatives for the variable <X>. returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("D"));
cls_HLRBRep_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfCInter.def("Values", (Standard_Boolean (HLRBRep_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfCInter::*)(const math_Vector &, math_Vector &, math_Matrix &)) &HLRBRep_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfCInter::Values, "returns the values <F> of the functions and the derivatives <D> for the variable <X>. returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"), py::arg("D"));

// CLASS: HLRBREP_EXACTINTERSECTIONPOINTOFTHEINTPCURVEPCURVEOFCINTER
py::class_<HLRBRep_ExactIntersectionPointOfTheIntPCurvePCurveOfCInter> cls_HLRBRep_ExactIntersectionPointOfTheIntPCurvePCurveOfCInter(mod, "HLRBRep_ExactIntersectionPointOfTheIntPCurvePCurveOfCInter", "None");

// Constructors
cls_HLRBRep_ExactIntersectionPointOfTheIntPCurvePCurveOfCInter.def(py::init<const Standard_Address &, const Standard_Address &, const Standard_Real>(), py::arg("C1"), py::arg("C2"), py::arg("Tol"));

// Methods
// cls_HLRBRep_ExactIntersectionPointOfTheIntPCurvePCurveOfCInter.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_ExactIntersectionPointOfTheIntPCurvePCurveOfCInter::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_ExactIntersectionPointOfTheIntPCurvePCurveOfCInter.def_static("operator delete_", (void (*)(void *)) &HLRBRep_ExactIntersectionPointOfTheIntPCurvePCurveOfCInter::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_ExactIntersectionPointOfTheIntPCurvePCurveOfCInter.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_ExactIntersectionPointOfTheIntPCurvePCurveOfCInter::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_ExactIntersectionPointOfTheIntPCurvePCurveOfCInter.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_ExactIntersectionPointOfTheIntPCurvePCurveOfCInter::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_ExactIntersectionPointOfTheIntPCurvePCurveOfCInter.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_ExactIntersectionPointOfTheIntPCurvePCurveOfCInter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_ExactIntersectionPointOfTheIntPCurvePCurveOfCInter.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_ExactIntersectionPointOfTheIntPCurvePCurveOfCInter::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_ExactIntersectionPointOfTheIntPCurvePCurveOfCInter.def("Perform", [](HLRBRep_ExactIntersectionPointOfTheIntPCurvePCurveOfCInter &self, const HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter & Poly1, const HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter & Poly2, Standard_Integer & NumSegOn1, Standard_Integer & NumSegOn2, Standard_Real & ParamOnSeg1, Standard_Real & ParamOnSeg2){ self.Perform(Poly1, Poly2, NumSegOn1, NumSegOn2, ParamOnSeg1, ParamOnSeg2); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Real &, Standard_Real &>(NumSegOn1, NumSegOn2, ParamOnSeg1, ParamOnSeg2); }, "None", py::arg("Poly1"), py::arg("Poly2"), py::arg("NumSegOn1"), py::arg("NumSegOn2"), py::arg("ParamOnSeg1"), py::arg("ParamOnSeg2"));
cls_HLRBRep_ExactIntersectionPointOfTheIntPCurvePCurveOfCInter.def("Perform", (void (HLRBRep_ExactIntersectionPointOfTheIntPCurvePCurveOfCInter::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &HLRBRep_ExactIntersectionPointOfTheIntPCurvePCurveOfCInter::Perform, "None", py::arg("Uo"), py::arg("Vo"), py::arg("UInf"), py::arg("VInf"), py::arg("USup"), py::arg("VSup"));
cls_HLRBRep_ExactIntersectionPointOfTheIntPCurvePCurveOfCInter.def("NbRoots", (Standard_Integer (HLRBRep_ExactIntersectionPointOfTheIntPCurvePCurveOfCInter::*)() const) &HLRBRep_ExactIntersectionPointOfTheIntPCurvePCurveOfCInter::NbRoots, "None");
cls_HLRBRep_ExactIntersectionPointOfTheIntPCurvePCurveOfCInter.def("Roots", [](HLRBRep_ExactIntersectionPointOfTheIntPCurvePCurveOfCInter &self, Standard_Real & U, Standard_Real & V){ self.Roots(U, V); return std::tuple<Standard_Real &, Standard_Real &>(U, V); }, "None", py::arg("U"), py::arg("V"));
cls_HLRBRep_ExactIntersectionPointOfTheIntPCurvePCurveOfCInter.def("AnErrorOccurred", (Standard_Boolean (HLRBRep_ExactIntersectionPointOfTheIntPCurvePCurveOfCInter::*)() const) &HLRBRep_ExactIntersectionPointOfTheIntPCurvePCurveOfCInter::AnErrorOccurred, "None");

// CLASS: HLRBREP_HIDER
py::class_<HLRBRep_Hider> cls_HLRBRep_Hider(mod, "HLRBRep_Hider", "None");

// Constructors
cls_HLRBRep_Hider.def(py::init<const opencascade::handle<HLRBRep_Data> &>(), py::arg("DS"));

// Methods
// cls_HLRBRep_Hider.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_Hider::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_Hider.def_static("operator delete_", (void (*)(void *)) &HLRBRep_Hider::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_Hider.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_Hider::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_Hider.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_Hider::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_Hider.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_Hider::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_Hider.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_Hider::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_Hider.def("OwnHiding", (void (HLRBRep_Hider::*)(const Standard_Integer)) &HLRBRep_Hider::OwnHiding, "own hiding the side face number <FI>.", py::arg("FI"));
cls_HLRBRep_Hider.def("Hide", (void (HLRBRep_Hider::*)(const Standard_Integer, BRepTopAdaptor_MapOfShapeTool &)) &HLRBRep_Hider::Hide, "Removes from the edges, the parts hidden by the hiding face number <FI>.", py::arg("FI"), py::arg("MST"));

// CLASS: HLRBREP_HLRTOSHAPE
py::class_<HLRBRep_HLRToShape> cls_HLRBRep_HLRToShape(mod, "HLRBRep_HLRToShape", "A framework for filtering the computation results of an HLRBRep_Algo algorithm by extraction. From the results calculated by the algorithm on a shape, a filter returns the type of edge you want to identify. You can choose any of the following types of output: - visible sharp edges - hidden sharp edges - visible smooth edges - hidden smooth edges - visible sewn edges - hidden sewn edges - visible outline edges - hidden outline edges. - visible isoparameters and - hidden isoparameters. Sharp edges present a C0 continuity (non G1). Smooth edges present a G1 continuity (non G2). Sewn edges present a C2 continuity. The result is composed of 2D edges in the projection plane of the view which the algorithm has worked with. These 2D edges are not included in the data structure of the visualized shape. In order to obtain a complete image, you must combine the shapes given by each of the chosen filters. The construction of the shape does not call a new computation of the algorithm, but only reads its internal results. The methods of this shape are almost identic to those of the HLRBrep_PolyHLRToShape class.");

// Constructors
cls_HLRBRep_HLRToShape.def(py::init<const opencascade::handle<HLRBRep_Algo> &>(), py::arg("A"));

// Methods
// cls_HLRBRep_HLRToShape.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_HLRToShape::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_HLRToShape.def_static("operator delete_", (void (*)(void *)) &HLRBRep_HLRToShape::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_HLRToShape.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_HLRToShape::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_HLRToShape.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_HLRToShape::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_HLRToShape.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_HLRToShape::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_HLRToShape.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_HLRToShape::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_HLRToShape.def("VCompound", (TopoDS_Shape (HLRBRep_HLRToShape::*)()) &HLRBRep_HLRToShape::VCompound, "None");
cls_HLRBRep_HLRToShape.def("VCompound", (TopoDS_Shape (HLRBRep_HLRToShape::*)(const TopoDS_Shape &)) &HLRBRep_HLRToShape::VCompound, "None", py::arg("S"));
cls_HLRBRep_HLRToShape.def("Rg1LineVCompound", (TopoDS_Shape (HLRBRep_HLRToShape::*)()) &HLRBRep_HLRToShape::Rg1LineVCompound, "None");
cls_HLRBRep_HLRToShape.def("Rg1LineVCompound", (TopoDS_Shape (HLRBRep_HLRToShape::*)(const TopoDS_Shape &)) &HLRBRep_HLRToShape::Rg1LineVCompound, "None", py::arg("S"));
cls_HLRBRep_HLRToShape.def("RgNLineVCompound", (TopoDS_Shape (HLRBRep_HLRToShape::*)()) &HLRBRep_HLRToShape::RgNLineVCompound, "None");
cls_HLRBRep_HLRToShape.def("RgNLineVCompound", (TopoDS_Shape (HLRBRep_HLRToShape::*)(const TopoDS_Shape &)) &HLRBRep_HLRToShape::RgNLineVCompound, "None", py::arg("S"));
cls_HLRBRep_HLRToShape.def("OutLineVCompound", (TopoDS_Shape (HLRBRep_HLRToShape::*)()) &HLRBRep_HLRToShape::OutLineVCompound, "None");
cls_HLRBRep_HLRToShape.def("OutLineVCompound3d", (TopoDS_Shape (HLRBRep_HLRToShape::*)()) &HLRBRep_HLRToShape::OutLineVCompound3d, "None");
cls_HLRBRep_HLRToShape.def("OutLineVCompound", (TopoDS_Shape (HLRBRep_HLRToShape::*)(const TopoDS_Shape &)) &HLRBRep_HLRToShape::OutLineVCompound, "None", py::arg("S"));
cls_HLRBRep_HLRToShape.def("IsoLineVCompound", (TopoDS_Shape (HLRBRep_HLRToShape::*)()) &HLRBRep_HLRToShape::IsoLineVCompound, "None");
cls_HLRBRep_HLRToShape.def("IsoLineVCompound", (TopoDS_Shape (HLRBRep_HLRToShape::*)(const TopoDS_Shape &)) &HLRBRep_HLRToShape::IsoLineVCompound, "None", py::arg("S"));
cls_HLRBRep_HLRToShape.def("HCompound", (TopoDS_Shape (HLRBRep_HLRToShape::*)()) &HLRBRep_HLRToShape::HCompound, "None");
cls_HLRBRep_HLRToShape.def("HCompound", (TopoDS_Shape (HLRBRep_HLRToShape::*)(const TopoDS_Shape &)) &HLRBRep_HLRToShape::HCompound, "None", py::arg("S"));
cls_HLRBRep_HLRToShape.def("Rg1LineHCompound", (TopoDS_Shape (HLRBRep_HLRToShape::*)()) &HLRBRep_HLRToShape::Rg1LineHCompound, "None");
cls_HLRBRep_HLRToShape.def("Rg1LineHCompound", (TopoDS_Shape (HLRBRep_HLRToShape::*)(const TopoDS_Shape &)) &HLRBRep_HLRToShape::Rg1LineHCompound, "None", py::arg("S"));
cls_HLRBRep_HLRToShape.def("RgNLineHCompound", (TopoDS_Shape (HLRBRep_HLRToShape::*)()) &HLRBRep_HLRToShape::RgNLineHCompound, "None");
cls_HLRBRep_HLRToShape.def("RgNLineHCompound", (TopoDS_Shape (HLRBRep_HLRToShape::*)(const TopoDS_Shape &)) &HLRBRep_HLRToShape::RgNLineHCompound, "None", py::arg("S"));
cls_HLRBRep_HLRToShape.def("OutLineHCompound", (TopoDS_Shape (HLRBRep_HLRToShape::*)()) &HLRBRep_HLRToShape::OutLineHCompound, "None");
cls_HLRBRep_HLRToShape.def("OutLineHCompound", (TopoDS_Shape (HLRBRep_HLRToShape::*)(const TopoDS_Shape &)) &HLRBRep_HLRToShape::OutLineHCompound, "None", py::arg("S"));
cls_HLRBRep_HLRToShape.def("IsoLineHCompound", (TopoDS_Shape (HLRBRep_HLRToShape::*)()) &HLRBRep_HLRToShape::IsoLineHCompound, "None");
cls_HLRBRep_HLRToShape.def("IsoLineHCompound", (TopoDS_Shape (HLRBRep_HLRToShape::*)(const TopoDS_Shape &)) &HLRBRep_HLRToShape::IsoLineHCompound, "None", py::arg("S"));
cls_HLRBRep_HLRToShape.def("CompoundOfEdges", (TopoDS_Shape (HLRBRep_HLRToShape::*)(const HLRBRep_TypeOfResultingEdge, const Standard_Boolean, const Standard_Boolean)) &HLRBRep_HLRToShape::CompoundOfEdges, "Returns compound of resulting edges of required type and visibility, taking into account the kind of space (2d or 3d)", py::arg("type"), py::arg("visible"), py::arg("In3d"));
cls_HLRBRep_HLRToShape.def("CompoundOfEdges", (TopoDS_Shape (HLRBRep_HLRToShape::*)(const TopoDS_Shape &, const HLRBRep_TypeOfResultingEdge, const Standard_Boolean, const Standard_Boolean)) &HLRBRep_HLRToShape::CompoundOfEdges, "For specified shape returns compound of resulting edges of required type and visibility, taking into account the kind of space (2d or 3d)", py::arg("S"), py::arg("type"), py::arg("visible"), py::arg("In3d"));

// CLASS: HLRBREP_INTCONICCURVEOFCINTER
py::class_<HLRBRep_IntConicCurveOfCInter, IntRes2d_Intersection> cls_HLRBRep_IntConicCurveOfCInter(mod, "HLRBRep_IntConicCurveOfCInter", "None");

// Constructors
cls_HLRBRep_IntConicCurveOfCInter.def(py::init<>());
cls_HLRBRep_IntConicCurveOfCInter.def(py::init<const gp_Lin2d &, const IntRes2d_Domain &, const Standard_Address &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real>(), py::arg("L"), py::arg("D1"), py::arg("PCurve"), py::arg("D2"), py::arg("TolConf"), py::arg("Tol"));
cls_HLRBRep_IntConicCurveOfCInter.def(py::init<const gp_Circ2d &, const IntRes2d_Domain &, const Standard_Address &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("D1"), py::arg("PCurve"), py::arg("D2"), py::arg("TolConf"), py::arg("Tol"));
cls_HLRBRep_IntConicCurveOfCInter.def(py::init<const gp_Elips2d &, const IntRes2d_Domain &, const Standard_Address &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real>(), py::arg("E"), py::arg("D1"), py::arg("PCurve"), py::arg("D2"), py::arg("TolConf"), py::arg("Tol"));
cls_HLRBRep_IntConicCurveOfCInter.def(py::init<const gp_Parab2d &, const IntRes2d_Domain &, const Standard_Address &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real>(), py::arg("Prb"), py::arg("D1"), py::arg("PCurve"), py::arg("D2"), py::arg("TolConf"), py::arg("Tol"));
cls_HLRBRep_IntConicCurveOfCInter.def(py::init<const gp_Hypr2d &, const IntRes2d_Domain &, const Standard_Address &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real>(), py::arg("H"), py::arg("D1"), py::arg("PCurve"), py::arg("D2"), py::arg("TolConf"), py::arg("Tol"));

// Methods
// cls_HLRBRep_IntConicCurveOfCInter.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_IntConicCurveOfCInter::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_IntConicCurveOfCInter.def_static("operator delete_", (void (*)(void *)) &HLRBRep_IntConicCurveOfCInter::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_IntConicCurveOfCInter.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_IntConicCurveOfCInter::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_IntConicCurveOfCInter.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_IntConicCurveOfCInter::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_IntConicCurveOfCInter.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_IntConicCurveOfCInter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_IntConicCurveOfCInter.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_IntConicCurveOfCInter::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_IntConicCurveOfCInter.def("Perform", (void (HLRBRep_IntConicCurveOfCInter::*)(const gp_Lin2d &, const IntRes2d_Domain &, const Standard_Address &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real)) &HLRBRep_IntConicCurveOfCInter::Perform, "Intersection between a line and a parametric curve.", py::arg("L"), py::arg("D1"), py::arg("PCurve"), py::arg("D2"), py::arg("TolConf"), py::arg("Tol"));
cls_HLRBRep_IntConicCurveOfCInter.def("Perform", (void (HLRBRep_IntConicCurveOfCInter::*)(const gp_Circ2d &, const IntRes2d_Domain &, const Standard_Address &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real)) &HLRBRep_IntConicCurveOfCInter::Perform, "Intersection between a line and a parametric curve.", py::arg("C"), py::arg("D1"), py::arg("PCurve"), py::arg("D2"), py::arg("TolConf"), py::arg("Tol"));
cls_HLRBRep_IntConicCurveOfCInter.def("Perform", (void (HLRBRep_IntConicCurveOfCInter::*)(const gp_Elips2d &, const IntRes2d_Domain &, const Standard_Address &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real)) &HLRBRep_IntConicCurveOfCInter::Perform, "Intersection between an ellipse and a parametric curve.", py::arg("E"), py::arg("D1"), py::arg("PCurve"), py::arg("D2"), py::arg("TolConf"), py::arg("Tol"));
cls_HLRBRep_IntConicCurveOfCInter.def("Perform", (void (HLRBRep_IntConicCurveOfCInter::*)(const gp_Parab2d &, const IntRes2d_Domain &, const Standard_Address &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real)) &HLRBRep_IntConicCurveOfCInter::Perform, "Intersection between a parabola and a parametric curve.", py::arg("Prb"), py::arg("D1"), py::arg("PCurve"), py::arg("D2"), py::arg("TolConf"), py::arg("Tol"));
cls_HLRBRep_IntConicCurveOfCInter.def("Perform", (void (HLRBRep_IntConicCurveOfCInter::*)(const gp_Hypr2d &, const IntRes2d_Domain &, const Standard_Address &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real)) &HLRBRep_IntConicCurveOfCInter::Perform, "Intersection between the main branch of an hyperbola and a parametric curve.", py::arg("H"), py::arg("D1"), py::arg("PCurve"), py::arg("D2"), py::arg("TolConf"), py::arg("Tol"));

// CLASS: HLRBREP_LINETOOL
py::class_<HLRBRep_LineTool> cls_HLRBRep_LineTool(mod, "HLRBRep_LineTool", "The LineTool class provides class methods to access the methodes of the Line.");

// Constructors
cls_HLRBRep_LineTool.def(py::init<>());

// Methods
// cls_HLRBRep_LineTool.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_LineTool::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_LineTool.def_static("operator delete_", (void (*)(void *)) &HLRBRep_LineTool::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_LineTool.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_LineTool::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_LineTool.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_LineTool::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_LineTool.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_LineTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_LineTool.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_LineTool::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_LineTool.def_static("FirstParameter_", (Standard_Real (*)(const gp_Lin &)) &HLRBRep_LineTool::FirstParameter, "None", py::arg("C"));
cls_HLRBRep_LineTool.def_static("LastParameter_", (Standard_Real (*)(const gp_Lin &)) &HLRBRep_LineTool::LastParameter, "None", py::arg("C"));
cls_HLRBRep_LineTool.def_static("Continuity_", (GeomAbs_Shape (*)(const gp_Lin &)) &HLRBRep_LineTool::Continuity, "None", py::arg("C"));
cls_HLRBRep_LineTool.def_static("NbIntervals_", (Standard_Integer (*)(const gp_Lin &, const GeomAbs_Shape)) &HLRBRep_LineTool::NbIntervals, "If necessary, breaks the line in intervals of continuity <S>. And returns the number of intervals.", py::arg("C"), py::arg("S"));
cls_HLRBRep_LineTool.def_static("Intervals_", (void (*)(const gp_Lin &, TColStd_Array1OfReal &, const GeomAbs_Shape)) &HLRBRep_LineTool::Intervals, "Sets the current working interval.", py::arg("C"), py::arg("T"), py::arg("Sh"));
cls_HLRBRep_LineTool.def_static("IntervalFirst_", (Standard_Real (*)(const gp_Lin &)) &HLRBRep_LineTool::IntervalFirst, "Returns the first parameter of the current interval.", py::arg("C"));
cls_HLRBRep_LineTool.def_static("IntervalLast_", (Standard_Real (*)(const gp_Lin &)) &HLRBRep_LineTool::IntervalLast, "Returns the last parameter of the current interval.", py::arg("C"));
cls_HLRBRep_LineTool.def_static("IntervalContinuity_", (GeomAbs_Shape (*)(const gp_Lin &)) &HLRBRep_LineTool::IntervalContinuity, "None", py::arg("C"));
cls_HLRBRep_LineTool.def_static("IsClosed_", (Standard_Boolean (*)(const gp_Lin &)) &HLRBRep_LineTool::IsClosed, "None", py::arg("C"));
cls_HLRBRep_LineTool.def_static("IsPeriodic_", (Standard_Boolean (*)(const gp_Lin &)) &HLRBRep_LineTool::IsPeriodic, "None", py::arg("C"));
cls_HLRBRep_LineTool.def_static("Period_", (Standard_Real (*)(const gp_Lin &)) &HLRBRep_LineTool::Period, "None", py::arg("C"));
cls_HLRBRep_LineTool.def_static("Value_", (gp_Pnt (*)(const gp_Lin &, const Standard_Real)) &HLRBRep_LineTool::Value, "Computes the point of parameter U on the line.", py::arg("C"), py::arg("U"));
cls_HLRBRep_LineTool.def_static("D0_", (void (*)(const gp_Lin &, const Standard_Real, gp_Pnt &)) &HLRBRep_LineTool::D0, "Computes the point of parameter U on the line.", py::arg("C"), py::arg("U"), py::arg("P"));
cls_HLRBRep_LineTool.def_static("D1_", (void (*)(const gp_Lin &, const Standard_Real, gp_Pnt &, gp_Vec &)) &HLRBRep_LineTool::D1, "Computes the point of parameter U on the line with its first derivative. Raised if the continuity of the current interval is not C1.", py::arg("C"), py::arg("U"), py::arg("P"), py::arg("V"));
cls_HLRBRep_LineTool.def_static("D2_", (void (*)(const gp_Lin &, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &)) &HLRBRep_LineTool::D2, "Returns the point P of parameter U, the first and second derivatives V1 and V2. Raised if the continuity of the current interval is not C2.", py::arg("C"), py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"));
cls_HLRBRep_LineTool.def_static("D3_", (void (*)(const gp_Lin &, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &)) &HLRBRep_LineTool::D3, "Returns the point P of parameter U, the first, the second and the third derivative. Raised if the continuity of the current interval is not C3.", py::arg("C"), py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"));
cls_HLRBRep_LineTool.def_static("DN_", (gp_Vec (*)(const gp_Lin &, const Standard_Real, const Standard_Integer)) &HLRBRep_LineTool::DN, "The returned vector gives the value of the derivative for the order of derivation N. Raised if the continuity of the current interval is not CN. Raised if N < 1.", py::arg("C"), py::arg("U"), py::arg("N"));
cls_HLRBRep_LineTool.def_static("Resolution_", (Standard_Real (*)(const gp_Lin &, const Standard_Real)) &HLRBRep_LineTool::Resolution, "Returns the parametric resolution corresponding to the real space resolution <R3d>.", py::arg("C"), py::arg("R3d"));
cls_HLRBRep_LineTool.def_static("GetType_", (GeomAbs_CurveType (*)(const gp_Lin &)) &HLRBRep_LineTool::GetType, "Returns the type of the line in the current interval : Line, Circle, Ellipse, Hyperbola, Parabola, BezierCurve, BSplineCurve, OtherCurve.", py::arg("C"));
cls_HLRBRep_LineTool.def_static("Line_", (gp_Lin (*)(const gp_Lin &)) &HLRBRep_LineTool::Line, "None", py::arg("C"));
cls_HLRBRep_LineTool.def_static("Circle_", (gp_Circ (*)(const gp_Lin &)) &HLRBRep_LineTool::Circle, "None", py::arg("C"));
cls_HLRBRep_LineTool.def_static("Ellipse_", (gp_Elips (*)(const gp_Lin &)) &HLRBRep_LineTool::Ellipse, "None", py::arg("C"));
cls_HLRBRep_LineTool.def_static("Hyperbola_", (gp_Hypr (*)(const gp_Lin &)) &HLRBRep_LineTool::Hyperbola, "None", py::arg("C"));
cls_HLRBRep_LineTool.def_static("Parabola_", (gp_Parab (*)(const gp_Lin &)) &HLRBRep_LineTool::Parabola, "None", py::arg("C"));
cls_HLRBRep_LineTool.def_static("Bezier_", (opencascade::handle<Geom_BezierCurve> (*)(const gp_Lin &)) &HLRBRep_LineTool::Bezier, "None", py::arg("C"));
cls_HLRBRep_LineTool.def_static("BSpline_", (opencascade::handle<Geom_BSplineCurve> (*)(const gp_Lin &)) &HLRBRep_LineTool::BSpline, "None", py::arg("C"));
cls_HLRBRep_LineTool.def_static("Degree_", (Standard_Integer (*)(const gp_Lin &)) &HLRBRep_LineTool::Degree, "None", py::arg("C"));
cls_HLRBRep_LineTool.def_static("NbPoles_", (Standard_Integer (*)(const gp_Lin &)) &HLRBRep_LineTool::NbPoles, "None", py::arg("C"));
cls_HLRBRep_LineTool.def_static("Poles_", (void (*)(const gp_Lin &, TColgp_Array1OfPnt &)) &HLRBRep_LineTool::Poles, "None", py::arg("C"), py::arg("TP"));
cls_HLRBRep_LineTool.def_static("IsRational_", (Standard_Boolean (*)(const gp_Lin &)) &HLRBRep_LineTool::IsRational, "None", py::arg("C"));
cls_HLRBRep_LineTool.def_static("PolesAndWeights_", (void (*)(const gp_Lin &, TColgp_Array1OfPnt &, TColStd_Array1OfReal &)) &HLRBRep_LineTool::PolesAndWeights, "None", py::arg("C"), py::arg("TP"), py::arg("TW"));
cls_HLRBRep_LineTool.def_static("NbKnots_", (Standard_Integer (*)(const gp_Lin &)) &HLRBRep_LineTool::NbKnots, "None", py::arg("C"));
cls_HLRBRep_LineTool.def_static("KnotsAndMultiplicities_", (void (*)(const gp_Lin &, TColStd_Array1OfReal &, TColStd_Array1OfInteger &)) &HLRBRep_LineTool::KnotsAndMultiplicities, "None", py::arg("C"), py::arg("TK"), py::arg("TM"));
cls_HLRBRep_LineTool.def_static("NbSamples_", (Standard_Integer (*)(const gp_Lin &, const Standard_Real, const Standard_Real)) &HLRBRep_LineTool::NbSamples, "None", py::arg("C"), py::arg("U0"), py::arg("U1"));
cls_HLRBRep_LineTool.def_static("SamplePars_", (void (*)(const gp_Lin &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer, opencascade::handle<TColStd_HArray1OfReal> &)) &HLRBRep_LineTool::SamplePars, "None", py::arg("C"), py::arg("U0"), py::arg("U1"), py::arg("Defl"), py::arg("NbMin"), py::arg("Pars"));

// TYPEDEF: HLRBREP_LISTOFBPNT2D
bind_NCollection_List<HLRBRep_BiPnt2D>(mod, "HLRBRep_ListOfBPnt2D", py::module_local(false));

// TYPEDEF: HLRBREP_LISTITERATOROFLISTOFBPNT2D
bind_NCollection_TListIterator<HLRBRep_BiPnt2D>(mod, "HLRBRep_ListIteratorOfListOfBPnt2D", py::module_local(false));

// TYPEDEF: HLRBREP_LISTOFBPOINT
bind_NCollection_List<HLRBRep_BiPoint>(mod, "HLRBRep_ListOfBPoint", py::module_local(false));

// TYPEDEF: HLRBREP_LISTITERATOROFLISTOFBPOINT
bind_NCollection_TListIterator<HLRBRep_BiPoint>(mod, "HLRBRep_ListIteratorOfListOfBPoint", py::module_local(false));

// CLASS: HLRBREP_MYIMPPARTOOLOFTHEINTERSECTOROFTHEINTCONICCURVEOFCINTER
py::class_<HLRBRep_MyImpParToolOfTheIntersectorOfTheIntConicCurveOfCInter, math_FunctionWithDerivative> cls_HLRBRep_MyImpParToolOfTheIntersectorOfTheIntConicCurveOfCInter(mod, "HLRBRep_MyImpParToolOfTheIntersectorOfTheIntConicCurveOfCInter", "None");

// Constructors
cls_HLRBRep_MyImpParToolOfTheIntersectorOfTheIntConicCurveOfCInter.def(py::init<const IntCurve_IConicTool &, const Standard_Address &>(), py::arg("IT"), py::arg("PC"));

// Methods
// cls_HLRBRep_MyImpParToolOfTheIntersectorOfTheIntConicCurveOfCInter.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_MyImpParToolOfTheIntersectorOfTheIntConicCurveOfCInter::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_MyImpParToolOfTheIntersectorOfTheIntConicCurveOfCInter.def_static("operator delete_", (void (*)(void *)) &HLRBRep_MyImpParToolOfTheIntersectorOfTheIntConicCurveOfCInter::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_MyImpParToolOfTheIntersectorOfTheIntConicCurveOfCInter.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_MyImpParToolOfTheIntersectorOfTheIntConicCurveOfCInter::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_MyImpParToolOfTheIntersectorOfTheIntConicCurveOfCInter.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_MyImpParToolOfTheIntersectorOfTheIntConicCurveOfCInter::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_MyImpParToolOfTheIntersectorOfTheIntConicCurveOfCInter.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_MyImpParToolOfTheIntersectorOfTheIntConicCurveOfCInter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_MyImpParToolOfTheIntersectorOfTheIntConicCurveOfCInter.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_MyImpParToolOfTheIntersectorOfTheIntConicCurveOfCInter::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_MyImpParToolOfTheIntersectorOfTheIntConicCurveOfCInter.def("Value", [](HLRBRep_MyImpParToolOfTheIntersectorOfTheIntConicCurveOfCInter &self, const Standard_Real Param, Standard_Real & F){ Standard_Boolean rv = self.Value(Param, F); return std::tuple<Standard_Boolean, Standard_Real &>(rv, F); }, "Computes the value of the signed distance between the implicit curve and the point at parameter Param on the parametrised curve.", py::arg("Param"), py::arg("F"));
cls_HLRBRep_MyImpParToolOfTheIntersectorOfTheIntConicCurveOfCInter.def("Derivative", [](HLRBRep_MyImpParToolOfTheIntersectorOfTheIntConicCurveOfCInter &self, const Standard_Real Param, Standard_Real & D){ Standard_Boolean rv = self.Derivative(Param, D); return std::tuple<Standard_Boolean, Standard_Real &>(rv, D); }, "Computes the derivative of the previous function at parameter Param.", py::arg("Param"), py::arg("D"));
cls_HLRBRep_MyImpParToolOfTheIntersectorOfTheIntConicCurveOfCInter.def("Values", [](HLRBRep_MyImpParToolOfTheIntersectorOfTheIntConicCurveOfCInter &self, const Standard_Real Param, Standard_Real & F, Standard_Real & D){ Standard_Boolean rv = self.Values(Param, F, D); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, F, D); }, "Computes the value and the derivative of the function.", py::arg("Param"), py::arg("F"), py::arg("D"));

// CLASS: HLRBREP_PCLOCFOFTHELOCATEEXTPCOFTHEPROJPCUROFCINTER
py::class_<HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter, math_FunctionWithDerivative> cls_HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter(mod, "HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter", "None");

// Constructors
cls_HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter.def(py::init<>());
cls_HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter.def(py::init<const gp_Pnt2d &, const Standard_Address &>(), py::arg("P"), py::arg("C"));

// Methods
// cls_HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter.def_static("operator delete_", (void (*)(void *)) &HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter.def("Initialize", (void (HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter::*)(const Standard_Address &)) &HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter::Initialize, "sets the field mycurve of the function.", py::arg("C"));
cls_HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter.def("SetPoint", (void (HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter::*)(const gp_Pnt2d &)) &HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter::SetPoint, "sets the field P of the function.", py::arg("P"));
cls_HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter.def("Value", [](HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter &self, const Standard_Real U, Standard_Real & F){ Standard_Boolean rv = self.Value(U, F); return std::tuple<Standard_Boolean, Standard_Real &>(rv, F); }, "Calculation of F(U).", py::arg("U"), py::arg("F"));
cls_HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter.def("Derivative", [](HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter &self, const Standard_Real U, Standard_Real & DF){ Standard_Boolean rv = self.Derivative(U, DF); return std::tuple<Standard_Boolean, Standard_Real &>(rv, DF); }, "Calculation of F'(U).", py::arg("U"), py::arg("DF"));
cls_HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter.def("Values", [](HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter &self, const Standard_Real U, Standard_Real & F, Standard_Real & DF){ Standard_Boolean rv = self.Values(U, F, DF); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, F, DF); }, "Calculation of F(U) and F'(U).", py::arg("U"), py::arg("F"), py::arg("DF"));
cls_HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter.def("GetStateNumber", (Standard_Integer (HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter::*)()) &HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter::GetStateNumber, "Save the found extremum.");
cls_HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter.def("NbExt", (Standard_Integer (HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter::*)() const) &HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter::NbExt, "Return the nunber of found extrema.");
cls_HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter.def("SquareDistance", (Standard_Real (HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter::*)(const Standard_Integer) const) &HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter::SquareDistance, "Returns the Nth distance.", py::arg("N"));
cls_HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter.def("IsMin", (Standard_Boolean (HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter::*)(const Standard_Integer) const) &HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter::IsMin, "Shows if the Nth distance is a minimum.", py::arg("N"));
cls_HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter.def("Point", (const Extrema_POnCurv2d & (HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter::*)(const Standard_Integer) const) &HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter::Point, "Returns the Nth extremum.", py::arg("N"));
cls_HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter.def("SubIntervalInitialize", (void (HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter::*)(const Standard_Real, const Standard_Real)) &HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter::SubIntervalInitialize, "Determines boundaries of subinterval for find of root.", py::arg("theUfirst"), py::arg("theUlast"));
cls_HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter.def("SearchOfTolerance", (Standard_Real (HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter::*)()) &HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter::SearchOfTolerance, "Computes a Tol value. If 1st derivative of curve |D1|<Tol, it is considered D1=0.");

// CLASS: HLRBREP_POLYALGO
py::class_<HLRBRep_PolyAlgo, opencascade::handle<HLRBRep_PolyAlgo>, Standard_Transient> cls_HLRBRep_PolyAlgo(mod, "HLRBRep_PolyAlgo", "to remove Hidden lines on Shapes with Triangulations. A framework to compute the shape as seen in a projection plane. This is done by calculating the visible and the hidden parts of the shape. HLRBRep_PolyAlgo works with three types of entity: - shapes to be visualized (these shapes must have already been triangulated.) - edges in these shapes (these edges are defined as polygonal lines on the triangulation of the shape, and are the basic entities which will be visualized or hidden), and - triangles in these shapes which hide the edges. HLRBRep_PolyAlgo is based on the principle of comparing each edge of the shape to be visualized with each of the triangles produced by the triangulation of the shape, and calculating the visible and the hidden parts of each edge. For a given projection, HLRBRep_PolyAlgo calculates a set of lines characteristic of the object being represented. It is also used in conjunction with the HLRBRep_PolyHLRToShape extraction utilities, which reconstruct a new, simplified shape from a selection of calculation results. This new shape is made up of edges, which represent the shape visualized in the projection. HLRBRep_PolyAlgo works with a polyhedral simplification of the shape whereas HLRBRep_Algo takes the shape itself into account. When you use HLRBRep_Algo, you obtain an exact result, whereas, when you use HLRBRep_PolyAlgo, you reduce computation time but obtain polygonal segments. An HLRBRep_PolyAlgo object provides a framework for: - defining the point of view - identifying the shape or shapes to be visualized - calculating the outlines - calculating the visible and hidden lines of the shape. Warning - Superimposed lines are not eliminated by this algorithm. - There must be no unfinished objects inside the shape you wish to visualize. - Points are not treated. - Note that this is not the sort of algorithm used in generating shading, which calculates the visible and hidden parts of each face in a shape to be visualized by comparing each face in the shape with every other face in the same shape.");

// Constructors
cls_HLRBRep_PolyAlgo.def(py::init<>());
cls_HLRBRep_PolyAlgo.def(py::init<const opencascade::handle<HLRBRep_PolyAlgo> &>(), py::arg("A"));
cls_HLRBRep_PolyAlgo.def(py::init<const TopoDS_Shape &>(), py::arg("S"));

// Methods
cls_HLRBRep_PolyAlgo.def("NbShapes", (Standard_Integer (HLRBRep_PolyAlgo::*)() const) &HLRBRep_PolyAlgo::NbShapes, "None");
cls_HLRBRep_PolyAlgo.def("Shape", (TopoDS_Shape & (HLRBRep_PolyAlgo::*)(const Standard_Integer)) &HLRBRep_PolyAlgo::Shape, "None", py::arg("I"));
cls_HLRBRep_PolyAlgo.def("Remove", (void (HLRBRep_PolyAlgo::*)(const Standard_Integer)) &HLRBRep_PolyAlgo::Remove, "remove the Shape of Index <I>.", py::arg("I"));
cls_HLRBRep_PolyAlgo.def("Index", (Standard_Integer (HLRBRep_PolyAlgo::*)(const TopoDS_Shape &) const) &HLRBRep_PolyAlgo::Index, "return the index of the Shape <S> and return 0 if the Shape <S> is not found.", py::arg("S"));
cls_HLRBRep_PolyAlgo.def("Load", (void (HLRBRep_PolyAlgo::*)(const TopoDS_Shape &)) &HLRBRep_PolyAlgo::Load, "Loads the shape S into this framework. Warning S must have already been triangulated.", py::arg("S"));
cls_HLRBRep_PolyAlgo.def("Algo", (opencascade::handle<HLRAlgo_PolyAlgo> (HLRBRep_PolyAlgo::*)() const) &HLRBRep_PolyAlgo::Algo, "None");
cls_HLRBRep_PolyAlgo.def("Projector", (const HLRAlgo_Projector & (HLRBRep_PolyAlgo::*)() const) &HLRBRep_PolyAlgo::Projector, "Sets the parameters of the view for this framework. These parameters are defined by an HLRAlgo_Projector object, which is returned by the Projector function on a Prs3d_Projector object.");
cls_HLRBRep_PolyAlgo.def("Projector", (void (HLRBRep_PolyAlgo::*)(const HLRAlgo_Projector &)) &HLRBRep_PolyAlgo::Projector, "None", py::arg("P"));
cls_HLRBRep_PolyAlgo.def("Angle", (Standard_Real (HLRBRep_PolyAlgo::*)() const) &HLRBRep_PolyAlgo::Angle, "None");
cls_HLRBRep_PolyAlgo.def("Angle", (void (HLRBRep_PolyAlgo::*)(const Standard_Real)) &HLRBRep_PolyAlgo::Angle, "None", py::arg("Ang"));
cls_HLRBRep_PolyAlgo.def("TolAngular", (Standard_Real (HLRBRep_PolyAlgo::*)() const) &HLRBRep_PolyAlgo::TolAngular, "None");
cls_HLRBRep_PolyAlgo.def("TolAngular", (void (HLRBRep_PolyAlgo::*)(const Standard_Real)) &HLRBRep_PolyAlgo::TolAngular, "None", py::arg("Tol"));
cls_HLRBRep_PolyAlgo.def("TolCoef", (Standard_Real (HLRBRep_PolyAlgo::*)() const) &HLRBRep_PolyAlgo::TolCoef, "None");
cls_HLRBRep_PolyAlgo.def("TolCoef", (void (HLRBRep_PolyAlgo::*)(const Standard_Real)) &HLRBRep_PolyAlgo::TolCoef, "None", py::arg("Tol"));
cls_HLRBRep_PolyAlgo.def("Update", (void (HLRBRep_PolyAlgo::*)()) &HLRBRep_PolyAlgo::Update, "Launches calculation of outlines of the shape visualized by this framework. Used after setting the point of view and defining the shape or shapes to be visualized.");
cls_HLRBRep_PolyAlgo.def("InitHide", (void (HLRBRep_PolyAlgo::*)()) &HLRBRep_PolyAlgo::InitHide, "None");
cls_HLRBRep_PolyAlgo.def("MoreHide", (Standard_Boolean (HLRBRep_PolyAlgo::*)() const) &HLRBRep_PolyAlgo::MoreHide, "None");
cls_HLRBRep_PolyAlgo.def("NextHide", (void (HLRBRep_PolyAlgo::*)()) &HLRBRep_PolyAlgo::NextHide, "None");
cls_HLRBRep_PolyAlgo.def("Hide", [](HLRBRep_PolyAlgo &self, HLRAlgo_EdgeStatus & status, TopoDS_Shape & S, Standard_Boolean & reg1, Standard_Boolean & regn, Standard_Boolean & outl, Standard_Boolean & intl){ HLRAlgo_BiPoint::PointsT & rv = self.Hide(status, S, reg1, regn, outl, intl); return std::tuple<HLRAlgo_BiPoint::PointsT &, Standard_Boolean &, Standard_Boolean &, Standard_Boolean &, Standard_Boolean &>(rv, reg1, regn, outl, intl); }, "None", py::arg("status"), py::arg("S"), py::arg("reg1"), py::arg("regn"), py::arg("outl"), py::arg("intl"));
cls_HLRBRep_PolyAlgo.def("InitShow", (void (HLRBRep_PolyAlgo::*)()) &HLRBRep_PolyAlgo::InitShow, "None");
cls_HLRBRep_PolyAlgo.def("MoreShow", (Standard_Boolean (HLRBRep_PolyAlgo::*)() const) &HLRBRep_PolyAlgo::MoreShow, "None");
cls_HLRBRep_PolyAlgo.def("NextShow", (void (HLRBRep_PolyAlgo::*)()) &HLRBRep_PolyAlgo::NextShow, "None");
cls_HLRBRep_PolyAlgo.def("Show", [](HLRBRep_PolyAlgo &self, TopoDS_Shape & S, Standard_Boolean & reg1, Standard_Boolean & regn, Standard_Boolean & outl, Standard_Boolean & intl){ HLRAlgo_BiPoint::PointsT & rv = self.Show(S, reg1, regn, outl, intl); return std::tuple<HLRAlgo_BiPoint::PointsT &, Standard_Boolean &, Standard_Boolean &, Standard_Boolean &, Standard_Boolean &>(rv, reg1, regn, outl, intl); }, "None", py::arg("S"), py::arg("reg1"), py::arg("regn"), py::arg("outl"), py::arg("intl"));
cls_HLRBRep_PolyAlgo.def("OutLinedShape", (TopoDS_Shape (HLRBRep_PolyAlgo::*)(const TopoDS_Shape &) const) &HLRBRep_PolyAlgo::OutLinedShape, "Make a shape with the internal outlines in each face.", py::arg("S"));
cls_HLRBRep_PolyAlgo.def("Debug", (Standard_Boolean (HLRBRep_PolyAlgo::*)() const) &HLRBRep_PolyAlgo::Debug, "None");
cls_HLRBRep_PolyAlgo.def("Debug", (void (HLRBRep_PolyAlgo::*)(const Standard_Boolean)) &HLRBRep_PolyAlgo::Debug, "None", py::arg("B"));
cls_HLRBRep_PolyAlgo.def_static("get_type_name_", (const char * (*)()) &HLRBRep_PolyAlgo::get_type_name, "None");
cls_HLRBRep_PolyAlgo.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &HLRBRep_PolyAlgo::get_type_descriptor, "None");
cls_HLRBRep_PolyAlgo.def("DynamicType", (const opencascade::handle<Standard_Type> & (HLRBRep_PolyAlgo::*)() const) &HLRBRep_PolyAlgo::DynamicType, "None");

// CLASS: HLRBREP_POLYHLRTOSHAPE
py::class_<HLRBRep_PolyHLRToShape> cls_HLRBRep_PolyHLRToShape(mod, "HLRBRep_PolyHLRToShape", "A framework for filtering the computation results of an HLRBRep_Algo algorithm by extraction. From the results calculated by the algorithm on a shape, a filter returns the type of edge you want to identify. You can choose any of the following types of output: - visible sharp edges - hidden sharp edges - visible smooth edges - hidden smooth edges - visible sewn edges - hidden sewn edges - visible outline edges - hidden outline edges. - visible isoparameters and - hidden isoparameters. Sharp edges present a C0 continuity (non G1). Smooth edges present a G1 continuity (non G2). Sewn edges present a C2 continuity. The result is composed of 2D edges in the projection plane of the view which the algorithm has worked with. These 2D edges are not included in the data structure of the visualized shape. In order to obtain a complete image, you must combine the shapes given by each of the chosen filters. The construction of the shape does not call a new computation of the algorithm, but only reads its internal results.");

// Constructors
cls_HLRBRep_PolyHLRToShape.def(py::init<>());

// Methods
// cls_HLRBRep_PolyHLRToShape.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_PolyHLRToShape::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_PolyHLRToShape.def_static("operator delete_", (void (*)(void *)) &HLRBRep_PolyHLRToShape::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_PolyHLRToShape.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_PolyHLRToShape::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_PolyHLRToShape.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_PolyHLRToShape::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_PolyHLRToShape.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_PolyHLRToShape::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_PolyHLRToShape.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_PolyHLRToShape::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_PolyHLRToShape.def("Update", (void (HLRBRep_PolyHLRToShape::*)(const opencascade::handle<HLRBRep_PolyAlgo> &)) &HLRBRep_PolyHLRToShape::Update, "None", py::arg("A"));
cls_HLRBRep_PolyHLRToShape.def("Show", (void (HLRBRep_PolyHLRToShape::*)()) &HLRBRep_PolyHLRToShape::Show, "None");
cls_HLRBRep_PolyHLRToShape.def("Hide", (void (HLRBRep_PolyHLRToShape::*)()) &HLRBRep_PolyHLRToShape::Hide, "None");
cls_HLRBRep_PolyHLRToShape.def("VCompound", (TopoDS_Shape (HLRBRep_PolyHLRToShape::*)()) &HLRBRep_PolyHLRToShape::VCompound, "None");
cls_HLRBRep_PolyHLRToShape.def("VCompound", (TopoDS_Shape (HLRBRep_PolyHLRToShape::*)(const TopoDS_Shape &)) &HLRBRep_PolyHLRToShape::VCompound, "None", py::arg("S"));
cls_HLRBRep_PolyHLRToShape.def("Rg1LineVCompound", (TopoDS_Shape (HLRBRep_PolyHLRToShape::*)()) &HLRBRep_PolyHLRToShape::Rg1LineVCompound, "Sets the extraction filter for visible smooth edges.");
cls_HLRBRep_PolyHLRToShape.def("Rg1LineVCompound", (TopoDS_Shape (HLRBRep_PolyHLRToShape::*)(const TopoDS_Shape &)) &HLRBRep_PolyHLRToShape::Rg1LineVCompound, "None", py::arg("S"));
cls_HLRBRep_PolyHLRToShape.def("RgNLineVCompound", (TopoDS_Shape (HLRBRep_PolyHLRToShape::*)()) &HLRBRep_PolyHLRToShape::RgNLineVCompound, "Sets the extraction filter for visible sewn edges.");
cls_HLRBRep_PolyHLRToShape.def("RgNLineVCompound", (TopoDS_Shape (HLRBRep_PolyHLRToShape::*)(const TopoDS_Shape &)) &HLRBRep_PolyHLRToShape::RgNLineVCompound, "None", py::arg("S"));
cls_HLRBRep_PolyHLRToShape.def("OutLineVCompound", (TopoDS_Shape (HLRBRep_PolyHLRToShape::*)()) &HLRBRep_PolyHLRToShape::OutLineVCompound, "None");
cls_HLRBRep_PolyHLRToShape.def("OutLineVCompound", (TopoDS_Shape (HLRBRep_PolyHLRToShape::*)(const TopoDS_Shape &)) &HLRBRep_PolyHLRToShape::OutLineVCompound, "Sets the extraction filter for visible outlines.", py::arg("S"));
cls_HLRBRep_PolyHLRToShape.def("HCompound", (TopoDS_Shape (HLRBRep_PolyHLRToShape::*)()) &HLRBRep_PolyHLRToShape::HCompound, "None");
cls_HLRBRep_PolyHLRToShape.def("HCompound", (TopoDS_Shape (HLRBRep_PolyHLRToShape::*)(const TopoDS_Shape &)) &HLRBRep_PolyHLRToShape::HCompound, "None", py::arg("S"));
cls_HLRBRep_PolyHLRToShape.def("Rg1LineHCompound", (TopoDS_Shape (HLRBRep_PolyHLRToShape::*)()) &HLRBRep_PolyHLRToShape::Rg1LineHCompound, "None");
cls_HLRBRep_PolyHLRToShape.def("Rg1LineHCompound", (TopoDS_Shape (HLRBRep_PolyHLRToShape::*)(const TopoDS_Shape &)) &HLRBRep_PolyHLRToShape::Rg1LineHCompound, "Sets the extraction filter for hidden smooth edges.", py::arg("S"));
cls_HLRBRep_PolyHLRToShape.def("RgNLineHCompound", (TopoDS_Shape (HLRBRep_PolyHLRToShape::*)()) &HLRBRep_PolyHLRToShape::RgNLineHCompound, "None");
cls_HLRBRep_PolyHLRToShape.def("RgNLineHCompound", (TopoDS_Shape (HLRBRep_PolyHLRToShape::*)(const TopoDS_Shape &)) &HLRBRep_PolyHLRToShape::RgNLineHCompound, "Sets the extraction filter for hidden sewn edges.", py::arg("S"));
cls_HLRBRep_PolyHLRToShape.def("OutLineHCompound", (TopoDS_Shape (HLRBRep_PolyHLRToShape::*)()) &HLRBRep_PolyHLRToShape::OutLineHCompound, "None");
cls_HLRBRep_PolyHLRToShape.def("OutLineHCompound", (TopoDS_Shape (HLRBRep_PolyHLRToShape::*)(const TopoDS_Shape &)) &HLRBRep_PolyHLRToShape::OutLineHCompound, "Sets the extraction filter for hidden outlines. Hidden outlines occur, for instance, in tori. In this case, the inner outlines of the torus seen on its side are hidden.", py::arg("S"));

// CLASS: HLRBREP_SHAPETOHLR
py::class_<HLRBRep_ShapeToHLR> cls_HLRBRep_ShapeToHLR(mod, "HLRBRep_ShapeToHLR", "compute the OutLinedShape of a Shape with an OutLiner, a Projector and create the Data Structure of a Shape.");

// Constructors
cls_HLRBRep_ShapeToHLR.def(py::init<>());

// Methods
// cls_HLRBRep_ShapeToHLR.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_ShapeToHLR::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_ShapeToHLR.def_static("operator delete_", (void (*)(void *)) &HLRBRep_ShapeToHLR::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_ShapeToHLR.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_ShapeToHLR::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_ShapeToHLR.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_ShapeToHLR::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_ShapeToHLR.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_ShapeToHLR::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_ShapeToHLR.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_ShapeToHLR::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_ShapeToHLR.def_static("Load_", [](const opencascade::handle<HLRTopoBRep_OutLiner> & a0, const HLRAlgo_Projector & a1, BRepTopAdaptor_MapOfShapeTool & a2) -> opencascade::handle<HLRBRep_Data> { return HLRBRep_ShapeToHLR::Load(a0, a1, a2); });
cls_HLRBRep_ShapeToHLR.def_static("Load_", (opencascade::handle<HLRBRep_Data> (*)(const opencascade::handle<HLRTopoBRep_OutLiner> &, const HLRAlgo_Projector &, BRepTopAdaptor_MapOfShapeTool &, const Standard_Integer)) &HLRBRep_ShapeToHLR::Load, "Creates a DataStructure containing the OutLiner <S> depending on the projector <P> and nbIso.", py::arg("S"), py::arg("P"), py::arg("MST"), py::arg("nbIso"));

// CLASS: HLRBREP_SLPROPSATOOL
py::class_<HLRBRep_SLPropsATool> cls_HLRBRep_SLPropsATool(mod, "HLRBRep_SLPropsATool", "None");

// Constructors
cls_HLRBRep_SLPropsATool.def(py::init<>());

// Methods
// cls_HLRBRep_SLPropsATool.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_SLPropsATool::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_SLPropsATool.def_static("operator delete_", (void (*)(void *)) &HLRBRep_SLPropsATool::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_SLPropsATool.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_SLPropsATool::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_SLPropsATool.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_SLPropsATool::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_SLPropsATool.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_SLPropsATool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_SLPropsATool.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_SLPropsATool::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_SLPropsATool.def_static("Value_", (void (*)(const Standard_Address, const Standard_Real, const Standard_Real, gp_Pnt &)) &HLRBRep_SLPropsATool::Value, "Computes the point <P> of parameter <U> and <V> on the Surface <A>.", py::arg("A"), py::arg("U"), py::arg("V"), py::arg("P"));
cls_HLRBRep_SLPropsATool.def_static("D1_", (void (*)(const Standard_Address, const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &)) &HLRBRep_SLPropsATool::D1, "Computes the point <P> and first derivative <D1*> of parameter <U> and <V> on the Surface <A>.", py::arg("A"), py::arg("U"), py::arg("V"), py::arg("P"), py::arg("D1U"), py::arg("D1V"));
cls_HLRBRep_SLPropsATool.def_static("D2_", (void (*)(const Standard_Address, const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &)) &HLRBRep_SLPropsATool::D2, "Computes the point <P>, the first derivative <D1*> and second derivative <D2*> of parameter <U> and <V> on the Surface <A>.", py::arg("A"), py::arg("U"), py::arg("V"), py::arg("P"), py::arg("D1U"), py::arg("D1V"), py::arg("D2U"), py::arg("D2V"), py::arg("DUV"));
cls_HLRBRep_SLPropsATool.def_static("DN_", (gp_Vec (*)(const Standard_Address, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Integer)) &HLRBRep_SLPropsATool::DN, "None", py::arg("A"), py::arg("U"), py::arg("V"), py::arg("Nu"), py::arg("Nv"));
cls_HLRBRep_SLPropsATool.def_static("Continuity_", (Standard_Integer (*)(const Standard_Address)) &HLRBRep_SLPropsATool::Continuity, "returns the order of continuity of the Surface <A>. returns 1 : first derivative only is computable returns 2 : first and second derivative only are computable.", py::arg("A"));
cls_HLRBRep_SLPropsATool.def_static("Bounds_", [](const Standard_Address A, Standard_Real & U1, Standard_Real & V1, Standard_Real & U2, Standard_Real & V2){ HLRBRep_SLPropsATool::Bounds(A, U1, V1, U2, V2); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(U1, V1, U2, V2); }, "returns the bounds of the Surface.", py::arg("A"), py::arg("U1"), py::arg("V1"), py::arg("U2"), py::arg("V2"));

// CLASS: HLRBREP_SURFACETOOL
py::class_<HLRBRep_SurfaceTool> cls_HLRBRep_SurfaceTool(mod, "HLRBRep_SurfaceTool", "None");

// Constructors
cls_HLRBRep_SurfaceTool.def(py::init<>());

// Methods
// cls_HLRBRep_SurfaceTool.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_SurfaceTool::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_SurfaceTool.def_static("operator delete_", (void (*)(void *)) &HLRBRep_SurfaceTool::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_SurfaceTool.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_SurfaceTool::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_SurfaceTool.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_SurfaceTool::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_SurfaceTool.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_SurfaceTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_SurfaceTool.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_SurfaceTool::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_SurfaceTool.def_static("FirstUParameter_", (Standard_Real (*)(const Standard_Address)) &HLRBRep_SurfaceTool::FirstUParameter, "None", py::arg("S"));
cls_HLRBRep_SurfaceTool.def_static("FirstVParameter_", (Standard_Real (*)(const Standard_Address)) &HLRBRep_SurfaceTool::FirstVParameter, "None", py::arg("S"));
cls_HLRBRep_SurfaceTool.def_static("LastUParameter_", (Standard_Real (*)(const Standard_Address)) &HLRBRep_SurfaceTool::LastUParameter, "None", py::arg("S"));
cls_HLRBRep_SurfaceTool.def_static("LastVParameter_", (Standard_Real (*)(const Standard_Address)) &HLRBRep_SurfaceTool::LastVParameter, "None", py::arg("S"));
cls_HLRBRep_SurfaceTool.def_static("NbUIntervals_", (Standard_Integer (*)(const Standard_Address, const GeomAbs_Shape)) &HLRBRep_SurfaceTool::NbUIntervals, "None", py::arg("S"), py::arg("Sh"));
cls_HLRBRep_SurfaceTool.def_static("NbVIntervals_", (Standard_Integer (*)(const Standard_Address, const GeomAbs_Shape)) &HLRBRep_SurfaceTool::NbVIntervals, "None", py::arg("S"), py::arg("Sh"));
cls_HLRBRep_SurfaceTool.def_static("UIntervals_", (void (*)(const Standard_Address, TColStd_Array1OfReal &, const GeomAbs_Shape)) &HLRBRep_SurfaceTool::UIntervals, "None", py::arg("S"), py::arg("T"), py::arg("Sh"));
cls_HLRBRep_SurfaceTool.def_static("VIntervals_", (void (*)(const Standard_Address, TColStd_Array1OfReal &, const GeomAbs_Shape)) &HLRBRep_SurfaceTool::VIntervals, "None", py::arg("S"), py::arg("T"), py::arg("Sh"));
cls_HLRBRep_SurfaceTool.def_static("UTrim_", (opencascade::handle<Adaptor3d_HSurface> (*)(const Standard_Address, const Standard_Real, const Standard_Real, const Standard_Real)) &HLRBRep_SurfaceTool::UTrim, "If <First> >= <Last>", py::arg("S"), py::arg("First"), py::arg("Last"), py::arg("Tol"));
cls_HLRBRep_SurfaceTool.def_static("VTrim_", (opencascade::handle<Adaptor3d_HSurface> (*)(const Standard_Address, const Standard_Real, const Standard_Real, const Standard_Real)) &HLRBRep_SurfaceTool::VTrim, "If <First> >= <Last>", py::arg("S"), py::arg("First"), py::arg("Last"), py::arg("Tol"));
cls_HLRBRep_SurfaceTool.def_static("IsUClosed_", (Standard_Boolean (*)(const Standard_Address)) &HLRBRep_SurfaceTool::IsUClosed, "None", py::arg("S"));
cls_HLRBRep_SurfaceTool.def_static("IsVClosed_", (Standard_Boolean (*)(const Standard_Address)) &HLRBRep_SurfaceTool::IsVClosed, "None", py::arg("S"));
cls_HLRBRep_SurfaceTool.def_static("IsUPeriodic_", (Standard_Boolean (*)(const Standard_Address)) &HLRBRep_SurfaceTool::IsUPeriodic, "None", py::arg("S"));
cls_HLRBRep_SurfaceTool.def_static("UPeriod_", (Standard_Real (*)(const Standard_Address)) &HLRBRep_SurfaceTool::UPeriod, "None", py::arg("S"));
cls_HLRBRep_SurfaceTool.def_static("IsVPeriodic_", (Standard_Boolean (*)(const Standard_Address)) &HLRBRep_SurfaceTool::IsVPeriodic, "None", py::arg("S"));
cls_HLRBRep_SurfaceTool.def_static("VPeriod_", (Standard_Real (*)(const Standard_Address)) &HLRBRep_SurfaceTool::VPeriod, "None", py::arg("S"));
cls_HLRBRep_SurfaceTool.def_static("Value_", (gp_Pnt (*)(const Standard_Address, const Standard_Real, const Standard_Real)) &HLRBRep_SurfaceTool::Value, "None", py::arg("S"), py::arg("u"), py::arg("v"));
cls_HLRBRep_SurfaceTool.def_static("D0_", (void (*)(const Standard_Address, const Standard_Real, const Standard_Real, gp_Pnt &)) &HLRBRep_SurfaceTool::D0, "None", py::arg("S"), py::arg("u"), py::arg("v"), py::arg("P"));
cls_HLRBRep_SurfaceTool.def_static("D1_", (void (*)(const Standard_Address, const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &)) &HLRBRep_SurfaceTool::D1, "None", py::arg("S"), py::arg("u"), py::arg("v"), py::arg("P"), py::arg("D1u"), py::arg("D1v"));
cls_HLRBRep_SurfaceTool.def_static("D2_", (void (*)(const Standard_Address, const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &)) &HLRBRep_SurfaceTool::D2, "None", py::arg("S"), py::arg("u"), py::arg("v"), py::arg("P"), py::arg("D1U"), py::arg("D1V"), py::arg("D2U"), py::arg("D2V"), py::arg("D2UV"));
cls_HLRBRep_SurfaceTool.def_static("D3_", (void (*)(const Standard_Address, const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &)) &HLRBRep_SurfaceTool::D3, "None", py::arg("S"), py::arg("u"), py::arg("v"), py::arg("P"), py::arg("D1U"), py::arg("D1V"), py::arg("D2U"), py::arg("D2V"), py::arg("D2UV"), py::arg("D3U"), py::arg("D3V"), py::arg("D3UUV"), py::arg("D3UVV"));
cls_HLRBRep_SurfaceTool.def_static("DN_", (gp_Vec (*)(const Standard_Address, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Integer)) &HLRBRep_SurfaceTool::DN, "None", py::arg("S"), py::arg("u"), py::arg("v"), py::arg("Nu"), py::arg("Nv"));
cls_HLRBRep_SurfaceTool.def_static("UResolution_", (Standard_Real (*)(const Standard_Address, const Standard_Real)) &HLRBRep_SurfaceTool::UResolution, "None", py::arg("S"), py::arg("R3d"));
cls_HLRBRep_SurfaceTool.def_static("VResolution_", (Standard_Real (*)(const Standard_Address, const Standard_Real)) &HLRBRep_SurfaceTool::VResolution, "None", py::arg("S"), py::arg("R3d"));
cls_HLRBRep_SurfaceTool.def_static("GetType_", (GeomAbs_SurfaceType (*)(const Standard_Address)) &HLRBRep_SurfaceTool::GetType, "None", py::arg("S"));
cls_HLRBRep_SurfaceTool.def_static("Plane_", (gp_Pln (*)(const Standard_Address)) &HLRBRep_SurfaceTool::Plane, "None", py::arg("S"));
cls_HLRBRep_SurfaceTool.def_static("Cylinder_", (gp_Cylinder (*)(const Standard_Address)) &HLRBRep_SurfaceTool::Cylinder, "None", py::arg("S"));
cls_HLRBRep_SurfaceTool.def_static("Cone_", (gp_Cone (*)(const Standard_Address)) &HLRBRep_SurfaceTool::Cone, "None", py::arg("S"));
cls_HLRBRep_SurfaceTool.def_static("Torus_", (gp_Torus (*)(const Standard_Address)) &HLRBRep_SurfaceTool::Torus, "None", py::arg("S"));
cls_HLRBRep_SurfaceTool.def_static("Sphere_", (gp_Sphere (*)(const Standard_Address)) &HLRBRep_SurfaceTool::Sphere, "None", py::arg("S"));
cls_HLRBRep_SurfaceTool.def_static("Bezier_", (opencascade::handle<Geom_BezierSurface> (*)(const Standard_Address)) &HLRBRep_SurfaceTool::Bezier, "None", py::arg("S"));
cls_HLRBRep_SurfaceTool.def_static("BSpline_", (opencascade::handle<Geom_BSplineSurface> (*)(const Standard_Address)) &HLRBRep_SurfaceTool::BSpline, "None", py::arg("S"));
cls_HLRBRep_SurfaceTool.def_static("AxeOfRevolution_", (gp_Ax1 (*)(const Standard_Address)) &HLRBRep_SurfaceTool::AxeOfRevolution, "None", py::arg("S"));
cls_HLRBRep_SurfaceTool.def_static("Direction_", (gp_Dir (*)(const Standard_Address)) &HLRBRep_SurfaceTool::Direction, "None", py::arg("S"));
cls_HLRBRep_SurfaceTool.def_static("BasisCurve_", (opencascade::handle<Adaptor3d_HCurve> (*)(const Standard_Address)) &HLRBRep_SurfaceTool::BasisCurve, "None", py::arg("S"));
cls_HLRBRep_SurfaceTool.def_static("BasisSurface_", (opencascade::handle<Adaptor3d_HSurface> (*)(const Standard_Address)) &HLRBRep_SurfaceTool::BasisSurface, "None", py::arg("S"));
cls_HLRBRep_SurfaceTool.def_static("OffsetValue_", (Standard_Real (*)(const Standard_Address)) &HLRBRep_SurfaceTool::OffsetValue, "None", py::arg("S"));
cls_HLRBRep_SurfaceTool.def_static("NbSamplesU_", (Standard_Integer (*)(const Standard_Address)) &HLRBRep_SurfaceTool::NbSamplesU, "None", py::arg("S"));
cls_HLRBRep_SurfaceTool.def_static("NbSamplesV_", (Standard_Integer (*)(const Standard_Address)) &HLRBRep_SurfaceTool::NbSamplesV, "None", py::arg("S"));
cls_HLRBRep_SurfaceTool.def_static("NbSamplesU_", (Standard_Integer (*)(const Standard_Address, const Standard_Real, const Standard_Real)) &HLRBRep_SurfaceTool::NbSamplesU, "None", py::arg("S"), py::arg("u1"), py::arg("u2"));
cls_HLRBRep_SurfaceTool.def_static("NbSamplesV_", (Standard_Integer (*)(const Standard_Address, const Standard_Real, const Standard_Real)) &HLRBRep_SurfaceTool::NbSamplesV, "None", py::arg("S"), py::arg("v1"), py::arg("v2"));

// CLASS: HLRBREP_THECSFUNCTIONOFINTERCSURF
py::class_<HLRBRep_TheCSFunctionOfInterCSurf, math_FunctionSetWithDerivatives> cls_HLRBRep_TheCSFunctionOfInterCSurf(mod, "HLRBRep_TheCSFunctionOfInterCSurf", "None");

// Constructors
cls_HLRBRep_TheCSFunctionOfInterCSurf.def(py::init<const Standard_Address &, const gp_Lin &>(), py::arg("S"), py::arg("C"));

// Methods
// cls_HLRBRep_TheCSFunctionOfInterCSurf.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_TheCSFunctionOfInterCSurf::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_TheCSFunctionOfInterCSurf.def_static("operator delete_", (void (*)(void *)) &HLRBRep_TheCSFunctionOfInterCSurf::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_TheCSFunctionOfInterCSurf.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_TheCSFunctionOfInterCSurf::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_TheCSFunctionOfInterCSurf.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_TheCSFunctionOfInterCSurf::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_TheCSFunctionOfInterCSurf.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_TheCSFunctionOfInterCSurf::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_TheCSFunctionOfInterCSurf.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_TheCSFunctionOfInterCSurf::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_TheCSFunctionOfInterCSurf.def("NbVariables", (Standard_Integer (HLRBRep_TheCSFunctionOfInterCSurf::*)() const) &HLRBRep_TheCSFunctionOfInterCSurf::NbVariables, "None");
cls_HLRBRep_TheCSFunctionOfInterCSurf.def("NbEquations", (Standard_Integer (HLRBRep_TheCSFunctionOfInterCSurf::*)() const) &HLRBRep_TheCSFunctionOfInterCSurf::NbEquations, "None");
cls_HLRBRep_TheCSFunctionOfInterCSurf.def("Value", (Standard_Boolean (HLRBRep_TheCSFunctionOfInterCSurf::*)(const math_Vector &, math_Vector &)) &HLRBRep_TheCSFunctionOfInterCSurf::Value, "None", py::arg("X"), py::arg("F"));
cls_HLRBRep_TheCSFunctionOfInterCSurf.def("Derivatives", (Standard_Boolean (HLRBRep_TheCSFunctionOfInterCSurf::*)(const math_Vector &, math_Matrix &)) &HLRBRep_TheCSFunctionOfInterCSurf::Derivatives, "None", py::arg("X"), py::arg("D"));
cls_HLRBRep_TheCSFunctionOfInterCSurf.def("Values", (Standard_Boolean (HLRBRep_TheCSFunctionOfInterCSurf::*)(const math_Vector &, math_Vector &, math_Matrix &)) &HLRBRep_TheCSFunctionOfInterCSurf::Values, "None", py::arg("X"), py::arg("F"), py::arg("D"));
cls_HLRBRep_TheCSFunctionOfInterCSurf.def("Point", (const gp_Pnt & (HLRBRep_TheCSFunctionOfInterCSurf::*)() const) &HLRBRep_TheCSFunctionOfInterCSurf::Point, "None");
cls_HLRBRep_TheCSFunctionOfInterCSurf.def("Root", (Standard_Real (HLRBRep_TheCSFunctionOfInterCSurf::*)() const) &HLRBRep_TheCSFunctionOfInterCSurf::Root, "None");
cls_HLRBRep_TheCSFunctionOfInterCSurf.def("AuxillarSurface", (const Standard_Address & (HLRBRep_TheCSFunctionOfInterCSurf::*)() const) &HLRBRep_TheCSFunctionOfInterCSurf::AuxillarSurface, "None");
cls_HLRBRep_TheCSFunctionOfInterCSurf.def("AuxillarCurve", (const gp_Lin & (HLRBRep_TheCSFunctionOfInterCSurf::*)() const) &HLRBRep_TheCSFunctionOfInterCSurf::AuxillarCurve, "None");

// CLASS: HLRBREP_THECURVELOCATOROFTHEPROJPCUROFCINTER
py::class_<HLRBRep_TheCurveLocatorOfTheProjPCurOfCInter> cls_HLRBRep_TheCurveLocatorOfTheProjPCurOfCInter(mod, "HLRBRep_TheCurveLocatorOfTheProjPCurOfCInter", "None");

// Constructors
cls_HLRBRep_TheCurveLocatorOfTheProjPCurOfCInter.def(py::init<>());

// Methods
// cls_HLRBRep_TheCurveLocatorOfTheProjPCurOfCInter.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_TheCurveLocatorOfTheProjPCurOfCInter::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_TheCurveLocatorOfTheProjPCurOfCInter.def_static("operator delete_", (void (*)(void *)) &HLRBRep_TheCurveLocatorOfTheProjPCurOfCInter::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_TheCurveLocatorOfTheProjPCurOfCInter.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_TheCurveLocatorOfTheProjPCurOfCInter::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_TheCurveLocatorOfTheProjPCurOfCInter.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_TheCurveLocatorOfTheProjPCurOfCInter::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_TheCurveLocatorOfTheProjPCurOfCInter.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_TheCurveLocatorOfTheProjPCurOfCInter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_TheCurveLocatorOfTheProjPCurOfCInter.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_TheCurveLocatorOfTheProjPCurOfCInter::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_TheCurveLocatorOfTheProjPCurOfCInter.def_static("Locate_", (void (*)(const gp_Pnt2d &, const Standard_Address &, const Standard_Integer, Extrema_POnCurv2d &)) &HLRBRep_TheCurveLocatorOfTheProjPCurOfCInter::Locate, "Among a set of points {C(ui),i=1,NbU}, locate the point P=C(uj) such that: distance(P,C) = Min{distance(P,C(ui))}", py::arg("P"), py::arg("C"), py::arg("NbU"), py::arg("Papp"));
cls_HLRBRep_TheCurveLocatorOfTheProjPCurOfCInter.def_static("Locate_", (void (*)(const gp_Pnt2d &, const Standard_Address &, const Standard_Integer, const Standard_Real, const Standard_Real, Extrema_POnCurv2d &)) &HLRBRep_TheCurveLocatorOfTheProjPCurOfCInter::Locate, "Among a set of points {C(ui),i=1,NbU}, locate the point P=C(uj) such that: distance(P,C) = Min{distance(P,C(ui))} The research is done between umin and usup.", py::arg("P"), py::arg("C"), py::arg("NbU"), py::arg("Umin"), py::arg("Usup"), py::arg("Papp"));
// cls_HLRBRep_TheCurveLocatorOfTheProjPCurOfCInter.def_static("Locate_", (void (*)(const Standard_Address &, const Standard_Address &, const Standard_Integer, const Standard_Integer, Extrema_POnCurv2d &, Extrema_POnCurv2d &)) &HLRBRep_TheCurveLocatorOfTheProjPCurOfCInter::Locate, "Among two sets of points {C1(ui),i=1,NbU} and {C2(vj),j=1,NbV}, locate the two points P1=C1(uk) and P2=C2(vl) such that: distance(P1,P2) = Min {distance(C1(ui),C2(vj))}.", py::arg("C1"), py::arg("C2"), py::arg("NbU"), py::arg("NbV"), py::arg("Papp1"), py::arg("Papp2"));

// CLASS: HLRBREP_THEEXACTINTERCSURF
py::class_<HLRBRep_TheExactInterCSurf> cls_HLRBRep_TheExactInterCSurf(mod, "HLRBRep_TheExactInterCSurf", "None");

// Constructors
cls_HLRBRep_TheExactInterCSurf.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const HLRBRep_TheCSFunctionOfInterCSurf &, const Standard_Real>(), py::arg("U"), py::arg("V"), py::arg("W"), py::arg("F"), py::arg("TolTangency"));
cls_HLRBRep_TheExactInterCSurf.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const HLRBRep_TheCSFunctionOfInterCSurf &, const Standard_Real, const Standard_Real>(), py::arg("U"), py::arg("V"), py::arg("W"), py::arg("F"), py::arg("TolTangency"), py::arg("MarginCoef"));
cls_HLRBRep_TheExactInterCSurf.def(py::init<const HLRBRep_TheCSFunctionOfInterCSurf &, const Standard_Real>(), py::arg("F"), py::arg("TolTangency"));

// Methods
// cls_HLRBRep_TheExactInterCSurf.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_TheExactInterCSurf::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_TheExactInterCSurf.def_static("operator delete_", (void (*)(void *)) &HLRBRep_TheExactInterCSurf::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_TheExactInterCSurf.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_TheExactInterCSurf::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_TheExactInterCSurf.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_TheExactInterCSurf::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_TheExactInterCSurf.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_TheExactInterCSurf::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_TheExactInterCSurf.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_TheExactInterCSurf::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_TheExactInterCSurf.def("Perform", (void (HLRBRep_TheExactInterCSurf::*)(const Standard_Real, const Standard_Real, const Standard_Real, math_FunctionSetRoot &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &HLRBRep_TheExactInterCSurf::Perform, "compute the solution it's possible to write to optimize: IntImp_IntCS inter(S1,C1,Toltangency) math_FunctionSetRoot rsnld(Inter.function()) while ...{ u=... v=... w=... inter.Perform(u,v,w,rsnld) } or IntImp_IntCS inter(Toltangency) inter.SetSurface(S); math_FunctionSetRoot rsnld(Inter.function()) while ...{ C=... inter.SetCurve(C); u=... v=... w=... inter.Perform(u,v,w,rsnld) }", py::arg("U"), py::arg("V"), py::arg("W"), py::arg("Rsnld"), py::arg("u0"), py::arg("v0"), py::arg("u1"), py::arg("v1"), py::arg("w0"), py::arg("w1"));
cls_HLRBRep_TheExactInterCSurf.def("IsDone", (Standard_Boolean (HLRBRep_TheExactInterCSurf::*)() const) &HLRBRep_TheExactInterCSurf::IsDone, "Returns TRUE if the creation completed without failure.");
cls_HLRBRep_TheExactInterCSurf.def("IsEmpty", (Standard_Boolean (HLRBRep_TheExactInterCSurf::*)() const) &HLRBRep_TheExactInterCSurf::IsEmpty, "None");
cls_HLRBRep_TheExactInterCSurf.def("Point", (const gp_Pnt & (HLRBRep_TheExactInterCSurf::*)() const) &HLRBRep_TheExactInterCSurf::Point, "returns the intersection point The exception NotDone is raised if IsDone is false. The exception DomainError is raised if IsEmpty is true.");
cls_HLRBRep_TheExactInterCSurf.def("ParameterOnCurve", (Standard_Real (HLRBRep_TheExactInterCSurf::*)() const) &HLRBRep_TheExactInterCSurf::ParameterOnCurve, "None");
cls_HLRBRep_TheExactInterCSurf.def("ParameterOnSurface", [](HLRBRep_TheExactInterCSurf &self, Standard_Real & U, Standard_Real & V){ self.ParameterOnSurface(U, V); return std::tuple<Standard_Real &, Standard_Real &>(U, V); }, "None", py::arg("U"), py::arg("V"));
cls_HLRBRep_TheExactInterCSurf.def("Function", (HLRBRep_TheCSFunctionOfInterCSurf & (HLRBRep_TheExactInterCSurf::*)()) &HLRBRep_TheExactInterCSurf::Function, "return the math function which is used to compute the intersection");

// CLASS: HLRBREP_THEINTERFERENCEOFINTERCSURF
py::class_<HLRBRep_TheInterferenceOfInterCSurf, Intf_Interference> cls_HLRBRep_TheInterferenceOfInterCSurf(mod, "HLRBRep_TheInterferenceOfInterCSurf", "None");

// Constructors
cls_HLRBRep_TheInterferenceOfInterCSurf.def(py::init<>());
cls_HLRBRep_TheInterferenceOfInterCSurf.def(py::init<const HLRBRep_ThePolygonOfInterCSurf &, const HLRBRep_ThePolyhedronOfInterCSurf &>(), py::arg("thePolyg"), py::arg("thePolyh"));
cls_HLRBRep_TheInterferenceOfInterCSurf.def(py::init<const gp_Lin &, const HLRBRep_ThePolyhedronOfInterCSurf &>(), py::arg("theLin"), py::arg("thePolyh"));
cls_HLRBRep_TheInterferenceOfInterCSurf.def(py::init<const Intf_Array1OfLin &, const HLRBRep_ThePolyhedronOfInterCSurf &>(), py::arg("theLins"), py::arg("thePolyh"));
cls_HLRBRep_TheInterferenceOfInterCSurf.def(py::init<const HLRBRep_ThePolygonOfInterCSurf &, const HLRBRep_ThePolyhedronOfInterCSurf &, Bnd_BoundSortBox &>(), py::arg("thePolyg"), py::arg("thePolyh"), py::arg("theBoundSB"));
cls_HLRBRep_TheInterferenceOfInterCSurf.def(py::init<const gp_Lin &, const HLRBRep_ThePolyhedronOfInterCSurf &, Bnd_BoundSortBox &>(), py::arg("theLin"), py::arg("thePolyh"), py::arg("theBoundSB"));
cls_HLRBRep_TheInterferenceOfInterCSurf.def(py::init<const Intf_Array1OfLin &, const HLRBRep_ThePolyhedronOfInterCSurf &, Bnd_BoundSortBox &>(), py::arg("theLins"), py::arg("thePolyh"), py::arg("theBoundSB"));

// Methods
// cls_HLRBRep_TheInterferenceOfInterCSurf.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_TheInterferenceOfInterCSurf::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_TheInterferenceOfInterCSurf.def_static("operator delete_", (void (*)(void *)) &HLRBRep_TheInterferenceOfInterCSurf::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_TheInterferenceOfInterCSurf.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_TheInterferenceOfInterCSurf::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_TheInterferenceOfInterCSurf.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_TheInterferenceOfInterCSurf::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_TheInterferenceOfInterCSurf.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_TheInterferenceOfInterCSurf::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_TheInterferenceOfInterCSurf.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_TheInterferenceOfInterCSurf::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_TheInterferenceOfInterCSurf.def("Perform", (void (HLRBRep_TheInterferenceOfInterCSurf::*)(const HLRBRep_ThePolygonOfInterCSurf &, const HLRBRep_ThePolyhedronOfInterCSurf &)) &HLRBRep_TheInterferenceOfInterCSurf::Perform, "Computes an interference between the Polygon and the Polyhedron.", py::arg("thePolyg"), py::arg("thePolyh"));
cls_HLRBRep_TheInterferenceOfInterCSurf.def("Perform", (void (HLRBRep_TheInterferenceOfInterCSurf::*)(const gp_Lin &, const HLRBRep_ThePolyhedronOfInterCSurf &)) &HLRBRep_TheInterferenceOfInterCSurf::Perform, "Computes an interference between the Straight Line and the Polyhedron.", py::arg("theLin"), py::arg("thePolyh"));
cls_HLRBRep_TheInterferenceOfInterCSurf.def("Perform", (void (HLRBRep_TheInterferenceOfInterCSurf::*)(const Intf_Array1OfLin &, const HLRBRep_ThePolyhedronOfInterCSurf &)) &HLRBRep_TheInterferenceOfInterCSurf::Perform, "Computes an interference between the Straight Lines and the Polyhedron.", py::arg("theLins"), py::arg("thePolyh"));
cls_HLRBRep_TheInterferenceOfInterCSurf.def("Perform", (void (HLRBRep_TheInterferenceOfInterCSurf::*)(const HLRBRep_ThePolygonOfInterCSurf &, const HLRBRep_ThePolyhedronOfInterCSurf &, Bnd_BoundSortBox &)) &HLRBRep_TheInterferenceOfInterCSurf::Perform, "Computes an interference between the Polygon and the Polyhedron.", py::arg("thePolyg"), py::arg("thePolyh"), py::arg("theBoundSB"));
cls_HLRBRep_TheInterferenceOfInterCSurf.def("Perform", (void (HLRBRep_TheInterferenceOfInterCSurf::*)(const gp_Lin &, const HLRBRep_ThePolyhedronOfInterCSurf &, Bnd_BoundSortBox &)) &HLRBRep_TheInterferenceOfInterCSurf::Perform, "Computes an interference between the Straight Line and the Polyhedron.", py::arg("theLin"), py::arg("thePolyh"), py::arg("theBoundSB"));
cls_HLRBRep_TheInterferenceOfInterCSurf.def("Perform", (void (HLRBRep_TheInterferenceOfInterCSurf::*)(const Intf_Array1OfLin &, const HLRBRep_ThePolyhedronOfInterCSurf &, Bnd_BoundSortBox &)) &HLRBRep_TheInterferenceOfInterCSurf::Perform, "Computes an interference between the Straight Lines and the Polyhedron.", py::arg("theLins"), py::arg("thePolyh"), py::arg("theBoundSB"));
cls_HLRBRep_TheInterferenceOfInterCSurf.def("Interference", (void (HLRBRep_TheInterferenceOfInterCSurf::*)(const HLRBRep_ThePolygonOfInterCSurf &, const HLRBRep_ThePolyhedronOfInterCSurf &, Bnd_BoundSortBox &)) &HLRBRep_TheInterferenceOfInterCSurf::Interference, "Compares the boundings between the segment of <thePolyg> and the facets of <thePolyh>.", py::arg("thePolyg"), py::arg("thePolyh"), py::arg("theBoundSB"));
cls_HLRBRep_TheInterferenceOfInterCSurf.def("Interference", (void (HLRBRep_TheInterferenceOfInterCSurf::*)(const HLRBRep_ThePolygonOfInterCSurf &, const HLRBRep_ThePolyhedronOfInterCSurf &)) &HLRBRep_TheInterferenceOfInterCSurf::Interference, "Compares the boundings between the segment of <thePolyg> and the facets of <thePolyh>.", py::arg("thePolyg"), py::arg("thePolyh"));

// CLASS: HLRBREP_THELOCATEEXTPCOFTHEPROJPCUROFCINTER
py::class_<HLRBRep_TheLocateExtPCOfTheProjPCurOfCInter> cls_HLRBRep_TheLocateExtPCOfTheProjPCurOfCInter(mod, "HLRBRep_TheLocateExtPCOfTheProjPCurOfCInter", "None");

// Constructors
cls_HLRBRep_TheLocateExtPCOfTheProjPCurOfCInter.def(py::init<>());
cls_HLRBRep_TheLocateExtPCOfTheProjPCurOfCInter.def(py::init<const gp_Pnt2d &, const Standard_Address &, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("C"), py::arg("U0"), py::arg("TolU"));
cls_HLRBRep_TheLocateExtPCOfTheProjPCurOfCInter.def(py::init<const gp_Pnt2d &, const Standard_Address &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("C"), py::arg("U0"), py::arg("Umin"), py::arg("Usup"), py::arg("TolU"));

// Methods
// cls_HLRBRep_TheLocateExtPCOfTheProjPCurOfCInter.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_TheLocateExtPCOfTheProjPCurOfCInter::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_TheLocateExtPCOfTheProjPCurOfCInter.def_static("operator delete_", (void (*)(void *)) &HLRBRep_TheLocateExtPCOfTheProjPCurOfCInter::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_TheLocateExtPCOfTheProjPCurOfCInter.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_TheLocateExtPCOfTheProjPCurOfCInter::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_TheLocateExtPCOfTheProjPCurOfCInter.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_TheLocateExtPCOfTheProjPCurOfCInter::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_TheLocateExtPCOfTheProjPCurOfCInter.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_TheLocateExtPCOfTheProjPCurOfCInter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_TheLocateExtPCOfTheProjPCurOfCInter.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_TheLocateExtPCOfTheProjPCurOfCInter::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_TheLocateExtPCOfTheProjPCurOfCInter.def("Initialize", (void (HLRBRep_TheLocateExtPCOfTheProjPCurOfCInter::*)(const Standard_Address &, const Standard_Real, const Standard_Real, const Standard_Real)) &HLRBRep_TheLocateExtPCOfTheProjPCurOfCInter::Initialize, "sets the fields of the algorithm.", py::arg("C"), py::arg("Umin"), py::arg("Usup"), py::arg("TolU"));
cls_HLRBRep_TheLocateExtPCOfTheProjPCurOfCInter.def("Perform", (void (HLRBRep_TheLocateExtPCOfTheProjPCurOfCInter::*)(const gp_Pnt2d &, const Standard_Real)) &HLRBRep_TheLocateExtPCOfTheProjPCurOfCInter::Perform, "the algorithm is done with the point P. An exception is raised if the fields have not been initialized.", py::arg("P"), py::arg("U0"));
cls_HLRBRep_TheLocateExtPCOfTheProjPCurOfCInter.def("IsDone", (Standard_Boolean (HLRBRep_TheLocateExtPCOfTheProjPCurOfCInter::*)() const) &HLRBRep_TheLocateExtPCOfTheProjPCurOfCInter::IsDone, "Returns True if the distance is found.");
cls_HLRBRep_TheLocateExtPCOfTheProjPCurOfCInter.def("SquareDistance", (Standard_Real (HLRBRep_TheLocateExtPCOfTheProjPCurOfCInter::*)() const) &HLRBRep_TheLocateExtPCOfTheProjPCurOfCInter::SquareDistance, "Returns the value of the extremum square distance.");
cls_HLRBRep_TheLocateExtPCOfTheProjPCurOfCInter.def("IsMin", (Standard_Boolean (HLRBRep_TheLocateExtPCOfTheProjPCurOfCInter::*)() const) &HLRBRep_TheLocateExtPCOfTheProjPCurOfCInter::IsMin, "Returns True if the extremum distance is a minimum.");
cls_HLRBRep_TheLocateExtPCOfTheProjPCurOfCInter.def("Point", (const Extrema_POnCurv2d & (HLRBRep_TheLocateExtPCOfTheProjPCurOfCInter::*)() const) &HLRBRep_TheLocateExtPCOfTheProjPCurOfCInter::Point, "Returns the point of the extremum distance.");

// CLASS: HLRBREP_THEPOLYGON2DOFTHEINTPCURVEPCURVEOFCINTER
py::class_<HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter, Intf_Polygon2d> cls_HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter(mod, "HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter", "None");

// Constructors
cls_HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter.def(py::init<const Standard_Address &, const Standard_Integer, const IntRes2d_Domain &, const Standard_Real>(), py::arg("Curve"), py::arg("NbPnt"), py::arg("Domain"), py::arg("Tol"));

// Methods
// cls_HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter.def_static("operator delete_", (void (*)(void *)) &HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter.def("ComputeWithBox", (void (HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter::*)(const Standard_Address &, const Bnd_Box2d &)) &HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter::ComputeWithBox, "The current polygon is modified if most of the points of the polygon are are outside the box <OtherBox>. In this situation, bounds are computed to build a polygon inside or near the OtherBox.", py::arg("Curve"), py::arg("OtherBox"));
cls_HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter.def("DeflectionOverEstimation", (Standard_Real (HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter::*)() const) &HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter::DeflectionOverEstimation, "None");
cls_HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter.def("SetDeflectionOverEstimation", (void (HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter::*)(const Standard_Real)) &HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter::SetDeflectionOverEstimation, "None", py::arg("x"));
cls_HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter.def("Closed", (void (HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter::*)(const Standard_Boolean)) &HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter::Closed, "None", py::arg("clos"));
cls_HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter.def("Closed", (Standard_Boolean (HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter::*)() const) &HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter::Closed, "Returns True if the polyline is closed.");
cls_HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter.def("NbSegments", (Standard_Integer (HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter::*)() const) &HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter::NbSegments, "Give the number of Segments in the polyline.");
cls_HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter.def("Segment", (void (HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter::*)(const Standard_Integer, gp_Pnt2d &, gp_Pnt2d &) const) &HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter::Segment, "Returns the points of the segment <Index> in the Polygon.", py::arg("theIndex"), py::arg("theBegin"), py::arg("theEnd"));
cls_HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter.def("InfParameter", (Standard_Real (HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter::*)() const) &HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter::InfParameter, "Returns the parameter (On the curve) of the first point of the Polygon");
cls_HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter.def("SupParameter", (Standard_Real (HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter::*)() const) &HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter::SupParameter, "Returns the parameter (On the curve) of the last point of the Polygon");
cls_HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter.def("AutoIntersectionIsPossible", (Standard_Boolean (HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter::*)() const) &HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter::AutoIntersectionIsPossible, "None");
cls_HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter.def("ApproxParamOnCurve", (Standard_Real (HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter::*)(const Standard_Integer, const Standard_Real) const) &HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter::ApproxParamOnCurve, "Give an approximation of the parameter on the curve according to the discretization of the Curve.", py::arg("Index"), py::arg("ParamOnLine"));
cls_HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter.def("CalculRegion", (Standard_Integer (HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real) const) &HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter::CalculRegion, "None", py::arg("x"), py::arg("y"), py::arg("x1"), py::arg("x2"), py::arg("y1"), py::arg("y2"));
cls_HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter.def("Dump", (void (HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter::*)() const) &HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter::Dump, "None");

// CLASS: HLRBREP_THEPOLYGONOFINTERCSURF
py::class_<HLRBRep_ThePolygonOfInterCSurf> cls_HLRBRep_ThePolygonOfInterCSurf(mod, "HLRBRep_ThePolygonOfInterCSurf", "None");

// Constructors
cls_HLRBRep_ThePolygonOfInterCSurf.def(py::init<const gp_Lin &, const Standard_Integer>(), py::arg("Curve"), py::arg("NbPnt"));
cls_HLRBRep_ThePolygonOfInterCSurf.def(py::init<const gp_Lin &, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("Curve"), py::arg("U1"), py::arg("U2"), py::arg("NbPnt"));
cls_HLRBRep_ThePolygonOfInterCSurf.def(py::init<const gp_Lin &, const TColStd_Array1OfReal &>(), py::arg("Curve"), py::arg("Upars"));

// Methods
// cls_HLRBRep_ThePolygonOfInterCSurf.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_ThePolygonOfInterCSurf::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_ThePolygonOfInterCSurf.def_static("operator delete_", (void (*)(void *)) &HLRBRep_ThePolygonOfInterCSurf::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_ThePolygonOfInterCSurf.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_ThePolygonOfInterCSurf::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_ThePolygonOfInterCSurf.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_ThePolygonOfInterCSurf::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_ThePolygonOfInterCSurf.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_ThePolygonOfInterCSurf::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_ThePolygonOfInterCSurf.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_ThePolygonOfInterCSurf::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_ThePolygonOfInterCSurf.def("Bounding", (const Bnd_Box & (HLRBRep_ThePolygonOfInterCSurf::*)() const) &HLRBRep_ThePolygonOfInterCSurf::Bounding, "Give the bounding box of the polygon.");
cls_HLRBRep_ThePolygonOfInterCSurf.def("DeflectionOverEstimation", (Standard_Real (HLRBRep_ThePolygonOfInterCSurf::*)() const) &HLRBRep_ThePolygonOfInterCSurf::DeflectionOverEstimation, "None");
cls_HLRBRep_ThePolygonOfInterCSurf.def("SetDeflectionOverEstimation", (void (HLRBRep_ThePolygonOfInterCSurf::*)(const Standard_Real)) &HLRBRep_ThePolygonOfInterCSurf::SetDeflectionOverEstimation, "None", py::arg("x"));
cls_HLRBRep_ThePolygonOfInterCSurf.def("Closed", (void (HLRBRep_ThePolygonOfInterCSurf::*)(const Standard_Boolean)) &HLRBRep_ThePolygonOfInterCSurf::Closed, "None", py::arg("clos"));
cls_HLRBRep_ThePolygonOfInterCSurf.def("Closed", (Standard_Boolean (HLRBRep_ThePolygonOfInterCSurf::*)() const) &HLRBRep_ThePolygonOfInterCSurf::Closed, "None");
cls_HLRBRep_ThePolygonOfInterCSurf.def("NbSegments", (Standard_Integer (HLRBRep_ThePolygonOfInterCSurf::*)() const) &HLRBRep_ThePolygonOfInterCSurf::NbSegments, "Give the number of Segments in the polyline.");
cls_HLRBRep_ThePolygonOfInterCSurf.def("BeginOfSeg", (const gp_Pnt & (HLRBRep_ThePolygonOfInterCSurf::*)(const Standard_Integer) const) &HLRBRep_ThePolygonOfInterCSurf::BeginOfSeg, "Give the point of range Index in the Polygon.", py::arg("Index"));
cls_HLRBRep_ThePolygonOfInterCSurf.def("EndOfSeg", (const gp_Pnt & (HLRBRep_ThePolygonOfInterCSurf::*)(const Standard_Integer) const) &HLRBRep_ThePolygonOfInterCSurf::EndOfSeg, "Give the point of range Index in the Polygon.", py::arg("Index"));
cls_HLRBRep_ThePolygonOfInterCSurf.def("InfParameter", (Standard_Real (HLRBRep_ThePolygonOfInterCSurf::*)() const) &HLRBRep_ThePolygonOfInterCSurf::InfParameter, "Returns the parameter (On the curve) of the first point of the Polygon");
cls_HLRBRep_ThePolygonOfInterCSurf.def("SupParameter", (Standard_Real (HLRBRep_ThePolygonOfInterCSurf::*)() const) &HLRBRep_ThePolygonOfInterCSurf::SupParameter, "Returns the parameter (On the curve) of the last point of the Polygon");
cls_HLRBRep_ThePolygonOfInterCSurf.def("ApproxParamOnCurve", (Standard_Real (HLRBRep_ThePolygonOfInterCSurf::*)(const Standard_Integer, const Standard_Real) const) &HLRBRep_ThePolygonOfInterCSurf::ApproxParamOnCurve, "Give an approximation of the parameter on the curve according to the discretization of the Curve.", py::arg("Index"), py::arg("ParamOnLine"));
cls_HLRBRep_ThePolygonOfInterCSurf.def("Dump", (void (HLRBRep_ThePolygonOfInterCSurf::*)() const) &HLRBRep_ThePolygonOfInterCSurf::Dump, "None");

// CLASS: HLRBREP_THEPOLYGONTOOLOFINTERCSURF
py::class_<HLRBRep_ThePolygonToolOfInterCSurf> cls_HLRBRep_ThePolygonToolOfInterCSurf(mod, "HLRBRep_ThePolygonToolOfInterCSurf", "None");

// Constructors
cls_HLRBRep_ThePolygonToolOfInterCSurf.def(py::init<>());

// Methods
// cls_HLRBRep_ThePolygonToolOfInterCSurf.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_ThePolygonToolOfInterCSurf::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_ThePolygonToolOfInterCSurf.def_static("operator delete_", (void (*)(void *)) &HLRBRep_ThePolygonToolOfInterCSurf::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_ThePolygonToolOfInterCSurf.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_ThePolygonToolOfInterCSurf::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_ThePolygonToolOfInterCSurf.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_ThePolygonToolOfInterCSurf::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_ThePolygonToolOfInterCSurf.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_ThePolygonToolOfInterCSurf::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_ThePolygonToolOfInterCSurf.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_ThePolygonToolOfInterCSurf::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_ThePolygonToolOfInterCSurf.def_static("Bounding_", (const Bnd_Box & (*)(const HLRBRep_ThePolygonOfInterCSurf &)) &HLRBRep_ThePolygonToolOfInterCSurf::Bounding, "Give the bounding box of the polygon.", py::arg("thePolygon"));
cls_HLRBRep_ThePolygonToolOfInterCSurf.def_static("DeflectionOverEstimation_", (Standard_Real (*)(const HLRBRep_ThePolygonOfInterCSurf &)) &HLRBRep_ThePolygonToolOfInterCSurf::DeflectionOverEstimation, "None", py::arg("thePolygon"));
cls_HLRBRep_ThePolygonToolOfInterCSurf.def_static("Closed_", (Standard_Boolean (*)(const HLRBRep_ThePolygonOfInterCSurf &)) &HLRBRep_ThePolygonToolOfInterCSurf::Closed, "None", py::arg("thePolygon"));
cls_HLRBRep_ThePolygonToolOfInterCSurf.def_static("NbSegments_", (Standard_Integer (*)(const HLRBRep_ThePolygonOfInterCSurf &)) &HLRBRep_ThePolygonToolOfInterCSurf::NbSegments, "None", py::arg("thePolygon"));
cls_HLRBRep_ThePolygonToolOfInterCSurf.def_static("BeginOfSeg_", (const gp_Pnt & (*)(const HLRBRep_ThePolygonOfInterCSurf &, const Standard_Integer)) &HLRBRep_ThePolygonToolOfInterCSurf::BeginOfSeg, "Give the point of range Index in the Polygon.", py::arg("thePolygon"), py::arg("Index"));
cls_HLRBRep_ThePolygonToolOfInterCSurf.def_static("EndOfSeg_", (const gp_Pnt & (*)(const HLRBRep_ThePolygonOfInterCSurf &, const Standard_Integer)) &HLRBRep_ThePolygonToolOfInterCSurf::EndOfSeg, "Give the point of range Index in the Polygon.", py::arg("thePolygon"), py::arg("Index"));
cls_HLRBRep_ThePolygonToolOfInterCSurf.def_static("Dump_", (void (*)(const HLRBRep_ThePolygonOfInterCSurf &)) &HLRBRep_ThePolygonToolOfInterCSurf::Dump, "None", py::arg("thePolygon"));

// CLASS: HLRBREP_THEPOLYHEDRONOFINTERCSURF
py::class_<HLRBRep_ThePolyhedronOfInterCSurf> cls_HLRBRep_ThePolyhedronOfInterCSurf(mod, "HLRBRep_ThePolyhedronOfInterCSurf", "None");

// Constructors
cls_HLRBRep_ThePolyhedronOfInterCSurf.def(py::init<const Standard_Address &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Surface"), py::arg("nbdU"), py::arg("nbdV"), py::arg("U1"), py::arg("V1"), py::arg("U2"), py::arg("V2"));
cls_HLRBRep_ThePolyhedronOfInterCSurf.def(py::init<const Standard_Address &, const TColStd_Array1OfReal &, const TColStd_Array1OfReal &>(), py::arg("Surface"), py::arg("Upars"), py::arg("Vpars"));

// Methods
// cls_HLRBRep_ThePolyhedronOfInterCSurf.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_ThePolyhedronOfInterCSurf::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_ThePolyhedronOfInterCSurf.def_static("operator delete_", (void (*)(void *)) &HLRBRep_ThePolyhedronOfInterCSurf::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_ThePolyhedronOfInterCSurf.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_ThePolyhedronOfInterCSurf::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_ThePolyhedronOfInterCSurf.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_ThePolyhedronOfInterCSurf::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_ThePolyhedronOfInterCSurf.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_ThePolyhedronOfInterCSurf::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_ThePolyhedronOfInterCSurf.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_ThePolyhedronOfInterCSurf::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_ThePolyhedronOfInterCSurf.def("Destroy", (void (HLRBRep_ThePolyhedronOfInterCSurf::*)()) &HLRBRep_ThePolyhedronOfInterCSurf::Destroy, "None");
cls_HLRBRep_ThePolyhedronOfInterCSurf.def("DeflectionOverEstimation", (void (HLRBRep_ThePolyhedronOfInterCSurf::*)(const Standard_Real)) &HLRBRep_ThePolyhedronOfInterCSurf::DeflectionOverEstimation, "None", py::arg("flec"));
cls_HLRBRep_ThePolyhedronOfInterCSurf.def("DeflectionOnTriangle", (Standard_Real (HLRBRep_ThePolyhedronOfInterCSurf::*)(const Standard_Address &, const Standard_Integer) const) &HLRBRep_ThePolyhedronOfInterCSurf::DeflectionOnTriangle, "None", py::arg("Surface"), py::arg("Index"));
// cls_HLRBRep_ThePolyhedronOfInterCSurf.def("UMinSingularity", (void (HLRBRep_ThePolyhedronOfInterCSurf::*)(const Standard_Boolean)) &HLRBRep_ThePolyhedronOfInterCSurf::UMinSingularity, "None", py::arg("Sing"));
// cls_HLRBRep_ThePolyhedronOfInterCSurf.def("UMaxSingularity", (void (HLRBRep_ThePolyhedronOfInterCSurf::*)(const Standard_Boolean)) &HLRBRep_ThePolyhedronOfInterCSurf::UMaxSingularity, "None", py::arg("Sing"));
// cls_HLRBRep_ThePolyhedronOfInterCSurf.def("VMinSingularity", (void (HLRBRep_ThePolyhedronOfInterCSurf::*)(const Standard_Boolean)) &HLRBRep_ThePolyhedronOfInterCSurf::VMinSingularity, "None", py::arg("Sing"));
// cls_HLRBRep_ThePolyhedronOfInterCSurf.def("VMaxSingularity", (void (HLRBRep_ThePolyhedronOfInterCSurf::*)(const Standard_Boolean)) &HLRBRep_ThePolyhedronOfInterCSurf::VMaxSingularity, "None", py::arg("Sing"));
cls_HLRBRep_ThePolyhedronOfInterCSurf.def("Size", [](HLRBRep_ThePolyhedronOfInterCSurf &self, Standard_Integer & nbdu, Standard_Integer & nbdv){ self.Size(nbdu, nbdv); return std::tuple<Standard_Integer &, Standard_Integer &>(nbdu, nbdv); }, "get the size of the discretization.", py::arg("nbdu"), py::arg("nbdv"));
cls_HLRBRep_ThePolyhedronOfInterCSurf.def("NbTriangles", (Standard_Integer (HLRBRep_ThePolyhedronOfInterCSurf::*)() const) &HLRBRep_ThePolyhedronOfInterCSurf::NbTriangles, "Give the number of triangles in this double array of");
cls_HLRBRep_ThePolyhedronOfInterCSurf.def("Triangle", [](HLRBRep_ThePolyhedronOfInterCSurf &self, const Standard_Integer Index, Standard_Integer & P1, Standard_Integer & P2, Standard_Integer & P3){ self.Triangle(Index, P1, P2, P3); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &>(P1, P2, P3); }, "Give the 3 points of the triangle of addresse Index in the double array of triangles.", py::arg("Index"), py::arg("P1"), py::arg("P2"), py::arg("P3"));
cls_HLRBRep_ThePolyhedronOfInterCSurf.def("TriConnex", [](HLRBRep_ThePolyhedronOfInterCSurf &self, const Standard_Integer Triang, const Standard_Integer Pivot, const Standard_Integer Pedge, Standard_Integer & TriCon, Standard_Integer & OtherP){ Standard_Integer rv = self.TriConnex(Triang, Pivot, Pedge, TriCon, OtherP); return std::tuple<Standard_Integer, Standard_Integer &, Standard_Integer &>(rv, TriCon, OtherP); }, "Give the addresse Tricon of the triangle connexe to the triangle of address Triang by the edge Pivot Pedge and the third point of this connexe triangle. When we are on a free edge TriCon==0 but the function return the value of the triangle in the other side of Pivot on the free edge. Used to turn around a vertex.", py::arg("Triang"), py::arg("Pivot"), py::arg("Pedge"), py::arg("TriCon"), py::arg("OtherP"));
cls_HLRBRep_ThePolyhedronOfInterCSurf.def("NbPoints", (Standard_Integer (HLRBRep_ThePolyhedronOfInterCSurf::*)() const) &HLRBRep_ThePolyhedronOfInterCSurf::NbPoints, "Give the number of point in the double array of triangles ((nbdu+1)*(nbdv+1)).");
cls_HLRBRep_ThePolyhedronOfInterCSurf.def("Point", (void (HLRBRep_ThePolyhedronOfInterCSurf::*)(const gp_Pnt &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real)) &HLRBRep_ThePolyhedronOfInterCSurf::Point, "Set the value of a field of the double array of points.", py::arg("thePnt"), py::arg("lig"), py::arg("col"), py::arg("U"), py::arg("V"));
cls_HLRBRep_ThePolyhedronOfInterCSurf.def("Point", [](HLRBRep_ThePolyhedronOfInterCSurf &self, const Standard_Integer Index, Standard_Real & U, Standard_Real & V){ const gp_Pnt & rv = self.Point(Index, U, V); return std::tuple<const gp_Pnt &, Standard_Real &, Standard_Real &>(rv, U, V); }, "Give the point of index i in the MaTriangle.", py::arg("Index"), py::arg("U"), py::arg("V"));
cls_HLRBRep_ThePolyhedronOfInterCSurf.def("Point", (const gp_Pnt & (HLRBRep_ThePolyhedronOfInterCSurf::*)(const Standard_Integer) const) &HLRBRep_ThePolyhedronOfInterCSurf::Point, "Give the point of index i in the MaTriangle.", py::arg("Index"));
cls_HLRBRep_ThePolyhedronOfInterCSurf.def("Point", (void (HLRBRep_ThePolyhedronOfInterCSurf::*)(const Standard_Integer, gp_Pnt &) const) &HLRBRep_ThePolyhedronOfInterCSurf::Point, "Give the point of index i in the MaTriangle.", py::arg("Index"), py::arg("P"));
cls_HLRBRep_ThePolyhedronOfInterCSurf.def("Bounding", (const Bnd_Box & (HLRBRep_ThePolyhedronOfInterCSurf::*)() const) &HLRBRep_ThePolyhedronOfInterCSurf::Bounding, "Give the bounding box of the MaTriangle.");
cls_HLRBRep_ThePolyhedronOfInterCSurf.def("FillBounding", (void (HLRBRep_ThePolyhedronOfInterCSurf::*)()) &HLRBRep_ThePolyhedronOfInterCSurf::FillBounding, "Compute the array of boxes. The box <n> corresponding to the triangle <n>.");
cls_HLRBRep_ThePolyhedronOfInterCSurf.def("ComponentsBounding", (const opencascade::handle<Bnd_HArray1OfBox> & (HLRBRep_ThePolyhedronOfInterCSurf::*)() const) &HLRBRep_ThePolyhedronOfInterCSurf::ComponentsBounding, "Give the array of boxes. The box <n> corresponding to the triangle <n>.");
cls_HLRBRep_ThePolyhedronOfInterCSurf.def("DeflectionOverEstimation", (Standard_Real (HLRBRep_ThePolyhedronOfInterCSurf::*)() const) &HLRBRep_ThePolyhedronOfInterCSurf::DeflectionOverEstimation, "None");
// cls_HLRBRep_ThePolyhedronOfInterCSurf.def("HasUMinSingularity", (Standard_Boolean (HLRBRep_ThePolyhedronOfInterCSurf::*)() const) &HLRBRep_ThePolyhedronOfInterCSurf::HasUMinSingularity, "None");
// cls_HLRBRep_ThePolyhedronOfInterCSurf.def("HasUMaxSingularity", (Standard_Boolean (HLRBRep_ThePolyhedronOfInterCSurf::*)() const) &HLRBRep_ThePolyhedronOfInterCSurf::HasUMaxSingularity, "None");
// cls_HLRBRep_ThePolyhedronOfInterCSurf.def("HasVMinSingularity", (Standard_Boolean (HLRBRep_ThePolyhedronOfInterCSurf::*)() const) &HLRBRep_ThePolyhedronOfInterCSurf::HasVMinSingularity, "None");
// cls_HLRBRep_ThePolyhedronOfInterCSurf.def("HasVMaxSingularity", (Standard_Boolean (HLRBRep_ThePolyhedronOfInterCSurf::*)() const) &HLRBRep_ThePolyhedronOfInterCSurf::HasVMaxSingularity, "None");
cls_HLRBRep_ThePolyhedronOfInterCSurf.def("PlaneEquation", [](HLRBRep_ThePolyhedronOfInterCSurf &self, const Standard_Integer Triang, gp_XYZ & NormalVector, Standard_Real & PolarDistance){ self.PlaneEquation(Triang, NormalVector, PolarDistance); return PolarDistance; }, "Give the plane equation of the triangle of addresse Triang.", py::arg("Triang"), py::arg("NormalVector"), py::arg("PolarDistance"));
cls_HLRBRep_ThePolyhedronOfInterCSurf.def("Contain", (Standard_Boolean (HLRBRep_ThePolyhedronOfInterCSurf::*)(const Standard_Integer, const gp_Pnt &) const) &HLRBRep_ThePolyhedronOfInterCSurf::Contain, "Give the plane equation of the triangle of addresse Triang.", py::arg("Triang"), py::arg("ThePnt"));
cls_HLRBRep_ThePolyhedronOfInterCSurf.def("Parameters", [](HLRBRep_ThePolyhedronOfInterCSurf &self, const Standard_Integer Index, Standard_Real & U, Standard_Real & V){ self.Parameters(Index, U, V); return std::tuple<Standard_Real &, Standard_Real &>(U, V); }, "None", py::arg("Index"), py::arg("U"), py::arg("V"));
cls_HLRBRep_ThePolyhedronOfInterCSurf.def("IsOnBound", (Standard_Boolean (HLRBRep_ThePolyhedronOfInterCSurf::*)(const Standard_Integer, const Standard_Integer) const) &HLRBRep_ThePolyhedronOfInterCSurf::IsOnBound, "This method returns true if the edge based on points with indices Index1 and Index2 represents a boundary edge. It is necessary to take into account the boundary deflection for this edge.", py::arg("Index1"), py::arg("Index2"));
cls_HLRBRep_ThePolyhedronOfInterCSurf.def("GetBorderDeflection", (Standard_Real (HLRBRep_ThePolyhedronOfInterCSurf::*)() const) &HLRBRep_ThePolyhedronOfInterCSurf::GetBorderDeflection, "This method returns a border deflection.");
cls_HLRBRep_ThePolyhedronOfInterCSurf.def("Dump", (void (HLRBRep_ThePolyhedronOfInterCSurf::*)() const) &HLRBRep_ThePolyhedronOfInterCSurf::Dump, "None");

// CLASS: HLRBREP_THEPOLYHEDRONTOOLOFINTERCSURF
py::class_<HLRBRep_ThePolyhedronToolOfInterCSurf> cls_HLRBRep_ThePolyhedronToolOfInterCSurf(mod, "HLRBRep_ThePolyhedronToolOfInterCSurf", "None");

// Constructors
cls_HLRBRep_ThePolyhedronToolOfInterCSurf.def(py::init<>());

// Methods
// cls_HLRBRep_ThePolyhedronToolOfInterCSurf.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_ThePolyhedronToolOfInterCSurf::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_ThePolyhedronToolOfInterCSurf.def_static("operator delete_", (void (*)(void *)) &HLRBRep_ThePolyhedronToolOfInterCSurf::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_ThePolyhedronToolOfInterCSurf.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_ThePolyhedronToolOfInterCSurf::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_ThePolyhedronToolOfInterCSurf.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_ThePolyhedronToolOfInterCSurf::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_ThePolyhedronToolOfInterCSurf.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_ThePolyhedronToolOfInterCSurf::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_ThePolyhedronToolOfInterCSurf.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_ThePolyhedronToolOfInterCSurf::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_ThePolyhedronToolOfInterCSurf.def_static("Bounding_", (const Bnd_Box & (*)(const HLRBRep_ThePolyhedronOfInterCSurf &)) &HLRBRep_ThePolyhedronToolOfInterCSurf::Bounding, "Give the bounding box of the PolyhedronTool.", py::arg("thePolyh"));
cls_HLRBRep_ThePolyhedronToolOfInterCSurf.def_static("ComponentsBounding_", (const opencascade::handle<Bnd_HArray1OfBox> & (*)(const HLRBRep_ThePolyhedronOfInterCSurf &)) &HLRBRep_ThePolyhedronToolOfInterCSurf::ComponentsBounding, "Give the array of boxes. The box <n> corresponding to the triangle <n>.", py::arg("thePolyh"));
cls_HLRBRep_ThePolyhedronToolOfInterCSurf.def_static("DeflectionOverEstimation_", (Standard_Real (*)(const HLRBRep_ThePolyhedronOfInterCSurf &)) &HLRBRep_ThePolyhedronToolOfInterCSurf::DeflectionOverEstimation, "Give the tolerance of the polygon.", py::arg("thePolyh"));
cls_HLRBRep_ThePolyhedronToolOfInterCSurf.def_static("NbTriangles_", (Standard_Integer (*)(const HLRBRep_ThePolyhedronOfInterCSurf &)) &HLRBRep_ThePolyhedronToolOfInterCSurf::NbTriangles, "Give the number of triangles in this polyedral surface.", py::arg("thePolyh"));
cls_HLRBRep_ThePolyhedronToolOfInterCSurf.def_static("Triangle_", [](const HLRBRep_ThePolyhedronOfInterCSurf & thePolyh, const Standard_Integer Index, Standard_Integer & P1, Standard_Integer & P2, Standard_Integer & P3){ HLRBRep_ThePolyhedronToolOfInterCSurf::Triangle(thePolyh, Index, P1, P2, P3); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &>(P1, P2, P3); }, "Give the indices of the 3 points of the triangle of address Index in the PolyhedronTool.", py::arg("thePolyh"), py::arg("Index"), py::arg("P1"), py::arg("P2"), py::arg("P3"));
cls_HLRBRep_ThePolyhedronToolOfInterCSurf.def_static("Point_", (const gp_Pnt & (*)(const HLRBRep_ThePolyhedronOfInterCSurf &, const Standard_Integer)) &HLRBRep_ThePolyhedronToolOfInterCSurf::Point, "Give the point of index i in the polyedral surface.", py::arg("thePolyh"), py::arg("Index"));
cls_HLRBRep_ThePolyhedronToolOfInterCSurf.def_static("TriConnex_", [](const HLRBRep_ThePolyhedronOfInterCSurf & thePolyh, const Standard_Integer Triang, const Standard_Integer Pivot, const Standard_Integer Pedge, Standard_Integer & TriCon, Standard_Integer & OtherP){ Standard_Integer rv = HLRBRep_ThePolyhedronToolOfInterCSurf::TriConnex(thePolyh, Triang, Pivot, Pedge, TriCon, OtherP); return std::tuple<Standard_Integer, Standard_Integer &, Standard_Integer &>(rv, TriCon, OtherP); }, "Give the addresse Tricon of the triangle connexe to the triangle of address Triang by the edge Pivot Pedge and the third point of this connexe triangle. When we are on a free edge TriCon==0 but the function return the value of the triangle in the other side of Pivot on the free edge. Used to turn around a vertex.", py::arg("thePolyh"), py::arg("Triang"), py::arg("Pivot"), py::arg("Pedge"), py::arg("TriCon"), py::arg("OtherP"));
cls_HLRBRep_ThePolyhedronToolOfInterCSurf.def_static("IsOnBound_", (Standard_Boolean (*)(const HLRBRep_ThePolyhedronOfInterCSurf &, const Standard_Integer, const Standard_Integer)) &HLRBRep_ThePolyhedronToolOfInterCSurf::IsOnBound, "This method returns true if the edge based on points with indices Index1 and Index2 represents a boundary edge. It is necessary to take into account the boundary deflection for this edge.", py::arg("thePolyh"), py::arg("Index1"), py::arg("Index2"));
cls_HLRBRep_ThePolyhedronToolOfInterCSurf.def_static("GetBorderDeflection_", (Standard_Real (*)(const HLRBRep_ThePolyhedronOfInterCSurf &)) &HLRBRep_ThePolyhedronToolOfInterCSurf::GetBorderDeflection, "This method returns a border deflection of the polyhedron.", py::arg("thePolyh"));
cls_HLRBRep_ThePolyhedronToolOfInterCSurf.def_static("Dump_", (void (*)(const HLRBRep_ThePolyhedronOfInterCSurf &)) &HLRBRep_ThePolyhedronToolOfInterCSurf::Dump, "None", py::arg("thePolyh"));

// CLASS: HLRBREP_THEPROJPCUROFCINTER
py::class_<HLRBRep_TheProjPCurOfCInter> cls_HLRBRep_TheProjPCurOfCInter(mod, "HLRBRep_TheProjPCurOfCInter", "None");

// Constructors
cls_HLRBRep_TheProjPCurOfCInter.def(py::init<>());

// Methods
// cls_HLRBRep_TheProjPCurOfCInter.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_TheProjPCurOfCInter::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_TheProjPCurOfCInter.def_static("operator delete_", (void (*)(void *)) &HLRBRep_TheProjPCurOfCInter::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_TheProjPCurOfCInter.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_TheProjPCurOfCInter::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_TheProjPCurOfCInter.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_TheProjPCurOfCInter::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_TheProjPCurOfCInter.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_TheProjPCurOfCInter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_TheProjPCurOfCInter.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_TheProjPCurOfCInter::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_TheProjPCurOfCInter.def_static("FindParameter_", (Standard_Real (*)(const Standard_Address &, const gp_Pnt2d &, const Standard_Real)) &HLRBRep_TheProjPCurOfCInter::FindParameter, "Returns the parameter V of the point on the parametric curve corresponding to the Point Pnt. The Correspondance between Pnt and the point P(V) on the parametric curve must be coherent with the way of determination of the signed distance between a point and the implicit curve. Tol is the tolerance on the distance between a point and the parametrised curve. In that case, no bounds are given. The research of the rigth parameter has to be made on the natural parametric domain of the curve.", py::arg("C"), py::arg("Pnt"), py::arg("Tol"));
cls_HLRBRep_TheProjPCurOfCInter.def_static("FindParameter_", (Standard_Real (*)(const Standard_Address &, const gp_Pnt2d &, const Standard_Real, const Standard_Real, const Standard_Real)) &HLRBRep_TheProjPCurOfCInter::FindParameter, "Returns the parameter V of the point on the parametric curve corresponding to the Point Pnt. The Correspondance between Pnt and the point P(V) on the parametric curve must be coherent with the way of determination of the signed distance between a point and the implicit curve. Tol is the tolerance on the distance between a point and the parametrised curve. LowParameter and HighParameter give the boundaries of the interval in wich the parameter certainly lies. These parameters are given to implement a more efficient algoritm. So, it is not necessary to check that the returned value verifies LowParameter <= Value <= HighParameter.", py::arg("C"), py::arg("Pnt"), py::arg("LowParameter"), py::arg("HighParameter"), py::arg("Tol"));

// CLASS: HLRBREP_THEQUADCURVEXACTINTERCSURF
py::class_<HLRBRep_TheQuadCurvExactInterCSurf> cls_HLRBRep_TheQuadCurvExactInterCSurf(mod, "HLRBRep_TheQuadCurvExactInterCSurf", "None");

// Constructors
cls_HLRBRep_TheQuadCurvExactInterCSurf.def(py::init<const Standard_Address &, const gp_Lin &>(), py::arg("S"), py::arg("C"));

// Methods
// cls_HLRBRep_TheQuadCurvExactInterCSurf.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_TheQuadCurvExactInterCSurf::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_TheQuadCurvExactInterCSurf.def_static("operator delete_", (void (*)(void *)) &HLRBRep_TheQuadCurvExactInterCSurf::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_TheQuadCurvExactInterCSurf.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_TheQuadCurvExactInterCSurf::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_TheQuadCurvExactInterCSurf.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_TheQuadCurvExactInterCSurf::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_TheQuadCurvExactInterCSurf.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_TheQuadCurvExactInterCSurf::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_TheQuadCurvExactInterCSurf.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_TheQuadCurvExactInterCSurf::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_TheQuadCurvExactInterCSurf.def("IsDone", (Standard_Boolean (HLRBRep_TheQuadCurvExactInterCSurf::*)() const) &HLRBRep_TheQuadCurvExactInterCSurf::IsDone, "None");
cls_HLRBRep_TheQuadCurvExactInterCSurf.def("NbRoots", (Standard_Integer (HLRBRep_TheQuadCurvExactInterCSurf::*)() const) &HLRBRep_TheQuadCurvExactInterCSurf::NbRoots, "None");
cls_HLRBRep_TheQuadCurvExactInterCSurf.def("Root", (Standard_Real (HLRBRep_TheQuadCurvExactInterCSurf::*)(const Standard_Integer) const) &HLRBRep_TheQuadCurvExactInterCSurf::Root, "None", py::arg("Index"));
cls_HLRBRep_TheQuadCurvExactInterCSurf.def("NbIntervals", (Standard_Integer (HLRBRep_TheQuadCurvExactInterCSurf::*)() const) &HLRBRep_TheQuadCurvExactInterCSurf::NbIntervals, "None");
cls_HLRBRep_TheQuadCurvExactInterCSurf.def("Intervals", [](HLRBRep_TheQuadCurvExactInterCSurf &self, const Standard_Integer Index, Standard_Real & U1, Standard_Real & U2){ self.Intervals(Index, U1, U2); return std::tuple<Standard_Real &, Standard_Real &>(U1, U2); }, "U1 and U2 are the parameters of a segment on the curve.", py::arg("Index"), py::arg("U1"), py::arg("U2"));

// CLASS: HLRBREP_THEQUADCURVFUNCOFTHEQUADCURVEXACTINTERCSURF
py::class_<HLRBRep_TheQuadCurvFuncOfTheQuadCurvExactInterCSurf, math_FunctionWithDerivative> cls_HLRBRep_TheQuadCurvFuncOfTheQuadCurvExactInterCSurf(mod, "HLRBRep_TheQuadCurvFuncOfTheQuadCurvExactInterCSurf", "None");

// Constructors
cls_HLRBRep_TheQuadCurvFuncOfTheQuadCurvExactInterCSurf.def(py::init<const IntSurf_Quadric &, const gp_Lin &>(), py::arg("Q"), py::arg("C"));

// Methods
// cls_HLRBRep_TheQuadCurvFuncOfTheQuadCurvExactInterCSurf.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_TheQuadCurvFuncOfTheQuadCurvExactInterCSurf::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_TheQuadCurvFuncOfTheQuadCurvExactInterCSurf.def_static("operator delete_", (void (*)(void *)) &HLRBRep_TheQuadCurvFuncOfTheQuadCurvExactInterCSurf::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_TheQuadCurvFuncOfTheQuadCurvExactInterCSurf.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_TheQuadCurvFuncOfTheQuadCurvExactInterCSurf::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_TheQuadCurvFuncOfTheQuadCurvExactInterCSurf.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_TheQuadCurvFuncOfTheQuadCurvExactInterCSurf::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_TheQuadCurvFuncOfTheQuadCurvExactInterCSurf.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_TheQuadCurvFuncOfTheQuadCurvExactInterCSurf::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_TheQuadCurvFuncOfTheQuadCurvExactInterCSurf.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_TheQuadCurvFuncOfTheQuadCurvExactInterCSurf::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_TheQuadCurvFuncOfTheQuadCurvExactInterCSurf.def("Value", [](HLRBRep_TheQuadCurvFuncOfTheQuadCurvExactInterCSurf &self, const Standard_Real Param, Standard_Real & F){ Standard_Boolean rv = self.Value(Param, F); return std::tuple<Standard_Boolean, Standard_Real &>(rv, F); }, "Computes the value of the signed distance between the implicit surface and the point at parameter Param on the parametrised curve. Value always returns True.", py::arg("Param"), py::arg("F"));
cls_HLRBRep_TheQuadCurvFuncOfTheQuadCurvExactInterCSurf.def("Derivative", [](HLRBRep_TheQuadCurvFuncOfTheQuadCurvExactInterCSurf &self, const Standard_Real Param, Standard_Real & D){ Standard_Boolean rv = self.Derivative(Param, D); return std::tuple<Standard_Boolean, Standard_Real &>(rv, D); }, "Computes the derivative of the previous function at parameter Param. Derivative always returns True.", py::arg("Param"), py::arg("D"));
cls_HLRBRep_TheQuadCurvFuncOfTheQuadCurvExactInterCSurf.def("Values", [](HLRBRep_TheQuadCurvFuncOfTheQuadCurvExactInterCSurf &self, const Standard_Real Param, Standard_Real & F, Standard_Real & D){ Standard_Boolean rv = self.Values(Param, F, D); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, F, D); }, "Computes the value and the derivative of the function. returns True.", py::arg("Param"), py::arg("F"), py::arg("D"));

// CLASS: HLRBREP_VERTEXLIST
py::class_<HLRBRep_VertexList> cls_HLRBRep_VertexList(mod, "HLRBRep_VertexList", "None");

// Constructors
cls_HLRBRep_VertexList.def(py::init<const HLRBRep_EdgeInterferenceTool &, const HLRAlgo_ListIteratorOfInterferenceList &>(), py::arg("T"), py::arg("I"));

// Methods
// cls_HLRBRep_VertexList.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_VertexList::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_VertexList.def_static("operator delete_", (void (*)(void *)) &HLRBRep_VertexList::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_VertexList.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_VertexList::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_VertexList.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_VertexList::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_VertexList.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_VertexList::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_VertexList.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_VertexList::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_VertexList.def("IsPeriodic", (Standard_Boolean (HLRBRep_VertexList::*)() const) &HLRBRep_VertexList::IsPeriodic, "Returns True when the curve is periodic.");
cls_HLRBRep_VertexList.def("More", (Standard_Boolean (HLRBRep_VertexList::*)() const) &HLRBRep_VertexList::More, "Returns True when there are more vertices.");
cls_HLRBRep_VertexList.def("Next", (void (HLRBRep_VertexList::*)()) &HLRBRep_VertexList::Next, "Proceeds to the next vertex.");
cls_HLRBRep_VertexList.def("Current", (const HLRAlgo_Intersection & (HLRBRep_VertexList::*)() const) &HLRBRep_VertexList::Current, "Returns the current vertex");
cls_HLRBRep_VertexList.def("IsBoundary", (Standard_Boolean (HLRBRep_VertexList::*)() const) &HLRBRep_VertexList::IsBoundary, "Returns True if the current vertex is is on the boundary of the edge.");
cls_HLRBRep_VertexList.def("IsInterference", (Standard_Boolean (HLRBRep_VertexList::*)() const) &HLRBRep_VertexList::IsInterference, "Returns True if the current vertex is an interference.");
cls_HLRBRep_VertexList.def("Orientation", (TopAbs_Orientation (HLRBRep_VertexList::*)() const) &HLRBRep_VertexList::Orientation, "Returns the orientation of the current vertex if it is on the boundary of the edge.");
cls_HLRBRep_VertexList.def("Transition", (TopAbs_Orientation (HLRBRep_VertexList::*)() const) &HLRBRep_VertexList::Transition, "Returns the transition of the current vertex if it is an interference.");
cls_HLRBRep_VertexList.def("BoundaryTransition", (TopAbs_Orientation (HLRBRep_VertexList::*)() const) &HLRBRep_VertexList::BoundaryTransition, "Returns the transition of the current vertex relative to the boundary if it is an interference.");


}
