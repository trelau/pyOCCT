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
#include <Geom2dAdaptor_Curve.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Vec2d.hxx>
#include <Geom2dGcc_CurveTool.hxx>

void bind_Geom2dGcc_CurveTool(py::module &mod){

py::class_<Geom2dGcc_CurveTool> cls_Geom2dGcc_CurveTool(mod, "Geom2dGcc_CurveTool", "None");

// Constructors

// Fields

// Methods
// cls_Geom2dGcc_CurveTool.def_static("operator new_", (void * (*)(size_t)) &Geom2dGcc_CurveTool::operator new, "None", py::arg("theSize"));
// cls_Geom2dGcc_CurveTool.def_static("operator delete_", (void (*)(void *)) &Geom2dGcc_CurveTool::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dGcc_CurveTool.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dGcc_CurveTool::operator new[], "None", py::arg("theSize"));
// cls_Geom2dGcc_CurveTool.def_static("operator delete[]_", (void (*)(void *)) &Geom2dGcc_CurveTool::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dGcc_CurveTool.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dGcc_CurveTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dGcc_CurveTool.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dGcc_CurveTool::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dGcc_CurveTool.def_static("FirstParameter_", (Standard_Real (*)(const Geom2dAdaptor_Curve &)) &Geom2dGcc_CurveTool::FirstParameter, "None", py::arg("C"));
cls_Geom2dGcc_CurveTool.def_static("LastParameter_", (Standard_Real (*)(const Geom2dAdaptor_Curve &)) &Geom2dGcc_CurveTool::LastParameter, "None", py::arg("C"));
cls_Geom2dGcc_CurveTool.def_static("EpsX_", (Standard_Real (*)(const Geom2dAdaptor_Curve &, const Standard_Real)) &Geom2dGcc_CurveTool::EpsX, "None", py::arg("C"), py::arg("Tol"));
cls_Geom2dGcc_CurveTool.def_static("NbSamples_", (Standard_Integer (*)(const Geom2dAdaptor_Curve &)) &Geom2dGcc_CurveTool::NbSamples, "None", py::arg("C"));
cls_Geom2dGcc_CurveTool.def_static("Value_", (gp_Pnt2d (*)(const Geom2dAdaptor_Curve &, const Standard_Real)) &Geom2dGcc_CurveTool::Value, "None", py::arg("C"), py::arg("X"));
cls_Geom2dGcc_CurveTool.def_static("D1_", (void (*)(const Geom2dAdaptor_Curve &, const Standard_Real, gp_Pnt2d &, gp_Vec2d &)) &Geom2dGcc_CurveTool::D1, "None", py::arg("C"), py::arg("U"), py::arg("P"), py::arg("T"));
cls_Geom2dGcc_CurveTool.def_static("D2_", (void (*)(const Geom2dAdaptor_Curve &, const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &)) &Geom2dGcc_CurveTool::D2, "None", py::arg("C"), py::arg("U"), py::arg("P"), py::arg("T"), py::arg("N"));
cls_Geom2dGcc_CurveTool.def_static("D3_", (void (*)(const Geom2dAdaptor_Curve &, const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &, gp_Vec2d &)) &Geom2dGcc_CurveTool::D3, "None", py::arg("C"), py::arg("U"), py::arg("P"), py::arg("T"), py::arg("N"), py::arg("dN"));

// Enums

}