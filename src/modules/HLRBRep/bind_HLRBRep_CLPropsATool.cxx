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
#include <HLRBRep_Curve.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Vec2d.hxx>
#include <HLRBRep_CLPropsATool.hxx>

void bind_HLRBRep_CLPropsATool(py::module &mod){

py::class_<HLRBRep_CLPropsATool, std::unique_ptr<HLRBRep_CLPropsATool>> cls_HLRBRep_CLPropsATool(mod, "HLRBRep_CLPropsATool", "None");

// Constructors

// Fields

// Methods
// cls_HLRBRep_CLPropsATool.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_CLPropsATool::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_CLPropsATool.def_static("operator delete_", (void (*)(void *)) &HLRBRep_CLPropsATool::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_CLPropsATool.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_CLPropsATool::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_CLPropsATool.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_CLPropsATool::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_CLPropsATool.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_CLPropsATool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_CLPropsATool.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_CLPropsATool::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_CLPropsATool.def_static("Value_", (void (*)(const HLRBRep_Curve *, const Standard_Real, gp_Pnt2d &)) &HLRBRep_CLPropsATool::Value, "Computes the point <P> of parameter <U> on the Curve from HLRBRep <C>.", py::arg("A"), py::arg("U"), py::arg("P"));
cls_HLRBRep_CLPropsATool.def_static("D1_", (void (*)(const HLRBRep_Curve *, const Standard_Real, gp_Pnt2d &, gp_Vec2d &)) &HLRBRep_CLPropsATool::D1, "Computes the point <P> and first derivative <V1> of parameter <U> on the curve <C>.", py::arg("A"), py::arg("U"), py::arg("P"), py::arg("V1"));
cls_HLRBRep_CLPropsATool.def_static("D2_", (void (*)(const HLRBRep_Curve *, const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &)) &HLRBRep_CLPropsATool::D2, "Computes the point <P>, the first derivative <V1> and second derivative <V2> of parameter <U> on the curve <C>.", py::arg("A"), py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"));
cls_HLRBRep_CLPropsATool.def_static("D3_", (void (*)(const HLRBRep_Curve *, const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &, gp_Vec2d &)) &HLRBRep_CLPropsATool::D3, "Computes the point <P>, the first derivative <V1>, the second derivative <V2> and third derivative <V3> of parameter <U> on the curve <C>.", py::arg("A"), py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"));
cls_HLRBRep_CLPropsATool.def_static("Continuity_", (Standard_Integer (*)(const HLRBRep_Curve *)) &HLRBRep_CLPropsATool::Continuity, "returns the order of continuity of the curve <C>. returns 1 : first derivative only is computable returns 2 : first and second derivative only are computable. returns 3 : first, second and third are computable.", py::arg("A"));
cls_HLRBRep_CLPropsATool.def_static("FirstParameter_", (Standard_Real (*)(const HLRBRep_Curve *)) &HLRBRep_CLPropsATool::FirstParameter, "returns the first parameter bound of the curve.", py::arg("A"));
cls_HLRBRep_CLPropsATool.def_static("LastParameter_", (Standard_Real (*)(const HLRBRep_Curve *)) &HLRBRep_CLPropsATool::LastParameter, "returns the last parameter bound of the curve. FirstParameter must be less than LastParamenter.", py::arg("A"));

// Enums

}