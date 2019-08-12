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
#include <StepAP242_IdAttributeSelect.hxx>
#include <StepAP242_IdAttribute.hxx>
#include <Standard_Type.hxx>

void bind_StepAP242_IdAttribute(py::module &mod){

py::class_<StepAP242_IdAttribute, opencascade::handle<StepAP242_IdAttribute>, Standard_Transient> cls_StepAP242_IdAttribute(mod, "StepAP242_IdAttribute", "None");

// Constructors
cls_StepAP242_IdAttribute.def(py::init<>());

// Fields

// Methods
cls_StepAP242_IdAttribute.def("Init", (void (StepAP242_IdAttribute::*)(const opencascade::handle<TCollection_HAsciiString> &, const StepAP242_IdAttributeSelect &)) &StepAP242_IdAttribute::Init, "Init all field own and inherited", py::arg("theAttributeValue"), py::arg("theIdentifiedItem"));
cls_StepAP242_IdAttribute.def("SetAttributeValue", (void (StepAP242_IdAttribute::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepAP242_IdAttribute::SetAttributeValue, "None", py::arg("theAttributeValue"));
cls_StepAP242_IdAttribute.def("AttributeValue", (opencascade::handle<TCollection_HAsciiString> (StepAP242_IdAttribute::*)() const) &StepAP242_IdAttribute::AttributeValue, "Returns field AttributeValue");
cls_StepAP242_IdAttribute.def("SetIdentifiedItem", (void (StepAP242_IdAttribute::*)(const StepAP242_IdAttributeSelect &)) &StepAP242_IdAttribute::SetIdentifiedItem, "Set field IdentifiedItem", py::arg("theIdentifiedItem"));
cls_StepAP242_IdAttribute.def("IdentifiedItem", (StepAP242_IdAttributeSelect (StepAP242_IdAttribute::*)() const) &StepAP242_IdAttribute::IdentifiedItem, "Returns IdentifiedItem");
cls_StepAP242_IdAttribute.def_static("get_type_name_", (const char * (*)()) &StepAP242_IdAttribute::get_type_name, "None");
cls_StepAP242_IdAttribute.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepAP242_IdAttribute::get_type_descriptor, "None");
cls_StepAP242_IdAttribute.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepAP242_IdAttribute::*)() const) &StepAP242_IdAttribute::DynamicType, "None");

// Enums

}