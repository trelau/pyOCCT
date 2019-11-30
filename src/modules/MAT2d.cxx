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
#include <NCollection_DataMap.hxx>
#include <Standard_TypeDef.hxx>
#include <Bisector_Bisec.hxx>
#include <TColStd_MapIntegerHasher.hxx>
#include <MAT2d_DataMapOfIntegerBisec.hxx>
#include <gp_Pnt2d.hxx>
#include <MAT2d_DataMapOfIntegerPnt2d.hxx>
#include <gp_Vec2d.hxx>
#include <MAT2d_DataMapOfIntegerVec2d.hxx>
#include <Standard.hxx>
#include <MAT_Side.hxx>
#include <GeomAbs_JoinType.hxx>
#include <Standard_Handle.hxx>
#include <MAT2d_Circuit.hxx>
#include <MAT_Bisector.hxx>
#include <Geom2d_Geometry.hxx>
#include <TColStd_SequenceOfInteger.hxx>
#include <MAT2d_Tool2d.hxx>
#include <MAT2d_BiInt.hxx>
#include <MAT2d_MapBiIntHasher.hxx>
#include <MAT2d_DataMapOfBiIntInteger.hxx>
#include <NCollection_Sequence.hxx>
#include <TColGeom2d_SequenceOfCurve.hxx>
#include <MAT2d_SequenceOfSequenceOfCurve.hxx>
#include <Standard_Transient.hxx>
#include <MAT2d_Connexion.hxx>
#include <Standard_Std.hxx>
#include <Standard_Type.hxx>
#include <NCollection_Array2.hxx>
#include <MAT2d_Array2OfConnexion.hxx>
#include <MAT2d_DataMapOfIntegerConnexion.hxx>
#include <MAT2d_DataMapOfBiIntSequenceOfInteger.hxx>
#include <TColGeom2d_SequenceOfGeometry.hxx>
#include <MAT2d_SequenceOfSequenceOfGeometry.hxx>
#include <MAT2d_SequenceOfConnexion.hxx>
#include <TColStd_SequenceOfBoolean.hxx>
#include <MAT2d_MiniPath.hxx>
#include <Geom2d_Curve.hxx>
#include <Geom2d_TrimmedCurve.hxx>
#include <MAT2d_CutCurve.hxx>
#include <MAT2d_DataMapOfIntegerSequenceOfConnexion.hxx>
#include <MAT_ListOfEdge.hxx>
#include <TColStd_DataMapOfIntegerInteger.hxx>
#include <MAT_DataMapOfIntegerBisector.hxx>
#include <MAT_ListOfBisector.hxx>
#include <MAT2d_Mat2d.hxx>
#include <bind_NCollection_DataMap.hxx>
#include <bind_NCollection_Sequence.hxx>
#include <bind_NCollection_Array2.hxx>

PYBIND11_MODULE(MAT2d, mod) {

py::module::import("OCCT.NCollection");
py::module::import("OCCT.Standard");
py::module::import("OCCT.Bisector");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.gp");
py::module::import("OCCT.MAT");
py::module::import("OCCT.GeomAbs");
py::module::import("OCCT.Geom2d");
py::module::import("OCCT.TColGeom2d");

// TYPEDEF: MAT2D_DATAMAPOFINTEGERBISEC
bind_NCollection_DataMap<int, Bisector_Bisec, NCollection_DefaultHasher<int> >(mod, "MAT2d_DataMapOfIntegerBisec", py::module_local(false));

// TYPEDEF: MAT2D_DATAMAPITERATOROFDATAMAPOFINTEGERBISEC

// TYPEDEF: MAT2D_DATAMAPOFINTEGERPNT2D
bind_NCollection_DataMap<int, gp_Pnt2d, NCollection_DefaultHasher<int> >(mod, "MAT2d_DataMapOfIntegerPnt2d", py::module_local(false));

// TYPEDEF: MAT2D_DATAMAPITERATOROFDATAMAPOFINTEGERPNT2D

// TYPEDEF: MAT2D_DATAMAPOFINTEGERVEC2D
bind_NCollection_DataMap<int, gp_Vec2d, NCollection_DefaultHasher<int> >(mod, "MAT2d_DataMapOfIntegerVec2d", py::module_local(false));

// TYPEDEF: MAT2D_DATAMAPITERATOROFDATAMAPOFINTEGERVEC2D

// CLASS: MAT2D_TOOL2D
py::class_<MAT2d_Tool2d> cls_MAT2d_Tool2d(mod, "MAT2d_Tool2d", "Set of the methods useful for the MAT's computation. Tool2d contains the geometry of the bisecting locus.");

// Constructors
cls_MAT2d_Tool2d.def(py::init<>());

// Methods
// cls_MAT2d_Tool2d.def_static("operator new_", (void * (*)(size_t)) &MAT2d_Tool2d::operator new, "None", py::arg("theSize"));
// cls_MAT2d_Tool2d.def_static("operator delete_", (void (*)(void *)) &MAT2d_Tool2d::operator delete, "None", py::arg("theAddress"));
// cls_MAT2d_Tool2d.def_static("operator new[]_", (void * (*)(size_t)) &MAT2d_Tool2d::operator new[], "None", py::arg("theSize"));
// cls_MAT2d_Tool2d.def_static("operator delete[]_", (void (*)(void *)) &MAT2d_Tool2d::operator delete[], "None", py::arg("theAddress"));
// cls_MAT2d_Tool2d.def_static("operator new_", (void * (*)(size_t, void *)) &MAT2d_Tool2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_MAT2d_Tool2d.def_static("operator delete_", (void (*)(void *, void *)) &MAT2d_Tool2d::operator delete, "None", py::arg(""), py::arg(""));
cls_MAT2d_Tool2d.def("Sense", (void (MAT2d_Tool2d::*)(const MAT_Side)) &MAT2d_Tool2d::Sense, "<aSide> defines the side of the computation of the map.", py::arg("aside"));
cls_MAT2d_Tool2d.def("SetJoinType", (void (MAT2d_Tool2d::*)(const GeomAbs_JoinType)) &MAT2d_Tool2d::SetJoinType, "None", py::arg("aJoinType"));
cls_MAT2d_Tool2d.def("InitItems", (void (MAT2d_Tool2d::*)(const opencascade::handle<MAT2d_Circuit> &)) &MAT2d_Tool2d::InitItems, "InitItems cuts the line in Items. this Items are the geometrics representations of the BasicElts from MAT.", py::arg("aCircuit"));
cls_MAT2d_Tool2d.def("NumberOfItems", (Standard_Integer (MAT2d_Tool2d::*)() const) &MAT2d_Tool2d::NumberOfItems, "Returns the Number of Items .");
cls_MAT2d_Tool2d.def("ToleranceOfConfusion", (Standard_Real (MAT2d_Tool2d::*)() const) &MAT2d_Tool2d::ToleranceOfConfusion, "Returns tolerance to test the confusion of two points.");
cls_MAT2d_Tool2d.def("FirstPoint", [](MAT2d_Tool2d &self, const Standard_Integer anitem, Standard_Real & dist){ Standard_Integer rv = self.FirstPoint(anitem, dist); return std::tuple<Standard_Integer, Standard_Real &>(rv, dist); }, "Creates the point at the origin of the bisector between anitem and the previous item. dist is the distance from the FirstPoint to <anitem>. Returns the index of this point in <theGeomPnts>.", py::arg("anitem"), py::arg("dist"));
cls_MAT2d_Tool2d.def("TangentBefore", (Standard_Integer (MAT2d_Tool2d::*)(const Standard_Integer, const Standard_Boolean)) &MAT2d_Tool2d::TangentBefore, "Creates the Tangent at the end of the Item defined by <anitem>. Returns the index of this vector in <theGeomVecs>", py::arg("anitem"), py::arg("IsOpenResult"));
cls_MAT2d_Tool2d.def("TangentAfter", (Standard_Integer (MAT2d_Tool2d::*)(const Standard_Integer, const Standard_Boolean)) &MAT2d_Tool2d::TangentAfter, "Creates the Reversed Tangent at the origin of the Item defined by <anitem>. Returns the index of this vector in <theGeomVecs>", py::arg("anitem"), py::arg("IsOpenResult"));
cls_MAT2d_Tool2d.def("Tangent", (Standard_Integer (MAT2d_Tool2d::*)(const Standard_Integer)) &MAT2d_Tool2d::Tangent, "Creates the Tangent at the end of the bisector defined by <bisector>. Returns the index of this vector in <theGeomVecs>", py::arg("bisector"));
cls_MAT2d_Tool2d.def("CreateBisector", (void (MAT2d_Tool2d::*)(const opencascade::handle<MAT_Bisector> &)) &MAT2d_Tool2d::CreateBisector, "Creates the geometric bisector defined by <abisector>.", py::arg("abisector"));
cls_MAT2d_Tool2d.def("TrimBisector", (Standard_Boolean (MAT2d_Tool2d::*)(const opencascade::handle<MAT_Bisector> &)) &MAT2d_Tool2d::TrimBisector, "Trims the geometric bisector by the <firstparameter> of <abisector>. If the parameter is out of the bisector, Return FALSE. else Return True.", py::arg("abisector"));
cls_MAT2d_Tool2d.def("TrimBisector", (Standard_Boolean (MAT2d_Tool2d::*)(const opencascade::handle<MAT_Bisector> &, const Standard_Integer)) &MAT2d_Tool2d::TrimBisector, "Trims the geometric bisector by the point of index <apoint> in <theGeomPnts>. If the point is out of the bisector, Return FALSE. else Return True.", py::arg("abisector"), py::arg("apoint"));
cls_MAT2d_Tool2d.def("IntersectBisector", [](MAT2d_Tool2d &self, const opencascade::handle<MAT_Bisector> & bisectorone, const opencascade::handle<MAT_Bisector> & bisectortwo, Standard_Integer & intpnt){ Standard_Real rv = self.IntersectBisector(bisectorone, bisectortwo, intpnt); return std::tuple<Standard_Real, Standard_Integer &>(rv, intpnt); }, "Computes the point of intersection between the bisectors defined by <bisectorone> and <bisectortwo> . If this point exists, <intpnt> is its index in <theGeomPnts> and Return the distance of the point from the bisector else Return <RealLast>.", py::arg("bisectorone"), py::arg("bisectortwo"), py::arg("intpnt"));
cls_MAT2d_Tool2d.def("Distance", (Standard_Real (MAT2d_Tool2d::*)(const opencascade::handle<MAT_Bisector> &, const Standard_Real, const Standard_Real) const) &MAT2d_Tool2d::Distance, "Returns the distance between the two points designed by their parameters on <abisector>.", py::arg("abisector"), py::arg("param1"), py::arg("param2"));
cls_MAT2d_Tool2d.def("Dump", (void (MAT2d_Tool2d::*)(const Standard_Integer, const Standard_Integer) const) &MAT2d_Tool2d::Dump, "displays informations about the bisector defined by <bisector>.", py::arg("bisector"), py::arg("erease"));
cls_MAT2d_Tool2d.def("GeomBis", (const Bisector_Bisec & (MAT2d_Tool2d::*)(const Standard_Integer) const) &MAT2d_Tool2d::GeomBis, "Returns the <Bisec> of index <Index> in <theGeomBisectors>.", py::arg("Index"));
cls_MAT2d_Tool2d.def("GeomElt", (opencascade::handle<Geom2d_Geometry> (MAT2d_Tool2d::*)(const Standard_Integer) const) &MAT2d_Tool2d::GeomElt, "Returns the Geometry of index <Index> in <theGeomElts>.", py::arg("Index"));
cls_MAT2d_Tool2d.def("GeomPnt", (const gp_Pnt2d & (MAT2d_Tool2d::*)(const Standard_Integer) const) &MAT2d_Tool2d::GeomPnt, "Returns the point of index <Index> in the <theGeomPnts>.", py::arg("Index"));
cls_MAT2d_Tool2d.def("GeomVec", (const gp_Vec2d & (MAT2d_Tool2d::*)(const Standard_Integer) const) &MAT2d_Tool2d::GeomVec, "Returns the vector of index <Index> in the <theGeomVecs>.", py::arg("Index"));
cls_MAT2d_Tool2d.def("Circuit", (opencascade::handle<MAT2d_Circuit> (MAT2d_Tool2d::*)() const) &MAT2d_Tool2d::Circuit, "None");
cls_MAT2d_Tool2d.def("BisecFusion", (void (MAT2d_Tool2d::*)(const Standard_Integer, const Standard_Integer)) &MAT2d_Tool2d::BisecFusion, "None", py::arg("Index1"), py::arg("Index2"));
cls_MAT2d_Tool2d.def("ChangeGeomBis", (Bisector_Bisec & (MAT2d_Tool2d::*)(const Standard_Integer)) &MAT2d_Tool2d::ChangeGeomBis, "Returns the <Bisec> of index <Index> in <theGeomBisectors>.", py::arg("Index"));

// CLASS: MAT2D_BIINT
py::class_<MAT2d_BiInt> cls_MAT2d_BiInt(mod, "MAT2d_BiInt", "BiInt is a set of two integers.");

// Constructors
cls_MAT2d_BiInt.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("I1"), py::arg("I2"));

// Methods
// cls_MAT2d_BiInt.def_static("operator new_", (void * (*)(size_t)) &MAT2d_BiInt::operator new, "None", py::arg("theSize"));
// cls_MAT2d_BiInt.def_static("operator delete_", (void (*)(void *)) &MAT2d_BiInt::operator delete, "None", py::arg("theAddress"));
// cls_MAT2d_BiInt.def_static("operator new[]_", (void * (*)(size_t)) &MAT2d_BiInt::operator new[], "None", py::arg("theSize"));
// cls_MAT2d_BiInt.def_static("operator delete[]_", (void (*)(void *)) &MAT2d_BiInt::operator delete[], "None", py::arg("theAddress"));
// cls_MAT2d_BiInt.def_static("operator new_", (void * (*)(size_t, void *)) &MAT2d_BiInt::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_MAT2d_BiInt.def_static("operator delete_", (void (*)(void *, void *)) &MAT2d_BiInt::operator delete, "None", py::arg(""), py::arg(""));
cls_MAT2d_BiInt.def("FirstIndex", (Standard_Integer (MAT2d_BiInt::*)() const) &MAT2d_BiInt::FirstIndex, "None");
cls_MAT2d_BiInt.def("SecondIndex", (Standard_Integer (MAT2d_BiInt::*)() const) &MAT2d_BiInt::SecondIndex, "None");
cls_MAT2d_BiInt.def("FirstIndex", (void (MAT2d_BiInt::*)(const Standard_Integer)) &MAT2d_BiInt::FirstIndex, "None", py::arg("I1"));
cls_MAT2d_BiInt.def("SecondIndex", (void (MAT2d_BiInt::*)(const Standard_Integer)) &MAT2d_BiInt::SecondIndex, "None", py::arg("I2"));
cls_MAT2d_BiInt.def("IsEqual", (Standard_Boolean (MAT2d_BiInt::*)(const MAT2d_BiInt &) const) &MAT2d_BiInt::IsEqual, "None", py::arg("B"));
cls_MAT2d_BiInt.def("__eq__", (Standard_Boolean (MAT2d_BiInt::*)(const MAT2d_BiInt &) const) &MAT2d_BiInt::operator==, py::is_operator(), "None", py::arg("B"));

// CLASS: MAT2D_MAPBIINTHASHER
py::class_<MAT2d_MapBiIntHasher> cls_MAT2d_MapBiIntHasher(mod, "MAT2d_MapBiIntHasher", "None");

// Methods
// cls_MAT2d_MapBiIntHasher.def_static("operator new_", (void * (*)(size_t)) &MAT2d_MapBiIntHasher::operator new, "None", py::arg("theSize"));
// cls_MAT2d_MapBiIntHasher.def_static("operator delete_", (void (*)(void *)) &MAT2d_MapBiIntHasher::operator delete, "None", py::arg("theAddress"));
// cls_MAT2d_MapBiIntHasher.def_static("operator new[]_", (void * (*)(size_t)) &MAT2d_MapBiIntHasher::operator new[], "None", py::arg("theSize"));
// cls_MAT2d_MapBiIntHasher.def_static("operator delete[]_", (void (*)(void *)) &MAT2d_MapBiIntHasher::operator delete[], "None", py::arg("theAddress"));
// cls_MAT2d_MapBiIntHasher.def_static("operator new_", (void * (*)(size_t, void *)) &MAT2d_MapBiIntHasher::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_MAT2d_MapBiIntHasher.def_static("operator delete_", (void (*)(void *, void *)) &MAT2d_MapBiIntHasher::operator delete, "None", py::arg(""), py::arg(""));
cls_MAT2d_MapBiIntHasher.def_static("HashCode_", (Standard_Integer (*)(const MAT2d_BiInt &, const Standard_Integer)) &MAT2d_MapBiIntHasher::HashCode, "Computes a hash code for the given key, in the range [1, theUpperBound]", py::arg("theKey"), py::arg("theUpperBound"));
cls_MAT2d_MapBiIntHasher.def_static("IsEqual_", (Standard_Boolean (*)(const MAT2d_BiInt &, const MAT2d_BiInt &)) &MAT2d_MapBiIntHasher::IsEqual, "None", py::arg("Key1"), py::arg("Key2"));

// TYPEDEF: MAT2D_DATAMAPOFBIINTINTEGER
bind_NCollection_DataMap<MAT2d_BiInt, int, MAT2d_MapBiIntHasher>(mod, "MAT2d_DataMapOfBiIntInteger", py::module_local(false));

// TYPEDEF: MAT2D_DATAMAPITERATOROFDATAMAPOFBIINTINTEGER

// TYPEDEF: MAT2D_SEQUENCEOFSEQUENCEOFCURVE
bind_NCollection_Sequence<NCollection_Sequence<opencascade::handle<Geom2d_Curve> > >(mod, "MAT2d_SequenceOfSequenceOfCurve", py::module_local(false));

// CLASS: MAT2D_CONNEXION
py::class_<MAT2d_Connexion, opencascade::handle<MAT2d_Connexion>, Standard_Transient> cls_MAT2d_Connexion(mod, "MAT2d_Connexion", "A Connexion links two lines of items in a set of lines. It s contains two points and their paramatric definitions on the lines. The items can be points or curves.");

// Constructors
cls_MAT2d_Connexion.def(py::init<>());
cls_MAT2d_Connexion.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real, const gp_Pnt2d &, const gp_Pnt2d &>(), py::arg("LineA"), py::arg("LineB"), py::arg("ItemA"), py::arg("ItemB"), py::arg("Distance"), py::arg("ParameterOnA"), py::arg("ParameterOnB"), py::arg("PointA"), py::arg("PointB"));

// Methods
cls_MAT2d_Connexion.def("IndexFirstLine", (Standard_Integer (MAT2d_Connexion::*)() const) &MAT2d_Connexion::IndexFirstLine, "Returns the Index on the first line.");
cls_MAT2d_Connexion.def("IndexSecondLine", (Standard_Integer (MAT2d_Connexion::*)() const) &MAT2d_Connexion::IndexSecondLine, "Returns the Index on the Second line.");
cls_MAT2d_Connexion.def("IndexItemOnFirst", (Standard_Integer (MAT2d_Connexion::*)() const) &MAT2d_Connexion::IndexItemOnFirst, "Returns the Index of the item on the first line.");
cls_MAT2d_Connexion.def("IndexItemOnSecond", (Standard_Integer (MAT2d_Connexion::*)() const) &MAT2d_Connexion::IndexItemOnSecond, "Returns the Index of the item on the second line.");
cls_MAT2d_Connexion.def("ParameterOnFirst", (Standard_Real (MAT2d_Connexion::*)() const) &MAT2d_Connexion::ParameterOnFirst, "Returns the parameter of the point on the firstline.");
cls_MAT2d_Connexion.def("ParameterOnSecond", (Standard_Real (MAT2d_Connexion::*)() const) &MAT2d_Connexion::ParameterOnSecond, "Returns the parameter of the point on the secondline.");
cls_MAT2d_Connexion.def("PointOnFirst", (gp_Pnt2d (MAT2d_Connexion::*)() const) &MAT2d_Connexion::PointOnFirst, "Returns the point on the firstline.");
cls_MAT2d_Connexion.def("PointOnSecond", (gp_Pnt2d (MAT2d_Connexion::*)() const) &MAT2d_Connexion::PointOnSecond, "Returns the point on the secondline.");
cls_MAT2d_Connexion.def("Distance", (Standard_Real (MAT2d_Connexion::*)() const) &MAT2d_Connexion::Distance, "Returns the distance between the two points.");
cls_MAT2d_Connexion.def("IndexFirstLine", (void (MAT2d_Connexion::*)(const Standard_Integer)) &MAT2d_Connexion::IndexFirstLine, "None", py::arg("anIndex"));
cls_MAT2d_Connexion.def("IndexSecondLine", (void (MAT2d_Connexion::*)(const Standard_Integer)) &MAT2d_Connexion::IndexSecondLine, "None", py::arg("anIndex"));
cls_MAT2d_Connexion.def("IndexItemOnFirst", (void (MAT2d_Connexion::*)(const Standard_Integer)) &MAT2d_Connexion::IndexItemOnFirst, "None", py::arg("anIndex"));
cls_MAT2d_Connexion.def("IndexItemOnSecond", (void (MAT2d_Connexion::*)(const Standard_Integer)) &MAT2d_Connexion::IndexItemOnSecond, "None", py::arg("anIndex"));
cls_MAT2d_Connexion.def("ParameterOnFirst", (void (MAT2d_Connexion::*)(const Standard_Real)) &MAT2d_Connexion::ParameterOnFirst, "None", py::arg("aParameter"));
cls_MAT2d_Connexion.def("ParameterOnSecond", (void (MAT2d_Connexion::*)(const Standard_Real)) &MAT2d_Connexion::ParameterOnSecond, "None", py::arg("aParameter"));
cls_MAT2d_Connexion.def("PointOnFirst", (void (MAT2d_Connexion::*)(const gp_Pnt2d &)) &MAT2d_Connexion::PointOnFirst, "None", py::arg("aPoint"));
cls_MAT2d_Connexion.def("PointOnSecond", (void (MAT2d_Connexion::*)(const gp_Pnt2d &)) &MAT2d_Connexion::PointOnSecond, "None", py::arg("aPoint"));
cls_MAT2d_Connexion.def("Distance", (void (MAT2d_Connexion::*)(const Standard_Real)) &MAT2d_Connexion::Distance, "None", py::arg("aDistance"));
cls_MAT2d_Connexion.def("Reverse", (opencascade::handle<MAT2d_Connexion> (MAT2d_Connexion::*)() const) &MAT2d_Connexion::Reverse, "Returns the reverse connexion of <me>. the firstpoint is the secondpoint. the secondpoint is the firstpoint.");
cls_MAT2d_Connexion.def("IsAfter", (Standard_Boolean (MAT2d_Connexion::*)(const opencascade::handle<MAT2d_Connexion> &, const Standard_Real) const) &MAT2d_Connexion::IsAfter, "Returns <True> if my firstPoint is on the same line than the firstpoint of <aConnexion> and my firstpoint is after the firstpoint of <aConnexion> on the line. <aSense> = 1 if <aConnexion> is on the Left of its firstline, else <aSense> = -1.", py::arg("aConnexion"), py::arg("aSense"));
cls_MAT2d_Connexion.def("Dump", [](MAT2d_Connexion &self) -> void { return self.Dump(); });
cls_MAT2d_Connexion.def("Dump", [](MAT2d_Connexion &self, const Standard_Integer a0) -> void { return self.Dump(a0); });
cls_MAT2d_Connexion.def("Dump", (void (MAT2d_Connexion::*)(const Standard_Integer, const Standard_Integer) const) &MAT2d_Connexion::Dump, "Print <me>.", py::arg("Deep"), py::arg("Offset"));
cls_MAT2d_Connexion.def_static("get_type_name_", (const char * (*)()) &MAT2d_Connexion::get_type_name, "None");
cls_MAT2d_Connexion.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MAT2d_Connexion::get_type_descriptor, "None");
cls_MAT2d_Connexion.def("DynamicType", (const opencascade::handle<Standard_Type> & (MAT2d_Connexion::*)() const) &MAT2d_Connexion::DynamicType, "None");

// TYPEDEF: MAT2D_ARRAY2OFCONNEXION
bind_NCollection_Array2<opencascade::handle<MAT2d_Connexion> >(mod, "MAT2d_Array2OfConnexion", py::module_local(false));

// TYPEDEF: MAT2D_DATAMAPOFINTEGERCONNEXION
bind_NCollection_DataMap<int, opencascade::handle<MAT2d_Connexion>, NCollection_DefaultHasher<int> >(mod, "MAT2d_DataMapOfIntegerConnexion", py::module_local(false));

// TYPEDEF: MAT2D_DATAMAPITERATOROFDATAMAPOFINTEGERCONNEXION

// TYPEDEF: MAT2D_DATAMAPOFBIINTSEQUENCEOFINTEGER
bind_NCollection_DataMap<MAT2d_BiInt, NCollection_Sequence<int>, MAT2d_MapBiIntHasher>(mod, "MAT2d_DataMapOfBiIntSequenceOfInteger", py::module_local(false));

// TYPEDEF: MAT2D_DATAMAPITERATOROFDATAMAPOFBIINTSEQUENCEOFINTEGER

// TYPEDEF: MAT2D_SEQUENCEOFSEQUENCEOFGEOMETRY
bind_NCollection_Sequence<NCollection_Sequence<opencascade::handle<Geom2d_Geometry> > >(mod, "MAT2d_SequenceOfSequenceOfGeometry", py::module_local(false));

// TYPEDEF: MAT2D_SEQUENCEOFCONNEXION
bind_NCollection_Sequence<opencascade::handle<MAT2d_Connexion> >(mod, "MAT2d_SequenceOfConnexion", py::module_local(false));

// CLASS: MAT2D_CIRCUIT
py::class_<MAT2d_Circuit, opencascade::handle<MAT2d_Circuit>, Standard_Transient> cls_MAT2d_Circuit(mod, "MAT2d_Circuit", "Constructs a circuit on a set of lines. EquiCircuit gives a Circuit passing by all the lines in a set and all the connexions of the minipath associated.");

// Constructors
cls_MAT2d_Circuit.def(py::init<>());
cls_MAT2d_Circuit.def(py::init<const GeomAbs_JoinType>(), py::arg("aJoinType"));
cls_MAT2d_Circuit.def(py::init<const GeomAbs_JoinType, const Standard_Boolean>(), py::arg("aJoinType"), py::arg("IsOpenResult"));

// Methods
cls_MAT2d_Circuit.def("Perform", (void (MAT2d_Circuit::*)(MAT2d_SequenceOfSequenceOfGeometry &, const TColStd_SequenceOfBoolean &, const Standard_Integer, const Standard_Boolean)) &MAT2d_Circuit::Perform, "None", py::arg("aFigure"), py::arg("IsClosed"), py::arg("IndRefLine"), py::arg("Trigo"));
cls_MAT2d_Circuit.def("NumberOfItems", (Standard_Integer (MAT2d_Circuit::*)() const) &MAT2d_Circuit::NumberOfItems, "Returns the Number of Items .");
cls_MAT2d_Circuit.def("Value", (opencascade::handle<Geom2d_Geometry> (MAT2d_Circuit::*)(const Standard_Integer) const) &MAT2d_Circuit::Value, "Returns the item at position <Index> in <me>.", py::arg("Index"));
cls_MAT2d_Circuit.def("LineLength", (Standard_Integer (MAT2d_Circuit::*)(const Standard_Integer) const) &MAT2d_Circuit::LineLength, "Returns the number of items on the line <IndexLine>.", py::arg("IndexLine"));
cls_MAT2d_Circuit.def("RefToEqui", (const TColStd_SequenceOfInteger & (MAT2d_Circuit::*)(const Standard_Integer, const Standard_Integer) const) &MAT2d_Circuit::RefToEqui, "Returns the set of index of the items in <me>corresponding to the curve <IndCurve> on the line <IndLine> from the initial figure.", py::arg("IndLine"), py::arg("IndCurve"));
cls_MAT2d_Circuit.def("Connexion", (opencascade::handle<MAT2d_Connexion> (MAT2d_Circuit::*)(const Standard_Integer) const) &MAT2d_Circuit::Connexion, "Returns the Connexion on the item <Index> in me.", py::arg("Index"));
cls_MAT2d_Circuit.def("ConnexionOn", (Standard_Boolean (MAT2d_Circuit::*)(const Standard_Integer) const) &MAT2d_Circuit::ConnexionOn, "Returns <True> is there is a connexion on the item <Index> in <me>.", py::arg("Index"));
cls_MAT2d_Circuit.def_static("get_type_name_", (const char * (*)()) &MAT2d_Circuit::get_type_name, "None");
cls_MAT2d_Circuit.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MAT2d_Circuit::get_type_descriptor, "None");
cls_MAT2d_Circuit.def("DynamicType", (const opencascade::handle<Standard_Type> & (MAT2d_Circuit::*)() const) &MAT2d_Circuit::DynamicType, "None");

// CLASS: MAT2D_CUTCURVE
py::class_<MAT2d_CutCurve> cls_MAT2d_CutCurve(mod, "MAT2d_CutCurve", "Cuts a curve at the extremas of curvature and at the inflections. Constructs a trimmed Curve for each interval.");

// Constructors
cls_MAT2d_CutCurve.def(py::init<>());
cls_MAT2d_CutCurve.def(py::init<const opencascade::handle<Geom2d_Curve> &>(), py::arg("C"));

// Methods
// cls_MAT2d_CutCurve.def_static("operator new_", (void * (*)(size_t)) &MAT2d_CutCurve::operator new, "None", py::arg("theSize"));
// cls_MAT2d_CutCurve.def_static("operator delete_", (void (*)(void *)) &MAT2d_CutCurve::operator delete, "None", py::arg("theAddress"));
// cls_MAT2d_CutCurve.def_static("operator new[]_", (void * (*)(size_t)) &MAT2d_CutCurve::operator new[], "None", py::arg("theSize"));
// cls_MAT2d_CutCurve.def_static("operator delete[]_", (void (*)(void *)) &MAT2d_CutCurve::operator delete[], "None", py::arg("theAddress"));
// cls_MAT2d_CutCurve.def_static("operator new_", (void * (*)(size_t, void *)) &MAT2d_CutCurve::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_MAT2d_CutCurve.def_static("operator delete_", (void (*)(void *, void *)) &MAT2d_CutCurve::operator delete, "None", py::arg(""), py::arg(""));
cls_MAT2d_CutCurve.def("Perform", (void (MAT2d_CutCurve::*)(const opencascade::handle<Geom2d_Curve> &)) &MAT2d_CutCurve::Perform, "Cuts a curve at the extremas of curvature and at the inflections.", py::arg("C"));
// cls_MAT2d_CutCurve.def("Perform", (void (MAT2d_CutCurve::*)(const opencascade::handle<Geom2d_Curve> &, const MAT_Side)) &MAT2d_CutCurve::Perform, "Cuts a curve at the inflections, and at the extremas of curvature where the concavity is on <aSide>.", py::arg("C"), py::arg("aSide"));
// cls_MAT2d_CutCurve.def("PerformInf", (void (MAT2d_CutCurve::*)(const opencascade::handle<Geom2d_Curve> &)) &MAT2d_CutCurve::PerformInf, "Cuts a curve at the inflections.", py::arg("C"));
cls_MAT2d_CutCurve.def("UnModified", (Standard_Boolean (MAT2d_CutCurve::*)() const) &MAT2d_CutCurve::UnModified, "Returns True if the curve is not cut.");
cls_MAT2d_CutCurve.def("NbCurves", (Standard_Integer (MAT2d_CutCurve::*)() const) &MAT2d_CutCurve::NbCurves, "Returns the number of curves. it's allways greatest than 2.");
cls_MAT2d_CutCurve.def("Value", (opencascade::handle<Geom2d_TrimmedCurve> (MAT2d_CutCurve::*)(const Standard_Integer) const) &MAT2d_CutCurve::Value, "Returns the Indexth curve. raises if Index not in the range [1,NbCurves()]", py::arg("Index"));

// TYPEDEF: MAT2D_DATAMAPOFINTEGERSEQUENCEOFCONNEXION
bind_NCollection_DataMap<int, NCollection_Sequence<opencascade::handle<MAT2d_Connexion> >, NCollection_DefaultHasher<int> >(mod, "MAT2d_DataMapOfIntegerSequenceOfConnexion", py::module_local(false));

// TYPEDEF: MAT2D_DATAMAPITERATOROFDATAMAPOFINTEGERSEQUENCEOFCONNEXION

// CLASS: MAT2D_MAT2D
py::class_<MAT2d_Mat2d> cls_MAT2d_Mat2d(mod, "MAT2d_Mat2d", "this class contains the generic algoritm of computation of the bisecting locus.");

// Constructors
cls_MAT2d_Mat2d.def(py::init<>());
cls_MAT2d_Mat2d.def(py::init<const Standard_Boolean>(), py::arg("IsOpenResult"));

// Methods
// cls_MAT2d_Mat2d.def_static("operator new_", (void * (*)(size_t)) &MAT2d_Mat2d::operator new, "None", py::arg("theSize"));
// cls_MAT2d_Mat2d.def_static("operator delete_", (void (*)(void *)) &MAT2d_Mat2d::operator delete, "None", py::arg("theAddress"));
// cls_MAT2d_Mat2d.def_static("operator new[]_", (void * (*)(size_t)) &MAT2d_Mat2d::operator new[], "None", py::arg("theSize"));
// cls_MAT2d_Mat2d.def_static("operator delete[]_", (void (*)(void *)) &MAT2d_Mat2d::operator delete[], "None", py::arg("theAddress"));
// cls_MAT2d_Mat2d.def_static("operator new_", (void * (*)(size_t, void *)) &MAT2d_Mat2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_MAT2d_Mat2d.def_static("operator delete_", (void (*)(void *, void *)) &MAT2d_Mat2d::operator delete, "None", py::arg(""), py::arg(""));
cls_MAT2d_Mat2d.def("CreateMat", (void (MAT2d_Mat2d::*)(MAT2d_Tool2d &)) &MAT2d_Mat2d::CreateMat, "Algoritm of computation of the bisecting locus.", py::arg("aTool"));
cls_MAT2d_Mat2d.def("CreateMatOpen", (void (MAT2d_Mat2d::*)(MAT2d_Tool2d &)) &MAT2d_Mat2d::CreateMatOpen, "Algoritm of computation of the bisecting locus for open wire.", py::arg("aTool"));
cls_MAT2d_Mat2d.def("IsDone", (Standard_Boolean (MAT2d_Mat2d::*)() const) &MAT2d_Mat2d::IsDone, "Returns <TRUE> if CreateMat has succeeded.");
cls_MAT2d_Mat2d.def("Init", (void (MAT2d_Mat2d::*)()) &MAT2d_Mat2d::Init, "Initialize an iterator on the set of the roots of the trees of bisectors.");
cls_MAT2d_Mat2d.def("More", (Standard_Boolean (MAT2d_Mat2d::*)() const) &MAT2d_Mat2d::More, "Return False if there is no more roots.");
cls_MAT2d_Mat2d.def("Next", (void (MAT2d_Mat2d::*)()) &MAT2d_Mat2d::Next, "Move to the next root.");
cls_MAT2d_Mat2d.def("Bisector", (opencascade::handle<MAT_Bisector> (MAT2d_Mat2d::*)() const) &MAT2d_Mat2d::Bisector, "Returns the current root.");
cls_MAT2d_Mat2d.def("SemiInfinite", (Standard_Boolean (MAT2d_Mat2d::*)() const) &MAT2d_Mat2d::SemiInfinite, "Returns True if there are semi_infinite bisectors. So there is a tree for each semi_infinte bisector.");
cls_MAT2d_Mat2d.def("NumberOfBisectors", (Standard_Integer (MAT2d_Mat2d::*)() const) &MAT2d_Mat2d::NumberOfBisectors, "Returns the total number of bisectors.");

// CLASS: MAT2D_MINIPATH
py::class_<MAT2d_MiniPath> cls_MAT2d_MiniPath(mod, "MAT2d_MiniPath", "MiniPath computes a path to link all the lines in a set of lines. The path is described as a set of connexions.");

// Constructors
cls_MAT2d_MiniPath.def(py::init<>());

// Methods
// cls_MAT2d_MiniPath.def_static("operator new_", (void * (*)(size_t)) &MAT2d_MiniPath::operator new, "None", py::arg("theSize"));
// cls_MAT2d_MiniPath.def_static("operator delete_", (void (*)(void *)) &MAT2d_MiniPath::operator delete, "None", py::arg("theAddress"));
// cls_MAT2d_MiniPath.def_static("operator new[]_", (void * (*)(size_t)) &MAT2d_MiniPath::operator new[], "None", py::arg("theSize"));
// cls_MAT2d_MiniPath.def_static("operator delete[]_", (void (*)(void *)) &MAT2d_MiniPath::operator delete[], "None", py::arg("theAddress"));
// cls_MAT2d_MiniPath.def_static("operator new_", (void * (*)(size_t, void *)) &MAT2d_MiniPath::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_MAT2d_MiniPath.def_static("operator delete_", (void (*)(void *, void *)) &MAT2d_MiniPath::operator delete, "None", py::arg(""), py::arg(""));
cls_MAT2d_MiniPath.def("Perform", (void (MAT2d_MiniPath::*)(const MAT2d_SequenceOfSequenceOfGeometry &, const Standard_Integer, const Standard_Boolean)) &MAT2d_MiniPath::Perform, "Computes the path to link the lines in <Figure>. the path starts on the line of index <IndStart> <Sense> = True if the Circuit turns in the trigonometric sense.", py::arg("Figure"), py::arg("IndStart"), py::arg("Sense"));
cls_MAT2d_MiniPath.def("RunOnConnexions", (void (MAT2d_MiniPath::*)()) &MAT2d_MiniPath::RunOnConnexions, "Run on the set of connexions to compute the path. the path is an exploration of the tree which contains the connexions and their reverses. if the tree of connexions is A / | B E / | | C D F");
cls_MAT2d_MiniPath.def("Path", (const MAT2d_SequenceOfConnexion & (MAT2d_MiniPath::*)() const) &MAT2d_MiniPath::Path, "Returns the sequence of connexions corresponding to the path.");
cls_MAT2d_MiniPath.def("IsConnexionsFrom", (Standard_Boolean (MAT2d_MiniPath::*)(const Standard_Integer) const) &MAT2d_MiniPath::IsConnexionsFrom, "Returns <True> if there is one Connexion which starts on line designed by <Index>.", py::arg("Index"));
cls_MAT2d_MiniPath.def("ConnexionsFrom", (MAT2d_SequenceOfConnexion & (MAT2d_MiniPath::*)(const Standard_Integer)) &MAT2d_MiniPath::ConnexionsFrom, "Returns the connexions which start on line designed by <Index>.", py::arg("Index"));
cls_MAT2d_MiniPath.def("IsRoot", (Standard_Boolean (MAT2d_MiniPath::*)(const Standard_Integer) const) &MAT2d_MiniPath::IsRoot, "Returns <True> if the line designed by <Index> is the root.", py::arg("Index"));
cls_MAT2d_MiniPath.def("Father", (opencascade::handle<MAT2d_Connexion> (MAT2d_MiniPath::*)(const Standard_Integer)) &MAT2d_MiniPath::Father, "Returns the connexion which ends on line designed by <Index>.", py::arg("Index"));


}
