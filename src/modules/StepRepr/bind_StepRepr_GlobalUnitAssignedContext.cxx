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
#include <StepBasic_HArray1OfNamedUnit.hxx>
#include <StepBasic_NamedUnit.hxx>
#include <Standard_TypeDef.hxx>
#include <StepRepr_GlobalUnitAssignedContext.hxx>
#include <Standard_Type.hxx>

void bind_StepRepr_GlobalUnitAssignedContext(py::module &mod){

py::class_<StepRepr_GlobalUnitAssignedContext, opencascade::handle<StepRepr_GlobalUnitAssignedContext>, StepRepr_RepresentationContext> cls_StepRepr_GlobalUnitAssignedContext(mod, "StepRepr_GlobalUnitAssignedContext", "None");

// Constructors
cls_StepRepr_GlobalUnitAssignedContext.def(py::init<>());

// Fields

// Methods
cls_StepRepr_GlobalUnitAssignedContext.def("Init", (void (StepRepr_GlobalUnitAssignedContext::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_HArray1OfNamedUnit> &)) &StepRepr_GlobalUnitAssignedContext::Init, "None", py::arg("aContextIdentifier"), py::arg("aContextType"), py::arg("aUnits"));
cls_StepRepr_GlobalUnitAssignedContext.def("SetUnits", (void (StepRepr_GlobalUnitAssignedContext::*)(const opencascade::handle<StepBasic_HArray1OfNamedUnit> &)) &StepRepr_GlobalUnitAssignedContext::SetUnits, "None", py::arg("aUnits"));
cls_StepRepr_GlobalUnitAssignedContext.def("Units", (opencascade::handle<StepBasic_HArray1OfNamedUnit> (StepRepr_GlobalUnitAssignedContext::*)() const) &StepRepr_GlobalUnitAssignedContext::Units, "None");
cls_StepRepr_GlobalUnitAssignedContext.def("UnitsValue", (opencascade::handle<StepBasic_NamedUnit> (StepRepr_GlobalUnitAssignedContext::*)(const Standard_Integer) const) &StepRepr_GlobalUnitAssignedContext::UnitsValue, "None", py::arg("num"));
cls_StepRepr_GlobalUnitAssignedContext.def("NbUnits", (Standard_Integer (StepRepr_GlobalUnitAssignedContext::*)() const) &StepRepr_GlobalUnitAssignedContext::NbUnits, "None");
cls_StepRepr_GlobalUnitAssignedContext.def_static("get_type_name_", (const char * (*)()) &StepRepr_GlobalUnitAssignedContext::get_type_name, "None");
cls_StepRepr_GlobalUnitAssignedContext.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_GlobalUnitAssignedContext::get_type_descriptor, "None");
cls_StepRepr_GlobalUnitAssignedContext.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_GlobalUnitAssignedContext::*)() const) &StepRepr_GlobalUnitAssignedContext::DynamicType, "None");

// Enums

}