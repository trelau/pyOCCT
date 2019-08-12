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
#include <BRepAdaptor_Curve.hxx>
#include <Standard_TypeDef.hxx>
#include <BRepLProp_CurveTool.hxx>
#include <BRepLProp_SurfaceTool.hxx>
#include <BRepLProp_CLProps.hxx>
#include <BRepLProp_SLProps.hxx>
#include <BRepLProp.hxx>

void bind_BRepLProp(py::module &mod){

py::class_<BRepLProp, std::unique_ptr<BRepLProp, Deleter<BRepLProp>>> cls_BRepLProp(mod, "BRepLProp", "These global functions compute the degree of continuity of a curve built by concatenation of two edges at their junction point.");

// Constructors

// Fields

// Methods
// cls_BRepLProp.def_static("operator new_", (void * (*)(size_t)) &BRepLProp::operator new, "None", py::arg("theSize"));
// cls_BRepLProp.def_static("operator delete_", (void (*)(void *)) &BRepLProp::operator delete, "None", py::arg("theAddress"));
// cls_BRepLProp.def_static("operator new[]_", (void * (*)(size_t)) &BRepLProp::operator new[], "None", py::arg("theSize"));
// cls_BRepLProp.def_static("operator delete[]_", (void (*)(void *)) &BRepLProp::operator delete[], "None", py::arg("theAddress"));
// cls_BRepLProp.def_static("operator new_", (void * (*)(size_t, void *)) &BRepLProp::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepLProp.def_static("operator delete_", (void (*)(void *, void *)) &BRepLProp::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepLProp.def_static("Continuity_", (GeomAbs_Shape (*)(const BRepAdaptor_Curve &, const BRepAdaptor_Curve &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &BRepLProp::Continuity, "Computes the regularity at the junction between C1 and C2. The point u1 on C1 and the point u2 on C2 must be confused. tl and ta are the linear and angular tolerance used two compare the derivative.", py::arg("C1"), py::arg("C2"), py::arg("u1"), py::arg("u2"), py::arg("tl"), py::arg("ta"));
cls_BRepLProp.def_static("Continuity_", (GeomAbs_Shape (*)(const BRepAdaptor_Curve &, const BRepAdaptor_Curve &, const Standard_Real, const Standard_Real)) &BRepLProp::Continuity, "The same as preciding but using the standard tolerances from package Precision.", py::arg("C1"), py::arg("C2"), py::arg("u1"), py::arg("u2"));

// Enums

}