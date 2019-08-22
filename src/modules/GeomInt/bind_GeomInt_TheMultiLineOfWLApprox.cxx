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
#include <Standard_Handle.hxx>
#include <IntPatch_WLine.hxx>
#include <Standard_TypeDef.hxx>
#include <Approx_Status.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <TColgp_Array1OfVec.hxx>
#include <TColgp_Array1OfVec2d.hxx>
#include <GeomInt_TheMultiLineOfWLApprox.hxx>

void bind_GeomInt_TheMultiLineOfWLApprox(py::module &mod){

py::class_<GeomInt_TheMultiLineOfWLApprox> cls_GeomInt_TheMultiLineOfWLApprox(mod, "GeomInt_TheMultiLineOfWLApprox", "None");

// Constructors
cls_GeomInt_TheMultiLineOfWLApprox.def(py::init<>());
cls_GeomInt_TheMultiLineOfWLApprox.def(py::init<const opencascade::handle<IntPatch_WLine> &, const Standard_Address, const Standard_Integer, const Standard_Integer, const Standard_Boolean, const Standard_Boolean, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean>(), py::arg("line"), py::arg("PtrSvSurfaces"), py::arg("NbP3d"), py::arg("NbP2d"), py::arg("ApproxU1V1"), py::arg("ApproxU2V2"), py::arg("xo"), py::arg("yo"), py::arg("zo"), py::arg("u1o"), py::arg("v1o"), py::arg("u2o"), py::arg("v2o"), py::arg("P2DOnFirst"));
cls_GeomInt_TheMultiLineOfWLApprox.def(py::init<const opencascade::handle<IntPatch_WLine> &, const Standard_Address, const Standard_Integer, const Standard_Integer, const Standard_Boolean, const Standard_Boolean, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean, const Standard_Integer>(), py::arg("line"), py::arg("PtrSvSurfaces"), py::arg("NbP3d"), py::arg("NbP2d"), py::arg("ApproxU1V1"), py::arg("ApproxU2V2"), py::arg("xo"), py::arg("yo"), py::arg("zo"), py::arg("u1o"), py::arg("v1o"), py::arg("u2o"), py::arg("v2o"), py::arg("P2DOnFirst"), py::arg("IndMin"));
cls_GeomInt_TheMultiLineOfWLApprox.def(py::init<const opencascade::handle<IntPatch_WLine> &, const Standard_Address, const Standard_Integer, const Standard_Integer, const Standard_Boolean, const Standard_Boolean, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean, const Standard_Integer, const Standard_Integer>(), py::arg("line"), py::arg("PtrSvSurfaces"), py::arg("NbP3d"), py::arg("NbP2d"), py::arg("ApproxU1V1"), py::arg("ApproxU2V2"), py::arg("xo"), py::arg("yo"), py::arg("zo"), py::arg("u1o"), py::arg("v1o"), py::arg("u2o"), py::arg("v2o"), py::arg("P2DOnFirst"), py::arg("IndMin"), py::arg("IndMax"));
cls_GeomInt_TheMultiLineOfWLApprox.def(py::init<const opencascade::handle<IntPatch_WLine> &, const Standard_Integer, const Standard_Integer, const Standard_Boolean, const Standard_Boolean, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean>(), py::arg("line"), py::arg("NbP3d"), py::arg("NbP2d"), py::arg("ApproxU1V1"), py::arg("ApproxU2V2"), py::arg("xo"), py::arg("yo"), py::arg("zo"), py::arg("u1o"), py::arg("v1o"), py::arg("u2o"), py::arg("v2o"), py::arg("P2DOnFirst"));
cls_GeomInt_TheMultiLineOfWLApprox.def(py::init<const opencascade::handle<IntPatch_WLine> &, const Standard_Integer, const Standard_Integer, const Standard_Boolean, const Standard_Boolean, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean, const Standard_Integer>(), py::arg("line"), py::arg("NbP3d"), py::arg("NbP2d"), py::arg("ApproxU1V1"), py::arg("ApproxU2V2"), py::arg("xo"), py::arg("yo"), py::arg("zo"), py::arg("u1o"), py::arg("v1o"), py::arg("u2o"), py::arg("v2o"), py::arg("P2DOnFirst"), py::arg("IndMin"));
cls_GeomInt_TheMultiLineOfWLApprox.def(py::init<const opencascade::handle<IntPatch_WLine> &, const Standard_Integer, const Standard_Integer, const Standard_Boolean, const Standard_Boolean, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean, const Standard_Integer, const Standard_Integer>(), py::arg("line"), py::arg("NbP3d"), py::arg("NbP2d"), py::arg("ApproxU1V1"), py::arg("ApproxU2V2"), py::arg("xo"), py::arg("yo"), py::arg("zo"), py::arg("u1o"), py::arg("v1o"), py::arg("u2o"), py::arg("v2o"), py::arg("P2DOnFirst"), py::arg("IndMin"), py::arg("IndMax"));

// Fields

// Methods
// cls_GeomInt_TheMultiLineOfWLApprox.def_static("operator new_", (void * (*)(size_t)) &GeomInt_TheMultiLineOfWLApprox::operator new, "None", py::arg("theSize"));
// cls_GeomInt_TheMultiLineOfWLApprox.def_static("operator delete_", (void (*)(void *)) &GeomInt_TheMultiLineOfWLApprox::operator delete, "None", py::arg("theAddress"));
// cls_GeomInt_TheMultiLineOfWLApprox.def_static("operator new[]_", (void * (*)(size_t)) &GeomInt_TheMultiLineOfWLApprox::operator new[], "None", py::arg("theSize"));
// cls_GeomInt_TheMultiLineOfWLApprox.def_static("operator delete[]_", (void (*)(void *)) &GeomInt_TheMultiLineOfWLApprox::operator delete[], "None", py::arg("theAddress"));
// cls_GeomInt_TheMultiLineOfWLApprox.def_static("operator new_", (void * (*)(size_t, void *)) &GeomInt_TheMultiLineOfWLApprox::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomInt_TheMultiLineOfWLApprox.def_static("operator delete_", (void (*)(void *, void *)) &GeomInt_TheMultiLineOfWLApprox::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomInt_TheMultiLineOfWLApprox.def("FirstPoint", (Standard_Integer (GeomInt_TheMultiLineOfWLApprox::*)() const) &GeomInt_TheMultiLineOfWLApprox::FirstPoint, "None");
cls_GeomInt_TheMultiLineOfWLApprox.def("LastPoint", (Standard_Integer (GeomInt_TheMultiLineOfWLApprox::*)() const) &GeomInt_TheMultiLineOfWLApprox::LastPoint, "None");
cls_GeomInt_TheMultiLineOfWLApprox.def("NbP2d", (Standard_Integer (GeomInt_TheMultiLineOfWLApprox::*)() const) &GeomInt_TheMultiLineOfWLApprox::NbP2d, "Returns the number of 2d points of a TheLine.");
cls_GeomInt_TheMultiLineOfWLApprox.def("NbP3d", (Standard_Integer (GeomInt_TheMultiLineOfWLApprox::*)() const) &GeomInt_TheMultiLineOfWLApprox::NbP3d, "Returns the number of 3d points of a TheLine.");
cls_GeomInt_TheMultiLineOfWLApprox.def("WhatStatus", (Approx_Status (GeomInt_TheMultiLineOfWLApprox::*)() const) &GeomInt_TheMultiLineOfWLApprox::WhatStatus, "None");
cls_GeomInt_TheMultiLineOfWLApprox.def("Value", (void (GeomInt_TheMultiLineOfWLApprox::*)(const Standard_Integer, TColgp_Array1OfPnt &) const) &GeomInt_TheMultiLineOfWLApprox::Value, "Returns the 3d points of the multipoint <MPointIndex> when only 3d points exist.", py::arg("MPointIndex"), py::arg("tabPt"));
cls_GeomInt_TheMultiLineOfWLApprox.def("Value", (void (GeomInt_TheMultiLineOfWLApprox::*)(const Standard_Integer, TColgp_Array1OfPnt2d &) const) &GeomInt_TheMultiLineOfWLApprox::Value, "Returns the 2d points of the multipoint <MPointIndex> when only 2d points exist.", py::arg("MPointIndex"), py::arg("tabPt2d"));
cls_GeomInt_TheMultiLineOfWLApprox.def("Value", (void (GeomInt_TheMultiLineOfWLApprox::*)(const Standard_Integer, TColgp_Array1OfPnt &, TColgp_Array1OfPnt2d &) const) &GeomInt_TheMultiLineOfWLApprox::Value, "returns the 3d and 2d points of the multipoint <MPointIndex>.", py::arg("MPointIndex"), py::arg("tabPt"), py::arg("tabPt2d"));
cls_GeomInt_TheMultiLineOfWLApprox.def("Tangency", (Standard_Boolean (GeomInt_TheMultiLineOfWLApprox::*)(const Standard_Integer, TColgp_Array1OfVec &) const) &GeomInt_TheMultiLineOfWLApprox::Tangency, "Returns the 3d tangency points of the multipoint <MPointIndex> only when 3d points exist.", py::arg("MPointIndex"), py::arg("tabV"));
cls_GeomInt_TheMultiLineOfWLApprox.def("Tangency", (Standard_Boolean (GeomInt_TheMultiLineOfWLApprox::*)(const Standard_Integer, TColgp_Array1OfVec2d &) const) &GeomInt_TheMultiLineOfWLApprox::Tangency, "Returns the 2d tangency points of the multipoint <MPointIndex> only when 2d points exist.", py::arg("MPointIndex"), py::arg("tabV2d"));
cls_GeomInt_TheMultiLineOfWLApprox.def("Tangency", (Standard_Boolean (GeomInt_TheMultiLineOfWLApprox::*)(const Standard_Integer, TColgp_Array1OfVec &, TColgp_Array1OfVec2d &) const) &GeomInt_TheMultiLineOfWLApprox::Tangency, "Returns the 3d and 2d points of the multipoint <MPointIndex>.", py::arg("MPointIndex"), py::arg("tabV"), py::arg("tabV2d"));
cls_GeomInt_TheMultiLineOfWLApprox.def("MakeMLBetween", (GeomInt_TheMultiLineOfWLApprox (GeomInt_TheMultiLineOfWLApprox::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer) const) &GeomInt_TheMultiLineOfWLApprox::MakeMLBetween, "Tries to make a sub-line between <Low> and <High> points of this line by adding <NbPointsToInsert> new points", py::arg("Low"), py::arg("High"), py::arg("NbPointsToInsert"));
cls_GeomInt_TheMultiLineOfWLApprox.def("MakeMLOneMorePoint", (Standard_Boolean (GeomInt_TheMultiLineOfWLApprox::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer, GeomInt_TheMultiLineOfWLApprox &) const) &GeomInt_TheMultiLineOfWLApprox::MakeMLOneMorePoint, "Tries to make a sub-line between <Low> and <High> points of this line by adding one more point between (indbad-1)-th and indbad-th points", py::arg("Low"), py::arg("High"), py::arg("indbad"), py::arg("OtherLine"));
cls_GeomInt_TheMultiLineOfWLApprox.def("Dump", (void (GeomInt_TheMultiLineOfWLApprox::*)() const) &GeomInt_TheMultiLineOfWLApprox::Dump, "Dump of the current multi-line.");

// Enums

}