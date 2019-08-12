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
#include <IGESData_IGESEntity.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <IGESBasic_ExternalRefFile.hxx>
#include <Standard_Type.hxx>

void bind_IGESBasic_ExternalRefFile(py::module &mod){

py::class_<IGESBasic_ExternalRefFile, opencascade::handle<IGESBasic_ExternalRefFile>, IGESData_IGESEntity> cls_IGESBasic_ExternalRefFile(mod, "IGESBasic_ExternalRefFile", "defines ExternalRefFile, Type <416> Form <1> in package IGESBasic Used when entire reference file is to be instanced");

// Constructors
cls_IGESBasic_ExternalRefFile.def(py::init<>());

// Fields

// Methods
cls_IGESBasic_ExternalRefFile.def("Init", (void (IGESBasic_ExternalRefFile::*)(const opencascade::handle<TCollection_HAsciiString> &)) &IGESBasic_ExternalRefFile::Init, "This method is used to set the field of the class ExternalRefFile - aFileIdent : External Reference File Identifier", py::arg("aFileIdent"));
cls_IGESBasic_ExternalRefFile.def("FileId", (opencascade::handle<TCollection_HAsciiString> (IGESBasic_ExternalRefFile::*)() const) &IGESBasic_ExternalRefFile::FileId, "returns External Reference File Identifier");
cls_IGESBasic_ExternalRefFile.def_static("get_type_name_", (const char * (*)()) &IGESBasic_ExternalRefFile::get_type_name, "None");
cls_IGESBasic_ExternalRefFile.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESBasic_ExternalRefFile::get_type_descriptor, "None");
cls_IGESBasic_ExternalRefFile.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESBasic_ExternalRefFile::*)() const) &IGESBasic_ExternalRefFile::DynamicType, "None");

// Enums

}