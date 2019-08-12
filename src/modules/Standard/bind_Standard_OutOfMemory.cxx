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
#include <Standard_ProgramError.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_SStream.hxx>
#include <Standard_Handle.hxx>
#include <Standard_OutOfMemory.hxx>
#include <Standard_Type.hxx>

void bind_Standard_OutOfMemory(py::module &mod){

py::class_<Standard_OutOfMemory, opencascade::handle<Standard_OutOfMemory>, Standard_ProgramError> cls_Standard_OutOfMemory(mod, "Standard_OutOfMemory", "Standard_OutOfMemory exception is defined explicitly and not by macro DEFINE_STANDARD_EXCEPTION, to avoid necessity of dynamic memory allocations during throwing and stack unwinding:");

// Constructors
cls_Standard_OutOfMemory.def(py::init<>());
cls_Standard_OutOfMemory.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Fields

// Methods
cls_Standard_OutOfMemory.def("GetMessageString", (Standard_CString (Standard_OutOfMemory::*)() const) &Standard_OutOfMemory::GetMessageString, "Returns error message");
cls_Standard_OutOfMemory.def("SetMessageString", (void (Standard_OutOfMemory::*)(const Standard_CString)) &Standard_OutOfMemory::SetMessageString, "Sets error message", py::arg("aMessage"));
cls_Standard_OutOfMemory.def_static("Raise_", []() -> void { return Standard_OutOfMemory::Raise(); });
cls_Standard_OutOfMemory.def_static("Raise_", (void (*)(const Standard_CString)) &Standard_OutOfMemory::Raise, "Raises exception with specified message string", py::arg("theMessage"));
cls_Standard_OutOfMemory.def_static("Raise_", (void (*)(Standard_SStream &)) &Standard_OutOfMemory::Raise, "Raises exception with specified message string", py::arg("theMessage"));
cls_Standard_OutOfMemory.def_static("NewInstance_", []() -> opencascade::handle<Standard_OutOfMemory> { return Standard_OutOfMemory::NewInstance(); });
cls_Standard_OutOfMemory.def_static("NewInstance_", (opencascade::handle<Standard_OutOfMemory> (*)(const Standard_CString)) &Standard_OutOfMemory::NewInstance, "Returns global instance of exception", py::arg("theMessage"));
cls_Standard_OutOfMemory.def_static("get_type_name_", (const char * (*)()) &Standard_OutOfMemory::get_type_name, "None");
cls_Standard_OutOfMemory.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Standard_OutOfMemory::get_type_descriptor, "None");
cls_Standard_OutOfMemory.def("DynamicType", (const opencascade::handle<Standard_Type> & (Standard_OutOfMemory::*)() const) &Standard_OutOfMemory::DynamicType, "None");

// Enums

}