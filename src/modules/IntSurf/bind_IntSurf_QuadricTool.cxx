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
#include <IntSurf_Quadric.hxx>
#include <gp_Vec.hxx>
#include <IntSurf_QuadricTool.hxx>

void bind_IntSurf_QuadricTool(py::module &mod){

py::class_<IntSurf_QuadricTool, std::unique_ptr<IntSurf_QuadricTool>> cls_IntSurf_QuadricTool(mod, "IntSurf_QuadricTool", "This class provides a tool on a quadric that can be used to instantiates the Walking algorithmes (see package IntWalk) with a Quadric from IntSurf as implicit surface.");

// Constructors

// Fields

// Methods
// cls_IntSurf_QuadricTool.def_static("operator new_", (void * (*)(size_t)) &IntSurf_QuadricTool::operator new, "None", py::arg("theSize"));
// cls_IntSurf_QuadricTool.def_static("operator delete_", (void (*)(void *)) &IntSurf_QuadricTool::operator delete, "None", py::arg("theAddress"));
// cls_IntSurf_QuadricTool.def_static("operator new[]_", (void * (*)(size_t)) &IntSurf_QuadricTool::operator new[], "None", py::arg("theSize"));
// cls_IntSurf_QuadricTool.def_static("operator delete[]_", (void (*)(void *)) &IntSurf_QuadricTool::operator delete[], "None", py::arg("theAddress"));
// cls_IntSurf_QuadricTool.def_static("operator new_", (void * (*)(size_t, void *)) &IntSurf_QuadricTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntSurf_QuadricTool.def_static("operator delete_", (void (*)(void *, void *)) &IntSurf_QuadricTool::operator delete, "None", py::arg(""), py::arg(""));
cls_IntSurf_QuadricTool.def_static("Value_", (Standard_Real (*)(const IntSurf_Quadric &, const Standard_Real, const Standard_Real, const Standard_Real)) &IntSurf_QuadricTool::Value, "Returns the value of the function.", py::arg("Quad"), py::arg("X"), py::arg("Y"), py::arg("Z"));
cls_IntSurf_QuadricTool.def_static("Gradient_", (void (*)(const IntSurf_Quadric &, const Standard_Real, const Standard_Real, const Standard_Real, gp_Vec &)) &IntSurf_QuadricTool::Gradient, "Returns the gradient of the function.", py::arg("Quad"), py::arg("X"), py::arg("Y"), py::arg("Z"), py::arg("V"));
cls_IntSurf_QuadricTool.def_static("ValueAndGradient_", [](const IntSurf_Quadric & Quad, const Standard_Real X, const Standard_Real Y, const Standard_Real Z, Standard_Real & Val, gp_Vec & Grad){ IntSurf_QuadricTool::ValueAndGradient(Quad, X, Y, Z, Val, Grad); return Val; }, "Returns the value and the gradient.", py::arg("Quad"), py::arg("X"), py::arg("Y"), py::arg("Z"), py::arg("Val"), py::arg("Grad"));
cls_IntSurf_QuadricTool.def_static("Tolerance_", (Standard_Real (*)(const IntSurf_Quadric &)) &IntSurf_QuadricTool::Tolerance, "returns the tolerance of the zero of the implicit function", py::arg("Quad"));

// Enums

}