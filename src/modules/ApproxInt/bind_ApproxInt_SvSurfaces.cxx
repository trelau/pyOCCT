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
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>
#include <gp_Vec2d.hxx>
#include <IntSurf_PntOn2S.hxx>
#include <ApproxInt_SvSurfaces.hxx>

void bind_ApproxInt_SvSurfaces(py::module &mod){

py::class_<ApproxInt_SvSurfaces, std::unique_ptr<ApproxInt_SvSurfaces, Deleter<ApproxInt_SvSurfaces>>> cls_ApproxInt_SvSurfaces(mod, "ApproxInt_SvSurfaces", "None");

// Fields

// Methods
// cls_ApproxInt_SvSurfaces.def_static("operator new_", (void * (*)(size_t)) &ApproxInt_SvSurfaces::operator new, "None", py::arg("theSize"));
// cls_ApproxInt_SvSurfaces.def_static("operator delete_", (void (*)(void *)) &ApproxInt_SvSurfaces::operator delete, "None", py::arg("theAddress"));
// cls_ApproxInt_SvSurfaces.def_static("operator new[]_", (void * (*)(size_t)) &ApproxInt_SvSurfaces::operator new[], "None", py::arg("theSize"));
// cls_ApproxInt_SvSurfaces.def_static("operator delete[]_", (void (*)(void *)) &ApproxInt_SvSurfaces::operator delete[], "None", py::arg("theAddress"));
// cls_ApproxInt_SvSurfaces.def_static("operator new_", (void * (*)(size_t, void *)) &ApproxInt_SvSurfaces::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_ApproxInt_SvSurfaces.def_static("operator delete_", (void (*)(void *, void *)) &ApproxInt_SvSurfaces::operator delete, "None", py::arg(""), py::arg(""));
cls_ApproxInt_SvSurfaces.def("Compute", [](ApproxInt_SvSurfaces &self, Standard_Real & u1, Standard_Real & v1, Standard_Real & u2, Standard_Real & v2, gp_Pnt & Pt, gp_Vec & Tg, gp_Vec2d & Tguv1, gp_Vec2d & Tguv2){ Standard_Boolean rv = self.Compute(u1, v1, u2, v2, Pt, Tg, Tguv1, Tguv2); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(rv, u1, v1, u2, v2); }, "returns True if Tg,Tguv1 Tguv2 can be computed.", py::arg("u1"), py::arg("v1"), py::arg("u2"), py::arg("v2"), py::arg("Pt"), py::arg("Tg"), py::arg("Tguv1"), py::arg("Tguv2"));
cls_ApproxInt_SvSurfaces.def("Pnt", (void (ApproxInt_SvSurfaces::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, gp_Pnt &)) &ApproxInt_SvSurfaces::Pnt, "None", py::arg("u1"), py::arg("v1"), py::arg("u2"), py::arg("v2"), py::arg("P"));
cls_ApproxInt_SvSurfaces.def("SeekPoint", (Standard_Boolean (ApproxInt_SvSurfaces::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, IntSurf_PntOn2S &)) &ApproxInt_SvSurfaces::SeekPoint, "computes point on curve and parameters on the surfaces", py::arg("u1"), py::arg("v1"), py::arg("u2"), py::arg("v2"), py::arg("Point"));
cls_ApproxInt_SvSurfaces.def("Tangency", (Standard_Boolean (ApproxInt_SvSurfaces::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, gp_Vec &)) &ApproxInt_SvSurfaces::Tangency, "None", py::arg("u1"), py::arg("v1"), py::arg("u2"), py::arg("v2"), py::arg("Tg"));
cls_ApproxInt_SvSurfaces.def("TangencyOnSurf1", (Standard_Boolean (ApproxInt_SvSurfaces::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, gp_Vec2d &)) &ApproxInt_SvSurfaces::TangencyOnSurf1, "None", py::arg("u1"), py::arg("v1"), py::arg("u2"), py::arg("v2"), py::arg("Tg"));
cls_ApproxInt_SvSurfaces.def("TangencyOnSurf2", (Standard_Boolean (ApproxInt_SvSurfaces::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, gp_Vec2d &)) &ApproxInt_SvSurfaces::TangencyOnSurf2, "None", py::arg("u1"), py::arg("v1"), py::arg("u2"), py::arg("v2"), py::arg("Tg"));

// Enums

}