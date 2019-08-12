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
#include <StepRepr_HArray1OfPropertyDefinitionRepresentation.hxx>
#include <StepRepr_DataEnvironment.hxx>
#include <Standard_Type.hxx>

void bind_StepRepr_DataEnvironment(py::module &mod){

py::class_<StepRepr_DataEnvironment, opencascade::handle<StepRepr_DataEnvironment>, Standard_Transient> cls_StepRepr_DataEnvironment(mod, "StepRepr_DataEnvironment", "Representation of STEP entity DataEnvironment");

// Constructors
cls_StepRepr_DataEnvironment.def(py::init<>());

// Fields

// Methods
cls_StepRepr_DataEnvironment.def("Init", (void (StepRepr_DataEnvironment::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepRepr_HArray1OfPropertyDefinitionRepresentation> &)) &StepRepr_DataEnvironment::Init, "Initialize all fields (own and inherited)", py::arg("aName"), py::arg("aDescription"), py::arg("aElements"));
cls_StepRepr_DataEnvironment.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepRepr_DataEnvironment::*)() const) &StepRepr_DataEnvironment::Name, "Returns field Name");
cls_StepRepr_DataEnvironment.def("SetName", (void (StepRepr_DataEnvironment::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepRepr_DataEnvironment::SetName, "Set field Name", py::arg("Name"));
cls_StepRepr_DataEnvironment.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepRepr_DataEnvironment::*)() const) &StepRepr_DataEnvironment::Description, "Returns field Description");
cls_StepRepr_DataEnvironment.def("SetDescription", (void (StepRepr_DataEnvironment::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepRepr_DataEnvironment::SetDescription, "Set field Description", py::arg("Description"));
cls_StepRepr_DataEnvironment.def("Elements", (opencascade::handle<StepRepr_HArray1OfPropertyDefinitionRepresentation> (StepRepr_DataEnvironment::*)() const) &StepRepr_DataEnvironment::Elements, "Returns field Elements");
cls_StepRepr_DataEnvironment.def("SetElements", (void (StepRepr_DataEnvironment::*)(const opencascade::handle<StepRepr_HArray1OfPropertyDefinitionRepresentation> &)) &StepRepr_DataEnvironment::SetElements, "Set field Elements", py::arg("Elements"));
cls_StepRepr_DataEnvironment.def_static("get_type_name_", (const char * (*)()) &StepRepr_DataEnvironment::get_type_name, "None");
cls_StepRepr_DataEnvironment.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_DataEnvironment::get_type_descriptor, "None");
cls_StepRepr_DataEnvironment.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_DataEnvironment::*)() const) &StepRepr_DataEnvironment::DynamicType, "None");

// Enums

}