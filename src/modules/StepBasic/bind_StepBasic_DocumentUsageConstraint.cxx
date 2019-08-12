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
#include <StepBasic_Document.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepBasic_DocumentUsageConstraint.hxx>
#include <Standard_Type.hxx>

void bind_StepBasic_DocumentUsageConstraint(py::module &mod){

py::class_<StepBasic_DocumentUsageConstraint, opencascade::handle<StepBasic_DocumentUsageConstraint>, Standard_Transient> cls_StepBasic_DocumentUsageConstraint(mod, "StepBasic_DocumentUsageConstraint", "None");

// Constructors
cls_StepBasic_DocumentUsageConstraint.def(py::init<>());

// Fields

// Methods
cls_StepBasic_DocumentUsageConstraint.def("Init", (void (StepBasic_DocumentUsageConstraint::*)(const opencascade::handle<StepBasic_Document> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_DocumentUsageConstraint::Init, "None", py::arg("aSource"), py::arg("ase"), py::arg("asev"));
cls_StepBasic_DocumentUsageConstraint.def("Source", (opencascade::handle<StepBasic_Document> (StepBasic_DocumentUsageConstraint::*)() const) &StepBasic_DocumentUsageConstraint::Source, "None");
cls_StepBasic_DocumentUsageConstraint.def("SetSource", (void (StepBasic_DocumentUsageConstraint::*)(const opencascade::handle<StepBasic_Document> &)) &StepBasic_DocumentUsageConstraint::SetSource, "None", py::arg("aSource"));
cls_StepBasic_DocumentUsageConstraint.def("SubjectElement", (opencascade::handle<TCollection_HAsciiString> (StepBasic_DocumentUsageConstraint::*)() const) &StepBasic_DocumentUsageConstraint::SubjectElement, "None");
cls_StepBasic_DocumentUsageConstraint.def("SetSubjectElement", (void (StepBasic_DocumentUsageConstraint::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_DocumentUsageConstraint::SetSubjectElement, "None", py::arg("ase"));
cls_StepBasic_DocumentUsageConstraint.def("SubjectElementValue", (opencascade::handle<TCollection_HAsciiString> (StepBasic_DocumentUsageConstraint::*)() const) &StepBasic_DocumentUsageConstraint::SubjectElementValue, "None");
cls_StepBasic_DocumentUsageConstraint.def("SetSubjectElementValue", (void (StepBasic_DocumentUsageConstraint::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_DocumentUsageConstraint::SetSubjectElementValue, "None", py::arg("asev"));
cls_StepBasic_DocumentUsageConstraint.def_static("get_type_name_", (const char * (*)()) &StepBasic_DocumentUsageConstraint::get_type_name, "None");
cls_StepBasic_DocumentUsageConstraint.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_DocumentUsageConstraint::get_type_descriptor, "None");
cls_StepBasic_DocumentUsageConstraint.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_DocumentUsageConstraint::*)() const) &StepBasic_DocumentUsageConstraint::DynamicType, "None");

// Enums

}