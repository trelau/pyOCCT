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
#include <StepGeom_Parabola.hxx>
#include <Standard_Type.hxx>

void bind_StepGeom_Parabola(py::module &mod){

py::class_<StepGeom_Parabola, opencascade::handle<StepGeom_Parabola>, StepGeom_Conic> cls_StepGeom_Parabola(mod, "StepGeom_Parabola", "None");

// Constructors
cls_StepGeom_Parabola.def(py::init<>());

// Fields

// Methods
cls_StepGeom_Parabola.def("Init", (void (StepGeom_Parabola::*)(const opencascade::handle<TCollection_HAsciiString> &, const StepGeom_Axis2Placement &, const Standard_Real)) &StepGeom_Parabola::Init, "None", py::arg("aName"), py::arg("aPosition"), py::arg("aFocalDist"));
cls_StepGeom_Parabola.def("SetFocalDist", (void (StepGeom_Parabola::*)(const Standard_Real)) &StepGeom_Parabola::SetFocalDist, "None", py::arg("aFocalDist"));
cls_StepGeom_Parabola.def("FocalDist", (Standard_Real (StepGeom_Parabola::*)() const) &StepGeom_Parabola::FocalDist, "None");
cls_StepGeom_Parabola.def_static("get_type_name_", (const char * (*)()) &StepGeom_Parabola::get_type_name, "None");
cls_StepGeom_Parabola.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_Parabola::get_type_descriptor, "None");
cls_StepGeom_Parabola.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_Parabola::*)() const) &StepGeom_Parabola::DynamicType, "None");

// Enums

}