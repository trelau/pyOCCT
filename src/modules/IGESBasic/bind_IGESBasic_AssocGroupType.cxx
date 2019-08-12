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
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <IGESBasic_AssocGroupType.hxx>
#include <Standard_Type.hxx>

void bind_IGESBasic_AssocGroupType(py::module &mod){

py::class_<IGESBasic_AssocGroupType, opencascade::handle<IGESBasic_AssocGroupType>, IGESData_IGESEntity> cls_IGESBasic_AssocGroupType(mod, "IGESBasic_AssocGroupType", "defines AssocGroupType, Type <406> Form <23> in package IGESBasic Used to assign an unambiguous identification to a Group Associativity.");

// Constructors
cls_IGESBasic_AssocGroupType.def(py::init<>());

// Fields

// Methods
cls_IGESBasic_AssocGroupType.def("Init", (void (IGESBasic_AssocGroupType::*)(const Standard_Integer, const Standard_Integer, const opencascade::handle<TCollection_HAsciiString> &)) &IGESBasic_AssocGroupType::Init, "This method is used to set the fields of the class AssocGroupType - nbDataFields : number of parameter data fields = 2 - aType : type of attached associativity - aName : identifier of associativity of type AType", py::arg("nbDataFields"), py::arg("aType"), py::arg("aName"));
cls_IGESBasic_AssocGroupType.def("NbData", (Standard_Integer (IGESBasic_AssocGroupType::*)() const) &IGESBasic_AssocGroupType::NbData, "returns the number of parameter data fields, always = 2");
cls_IGESBasic_AssocGroupType.def("AssocType", (Standard_Integer (IGESBasic_AssocGroupType::*)() const) &IGESBasic_AssocGroupType::AssocType, "returns the type of attached associativity");
cls_IGESBasic_AssocGroupType.def("Name", (opencascade::handle<TCollection_HAsciiString> (IGESBasic_AssocGroupType::*)() const) &IGESBasic_AssocGroupType::Name, "returns identifier of instance of specified associativity");
cls_IGESBasic_AssocGroupType.def_static("get_type_name_", (const char * (*)()) &IGESBasic_AssocGroupType::get_type_name, "None");
cls_IGESBasic_AssocGroupType.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESBasic_AssocGroupType::get_type_descriptor, "None");
cls_IGESBasic_AssocGroupType.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESBasic_AssocGroupType::*)() const) &IGESBasic_AssocGroupType::DynamicType, "None");

// Enums

}