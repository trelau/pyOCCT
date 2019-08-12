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
#include <Interface_HArray1OfHAsciiString.hxx>
#include <Standard_TypeDef.hxx>
#include <TCollection_HAsciiString.hxx>
#include <IGESBasic_ExternalReferenceFile.hxx>
#include <Standard_Type.hxx>

void bind_IGESBasic_ExternalReferenceFile(py::module &mod){

py::class_<IGESBasic_ExternalReferenceFile, opencascade::handle<IGESBasic_ExternalReferenceFile>, IGESData_IGESEntity> cls_IGESBasic_ExternalReferenceFile(mod, "IGESBasic_ExternalReferenceFile", "defines ExternalReferenceFile, Type <406> Form <12> in package IGESBasic References definitions residing in another file");

// Constructors
cls_IGESBasic_ExternalReferenceFile.def(py::init<>());

// Fields

// Methods
cls_IGESBasic_ExternalReferenceFile.def("Init", (void (IGESBasic_ExternalReferenceFile::*)(const opencascade::handle<Interface_HArray1OfHAsciiString> &)) &IGESBasic_ExternalReferenceFile::Init, "This method is used to set the fields of the class ExternalReferenceFile - aNameArray : External Reference File Names", py::arg("aNameArray"));
cls_IGESBasic_ExternalReferenceFile.def("NbListEntries", (Standard_Integer (IGESBasic_ExternalReferenceFile::*)() const) &IGESBasic_ExternalReferenceFile::NbListEntries, "returns number of External Reference File Names");
cls_IGESBasic_ExternalReferenceFile.def("Name", (opencascade::handle<TCollection_HAsciiString> (IGESBasic_ExternalReferenceFile::*)(const Standard_Integer) const) &IGESBasic_ExternalReferenceFile::Name, "returns External Reference File Name raises exception if Index <= 0 or Index > NbListEntries()", py::arg("Index"));
cls_IGESBasic_ExternalReferenceFile.def_static("get_type_name_", (const char * (*)()) &IGESBasic_ExternalReferenceFile::get_type_name, "None");
cls_IGESBasic_ExternalReferenceFile.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESBasic_ExternalReferenceFile::get_type_descriptor, "None");
cls_IGESBasic_ExternalReferenceFile.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESBasic_ExternalReferenceFile::*)() const) &IGESBasic_ExternalReferenceFile::DynamicType, "None");

// Enums

}