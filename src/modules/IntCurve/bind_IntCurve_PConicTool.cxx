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
#include <IntCurve_PConic.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Vec2d.hxx>
#include <IntCurve_PConicTool.hxx>

void bind_IntCurve_PConicTool(py::module &mod){

py::class_<IntCurve_PConicTool> cls_IntCurve_PConicTool(mod, "IntCurve_PConicTool", "Implementation of the ParTool from IntImpParGen for conics of gp, using the class PConic from IntCurve.");

// Constructors

// Fields

// Methods
// cls_IntCurve_PConicTool.def_static("operator new_", (void * (*)(size_t)) &IntCurve_PConicTool::operator new, "None", py::arg("theSize"));
// cls_IntCurve_PConicTool.def_static("operator delete_", (void (*)(void *)) &IntCurve_PConicTool::operator delete, "None", py::arg("theAddress"));
// cls_IntCurve_PConicTool.def_static("operator new[]_", (void * (*)(size_t)) &IntCurve_PConicTool::operator new[], "None", py::arg("theSize"));
// cls_IntCurve_PConicTool.def_static("operator delete[]_", (void (*)(void *)) &IntCurve_PConicTool::operator delete[], "None", py::arg("theAddress"));
// cls_IntCurve_PConicTool.def_static("operator new_", (void * (*)(size_t, void *)) &IntCurve_PConicTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntCurve_PConicTool.def_static("operator delete_", (void (*)(void *, void *)) &IntCurve_PConicTool::operator delete, "None", py::arg(""), py::arg(""));
cls_IntCurve_PConicTool.def_static("EpsX_", (Standard_Real (*)(const IntCurve_PConic &)) &IntCurve_PConicTool::EpsX, "None", py::arg("C"));
cls_IntCurve_PConicTool.def_static("NbSamples_", (Standard_Integer (*)(const IntCurve_PConic &)) &IntCurve_PConicTool::NbSamples, "None", py::arg("C"));
cls_IntCurve_PConicTool.def_static("NbSamples_", (Standard_Integer (*)(const IntCurve_PConic &, const Standard_Real, const Standard_Real)) &IntCurve_PConicTool::NbSamples, "None", py::arg("C"), py::arg("U0"), py::arg("U1"));
cls_IntCurve_PConicTool.def_static("Value_", (gp_Pnt2d (*)(const IntCurve_PConic &, const Standard_Real)) &IntCurve_PConicTool::Value, "None", py::arg("C"), py::arg("X"));
cls_IntCurve_PConicTool.def_static("D1_", (void (*)(const IntCurve_PConic &, const Standard_Real, gp_Pnt2d &, gp_Vec2d &)) &IntCurve_PConicTool::D1, "None", py::arg("C"), py::arg("U"), py::arg("P"), py::arg("T"));
cls_IntCurve_PConicTool.def_static("D2_", (void (*)(const IntCurve_PConic &, const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &)) &IntCurve_PConicTool::D2, "None", py::arg("C"), py::arg("U"), py::arg("P"), py::arg("T"), py::arg("N"));

// Enums

}