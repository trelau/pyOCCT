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
#include <StepRepr_AssemblyComponentUsage.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <Standard_TypeDef.hxx>
#include <StepBasic_ProductDefinition.hxx>
#include <StepRepr_NextAssemblyUsageOccurrence.hxx>
#include <StepBasic_ProductDefinitionOrReference.hxx>
#include <StepRepr_SpecifiedHigherUsageOccurrence.hxx>
#include <Standard_Type.hxx>

void bind_StepRepr_SpecifiedHigherUsageOccurrence(py::module &mod){

py::class_<StepRepr_SpecifiedHigherUsageOccurrence, opencascade::handle<StepRepr_SpecifiedHigherUsageOccurrence>, StepRepr_AssemblyComponentUsage> cls_StepRepr_SpecifiedHigherUsageOccurrence(mod, "StepRepr_SpecifiedHigherUsageOccurrence", "Representation of STEP entity SpecifiedHigherUsageOccurrence");

// Constructors
cls_StepRepr_SpecifiedHigherUsageOccurrence.def(py::init<>());

// Fields

// Methods
cls_StepRepr_SpecifiedHigherUsageOccurrence.def("Init", (void (StepRepr_SpecifiedHigherUsageOccurrence::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_ProductDefinition> &, const opencascade::handle<StepBasic_ProductDefinition> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepRepr_AssemblyComponentUsage> &, const opencascade::handle<StepRepr_NextAssemblyUsageOccurrence> &)) &StepRepr_SpecifiedHigherUsageOccurrence::Init, "Initialize all fields (own and inherited)", py::arg("aProductDefinitionRelationship_Id"), py::arg("aProductDefinitionRelationship_Name"), py::arg("hasProductDefinitionRelationship_Description"), py::arg("aProductDefinitionRelationship_Description"), py::arg("aProductDefinitionRelationship_RelatingProductDefinition"), py::arg("aProductDefinitionRelationship_RelatedProductDefinition"), py::arg("hasAssemblyComponentUsage_ReferenceDesignator"), py::arg("aAssemblyComponentUsage_ReferenceDesignator"), py::arg("aUpperUsage"), py::arg("aNextUsage"));
cls_StepRepr_SpecifiedHigherUsageOccurrence.def("Init", (void (StepRepr_SpecifiedHigherUsageOccurrence::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const StepBasic_ProductDefinitionOrReference &, const StepBasic_ProductDefinitionOrReference &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepRepr_AssemblyComponentUsage> &, const opencascade::handle<StepRepr_NextAssemblyUsageOccurrence> &)) &StepRepr_SpecifiedHigherUsageOccurrence::Init, "Initialize all fields (own and inherited)", py::arg("aProductDefinitionRelationship_Id"), py::arg("aProductDefinitionRelationship_Name"), py::arg("hasProductDefinitionRelationship_Description"), py::arg("aProductDefinitionRelationship_Description"), py::arg("aProductDefinitionRelationship_RelatingProductDefinition"), py::arg("aProductDefinitionRelationship_RelatedProductDefinition"), py::arg("hasAssemblyComponentUsage_ReferenceDesignator"), py::arg("aAssemblyComponentUsage_ReferenceDesignator"), py::arg("aUpperUsage"), py::arg("aNextUsage"));
cls_StepRepr_SpecifiedHigherUsageOccurrence.def("UpperUsage", (opencascade::handle<StepRepr_AssemblyComponentUsage> (StepRepr_SpecifiedHigherUsageOccurrence::*)() const) &StepRepr_SpecifiedHigherUsageOccurrence::UpperUsage, "Returns field UpperUsage");
cls_StepRepr_SpecifiedHigherUsageOccurrence.def("SetUpperUsage", (void (StepRepr_SpecifiedHigherUsageOccurrence::*)(const opencascade::handle<StepRepr_AssemblyComponentUsage> &)) &StepRepr_SpecifiedHigherUsageOccurrence::SetUpperUsage, "Set field UpperUsage", py::arg("UpperUsage"));
cls_StepRepr_SpecifiedHigherUsageOccurrence.def("NextUsage", (opencascade::handle<StepRepr_NextAssemblyUsageOccurrence> (StepRepr_SpecifiedHigherUsageOccurrence::*)() const) &StepRepr_SpecifiedHigherUsageOccurrence::NextUsage, "Returns field NextUsage");
cls_StepRepr_SpecifiedHigherUsageOccurrence.def("SetNextUsage", (void (StepRepr_SpecifiedHigherUsageOccurrence::*)(const opencascade::handle<StepRepr_NextAssemblyUsageOccurrence> &)) &StepRepr_SpecifiedHigherUsageOccurrence::SetNextUsage, "Set field NextUsage", py::arg("NextUsage"));
cls_StepRepr_SpecifiedHigherUsageOccurrence.def_static("get_type_name_", (const char * (*)()) &StepRepr_SpecifiedHigherUsageOccurrence::get_type_name, "None");
cls_StepRepr_SpecifiedHigherUsageOccurrence.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_SpecifiedHigherUsageOccurrence::get_type_descriptor, "None");
cls_StepRepr_SpecifiedHigherUsageOccurrence.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_SpecifiedHigherUsageOccurrence::*)() const) &StepRepr_SpecifiedHigherUsageOccurrence::DynamicType, "None");

// Enums

}