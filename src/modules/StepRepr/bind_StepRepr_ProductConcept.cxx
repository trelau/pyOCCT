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
#include <StepBasic_ProductConceptContext.hxx>
#include <StepRepr_ProductConcept.hxx>
#include <Standard_Type.hxx>

void bind_StepRepr_ProductConcept(py::module &mod){

py::class_<StepRepr_ProductConcept, opencascade::handle<StepRepr_ProductConcept>, Standard_Transient> cls_StepRepr_ProductConcept(mod, "StepRepr_ProductConcept", "Representation of STEP entity ProductConcept");

// Constructors
cls_StepRepr_ProductConcept.def(py::init<>());

// Fields

// Methods
cls_StepRepr_ProductConcept.def("Init", (void (StepRepr_ProductConcept::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_ProductConceptContext> &)) &StepRepr_ProductConcept::Init, "Initialize all fields (own and inherited)", py::arg("aId"), py::arg("aName"), py::arg("hasDescription"), py::arg("aDescription"), py::arg("aMarketContext"));
cls_StepRepr_ProductConcept.def("Id", (opencascade::handle<TCollection_HAsciiString> (StepRepr_ProductConcept::*)() const) &StepRepr_ProductConcept::Id, "Returns field Id");
cls_StepRepr_ProductConcept.def("SetId", (void (StepRepr_ProductConcept::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepRepr_ProductConcept::SetId, "Set field Id", py::arg("Id"));
cls_StepRepr_ProductConcept.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepRepr_ProductConcept::*)() const) &StepRepr_ProductConcept::Name, "Returns field Name");
cls_StepRepr_ProductConcept.def("SetName", (void (StepRepr_ProductConcept::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepRepr_ProductConcept::SetName, "Set field Name", py::arg("Name"));
cls_StepRepr_ProductConcept.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepRepr_ProductConcept::*)() const) &StepRepr_ProductConcept::Description, "Returns field Description");
cls_StepRepr_ProductConcept.def("SetDescription", (void (StepRepr_ProductConcept::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepRepr_ProductConcept::SetDescription, "Set field Description", py::arg("Description"));
cls_StepRepr_ProductConcept.def("HasDescription", (Standard_Boolean (StepRepr_ProductConcept::*)() const) &StepRepr_ProductConcept::HasDescription, "Returns True if optional field Description is defined");
cls_StepRepr_ProductConcept.def("MarketContext", (opencascade::handle<StepBasic_ProductConceptContext> (StepRepr_ProductConcept::*)() const) &StepRepr_ProductConcept::MarketContext, "Returns field MarketContext");
cls_StepRepr_ProductConcept.def("SetMarketContext", (void (StepRepr_ProductConcept::*)(const opencascade::handle<StepBasic_ProductConceptContext> &)) &StepRepr_ProductConcept::SetMarketContext, "Set field MarketContext", py::arg("MarketContext"));
cls_StepRepr_ProductConcept.def_static("get_type_name_", (const char * (*)()) &StepRepr_ProductConcept::get_type_name, "None");
cls_StepRepr_ProductConcept.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_ProductConcept::get_type_descriptor, "None");
cls_StepRepr_ProductConcept.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_ProductConcept::*)() const) &StepRepr_ProductConcept::DynamicType, "None");

// Enums

}