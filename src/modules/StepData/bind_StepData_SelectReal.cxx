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
#include <StepData_SelectMember.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <StepData_SelectReal.hxx>
#include <Standard_Type.hxx>

void bind_StepData_SelectReal(py::module &mod){

py::class_<StepData_SelectReal, opencascade::handle<StepData_SelectReal>, StepData_SelectMember> cls_StepData_SelectReal(mod, "StepData_SelectReal", "A SelectReal is a SelectMember specialised for a basic real type in a select which also accepts entities : this one has NO NAME For a named select, see SelectNamed");

// Constructors
cls_StepData_SelectReal.def(py::init<>());

// Fields

// Methods
cls_StepData_SelectReal.def("Kind", (Standard_Integer (StepData_SelectReal::*)() const) &StepData_SelectReal::Kind, "None");
cls_StepData_SelectReal.def("Real", (Standard_Real (StepData_SelectReal::*)() const) &StepData_SelectReal::Real, "None");
cls_StepData_SelectReal.def("SetReal", (void (StepData_SelectReal::*)(const Standard_Real)) &StepData_SelectReal::SetReal, "None", py::arg("val"));
cls_StepData_SelectReal.def_static("get_type_name_", (const char * (*)()) &StepData_SelectReal::get_type_name, "None");
cls_StepData_SelectReal.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepData_SelectReal::get_type_descriptor, "None");
cls_StepData_SelectReal.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepData_SelectReal::*)() const) &StepData_SelectReal::DynamicType, "None");

// Enums

}