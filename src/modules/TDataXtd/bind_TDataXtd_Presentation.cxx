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
#include <TDF_Attribute.hxx>
#include <Standard_Handle.hxx>
#include <TDataXtd_Presentation.hxx>
#include <TDF_Label.hxx>
#include <Standard_GUID.hxx>
#include <TDF_RelocationTable.hxx>
#include <Standard_Type.hxx>
#include <Standard_TypeDef.hxx>
#include <Quantity_NameOfColor.hxx>

void bind_TDataXtd_Presentation(py::module &mod){

py::class_<TDataXtd_Presentation, opencascade::handle<TDataXtd_Presentation>, TDF_Attribute> cls_TDataXtd_Presentation(mod, "TDataXtd_Presentation", "Attribute containing parameters of presentation of the shape, e.g. the shape attached to the same label and displayed using TPrsStd tools (see TPrsStd_AISPresentation).");

// Constructors
cls_TDataXtd_Presentation.def(py::init<>());

// Fields

// Methods
cls_TDataXtd_Presentation.def_static("Set_", (opencascade::handle<TDataXtd_Presentation> (*)(const TDF_Label &, const Standard_GUID &)) &TDataXtd_Presentation::Set, "Create if not found the TDataXtd_Presentation attribute and set its driver GUID", py::arg("theLabel"), py::arg("theDriverId"));
cls_TDataXtd_Presentation.def_static("Unset_", (void (*)(const TDF_Label &)) &TDataXtd_Presentation::Unset, "Remove attribute of this type from the label", py::arg("theLabel"));
cls_TDataXtd_Presentation.def("ID", (const Standard_GUID & (TDataXtd_Presentation::*)() const) &TDataXtd_Presentation::ID, "Returns the ID of the attribute.");
cls_TDataXtd_Presentation.def_static("GetID_", (const Standard_GUID & (*)()) &TDataXtd_Presentation::GetID, "Returns the ID of the attribute.");
cls_TDataXtd_Presentation.def("Restore", (void (TDataXtd_Presentation::*)(const opencascade::handle<TDF_Attribute> &)) &TDataXtd_Presentation::Restore, "Restores the contents from <anAttribute> into this one. It is used when aborting a transaction.", py::arg("anAttribute"));
cls_TDataXtd_Presentation.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TDataXtd_Presentation::*)() const) &TDataXtd_Presentation::NewEmpty, "Returns an new empty attribute from the good end type. It is used by the copy algorithm.");
cls_TDataXtd_Presentation.def("Paste", (void (TDataXtd_Presentation::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TDataXtd_Presentation::Paste, "This method is different from the 'Copy' one, because it is used when copying an attribute from a source structure into a target structure. This method pastes the current attribute to the label corresponding to the insertor. The pasted attribute may be a brand new one or a new version of the previous one.", py::arg("intoAttribute"), py::arg("aRelocTationable"));
cls_TDataXtd_Presentation.def("BackupCopy", (opencascade::handle<TDF_Attribute> (TDataXtd_Presentation::*)() const) &TDataXtd_Presentation::BackupCopy, "None");
cls_TDataXtd_Presentation.def_static("get_type_name_", (const char * (*)()) &TDataXtd_Presentation::get_type_name, "None");
cls_TDataXtd_Presentation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDataXtd_Presentation::get_type_descriptor, "None");
cls_TDataXtd_Presentation.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDataXtd_Presentation::*)() const) &TDataXtd_Presentation::DynamicType, "None");
cls_TDataXtd_Presentation.def("GetDriverGUID", (Standard_GUID (TDataXtd_Presentation::*)() const) &TDataXtd_Presentation::GetDriverGUID, "Returns the GUID of the driver managing display of associated AIS object");
cls_TDataXtd_Presentation.def("SetDriverGUID", (void (TDataXtd_Presentation::*)(const Standard_GUID &)) &TDataXtd_Presentation::SetDriverGUID, "Sets the GUID of the driver managing display of associated AIS object", py::arg("theGUID"));
cls_TDataXtd_Presentation.def("IsDisplayed", (Standard_Boolean (TDataXtd_Presentation::*)() const) &TDataXtd_Presentation::IsDisplayed, "None");
cls_TDataXtd_Presentation.def("HasOwnMaterial", (Standard_Boolean (TDataXtd_Presentation::*)() const) &TDataXtd_Presentation::HasOwnMaterial, "None");
cls_TDataXtd_Presentation.def("HasOwnTransparency", (Standard_Boolean (TDataXtd_Presentation::*)() const) &TDataXtd_Presentation::HasOwnTransparency, "None");
cls_TDataXtd_Presentation.def("HasOwnColor", (Standard_Boolean (TDataXtd_Presentation::*)() const) &TDataXtd_Presentation::HasOwnColor, "None");
cls_TDataXtd_Presentation.def("HasOwnWidth", (Standard_Boolean (TDataXtd_Presentation::*)() const) &TDataXtd_Presentation::HasOwnWidth, "None");
cls_TDataXtd_Presentation.def("HasOwnMode", (Standard_Boolean (TDataXtd_Presentation::*)() const) &TDataXtd_Presentation::HasOwnMode, "None");
cls_TDataXtd_Presentation.def("HasOwnSelectionMode", (Standard_Boolean (TDataXtd_Presentation::*)() const) &TDataXtd_Presentation::HasOwnSelectionMode, "None");
cls_TDataXtd_Presentation.def("SetDisplayed", (void (TDataXtd_Presentation::*)(const Standard_Boolean)) &TDataXtd_Presentation::SetDisplayed, "None", py::arg("theIsDisplayed"));
cls_TDataXtd_Presentation.def("SetMaterialIndex", (void (TDataXtd_Presentation::*)(const Standard_Integer)) &TDataXtd_Presentation::SetMaterialIndex, "None", py::arg("theMaterialIndex"));
cls_TDataXtd_Presentation.def("SetTransparency", (void (TDataXtd_Presentation::*)(const Standard_Real)) &TDataXtd_Presentation::SetTransparency, "None", py::arg("theValue"));
cls_TDataXtd_Presentation.def("SetColor", (void (TDataXtd_Presentation::*)(const Quantity_NameOfColor)) &TDataXtd_Presentation::SetColor, "None", py::arg("theColor"));
cls_TDataXtd_Presentation.def("SetWidth", (void (TDataXtd_Presentation::*)(const Standard_Real)) &TDataXtd_Presentation::SetWidth, "None", py::arg("theWidth"));
cls_TDataXtd_Presentation.def("SetMode", (void (TDataXtd_Presentation::*)(const Standard_Integer)) &TDataXtd_Presentation::SetMode, "None", py::arg("theMode"));
cls_TDataXtd_Presentation.def("SetSelectionMode", (void (TDataXtd_Presentation::*)(const Standard_Integer)) &TDataXtd_Presentation::SetSelectionMode, "None", py::arg("theSelectionMode"));
cls_TDataXtd_Presentation.def("MaterialIndex", (Standard_Integer (TDataXtd_Presentation::*)() const) &TDataXtd_Presentation::MaterialIndex, "None");
cls_TDataXtd_Presentation.def("Transparency", (Standard_Real (TDataXtd_Presentation::*)() const) &TDataXtd_Presentation::Transparency, "None");
cls_TDataXtd_Presentation.def("Color", (Quantity_NameOfColor (TDataXtd_Presentation::*)() const) &TDataXtd_Presentation::Color, "None");
cls_TDataXtd_Presentation.def("Width", (Standard_Real (TDataXtd_Presentation::*)() const) &TDataXtd_Presentation::Width, "None");
cls_TDataXtd_Presentation.def("Mode", (Standard_Integer (TDataXtd_Presentation::*)() const) &TDataXtd_Presentation::Mode, "None");
cls_TDataXtd_Presentation.def("SelectionMode", (Standard_Integer (TDataXtd_Presentation::*)() const) &TDataXtd_Presentation::SelectionMode, "None");
cls_TDataXtd_Presentation.def("UnsetMaterial", (void (TDataXtd_Presentation::*)()) &TDataXtd_Presentation::UnsetMaterial, "None");
cls_TDataXtd_Presentation.def("UnsetTransparency", (void (TDataXtd_Presentation::*)()) &TDataXtd_Presentation::UnsetTransparency, "None");
cls_TDataXtd_Presentation.def("UnsetColor", (void (TDataXtd_Presentation::*)()) &TDataXtd_Presentation::UnsetColor, "None");
cls_TDataXtd_Presentation.def("UnsetWidth", (void (TDataXtd_Presentation::*)()) &TDataXtd_Presentation::UnsetWidth, "None");
cls_TDataXtd_Presentation.def("UnsetMode", (void (TDataXtd_Presentation::*)()) &TDataXtd_Presentation::UnsetMode, "None");
cls_TDataXtd_Presentation.def("UnsetSelectionMode", (void (TDataXtd_Presentation::*)()) &TDataXtd_Presentation::UnsetSelectionMode, "None");

// Enums

}