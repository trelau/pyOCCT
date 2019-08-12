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
#include <StepAP214_Class.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <Standard_TypeDef.hxx>
#include <StepBasic_SourceItem.hxx>
#include <StepBasic_ExternalSource.hxx>
#include <StepBasic_ExternallyDefinedItem.hxx>
#include <StepAP214_ExternallyDefinedClass.hxx>
#include <Standard_Type.hxx>

void bind_StepAP214_ExternallyDefinedClass(py::module &mod){

py::class_<StepAP214_ExternallyDefinedClass, opencascade::handle<StepAP214_ExternallyDefinedClass>, StepAP214_Class> cls_StepAP214_ExternallyDefinedClass(mod, "StepAP214_ExternallyDefinedClass", "Representation of STEP entity ExternallyDefinedClass");

// Constructors
cls_StepAP214_ExternallyDefinedClass.def(py::init<>());

// Fields

// Methods
cls_StepAP214_ExternallyDefinedClass.def("Init", (void (StepAP214_ExternallyDefinedClass::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const StepBasic_SourceItem &, const opencascade::handle<StepBasic_ExternalSource> &)) &StepAP214_ExternallyDefinedClass::Init, "Initialize all fields (own and inherited)", py::arg("aGroup_Name"), py::arg("hasGroup_Description"), py::arg("aGroup_Description"), py::arg("aExternallyDefinedItem_ItemId"), py::arg("aExternallyDefinedItem_Source"));
cls_StepAP214_ExternallyDefinedClass.def("ExternallyDefinedItem", (opencascade::handle<StepBasic_ExternallyDefinedItem> (StepAP214_ExternallyDefinedClass::*)() const) &StepAP214_ExternallyDefinedClass::ExternallyDefinedItem, "Returns data for supertype ExternallyDefinedItem");
cls_StepAP214_ExternallyDefinedClass.def("SetExternallyDefinedItem", (void (StepAP214_ExternallyDefinedClass::*)(const opencascade::handle<StepBasic_ExternallyDefinedItem> &)) &StepAP214_ExternallyDefinedClass::SetExternallyDefinedItem, "Set data for supertype ExternallyDefinedItem", py::arg("ExternallyDefinedItem"));
cls_StepAP214_ExternallyDefinedClass.def_static("get_type_name_", (const char * (*)()) &StepAP214_ExternallyDefinedClass::get_type_name, "None");
cls_StepAP214_ExternallyDefinedClass.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepAP214_ExternallyDefinedClass::get_type_descriptor, "None");
cls_StepAP214_ExternallyDefinedClass.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepAP214_ExternallyDefinedClass::*)() const) &StepAP214_ExternallyDefinedClass::DynamicType, "None");

// Enums

}