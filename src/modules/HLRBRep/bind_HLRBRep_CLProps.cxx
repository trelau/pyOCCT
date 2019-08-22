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
#include <gp_Dir2d.hxx>
#include <LProp_Status.hxx>
#include <HLRBRep_CLProps.hxx>

void bind_HLRBRep_CLProps(py::module &mod){

py::class_<HLRBRep_CLProps> cls_HLRBRep_CLProps(mod, "HLRBRep_CLProps", "None");

// Constructors
// cls_HLRBRep_CLProps.def(py::init<const HLRBRep_Curve *&, const Standard_Integer, const Standard_Real>(), py::arg("C"), py::arg("N"), py::arg("Resolution"));
// cls_HLRBRep_CLProps.def(py::init<const HLRBRep_Curve *&, const Standard_Real, const Standard_Integer, const Standard_Real>(), py::arg("C"), py::arg("U"), py::arg("N"), py::arg("Resolution"));
cls_HLRBRep_CLProps.def(py::init<const Standard_Integer, const Standard_Real>(), py::arg("N"), py::arg("Resolution"));

// Fields

// Methods
// cls_HLRBRep_CLProps.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_CLProps::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_CLProps.def_static("operator delete_", (void (*)(void *)) &HLRBRep_CLProps::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_CLProps.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_CLProps::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_CLProps.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_CLProps::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_CLProps.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_CLProps::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_CLProps.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_CLProps::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_CLProps.def("SetParameter", (void (HLRBRep_CLProps::*)(const Standard_Real)) &HLRBRep_CLProps::SetParameter, "Initializes the local properties of the curve for the parameter value <U>.", py::arg("U"));
// cls_HLRBRep_CLProps.def("SetCurve", (void (HLRBRep_CLProps::*)(const HLRBRep_Curve *&)) &HLRBRep_CLProps::SetCurve, "Initializes the local properties of the curve for the new curve.", py::arg("C"));
cls_HLRBRep_CLProps.def("Value", (const gp_Pnt2d & (HLRBRep_CLProps::*)() const) &HLRBRep_CLProps::Value, "Returns the Point.");
cls_HLRBRep_CLProps.def("D1", (const gp_Vec2d & (HLRBRep_CLProps::*)()) &HLRBRep_CLProps::D1, "Returns the first derivative. The derivative is computed if it has not been yet.");
cls_HLRBRep_CLProps.def("D2", (const gp_Vec2d & (HLRBRep_CLProps::*)()) &HLRBRep_CLProps::D2, "Returns the second derivative. The derivative is computed if it has not been yet.");
cls_HLRBRep_CLProps.def("D3", (const gp_Vec2d & (HLRBRep_CLProps::*)()) &HLRBRep_CLProps::D3, "Returns the third derivative. The derivative is computed if it has not been yet.");
cls_HLRBRep_CLProps.def("IsTangentDefined", (Standard_Boolean (HLRBRep_CLProps::*)()) &HLRBRep_CLProps::IsTangentDefined, "Returns True if the tangent is defined. For example, the tangent is not defined if the three first derivatives are all null.");
cls_HLRBRep_CLProps.def("Tangent", (void (HLRBRep_CLProps::*)(gp_Dir2d &)) &HLRBRep_CLProps::Tangent, "output the tangent direction <D>", py::arg("D"));
cls_HLRBRep_CLProps.def("Curvature", (Standard_Real (HLRBRep_CLProps::*)()) &HLRBRep_CLProps::Curvature, "Returns the curvature.");
cls_HLRBRep_CLProps.def("Normal", (void (HLRBRep_CLProps::*)(gp_Dir2d &)) &HLRBRep_CLProps::Normal, "Returns the normal direction <N>.", py::arg("N"));
cls_HLRBRep_CLProps.def("CentreOfCurvature", (void (HLRBRep_CLProps::*)(gp_Pnt2d &)) &HLRBRep_CLProps::CentreOfCurvature, "Returns the centre of curvature <P>.", py::arg("P"));

// Enums

}