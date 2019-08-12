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
#include <Standard_Failure.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Standard_ProgramError.hxx>
#include <Standard_SStream.hxx>
#include <Standard_Type.hxx>

void bind_Standard_ProgramError(py::module &mod){

py::class_<Standard_ProgramError, opencascade::handle<Standard_ProgramError>, Standard_Failure> cls_Standard_ProgramError(mod, "Standard_ProgramError", "None");

// Constructors
cls_Standard_ProgramError.def(py::init<>());
cls_Standard_ProgramError.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Fields

// Methods
cls_Standard_ProgramError.def_static("Raise_", (void (*)(const Standard_CString)) &Standard_ProgramError::Raise, "None", py::arg("theMessage"));
cls_Standard_ProgramError.def_static("Raise_", (void (*)(Standard_SStream &)) &Standard_ProgramError::Raise, "None", py::arg("theMessage"));
cls_Standard_ProgramError.def_static("NewInstance_", (opencascade::handle<Standard_ProgramError> (*)(const Standard_CString)) &Standard_ProgramError::NewInstance, "None", py::arg("theMessage"));
cls_Standard_ProgramError.def_static("get_type_name_", (const char * (*)()) &Standard_ProgramError::get_type_name, "None");
cls_Standard_ProgramError.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Standard_ProgramError::get_type_descriptor, "None");
cls_Standard_ProgramError.def("DynamicType", (const opencascade::handle<Standard_Type> & (Standard_ProgramError::*)() const) &Standard_ProgramError::DynamicType, "None");

// Enums

}