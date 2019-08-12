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
#include <MAT_Side.hxx>
#include <GeomAbs_JoinType.hxx>
#include <Standard_Handle.hxx>
#include <MAT2d_Circuit.hxx>
#include <Standard_TypeDef.hxx>
#include <MAT_Bisector.hxx>
#include <Bisector_Bisec.hxx>
#include <Geom2d_Geometry.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Vec2d.hxx>
#include <MAT2d_DataMapOfIntegerBisec.hxx>
#include <MAT2d_DataMapOfIntegerPnt2d.hxx>
#include <MAT2d_DataMapOfIntegerVec2d.hxx>
#include <TColStd_SequenceOfInteger.hxx>
#include <MAT2d_Tool2d.hxx>

void bind_MAT2d_Tool2d(py::module &mod){

py::class_<MAT2d_Tool2d, std::unique_ptr<MAT2d_Tool2d, Deleter<MAT2d_Tool2d>>> cls_MAT2d_Tool2d(mod, "MAT2d_Tool2d", "Set of the methods useful for the MAT's computation. Tool2d contains the geometry of the bisecting locus.");

// Constructors
cls_MAT2d_Tool2d.def(py::init<>());

// Fields

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

// Enums

}