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
#include <LocOpe_Operation.hxx>
#include <Standard.hxx>
#include <TopoDS_Shape.hxx>
#include <TopoDS_Face.hxx>
#include <TopoDS_Edge.hxx>
#include <Standard_TypeDef.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TopAbs_Orientation.hxx>
#include <TopTools_IndexedDataMapOfShapeShape.hxx>
#include <TopTools_DataMapOfShapeShape.hxx>
#include <TopTools_DataMapOfShapeListOfShape.hxx>
#include <LocOpe_Gluer.hxx>
#include <Standard_Handle.hxx>
#include <LocOpe_WiresOnShape.hxx>
#include <LocOpe_Spliter.hxx>
#include <Standard_Transient.hxx>
#include <TopTools_SequenceOfShape.hxx>
#include <TopoDS_Wire.hxx>
#include <TopoDS_Compound.hxx>
#include <TopoDS_Vertex.hxx>
#include <Standard_Std.hxx>
#include <Standard_Type.hxx>
#include <TopTools_MapOfShape.hxx>
#include <TColgp_SequenceOfPnt.hxx>
#include <LocOpe_SplitShape.hxx>
#include <LocOpe_Generator.hxx>
#include <LocOpe_GeneratedShape.hxx>
#include <LocOpe_GluedShape.hxx>
#include <LocOpe_Prism.hxx>
#include <LocOpe_Revol.hxx>
#include <LocOpe_Pipe.hxx>
#include <LocOpe_DPrism.hxx>
#include <LocOpe_LinearForm.hxx>
#include <LocOpe_RevolutionForm.hxx>
#include <LocOpe_FindEdges.hxx>
#include <LocOpe_FindEdgesInFace.hxx>
#include <LocOpe_PntFace.hxx>
#include <LocOpe_CurveShapeIntersector.hxx>
#include <LocOpe_CSIntersector.hxx>
#include <LocOpe_BuildShape.hxx>
#include <LocOpe_SplitDrafts.hxx>
#include <LocOpe_BuildWires.hxx>
#include <LocOpe.hxx>
#include <NCollection_Sequence.hxx>
#include <gp_Lin.hxx>
#include <LocOpe_SequenceOfLin.hxx>
#include <gp_Circ.hxx>
#include <LocOpe_SequenceOfCirc.hxx>
#include <TColGeom_SequenceOfCurve.hxx>
#include <gp_Pnt.hxx>
#include <LocOpe_SequenceOfPntFace.hxx>
#include <gp_Ax1.hxx>
#include <NCollection_DataMap.hxx>
#include <TopTools_ShapeMapHasher.hxx>
#include <LocOpe_DataMapOfShapePnt.hxx>
#include <Geom_Curve.hxx>
#include <BRepFill_Evolved.hxx>
#include <gp_Vec.hxx>
#include <BRepFill_Pipe.hxx>
#include <gp_Dir.hxx>
#include <gp_Pln.hxx>
#include <bind_NCollection_Sequence.hxx>
#include <bind_NCollection_DataMap.hxx>

PYBIND11_MODULE(LocOpe, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.TopTools");
py::module::import("OCCT.TopAbs");
py::module::import("OCCT.TColgp");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.gp");
py::module::import("OCCT.TColGeom");
py::module::import("OCCT.Geom");
py::module::import("OCCT.BRepFill");

// ENUM: LOCOPE_OPERATION
py::enum_<LocOpe_Operation>(mod, "LocOpe_Operation", "None")
	.value("LocOpe_FUSE", LocOpe_Operation::LocOpe_FUSE)
	.value("LocOpe_CUT", LocOpe_Operation::LocOpe_CUT)
	.value("LocOpe_INVALID", LocOpe_Operation::LocOpe_INVALID)
	.export_values();


// CLASS: LOCOPE_GLUER
py::class_<LocOpe_Gluer> cls_LocOpe_Gluer(mod, "LocOpe_Gluer", "None");

// Constructors
cls_LocOpe_Gluer.def(py::init<>());
cls_LocOpe_Gluer.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &>(), py::arg("Sbase"), py::arg("Snew"));

// Methods
// cls_LocOpe_Gluer.def_static("operator new_", (void * (*)(size_t)) &LocOpe_Gluer::operator new, "None", py::arg("theSize"));
// cls_LocOpe_Gluer.def_static("operator delete_", (void (*)(void *)) &LocOpe_Gluer::operator delete, "None", py::arg("theAddress"));
// cls_LocOpe_Gluer.def_static("operator new[]_", (void * (*)(size_t)) &LocOpe_Gluer::operator new[], "None", py::arg("theSize"));
// cls_LocOpe_Gluer.def_static("operator delete[]_", (void (*)(void *)) &LocOpe_Gluer::operator delete[], "None", py::arg("theAddress"));
// cls_LocOpe_Gluer.def_static("operator new_", (void * (*)(size_t, void *)) &LocOpe_Gluer::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_LocOpe_Gluer.def_static("operator delete_", (void (*)(void *, void *)) &LocOpe_Gluer::operator delete, "None", py::arg(""), py::arg(""));
cls_LocOpe_Gluer.def("Init", (void (LocOpe_Gluer::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &LocOpe_Gluer::Init, "None", py::arg("Sbase"), py::arg("Snew"));
cls_LocOpe_Gluer.def("Bind", (void (LocOpe_Gluer::*)(const TopoDS_Face &, const TopoDS_Face &)) &LocOpe_Gluer::Bind, "None", py::arg("Fnew"), py::arg("Fbase"));
cls_LocOpe_Gluer.def("Bind", (void (LocOpe_Gluer::*)(const TopoDS_Edge &, const TopoDS_Edge &)) &LocOpe_Gluer::Bind, "None", py::arg("Enew"), py::arg("Ebase"));
cls_LocOpe_Gluer.def("OpeType", (LocOpe_Operation (LocOpe_Gluer::*)() const) &LocOpe_Gluer::OpeType, "None");
cls_LocOpe_Gluer.def("Perform", (void (LocOpe_Gluer::*)()) &LocOpe_Gluer::Perform, "None");
cls_LocOpe_Gluer.def("IsDone", (Standard_Boolean (LocOpe_Gluer::*)() const) &LocOpe_Gluer::IsDone, "None");
cls_LocOpe_Gluer.def("ResultingShape", (const TopoDS_Shape & (LocOpe_Gluer::*)() const) &LocOpe_Gluer::ResultingShape, "None");
cls_LocOpe_Gluer.def("DescendantFaces", (const TopTools_ListOfShape & (LocOpe_Gluer::*)(const TopoDS_Face &) const) &LocOpe_Gluer::DescendantFaces, "None", py::arg("F"));
cls_LocOpe_Gluer.def("BasisShape", (const TopoDS_Shape & (LocOpe_Gluer::*)() const) &LocOpe_Gluer::BasisShape, "None");
cls_LocOpe_Gluer.def("GluedShape", (const TopoDS_Shape & (LocOpe_Gluer::*)() const) &LocOpe_Gluer::GluedShape, "None");
cls_LocOpe_Gluer.def("Edges", (const TopTools_ListOfShape & (LocOpe_Gluer::*)() const) &LocOpe_Gluer::Edges, "None");
cls_LocOpe_Gluer.def("TgtEdges", (const TopTools_ListOfShape & (LocOpe_Gluer::*)() const) &LocOpe_Gluer::TgtEdges, "None");

// CLASS: LOCOPE_SPLITER
py::class_<LocOpe_Spliter> cls_LocOpe_Spliter(mod, "LocOpe_Spliter", "None");

// Constructors
cls_LocOpe_Spliter.def(py::init<>());
cls_LocOpe_Spliter.def(py::init<const TopoDS_Shape &>(), py::arg("S"));

// Methods
// cls_LocOpe_Spliter.def_static("operator new_", (void * (*)(size_t)) &LocOpe_Spliter::operator new, "None", py::arg("theSize"));
// cls_LocOpe_Spliter.def_static("operator delete_", (void (*)(void *)) &LocOpe_Spliter::operator delete, "None", py::arg("theAddress"));
// cls_LocOpe_Spliter.def_static("operator new[]_", (void * (*)(size_t)) &LocOpe_Spliter::operator new[], "None", py::arg("theSize"));
// cls_LocOpe_Spliter.def_static("operator delete[]_", (void (*)(void *)) &LocOpe_Spliter::operator delete[], "None", py::arg("theAddress"));
// cls_LocOpe_Spliter.def_static("operator new_", (void * (*)(size_t, void *)) &LocOpe_Spliter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_LocOpe_Spliter.def_static("operator delete_", (void (*)(void *, void *)) &LocOpe_Spliter::operator delete, "None", py::arg(""), py::arg(""));
cls_LocOpe_Spliter.def("Init", (void (LocOpe_Spliter::*)(const TopoDS_Shape &)) &LocOpe_Spliter::Init, "Initializes the algorithm on the shape <S>.", py::arg("S"));
cls_LocOpe_Spliter.def("Perform", (void (LocOpe_Spliter::*)(const opencascade::handle<LocOpe_WiresOnShape> &)) &LocOpe_Spliter::Perform, "None", py::arg("PW"));
cls_LocOpe_Spliter.def("IsDone", (Standard_Boolean (LocOpe_Spliter::*)() const) &LocOpe_Spliter::IsDone, "None");
cls_LocOpe_Spliter.def("ResultingShape", (const TopoDS_Shape & (LocOpe_Spliter::*)() const) &LocOpe_Spliter::ResultingShape, "Returns the new shape");
cls_LocOpe_Spliter.def("Shape", (const TopoDS_Shape & (LocOpe_Spliter::*)() const) &LocOpe_Spliter::Shape, "Returns the initial shape");
cls_LocOpe_Spliter.def("DirectLeft", (const TopTools_ListOfShape & (LocOpe_Spliter::*)() const) &LocOpe_Spliter::DirectLeft, "Returns the faces which are the left of the projected wires and which are");
cls_LocOpe_Spliter.def("Left", (const TopTools_ListOfShape & (LocOpe_Spliter::*)() const) &LocOpe_Spliter::Left, "Returns the faces of the 'left' part on the shape. (It is build from DirectLeft, with the faces connected to this set, and so on...).");
cls_LocOpe_Spliter.def("DescendantShapes", (const TopTools_ListOfShape & (LocOpe_Spliter::*)(const TopoDS_Shape &)) &LocOpe_Spliter::DescendantShapes, "Returns the list of descendant shapes of <S>.", py::arg("S"));

// CLASS: LOCOPE_WIRESONSHAPE
py::class_<LocOpe_WiresOnShape, opencascade::handle<LocOpe_WiresOnShape>, Standard_Transient> cls_LocOpe_WiresOnShape(mod, "LocOpe_WiresOnShape", "None");

// Constructors
cls_LocOpe_WiresOnShape.def(py::init<const TopoDS_Shape &>(), py::arg("S"));

// Methods
cls_LocOpe_WiresOnShape.def("Init", (void (LocOpe_WiresOnShape::*)(const TopoDS_Shape &)) &LocOpe_WiresOnShape::Init, "None", py::arg("S"));
cls_LocOpe_WiresOnShape.def("Add", (Standard_Boolean (LocOpe_WiresOnShape::*)(const TopTools_SequenceOfShape &)) &LocOpe_WiresOnShape::Add, "Add splitting edges or wires for whole initial shape withot additional specification edge->face, edge->edge This method puts edge on the corresponding faces from initial shape", py::arg("theEdges"));
cls_LocOpe_WiresOnShape.def("SetCheckInterior", (void (LocOpe_WiresOnShape::*)(const Standard_Boolean)) &LocOpe_WiresOnShape::SetCheckInterior, "Set the flag of check internal intersections default value is True (to check)", py::arg("ToCheckInterior"));
cls_LocOpe_WiresOnShape.def("Bind", (void (LocOpe_WiresOnShape::*)(const TopoDS_Wire &, const TopoDS_Face &)) &LocOpe_WiresOnShape::Bind, "None", py::arg("W"), py::arg("F"));
cls_LocOpe_WiresOnShape.def("Bind", (void (LocOpe_WiresOnShape::*)(const TopoDS_Compound &, const TopoDS_Face &)) &LocOpe_WiresOnShape::Bind, "None", py::arg("Comp"), py::arg("F"));
cls_LocOpe_WiresOnShape.def("Bind", (void (LocOpe_WiresOnShape::*)(const TopoDS_Edge &, const TopoDS_Face &)) &LocOpe_WiresOnShape::Bind, "None", py::arg("E"), py::arg("F"));
cls_LocOpe_WiresOnShape.def("Bind", (void (LocOpe_WiresOnShape::*)(const TopoDS_Edge &, const TopoDS_Edge &)) &LocOpe_WiresOnShape::Bind, "None", py::arg("EfromW"), py::arg("EonFace"));
cls_LocOpe_WiresOnShape.def("BindAll", (void (LocOpe_WiresOnShape::*)()) &LocOpe_WiresOnShape::BindAll, "None");
cls_LocOpe_WiresOnShape.def("IsDone", (Standard_Boolean (LocOpe_WiresOnShape::*)() const) &LocOpe_WiresOnShape::IsDone, "None");
cls_LocOpe_WiresOnShape.def("InitEdgeIterator", (void (LocOpe_WiresOnShape::*)()) &LocOpe_WiresOnShape::InitEdgeIterator, "None");
cls_LocOpe_WiresOnShape.def("MoreEdge", (Standard_Boolean (LocOpe_WiresOnShape::*)()) &LocOpe_WiresOnShape::MoreEdge, "None");
cls_LocOpe_WiresOnShape.def("Edge", (TopoDS_Edge (LocOpe_WiresOnShape::*)()) &LocOpe_WiresOnShape::Edge, "None");
cls_LocOpe_WiresOnShape.def("OnFace", (TopoDS_Face (LocOpe_WiresOnShape::*)()) &LocOpe_WiresOnShape::OnFace, "Returns the face of the shape on which the current edge is projected.");
cls_LocOpe_WiresOnShape.def("OnEdge", (Standard_Boolean (LocOpe_WiresOnShape::*)(TopoDS_Edge &)) &LocOpe_WiresOnShape::OnEdge, "If the current edge is projected on an edge, returns <Standard_True> and sets the value of <E>. Otherwise, returns <Standard_False>.", py::arg("E"));
cls_LocOpe_WiresOnShape.def("NextEdge", (void (LocOpe_WiresOnShape::*)()) &LocOpe_WiresOnShape::NextEdge, "None");
cls_LocOpe_WiresOnShape.def("OnVertex", (Standard_Boolean (LocOpe_WiresOnShape::*)(const TopoDS_Vertex &, TopoDS_Vertex &)) &LocOpe_WiresOnShape::OnVertex, "None", py::arg("Vwire"), py::arg("Vshape"));
cls_LocOpe_WiresOnShape.def("OnEdge", [](LocOpe_WiresOnShape &self, const TopoDS_Vertex & V, TopoDS_Edge & E, Standard_Real & P){ Standard_Boolean rv = self.OnEdge(V, E, P); return std::tuple<Standard_Boolean, Standard_Real &>(rv, P); }, "If the vertex <V> lies on an edge of the original shape, returns <Standard_True> and sets the concerned edge in <E>, and the parameter on the edge in <P>. Else returns <Standard_False>.", py::arg("V"), py::arg("E"), py::arg("P"));
cls_LocOpe_WiresOnShape.def("OnEdge", [](LocOpe_WiresOnShape &self, const TopoDS_Vertex & V, const TopoDS_Edge & EdgeFrom, TopoDS_Edge & E, Standard_Real & P){ Standard_Boolean rv = self.OnEdge(V, EdgeFrom, E, P); return std::tuple<Standard_Boolean, Standard_Real &>(rv, P); }, "If the vertex <V> lies on an edge of the original shape, returns <Standard_True> and sets the concerned edge in <E>, and the parameter on the edge in <P>. Else returns <Standard_False>.", py::arg("V"), py::arg("EdgeFrom"), py::arg("E"), py::arg("P"));
cls_LocOpe_WiresOnShape.def("IsFaceWithSection", (Standard_Boolean (LocOpe_WiresOnShape::*)(const TopoDS_Shape &) const) &LocOpe_WiresOnShape::IsFaceWithSection, "tells is the face to be split by section or not", py::arg("aFace"));
cls_LocOpe_WiresOnShape.def_static("get_type_name_", (const char * (*)()) &LocOpe_WiresOnShape::get_type_name, "None");
cls_LocOpe_WiresOnShape.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &LocOpe_WiresOnShape::get_type_descriptor, "None");
cls_LocOpe_WiresOnShape.def("DynamicType", (const opencascade::handle<Standard_Type> & (LocOpe_WiresOnShape::*)() const) &LocOpe_WiresOnShape::DynamicType, "None");

// CLASS: LOCOPE
py::class_<LocOpe> cls_LocOpe(mod, "LocOpe", "Provides tools to implement local topological operations on a shape.");

// Constructors
cls_LocOpe.def(py::init<>());

// Methods
// cls_LocOpe.def_static("operator new_", (void * (*)(size_t)) &LocOpe::operator new, "None", py::arg("theSize"));
// cls_LocOpe.def_static("operator delete_", (void (*)(void *)) &LocOpe::operator delete, "None", py::arg("theAddress"));
// cls_LocOpe.def_static("operator new[]_", (void * (*)(size_t)) &LocOpe::operator new[], "None", py::arg("theSize"));
// cls_LocOpe.def_static("operator delete[]_", (void (*)(void *)) &LocOpe::operator delete[], "None", py::arg("theAddress"));
// cls_LocOpe.def_static("operator new_", (void * (*)(size_t, void *)) &LocOpe::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_LocOpe.def_static("operator delete_", (void (*)(void *, void *)) &LocOpe::operator delete, "None", py::arg(""), py::arg(""));
cls_LocOpe.def_static("Closed_", (Standard_Boolean (*)(const TopoDS_Wire &, const TopoDS_Face &)) &LocOpe::Closed, "Returns Standard_True when the wire <W> is closed on the face <OnF>.", py::arg("W"), py::arg("OnF"));
cls_LocOpe.def_static("Closed_", (Standard_Boolean (*)(const TopoDS_Edge &, const TopoDS_Face &)) &LocOpe::Closed, "Returns Standard_True when the edge <E> is closed on the face <OnF>.", py::arg("E"), py::arg("OnF"));
cls_LocOpe.def_static("TgtFaces_", (Standard_Boolean (*)(const TopoDS_Edge &, const TopoDS_Face &, const TopoDS_Face &)) &LocOpe::TgtFaces, "Returns Standard_True when the faces are tangent", py::arg("E"), py::arg("F1"), py::arg("F2"));
cls_LocOpe.def_static("SampleEdges_", (void (*)(const TopoDS_Shape &, TColgp_SequenceOfPnt &)) &LocOpe::SampleEdges, "None", py::arg("S"), py::arg("Pt"));

// CLASS: LOCOPE_BUILDSHAPE
py::class_<LocOpe_BuildShape> cls_LocOpe_BuildShape(mod, "LocOpe_BuildShape", "None");

// Constructors
cls_LocOpe_BuildShape.def(py::init<>());
cls_LocOpe_BuildShape.def(py::init<const TopTools_ListOfShape &>(), py::arg("L"));

// Methods
// cls_LocOpe_BuildShape.def_static("operator new_", (void * (*)(size_t)) &LocOpe_BuildShape::operator new, "None", py::arg("theSize"));
// cls_LocOpe_BuildShape.def_static("operator delete_", (void (*)(void *)) &LocOpe_BuildShape::operator delete, "None", py::arg("theAddress"));
// cls_LocOpe_BuildShape.def_static("operator new[]_", (void * (*)(size_t)) &LocOpe_BuildShape::operator new[], "None", py::arg("theSize"));
// cls_LocOpe_BuildShape.def_static("operator delete[]_", (void (*)(void *)) &LocOpe_BuildShape::operator delete[], "None", py::arg("theAddress"));
// cls_LocOpe_BuildShape.def_static("operator new_", (void * (*)(size_t, void *)) &LocOpe_BuildShape::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_LocOpe_BuildShape.def_static("operator delete_", (void (*)(void *, void *)) &LocOpe_BuildShape::operator delete, "None", py::arg(""), py::arg(""));
cls_LocOpe_BuildShape.def("Perform", (void (LocOpe_BuildShape::*)(const TopTools_ListOfShape &)) &LocOpe_BuildShape::Perform, "Builds shape(s) from the list <L>. Uses only the faces of <L>.", py::arg("L"));
cls_LocOpe_BuildShape.def("Shape", (const TopoDS_Shape & (LocOpe_BuildShape::*)() const) &LocOpe_BuildShape::Shape, "None");

// CLASS: LOCOPE_BUILDWIRES
py::class_<LocOpe_BuildWires> cls_LocOpe_BuildWires(mod, "LocOpe_BuildWires", "None");

// Constructors
cls_LocOpe_BuildWires.def(py::init<>());
cls_LocOpe_BuildWires.def(py::init<const TopTools_ListOfShape &, const opencascade::handle<LocOpe_WiresOnShape> &>(), py::arg("Ledges"), py::arg("PW"));

// Methods
// cls_LocOpe_BuildWires.def_static("operator new_", (void * (*)(size_t)) &LocOpe_BuildWires::operator new, "None", py::arg("theSize"));
// cls_LocOpe_BuildWires.def_static("operator delete_", (void (*)(void *)) &LocOpe_BuildWires::operator delete, "None", py::arg("theAddress"));
// cls_LocOpe_BuildWires.def_static("operator new[]_", (void * (*)(size_t)) &LocOpe_BuildWires::operator new[], "None", py::arg("theSize"));
// cls_LocOpe_BuildWires.def_static("operator delete[]_", (void (*)(void *)) &LocOpe_BuildWires::operator delete[], "None", py::arg("theAddress"));
// cls_LocOpe_BuildWires.def_static("operator new_", (void * (*)(size_t, void *)) &LocOpe_BuildWires::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_LocOpe_BuildWires.def_static("operator delete_", (void (*)(void *, void *)) &LocOpe_BuildWires::operator delete, "None", py::arg(""), py::arg(""));
cls_LocOpe_BuildWires.def("Perform", (void (LocOpe_BuildWires::*)(const TopTools_ListOfShape &, const opencascade::handle<LocOpe_WiresOnShape> &)) &LocOpe_BuildWires::Perform, "None", py::arg("Ledges"), py::arg("PW"));
cls_LocOpe_BuildWires.def("IsDone", (Standard_Boolean (LocOpe_BuildWires::*)() const) &LocOpe_BuildWires::IsDone, "None");
cls_LocOpe_BuildWires.def("Result", (const TopTools_ListOfShape & (LocOpe_BuildWires::*)() const) &LocOpe_BuildWires::Result, "None");

// TYPEDEF: LOCOPE_SEQUENCEOFLIN
bind_NCollection_Sequence<gp_Lin>(mod, "LocOpe_SequenceOfLin", py::module_local(false));

// TYPEDEF: LOCOPE_SEQUENCEOFCIRC
bind_NCollection_Sequence<gp_Circ>(mod, "LocOpe_SequenceOfCirc", py::module_local(false));

// CLASS: LOCOPE_CSINTERSECTOR
py::class_<LocOpe_CSIntersector> cls_LocOpe_CSIntersector(mod, "LocOpe_CSIntersector", "This class provides the intersection between a set of axis or a circle and the faces of a shape. The intersection points are sorted in increasing parameter along each axis or circle.");

// Constructors
cls_LocOpe_CSIntersector.def(py::init<>());
cls_LocOpe_CSIntersector.def(py::init<const TopoDS_Shape &>(), py::arg("S"));

// Methods
// cls_LocOpe_CSIntersector.def_static("operator new_", (void * (*)(size_t)) &LocOpe_CSIntersector::operator new, "None", py::arg("theSize"));
// cls_LocOpe_CSIntersector.def_static("operator delete_", (void (*)(void *)) &LocOpe_CSIntersector::operator delete, "None", py::arg("theAddress"));
// cls_LocOpe_CSIntersector.def_static("operator new[]_", (void * (*)(size_t)) &LocOpe_CSIntersector::operator new[], "None", py::arg("theSize"));
// cls_LocOpe_CSIntersector.def_static("operator delete[]_", (void (*)(void *)) &LocOpe_CSIntersector::operator delete[], "None", py::arg("theAddress"));
// cls_LocOpe_CSIntersector.def_static("operator new_", (void * (*)(size_t, void *)) &LocOpe_CSIntersector::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_LocOpe_CSIntersector.def_static("operator delete_", (void (*)(void *, void *)) &LocOpe_CSIntersector::operator delete, "None", py::arg(""), py::arg(""));
cls_LocOpe_CSIntersector.def("Init", (void (LocOpe_CSIntersector::*)(const TopoDS_Shape &)) &LocOpe_CSIntersector::Init, "Performs the intersection between <Ax1 and <S>.", py::arg("S"));
cls_LocOpe_CSIntersector.def("Perform", (void (LocOpe_CSIntersector::*)(const LocOpe_SequenceOfLin &)) &LocOpe_CSIntersector::Perform, "None", py::arg("Slin"));
cls_LocOpe_CSIntersector.def("Perform", (void (LocOpe_CSIntersector::*)(const LocOpe_SequenceOfCirc &)) &LocOpe_CSIntersector::Perform, "None", py::arg("Scir"));
cls_LocOpe_CSIntersector.def("Perform", (void (LocOpe_CSIntersector::*)(const TColGeom_SequenceOfCurve &)) &LocOpe_CSIntersector::Perform, "None", py::arg("Scur"));
cls_LocOpe_CSIntersector.def("IsDone", (Standard_Boolean (LocOpe_CSIntersector::*)() const) &LocOpe_CSIntersector::IsDone, "Returns <Standard_True> if the intersection has been done.");
cls_LocOpe_CSIntersector.def("NbPoints", (Standard_Integer (LocOpe_CSIntersector::*)(const Standard_Integer) const) &LocOpe_CSIntersector::NbPoints, "Returns the number of intersection point on the element of range <I>.", py::arg("I"));
cls_LocOpe_CSIntersector.def("Point", (const LocOpe_PntFace & (LocOpe_CSIntersector::*)(const Standard_Integer, const Standard_Integer) const) &LocOpe_CSIntersector::Point, "Returns the intersection point of range <Index> on element of range <I>. The points are sorted in increasing order of parameter along the axis.", py::arg("I"), py::arg("Index"));
cls_LocOpe_CSIntersector.def("LocalizeAfter", [](LocOpe_CSIntersector &self, const Standard_Integer I, const Standard_Real From, const Standard_Real Tol, TopAbs_Orientation & Or, Standard_Integer & IndFrom, Standard_Integer & IndTo){ Standard_Boolean rv = self.LocalizeAfter(I, From, Tol, Or, IndFrom, IndTo); return std::tuple<Standard_Boolean, Standard_Integer &, Standard_Integer &>(rv, IndFrom, IndTo); }, "On the element of range <I>, searches the first intersection point located after the parameter <From>, wich orientation is not TopAbs_EXTERNAL. If found, returns <Standard_True>. <Or> contains the orientation of the point, <IndFrom> and <IndTo> represents the interval of index in the sequence of intersection point corresponding to the point. (IndFrom <= IndTo). <Tol> is used to determine if 2 parameters are equal.", py::arg("I"), py::arg("From"), py::arg("Tol"), py::arg("Or"), py::arg("IndFrom"), py::arg("IndTo"));
cls_LocOpe_CSIntersector.def("LocalizeBefore", [](LocOpe_CSIntersector &self, const Standard_Integer I, const Standard_Real From, const Standard_Real Tol, TopAbs_Orientation & Or, Standard_Integer & IndFrom, Standard_Integer & IndTo){ Standard_Boolean rv = self.LocalizeBefore(I, From, Tol, Or, IndFrom, IndTo); return std::tuple<Standard_Boolean, Standard_Integer &, Standard_Integer &>(rv, IndFrom, IndTo); }, "On the element of range <I>, searches the first intersection point located before the parameter <From>, wich orientation is not TopAbs_EXTERNAL. If found, returns <Standard_True>. <Or> contains the orientation of the point, <IndFrom> and <IndTo> represents the interval of index in the sequence of intersection point corresponding to the point (IndFrom <= IndTo). <Tol> is used to determine if 2 parameters are equal.", py::arg("I"), py::arg("From"), py::arg("Tol"), py::arg("Or"), py::arg("IndFrom"), py::arg("IndTo"));
cls_LocOpe_CSIntersector.def("LocalizeAfter", [](LocOpe_CSIntersector &self, const Standard_Integer I, const Standard_Integer FromInd, const Standard_Real Tol, TopAbs_Orientation & Or, Standard_Integer & IndFrom, Standard_Integer & IndTo){ Standard_Boolean rv = self.LocalizeAfter(I, FromInd, Tol, Or, IndFrom, IndTo); return std::tuple<Standard_Boolean, Standard_Integer &, Standard_Integer &>(rv, IndFrom, IndTo); }, "On the element of range <I>, searches the first intersection point located after the index <FromInd> ( >= FromInd + 1), wich orientation is not TopAbs_EXTERNAL. If found, returns <Standard_True>. <Or> contains the orientation of the point, <IndFrom> and <IndTo> represents the interval of index in the sequence of intersection point corresponding to the point. (IndFrom <= IndTo). <Tol> is used to determine if 2 parameters are equal.", py::arg("I"), py::arg("FromInd"), py::arg("Tol"), py::arg("Or"), py::arg("IndFrom"), py::arg("IndTo"));
cls_LocOpe_CSIntersector.def("LocalizeBefore", [](LocOpe_CSIntersector &self, const Standard_Integer I, const Standard_Integer FromInd, const Standard_Real Tol, TopAbs_Orientation & Or, Standard_Integer & IndFrom, Standard_Integer & IndTo){ Standard_Boolean rv = self.LocalizeBefore(I, FromInd, Tol, Or, IndFrom, IndTo); return std::tuple<Standard_Boolean, Standard_Integer &, Standard_Integer &>(rv, IndFrom, IndTo); }, "On the element of range <I>, searches the first intersection point located before the index <FromInd> ( <= FromInd -1), wich orientation is not TopAbs_EXTERNAL. If found, returns <Standard_True>. <Or> contains the orientation of the point, <IndFrom> and <IndTo> represents the interval of index in the sequence of intersection point corresponding to the point (IndFrom <= IndTo). <Tol> is used to determine if 2 parameters are equal.", py::arg("I"), py::arg("FromInd"), py::arg("Tol"), py::arg("Or"), py::arg("IndFrom"), py::arg("IndTo"));
cls_LocOpe_CSIntersector.def("Destroy", (void (LocOpe_CSIntersector::*)()) &LocOpe_CSIntersector::Destroy, "None");

// CLASS: LOCOPE_PNTFACE
py::class_<LocOpe_PntFace> cls_LocOpe_PntFace(mod, "LocOpe_PntFace", "None");

// Constructors
cls_LocOpe_PntFace.def(py::init<>());
cls_LocOpe_PntFace.def(py::init<const gp_Pnt &, const TopoDS_Face &, const TopAbs_Orientation, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("F"), py::arg("Or"), py::arg("Param"), py::arg("UPar"), py::arg("VPar"));

// Methods
// cls_LocOpe_PntFace.def_static("operator new_", (void * (*)(size_t)) &LocOpe_PntFace::operator new, "None", py::arg("theSize"));
// cls_LocOpe_PntFace.def_static("operator delete_", (void (*)(void *)) &LocOpe_PntFace::operator delete, "None", py::arg("theAddress"));
// cls_LocOpe_PntFace.def_static("operator new[]_", (void * (*)(size_t)) &LocOpe_PntFace::operator new[], "None", py::arg("theSize"));
// cls_LocOpe_PntFace.def_static("operator delete[]_", (void (*)(void *)) &LocOpe_PntFace::operator delete[], "None", py::arg("theAddress"));
// cls_LocOpe_PntFace.def_static("operator new_", (void * (*)(size_t, void *)) &LocOpe_PntFace::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_LocOpe_PntFace.def_static("operator delete_", (void (*)(void *, void *)) &LocOpe_PntFace::operator delete, "None", py::arg(""), py::arg(""));
cls_LocOpe_PntFace.def("Pnt", (const gp_Pnt & (LocOpe_PntFace::*)() const) &LocOpe_PntFace::Pnt, "None");
cls_LocOpe_PntFace.def("Face", (const TopoDS_Face & (LocOpe_PntFace::*)() const) &LocOpe_PntFace::Face, "None");
cls_LocOpe_PntFace.def("Orientation", (TopAbs_Orientation (LocOpe_PntFace::*)() const) &LocOpe_PntFace::Orientation, "None");
cls_LocOpe_PntFace.def("ChangeOrientation", (TopAbs_Orientation & (LocOpe_PntFace::*)()) &LocOpe_PntFace::ChangeOrientation, "None");
cls_LocOpe_PntFace.def("Parameter", (Standard_Real (LocOpe_PntFace::*)() const) &LocOpe_PntFace::Parameter, "None");
cls_LocOpe_PntFace.def("UParameter", (Standard_Real (LocOpe_PntFace::*)() const) &LocOpe_PntFace::UParameter, "None");
cls_LocOpe_PntFace.def("VParameter", (Standard_Real (LocOpe_PntFace::*)() const) &LocOpe_PntFace::VParameter, "None");

// TYPEDEF: LOCOPE_SEQUENCEOFPNTFACE
bind_NCollection_Sequence<LocOpe_PntFace>(mod, "LocOpe_SequenceOfPntFace", py::module_local(false));

// CLASS: LOCOPE_CURVESHAPEINTERSECTOR
py::class_<LocOpe_CurveShapeIntersector> cls_LocOpe_CurveShapeIntersector(mod, "LocOpe_CurveShapeIntersector", "This class provides the intersection between an axis or a circle and the faces of a shape. The intersection points are sorted in increasing parameter along the axis.");

// Constructors
cls_LocOpe_CurveShapeIntersector.def(py::init<>());
cls_LocOpe_CurveShapeIntersector.def(py::init<const gp_Ax1 &, const TopoDS_Shape &>(), py::arg("Axis"), py::arg("S"));
cls_LocOpe_CurveShapeIntersector.def(py::init<const gp_Circ &, const TopoDS_Shape &>(), py::arg("C"), py::arg("S"));

// Methods
// cls_LocOpe_CurveShapeIntersector.def_static("operator new_", (void * (*)(size_t)) &LocOpe_CurveShapeIntersector::operator new, "None", py::arg("theSize"));
// cls_LocOpe_CurveShapeIntersector.def_static("operator delete_", (void (*)(void *)) &LocOpe_CurveShapeIntersector::operator delete, "None", py::arg("theAddress"));
// cls_LocOpe_CurveShapeIntersector.def_static("operator new[]_", (void * (*)(size_t)) &LocOpe_CurveShapeIntersector::operator new[], "None", py::arg("theSize"));
// cls_LocOpe_CurveShapeIntersector.def_static("operator delete[]_", (void (*)(void *)) &LocOpe_CurveShapeIntersector::operator delete[], "None", py::arg("theAddress"));
// cls_LocOpe_CurveShapeIntersector.def_static("operator new_", (void * (*)(size_t, void *)) &LocOpe_CurveShapeIntersector::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_LocOpe_CurveShapeIntersector.def_static("operator delete_", (void (*)(void *, void *)) &LocOpe_CurveShapeIntersector::operator delete, "None", py::arg(""), py::arg(""));
cls_LocOpe_CurveShapeIntersector.def("Init", (void (LocOpe_CurveShapeIntersector::*)(const gp_Ax1 &, const TopoDS_Shape &)) &LocOpe_CurveShapeIntersector::Init, "Performs the intersection between <Ax1 and <S>.", py::arg("Axis"), py::arg("S"));
cls_LocOpe_CurveShapeIntersector.def("Init", (void (LocOpe_CurveShapeIntersector::*)(const gp_Circ &, const TopoDS_Shape &)) &LocOpe_CurveShapeIntersector::Init, "Performs the intersection between <Ax1 and <S>.", py::arg("C"), py::arg("S"));
cls_LocOpe_CurveShapeIntersector.def("IsDone", (Standard_Boolean (LocOpe_CurveShapeIntersector::*)() const) &LocOpe_CurveShapeIntersector::IsDone, "Returns <Standard_True> if the intersection has been done.");
cls_LocOpe_CurveShapeIntersector.def("NbPoints", (Standard_Integer (LocOpe_CurveShapeIntersector::*)() const) &LocOpe_CurveShapeIntersector::NbPoints, "Returns the number of intersection point.");
cls_LocOpe_CurveShapeIntersector.def("Point", (const LocOpe_PntFace & (LocOpe_CurveShapeIntersector::*)(const Standard_Integer) const) &LocOpe_CurveShapeIntersector::Point, "Returns the intersection point of range <Index>. The points are sorted in increasing order of parameter along the axis.", py::arg("Index"));
cls_LocOpe_CurveShapeIntersector.def("LocalizeAfter", [](LocOpe_CurveShapeIntersector &self, const Standard_Real From, TopAbs_Orientation & Or, Standard_Integer & IndFrom, Standard_Integer & IndTo){ Standard_Boolean rv = self.LocalizeAfter(From, Or, IndFrom, IndTo); return std::tuple<Standard_Boolean, Standard_Integer &, Standard_Integer &>(rv, IndFrom, IndTo); }, "Searches the first intersection point located after the parameter <From>, wich orientation is not TopAbs_EXTERNAL. If found, returns <Standard_True>. <Or> contains the orientation of the point, <IndFrom> and <IndTo> represents the interval of index in the sequence of intersection point corresponding to the point. (IndFrom <= IndTo).", py::arg("From"), py::arg("Or"), py::arg("IndFrom"), py::arg("IndTo"));
cls_LocOpe_CurveShapeIntersector.def("LocalizeBefore", [](LocOpe_CurveShapeIntersector &self, const Standard_Real From, TopAbs_Orientation & Or, Standard_Integer & IndFrom, Standard_Integer & IndTo){ Standard_Boolean rv = self.LocalizeBefore(From, Or, IndFrom, IndTo); return std::tuple<Standard_Boolean, Standard_Integer &, Standard_Integer &>(rv, IndFrom, IndTo); }, "Searches the first intersection point located before the parameter <From>, wich orientation is not TopAbs_EXTERNAL. If found, returns <Standard_True>. <Or> contains the orientation of the point, <IndFrom> and <IndTo> represents the interval of index in the sequence of intersection point corresponding to the point (IndFrom <= IndTo).", py::arg("From"), py::arg("Or"), py::arg("IndFrom"), py::arg("IndTo"));
cls_LocOpe_CurveShapeIntersector.def("LocalizeAfter", [](LocOpe_CurveShapeIntersector &self, const Standard_Integer FromInd, TopAbs_Orientation & Or, Standard_Integer & IndFrom, Standard_Integer & IndTo){ Standard_Boolean rv = self.LocalizeAfter(FromInd, Or, IndFrom, IndTo); return std::tuple<Standard_Boolean, Standard_Integer &, Standard_Integer &>(rv, IndFrom, IndTo); }, "Searches the first intersection point located after the index <FromInd> ( >= FromInd + 1), wich orientation is not TopAbs_EXTERNAL. If found, returns <Standard_True>. <Or> contains the orientation of the point, <IndFrom> and <IndTo> represents the interval of index in the sequence of intersection point corresponding to the point. (IndFrom <= IndTo).", py::arg("FromInd"), py::arg("Or"), py::arg("IndFrom"), py::arg("IndTo"));
cls_LocOpe_CurveShapeIntersector.def("LocalizeBefore", [](LocOpe_CurveShapeIntersector &self, const Standard_Integer FromInd, TopAbs_Orientation & Or, Standard_Integer & IndFrom, Standard_Integer & IndTo){ Standard_Boolean rv = self.LocalizeBefore(FromInd, Or, IndFrom, IndTo); return std::tuple<Standard_Boolean, Standard_Integer &, Standard_Integer &>(rv, IndFrom, IndTo); }, "Searches the first intersection point located before the index <FromInd> ( <= FromInd -1), wich orientation is not TopAbs_EXTERNAL. If found, returns <Standard_True>. <Or> contains the orientation of the point, <IndFrom> and <IndTo> represents the interval of index in the sequence of intersection point corresponding to the point (IndFrom <= IndTo).", py::arg("FromInd"), py::arg("Or"), py::arg("IndFrom"), py::arg("IndTo"));

// TYPEDEF: LOCOPE_DATAMAPOFSHAPEPNT
bind_NCollection_DataMap<TopoDS_Shape, gp_Pnt, TopTools_ShapeMapHasher>(mod, "LocOpe_DataMapOfShapePnt", py::module_local(false));

// TYPEDEF: LOCOPE_DATAMAPITERATOROFDATAMAPOFSHAPEPNT

// CLASS: LOCOPE_DPRISM
py::class_<LocOpe_DPrism> cls_LocOpe_DPrism(mod, "LocOpe_DPrism", "Defines a pipe (near from Pipe from BRepFill), with modifications provided for the Pipe feature.");

// Constructors
cls_LocOpe_DPrism.def(py::init<const TopoDS_Face &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Spine"), py::arg("Height1"), py::arg("Height2"), py::arg("Angle"));
cls_LocOpe_DPrism.def(py::init<const TopoDS_Face &, const Standard_Real, const Standard_Real>(), py::arg("Spine"), py::arg("Height"), py::arg("Angle"));

// Methods
// cls_LocOpe_DPrism.def_static("operator new_", (void * (*)(size_t)) &LocOpe_DPrism::operator new, "None", py::arg("theSize"));
// cls_LocOpe_DPrism.def_static("operator delete_", (void (*)(void *)) &LocOpe_DPrism::operator delete, "None", py::arg("theAddress"));
// cls_LocOpe_DPrism.def_static("operator new[]_", (void * (*)(size_t)) &LocOpe_DPrism::operator new[], "None", py::arg("theSize"));
// cls_LocOpe_DPrism.def_static("operator delete[]_", (void (*)(void *)) &LocOpe_DPrism::operator delete[], "None", py::arg("theAddress"));
// cls_LocOpe_DPrism.def_static("operator new_", (void * (*)(size_t, void *)) &LocOpe_DPrism::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_LocOpe_DPrism.def_static("operator delete_", (void (*)(void *, void *)) &LocOpe_DPrism::operator delete, "None", py::arg(""), py::arg(""));
cls_LocOpe_DPrism.def("IsDone", (Standard_Boolean (LocOpe_DPrism::*)() const) &LocOpe_DPrism::IsDone, "None");
cls_LocOpe_DPrism.def("Spine", (const TopoDS_Shape & (LocOpe_DPrism::*)() const) &LocOpe_DPrism::Spine, "None");
cls_LocOpe_DPrism.def("Profile", (const TopoDS_Shape & (LocOpe_DPrism::*)() const) &LocOpe_DPrism::Profile, "None");
cls_LocOpe_DPrism.def("FirstShape", (const TopoDS_Shape & (LocOpe_DPrism::*)() const) &LocOpe_DPrism::FirstShape, "None");
cls_LocOpe_DPrism.def("LastShape", (const TopoDS_Shape & (LocOpe_DPrism::*)() const) &LocOpe_DPrism::LastShape, "None");
cls_LocOpe_DPrism.def("Shape", (const TopoDS_Shape & (LocOpe_DPrism::*)() const) &LocOpe_DPrism::Shape, "None");
cls_LocOpe_DPrism.def("Shapes", (const TopTools_ListOfShape & (LocOpe_DPrism::*)(const TopoDS_Shape &) const) &LocOpe_DPrism::Shapes, "None", py::arg("S"));
cls_LocOpe_DPrism.def("Curves", (void (LocOpe_DPrism::*)(TColGeom_SequenceOfCurve &) const) &LocOpe_DPrism::Curves, "None", py::arg("SCurves"));
cls_LocOpe_DPrism.def("BarycCurve", (opencascade::handle<Geom_Curve> (LocOpe_DPrism::*)() const) &LocOpe_DPrism::BarycCurve, "None");

// CLASS: LOCOPE_FINDEDGES
py::class_<LocOpe_FindEdges> cls_LocOpe_FindEdges(mod, "LocOpe_FindEdges", "None");

// Constructors
cls_LocOpe_FindEdges.def(py::init<>());
cls_LocOpe_FindEdges.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &>(), py::arg("FFrom"), py::arg("FTo"));

// Methods
// cls_LocOpe_FindEdges.def_static("operator new_", (void * (*)(size_t)) &LocOpe_FindEdges::operator new, "None", py::arg("theSize"));
// cls_LocOpe_FindEdges.def_static("operator delete_", (void (*)(void *)) &LocOpe_FindEdges::operator delete, "None", py::arg("theAddress"));
// cls_LocOpe_FindEdges.def_static("operator new[]_", (void * (*)(size_t)) &LocOpe_FindEdges::operator new[], "None", py::arg("theSize"));
// cls_LocOpe_FindEdges.def_static("operator delete[]_", (void (*)(void *)) &LocOpe_FindEdges::operator delete[], "None", py::arg("theAddress"));
// cls_LocOpe_FindEdges.def_static("operator new_", (void * (*)(size_t, void *)) &LocOpe_FindEdges::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_LocOpe_FindEdges.def_static("operator delete_", (void (*)(void *, void *)) &LocOpe_FindEdges::operator delete, "None", py::arg(""), py::arg(""));
cls_LocOpe_FindEdges.def("Set", (void (LocOpe_FindEdges::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &LocOpe_FindEdges::Set, "None", py::arg("FFrom"), py::arg("FTo"));
cls_LocOpe_FindEdges.def("InitIterator", (void (LocOpe_FindEdges::*)()) &LocOpe_FindEdges::InitIterator, "None");
cls_LocOpe_FindEdges.def("More", (Standard_Boolean (LocOpe_FindEdges::*)() const) &LocOpe_FindEdges::More, "None");
cls_LocOpe_FindEdges.def("EdgeFrom", (const TopoDS_Edge & (LocOpe_FindEdges::*)() const) &LocOpe_FindEdges::EdgeFrom, "None");
cls_LocOpe_FindEdges.def("EdgeTo", (const TopoDS_Edge & (LocOpe_FindEdges::*)() const) &LocOpe_FindEdges::EdgeTo, "None");
cls_LocOpe_FindEdges.def("Next", (void (LocOpe_FindEdges::*)()) &LocOpe_FindEdges::Next, "None");

// CLASS: LOCOPE_FINDEDGESINFACE
py::class_<LocOpe_FindEdgesInFace> cls_LocOpe_FindEdgesInFace(mod, "LocOpe_FindEdgesInFace", "None");

// Constructors
cls_LocOpe_FindEdgesInFace.def(py::init<>());
cls_LocOpe_FindEdgesInFace.def(py::init<const TopoDS_Shape &, const TopoDS_Face &>(), py::arg("S"), py::arg("F"));

// Methods
// cls_LocOpe_FindEdgesInFace.def_static("operator new_", (void * (*)(size_t)) &LocOpe_FindEdgesInFace::operator new, "None", py::arg("theSize"));
// cls_LocOpe_FindEdgesInFace.def_static("operator delete_", (void (*)(void *)) &LocOpe_FindEdgesInFace::operator delete, "None", py::arg("theAddress"));
// cls_LocOpe_FindEdgesInFace.def_static("operator new[]_", (void * (*)(size_t)) &LocOpe_FindEdgesInFace::operator new[], "None", py::arg("theSize"));
// cls_LocOpe_FindEdgesInFace.def_static("operator delete[]_", (void (*)(void *)) &LocOpe_FindEdgesInFace::operator delete[], "None", py::arg("theAddress"));
// cls_LocOpe_FindEdgesInFace.def_static("operator new_", (void * (*)(size_t, void *)) &LocOpe_FindEdgesInFace::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_LocOpe_FindEdgesInFace.def_static("operator delete_", (void (*)(void *, void *)) &LocOpe_FindEdgesInFace::operator delete, "None", py::arg(""), py::arg(""));
cls_LocOpe_FindEdgesInFace.def("Set", (void (LocOpe_FindEdgesInFace::*)(const TopoDS_Shape &, const TopoDS_Face &)) &LocOpe_FindEdgesInFace::Set, "None", py::arg("S"), py::arg("F"));
cls_LocOpe_FindEdgesInFace.def("Init", (void (LocOpe_FindEdgesInFace::*)()) &LocOpe_FindEdgesInFace::Init, "None");
cls_LocOpe_FindEdgesInFace.def("More", (Standard_Boolean (LocOpe_FindEdgesInFace::*)() const) &LocOpe_FindEdgesInFace::More, "None");
cls_LocOpe_FindEdgesInFace.def("Edge", (const TopoDS_Edge & (LocOpe_FindEdgesInFace::*)() const) &LocOpe_FindEdgesInFace::Edge, "None");
cls_LocOpe_FindEdgesInFace.def("Next", (void (LocOpe_FindEdgesInFace::*)()) &LocOpe_FindEdgesInFace::Next, "None");

// CLASS: LOCOPE_GENERATEDSHAPE
py::class_<LocOpe_GeneratedShape, opencascade::handle<LocOpe_GeneratedShape>, Standard_Transient> cls_LocOpe_GeneratedShape(mod, "LocOpe_GeneratedShape", "None");

// Methods
cls_LocOpe_GeneratedShape.def("GeneratingEdges", (const TopTools_ListOfShape & (LocOpe_GeneratedShape::*)()) &LocOpe_GeneratedShape::GeneratingEdges, "None");
cls_LocOpe_GeneratedShape.def("Generated", (TopoDS_Edge (LocOpe_GeneratedShape::*)(const TopoDS_Vertex &)) &LocOpe_GeneratedShape::Generated, "Returns the edge created by the vertex <V>. If none, must return a null shape.", py::arg("V"));
cls_LocOpe_GeneratedShape.def("Generated", (TopoDS_Face (LocOpe_GeneratedShape::*)(const TopoDS_Edge &)) &LocOpe_GeneratedShape::Generated, "Returns the face created by the edge <E>. If none, must return a null shape.", py::arg("E"));
cls_LocOpe_GeneratedShape.def("OrientedFaces", (const TopTools_ListOfShape & (LocOpe_GeneratedShape::*)()) &LocOpe_GeneratedShape::OrientedFaces, "Returns the list of correctly oriented generated faces.");
cls_LocOpe_GeneratedShape.def_static("get_type_name_", (const char * (*)()) &LocOpe_GeneratedShape::get_type_name, "None");
cls_LocOpe_GeneratedShape.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &LocOpe_GeneratedShape::get_type_descriptor, "None");
cls_LocOpe_GeneratedShape.def("DynamicType", (const opencascade::handle<Standard_Type> & (LocOpe_GeneratedShape::*)() const) &LocOpe_GeneratedShape::DynamicType, "None");

// CLASS: LOCOPE_GENERATOR
py::class_<LocOpe_Generator> cls_LocOpe_Generator(mod, "LocOpe_Generator", "None");

// Constructors
cls_LocOpe_Generator.def(py::init<>());
cls_LocOpe_Generator.def(py::init<const TopoDS_Shape &>(), py::arg("S"));

// Methods
// cls_LocOpe_Generator.def_static("operator new_", (void * (*)(size_t)) &LocOpe_Generator::operator new, "None", py::arg("theSize"));
// cls_LocOpe_Generator.def_static("operator delete_", (void (*)(void *)) &LocOpe_Generator::operator delete, "None", py::arg("theAddress"));
// cls_LocOpe_Generator.def_static("operator new[]_", (void * (*)(size_t)) &LocOpe_Generator::operator new[], "None", py::arg("theSize"));
// cls_LocOpe_Generator.def_static("operator delete[]_", (void (*)(void *)) &LocOpe_Generator::operator delete[], "None", py::arg("theAddress"));
// cls_LocOpe_Generator.def_static("operator new_", (void * (*)(size_t, void *)) &LocOpe_Generator::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_LocOpe_Generator.def_static("operator delete_", (void (*)(void *, void *)) &LocOpe_Generator::operator delete, "None", py::arg(""), py::arg(""));
cls_LocOpe_Generator.def("Init", (void (LocOpe_Generator::*)(const TopoDS_Shape &)) &LocOpe_Generator::Init, "Initializes the algorithm on the shape <S>.", py::arg("S"));
cls_LocOpe_Generator.def("Perform", (void (LocOpe_Generator::*)(const opencascade::handle<LocOpe_GeneratedShape> &)) &LocOpe_Generator::Perform, "None", py::arg("G"));
cls_LocOpe_Generator.def("IsDone", (Standard_Boolean (LocOpe_Generator::*)() const) &LocOpe_Generator::IsDone, "None");
cls_LocOpe_Generator.def("ResultingShape", (const TopoDS_Shape & (LocOpe_Generator::*)() const) &LocOpe_Generator::ResultingShape, "Returns the new shape");
cls_LocOpe_Generator.def("Shape", (const TopoDS_Shape & (LocOpe_Generator::*)() const) &LocOpe_Generator::Shape, "Returns the initial shape");
cls_LocOpe_Generator.def("DescendantFace", (const TopTools_ListOfShape & (LocOpe_Generator::*)(const TopoDS_Face &)) &LocOpe_Generator::DescendantFace, "Returns the descendant face of <F>. <F> may belong to the original shape or to the 'generated' shape. The returned face may be a null shape (when <F> disappears).", py::arg("F"));

// CLASS: LOCOPE_GLUEDSHAPE
py::class_<LocOpe_GluedShape, opencascade::handle<LocOpe_GluedShape>, LocOpe_GeneratedShape> cls_LocOpe_GluedShape(mod, "LocOpe_GluedShape", "None");

// Constructors
cls_LocOpe_GluedShape.def(py::init<>());
cls_LocOpe_GluedShape.def(py::init<const TopoDS_Shape &>(), py::arg("S"));

// Methods
cls_LocOpe_GluedShape.def("Init", (void (LocOpe_GluedShape::*)(const TopoDS_Shape &)) &LocOpe_GluedShape::Init, "None", py::arg("S"));
cls_LocOpe_GluedShape.def("GlueOnFace", (void (LocOpe_GluedShape::*)(const TopoDS_Face &)) &LocOpe_GluedShape::GlueOnFace, "None", py::arg("F"));
cls_LocOpe_GluedShape.def("GeneratingEdges", (const TopTools_ListOfShape & (LocOpe_GluedShape::*)()) &LocOpe_GluedShape::GeneratingEdges, "None");
cls_LocOpe_GluedShape.def("Generated", (TopoDS_Edge (LocOpe_GluedShape::*)(const TopoDS_Vertex &)) &LocOpe_GluedShape::Generated, "Returns the edge created by the vertex <V>. If none, must return a null shape.", py::arg("V"));
cls_LocOpe_GluedShape.def("Generated", (TopoDS_Face (LocOpe_GluedShape::*)(const TopoDS_Edge &)) &LocOpe_GluedShape::Generated, "Returns the face created by the edge <E>. If none, must return a null shape.", py::arg("E"));
cls_LocOpe_GluedShape.def("OrientedFaces", (const TopTools_ListOfShape & (LocOpe_GluedShape::*)()) &LocOpe_GluedShape::OrientedFaces, "Returns the list of correctly oriented generated faces.");
cls_LocOpe_GluedShape.def_static("get_type_name_", (const char * (*)()) &LocOpe_GluedShape::get_type_name, "None");
cls_LocOpe_GluedShape.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &LocOpe_GluedShape::get_type_descriptor, "None");
cls_LocOpe_GluedShape.def("DynamicType", (const opencascade::handle<Standard_Type> & (LocOpe_GluedShape::*)() const) &LocOpe_GluedShape::DynamicType, "None");

// CLASS: LOCOPE_LINEARFORM
py::class_<LocOpe_LinearForm> cls_LocOpe_LinearForm(mod, "LocOpe_LinearForm", "Defines a linear form (using Prism from BRepSweep) with modifications provided for the LinearForm feature.");

// Constructors
cls_LocOpe_LinearForm.def(py::init<>());
cls_LocOpe_LinearForm.def(py::init<const TopoDS_Shape &, const gp_Vec &, const gp_Pnt &, const gp_Pnt &>(), py::arg("Base"), py::arg("V"), py::arg("Pnt1"), py::arg("Pnt2"));
cls_LocOpe_LinearForm.def(py::init<const TopoDS_Shape &, const gp_Vec &, const gp_Vec &, const gp_Pnt &, const gp_Pnt &>(), py::arg("Base"), py::arg("V"), py::arg("Vectra"), py::arg("Pnt1"), py::arg("Pnt2"));

// Methods
// cls_LocOpe_LinearForm.def_static("operator new_", (void * (*)(size_t)) &LocOpe_LinearForm::operator new, "None", py::arg("theSize"));
// cls_LocOpe_LinearForm.def_static("operator delete_", (void (*)(void *)) &LocOpe_LinearForm::operator delete, "None", py::arg("theAddress"));
// cls_LocOpe_LinearForm.def_static("operator new[]_", (void * (*)(size_t)) &LocOpe_LinearForm::operator new[], "None", py::arg("theSize"));
// cls_LocOpe_LinearForm.def_static("operator delete[]_", (void (*)(void *)) &LocOpe_LinearForm::operator delete[], "None", py::arg("theAddress"));
// cls_LocOpe_LinearForm.def_static("operator new_", (void * (*)(size_t, void *)) &LocOpe_LinearForm::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_LocOpe_LinearForm.def_static("operator delete_", (void (*)(void *, void *)) &LocOpe_LinearForm::operator delete, "None", py::arg(""), py::arg(""));
cls_LocOpe_LinearForm.def("Perform", (void (LocOpe_LinearForm::*)(const TopoDS_Shape &, const gp_Vec &, const gp_Pnt &, const gp_Pnt &)) &LocOpe_LinearForm::Perform, "None", py::arg("Base"), py::arg("V"), py::arg("Pnt1"), py::arg("Pnt2"));
cls_LocOpe_LinearForm.def("Perform", (void (LocOpe_LinearForm::*)(const TopoDS_Shape &, const gp_Vec &, const gp_Vec &, const gp_Pnt &, const gp_Pnt &)) &LocOpe_LinearForm::Perform, "None", py::arg("Base"), py::arg("V"), py::arg("Vectra"), py::arg("Pnt1"), py::arg("Pnt2"));
cls_LocOpe_LinearForm.def("FirstShape", (const TopoDS_Shape & (LocOpe_LinearForm::*)() const) &LocOpe_LinearForm::FirstShape, "None");
cls_LocOpe_LinearForm.def("LastShape", (const TopoDS_Shape & (LocOpe_LinearForm::*)() const) &LocOpe_LinearForm::LastShape, "None");
cls_LocOpe_LinearForm.def("Shape", (const TopoDS_Shape & (LocOpe_LinearForm::*)() const) &LocOpe_LinearForm::Shape, "None");
cls_LocOpe_LinearForm.def("Shapes", (const TopTools_ListOfShape & (LocOpe_LinearForm::*)(const TopoDS_Shape &) const) &LocOpe_LinearForm::Shapes, "None", py::arg("S"));

// CLASS: LOCOPE_PIPE
py::class_<LocOpe_Pipe> cls_LocOpe_Pipe(mod, "LocOpe_Pipe", "Defines a pipe (near from Pipe from BRepFill), with modifications provided for the Pipe feature.");

// Constructors
cls_LocOpe_Pipe.def(py::init<const TopoDS_Wire &, const TopoDS_Shape &>(), py::arg("Spine"), py::arg("Profile"));

// Methods
// cls_LocOpe_Pipe.def_static("operator new_", (void * (*)(size_t)) &LocOpe_Pipe::operator new, "None", py::arg("theSize"));
// cls_LocOpe_Pipe.def_static("operator delete_", (void (*)(void *)) &LocOpe_Pipe::operator delete, "None", py::arg("theAddress"));
// cls_LocOpe_Pipe.def_static("operator new[]_", (void * (*)(size_t)) &LocOpe_Pipe::operator new[], "None", py::arg("theSize"));
// cls_LocOpe_Pipe.def_static("operator delete[]_", (void (*)(void *)) &LocOpe_Pipe::operator delete[], "None", py::arg("theAddress"));
// cls_LocOpe_Pipe.def_static("operator new_", (void * (*)(size_t, void *)) &LocOpe_Pipe::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_LocOpe_Pipe.def_static("operator delete_", (void (*)(void *, void *)) &LocOpe_Pipe::operator delete, "None", py::arg(""), py::arg(""));
cls_LocOpe_Pipe.def("Spine", (const TopoDS_Shape & (LocOpe_Pipe::*)() const) &LocOpe_Pipe::Spine, "None");
cls_LocOpe_Pipe.def("Profile", (const TopoDS_Shape & (LocOpe_Pipe::*)() const) &LocOpe_Pipe::Profile, "None");
cls_LocOpe_Pipe.def("FirstShape", (const TopoDS_Shape & (LocOpe_Pipe::*)() const) &LocOpe_Pipe::FirstShape, "None");
cls_LocOpe_Pipe.def("LastShape", (const TopoDS_Shape & (LocOpe_Pipe::*)() const) &LocOpe_Pipe::LastShape, "None");
cls_LocOpe_Pipe.def("Shape", (const TopoDS_Shape & (LocOpe_Pipe::*)() const) &LocOpe_Pipe::Shape, "None");
cls_LocOpe_Pipe.def("Shapes", (const TopTools_ListOfShape & (LocOpe_Pipe::*)(const TopoDS_Shape &)) &LocOpe_Pipe::Shapes, "None", py::arg("S"));
cls_LocOpe_Pipe.def("Curves", (const TColGeom_SequenceOfCurve & (LocOpe_Pipe::*)(const TColgp_SequenceOfPnt &)) &LocOpe_Pipe::Curves, "None", py::arg("Spt"));
cls_LocOpe_Pipe.def("BarycCurve", (opencascade::handle<Geom_Curve> (LocOpe_Pipe::*)()) &LocOpe_Pipe::BarycCurve, "None");

// CLASS: LOCOPE_PRISM
py::class_<LocOpe_Prism> cls_LocOpe_Prism(mod, "LocOpe_Prism", "Defines a prism (using Prism from BRepSweep) with modifications provided for the Prism feature.");

// Constructors
cls_LocOpe_Prism.def(py::init<>());
cls_LocOpe_Prism.def(py::init<const TopoDS_Shape &, const gp_Vec &>(), py::arg("Base"), py::arg("V"));
cls_LocOpe_Prism.def(py::init<const TopoDS_Shape &, const gp_Vec &, const gp_Vec &>(), py::arg("Base"), py::arg("V"), py::arg("Vectra"));

// Methods
// cls_LocOpe_Prism.def_static("operator new_", (void * (*)(size_t)) &LocOpe_Prism::operator new, "None", py::arg("theSize"));
// cls_LocOpe_Prism.def_static("operator delete_", (void (*)(void *)) &LocOpe_Prism::operator delete, "None", py::arg("theAddress"));
// cls_LocOpe_Prism.def_static("operator new[]_", (void * (*)(size_t)) &LocOpe_Prism::operator new[], "None", py::arg("theSize"));
// cls_LocOpe_Prism.def_static("operator delete[]_", (void (*)(void *)) &LocOpe_Prism::operator delete[], "None", py::arg("theAddress"));
// cls_LocOpe_Prism.def_static("operator new_", (void * (*)(size_t, void *)) &LocOpe_Prism::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_LocOpe_Prism.def_static("operator delete_", (void (*)(void *, void *)) &LocOpe_Prism::operator delete, "None", py::arg(""), py::arg(""));
cls_LocOpe_Prism.def("Perform", (void (LocOpe_Prism::*)(const TopoDS_Shape &, const gp_Vec &)) &LocOpe_Prism::Perform, "None", py::arg("Base"), py::arg("V"));
cls_LocOpe_Prism.def("Perform", (void (LocOpe_Prism::*)(const TopoDS_Shape &, const gp_Vec &, const gp_Vec &)) &LocOpe_Prism::Perform, "None", py::arg("Base"), py::arg("V"), py::arg("Vtra"));
cls_LocOpe_Prism.def("FirstShape", (const TopoDS_Shape & (LocOpe_Prism::*)() const) &LocOpe_Prism::FirstShape, "None");
cls_LocOpe_Prism.def("LastShape", (const TopoDS_Shape & (LocOpe_Prism::*)() const) &LocOpe_Prism::LastShape, "None");
cls_LocOpe_Prism.def("Shape", (const TopoDS_Shape & (LocOpe_Prism::*)() const) &LocOpe_Prism::Shape, "None");
cls_LocOpe_Prism.def("Shapes", (const TopTools_ListOfShape & (LocOpe_Prism::*)(const TopoDS_Shape &) const) &LocOpe_Prism::Shapes, "None", py::arg("S"));
cls_LocOpe_Prism.def("Curves", (void (LocOpe_Prism::*)(TColGeom_SequenceOfCurve &) const) &LocOpe_Prism::Curves, "None", py::arg("SCurves"));
cls_LocOpe_Prism.def("BarycCurve", (opencascade::handle<Geom_Curve> (LocOpe_Prism::*)() const) &LocOpe_Prism::BarycCurve, "None");

// CLASS: LOCOPE_REVOL
py::class_<LocOpe_Revol> cls_LocOpe_Revol(mod, "LocOpe_Revol", "Defines a prism (using Prism from BRepSweep) with modifications provided for the Prism feature.");

// Constructors
cls_LocOpe_Revol.def(py::init<>());
// cls_LocOpe_Revol.def(py::init<const TopoDS_Shape &, const gp_Ax1 &, const Standard_Real, const Standard_Real>(), py::arg("Base"), py::arg("Axis"), py::arg("Angle"), py::arg("angledec"));
// cls_LocOpe_Revol.def(py::init<const TopoDS_Shape &, const gp_Ax1 &, const Standard_Real>(), py::arg("Base"), py::arg("Axis"), py::arg("Angle"));

// Methods
// cls_LocOpe_Revol.def_static("operator new_", (void * (*)(size_t)) &LocOpe_Revol::operator new, "None", py::arg("theSize"));
// cls_LocOpe_Revol.def_static("operator delete_", (void (*)(void *)) &LocOpe_Revol::operator delete, "None", py::arg("theAddress"));
// cls_LocOpe_Revol.def_static("operator new[]_", (void * (*)(size_t)) &LocOpe_Revol::operator new[], "None", py::arg("theSize"));
// cls_LocOpe_Revol.def_static("operator delete[]_", (void (*)(void *)) &LocOpe_Revol::operator delete[], "None", py::arg("theAddress"));
// cls_LocOpe_Revol.def_static("operator new_", (void * (*)(size_t, void *)) &LocOpe_Revol::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_LocOpe_Revol.def_static("operator delete_", (void (*)(void *, void *)) &LocOpe_Revol::operator delete, "None", py::arg(""), py::arg(""));
cls_LocOpe_Revol.def("Perform", (void (LocOpe_Revol::*)(const TopoDS_Shape &, const gp_Ax1 &, const Standard_Real, const Standard_Real)) &LocOpe_Revol::Perform, "None", py::arg("Base"), py::arg("Axis"), py::arg("Angle"), py::arg("angledec"));
cls_LocOpe_Revol.def("Perform", (void (LocOpe_Revol::*)(const TopoDS_Shape &, const gp_Ax1 &, const Standard_Real)) &LocOpe_Revol::Perform, "None", py::arg("Base"), py::arg("Axis"), py::arg("Angle"));
cls_LocOpe_Revol.def("FirstShape", (const TopoDS_Shape & (LocOpe_Revol::*)() const) &LocOpe_Revol::FirstShape, "None");
cls_LocOpe_Revol.def("LastShape", (const TopoDS_Shape & (LocOpe_Revol::*)() const) &LocOpe_Revol::LastShape, "None");
cls_LocOpe_Revol.def("Shape", (const TopoDS_Shape & (LocOpe_Revol::*)() const) &LocOpe_Revol::Shape, "None");
cls_LocOpe_Revol.def("Shapes", (const TopTools_ListOfShape & (LocOpe_Revol::*)(const TopoDS_Shape &) const) &LocOpe_Revol::Shapes, "None", py::arg("S"));
cls_LocOpe_Revol.def("Curves", (void (LocOpe_Revol::*)(TColGeom_SequenceOfCurve &) const) &LocOpe_Revol::Curves, "None", py::arg("SCurves"));
cls_LocOpe_Revol.def("BarycCurve", (opencascade::handle<Geom_Curve> (LocOpe_Revol::*)() const) &LocOpe_Revol::BarycCurve, "None");

// CLASS: LOCOPE_REVOLUTIONFORM
py::class_<LocOpe_RevolutionForm> cls_LocOpe_RevolutionForm(mod, "LocOpe_RevolutionForm", "Defines a revolution form (using Revol from BRepSweep) with modifications provided for the RevolutionForm feature.");

// Constructors
cls_LocOpe_RevolutionForm.def(py::init<>());
// cls_LocOpe_RevolutionForm.def(py::init<const TopoDS_Shape &, const gp_Ax1 &, const Standard_Real>(), py::arg("Base"), py::arg("Axe"), py::arg("Angle"));

// Methods
// cls_LocOpe_RevolutionForm.def_static("operator new_", (void * (*)(size_t)) &LocOpe_RevolutionForm::operator new, "None", py::arg("theSize"));
// cls_LocOpe_RevolutionForm.def_static("operator delete_", (void (*)(void *)) &LocOpe_RevolutionForm::operator delete, "None", py::arg("theAddress"));
// cls_LocOpe_RevolutionForm.def_static("operator new[]_", (void * (*)(size_t)) &LocOpe_RevolutionForm::operator new[], "None", py::arg("theSize"));
// cls_LocOpe_RevolutionForm.def_static("operator delete[]_", (void (*)(void *)) &LocOpe_RevolutionForm::operator delete[], "None", py::arg("theAddress"));
// cls_LocOpe_RevolutionForm.def_static("operator new_", (void * (*)(size_t, void *)) &LocOpe_RevolutionForm::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_LocOpe_RevolutionForm.def_static("operator delete_", (void (*)(void *, void *)) &LocOpe_RevolutionForm::operator delete, "None", py::arg(""), py::arg(""));
cls_LocOpe_RevolutionForm.def("Perform", (void (LocOpe_RevolutionForm::*)(const TopoDS_Shape &, const gp_Ax1 &, const Standard_Real)) &LocOpe_RevolutionForm::Perform, "None", py::arg("Base"), py::arg("Axe"), py::arg("Angle"));
cls_LocOpe_RevolutionForm.def("FirstShape", (const TopoDS_Shape & (LocOpe_RevolutionForm::*)() const) &LocOpe_RevolutionForm::FirstShape, "None");
cls_LocOpe_RevolutionForm.def("LastShape", (const TopoDS_Shape & (LocOpe_RevolutionForm::*)() const) &LocOpe_RevolutionForm::LastShape, "None");
cls_LocOpe_RevolutionForm.def("Shape", (const TopoDS_Shape & (LocOpe_RevolutionForm::*)() const) &LocOpe_RevolutionForm::Shape, "None");
cls_LocOpe_RevolutionForm.def("Shapes", (const TopTools_ListOfShape & (LocOpe_RevolutionForm::*)(const TopoDS_Shape &) const) &LocOpe_RevolutionForm::Shapes, "None", py::arg("S"));

// CLASS: LOCOPE_SPLITDRAFTS
py::class_<LocOpe_SplitDrafts> cls_LocOpe_SplitDrafts(mod, "LocOpe_SplitDrafts", "This class provides a tool to realize the following operations on a shape : - split a face of the shape with a wire, - put draft angle on both side of the wire. For each side, the draft angle may be different.");

// Constructors
cls_LocOpe_SplitDrafts.def(py::init<>());
cls_LocOpe_SplitDrafts.def(py::init<const TopoDS_Shape &>(), py::arg("S"));

// Methods
// cls_LocOpe_SplitDrafts.def_static("operator new_", (void * (*)(size_t)) &LocOpe_SplitDrafts::operator new, "None", py::arg("theSize"));
// cls_LocOpe_SplitDrafts.def_static("operator delete_", (void (*)(void *)) &LocOpe_SplitDrafts::operator delete, "None", py::arg("theAddress"));
// cls_LocOpe_SplitDrafts.def_static("operator new[]_", (void * (*)(size_t)) &LocOpe_SplitDrafts::operator new[], "None", py::arg("theSize"));
// cls_LocOpe_SplitDrafts.def_static("operator delete[]_", (void (*)(void *)) &LocOpe_SplitDrafts::operator delete[], "None", py::arg("theAddress"));
// cls_LocOpe_SplitDrafts.def_static("operator new_", (void * (*)(size_t, void *)) &LocOpe_SplitDrafts::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_LocOpe_SplitDrafts.def_static("operator delete_", (void (*)(void *, void *)) &LocOpe_SplitDrafts::operator delete, "None", py::arg(""), py::arg(""));
cls_LocOpe_SplitDrafts.def("Init", (void (LocOpe_SplitDrafts::*)(const TopoDS_Shape &)) &LocOpe_SplitDrafts::Init, "Initializes the algoritm with the shape <S>.", py::arg("S"));
cls_LocOpe_SplitDrafts.def("Perform", [](LocOpe_SplitDrafts &self, const TopoDS_Face & a0, const TopoDS_Wire & a1, const gp_Dir & a2, const gp_Pln & a3, const Standard_Real a4, const gp_Dir & a5, const gp_Pln & a6, const Standard_Real a7) -> void { return self.Perform(a0, a1, a2, a3, a4, a5, a6, a7); });
cls_LocOpe_SplitDrafts.def("Perform", [](LocOpe_SplitDrafts &self, const TopoDS_Face & a0, const TopoDS_Wire & a1, const gp_Dir & a2, const gp_Pln & a3, const Standard_Real a4, const gp_Dir & a5, const gp_Pln & a6, const Standard_Real a7, const Standard_Boolean a8) -> void { return self.Perform(a0, a1, a2, a3, a4, a5, a6, a7, a8); });
cls_LocOpe_SplitDrafts.def("Perform", (void (LocOpe_SplitDrafts::*)(const TopoDS_Face &, const TopoDS_Wire &, const gp_Dir &, const gp_Pln &, const Standard_Real, const gp_Dir &, const gp_Pln &, const Standard_Real, const Standard_Boolean, const Standard_Boolean)) &LocOpe_SplitDrafts::Perform, "Splits the face <F> of the former given shape with the wire <W>. The wire is assumed to lie on the face. Puts a draft angle on both parts of the wire. <Extractg>, <Nplg>, <Angleg> define the arguments for the left part of the wire. <Extractd>, <Npld>, <Angled> define the arguments for the right part of the wire. The draft angle is measured with the direction <Extract>. <Npl> defines the neutral plane (points belonging to the neutral plane are not modified). <Angle> is the value of the draft angle. If <ModifyLeft> is set to <Standard_False>, no draft angle is applied to the left part of the wire. If <ModifyRight> is set to <Standard_False>,no draft angle is applied to the right part of the wire.", py::arg("F"), py::arg("W"), py::arg("Extractg"), py::arg("NPlg"), py::arg("Angleg"), py::arg("Extractd"), py::arg("NPld"), py::arg("Angled"), py::arg("ModifyLeft"), py::arg("ModifyRight"));
cls_LocOpe_SplitDrafts.def("Perform", (void (LocOpe_SplitDrafts::*)(const TopoDS_Face &, const TopoDS_Wire &, const gp_Dir &, const gp_Pln &, const Standard_Real)) &LocOpe_SplitDrafts::Perform, "Splits the face <F> of the former given shape with the wire <W>. The wire is assumed to lie on the face. Puts a draft angle on the left part of the wire. The draft angle is measured with the direction <Extract>. <Npl> defines the neutral plane (points belonging to the neutral plane are not modified). <Angle> is the value of the draft angle.", py::arg("F"), py::arg("W"), py::arg("Extract"), py::arg("NPl"), py::arg("Angle"));
cls_LocOpe_SplitDrafts.def("IsDone", (Standard_Boolean (LocOpe_SplitDrafts::*)() const) &LocOpe_SplitDrafts::IsDone, "Returns <Standard_True> if the modification has been succesfully performed.");
cls_LocOpe_SplitDrafts.def("OriginalShape", (const TopoDS_Shape & (LocOpe_SplitDrafts::*)() const) &LocOpe_SplitDrafts::OriginalShape, "None");
cls_LocOpe_SplitDrafts.def("Shape", (const TopoDS_Shape & (LocOpe_SplitDrafts::*)() const) &LocOpe_SplitDrafts::Shape, "Returns the modified shape.");
cls_LocOpe_SplitDrafts.def("ShapesFromShape", (const TopTools_ListOfShape & (LocOpe_SplitDrafts::*)(const TopoDS_Shape &) const) &LocOpe_SplitDrafts::ShapesFromShape, "Manages the descendant shapes.", py::arg("S"));

// CLASS: LOCOPE_SPLITSHAPE
py::class_<LocOpe_SplitShape> cls_LocOpe_SplitShape(mod, "LocOpe_SplitShape", "Provides a tool to cut : - edges with a vertices, - faces with wires, and rebuilds the shape containing the edges and the faces.");

// Constructors
cls_LocOpe_SplitShape.def(py::init<>());
cls_LocOpe_SplitShape.def(py::init<const TopoDS_Shape &>(), py::arg("S"));

// Methods
// cls_LocOpe_SplitShape.def_static("operator new_", (void * (*)(size_t)) &LocOpe_SplitShape::operator new, "None", py::arg("theSize"));
// cls_LocOpe_SplitShape.def_static("operator delete_", (void (*)(void *)) &LocOpe_SplitShape::operator delete, "None", py::arg("theAddress"));
// cls_LocOpe_SplitShape.def_static("operator new[]_", (void * (*)(size_t)) &LocOpe_SplitShape::operator new[], "None", py::arg("theSize"));
// cls_LocOpe_SplitShape.def_static("operator delete[]_", (void (*)(void *)) &LocOpe_SplitShape::operator delete[], "None", py::arg("theAddress"));
// cls_LocOpe_SplitShape.def_static("operator new_", (void * (*)(size_t, void *)) &LocOpe_SplitShape::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_LocOpe_SplitShape.def_static("operator delete_", (void (*)(void *, void *)) &LocOpe_SplitShape::operator delete, "None", py::arg(""), py::arg(""));
cls_LocOpe_SplitShape.def("Init", (void (LocOpe_SplitShape::*)(const TopoDS_Shape &)) &LocOpe_SplitShape::Init, "Initializes the process on the shape <S>.", py::arg("S"));
cls_LocOpe_SplitShape.def("CanSplit", (Standard_Boolean (LocOpe_SplitShape::*)(const TopoDS_Edge &) const) &LocOpe_SplitShape::CanSplit, "Tests if it is possible to split the edge <E>.", py::arg("E"));
cls_LocOpe_SplitShape.def("Add", (void (LocOpe_SplitShape::*)(const TopoDS_Vertex &, const Standard_Real, const TopoDS_Edge &)) &LocOpe_SplitShape::Add, "Adds the vertex <V> on the edge <E>, at parameter <P>.", py::arg("V"), py::arg("P"), py::arg("E"));
cls_LocOpe_SplitShape.def("Add", (Standard_Boolean (LocOpe_SplitShape::*)(const TopoDS_Wire &, const TopoDS_Face &)) &LocOpe_SplitShape::Add, "Adds the wire <W> on the face <F>.", py::arg("W"), py::arg("F"));
cls_LocOpe_SplitShape.def("Add", (Standard_Boolean (LocOpe_SplitShape::*)(const TopTools_ListOfShape &, const TopoDS_Face &)) &LocOpe_SplitShape::Add, "Adds the list of wires <Lwires> on the face <F>.", py::arg("Lwires"), py::arg("F"));
cls_LocOpe_SplitShape.def("Shape", (const TopoDS_Shape & (LocOpe_SplitShape::*)() const) &LocOpe_SplitShape::Shape, "Returns the 'original' shape.");
cls_LocOpe_SplitShape.def("DescendantShapes", (const TopTools_ListOfShape & (LocOpe_SplitShape::*)(const TopoDS_Shape &)) &LocOpe_SplitShape::DescendantShapes, "Returns the list of descendant shapes of <S>.", py::arg("S"));
cls_LocOpe_SplitShape.def("LeftOf", (const TopTools_ListOfShape & (LocOpe_SplitShape::*)(const TopoDS_Wire &, const TopoDS_Face &)) &LocOpe_SplitShape::LeftOf, "Returns the 'left' part defined by the wire <W> on the face <F>. The returned list of shape is in fact a list of faces. The face <F> is considered with its topological orientation in the original shape. <W> is considered with its orientation.", py::arg("W"), py::arg("F"));


}
