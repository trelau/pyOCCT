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
#include <IGESBasic_ExternalRefLibName.hxx>
#include <Standard_Type.hxx>

void bind_IGESBasic_ExternalRefLibName(py::module &mod){

py::class_<IGESBasic_ExternalRefLibName, opencascade::handle<IGESBasic_ExternalRefLibName>, IGESData_IGESEntity> cls_IGESBasic_ExternalRefLibName(mod, "IGESBasic_ExternalRefLibName", "defines ExternalRefLibName, Type <416> Form <4> in package IGESBasic Used when it is assumed that a copy of the subfigure exists in native form in a library on the receiving system");

// Constructors
cls_IGESBasic_ExternalRefLibName.def(py::init<>());

// Fields

// Methods
cls_IGESBasic_ExternalRefLibName.def("Init", (void (IGESBasic_ExternalRefLibName::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &)) &IGESBasic_ExternalRefLibName::Init, "This method is used to set the fields of the class ExternalRefLibName - aLibName : Name of library in which ExtName resides - anExtName : External Reference Entity Symbolic Name", py::arg("aLibName"), py::arg("anExtName"));
cls_IGESBasic_ExternalRefLibName.def("LibraryName", (opencascade::handle<TCollection_HAsciiString> (IGESBasic_ExternalRefLibName::*)() const) &IGESBasic_ExternalRefLibName::LibraryName, "returns name of library in which External Reference Entity Symbolic Name resides");
cls_IGESBasic_ExternalRefLibName.def("ReferenceName", (opencascade::handle<TCollection_HAsciiString> (IGESBasic_ExternalRefLibName::*)() const) &IGESBasic_ExternalRefLibName::ReferenceName, "returns External Reference Entity Symbolic Name");
cls_IGESBasic_ExternalRefLibName.def_static("get_type_name_", (const char * (*)()) &IGESBasic_ExternalRefLibName::get_type_name, "None");
cls_IGESBasic_ExternalRefLibName.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESBasic_ExternalRefLibName::get_type_descriptor, "None");
cls_IGESBasic_ExternalRefLibName.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESBasic_ExternalRefLibName::*)() const) &IGESBasic_ExternalRefLibName::DynamicType, "None");

// Enums

}