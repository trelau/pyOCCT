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
#include <StepBasic_GeneralProperty.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <Standard_TypeDef.hxx>
#include <StepBasic_SourceItem.hxx>
#include <StepBasic_ExternalSource.hxx>
#include <StepBasic_ExternallyDefinedItem.hxx>
#include <StepAP214_ExternallyDefinedGeneralProperty.hxx>
#include <Standard_Type.hxx>

void bind_StepAP214_ExternallyDefinedGeneralProperty(py::module &mod){

py::class_<StepAP214_ExternallyDefinedGeneralProperty, opencascade::handle<StepAP214_ExternallyDefinedGeneralProperty>, StepBasic_GeneralProperty> cls_StepAP214_ExternallyDefinedGeneralProperty(mod, "StepAP214_ExternallyDefinedGeneralProperty", "Representation of STEP entity ExternallyDefinedGeneralProperty");

// Constructors
cls_StepAP214_ExternallyDefinedGeneralProperty.def(py::init<>());

// Fields

// Methods
cls_StepAP214_ExternallyDefinedGeneralProperty.def("Init", (void (StepAP214_ExternallyDefinedGeneralProperty::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const StepBasic_SourceItem &, const opencascade::handle<StepBasic_ExternalSource> &)) &StepAP214_ExternallyDefinedGeneralProperty::Init, "Initialize all fields (own and inherited)", py::arg("aGeneralProperty_Id"), py::arg("aGeneralProperty_Name"), py::arg("hasGeneralProperty_Description"), py::arg("aGeneralProperty_Description"), py::arg("aExternallyDefinedItem_ItemId"), py::arg("aExternallyDefinedItem_Source"));
cls_StepAP214_ExternallyDefinedGeneralProperty.def("ExternallyDefinedItem", (opencascade::handle<StepBasic_ExternallyDefinedItem> (StepAP214_ExternallyDefinedGeneralProperty::*)() const) &StepAP214_ExternallyDefinedGeneralProperty::ExternallyDefinedItem, "Returns data for supertype ExternallyDefinedItem");
cls_StepAP214_ExternallyDefinedGeneralProperty.def("SetExternallyDefinedItem", (void (StepAP214_ExternallyDefinedGeneralProperty::*)(const opencascade::handle<StepBasic_ExternallyDefinedItem> &)) &StepAP214_ExternallyDefinedGeneralProperty::SetExternallyDefinedItem, "Set data for supertype ExternallyDefinedItem", py::arg("ExternallyDefinedItem"));
cls_StepAP214_ExternallyDefinedGeneralProperty.def_static("get_type_name_", (const char * (*)()) &StepAP214_ExternallyDefinedGeneralProperty::get_type_name, "None");
cls_StepAP214_ExternallyDefinedGeneralProperty.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepAP214_ExternallyDefinedGeneralProperty::get_type_descriptor, "None");
cls_StepAP214_ExternallyDefinedGeneralProperty.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepAP214_ExternallyDefinedGeneralProperty::*)() const) &StepAP214_ExternallyDefinedGeneralProperty::DynamicType, "None");

// Enums

}