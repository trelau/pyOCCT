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
#include <GeomAbs_Shape.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Curve.hxx>
#include <Standard_TypeDef.hxx>
#include <GeomLProp_CurveTool.hxx>
#include <GeomLProp_SurfaceTool.hxx>
#include <GeomLProp_CLProps.hxx>
#include <GeomLProp_SLProps.hxx>
#include <GeomLProp.hxx>

void bind_GeomLProp(py::module &mod){

py::class_<GeomLProp> cls_GeomLProp(mod, "GeomLProp", "These global functions compute the degree of continuity of a 3D curve built by concatenation of two other curves (or portions of curves) at their junction point.");

// Constructors

// Fields

// Methods
// cls_GeomLProp.def_static("operator new_", (void * (*)(size_t)) &GeomLProp::operator new, "None", py::arg("theSize"));
// cls_GeomLProp.def_static("operator delete_", (void (*)(void *)) &GeomLProp::operator delete, "None", py::arg("theAddress"));
// cls_GeomLProp.def_static("operator new[]_", (void * (*)(size_t)) &GeomLProp::operator new[], "None", py::arg("theSize"));
// cls_GeomLProp.def_static("operator delete[]_", (void (*)(void *)) &GeomLProp::operator delete[], "None", py::arg("theAddress"));
// cls_GeomLProp.def_static("operator new_", (void * (*)(size_t, void *)) &GeomLProp::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomLProp.def_static("operator delete_", (void (*)(void *, void *)) &GeomLProp::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomLProp.def_static("Continuity_", (GeomAbs_Shape (*)(const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom_Curve> &, const Standard_Real, const Standard_Real, const Standard_Boolean, const Standard_Boolean, const Standard_Real, const Standard_Real)) &GeomLProp::Continuity, "Computes the regularity at the junction between C1 and C2. The booleans r1 and r2 are true if the curves must be taken reversed. The point u1 on C1 and the point u2 on C2 must be confused. tl and ta are the linear and angular tolerance used two compare the derivative.", py::arg("C1"), py::arg("C2"), py::arg("u1"), py::arg("u2"), py::arg("r1"), py::arg("r2"), py::arg("tl"), py::arg("ta"));
cls_GeomLProp.def_static("Continuity_", (GeomAbs_Shape (*)(const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom_Curve> &, const Standard_Real, const Standard_Real, const Standard_Boolean, const Standard_Boolean)) &GeomLProp::Continuity, "The same as preciding but using the standard tolerances from package Precision.", py::arg("C1"), py::arg("C2"), py::arg("u1"), py::arg("u2"), py::arg("r1"), py::arg("r2"));

// Enums

}