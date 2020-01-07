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
#include <BRepCheck_Status.hxx>
#include <NCollection_List.hxx>
#include <BRepCheck_ListOfStatus.hxx>
#include <Standard.hxx>
#include <Standard_OStream.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Wire.hxx>
#include <TopoDS_Face.hxx>
#include <TopoDS_Edge.hxx>
#include <Adaptor3d_Curve.hxx>
#include <Standard_Handle.hxx>
#include <Adaptor3d_HSurface.hxx>
#include <BRepCheck_Result.hxx>
#include <BRepCheck_Vertex.hxx>
#include <BRepCheck_Edge.hxx>
#include <BRepCheck_Wire.hxx>
#include <BRepCheck_Face.hxx>
#include <BRepCheck_Shell.hxx>
#include <BRepCheck_Solid.hxx>
#include <BRepCheck_Analyzer.hxx>
#include <BRepCheck.hxx>
#include <NCollection_DataMap.hxx>
#include <TopoDS_Shape.hxx>
#include <TopTools_ShapeMapHasher.hxx>
#include <BRepCheck_DataMapOfShapeListOfStatus.hxx>
#include <Standard_Transient.hxx>
#include <Standard_Std.hxx>
#include <Standard_Type.hxx>
#include <TopTools_OrientedShapeMapHasher.hxx>
#include <BRepCheck_DataMapOfShapeResult.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <BRep_CurveRepresentation.hxx>
#include <Adaptor3d_HCurve.hxx>
#include <TopTools_DataMapOfShapeListOfShape.hxx>
#include <TopoDS_Shell.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TopTools_IndexedDataMapOfShapeListOfShape.hxx>
#include <TopoDS_Solid.hxx>
#include <TopoDS_Vertex.hxx>
#include <bind_NCollection_List.hxx>
#include <bind_NCollection_TListIterator.hxx>
#include <bind_NCollection_DataMap.hxx>

PYBIND11_MODULE(BRepCheck, mod) {

py::module::import("OCCT.NCollection");
py::module::import("OCCT.Standard");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.Adaptor3d");
py::module::import("OCCT.TopTools");
py::module::import("OCCT.TopAbs");
py::module::import("OCCT.BRep");

// ENUM: BREPCHECK_STATUS
py::enum_<BRepCheck_Status>(mod, "BRepCheck_Status", "None")
	.value("BRepCheck_NoError", BRepCheck_Status::BRepCheck_NoError)
	.value("BRepCheck_InvalidPointOnCurve", BRepCheck_Status::BRepCheck_InvalidPointOnCurve)
	.value("BRepCheck_InvalidPointOnCurveOnSurface", BRepCheck_Status::BRepCheck_InvalidPointOnCurveOnSurface)
	.value("BRepCheck_InvalidPointOnSurface", BRepCheck_Status::BRepCheck_InvalidPointOnSurface)
	.value("BRepCheck_No3DCurve", BRepCheck_Status::BRepCheck_No3DCurve)
	.value("BRepCheck_Multiple3DCurve", BRepCheck_Status::BRepCheck_Multiple3DCurve)
	.value("BRepCheck_Invalid3DCurve", BRepCheck_Status::BRepCheck_Invalid3DCurve)
	.value("BRepCheck_NoCurveOnSurface", BRepCheck_Status::BRepCheck_NoCurveOnSurface)
	.value("BRepCheck_InvalidCurveOnSurface", BRepCheck_Status::BRepCheck_InvalidCurveOnSurface)
	.value("BRepCheck_InvalidCurveOnClosedSurface", BRepCheck_Status::BRepCheck_InvalidCurveOnClosedSurface)
	.value("BRepCheck_InvalidSameRangeFlag", BRepCheck_Status::BRepCheck_InvalidSameRangeFlag)
	.value("BRepCheck_InvalidSameParameterFlag", BRepCheck_Status::BRepCheck_InvalidSameParameterFlag)
	.value("BRepCheck_InvalidDegeneratedFlag", BRepCheck_Status::BRepCheck_InvalidDegeneratedFlag)
	.value("BRepCheck_FreeEdge", BRepCheck_Status::BRepCheck_FreeEdge)
	.value("BRepCheck_InvalidMultiConnexity", BRepCheck_Status::BRepCheck_InvalidMultiConnexity)
	.value("BRepCheck_InvalidRange", BRepCheck_Status::BRepCheck_InvalidRange)
	.value("BRepCheck_EmptyWire", BRepCheck_Status::BRepCheck_EmptyWire)
	.value("BRepCheck_RedundantEdge", BRepCheck_Status::BRepCheck_RedundantEdge)
	.value("BRepCheck_SelfIntersectingWire", BRepCheck_Status::BRepCheck_SelfIntersectingWire)
	.value("BRepCheck_NoSurface", BRepCheck_Status::BRepCheck_NoSurface)
	.value("BRepCheck_InvalidWire", BRepCheck_Status::BRepCheck_InvalidWire)
	.value("BRepCheck_RedundantWire", BRepCheck_Status::BRepCheck_RedundantWire)
	.value("BRepCheck_IntersectingWires", BRepCheck_Status::BRepCheck_IntersectingWires)
	.value("BRepCheck_InvalidImbricationOfWires", BRepCheck_Status::BRepCheck_InvalidImbricationOfWires)
	.value("BRepCheck_EmptyShell", BRepCheck_Status::BRepCheck_EmptyShell)
	.value("BRepCheck_RedundantFace", BRepCheck_Status::BRepCheck_RedundantFace)
	.value("BRepCheck_InvalidImbricationOfShells", BRepCheck_Status::BRepCheck_InvalidImbricationOfShells)
	.value("BRepCheck_UnorientableShape", BRepCheck_Status::BRepCheck_UnorientableShape)
	.value("BRepCheck_NotClosed", BRepCheck_Status::BRepCheck_NotClosed)
	.value("BRepCheck_NotConnected", BRepCheck_Status::BRepCheck_NotConnected)
	.value("BRepCheck_SubshapeNotInShape", BRepCheck_Status::BRepCheck_SubshapeNotInShape)
	.value("BRepCheck_BadOrientation", BRepCheck_Status::BRepCheck_BadOrientation)
	.value("BRepCheck_BadOrientationOfSubshape", BRepCheck_Status::BRepCheck_BadOrientationOfSubshape)
	.value("BRepCheck_InvalidPolygonOnTriangulation", BRepCheck_Status::BRepCheck_InvalidPolygonOnTriangulation)
	.value("BRepCheck_InvalidToleranceValue", BRepCheck_Status::BRepCheck_InvalidToleranceValue)
	.value("BRepCheck_EnclosedRegion", BRepCheck_Status::BRepCheck_EnclosedRegion)
	.value("BRepCheck_CheckFail", BRepCheck_Status::BRepCheck_CheckFail)
	.export_values();


// TYPEDEF: BREPCHECK_LISTOFSTATUS
bind_NCollection_List<BRepCheck_Status>(mod, "BRepCheck_ListOfStatus", py::module_local(false));

// TYPEDEF: BREPCHECK_LISTITERATOROFLISTOFSTATUS
bind_NCollection_TListIterator<BRepCheck_Status>(mod, "BRepCheck_ListIteratorOfListOfStatus", py::module_local(false));

// CLASS: BREPCHECK
py::class_<BRepCheck> cls_BRepCheck(mod, "BRepCheck", "This package provides tools to check the validity of the BRep.");

// Constructors
cls_BRepCheck.def(py::init<>());

// Methods
// cls_BRepCheck.def_static("operator new_", (void * (*)(size_t)) &BRepCheck::operator new, "None", py::arg("theSize"));
// cls_BRepCheck.def_static("operator delete_", (void (*)(void *)) &BRepCheck::operator delete, "None", py::arg("theAddress"));
// cls_BRepCheck.def_static("operator new[]_", (void * (*)(size_t)) &BRepCheck::operator new[], "None", py::arg("theSize"));
// cls_BRepCheck.def_static("operator delete[]_", (void (*)(void *)) &BRepCheck::operator delete[], "None", py::arg("theAddress"));
// cls_BRepCheck.def_static("operator new_", (void * (*)(size_t, void *)) &BRepCheck::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepCheck.def_static("operator delete_", (void (*)(void *, void *)) &BRepCheck::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepCheck.def_static("Add_", (void (*)(BRepCheck_ListOfStatus &, const BRepCheck_Status)) &BRepCheck::Add, "None", py::arg("List"), py::arg("Stat"));
cls_BRepCheck.def_static("Print_", (void (*)(const BRepCheck_Status, Standard_OStream &)) &BRepCheck::Print, "None", py::arg("Stat"), py::arg("OS"));
cls_BRepCheck.def_static("SelfIntersection_", (Standard_Boolean (*)(const TopoDS_Wire &, const TopoDS_Face &, TopoDS_Edge &, TopoDS_Edge &)) &BRepCheck::SelfIntersection, "None", py::arg("W"), py::arg("F"), py::arg("E1"), py::arg("E2"));
cls_BRepCheck.def_static("PrecCurve_", (Standard_Real (*)(const Adaptor3d_Curve &)) &BRepCheck::PrecCurve, "Returns the resolution on the 3d curve", py::arg("aAC3D"));
cls_BRepCheck.def_static("PrecSurface_", (Standard_Real (*)(const opencascade::handle<Adaptor3d_HSurface> &)) &BRepCheck::PrecSurface, "Returns the resolution on the surface", py::arg("aAHSurf"));

// TYPEDEF: BREPCHECK_DATAMAPOFSHAPELISTOFSTATUS
bind_NCollection_DataMap<TopoDS_Shape, NCollection_List<BRepCheck_Status>, TopTools_ShapeMapHasher>(mod, "BRepCheck_DataMapOfShapeListOfStatus", py::module_local(false));

// TYPEDEF: BREPCHECK_DATAMAPITERATOROFDATAMAPOFSHAPELISTOFSTATUS
py::class_<NCollection_DataMap<TopoDS_Shape, NCollection_List<BRepCheck_Status>, TopTools_ShapeMapHasher>::Iterator, NCollection_BaseMap::Iterator> cls_NCollection_DataMap_BRepCheck_DataMapIteratorOfDataMapOfShapeListOfStatus(mod, "BRepCheck_DataMapIteratorOfDataMapOfShapeListOfStatus", "None");

// Constructors
cls_NCollection_DataMap_BRepCheck_DataMapIteratorOfDataMapOfShapeListOfStatus.def(py::init<>());
cls_NCollection_DataMap_BRepCheck_DataMapIteratorOfDataMapOfShapeListOfStatus.def(py::init<const NCollection_DataMap<TopoDS_Shape, NCollection_List<BRepCheck_Status>, TopTools_ShapeMapHasher> &>(), py::arg("theMap"));

// Methods
cls_NCollection_DataMap_BRepCheck_DataMapIteratorOfDataMapOfShapeListOfStatus.def("More", (Standard_Boolean (NCollection_DataMap<TopoDS_Shape, NCollection_List<BRepCheck_Status>, TopTools_ShapeMapHasher>::Iterator::*)() const) &NCollection_DataMap<TopoDS_Shape, NCollection_List<BRepCheck_Status>, TopTools_ShapeMapHasher>::Iterator::More, "Query if the end of collection is reached by iterator");
cls_NCollection_DataMap_BRepCheck_DataMapIteratorOfDataMapOfShapeListOfStatus.def("Next", (void (NCollection_DataMap<TopoDS_Shape, NCollection_List<BRepCheck_Status>, TopTools_ShapeMapHasher>::Iterator::*)()) &NCollection_DataMap<TopoDS_Shape, NCollection_List<BRepCheck_Status>, TopTools_ShapeMapHasher>::Iterator::Next, "Make a step along the collection");
cls_NCollection_DataMap_BRepCheck_DataMapIteratorOfDataMapOfShapeListOfStatus.def("Value", (const NCollection_List<BRepCheck_Status> & (NCollection_DataMap<TopoDS_Shape, NCollection_List<BRepCheck_Status>, TopTools_ShapeMapHasher>::Iterator::*)() const) &NCollection_DataMap<TopoDS_Shape, NCollection_List<BRepCheck_Status>, TopTools_ShapeMapHasher>::Iterator::Value, "Value inquiry");
cls_NCollection_DataMap_BRepCheck_DataMapIteratorOfDataMapOfShapeListOfStatus.def("ChangeValue", (NCollection_List<BRepCheck_Status> & (NCollection_DataMap<TopoDS_Shape, NCollection_List<BRepCheck_Status>, TopTools_ShapeMapHasher>::Iterator::*)() const) &NCollection_DataMap<TopoDS_Shape, NCollection_List<BRepCheck_Status>, TopTools_ShapeMapHasher>::Iterator::ChangeValue, "Value change access");
cls_NCollection_DataMap_BRepCheck_DataMapIteratorOfDataMapOfShapeListOfStatus.def("Key", (const TopoDS_Shape & (NCollection_DataMap<TopoDS_Shape, NCollection_List<BRepCheck_Status>, TopTools_ShapeMapHasher>::Iterator::*)() const) &NCollection_DataMap<TopoDS_Shape, NCollection_List<BRepCheck_Status>, TopTools_ShapeMapHasher>::Iterator::Key, "Key");

// CLASS: BREPCHECK_RESULT
py::class_<BRepCheck_Result, opencascade::handle<BRepCheck_Result>, Standard_Transient> cls_BRepCheck_Result(mod, "BRepCheck_Result", "None");

// Methods
cls_BRepCheck_Result.def("Init", (void (BRepCheck_Result::*)(const TopoDS_Shape &)) &BRepCheck_Result::Init, "None", py::arg("S"));
cls_BRepCheck_Result.def("InContext", (void (BRepCheck_Result::*)(const TopoDS_Shape &)) &BRepCheck_Result::InContext, "None", py::arg("ContextShape"));
cls_BRepCheck_Result.def("Minimum", (void (BRepCheck_Result::*)()) &BRepCheck_Result::Minimum, "None");
cls_BRepCheck_Result.def("Blind", (void (BRepCheck_Result::*)()) &BRepCheck_Result::Blind, "None");
cls_BRepCheck_Result.def("SetFailStatus", (void (BRepCheck_Result::*)(const TopoDS_Shape &)) &BRepCheck_Result::SetFailStatus, "None", py::arg("S"));
cls_BRepCheck_Result.def("Status", (const BRepCheck_ListOfStatus & (BRepCheck_Result::*)() const) &BRepCheck_Result::Status, "None");
cls_BRepCheck_Result.def("IsMinimum", (Standard_Boolean (BRepCheck_Result::*)() const) &BRepCheck_Result::IsMinimum, "None");
cls_BRepCheck_Result.def("IsBlind", (Standard_Boolean (BRepCheck_Result::*)() const) &BRepCheck_Result::IsBlind, "None");
cls_BRepCheck_Result.def("StatusOnShape", (const BRepCheck_ListOfStatus & (BRepCheck_Result::*)(const TopoDS_Shape &)) &BRepCheck_Result::StatusOnShape, "If not already done, performs the InContext control and returns the list of status.", py::arg("S"));
cls_BRepCheck_Result.def("InitContextIterator", (void (BRepCheck_Result::*)()) &BRepCheck_Result::InitContextIterator, "None");
cls_BRepCheck_Result.def("MoreShapeInContext", (Standard_Boolean (BRepCheck_Result::*)() const) &BRepCheck_Result::MoreShapeInContext, "None");
cls_BRepCheck_Result.def("ContextualShape", (const TopoDS_Shape & (BRepCheck_Result::*)() const) &BRepCheck_Result::ContextualShape, "None");
cls_BRepCheck_Result.def("StatusOnShape", (const BRepCheck_ListOfStatus & (BRepCheck_Result::*)() const) &BRepCheck_Result::StatusOnShape, "None");
cls_BRepCheck_Result.def("NextShapeInContext", (void (BRepCheck_Result::*)()) &BRepCheck_Result::NextShapeInContext, "None");
cls_BRepCheck_Result.def_static("get_type_name_", (const char * (*)()) &BRepCheck_Result::get_type_name, "None");
cls_BRepCheck_Result.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepCheck_Result::get_type_descriptor, "None");
cls_BRepCheck_Result.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepCheck_Result::*)() const) &BRepCheck_Result::DynamicType, "None");

// TYPEDEF: BREPCHECK_DATAMAPOFSHAPERESULT
bind_NCollection_DataMap<TopoDS_Shape, opencascade::handle<BRepCheck_Result>, TopTools_OrientedShapeMapHasher>(mod, "BRepCheck_DataMapOfShapeResult", py::module_local(false));

// TYPEDEF: BREPCHECK_DATAMAPITERATOROFDATAMAPOFSHAPERESULT

// CLASS: BREPCHECK_ANALYZER
py::class_<BRepCheck_Analyzer> cls_BRepCheck_Analyzer(mod, "BRepCheck_Analyzer", "A framework to check the overall validity of a shape. For a shape to be valid in Open CASCADE, it - or its component subshapes - must respect certain criteria. These criteria are checked by the function IsValid. Once you have determined whether a shape is valid or not, you can diagnose its specific anomalies and correct them using the services of the ShapeAnalysis, ShapeUpgrade, and ShapeFix packages.");

// Constructors
cls_BRepCheck_Analyzer.def(py::init<const TopoDS_Shape &>(), py::arg("S"));
cls_BRepCheck_Analyzer.def(py::init<const TopoDS_Shape &, const Standard_Boolean>(), py::arg("S"), py::arg("GeomControls"));

// Methods
// cls_BRepCheck_Analyzer.def_static("operator new_", (void * (*)(size_t)) &BRepCheck_Analyzer::operator new, "None", py::arg("theSize"));
// cls_BRepCheck_Analyzer.def_static("operator delete_", (void (*)(void *)) &BRepCheck_Analyzer::operator delete, "None", py::arg("theAddress"));
// cls_BRepCheck_Analyzer.def_static("operator new[]_", (void * (*)(size_t)) &BRepCheck_Analyzer::operator new[], "None", py::arg("theSize"));
// cls_BRepCheck_Analyzer.def_static("operator delete[]_", (void (*)(void *)) &BRepCheck_Analyzer::operator delete[], "None", py::arg("theAddress"));
// cls_BRepCheck_Analyzer.def_static("operator new_", (void * (*)(size_t, void *)) &BRepCheck_Analyzer::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepCheck_Analyzer.def_static("operator delete_", (void (*)(void *, void *)) &BRepCheck_Analyzer::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepCheck_Analyzer.def("Init", [](BRepCheck_Analyzer &self, const TopoDS_Shape & a0) -> void { return self.Init(a0); });
cls_BRepCheck_Analyzer.def("Init", (void (BRepCheck_Analyzer::*)(const TopoDS_Shape &, const Standard_Boolean)) &BRepCheck_Analyzer::Init, "<S> is the shape to control. <GeomControls> If False only topological informaions are checked. The geometricals controls are For a Vertex : BRepCheck_InvalidTolerance NYI For an Edge : BRepCheck_InvalidCurveOnClosedSurface, BRepCheck_InvalidCurveOnSurface, BRepCheck_InvalidSameParameterFlag, BRepCheck_InvalidTolerance NYI For a face : BRepCheck_UnorientableShape, BRepCheck_IntersectingWires, BRepCheck_InvalidTolerance NYI For a wire : BRepCheck_SelfIntersectingWire", py::arg("S"), py::arg("GeomControls"));
cls_BRepCheck_Analyzer.def("IsValid", (Standard_Boolean (BRepCheck_Analyzer::*)(const TopoDS_Shape &) const) &BRepCheck_Analyzer::IsValid, "<S> is a subshape of the original shape. Returns <STandard_True> if no default has been detected on <S> and any of its subshape.", py::arg("S"));
cls_BRepCheck_Analyzer.def("IsValid", (Standard_Boolean (BRepCheck_Analyzer::*)() const) &BRepCheck_Analyzer::IsValid, "Returns true if no defect is detected on the shape S or any of its subshapes. Returns true if the shape S is valid. This function checks whether a given shape is valid by checking that: - the topology is correct - parameterization of edges in particular is correct. For the topology to be correct, the following conditions must be satisfied: - edges should have at least two vertices if they are not degenerate edges. The vertices should be within the range of the bounding edges at the tolerance specified in the vertex, - edges should share at least one face. The representation of the edges should be within the tolerance criterion assigned to them. - wires defining a face should not self-intersect and should be closed, - there should be one wire which contains all other wires inside a face, - wires should be correctly oriented with respect to each of the edges, - faces should be correctly oriented, in particular with respect to adjacent faces if these faces define a solid, - shells defining a solid should be closed. There should be one enclosing shell if the shape is a solid; To check parameterization of edge, there are 2 approaches depending on the edge?s contextual situation. - if the edge is either single, or it is in the context of a wire or a compound, its parameterization is defined by the parameterization of its 3D curve and is considered as valid. - If the edge is in the context of a face, it should have SameParameter and SameRange flags set to Standard_True. To check these flags, you should call the function BRep_Tool::SameParameter and BRep_Tool::SameRange for an edge. If at least one of these flags is set to Standard_False, the edge is considered as invalid without any additional check. If the edge is contained by a face, and it has SameParameter and SameRange flags set to Standard_True, IsValid checks whether representation of the edge on face, in context of which the edge is considered, has the same parameterization up to the tolerance value coded on the edge. For a given parameter t on the edge having C as a 3D curve and one PCurve P on a surface S (base surface of the reference face), this checks that |C(t) - S(P(t))| is less than or equal to tolerance, where tolerance is the tolerance value coded on the edge.");
cls_BRepCheck_Analyzer.def("Result", (const opencascade::handle<BRepCheck_Result> & (BRepCheck_Analyzer::*)(const TopoDS_Shape &) const) &BRepCheck_Analyzer::Result, "None", py::arg("SubS"));

// CLASS: BREPCHECK_EDGE
py::class_<BRepCheck_Edge, opencascade::handle<BRepCheck_Edge>, BRepCheck_Result> cls_BRepCheck_Edge(mod, "BRepCheck_Edge", "None");

// Constructors
cls_BRepCheck_Edge.def(py::init<const TopoDS_Edge &>(), py::arg("E"));

// Methods
cls_BRepCheck_Edge.def("InContext", (void (BRepCheck_Edge::*)(const TopoDS_Shape &)) &BRepCheck_Edge::InContext, "None", py::arg("ContextShape"));
cls_BRepCheck_Edge.def("Minimum", (void (BRepCheck_Edge::*)()) &BRepCheck_Edge::Minimum, "None");
cls_BRepCheck_Edge.def("Blind", (void (BRepCheck_Edge::*)()) &BRepCheck_Edge::Blind, "None");
cls_BRepCheck_Edge.def("GeometricControls", (Standard_Boolean (BRepCheck_Edge::*)() const) &BRepCheck_Edge::GeometricControls, "None");
cls_BRepCheck_Edge.def("GeometricControls", (void (BRepCheck_Edge::*)(const Standard_Boolean)) &BRepCheck_Edge::GeometricControls, "None", py::arg("B"));
cls_BRepCheck_Edge.def("Tolerance", (Standard_Real (BRepCheck_Edge::*)()) &BRepCheck_Edge::Tolerance, "None");
cls_BRepCheck_Edge.def("SetStatus", (void (BRepCheck_Edge::*)(const BRepCheck_Status)) &BRepCheck_Edge::SetStatus, "Sets status of Edge;", py::arg("theStatus"));
cls_BRepCheck_Edge.def("CheckPolygonOnTriangulation", (BRepCheck_Status (BRepCheck_Edge::*)(const TopoDS_Edge &)) &BRepCheck_Edge::CheckPolygonOnTriangulation, "Checks, if polygon on triangulation of heEdge is out of 3D-curve of this edge.", py::arg("theEdge"));
cls_BRepCheck_Edge.def_static("get_type_name_", (const char * (*)()) &BRepCheck_Edge::get_type_name, "None");
cls_BRepCheck_Edge.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepCheck_Edge::get_type_descriptor, "None");
cls_BRepCheck_Edge.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepCheck_Edge::*)() const) &BRepCheck_Edge::DynamicType, "None");

// CLASS: BREPCHECK_FACE
py::class_<BRepCheck_Face, opencascade::handle<BRepCheck_Face>, BRepCheck_Result> cls_BRepCheck_Face(mod, "BRepCheck_Face", "None");

// Constructors
cls_BRepCheck_Face.def(py::init<const TopoDS_Face &>(), py::arg("F"));

// Methods
cls_BRepCheck_Face.def("InContext", (void (BRepCheck_Face::*)(const TopoDS_Shape &)) &BRepCheck_Face::InContext, "None", py::arg("ContextShape"));
cls_BRepCheck_Face.def("Minimum", (void (BRepCheck_Face::*)()) &BRepCheck_Face::Minimum, "None");
cls_BRepCheck_Face.def("Blind", (void (BRepCheck_Face::*)()) &BRepCheck_Face::Blind, "None");
cls_BRepCheck_Face.def("IntersectWires", [](BRepCheck_Face &self) -> BRepCheck_Status { return self.IntersectWires(); });
cls_BRepCheck_Face.def("IntersectWires", (BRepCheck_Status (BRepCheck_Face::*)(const Standard_Boolean)) &BRepCheck_Face::IntersectWires, "None", py::arg("Update"));
cls_BRepCheck_Face.def("ClassifyWires", [](BRepCheck_Face &self) -> BRepCheck_Status { return self.ClassifyWires(); });
cls_BRepCheck_Face.def("ClassifyWires", (BRepCheck_Status (BRepCheck_Face::*)(const Standard_Boolean)) &BRepCheck_Face::ClassifyWires, "None", py::arg("Update"));
cls_BRepCheck_Face.def("OrientationOfWires", [](BRepCheck_Face &self) -> BRepCheck_Status { return self.OrientationOfWires(); });
cls_BRepCheck_Face.def("OrientationOfWires", (BRepCheck_Status (BRepCheck_Face::*)(const Standard_Boolean)) &BRepCheck_Face::OrientationOfWires, "None", py::arg("Update"));
cls_BRepCheck_Face.def("SetUnorientable", (void (BRepCheck_Face::*)()) &BRepCheck_Face::SetUnorientable, "None");
cls_BRepCheck_Face.def("SetStatus", (void (BRepCheck_Face::*)(const BRepCheck_Status)) &BRepCheck_Face::SetStatus, "Sets status of Face;", py::arg("theStatus"));
cls_BRepCheck_Face.def("IsUnorientable", (Standard_Boolean (BRepCheck_Face::*)() const) &BRepCheck_Face::IsUnorientable, "None");
cls_BRepCheck_Face.def("GeometricControls", (Standard_Boolean (BRepCheck_Face::*)() const) &BRepCheck_Face::GeometricControls, "None");
cls_BRepCheck_Face.def("GeometricControls", (void (BRepCheck_Face::*)(const Standard_Boolean)) &BRepCheck_Face::GeometricControls, "None", py::arg("B"));
cls_BRepCheck_Face.def_static("get_type_name_", (const char * (*)()) &BRepCheck_Face::get_type_name, "None");
cls_BRepCheck_Face.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepCheck_Face::get_type_descriptor, "None");
cls_BRepCheck_Face.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepCheck_Face::*)() const) &BRepCheck_Face::DynamicType, "None");

// CLASS: BREPCHECK_SHELL
py::class_<BRepCheck_Shell, opencascade::handle<BRepCheck_Shell>, BRepCheck_Result> cls_BRepCheck_Shell(mod, "BRepCheck_Shell", "None");

// Constructors
cls_BRepCheck_Shell.def(py::init<const TopoDS_Shell &>(), py::arg("S"));

// Methods
cls_BRepCheck_Shell.def("InContext", (void (BRepCheck_Shell::*)(const TopoDS_Shape &)) &BRepCheck_Shell::InContext, "None", py::arg("ContextShape"));
cls_BRepCheck_Shell.def("Minimum", (void (BRepCheck_Shell::*)()) &BRepCheck_Shell::Minimum, "None");
cls_BRepCheck_Shell.def("Blind", (void (BRepCheck_Shell::*)()) &BRepCheck_Shell::Blind, "None");
cls_BRepCheck_Shell.def("Closed", [](BRepCheck_Shell &self) -> BRepCheck_Status { return self.Closed(); });
cls_BRepCheck_Shell.def("Closed", (BRepCheck_Status (BRepCheck_Shell::*)(const Standard_Boolean)) &BRepCheck_Shell::Closed, "Checks if the oriented faces of the shell give a closed shell. If the wire is closed, returns BRepCheck_NoError.If <Update> is set to Standard_True, registers the status in the list.", py::arg("Update"));
cls_BRepCheck_Shell.def("Orientation", [](BRepCheck_Shell &self) -> BRepCheck_Status { return self.Orientation(); });
cls_BRepCheck_Shell.def("Orientation", (BRepCheck_Status (BRepCheck_Shell::*)(const Standard_Boolean)) &BRepCheck_Shell::Orientation, "Checks if the oriented faces of the shell are correctly oriented. An internal call is made to the method Closed. If <Update> is set to Standard_True, registers the status in the list.", py::arg("Update"));
cls_BRepCheck_Shell.def("SetUnorientable", (void (BRepCheck_Shell::*)()) &BRepCheck_Shell::SetUnorientable, "None");
cls_BRepCheck_Shell.def("IsUnorientable", (Standard_Boolean (BRepCheck_Shell::*)() const) &BRepCheck_Shell::IsUnorientable, "None");
cls_BRepCheck_Shell.def("NbConnectedSet", (Standard_Integer (BRepCheck_Shell::*)(TopTools_ListOfShape &)) &BRepCheck_Shell::NbConnectedSet, "None", py::arg("theSets"));
cls_BRepCheck_Shell.def_static("get_type_name_", (const char * (*)()) &BRepCheck_Shell::get_type_name, "None");
cls_BRepCheck_Shell.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepCheck_Shell::get_type_descriptor, "None");
cls_BRepCheck_Shell.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepCheck_Shell::*)() const) &BRepCheck_Shell::DynamicType, "None");

// CLASS: BREPCHECK_SOLID
py::class_<BRepCheck_Solid, opencascade::handle<BRepCheck_Solid>, BRepCheck_Result> cls_BRepCheck_Solid(mod, "BRepCheck_Solid", "The class is to check a solid.");

// Constructors
cls_BRepCheck_Solid.def(py::init<const TopoDS_Solid &>(), py::arg("theS"));

// Methods
cls_BRepCheck_Solid.def("InContext", (void (BRepCheck_Solid::*)(const TopoDS_Shape &)) &BRepCheck_Solid::InContext, "Checks the solid in context of the shape <theContextShape>", py::arg("theContextShape"));
cls_BRepCheck_Solid.def("Minimum", (void (BRepCheck_Solid::*)()) &BRepCheck_Solid::Minimum, "Checks the solid per se.");
cls_BRepCheck_Solid.def("Blind", (void (BRepCheck_Solid::*)()) &BRepCheck_Solid::Blind, "see the parent class for more details");
cls_BRepCheck_Solid.def_static("get_type_name_", (const char * (*)()) &BRepCheck_Solid::get_type_name, "None");
cls_BRepCheck_Solid.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepCheck_Solid::get_type_descriptor, "None");
cls_BRepCheck_Solid.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepCheck_Solid::*)() const) &BRepCheck_Solid::DynamicType, "None");

// CLASS: BREPCHECK_VERTEX
py::class_<BRepCheck_Vertex, opencascade::handle<BRepCheck_Vertex>, BRepCheck_Result> cls_BRepCheck_Vertex(mod, "BRepCheck_Vertex", "None");

// Constructors
cls_BRepCheck_Vertex.def(py::init<const TopoDS_Vertex &>(), py::arg("V"));

// Methods
cls_BRepCheck_Vertex.def("InContext", (void (BRepCheck_Vertex::*)(const TopoDS_Shape &)) &BRepCheck_Vertex::InContext, "None", py::arg("ContextShape"));
cls_BRepCheck_Vertex.def("Minimum", (void (BRepCheck_Vertex::*)()) &BRepCheck_Vertex::Minimum, "None");
cls_BRepCheck_Vertex.def("Blind", (void (BRepCheck_Vertex::*)()) &BRepCheck_Vertex::Blind, "None");
cls_BRepCheck_Vertex.def("Tolerance", (Standard_Real (BRepCheck_Vertex::*)()) &BRepCheck_Vertex::Tolerance, "None");
cls_BRepCheck_Vertex.def_static("get_type_name_", (const char * (*)()) &BRepCheck_Vertex::get_type_name, "None");
cls_BRepCheck_Vertex.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepCheck_Vertex::get_type_descriptor, "None");
cls_BRepCheck_Vertex.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepCheck_Vertex::*)() const) &BRepCheck_Vertex::DynamicType, "None");

// CLASS: BREPCHECK_WIRE
py::class_<BRepCheck_Wire, opencascade::handle<BRepCheck_Wire>, BRepCheck_Result> cls_BRepCheck_Wire(mod, "BRepCheck_Wire", "None");

// Constructors
cls_BRepCheck_Wire.def(py::init<const TopoDS_Wire &>(), py::arg("W"));

// Methods
cls_BRepCheck_Wire.def("InContext", (void (BRepCheck_Wire::*)(const TopoDS_Shape &)) &BRepCheck_Wire::InContext, "if <ContextShape> is a face, consequently checks SelfIntersect(), Closed(), Orientation() and Closed2d until faulty is found", py::arg("ContextShape"));
cls_BRepCheck_Wire.def("Minimum", (void (BRepCheck_Wire::*)()) &BRepCheck_Wire::Minimum, "checks that the wire is not empty and 'connex'. Called by constructor");
cls_BRepCheck_Wire.def("Blind", (void (BRepCheck_Wire::*)()) &BRepCheck_Wire::Blind, "Does nothing");
cls_BRepCheck_Wire.def("Closed", [](BRepCheck_Wire &self) -> BRepCheck_Status { return self.Closed(); });
cls_BRepCheck_Wire.def("Closed", (BRepCheck_Status (BRepCheck_Wire::*)(const Standard_Boolean)) &BRepCheck_Wire::Closed, "Checks if the oriented edges of the wire give a closed wire. If the wire is closed, returns BRepCheck_NoError. Warning : if the first and last edge are infinite, the wire will be considered as a closed one. If <Update> is set to Standard_True, registers the status in the list. May return (and registers): **BRepCheck_NotConnected, if wire is not topologically closed **BRepCheck_RedundantEdge, if an edge is in wire more than 3 times or in case of 2 occurences if not with FORWARD and REVERSED orientation. **BRepCheck_NoError", py::arg("Update"));
cls_BRepCheck_Wire.def("Closed2d", [](BRepCheck_Wire &self, const TopoDS_Face & a0) -> BRepCheck_Status { return self.Closed2d(a0); });
cls_BRepCheck_Wire.def("Closed2d", (BRepCheck_Status (BRepCheck_Wire::*)(const TopoDS_Face &, const Standard_Boolean)) &BRepCheck_Wire::Closed2d, "Checks if edges of the wire give a wire closed in 2d space. Returns BRepCheck_NoError, or BRepCheck_NotClosed If <Update> is set to Standard_True, registers the status in the list.", py::arg("F"), py::arg("Update"));
cls_BRepCheck_Wire.def("Orientation", [](BRepCheck_Wire &self, const TopoDS_Face & a0) -> BRepCheck_Status { return self.Orientation(a0); });
cls_BRepCheck_Wire.def("Orientation", (BRepCheck_Status (BRepCheck_Wire::*)(const TopoDS_Face &, const Standard_Boolean)) &BRepCheck_Wire::Orientation, "Checks if the oriented edges of the wire are correctly oriented. An internal call is made to the method Closed. If no face exists, call the method with a null face (TopoDS_face()). If <Update> is set to Standard_True, registers the status in the list. May return (and registers): BRepCheck_InvalidDegeneratedFlag, BRepCheck_BadOrientationOfSubshape, BRepCheck_NotClosed, BRepCheck_NoError", py::arg("F"), py::arg("Update"));
cls_BRepCheck_Wire.def("SelfIntersect", [](BRepCheck_Wire &self, const TopoDS_Face & a0, TopoDS_Edge & a1, TopoDS_Edge & a2) -> BRepCheck_Status { return self.SelfIntersect(a0, a1, a2); });
cls_BRepCheck_Wire.def("SelfIntersect", (BRepCheck_Status (BRepCheck_Wire::*)(const TopoDS_Face &, TopoDS_Edge &, TopoDS_Edge &, const Standard_Boolean)) &BRepCheck_Wire::SelfIntersect, "Checks if the wire intersect itself on the face <F>. <E1> and <E2> are the first intersecting edges found. <E2> may be a null edge when a self-intersecting edge is found.If <Update> is set to Standard_True, registers the status in the list. May return (and register): BRepCheck_EmptyWire, BRepCheck_SelfIntersectingWire, BRepCheck_NoCurveOnSurface, BRepCheck_NoError", py::arg("F"), py::arg("E1"), py::arg("E2"), py::arg("Update"));
cls_BRepCheck_Wire.def("GeometricControls", (Standard_Boolean (BRepCheck_Wire::*)() const) &BRepCheck_Wire::GeometricControls, "report SelfIntersect() check would be (is) done");
cls_BRepCheck_Wire.def("GeometricControls", (void (BRepCheck_Wire::*)(const Standard_Boolean)) &BRepCheck_Wire::GeometricControls, "set SelfIntersect() to be checked", py::arg("B"));
cls_BRepCheck_Wire.def("SetStatus", (void (BRepCheck_Wire::*)(const BRepCheck_Status)) &BRepCheck_Wire::SetStatus, "Sets status of Wire;", py::arg("theStatus"));
cls_BRepCheck_Wire.def_static("get_type_name_", (const char * (*)()) &BRepCheck_Wire::get_type_name, "None");
cls_BRepCheck_Wire.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepCheck_Wire::get_type_descriptor, "None");
cls_BRepCheck_Wire.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepCheck_Wire::*)() const) &BRepCheck_Wire::DynamicType, "None");


}
