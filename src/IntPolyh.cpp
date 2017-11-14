#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <Standard_TypeDef.hxx>
#include <IntPolyh_Edge.hxx>
#include <IntPolyh_Array.hxx>
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
	cls_IntPolyh_StartPoint.def("GetEdgePoints", (Standard_Integer (IntPolyh_StartPoint::*)(const IntPolyh_Triangle &, Standard_Integer &, Standard_Integer &, Standard_Integer &) const ) &IntPolyh_StartPoint::GetEdgePoints, "None", py::arg("Triangle"), py::arg("FirstEdgePoint"), py::arg("SecondEdgePoint"), py::arg("LastPoint"));
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
	cls_IntPolyh_MaillageAffinage.def("CommonBox", (void (IntPolyh_MaillageAffinage::*)(const Bnd_Box &, const Bnd_Box &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &)) &IntPolyh_MaillageAffinage::CommonBox, "Compute the common box witch is the intersection of the two bounding boxes, and mark the points of the two surfaces that are inside.", py::arg("B1"), py::arg("B2"), py::arg("xMin"), py::arg("yMin"), py::arg("zMin"), py::arg("xMax"), py::arg("yMax"), py::arg("zMax"));
	cls_IntPolyh_MaillageAffinage.def("FillArrayOfEdges", (void (IntPolyh_MaillageAffinage::*)(const Standard_Integer)) &IntPolyh_MaillageAffinage::FillArrayOfEdges, "Compute edges from the array of points", py::arg("SurfID"));
	cls_IntPolyh_MaillageAffinage.def("FillArrayOfTriangles", (void (IntPolyh_MaillageAffinage::*)(const Standard_Integer)) &IntPolyh_MaillageAffinage::FillArrayOfTriangles, "Compute triangles from the array of points, and -- mark the triangles that use marked points by the CommonBox function.", py::arg("SurfID"));
	cls_IntPolyh_MaillageAffinage.def("CommonPartRefinement", (void (IntPolyh_MaillageAffinage::*)()) &IntPolyh_MaillageAffinage::CommonPartRefinement, "Refine systematicaly all marked triangles of both surfaces");
	cls_IntPolyh_MaillageAffinage.def("LocalSurfaceRefinement", (void (IntPolyh_MaillageAffinage::*)(const Standard_Integer)) &IntPolyh_MaillageAffinage::LocalSurfaceRefinement, "Refine systematicaly all marked triangles of ONE surface", py::arg("SurfId"));
	cls_IntPolyh_MaillageAffinage.def("ComputeDeflections", (void (IntPolyh_MaillageAffinage::*)(const Standard_Integer)) &IntPolyh_MaillageAffinage::ComputeDeflections, "Compute deflection for all triangles of one surface,and sort min and max of deflections", py::arg("SurfID"));
	cls_IntPolyh_MaillageAffinage.def("TrianglesDeflectionsRefinementBSB", (void (IntPolyh_MaillageAffinage::*)()) &IntPolyh_MaillageAffinage::TrianglesDeflectionsRefinementBSB, "Refine both surfaces using BoundSortBox as -- rejection. The criterions used to refine a -- triangle are: The deflection The size of the -- bounding boxes (one surface may be very small compared to the other)");
	cls_IntPolyh_MaillageAffinage.def("TriContact", (Standard_Integer (IntPolyh_MaillageAffinage::*)(const IntPolyh_Point &, const IntPolyh_Point &, const IntPolyh_Point &, const IntPolyh_Point &, const IntPolyh_Point &, const IntPolyh_Point &, Standard_Real &) const ) &IntPolyh_MaillageAffinage::TriContact, "This fonction Check if two triangles are in contact or no, return 1 if yes, return 0 if no.", py::arg("P1"), py::arg("P2"), py::arg("P3"), py::arg("Q1"), py::arg("Q2"), py::arg("Q3"), py::arg("Angle"));
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
	cls_IntPolyh_MaillageAffinage.def("GetFinTE", (Standard_Integer (IntPolyh_MaillageAffinage::*)(const Standard_Integer) const ) &IntPolyh_MaillageAffinage::GetFinTE, "None", py::arg("SurfID"));
	cls_IntPolyh_MaillageAffinage.def("GetFinTT", (Standard_Integer (IntPolyh_MaillageAffinage::*)(const Standard_Integer) const ) &IntPolyh_MaillageAffinage::GetFinTT, "None", py::arg("SurfID"));
	cls_IntPolyh_MaillageAffinage.def("GetBox", (Bnd_Box (IntPolyh_MaillageAffinage::*)(const Standard_Integer) const ) &IntPolyh_MaillageAffinage::GetBox, "None", py::arg("SurfID"));
	cls_IntPolyh_MaillageAffinage.def("GetCouples", (IntPolyh_ListOfCouples & (IntPolyh_MaillageAffinage::*)()) &IntPolyh_MaillageAffinage::GetCouples, "This method returns list of couples of contact triangles.");
	cls_IntPolyh_MaillageAffinage.def("SetEnlargeZone", (void (IntPolyh_MaillageAffinage::*)(Standard_Boolean &)) &IntPolyh_MaillageAffinage::SetEnlargeZone, "None", py::arg("EnlargeZone"));
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
	cls_IntPolyh_Intersection.def("GetLinePoint", (void (IntPolyh_Intersection::*)(const Standard_Integer, const Standard_Integer, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &) const ) &IntPolyh_Intersection::GetLinePoint, "None", py::arg("IndexLine"), py::arg("IndexPoint"), py::arg("x"), py::arg("y"), py::arg("z"), py::arg("u1"), py::arg("v1"), py::arg("u2"), py::arg("v2"), py::arg("incidence"));
	cls_IntPolyh_Intersection.def("NbTangentZones", (Standard_Integer (IntPolyh_Intersection::*)() const ) &IntPolyh_Intersection::NbTangentZones, "None");
	cls_IntPolyh_Intersection.def("NbPointsInTangentZone", (Standard_Integer (IntPolyh_Intersection::*)(const Standard_Integer) const ) &IntPolyh_Intersection::NbPointsInTangentZone, "None", py::arg("IndexLine"));
	cls_IntPolyh_Intersection.def("GetTangentZonePoint", (void (IntPolyh_Intersection::*)(const Standard_Integer, const Standard_Integer, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &) const ) &IntPolyh_Intersection::GetTangentZonePoint, "None", py::arg("IndexLine"), py::arg("IndexPoint"), py::arg("x"), py::arg("y"), py::arg("z"), py::arg("u1"), py::arg("v1"), py::arg("u2"), py::arg("v2"));

	/* FIXME
	// C:\Miniconda\envs\occt\Library\include\opencascade\IntPolyh_Array.hxx
	py::class_<IntPolyh_ArrayOfEdges, std::unique_ptr<IntPolyh_ArrayOfEdges, Deleter<IntPolyh_ArrayOfEdges>>> cls_IntPolyh_ArrayOfEdges(mod, "IntPolyh_ArrayOfEdges", "Class IntPolyh_Array (dynamic array of objects)");
	cls_IntPolyh_ArrayOfEdges.def(py::init<>());
	cls_IntPolyh_ArrayOfEdges.def(py::init<const Standard_Integer>(), py::arg("aIncrement"));
	cls_IntPolyh_ArrayOfEdges.def(py::init<const Standard_Integer>(), py::arg("aN"));
	cls_IntPolyh_ArrayOfEdges.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("aN"), py::arg("aIncrement"));
	cls_IntPolyh_ArrayOfEdges.def("assign", (IntPolyh_ArrayOfEdges & (IntPolyh_ArrayOfEdges::*)(const IntPolyh_ArrayOfEdges &)) &IntPolyh_ArrayOfEdges::operator=, py::is_operator(), "Assignment operator", py::arg("aOther"));
	cls_IntPolyh_ArrayOfEdges.def("Copy", (IntPolyh_ArrayOfEdges & (IntPolyh_ArrayOfEdges::*)(const IntPolyh_ArrayOfEdges &)) &IntPolyh_ArrayOfEdges::Copy, "Copy", py::arg("aOther"));
	cls_IntPolyh_ArrayOfEdges.def("Init", (void (IntPolyh_ArrayOfEdges::*)(const Standard_Integer)) &IntPolyh_ArrayOfEdges::Init, "Init - allocate memory for <aN> items", py::arg("aN"));
	cls_IntPolyh_ArrayOfEdges.def("IncrementNbItems", (void (IntPolyh_ArrayOfEdges::*)()) &IntPolyh_ArrayOfEdges::IncrementNbItems, "IncrementNbItems - increment the number of stored items");
	cls_IntPolyh_ArrayOfEdges.def("GetN", (Standard_Integer (IntPolyh_ArrayOfEdges::*)() const ) &IntPolyh_ArrayOfEdges::GetN, "GetN - returns the number of 'allocated' items");
	cls_IntPolyh_ArrayOfEdges.def("NbItems", (Standard_Integer (IntPolyh_ArrayOfEdges::*)() const ) &IntPolyh_ArrayOfEdges::NbItems, "NbItems - returns the number of stored items");
	cls_IntPolyh_ArrayOfEdges.def("SetNbItems", (void (IntPolyh_ArrayOfEdges::*)(const Standard_Integer)) &IntPolyh_ArrayOfEdges::SetNbItems, "set the number of stored items", py::arg("aNb"));
	cls_IntPolyh_ArrayOfEdges.def("Value", (const IntPolyh_Edge & (IntPolyh_ArrayOfEdges::*)(const Standard_Integer) const ) &IntPolyh_ArrayOfEdges::Value, "query the const value", py::arg("aIndex"));
	cls_IntPolyh_ArrayOfEdges.def("__getitem__", (const IntPolyh_Edge & (IntPolyh_ArrayOfEdges::*)(const Standard_Integer) const ) &IntPolyh_ArrayOfEdges::operator[], py::is_operator(), "query the const value", py::arg("aIndex"));
	cls_IntPolyh_ArrayOfEdges.def("ChangeValue", (IntPolyh_Edge & (IntPolyh_ArrayOfEdges::*)(const Standard_Integer)) &IntPolyh_ArrayOfEdges::ChangeValue, "query the value", py::arg("aIndex"));
	cls_IntPolyh_ArrayOfEdges.def("__getitem__", (IntPolyh_Edge & (IntPolyh_ArrayOfEdges::*)(const Standard_Integer)) &IntPolyh_ArrayOfEdges::operator[], py::is_operator(), "query the value", py::arg("aIndex"));
	// FIXME cls_IntPolyh_ArrayOfEdges.def("Dump", (void (IntPolyh_ArrayOfEdges::*)() const ) &IntPolyh_ArrayOfEdges::Dump, "dump the contents");

	*/

	/* FIXME
	// C:\Miniconda\envs\occt\Library\include\opencascade\IntPolyh_Array.hxx
	py::class_<IntPolyh_ArrayOfPoints, std::unique_ptr<IntPolyh_ArrayOfPoints, Deleter<IntPolyh_ArrayOfPoints>>> cls_IntPolyh_ArrayOfPoints(mod, "IntPolyh_ArrayOfPoints", "Class IntPolyh_Array (dynamic array of objects)");
	cls_IntPolyh_ArrayOfPoints.def(py::init<>());
	cls_IntPolyh_ArrayOfPoints.def(py::init<const Standard_Integer>(), py::arg("aIncrement"));
	cls_IntPolyh_ArrayOfPoints.def(py::init<const Standard_Integer>(), py::arg("aN"));
	cls_IntPolyh_ArrayOfPoints.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("aN"), py::arg("aIncrement"));
	cls_IntPolyh_ArrayOfPoints.def("assign", (IntPolyh_ArrayOfPoints & (IntPolyh_ArrayOfPoints::*)(const IntPolyh_ArrayOfPoints &)) &IntPolyh_ArrayOfPoints::operator=, py::is_operator(), "Assignment operator", py::arg("aOther"));
	cls_IntPolyh_ArrayOfPoints.def("Copy", (IntPolyh_ArrayOfPoints & (IntPolyh_ArrayOfPoints::*)(const IntPolyh_ArrayOfPoints &)) &IntPolyh_ArrayOfPoints::Copy, "Copy", py::arg("aOther"));
	cls_IntPolyh_ArrayOfPoints.def("Init", (void (IntPolyh_ArrayOfPoints::*)(const Standard_Integer)) &IntPolyh_ArrayOfPoints::Init, "Init - allocate memory for <aN> items", py::arg("aN"));
	cls_IntPolyh_ArrayOfPoints.def("IncrementNbItems", (void (IntPolyh_ArrayOfPoints::*)()) &IntPolyh_ArrayOfPoints::IncrementNbItems, "IncrementNbItems - increment the number of stored items");
	cls_IntPolyh_ArrayOfPoints.def("GetN", (Standard_Integer (IntPolyh_ArrayOfPoints::*)() const ) &IntPolyh_ArrayOfPoints::GetN, "GetN - returns the number of 'allocated' items");
	cls_IntPolyh_ArrayOfPoints.def("NbItems", (Standard_Integer (IntPolyh_ArrayOfPoints::*)() const ) &IntPolyh_ArrayOfPoints::NbItems, "NbItems - returns the number of stored items");
	cls_IntPolyh_ArrayOfPoints.def("SetNbItems", (void (IntPolyh_ArrayOfPoints::*)(const Standard_Integer)) &IntPolyh_ArrayOfPoints::SetNbItems, "set the number of stored items", py::arg("aNb"));
	cls_IntPolyh_ArrayOfPoints.def("Value", (const IntPolyh_Point & (IntPolyh_ArrayOfPoints::*)(const Standard_Integer) const ) &IntPolyh_ArrayOfPoints::Value, "query the const value", py::arg("aIndex"));
	cls_IntPolyh_ArrayOfPoints.def("__getitem__", (const IntPolyh_Point & (IntPolyh_ArrayOfPoints::*)(const Standard_Integer) const ) &IntPolyh_ArrayOfPoints::operator[], py::is_operator(), "query the const value", py::arg("aIndex"));
	cls_IntPolyh_ArrayOfPoints.def("ChangeValue", (IntPolyh_Point & (IntPolyh_ArrayOfPoints::*)(const Standard_Integer)) &IntPolyh_ArrayOfPoints::ChangeValue, "query the value", py::arg("aIndex"));
	cls_IntPolyh_ArrayOfPoints.def("__getitem__", (IntPolyh_Point & (IntPolyh_ArrayOfPoints::*)(const Standard_Integer)) &IntPolyh_ArrayOfPoints::operator[], py::is_operator(), "query the value", py::arg("aIndex"));
	// FIXME cls_IntPolyh_ArrayOfPoints.def("Dump", (void (IntPolyh_ArrayOfPoints::*)() const ) &IntPolyh_ArrayOfPoints::Dump, "dump the contents");

	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
	py::class_<IntPolyh_SeqOfStartPoints, std::unique_ptr<IntPolyh_SeqOfStartPoints, Deleter<IntPolyh_SeqOfStartPoints>>, NCollection_BaseSequence> cls_IntPolyh_SeqOfStartPoints(mod, "IntPolyh_SeqOfStartPoints", "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n");
	cls_IntPolyh_SeqOfStartPoints.def(py::init<>());
	cls_IntPolyh_SeqOfStartPoints.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_IntPolyh_SeqOfStartPoints.def(py::init([] (const IntPolyh_SeqOfStartPoints &other) {return new IntPolyh_SeqOfStartPoints(other);}), "Copy constructor", py::arg("other"));
	cls_IntPolyh_SeqOfStartPoints.def("begin", (IntPolyh_SeqOfStartPoints::iterator (IntPolyh_SeqOfStartPoints::*)() const ) &IntPolyh_SeqOfStartPoints::begin, "Returns an iterator pointing to the first element in the sequence.");
	cls_IntPolyh_SeqOfStartPoints.def("end", (IntPolyh_SeqOfStartPoints::iterator (IntPolyh_SeqOfStartPoints::*)() const ) &IntPolyh_SeqOfStartPoints::end, "Returns an iterator referring to the past-the-end element in the sequence.");
	cls_IntPolyh_SeqOfStartPoints.def("cbegin", (IntPolyh_SeqOfStartPoints::const_iterator (IntPolyh_SeqOfStartPoints::*)() const ) &IntPolyh_SeqOfStartPoints::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
	cls_IntPolyh_SeqOfStartPoints.def("cend", (IntPolyh_SeqOfStartPoints::const_iterator (IntPolyh_SeqOfStartPoints::*)() const ) &IntPolyh_SeqOfStartPoints::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
	cls_IntPolyh_SeqOfStartPoints.def("Size", (Standard_Integer (IntPolyh_SeqOfStartPoints::*)() const ) &IntPolyh_SeqOfStartPoints::Size, "Number of items");
	cls_IntPolyh_SeqOfStartPoints.def("Length", (Standard_Integer (IntPolyh_SeqOfStartPoints::*)() const ) &IntPolyh_SeqOfStartPoints::Length, "Number of items");
	cls_IntPolyh_SeqOfStartPoints.def("Lower", (Standard_Integer (IntPolyh_SeqOfStartPoints::*)() const ) &IntPolyh_SeqOfStartPoints::Lower, "Method for consistency with other collections.");
	cls_IntPolyh_SeqOfStartPoints.def("Upper", (Standard_Integer (IntPolyh_SeqOfStartPoints::*)() const ) &IntPolyh_SeqOfStartPoints::Upper, "Method for consistency with other collections.");
	cls_IntPolyh_SeqOfStartPoints.def("IsEmpty", (Standard_Boolean (IntPolyh_SeqOfStartPoints::*)() const ) &IntPolyh_SeqOfStartPoints::IsEmpty, "Empty query");
	cls_IntPolyh_SeqOfStartPoints.def("Reverse", (void (IntPolyh_SeqOfStartPoints::*)()) &IntPolyh_SeqOfStartPoints::Reverse, "Reverse sequence");
	cls_IntPolyh_SeqOfStartPoints.def("Exchange", (void (IntPolyh_SeqOfStartPoints::*)(const Standard_Integer, const Standard_Integer)) &IntPolyh_SeqOfStartPoints::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
	cls_IntPolyh_SeqOfStartPoints.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &IntPolyh_SeqOfStartPoints::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
	cls_IntPolyh_SeqOfStartPoints.def("Clear", [](IntPolyh_SeqOfStartPoints &self) -> void { return self.Clear(); });
	cls_IntPolyh_SeqOfStartPoints.def("Clear", (void (IntPolyh_SeqOfStartPoints::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &IntPolyh_SeqOfStartPoints::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
	cls_IntPolyh_SeqOfStartPoints.def("Assign", (IntPolyh_SeqOfStartPoints & (IntPolyh_SeqOfStartPoints::*)(const IntPolyh_SeqOfStartPoints &)) &IntPolyh_SeqOfStartPoints::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
	cls_IntPolyh_SeqOfStartPoints.def("assign", (IntPolyh_SeqOfStartPoints & (IntPolyh_SeqOfStartPoints::*)(const IntPolyh_SeqOfStartPoints &)) &IntPolyh_SeqOfStartPoints::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_IntPolyh_SeqOfStartPoints.def("Remove", (void (IntPolyh_SeqOfStartPoints::*)(IntPolyh_SeqOfStartPoints::Iterator &)) &IntPolyh_SeqOfStartPoints::Remove, "Remove one item", py::arg("thePosition"));
	cls_IntPolyh_SeqOfStartPoints.def("Remove", (void (IntPolyh_SeqOfStartPoints::*)(const Standard_Integer)) &IntPolyh_SeqOfStartPoints::Remove, "Remove one item", py::arg("theIndex"));
	cls_IntPolyh_SeqOfStartPoints.def("Remove", (void (IntPolyh_SeqOfStartPoints::*)(const Standard_Integer, const Standard_Integer)) &IntPolyh_SeqOfStartPoints::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
	cls_IntPolyh_SeqOfStartPoints.def("Append", (void (IntPolyh_SeqOfStartPoints::*)(const IntPolyh_StartPoint &)) &IntPolyh_SeqOfStartPoints::Append, "Append one item", py::arg("theItem"));
	cls_IntPolyh_SeqOfStartPoints.def("Append", (void (IntPolyh_SeqOfStartPoints::*)(IntPolyh_SeqOfStartPoints &)) &IntPolyh_SeqOfStartPoints::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
	cls_IntPolyh_SeqOfStartPoints.def("Prepend", (void (IntPolyh_SeqOfStartPoints::*)(const IntPolyh_StartPoint &)) &IntPolyh_SeqOfStartPoints::Prepend, "Prepend one item", py::arg("theItem"));
	cls_IntPolyh_SeqOfStartPoints.def("Prepend", (void (IntPolyh_SeqOfStartPoints::*)(IntPolyh_SeqOfStartPoints &)) &IntPolyh_SeqOfStartPoints::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
	cls_IntPolyh_SeqOfStartPoints.def("InsertBefore", (void (IntPolyh_SeqOfStartPoints::*)(const Standard_Integer, const IntPolyh_StartPoint &)) &IntPolyh_SeqOfStartPoints::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
	cls_IntPolyh_SeqOfStartPoints.def("InsertBefore", (void (IntPolyh_SeqOfStartPoints::*)(const Standard_Integer, IntPolyh_SeqOfStartPoints &)) &IntPolyh_SeqOfStartPoints::InsertBefore, "InsertBefore theIndex another sequence", py::arg("theIndex"), py::arg("theSeq"));
	cls_IntPolyh_SeqOfStartPoints.def("InsertAfter", (void (IntPolyh_SeqOfStartPoints::*)(IntPolyh_SeqOfStartPoints::Iterator &, const IntPolyh_StartPoint &)) &IntPolyh_SeqOfStartPoints::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
	cls_IntPolyh_SeqOfStartPoints.def("InsertAfter", (void (IntPolyh_SeqOfStartPoints::*)(const Standard_Integer, IntPolyh_SeqOfStartPoints &)) &IntPolyh_SeqOfStartPoints::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theSeq"));
	cls_IntPolyh_SeqOfStartPoints.def("InsertAfter", (void (IntPolyh_SeqOfStartPoints::*)(const Standard_Integer, const IntPolyh_StartPoint &)) &IntPolyh_SeqOfStartPoints::InsertAfter, "InsertAfter theIndex another sequence", py::arg("theIndex"), py::arg("theItem"));
	cls_IntPolyh_SeqOfStartPoints.def("Split", (void (IntPolyh_SeqOfStartPoints::*)(const Standard_Integer, IntPolyh_SeqOfStartPoints &)) &IntPolyh_SeqOfStartPoints::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
	cls_IntPolyh_SeqOfStartPoints.def("First", (const IntPolyh_StartPoint & (IntPolyh_SeqOfStartPoints::*)() const ) &IntPolyh_SeqOfStartPoints::First, "First item access");
	cls_IntPolyh_SeqOfStartPoints.def("ChangeFirst", (IntPolyh_StartPoint & (IntPolyh_SeqOfStartPoints::*)()) &IntPolyh_SeqOfStartPoints::ChangeFirst, "First item access");
	cls_IntPolyh_SeqOfStartPoints.def("Last", (const IntPolyh_StartPoint & (IntPolyh_SeqOfStartPoints::*)() const ) &IntPolyh_SeqOfStartPoints::Last, "Last item access");
	cls_IntPolyh_SeqOfStartPoints.def("ChangeLast", (IntPolyh_StartPoint & (IntPolyh_SeqOfStartPoints::*)()) &IntPolyh_SeqOfStartPoints::ChangeLast, "Last item access");
	cls_IntPolyh_SeqOfStartPoints.def("Value", (const IntPolyh_StartPoint & (IntPolyh_SeqOfStartPoints::*)(const Standard_Integer) const ) &IntPolyh_SeqOfStartPoints::Value, "Constant item access by theIndex", py::arg("theIndex"));
	cls_IntPolyh_SeqOfStartPoints.def("__call__", (const IntPolyh_StartPoint & (IntPolyh_SeqOfStartPoints::*)(const Standard_Integer) const ) &IntPolyh_SeqOfStartPoints::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
	cls_IntPolyh_SeqOfStartPoints.def("ChangeValue", (IntPolyh_StartPoint & (IntPolyh_SeqOfStartPoints::*)(const Standard_Integer)) &IntPolyh_SeqOfStartPoints::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
	cls_IntPolyh_SeqOfStartPoints.def("__call__", (IntPolyh_StartPoint & (IntPolyh_SeqOfStartPoints::*)(const Standard_Integer)) &IntPolyh_SeqOfStartPoints::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
	cls_IntPolyh_SeqOfStartPoints.def("SetValue", (void (IntPolyh_SeqOfStartPoints::*)(const Standard_Integer, const IntPolyh_StartPoint &)) &IntPolyh_SeqOfStartPoints::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
	cls_IntPolyh_SeqOfStartPoints.def("__iter__", [](const IntPolyh_SeqOfStartPoints &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	/* FIXME
	// C:\Miniconda\envs\occt\Library\include\opencascade\IntPolyh_Array.hxx
	py::class_<IntPolyh_ArrayOfSectionLines, std::unique_ptr<IntPolyh_ArrayOfSectionLines, Deleter<IntPolyh_ArrayOfSectionLines>>> cls_IntPolyh_ArrayOfSectionLines(mod, "IntPolyh_ArrayOfSectionLines", "Class IntPolyh_Array (dynamic array of objects)");
	cls_IntPolyh_ArrayOfSectionLines.def(py::init<>());
	cls_IntPolyh_ArrayOfSectionLines.def(py::init<const Standard_Integer>(), py::arg("aIncrement"));
	cls_IntPolyh_ArrayOfSectionLines.def(py::init<const Standard_Integer>(), py::arg("aN"));
	cls_IntPolyh_ArrayOfSectionLines.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("aN"), py::arg("aIncrement"));
	cls_IntPolyh_ArrayOfSectionLines.def("assign", (IntPolyh_ArrayOfSectionLines & (IntPolyh_ArrayOfSectionLines::*)(const IntPolyh_ArrayOfSectionLines &)) &IntPolyh_ArrayOfSectionLines::operator=, py::is_operator(), "Assignment operator", py::arg("aOther"));
	cls_IntPolyh_ArrayOfSectionLines.def("Copy", (IntPolyh_ArrayOfSectionLines & (IntPolyh_ArrayOfSectionLines::*)(const IntPolyh_ArrayOfSectionLines &)) &IntPolyh_ArrayOfSectionLines::Copy, "Copy", py::arg("aOther"));
	cls_IntPolyh_ArrayOfSectionLines.def("Init", (void (IntPolyh_ArrayOfSectionLines::*)(const Standard_Integer)) &IntPolyh_ArrayOfSectionLines::Init, "Init - allocate memory for <aN> items", py::arg("aN"));
	cls_IntPolyh_ArrayOfSectionLines.def("IncrementNbItems", (void (IntPolyh_ArrayOfSectionLines::*)()) &IntPolyh_ArrayOfSectionLines::IncrementNbItems, "IncrementNbItems - increment the number of stored items");
	cls_IntPolyh_ArrayOfSectionLines.def("GetN", (Standard_Integer (IntPolyh_ArrayOfSectionLines::*)() const ) &IntPolyh_ArrayOfSectionLines::GetN, "GetN - returns the number of 'allocated' items");
	cls_IntPolyh_ArrayOfSectionLines.def("NbItems", (Standard_Integer (IntPolyh_ArrayOfSectionLines::*)() const ) &IntPolyh_ArrayOfSectionLines::NbItems, "NbItems - returns the number of stored items");
	cls_IntPolyh_ArrayOfSectionLines.def("SetNbItems", (void (IntPolyh_ArrayOfSectionLines::*)(const Standard_Integer)) &IntPolyh_ArrayOfSectionLines::SetNbItems, "set the number of stored items", py::arg("aNb"));
	cls_IntPolyh_ArrayOfSectionLines.def("Value", (const IntPolyh_SectionLine & (IntPolyh_ArrayOfSectionLines::*)(const Standard_Integer) const ) &IntPolyh_ArrayOfSectionLines::Value, "query the const value", py::arg("aIndex"));
	cls_IntPolyh_ArrayOfSectionLines.def("__getitem__", (const IntPolyh_SectionLine & (IntPolyh_ArrayOfSectionLines::*)(const Standard_Integer) const ) &IntPolyh_ArrayOfSectionLines::operator[], py::is_operator(), "query the const value", py::arg("aIndex"));
	cls_IntPolyh_ArrayOfSectionLines.def("ChangeValue", (IntPolyh_SectionLine & (IntPolyh_ArrayOfSectionLines::*)(const Standard_Integer)) &IntPolyh_ArrayOfSectionLines::ChangeValue, "query the value", py::arg("aIndex"));
	cls_IntPolyh_ArrayOfSectionLines.def("__getitem__", (IntPolyh_SectionLine & (IntPolyh_ArrayOfSectionLines::*)(const Standard_Integer)) &IntPolyh_ArrayOfSectionLines::operator[], py::is_operator(), "query the value", py::arg("aIndex"));
	// FIXME cls_IntPolyh_ArrayOfSectionLines.def("Dump", (void (IntPolyh_ArrayOfSectionLines::*)() const ) &IntPolyh_ArrayOfSectionLines::Dump, "dump the contents");

	*/

	/* FIXME
	// C:\Miniconda\envs\occt\Library\include\opencascade\IntPolyh_Array.hxx
	py::class_<IntPolyh_ArrayOfTangentZones, std::unique_ptr<IntPolyh_ArrayOfTangentZones, Deleter<IntPolyh_ArrayOfTangentZones>>> cls_IntPolyh_ArrayOfTangentZones(mod, "IntPolyh_ArrayOfTangentZones", "Class IntPolyh_Array (dynamic array of objects)");
	cls_IntPolyh_ArrayOfTangentZones.def(py::init<>());
	cls_IntPolyh_ArrayOfTangentZones.def(py::init<const Standard_Integer>(), py::arg("aIncrement"));
	cls_IntPolyh_ArrayOfTangentZones.def(py::init<const Standard_Integer>(), py::arg("aN"));
	cls_IntPolyh_ArrayOfTangentZones.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("aN"), py::arg("aIncrement"));
	cls_IntPolyh_ArrayOfTangentZones.def("assign", (IntPolyh_ArrayOfTangentZones & (IntPolyh_ArrayOfTangentZones::*)(const IntPolyh_ArrayOfTangentZones &)) &IntPolyh_ArrayOfTangentZones::operator=, py::is_operator(), "Assignment operator", py::arg("aOther"));
	cls_IntPolyh_ArrayOfTangentZones.def("Copy", (IntPolyh_ArrayOfTangentZones & (IntPolyh_ArrayOfTangentZones::*)(const IntPolyh_ArrayOfTangentZones &)) &IntPolyh_ArrayOfTangentZones::Copy, "Copy", py::arg("aOther"));
	cls_IntPolyh_ArrayOfTangentZones.def("Init", (void (IntPolyh_ArrayOfTangentZones::*)(const Standard_Integer)) &IntPolyh_ArrayOfTangentZones::Init, "Init - allocate memory for <aN> items", py::arg("aN"));
	cls_IntPolyh_ArrayOfTangentZones.def("IncrementNbItems", (void (IntPolyh_ArrayOfTangentZones::*)()) &IntPolyh_ArrayOfTangentZones::IncrementNbItems, "IncrementNbItems - increment the number of stored items");
	cls_IntPolyh_ArrayOfTangentZones.def("GetN", (Standard_Integer (IntPolyh_ArrayOfTangentZones::*)() const ) &IntPolyh_ArrayOfTangentZones::GetN, "GetN - returns the number of 'allocated' items");
	cls_IntPolyh_ArrayOfTangentZones.def("NbItems", (Standard_Integer (IntPolyh_ArrayOfTangentZones::*)() const ) &IntPolyh_ArrayOfTangentZones::NbItems, "NbItems - returns the number of stored items");
	cls_IntPolyh_ArrayOfTangentZones.def("SetNbItems", (void (IntPolyh_ArrayOfTangentZones::*)(const Standard_Integer)) &IntPolyh_ArrayOfTangentZones::SetNbItems, "set the number of stored items", py::arg("aNb"));
	cls_IntPolyh_ArrayOfTangentZones.def("Value", (const IntPolyh_StartPoint & (IntPolyh_ArrayOfTangentZones::*)(const Standard_Integer) const ) &IntPolyh_ArrayOfTangentZones::Value, "query the const value", py::arg("aIndex"));
	cls_IntPolyh_ArrayOfTangentZones.def("__getitem__", (const IntPolyh_StartPoint & (IntPolyh_ArrayOfTangentZones::*)(const Standard_Integer) const ) &IntPolyh_ArrayOfTangentZones::operator[], py::is_operator(), "query the const value", py::arg("aIndex"));
	cls_IntPolyh_ArrayOfTangentZones.def("ChangeValue", (IntPolyh_StartPoint & (IntPolyh_ArrayOfTangentZones::*)(const Standard_Integer)) &IntPolyh_ArrayOfTangentZones::ChangeValue, "query the value", py::arg("aIndex"));
	cls_IntPolyh_ArrayOfTangentZones.def("__getitem__", (IntPolyh_StartPoint & (IntPolyh_ArrayOfTangentZones::*)(const Standard_Integer)) &IntPolyh_ArrayOfTangentZones::operator[], py::is_operator(), "query the value", py::arg("aIndex"));
	// FIXME cls_IntPolyh_ArrayOfTangentZones.def("Dump", (void (IntPolyh_ArrayOfTangentZones::*)() const ) &IntPolyh_ArrayOfTangentZones::Dump, "dump the contents");

	*/

	/* FIXME
	// C:\Miniconda\envs\occt\Library\include\opencascade\IntPolyh_Array.hxx
	py::class_<IntPolyh_ArrayOfTriangles, std::unique_ptr<IntPolyh_ArrayOfTriangles, Deleter<IntPolyh_ArrayOfTriangles>>> cls_IntPolyh_ArrayOfTriangles(mod, "IntPolyh_ArrayOfTriangles", "Class IntPolyh_Array (dynamic array of objects)");
	cls_IntPolyh_ArrayOfTriangles.def(py::init<>());
	cls_IntPolyh_ArrayOfTriangles.def(py::init<const Standard_Integer>(), py::arg("aIncrement"));
	cls_IntPolyh_ArrayOfTriangles.def(py::init<const Standard_Integer>(), py::arg("aN"));
	cls_IntPolyh_ArrayOfTriangles.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("aN"), py::arg("aIncrement"));
	cls_IntPolyh_ArrayOfTriangles.def("assign", (IntPolyh_ArrayOfTriangles & (IntPolyh_ArrayOfTriangles::*)(const IntPolyh_ArrayOfTriangles &)) &IntPolyh_ArrayOfTriangles::operator=, py::is_operator(), "Assignment operator", py::arg("aOther"));
	cls_IntPolyh_ArrayOfTriangles.def("Copy", (IntPolyh_ArrayOfTriangles & (IntPolyh_ArrayOfTriangles::*)(const IntPolyh_ArrayOfTriangles &)) &IntPolyh_ArrayOfTriangles::Copy, "Copy", py::arg("aOther"));
	cls_IntPolyh_ArrayOfTriangles.def("Init", (void (IntPolyh_ArrayOfTriangles::*)(const Standard_Integer)) &IntPolyh_ArrayOfTriangles::Init, "Init - allocate memory for <aN> items", py::arg("aN"));
	cls_IntPolyh_ArrayOfTriangles.def("IncrementNbItems", (void (IntPolyh_ArrayOfTriangles::*)()) &IntPolyh_ArrayOfTriangles::IncrementNbItems, "IncrementNbItems - increment the number of stored items");
	cls_IntPolyh_ArrayOfTriangles.def("GetN", (Standard_Integer (IntPolyh_ArrayOfTriangles::*)() const ) &IntPolyh_ArrayOfTriangles::GetN, "GetN - returns the number of 'allocated' items");
	cls_IntPolyh_ArrayOfTriangles.def("NbItems", (Standard_Integer (IntPolyh_ArrayOfTriangles::*)() const ) &IntPolyh_ArrayOfTriangles::NbItems, "NbItems - returns the number of stored items");
	cls_IntPolyh_ArrayOfTriangles.def("SetNbItems", (void (IntPolyh_ArrayOfTriangles::*)(const Standard_Integer)) &IntPolyh_ArrayOfTriangles::SetNbItems, "set the number of stored items", py::arg("aNb"));
	cls_IntPolyh_ArrayOfTriangles.def("Value", (const IntPolyh_Triangle & (IntPolyh_ArrayOfTriangles::*)(const Standard_Integer) const ) &IntPolyh_ArrayOfTriangles::Value, "query the const value", py::arg("aIndex"));
	cls_IntPolyh_ArrayOfTriangles.def("__getitem__", (const IntPolyh_Triangle & (IntPolyh_ArrayOfTriangles::*)(const Standard_Integer) const ) &IntPolyh_ArrayOfTriangles::operator[], py::is_operator(), "query the const value", py::arg("aIndex"));
	cls_IntPolyh_ArrayOfTriangles.def("ChangeValue", (IntPolyh_Triangle & (IntPolyh_ArrayOfTriangles::*)(const Standard_Integer)) &IntPolyh_ArrayOfTriangles::ChangeValue, "query the value", py::arg("aIndex"));
	cls_IntPolyh_ArrayOfTriangles.def("__getitem__", (IntPolyh_Triangle & (IntPolyh_ArrayOfTriangles::*)(const Standard_Integer)) &IntPolyh_ArrayOfTriangles::operator[], py::is_operator(), "query the value", py::arg("aIndex"));
	// FIXME cls_IntPolyh_ArrayOfTriangles.def("Dump", (void (IntPolyh_ArrayOfTriangles::*)() const ) &IntPolyh_ArrayOfTriangles::Dump, "dump the contents");

	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntPolyh_PMaillageAffinage.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_List.hxx
	py::class_<IntPolyh_ListOfCouples, std::unique_ptr<IntPolyh_ListOfCouples, Deleter<IntPolyh_ListOfCouples>>, NCollection_BaseList> cls_IntPolyh_ListOfCouples(mod, "IntPolyh_ListOfCouples", "Purpose: Simple list to link items together keeping the first and the last one. Inherits BaseList, adding the data item to each node.");
	cls_IntPolyh_ListOfCouples.def(py::init<>());
	cls_IntPolyh_ListOfCouples.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_IntPolyh_ListOfCouples.def(py::init([] (const IntPolyh_ListOfCouples &other) {return new IntPolyh_ListOfCouples(other);}), "Copy constructor", py::arg("other"));
	cls_IntPolyh_ListOfCouples.def("begin", (IntPolyh_ListOfCouples::iterator (IntPolyh_ListOfCouples::*)() const ) &IntPolyh_ListOfCouples::begin, "Returns an iterator pointing to the first element in the list.");
	cls_IntPolyh_ListOfCouples.def("end", (IntPolyh_ListOfCouples::iterator (IntPolyh_ListOfCouples::*)() const ) &IntPolyh_ListOfCouples::end, "Returns an iterator referring to the past-the-end element in the list.");
	cls_IntPolyh_ListOfCouples.def("cbegin", (IntPolyh_ListOfCouples::const_iterator (IntPolyh_ListOfCouples::*)() const ) &IntPolyh_ListOfCouples::cbegin, "Returns a const iterator pointing to the first element in the list.");
	cls_IntPolyh_ListOfCouples.def("cend", (IntPolyh_ListOfCouples::const_iterator (IntPolyh_ListOfCouples::*)() const ) &IntPolyh_ListOfCouples::cend, "Returns a const iterator referring to the past-the-end element in the list.");
	cls_IntPolyh_ListOfCouples.def("Size", (Standard_Integer (IntPolyh_ListOfCouples::*)() const ) &IntPolyh_ListOfCouples::Size, "Size - Number of items");
	cls_IntPolyh_ListOfCouples.def("Assign", (IntPolyh_ListOfCouples & (IntPolyh_ListOfCouples::*)(const IntPolyh_ListOfCouples &)) &IntPolyh_ListOfCouples::Assign, "Replace this list by the items of another list (theOther parameter). This method does not change the internal allocator.", py::arg("theOther"));
	cls_IntPolyh_ListOfCouples.def("assign", (IntPolyh_ListOfCouples & (IntPolyh_ListOfCouples::*)(const IntPolyh_ListOfCouples &)) &IntPolyh_ListOfCouples::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_IntPolyh_ListOfCouples.def("Clear", [](IntPolyh_ListOfCouples &self) -> void { return self.Clear(); });
	cls_IntPolyh_ListOfCouples.def("Clear", (void (IntPolyh_ListOfCouples::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &IntPolyh_ListOfCouples::Clear, "Clear this list", py::arg("theAllocator"));
	cls_IntPolyh_ListOfCouples.def("First", (const IntPolyh_Couple & (IntPolyh_ListOfCouples::*)() const ) &IntPolyh_ListOfCouples::First, "First item");
	cls_IntPolyh_ListOfCouples.def("First", (IntPolyh_Couple & (IntPolyh_ListOfCouples::*)()) &IntPolyh_ListOfCouples::First, "First item (non-const)");
	cls_IntPolyh_ListOfCouples.def("Last", (const IntPolyh_Couple & (IntPolyh_ListOfCouples::*)() const ) &IntPolyh_ListOfCouples::Last, "Last item");
	cls_IntPolyh_ListOfCouples.def("Last", (IntPolyh_Couple & (IntPolyh_ListOfCouples::*)()) &IntPolyh_ListOfCouples::Last, "Last item (non-const)");
	cls_IntPolyh_ListOfCouples.def("Append", (IntPolyh_Couple & (IntPolyh_ListOfCouples::*)(const IntPolyh_Couple &)) &IntPolyh_ListOfCouples::Append, "Append one item at the end", py::arg("theItem"));
	cls_IntPolyh_ListOfCouples.def("Append", (void (IntPolyh_ListOfCouples::*)(const IntPolyh_Couple &, IntPolyh_ListOfCouples::Iterator &)) &IntPolyh_ListOfCouples::Append, "Append one item at the end and output iterator pointing at the appended item", py::arg("theItem"), py::arg("theIter"));
	cls_IntPolyh_ListOfCouples.def("Append", (void (IntPolyh_ListOfCouples::*)(IntPolyh_ListOfCouples &)) &IntPolyh_ListOfCouples::Append, "Append another list at the end", py::arg("theOther"));
	cls_IntPolyh_ListOfCouples.def("Prepend", (IntPolyh_Couple & (IntPolyh_ListOfCouples::*)(const IntPolyh_Couple &)) &IntPolyh_ListOfCouples::Prepend, "Prepend one item at the beginning", py::arg("theItem"));
	cls_IntPolyh_ListOfCouples.def("Prepend", (void (IntPolyh_ListOfCouples::*)(IntPolyh_ListOfCouples &)) &IntPolyh_ListOfCouples::Prepend, "Prepend another list at the beginning", py::arg("theOther"));
	cls_IntPolyh_ListOfCouples.def("RemoveFirst", (void (IntPolyh_ListOfCouples::*)()) &IntPolyh_ListOfCouples::RemoveFirst, "RemoveFirst item");
	cls_IntPolyh_ListOfCouples.def("Remove", (void (IntPolyh_ListOfCouples::*)(IntPolyh_ListOfCouples::Iterator &)) &IntPolyh_ListOfCouples::Remove, "Remove item pointed by iterator theIter; theIter is then set to the next item", py::arg("theIter"));
	cls_IntPolyh_ListOfCouples.def("InsertBefore", (IntPolyh_Couple & (IntPolyh_ListOfCouples::*)(const IntPolyh_Couple &, IntPolyh_ListOfCouples::Iterator &)) &IntPolyh_ListOfCouples::InsertBefore, "InsertBefore", py::arg("theItem"), py::arg("theIter"));
	cls_IntPolyh_ListOfCouples.def("InsertBefore", (void (IntPolyh_ListOfCouples::*)(IntPolyh_ListOfCouples &, IntPolyh_ListOfCouples::Iterator &)) &IntPolyh_ListOfCouples::InsertBefore, "InsertBefore", py::arg("theOther"), py::arg("theIter"));
	cls_IntPolyh_ListOfCouples.def("InsertAfter", (IntPolyh_Couple & (IntPolyh_ListOfCouples::*)(const IntPolyh_Couple &, IntPolyh_ListOfCouples::Iterator &)) &IntPolyh_ListOfCouples::InsertAfter, "InsertAfter", py::arg("theItem"), py::arg("theIter"));
	cls_IntPolyh_ListOfCouples.def("InsertAfter", (void (IntPolyh_ListOfCouples::*)(IntPolyh_ListOfCouples &, IntPolyh_ListOfCouples::Iterator &)) &IntPolyh_ListOfCouples::InsertAfter, "InsertAfter", py::arg("theOther"), py::arg("theIter"));
	cls_IntPolyh_ListOfCouples.def("Reverse", (void (IntPolyh_ListOfCouples::*)()) &IntPolyh_ListOfCouples::Reverse, "Reverse the list");
	cls_IntPolyh_ListOfCouples.def("__iter__", [](const IntPolyh_ListOfCouples &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_TListIterator.hxx
	py::class_<IntPolyh_ListIteratorOfListOfCouples, std::unique_ptr<IntPolyh_ListIteratorOfListOfCouples, Deleter<IntPolyh_ListIteratorOfListOfCouples>>> cls_IntPolyh_ListIteratorOfListOfCouples(mod, "IntPolyh_ListIteratorOfListOfCouples", "Purpose: This Iterator class iterates on BaseList of TListNode and is instantiated in List/Set/Queue/Stack Remark: TListIterator is internal class");
	cls_IntPolyh_ListIteratorOfListOfCouples.def(py::init<>());
	cls_IntPolyh_ListIteratorOfListOfCouples.def(py::init<const NCollection_BaseList &>(), py::arg("theList"));
	cls_IntPolyh_ListIteratorOfListOfCouples.def("More", (Standard_Boolean (IntPolyh_ListIteratorOfListOfCouples::*)() const ) &IntPolyh_ListIteratorOfListOfCouples::More, "Check end");
	cls_IntPolyh_ListIteratorOfListOfCouples.def("Next", (void (IntPolyh_ListIteratorOfListOfCouples::*)()) &IntPolyh_ListIteratorOfListOfCouples::Next, "Make step");
	cls_IntPolyh_ListIteratorOfListOfCouples.def("Value", (const IntPolyh_Couple & (IntPolyh_ListIteratorOfListOfCouples::*)() const ) &IntPolyh_ListIteratorOfListOfCouples::Value, "Constant Value access");
	cls_IntPolyh_ListIteratorOfListOfCouples.def("Value", (IntPolyh_Couple & (IntPolyh_ListIteratorOfListOfCouples::*)()) &IntPolyh_ListIteratorOfListOfCouples::Value, "Non-const Value access");
	cls_IntPolyh_ListIteratorOfListOfCouples.def("ChangeValue", (IntPolyh_Couple & (IntPolyh_ListIteratorOfListOfCouples::*)() const ) &IntPolyh_ListIteratorOfListOfCouples::ChangeValue, "Non-const Value access");


}
