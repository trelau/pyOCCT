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
#include <IntSurf_Quadric.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>
#include <gp_Vec2d.hxx>
#include <IntSurf_PntOn2S.hxx>
#include <math_Vector.hxx>
#include <gp_Pnt2d.hxx>
#include <GeomInt_TheZerImpFuncOfTheImpPrmSvSurfacesOfWLApprox.hxx>
#include <GeomInt_TheImpPrmSvSurfacesOfWLApprox.hxx>

void bind_GeomInt_TheImpPrmSvSurfacesOfWLApprox(py::module &mod){

py::class_<GeomInt_TheImpPrmSvSurfacesOfWLApprox, std::unique_ptr<GeomInt_TheImpPrmSvSurfacesOfWLApprox>, ApproxInt_SvSurfaces> cls_GeomInt_TheImpPrmSvSurfacesOfWLApprox(mod, "GeomInt_TheImpPrmSvSurfacesOfWLApprox", "None");

// Constructors
cls_GeomInt_TheImpPrmSvSurfacesOfWLApprox.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const IntSurf_Quadric &>(), py::arg("Surf1"), py::arg("Surf2"));
cls_GeomInt_TheImpPrmSvSurfacesOfWLApprox.def(py::init<const IntSurf_Quadric &, const opencascade::handle<Adaptor3d_HSurface> &>(), py::arg("Surf1"), py::arg("Surf2"));

// Fields

// Methods
// cls_GeomInt_TheImpPrmSvSurfacesOfWLApprox.def_static("operator new_", (void * (*)(size_t)) &GeomInt_TheImpPrmSvSurfacesOfWLApprox::operator new, "None", py::arg("theSize"));
// cls_GeomInt_TheImpPrmSvSurfacesOfWLApprox.def_static("operator delete_", (void (*)(void *)) &GeomInt_TheImpPrmSvSurfacesOfWLApprox::operator delete, "None", py::arg("theAddress"));
// cls_GeomInt_TheImpPrmSvSurfacesOfWLApprox.def_static("operator new[]_", (void * (*)(size_t)) &GeomInt_TheImpPrmSvSurfacesOfWLApprox::operator new[], "None", py::arg("theSize"));
// cls_GeomInt_TheImpPrmSvSurfacesOfWLApprox.def_static("operator delete[]_", (void (*)(void *)) &GeomInt_TheImpPrmSvSurfacesOfWLApprox::operator delete[], "None", py::arg("theAddress"));
// cls_GeomInt_TheImpPrmSvSurfacesOfWLApprox.def_static("operator new_", (void * (*)(size_t, void *)) &GeomInt_TheImpPrmSvSurfacesOfWLApprox::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomInt_TheImpPrmSvSurfacesOfWLApprox.def_static("operator delete_", (void (*)(void *, void *)) &GeomInt_TheImpPrmSvSurfacesOfWLApprox::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomInt_TheImpPrmSvSurfacesOfWLApprox.def("Compute", [](GeomInt_TheImpPrmSvSurfacesOfWLApprox &self, Standard_Real & u1, Standard_Real & v1, Standard_Real & u2, Standard_Real & v2, gp_Pnt & Pt, gp_Vec & Tg, gp_Vec2d & Tguv1, gp_Vec2d & Tguv2){ Standard_Boolean rv = self.Compute(u1, v1, u2, v2, Pt, Tg, Tguv1, Tguv2); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(rv, u1, v1, u2, v2); }, "returns True if Tg,Tguv1 Tguv2 can be computed.", py::arg("u1"), py::arg("v1"), py::arg("u2"), py::arg("v2"), py::arg("Pt"), py::arg("Tg"), py::arg("Tguv1"), py::arg("Tguv2"));
cls_GeomInt_TheImpPrmSvSurfacesOfWLApprox.def("Pnt", (void (GeomInt_TheImpPrmSvSurfacesOfWLApprox::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, gp_Pnt &)) &GeomInt_TheImpPrmSvSurfacesOfWLApprox::Pnt, "None", py::arg("u1"), py::arg("v1"), py::arg("u2"), py::arg("v2"), py::arg("P"));
cls_GeomInt_TheImpPrmSvSurfacesOfWLApprox.def("SeekPoint", (Standard_Boolean (GeomInt_TheImpPrmSvSurfacesOfWLApprox::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, IntSurf_PntOn2S &)) &GeomInt_TheImpPrmSvSurfacesOfWLApprox::SeekPoint, "None", py::arg("u1"), py::arg("v1"), py::arg("u2"), py::arg("v2"), py::arg("Point"));
cls_GeomInt_TheImpPrmSvSurfacesOfWLApprox.def("Tangency", (Standard_Boolean (GeomInt_TheImpPrmSvSurfacesOfWLApprox::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, gp_Vec &)) &GeomInt_TheImpPrmSvSurfacesOfWLApprox::Tangency, "None", py::arg("u1"), py::arg("v1"), py::arg("u2"), py::arg("v2"), py::arg("Tg"));
cls_GeomInt_TheImpPrmSvSurfacesOfWLApprox.def("TangencyOnSurf1", (Standard_Boolean (GeomInt_TheImpPrmSvSurfacesOfWLApprox::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, gp_Vec2d &)) &GeomInt_TheImpPrmSvSurfacesOfWLApprox::TangencyOnSurf1, "None", py::arg("u1"), py::arg("v1"), py::arg("u2"), py::arg("v2"), py::arg("Tg"));
cls_GeomInt_TheImpPrmSvSurfacesOfWLApprox.def("TangencyOnSurf2", (Standard_Boolean (GeomInt_TheImpPrmSvSurfacesOfWLApprox::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, gp_Vec2d &)) &GeomInt_TheImpPrmSvSurfacesOfWLApprox::TangencyOnSurf2, "None", py::arg("u1"), py::arg("v1"), py::arg("u2"), py::arg("v2"), py::arg("Tg"));
// cls_GeomInt_TheImpPrmSvSurfacesOfWLApprox.def("FillInitialVectorOfSolution", [](GeomInt_TheImpPrmSvSurfacesOfWLApprox &self, const Standard_Real u1, const Standard_Real v1, const Standard_Real u2, const Standard_Real v2, const Standard_Real binfu, const Standard_Real bsupu, const Standard_Real binfv, const Standard_Real bsupv, math_Vector & X, Standard_Real & TranslationU, Standard_Real & TranslationV){ Standard_Boolean rv = self.FillInitialVectorOfSolution(u1, v1, u2, v2, binfu, bsupu, binfv, bsupv, X, TranslationU, TranslationV); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, TranslationU, TranslationV); }, "None", py::arg("u1"), py::arg("v1"), py::arg("u2"), py::arg("v2"), py::arg("binfu"), py::arg("bsupu"), py::arg("binfv"), py::arg("bsupv"), py::arg("X"), py::arg("TranslationU"), py::arg("TranslationV"));

// Enums

}