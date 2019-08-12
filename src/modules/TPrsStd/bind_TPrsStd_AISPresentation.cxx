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
#include <Standard_GUID.hxx>
#include <Standard_Handle.hxx>
#include <TPrsStd_AISPresentation.hxx>
#include <TDF_Label.hxx>
#include <Standard_TypeDef.hxx>
#include <AIS_InteractiveObject.hxx>
#include <Graphic3d_NameOfMaterial.hxx>
#include <Quantity_NameOfColor.hxx>
#include <TDF_RelocationTable.hxx>
#include <TDF_AttributeDelta.hxx>
#include <Standard_Type.hxx>
#include <TDataXtd_Presentation.hxx>
#include <AIS_InteractiveContext.hxx>

void bind_TPrsStd_AISPresentation(py::module &mod){

py::class_<TPrsStd_AISPresentation, opencascade::handle<TPrsStd_AISPresentation>, TDF_Attribute> cls_TPrsStd_AISPresentation(mod, "TPrsStd_AISPresentation", "An attribute to associate an AIS_InteractiveObject to a label in an AIS viewer. This attribute works in collaboration with TPrsStd_AISViewer. Note that all the Set... and Unset... attribute methods as well as the query methods for visualization attributes and the HasOwn... test methods are shortcuts to the respective AIS_InteractiveObject settings.");

// Constructors
cls_TPrsStd_AISPresentation.def(py::init<>());

// Fields

// Methods
cls_TPrsStd_AISPresentation.def_static("GetID_", (const Standard_GUID & (*)()) &TPrsStd_AISPresentation::GetID, "Returns the GUID for TPrsStd_AISPresentation attributes.");
cls_TPrsStd_AISPresentation.def_static("Set_", (opencascade::handle<TPrsStd_AISPresentation> (*)(const TDF_Label &, const Standard_GUID &)) &TPrsStd_AISPresentation::Set, "Creates or retrieves the presentation attribute on the label L, and sets the GUID driver.", py::arg("L"), py::arg("driver"));
cls_TPrsStd_AISPresentation.def_static("Unset_", (void (*)(const TDF_Label &)) &TPrsStd_AISPresentation::Unset, "Delete (if exist) the presentation attribute associated to the label <L>.", py::arg("L"));
cls_TPrsStd_AISPresentation.def_static("Set_", (opencascade::handle<TPrsStd_AISPresentation> (*)(const opencascade::handle<TDF_Attribute> &)) &TPrsStd_AISPresentation::Set, "Creates or retrieves the AISPresentation attribute attached to master. The GUID of the driver will be the GUID of master. master is the attribute you want to display.", py::arg("master"));
cls_TPrsStd_AISPresentation.def("SetDisplayed", (void (TPrsStd_AISPresentation::*)(const Standard_Boolean)) &TPrsStd_AISPresentation::SetDisplayed, "None", py::arg("B"));
cls_TPrsStd_AISPresentation.def("Display", [](TPrsStd_AISPresentation &self) -> void { return self.Display(); });
cls_TPrsStd_AISPresentation.def("Display", (void (TPrsStd_AISPresentation::*)(const Standard_Boolean)) &TPrsStd_AISPresentation::Display, "Display presentation of object in AIS viewer. If <update> = True then AISObject is recomputed and all the visualization settings are applied", py::arg("update"));
cls_TPrsStd_AISPresentation.def("Erase", [](TPrsStd_AISPresentation &self) -> void { return self.Erase(); });
cls_TPrsStd_AISPresentation.def("Erase", (void (TPrsStd_AISPresentation::*)(const Standard_Boolean)) &TPrsStd_AISPresentation::Erase, "Removes the presentation of this AIS presentation attribute from the TPrsStd_AISViewer. If remove is true, this AIS presentation attribute is removed from the interactive context.", py::arg("remove"));
cls_TPrsStd_AISPresentation.def("Update", (void (TPrsStd_AISPresentation::*)()) &TPrsStd_AISPresentation::Update, "Recompute presentation of object and apply the visualization settings");
cls_TPrsStd_AISPresentation.def("GetDriverGUID", (Standard_GUID (TPrsStd_AISPresentation::*)() const) &TPrsStd_AISPresentation::GetDriverGUID, "None");
cls_TPrsStd_AISPresentation.def("SetDriverGUID", (void (TPrsStd_AISPresentation::*)(const Standard_GUID &)) &TPrsStd_AISPresentation::SetDriverGUID, "None", py::arg("guid"));
cls_TPrsStd_AISPresentation.def("IsDisplayed", (Standard_Boolean (TPrsStd_AISPresentation::*)() const) &TPrsStd_AISPresentation::IsDisplayed, "Returns true if this AIS presentation attribute is displayed.");
cls_TPrsStd_AISPresentation.def("GetAIS", (opencascade::handle<AIS_InteractiveObject> (TPrsStd_AISPresentation::*)() const) &TPrsStd_AISPresentation::GetAIS, "Returns AIS_InteractiveObject stored in the presentation attribute");
cls_TPrsStd_AISPresentation.def("Material", (Graphic3d_NameOfMaterial (TPrsStd_AISPresentation::*)() const) &TPrsStd_AISPresentation::Material, "Returns the material setting for this presentation attribute.");
cls_TPrsStd_AISPresentation.def("SetMaterial", (void (TPrsStd_AISPresentation::*)(const Graphic3d_NameOfMaterial)) &TPrsStd_AISPresentation::SetMaterial, "Sets the material aName for this presentation attribute.", py::arg("aName"));
cls_TPrsStd_AISPresentation.def("HasOwnMaterial", (Standard_Boolean (TPrsStd_AISPresentation::*)() const) &TPrsStd_AISPresentation::HasOwnMaterial, "Returns true if this presentation attribute already has a material setting.");
cls_TPrsStd_AISPresentation.def("UnsetMaterial", (void (TPrsStd_AISPresentation::*)()) &TPrsStd_AISPresentation::UnsetMaterial, "Removes the material setting from this presentation attribute.");
cls_TPrsStd_AISPresentation.def("SetTransparency", [](TPrsStd_AISPresentation &self) -> void { return self.SetTransparency(); });
cls_TPrsStd_AISPresentation.def("SetTransparency", (void (TPrsStd_AISPresentation::*)(const Standard_Real)) &TPrsStd_AISPresentation::SetTransparency, "Sets the transparency value aValue for this presentation attribute. This value is 0.6 by default.", py::arg("aValue"));
cls_TPrsStd_AISPresentation.def("Transparency", (Standard_Real (TPrsStd_AISPresentation::*)() const) &TPrsStd_AISPresentation::Transparency, "None");
cls_TPrsStd_AISPresentation.def("HasOwnTransparency", (Standard_Boolean (TPrsStd_AISPresentation::*)() const) &TPrsStd_AISPresentation::HasOwnTransparency, "Returns true if this presentation attribute already has a transparency setting.");
cls_TPrsStd_AISPresentation.def("UnsetTransparency", (void (TPrsStd_AISPresentation::*)()) &TPrsStd_AISPresentation::UnsetTransparency, "Removes the transparency setting from this presentation attribute.");
cls_TPrsStd_AISPresentation.def("Color", (Quantity_NameOfColor (TPrsStd_AISPresentation::*)() const) &TPrsStd_AISPresentation::Color, "None");
cls_TPrsStd_AISPresentation.def("SetColor", (void (TPrsStd_AISPresentation::*)(const Quantity_NameOfColor)) &TPrsStd_AISPresentation::SetColor, "Sets the color aColor for this presentation attribute.", py::arg("aColor"));
cls_TPrsStd_AISPresentation.def("HasOwnColor", (Standard_Boolean (TPrsStd_AISPresentation::*)() const) &TPrsStd_AISPresentation::HasOwnColor, "Returns true if this presentation attribute already has a color setting.");
cls_TPrsStd_AISPresentation.def("UnsetColor", (void (TPrsStd_AISPresentation::*)()) &TPrsStd_AISPresentation::UnsetColor, "Removes the color setting from this presentation attribute.");
cls_TPrsStd_AISPresentation.def("Width", (Standard_Real (TPrsStd_AISPresentation::*)() const) &TPrsStd_AISPresentation::Width, "None");
cls_TPrsStd_AISPresentation.def("SetWidth", (void (TPrsStd_AISPresentation::*)(const Standard_Real)) &TPrsStd_AISPresentation::SetWidth, "Sets the width aWidth for this presentation attribute.", py::arg("aWidth"));
cls_TPrsStd_AISPresentation.def("HasOwnWidth", (Standard_Boolean (TPrsStd_AISPresentation::*)() const) &TPrsStd_AISPresentation::HasOwnWidth, "Returns true if this presentation attribute already has a width setting.");
cls_TPrsStd_AISPresentation.def("UnsetWidth", (void (TPrsStd_AISPresentation::*)()) &TPrsStd_AISPresentation::UnsetWidth, "Removes the width setting from this presentation attribute.");
cls_TPrsStd_AISPresentation.def("Mode", (Standard_Integer (TPrsStd_AISPresentation::*)() const) &TPrsStd_AISPresentation::Mode, "None");
cls_TPrsStd_AISPresentation.def("SetMode", (void (TPrsStd_AISPresentation::*)(const Standard_Integer)) &TPrsStd_AISPresentation::SetMode, "None", py::arg("theMode"));
cls_TPrsStd_AISPresentation.def("HasOwnMode", (Standard_Boolean (TPrsStd_AISPresentation::*)() const) &TPrsStd_AISPresentation::HasOwnMode, "None");
cls_TPrsStd_AISPresentation.def("UnsetMode", (void (TPrsStd_AISPresentation::*)()) &TPrsStd_AISPresentation::UnsetMode, "None");
cls_TPrsStd_AISPresentation.def("SelectionMode", (Standard_Integer (TPrsStd_AISPresentation::*)() const) &TPrsStd_AISPresentation::SelectionMode, "None");
cls_TPrsStd_AISPresentation.def("SetSelectionMode", (void (TPrsStd_AISPresentation::*)(const Standard_Integer)) &TPrsStd_AISPresentation::SetSelectionMode, "None", py::arg("theSelectionMode"));
cls_TPrsStd_AISPresentation.def("HasOwnSelectionMode", (Standard_Boolean (TPrsStd_AISPresentation::*)() const) &TPrsStd_AISPresentation::HasOwnSelectionMode, "None");
cls_TPrsStd_AISPresentation.def("UnsetSelectionMode", (void (TPrsStd_AISPresentation::*)()) &TPrsStd_AISPresentation::UnsetSelectionMode, "None");
cls_TPrsStd_AISPresentation.def("ID", (const Standard_GUID & (TPrsStd_AISPresentation::*)() const) &TPrsStd_AISPresentation::ID, "None");
cls_TPrsStd_AISPresentation.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TPrsStd_AISPresentation::*)() const) &TPrsStd_AISPresentation::NewEmpty, "None");
cls_TPrsStd_AISPresentation.def("Restore", (void (TPrsStd_AISPresentation::*)(const opencascade::handle<TDF_Attribute> &)) &TPrsStd_AISPresentation::Restore, "None", py::arg("with"));
cls_TPrsStd_AISPresentation.def("Paste", (void (TPrsStd_AISPresentation::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TPrsStd_AISPresentation::Paste, "None", py::arg("into"), py::arg("RT"));
cls_TPrsStd_AISPresentation.def("BackupCopy", (opencascade::handle<TDF_Attribute> (TPrsStd_AISPresentation::*)() const) &TPrsStd_AISPresentation::BackupCopy, "None");
cls_TPrsStd_AISPresentation.def("AfterAddition", (void (TPrsStd_AISPresentation::*)()) &TPrsStd_AISPresentation::AfterAddition, "None");
cls_TPrsStd_AISPresentation.def("BeforeRemoval", (void (TPrsStd_AISPresentation::*)()) &TPrsStd_AISPresentation::BeforeRemoval, "None");
cls_TPrsStd_AISPresentation.def("BeforeForget", (void (TPrsStd_AISPresentation::*)()) &TPrsStd_AISPresentation::BeforeForget, "None");
cls_TPrsStd_AISPresentation.def("AfterResume", (void (TPrsStd_AISPresentation::*)()) &TPrsStd_AISPresentation::AfterResume, "None");
cls_TPrsStd_AISPresentation.def("BeforeUndo", [](TPrsStd_AISPresentation &self, const opencascade::handle<TDF_AttributeDelta> & a0) -> Standard_Boolean { return self.BeforeUndo(a0); });
cls_TPrsStd_AISPresentation.def("BeforeUndo", (Standard_Boolean (TPrsStd_AISPresentation::*)(const opencascade::handle<TDF_AttributeDelta> &, const Standard_Boolean)) &TPrsStd_AISPresentation::BeforeUndo, "None", py::arg("anAttDelta"), py::arg("forceIt"));
cls_TPrsStd_AISPresentation.def("AfterUndo", [](TPrsStd_AISPresentation &self, const opencascade::handle<TDF_AttributeDelta> & a0) -> Standard_Boolean { return self.AfterUndo(a0); });
cls_TPrsStd_AISPresentation.def("AfterUndo", (Standard_Boolean (TPrsStd_AISPresentation::*)(const opencascade::handle<TDF_AttributeDelta> &, const Standard_Boolean)) &TPrsStd_AISPresentation::AfterUndo, "update AIS viewer according to delta", py::arg("anAttDelta"), py::arg("forceIt"));
cls_TPrsStd_AISPresentation.def_static("get_type_name_", (const char * (*)()) &TPrsStd_AISPresentation::get_type_name, "None");
cls_TPrsStd_AISPresentation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TPrsStd_AISPresentation::get_type_descriptor, "None");
cls_TPrsStd_AISPresentation.def("DynamicType", (const opencascade::handle<Standard_Type> & (TPrsStd_AISPresentation::*)() const) &TPrsStd_AISPresentation::DynamicType, "None");

// Enums

}