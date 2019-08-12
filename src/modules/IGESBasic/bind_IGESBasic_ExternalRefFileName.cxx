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
#include <Standard_TypeDef.hxx>
#include <IGESBasic_ExternalRefFileName.hxx>
#include <Standard_Type.hxx>

void bind_IGESBasic_ExternalRefFileName(py::module &mod){

py::class_<IGESBasic_ExternalRefFileName, opencascade::handle<IGESBasic_ExternalRefFileName>, IGESData_IGESEntity> cls_IGESBasic_ExternalRefFileName(mod, "IGESBasic_ExternalRefFileName", "defines ExternalRefFileName, Type <416> Form <0-2> in package IGESBasic Used when single definition from the reference file is required or for external logical references where an entity in one file relates to an entity in another file");

// Constructors
cls_IGESBasic_ExternalRefFileName.def(py::init<>());

// Fields

// Methods
cls_IGESBasic_ExternalRefFileName.def("Init", (void (IGESBasic_ExternalRefFileName::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &)) &IGESBasic_ExternalRefFileName::Init, "This method is used to set the fields of the class ExternalRefFileName - aFileIdent : External Reference File Identifier - anExtName : External Reference Entity Symbolic Name", py::arg("aFileIdent"), py::arg("anExtName"));
cls_IGESBasic_ExternalRefFileName.def("SetForEntity", (void (IGESBasic_ExternalRefFileName::*)(const Standard_Boolean)) &IGESBasic_ExternalRefFileName::SetForEntity, "Changes FormNumber to be 2 if <mode> is True (For Entity) or 0 if <mode> is False (For Definition)", py::arg("mode"));
cls_IGESBasic_ExternalRefFileName.def("FileId", (opencascade::handle<TCollection_HAsciiString> (IGESBasic_ExternalRefFileName::*)() const) &IGESBasic_ExternalRefFileName::FileId, "returns External Reference File Identifier");
cls_IGESBasic_ExternalRefFileName.def("ReferenceName", (opencascade::handle<TCollection_HAsciiString> (IGESBasic_ExternalRefFileName::*)() const) &IGESBasic_ExternalRefFileName::ReferenceName, "returns External Reference Entity Symbolic Name");
cls_IGESBasic_ExternalRefFileName.def_static("get_type_name_", (const char * (*)()) &IGESBasic_ExternalRefFileName::get_type_name, "None");
cls_IGESBasic_ExternalRefFileName.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESBasic_ExternalRefFileName::get_type_descriptor, "None");
cls_IGESBasic_ExternalRefFileName.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESBasic_ExternalRefFileName::*)() const) &IGESBasic_ExternalRefFileName::DynamicType, "None");

// Enums

}