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
#include <ApproxInt_SvSurfaces.hxx>
#include <Standard.hxx>
#include <BRepAdaptor_Surface.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>
#include <gp_Vec2d.hxx>
#include <IntSurf_PntOn2S.hxx>
#include <gp_Pnt2d.hxx>
#include <BRepApprox_TheInt2SOfThePrmPrmSvSurfacesOfApprox.hxx>
#include <BRepApprox_ThePrmPrmSvSurfacesOfApprox.hxx>

void bind_BRepApprox_ThePrmPrmSvSurfacesOfApprox(py::module &mod){

py::class_<BRepApprox_ThePrmPrmSvSurfacesOfApprox, ApproxInt_SvSurfaces> cls_BRepApprox_ThePrmPrmSvSurfacesOfApprox(mod, "BRepApprox_ThePrmPrmSvSurfacesOfApprox", "None");

// Constructors
cls_BRepApprox_ThePrmPrmSvSurfacesOfApprox.def(py::init<const BRepAdaptor_Surface &, const BRepAdaptor_Surface &>(), py::arg("Surf1"), py::arg("Surf2"));

// Fields

// Methods
// cls_BRepApprox_ThePrmPrmSvSurfacesOfApprox.def_static("operator new_", (void * (*)(size_t)) &BRepApprox_ThePrmPrmSvSurfacesOfApprox::operator new, "None", py::arg("theSize"));
// cls_BRepApprox_ThePrmPrmSvSurfacesOfApprox.def_static("operator delete_", (void (*)(void *)) &BRepApprox_ThePrmPrmSvSurfacesOfApprox::operator delete, "None", py::arg("theAddress"));
// cls_BRepApprox_ThePrmPrmSvSurfacesOfApprox.def_static("operator new[]_", (void * (*)(size_t)) &BRepApprox_ThePrmPrmSvSurfacesOfApprox::operator new[], "None", py::arg("theSize"));
// cls_BRepApprox_ThePrmPrmSvSurfacesOfApprox.def_static("operator delete[]_", (void (*)(void *)) &BRepApprox_ThePrmPrmSvSurfacesOfApprox::operator delete[], "None", py::arg("theAddress"));
// cls_BRepApprox_ThePrmPrmSvSurfacesOfApprox.def_static("operator new_", (void * (*)(size_t, void *)) &BRepApprox_ThePrmPrmSvSurfacesOfApprox::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepApprox_ThePrmPrmSvSurfacesOfApprox.def_static("operator delete_", (void (*)(void *, void *)) &BRepApprox_ThePrmPrmSvSurfacesOfApprox::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepApprox_ThePrmPrmSvSurfacesOfApprox.def("Compute", [](BRepApprox_ThePrmPrmSvSurfacesOfApprox &self, Standard_Real & u1, Standard_Real & v1, Standard_Real & u2, Standard_Real & v2, gp_Pnt & Pt, gp_Vec & Tg, gp_Vec2d & Tguv1, gp_Vec2d & Tguv2){ Standard_Boolean rv = self.Compute(u1, v1, u2, v2, Pt, Tg, Tguv1, Tguv2); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(rv, u1, v1, u2, v2); }, "returns True if Tg,Tguv1 Tguv2 can be computed.", py::arg("u1"), py::arg("v1"), py::arg("u2"), py::arg("v2"), py::arg("Pt"), py::arg("Tg"), py::arg("Tguv1"), py::arg("Tguv2"));
cls_BRepApprox_ThePrmPrmSvSurfacesOfApprox.def("Pnt", (void (BRepApprox_ThePrmPrmSvSurfacesOfApprox::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, gp_Pnt &)) &BRepApprox_ThePrmPrmSvSurfacesOfApprox::Pnt, "None", py::arg("u1"), py::arg("v1"), py::arg("u2"), py::arg("v2"), py::arg("P"));
cls_BRepApprox_ThePrmPrmSvSurfacesOfApprox.def("SeekPoint", (Standard_Boolean (BRepApprox_ThePrmPrmSvSurfacesOfApprox::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, IntSurf_PntOn2S &)) &BRepApprox_ThePrmPrmSvSurfacesOfApprox::SeekPoint, "None", py::arg("u1"), py::arg("v1"), py::arg("u2"), py::arg("v2"), py::arg("Point"));
cls_BRepApprox_ThePrmPrmSvSurfacesOfApprox.def("Tangency", (Standard_Boolean (BRepApprox_ThePrmPrmSvSurfacesOfApprox::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, gp_Vec &)) &BRepApprox_ThePrmPrmSvSurfacesOfApprox::Tangency, "None", py::arg("u1"), py::arg("v1"), py::arg("u2"), py::arg("v2"), py::arg("Tg"));
cls_BRepApprox_ThePrmPrmSvSurfacesOfApprox.def("TangencyOnSurf1", (Standard_Boolean (BRepApprox_ThePrmPrmSvSurfacesOfApprox::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, gp_Vec2d &)) &BRepApprox_ThePrmPrmSvSurfacesOfApprox::TangencyOnSurf1, "None", py::arg("u1"), py::arg("v1"), py::arg("u2"), py::arg("v2"), py::arg("Tg"));
cls_BRepApprox_ThePrmPrmSvSurfacesOfApprox.def("TangencyOnSurf2", (Standard_Boolean (BRepApprox_ThePrmPrmSvSurfacesOfApprox::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, gp_Vec2d &)) &BRepApprox_ThePrmPrmSvSurfacesOfApprox::TangencyOnSurf2, "None", py::arg("u1"), py::arg("v1"), py::arg("u2"), py::arg("v2"), py::arg("Tg"));

// Enums

}