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
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <Standard_TypeDef.hxx>
#include <Interface_HArray1OfHAsciiString.hxx>
#include <StepBasic_Person.hxx>
#include <Standard_Type.hxx>

void bind_StepBasic_Person(py::module &mod){

py::class_<StepBasic_Person, opencascade::handle<StepBasic_Person>, Standard_Transient> cls_StepBasic_Person(mod, "StepBasic_Person", "None");

// Constructors
cls_StepBasic_Person.def(py::init<>());

// Fields

// Methods
cls_StepBasic_Person.def("Init", (void (StepBasic_Person::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<Interface_HArray1OfHAsciiString> &, const Standard_Boolean, const opencascade::handle<Interface_HArray1OfHAsciiString> &, const Standard_Boolean, const opencascade::handle<Interface_HArray1OfHAsciiString> &)) &StepBasic_Person::Init, "None", py::arg("aId"), py::arg("hasAlastName"), py::arg("aLastName"), py::arg("hasAfirstName"), py::arg("aFirstName"), py::arg("hasAmiddleNames"), py::arg("aMiddleNames"), py::arg("hasAprefixTitles"), py::arg("aPrefixTitles"), py::arg("hasAsuffixTitles"), py::arg("aSuffixTitles"));
cls_StepBasic_Person.def("SetId", (void (StepBasic_Person::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_Person::SetId, "None", py::arg("aId"));
cls_StepBasic_Person.def("Id", (opencascade::handle<TCollection_HAsciiString> (StepBasic_Person::*)() const) &StepBasic_Person::Id, "None");
cls_StepBasic_Person.def("SetLastName", (void (StepBasic_Person::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_Person::SetLastName, "None", py::arg("aLastName"));
cls_StepBasic_Person.def("UnSetLastName", (void (StepBasic_Person::*)()) &StepBasic_Person::UnSetLastName, "None");
cls_StepBasic_Person.def("LastName", (opencascade::handle<TCollection_HAsciiString> (StepBasic_Person::*)() const) &StepBasic_Person::LastName, "None");
cls_StepBasic_Person.def("HasLastName", (Standard_Boolean (StepBasic_Person::*)() const) &StepBasic_Person::HasLastName, "None");
cls_StepBasic_Person.def("SetFirstName", (void (StepBasic_Person::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_Person::SetFirstName, "None", py::arg("aFirstName"));
cls_StepBasic_Person.def("UnSetFirstName", (void (StepBasic_Person::*)()) &StepBasic_Person::UnSetFirstName, "None");
cls_StepBasic_Person.def("FirstName", (opencascade::handle<TCollection_HAsciiString> (StepBasic_Person::*)() const) &StepBasic_Person::FirstName, "None");
cls_StepBasic_Person.def("HasFirstName", (Standard_Boolean (StepBasic_Person::*)() const) &StepBasic_Person::HasFirstName, "None");
cls_StepBasic_Person.def("SetMiddleNames", (void (StepBasic_Person::*)(const opencascade::handle<Interface_HArray1OfHAsciiString> &)) &StepBasic_Person::SetMiddleNames, "None", py::arg("aMiddleNames"));
cls_StepBasic_Person.def("UnSetMiddleNames", (void (StepBasic_Person::*)()) &StepBasic_Person::UnSetMiddleNames, "None");
cls_StepBasic_Person.def("MiddleNames", (opencascade::handle<Interface_HArray1OfHAsciiString> (StepBasic_Person::*)() const) &StepBasic_Person::MiddleNames, "None");
cls_StepBasic_Person.def("HasMiddleNames", (Standard_Boolean (StepBasic_Person::*)() const) &StepBasic_Person::HasMiddleNames, "None");
cls_StepBasic_Person.def("MiddleNamesValue", (opencascade::handle<TCollection_HAsciiString> (StepBasic_Person::*)(const Standard_Integer) const) &StepBasic_Person::MiddleNamesValue, "None", py::arg("num"));
cls_StepBasic_Person.def("NbMiddleNames", (Standard_Integer (StepBasic_Person::*)() const) &StepBasic_Person::NbMiddleNames, "None");
cls_StepBasic_Person.def("SetPrefixTitles", (void (StepBasic_Person::*)(const opencascade::handle<Interface_HArray1OfHAsciiString> &)) &StepBasic_Person::SetPrefixTitles, "None", py::arg("aPrefixTitles"));
cls_StepBasic_Person.def("UnSetPrefixTitles", (void (StepBasic_Person::*)()) &StepBasic_Person::UnSetPrefixTitles, "None");
cls_StepBasic_Person.def("PrefixTitles", (opencascade::handle<Interface_HArray1OfHAsciiString> (StepBasic_Person::*)() const) &StepBasic_Person::PrefixTitles, "None");
cls_StepBasic_Person.def("HasPrefixTitles", (Standard_Boolean (StepBasic_Person::*)() const) &StepBasic_Person::HasPrefixTitles, "None");
cls_StepBasic_Person.def("PrefixTitlesValue", (opencascade::handle<TCollection_HAsciiString> (StepBasic_Person::*)(const Standard_Integer) const) &StepBasic_Person::PrefixTitlesValue, "None", py::arg("num"));
cls_StepBasic_Person.def("NbPrefixTitles", (Standard_Integer (StepBasic_Person::*)() const) &StepBasic_Person::NbPrefixTitles, "None");
cls_StepBasic_Person.def("SetSuffixTitles", (void (StepBasic_Person::*)(const opencascade::handle<Interface_HArray1OfHAsciiString> &)) &StepBasic_Person::SetSuffixTitles, "None", py::arg("aSuffixTitles"));
cls_StepBasic_Person.def("UnSetSuffixTitles", (void (StepBasic_Person::*)()) &StepBasic_Person::UnSetSuffixTitles, "None");
cls_StepBasic_Person.def("SuffixTitles", (opencascade::handle<Interface_HArray1OfHAsciiString> (StepBasic_Person::*)() const) &StepBasic_Person::SuffixTitles, "None");
cls_StepBasic_Person.def("HasSuffixTitles", (Standard_Boolean (StepBasic_Person::*)() const) &StepBasic_Person::HasSuffixTitles, "None");
cls_StepBasic_Person.def("SuffixTitlesValue", (opencascade::handle<TCollection_HAsciiString> (StepBasic_Person::*)(const Standard_Integer) const) &StepBasic_Person::SuffixTitlesValue, "None", py::arg("num"));
cls_StepBasic_Person.def("NbSuffixTitles", (Standard_Integer (StepBasic_Person::*)() const) &StepBasic_Person::NbSuffixTitles, "None");
cls_StepBasic_Person.def_static("get_type_name_", (const char * (*)()) &StepBasic_Person::get_type_name, "None");
cls_StepBasic_Person.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_Person::get_type_descriptor, "None");
cls_StepBasic_Person.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_Person::*)() const) &StepBasic_Person::DynamicType, "None");

// Enums

}