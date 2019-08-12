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
#include <TDataStd_RealList.hxx>
#include <TDF_Label.hxx>
#include <Standard_TypeDef.hxx>
#include <TColStd_ListOfReal.hxx>
#include <TDF_RelocationTable.hxx>
#include <Standard_OStream.hxx>
#include <Standard_Type.hxx>

void bind_TDataStd_RealList(py::module &mod){

py::class_<TDataStd_RealList, opencascade::handle<TDataStd_RealList>, TDF_Attribute> cls_TDataStd_RealList(mod, "TDataStd_RealList", "Contains a list of doubles.");

// Constructors
cls_TDataStd_RealList.def(py::init<>());

// Fields

// Methods
cls_TDataStd_RealList.def_static("GetID_", (const Standard_GUID & (*)()) &TDataStd_RealList::GetID, "Static methods ============== Returns the ID of the list of doubles attribute.");
cls_TDataStd_RealList.def_static("Set_", (opencascade::handle<TDataStd_RealList> (*)(const TDF_Label &)) &TDataStd_RealList::Set, "Finds or creates a list of double values attribute.", py::arg("label"));
cls_TDataStd_RealList.def_static("Set_", (opencascade::handle<TDataStd_RealList> (*)(const TDF_Label &, const Standard_GUID &)) &TDataStd_RealList::Set, "Finds or creates a list of double values attribute with explicit user defined <guid>.", py::arg("label"), py::arg("theGuid"));
cls_TDataStd_RealList.def("IsEmpty", (Standard_Boolean (TDataStd_RealList::*)() const) &TDataStd_RealList::IsEmpty, "None");
cls_TDataStd_RealList.def("Extent", (Standard_Integer (TDataStd_RealList::*)() const) &TDataStd_RealList::Extent, "None");
cls_TDataStd_RealList.def("Prepend", (void (TDataStd_RealList::*)(const Standard_Real)) &TDataStd_RealList::Prepend, "None", py::arg("value"));
cls_TDataStd_RealList.def("Append", (void (TDataStd_RealList::*)(const Standard_Real)) &TDataStd_RealList::Append, "None", py::arg("value"));
cls_TDataStd_RealList.def("SetID", (void (TDataStd_RealList::*)(const Standard_GUID &)) &TDataStd_RealList::SetID, "Sets the explicit GUID (user defined) for the attribute.", py::arg("theGuid"));
cls_TDataStd_RealList.def("SetID", (void (TDataStd_RealList::*)()) &TDataStd_RealList::SetID, "Sets default GUID for the attribute.");
cls_TDataStd_RealList.def("InsertBefore", (Standard_Boolean (TDataStd_RealList::*)(const Standard_Real, const Standard_Real)) &TDataStd_RealList::InsertBefore, "Inserts the <value> before the first meet of <before_value>.", py::arg("value"), py::arg("before_value"));
cls_TDataStd_RealList.def("InsertBeforeByIndex", (Standard_Boolean (TDataStd_RealList::*)(const Standard_Integer, const Standard_Real)) &TDataStd_RealList::InsertBeforeByIndex, "Inserts the <value> before the <index> position. The indices start with 1 .. Extent().", py::arg("index"), py::arg("before_value"));
cls_TDataStd_RealList.def("InsertAfter", (Standard_Boolean (TDataStd_RealList::*)(const Standard_Real, const Standard_Real)) &TDataStd_RealList::InsertAfter, "Inserts the <value> after the first meet of <after_value>.", py::arg("value"), py::arg("after_value"));
cls_TDataStd_RealList.def("InsertAfterByIndex", (Standard_Boolean (TDataStd_RealList::*)(const Standard_Integer, const Standard_Real)) &TDataStd_RealList::InsertAfterByIndex, "Inserts the <value> after the <index> position. The indices start with 1 .. Extent().", py::arg("index"), py::arg("after_value"));
cls_TDataStd_RealList.def("Remove", (Standard_Boolean (TDataStd_RealList::*)(const Standard_Real)) &TDataStd_RealList::Remove, "Removes the first meet of the <value>.", py::arg("value"));
cls_TDataStd_RealList.def("RemoveByIndex", (Standard_Boolean (TDataStd_RealList::*)(const Standard_Integer)) &TDataStd_RealList::RemoveByIndex, "Removes a value at <index> position.", py::arg("index"));
cls_TDataStd_RealList.def("Clear", (void (TDataStd_RealList::*)()) &TDataStd_RealList::Clear, "None");
cls_TDataStd_RealList.def("First", (Standard_Real (TDataStd_RealList::*)() const) &TDataStd_RealList::First, "None");
cls_TDataStd_RealList.def("Last", (Standard_Real (TDataStd_RealList::*)() const) &TDataStd_RealList::Last, "None");
cls_TDataStd_RealList.def("List", (const TColStd_ListOfReal & (TDataStd_RealList::*)() const) &TDataStd_RealList::List, "None");
cls_TDataStd_RealList.def("ID", (const Standard_GUID & (TDataStd_RealList::*)() const) &TDataStd_RealList::ID, "None");
cls_TDataStd_RealList.def("Restore", (void (TDataStd_RealList::*)(const opencascade::handle<TDF_Attribute> &)) &TDataStd_RealList::Restore, "None", py::arg("With"));
cls_TDataStd_RealList.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TDataStd_RealList::*)() const) &TDataStd_RealList::NewEmpty, "None");
cls_TDataStd_RealList.def("Paste", (void (TDataStd_RealList::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TDataStd_RealList::Paste, "None", py::arg("Into"), py::arg("RT"));
cls_TDataStd_RealList.def("Dump", (Standard_OStream & (TDataStd_RealList::*)(Standard_OStream &) const) &TDataStd_RealList::Dump, "None", py::arg("anOS"));
cls_TDataStd_RealList.def_static("get_type_name_", (const char * (*)()) &TDataStd_RealList::get_type_name, "None");
cls_TDataStd_RealList.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDataStd_RealList::get_type_descriptor, "None");
cls_TDataStd_RealList.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDataStd_RealList::*)() const) &TDataStd_RealList::DynamicType, "None");

// Enums

}