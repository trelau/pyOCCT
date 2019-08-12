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
#include <StepAP242_ItemIdentifiedRepresentationUsageDefinition.hxx>
#include <StepRepr_Representation.hxx>
#include <StepRepr_HArray1OfRepresentationItem.hxx>
#include <Standard_TypeDef.hxx>
#include <StepRepr_RepresentationItem.hxx>
#include <StepAP242_ItemIdentifiedRepresentationUsage.hxx>
#include <Standard_Type.hxx>

void bind_StepAP242_ItemIdentifiedRepresentationUsage(py::module &mod){

py::class_<StepAP242_ItemIdentifiedRepresentationUsage, opencascade::handle<StepAP242_ItemIdentifiedRepresentationUsage>, Standard_Transient> cls_StepAP242_ItemIdentifiedRepresentationUsage(mod, "StepAP242_ItemIdentifiedRepresentationUsage", "None");

// Constructors
cls_StepAP242_ItemIdentifiedRepresentationUsage.def(py::init<>());

// Fields

// Methods
cls_StepAP242_ItemIdentifiedRepresentationUsage.def("Init", (void (StepAP242_ItemIdentifiedRepresentationUsage::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const StepAP242_ItemIdentifiedRepresentationUsageDefinition &, const opencascade::handle<StepRepr_Representation> &, const opencascade::handle<StepRepr_HArray1OfRepresentationItem> &)) &StepAP242_ItemIdentifiedRepresentationUsage::Init, "Init all fields own and inherited", py::arg("theName"), py::arg("theDescription"), py::arg("theDefinition"), py::arg("theUsedRepresentation"), py::arg("theIdentifiedItem"));
cls_StepAP242_ItemIdentifiedRepresentationUsage.def("SetName", (void (StepAP242_ItemIdentifiedRepresentationUsage::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepAP242_ItemIdentifiedRepresentationUsage::SetName, "Set field Name", py::arg("theName"));
cls_StepAP242_ItemIdentifiedRepresentationUsage.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepAP242_ItemIdentifiedRepresentationUsage::*)() const) &StepAP242_ItemIdentifiedRepresentationUsage::Name, "Returns field Name");
cls_StepAP242_ItemIdentifiedRepresentationUsage.def("SetDescription", (void (StepAP242_ItemIdentifiedRepresentationUsage::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepAP242_ItemIdentifiedRepresentationUsage::SetDescription, "Set field Description", py::arg("theDescription"));
cls_StepAP242_ItemIdentifiedRepresentationUsage.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepAP242_ItemIdentifiedRepresentationUsage::*)() const) &StepAP242_ItemIdentifiedRepresentationUsage::Description, "Returns field Description");
cls_StepAP242_ItemIdentifiedRepresentationUsage.def("SetDefinition", (void (StepAP242_ItemIdentifiedRepresentationUsage::*)(const StepAP242_ItemIdentifiedRepresentationUsageDefinition &)) &StepAP242_ItemIdentifiedRepresentationUsage::SetDefinition, "Set field Definition", py::arg("theDefinition"));
cls_StepAP242_ItemIdentifiedRepresentationUsage.def("Definition", (StepAP242_ItemIdentifiedRepresentationUsageDefinition (StepAP242_ItemIdentifiedRepresentationUsage::*)() const) &StepAP242_ItemIdentifiedRepresentationUsage::Definition, "Returns field Definition");
cls_StepAP242_ItemIdentifiedRepresentationUsage.def("SetUsedRepresentation", (void (StepAP242_ItemIdentifiedRepresentationUsage::*)(const opencascade::handle<StepRepr_Representation> &)) &StepAP242_ItemIdentifiedRepresentationUsage::SetUsedRepresentation, "Set field UsedRepresentation", py::arg("theUsedRepresentation"));
cls_StepAP242_ItemIdentifiedRepresentationUsage.def("UsedRepresentation", (opencascade::handle<StepRepr_Representation> (StepAP242_ItemIdentifiedRepresentationUsage::*)() const) &StepAP242_ItemIdentifiedRepresentationUsage::UsedRepresentation, "Retuns field UsedRepresentation");
cls_StepAP242_ItemIdentifiedRepresentationUsage.def("IdentifiedItem", (opencascade::handle<StepRepr_HArray1OfRepresentationItem> (StepAP242_ItemIdentifiedRepresentationUsage::*)() const) &StepAP242_ItemIdentifiedRepresentationUsage::IdentifiedItem, "Returns field IdentifiedItem");
cls_StepAP242_ItemIdentifiedRepresentationUsage.def("NbIdentifiedItem", (Standard_Integer (StepAP242_ItemIdentifiedRepresentationUsage::*)() const) &StepAP242_ItemIdentifiedRepresentationUsage::NbIdentifiedItem, "Returns number of identified items");
cls_StepAP242_ItemIdentifiedRepresentationUsage.def("SetIdentifiedItem", (void (StepAP242_ItemIdentifiedRepresentationUsage::*)(const opencascade::handle<StepRepr_HArray1OfRepresentationItem> &)) &StepAP242_ItemIdentifiedRepresentationUsage::SetIdentifiedItem, "Set fiels IdentifiedItem", py::arg("theIdentifiedItem"));
cls_StepAP242_ItemIdentifiedRepresentationUsage.def("IdentifiedItemValue", (opencascade::handle<StepRepr_RepresentationItem> (StepAP242_ItemIdentifiedRepresentationUsage::*)(const Standard_Integer) const) &StepAP242_ItemIdentifiedRepresentationUsage::IdentifiedItemValue, "Returns identified item with given number", py::arg("num"));
cls_StepAP242_ItemIdentifiedRepresentationUsage.def("SetIdentifiedItemValue", (void (StepAP242_ItemIdentifiedRepresentationUsage::*)(const Standard_Integer, const opencascade::handle<StepRepr_RepresentationItem> &)) &StepAP242_ItemIdentifiedRepresentationUsage::SetIdentifiedItemValue, "Set identified item with given number", py::arg("num"), py::arg("theItem"));
cls_StepAP242_ItemIdentifiedRepresentationUsage.def_static("get_type_name_", (const char * (*)()) &StepAP242_ItemIdentifiedRepresentationUsage::get_type_name, "None");
cls_StepAP242_ItemIdentifiedRepresentationUsage.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepAP242_ItemIdentifiedRepresentationUsage::get_type_descriptor, "None");
cls_StepAP242_ItemIdentifiedRepresentationUsage.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepAP242_ItemIdentifiedRepresentationUsage::*)() const) &StepAP242_ItemIdentifiedRepresentationUsage::DynamicType, "None");

// Enums

}