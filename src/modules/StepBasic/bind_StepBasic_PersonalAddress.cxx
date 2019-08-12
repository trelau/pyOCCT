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
#include <StepBasic_Address.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepBasic_HArray1OfPerson.hxx>
#include <StepBasic_Person.hxx>
#include <StepBasic_PersonalAddress.hxx>
#include <Standard_Type.hxx>

void bind_StepBasic_PersonalAddress(py::module &mod){

py::class_<StepBasic_PersonalAddress, opencascade::handle<StepBasic_PersonalAddress>, StepBasic_Address> cls_StepBasic_PersonalAddress(mod, "StepBasic_PersonalAddress", "None");

// Constructors
cls_StepBasic_PersonalAddress.def(py::init<>());

// Fields

// Methods
cls_StepBasic_PersonalAddress.def("Init", (void (StepBasic_PersonalAddress::*)(const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_HArray1OfPerson> &, const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_PersonalAddress::Init, "None", py::arg("hasAinternalLocation"), py::arg("aInternalLocation"), py::arg("hasAstreetNumber"), py::arg("aStreetNumber"), py::arg("hasAstreet"), py::arg("aStreet"), py::arg("hasApostalBox"), py::arg("aPostalBox"), py::arg("hasAtown"), py::arg("aTown"), py::arg("hasAregion"), py::arg("aRegion"), py::arg("hasApostalCode"), py::arg("aPostalCode"), py::arg("hasAcountry"), py::arg("aCountry"), py::arg("hasAfacsimileNumber"), py::arg("aFacsimileNumber"), py::arg("hasAtelephoneNumber"), py::arg("aTelephoneNumber"), py::arg("hasAelectronicMailAddress"), py::arg("aElectronicMailAddress"), py::arg("hasAtelexNumber"), py::arg("aTelexNumber"), py::arg("aPeople"), py::arg("aDescription"));
cls_StepBasic_PersonalAddress.def("SetPeople", (void (StepBasic_PersonalAddress::*)(const opencascade::handle<StepBasic_HArray1OfPerson> &)) &StepBasic_PersonalAddress::SetPeople, "None", py::arg("aPeople"));
cls_StepBasic_PersonalAddress.def("People", (opencascade::handle<StepBasic_HArray1OfPerson> (StepBasic_PersonalAddress::*)() const) &StepBasic_PersonalAddress::People, "None");
cls_StepBasic_PersonalAddress.def("PeopleValue", (opencascade::handle<StepBasic_Person> (StepBasic_PersonalAddress::*)(const Standard_Integer) const) &StepBasic_PersonalAddress::PeopleValue, "None", py::arg("num"));
cls_StepBasic_PersonalAddress.def("NbPeople", (Standard_Integer (StepBasic_PersonalAddress::*)() const) &StepBasic_PersonalAddress::NbPeople, "None");
cls_StepBasic_PersonalAddress.def("SetDescription", (void (StepBasic_PersonalAddress::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_PersonalAddress::SetDescription, "None", py::arg("aDescription"));
cls_StepBasic_PersonalAddress.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepBasic_PersonalAddress::*)() const) &StepBasic_PersonalAddress::Description, "None");
cls_StepBasic_PersonalAddress.def_static("get_type_name_", (const char * (*)()) &StepBasic_PersonalAddress::get_type_name, "None");
cls_StepBasic_PersonalAddress.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_PersonalAddress::get_type_descriptor, "None");
cls_StepBasic_PersonalAddress.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_PersonalAddress::*)() const) &StepBasic_PersonalAddress::DynamicType, "None");

// Enums

}