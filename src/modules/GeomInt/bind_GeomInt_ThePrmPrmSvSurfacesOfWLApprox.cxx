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
#include <Standard_Handle.hxx>
#include <Adaptor3d_HSurface.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>
#include <gp_Vec2d.hxx>
#include <IntSurf_PntOn2S.hxx>
#include <gp_Pnt2d.hxx>
#include <GeomInt_TheInt2SOfThePrmPrmSvSurfacesOfWLApprox.hxx>
#include <GeomInt_ThePrmPrmSvSurfacesOfWLApprox.hxx>

void bind_GeomInt_ThePrmPrmSvSurfacesOfWLApprox(py::module &mod){

py::class_<GeomInt_ThePrmPrmSvSurfacesOfWLApprox, std::unique_ptr<GeomInt_ThePrmPrmSvSurfacesOfWLApprox>, ApproxInt_SvSurfaces> cls_GeomInt_ThePrmPrmSvSurfacesOfWLApprox(mod, "GeomInt_ThePrmPrmSvSurfacesOfWLApprox", "None");

// Constructors
cls_GeomInt_ThePrmPrmSvSurfacesOfWLApprox.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &>(), py::arg("Surf1"), py::arg("Surf2"));

// Fields

// Methods
// cls_GeomInt_ThePrmPrmSvSurfacesOfWLApprox.def_static("operator new_", (void * (*)(size_t)) &GeomInt_ThePrmPrmSvSurfacesOfWLApprox::operator new, "None", py::arg("theSize"));
// cls_GeomInt_ThePrmPrmSvSurfacesOfWLApprox.def_static("operator delete_", (void (*)(void *)) &GeomInt_ThePrmPrmSvSurfacesOfWLApprox::operator delete, "None", py::arg("theAddress"));
// cls_GeomInt_ThePrmPrmSvSurfacesOfWLApprox.def_static("operator new[]_", (void * (*)(size_t)) &GeomInt_ThePrmPrmSvSurfacesOfWLApprox::operator new[], "None", py::arg("theSize"));
// cls_GeomInt_ThePrmPrmSvSurfacesOfWLApprox.def_static("operator delete[]_", (void (*)(void *)) &GeomInt_ThePrmPrmSvSurfacesOfWLApprox::operator delete[], "None", py::arg("theAddress"));
// cls_GeomInt_ThePrmPrmSvSurfacesOfWLApprox.def_static("operator new_", (void * (*)(size_t, void *)) &GeomInt_ThePrmPrmSvSurfacesOfWLApprox::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomInt_ThePrmPrmSvSurfacesOfWLApprox.def_static("operator delete_", (void (*)(void *, void *)) &GeomInt_ThePrmPrmSvSurfacesOfWLApprox::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomInt_ThePrmPrmSvSurfacesOfWLApprox.def("Compute", [](GeomInt_ThePrmPrmSvSurfacesOfWLApprox &self, Standard_Real & u1, Standard_Real & v1, Standard_Real & u2, Standard_Real & v2, gp_Pnt & Pt, gp_Vec & Tg, gp_Vec2d & Tguv1, gp_Vec2d & Tguv2){ Standard_Boolean rv = self.Compute(u1, v1, u2, v2, Pt, Tg, Tguv1, Tguv2); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(rv, u1, v1, u2, v2); }, "returns True if Tg,Tguv1 Tguv2 can be computed.", py::arg("u1"), py::arg("v1"), py::arg("u2"), py::arg("v2"), py::arg("Pt"), py::arg("Tg"), py::arg("Tguv1"), py::arg("Tguv2"));
cls_GeomInt_ThePrmPrmSvSurfacesOfWLApprox.def("Pnt", (void (GeomInt_ThePrmPrmSvSurfacesOfWLApprox::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, gp_Pnt &)) &GeomInt_ThePrmPrmSvSurfacesOfWLApprox::Pnt, "None", py::arg("u1"), py::arg("v1"), py::arg("u2"), py::arg("v2"), py::arg("P"));
cls_GeomInt_ThePrmPrmSvSurfacesOfWLApprox.def("SeekPoint", (Standard_Boolean (GeomInt_ThePrmPrmSvSurfacesOfWLApprox::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, IntSurf_PntOn2S &)) &GeomInt_ThePrmPrmSvSurfacesOfWLApprox::SeekPoint, "None", py::arg("u1"), py::arg("v1"), py::arg("u2"), py::arg("v2"), py::arg("Point"));
cls_GeomInt_ThePrmPrmSvSurfacesOfWLApprox.def("Tangency", (Standard_Boolean (GeomInt_ThePrmPrmSvSurfacesOfWLApprox::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, gp_Vec &)) &GeomInt_ThePrmPrmSvSurfacesOfWLApprox::Tangency, "None", py::arg("u1"), py::arg("v1"), py::arg("u2"), py::arg("v2"), py::arg("Tg"));
cls_GeomInt_ThePrmPrmSvSurfacesOfWLApprox.def("TangencyOnSurf1", (Standard_Boolean (GeomInt_ThePrmPrmSvSurfacesOfWLApprox::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, gp_Vec2d &)) &GeomInt_ThePrmPrmSvSurfacesOfWLApprox::TangencyOnSurf1, "None", py::arg("u1"), py::arg("v1"), py::arg("u2"), py::arg("v2"), py::arg("Tg"));
cls_GeomInt_ThePrmPrmSvSurfacesOfWLApprox.def("TangencyOnSurf2", (Standard_Boolean (GeomInt_ThePrmPrmSvSurfacesOfWLApprox::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, gp_Vec2d &)) &GeomInt_ThePrmPrmSvSurfacesOfWLApprox::TangencyOnSurf2, "None", py::arg("u1"), py::arg("v1"), py::arg("u2"), py::arg("v2"), py::arg("Tg"));

// Enums

}