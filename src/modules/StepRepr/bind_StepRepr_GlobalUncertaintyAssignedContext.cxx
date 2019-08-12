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
#include <StepRepr_RepresentationContext.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepBasic_HArray1OfUncertaintyMeasureWithUnit.hxx>
#include <StepBasic_UncertaintyMeasureWithUnit.hxx>
#include <Standard_TypeDef.hxx>
#include <StepRepr_GlobalUncertaintyAssignedContext.hxx>
#include <Standard_Type.hxx>

void bind_StepRepr_GlobalUncertaintyAssignedContext(py::module &mod){

py::class_<StepRepr_GlobalUncertaintyAssignedContext, opencascade::handle<StepRepr_GlobalUncertaintyAssignedContext>, StepRepr_RepresentationContext> cls_StepRepr_GlobalUncertaintyAssignedContext(mod, "StepRepr_GlobalUncertaintyAssignedContext", "None");

// Constructors
cls_StepRepr_GlobalUncertaintyAssignedContext.def(py::init<>());

// Fields

// Methods
cls_StepRepr_GlobalUncertaintyAssignedContext.def("Init", (void (StepRepr_GlobalUncertaintyAssignedContext::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_HArray1OfUncertaintyMeasureWithUnit> &)) &StepRepr_GlobalUncertaintyAssignedContext::Init, "None", py::arg("aContextIdentifier"), py::arg("aContextType"), py::arg("aUncertainty"));
cls_StepRepr_GlobalUncertaintyAssignedContext.def("SetUncertainty", (void (StepRepr_GlobalUncertaintyAssignedContext::*)(const opencascade::handle<StepBasic_HArray1OfUncertaintyMeasureWithUnit> &)) &StepRepr_GlobalUncertaintyAssignedContext::SetUncertainty, "None", py::arg("aUncertainty"));
cls_StepRepr_GlobalUncertaintyAssignedContext.def("Uncertainty", (opencascade::handle<StepBasic_HArray1OfUncertaintyMeasureWithUnit> (StepRepr_GlobalUncertaintyAssignedContext::*)() const) &StepRepr_GlobalUncertaintyAssignedContext::Uncertainty, "None");
cls_StepRepr_GlobalUncertaintyAssignedContext.def("UncertaintyValue", (opencascade::handle<StepBasic_UncertaintyMeasureWithUnit> (StepRepr_GlobalUncertaintyAssignedContext::*)(const Standard_Integer) const) &StepRepr_GlobalUncertaintyAssignedContext::UncertaintyValue, "None", py::arg("num"));
cls_StepRepr_GlobalUncertaintyAssignedContext.def("NbUncertainty", (Standard_Integer (StepRepr_GlobalUncertaintyAssignedContext::*)() const) &StepRepr_GlobalUncertaintyAssignedContext::NbUncertainty, "None");
cls_StepRepr_GlobalUncertaintyAssignedContext.def_static("get_type_name_", (const char * (*)()) &StepRepr_GlobalUncertaintyAssignedContext::get_type_name, "None");
cls_StepRepr_GlobalUncertaintyAssignedContext.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_GlobalUncertaintyAssignedContext::get_type_descriptor, "None");
cls_StepRepr_GlobalUncertaintyAssignedContext.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_GlobalUncertaintyAssignedContext::*)() const) &StepRepr_GlobalUncertaintyAssignedContext::DynamicType, "None");

// Enums

}