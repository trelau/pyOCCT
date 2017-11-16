#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <NCollection_BaseMap.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_DataMap.hxx>
#include <MAT2d_DataMapOfIntegerBisec.hxx>
#include <MAT2d_DataMapOfIntegerPnt2d.hxx>
#include <MAT2d_DataMapOfIntegerVec2d.hxx>
#include <Standard_Transient.hxx>
#include <GeomAbs_JoinType.hxx>
#include <MAT2d_SequenceOfSequenceOfGeometry.hxx>
#include <TColStd_SequenceOfBoolean.hxx>
#include <Geom2d_Geometry.hxx>
#include <TColStd_SequenceOfInteger.hxx>
#include <MAT2d_Connexion.hxx>
#include <Standard_Type.hxx>
#include <MAT2d_Circuit.hxx>
#include <MAT_Side.hxx>
#include <MAT_Bisector.hxx>
#include <Bisector_Bisec.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Vec2d.hxx>
#include <MAT2d_Tool2d.hxx>
#include <MAT2d_BiInt.hxx>
#include <MAT2d_MapBiIntHasher.hxx>
#include <MAT2d_DataMapOfBiIntInteger.hxx>
#include <NCollection_BaseSequence.hxx>
#include <NCollection_Sequence.hxx>
#include <MAT2d_SequenceOfSequenceOfCurve.hxx>
#include <NCollection_Array2.hxx>
#include <MAT2d_Array2OfConnexion.hxx>
#include <MAT2d_DataMapOfIntegerConnexion.hxx>
#include <MAT2d_DataMapOfBiIntSequenceOfInteger.hxx>
#include <MAT2d_SequenceOfConnexion.hxx>
#include <MAT2d_MiniPath.hxx>
#include <Geom2d_Curve.hxx>
#include <Geom2d_TrimmedCurve.hxx>
#include <MAT2d_CutCurve.hxx>
#include <MAT2d_DataMapOfIntegerSequenceOfConnexion.hxx>
#include <MAT2d_Mat2d.hxx>
#include <MAT2d_SketchExplorer.hxx>

PYBIND11_MODULE(MAT2d, mod) {

	// IMPORT
	py::module::import("OCCT.NCollection");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.GeomAbs");
	py::module::import("OCCT.TColStd");
	py::module::import("OCCT.Geom2d");
	py::module::import("OCCT.MAT");
	py::module::import("OCCT.Bisector");
	py::module::import("OCCT.gp");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\MAT2d_Circuit.hxx
	py::class_<MAT2d_Circuit, opencascade::handle<MAT2d_Circuit>, Standard_Transient> cls_MAT2d_Circuit(mod, "MAT2d_Circuit", "Constructs a circuit on a set of lines. EquiCircuit gives a Circuit passing by all the lines in a set and all the connexions of the minipath associated.");
	cls_MAT2d_Circuit.def(py::init<>());
	cls_MAT2d_Circuit.def(py::init<const GeomAbs_JoinType>(), py::arg("aJoinType"));
	cls_MAT2d_Circuit.def(py::init<const GeomAbs_JoinType, const Standard_Boolean>(), py::arg("aJoinType"), py::arg("IsOpenResult"));
	cls_MAT2d_Circuit.def("Perform", (void (MAT2d_Circuit::*)(MAT2d_SequenceOfSequenceOfGeometry &, const TColStd_SequenceOfBoolean &, const Standard_Integer, const Standard_Boolean)) &MAT2d_Circuit::Perform, "None", py::arg("aFigure"), py::arg("IsClosed"), py::arg("IndRefLine"), py::arg("Trigo"));
	cls_MAT2d_Circuit.def("NumberOfItems", (Standard_Integer (MAT2d_Circuit::*)() const ) &MAT2d_Circuit::NumberOfItems, "Returns the Number of Items .");
	cls_MAT2d_Circuit.def("Value", (opencascade::handle<Geom2d_Geometry> (MAT2d_Circuit::*)(const Standard_Integer) const ) &MAT2d_Circuit::Value, "Returns the item at position <Index> in <me>.", py::arg("Index"));
	cls_MAT2d_Circuit.def("LineLength", (Standard_Integer (MAT2d_Circuit::*)(const Standard_Integer) const ) &MAT2d_Circuit::LineLength, "Returns the number of items on the line <IndexLine>.", py::arg("IndexLine"));
	cls_MAT2d_Circuit.def("RefToEqui", (const TColStd_SequenceOfInteger & (MAT2d_Circuit::*)(const Standard_Integer, const Standard_Integer) const ) &MAT2d_Circuit::RefToEqui, "Returns the set of index of the items in <me>corresponding to the curve <IndCurve> on the line <IndLine> from the initial figure.", py::arg("IndLine"), py::arg("IndCurve"));
	cls_MAT2d_Circuit.def("Connexion", (opencascade::handle<MAT2d_Connexion> (MAT2d_Circuit::*)(const Standard_Integer) const ) &MAT2d_Circuit::Connexion, "Returns the Connexion on the item <Index> in me.", py::arg("Index"));
	cls_MAT2d_Circuit.def("ConnexionOn", (Standard_Boolean (MAT2d_Circuit::*)(const Standard_Integer) const ) &MAT2d_Circuit::ConnexionOn, "Returns <True> is there is a connexion on the item <Index> in <me>.", py::arg("Index"));
	cls_MAT2d_Circuit.def_static("get_type_name_", (const char * (*)()) &MAT2d_Circuit::get_type_name, "None");
	cls_MAT2d_Circuit.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MAT2d_Circuit::get_type_descriptor, "None");
	cls_MAT2d_Circuit.def("DynamicType", (const opencascade::handle<Standard_Type> & (MAT2d_Circuit::*)() const ) &MAT2d_Circuit::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\MAT2d_Tool2d.hxx
	py::class_<MAT2d_Tool2d, std::unique_ptr<MAT2d_Tool2d, Deleter<MAT2d_Tool2d>>> cls_MAT2d_Tool2d(mod, "MAT2d_Tool2d", "Set of the methods useful for the MAT's computation. Tool2d contains the geometry of the bisecting locus.");
	cls_MAT2d_Tool2d.def(py::init<>());
	cls_MAT2d_Tool2d.def("Sense", (void (MAT2d_Tool2d::*)(const MAT_Side)) &MAT2d_Tool2d::Sense, "<aSide> defines the side of the computation of the map.", py::arg("aside"));
	cls_MAT2d_Tool2d.def("SetJoinType", (void (MAT2d_Tool2d::*)(const GeomAbs_JoinType)) &MAT2d_Tool2d::SetJoinType, "None", py::arg("aJoinType"));
	cls_MAT2d_Tool2d.def("InitItems", (void (MAT2d_Tool2d::*)(const opencascade::handle<MAT2d_Circuit> &)) &MAT2d_Tool2d::InitItems, "InitItems cuts the line in Items. this Items are the geometrics representations of the BasicElts from MAT.", py::arg("aCircuit"));
	cls_MAT2d_Tool2d.def("NumberOfItems", (Standard_Integer (MAT2d_Tool2d::*)() const ) &MAT2d_Tool2d::NumberOfItems, "Returns the Number of Items .");
	cls_MAT2d_Tool2d.def("ToleranceOfConfusion", (Standard_Real (MAT2d_Tool2d::*)() const ) &MAT2d_Tool2d::ToleranceOfConfusion, "Returns tolerance to test the confusion of two points.");
	cls_MAT2d_Tool2d.def("FirstPoint", (Standard_Integer (MAT2d_Tool2d::*)(const Standard_Integer, Standard_Real &)) &MAT2d_Tool2d::FirstPoint, "Creates the point at the origin of the bisector between anitem and the previous item. dist is the distance from the FirstPoint to <anitem>. Returns the index of this point in <theGeomPnts>.", py::arg("anitem"), py::arg("dist"));
	cls_MAT2d_Tool2d.def("TangentBefore", (Standard_Integer (MAT2d_Tool2d::*)(const Standard_Integer, const Standard_Boolean)) &MAT2d_Tool2d::TangentBefore, "Creates the Tangent at the end of the Item defined by <anitem>. Returns the index of this vector in <theGeomVecs>", py::arg("anitem"), py::arg("IsOpenResult"));
	cls_MAT2d_Tool2d.def("TangentAfter", (Standard_Integer (MAT2d_Tool2d::*)(const Standard_Integer, const Standard_Boolean)) &MAT2d_Tool2d::TangentAfter, "Creates the Reversed Tangent at the origin of the Item defined by <anitem>. Returns the index of this vector in <theGeomVecs>", py::arg("anitem"), py::arg("IsOpenResult"));
	cls_MAT2d_Tool2d.def("Tangent", (Standard_Integer (MAT2d_Tool2d::*)(const Standard_Integer)) &MAT2d_Tool2d::Tangent, "Creates the Tangent at the end of the bisector defined by <bisector>. Returns the index of this vector in <theGeomVecs>", py::arg("bisector"));
	cls_MAT2d_Tool2d.def("CreateBisector", (void (MAT2d_Tool2d::*)(const opencascade::handle<MAT_Bisector> &)) &MAT2d_Tool2d::CreateBisector, "Creates the geometric bisector defined by <abisector>.", py::arg("abisector"));
	cls_MAT2d_Tool2d.def("TrimBisector", (Standard_Boolean (MAT2d_Tool2d::*)(const opencascade::handle<MAT_Bisector> &)) &MAT2d_Tool2d::TrimBisector, "Trims the geometric bisector by the <firstparameter> of <abisector>. If the parameter is out of the bisector, Return FALSE. else Return True.", py::arg("abisector"));
	cls_MAT2d_Tool2d.def("TrimBisector", (Standard_Boolean (MAT2d_Tool2d::*)(const opencascade::handle<MAT_Bisector> &, const Standard_Integer)) &MAT2d_Tool2d::TrimBisector, "Trims the geometric bisector by the point of index <apoint> in <theGeomPnts>. If the point is out of the bisector, Return FALSE. else Return True.", py::arg("abisector"), py::arg("apoint"));
	cls_MAT2d_Tool2d.def("IntersectBisector", (Standard_Real (MAT2d_Tool2d::*)(const opencascade::handle<MAT_Bisector> &, const opencascade::handle<MAT_Bisector> &, Standard_Integer &)) &MAT2d_Tool2d::IntersectBisector, "Computes the point of intersection between the bisectors defined by <bisectorone> and <bisectortwo> . If this point exists, <intpnt> is its index in <theGeomPnts> and Return the distance of the point from the bisector else Return <RealLast>.", py::arg("bisectorone"), py::arg("bisectortwo"), py::arg("intpnt"));
	cls_MAT2d_Tool2d.def("Distance", (Standard_Real (MAT2d_Tool2d::*)(const opencascade::handle<MAT_Bisector> &, const Standard_Real, const Standard_Real) const ) &MAT2d_Tool2d::Distance, "Returns the distance between the two points designed by their parameters on <abisector>.", py::arg("abisector"), py::arg("param1"), py::arg("param2"));
	// FIXME cls_MAT2d_Tool2d.def("Dump", (void (MAT2d_Tool2d::*)(const Standard_Integer, const Standard_Integer) const ) &MAT2d_Tool2d::Dump, "displays informations about the bisector defined by <bisector>.", py::arg("bisector"), py::arg("erease"));
	cls_MAT2d_Tool2d.def("GeomBis", (const Bisector_Bisec & (MAT2d_Tool2d::*)(const Standard_Integer) const ) &MAT2d_Tool2d::GeomBis, "Returns the <Bisec> of index <Index> in <theGeomBisectors>.", py::arg("Index"));
	cls_MAT2d_Tool2d.def("GeomElt", (opencascade::handle<Geom2d_Geometry> (MAT2d_Tool2d::*)(const Standard_Integer) const ) &MAT2d_Tool2d::GeomElt, "Returns the Geometry of index <Index> in <theGeomElts>.", py::arg("Index"));
	cls_MAT2d_Tool2d.def("GeomPnt", (const gp_Pnt2d & (MAT2d_Tool2d::*)(const Standard_Integer) const ) &MAT2d_Tool2d::GeomPnt, "Returns the point of index <Index> in the <theGeomPnts>.", py::arg("Index"));
	cls_MAT2d_Tool2d.def("GeomVec", (const gp_Vec2d & (MAT2d_Tool2d::*)(const Standard_Integer) const ) &MAT2d_Tool2d::GeomVec, "Returns the vector of index <Index> in the <theGeomVecs>.", py::arg("Index"));
	cls_MAT2d_Tool2d.def("Circuit", (opencascade::handle<MAT2d_Circuit> (MAT2d_Tool2d::*)() const ) &MAT2d_Tool2d::Circuit, "None");
	cls_MAT2d_Tool2d.def("BisecFusion", (void (MAT2d_Tool2d::*)(const Standard_Integer, const Standard_Integer)) &MAT2d_Tool2d::BisecFusion, "None", py::arg("Index1"), py::arg("Index2"));
	cls_MAT2d_Tool2d.def("ChangeGeomBis", (Bisector_Bisec & (MAT2d_Tool2d::*)(const Standard_Integer)) &MAT2d_Tool2d::ChangeGeomBis, "Returns the <Bisec> of index <Index> in <theGeomBisectors>.", py::arg("Index"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\MAT2d_BiInt.hxx
	py::class_<MAT2d_BiInt, std::unique_ptr<MAT2d_BiInt, Deleter<MAT2d_BiInt>>> cls_MAT2d_BiInt(mod, "MAT2d_BiInt", "BiInt is a set of two integers.");
	cls_MAT2d_BiInt.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("I1"), py::arg("I2"));
	cls_MAT2d_BiInt.def("FirstIndex", (Standard_Integer (MAT2d_BiInt::*)() const ) &MAT2d_BiInt::FirstIndex, "None");
	cls_MAT2d_BiInt.def("SecondIndex", (Standard_Integer (MAT2d_BiInt::*)() const ) &MAT2d_BiInt::SecondIndex, "None");
	cls_MAT2d_BiInt.def("FirstIndex", (void (MAT2d_BiInt::*)(const Standard_Integer)) &MAT2d_BiInt::FirstIndex, "None", py::arg("I1"));
	cls_MAT2d_BiInt.def("SecondIndex", (void (MAT2d_BiInt::*)(const Standard_Integer)) &MAT2d_BiInt::SecondIndex, "None", py::arg("I2"));
	cls_MAT2d_BiInt.def("IsEqual", (Standard_Boolean (MAT2d_BiInt::*)(const MAT2d_BiInt &) const ) &MAT2d_BiInt::IsEqual, "None", py::arg("B"));
	cls_MAT2d_BiInt.def("__eq__", (Standard_Boolean (MAT2d_BiInt::*)(const MAT2d_BiInt &) const ) &MAT2d_BiInt::operator==, py::is_operator(), "None", py::arg("B"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\MAT2d_MapBiIntHasher.hxx
	py::class_<MAT2d_MapBiIntHasher, std::unique_ptr<MAT2d_MapBiIntHasher, Deleter<MAT2d_MapBiIntHasher>>> cls_MAT2d_MapBiIntHasher(mod, "MAT2d_MapBiIntHasher", "None");
	cls_MAT2d_MapBiIntHasher.def(py::init<>());
	cls_MAT2d_MapBiIntHasher.def_static("HashCode_", (Standard_Integer (*)(const MAT2d_BiInt &, const Standard_Integer)) &MAT2d_MapBiIntHasher::HashCode, "None", py::arg("Key1"), py::arg("Upper"));
	cls_MAT2d_MapBiIntHasher.def_static("IsEqual_", (Standard_Boolean (*)(const MAT2d_BiInt &, const MAT2d_BiInt &)) &MAT2d_MapBiIntHasher::IsEqual, "None", py::arg("Key1"), py::arg("Key2"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\MAT2d_Connexion.hxx
	py::class_<MAT2d_Connexion, opencascade::handle<MAT2d_Connexion>, Standard_Transient> cls_MAT2d_Connexion(mod, "MAT2d_Connexion", "A Connexion links two lines of items in a set of lines. It s contains two points and their paramatric definitions on the lines. The items can be points or curves.");
	cls_MAT2d_Connexion.def(py::init<>());
	cls_MAT2d_Connexion.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real, const gp_Pnt2d &, const gp_Pnt2d &>(), py::arg("LineA"), py::arg("LineB"), py::arg("ItemA"), py::arg("ItemB"), py::arg("Distance"), py::arg("ParameterOnA"), py::arg("ParameterOnB"), py::arg("PointA"), py::arg("PointB"));
	cls_MAT2d_Connexion.def("IndexFirstLine", (Standard_Integer (MAT2d_Connexion::*)() const ) &MAT2d_Connexion::IndexFirstLine, "Returns the Index on the first line.");
	cls_MAT2d_Connexion.def("IndexSecondLine", (Standard_Integer (MAT2d_Connexion::*)() const ) &MAT2d_Connexion::IndexSecondLine, "Returns the Index on the Second line.");
	cls_MAT2d_Connexion.def("IndexItemOnFirst", (Standard_Integer (MAT2d_Connexion::*)() const ) &MAT2d_Connexion::IndexItemOnFirst, "Returns the Index of the item on the first line.");
	cls_MAT2d_Connexion.def("IndexItemOnSecond", (Standard_Integer (MAT2d_Connexion::*)() const ) &MAT2d_Connexion::IndexItemOnSecond, "Returns the Index of the item on the second line.");
	cls_MAT2d_Connexion.def("ParameterOnFirst", (Standard_Real (MAT2d_Connexion::*)() const ) &MAT2d_Connexion::ParameterOnFirst, "Returns the parameter of the point on the firstline.");
	cls_MAT2d_Connexion.def("ParameterOnSecond", (Standard_Real (MAT2d_Connexion::*)() const ) &MAT2d_Connexion::ParameterOnSecond, "Returns the parameter of the point on the secondline.");
	cls_MAT2d_Connexion.def("PointOnFirst", (gp_Pnt2d (MAT2d_Connexion::*)() const ) &MAT2d_Connexion::PointOnFirst, "Returns the point on the firstline.");
	cls_MAT2d_Connexion.def("PointOnSecond", (gp_Pnt2d (MAT2d_Connexion::*)() const ) &MAT2d_Connexion::PointOnSecond, "Returns the point on the secondline.");
	cls_MAT2d_Connexion.def("Distance", (Standard_Real (MAT2d_Connexion::*)() const ) &MAT2d_Connexion::Distance, "Returns the distance between the two points.");
	cls_MAT2d_Connexion.def("IndexFirstLine", (void (MAT2d_Connexion::*)(const Standard_Integer)) &MAT2d_Connexion::IndexFirstLine, "None", py::arg("anIndex"));
	cls_MAT2d_Connexion.def("IndexSecondLine", (void (MAT2d_Connexion::*)(const Standard_Integer)) &MAT2d_Connexion::IndexSecondLine, "None", py::arg("anIndex"));
	cls_MAT2d_Connexion.def("IndexItemOnFirst", (void (MAT2d_Connexion::*)(const Standard_Integer)) &MAT2d_Connexion::IndexItemOnFirst, "None", py::arg("anIndex"));
	cls_MAT2d_Connexion.def("IndexItemOnSecond", (void (MAT2d_Connexion::*)(const Standard_Integer)) &MAT2d_Connexion::IndexItemOnSecond, "None", py::arg("anIndex"));
	cls_MAT2d_Connexion.def("ParameterOnFirst", (void (MAT2d_Connexion::*)(const Standard_Real)) &MAT2d_Connexion::ParameterOnFirst, "None", py::arg("aParameter"));
	cls_MAT2d_Connexion.def("ParameterOnSecond", (void (MAT2d_Connexion::*)(const Standard_Real)) &MAT2d_Connexion::ParameterOnSecond, "None", py::arg("aParameter"));
	cls_MAT2d_Connexion.def("PointOnFirst", (void (MAT2d_Connexion::*)(const gp_Pnt2d &)) &MAT2d_Connexion::PointOnFirst, "None", py::arg("aPoint"));
	cls_MAT2d_Connexion.def("PointOnSecond", (void (MAT2d_Connexion::*)(const gp_Pnt2d &)) &MAT2d_Connexion::PointOnSecond, "None", py::arg("aPoint"));
	cls_MAT2d_Connexion.def("Distance", (void (MAT2d_Connexion::*)(const Standard_Real)) &MAT2d_Connexion::Distance, "None", py::arg("aDistance"));
	cls_MAT2d_Connexion.def("Reverse", (opencascade::handle<MAT2d_Connexion> (MAT2d_Connexion::*)() const ) &MAT2d_Connexion::Reverse, "Returns the reverse connexion of <me>. the firstpoint is the secondpoint. the secondpoint is the firstpoint.");
	cls_MAT2d_Connexion.def("IsAfter", (Standard_Boolean (MAT2d_Connexion::*)(const opencascade::handle<MAT2d_Connexion> &, const Standard_Real) const ) &MAT2d_Connexion::IsAfter, "Returns <True> if my firstPoint is on the same line than the firstpoint of <aConnexion> and my firstpoint is after the firstpoint of <aConnexion> on the line. <aSense> = 1 if <aConnexion> is on the Left of its firstline, else <aSense> = -1.", py::arg("aConnexion"), py::arg("aSense"));
	// FIXME cls_MAT2d_Connexion.def("Dump", [](MAT2d_Connexion &self) -> void { return self.Dump(); });
	// FIXME cls_MAT2d_Connexion.def("Dump", [](MAT2d_Connexion &self, const Standard_Integer a0) -> void { return self.Dump(a0); }, py::arg("Deep"));
	// FIXME cls_MAT2d_Connexion.def("Dump", (void (MAT2d_Connexion::*)(const Standard_Integer, const Standard_Integer) const ) &MAT2d_Connexion::Dump, "Print <me>.", py::arg("Deep"), py::arg("Offset"));
	cls_MAT2d_Connexion.def_static("get_type_name_", (const char * (*)()) &MAT2d_Connexion::get_type_name, "None");
	cls_MAT2d_Connexion.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MAT2d_Connexion::get_type_descriptor, "None");
	cls_MAT2d_Connexion.def("DynamicType", (const opencascade::handle<Standard_Type> & (MAT2d_Connexion::*)() const ) &MAT2d_Connexion::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\MAT2d_MiniPath.hxx
	py::class_<MAT2d_MiniPath, std::unique_ptr<MAT2d_MiniPath, Deleter<MAT2d_MiniPath>>> cls_MAT2d_MiniPath(mod, "MAT2d_MiniPath", "MiniPath computes a path to link all the lines in a set of lines. The path is described as a set of connexions.");
	cls_MAT2d_MiniPath.def(py::init<>());
	cls_MAT2d_MiniPath.def("Perform", (void (MAT2d_MiniPath::*)(const MAT2d_SequenceOfSequenceOfGeometry &, const Standard_Integer, const Standard_Boolean)) &MAT2d_MiniPath::Perform, "Computes the path to link the lines in <Figure>. the path starts on the line of index <IndStart> <Sense> = True if the Circuit turns in the trigonometric sense.", py::arg("Figure"), py::arg("IndStart"), py::arg("Sense"));
	cls_MAT2d_MiniPath.def("RunOnConnexions", (void (MAT2d_MiniPath::*)()) &MAT2d_MiniPath::RunOnConnexions, "Run on the set of connexions to compute the path. the path is an exploration of the tree which contains the connexions and their reverses. if the tree of connexions is A / | B E / | | C D F");
	cls_MAT2d_MiniPath.def("Path", (const MAT2d_SequenceOfConnexion & (MAT2d_MiniPath::*)() const ) &MAT2d_MiniPath::Path, "Returns the sequence of connexions corresponding to the path.");
	cls_MAT2d_MiniPath.def("IsConnexionsFrom", (Standard_Boolean (MAT2d_MiniPath::*)(const Standard_Integer) const ) &MAT2d_MiniPath::IsConnexionsFrom, "Returns <True> if there is one Connexion which starts on line designed by <Index>.", py::arg("Index"));
	cls_MAT2d_MiniPath.def("ConnexionsFrom", (MAT2d_SequenceOfConnexion & (MAT2d_MiniPath::*)(const Standard_Integer)) &MAT2d_MiniPath::ConnexionsFrom, "Returns the connexions which start on line designed by <Index>.", py::arg("Index"));
	cls_MAT2d_MiniPath.def("IsRoot", (Standard_Boolean (MAT2d_MiniPath::*)(const Standard_Integer) const ) &MAT2d_MiniPath::IsRoot, "Returns <True> if the line designed by <Index> is the root.", py::arg("Index"));
	cls_MAT2d_MiniPath.def("Father", (opencascade::handle<MAT2d_Connexion> (MAT2d_MiniPath::*)(const Standard_Integer)) &MAT2d_MiniPath::Father, "Returns the connexion which ends on line designed by <Index>.", py::arg("Index"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\MAT2d_CutCurve.hxx
	py::class_<MAT2d_CutCurve, std::unique_ptr<MAT2d_CutCurve, Deleter<MAT2d_CutCurve>>> cls_MAT2d_CutCurve(mod, "MAT2d_CutCurve", "Cuts a curve at the extremas of curvature and at the inflections. Constructs a trimmed Curve for each interval.");
	cls_MAT2d_CutCurve.def(py::init<>());
	cls_MAT2d_CutCurve.def(py::init<const opencascade::handle<Geom2d_Curve> &>(), py::arg("C"));
	cls_MAT2d_CutCurve.def("Perform", (void (MAT2d_CutCurve::*)(const opencascade::handle<Geom2d_Curve> &)) &MAT2d_CutCurve::Perform, "Cuts a curve at the extremas of curvature and at the inflections.", py::arg("C"));
	cls_MAT2d_CutCurve.def("Perform", (void (MAT2d_CutCurve::*)(const opencascade::handle<Geom2d_Curve> &, const MAT_Side)) &MAT2d_CutCurve::Perform, "Cuts a curve at the inflections, and at the extremas of curvature where the concavity is on <aSide>.", py::arg("C"), py::arg("aSide"));
	cls_MAT2d_CutCurve.def("PerformInf", (void (MAT2d_CutCurve::*)(const opencascade::handle<Geom2d_Curve> &)) &MAT2d_CutCurve::PerformInf, "Cuts a curve at the inflections.", py::arg("C"));
	cls_MAT2d_CutCurve.def("UnModified", (Standard_Boolean (MAT2d_CutCurve::*)() const ) &MAT2d_CutCurve::UnModified, "Returns True if the curve is not cut.");
	cls_MAT2d_CutCurve.def("NbCurves", (Standard_Integer (MAT2d_CutCurve::*)() const ) &MAT2d_CutCurve::NbCurves, "Returns the number of curves. it's allways greatest than 2.");
	cls_MAT2d_CutCurve.def("Value", (opencascade::handle<Geom2d_TrimmedCurve> (MAT2d_CutCurve::*)(const Standard_Integer) const ) &MAT2d_CutCurve::Value, "Returns the Indexth curve. raises if Index not in the range [1,NbCurves()]", py::arg("Index"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\MAT2d_Mat2d.hxx
	py::class_<MAT2d_Mat2d, std::unique_ptr<MAT2d_Mat2d, Deleter<MAT2d_Mat2d>>> cls_MAT2d_Mat2d(mod, "MAT2d_Mat2d", "this class contains the generic algoritm of computation of the bisecting locus.");
	cls_MAT2d_Mat2d.def(py::init<>());
	cls_MAT2d_Mat2d.def(py::init<const Standard_Boolean>(), py::arg("IsOpenResult"));
	cls_MAT2d_Mat2d.def("CreateMat", (void (MAT2d_Mat2d::*)(MAT2d_Tool2d &)) &MAT2d_Mat2d::CreateMat, "Algoritm of computation of the bisecting locus.", py::arg("aTool"));
	cls_MAT2d_Mat2d.def("CreateMatOpen", (void (MAT2d_Mat2d::*)(MAT2d_Tool2d &)) &MAT2d_Mat2d::CreateMatOpen, "Algoritm of computation of the bisecting locus for open wire.", py::arg("aTool"));
	cls_MAT2d_Mat2d.def("IsDone", (Standard_Boolean (MAT2d_Mat2d::*)() const ) &MAT2d_Mat2d::IsDone, "Returns <TRUE> if CreateMat has succeeded.");
	cls_MAT2d_Mat2d.def("Init", (void (MAT2d_Mat2d::*)()) &MAT2d_Mat2d::Init, "Initialize an iterator on the set of the roots of the trees of bisectors.");
	cls_MAT2d_Mat2d.def("More", (Standard_Boolean (MAT2d_Mat2d::*)() const ) &MAT2d_Mat2d::More, "Return False if there is no more roots.");
	cls_MAT2d_Mat2d.def("Next", (void (MAT2d_Mat2d::*)()) &MAT2d_Mat2d::Next, "Move to the next root.");
	cls_MAT2d_Mat2d.def("Bisector", (opencascade::handle<MAT_Bisector> (MAT2d_Mat2d::*)() const ) &MAT2d_Mat2d::Bisector, "Returns the current root.");
	cls_MAT2d_Mat2d.def("SemiInfinite", (Standard_Boolean (MAT2d_Mat2d::*)() const ) &MAT2d_Mat2d::SemiInfinite, "Returns True if there are semi_infinite bisectors. So there is a tree for each semi_infinte bisector.");
	cls_MAT2d_Mat2d.def("NumberOfBisectors", (Standard_Integer (MAT2d_Mat2d::*)() const ) &MAT2d_Mat2d::NumberOfBisectors, "Returns the total number of bisectors.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\MAT2d_SketchExplorer.hxx
	py::class_<MAT2d_SketchExplorer, std::unique_ptr<MAT2d_SketchExplorer, Deleter<MAT2d_SketchExplorer>>> cls_MAT2d_SketchExplorer(mod, "MAT2d_SketchExplorer", "SketchExplorer is an iterator on a sketch. A sketch is a set of contours, each contour is a set of curves from Geom2d. It's use by BisectingLocus.");
	cls_MAT2d_SketchExplorer.def(py::init<>());
	cls_MAT2d_SketchExplorer.def("NumberOfContours", (Standard_Integer (MAT2d_SketchExplorer::*)() const ) &MAT2d_SketchExplorer::NumberOfContours, "Returns the number of contours in the figure.");
	cls_MAT2d_SketchExplorer.def("Init", (void (MAT2d_SketchExplorer::*)(const Standard_Integer)) &MAT2d_SketchExplorer::Init, "Initializes the curves explorer on the contour of range <ContourIndex>.", py::arg("ContourIndex"));
	cls_MAT2d_SketchExplorer.def("More", (Standard_Boolean (MAT2d_SketchExplorer::*)() const ) &MAT2d_SketchExplorer::More, "Returns False if there is no more curves on the current contour.");
	cls_MAT2d_SketchExplorer.def("Next", (void (MAT2d_SketchExplorer::*)()) &MAT2d_SketchExplorer::Next, "Moves to the next curve of the current contour.");
	cls_MAT2d_SketchExplorer.def("Value", (opencascade::handle<Geom2d_Curve> (MAT2d_SketchExplorer::*)() const ) &MAT2d_SketchExplorer::Value, "Returns the current curve on the current contour.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<MAT2d_DataMapOfIntegerBisec, std::unique_ptr<MAT2d_DataMapOfIntegerBisec, Deleter<MAT2d_DataMapOfIntegerBisec>>, NCollection_BaseMap> cls_MAT2d_DataMapOfIntegerBisec(mod, "MAT2d_DataMapOfIntegerBisec", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_MAT2d_DataMapOfIntegerBisec.def(py::init<>());
	cls_MAT2d_DataMapOfIntegerBisec.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_MAT2d_DataMapOfIntegerBisec.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_MAT2d_DataMapOfIntegerBisec.def(py::init([] (const MAT2d_DataMapOfIntegerBisec &other) {return new MAT2d_DataMapOfIntegerBisec(other);}), "Copy constructor", py::arg("other"));
	cls_MAT2d_DataMapOfIntegerBisec.def("begin", (MAT2d_DataMapOfIntegerBisec::iterator (MAT2d_DataMapOfIntegerBisec::*)() const ) &MAT2d_DataMapOfIntegerBisec::begin, "Returns an iterator pointing to the first element in the map.");
	cls_MAT2d_DataMapOfIntegerBisec.def("end", (MAT2d_DataMapOfIntegerBisec::iterator (MAT2d_DataMapOfIntegerBisec::*)() const ) &MAT2d_DataMapOfIntegerBisec::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_MAT2d_DataMapOfIntegerBisec.def("cbegin", (MAT2d_DataMapOfIntegerBisec::const_iterator (MAT2d_DataMapOfIntegerBisec::*)() const ) &MAT2d_DataMapOfIntegerBisec::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_MAT2d_DataMapOfIntegerBisec.def("cend", (MAT2d_DataMapOfIntegerBisec::const_iterator (MAT2d_DataMapOfIntegerBisec::*)() const ) &MAT2d_DataMapOfIntegerBisec::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_MAT2d_DataMapOfIntegerBisec.def("Exchange", (void (MAT2d_DataMapOfIntegerBisec::*)(MAT2d_DataMapOfIntegerBisec &)) &MAT2d_DataMapOfIntegerBisec::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_MAT2d_DataMapOfIntegerBisec.def("Assign", (MAT2d_DataMapOfIntegerBisec & (MAT2d_DataMapOfIntegerBisec::*)(const MAT2d_DataMapOfIntegerBisec &)) &MAT2d_DataMapOfIntegerBisec::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_MAT2d_DataMapOfIntegerBisec.def("assign", (MAT2d_DataMapOfIntegerBisec & (MAT2d_DataMapOfIntegerBisec::*)(const MAT2d_DataMapOfIntegerBisec &)) &MAT2d_DataMapOfIntegerBisec::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_MAT2d_DataMapOfIntegerBisec.def("ReSize", (void (MAT2d_DataMapOfIntegerBisec::*)(const Standard_Integer)) &MAT2d_DataMapOfIntegerBisec::ReSize, "ReSize", py::arg("N"));
	cls_MAT2d_DataMapOfIntegerBisec.def("Bind", (Standard_Boolean (MAT2d_DataMapOfIntegerBisec::*)(const Standard_Integer &, const Bisector_Bisec &)) &MAT2d_DataMapOfIntegerBisec::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_MAT2d_DataMapOfIntegerBisec.def("Bound", (Bisector_Bisec * (MAT2d_DataMapOfIntegerBisec::*)(const Standard_Integer &, const Bisector_Bisec &)) &MAT2d_DataMapOfIntegerBisec::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_MAT2d_DataMapOfIntegerBisec.def("IsBound", (Standard_Boolean (MAT2d_DataMapOfIntegerBisec::*)(const Standard_Integer &) const ) &MAT2d_DataMapOfIntegerBisec::IsBound, "IsBound", py::arg("theKey"));
	cls_MAT2d_DataMapOfIntegerBisec.def("UnBind", (Standard_Boolean (MAT2d_DataMapOfIntegerBisec::*)(const Standard_Integer &)) &MAT2d_DataMapOfIntegerBisec::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_MAT2d_DataMapOfIntegerBisec.def("Seek", (const Bisector_Bisec * (MAT2d_DataMapOfIntegerBisec::*)(const Standard_Integer &) const ) &MAT2d_DataMapOfIntegerBisec::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_MAT2d_DataMapOfIntegerBisec.def("Find", (const Bisector_Bisec & (MAT2d_DataMapOfIntegerBisec::*)(const Standard_Integer &) const ) &MAT2d_DataMapOfIntegerBisec::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_MAT2d_DataMapOfIntegerBisec.def("Find", (Standard_Boolean (MAT2d_DataMapOfIntegerBisec::*)(const Standard_Integer &, Bisector_Bisec &) const ) &MAT2d_DataMapOfIntegerBisec::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_MAT2d_DataMapOfIntegerBisec.def("__call__", (const Bisector_Bisec & (MAT2d_DataMapOfIntegerBisec::*)(const Standard_Integer &) const ) &MAT2d_DataMapOfIntegerBisec::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_MAT2d_DataMapOfIntegerBisec.def("ChangeSeek", (Bisector_Bisec * (MAT2d_DataMapOfIntegerBisec::*)(const Standard_Integer &)) &MAT2d_DataMapOfIntegerBisec::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_MAT2d_DataMapOfIntegerBisec.def("ChangeFind", (Bisector_Bisec & (MAT2d_DataMapOfIntegerBisec::*)(const Standard_Integer &)) &MAT2d_DataMapOfIntegerBisec::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_MAT2d_DataMapOfIntegerBisec.def("__call__", (Bisector_Bisec & (MAT2d_DataMapOfIntegerBisec::*)(const Standard_Integer &)) &MAT2d_DataMapOfIntegerBisec::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_MAT2d_DataMapOfIntegerBisec.def("Clear", [](MAT2d_DataMapOfIntegerBisec &self) -> void { return self.Clear(); });
	cls_MAT2d_DataMapOfIntegerBisec.def("Clear", (void (MAT2d_DataMapOfIntegerBisec::*)(const Standard_Boolean)) &MAT2d_DataMapOfIntegerBisec::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_MAT2d_DataMapOfIntegerBisec.def("Clear", (void (MAT2d_DataMapOfIntegerBisec::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &MAT2d_DataMapOfIntegerBisec::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_MAT2d_DataMapOfIntegerBisec.def("Size", (Standard_Integer (MAT2d_DataMapOfIntegerBisec::*)() const ) &MAT2d_DataMapOfIntegerBisec::Size, "Size");
	cls_MAT2d_DataMapOfIntegerBisec.def("__iter__", [](const MAT2d_DataMapOfIntegerBisec &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\MAT2d_DataMapOfIntegerBisec.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<MAT2d_DataMapOfIntegerPnt2d, std::unique_ptr<MAT2d_DataMapOfIntegerPnt2d, Deleter<MAT2d_DataMapOfIntegerPnt2d>>, NCollection_BaseMap> cls_MAT2d_DataMapOfIntegerPnt2d(mod, "MAT2d_DataMapOfIntegerPnt2d", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_MAT2d_DataMapOfIntegerPnt2d.def(py::init<>());
	cls_MAT2d_DataMapOfIntegerPnt2d.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_MAT2d_DataMapOfIntegerPnt2d.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_MAT2d_DataMapOfIntegerPnt2d.def(py::init([] (const MAT2d_DataMapOfIntegerPnt2d &other) {return new MAT2d_DataMapOfIntegerPnt2d(other);}), "Copy constructor", py::arg("other"));
	cls_MAT2d_DataMapOfIntegerPnt2d.def("begin", (MAT2d_DataMapOfIntegerPnt2d::iterator (MAT2d_DataMapOfIntegerPnt2d::*)() const ) &MAT2d_DataMapOfIntegerPnt2d::begin, "Returns an iterator pointing to the first element in the map.");
	cls_MAT2d_DataMapOfIntegerPnt2d.def("end", (MAT2d_DataMapOfIntegerPnt2d::iterator (MAT2d_DataMapOfIntegerPnt2d::*)() const ) &MAT2d_DataMapOfIntegerPnt2d::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_MAT2d_DataMapOfIntegerPnt2d.def("cbegin", (MAT2d_DataMapOfIntegerPnt2d::const_iterator (MAT2d_DataMapOfIntegerPnt2d::*)() const ) &MAT2d_DataMapOfIntegerPnt2d::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_MAT2d_DataMapOfIntegerPnt2d.def("cend", (MAT2d_DataMapOfIntegerPnt2d::const_iterator (MAT2d_DataMapOfIntegerPnt2d::*)() const ) &MAT2d_DataMapOfIntegerPnt2d::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_MAT2d_DataMapOfIntegerPnt2d.def("Exchange", (void (MAT2d_DataMapOfIntegerPnt2d::*)(MAT2d_DataMapOfIntegerPnt2d &)) &MAT2d_DataMapOfIntegerPnt2d::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_MAT2d_DataMapOfIntegerPnt2d.def("Assign", (MAT2d_DataMapOfIntegerPnt2d & (MAT2d_DataMapOfIntegerPnt2d::*)(const MAT2d_DataMapOfIntegerPnt2d &)) &MAT2d_DataMapOfIntegerPnt2d::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_MAT2d_DataMapOfIntegerPnt2d.def("assign", (MAT2d_DataMapOfIntegerPnt2d & (MAT2d_DataMapOfIntegerPnt2d::*)(const MAT2d_DataMapOfIntegerPnt2d &)) &MAT2d_DataMapOfIntegerPnt2d::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_MAT2d_DataMapOfIntegerPnt2d.def("ReSize", (void (MAT2d_DataMapOfIntegerPnt2d::*)(const Standard_Integer)) &MAT2d_DataMapOfIntegerPnt2d::ReSize, "ReSize", py::arg("N"));
	cls_MAT2d_DataMapOfIntegerPnt2d.def("Bind", (Standard_Boolean (MAT2d_DataMapOfIntegerPnt2d::*)(const Standard_Integer &, const gp_Pnt2d &)) &MAT2d_DataMapOfIntegerPnt2d::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_MAT2d_DataMapOfIntegerPnt2d.def("Bound", (gp_Pnt2d * (MAT2d_DataMapOfIntegerPnt2d::*)(const Standard_Integer &, const gp_Pnt2d &)) &MAT2d_DataMapOfIntegerPnt2d::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_MAT2d_DataMapOfIntegerPnt2d.def("IsBound", (Standard_Boolean (MAT2d_DataMapOfIntegerPnt2d::*)(const Standard_Integer &) const ) &MAT2d_DataMapOfIntegerPnt2d::IsBound, "IsBound", py::arg("theKey"));
	cls_MAT2d_DataMapOfIntegerPnt2d.def("UnBind", (Standard_Boolean (MAT2d_DataMapOfIntegerPnt2d::*)(const Standard_Integer &)) &MAT2d_DataMapOfIntegerPnt2d::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_MAT2d_DataMapOfIntegerPnt2d.def("Seek", (const gp_Pnt2d * (MAT2d_DataMapOfIntegerPnt2d::*)(const Standard_Integer &) const ) &MAT2d_DataMapOfIntegerPnt2d::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_MAT2d_DataMapOfIntegerPnt2d.def("Find", (const gp_Pnt2d & (MAT2d_DataMapOfIntegerPnt2d::*)(const Standard_Integer &) const ) &MAT2d_DataMapOfIntegerPnt2d::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_MAT2d_DataMapOfIntegerPnt2d.def("Find", (Standard_Boolean (MAT2d_DataMapOfIntegerPnt2d::*)(const Standard_Integer &, gp_Pnt2d &) const ) &MAT2d_DataMapOfIntegerPnt2d::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_MAT2d_DataMapOfIntegerPnt2d.def("__call__", (const gp_Pnt2d & (MAT2d_DataMapOfIntegerPnt2d::*)(const Standard_Integer &) const ) &MAT2d_DataMapOfIntegerPnt2d::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_MAT2d_DataMapOfIntegerPnt2d.def("ChangeSeek", (gp_Pnt2d * (MAT2d_DataMapOfIntegerPnt2d::*)(const Standard_Integer &)) &MAT2d_DataMapOfIntegerPnt2d::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_MAT2d_DataMapOfIntegerPnt2d.def("ChangeFind", (gp_Pnt2d & (MAT2d_DataMapOfIntegerPnt2d::*)(const Standard_Integer &)) &MAT2d_DataMapOfIntegerPnt2d::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_MAT2d_DataMapOfIntegerPnt2d.def("__call__", (gp_Pnt2d & (MAT2d_DataMapOfIntegerPnt2d::*)(const Standard_Integer &)) &MAT2d_DataMapOfIntegerPnt2d::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_MAT2d_DataMapOfIntegerPnt2d.def("Clear", [](MAT2d_DataMapOfIntegerPnt2d &self) -> void { return self.Clear(); });
	cls_MAT2d_DataMapOfIntegerPnt2d.def("Clear", (void (MAT2d_DataMapOfIntegerPnt2d::*)(const Standard_Boolean)) &MAT2d_DataMapOfIntegerPnt2d::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_MAT2d_DataMapOfIntegerPnt2d.def("Clear", (void (MAT2d_DataMapOfIntegerPnt2d::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &MAT2d_DataMapOfIntegerPnt2d::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_MAT2d_DataMapOfIntegerPnt2d.def("Size", (Standard_Integer (MAT2d_DataMapOfIntegerPnt2d::*)() const ) &MAT2d_DataMapOfIntegerPnt2d::Size, "Size");
	cls_MAT2d_DataMapOfIntegerPnt2d.def("__iter__", [](const MAT2d_DataMapOfIntegerPnt2d &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\MAT2d_DataMapOfIntegerPnt2d.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<MAT2d_DataMapOfIntegerVec2d, std::unique_ptr<MAT2d_DataMapOfIntegerVec2d, Deleter<MAT2d_DataMapOfIntegerVec2d>>, NCollection_BaseMap> cls_MAT2d_DataMapOfIntegerVec2d(mod, "MAT2d_DataMapOfIntegerVec2d", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_MAT2d_DataMapOfIntegerVec2d.def(py::init<>());
	cls_MAT2d_DataMapOfIntegerVec2d.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_MAT2d_DataMapOfIntegerVec2d.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_MAT2d_DataMapOfIntegerVec2d.def(py::init([] (const MAT2d_DataMapOfIntegerVec2d &other) {return new MAT2d_DataMapOfIntegerVec2d(other);}), "Copy constructor", py::arg("other"));
	cls_MAT2d_DataMapOfIntegerVec2d.def("begin", (MAT2d_DataMapOfIntegerVec2d::iterator (MAT2d_DataMapOfIntegerVec2d::*)() const ) &MAT2d_DataMapOfIntegerVec2d::begin, "Returns an iterator pointing to the first element in the map.");
	cls_MAT2d_DataMapOfIntegerVec2d.def("end", (MAT2d_DataMapOfIntegerVec2d::iterator (MAT2d_DataMapOfIntegerVec2d::*)() const ) &MAT2d_DataMapOfIntegerVec2d::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_MAT2d_DataMapOfIntegerVec2d.def("cbegin", (MAT2d_DataMapOfIntegerVec2d::const_iterator (MAT2d_DataMapOfIntegerVec2d::*)() const ) &MAT2d_DataMapOfIntegerVec2d::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_MAT2d_DataMapOfIntegerVec2d.def("cend", (MAT2d_DataMapOfIntegerVec2d::const_iterator (MAT2d_DataMapOfIntegerVec2d::*)() const ) &MAT2d_DataMapOfIntegerVec2d::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_MAT2d_DataMapOfIntegerVec2d.def("Exchange", (void (MAT2d_DataMapOfIntegerVec2d::*)(MAT2d_DataMapOfIntegerVec2d &)) &MAT2d_DataMapOfIntegerVec2d::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_MAT2d_DataMapOfIntegerVec2d.def("Assign", (MAT2d_DataMapOfIntegerVec2d & (MAT2d_DataMapOfIntegerVec2d::*)(const MAT2d_DataMapOfIntegerVec2d &)) &MAT2d_DataMapOfIntegerVec2d::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_MAT2d_DataMapOfIntegerVec2d.def("assign", (MAT2d_DataMapOfIntegerVec2d & (MAT2d_DataMapOfIntegerVec2d::*)(const MAT2d_DataMapOfIntegerVec2d &)) &MAT2d_DataMapOfIntegerVec2d::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_MAT2d_DataMapOfIntegerVec2d.def("ReSize", (void (MAT2d_DataMapOfIntegerVec2d::*)(const Standard_Integer)) &MAT2d_DataMapOfIntegerVec2d::ReSize, "ReSize", py::arg("N"));
	cls_MAT2d_DataMapOfIntegerVec2d.def("Bind", (Standard_Boolean (MAT2d_DataMapOfIntegerVec2d::*)(const Standard_Integer &, const gp_Vec2d &)) &MAT2d_DataMapOfIntegerVec2d::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_MAT2d_DataMapOfIntegerVec2d.def("Bound", (gp_Vec2d * (MAT2d_DataMapOfIntegerVec2d::*)(const Standard_Integer &, const gp_Vec2d &)) &MAT2d_DataMapOfIntegerVec2d::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_MAT2d_DataMapOfIntegerVec2d.def("IsBound", (Standard_Boolean (MAT2d_DataMapOfIntegerVec2d::*)(const Standard_Integer &) const ) &MAT2d_DataMapOfIntegerVec2d::IsBound, "IsBound", py::arg("theKey"));
	cls_MAT2d_DataMapOfIntegerVec2d.def("UnBind", (Standard_Boolean (MAT2d_DataMapOfIntegerVec2d::*)(const Standard_Integer &)) &MAT2d_DataMapOfIntegerVec2d::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_MAT2d_DataMapOfIntegerVec2d.def("Seek", (const gp_Vec2d * (MAT2d_DataMapOfIntegerVec2d::*)(const Standard_Integer &) const ) &MAT2d_DataMapOfIntegerVec2d::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_MAT2d_DataMapOfIntegerVec2d.def("Find", (const gp_Vec2d & (MAT2d_DataMapOfIntegerVec2d::*)(const Standard_Integer &) const ) &MAT2d_DataMapOfIntegerVec2d::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_MAT2d_DataMapOfIntegerVec2d.def("Find", (Standard_Boolean (MAT2d_DataMapOfIntegerVec2d::*)(const Standard_Integer &, gp_Vec2d &) const ) &MAT2d_DataMapOfIntegerVec2d::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_MAT2d_DataMapOfIntegerVec2d.def("__call__", (const gp_Vec2d & (MAT2d_DataMapOfIntegerVec2d::*)(const Standard_Integer &) const ) &MAT2d_DataMapOfIntegerVec2d::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_MAT2d_DataMapOfIntegerVec2d.def("ChangeSeek", (gp_Vec2d * (MAT2d_DataMapOfIntegerVec2d::*)(const Standard_Integer &)) &MAT2d_DataMapOfIntegerVec2d::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_MAT2d_DataMapOfIntegerVec2d.def("ChangeFind", (gp_Vec2d & (MAT2d_DataMapOfIntegerVec2d::*)(const Standard_Integer &)) &MAT2d_DataMapOfIntegerVec2d::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_MAT2d_DataMapOfIntegerVec2d.def("__call__", (gp_Vec2d & (MAT2d_DataMapOfIntegerVec2d::*)(const Standard_Integer &)) &MAT2d_DataMapOfIntegerVec2d::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_MAT2d_DataMapOfIntegerVec2d.def("Clear", [](MAT2d_DataMapOfIntegerVec2d &self) -> void { return self.Clear(); });
	cls_MAT2d_DataMapOfIntegerVec2d.def("Clear", (void (MAT2d_DataMapOfIntegerVec2d::*)(const Standard_Boolean)) &MAT2d_DataMapOfIntegerVec2d::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_MAT2d_DataMapOfIntegerVec2d.def("Clear", (void (MAT2d_DataMapOfIntegerVec2d::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &MAT2d_DataMapOfIntegerVec2d::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_MAT2d_DataMapOfIntegerVec2d.def("Size", (Standard_Integer (MAT2d_DataMapOfIntegerVec2d::*)() const ) &MAT2d_DataMapOfIntegerVec2d::Size, "Size");
	cls_MAT2d_DataMapOfIntegerVec2d.def("__iter__", [](const MAT2d_DataMapOfIntegerVec2d &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\MAT2d_DataMapOfIntegerVec2d.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<MAT2d_DataMapOfBiIntInteger, std::unique_ptr<MAT2d_DataMapOfBiIntInteger, Deleter<MAT2d_DataMapOfBiIntInteger>>, NCollection_BaseMap> cls_MAT2d_DataMapOfBiIntInteger(mod, "MAT2d_DataMapOfBiIntInteger", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_MAT2d_DataMapOfBiIntInteger.def(py::init<>());
	cls_MAT2d_DataMapOfBiIntInteger.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_MAT2d_DataMapOfBiIntInteger.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_MAT2d_DataMapOfBiIntInteger.def(py::init([] (const MAT2d_DataMapOfBiIntInteger &other) {return new MAT2d_DataMapOfBiIntInteger(other);}), "Copy constructor", py::arg("other"));
	cls_MAT2d_DataMapOfBiIntInteger.def("begin", (MAT2d_DataMapOfBiIntInteger::iterator (MAT2d_DataMapOfBiIntInteger::*)() const ) &MAT2d_DataMapOfBiIntInteger::begin, "Returns an iterator pointing to the first element in the map.");
	cls_MAT2d_DataMapOfBiIntInteger.def("end", (MAT2d_DataMapOfBiIntInteger::iterator (MAT2d_DataMapOfBiIntInteger::*)() const ) &MAT2d_DataMapOfBiIntInteger::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_MAT2d_DataMapOfBiIntInteger.def("cbegin", (MAT2d_DataMapOfBiIntInteger::const_iterator (MAT2d_DataMapOfBiIntInteger::*)() const ) &MAT2d_DataMapOfBiIntInteger::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_MAT2d_DataMapOfBiIntInteger.def("cend", (MAT2d_DataMapOfBiIntInteger::const_iterator (MAT2d_DataMapOfBiIntInteger::*)() const ) &MAT2d_DataMapOfBiIntInteger::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_MAT2d_DataMapOfBiIntInteger.def("Exchange", (void (MAT2d_DataMapOfBiIntInteger::*)(MAT2d_DataMapOfBiIntInteger &)) &MAT2d_DataMapOfBiIntInteger::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_MAT2d_DataMapOfBiIntInteger.def("Assign", (MAT2d_DataMapOfBiIntInteger & (MAT2d_DataMapOfBiIntInteger::*)(const MAT2d_DataMapOfBiIntInteger &)) &MAT2d_DataMapOfBiIntInteger::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_MAT2d_DataMapOfBiIntInteger.def("assign", (MAT2d_DataMapOfBiIntInteger & (MAT2d_DataMapOfBiIntInteger::*)(const MAT2d_DataMapOfBiIntInteger &)) &MAT2d_DataMapOfBiIntInteger::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_MAT2d_DataMapOfBiIntInteger.def("ReSize", (void (MAT2d_DataMapOfBiIntInteger::*)(const Standard_Integer)) &MAT2d_DataMapOfBiIntInteger::ReSize, "ReSize", py::arg("N"));
	cls_MAT2d_DataMapOfBiIntInteger.def("Bind", (Standard_Boolean (MAT2d_DataMapOfBiIntInteger::*)(const MAT2d_BiInt &, const Standard_Integer &)) &MAT2d_DataMapOfBiIntInteger::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_MAT2d_DataMapOfBiIntInteger.def("Bound", (Standard_Integer * (MAT2d_DataMapOfBiIntInteger::*)(const MAT2d_BiInt &, const Standard_Integer &)) &MAT2d_DataMapOfBiIntInteger::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_MAT2d_DataMapOfBiIntInteger.def("IsBound", (Standard_Boolean (MAT2d_DataMapOfBiIntInteger::*)(const MAT2d_BiInt &) const ) &MAT2d_DataMapOfBiIntInteger::IsBound, "IsBound", py::arg("theKey"));
	cls_MAT2d_DataMapOfBiIntInteger.def("UnBind", (Standard_Boolean (MAT2d_DataMapOfBiIntInteger::*)(const MAT2d_BiInt &)) &MAT2d_DataMapOfBiIntInteger::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_MAT2d_DataMapOfBiIntInteger.def("Seek", (const Standard_Integer * (MAT2d_DataMapOfBiIntInteger::*)(const MAT2d_BiInt &) const ) &MAT2d_DataMapOfBiIntInteger::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_MAT2d_DataMapOfBiIntInteger.def("Find", (const Standard_Integer & (MAT2d_DataMapOfBiIntInteger::*)(const MAT2d_BiInt &) const ) &MAT2d_DataMapOfBiIntInteger::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_MAT2d_DataMapOfBiIntInteger.def("Find", (Standard_Boolean (MAT2d_DataMapOfBiIntInteger::*)(const MAT2d_BiInt &, Standard_Integer &) const ) &MAT2d_DataMapOfBiIntInteger::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_MAT2d_DataMapOfBiIntInteger.def("__call__", (const Standard_Integer & (MAT2d_DataMapOfBiIntInteger::*)(const MAT2d_BiInt &) const ) &MAT2d_DataMapOfBiIntInteger::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_MAT2d_DataMapOfBiIntInteger.def("ChangeSeek", (Standard_Integer * (MAT2d_DataMapOfBiIntInteger::*)(const MAT2d_BiInt &)) &MAT2d_DataMapOfBiIntInteger::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_MAT2d_DataMapOfBiIntInteger.def("ChangeFind", (Standard_Integer & (MAT2d_DataMapOfBiIntInteger::*)(const MAT2d_BiInt &)) &MAT2d_DataMapOfBiIntInteger::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_MAT2d_DataMapOfBiIntInteger.def("__call__", (Standard_Integer & (MAT2d_DataMapOfBiIntInteger::*)(const MAT2d_BiInt &)) &MAT2d_DataMapOfBiIntInteger::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_MAT2d_DataMapOfBiIntInteger.def("Clear", [](MAT2d_DataMapOfBiIntInteger &self) -> void { return self.Clear(); });
	cls_MAT2d_DataMapOfBiIntInteger.def("Clear", (void (MAT2d_DataMapOfBiIntInteger::*)(const Standard_Boolean)) &MAT2d_DataMapOfBiIntInteger::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_MAT2d_DataMapOfBiIntInteger.def("Clear", (void (MAT2d_DataMapOfBiIntInteger::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &MAT2d_DataMapOfBiIntInteger::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_MAT2d_DataMapOfBiIntInteger.def("Size", (Standard_Integer (MAT2d_DataMapOfBiIntInteger::*)() const ) &MAT2d_DataMapOfBiIntInteger::Size, "Size");
	cls_MAT2d_DataMapOfBiIntInteger.def("__iter__", [](const MAT2d_DataMapOfBiIntInteger &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\MAT2d_DataMapOfBiIntInteger.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
	py::class_<MAT2d_SequenceOfSequenceOfCurve, std::unique_ptr<MAT2d_SequenceOfSequenceOfCurve, Deleter<MAT2d_SequenceOfSequenceOfCurve>>, NCollection_BaseSequence> cls_MAT2d_SequenceOfSequenceOfCurve(mod, "MAT2d_SequenceOfSequenceOfCurve", "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n");
	cls_MAT2d_SequenceOfSequenceOfCurve.def(py::init<>());
	cls_MAT2d_SequenceOfSequenceOfCurve.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_MAT2d_SequenceOfSequenceOfCurve.def(py::init([] (const MAT2d_SequenceOfSequenceOfCurve &other) {return new MAT2d_SequenceOfSequenceOfCurve(other);}), "Copy constructor", py::arg("other"));
	cls_MAT2d_SequenceOfSequenceOfCurve.def("begin", (MAT2d_SequenceOfSequenceOfCurve::iterator (MAT2d_SequenceOfSequenceOfCurve::*)() const ) &MAT2d_SequenceOfSequenceOfCurve::begin, "Returns an iterator pointing to the first element in the sequence.");
	cls_MAT2d_SequenceOfSequenceOfCurve.def("end", (MAT2d_SequenceOfSequenceOfCurve::iterator (MAT2d_SequenceOfSequenceOfCurve::*)() const ) &MAT2d_SequenceOfSequenceOfCurve::end, "Returns an iterator referring to the past-the-end element in the sequence.");
	cls_MAT2d_SequenceOfSequenceOfCurve.def("cbegin", (MAT2d_SequenceOfSequenceOfCurve::const_iterator (MAT2d_SequenceOfSequenceOfCurve::*)() const ) &MAT2d_SequenceOfSequenceOfCurve::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
	cls_MAT2d_SequenceOfSequenceOfCurve.def("cend", (MAT2d_SequenceOfSequenceOfCurve::const_iterator (MAT2d_SequenceOfSequenceOfCurve::*)() const ) &MAT2d_SequenceOfSequenceOfCurve::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
	cls_MAT2d_SequenceOfSequenceOfCurve.def("Size", (Standard_Integer (MAT2d_SequenceOfSequenceOfCurve::*)() const ) &MAT2d_SequenceOfSequenceOfCurve::Size, "Number of items");
	cls_MAT2d_SequenceOfSequenceOfCurve.def("Length", (Standard_Integer (MAT2d_SequenceOfSequenceOfCurve::*)() const ) &MAT2d_SequenceOfSequenceOfCurve::Length, "Number of items");
	cls_MAT2d_SequenceOfSequenceOfCurve.def("Lower", (Standard_Integer (MAT2d_SequenceOfSequenceOfCurve::*)() const ) &MAT2d_SequenceOfSequenceOfCurve::Lower, "Method for consistency with other collections.");
	cls_MAT2d_SequenceOfSequenceOfCurve.def("Upper", (Standard_Integer (MAT2d_SequenceOfSequenceOfCurve::*)() const ) &MAT2d_SequenceOfSequenceOfCurve::Upper, "Method for consistency with other collections.");
	cls_MAT2d_SequenceOfSequenceOfCurve.def("IsEmpty", (Standard_Boolean (MAT2d_SequenceOfSequenceOfCurve::*)() const ) &MAT2d_SequenceOfSequenceOfCurve::IsEmpty, "Empty query");
	cls_MAT2d_SequenceOfSequenceOfCurve.def("Reverse", (void (MAT2d_SequenceOfSequenceOfCurve::*)()) &MAT2d_SequenceOfSequenceOfCurve::Reverse, "Reverse sequence");
	cls_MAT2d_SequenceOfSequenceOfCurve.def("Exchange", (void (MAT2d_SequenceOfSequenceOfCurve::*)(const Standard_Integer, const Standard_Integer)) &MAT2d_SequenceOfSequenceOfCurve::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
	cls_MAT2d_SequenceOfSequenceOfCurve.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &MAT2d_SequenceOfSequenceOfCurve::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
	cls_MAT2d_SequenceOfSequenceOfCurve.def("Clear", [](MAT2d_SequenceOfSequenceOfCurve &self) -> void { return self.Clear(); });
	cls_MAT2d_SequenceOfSequenceOfCurve.def("Clear", (void (MAT2d_SequenceOfSequenceOfCurve::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &MAT2d_SequenceOfSequenceOfCurve::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
	cls_MAT2d_SequenceOfSequenceOfCurve.def("Assign", (MAT2d_SequenceOfSequenceOfCurve & (MAT2d_SequenceOfSequenceOfCurve::*)(const MAT2d_SequenceOfSequenceOfCurve &)) &MAT2d_SequenceOfSequenceOfCurve::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
	cls_MAT2d_SequenceOfSequenceOfCurve.def("assign", (MAT2d_SequenceOfSequenceOfCurve & (MAT2d_SequenceOfSequenceOfCurve::*)(const MAT2d_SequenceOfSequenceOfCurve &)) &MAT2d_SequenceOfSequenceOfCurve::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_MAT2d_SequenceOfSequenceOfCurve.def("Remove", (void (MAT2d_SequenceOfSequenceOfCurve::*)(MAT2d_SequenceOfSequenceOfCurve::Iterator &)) &MAT2d_SequenceOfSequenceOfCurve::Remove, "Remove one item", py::arg("thePosition"));
	cls_MAT2d_SequenceOfSequenceOfCurve.def("Remove", (void (MAT2d_SequenceOfSequenceOfCurve::*)(const Standard_Integer)) &MAT2d_SequenceOfSequenceOfCurve::Remove, "Remove one item", py::arg("theIndex"));
	cls_MAT2d_SequenceOfSequenceOfCurve.def("Remove", (void (MAT2d_SequenceOfSequenceOfCurve::*)(const Standard_Integer, const Standard_Integer)) &MAT2d_SequenceOfSequenceOfCurve::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
	cls_MAT2d_SequenceOfSequenceOfCurve.def("Append", (void (MAT2d_SequenceOfSequenceOfCurve::*)(const TColGeom2d_SequenceOfCurve &)) &MAT2d_SequenceOfSequenceOfCurve::Append, "Append one item", py::arg("theItem"));
	cls_MAT2d_SequenceOfSequenceOfCurve.def("Append", (void (MAT2d_SequenceOfSequenceOfCurve::*)(MAT2d_SequenceOfSequenceOfCurve &)) &MAT2d_SequenceOfSequenceOfCurve::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
	cls_MAT2d_SequenceOfSequenceOfCurve.def("Prepend", (void (MAT2d_SequenceOfSequenceOfCurve::*)(const TColGeom2d_SequenceOfCurve &)) &MAT2d_SequenceOfSequenceOfCurve::Prepend, "Prepend one item", py::arg("theItem"));
	cls_MAT2d_SequenceOfSequenceOfCurve.def("Prepend", (void (MAT2d_SequenceOfSequenceOfCurve::*)(MAT2d_SequenceOfSequenceOfCurve &)) &MAT2d_SequenceOfSequenceOfCurve::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
	cls_MAT2d_SequenceOfSequenceOfCurve.def("InsertBefore", (void (MAT2d_SequenceOfSequenceOfCurve::*)(const Standard_Integer, const TColGeom2d_SequenceOfCurve &)) &MAT2d_SequenceOfSequenceOfCurve::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
	cls_MAT2d_SequenceOfSequenceOfCurve.def("InsertBefore", (void (MAT2d_SequenceOfSequenceOfCurve::*)(const Standard_Integer, MAT2d_SequenceOfSequenceOfCurve &)) &MAT2d_SequenceOfSequenceOfCurve::InsertBefore, "InsertBefore theIndex another sequence", py::arg("theIndex"), py::arg("theSeq"));
	cls_MAT2d_SequenceOfSequenceOfCurve.def("InsertAfter", (void (MAT2d_SequenceOfSequenceOfCurve::*)(MAT2d_SequenceOfSequenceOfCurve::Iterator &, const TColGeom2d_SequenceOfCurve &)) &MAT2d_SequenceOfSequenceOfCurve::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
	cls_MAT2d_SequenceOfSequenceOfCurve.def("InsertAfter", (void (MAT2d_SequenceOfSequenceOfCurve::*)(const Standard_Integer, MAT2d_SequenceOfSequenceOfCurve &)) &MAT2d_SequenceOfSequenceOfCurve::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theSeq"));
	cls_MAT2d_SequenceOfSequenceOfCurve.def("InsertAfter", (void (MAT2d_SequenceOfSequenceOfCurve::*)(const Standard_Integer, const TColGeom2d_SequenceOfCurve &)) &MAT2d_SequenceOfSequenceOfCurve::InsertAfter, "InsertAfter theIndex another sequence", py::arg("theIndex"), py::arg("theItem"));
	cls_MAT2d_SequenceOfSequenceOfCurve.def("Split", (void (MAT2d_SequenceOfSequenceOfCurve::*)(const Standard_Integer, MAT2d_SequenceOfSequenceOfCurve &)) &MAT2d_SequenceOfSequenceOfCurve::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
	cls_MAT2d_SequenceOfSequenceOfCurve.def("First", (const TColGeom2d_SequenceOfCurve & (MAT2d_SequenceOfSequenceOfCurve::*)() const ) &MAT2d_SequenceOfSequenceOfCurve::First, "First item access");
	cls_MAT2d_SequenceOfSequenceOfCurve.def("ChangeFirst", (TColGeom2d_SequenceOfCurve & (MAT2d_SequenceOfSequenceOfCurve::*)()) &MAT2d_SequenceOfSequenceOfCurve::ChangeFirst, "First item access");
	cls_MAT2d_SequenceOfSequenceOfCurve.def("Last", (const TColGeom2d_SequenceOfCurve & (MAT2d_SequenceOfSequenceOfCurve::*)() const ) &MAT2d_SequenceOfSequenceOfCurve::Last, "Last item access");
	cls_MAT2d_SequenceOfSequenceOfCurve.def("ChangeLast", (TColGeom2d_SequenceOfCurve & (MAT2d_SequenceOfSequenceOfCurve::*)()) &MAT2d_SequenceOfSequenceOfCurve::ChangeLast, "Last item access");
	cls_MAT2d_SequenceOfSequenceOfCurve.def("Value", (const TColGeom2d_SequenceOfCurve & (MAT2d_SequenceOfSequenceOfCurve::*)(const Standard_Integer) const ) &MAT2d_SequenceOfSequenceOfCurve::Value, "Constant item access by theIndex", py::arg("theIndex"));
	cls_MAT2d_SequenceOfSequenceOfCurve.def("__call__", (const TColGeom2d_SequenceOfCurve & (MAT2d_SequenceOfSequenceOfCurve::*)(const Standard_Integer) const ) &MAT2d_SequenceOfSequenceOfCurve::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
	cls_MAT2d_SequenceOfSequenceOfCurve.def("ChangeValue", (TColGeom2d_SequenceOfCurve & (MAT2d_SequenceOfSequenceOfCurve::*)(const Standard_Integer)) &MAT2d_SequenceOfSequenceOfCurve::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
	cls_MAT2d_SequenceOfSequenceOfCurve.def("__call__", (TColGeom2d_SequenceOfCurve & (MAT2d_SequenceOfSequenceOfCurve::*)(const Standard_Integer)) &MAT2d_SequenceOfSequenceOfCurve::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
	cls_MAT2d_SequenceOfSequenceOfCurve.def("SetValue", (void (MAT2d_SequenceOfSequenceOfCurve::*)(const Standard_Integer, const TColGeom2d_SequenceOfCurve &)) &MAT2d_SequenceOfSequenceOfCurve::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
	cls_MAT2d_SequenceOfSequenceOfCurve.def("__iter__", [](const MAT2d_SequenceOfSequenceOfCurve &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array2.hxx
	py::class_<MAT2d_Array2OfConnexion, std::unique_ptr<MAT2d_Array2OfConnexion, Deleter<MAT2d_Array2OfConnexion>>> cls_MAT2d_Array2OfConnexion(mod, "MAT2d_Array2OfConnexion", "Purpose: The class Array2 represents bi-dimensional arrays of fixed size known at run time. The ranges of indices are user defined.");
	cls_MAT2d_Array2OfConnexion.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theRowLower"), py::arg("theRowUpper"), py::arg("theColLower"), py::arg("theColUpper"));
	cls_MAT2d_Array2OfConnexion.def(py::init([] (const MAT2d_Array2OfConnexion &other) {return new MAT2d_Array2OfConnexion(other);}), "Copy constructor", py::arg("other"));
	cls_MAT2d_Array2OfConnexion.def(py::init<const opencascade::handle<MAT2d_Connexion> &, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theRowLower"), py::arg("theRowUpper"), py::arg("theColLower"), py::arg("theColUpper"));
	cls_MAT2d_Array2OfConnexion.def("Init", (void (MAT2d_Array2OfConnexion::*)(const opencascade::handle<MAT2d_Connexion> &)) &MAT2d_Array2OfConnexion::Init, "Initialise the values", py::arg("theValue"));
	cls_MAT2d_Array2OfConnexion.def("Size", (Standard_Integer (MAT2d_Array2OfConnexion::*)() const ) &MAT2d_Array2OfConnexion::Size, "Size (number of items)");
	cls_MAT2d_Array2OfConnexion.def("Length", (Standard_Integer (MAT2d_Array2OfConnexion::*)() const ) &MAT2d_Array2OfConnexion::Length, "Length (number of items)");
	cls_MAT2d_Array2OfConnexion.def("RowLength", (Standard_Integer (MAT2d_Array2OfConnexion::*)() const ) &MAT2d_Array2OfConnexion::RowLength, "Returns length of the row, i.e. number of columns");
	cls_MAT2d_Array2OfConnexion.def("ColLength", (Standard_Integer (MAT2d_Array2OfConnexion::*)() const ) &MAT2d_Array2OfConnexion::ColLength, "Returns length of the column, i.e. number of rows");
	cls_MAT2d_Array2OfConnexion.def("LowerRow", (Standard_Integer (MAT2d_Array2OfConnexion::*)() const ) &MAT2d_Array2OfConnexion::LowerRow, "LowerRow");
	cls_MAT2d_Array2OfConnexion.def("UpperRow", (Standard_Integer (MAT2d_Array2OfConnexion::*)() const ) &MAT2d_Array2OfConnexion::UpperRow, "UpperRow");
	cls_MAT2d_Array2OfConnexion.def("LowerCol", (Standard_Integer (MAT2d_Array2OfConnexion::*)() const ) &MAT2d_Array2OfConnexion::LowerCol, "LowerCol");
	cls_MAT2d_Array2OfConnexion.def("UpperCol", (Standard_Integer (MAT2d_Array2OfConnexion::*)() const ) &MAT2d_Array2OfConnexion::UpperCol, "UpperCol");
	cls_MAT2d_Array2OfConnexion.def("IsDeletable", (Standard_Boolean (MAT2d_Array2OfConnexion::*)() const ) &MAT2d_Array2OfConnexion::IsDeletable, "myDeletable flag");
	cls_MAT2d_Array2OfConnexion.def("Assign", (MAT2d_Array2OfConnexion & (MAT2d_Array2OfConnexion::*)(const MAT2d_Array2OfConnexion &)) &MAT2d_Array2OfConnexion::Assign, "Assignment", py::arg("theOther"));
	cls_MAT2d_Array2OfConnexion.def("assign", (MAT2d_Array2OfConnexion & (MAT2d_Array2OfConnexion::*)(const MAT2d_Array2OfConnexion &)) &MAT2d_Array2OfConnexion::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_MAT2d_Array2OfConnexion.def("Value", (const opencascade::handle<MAT2d_Connexion> & (MAT2d_Array2OfConnexion::*)(const Standard_Integer, const Standard_Integer) const ) &MAT2d_Array2OfConnexion::Value, "Constant value access", py::arg("theRow"), py::arg("theCol"));
	cls_MAT2d_Array2OfConnexion.def("__call__", (const opencascade::handle<MAT2d_Connexion> & (MAT2d_Array2OfConnexion::*)(const Standard_Integer, const Standard_Integer) const ) &MAT2d_Array2OfConnexion::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theRow"), py::arg("theCol"));
	cls_MAT2d_Array2OfConnexion.def("ChangeValue", (opencascade::handle<MAT2d_Connexion> & (MAT2d_Array2OfConnexion::*)(const Standard_Integer, const Standard_Integer)) &MAT2d_Array2OfConnexion::ChangeValue, "Variable value access", py::arg("theRow"), py::arg("theCol"));
	cls_MAT2d_Array2OfConnexion.def("__call__", (opencascade::handle<MAT2d_Connexion> & (MAT2d_Array2OfConnexion::*)(const Standard_Integer, const Standard_Integer)) &MAT2d_Array2OfConnexion::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theRow"), py::arg("theCol"));
	cls_MAT2d_Array2OfConnexion.def("SetValue", (void (MAT2d_Array2OfConnexion::*)(const Standard_Integer, const Standard_Integer, const opencascade::handle<MAT2d_Connexion> &)) &MAT2d_Array2OfConnexion::SetValue, "SetValue", py::arg("theRow"), py::arg("theCol"), py::arg("theItem"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<MAT2d_DataMapOfIntegerConnexion, std::unique_ptr<MAT2d_DataMapOfIntegerConnexion, Deleter<MAT2d_DataMapOfIntegerConnexion>>, NCollection_BaseMap> cls_MAT2d_DataMapOfIntegerConnexion(mod, "MAT2d_DataMapOfIntegerConnexion", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_MAT2d_DataMapOfIntegerConnexion.def(py::init<>());
	cls_MAT2d_DataMapOfIntegerConnexion.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_MAT2d_DataMapOfIntegerConnexion.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_MAT2d_DataMapOfIntegerConnexion.def(py::init([] (const MAT2d_DataMapOfIntegerConnexion &other) {return new MAT2d_DataMapOfIntegerConnexion(other);}), "Copy constructor", py::arg("other"));
	cls_MAT2d_DataMapOfIntegerConnexion.def("begin", (MAT2d_DataMapOfIntegerConnexion::iterator (MAT2d_DataMapOfIntegerConnexion::*)() const ) &MAT2d_DataMapOfIntegerConnexion::begin, "Returns an iterator pointing to the first element in the map.");
	cls_MAT2d_DataMapOfIntegerConnexion.def("end", (MAT2d_DataMapOfIntegerConnexion::iterator (MAT2d_DataMapOfIntegerConnexion::*)() const ) &MAT2d_DataMapOfIntegerConnexion::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_MAT2d_DataMapOfIntegerConnexion.def("cbegin", (MAT2d_DataMapOfIntegerConnexion::const_iterator (MAT2d_DataMapOfIntegerConnexion::*)() const ) &MAT2d_DataMapOfIntegerConnexion::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_MAT2d_DataMapOfIntegerConnexion.def("cend", (MAT2d_DataMapOfIntegerConnexion::const_iterator (MAT2d_DataMapOfIntegerConnexion::*)() const ) &MAT2d_DataMapOfIntegerConnexion::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_MAT2d_DataMapOfIntegerConnexion.def("Exchange", (void (MAT2d_DataMapOfIntegerConnexion::*)(MAT2d_DataMapOfIntegerConnexion &)) &MAT2d_DataMapOfIntegerConnexion::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_MAT2d_DataMapOfIntegerConnexion.def("Assign", (MAT2d_DataMapOfIntegerConnexion & (MAT2d_DataMapOfIntegerConnexion::*)(const MAT2d_DataMapOfIntegerConnexion &)) &MAT2d_DataMapOfIntegerConnexion::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_MAT2d_DataMapOfIntegerConnexion.def("assign", (MAT2d_DataMapOfIntegerConnexion & (MAT2d_DataMapOfIntegerConnexion::*)(const MAT2d_DataMapOfIntegerConnexion &)) &MAT2d_DataMapOfIntegerConnexion::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_MAT2d_DataMapOfIntegerConnexion.def("ReSize", (void (MAT2d_DataMapOfIntegerConnexion::*)(const Standard_Integer)) &MAT2d_DataMapOfIntegerConnexion::ReSize, "ReSize", py::arg("N"));
	cls_MAT2d_DataMapOfIntegerConnexion.def("Bind", (Standard_Boolean (MAT2d_DataMapOfIntegerConnexion::*)(const Standard_Integer &, const opencascade::handle<MAT2d_Connexion> &)) &MAT2d_DataMapOfIntegerConnexion::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_MAT2d_DataMapOfIntegerConnexion.def("Bound", (opencascade::handle<MAT2d_Connexion> * (MAT2d_DataMapOfIntegerConnexion::*)(const Standard_Integer &, const opencascade::handle<MAT2d_Connexion> &)) &MAT2d_DataMapOfIntegerConnexion::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_MAT2d_DataMapOfIntegerConnexion.def("IsBound", (Standard_Boolean (MAT2d_DataMapOfIntegerConnexion::*)(const Standard_Integer &) const ) &MAT2d_DataMapOfIntegerConnexion::IsBound, "IsBound", py::arg("theKey"));
	cls_MAT2d_DataMapOfIntegerConnexion.def("UnBind", (Standard_Boolean (MAT2d_DataMapOfIntegerConnexion::*)(const Standard_Integer &)) &MAT2d_DataMapOfIntegerConnexion::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_MAT2d_DataMapOfIntegerConnexion.def("Seek", (const opencascade::handle<MAT2d_Connexion> * (MAT2d_DataMapOfIntegerConnexion::*)(const Standard_Integer &) const ) &MAT2d_DataMapOfIntegerConnexion::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_MAT2d_DataMapOfIntegerConnexion.def("Find", (const opencascade::handle<MAT2d_Connexion> & (MAT2d_DataMapOfIntegerConnexion::*)(const Standard_Integer &) const ) &MAT2d_DataMapOfIntegerConnexion::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_MAT2d_DataMapOfIntegerConnexion.def("Find", (Standard_Boolean (MAT2d_DataMapOfIntegerConnexion::*)(const Standard_Integer &, opencascade::handle<MAT2d_Connexion> &) const ) &MAT2d_DataMapOfIntegerConnexion::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_MAT2d_DataMapOfIntegerConnexion.def("__call__", (const opencascade::handle<MAT2d_Connexion> & (MAT2d_DataMapOfIntegerConnexion::*)(const Standard_Integer &) const ) &MAT2d_DataMapOfIntegerConnexion::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_MAT2d_DataMapOfIntegerConnexion.def("ChangeSeek", (opencascade::handle<MAT2d_Connexion> * (MAT2d_DataMapOfIntegerConnexion::*)(const Standard_Integer &)) &MAT2d_DataMapOfIntegerConnexion::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_MAT2d_DataMapOfIntegerConnexion.def("ChangeFind", (opencascade::handle<MAT2d_Connexion> & (MAT2d_DataMapOfIntegerConnexion::*)(const Standard_Integer &)) &MAT2d_DataMapOfIntegerConnexion::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_MAT2d_DataMapOfIntegerConnexion.def("__call__", (opencascade::handle<MAT2d_Connexion> & (MAT2d_DataMapOfIntegerConnexion::*)(const Standard_Integer &)) &MAT2d_DataMapOfIntegerConnexion::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_MAT2d_DataMapOfIntegerConnexion.def("Clear", [](MAT2d_DataMapOfIntegerConnexion &self) -> void { return self.Clear(); });
	cls_MAT2d_DataMapOfIntegerConnexion.def("Clear", (void (MAT2d_DataMapOfIntegerConnexion::*)(const Standard_Boolean)) &MAT2d_DataMapOfIntegerConnexion::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_MAT2d_DataMapOfIntegerConnexion.def("Clear", (void (MAT2d_DataMapOfIntegerConnexion::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &MAT2d_DataMapOfIntegerConnexion::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_MAT2d_DataMapOfIntegerConnexion.def("Size", (Standard_Integer (MAT2d_DataMapOfIntegerConnexion::*)() const ) &MAT2d_DataMapOfIntegerConnexion::Size, "Size");
	cls_MAT2d_DataMapOfIntegerConnexion.def("__iter__", [](const MAT2d_DataMapOfIntegerConnexion &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\MAT2d_DataMapOfIntegerConnexion.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<MAT2d_DataMapOfBiIntSequenceOfInteger, std::unique_ptr<MAT2d_DataMapOfBiIntSequenceOfInteger, Deleter<MAT2d_DataMapOfBiIntSequenceOfInteger>>, NCollection_BaseMap> cls_MAT2d_DataMapOfBiIntSequenceOfInteger(mod, "MAT2d_DataMapOfBiIntSequenceOfInteger", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_MAT2d_DataMapOfBiIntSequenceOfInteger.def(py::init<>());
	cls_MAT2d_DataMapOfBiIntSequenceOfInteger.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_MAT2d_DataMapOfBiIntSequenceOfInteger.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_MAT2d_DataMapOfBiIntSequenceOfInteger.def(py::init([] (const MAT2d_DataMapOfBiIntSequenceOfInteger &other) {return new MAT2d_DataMapOfBiIntSequenceOfInteger(other);}), "Copy constructor", py::arg("other"));
	cls_MAT2d_DataMapOfBiIntSequenceOfInteger.def("begin", (MAT2d_DataMapOfBiIntSequenceOfInteger::iterator (MAT2d_DataMapOfBiIntSequenceOfInteger::*)() const ) &MAT2d_DataMapOfBiIntSequenceOfInteger::begin, "Returns an iterator pointing to the first element in the map.");
	cls_MAT2d_DataMapOfBiIntSequenceOfInteger.def("end", (MAT2d_DataMapOfBiIntSequenceOfInteger::iterator (MAT2d_DataMapOfBiIntSequenceOfInteger::*)() const ) &MAT2d_DataMapOfBiIntSequenceOfInteger::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_MAT2d_DataMapOfBiIntSequenceOfInteger.def("cbegin", (MAT2d_DataMapOfBiIntSequenceOfInteger::const_iterator (MAT2d_DataMapOfBiIntSequenceOfInteger::*)() const ) &MAT2d_DataMapOfBiIntSequenceOfInteger::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_MAT2d_DataMapOfBiIntSequenceOfInteger.def("cend", (MAT2d_DataMapOfBiIntSequenceOfInteger::const_iterator (MAT2d_DataMapOfBiIntSequenceOfInteger::*)() const ) &MAT2d_DataMapOfBiIntSequenceOfInteger::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_MAT2d_DataMapOfBiIntSequenceOfInteger.def("Exchange", (void (MAT2d_DataMapOfBiIntSequenceOfInteger::*)(MAT2d_DataMapOfBiIntSequenceOfInteger &)) &MAT2d_DataMapOfBiIntSequenceOfInteger::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_MAT2d_DataMapOfBiIntSequenceOfInteger.def("Assign", (MAT2d_DataMapOfBiIntSequenceOfInteger & (MAT2d_DataMapOfBiIntSequenceOfInteger::*)(const MAT2d_DataMapOfBiIntSequenceOfInteger &)) &MAT2d_DataMapOfBiIntSequenceOfInteger::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_MAT2d_DataMapOfBiIntSequenceOfInteger.def("assign", (MAT2d_DataMapOfBiIntSequenceOfInteger & (MAT2d_DataMapOfBiIntSequenceOfInteger::*)(const MAT2d_DataMapOfBiIntSequenceOfInteger &)) &MAT2d_DataMapOfBiIntSequenceOfInteger::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_MAT2d_DataMapOfBiIntSequenceOfInteger.def("ReSize", (void (MAT2d_DataMapOfBiIntSequenceOfInteger::*)(const Standard_Integer)) &MAT2d_DataMapOfBiIntSequenceOfInteger::ReSize, "ReSize", py::arg("N"));
	cls_MAT2d_DataMapOfBiIntSequenceOfInteger.def("Bind", (Standard_Boolean (MAT2d_DataMapOfBiIntSequenceOfInteger::*)(const MAT2d_BiInt &, const TColStd_SequenceOfInteger &)) &MAT2d_DataMapOfBiIntSequenceOfInteger::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_MAT2d_DataMapOfBiIntSequenceOfInteger.def("Bound", (TColStd_SequenceOfInteger * (MAT2d_DataMapOfBiIntSequenceOfInteger::*)(const MAT2d_BiInt &, const TColStd_SequenceOfInteger &)) &MAT2d_DataMapOfBiIntSequenceOfInteger::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_MAT2d_DataMapOfBiIntSequenceOfInteger.def("IsBound", (Standard_Boolean (MAT2d_DataMapOfBiIntSequenceOfInteger::*)(const MAT2d_BiInt &) const ) &MAT2d_DataMapOfBiIntSequenceOfInteger::IsBound, "IsBound", py::arg("theKey"));
	cls_MAT2d_DataMapOfBiIntSequenceOfInteger.def("UnBind", (Standard_Boolean (MAT2d_DataMapOfBiIntSequenceOfInteger::*)(const MAT2d_BiInt &)) &MAT2d_DataMapOfBiIntSequenceOfInteger::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_MAT2d_DataMapOfBiIntSequenceOfInteger.def("Seek", (const TColStd_SequenceOfInteger * (MAT2d_DataMapOfBiIntSequenceOfInteger::*)(const MAT2d_BiInt &) const ) &MAT2d_DataMapOfBiIntSequenceOfInteger::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_MAT2d_DataMapOfBiIntSequenceOfInteger.def("Find", (const TColStd_SequenceOfInteger & (MAT2d_DataMapOfBiIntSequenceOfInteger::*)(const MAT2d_BiInt &) const ) &MAT2d_DataMapOfBiIntSequenceOfInteger::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_MAT2d_DataMapOfBiIntSequenceOfInteger.def("Find", (Standard_Boolean (MAT2d_DataMapOfBiIntSequenceOfInteger::*)(const MAT2d_BiInt &, TColStd_SequenceOfInteger &) const ) &MAT2d_DataMapOfBiIntSequenceOfInteger::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_MAT2d_DataMapOfBiIntSequenceOfInteger.def("__call__", (const TColStd_SequenceOfInteger & (MAT2d_DataMapOfBiIntSequenceOfInteger::*)(const MAT2d_BiInt &) const ) &MAT2d_DataMapOfBiIntSequenceOfInteger::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_MAT2d_DataMapOfBiIntSequenceOfInteger.def("ChangeSeek", (TColStd_SequenceOfInteger * (MAT2d_DataMapOfBiIntSequenceOfInteger::*)(const MAT2d_BiInt &)) &MAT2d_DataMapOfBiIntSequenceOfInteger::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_MAT2d_DataMapOfBiIntSequenceOfInteger.def("ChangeFind", (TColStd_SequenceOfInteger & (MAT2d_DataMapOfBiIntSequenceOfInteger::*)(const MAT2d_BiInt &)) &MAT2d_DataMapOfBiIntSequenceOfInteger::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_MAT2d_DataMapOfBiIntSequenceOfInteger.def("__call__", (TColStd_SequenceOfInteger & (MAT2d_DataMapOfBiIntSequenceOfInteger::*)(const MAT2d_BiInt &)) &MAT2d_DataMapOfBiIntSequenceOfInteger::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_MAT2d_DataMapOfBiIntSequenceOfInteger.def("Clear", [](MAT2d_DataMapOfBiIntSequenceOfInteger &self) -> void { return self.Clear(); });
	cls_MAT2d_DataMapOfBiIntSequenceOfInteger.def("Clear", (void (MAT2d_DataMapOfBiIntSequenceOfInteger::*)(const Standard_Boolean)) &MAT2d_DataMapOfBiIntSequenceOfInteger::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_MAT2d_DataMapOfBiIntSequenceOfInteger.def("Clear", (void (MAT2d_DataMapOfBiIntSequenceOfInteger::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &MAT2d_DataMapOfBiIntSequenceOfInteger::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_MAT2d_DataMapOfBiIntSequenceOfInteger.def("Size", (Standard_Integer (MAT2d_DataMapOfBiIntSequenceOfInteger::*)() const ) &MAT2d_DataMapOfBiIntSequenceOfInteger::Size, "Size");
	cls_MAT2d_DataMapOfBiIntSequenceOfInteger.def("__iter__", [](const MAT2d_DataMapOfBiIntSequenceOfInteger &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\MAT2d_DataMapOfBiIntSequenceOfInteger.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
	py::class_<MAT2d_SequenceOfSequenceOfGeometry, std::unique_ptr<MAT2d_SequenceOfSequenceOfGeometry, Deleter<MAT2d_SequenceOfSequenceOfGeometry>>, NCollection_BaseSequence> cls_MAT2d_SequenceOfSequenceOfGeometry(mod, "MAT2d_SequenceOfSequenceOfGeometry", "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n");
	cls_MAT2d_SequenceOfSequenceOfGeometry.def(py::init<>());
	cls_MAT2d_SequenceOfSequenceOfGeometry.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_MAT2d_SequenceOfSequenceOfGeometry.def(py::init([] (const MAT2d_SequenceOfSequenceOfGeometry &other) {return new MAT2d_SequenceOfSequenceOfGeometry(other);}), "Copy constructor", py::arg("other"));
	cls_MAT2d_SequenceOfSequenceOfGeometry.def("begin", (MAT2d_SequenceOfSequenceOfGeometry::iterator (MAT2d_SequenceOfSequenceOfGeometry::*)() const ) &MAT2d_SequenceOfSequenceOfGeometry::begin, "Returns an iterator pointing to the first element in the sequence.");
	cls_MAT2d_SequenceOfSequenceOfGeometry.def("end", (MAT2d_SequenceOfSequenceOfGeometry::iterator (MAT2d_SequenceOfSequenceOfGeometry::*)() const ) &MAT2d_SequenceOfSequenceOfGeometry::end, "Returns an iterator referring to the past-the-end element in the sequence.");
	cls_MAT2d_SequenceOfSequenceOfGeometry.def("cbegin", (MAT2d_SequenceOfSequenceOfGeometry::const_iterator (MAT2d_SequenceOfSequenceOfGeometry::*)() const ) &MAT2d_SequenceOfSequenceOfGeometry::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
	cls_MAT2d_SequenceOfSequenceOfGeometry.def("cend", (MAT2d_SequenceOfSequenceOfGeometry::const_iterator (MAT2d_SequenceOfSequenceOfGeometry::*)() const ) &MAT2d_SequenceOfSequenceOfGeometry::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
	cls_MAT2d_SequenceOfSequenceOfGeometry.def("Size", (Standard_Integer (MAT2d_SequenceOfSequenceOfGeometry::*)() const ) &MAT2d_SequenceOfSequenceOfGeometry::Size, "Number of items");
	cls_MAT2d_SequenceOfSequenceOfGeometry.def("Length", (Standard_Integer (MAT2d_SequenceOfSequenceOfGeometry::*)() const ) &MAT2d_SequenceOfSequenceOfGeometry::Length, "Number of items");
	cls_MAT2d_SequenceOfSequenceOfGeometry.def("Lower", (Standard_Integer (MAT2d_SequenceOfSequenceOfGeometry::*)() const ) &MAT2d_SequenceOfSequenceOfGeometry::Lower, "Method for consistency with other collections.");
	cls_MAT2d_SequenceOfSequenceOfGeometry.def("Upper", (Standard_Integer (MAT2d_SequenceOfSequenceOfGeometry::*)() const ) &MAT2d_SequenceOfSequenceOfGeometry::Upper, "Method for consistency with other collections.");
	cls_MAT2d_SequenceOfSequenceOfGeometry.def("IsEmpty", (Standard_Boolean (MAT2d_SequenceOfSequenceOfGeometry::*)() const ) &MAT2d_SequenceOfSequenceOfGeometry::IsEmpty, "Empty query");
	cls_MAT2d_SequenceOfSequenceOfGeometry.def("Reverse", (void (MAT2d_SequenceOfSequenceOfGeometry::*)()) &MAT2d_SequenceOfSequenceOfGeometry::Reverse, "Reverse sequence");
	cls_MAT2d_SequenceOfSequenceOfGeometry.def("Exchange", (void (MAT2d_SequenceOfSequenceOfGeometry::*)(const Standard_Integer, const Standard_Integer)) &MAT2d_SequenceOfSequenceOfGeometry::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
	cls_MAT2d_SequenceOfSequenceOfGeometry.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &MAT2d_SequenceOfSequenceOfGeometry::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
	cls_MAT2d_SequenceOfSequenceOfGeometry.def("Clear", [](MAT2d_SequenceOfSequenceOfGeometry &self) -> void { return self.Clear(); });
	cls_MAT2d_SequenceOfSequenceOfGeometry.def("Clear", (void (MAT2d_SequenceOfSequenceOfGeometry::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &MAT2d_SequenceOfSequenceOfGeometry::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
	cls_MAT2d_SequenceOfSequenceOfGeometry.def("Assign", (MAT2d_SequenceOfSequenceOfGeometry & (MAT2d_SequenceOfSequenceOfGeometry::*)(const MAT2d_SequenceOfSequenceOfGeometry &)) &MAT2d_SequenceOfSequenceOfGeometry::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
	cls_MAT2d_SequenceOfSequenceOfGeometry.def("assign", (MAT2d_SequenceOfSequenceOfGeometry & (MAT2d_SequenceOfSequenceOfGeometry::*)(const MAT2d_SequenceOfSequenceOfGeometry &)) &MAT2d_SequenceOfSequenceOfGeometry::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_MAT2d_SequenceOfSequenceOfGeometry.def("Remove", (void (MAT2d_SequenceOfSequenceOfGeometry::*)(MAT2d_SequenceOfSequenceOfGeometry::Iterator &)) &MAT2d_SequenceOfSequenceOfGeometry::Remove, "Remove one item", py::arg("thePosition"));
	cls_MAT2d_SequenceOfSequenceOfGeometry.def("Remove", (void (MAT2d_SequenceOfSequenceOfGeometry::*)(const Standard_Integer)) &MAT2d_SequenceOfSequenceOfGeometry::Remove, "Remove one item", py::arg("theIndex"));
	cls_MAT2d_SequenceOfSequenceOfGeometry.def("Remove", (void (MAT2d_SequenceOfSequenceOfGeometry::*)(const Standard_Integer, const Standard_Integer)) &MAT2d_SequenceOfSequenceOfGeometry::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
	cls_MAT2d_SequenceOfSequenceOfGeometry.def("Append", (void (MAT2d_SequenceOfSequenceOfGeometry::*)(const TColGeom2d_SequenceOfGeometry &)) &MAT2d_SequenceOfSequenceOfGeometry::Append, "Append one item", py::arg("theItem"));
	cls_MAT2d_SequenceOfSequenceOfGeometry.def("Append", (void (MAT2d_SequenceOfSequenceOfGeometry::*)(MAT2d_SequenceOfSequenceOfGeometry &)) &MAT2d_SequenceOfSequenceOfGeometry::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
	cls_MAT2d_SequenceOfSequenceOfGeometry.def("Prepend", (void (MAT2d_SequenceOfSequenceOfGeometry::*)(const TColGeom2d_SequenceOfGeometry &)) &MAT2d_SequenceOfSequenceOfGeometry::Prepend, "Prepend one item", py::arg("theItem"));
	cls_MAT2d_SequenceOfSequenceOfGeometry.def("Prepend", (void (MAT2d_SequenceOfSequenceOfGeometry::*)(MAT2d_SequenceOfSequenceOfGeometry &)) &MAT2d_SequenceOfSequenceOfGeometry::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
	cls_MAT2d_SequenceOfSequenceOfGeometry.def("InsertBefore", (void (MAT2d_SequenceOfSequenceOfGeometry::*)(const Standard_Integer, const TColGeom2d_SequenceOfGeometry &)) &MAT2d_SequenceOfSequenceOfGeometry::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
	cls_MAT2d_SequenceOfSequenceOfGeometry.def("InsertBefore", (void (MAT2d_SequenceOfSequenceOfGeometry::*)(const Standard_Integer, MAT2d_SequenceOfSequenceOfGeometry &)) &MAT2d_SequenceOfSequenceOfGeometry::InsertBefore, "InsertBefore theIndex another sequence", py::arg("theIndex"), py::arg("theSeq"));
	cls_MAT2d_SequenceOfSequenceOfGeometry.def("InsertAfter", (void (MAT2d_SequenceOfSequenceOfGeometry::*)(MAT2d_SequenceOfSequenceOfGeometry::Iterator &, const TColGeom2d_SequenceOfGeometry &)) &MAT2d_SequenceOfSequenceOfGeometry::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
	cls_MAT2d_SequenceOfSequenceOfGeometry.def("InsertAfter", (void (MAT2d_SequenceOfSequenceOfGeometry::*)(const Standard_Integer, MAT2d_SequenceOfSequenceOfGeometry &)) &MAT2d_SequenceOfSequenceOfGeometry::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theSeq"));
	cls_MAT2d_SequenceOfSequenceOfGeometry.def("InsertAfter", (void (MAT2d_SequenceOfSequenceOfGeometry::*)(const Standard_Integer, const TColGeom2d_SequenceOfGeometry &)) &MAT2d_SequenceOfSequenceOfGeometry::InsertAfter, "InsertAfter theIndex another sequence", py::arg("theIndex"), py::arg("theItem"));
	cls_MAT2d_SequenceOfSequenceOfGeometry.def("Split", (void (MAT2d_SequenceOfSequenceOfGeometry::*)(const Standard_Integer, MAT2d_SequenceOfSequenceOfGeometry &)) &MAT2d_SequenceOfSequenceOfGeometry::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
	cls_MAT2d_SequenceOfSequenceOfGeometry.def("First", (const TColGeom2d_SequenceOfGeometry & (MAT2d_SequenceOfSequenceOfGeometry::*)() const ) &MAT2d_SequenceOfSequenceOfGeometry::First, "First item access");
	cls_MAT2d_SequenceOfSequenceOfGeometry.def("ChangeFirst", (TColGeom2d_SequenceOfGeometry & (MAT2d_SequenceOfSequenceOfGeometry::*)()) &MAT2d_SequenceOfSequenceOfGeometry::ChangeFirst, "First item access");
	cls_MAT2d_SequenceOfSequenceOfGeometry.def("Last", (const TColGeom2d_SequenceOfGeometry & (MAT2d_SequenceOfSequenceOfGeometry::*)() const ) &MAT2d_SequenceOfSequenceOfGeometry::Last, "Last item access");
	cls_MAT2d_SequenceOfSequenceOfGeometry.def("ChangeLast", (TColGeom2d_SequenceOfGeometry & (MAT2d_SequenceOfSequenceOfGeometry::*)()) &MAT2d_SequenceOfSequenceOfGeometry::ChangeLast, "Last item access");
	cls_MAT2d_SequenceOfSequenceOfGeometry.def("Value", (const TColGeom2d_SequenceOfGeometry & (MAT2d_SequenceOfSequenceOfGeometry::*)(const Standard_Integer) const ) &MAT2d_SequenceOfSequenceOfGeometry::Value, "Constant item access by theIndex", py::arg("theIndex"));
	cls_MAT2d_SequenceOfSequenceOfGeometry.def("__call__", (const TColGeom2d_SequenceOfGeometry & (MAT2d_SequenceOfSequenceOfGeometry::*)(const Standard_Integer) const ) &MAT2d_SequenceOfSequenceOfGeometry::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
	cls_MAT2d_SequenceOfSequenceOfGeometry.def("ChangeValue", (TColGeom2d_SequenceOfGeometry & (MAT2d_SequenceOfSequenceOfGeometry::*)(const Standard_Integer)) &MAT2d_SequenceOfSequenceOfGeometry::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
	cls_MAT2d_SequenceOfSequenceOfGeometry.def("__call__", (TColGeom2d_SequenceOfGeometry & (MAT2d_SequenceOfSequenceOfGeometry::*)(const Standard_Integer)) &MAT2d_SequenceOfSequenceOfGeometry::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
	cls_MAT2d_SequenceOfSequenceOfGeometry.def("SetValue", (void (MAT2d_SequenceOfSequenceOfGeometry::*)(const Standard_Integer, const TColGeom2d_SequenceOfGeometry &)) &MAT2d_SequenceOfSequenceOfGeometry::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
	cls_MAT2d_SequenceOfSequenceOfGeometry.def("__iter__", [](const MAT2d_SequenceOfSequenceOfGeometry &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
	py::class_<MAT2d_SequenceOfConnexion, std::unique_ptr<MAT2d_SequenceOfConnexion, Deleter<MAT2d_SequenceOfConnexion>>, NCollection_BaseSequence> cls_MAT2d_SequenceOfConnexion(mod, "MAT2d_SequenceOfConnexion", "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n");
	cls_MAT2d_SequenceOfConnexion.def(py::init<>());
	cls_MAT2d_SequenceOfConnexion.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_MAT2d_SequenceOfConnexion.def(py::init([] (const MAT2d_SequenceOfConnexion &other) {return new MAT2d_SequenceOfConnexion(other);}), "Copy constructor", py::arg("other"));
	cls_MAT2d_SequenceOfConnexion.def("begin", (MAT2d_SequenceOfConnexion::iterator (MAT2d_SequenceOfConnexion::*)() const ) &MAT2d_SequenceOfConnexion::begin, "Returns an iterator pointing to the first element in the sequence.");
	cls_MAT2d_SequenceOfConnexion.def("end", (MAT2d_SequenceOfConnexion::iterator (MAT2d_SequenceOfConnexion::*)() const ) &MAT2d_SequenceOfConnexion::end, "Returns an iterator referring to the past-the-end element in the sequence.");
	cls_MAT2d_SequenceOfConnexion.def("cbegin", (MAT2d_SequenceOfConnexion::const_iterator (MAT2d_SequenceOfConnexion::*)() const ) &MAT2d_SequenceOfConnexion::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
	cls_MAT2d_SequenceOfConnexion.def("cend", (MAT2d_SequenceOfConnexion::const_iterator (MAT2d_SequenceOfConnexion::*)() const ) &MAT2d_SequenceOfConnexion::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
	cls_MAT2d_SequenceOfConnexion.def("Size", (Standard_Integer (MAT2d_SequenceOfConnexion::*)() const ) &MAT2d_SequenceOfConnexion::Size, "Number of items");
	cls_MAT2d_SequenceOfConnexion.def("Length", (Standard_Integer (MAT2d_SequenceOfConnexion::*)() const ) &MAT2d_SequenceOfConnexion::Length, "Number of items");
	cls_MAT2d_SequenceOfConnexion.def("Lower", (Standard_Integer (MAT2d_SequenceOfConnexion::*)() const ) &MAT2d_SequenceOfConnexion::Lower, "Method for consistency with other collections.");
	cls_MAT2d_SequenceOfConnexion.def("Upper", (Standard_Integer (MAT2d_SequenceOfConnexion::*)() const ) &MAT2d_SequenceOfConnexion::Upper, "Method for consistency with other collections.");
	cls_MAT2d_SequenceOfConnexion.def("IsEmpty", (Standard_Boolean (MAT2d_SequenceOfConnexion::*)() const ) &MAT2d_SequenceOfConnexion::IsEmpty, "Empty query");
	cls_MAT2d_SequenceOfConnexion.def("Reverse", (void (MAT2d_SequenceOfConnexion::*)()) &MAT2d_SequenceOfConnexion::Reverse, "Reverse sequence");
	cls_MAT2d_SequenceOfConnexion.def("Exchange", (void (MAT2d_SequenceOfConnexion::*)(const Standard_Integer, const Standard_Integer)) &MAT2d_SequenceOfConnexion::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
	cls_MAT2d_SequenceOfConnexion.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &MAT2d_SequenceOfConnexion::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
	cls_MAT2d_SequenceOfConnexion.def("Clear", [](MAT2d_SequenceOfConnexion &self) -> void { return self.Clear(); });
	cls_MAT2d_SequenceOfConnexion.def("Clear", (void (MAT2d_SequenceOfConnexion::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &MAT2d_SequenceOfConnexion::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
	cls_MAT2d_SequenceOfConnexion.def("Assign", (MAT2d_SequenceOfConnexion & (MAT2d_SequenceOfConnexion::*)(const MAT2d_SequenceOfConnexion &)) &MAT2d_SequenceOfConnexion::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
	cls_MAT2d_SequenceOfConnexion.def("assign", (MAT2d_SequenceOfConnexion & (MAT2d_SequenceOfConnexion::*)(const MAT2d_SequenceOfConnexion &)) &MAT2d_SequenceOfConnexion::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_MAT2d_SequenceOfConnexion.def("Remove", (void (MAT2d_SequenceOfConnexion::*)(MAT2d_SequenceOfConnexion::Iterator &)) &MAT2d_SequenceOfConnexion::Remove, "Remove one item", py::arg("thePosition"));
	cls_MAT2d_SequenceOfConnexion.def("Remove", (void (MAT2d_SequenceOfConnexion::*)(const Standard_Integer)) &MAT2d_SequenceOfConnexion::Remove, "Remove one item", py::arg("theIndex"));
	cls_MAT2d_SequenceOfConnexion.def("Remove", (void (MAT2d_SequenceOfConnexion::*)(const Standard_Integer, const Standard_Integer)) &MAT2d_SequenceOfConnexion::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
	cls_MAT2d_SequenceOfConnexion.def("Append", (void (MAT2d_SequenceOfConnexion::*)(const opencascade::handle<MAT2d_Connexion> &)) &MAT2d_SequenceOfConnexion::Append, "Append one item", py::arg("theItem"));
	cls_MAT2d_SequenceOfConnexion.def("Append", (void (MAT2d_SequenceOfConnexion::*)(MAT2d_SequenceOfConnexion &)) &MAT2d_SequenceOfConnexion::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
	cls_MAT2d_SequenceOfConnexion.def("Prepend", (void (MAT2d_SequenceOfConnexion::*)(const opencascade::handle<MAT2d_Connexion> &)) &MAT2d_SequenceOfConnexion::Prepend, "Prepend one item", py::arg("theItem"));
	cls_MAT2d_SequenceOfConnexion.def("Prepend", (void (MAT2d_SequenceOfConnexion::*)(MAT2d_SequenceOfConnexion &)) &MAT2d_SequenceOfConnexion::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
	cls_MAT2d_SequenceOfConnexion.def("InsertBefore", (void (MAT2d_SequenceOfConnexion::*)(const Standard_Integer, const opencascade::handle<MAT2d_Connexion> &)) &MAT2d_SequenceOfConnexion::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
	cls_MAT2d_SequenceOfConnexion.def("InsertBefore", (void (MAT2d_SequenceOfConnexion::*)(const Standard_Integer, MAT2d_SequenceOfConnexion &)) &MAT2d_SequenceOfConnexion::InsertBefore, "InsertBefore theIndex another sequence", py::arg("theIndex"), py::arg("theSeq"));
	cls_MAT2d_SequenceOfConnexion.def("InsertAfter", (void (MAT2d_SequenceOfConnexion::*)(MAT2d_SequenceOfConnexion::Iterator &, const opencascade::handle<MAT2d_Connexion> &)) &MAT2d_SequenceOfConnexion::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
	cls_MAT2d_SequenceOfConnexion.def("InsertAfter", (void (MAT2d_SequenceOfConnexion::*)(const Standard_Integer, MAT2d_SequenceOfConnexion &)) &MAT2d_SequenceOfConnexion::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theSeq"));
	cls_MAT2d_SequenceOfConnexion.def("InsertAfter", (void (MAT2d_SequenceOfConnexion::*)(const Standard_Integer, const opencascade::handle<MAT2d_Connexion> &)) &MAT2d_SequenceOfConnexion::InsertAfter, "InsertAfter theIndex another sequence", py::arg("theIndex"), py::arg("theItem"));
	cls_MAT2d_SequenceOfConnexion.def("Split", (void (MAT2d_SequenceOfConnexion::*)(const Standard_Integer, MAT2d_SequenceOfConnexion &)) &MAT2d_SequenceOfConnexion::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
	cls_MAT2d_SequenceOfConnexion.def("First", (const opencascade::handle<MAT2d_Connexion> & (MAT2d_SequenceOfConnexion::*)() const ) &MAT2d_SequenceOfConnexion::First, "First item access");
	cls_MAT2d_SequenceOfConnexion.def("ChangeFirst", (opencascade::handle<MAT2d_Connexion> & (MAT2d_SequenceOfConnexion::*)()) &MAT2d_SequenceOfConnexion::ChangeFirst, "First item access");
	cls_MAT2d_SequenceOfConnexion.def("Last", (const opencascade::handle<MAT2d_Connexion> & (MAT2d_SequenceOfConnexion::*)() const ) &MAT2d_SequenceOfConnexion::Last, "Last item access");
	cls_MAT2d_SequenceOfConnexion.def("ChangeLast", (opencascade::handle<MAT2d_Connexion> & (MAT2d_SequenceOfConnexion::*)()) &MAT2d_SequenceOfConnexion::ChangeLast, "Last item access");
	cls_MAT2d_SequenceOfConnexion.def("Value", (const opencascade::handle<MAT2d_Connexion> & (MAT2d_SequenceOfConnexion::*)(const Standard_Integer) const ) &MAT2d_SequenceOfConnexion::Value, "Constant item access by theIndex", py::arg("theIndex"));
	cls_MAT2d_SequenceOfConnexion.def("__call__", (const opencascade::handle<MAT2d_Connexion> & (MAT2d_SequenceOfConnexion::*)(const Standard_Integer) const ) &MAT2d_SequenceOfConnexion::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
	cls_MAT2d_SequenceOfConnexion.def("ChangeValue", (opencascade::handle<MAT2d_Connexion> & (MAT2d_SequenceOfConnexion::*)(const Standard_Integer)) &MAT2d_SequenceOfConnexion::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
	cls_MAT2d_SequenceOfConnexion.def("__call__", (opencascade::handle<MAT2d_Connexion> & (MAT2d_SequenceOfConnexion::*)(const Standard_Integer)) &MAT2d_SequenceOfConnexion::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
	cls_MAT2d_SequenceOfConnexion.def("SetValue", (void (MAT2d_SequenceOfConnexion::*)(const Standard_Integer, const opencascade::handle<MAT2d_Connexion> &)) &MAT2d_SequenceOfConnexion::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
	cls_MAT2d_SequenceOfConnexion.def("__iter__", [](const MAT2d_SequenceOfConnexion &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<MAT2d_DataMapOfIntegerSequenceOfConnexion, std::unique_ptr<MAT2d_DataMapOfIntegerSequenceOfConnexion, Deleter<MAT2d_DataMapOfIntegerSequenceOfConnexion>>, NCollection_BaseMap> cls_MAT2d_DataMapOfIntegerSequenceOfConnexion(mod, "MAT2d_DataMapOfIntegerSequenceOfConnexion", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_MAT2d_DataMapOfIntegerSequenceOfConnexion.def(py::init<>());
	cls_MAT2d_DataMapOfIntegerSequenceOfConnexion.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_MAT2d_DataMapOfIntegerSequenceOfConnexion.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_MAT2d_DataMapOfIntegerSequenceOfConnexion.def(py::init([] (const MAT2d_DataMapOfIntegerSequenceOfConnexion &other) {return new MAT2d_DataMapOfIntegerSequenceOfConnexion(other);}), "Copy constructor", py::arg("other"));
	cls_MAT2d_DataMapOfIntegerSequenceOfConnexion.def("begin", (MAT2d_DataMapOfIntegerSequenceOfConnexion::iterator (MAT2d_DataMapOfIntegerSequenceOfConnexion::*)() const ) &MAT2d_DataMapOfIntegerSequenceOfConnexion::begin, "Returns an iterator pointing to the first element in the map.");
	cls_MAT2d_DataMapOfIntegerSequenceOfConnexion.def("end", (MAT2d_DataMapOfIntegerSequenceOfConnexion::iterator (MAT2d_DataMapOfIntegerSequenceOfConnexion::*)() const ) &MAT2d_DataMapOfIntegerSequenceOfConnexion::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_MAT2d_DataMapOfIntegerSequenceOfConnexion.def("cbegin", (MAT2d_DataMapOfIntegerSequenceOfConnexion::const_iterator (MAT2d_DataMapOfIntegerSequenceOfConnexion::*)() const ) &MAT2d_DataMapOfIntegerSequenceOfConnexion::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_MAT2d_DataMapOfIntegerSequenceOfConnexion.def("cend", (MAT2d_DataMapOfIntegerSequenceOfConnexion::const_iterator (MAT2d_DataMapOfIntegerSequenceOfConnexion::*)() const ) &MAT2d_DataMapOfIntegerSequenceOfConnexion::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_MAT2d_DataMapOfIntegerSequenceOfConnexion.def("Exchange", (void (MAT2d_DataMapOfIntegerSequenceOfConnexion::*)(MAT2d_DataMapOfIntegerSequenceOfConnexion &)) &MAT2d_DataMapOfIntegerSequenceOfConnexion::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_MAT2d_DataMapOfIntegerSequenceOfConnexion.def("Assign", (MAT2d_DataMapOfIntegerSequenceOfConnexion & (MAT2d_DataMapOfIntegerSequenceOfConnexion::*)(const MAT2d_DataMapOfIntegerSequenceOfConnexion &)) &MAT2d_DataMapOfIntegerSequenceOfConnexion::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_MAT2d_DataMapOfIntegerSequenceOfConnexion.def("assign", (MAT2d_DataMapOfIntegerSequenceOfConnexion & (MAT2d_DataMapOfIntegerSequenceOfConnexion::*)(const MAT2d_DataMapOfIntegerSequenceOfConnexion &)) &MAT2d_DataMapOfIntegerSequenceOfConnexion::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_MAT2d_DataMapOfIntegerSequenceOfConnexion.def("ReSize", (void (MAT2d_DataMapOfIntegerSequenceOfConnexion::*)(const Standard_Integer)) &MAT2d_DataMapOfIntegerSequenceOfConnexion::ReSize, "ReSize", py::arg("N"));
	cls_MAT2d_DataMapOfIntegerSequenceOfConnexion.def("Bind", (Standard_Boolean (MAT2d_DataMapOfIntegerSequenceOfConnexion::*)(const Standard_Integer &, const MAT2d_SequenceOfConnexion &)) &MAT2d_DataMapOfIntegerSequenceOfConnexion::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_MAT2d_DataMapOfIntegerSequenceOfConnexion.def("Bound", (MAT2d_SequenceOfConnexion * (MAT2d_DataMapOfIntegerSequenceOfConnexion::*)(const Standard_Integer &, const MAT2d_SequenceOfConnexion &)) &MAT2d_DataMapOfIntegerSequenceOfConnexion::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_MAT2d_DataMapOfIntegerSequenceOfConnexion.def("IsBound", (Standard_Boolean (MAT2d_DataMapOfIntegerSequenceOfConnexion::*)(const Standard_Integer &) const ) &MAT2d_DataMapOfIntegerSequenceOfConnexion::IsBound, "IsBound", py::arg("theKey"));
	cls_MAT2d_DataMapOfIntegerSequenceOfConnexion.def("UnBind", (Standard_Boolean (MAT2d_DataMapOfIntegerSequenceOfConnexion::*)(const Standard_Integer &)) &MAT2d_DataMapOfIntegerSequenceOfConnexion::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_MAT2d_DataMapOfIntegerSequenceOfConnexion.def("Seek", (const MAT2d_SequenceOfConnexion * (MAT2d_DataMapOfIntegerSequenceOfConnexion::*)(const Standard_Integer &) const ) &MAT2d_DataMapOfIntegerSequenceOfConnexion::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_MAT2d_DataMapOfIntegerSequenceOfConnexion.def("Find", (const MAT2d_SequenceOfConnexion & (MAT2d_DataMapOfIntegerSequenceOfConnexion::*)(const Standard_Integer &) const ) &MAT2d_DataMapOfIntegerSequenceOfConnexion::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_MAT2d_DataMapOfIntegerSequenceOfConnexion.def("Find", (Standard_Boolean (MAT2d_DataMapOfIntegerSequenceOfConnexion::*)(const Standard_Integer &, MAT2d_SequenceOfConnexion &) const ) &MAT2d_DataMapOfIntegerSequenceOfConnexion::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_MAT2d_DataMapOfIntegerSequenceOfConnexion.def("__call__", (const MAT2d_SequenceOfConnexion & (MAT2d_DataMapOfIntegerSequenceOfConnexion::*)(const Standard_Integer &) const ) &MAT2d_DataMapOfIntegerSequenceOfConnexion::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_MAT2d_DataMapOfIntegerSequenceOfConnexion.def("ChangeSeek", (MAT2d_SequenceOfConnexion * (MAT2d_DataMapOfIntegerSequenceOfConnexion::*)(const Standard_Integer &)) &MAT2d_DataMapOfIntegerSequenceOfConnexion::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_MAT2d_DataMapOfIntegerSequenceOfConnexion.def("ChangeFind", (MAT2d_SequenceOfConnexion & (MAT2d_DataMapOfIntegerSequenceOfConnexion::*)(const Standard_Integer &)) &MAT2d_DataMapOfIntegerSequenceOfConnexion::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_MAT2d_DataMapOfIntegerSequenceOfConnexion.def("__call__", (MAT2d_SequenceOfConnexion & (MAT2d_DataMapOfIntegerSequenceOfConnexion::*)(const Standard_Integer &)) &MAT2d_DataMapOfIntegerSequenceOfConnexion::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_MAT2d_DataMapOfIntegerSequenceOfConnexion.def("Clear", [](MAT2d_DataMapOfIntegerSequenceOfConnexion &self) -> void { return self.Clear(); });
	cls_MAT2d_DataMapOfIntegerSequenceOfConnexion.def("Clear", (void (MAT2d_DataMapOfIntegerSequenceOfConnexion::*)(const Standard_Boolean)) &MAT2d_DataMapOfIntegerSequenceOfConnexion::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_MAT2d_DataMapOfIntegerSequenceOfConnexion.def("Clear", (void (MAT2d_DataMapOfIntegerSequenceOfConnexion::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &MAT2d_DataMapOfIntegerSequenceOfConnexion::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_MAT2d_DataMapOfIntegerSequenceOfConnexion.def("Size", (Standard_Integer (MAT2d_DataMapOfIntegerSequenceOfConnexion::*)() const ) &MAT2d_DataMapOfIntegerSequenceOfConnexion::Size, "Size");
	cls_MAT2d_DataMapOfIntegerSequenceOfConnexion.def("__iter__", [](const MAT2d_DataMapOfIntegerSequenceOfConnexion &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\MAT2d_DataMapOfIntegerSequenceOfConnexion.hxx

}
