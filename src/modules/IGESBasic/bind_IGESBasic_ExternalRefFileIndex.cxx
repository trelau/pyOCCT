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
#include <IGESData_HArray1OfIGESEntity.hxx>
#include <Standard_TypeDef.hxx>
#include <TCollection_HAsciiString.hxx>
#include <IGESBasic_ExternalRefFileIndex.hxx>
#include <Standard_Type.hxx>

void bind_IGESBasic_ExternalRefFileIndex(py::module &mod){

py::class_<IGESBasic_ExternalRefFileIndex, opencascade::handle<IGESBasic_ExternalRefFileIndex>, IGESData_IGESEntity> cls_IGESBasic_ExternalRefFileIndex(mod, "IGESBasic_ExternalRefFileIndex", "defines ExternalRefFileIndex, Type <402> Form <12> in package IGESBasic Contains a list of the symbolic names used by the referencing files and the DE pointers to the corresponding definitions within the referenced file");

// Constructors
cls_IGESBasic_ExternalRefFileIndex.def(py::init<>());

// Fields

// Methods
cls_IGESBasic_ExternalRefFileIndex.def("Init", (void (IGESBasic_ExternalRefFileIndex::*)(const opencascade::handle<Interface_HArray1OfHAsciiString> &, const opencascade::handle<IGESData_HArray1OfIGESEntity> &)) &IGESBasic_ExternalRefFileIndex::Init, "This method is used to set the fields of the class ExternalRefFileIndex - aNameArray : External Reference Entity symbolic names - allEntities : External Reference Entities raises exception if array lengths are not equal if size of aNameArray is not equal to size of allEntities", py::arg("aNameArray"), py::arg("allEntities"));
cls_IGESBasic_ExternalRefFileIndex.def("NbEntries", (Standard_Integer (IGESBasic_ExternalRefFileIndex::*)() const) &IGESBasic_ExternalRefFileIndex::NbEntries, "returns number of index entries");
cls_IGESBasic_ExternalRefFileIndex.def("Name", (opencascade::handle<TCollection_HAsciiString> (IGESBasic_ExternalRefFileIndex::*)(const Standard_Integer) const) &IGESBasic_ExternalRefFileIndex::Name, "returns the External Reference Entity symbolic name raises exception if Index <= 0 or Index > NbEntries()", py::arg("Index"));
cls_IGESBasic_ExternalRefFileIndex.def("Entity", (opencascade::handle<IGESData_IGESEntity> (IGESBasic_ExternalRefFileIndex::*)(const Standard_Integer) const) &IGESBasic_ExternalRefFileIndex::Entity, "returns the internal entity raises exception if Index <= 0 or Index > NbEntries()", py::arg("Index"));
cls_IGESBasic_ExternalRefFileIndex.def_static("get_type_name_", (const char * (*)()) &IGESBasic_ExternalRefFileIndex::get_type_name, "None");
cls_IGESBasic_ExternalRefFileIndex.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESBasic_ExternalRefFileIndex::get_type_descriptor, "None");
cls_IGESBasic_ExternalRefFileIndex.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESBasic_ExternalRefFileIndex::*)() const) &IGESBasic_ExternalRefFileIndex::DynamicType, "None");

// Enums

}