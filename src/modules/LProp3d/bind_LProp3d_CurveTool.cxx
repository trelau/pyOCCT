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
#include <Adaptor3d_HCurve.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>
#include <LProp3d_CurveTool.hxx>

void bind_LProp3d_CurveTool(py::module &mod){

py::class_<LProp3d_CurveTool> cls_LProp3d_CurveTool(mod, "LProp3d_CurveTool", "None");

// Constructors

// Fields

// Methods
// cls_LProp3d_CurveTool.def_static("operator new_", (void * (*)(size_t)) &LProp3d_CurveTool::operator new, "None", py::arg("theSize"));
// cls_LProp3d_CurveTool.def_static("operator delete_", (void (*)(void *)) &LProp3d_CurveTool::operator delete, "None", py::arg("theAddress"));
// cls_LProp3d_CurveTool.def_static("operator new[]_", (void * (*)(size_t)) &LProp3d_CurveTool::operator new[], "None", py::arg("theSize"));
// cls_LProp3d_CurveTool.def_static("operator delete[]_", (void (*)(void *)) &LProp3d_CurveTool::operator delete[], "None", py::arg("theAddress"));
// cls_LProp3d_CurveTool.def_static("operator new_", (void * (*)(size_t, void *)) &LProp3d_CurveTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_LProp3d_CurveTool.def_static("operator delete_", (void (*)(void *, void *)) &LProp3d_CurveTool::operator delete, "None", py::arg(""), py::arg(""));
cls_LProp3d_CurveTool.def_static("Value_", (void (*)(const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Real, gp_Pnt &)) &LProp3d_CurveTool::Value, "Computes the point <P> of parameter <U> on the HCurve <C>.", py::arg("C"), py::arg("U"), py::arg("P"));
cls_LProp3d_CurveTool.def_static("D1_", (void (*)(const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Real, gp_Pnt &, gp_Vec &)) &LProp3d_CurveTool::D1, "Computes the point <P> and first derivative <V1> of parameter <U> on the HCurve <C>.", py::arg("C"), py::arg("U"), py::arg("P"), py::arg("V1"));
cls_LProp3d_CurveTool.def_static("D2_", (void (*)(const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &)) &LProp3d_CurveTool::D2, "Computes the point <P>, the first derivative <V1> and second derivative <V2> of parameter <U> on the HCurve <C>.", py::arg("C"), py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"));
cls_LProp3d_CurveTool.def_static("D3_", (void (*)(const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &)) &LProp3d_CurveTool::D3, "Computes the point <P>, the first derivative <V1>, the second derivative <V2> and third derivative <V3> of parameter <U> on the HCurve <C>.", py::arg("C"), py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"));
cls_LProp3d_CurveTool.def_static("Continuity_", (Standard_Integer (*)(const opencascade::handle<Adaptor3d_HCurve> &)) &LProp3d_CurveTool::Continuity, "returns the order of continuity of the HCurve <C>. returns 1 : first derivative only is computable returns 2 : first and second derivative only are computable. returns 3 : first, second and third are computable.", py::arg("C"));
cls_LProp3d_CurveTool.def_static("FirstParameter_", (Standard_Real (*)(const opencascade::handle<Adaptor3d_HCurve> &)) &LProp3d_CurveTool::FirstParameter, "returns the first parameter bound of the HCurve.", py::arg("C"));
cls_LProp3d_CurveTool.def_static("LastParameter_", (Standard_Real (*)(const opencascade::handle<Adaptor3d_HCurve> &)) &LProp3d_CurveTool::LastParameter, "returns the last parameter bound of the HCurve. FirstParameter must be less than LastParamenter.", py::arg("C"));

// Enums

}