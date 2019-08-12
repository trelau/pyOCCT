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
#include <StepElement_SurfaceElementPurposeMember.hxx>
#include <Standard_Type.hxx>

void bind_StepElement_SurfaceElementPurposeMember(py::module &mod){

py::class_<StepElement_SurfaceElementPurposeMember, opencascade::handle<StepElement_SurfaceElementPurposeMember>, StepData_SelectNamed> cls_StepElement_SurfaceElementPurposeMember(mod, "StepElement_SurfaceElementPurposeMember", "Representation of member for STEP SELECT type SurfaceElementPurpose");

// Constructors
cls_StepElement_SurfaceElementPurposeMember.def(py::init<>());

// Fields

// Methods
cls_StepElement_SurfaceElementPurposeMember.def("HasName", (Standard_Boolean (StepElement_SurfaceElementPurposeMember::*)() const) &StepElement_SurfaceElementPurposeMember::HasName, "Returns True if has name");
cls_StepElement_SurfaceElementPurposeMember.def("Name", (Standard_CString (StepElement_SurfaceElementPurposeMember::*)() const) &StepElement_SurfaceElementPurposeMember::Name, "Returns set name");
cls_StepElement_SurfaceElementPurposeMember.def("SetName", (Standard_Boolean (StepElement_SurfaceElementPurposeMember::*)(const Standard_CString)) &StepElement_SurfaceElementPurposeMember::SetName, "Set name", py::arg("name"));
cls_StepElement_SurfaceElementPurposeMember.def("Matches", (Standard_Boolean (StepElement_SurfaceElementPurposeMember::*)(const Standard_CString) const) &StepElement_SurfaceElementPurposeMember::Matches, "Tells if the name of a SelectMember matches a given one;", py::arg("name"));
cls_StepElement_SurfaceElementPurposeMember.def_static("get_type_name_", (const char * (*)()) &StepElement_SurfaceElementPurposeMember::get_type_name, "None");
cls_StepElement_SurfaceElementPurposeMember.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepElement_SurfaceElementPurposeMember::get_type_descriptor, "None");
cls_StepElement_SurfaceElementPurposeMember.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepElement_SurfaceElementPurposeMember::*)() const) &StepElement_SurfaceElementPurposeMember::DynamicType, "None");

// Enums

}