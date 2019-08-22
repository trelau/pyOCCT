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
#include <IntSurf_Quadric.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>
#include <gp_Vec2d.hxx>
#include <IntSurf_PntOn2S.hxx>
#include <math_Vector.hxx>
#include <gp_Pnt2d.hxx>
#include <BRepApprox_TheZerImpFuncOfTheImpPrmSvSurfacesOfApprox.hxx>
#include <BRepApprox_TheImpPrmSvSurfacesOfApprox.hxx>

void bind_BRepApprox_TheImpPrmSvSurfacesOfApprox(py::module &mod){

py::class_<BRepApprox_TheImpPrmSvSurfacesOfApprox, ApproxInt_SvSurfaces> cls_BRepApprox_TheImpPrmSvSurfacesOfApprox(mod, "BRepApprox_TheImpPrmSvSurfacesOfApprox", "None");

// Constructors
cls_BRepApprox_TheImpPrmSvSurfacesOfApprox.def(py::init<const BRepAdaptor_Surface &, const IntSurf_Quadric &>(), py::arg("Surf1"), py::arg("Surf2"));
cls_BRepApprox_TheImpPrmSvSurfacesOfApprox.def(py::init<const IntSurf_Quadric &, const BRepAdaptor_Surface &>(), py::arg("Surf1"), py::arg("Surf2"));

// Fields

// Methods
// cls_BRepApprox_TheImpPrmSvSurfacesOfApprox.def_static("operator new_", (void * (*)(size_t)) &BRepApprox_TheImpPrmSvSurfacesOfApprox::operator new, "None", py::arg("theSize"));
// cls_BRepApprox_TheImpPrmSvSurfacesOfApprox.def_static("operator delete_", (void (*)(void *)) &BRepApprox_TheImpPrmSvSurfacesOfApprox::operator delete, "None", py::arg("theAddress"));
// cls_BRepApprox_TheImpPrmSvSurfacesOfApprox.def_static("operator new[]_", (void * (*)(size_t)) &BRepApprox_TheImpPrmSvSurfacesOfApprox::operator new[], "None", py::arg("theSize"));
// cls_BRepApprox_TheImpPrmSvSurfacesOfApprox.def_static("operator delete[]_", (void (*)(void *)) &BRepApprox_TheImpPrmSvSurfacesOfApprox::operator delete[], "None", py::arg("theAddress"));
// cls_BRepApprox_TheImpPrmSvSurfacesOfApprox.def_static("operator new_", (void * (*)(size_t, void *)) &BRepApprox_TheImpPrmSvSurfacesOfApprox::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepApprox_TheImpPrmSvSurfacesOfApprox.def_static("operator delete_", (void (*)(void *, void *)) &BRepApprox_TheImpPrmSvSurfacesOfApprox::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepApprox_TheImpPrmSvSurfacesOfApprox.def("Compute", [](BRepApprox_TheImpPrmSvSurfacesOfApprox &self, Standard_Real & u1, Standard_Real & v1, Standard_Real & u2, Standard_Real & v2, gp_Pnt & Pt, gp_Vec & Tg, gp_Vec2d & Tguv1, gp_Vec2d & Tguv2){ Standard_Boolean rv = self.Compute(u1, v1, u2, v2, Pt, Tg, Tguv1, Tguv2); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(rv, u1, v1, u2, v2); }, "returns True if Tg,Tguv1 Tguv2 can be computed.", py::arg("u1"), py::arg("v1"), py::arg("u2"), py::arg("v2"), py::arg("Pt"), py::arg("Tg"), py::arg("Tguv1"), py::arg("Tguv2"));
cls_BRepApprox_TheImpPrmSvSurfacesOfApprox.def("Pnt", (void (BRepApprox_TheImpPrmSvSurfacesOfApprox::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, gp_Pnt &)) &BRepApprox_TheImpPrmSvSurfacesOfApprox::Pnt, "None", py::arg("u1"), py::arg("v1"), py::arg("u2"), py::arg("v2"), py::arg("P"));
cls_BRepApprox_TheImpPrmSvSurfacesOfApprox.def("SeekPoint", (Standard_Boolean (BRepApprox_TheImpPrmSvSurfacesOfApprox::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, IntSurf_PntOn2S &)) &BRepApprox_TheImpPrmSvSurfacesOfApprox::SeekPoint, "None", py::arg("u1"), py::arg("v1"), py::arg("u2"), py::arg("v2"), py::arg("Point"));
cls_BRepApprox_TheImpPrmSvSurfacesOfApprox.def("Tangency", (Standard_Boolean (BRepApprox_TheImpPrmSvSurfacesOfApprox::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, gp_Vec &)) &BRepApprox_TheImpPrmSvSurfacesOfApprox::Tangency, "None", py::arg("u1"), py::arg("v1"), py::arg("u2"), py::arg("v2"), py::arg("Tg"));
cls_BRepApprox_TheImpPrmSvSurfacesOfApprox.def("TangencyOnSurf1", (Standard_Boolean (BRepApprox_TheImpPrmSvSurfacesOfApprox::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, gp_Vec2d &)) &BRepApprox_TheImpPrmSvSurfacesOfApprox::TangencyOnSurf1, "None", py::arg("u1"), py::arg("v1"), py::arg("u2"), py::arg("v2"), py::arg("Tg"));
cls_BRepApprox_TheImpPrmSvSurfacesOfApprox.def("TangencyOnSurf2", (Standard_Boolean (BRepApprox_TheImpPrmSvSurfacesOfApprox::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, gp_Vec2d &)) &BRepApprox_TheImpPrmSvSurfacesOfApprox::TangencyOnSurf2, "None", py::arg("u1"), py::arg("v1"), py::arg("u2"), py::arg("v2"), py::arg("Tg"));
// cls_BRepApprox_TheImpPrmSvSurfacesOfApprox.def("FillInitialVectorOfSolution", [](BRepApprox_TheImpPrmSvSurfacesOfApprox &self, const Standard_Real u1, const Standard_Real v1, const Standard_Real u2, const Standard_Real v2, const Standard_Real binfu, const Standard_Real bsupu, const Standard_Real binfv, const Standard_Real bsupv, math_Vector & X, Standard_Real & TranslationU, Standard_Real & TranslationV){ Standard_Boolean rv = self.FillInitialVectorOfSolution(u1, v1, u2, v2, binfu, bsupu, binfv, bsupv, X, TranslationU, TranslationV); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, TranslationU, TranslationV); }, "None", py::arg("u1"), py::arg("v1"), py::arg("u2"), py::arg("v2"), py::arg("binfu"), py::arg("bsupu"), py::arg("binfv"), py::arg("bsupv"), py::arg("X"), py::arg("TranslationU"), py::arg("TranslationV"));

// Enums

}