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
#include <StepBasic_HArray1OfOrganization.hxx>
#include <StepBasic_Organization.hxx>
#include <StepBasic_OrganizationalAddress.hxx>
#include <Standard_Type.hxx>

void bind_StepBasic_OrganizationalAddress(py::module &mod){

py::class_<StepBasic_OrganizationalAddress, opencascade::handle<StepBasic_OrganizationalAddress>, StepBasic_Address> cls_StepBasic_OrganizationalAddress(mod, "StepBasic_OrganizationalAddress", "None");

// Constructors
cls_StepBasic_OrganizationalAddress.def(py::init<>());

// Fields

// Methods
cls_StepBasic_OrganizationalAddress.def("Init", (void (StepBasic_OrganizationalAddress::*)(const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_HArray1OfOrganization> &, const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_OrganizationalAddress::Init, "None", py::arg("hasAinternalLocation"), py::arg("aInternalLocation"), py::arg("hasAstreetNumber"), py::arg("aStreetNumber"), py::arg("hasAstreet"), py::arg("aStreet"), py::arg("hasApostalBox"), py::arg("aPostalBox"), py::arg("hasAtown"), py::arg("aTown"), py::arg("hasAregion"), py::arg("aRegion"), py::arg("hasApostalCode"), py::arg("aPostalCode"), py::arg("hasAcountry"), py::arg("aCountry"), py::arg("hasAfacsimileNumber"), py::arg("aFacsimileNumber"), py::arg("hasAtelephoneNumber"), py::arg("aTelephoneNumber"), py::arg("hasAelectronicMailAddress"), py::arg("aElectronicMailAddress"), py::arg("hasAtelexNumber"), py::arg("aTelexNumber"), py::arg("aOrganizations"), py::arg("aDescription"));
cls_StepBasic_OrganizationalAddress.def("SetOrganizations", (void (StepBasic_OrganizationalAddress::*)(const opencascade::handle<StepBasic_HArray1OfOrganization> &)) &StepBasic_OrganizationalAddress::SetOrganizations, "None", py::arg("aOrganizations"));
cls_StepBasic_OrganizationalAddress.def("Organizations", (opencascade::handle<StepBasic_HArray1OfOrganization> (StepBasic_OrganizationalAddress::*)() const) &StepBasic_OrganizationalAddress::Organizations, "None");
cls_StepBasic_OrganizationalAddress.def("OrganizationsValue", (opencascade::handle<StepBasic_Organization> (StepBasic_OrganizationalAddress::*)(const Standard_Integer) const) &StepBasic_OrganizationalAddress::OrganizationsValue, "None", py::arg("num"));
cls_StepBasic_OrganizationalAddress.def("NbOrganizations", (Standard_Integer (StepBasic_OrganizationalAddress::*)() const) &StepBasic_OrganizationalAddress::NbOrganizations, "None");
cls_StepBasic_OrganizationalAddress.def("SetDescription", (void (StepBasic_OrganizationalAddress::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_OrganizationalAddress::SetDescription, "None", py::arg("aDescription"));
cls_StepBasic_OrganizationalAddress.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepBasic_OrganizationalAddress::*)() const) &StepBasic_OrganizationalAddress::Description, "None");
cls_StepBasic_OrganizationalAddress.def_static("get_type_name_", (const char * (*)()) &StepBasic_OrganizationalAddress::get_type_name, "None");
cls_StepBasic_OrganizationalAddress.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_OrganizationalAddress::get_type_descriptor, "None");
cls_StepBasic_OrganizationalAddress.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_OrganizationalAddress::*)() const) &StepBasic_OrganizationalAddress::DynamicType, "None");

// Enums

}