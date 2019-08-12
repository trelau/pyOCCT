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
#include <IntRes2d_Position.hxx>
#include <gp_Vec2d.hxx>
#include <IntRes2d_Transition.hxx>
#include <Standard_TypeDef.hxx>
#include <IntRes2d_Domain.hxx>
#include <gp_Pnt2d.hxx>
#include <IntImpParGen_ImpTool.hxx>
#include <IntImpParGen.hxx>

void bind_IntImpParGen(py::module &mod){

py::class_<IntImpParGen, std::unique_ptr<IntImpParGen, Deleter<IntImpParGen>>> cls_IntImpParGen(mod, "IntImpParGen", "Gives a generic algorithm to intersect Implicit Curves and Bounded Parametric Curves.");

// Constructors

// Fields

// Methods
// cls_IntImpParGen.def_static("operator new_", (void * (*)(size_t)) &IntImpParGen::operator new, "None", py::arg("theSize"));
// cls_IntImpParGen.def_static("operator delete_", (void (*)(void *)) &IntImpParGen::operator delete, "None", py::arg("theAddress"));
// cls_IntImpParGen.def_static("operator new[]_", (void * (*)(size_t)) &IntImpParGen::operator new[], "None", py::arg("theSize"));
// cls_IntImpParGen.def_static("operator delete[]_", (void (*)(void *)) &IntImpParGen::operator delete[], "None", py::arg("theAddress"));
// cls_IntImpParGen.def_static("operator new_", (void * (*)(size_t, void *)) &IntImpParGen::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntImpParGen.def_static("operator delete_", (void (*)(void *, void *)) &IntImpParGen::operator delete, "None", py::arg(""), py::arg(""));
cls_IntImpParGen.def_static("DetermineTransition_", (void (*)(const IntRes2d_Position, gp_Vec2d &, const gp_Vec2d &, IntRes2d_Transition &, const IntRes2d_Position, gp_Vec2d &, const gp_Vec2d &, IntRes2d_Transition &, const Standard_Real)) &IntImpParGen::DetermineTransition, "Template class for an implicit curve. Math function, instantiated inside the Intersector. Tool used by the package IntCurve and IntImpParGen", py::arg("Pos1"), py::arg("Tan1"), py::arg("Norm1"), py::arg("Trans1"), py::arg("Pos2"), py::arg("Tan2"), py::arg("Norm2"), py::arg("Trans2"), py::arg("Tol"));
cls_IntImpParGen.def_static("DetermineTransition_", (Standard_Boolean (*)(const IntRes2d_Position, gp_Vec2d &, IntRes2d_Transition &, const IntRes2d_Position, gp_Vec2d &, IntRes2d_Transition &, const Standard_Real)) &IntImpParGen::DetermineTransition, "None", py::arg("Pos1"), py::arg("Tan1"), py::arg("Trans1"), py::arg("Pos2"), py::arg("Tan2"), py::arg("Trans2"), py::arg("Tol"));
cls_IntImpParGen.def_static("DeterminePosition_", (void (*)(IntRes2d_Position &, const IntRes2d_Domain &, const gp_Pnt2d &, const Standard_Real)) &IntImpParGen::DeterminePosition, "None", py::arg("Pos1"), py::arg("Dom1"), py::arg("P1"), py::arg("Tol"));
cls_IntImpParGen.def_static("NormalizeOnDomain_", [](Standard_Real & Par1, const IntRes2d_Domain & Dom1){ Standard_Real rv = IntImpParGen::NormalizeOnDomain(Par1, Dom1); return std::tuple<Standard_Real, Standard_Real &>(rv, Par1); }, "None", py::arg("Par1"), py::arg("Dom1"));

// Enums

}