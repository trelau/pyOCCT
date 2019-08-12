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
#include <Storage_StreamModeError.hxx>
#include <Standard_SStream.hxx>
#include <Standard_Type.hxx>

void bind_Storage_StreamModeError(py::module &mod){

py::class_<Storage_StreamModeError, opencascade::handle<Storage_StreamModeError>, Standard_Failure> cls_Storage_StreamModeError(mod, "Storage_StreamModeError", "None");

// Constructors
cls_Storage_StreamModeError.def(py::init<>());
cls_Storage_StreamModeError.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Fields

// Methods
cls_Storage_StreamModeError.def_static("Raise_", (void (*)(const Standard_CString)) &Storage_StreamModeError::Raise, "None", py::arg("theMessage"));
cls_Storage_StreamModeError.def_static("Raise_", (void (*)(Standard_SStream &)) &Storage_StreamModeError::Raise, "None", py::arg("theMessage"));
cls_Storage_StreamModeError.def_static("NewInstance_", (opencascade::handle<Storage_StreamModeError> (*)(const Standard_CString)) &Storage_StreamModeError::NewInstance, "None", py::arg("theMessage"));
cls_Storage_StreamModeError.def_static("get_type_name_", (const char * (*)()) &Storage_StreamModeError::get_type_name, "None");
cls_Storage_StreamModeError.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Storage_StreamModeError::get_type_descriptor, "None");
cls_Storage_StreamModeError.def("DynamicType", (const opencascade::handle<Standard_Type> & (Storage_StreamModeError::*)() const) &Storage_StreamModeError::DynamicType, "None");

// Enums

}