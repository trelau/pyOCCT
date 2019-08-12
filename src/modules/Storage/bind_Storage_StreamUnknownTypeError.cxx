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
#include <Storage_StreamReadError.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Storage_StreamUnknownTypeError.hxx>
#include <Standard_SStream.hxx>
#include <Standard_Type.hxx>

void bind_Storage_StreamUnknownTypeError(py::module &mod){

py::class_<Storage_StreamUnknownTypeError, opencascade::handle<Storage_StreamUnknownTypeError>, Storage_StreamReadError> cls_Storage_StreamUnknownTypeError(mod, "Storage_StreamUnknownTypeError", "None");

// Constructors
cls_Storage_StreamUnknownTypeError.def(py::init<>());
cls_Storage_StreamUnknownTypeError.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Fields

// Methods
cls_Storage_StreamUnknownTypeError.def_static("Raise_", (void (*)(const Standard_CString)) &Storage_StreamUnknownTypeError::Raise, "None", py::arg("theMessage"));
cls_Storage_StreamUnknownTypeError.def_static("Raise_", (void (*)(Standard_SStream &)) &Storage_StreamUnknownTypeError::Raise, "None", py::arg("theMessage"));
cls_Storage_StreamUnknownTypeError.def_static("NewInstance_", (opencascade::handle<Storage_StreamUnknownTypeError> (*)(const Standard_CString)) &Storage_StreamUnknownTypeError::NewInstance, "None", py::arg("theMessage"));
cls_Storage_StreamUnknownTypeError.def_static("get_type_name_", (const char * (*)()) &Storage_StreamUnknownTypeError::get_type_name, "None");
cls_Storage_StreamUnknownTypeError.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Storage_StreamUnknownTypeError::get_type_descriptor, "None");
cls_Storage_StreamUnknownTypeError.def("DynamicType", (const opencascade::handle<Standard_Type> & (Storage_StreamUnknownTypeError::*)() const) &Storage_StreamUnknownTypeError::DynamicType, "None");

// Enums

}