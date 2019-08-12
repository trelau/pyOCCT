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
#include <TDataStd_IntegerList.hxx>
#include <TDF_Label.hxx>
#include <Standard_TypeDef.hxx>
#include <TColStd_ListOfInteger.hxx>
#include <TDF_RelocationTable.hxx>
#include <Standard_OStream.hxx>
#include <Standard_Type.hxx>

void bind_TDataStd_IntegerList(py::module &mod){

py::class_<TDataStd_IntegerList, opencascade::handle<TDataStd_IntegerList>, TDF_Attribute> cls_TDataStd_IntegerList(mod, "TDataStd_IntegerList", "Contains a list of integers.");

// Constructors
cls_TDataStd_IntegerList.def(py::init<>());

// Fields

// Methods
cls_TDataStd_IntegerList.def_static("GetID_", (const Standard_GUID & (*)()) &TDataStd_IntegerList::GetID, "Static methods ============== Returns the ID of the list of integer attribute.");
cls_TDataStd_IntegerList.def_static("Set_", (opencascade::handle<TDataStd_IntegerList> (*)(const TDF_Label &)) &TDataStd_IntegerList::Set, "Finds or creates a list of integer values attribute.", py::arg("label"));
cls_TDataStd_IntegerList.def_static("Set_", (opencascade::handle<TDataStd_IntegerList> (*)(const TDF_Label &, const Standard_GUID &)) &TDataStd_IntegerList::Set, "Finds or creates a list of integer values attribute with explicit user defined <guid>.", py::arg("label"), py::arg("theGuid"));
cls_TDataStd_IntegerList.def("IsEmpty", (Standard_Boolean (TDataStd_IntegerList::*)() const) &TDataStd_IntegerList::IsEmpty, "None");
cls_TDataStd_IntegerList.def("Extent", (Standard_Integer (TDataStd_IntegerList::*)() const) &TDataStd_IntegerList::Extent, "None");
cls_TDataStd_IntegerList.def("Prepend", (void (TDataStd_IntegerList::*)(const Standard_Integer)) &TDataStd_IntegerList::Prepend, "None", py::arg("value"));
cls_TDataStd_IntegerList.def("Append", (void (TDataStd_IntegerList::*)(const Standard_Integer)) &TDataStd_IntegerList::Append, "None", py::arg("value"));
cls_TDataStd_IntegerList.def("SetID", (void (TDataStd_IntegerList::*)(const Standard_GUID &)) &TDataStd_IntegerList::SetID, "Sets the explicit GUID (user defined) for the attribute.", py::arg("theGuid"));
cls_TDataStd_IntegerList.def("SetID", (void (TDataStd_IntegerList::*)()) &TDataStd_IntegerList::SetID, "Sets default GUID for the attribute.");
cls_TDataStd_IntegerList.def("InsertBefore", (Standard_Boolean (TDataStd_IntegerList::*)(const Standard_Integer, const Standard_Integer)) &TDataStd_IntegerList::InsertBefore, "Inserts the <value> before the first meet of <before_value>.", py::arg("value"), py::arg("before_value"));
cls_TDataStd_IntegerList.def("InsertBeforeByIndex", (Standard_Boolean (TDataStd_IntegerList::*)(const Standard_Integer, const Standard_Integer)) &TDataStd_IntegerList::InsertBeforeByIndex, "Inserts the <value> before the <index> position. The indices start with 1 .. Extent().", py::arg("index"), py::arg("before_value"));
cls_TDataStd_IntegerList.def("InsertAfter", (Standard_Boolean (TDataStd_IntegerList::*)(const Standard_Integer, const Standard_Integer)) &TDataStd_IntegerList::InsertAfter, "Inserts the <value> after the first meet of <after_value>.", py::arg("value"), py::arg("after_value"));
cls_TDataStd_IntegerList.def("InsertAfterByIndex", (Standard_Boolean (TDataStd_IntegerList::*)(const Standard_Integer, const Standard_Integer)) &TDataStd_IntegerList::InsertAfterByIndex, "Inserts the <value> after the <index> position. The indices start with 1 .. Extent().", py::arg("index"), py::arg("after_value"));
cls_TDataStd_IntegerList.def("Remove", (Standard_Boolean (TDataStd_IntegerList::*)(const Standard_Integer)) &TDataStd_IntegerList::Remove, "Removes the first meet of the <value>.", py::arg("value"));
cls_TDataStd_IntegerList.def("RemoveByIndex", (Standard_Boolean (TDataStd_IntegerList::*)(const Standard_Integer)) &TDataStd_IntegerList::RemoveByIndex, "Removes a value at <index> position.", py::arg("index"));
cls_TDataStd_IntegerList.def("Clear", (void (TDataStd_IntegerList::*)()) &TDataStd_IntegerList::Clear, "None");
cls_TDataStd_IntegerList.def("First", (Standard_Integer (TDataStd_IntegerList::*)() const) &TDataStd_IntegerList::First, "None");
cls_TDataStd_IntegerList.def("Last", (Standard_Integer (TDataStd_IntegerList::*)() const) &TDataStd_IntegerList::Last, "None");
cls_TDataStd_IntegerList.def("List", (const TColStd_ListOfInteger & (TDataStd_IntegerList::*)() const) &TDataStd_IntegerList::List, "None");
cls_TDataStd_IntegerList.def("ID", (const Standard_GUID & (TDataStd_IntegerList::*)() const) &TDataStd_IntegerList::ID, "None");
cls_TDataStd_IntegerList.def("Restore", (void (TDataStd_IntegerList::*)(const opencascade::handle<TDF_Attribute> &)) &TDataStd_IntegerList::Restore, "None", py::arg("With"));
cls_TDataStd_IntegerList.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TDataStd_IntegerList::*)() const) &TDataStd_IntegerList::NewEmpty, "None");
cls_TDataStd_IntegerList.def("Paste", (void (TDataStd_IntegerList::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TDataStd_IntegerList::Paste, "None", py::arg("Into"), py::arg("RT"));
cls_TDataStd_IntegerList.def("Dump", (Standard_OStream & (TDataStd_IntegerList::*)(Standard_OStream &) const) &TDataStd_IntegerList::Dump, "None", py::arg("anOS"));
cls_TDataStd_IntegerList.def_static("get_type_name_", (const char * (*)()) &TDataStd_IntegerList::get_type_name, "None");
cls_TDataStd_IntegerList.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDataStd_IntegerList::get_type_descriptor, "None");
cls_TDataStd_IntegerList.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDataStd_IntegerList::*)() const) &TDataStd_IntegerList::DynamicType, "None");

// Enums

}