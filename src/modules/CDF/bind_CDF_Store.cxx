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
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <CDM_Document.hxx>
#include <Standard_TypeDef.hxx>
#include <TCollection_ExtendedString.hxx>
#include <CDF_StoreSetNameStatus.hxx>
#include <CDF_SubComponentStatus.hxx>
#include <PCDM_StoreStatus.hxx>
#include <CDF_StoreList.hxx>
#include <CDF_Store.hxx>

void bind_CDF_Store(py::module &mod){

py::class_<CDF_Store> cls_CDF_Store(mod, "CDF_Store", "None");

// Constructors
cls_CDF_Store.def(py::init<const opencascade::handle<CDM_Document> &>(), py::arg("aDocument"));

// Fields

// Methods
// cls_CDF_Store.def_static("operator new_", (void * (*)(size_t)) &CDF_Store::operator new, "None", py::arg("theSize"));
// cls_CDF_Store.def_static("operator delete_", (void (*)(void *)) &CDF_Store::operator delete, "None", py::arg("theAddress"));
// cls_CDF_Store.def_static("operator new[]_", (void * (*)(size_t)) &CDF_Store::operator new[], "None", py::arg("theSize"));
// cls_CDF_Store.def_static("operator delete[]_", (void (*)(void *)) &CDF_Store::operator delete[], "None", py::arg("theAddress"));
// cls_CDF_Store.def_static("operator new_", (void * (*)(size_t, void *)) &CDF_Store::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_CDF_Store.def_static("operator delete_", (void (*)(void *, void *)) &CDF_Store::operator delete, "None", py::arg(""), py::arg(""));
cls_CDF_Store.def("Folder", (Standard_ExtString (CDF_Store::*)() const) &CDF_Store::Folder, "returns the folder in which the current document will be stored.");
cls_CDF_Store.def("Name", (Standard_ExtString (CDF_Store::*)() const) &CDF_Store::Name, "returns the name under which the current document will be stored");
cls_CDF_Store.def("IsStored", (Standard_Boolean (CDF_Store::*)() const) &CDF_Store::IsStored, "returns true if the current document is already stored");
cls_CDF_Store.def("IsModified", (Standard_Boolean (CDF_Store::*)() const) &CDF_Store::IsModified, "None");
cls_CDF_Store.def("CurrentIsConsistent", (Standard_Boolean (CDF_Store::*)() const) &CDF_Store::CurrentIsConsistent, "None");
cls_CDF_Store.def("IsConsistent", (Standard_Boolean (CDF_Store::*)() const) &CDF_Store::IsConsistent, "None");
cls_CDF_Store.def("HasAPreviousVersion", (Standard_Boolean (CDF_Store::*)() const) &CDF_Store::HasAPreviousVersion, "None");
cls_CDF_Store.def("PreviousVersion", (Standard_ExtString (CDF_Store::*)() const) &CDF_Store::PreviousVersion, "None");
cls_CDF_Store.def("IsMainDocument", (Standard_Boolean (CDF_Store::*)() const) &CDF_Store::IsMainDocument, "returns true if the currentdocument is the main one, ie the document of the current selection.");
cls_CDF_Store.def("SetFolder", (Standard_Boolean (CDF_Store::*)(const TCollection_ExtendedString &)) &CDF_Store::SetFolder, "defines the folder in which the document should be stored. returns Standard_True if the Folder exists, Standard_False otherwise.", py::arg("aFolder"));
cls_CDF_Store.def("SetName", (CDF_StoreSetNameStatus (CDF_Store::*)(const Standard_ExtString)) &CDF_Store::SetName, "defines the name under which the document should be stored.", py::arg("aName"));
cls_CDF_Store.def("SetComment", (void (CDF_Store::*)(const Standard_ExtString)) &CDF_Store::SetComment, "None", py::arg("aComment"));
cls_CDF_Store.def("Comment", (Standard_ExtString (CDF_Store::*)() const) &CDF_Store::Comment, "None");
cls_CDF_Store.def("RecheckName", (CDF_StoreSetNameStatus (CDF_Store::*)()) &CDF_Store::RecheckName, "defines the name under which the document should be stored. uses for example after modification of the folder.");
cls_CDF_Store.def("SetPreviousVersion", (Standard_Boolean (CDF_Store::*)(const Standard_ExtString)) &CDF_Store::SetPreviousVersion, "None", py::arg("aPreviousVersion"));
cls_CDF_Store.def("Realize", (void (CDF_Store::*)()) &CDF_Store::Realize, "None");
cls_CDF_Store.def("Path", (Standard_ExtString (CDF_Store::*)() const) &CDF_Store::Path, "returns the complete path of the created meta-data.");
cls_CDF_Store.def("MetaDataPath", (Standard_ExtString (CDF_Store::*)() const) &CDF_Store::MetaDataPath, "returns the path of the previous store is the object is already stored, otherwise an empty string;");
cls_CDF_Store.def("Description", (Standard_ExtString (CDF_Store::*)() const) &CDF_Store::Description, "returns the description of the format of the main object.");
cls_CDF_Store.def("InitComponent", (void (CDF_Store::*)()) &CDF_Store::InitComponent, "Allows to Start a new Iteration from beginning");
cls_CDF_Store.def("MoreComponent", (Standard_Boolean (CDF_Store::*)() const) &CDF_Store::MoreComponent, "Returns True if there are more entries to return");
cls_CDF_Store.def("NextComponent", (void (CDF_Store::*)()) &CDF_Store::NextComponent, "Go to the next entry (if there is not, Value will raise an exception)");
cls_CDF_Store.def("SetCurrent", (void (CDF_Store::*)()) &CDF_Store::SetCurrent, "None");
cls_CDF_Store.def("Component", (Standard_ExtString (CDF_Store::*)() const) &CDF_Store::Component, "Returns item value of current entry");
cls_CDF_Store.def("HasSubComponents", (Standard_Boolean (CDF_Store::*)() const) &CDF_Store::HasSubComponents, "None");
cls_CDF_Store.def("SubComponentStatus", (CDF_SubComponentStatus (CDF_Store::*)(const Standard_ExtString) const) &CDF_Store::SubComponentStatus, "None", py::arg("aPresentation"));
cls_CDF_Store.def("SetCurrent", (void (CDF_Store::*)(const Standard_ExtString)) &CDF_Store::SetCurrent, "None", py::arg("aPresentation"));
cls_CDF_Store.def("SetMain", (void (CDF_Store::*)()) &CDF_Store::SetMain, "the two following methods can be used just after Realize or Import -- method to know if thes methods worked correctly, and if not why.");
cls_CDF_Store.def("StoreStatus", (PCDM_StoreStatus (CDF_Store::*)() const) &CDF_Store::StoreStatus, "None");
cls_CDF_Store.def("AssociatedStatusText", (Standard_ExtString (CDF_Store::*)() const) &CDF_Store::AssociatedStatusText, "None");
cls_CDF_Store.def("SetName", (CDF_StoreSetNameStatus (CDF_Store::*)(const TCollection_ExtendedString &)) &CDF_Store::SetName, "defines the name under which the document should be stored.", py::arg("aName"));
cls_CDF_Store.def("SetFolder", (Standard_Boolean (CDF_Store::*)(const Standard_ExtString)) &CDF_Store::SetFolder, "defines the folder in which the document should be stored. returns Standard_True if the Folder exists, Standard_False otherwise.", py::arg("aFolder"));

// Enums

}