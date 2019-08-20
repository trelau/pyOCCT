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
#include <BRepApprox_TheMultiLineOfApprox.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <TColgp_Array1OfVec.hxx>
#include <TColgp_Array1OfVec2d.hxx>
#include <Approx_Status.hxx>
#include <BRepApprox_TheMultiLineToolOfApprox.hxx>

void bind_BRepApprox_TheMultiLineToolOfApprox(py::module &mod){

py::class_<BRepApprox_TheMultiLineToolOfApprox, std::unique_ptr<BRepApprox_TheMultiLineToolOfApprox>> cls_BRepApprox_TheMultiLineToolOfApprox(mod, "BRepApprox_TheMultiLineToolOfApprox", "None");

// Constructors

// Fields

// Methods
// cls_BRepApprox_TheMultiLineToolOfApprox.def_static("operator new_", (void * (*)(size_t)) &BRepApprox_TheMultiLineToolOfApprox::operator new, "None", py::arg("theSize"));
// cls_BRepApprox_TheMultiLineToolOfApprox.def_static("operator delete_", (void (*)(void *)) &BRepApprox_TheMultiLineToolOfApprox::operator delete, "None", py::arg("theAddress"));
// cls_BRepApprox_TheMultiLineToolOfApprox.def_static("operator new[]_", (void * (*)(size_t)) &BRepApprox_TheMultiLineToolOfApprox::operator new[], "None", py::arg("theSize"));
// cls_BRepApprox_TheMultiLineToolOfApprox.def_static("operator delete[]_", (void (*)(void *)) &BRepApprox_TheMultiLineToolOfApprox::operator delete[], "None", py::arg("theAddress"));
// cls_BRepApprox_TheMultiLineToolOfApprox.def_static("operator new_", (void * (*)(size_t, void *)) &BRepApprox_TheMultiLineToolOfApprox::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepApprox_TheMultiLineToolOfApprox.def_static("operator delete_", (void (*)(void *, void *)) &BRepApprox_TheMultiLineToolOfApprox::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepApprox_TheMultiLineToolOfApprox.def_static("FirstPoint_", (Standard_Integer (*)(const BRepApprox_TheMultiLineOfApprox &)) &BRepApprox_TheMultiLineToolOfApprox::FirstPoint, "Returns the number of multipoints of the TheMultiLine.", py::arg("ML"));
cls_BRepApprox_TheMultiLineToolOfApprox.def_static("LastPoint_", (Standard_Integer (*)(const BRepApprox_TheMultiLineOfApprox &)) &BRepApprox_TheMultiLineToolOfApprox::LastPoint, "Returns the number of multipoints of the TheMultiLine.", py::arg("ML"));
cls_BRepApprox_TheMultiLineToolOfApprox.def_static("NbP2d_", (Standard_Integer (*)(const BRepApprox_TheMultiLineOfApprox &)) &BRepApprox_TheMultiLineToolOfApprox::NbP2d, "Returns the number of 2d points of a TheMultiLine.", py::arg("ML"));
cls_BRepApprox_TheMultiLineToolOfApprox.def_static("NbP3d_", (Standard_Integer (*)(const BRepApprox_TheMultiLineOfApprox &)) &BRepApprox_TheMultiLineToolOfApprox::NbP3d, "Returns the number of 3d points of a TheMultiLine.", py::arg("ML"));
cls_BRepApprox_TheMultiLineToolOfApprox.def_static("Value_", (void (*)(const BRepApprox_TheMultiLineOfApprox &, const Standard_Integer, TColgp_Array1OfPnt &)) &BRepApprox_TheMultiLineToolOfApprox::Value, "returns the 3d points of the multipoint <MPointIndex> when only 3d points exist.", py::arg("ML"), py::arg("MPointIndex"), py::arg("tabPt"));
cls_BRepApprox_TheMultiLineToolOfApprox.def_static("Value_", (void (*)(const BRepApprox_TheMultiLineOfApprox &, const Standard_Integer, TColgp_Array1OfPnt2d &)) &BRepApprox_TheMultiLineToolOfApprox::Value, "returns the 2d points of the multipoint <MPointIndex> when only 2d points exist.", py::arg("ML"), py::arg("MPointIndex"), py::arg("tabPt2d"));
cls_BRepApprox_TheMultiLineToolOfApprox.def_static("Value_", (void (*)(const BRepApprox_TheMultiLineOfApprox &, const Standard_Integer, TColgp_Array1OfPnt &, TColgp_Array1OfPnt2d &)) &BRepApprox_TheMultiLineToolOfApprox::Value, "returns the 3d and 2d points of the multipoint <MPointIndex>.", py::arg("ML"), py::arg("MPointIndex"), py::arg("tabPt"), py::arg("tabPt2d"));
cls_BRepApprox_TheMultiLineToolOfApprox.def_static("Tangency_", (Standard_Boolean (*)(const BRepApprox_TheMultiLineOfApprox &, const Standard_Integer, TColgp_Array1OfVec &)) &BRepApprox_TheMultiLineToolOfApprox::Tangency, "returns the 3d points of the multipoint <MPointIndex> when only 3d points exist.", py::arg("ML"), py::arg("MPointIndex"), py::arg("tabV"));
cls_BRepApprox_TheMultiLineToolOfApprox.def_static("Tangency_", (Standard_Boolean (*)(const BRepApprox_TheMultiLineOfApprox &, const Standard_Integer, TColgp_Array1OfVec2d &)) &BRepApprox_TheMultiLineToolOfApprox::Tangency, "returns the 2d tangency points of the multipoint <MPointIndex> only when 2d points exist.", py::arg("ML"), py::arg("MPointIndex"), py::arg("tabV2d"));
cls_BRepApprox_TheMultiLineToolOfApprox.def_static("Tangency_", (Standard_Boolean (*)(const BRepApprox_TheMultiLineOfApprox &, const Standard_Integer, TColgp_Array1OfVec &, TColgp_Array1OfVec2d &)) &BRepApprox_TheMultiLineToolOfApprox::Tangency, "returns the 3d and 2d points of the multipoint <MPointIndex>.", py::arg("ML"), py::arg("MPointIndex"), py::arg("tabV"), py::arg("tabV2d"));
cls_BRepApprox_TheMultiLineToolOfApprox.def_static("Curvature_", (Standard_Boolean (*)(const BRepApprox_TheMultiLineOfApprox &, const Standard_Integer, TColgp_Array1OfVec &)) &BRepApprox_TheMultiLineToolOfApprox::Curvature, "returns the 3d curvature of the multipoint <MPointIndex> when only 3d points exist.", py::arg("ML"), py::arg("MPointIndex"), py::arg("tabV"));
cls_BRepApprox_TheMultiLineToolOfApprox.def_static("Curvature_", (Standard_Boolean (*)(const BRepApprox_TheMultiLineOfApprox &, const Standard_Integer, TColgp_Array1OfVec2d &)) &BRepApprox_TheMultiLineToolOfApprox::Curvature, "returns the 2d curvature points of the multipoint <MPointIndex> only when 2d points exist.", py::arg("ML"), py::arg("MPointIndex"), py::arg("tabV2d"));
cls_BRepApprox_TheMultiLineToolOfApprox.def_static("Curvature_", (Standard_Boolean (*)(const BRepApprox_TheMultiLineOfApprox &, const Standard_Integer, TColgp_Array1OfVec &, TColgp_Array1OfVec2d &)) &BRepApprox_TheMultiLineToolOfApprox::Curvature, "returns the 3d and 2d curvature of the multipoint <MPointIndex>.", py::arg("ML"), py::arg("MPointIndex"), py::arg("tabV"), py::arg("tabV2d"));
cls_BRepApprox_TheMultiLineToolOfApprox.def_static("MakeMLBetween_", (BRepApprox_TheMultiLineOfApprox (*)(const BRepApprox_TheMultiLineOfApprox &, const Standard_Integer, const Standard_Integer, const Standard_Integer)) &BRepApprox_TheMultiLineToolOfApprox::MakeMLBetween, "Is called if WhatStatus returned 'PointsAdded'.", py::arg("ML"), py::arg("I1"), py::arg("I2"), py::arg("NbPMin"));
cls_BRepApprox_TheMultiLineToolOfApprox.def_static("MakeMLOneMorePoint_", (Standard_Boolean (*)(const BRepApprox_TheMultiLineOfApprox &, const Standard_Integer, const Standard_Integer, const Standard_Integer, BRepApprox_TheMultiLineOfApprox &)) &BRepApprox_TheMultiLineToolOfApprox::MakeMLOneMorePoint, "Is called when the Bezier curve contains a loop", py::arg("ML"), py::arg("I1"), py::arg("I2"), py::arg("indbad"), py::arg("OtherLine"));
cls_BRepApprox_TheMultiLineToolOfApprox.def_static("WhatStatus_", (Approx_Status (*)(const BRepApprox_TheMultiLineOfApprox &, const Standard_Integer, const Standard_Integer)) &BRepApprox_TheMultiLineToolOfApprox::WhatStatus, "None", py::arg("ML"), py::arg("I1"), py::arg("I2"));
cls_BRepApprox_TheMultiLineToolOfApprox.def_static("Dump_", (void (*)(const BRepApprox_TheMultiLineOfApprox &)) &BRepApprox_TheMultiLineToolOfApprox::Dump, "Dump of the current multi-line.", py::arg("ML"));

// Enums

}