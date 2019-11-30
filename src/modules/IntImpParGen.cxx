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

PYBIND11_MODULE(IntImpParGen, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.IntRes2d");
py::module::import("OCCT.gp");

// CLASS: INTIMPPARGEN
py::class_<IntImpParGen> cls_IntImpParGen(mod, "IntImpParGen", "Gives a generic algorithm to intersect Implicit Curves and Bounded Parametric Curves.");

// Constructors
cls_IntImpParGen.def(py::init<>());

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

// CLASS: INTIMPPARGEN_IMPTOOL
py::class_<IntImpParGen_ImpTool> cls_IntImpParGen_ImpTool(mod, "IntImpParGen_ImpTool", "Template class for an implicit curve.");

// Constructors
cls_IntImpParGen_ImpTool.def(py::init<>());

// Methods
// cls_IntImpParGen_ImpTool.def_static("operator new_", (void * (*)(size_t)) &IntImpParGen_ImpTool::operator new, "None", py::arg("theSize"));
// cls_IntImpParGen_ImpTool.def_static("operator delete_", (void (*)(void *)) &IntImpParGen_ImpTool::operator delete, "None", py::arg("theAddress"));
// cls_IntImpParGen_ImpTool.def_static("operator new[]_", (void * (*)(size_t)) &IntImpParGen_ImpTool::operator new[], "None", py::arg("theSize"));
// cls_IntImpParGen_ImpTool.def_static("operator delete[]_", (void (*)(void *)) &IntImpParGen_ImpTool::operator delete[], "None", py::arg("theAddress"));
// cls_IntImpParGen_ImpTool.def_static("operator new_", (void * (*)(size_t, void *)) &IntImpParGen_ImpTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntImpParGen_ImpTool.def_static("operator delete_", (void (*)(void *, void *)) &IntImpParGen_ImpTool::operator delete, "None", py::arg(""), py::arg(""));
// cls_IntImpParGen_ImpTool.def("Value", (gp_Pnt2d (IntImpParGen_ImpTool::*)(const Standard_Real) const) &IntImpParGen_ImpTool::Value, "None", py::arg("U"));
// cls_IntImpParGen_ImpTool.def("D1", (void (IntImpParGen_ImpTool::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &) const) &IntImpParGen_ImpTool::D1, "None", py::arg("U"), py::arg("P"), py::arg("T"));
// cls_IntImpParGen_ImpTool.def("D2", (void (IntImpParGen_ImpTool::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &) const) &IntImpParGen_ImpTool::D2, "None", py::arg("U"), py::arg("P"), py::arg("T"), py::arg("N"));
// cls_IntImpParGen_ImpTool.def("Distance", (Standard_Real (IntImpParGen_ImpTool::*)(const gp_Pnt2d &) const) &IntImpParGen_ImpTool::Distance, "Computes the value of the signed distance between the point P and the implicit curve.", py::arg("P"));
// cls_IntImpParGen_ImpTool.def("GradDistance", (gp_Vec2d (IntImpParGen_ImpTool::*)(const gp_Pnt2d &) const) &IntImpParGen_ImpTool::GradDistance, "Computes the Gradient of the Signed Distance between a point and the implicit curve, at the point P.", py::arg("P"));
// cls_IntImpParGen_ImpTool.def("FindParameter", (Standard_Real (IntImpParGen_ImpTool::*)(const gp_Pnt2d &) const) &IntImpParGen_ImpTool::FindParameter, "Returns the parameter U of the point on the implicit curve corresponding to the point P. The correspondance between P and the point P(U) on the implicit curve must be coherent with the way of determination of the signed distance.", py::arg("P"));


}
