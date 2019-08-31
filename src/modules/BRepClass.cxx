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
#include <Standard.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Face.hxx>
#include <BRepClass_Edge.hxx>
#include <Geom2dInt_IntConicCurveOfGInter.hxx>
#include <gp_Lin2d.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Dir2d.hxx>
#include <BRepClass_Intersector.hxx>
#include <TopAbs_Orientation.hxx>
#include <TopAbs_State.hxx>
#include <TopTrans_CurveTransition.hxx>
#include <BRepClass_FClass2dOfFClassifier.hxx>
#include <BRepClass_FaceExplorer.hxx>
#include <gp_Pnt2d.hxx>
#include <IntRes2d_Position.hxx>
#include <BRepClass_FClassifier.hxx>
#include <TopExp_Explorer.hxx>
#include <gp_Pnt.hxx>
#include <BRepClass_FaceClassifier.hxx>
#include <BRepClass_FacePassiveClassifier.hxx>

PYBIND11_MODULE(BRepClass, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.Geom2dInt");
py::module::import("OCCT.gp");
py::module::import("OCCT.TopAbs");
py::module::import("OCCT.TopTrans");
py::module::import("OCCT.IntRes2d");
py::module::import("OCCT.TopExp");

// CLASS: BREPCLASS_EDGE
py::class_<BRepClass_Edge> cls_BRepClass_Edge(mod, "BRepClass_Edge", "This class is used to send the description of an Edge to the classifier. It contains an Edge and a Face. So the PCurve of the Edge can be found.");

// Constructors
cls_BRepClass_Edge.def(py::init<>());
cls_BRepClass_Edge.def(py::init<const TopoDS_Edge &, const TopoDS_Face &>(), py::arg("E"), py::arg("F"));

// Methods
// cls_BRepClass_Edge.def_static("operator new_", (void * (*)(size_t)) &BRepClass_Edge::operator new, "None", py::arg("theSize"));
// cls_BRepClass_Edge.def_static("operator delete_", (void (*)(void *)) &BRepClass_Edge::operator delete, "None", py::arg("theAddress"));
// cls_BRepClass_Edge.def_static("operator new[]_", (void * (*)(size_t)) &BRepClass_Edge::operator new[], "None", py::arg("theSize"));
// cls_BRepClass_Edge.def_static("operator delete[]_", (void (*)(void *)) &BRepClass_Edge::operator delete[], "None", py::arg("theAddress"));
// cls_BRepClass_Edge.def_static("operator new_", (void * (*)(size_t, void *)) &BRepClass_Edge::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepClass_Edge.def_static("operator delete_", (void (*)(void *, void *)) &BRepClass_Edge::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepClass_Edge.def("Edge", (TopoDS_Edge & (BRepClass_Edge::*)()) &BRepClass_Edge::Edge, "None");
cls_BRepClass_Edge.def("Edge", (const TopoDS_Edge & (BRepClass_Edge::*)() const) &BRepClass_Edge::Edge, "None");
cls_BRepClass_Edge.def("Face", (TopoDS_Face & (BRepClass_Edge::*)()) &BRepClass_Edge::Face, "None");
cls_BRepClass_Edge.def("Face", (const TopoDS_Face & (BRepClass_Edge::*)() const) &BRepClass_Edge::Face, "None");

// CLASS: BREPCLASS_INTERSECTOR
py::class_<BRepClass_Intersector, Geom2dInt_IntConicCurveOfGInter> cls_BRepClass_Intersector(mod, "BRepClass_Intersector", "Intersect an Edge with a segment. Implement the Intersector2d required by the classifier.");

// Constructors
cls_BRepClass_Intersector.def(py::init<>());

// Methods
// cls_BRepClass_Intersector.def_static("operator new_", (void * (*)(size_t)) &BRepClass_Intersector::operator new, "None", py::arg("theSize"));
// cls_BRepClass_Intersector.def_static("operator delete_", (void (*)(void *)) &BRepClass_Intersector::operator delete, "None", py::arg("theAddress"));
// cls_BRepClass_Intersector.def_static("operator new[]_", (void * (*)(size_t)) &BRepClass_Intersector::operator new[], "None", py::arg("theSize"));
// cls_BRepClass_Intersector.def_static("operator delete[]_", (void (*)(void *)) &BRepClass_Intersector::operator delete[], "None", py::arg("theAddress"));
// cls_BRepClass_Intersector.def_static("operator new_", (void * (*)(size_t, void *)) &BRepClass_Intersector::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepClass_Intersector.def_static("operator delete_", (void (*)(void *, void *)) &BRepClass_Intersector::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepClass_Intersector.def("Perform", (void (BRepClass_Intersector::*)(const gp_Lin2d &, const Standard_Real, const Standard_Real, const BRepClass_Edge &)) &BRepClass_Intersector::Perform, "Intersect the line segment and the edge.", py::arg("L"), py::arg("P"), py::arg("Tol"), py::arg("E"));
cls_BRepClass_Intersector.def("LocalGeometry", [](BRepClass_Intersector &self, const BRepClass_Edge & E, const Standard_Real U, gp_Dir2d & T, gp_Dir2d & N, Standard_Real & C){ self.LocalGeometry(E, U, T, N, C); return C; }, "Returns in <T>, <N> and <C> the tangent, normal and curvature of the edge <E> at parameter value <U>.", py::arg("E"), py::arg("U"), py::arg("T"), py::arg("N"), py::arg("C"));

// CLASS: BREPCLASS_FCLASS2DOFFCLASSIFIER
py::class_<BRepClass_FClass2dOfFClassifier> cls_BRepClass_FClass2dOfFClassifier(mod, "BRepClass_FClass2dOfFClassifier", "None");

// Constructors
cls_BRepClass_FClass2dOfFClassifier.def(py::init<>());

// Methods
// cls_BRepClass_FClass2dOfFClassifier.def_static("operator new_", (void * (*)(size_t)) &BRepClass_FClass2dOfFClassifier::operator new, "None", py::arg("theSize"));
// cls_BRepClass_FClass2dOfFClassifier.def_static("operator delete_", (void (*)(void *)) &BRepClass_FClass2dOfFClassifier::operator delete, "None", py::arg("theAddress"));
// cls_BRepClass_FClass2dOfFClassifier.def_static("operator new[]_", (void * (*)(size_t)) &BRepClass_FClass2dOfFClassifier::operator new[], "None", py::arg("theSize"));
// cls_BRepClass_FClass2dOfFClassifier.def_static("operator delete[]_", (void (*)(void *)) &BRepClass_FClass2dOfFClassifier::operator delete[], "None", py::arg("theAddress"));
// cls_BRepClass_FClass2dOfFClassifier.def_static("operator new_", (void * (*)(size_t, void *)) &BRepClass_FClass2dOfFClassifier::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepClass_FClass2dOfFClassifier.def_static("operator delete_", (void (*)(void *, void *)) &BRepClass_FClass2dOfFClassifier::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepClass_FClass2dOfFClassifier.def("Reset", (void (BRepClass_FClass2dOfFClassifier::*)(const gp_Lin2d &, const Standard_Real, const Standard_Real)) &BRepClass_FClass2dOfFClassifier::Reset, "Starts a classification process. The point to classify is the origin of the line <L>. <P> is the original length of the segment on <L> used to compute intersections. <Tol> is the tolerance attached to the line segment in intersections.", py::arg("L"), py::arg("P"), py::arg("Tol"));
cls_BRepClass_FClass2dOfFClassifier.def("Compare", (void (BRepClass_FClass2dOfFClassifier::*)(const BRepClass_Edge &, const TopAbs_Orientation)) &BRepClass_FClass2dOfFClassifier::Compare, "Updates the classification process with the edge <E> from the boundary.", py::arg("E"), py::arg("Or"));
cls_BRepClass_FClass2dOfFClassifier.def("Parameter", (Standard_Real (BRepClass_FClass2dOfFClassifier::*)() const) &BRepClass_FClass2dOfFClassifier::Parameter, "Returns the current value of the parameter.");
cls_BRepClass_FClass2dOfFClassifier.def("Intersector", (BRepClass_Intersector & (BRepClass_FClass2dOfFClassifier::*)()) &BRepClass_FClass2dOfFClassifier::Intersector, "Returns the intersecting algorithm.");
cls_BRepClass_FClass2dOfFClassifier.def("ClosestIntersection", (Standard_Integer (BRepClass_FClass2dOfFClassifier::*)() const) &BRepClass_FClass2dOfFClassifier::ClosestIntersection, "Returns 0 if the last compared edge had no relevant intersection. Else returns the index of this intersection in the last intersection algorithm.");
cls_BRepClass_FClass2dOfFClassifier.def("State", (TopAbs_State (BRepClass_FClass2dOfFClassifier::*)() const) &BRepClass_FClass2dOfFClassifier::State, "Returns the current state of the point.");
cls_BRepClass_FClass2dOfFClassifier.def("IsHeadOrEnd", (Standard_Boolean (BRepClass_FClass2dOfFClassifier::*)() const) &BRepClass_FClass2dOfFClassifier::IsHeadOrEnd, "Returns the Standard_True if the closest intersection point represents head or end of the edge. Returns Standard_False otherwise.");

// CLASS: BREPCLASS_FCLASSIFIER
py::class_<BRepClass_FClassifier> cls_BRepClass_FClassifier(mod, "BRepClass_FClassifier", "None");

// Constructors
cls_BRepClass_FClassifier.def(py::init<>());
cls_BRepClass_FClassifier.def(py::init<BRepClass_FaceExplorer &, const gp_Pnt2d &, const Standard_Real>(), py::arg("F"), py::arg("P"), py::arg("Tol"));

// Methods
// cls_BRepClass_FClassifier.def_static("operator new_", (void * (*)(size_t)) &BRepClass_FClassifier::operator new, "None", py::arg("theSize"));
// cls_BRepClass_FClassifier.def_static("operator delete_", (void (*)(void *)) &BRepClass_FClassifier::operator delete, "None", py::arg("theAddress"));
// cls_BRepClass_FClassifier.def_static("operator new[]_", (void * (*)(size_t)) &BRepClass_FClassifier::operator new[], "None", py::arg("theSize"));
// cls_BRepClass_FClassifier.def_static("operator delete[]_", (void (*)(void *)) &BRepClass_FClassifier::operator delete[], "None", py::arg("theAddress"));
// cls_BRepClass_FClassifier.def_static("operator new_", (void * (*)(size_t, void *)) &BRepClass_FClassifier::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepClass_FClassifier.def_static("operator delete_", (void (*)(void *, void *)) &BRepClass_FClassifier::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepClass_FClassifier.def("Perform", (void (BRepClass_FClassifier::*)(BRepClass_FaceExplorer &, const gp_Pnt2d &, const Standard_Real)) &BRepClass_FClassifier::Perform, "Classify the Point P with Tolerance <T> on the face described by <F>.", py::arg("F"), py::arg("P"), py::arg("Tol"));
cls_BRepClass_FClassifier.def("State", (TopAbs_State (BRepClass_FClassifier::*)() const) &BRepClass_FClassifier::State, "Returns the result of the classification.");
cls_BRepClass_FClassifier.def("Rejected", (Standard_Boolean (BRepClass_FClassifier::*)() const) &BRepClass_FClassifier::Rejected, "Returns True when the state was computed by a rejection. The state is OUT.");
cls_BRepClass_FClassifier.def("NoWires", (Standard_Boolean (BRepClass_FClassifier::*)() const) &BRepClass_FClassifier::NoWires, "Returns True if the face contains no wire. The state is IN.");
cls_BRepClass_FClassifier.def("Edge", (const BRepClass_Edge & (BRepClass_FClassifier::*)() const) &BRepClass_FClassifier::Edge, "Returns the Edge used to determine the classification. When the State is ON this is the Edge containing the point.");
cls_BRepClass_FClassifier.def("EdgeParameter", (Standard_Real (BRepClass_FClassifier::*)() const) &BRepClass_FClassifier::EdgeParameter, "Returns the parameter on Edge() used to determine the classification.");
cls_BRepClass_FClassifier.def("Position", (IntRes2d_Position (BRepClass_FClassifier::*)() const) &BRepClass_FClassifier::Position, "Returns the position of the point on the edge returned by Edge.");

// CLASS: BREPCLASS_FACEEXPLORER
py::class_<BRepClass_FaceExplorer> cls_BRepClass_FaceExplorer(mod, "BRepClass_FaceExplorer", "Provide an exploration of a BRep Face for the classification. Return UV edges.");

// Constructors
cls_BRepClass_FaceExplorer.def(py::init<const TopoDS_Face &>(), py::arg("F"));

// Methods
// cls_BRepClass_FaceExplorer.def_static("operator new_", (void * (*)(size_t)) &BRepClass_FaceExplorer::operator new, "None", py::arg("theSize"));
// cls_BRepClass_FaceExplorer.def_static("operator delete_", (void (*)(void *)) &BRepClass_FaceExplorer::operator delete, "None", py::arg("theAddress"));
// cls_BRepClass_FaceExplorer.def_static("operator new[]_", (void * (*)(size_t)) &BRepClass_FaceExplorer::operator new[], "None", py::arg("theSize"));
// cls_BRepClass_FaceExplorer.def_static("operator delete[]_", (void (*)(void *)) &BRepClass_FaceExplorer::operator delete[], "None", py::arg("theAddress"));
// cls_BRepClass_FaceExplorer.def_static("operator new_", (void * (*)(size_t, void *)) &BRepClass_FaceExplorer::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepClass_FaceExplorer.def_static("operator delete_", (void (*)(void *, void *)) &BRepClass_FaceExplorer::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepClass_FaceExplorer.def("CheckPoint", (Standard_Boolean (BRepClass_FaceExplorer::*)(gp_Pnt2d &)) &BRepClass_FaceExplorer::CheckPoint, "Checks the point and change its coords if it is located too far from the bounding box of the face. New Coordinates of the point will be on the line between the point and the center of the bounding box. Returns True if point was not changed.", py::arg("thePoint"));
cls_BRepClass_FaceExplorer.def("Reject", (Standard_Boolean (BRepClass_FaceExplorer::*)(const gp_Pnt2d &) const) &BRepClass_FaceExplorer::Reject, "Should return True if the point is outside a bounding volume of the face.", py::arg("P"));
cls_BRepClass_FaceExplorer.def("Segment", [](BRepClass_FaceExplorer &self, const gp_Pnt2d & P, gp_Lin2d & L, Standard_Real & Par){ Standard_Boolean rv = self.Segment(P, L, Par); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Par); }, "Returns in <L>, <Par> a segment having at least one intersection with the face boundary to compute intersections.", py::arg("P"), py::arg("L"), py::arg("Par"));
cls_BRepClass_FaceExplorer.def("OtherSegment", [](BRepClass_FaceExplorer &self, const gp_Pnt2d & P, gp_Lin2d & L, Standard_Real & Par){ Standard_Boolean rv = self.OtherSegment(P, L, Par); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Par); }, "Returns in <L>, <Par> a segment having at least one intersection with the face boundary to compute intersections. Each call gives another segment.", py::arg("P"), py::arg("L"), py::arg("Par"));
cls_BRepClass_FaceExplorer.def("InitWires", (void (BRepClass_FaceExplorer::*)()) &BRepClass_FaceExplorer::InitWires, "Starts an exploration of the wires.");
cls_BRepClass_FaceExplorer.def("MoreWires", (Standard_Boolean (BRepClass_FaceExplorer::*)() const) &BRepClass_FaceExplorer::MoreWires, "Returns True if there is a current wire.");
cls_BRepClass_FaceExplorer.def("NextWire", (void (BRepClass_FaceExplorer::*)()) &BRepClass_FaceExplorer::NextWire, "Sets the explorer to the next wire.");
cls_BRepClass_FaceExplorer.def("RejectWire", (Standard_Boolean (BRepClass_FaceExplorer::*)(const gp_Lin2d &, const Standard_Real) const) &BRepClass_FaceExplorer::RejectWire, "Returns True if the wire bounding volume does not intersect the segment.", py::arg("L"), py::arg("Par"));
cls_BRepClass_FaceExplorer.def("InitEdges", (void (BRepClass_FaceExplorer::*)()) &BRepClass_FaceExplorer::InitEdges, "Starts an exploration of the edges of the current wire.");
cls_BRepClass_FaceExplorer.def("MoreEdges", (Standard_Boolean (BRepClass_FaceExplorer::*)() const) &BRepClass_FaceExplorer::MoreEdges, "Returns True if there is a current edge.");
cls_BRepClass_FaceExplorer.def("NextEdge", (void (BRepClass_FaceExplorer::*)()) &BRepClass_FaceExplorer::NextEdge, "Sets the explorer to the next edge.");
cls_BRepClass_FaceExplorer.def("RejectEdge", (Standard_Boolean (BRepClass_FaceExplorer::*)(const gp_Lin2d &, const Standard_Real) const) &BRepClass_FaceExplorer::RejectEdge, "Returns True if the edge bounding volume does not intersect the segment.", py::arg("L"), py::arg("Par"));
cls_BRepClass_FaceExplorer.def("CurrentEdge", (void (BRepClass_FaceExplorer::*)(BRepClass_Edge &, TopAbs_Orientation &) const) &BRepClass_FaceExplorer::CurrentEdge, "Current edge in current wire and its orientation.", py::arg("E"), py::arg("Or"));

// CLASS: BREPCLASS_FACECLASSIFIER
py::class_<BRepClass_FaceClassifier, BRepClass_FClassifier> cls_BRepClass_FaceClassifier(mod, "BRepClass_FaceClassifier", "Provides Constructors with a Face.");

// Constructors
cls_BRepClass_FaceClassifier.def(py::init<>());
cls_BRepClass_FaceClassifier.def(py::init<BRepClass_FaceExplorer &, const gp_Pnt2d &, const Standard_Real>(), py::arg("F"), py::arg("P"), py::arg("Tol"));
cls_BRepClass_FaceClassifier.def(py::init<const TopoDS_Face &, const gp_Pnt2d &, const Standard_Real>(), py::arg("F"), py::arg("P"), py::arg("Tol"));
cls_BRepClass_FaceClassifier.def(py::init<const TopoDS_Face &, const gp_Pnt &, const Standard_Real>(), py::arg("F"), py::arg("P"), py::arg("Tol"));

// Methods
// cls_BRepClass_FaceClassifier.def_static("operator new_", (void * (*)(size_t)) &BRepClass_FaceClassifier::operator new, "None", py::arg("theSize"));
// cls_BRepClass_FaceClassifier.def_static("operator delete_", (void (*)(void *)) &BRepClass_FaceClassifier::operator delete, "None", py::arg("theAddress"));
// cls_BRepClass_FaceClassifier.def_static("operator new[]_", (void * (*)(size_t)) &BRepClass_FaceClassifier::operator new[], "None", py::arg("theSize"));
// cls_BRepClass_FaceClassifier.def_static("operator delete[]_", (void (*)(void *)) &BRepClass_FaceClassifier::operator delete[], "None", py::arg("theAddress"));
// cls_BRepClass_FaceClassifier.def_static("operator new_", (void * (*)(size_t, void *)) &BRepClass_FaceClassifier::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepClass_FaceClassifier.def_static("operator delete_", (void (*)(void *, void *)) &BRepClass_FaceClassifier::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepClass_FaceClassifier.def("Perform", (void (BRepClass_FaceClassifier::*)(const TopoDS_Face &, const gp_Pnt2d &, const Standard_Real)) &BRepClass_FaceClassifier::Perform, "Classify the Point P with Tolerance <T> on the face described by <F>.", py::arg("F"), py::arg("P"), py::arg("Tol"));
cls_BRepClass_FaceClassifier.def("Perform", (void (BRepClass_FaceClassifier::*)(const TopoDS_Face &, const gp_Pnt &, const Standard_Real)) &BRepClass_FaceClassifier::Perform, "Classify the Point P with Tolerance <T> on the face described by <F>.", py::arg("F"), py::arg("P"), py::arg("Tol"));

// CLASS: BREPCLASS_FACEPASSIVECLASSIFIER
py::class_<BRepClass_FacePassiveClassifier> cls_BRepClass_FacePassiveClassifier(mod, "BRepClass_FacePassiveClassifier", "None");

// Constructors
cls_BRepClass_FacePassiveClassifier.def(py::init<>());

// Methods
// cls_BRepClass_FacePassiveClassifier.def_static("operator new_", (void * (*)(size_t)) &BRepClass_FacePassiveClassifier::operator new, "None", py::arg("theSize"));
// cls_BRepClass_FacePassiveClassifier.def_static("operator delete_", (void (*)(void *)) &BRepClass_FacePassiveClassifier::operator delete, "None", py::arg("theAddress"));
// cls_BRepClass_FacePassiveClassifier.def_static("operator new[]_", (void * (*)(size_t)) &BRepClass_FacePassiveClassifier::operator new[], "None", py::arg("theSize"));
// cls_BRepClass_FacePassiveClassifier.def_static("operator delete[]_", (void (*)(void *)) &BRepClass_FacePassiveClassifier::operator delete[], "None", py::arg("theAddress"));
// cls_BRepClass_FacePassiveClassifier.def_static("operator new_", (void * (*)(size_t, void *)) &BRepClass_FacePassiveClassifier::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepClass_FacePassiveClassifier.def_static("operator delete_", (void (*)(void *, void *)) &BRepClass_FacePassiveClassifier::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepClass_FacePassiveClassifier.def("Reset", (void (BRepClass_FacePassiveClassifier::*)(const gp_Lin2d &, const Standard_Real, const Standard_Real)) &BRepClass_FacePassiveClassifier::Reset, "Starts a classification process. The point to classify is the origin of the line <L>. <P> is the original length of the segment on <L> used to compute intersections. <Tol> is the tolerance attached to the line segment in intersections.", py::arg("L"), py::arg("P"), py::arg("Tol"));
cls_BRepClass_FacePassiveClassifier.def("Compare", (void (BRepClass_FacePassiveClassifier::*)(const BRepClass_Edge &, const TopAbs_Orientation)) &BRepClass_FacePassiveClassifier::Compare, "Updates the classification process with the edge <E> from the boundary.", py::arg("E"), py::arg("Or"));
cls_BRepClass_FacePassiveClassifier.def("Parameter", (Standard_Real (BRepClass_FacePassiveClassifier::*)() const) &BRepClass_FacePassiveClassifier::Parameter, "Returns the current value of the parameter.");
cls_BRepClass_FacePassiveClassifier.def("Intersector", (BRepClass_Intersector & (BRepClass_FacePassiveClassifier::*)()) &BRepClass_FacePassiveClassifier::Intersector, "Returns the intersecting algorithm.");
cls_BRepClass_FacePassiveClassifier.def("ClosestIntersection", (Standard_Integer (BRepClass_FacePassiveClassifier::*)() const) &BRepClass_FacePassiveClassifier::ClosestIntersection, "Returns 0 if the last compared edge had no relevant intersection. Else returns the index of this intersection in the last intersection algorithm.");
cls_BRepClass_FacePassiveClassifier.def("State", (TopAbs_State (BRepClass_FacePassiveClassifier::*)() const) &BRepClass_FacePassiveClassifier::State, "Returns the current state of the point.");
cls_BRepClass_FacePassiveClassifier.def("IsHeadOrEnd", (Standard_Boolean (BRepClass_FacePassiveClassifier::*)() const) &BRepClass_FacePassiveClassifier::IsHeadOrEnd, "Returns the Standard_True if the closest intersection point represents head or end of the edge. Returns Standard_False otherwise.");


}
