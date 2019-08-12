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
#include <TDataStd_BooleanList.hxx>
#include <TDF_Label.hxx>
#include <Standard_TypeDef.hxx>
#include <TDataStd_ListOfByte.hxx>
#include <TDF_RelocationTable.hxx>
#include <Standard_OStream.hxx>
#include <Standard_Type.hxx>

void bind_TDataStd_BooleanList(py::module &mod){

py::class_<TDataStd_BooleanList, opencascade::handle<TDataStd_BooleanList>, TDF_Attribute> cls_TDataStd_BooleanList(mod, "TDataStd_BooleanList", "Contains a list of bolleans.");

// Constructors
cls_TDataStd_BooleanList.def(py::init<>());

// Fields

// Methods
cls_TDataStd_BooleanList.def_static("GetID_", (const Standard_GUID & (*)()) &TDataStd_BooleanList::GetID, "Static methods ============== Returns the ID of the list of booleans attribute.");
cls_TDataStd_BooleanList.def_static("Set_", (opencascade::handle<TDataStd_BooleanList> (*)(const TDF_Label &)) &TDataStd_BooleanList::Set, "Finds or creates a list of boolean values attribute.", py::arg("label"));
cls_TDataStd_BooleanList.def_static("Set_", (opencascade::handle<TDataStd_BooleanList> (*)(const TDF_Label &, const Standard_GUID &)) &TDataStd_BooleanList::Set, "Finds or creates a list of boolean values attribute with explicit user defined <guid>.", py::arg("label"), py::arg("theGuid"));
cls_TDataStd_BooleanList.def("IsEmpty", (Standard_Boolean (TDataStd_BooleanList::*)() const) &TDataStd_BooleanList::IsEmpty, "None");
cls_TDataStd_BooleanList.def("Extent", (Standard_Integer (TDataStd_BooleanList::*)() const) &TDataStd_BooleanList::Extent, "None");
cls_TDataStd_BooleanList.def("Prepend", (void (TDataStd_BooleanList::*)(const Standard_Boolean)) &TDataStd_BooleanList::Prepend, "None", py::arg("value"));
cls_TDataStd_BooleanList.def("Append", (void (TDataStd_BooleanList::*)(const Standard_Boolean)) &TDataStd_BooleanList::Append, "None", py::arg("value"));
cls_TDataStd_BooleanList.def("Clear", (void (TDataStd_BooleanList::*)()) &TDataStd_BooleanList::Clear, "None");
cls_TDataStd_BooleanList.def("First", (Standard_Boolean (TDataStd_BooleanList::*)() const) &TDataStd_BooleanList::First, "None");
cls_TDataStd_BooleanList.def("Last", (Standard_Boolean (TDataStd_BooleanList::*)() const) &TDataStd_BooleanList::Last, "None");
cls_TDataStd_BooleanList.def("List", (const TDataStd_ListOfByte & (TDataStd_BooleanList::*)() const) &TDataStd_BooleanList::List, "1 - means TRUE, 0 - means FALSE.");
cls_TDataStd_BooleanList.def("InsertBefore", (Standard_Boolean (TDataStd_BooleanList::*)(const Standard_Integer, const Standard_Boolean)) &TDataStd_BooleanList::InsertBefore, "Inserts the <value> before the <index> position. The indices start with 1 .. Extent().", py::arg("index"), py::arg("before_value"));
cls_TDataStd_BooleanList.def("InsertAfter", (Standard_Boolean (TDataStd_BooleanList::*)(const Standard_Integer, const Standard_Boolean)) &TDataStd_BooleanList::InsertAfter, "Inserts the <value> after the <index> position. The indices start with 1 .. Extent().", py::arg("index"), py::arg("after_value"));
cls_TDataStd_BooleanList.def("Remove", (Standard_Boolean (TDataStd_BooleanList::*)(const Standard_Integer)) &TDataStd_BooleanList::Remove, "Removes a value at <index> position.", py::arg("index"));
cls_TDataStd_BooleanList.def("SetID", (void (TDataStd_BooleanList::*)(const Standard_GUID &)) &TDataStd_BooleanList::SetID, "Sets the explicit GUID (user defined) for the attribute.", py::arg("theGuid"));
cls_TDataStd_BooleanList.def("SetID", (void (TDataStd_BooleanList::*)()) &TDataStd_BooleanList::SetID, "Sets default GUID for the attribute.");
cls_TDataStd_BooleanList.def("ID", (const Standard_GUID & (TDataStd_BooleanList::*)() const) &TDataStd_BooleanList::ID, "None");
cls_TDataStd_BooleanList.def("Restore", (void (TDataStd_BooleanList::*)(const opencascade::handle<TDF_Attribute> &)) &TDataStd_BooleanList::Restore, "None", py::arg("With"));
cls_TDataStd_BooleanList.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TDataStd_BooleanList::*)() const) &TDataStd_BooleanList::NewEmpty, "None");
cls_TDataStd_BooleanList.def("Paste", (void (TDataStd_BooleanList::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TDataStd_BooleanList::Paste, "None", py::arg("Into"), py::arg("RT"));
cls_TDataStd_BooleanList.def("Dump", (Standard_OStream & (TDataStd_BooleanList::*)(Standard_OStream &) const) &TDataStd_BooleanList::Dump, "None", py::arg("anOS"));
cls_TDataStd_BooleanList.def_static("get_type_name_", (const char * (*)()) &TDataStd_BooleanList::get_type_name, "None");
cls_TDataStd_BooleanList.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDataStd_BooleanList::get_type_descriptor, "None");
cls_TDataStd_BooleanList.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDataStd_BooleanList::*)() const) &TDataStd_BooleanList::DynamicType, "None");

// Enums

}