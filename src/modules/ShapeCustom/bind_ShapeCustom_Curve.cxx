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
#include <Geom_Curve.hxx>
#include <Standard_TypeDef.hxx>
#include <ShapeCustom_Curve.hxx>

void bind_ShapeCustom_Curve(py::module &mod){

py::class_<ShapeCustom_Curve, std::unique_ptr<ShapeCustom_Curve, Deleter<ShapeCustom_Curve>>> cls_ShapeCustom_Curve(mod, "ShapeCustom_Curve", "Converts BSpline curve to periodic");

// Constructors
cls_ShapeCustom_Curve.def(py::init<>());
cls_ShapeCustom_Curve.def(py::init<const opencascade::handle<Geom_Curve> &>(), py::arg("C"));

// Fields

// Methods
// cls_ShapeCustom_Curve.def_static("operator new_", (void * (*)(size_t)) &ShapeCustom_Curve::operator new, "None", py::arg("theSize"));
// cls_ShapeCustom_Curve.def_static("operator delete_", (void (*)(void *)) &ShapeCustom_Curve::operator delete, "None", py::arg("theAddress"));
// cls_ShapeCustom_Curve.def_static("operator new[]_", (void * (*)(size_t)) &ShapeCustom_Curve::operator new[], "None", py::arg("theSize"));
// cls_ShapeCustom_Curve.def_static("operator delete[]_", (void (*)(void *)) &ShapeCustom_Curve::operator delete[], "None", py::arg("theAddress"));
// cls_ShapeCustom_Curve.def_static("operator new_", (void * (*)(size_t, void *)) &ShapeCustom_Curve::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_ShapeCustom_Curve.def_static("operator delete_", (void (*)(void *, void *)) &ShapeCustom_Curve::operator delete, "None", py::arg(""), py::arg(""));
cls_ShapeCustom_Curve.def("Init", (void (ShapeCustom_Curve::*)(const opencascade::handle<Geom_Curve> &)) &ShapeCustom_Curve::Init, "None", py::arg("C"));
cls_ShapeCustom_Curve.def("ConvertToPeriodic", [](ShapeCustom_Curve &self, const Standard_Boolean a0) -> opencascade::handle<Geom_Curve> { return self.ConvertToPeriodic(a0); });
cls_ShapeCustom_Curve.def("ConvertToPeriodic", (opencascade::handle<Geom_Curve> (ShapeCustom_Curve::*)(const Standard_Boolean, const Standard_Real)) &ShapeCustom_Curve::ConvertToPeriodic, "Tries to convert the Curve to the Periodic form Returns the resulting curve Works only if the Curve is BSpline and is closed with Precision::Confusion() Else, or in case of failure, returns a Null Handle", py::arg("substitute"), py::arg("preci"));

// Enums

}