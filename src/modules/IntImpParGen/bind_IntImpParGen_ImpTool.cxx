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
#include <gp_Pnt2d.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Vec2d.hxx>
#include <IntImpParGen_ImpTool.hxx>

void bind_IntImpParGen_ImpTool(py::module &mod){

py::class_<IntImpParGen_ImpTool, std::unique_ptr<IntImpParGen_ImpTool>> cls_IntImpParGen_ImpTool(mod, "IntImpParGen_ImpTool", "Template class for an implicit curve.");

// Constructors

// Fields

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

// Enums

}