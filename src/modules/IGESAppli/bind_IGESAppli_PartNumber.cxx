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
#include <IGESAppli_PartNumber.hxx>
#include <Standard_Type.hxx>

void bind_IGESAppli_PartNumber(py::module &mod){

py::class_<IGESAppli_PartNumber, opencascade::handle<IGESAppli_PartNumber>, IGESData_IGESEntity> cls_IGESAppli_PartNumber(mod, "IGESAppli_PartNumber", "defines PartNumber, Type <406> Form <9> in package IGESAppli Attaches a set of text strings that define the common part numbers to an entity being used to represent a physical component");

// Constructors
cls_IGESAppli_PartNumber.def(py::init<>());

// Fields

// Methods
cls_IGESAppli_PartNumber.def("Init", (void (IGESAppli_PartNumber::*)(const Standard_Integer, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &)) &IGESAppli_PartNumber::Init, "This method is used to set the fields of the class PartNumber - nbPropVal : number of property values, always = 4 - aGenName : Generic part number or name - aMilName : Military Standard (MIL-STD) part number - aVendName : Vendor part number or name - anIntName : Internal part number", py::arg("nbPropVal"), py::arg("aGenName"), py::arg("aMilName"), py::arg("aVendName"), py::arg("anIntName"));
cls_IGESAppli_PartNumber.def("NbPropertyValues", (Standard_Integer (IGESAppli_PartNumber::*)() const) &IGESAppli_PartNumber::NbPropertyValues, "returns number of property values, always = 4");
cls_IGESAppli_PartNumber.def("GenericNumber", (opencascade::handle<TCollection_HAsciiString> (IGESAppli_PartNumber::*)() const) &IGESAppli_PartNumber::GenericNumber, "returns Generic part number or name");
cls_IGESAppli_PartNumber.def("MilitaryNumber", (opencascade::handle<TCollection_HAsciiString> (IGESAppli_PartNumber::*)() const) &IGESAppli_PartNumber::MilitaryNumber, "returns Military Standard (MIL-STD) part number");
cls_IGESAppli_PartNumber.def("VendorNumber", (opencascade::handle<TCollection_HAsciiString> (IGESAppli_PartNumber::*)() const) &IGESAppli_PartNumber::VendorNumber, "returns Vendor part number or name");
cls_IGESAppli_PartNumber.def("InternalNumber", (opencascade::handle<TCollection_HAsciiString> (IGESAppli_PartNumber::*)() const) &IGESAppli_PartNumber::InternalNumber, "returns Internal part number");
cls_IGESAppli_PartNumber.def_static("get_type_name_", (const char * (*)()) &IGESAppli_PartNumber::get_type_name, "None");
cls_IGESAppli_PartNumber.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESAppli_PartNumber::get_type_descriptor, "None");
cls_IGESAppli_PartNumber.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESAppli_PartNumber::*)() const) &IGESAppli_PartNumber::DynamicType, "None");

// Enums

}