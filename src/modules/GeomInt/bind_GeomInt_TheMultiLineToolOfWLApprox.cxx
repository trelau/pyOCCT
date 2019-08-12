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
#include <Standard_TypeDef.hxx>
#include <GeomInt_TheMultiLineOfWLApprox.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <TColgp_Array1OfVec.hxx>
#include <TColgp_Array1OfVec2d.hxx>
#include <Approx_Status.hxx>
#include <GeomInt_TheMultiLineToolOfWLApprox.hxx>

void bind_GeomInt_TheMultiLineToolOfWLApprox(py::module &mod){

py::class_<GeomInt_TheMultiLineToolOfWLApprox, std::unique_ptr<GeomInt_TheMultiLineToolOfWLApprox, Deleter<GeomInt_TheMultiLineToolOfWLApprox>>> cls_GeomInt_TheMultiLineToolOfWLApprox(mod, "GeomInt_TheMultiLineToolOfWLApprox", "None");

// Constructors

// Fields

// Methods
// cls_GeomInt_TheMultiLineToolOfWLApprox.def_static("operator new_", (void * (*)(size_t)) &GeomInt_TheMultiLineToolOfWLApprox::operator new, "None", py::arg("theSize"));
// cls_GeomInt_TheMultiLineToolOfWLApprox.def_static("operator delete_", (void (*)(void *)) &GeomInt_TheMultiLineToolOfWLApprox::operator delete, "None", py::arg("theAddress"));
// cls_GeomInt_TheMultiLineToolOfWLApprox.def_static("operator new[]_", (void * (*)(size_t)) &GeomInt_TheMultiLineToolOfWLApprox::operator new[], "None", py::arg("theSize"));
// cls_GeomInt_TheMultiLineToolOfWLApprox.def_static("operator delete[]_", (void (*)(void *)) &GeomInt_TheMultiLineToolOfWLApprox::operator delete[], "None", py::arg("theAddress"));
// cls_GeomInt_TheMultiLineToolOfWLApprox.def_static("operator new_", (void * (*)(size_t, void *)) &GeomInt_TheMultiLineToolOfWLApprox::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomInt_TheMultiLineToolOfWLApprox.def_static("operator delete_", (void (*)(void *, void *)) &GeomInt_TheMultiLineToolOfWLApprox::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomInt_TheMultiLineToolOfWLApprox.def_static("FirstPoint_", (Standard_Integer (*)(const GeomInt_TheMultiLineOfWLApprox &)) &GeomInt_TheMultiLineToolOfWLApprox::FirstPoint, "Returns the number of multipoints of the TheMultiLine.", py::arg("ML"));
cls_GeomInt_TheMultiLineToolOfWLApprox.def_static("LastPoint_", (Standard_Integer (*)(const GeomInt_TheMultiLineOfWLApprox &)) &GeomInt_TheMultiLineToolOfWLApprox::LastPoint, "Returns the number of multipoints of the TheMultiLine.", py::arg("ML"));
cls_GeomInt_TheMultiLineToolOfWLApprox.def_static("NbP2d_", (Standard_Integer (*)(const GeomInt_TheMultiLineOfWLApprox &)) &GeomInt_TheMultiLineToolOfWLApprox::NbP2d, "Returns the number of 2d points of a TheMultiLine.", py::arg("ML"));
cls_GeomInt_TheMultiLineToolOfWLApprox.def_static("NbP3d_", (Standard_Integer (*)(const GeomInt_TheMultiLineOfWLApprox &)) &GeomInt_TheMultiLineToolOfWLApprox::NbP3d, "Returns the number of 3d points of a TheMultiLine.", py::arg("ML"));
cls_GeomInt_TheMultiLineToolOfWLApprox.def_static("Value_", (void (*)(const GeomInt_TheMultiLineOfWLApprox &, const Standard_Integer, TColgp_Array1OfPnt &)) &GeomInt_TheMultiLineToolOfWLApprox::Value, "returns the 3d points of the multipoint <MPointIndex> when only 3d points exist.", py::arg("ML"), py::arg("MPointIndex"), py::arg("tabPt"));
cls_GeomInt_TheMultiLineToolOfWLApprox.def_static("Value_", (void (*)(const GeomInt_TheMultiLineOfWLApprox &, const Standard_Integer, TColgp_Array1OfPnt2d &)) &GeomInt_TheMultiLineToolOfWLApprox::Value, "returns the 2d points of the multipoint <MPointIndex> when only 2d points exist.", py::arg("ML"), py::arg("MPointIndex"), py::arg("tabPt2d"));
cls_GeomInt_TheMultiLineToolOfWLApprox.def_static("Value_", (void (*)(const GeomInt_TheMultiLineOfWLApprox &, const Standard_Integer, TColgp_Array1OfPnt &, TColgp_Array1OfPnt2d &)) &GeomInt_TheMultiLineToolOfWLApprox::Value, "returns the 3d and 2d points of the multipoint <MPointIndex>.", py::arg("ML"), py::arg("MPointIndex"), py::arg("tabPt"), py::arg("tabPt2d"));
cls_GeomInt_TheMultiLineToolOfWLApprox.def_static("Tangency_", (Standard_Boolean (*)(const GeomInt_TheMultiLineOfWLApprox &, const Standard_Integer, TColgp_Array1OfVec &)) &GeomInt_TheMultiLineToolOfWLApprox::Tangency, "returns the 3d points of the multipoint <MPointIndex> when only 3d points exist.", py::arg("ML"), py::arg("MPointIndex"), py::arg("tabV"));
cls_GeomInt_TheMultiLineToolOfWLApprox.def_static("Tangency_", (Standard_Boolean (*)(const GeomInt_TheMultiLineOfWLApprox &, const Standard_Integer, TColgp_Array1OfVec2d &)) &GeomInt_TheMultiLineToolOfWLApprox::Tangency, "returns the 2d tangency points of the multipoint <MPointIndex> only when 2d points exist.", py::arg("ML"), py::arg("MPointIndex"), py::arg("tabV2d"));
cls_GeomInt_TheMultiLineToolOfWLApprox.def_static("Tangency_", (Standard_Boolean (*)(const GeomInt_TheMultiLineOfWLApprox &, const Standard_Integer, TColgp_Array1OfVec &, TColgp_Array1OfVec2d &)) &GeomInt_TheMultiLineToolOfWLApprox::Tangency, "returns the 3d and 2d points of the multipoint <MPointIndex>.", py::arg("ML"), py::arg("MPointIndex"), py::arg("tabV"), py::arg("tabV2d"));
cls_GeomInt_TheMultiLineToolOfWLApprox.def_static("Curvature_", (Standard_Boolean (*)(const GeomInt_TheMultiLineOfWLApprox &, const Standard_Integer, TColgp_Array1OfVec &)) &GeomInt_TheMultiLineToolOfWLApprox::Curvature, "returns the 3d curvature of the multipoint <MPointIndex> when only 3d points exist.", py::arg("ML"), py::arg("MPointIndex"), py::arg("tabV"));
cls_GeomInt_TheMultiLineToolOfWLApprox.def_static("Curvature_", (Standard_Boolean (*)(const GeomInt_TheMultiLineOfWLApprox &, const Standard_Integer, TColgp_Array1OfVec2d &)) &GeomInt_TheMultiLineToolOfWLApprox::Curvature, "returns the 2d curvature points of the multipoint <MPointIndex> only when 2d points exist.", py::arg("ML"), py::arg("MPointIndex"), py::arg("tabV2d"));
cls_GeomInt_TheMultiLineToolOfWLApprox.def_static("Curvature_", (Standard_Boolean (*)(const GeomInt_TheMultiLineOfWLApprox &, const Standard_Integer, TColgp_Array1OfVec &, TColgp_Array1OfVec2d &)) &GeomInt_TheMultiLineToolOfWLApprox::Curvature, "returns the 3d and 2d curvature of the multipoint <MPointIndex>.", py::arg("ML"), py::arg("MPointIndex"), py::arg("tabV"), py::arg("tabV2d"));
cls_GeomInt_TheMultiLineToolOfWLApprox.def_static("MakeMLBetween_", (GeomInt_TheMultiLineOfWLApprox (*)(const GeomInt_TheMultiLineOfWLApprox &, const Standard_Integer, const Standard_Integer, const Standard_Integer)) &GeomInt_TheMultiLineToolOfWLApprox::MakeMLBetween, "Is called if WhatStatus returned 'PointsAdded'.", py::arg("ML"), py::arg("I1"), py::arg("I2"), py::arg("NbPMin"));
cls_GeomInt_TheMultiLineToolOfWLApprox.def_static("MakeMLOneMorePoint_", (Standard_Boolean (*)(const GeomInt_TheMultiLineOfWLApprox &, const Standard_Integer, const Standard_Integer, const Standard_Integer, GeomInt_TheMultiLineOfWLApprox &)) &GeomInt_TheMultiLineToolOfWLApprox::MakeMLOneMorePoint, "Is called when the Bezier curve contains a loop", py::arg("ML"), py::arg("I1"), py::arg("I2"), py::arg("indbad"), py::arg("OtherLine"));
cls_GeomInt_TheMultiLineToolOfWLApprox.def_static("WhatStatus_", (Approx_Status (*)(const GeomInt_TheMultiLineOfWLApprox &, const Standard_Integer, const Standard_Integer)) &GeomInt_TheMultiLineToolOfWLApprox::WhatStatus, "None", py::arg("ML"), py::arg("I1"), py::arg("I2"));
cls_GeomInt_TheMultiLineToolOfWLApprox.def_static("Dump_", (void (*)(const GeomInt_TheMultiLineOfWLApprox &)) &GeomInt_TheMultiLineToolOfWLApprox::Dump, "Dump of the current multi-line.", py::arg("ML"));

// Enums

}