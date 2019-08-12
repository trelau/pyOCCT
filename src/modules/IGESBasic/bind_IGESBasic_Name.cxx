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
#include <IGESData_NameEntity.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <IGESBasic_Name.hxx>
#include <Standard_Type.hxx>

void bind_IGESBasic_Name(py::module &mod){

py::class_<IGESBasic_Name, opencascade::handle<IGESBasic_Name>, IGESData_NameEntity> cls_IGESBasic_Name(mod, "IGESBasic_Name", "defines Name, Type <406> Form <15> in package IGESBasic Used to specify a user defined name");

// Constructors
cls_IGESBasic_Name.def(py::init<>());

// Fields

// Methods
cls_IGESBasic_Name.def("Init", (void (IGESBasic_Name::*)(const Standard_Integer, const opencascade::handle<TCollection_HAsciiString> &)) &IGESBasic_Name::Init, "This method is used to set the fields of the class Name - nbPropVal : Number of property values, always = 1 - aName : Stores the Name", py::arg("nbPropVal"), py::arg("aName"));
cls_IGESBasic_Name.def("NbPropertyValues", (Standard_Integer (IGESBasic_Name::*)() const) &IGESBasic_Name::NbPropertyValues, "returns the number of property values, which should be 1");
cls_IGESBasic_Name.def("Value", (opencascade::handle<TCollection_HAsciiString> (IGESBasic_Name::*)() const) &IGESBasic_Name::Value, "returns the user defined Name");
cls_IGESBasic_Name.def_static("get_type_name_", (const char * (*)()) &IGESBasic_Name::get_type_name, "None");
cls_IGESBasic_Name.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESBasic_Name::get_type_descriptor, "None");
cls_IGESBasic_Name.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESBasic_Name::*)() const) &IGESBasic_Name::DynamicType, "None");

// Enums

}