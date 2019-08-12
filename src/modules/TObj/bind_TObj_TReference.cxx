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
#include <TObj_TReference.hxx>
#include <TDF_Label.hxx>
#include <TObj_Object.hxx>
#include <TDF_RelocationTable.hxx>
#include <Standard_TypeDef.hxx>
#include <TDF_AttributeDelta.hxx>
#include <Standard_Type.hxx>

void bind_TObj_TReference(py::module &mod){

py::class_<TObj_TReference, opencascade::handle<TObj_TReference>, TDF_Attribute> cls_TObj_TReference(mod, "TObj_TReference", "Attribute for storing references to the objects which implement TObj_Object interface in the OCAF tree. Its persistency mechanism provides transparent method for storing cross-model references. Each reference, when created, registers itself in the referred object, to support back references");

// Constructors
cls_TObj_TReference.def(py::init<>());

// Fields

// Methods
cls_TObj_TReference.def_static("GetID_", (const Standard_GUID & (*)()) &TObj_TReference::GetID, "This method is used in implementation of ID()");
cls_TObj_TReference.def("ID", (const Standard_GUID & (TObj_TReference::*)() const) &TObj_TReference::ID, "Returns the ID of TObj_TReference attribute.");
cls_TObj_TReference.def_static("Set_", (opencascade::handle<TObj_TReference> (*)(const TDF_Label &, const opencascade::handle<TObj_Object> &, const opencascade::handle<TObj_Object> &)) &TObj_TReference::Set, "Creates reference on TDF_Label <theLabel> to the object <theObject> and creates backreference from the object <theObject> to <theMaster> one.", py::arg("theLabel"), py::arg("theObject"), py::arg("theMaster"));
cls_TObj_TReference.def("Set", (void (TObj_TReference::*)(const opencascade::handle<TObj_Object> &, const TDF_Label &)) &TObj_TReference::Set, "Sets the reference to the theObject", py::arg("theObject"), py::arg("theMasterLabel"));
cls_TObj_TReference.def("Set", (void (TObj_TReference::*)(const TDF_Label &, const TDF_Label &)) &TObj_TReference::Set, "Sets the reference to the theObject at indicated Label. It is method for persistent only. Don`t use anywhere else.", py::arg("theLabel"), py::arg("theMasterLabel"));
cls_TObj_TReference.def("Get", (opencascade::handle<TObj_Object> (TObj_TReference::*)() const) &TObj_TReference::Get, "Returns the referenced theObject");
cls_TObj_TReference.def("GetMasterLabel", (TDF_Label (TObj_TReference::*)() const) &TObj_TReference::GetMasterLabel, "Returns the Label of master object.");
cls_TObj_TReference.def("GetLabel", (TDF_Label (TObj_TReference::*)() const) &TObj_TReference::GetLabel, "Returns the referred label.");
cls_TObj_TReference.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TObj_TReference::*)() const) &TObj_TReference::NewEmpty, "Returns an new empty TObj_TReference attribute. It is used by the copy algorithm.");
cls_TObj_TReference.def("Restore", (void (TObj_TReference::*)(const opencascade::handle<TDF_Attribute> &)) &TObj_TReference::Restore, "Restores the backuped contents from <theWith> into this one. It is used when aborting a transaction.", py::arg("theWith"));
cls_TObj_TReference.def("Paste", (void (TObj_TReference::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TObj_TReference::Paste, "This method is used when copying an attribute from a source structure into a target structure.", py::arg("theInto"), py::arg("theRT"));
cls_TObj_TReference.def("BeforeForget", (void (TObj_TReference::*)()) &TObj_TReference::BeforeForget, "Remove back references of it reference if it is in other document.");
cls_TObj_TReference.def("BeforeUndo", [](TObj_TReference &self, const opencascade::handle<TDF_AttributeDelta> & a0) -> Standard_Boolean { return self.BeforeUndo(a0); });
cls_TObj_TReference.def("BeforeUndo", (Standard_Boolean (TObj_TReference::*)(const opencascade::handle<TDF_AttributeDelta> &, const Standard_Boolean)) &TObj_TReference::BeforeUndo, "It is necessary for tranzaction mechanism (Undo/Redo).", py::arg("theDelta"), py::arg("isForced"));
cls_TObj_TReference.def("AfterUndo", [](TObj_TReference &self, const opencascade::handle<TDF_AttributeDelta> & a0) -> Standard_Boolean { return self.AfterUndo(a0); });
cls_TObj_TReference.def("AfterUndo", (Standard_Boolean (TObj_TReference::*)(const opencascade::handle<TDF_AttributeDelta> &, const Standard_Boolean)) &TObj_TReference::AfterUndo, "It is necessary for tranzaction mechanism (Undo/Redo).", py::arg("theDelta"), py::arg("isForced"));
cls_TObj_TReference.def("AfterResume", (void (TObj_TReference::*)()) &TObj_TReference::AfterResume, "Check if back reference exists for reference.");
cls_TObj_TReference.def("AfterRetrieval", [](TObj_TReference &self) -> Standard_Boolean { return self.AfterRetrieval(); });
cls_TObj_TReference.def("AfterRetrieval", (Standard_Boolean (TObj_TReference::*)(const Standard_Boolean)) &TObj_TReference::AfterRetrieval, "Called after retrieval reference from file.", py::arg("forceIt"));
cls_TObj_TReference.def_static("get_type_name_", (const char * (*)()) &TObj_TReference::get_type_name, "None");
cls_TObj_TReference.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TObj_TReference::get_type_descriptor, "None");
cls_TObj_TReference.def("DynamicType", (const opencascade::handle<Standard_Type> & (TObj_TReference::*)() const) &TObj_TReference::DynamicType, "None");

// Enums

}