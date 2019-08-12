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
#include <TObj_TNameContainer.hxx>
#include <TDF_Label.hxx>
#include <TCollection_HExtendedString.hxx>
#include <Standard_TypeDef.hxx>
#include <TObj_Container.hxx>
#include <TDF_RelocationTable.hxx>
#include <Standard_Type.hxx>

void bind_TObj_TNameContainer(py::module &mod){

py::class_<TObj_TNameContainer, opencascade::handle<TObj_TNameContainer>, TDF_Attribute> cls_TObj_TNameContainer(mod, "TObj_TNameContainer", "This class provides OCAF Attribute to storing the unique names of object in model.");

// Constructors
cls_TObj_TNameContainer.def(py::init<>());

// Fields

// Methods
cls_TObj_TNameContainer.def_static("GetID_", (const Standard_GUID & (*)()) &TObj_TNameContainer::GetID, "This method is used in implementation of ID()");
cls_TObj_TNameContainer.def("ID", (const Standard_GUID & (TObj_TNameContainer::*)() const) &TObj_TNameContainer::ID, "Returns the ID of TObj_TNameContainer attribute.");
cls_TObj_TNameContainer.def_static("Set_", (opencascade::handle<TObj_TNameContainer> (*)(const TDF_Label &)) &TObj_TNameContainer::Set, "Creates TObj_DataMapOfNameLabel attribute on given label if not exist", py::arg("theLabel"));
cls_TObj_TNameContainer.def("RecordName", (void (TObj_TNameContainer::*)(const opencascade::handle<TCollection_HExtendedString> &, const TDF_Label &)) &TObj_TNameContainer::RecordName, "Records name with label attached", py::arg("theName"), py::arg("theLabel"));
cls_TObj_TNameContainer.def("RemoveName", (void (TObj_TNameContainer::*)(const opencascade::handle<TCollection_HExtendedString> &)) &TObj_TNameContainer::RemoveName, "Remove name from the map", py::arg("theName"));
cls_TObj_TNameContainer.def("IsRegistered", (Standard_Boolean (TObj_TNameContainer::*)(const opencascade::handle<TCollection_HExtendedString> &) const) &TObj_TNameContainer::IsRegistered, "Return True is theName is registered in the Map", py::arg("theName"));
cls_TObj_TNameContainer.def("Clear", (void (TObj_TNameContainer::*)()) &TObj_TNameContainer::Clear, "Remove all names registered in container");
cls_TObj_TNameContainer.def("Set", (void (TObj_TNameContainer::*)(const TObj_DataMapOfNameLabel &)) &TObj_TNameContainer::Set, "Sets the TObj_DataMapOfNameLabel object", py::arg("theElem"));
cls_TObj_TNameContainer.def("Get", (const TObj_DataMapOfNameLabel & (TObj_TNameContainer::*)() const) &TObj_TNameContainer::Get, "Returns the TObj_DataMapOfNameLabel object");
cls_TObj_TNameContainer.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TObj_TNameContainer::*)() const) &TObj_TNameContainer::NewEmpty, "Returns an new empty TObj_TNameContainer attribute. It is used by the copy algorithm.");
cls_TObj_TNameContainer.def("Restore", (void (TObj_TNameContainer::*)(const opencascade::handle<TDF_Attribute> &)) &TObj_TNameContainer::Restore, "Restores the backuped contents from <theWith> into this one. It is used when aborting a transaction.", py::arg("theWith"));
cls_TObj_TNameContainer.def("Paste", (void (TObj_TNameContainer::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TObj_TNameContainer::Paste, "This method is used when copying an attribute from a source structure into a target structure.", py::arg("theInto"), py::arg("theRT"));
cls_TObj_TNameContainer.def_static("get_type_name_", (const char * (*)()) &TObj_TNameContainer::get_type_name, "None");
cls_TObj_TNameContainer.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TObj_TNameContainer::get_type_descriptor, "None");
cls_TObj_TNameContainer.def("DynamicType", (const opencascade::handle<Standard_Type> & (TObj_TNameContainer::*)() const) &TObj_TNameContainer::DynamicType, "None");

// Enums

}