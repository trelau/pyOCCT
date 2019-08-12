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
#include <StepGeom_Conic.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepGeom_Axis2Placement.hxx>
#include <Standard_TypeDef.hxx>
#include <StepGeom_Hyperbola.hxx>
#include <Standard_Type.hxx>

void bind_StepGeom_Hyperbola(py::module &mod){

py::class_<StepGeom_Hyperbola, opencascade::handle<StepGeom_Hyperbola>, StepGeom_Conic> cls_StepGeom_Hyperbola(mod, "StepGeom_Hyperbola", "None");

// Constructors
cls_StepGeom_Hyperbola.def(py::init<>());

// Fields

// Methods
cls_StepGeom_Hyperbola.def("Init", (void (StepGeom_Hyperbola::*)(const opencascade::handle<TCollection_HAsciiString> &, const StepGeom_Axis2Placement &, const Standard_Real, const Standard_Real)) &StepGeom_Hyperbola::Init, "None", py::arg("aName"), py::arg("aPosition"), py::arg("aSemiAxis"), py::arg("aSemiImagAxis"));
cls_StepGeom_Hyperbola.def("SetSemiAxis", (void (StepGeom_Hyperbola::*)(const Standard_Real)) &StepGeom_Hyperbola::SetSemiAxis, "None", py::arg("aSemiAxis"));
cls_StepGeom_Hyperbola.def("SemiAxis", (Standard_Real (StepGeom_Hyperbola::*)() const) &StepGeom_Hyperbola::SemiAxis, "None");
cls_StepGeom_Hyperbola.def("SetSemiImagAxis", (void (StepGeom_Hyperbola::*)(const Standard_Real)) &StepGeom_Hyperbola::SetSemiImagAxis, "None", py::arg("aSemiImagAxis"));
cls_StepGeom_Hyperbola.def("SemiImagAxis", (Standard_Real (StepGeom_Hyperbola::*)() const) &StepGeom_Hyperbola::SemiImagAxis, "None");
cls_StepGeom_Hyperbola.def_static("get_type_name_", (const char * (*)()) &StepGeom_Hyperbola::get_type_name, "None");
cls_StepGeom_Hyperbola.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_Hyperbola::get_type_descriptor, "None");
cls_StepGeom_Hyperbola.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_Hyperbola::*)() const) &StepGeom_Hyperbola::DynamicType, "None");

// Enums

}