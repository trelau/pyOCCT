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
#include <TDataStd_ExtStringList.hxx>
#include <TDF_Label.hxx>
#include <Standard_TypeDef.hxx>
#include <TCollection_ExtendedString.hxx>
#include <TDataStd_ListOfExtendedString.hxx>
#include <TDF_RelocationTable.hxx>
#include <Standard_OStream.hxx>
#include <Standard_Type.hxx>

void bind_TDataStd_ExtStringList(py::module &mod){

py::class_<TDataStd_ExtStringList, opencascade::handle<TDataStd_ExtStringList>, TDF_Attribute> cls_TDataStd_ExtStringList(mod, "TDataStd_ExtStringList", "Contains a list of ExtendedString.");

// Constructors
cls_TDataStd_ExtStringList.def(py::init<>());

// Fields

// Methods
cls_TDataStd_ExtStringList.def_static("GetID_", (const Standard_GUID & (*)()) &TDataStd_ExtStringList::GetID, "Static methods ============== Returns the ID of the list of strings attribute.");
cls_TDataStd_ExtStringList.def_static("Set_", (opencascade::handle<TDataStd_ExtStringList> (*)(const TDF_Label &)) &TDataStd_ExtStringList::Set, "Finds or creates a list of string values attribute with explicit user defined <guid>.", py::arg("label"));
cls_TDataStd_ExtStringList.def_static("Set_", (opencascade::handle<TDataStd_ExtStringList> (*)(const TDF_Label &, const Standard_GUID &)) &TDataStd_ExtStringList::Set, "Finds or creates a list of string values attribute.", py::arg("label"), py::arg("theGuid"));
cls_TDataStd_ExtStringList.def("IsEmpty", (Standard_Boolean (TDataStd_ExtStringList::*)() const) &TDataStd_ExtStringList::IsEmpty, "None");
cls_TDataStd_ExtStringList.def("Extent", (Standard_Integer (TDataStd_ExtStringList::*)() const) &TDataStd_ExtStringList::Extent, "None");
cls_TDataStd_ExtStringList.def("Prepend", (void (TDataStd_ExtStringList::*)(const TCollection_ExtendedString &)) &TDataStd_ExtStringList::Prepend, "None", py::arg("value"));
cls_TDataStd_ExtStringList.def("Append", (void (TDataStd_ExtStringList::*)(const TCollection_ExtendedString &)) &TDataStd_ExtStringList::Append, "None", py::arg("value"));
cls_TDataStd_ExtStringList.def("SetID", (void (TDataStd_ExtStringList::*)(const Standard_GUID &)) &TDataStd_ExtStringList::SetID, "Sets the explicit GUID (user defined) for the attribute.", py::arg("theGuid"));
cls_TDataStd_ExtStringList.def("SetID", (void (TDataStd_ExtStringList::*)()) &TDataStd_ExtStringList::SetID, "Sets default GUID for the attribute.");
cls_TDataStd_ExtStringList.def("InsertBefore", (Standard_Boolean (TDataStd_ExtStringList::*)(const TCollection_ExtendedString &, const TCollection_ExtendedString &)) &TDataStd_ExtStringList::InsertBefore, "Inserts the <value> before the first meet of <before_value>.", py::arg("value"), py::arg("before_value"));
cls_TDataStd_ExtStringList.def("InsertBefore", (Standard_Boolean (TDataStd_ExtStringList::*)(const Standard_Integer, const TCollection_ExtendedString &)) &TDataStd_ExtStringList::InsertBefore, "Inserts the <value> before the <index> position. The indices start with 1 .. Extent().", py::arg("index"), py::arg("before_value"));
cls_TDataStd_ExtStringList.def("InsertAfter", (Standard_Boolean (TDataStd_ExtStringList::*)(const TCollection_ExtendedString &, const TCollection_ExtendedString &)) &TDataStd_ExtStringList::InsertAfter, "Inserts the <value> after the first meet of <after_value>.", py::arg("value"), py::arg("after_value"));
cls_TDataStd_ExtStringList.def("InsertAfter", (Standard_Boolean (TDataStd_ExtStringList::*)(const Standard_Integer, const TCollection_ExtendedString &)) &TDataStd_ExtStringList::InsertAfter, "Inserts the <value> after the <index> position. The indices start with 1 .. Extent().", py::arg("index"), py::arg("after_value"));
cls_TDataStd_ExtStringList.def("Remove", (Standard_Boolean (TDataStd_ExtStringList::*)(const TCollection_ExtendedString &)) &TDataStd_ExtStringList::Remove, "Removes the first meet of the <value>.", py::arg("value"));
cls_TDataStd_ExtStringList.def("Remove", (Standard_Boolean (TDataStd_ExtStringList::*)(const Standard_Integer)) &TDataStd_ExtStringList::Remove, "Removes a value at <index> position.", py::arg("index"));
cls_TDataStd_ExtStringList.def("Clear", (void (TDataStd_ExtStringList::*)()) &TDataStd_ExtStringList::Clear, "None");
cls_TDataStd_ExtStringList.def("First", (const TCollection_ExtendedString & (TDataStd_ExtStringList::*)() const) &TDataStd_ExtStringList::First, "None");
cls_TDataStd_ExtStringList.def("Last", (const TCollection_ExtendedString & (TDataStd_ExtStringList::*)() const) &TDataStd_ExtStringList::Last, "None");
cls_TDataStd_ExtStringList.def("List", (const TDataStd_ListOfExtendedString & (TDataStd_ExtStringList::*)() const) &TDataStd_ExtStringList::List, "None");
cls_TDataStd_ExtStringList.def("ID", (const Standard_GUID & (TDataStd_ExtStringList::*)() const) &TDataStd_ExtStringList::ID, "None");
cls_TDataStd_ExtStringList.def("Restore", (void (TDataStd_ExtStringList::*)(const opencascade::handle<TDF_Attribute> &)) &TDataStd_ExtStringList::Restore, "None", py::arg("With"));
cls_TDataStd_ExtStringList.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TDataStd_ExtStringList::*)() const) &TDataStd_ExtStringList::NewEmpty, "None");
cls_TDataStd_ExtStringList.def("Paste", (void (TDataStd_ExtStringList::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TDataStd_ExtStringList::Paste, "None", py::arg("Into"), py::arg("RT"));
cls_TDataStd_ExtStringList.def("Dump", (Standard_OStream & (TDataStd_ExtStringList::*)(Standard_OStream &) const) &TDataStd_ExtStringList::Dump, "None", py::arg("anOS"));
cls_TDataStd_ExtStringList.def_static("get_type_name_", (const char * (*)()) &TDataStd_ExtStringList::get_type_name, "None");
cls_TDataStd_ExtStringList.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDataStd_ExtStringList::get_type_descriptor, "None");
cls_TDataStd_ExtStringList.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDataStd_ExtStringList::*)() const) &TDataStd_ExtStringList::DynamicType, "None");

// Enums

}