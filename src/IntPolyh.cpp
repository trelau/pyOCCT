/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC (info@laughlinresearch.com)

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
#include <pyOCCT_Common.hpp>

#include <Standard_TypeDef.hxx>
#include <IntPolyh_Array.hxx>
#include <IntPolyh_Edge.hxx>
#include <IntPolyh_ArrayOfEdges.hxx>
#include <IntPolyh_Point.hxx>
#include <Standard_Handle.hxx>
#include <Adaptor3d_HSurface.hxx>
#include <IntPolyh_ArrayOfPoints.hxx>
#include <IntPolyh_ArrayOfTriangles.hxx>
#include <Bnd_Box.hxx>
#include <IntPolyh_Triangle.hxx>
#include <IntPolyh_StartPoint.hxx>
#include <NCollection_BaseSequence.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_Sequence.hxx>
#include <IntPolyh_SeqOfStartPoints.hxx>
#include <IntPolyh_SectionLine.hxx>
#include <IntPolyh_ArrayOfSectionLines.hxx>
#include <IntPolyh_ArrayOfTangentZones.hxx>
#include <IntPolyh_Couple.hxx>
#include <IntPolyh_CoupleMapHasher.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <IntPolyh_ListOfCouples.hxx>
#include <IntPolyh_MaillageAffinage.hxx>
#include <IntPolyh_PMaillageAffinage.hxx>
#include <NCollection_BaseList.hxx>
#include <NCollection_List.hxx>
#include <IntPolyh_Intersection.hxx>
#include <IntPolyh_Templates.hpp>
#include <NCollection_Templates.hpp>

PYBIND11_MODULE(IntPolyh, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.Adaptor3d");
	py::module::import("OCCT.Bnd");
	py::module::import("OCCT.NCollection");
	py::module::import("OCCT.TColStd");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\IntPolyh_Edge.hxx
	py::class_<IntPolyh_Edge, std::unique_ptr<IntPolyh_Edge, Deleter<IntPolyh_Edge>>> cls_IntPolyh_Edge(mod, "IntPolyh_Edge", "The class represents the edge built between the two IntPolyh points. It is linked to two IntPolyh triangles.");
	cls_IntPolyh_Edge.def(py::init<>());
	cls_IntPolyh_Edge.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("thePoint1"), py::arg("thePoint2"), py::arg("theTriangle1"), py::arg("theTriangle2"));
	cls_IntPolyh_Edge.def("FirstPoint", (Standard_Integer (IntPolyh_Edge::*)() const ) &IntPolyh_Edge::FirstPoint, "Returns the first point");
	cls_IntPolyh_Edge.def("SecondPoint", (Standard_Integer (IntPolyh_Edge::*)() const ) &IntPolyh_Edge::SecondPoint, "Returns the second point");
	cls_IntPolyh_Edge.def("FirstTriangle", (Standard_Integer (IntPolyh_Edge::*)() const ) &IntPolyh_Edge::FirstTriangle, "Returns the first triangle");
	cls_IntPolyh_Edge.def("SecondTriangle", (Standard_Integer (IntPolyh_Edge::*)() const ) &IntPolyh_Edge::SecondTriangle, "Returns the second triangle");
	cls_IntPolyh_Edge.def("SetFirstPoint", (void (IntPolyh_Edge::*)(const Standard_Integer)) &IntPolyh_Edge::SetFirstPoint, "Sets the first point", py::arg("thePoint"));
	cls_IntPolyh_Edge.def("SetSecondPoint", (void (IntPolyh_Edge::*)(const Standard_Integer)) &IntPolyh_Edge::SetSecondPoint, "Sets the second point", py::arg("thePoint"));
	cls_IntPolyh_Edge.def("SetFirstTriangle", (void (IntPolyh_Edge::*)(const Standard_Integer)) &IntPolyh_Edge::SetFirstTriangle, "Sets the first triangle", py::arg("theTriangle"));
	cls_IntPolyh_Edge.def("SetSecondTriangle", (void (IntPolyh_Edge::*)(const Standard_Integer)) &IntPolyh_Edge::SetSecondTriangle, "Sets the second triangle", py::arg("theTriangle"));
	// FIXME cls_IntPolyh_Edge.def("Dump", (void (IntPolyh_Edge::*)(const Standard_Integer) const ) &IntPolyh_Edge::Dump, "None", py::arg("v"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntPolyh_Point.hxx
	py::class_<IntPolyh_Point, std::unique_ptr<IntPolyh_Point, Deleter<IntPolyh_Point>>> cls_IntPolyh_Point(mod, "IntPolyh_Point", "The class represents the point on the surface with both 3D and 2D points.");
	cls_IntPolyh_Point.def(py::init<>());
	cls_IntPolyh_Point.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("x"), py::arg("y"), py::arg("z"), py::arg("u"), py::arg("v"));
	cls_IntPolyh_Point.def("X", (Standard_Real (IntPolyh_Point::*)() const ) &IntPolyh_Point::X, "Returns X coordinate of the 3D point");
	cls_IntPolyh_Point.def("Y", (Standard_Real (IntPolyh_Point::*)() const ) &IntPolyh_Point::Y, "Returns Y coordinate of the 3D point");
	cls_IntPolyh_Point.def("Z", (Standard_Real (IntPolyh_Point::*)() const ) &IntPolyh_Point::Z, "Returns the Z coordinate of the 3D point");
	cls_IntPolyh_Point.def("U", (Standard_Real (IntPolyh_Point::*)() const ) &IntPolyh_Point::U, "Returns the U coordinate of the 2D point");
	cls_IntPolyh_Point.def("V", (Standard_Real (IntPolyh_Point::*)() const ) &IntPolyh_Point::V, "Returns the V coordinate of the 2D point");
	cls_IntPolyh_Point.def("PartOfCommon", (Standard_Integer (IntPolyh_Point::*)() const ) &IntPolyh_Point::PartOfCommon, "Returns 0 if the point is not common with the other surface");
	cls_IntPolyh_Point.def("Equal", (void (IntPolyh_Point::*)(const IntPolyh_Point &)) &IntPolyh_Point::Equal, "Assignment operator", py::arg("Pt"));
	cls_IntPolyh_Point.def("assign", (void (IntPolyh_Point::*)(const IntPolyh_Point &)) &IntPolyh_Point::operator=, py::is_operator(), "None", py::arg("Pt"));
	cls_IntPolyh_Point.def("Set", [](IntPolyh_Point &self, const Standard_Real a0, const Standard_Real a1, const Standard_Real a2, const Standard_Real a3, const Standard_Real a4) -> void { return self.Set(a0, a1, a2, a3, a4); }, py::arg("x"), py::arg("y"), py::arg("z"), py::arg("u"), py::arg("v"));
	cls_IntPolyh_Point.def("Set", (void (IntPolyh_Point::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer)) &IntPolyh_Point::Set, "Sets the point", py::arg("x"), py::arg("y"), py::arg("z"), py::arg("u"), py::arg("v"), py::arg("II"));
	cls_IntPolyh_Point.def("SetX", (void (IntPolyh_Point::*)(const Standard_Real)) &IntPolyh_Point::SetX, "Sets the X coordinate for the 3D point", py::arg("x"));
	cls_IntPolyh_Point.def("SetY", (void (IntPolyh_Point::*)(const Standard_Real)) &IntPolyh_Point::SetY, "Sets the Y coordinate for the 3D point", py::arg("y"));
	cls_IntPolyh_Point.def("SetZ", (void (IntPolyh_Point::*)(const Standard_Real)) &IntPolyh_Point::SetZ, "Sets the Z coordinate for the 3D point", py::arg("z"));
	cls_IntPolyh_Point.def("SetU", (void (IntPolyh_Point::*)(const Standard_Real)) &IntPolyh_Point::SetU, "Sets the U coordinate for the 2D point", py::arg("u"));
	cls_IntPolyh_Point.def("SetV", (void (IntPolyh_Point::*)(const Standard_Real)) &IntPolyh_Point::SetV, "Sets the V coordinate for the 2D point", py::arg("v"));
	cls_IntPolyh_Point.def("SetPartOfCommon", (void (IntPolyh_Point::*)(const Standard_Integer)) &IntPolyh_Point::SetPartOfCommon, "Sets the part of common", py::arg("ii"));
	cls_IntPolyh_Point.def("Middle", (void (IntPolyh_Point::*)(const opencascade::handle<Adaptor3d_HSurface> &, const IntPolyh_Point &, const IntPolyh_Point &)) &IntPolyh_Point::Middle, "Creates middle point from P1 and P2 and stores it to this", py::arg("MySurface"), py::arg("P1"), py::arg("P2"));
	cls_IntPolyh_Point.def("Add", (IntPolyh_Point (IntPolyh_Point::*)(const IntPolyh_Point &) const ) &IntPolyh_Point::Add, "Addition", py::arg("P1"));
	cls_IntPolyh_Point.def("__add__", (IntPolyh_Point (IntPolyh_Point::*)(const IntPolyh_Point &) const ) &IntPolyh_Point::operator+, py::is_operator(), "None", py::arg("P1"));
	cls_IntPolyh_Point.def("Sub", (IntPolyh_Point (IntPolyh_Point::*)(const IntPolyh_Point &) const ) &IntPolyh_Point::Sub, "Subtraction", py::arg("P1"));
	cls_IntPolyh_Point.def("__sub__", (IntPolyh_Point (IntPolyh_Point::*)(const IntPolyh_Point &) const ) &IntPolyh_Point::operator-, py::is_operator(), "None", py::arg("P1"));
	cls_IntPolyh_Point.def("Divide", (IntPolyh_Point (IntPolyh_Point::*)(const Standard_Real) const ) &IntPolyh_Point::Divide, "Division", py::arg("rr"));
	cls_IntPolyh_Point.def("__truediv__", (IntPolyh_Point (IntPolyh_Point::*)(const Standard_Real) const ) &IntPolyh_Point::operator/, py::is_operator(), "None", py::arg("rr"));
	cls_IntPolyh_Point.def("Multiplication", (IntPolyh_Point (IntPolyh_Point::*)(const Standard_Real) const ) &IntPolyh_Point::Multiplication, "Multiplication", py::arg("rr"));
	cls_IntPolyh_Point.def("__mul__", (IntPolyh_Point (IntPolyh_Point::*)(const Standard_Real) const ) &IntPolyh_Point::operator*, py::is_operator(), "None", py::arg("rr"));
	cls_IntPolyh_Point.def("SquareModulus", (Standard_Real (IntPolyh_Point::*)() const ) &IntPolyh_Point::SquareModulus, "Square modulus");
	cls_IntPolyh_Point.def("SquareDistance", (Standard_Real (IntPolyh_Point::*)(const IntPolyh_Point &) const ) &IntPolyh_Point::SquareDistance, "Square distance to the other point", py::arg("P2"));
	cls_IntPolyh_Point.def("Dot", (Standard_Real (IntPolyh_Point::*)(const IntPolyh_Point &) const ) &IntPolyh_Point::Dot, "Dot", py::arg("P2"));
	cls_IntPolyh_Point.def("Cross", (void (IntPolyh_Point::*)(const IntPolyh_Point &, const IntPolyh_Point &)) &IntPolyh_Point::Cross, "Cross", py::arg("P1"), py::arg("P2"));
	// FIXME cls_IntPolyh_Point.def("Dump", (void (IntPolyh_Point::*)() const ) &IntPolyh_Point::Dump, "Dump");
	// FIXME cls_IntPolyh_Point.def("Dump", (void (IntPolyh_Point::*)(const Standard_Integer) const ) &IntPolyh_Point::Dump, "Dump", py::arg("i"));
	cls_IntPolyh_Point.def("SetDegenerated", (void (IntPolyh_Point::*)(const Standard_Boolean)) &IntPolyh_Point::SetDegenerated, "Sets the degenerated flag", py::arg("theFlag"));
	cls_IntPolyh_Point.def("Degenerated", (Standard_Boolean (IntPolyh_Point::*)() const ) &IntPolyh_Point::Degenerated, "Returns the degenerated flag");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntPolyh_Triangle.hxx
	py::class_<IntPolyh_Triangle, std::unique_ptr<IntPolyh_Triangle, Deleter<IntPolyh_Triangle>>> cls_IntPolyh_Triangle(mod, "IntPolyh_Triangle", "The class represents the triangle built from three IntPolyh points and three IntPolyh edges.");
	cls_IntPolyh_Triangle.def(py::init<>());
	cls_IntPolyh_Triangle.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("thePoint1"), py::arg("thePoint2"), py::arg("thePoint3"));
	cls_IntPolyh_Triangle.def("FirstPoint", (Standard_Integer (IntPolyh_Triangle::*)() const ) &IntPolyh_Triangle::FirstPoint, "Returns the first point");
	cls_IntPolyh_Triangle.def("SecondPoint", (Standard_Integer (IntPolyh_Triangle::*)() const ) &IntPolyh_Triangle::SecondPoint, "Returns the second point");
	cls_IntPolyh_Triangle.def("ThirdPoint", (Standard_Integer (IntPolyh_Triangle::*)() const ) &IntPolyh_Triangle::ThirdPoint, "Returns the third point");
	cls_IntPolyh_Triangle.def("FirstEdge", (Standard_Integer (IntPolyh_Triangle::*)() const ) &IntPolyh_Triangle::FirstEdge, "Returns the first edge");
	cls_IntPolyh_Triangle.def("FirstEdgeOrientation", (Standard_Integer (IntPolyh_Triangle::*)() const ) &IntPolyh_Triangle::FirstEdgeOrientation, "Returns the orientation of the first edge");
	cls_IntPolyh_Triangle.def("SecondEdge", (Standard_Integer (IntPolyh_Triangle::*)() const ) &IntPolyh_Triangle::SecondEdge, "Returns the second edge");
	cls_IntPolyh_Triangle.def("SecondEdgeOrientation", (Standard_Integer (IntPolyh_Triangle::*)() const ) &IntPolyh_Triangle::SecondEdgeOrientation, "Returns the orientation of the second edge");
	cls_IntPolyh_Triangle.def("ThirdEdge", (Standard_Integer (IntPolyh_Triangle::*)() const ) &IntPolyh_Triangle::ThirdEdge, "Returns the third edge");
	cls_IntPolyh_Triangle.def("ThirdEdgeOrientation", (Standard_Integer (IntPolyh_Triangle::*)() const ) &IntPolyh_Triangle::ThirdEdgeOrientation, "Returns the orientation of the third edge");
	cls_IntPolyh_Triangle.def("Deflection", (Standard_Real (IntPolyh_Triangle::*)() const ) &IntPolyh_Triangle::Deflection, "Returns the deflection of the triangle");
	cls_IntPolyh_Triangle.def("IsIntersectionPossible", (Standard_Boolean (IntPolyh_Triangle::*)() const ) &IntPolyh_Triangle::IsIntersectionPossible, "Returns possibility of the intersection");
	cls_IntPolyh_Triangle.def("HasIntersection", (Standard_Boolean (IntPolyh_Triangle::*)() const ) &IntPolyh_Triangle::HasIntersection, "Returns true if the triangle has interfered the other triangle");
	cls_IntPolyh_Triangle.def("IsDegenerated", (Standard_Boolean (IntPolyh_Triangle::*)() const ) &IntPolyh_Triangle::IsDegenerated, "Returns the Degenerated flag");
	cls_IntPolyh_Triangle.def("SetFirstPoint", (void (IntPolyh_Triangle::*)(const Standard_Integer)) &IntPolyh_Triangle::SetFirstPoint, "Sets the first point", py::arg("thePoint"));
	cls_IntPolyh_Triangle.def("SetSecondPoint", (void (IntPolyh_Triangle::*)(const Standard_Integer)) &IntPolyh_Triangle::SetSecondPoint, "Sets the second point", py::arg("thePoint"));
	cls_IntPolyh_Triangle.def("SetThirdPoint", (void (IntPolyh_Triangle::*)(const Standard_Integer)) &IntPolyh_Triangle::SetThirdPoint, "Sets the third point", py::arg("thePoint"));
	cls_IntPolyh_Triangle.def("SetFirstEdge", (void (IntPolyh_Triangle::*)(const Standard_Integer, const Standard_Integer)) &IntPolyh_Triangle::SetFirstEdge, "Sets the first edge", py::arg("theEdge"), py::arg("theEdgeOrientation"));
	cls_IntPolyh_Triangle.def("SetSecondEdge", (void (IntPolyh_Triangle::*)(const Standard_Integer, const Standard_Integer)) &IntPolyh_Triangle::SetSecondEdge, "Sets the second edge", py::arg("theEdge"), py::arg("theEdgeOrientation"));
	cls_IntPolyh_Triangle.def("SetThirdEdge", (void (IntPolyh_Triangle::*)(const Standard_Integer, const Standard_Integer)) &IntPolyh_Triangle::SetThirdEdge, "Sets the third edge", py::arg("theEdge"), py::arg("theEdgeOrientation"));
	cls_IntPolyh_Triangle.def("SetDeflection", (void (IntPolyh_Triangle::*)(const Standard_Real)) &IntPolyh_Triangle::SetDeflection, "Sets the deflection", py::arg("theDeflection"));
	cls_IntPolyh_Triangle.def("SetIntersectionPossible", (void (IntPolyh_Triangle::*)(const Standard_Boolean)) &IntPolyh_Triangle::SetIntersectionPossible, "Sets the flag of possibility of intersection", py::arg("theIP"));
	cls_IntPolyh_Triangle.def("SetIntersection", (void (IntPolyh_Triangle::*)(const Standard_Boolean)) &IntPolyh_Triangle::SetIntersection, "Sets the flag of intersection", py::arg("theInt"));
	cls_IntPolyh_Triangle.def("SetDegenerated", (void (IntPolyh_Triangle::*)(const Standard_Boolean)) &IntPolyh_Triangle::SetDegenerated, "Sets the degenerated flag", py::arg("theDegFlag"));
	cls_IntPolyh_Triangle.def("GetEdgeNumber", (Standard_Integer (IntPolyh_Triangle::*)(const Standard_Integer) const ) &IntPolyh_Triangle::GetEdgeNumber, "Gets the edge number by the index", py::arg("theEdgeIndex"));
	cls_IntPolyh_Triangle.def("SetEdge", (void (IntPolyh_Triangle::*)(const Standard_Integer, const Standard_Integer)) &IntPolyh_Triangle::SetEdge, "Sets the edge by the index", py::arg("theEdgeIndex"), py::arg("theEdgeNumber"));
	cls_IntPolyh_Triangle.def("GetEdgeOrientation", (Standard_Integer (IntPolyh_Triangle::*)(const Standard_Integer) const ) &IntPolyh_Triangle::GetEdgeOrientation, "Gets the edges orientation by the index", py::arg("theEdgeIndex"));
	cls_IntPolyh_Triangle.def("SetEdgeOrientation", (void (IntPolyh_Triangle::*)(const Standard_Integer, const Standard_Integer)) &IntPolyh_Triangle::SetEdgeOrientation, "Sets the edges orientation by the index", py::arg("theEdgeIndex"), py::arg("theEdgeOrientation"));
	cls_IntPolyh_Triangle.def("ComputeDeflection", (Standard_Real (IntPolyh_Triangle::*)(const opencascade::handle<Adaptor3d_HSurface> &, const IntPolyh_ArrayOfPoints &)) &IntPolyh_Triangle::ComputeDeflection, "Computes the deflection for the triangle", py::arg("theSurface"), py::arg("thePoints"));
	cls_IntPolyh_Triangle.def("GetNextTriangle", (Standard_Integer (IntPolyh_Triangle::*)(const Standard_Integer, const Standard_Integer, const IntPolyh_ArrayOfEdges &) const ) &IntPolyh_Triangle::GetNextTriangle, "Gets the adjacent triangle", py::arg("theTriangle"), py::arg("theEdgeNum"), py::arg("TEdges"));
	cls_IntPolyh_Triangle.def("MiddleRefinement", (void (IntPolyh_Triangle::*)(const Standard_Integer, const opencascade::handle<Adaptor3d_HSurface> &, IntPolyh_ArrayOfPoints &, IntPolyh_ArrayOfTriangles &, IntPolyh_ArrayOfEdges &)) &IntPolyh_Triangle::MiddleRefinement, "Splits the triangle on two to decrease its deflection", py::arg("theTriangleNumber"), py::arg("theSurface"), py::arg("TPoints"), py::arg("TTriangles"), py::arg("TEdges"));
	cls_IntPolyh_Triangle.def("MultipleMiddleRefinement", (void (IntPolyh_Triangle::*)(const Standard_Real, const Bnd_Box &, const Standard_Integer, const opencascade::handle<Adaptor3d_HSurface> &, IntPolyh_ArrayOfPoints &, IntPolyh_ArrayOfTriangles &, IntPolyh_ArrayOfEdges &)) &IntPolyh_Triangle::MultipleMiddleRefinement, "Splits the current triangle and new triangles until the refinement criterion is not achieved", py::arg("theRefineCriterion"), py::arg("theBox"), py::arg("theTriangleNumber"), py::arg("theSurface"), py::arg("TPoints"), py::arg("TTriangles"), py::arg("TEdges"));
	cls_IntPolyh_Triangle.def("LinkEdges2Triangle", (void (IntPolyh_Triangle::*)(const IntPolyh_ArrayOfEdges &, const Standard_Integer, const Standard_Integer, const Standard_Integer)) &IntPolyh_Triangle::LinkEdges2Triangle, "Links edges to triangle", py::arg("TEdges"), py::arg("theEdge1"), py::arg("theEdge2"), py::arg("theEdge3"));
	cls_IntPolyh_Triangle.def("SetEdgeAndOrientation", (void (IntPolyh_Triangle::*)(const IntPolyh_Edge &, const Standard_Integer)) &IntPolyh_Triangle::SetEdgeAndOrientation, "Sets the appropriate edge and orientation for the triangle.", py::arg("theEdge"), py::arg("theEdgeIndex"));
	cls_IntPolyh_Triangle.def("BoundingBox", (const Bnd_Box & (IntPolyh_Triangle::*)(const IntPolyh_ArrayOfPoints &)) &IntPolyh_Triangle::BoundingBox, "Returns the bounding box of the triangle.", py::arg("thePoints"));
	// FIXME cls_IntPolyh_Triangle.def("Dump", (void (IntPolyh_Triangle::*)(const Standard_Integer) const ) &IntPolyh_Triangle::Dump, "Dumps the contents of the triangle.", py::arg("v"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntPolyh_StartPoint.hxx
	py::class_<IntPolyh_StartPoint, std::unique_ptr<IntPolyh_StartPoint, Deleter<IntPolyh_StartPoint>>> cls_IntPolyh_StartPoint(mod, "IntPolyh_StartPoint", "None");
	cls_IntPolyh_StartPoint.def(py::init<>());
	cls_IntPolyh_StartPoint.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Integer>(), py::arg("xx"), py::arg("yy"), py::arg("zz"), py::arg("uu1"), py::arg("vv1"), py::arg("uu2"), py::arg("vv2"), py::arg("T1"), py::arg("E1"), py::arg("LAM1"), py::arg("T2"), py::arg("E2"), py::arg("LAM2"), py::arg("List"));
	cls_IntPolyh_StartPoint.def("X", (Standard_Real (IntPolyh_StartPoint::*)() const ) &IntPolyh_StartPoint::X, "None");
	cls_IntPolyh_StartPoint.def("Y", (Standard_Real (IntPolyh_StartPoint::*)() const ) &IntPolyh_StartPoint::Y, "None");
	cls_IntPolyh_StartPoint.def("Z", (Standard_Real (IntPolyh_StartPoint::*)() const ) &IntPolyh_StartPoint::Z, "None");
	cls_IntPolyh_StartPoint.def("U1", (Standard_Real (IntPolyh_StartPoint::*)() const ) &IntPolyh_StartPoint::U1, "None");
	cls_IntPolyh_StartPoint.def("V1", (Standard_Real (IntPolyh_StartPoint::*)() const ) &IntPolyh_StartPoint::V1, "None");
	cls_IntPolyh_StartPoint.def("U2", (Standard_Real (IntPolyh_StartPoint::*)() const ) &IntPolyh_StartPoint::U2, "None");
	cls_IntPolyh_StartPoint.def("V2", (Standard_Real (IntPolyh_StartPoint::*)() const ) &IntPolyh_StartPoint::V2, "None");
	cls_IntPolyh_StartPoint.def("T1", (Standard_Integer (IntPolyh_StartPoint::*)() const ) &IntPolyh_StartPoint::T1, "None");
	cls_IntPolyh_StartPoint.def("E1", (Standard_Integer (IntPolyh_StartPoint::*)() const ) &IntPolyh_StartPoint::E1, "None");
	cls_IntPolyh_StartPoint.def("Lambda1", (Standard_Real (IntPolyh_StartPoint::*)() const ) &IntPolyh_StartPoint::Lambda1, "None");
	cls_IntPolyh_StartPoint.def("T2", (Standard_Integer (IntPolyh_StartPoint::*)() const ) &IntPolyh_StartPoint::T2, "None");
	cls_IntPolyh_StartPoint.def("E2", (Standard_Integer (IntPolyh_StartPoint::*)() const ) &IntPolyh_StartPoint::E2, "None");
	cls_IntPolyh_StartPoint.def("Lambda2", (Standard_Real (IntPolyh_StartPoint::*)() const ) &IntPolyh_StartPoint::Lambda2, "None");
	cls_IntPolyh_StartPoint.def("GetAngle", (Standard_Real (IntPolyh_StartPoint::*)() const ) &IntPolyh_StartPoint::GetAngle, "None");
	cls_IntPolyh_StartPoint.def("ChainList", (Standard_Integer (IntPolyh_StartPoint::*)() const ) &IntPolyh_StartPoint::ChainList, "None");
	cls_IntPolyh_StartPoint.def("GetEdgePoints", [](IntPolyh_StartPoint &self, const IntPolyh_Triangle & Triangle, Standard_Integer & FirstEdgePoint, Standard_Integer & SecondEdgePoint, Standard_Integer & LastPoint){ Standard_Integer rv = self.GetEdgePoints(Triangle, FirstEdgePoint, SecondEdgePoint, LastPoint); return std::tuple<Standard_Integer, Standard_Integer &, Standard_Integer &, Standard_Integer &>(rv, FirstEdgePoint, SecondEdgePoint, LastPoint); }, "None", py::arg("Triangle"), py::arg("FirstEdgePoint"), py::arg("SecondEdgePoint"), py::arg("LastPoint"));
	cls_IntPolyh_StartPoint.def("SetXYZ", (void (IntPolyh_StartPoint::*)(const Standard_Real, const Standard_Real, const Standard_Real)) &IntPolyh_StartPoint::SetXYZ, "None", py::arg("XX"), py::arg("YY"), py::arg("ZZ"));
	cls_IntPolyh_StartPoint.def("SetUV1", (void (IntPolyh_StartPoint::*)(const Standard_Real, const Standard_Real)) &IntPolyh_StartPoint::SetUV1, "None", py::arg("UU1"), py::arg("VV1"));
	cls_IntPolyh_StartPoint.def("SetUV2", (void (IntPolyh_StartPoint::*)(const Standard_Real, const Standard_Real)) &IntPolyh_StartPoint::SetUV2, "None", py::arg("UU2"), py::arg("VV2"));
	cls_IntPolyh_StartPoint.def("SetEdge1", (void (IntPolyh_StartPoint::*)(const Standard_Integer)) &IntPolyh_StartPoint::SetEdge1, "None", py::arg("IE1"));
	cls_IntPolyh_StartPoint.def("SetLambda1", (void (IntPolyh_StartPoint::*)(const Standard_Real)) &IntPolyh_StartPoint::SetLambda1, "None", py::arg("LAM1"));
	cls_IntPolyh_StartPoint.def("SetEdge2", (void (IntPolyh_StartPoint::*)(const Standard_Integer)) &IntPolyh_StartPoint::SetEdge2, "None", py::arg("IE2"));
	cls_IntPolyh_StartPoint.def("SetLambda2", (void (IntPolyh_StartPoint::*)(const Standard_Real)) &IntPolyh_StartPoint::SetLambda2, "None", py::arg("LAM2"));
	cls_IntPolyh_StartPoint.def("SetCoupleValue", (void (IntPolyh_StartPoint::*)(const Standard_Integer, const Standard_Integer)) &IntPolyh_StartPoint::SetCoupleValue, "None", py::arg("IT1"), py::arg("IT2"));
	cls_IntPolyh_StartPoint.def("SetAngle", (void (IntPolyh_StartPoint::*)(const Standard_Real)) &IntPolyh_StartPoint::SetAngle, "None", py::arg("ang"));
	cls_IntPolyh_StartPoint.def("SetChainList", (void (IntPolyh_StartPoint::*)(const Standard_Integer)) &IntPolyh_StartPoint::SetChainList, "None", py::arg("ChList"));
	cls_IntPolyh_StartPoint.def("CheckSameSP", (Standard_Integer (IntPolyh_StartPoint::*)(const IntPolyh_StartPoint &) const ) &IntPolyh_StartPoint::CheckSameSP, "None", py::arg("SP"));
	// FIXME cls_IntPolyh_StartPoint.def("Dump", (void (IntPolyh_StartPoint::*)() const ) &IntPolyh_StartPoint::Dump, "None");
	// FIXME cls_IntPolyh_StartPoint.def("Dump", (void (IntPolyh_StartPoint::*)(const Standard_Integer) const ) &IntPolyh_StartPoint::Dump, "None", py::arg("i"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntPolyh_SectionLine.hxx
	py::class_<IntPolyh_SectionLine, std::unique_ptr<IntPolyh_SectionLine, Deleter<IntPolyh_SectionLine>>> cls_IntPolyh_SectionLine(mod, "IntPolyh_SectionLine", "None");
	cls_IntPolyh_SectionLine.def(py::init<>());
	cls_IntPolyh_SectionLine.def(py::init<const Standard_Integer>(), py::arg("nn"));
	cls_IntPolyh_SectionLine.def("Init", (void (IntPolyh_SectionLine::*)(const Standard_Integer)) &IntPolyh_SectionLine::Init, "None", py::arg("nn"));
	cls_IntPolyh_SectionLine.def("Value", (const IntPolyh_StartPoint & (IntPolyh_SectionLine::*)(const Standard_Integer) const ) &IntPolyh_SectionLine::Value, "None", py::arg("nn"));
	cls_IntPolyh_SectionLine.def("__getitem__", (const IntPolyh_StartPoint & (IntPolyh_SectionLine::*)(const Standard_Integer) const ) &IntPolyh_SectionLine::operator[], py::is_operator(), "None", py::arg("nn"));
	cls_IntPolyh_SectionLine.def("ChangeValue", (IntPolyh_StartPoint & (IntPolyh_SectionLine::*)(const Standard_Integer)) &IntPolyh_SectionLine::ChangeValue, "None", py::arg("nn"));
	cls_IntPolyh_SectionLine.def("__getitem__", (IntPolyh_StartPoint & (IntPolyh_SectionLine::*)(const Standard_Integer)) &IntPolyh_SectionLine::operator[], py::is_operator(), "None", py::arg("nn"));
	cls_IntPolyh_SectionLine.def("Copy", (IntPolyh_SectionLine & (IntPolyh_SectionLine::*)(const IntPolyh_SectionLine &)) &IntPolyh_SectionLine::Copy, "None", py::arg("Other"));
	cls_IntPolyh_SectionLine.def("assign", (IntPolyh_SectionLine & (IntPolyh_SectionLine::*)(const IntPolyh_SectionLine &)) &IntPolyh_SectionLine::operator=, py::is_operator(), "None", py::arg("Other"));
	cls_IntPolyh_SectionLine.def("GetN", (Standard_Integer (IntPolyh_SectionLine::*)() const ) &IntPolyh_SectionLine::GetN, "None");
	cls_IntPolyh_SectionLine.def("NbStartPoints", (Standard_Integer (IntPolyh_SectionLine::*)() const ) &IntPolyh_SectionLine::NbStartPoints, "None");
	cls_IntPolyh_SectionLine.def("IncrementNbStartPoints", (void (IntPolyh_SectionLine::*)()) &IntPolyh_SectionLine::IncrementNbStartPoints, "None");
	cls_IntPolyh_SectionLine.def("Destroy", (void (IntPolyh_SectionLine::*)()) &IntPolyh_SectionLine::Destroy, "None");
	// FIXME cls_IntPolyh_SectionLine.def("Dump", (void (IntPolyh_SectionLine::*)() const ) &IntPolyh_SectionLine::Dump, "None");
	cls_IntPolyh_SectionLine.def("Prepend", (void (IntPolyh_SectionLine::*)(const IntPolyh_StartPoint &)) &IntPolyh_SectionLine::Prepend, "None", py::arg("SP"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntPolyh_Couple.hxx
	py::class_<IntPolyh_Couple, std::unique_ptr<IntPolyh_Couple, Deleter<IntPolyh_Couple>>> cls_IntPolyh_Couple(mod, "IntPolyh_Couple", "The class represents the couple of indices with additional characteristics such as analyzed flag and an angle. In IntPolyh_MaillageAffinage algorithm the class is used as a couple of interfering triangles with the intersection angle.");
	cls_IntPolyh_Couple.def(py::init<>());
	cls_IntPolyh_Couple.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theTriangle1"), py::arg("theTriangle2"));
	cls_IntPolyh_Couple.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Real>(), py::arg("theTriangle1"), py::arg("theTriangle2"), py::arg("theAngle"));
	cls_IntPolyh_Couple.def("FirstValue", (Standard_Integer (IntPolyh_Couple::*)() const ) &IntPolyh_Couple::FirstValue, "Returns the first index");
	cls_IntPolyh_Couple.def("SecondValue", (Standard_Integer (IntPolyh_Couple::*)() const ) &IntPolyh_Couple::SecondValue, "Returns the second index");
	cls_IntPolyh_Couple.def("IsAnalyzed", (Standard_Boolean (IntPolyh_Couple::*)() const ) &IntPolyh_Couple::IsAnalyzed, "Returns TRUE if the couple has been analyzed");
	cls_IntPolyh_Couple.def("Angle", (Standard_Real (IntPolyh_Couple::*)() const ) &IntPolyh_Couple::Angle, "Returns the angle");
	cls_IntPolyh_Couple.def("SetCoupleValue", (void (IntPolyh_Couple::*)(const Standard_Integer, const Standard_Integer)) &IntPolyh_Couple::SetCoupleValue, "Sets the triangles", py::arg("theInd1"), py::arg("theInd2"));
	cls_IntPolyh_Couple.def("SetAnalyzed", (void (IntPolyh_Couple::*)(const Standard_Boolean)) &IntPolyh_Couple::SetAnalyzed, "Sets the analyzed flag", py::arg("theAnalyzed"));
	cls_IntPolyh_Couple.def("SetAngle", (void (IntPolyh_Couple::*)(const Standard_Real)) &IntPolyh_Couple::SetAngle, "Sets the angle", py::arg("theAngle"));
	cls_IntPolyh_Couple.def("IsEqual", (Standard_Boolean (IntPolyh_Couple::*)(const IntPolyh_Couple &) const ) &IntPolyh_Couple::IsEqual, "Returns true if the Couple is equal to <theOther>", py::arg("theOther"));
	cls_IntPolyh_Couple.def("HashCode", (Standard_Integer (IntPolyh_Couple::*)(const Standard_Integer) const ) &IntPolyh_Couple::HashCode, "Returns hash code", py::arg("theUpper"));
	// FIXME cls_IntPolyh_Couple.def("Dump", (void (IntPolyh_Couple::*)(const Standard_Integer) const ) &IntPolyh_Couple::Dump, "None", py::arg("v"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntPolyh_CoupleMapHasher.hxx
	py::class_<IntPolyh_CoupleMapHasher, std::unique_ptr<IntPolyh_CoupleMapHasher, Deleter<IntPolyh_CoupleMapHasher>>> cls_IntPolyh_CoupleMapHasher(mod, "IntPolyh_CoupleMapHasher", "None");
	cls_IntPolyh_CoupleMapHasher.def(py::init<>());
	cls_IntPolyh_CoupleMapHasher.def_static("HashCode_", (Standard_Integer (*)(const IntPolyh_Couple &, const Standard_Integer)) &IntPolyh_CoupleMapHasher::HashCode, "None", py::arg("theCouple"), py::arg("Upper"));
	cls_IntPolyh_CoupleMapHasher.def_static("IsEqual_", (Standard_Boolean (*)(const IntPolyh_Couple &, const IntPolyh_Couple &)) &IntPolyh_CoupleMapHasher::IsEqual, "None", py::arg("theCouple1"), py::arg("theCouple2"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntPolyh_MaillageAffinage.hxx
	py::class_<IntPolyh_MaillageAffinage, std::unique_ptr<IntPolyh_MaillageAffinage, Deleter<IntPolyh_MaillageAffinage>>> cls_IntPolyh_MaillageAffinage(mod, "IntPolyh_MaillageAffinage", "Provide the algorythms used in the package");
	cls_IntPolyh_MaillageAffinage.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Integer, const Standard_Integer, const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("S1"), py::arg("NbSU1"), py::arg("NbSV1"), py::arg("S2"), py::arg("NbSU2"), py::arg("NbSV2"), py::arg("PRINT"));
	cls_IntPolyh_MaillageAffinage.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Integer>(), py::arg("S1"), py::arg("S2"), py::arg("PRINT"));
	cls_IntPolyh_MaillageAffinage.def("FillArrayOfPnt", (void (IntPolyh_MaillageAffinage::*)(const Standard_Integer)) &IntPolyh_MaillageAffinage::FillArrayOfPnt, "Compute points on one surface and fill an array of points; standard (default) method", py::arg("SurfID"));
	cls_IntPolyh_MaillageAffinage.def("FillArrayOfPnt", (void (IntPolyh_MaillageAffinage::*)(const Standard_Integer, const Standard_Boolean)) &IntPolyh_MaillageAffinage::FillArrayOfPnt, "isShiftFwd flag is added. The purpose is to define shift of points along normal to the surface in this point. The shift length represents maximal deflection of triangulation. The direction (forward or reversed regarding to normal direction) is defined by isShiftFwd flag. Compute points on one surface and fill an array of points; advanced method", py::arg("SurfID"), py::arg("isShiftFwd"));
	cls_IntPolyh_MaillageAffinage.def("FillArrayOfPnt", (void (IntPolyh_MaillageAffinage::*)(const Standard_Integer, const TColStd_Array1OfReal &, const TColStd_Array1OfReal &)) &IntPolyh_MaillageAffinage::FillArrayOfPnt, "Compute points on one surface and fill an array of points; standard (default) method", py::arg("SurfID"), py::arg("Upars"), py::arg("Vpars"));
	cls_IntPolyh_MaillageAffinage.def("FillArrayOfPnt", (void (IntPolyh_MaillageAffinage::*)(const Standard_Integer, const Standard_Boolean, const TColStd_Array1OfReal &, const TColStd_Array1OfReal &)) &IntPolyh_MaillageAffinage::FillArrayOfPnt, "isShiftFwd flag is added. The purpose is to define shift of points along normal to the surface in this point. The shift length represents maximal deflection of triangulation. The direction (forward or reversed regarding to normal direction) is defined by isShiftFwd flag. Compute points on one surface and fill an array of points; advanced method", py::arg("SurfID"), py::arg("isShiftFwd"), py::arg("Upars"), py::arg("Vpars"));
	cls_IntPolyh_MaillageAffinage.def("CommonBox", [](IntPolyh_MaillageAffinage &self, const Bnd_Box & B1, const Bnd_Box & B2, Standard_Real & xMin, Standard_Real & yMin, Standard_Real & zMin, Standard_Real & xMax, Standard_Real & yMax, Standard_Real & zMax){ self.CommonBox(B1, B2, xMin, yMin, zMin, xMax, yMax, zMax); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(xMin, yMin, zMin, xMax, yMax, zMax); }, "Compute the common box witch is the intersection of the two bounding boxes, and mark the points of the two surfaces that are inside.", py::arg("B1"), py::arg("B2"), py::arg("xMin"), py::arg("yMin"), py::arg("zMin"), py::arg("xMax"), py::arg("yMax"), py::arg("zMax"));
	cls_IntPolyh_MaillageAffinage.def("FillArrayOfEdges", (void (IntPolyh_MaillageAffinage::*)(const Standard_Integer)) &IntPolyh_MaillageAffinage::FillArrayOfEdges, "Compute edges from the array of points", py::arg("SurfID"));
	cls_IntPolyh_MaillageAffinage.def("FillArrayOfTriangles", (void (IntPolyh_MaillageAffinage::*)(const Standard_Integer)) &IntPolyh_MaillageAffinage::FillArrayOfTriangles, "Compute triangles from the array of points, and -- mark the triangles that use marked points by the CommonBox function.", py::arg("SurfID"));
	cls_IntPolyh_MaillageAffinage.def("CommonPartRefinement", (void (IntPolyh_MaillageAffinage::*)()) &IntPolyh_MaillageAffinage::CommonPartRefinement, "Refine systematicaly all marked triangles of both surfaces");
	cls_IntPolyh_MaillageAffinage.def("LocalSurfaceRefinement", (void (IntPolyh_MaillageAffinage::*)(const Standard_Integer)) &IntPolyh_MaillageAffinage::LocalSurfaceRefinement, "Refine systematicaly all marked triangles of ONE surface", py::arg("SurfId"));
	cls_IntPolyh_MaillageAffinage.def("ComputeDeflections", (void (IntPolyh_MaillageAffinage::*)(const Standard_Integer)) &IntPolyh_MaillageAffinage::ComputeDeflections, "Compute deflection for all triangles of one surface,and sort min and max of deflections", py::arg("SurfID"));
	cls_IntPolyh_MaillageAffinage.def("TrianglesDeflectionsRefinementBSB", (void (IntPolyh_MaillageAffinage::*)()) &IntPolyh_MaillageAffinage::TrianglesDeflectionsRefinementBSB, "Refine both surfaces using BoundSortBox as -- rejection. The criterions used to refine a -- triangle are: The deflection The size of the -- bounding boxes (one surface may be very small compared to the other)");
	cls_IntPolyh_MaillageAffinage.def("TriContact", [](IntPolyh_MaillageAffinage &self, const IntPolyh_Point & P1, const IntPolyh_Point & P2, const IntPolyh_Point & P3, const IntPolyh_Point & Q1, const IntPolyh_Point & Q2, const IntPolyh_Point & Q3, Standard_Real & Angle){ Standard_Integer rv = self.TriContact(P1, P2, P3, Q1, Q2, Q3, Angle); return std::tuple<Standard_Integer, Standard_Real &>(rv, Angle); }, "This fonction Check if two triangles are in contact or no, return 1 if yes, return 0 if no.", py::arg("P1"), py::arg("P2"), py::arg("P3"), py::arg("Q1"), py::arg("Q2"), py::arg("Q3"), py::arg("Angle"));
	cls_IntPolyh_MaillageAffinage.def("TriangleEdgeContact", (Standard_Integer (IntPolyh_MaillageAffinage::*)(const Standard_Integer, const Standard_Integer, const IntPolyh_Triangle &, const IntPolyh_Triangle &, const IntPolyh_Point &, const IntPolyh_Point &, const IntPolyh_Point &, const IntPolyh_Point &, const IntPolyh_Point &, const IntPolyh_Point &, const IntPolyh_Point &, const IntPolyh_Point &, const IntPolyh_Point &, const IntPolyh_Point &, IntPolyh_StartPoint &, IntPolyh_StartPoint &) const ) &IntPolyh_MaillageAffinage::TriangleEdgeContact, "None", py::arg("TriSurfID"), py::arg("EdgeIndice"), py::arg("Tri1"), py::arg("Tri2"), py::arg("P1"), py::arg("P2"), py::arg("P3"), py::arg("C1"), py::arg("C2"), py::arg("C3"), py::arg("Pe1"), py::arg("Pe2"), py::arg("E"), py::arg("N"), py::arg("SP1"), py::arg("SP2"));
	cls_IntPolyh_MaillageAffinage.def("StartingPointsResearch", (Standard_Integer (IntPolyh_MaillageAffinage::*)(const Standard_Integer, const Standard_Integer, IntPolyh_StartPoint &, IntPolyh_StartPoint &) const ) &IntPolyh_MaillageAffinage::StartingPointsResearch, "From two triangles compute intersection points. If I found more than two intersection points that's mean that those triangle are coplanar", py::arg("T1"), py::arg("T2"), py::arg("SP1"), py::arg("SP2"));
	cls_IntPolyh_MaillageAffinage.def("NextStartingPointsResearch", (Standard_Integer (IntPolyh_MaillageAffinage::*)(const Standard_Integer, const Standard_Integer, const IntPolyh_StartPoint &, IntPolyh_StartPoint &) const ) &IntPolyh_MaillageAffinage::NextStartingPointsResearch, "from two triangles and an intersection point I seach the other point (if it exist). This function is used by StartPointChain", py::arg("T1"), py::arg("T2"), py::arg("SPInit"), py::arg("SPNext"));
	cls_IntPolyh_MaillageAffinage.def("TriangleCompare", (Standard_Integer (IntPolyh_MaillageAffinage::*)()) &IntPolyh_MaillageAffinage::TriangleCompare, "Analyse each couple of triangles from the two -- array of triangles, to see if they are in contact, and compute the incidence. Then put couples in contact in the array of couples");
	cls_IntPolyh_MaillageAffinage.def("StartPointsChain", (Standard_Integer (IntPolyh_MaillageAffinage::*)(IntPolyh_ArrayOfSectionLines &, IntPolyh_ArrayOfTangentZones &)) &IntPolyh_MaillageAffinage::StartPointsChain, "Loop on the array of couples. Compute StartPoints. Try to chain the StartPoints into SectionLines or put the point in the ArrayOfTangentZones if chaining it, is not possible.", py::arg("TSectionLines"), py::arg("TTangentZones"));
	cls_IntPolyh_MaillageAffinage.def("GetNextChainStartPoint", [](IntPolyh_MaillageAffinage &self, const IntPolyh_StartPoint & a0, IntPolyh_StartPoint & a1, IntPolyh_SectionLine & a2, IntPolyh_ArrayOfTangentZones & a3) -> Standard_Integer { return self.GetNextChainStartPoint(a0, a1, a2, a3); }, py::arg("SPInit"), py::arg("SPNext"), py::arg("MySectionLine"), py::arg("TTangentZones"));
	cls_IntPolyh_MaillageAffinage.def("GetNextChainStartPoint", (Standard_Integer (IntPolyh_MaillageAffinage::*)(const IntPolyh_StartPoint &, IntPolyh_StartPoint &, IntPolyh_SectionLine &, IntPolyh_ArrayOfTangentZones &, const Standard_Boolean)) &IntPolyh_MaillageAffinage::GetNextChainStartPoint, "Mainly used by StartPointsChain(), this function try to compute the next StartPoint.", py::arg("SPInit"), py::arg("SPNext"), py::arg("MySectionLine"), py::arg("TTangentZones"), py::arg("Prepend"));
	cls_IntPolyh_MaillageAffinage.def("GetArrayOfPoints", (const IntPolyh_ArrayOfPoints & (IntPolyh_MaillageAffinage::*)(const Standard_Integer) const ) &IntPolyh_MaillageAffinage::GetArrayOfPoints, "None", py::arg("SurfID"));
	cls_IntPolyh_MaillageAffinage.def("GetArrayOfEdges", (const IntPolyh_ArrayOfEdges & (IntPolyh_MaillageAffinage::*)(const Standard_Integer) const ) &IntPolyh_MaillageAffinage::GetArrayOfEdges, "None", py::arg("SurfID"));
	cls_IntPolyh_MaillageAffinage.def("GetArrayOfTriangles", (const IntPolyh_ArrayOfTriangles & (IntPolyh_MaillageAffinage::*)(const Standard_Integer) const ) &IntPolyh_MaillageAffinage::GetArrayOfTriangles, "None", py::arg("SurfID"));
	// cls_IntPolyh_MaillageAffinage.def("GetFinTE", (Standard_Integer (IntPolyh_MaillageAffinage::*)(const Standard_Integer) const ) &IntPolyh_MaillageAffinage::GetFinTE, "None", py::arg("SurfID"));
	// cls_IntPolyh_MaillageAffinage.def("GetFinTT", (Standard_Integer (IntPolyh_MaillageAffinage::*)(const Standard_Integer) const ) &IntPolyh_MaillageAffinage::GetFinTT, "None", py::arg("SurfID"));
	cls_IntPolyh_MaillageAffinage.def("GetBox", (Bnd_Box (IntPolyh_MaillageAffinage::*)(const Standard_Integer) const ) &IntPolyh_MaillageAffinage::GetBox, "None", py::arg("SurfID"));
	cls_IntPolyh_MaillageAffinage.def("GetCouples", (IntPolyh_ListOfCouples & (IntPolyh_MaillageAffinage::*)()) &IntPolyh_MaillageAffinage::GetCouples, "This method returns list of couples of contact triangles.");
	cls_IntPolyh_MaillageAffinage.def("SetEnlargeZone", [](IntPolyh_MaillageAffinage &self, Standard_Boolean & EnlargeZone){ self.SetEnlargeZone(EnlargeZone); return EnlargeZone; }, "None", py::arg("EnlargeZone"));
	cls_IntPolyh_MaillageAffinage.def("GetEnlargeZone", (Standard_Boolean (IntPolyh_MaillageAffinage::*)() const ) &IntPolyh_MaillageAffinage::GetEnlargeZone, "None");
	cls_IntPolyh_MaillageAffinage.def("GetMinDeflection", (Standard_Real (IntPolyh_MaillageAffinage::*)(const Standard_Integer) const ) &IntPolyh_MaillageAffinage::GetMinDeflection, "returns FlecheMin", py::arg("SurfID"));
	cls_IntPolyh_MaillageAffinage.def("GetMaxDeflection", (Standard_Real (IntPolyh_MaillageAffinage::*)(const Standard_Integer) const ) &IntPolyh_MaillageAffinage::GetMaxDeflection, "returns FlecheMax", py::arg("SurfID"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntPolyh_Intersection.hxx
	py::class_<IntPolyh_Intersection, std::unique_ptr<IntPolyh_Intersection, Deleter<IntPolyh_Intersection>>> cls_IntPolyh_Intersection(mod, "IntPolyh_Intersection", "the main algorithm. Algorithm outputs are lines and points like describe in the last paragraph. The Algorithm provides direct access to the elements of those lines and points. Other classes of this package are for internal use and only concern the algorithmic part.");
	cls_IntPolyh_Intersection.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &>(), py::arg("S1"), py::arg("S2"));
	cls_IntPolyh_Intersection.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Integer, const Standard_Integer, const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Integer, const Standard_Integer>(), py::arg("S1"), py::arg("NbSU1"), py::arg("NbSV1"), py::arg("S2"), py::arg("NbSU2"), py::arg("NbSV2"));
	cls_IntPolyh_Intersection.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const TColStd_Array1OfReal &, const TColStd_Array1OfReal &, const opencascade::handle<Adaptor3d_HSurface> &, const TColStd_Array1OfReal &, const TColStd_Array1OfReal &>(), py::arg("S1"), py::arg("anUpars1"), py::arg("aVpars1"), py::arg("S2"), py::arg("anUpars2"), py::arg("aVpars2"));
	cls_IntPolyh_Intersection.def("Perform", (void (IntPolyh_Intersection::*)()) &IntPolyh_Intersection::Perform, "Compute the intersection.");
	cls_IntPolyh_Intersection.def("Perform", (void (IntPolyh_Intersection::*)(const TColStd_Array1OfReal &, const TColStd_Array1OfReal &, const TColStd_Array1OfReal &, const TColStd_Array1OfReal &)) &IntPolyh_Intersection::Perform, "Compute the intersection.", py::arg("Upars1"), py::arg("Vpars1"), py::arg("Upars2"), py::arg("Vpars2"));
	cls_IntPolyh_Intersection.def("IsDone", (Standard_Boolean (IntPolyh_Intersection::*)() const ) &IntPolyh_Intersection::IsDone, "None");
	cls_IntPolyh_Intersection.def("NbSectionLines", (Standard_Integer (IntPolyh_Intersection::*)() const ) &IntPolyh_Intersection::NbSectionLines, "None");
	cls_IntPolyh_Intersection.def("NbPointsInLine", (Standard_Integer (IntPolyh_Intersection::*)(const Standard_Integer) const ) &IntPolyh_Intersection::NbPointsInLine, "None", py::arg("IndexLine"));
	cls_IntPolyh_Intersection.def("GetLinePoint", [](IntPolyh_Intersection &self, const Standard_Integer IndexLine, const Standard_Integer IndexPoint, Standard_Real & x, Standard_Real & y, Standard_Real & z, Standard_Real & u1, Standard_Real & v1, Standard_Real & u2, Standard_Real & v2, Standard_Real & incidence){ self.GetLinePoint(IndexLine, IndexPoint, x, y, z, u1, v1, u2, v2, incidence); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(x, y, z, u1, v1, u2, v2, incidence); }, "None", py::arg("IndexLine"), py::arg("IndexPoint"), py::arg("x"), py::arg("y"), py::arg("z"), py::arg("u1"), py::arg("v1"), py::arg("u2"), py::arg("v2"), py::arg("incidence"));
	cls_IntPolyh_Intersection.def("NbTangentZones", (Standard_Integer (IntPolyh_Intersection::*)() const ) &IntPolyh_Intersection::NbTangentZones, "None");
	cls_IntPolyh_Intersection.def("NbPointsInTangentZone", (Standard_Integer (IntPolyh_Intersection::*)(const Standard_Integer) const ) &IntPolyh_Intersection::NbPointsInTangentZone, "None", py::arg("IndexLine"));
	cls_IntPolyh_Intersection.def("GetTangentZonePoint", [](IntPolyh_Intersection &self, const Standard_Integer IndexLine, const Standard_Integer IndexPoint, Standard_Real & x, Standard_Real & y, Standard_Real & z, Standard_Real & u1, Standard_Real & v1, Standard_Real & u2, Standard_Real & v2){ self.GetTangentZonePoint(IndexLine, IndexPoint, x, y, z, u1, v1, u2, v2); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(x, y, z, u1, v1, u2, v2); }, "None", py::arg("IndexLine"), py::arg("IndexPoint"), py::arg("x"), py::arg("y"), py::arg("z"), py::arg("u1"), py::arg("v1"), py::arg("u2"), py::arg("v2"));

	/* FIXME
	// C:\Miniconda\envs\occt\Library\include\opencascade\IntPolyh_ArrayOfEdges.hxx
	bind_IntPolyh_Array<IntPolyh_Edge>(mod, "IntPolyh_ArrayOfEdges");

	*/

	/* FIXME
	// C:\Miniconda\envs\occt\Library\include\opencascade\IntPolyh_ArrayOfPoints.hxx
	bind_IntPolyh_Array<IntPolyh_Point>(mod, "IntPolyh_ArrayOfPoints");

	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntPolyh_SeqOfStartPoints.hxx
	bind_NCollection_Sequence<IntPolyh_StartPoint>(mod, "IntPolyh_SeqOfStartPoints");

	/* FIXME
	// C:\Miniconda\envs\occt\Library\include\opencascade\IntPolyh_ArrayOfSectionLines.hxx
	bind_IntPolyh_Array<IntPolyh_SectionLine>(mod, "IntPolyh_ArrayOfSectionLines");

	*/

	/* FIXME
	// C:\Miniconda\envs\occt\Library\include\opencascade\IntPolyh_ArrayOfTangentZones.hxx
	bind_IntPolyh_Array<IntPolyh_StartPoint>(mod, "IntPolyh_ArrayOfTangentZones");

	*/

	/* FIXME
	// C:\Miniconda\envs\occt\Library\include\opencascade\IntPolyh_ArrayOfTriangles.hxx
	bind_IntPolyh_Array<IntPolyh_Triangle>(mod, "IntPolyh_ArrayOfTriangles");

	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntPolyh_PMaillageAffinage.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\IntPolyh_ListOfCouples.hxx
	bind_NCollection_List<IntPolyh_Couple>(mod, "IntPolyh_ListOfCouples");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntPolyh_ListOfCouples.hxx

}
