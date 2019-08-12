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
#include <IGESAppli_PinNumber.hxx>
#include <Standard_Type.hxx>

void bind_IGESAppli_PinNumber(py::module &mod){

py::class_<IGESAppli_PinNumber, opencascade::handle<IGESAppli_PinNumber>, IGESData_IGESEntity> cls_IGESAppli_PinNumber(mod, "IGESAppli_PinNumber", "defines PinNumber, Type <406> Form <8> in package IGESAppli Used to attach a text string representing a component pin number to an entity being used to represent an electrical component's pin");

// Constructors
cls_IGESAppli_PinNumber.def(py::init<>());

// Fields

// Methods
cls_IGESAppli_PinNumber.def("Init", (void (IGESAppli_PinNumber::*)(const Standard_Integer, const opencascade::handle<TCollection_HAsciiString> &)) &IGESAppli_PinNumber::Init, "This method is used to set the fields of the class PinNumber - nbPropVal : Number of property values (always = 1) - aValue : Pin Number value", py::arg("nbPropVal"), py::arg("aValue"));
cls_IGESAppli_PinNumber.def("NbPropertyValues", (Standard_Integer (IGESAppli_PinNumber::*)() const) &IGESAppli_PinNumber::NbPropertyValues, "returns the number of property values is always 1");
cls_IGESAppli_PinNumber.def("PinNumberVal", (opencascade::handle<TCollection_HAsciiString> (IGESAppli_PinNumber::*)() const) &IGESAppli_PinNumber::PinNumberVal, "returns the pin number value");
cls_IGESAppli_PinNumber.def_static("get_type_name_", (const char * (*)()) &IGESAppli_PinNumber::get_type_name, "None");
cls_IGESAppli_PinNumber.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESAppli_PinNumber::get_type_descriptor, "None");
cls_IGESAppli_PinNumber.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESAppli_PinNumber::*)() const) &IGESAppli_PinNumber::DynamicType, "None");

// Enums

}