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
#include <Geom_Surface.hxx>
#include <Standard_TypeDef.hxx>
#include <ShapeCustom_Surface.hxx>

void bind_ShapeCustom_Surface(py::module &mod){

py::class_<ShapeCustom_Surface, std::unique_ptr<ShapeCustom_Surface>> cls_ShapeCustom_Surface(mod, "ShapeCustom_Surface", "Converts a surface to the analitical form with given precision. Conversion is done only the surface is bspline of bezier and this can be approximed by some analytical surface with that precision.");

// Constructors
cls_ShapeCustom_Surface.def(py::init<>());
cls_ShapeCustom_Surface.def(py::init<const opencascade::handle<Geom_Surface> &>(), py::arg("S"));

// Fields

// Methods
// cls_ShapeCustom_Surface.def_static("operator new_", (void * (*)(size_t)) &ShapeCustom_Surface::operator new, "None", py::arg("theSize"));
// cls_ShapeCustom_Surface.def_static("operator delete_", (void (*)(void *)) &ShapeCustom_Surface::operator delete, "None", py::arg("theAddress"));
// cls_ShapeCustom_Surface.def_static("operator new[]_", (void * (*)(size_t)) &ShapeCustom_Surface::operator new[], "None", py::arg("theSize"));
// cls_ShapeCustom_Surface.def_static("operator delete[]_", (void (*)(void *)) &ShapeCustom_Surface::operator delete[], "None", py::arg("theAddress"));
// cls_ShapeCustom_Surface.def_static("operator new_", (void * (*)(size_t, void *)) &ShapeCustom_Surface::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_ShapeCustom_Surface.def_static("operator delete_", (void (*)(void *, void *)) &ShapeCustom_Surface::operator delete, "None", py::arg(""), py::arg(""));
cls_ShapeCustom_Surface.def("Init", (void (ShapeCustom_Surface::*)(const opencascade::handle<Geom_Surface> &)) &ShapeCustom_Surface::Init, "None", py::arg("S"));
cls_ShapeCustom_Surface.def("Gap", (Standard_Real (ShapeCustom_Surface::*)() const) &ShapeCustom_Surface::Gap, "Returns maximal deviation of converted surface from the original one computed by last call to ConvertToAnalytical");
cls_ShapeCustom_Surface.def("ConvertToAnalytical", (opencascade::handle<Geom_Surface> (ShapeCustom_Surface::*)(const Standard_Real, const Standard_Boolean)) &ShapeCustom_Surface::ConvertToAnalytical, "Tries to convert the Surface to an Analytic form Returns the result Works only if the Surface is BSpline or Bezier. Else, or in case of failure, returns a Null Handle", py::arg("tol"), py::arg("substitute"));
cls_ShapeCustom_Surface.def("ConvertToPeriodic", [](ShapeCustom_Surface &self, const Standard_Boolean a0) -> opencascade::handle<Geom_Surface> { return self.ConvertToPeriodic(a0); });
cls_ShapeCustom_Surface.def("ConvertToPeriodic", (opencascade::handle<Geom_Surface> (ShapeCustom_Surface::*)(const Standard_Boolean, const Standard_Real)) &ShapeCustom_Surface::ConvertToPeriodic, "Tries to convert the Surface to the Periodic form Returns the resulting surface Works only if the Surface is BSpline and is closed with Precision::Confusion() Else, or in case of failure, returns a Null Handle", py::arg("substitute"), py::arg("preci"));

// Enums

}