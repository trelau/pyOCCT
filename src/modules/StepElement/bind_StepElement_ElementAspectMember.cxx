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
#include <StepData_SelectNamed.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <StepElement_ElementAspectMember.hxx>
#include <Standard_Type.hxx>

void bind_StepElement_ElementAspectMember(py::module &mod){

py::class_<StepElement_ElementAspectMember, opencascade::handle<StepElement_ElementAspectMember>, StepData_SelectNamed> cls_StepElement_ElementAspectMember(mod, "StepElement_ElementAspectMember", "Representation of member for STEP SELECT type ElementAspect");

// Constructors
cls_StepElement_ElementAspectMember.def(py::init<>());

// Fields

// Methods
cls_StepElement_ElementAspectMember.def("HasName", (Standard_Boolean (StepElement_ElementAspectMember::*)() const) &StepElement_ElementAspectMember::HasName, "Returns True if has name");
cls_StepElement_ElementAspectMember.def("Name", (Standard_CString (StepElement_ElementAspectMember::*)() const) &StepElement_ElementAspectMember::Name, "Returns set name");
cls_StepElement_ElementAspectMember.def("SetName", (Standard_Boolean (StepElement_ElementAspectMember::*)(const Standard_CString)) &StepElement_ElementAspectMember::SetName, "Set name", py::arg("name"));
cls_StepElement_ElementAspectMember.def("Matches", (Standard_Boolean (StepElement_ElementAspectMember::*)(const Standard_CString) const) &StepElement_ElementAspectMember::Matches, "Tells if the name of a SelectMember matches a given one;", py::arg("name"));
cls_StepElement_ElementAspectMember.def_static("get_type_name_", (const char * (*)()) &StepElement_ElementAspectMember::get_type_name, "None");
cls_StepElement_ElementAspectMember.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepElement_ElementAspectMember::get_type_descriptor, "None");
cls_StepElement_ElementAspectMember.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepElement_ElementAspectMember::*)() const) &StepElement_ElementAspectMember::DynamicType, "None");

// Enums

}