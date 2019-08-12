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
#include <Standard_Transient.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepBasic_Address.hxx>
#include <Standard_Type.hxx>

void bind_StepBasic_Address(py::module &mod){

py::class_<StepBasic_Address, opencascade::handle<StepBasic_Address>, Standard_Transient> cls_StepBasic_Address(mod, "StepBasic_Address", "None");

// Constructors
cls_StepBasic_Address.def(py::init<>());

// Fields

// Methods
cls_StepBasic_Address.def("Init", (void (StepBasic_Address::*)(const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_Address::Init, "None", py::arg("hasAinternalLocation"), py::arg("aInternalLocation"), py::arg("hasAstreetNumber"), py::arg("aStreetNumber"), py::arg("hasAstreet"), py::arg("aStreet"), py::arg("hasApostalBox"), py::arg("aPostalBox"), py::arg("hasAtown"), py::arg("aTown"), py::arg("hasAregion"), py::arg("aRegion"), py::arg("hasApostalCode"), py::arg("aPostalCode"), py::arg("hasAcountry"), py::arg("aCountry"), py::arg("hasAfacsimileNumber"), py::arg("aFacsimileNumber"), py::arg("hasAtelephoneNumber"), py::arg("aTelephoneNumber"), py::arg("hasAelectronicMailAddress"), py::arg("aElectronicMailAddress"), py::arg("hasAtelexNumber"), py::arg("aTelexNumber"));
cls_StepBasic_Address.def("SetInternalLocation", (void (StepBasic_Address::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_Address::SetInternalLocation, "None", py::arg("aInternalLocation"));
cls_StepBasic_Address.def("UnSetInternalLocation", (void (StepBasic_Address::*)()) &StepBasic_Address::UnSetInternalLocation, "None");
cls_StepBasic_Address.def("InternalLocation", (opencascade::handle<TCollection_HAsciiString> (StepBasic_Address::*)() const) &StepBasic_Address::InternalLocation, "None");
cls_StepBasic_Address.def("HasInternalLocation", (Standard_Boolean (StepBasic_Address::*)() const) &StepBasic_Address::HasInternalLocation, "None");
cls_StepBasic_Address.def("SetStreetNumber", (void (StepBasic_Address::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_Address::SetStreetNumber, "None", py::arg("aStreetNumber"));
cls_StepBasic_Address.def("UnSetStreetNumber", (void (StepBasic_Address::*)()) &StepBasic_Address::UnSetStreetNumber, "None");
cls_StepBasic_Address.def("StreetNumber", (opencascade::handle<TCollection_HAsciiString> (StepBasic_Address::*)() const) &StepBasic_Address::StreetNumber, "None");
cls_StepBasic_Address.def("HasStreetNumber", (Standard_Boolean (StepBasic_Address::*)() const) &StepBasic_Address::HasStreetNumber, "None");
cls_StepBasic_Address.def("SetStreet", (void (StepBasic_Address::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_Address::SetStreet, "None", py::arg("aStreet"));
cls_StepBasic_Address.def("UnSetStreet", (void (StepBasic_Address::*)()) &StepBasic_Address::UnSetStreet, "None");
cls_StepBasic_Address.def("Street", (opencascade::handle<TCollection_HAsciiString> (StepBasic_Address::*)() const) &StepBasic_Address::Street, "None");
cls_StepBasic_Address.def("HasStreet", (Standard_Boolean (StepBasic_Address::*)() const) &StepBasic_Address::HasStreet, "None");
cls_StepBasic_Address.def("SetPostalBox", (void (StepBasic_Address::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_Address::SetPostalBox, "None", py::arg("aPostalBox"));
cls_StepBasic_Address.def("UnSetPostalBox", (void (StepBasic_Address::*)()) &StepBasic_Address::UnSetPostalBox, "None");
cls_StepBasic_Address.def("PostalBox", (opencascade::handle<TCollection_HAsciiString> (StepBasic_Address::*)() const) &StepBasic_Address::PostalBox, "None");
cls_StepBasic_Address.def("HasPostalBox", (Standard_Boolean (StepBasic_Address::*)() const) &StepBasic_Address::HasPostalBox, "None");
cls_StepBasic_Address.def("SetTown", (void (StepBasic_Address::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_Address::SetTown, "None", py::arg("aTown"));
cls_StepBasic_Address.def("UnSetTown", (void (StepBasic_Address::*)()) &StepBasic_Address::UnSetTown, "None");
cls_StepBasic_Address.def("Town", (opencascade::handle<TCollection_HAsciiString> (StepBasic_Address::*)() const) &StepBasic_Address::Town, "None");
cls_StepBasic_Address.def("HasTown", (Standard_Boolean (StepBasic_Address::*)() const) &StepBasic_Address::HasTown, "None");
cls_StepBasic_Address.def("SetRegion", (void (StepBasic_Address::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_Address::SetRegion, "None", py::arg("aRegion"));
cls_StepBasic_Address.def("UnSetRegion", (void (StepBasic_Address::*)()) &StepBasic_Address::UnSetRegion, "None");
cls_StepBasic_Address.def("Region", (opencascade::handle<TCollection_HAsciiString> (StepBasic_Address::*)() const) &StepBasic_Address::Region, "None");
cls_StepBasic_Address.def("HasRegion", (Standard_Boolean (StepBasic_Address::*)() const) &StepBasic_Address::HasRegion, "None");
cls_StepBasic_Address.def("SetPostalCode", (void (StepBasic_Address::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_Address::SetPostalCode, "None", py::arg("aPostalCode"));
cls_StepBasic_Address.def("UnSetPostalCode", (void (StepBasic_Address::*)()) &StepBasic_Address::UnSetPostalCode, "None");
cls_StepBasic_Address.def("PostalCode", (opencascade::handle<TCollection_HAsciiString> (StepBasic_Address::*)() const) &StepBasic_Address::PostalCode, "None");
cls_StepBasic_Address.def("HasPostalCode", (Standard_Boolean (StepBasic_Address::*)() const) &StepBasic_Address::HasPostalCode, "None");
cls_StepBasic_Address.def("SetCountry", (void (StepBasic_Address::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_Address::SetCountry, "None", py::arg("aCountry"));
cls_StepBasic_Address.def("UnSetCountry", (void (StepBasic_Address::*)()) &StepBasic_Address::UnSetCountry, "None");
cls_StepBasic_Address.def("Country", (opencascade::handle<TCollection_HAsciiString> (StepBasic_Address::*)() const) &StepBasic_Address::Country, "None");
cls_StepBasic_Address.def("HasCountry", (Standard_Boolean (StepBasic_Address::*)() const) &StepBasic_Address::HasCountry, "None");
cls_StepBasic_Address.def("SetFacsimileNumber", (void (StepBasic_Address::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_Address::SetFacsimileNumber, "None", py::arg("aFacsimileNumber"));
cls_StepBasic_Address.def("UnSetFacsimileNumber", (void (StepBasic_Address::*)()) &StepBasic_Address::UnSetFacsimileNumber, "None");
cls_StepBasic_Address.def("FacsimileNumber", (opencascade::handle<TCollection_HAsciiString> (StepBasic_Address::*)() const) &StepBasic_Address::FacsimileNumber, "None");
cls_StepBasic_Address.def("HasFacsimileNumber", (Standard_Boolean (StepBasic_Address::*)() const) &StepBasic_Address::HasFacsimileNumber, "None");
cls_StepBasic_Address.def("SetTelephoneNumber", (void (StepBasic_Address::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_Address::SetTelephoneNumber, "None", py::arg("aTelephoneNumber"));
cls_StepBasic_Address.def("UnSetTelephoneNumber", (void (StepBasic_Address::*)()) &StepBasic_Address::UnSetTelephoneNumber, "None");
cls_StepBasic_Address.def("TelephoneNumber", (opencascade::handle<TCollection_HAsciiString> (StepBasic_Address::*)() const) &StepBasic_Address::TelephoneNumber, "None");
cls_StepBasic_Address.def("HasTelephoneNumber", (Standard_Boolean (StepBasic_Address::*)() const) &StepBasic_Address::HasTelephoneNumber, "None");
cls_StepBasic_Address.def("SetElectronicMailAddress", (void (StepBasic_Address::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_Address::SetElectronicMailAddress, "None", py::arg("aElectronicMailAddress"));
cls_StepBasic_Address.def("UnSetElectronicMailAddress", (void (StepBasic_Address::*)()) &StepBasic_Address::UnSetElectronicMailAddress, "None");
cls_StepBasic_Address.def("ElectronicMailAddress", (opencascade::handle<TCollection_HAsciiString> (StepBasic_Address::*)() const) &StepBasic_Address::ElectronicMailAddress, "None");
cls_StepBasic_Address.def("HasElectronicMailAddress", (Standard_Boolean (StepBasic_Address::*)() const) &StepBasic_Address::HasElectronicMailAddress, "None");
cls_StepBasic_Address.def("SetTelexNumber", (void (StepBasic_Address::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_Address::SetTelexNumber, "None", py::arg("aTelexNumber"));
cls_StepBasic_Address.def("UnSetTelexNumber", (void (StepBasic_Address::*)()) &StepBasic_Address::UnSetTelexNumber, "None");
cls_StepBasic_Address.def("TelexNumber", (opencascade::handle<TCollection_HAsciiString> (StepBasic_Address::*)() const) &StepBasic_Address::TelexNumber, "None");
cls_StepBasic_Address.def("HasTelexNumber", (Standard_Boolean (StepBasic_Address::*)() const) &StepBasic_Address::HasTelexNumber, "None");
cls_StepBasic_Address.def_static("get_type_name_", (const char * (*)()) &StepBasic_Address::get_type_name, "None");
cls_StepBasic_Address.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_Address::get_type_descriptor, "None");
cls_StepBasic_Address.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_Address::*)() const) &StepBasic_Address::DynamicType, "None");

// Enums

}