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
#include <Standard_Transient.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <StepData_Described.hxx>
#include <StepData_EDescr.hxx>
#include <Standard_Type.hxx>

void bind_StepData_EDescr(py::module &mod){

py::class_<StepData_EDescr, opencascade::handle<StepData_EDescr>, Standard_Transient> cls_StepData_EDescr(mod, "StepData_EDescr", "This class is intended to describe the authorized form for an entity, either Simple or Plex");

// Fields

// Methods
cls_StepData_EDescr.def("Matches", (Standard_Boolean (StepData_EDescr::*)(const Standard_CString) const) &StepData_EDescr::Matches, "Tells if a ESDescr matches a step type : exact or super type", py::arg("steptype"));
cls_StepData_EDescr.def("IsComplex", (Standard_Boolean (StepData_EDescr::*)() const) &StepData_EDescr::IsComplex, "Tells if a EDescr is complex (ECDescr) or simple (ESDescr)");
cls_StepData_EDescr.def("NewEntity", (opencascade::handle<StepData_Described> (StepData_EDescr::*)() const) &StepData_EDescr::NewEntity, "Creates a described entity (i.e. a simple one)");
cls_StepData_EDescr.def_static("get_type_name_", (const char * (*)()) &StepData_EDescr::get_type_name, "None");
cls_StepData_EDescr.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepData_EDescr::get_type_descriptor, "None");
cls_StepData_EDescr.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepData_EDescr::*)() const) &StepData_EDescr::DynamicType, "None");

// Enums

}