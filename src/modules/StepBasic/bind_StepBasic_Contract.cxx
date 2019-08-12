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
#include <StepBasic_ContractType.hxx>
#include <StepBasic_Contract.hxx>
#include <Standard_Type.hxx>

void bind_StepBasic_Contract(py::module &mod){

py::class_<StepBasic_Contract, opencascade::handle<StepBasic_Contract>, Standard_Transient> cls_StepBasic_Contract(mod, "StepBasic_Contract", "Representation of STEP entity Contract");

// Constructors
cls_StepBasic_Contract.def(py::init<>());

// Fields

// Methods
cls_StepBasic_Contract.def("Init", (void (StepBasic_Contract::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_ContractType> &)) &StepBasic_Contract::Init, "Initialize all fields (own and inherited)", py::arg("aName"), py::arg("aPurpose"), py::arg("aKind"));
cls_StepBasic_Contract.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepBasic_Contract::*)() const) &StepBasic_Contract::Name, "Returns field Name");
cls_StepBasic_Contract.def("SetName", (void (StepBasic_Contract::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_Contract::SetName, "Set field Name", py::arg("Name"));
cls_StepBasic_Contract.def("Purpose", (opencascade::handle<TCollection_HAsciiString> (StepBasic_Contract::*)() const) &StepBasic_Contract::Purpose, "Returns field Purpose");
cls_StepBasic_Contract.def("SetPurpose", (void (StepBasic_Contract::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_Contract::SetPurpose, "Set field Purpose", py::arg("Purpose"));
cls_StepBasic_Contract.def("Kind", (opencascade::handle<StepBasic_ContractType> (StepBasic_Contract::*)() const) &StepBasic_Contract::Kind, "Returns field Kind");
cls_StepBasic_Contract.def("SetKind", (void (StepBasic_Contract::*)(const opencascade::handle<StepBasic_ContractType> &)) &StepBasic_Contract::SetKind, "Set field Kind", py::arg("Kind"));
cls_StepBasic_Contract.def_static("get_type_name_", (const char * (*)()) &StepBasic_Contract::get_type_name, "None");
cls_StepBasic_Contract.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_Contract::get_type_descriptor, "None");
cls_StepBasic_Contract.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_Contract::*)() const) &StepBasic_Contract::DynamicType, "None");

// Enums

}