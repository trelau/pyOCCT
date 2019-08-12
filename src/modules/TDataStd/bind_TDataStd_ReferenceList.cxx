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
#include <TDataStd_ReferenceList.hxx>
#include <TDF_Label.hxx>
#include <Standard_TypeDef.hxx>
#include <TDF_LabelList.hxx>
#include <TDF_RelocationTable.hxx>
#include <TDF_DataSet.hxx>
#include <Standard_OStream.hxx>
#include <Standard_Type.hxx>

void bind_TDataStd_ReferenceList(py::module &mod){

py::class_<TDataStd_ReferenceList, opencascade::handle<TDataStd_ReferenceList>, TDF_Attribute> cls_TDataStd_ReferenceList(mod, "TDataStd_ReferenceList", "Contains a list of references.");

// Constructors
cls_TDataStd_ReferenceList.def(py::init<>());

// Fields

// Methods
cls_TDataStd_ReferenceList.def_static("GetID_", (const Standard_GUID & (*)()) &TDataStd_ReferenceList::GetID, "Static methods ============== Returns the ID of the list of references (labels) attribute.");
cls_TDataStd_ReferenceList.def_static("Set_", (opencascade::handle<TDataStd_ReferenceList> (*)(const TDF_Label &)) &TDataStd_ReferenceList::Set, "Finds or creates a list of reference values (labels) attribute.", py::arg("label"));
cls_TDataStd_ReferenceList.def_static("Set_", (opencascade::handle<TDataStd_ReferenceList> (*)(const TDF_Label &, const Standard_GUID &)) &TDataStd_ReferenceList::Set, "Finds or creates a list of reference values (labels) attribute with explicit user defined <guid>.", py::arg("label"), py::arg("theGuid"));
cls_TDataStd_ReferenceList.def("IsEmpty", (Standard_Boolean (TDataStd_ReferenceList::*)() const) &TDataStd_ReferenceList::IsEmpty, "None");
cls_TDataStd_ReferenceList.def("Extent", (Standard_Integer (TDataStd_ReferenceList::*)() const) &TDataStd_ReferenceList::Extent, "None");
cls_TDataStd_ReferenceList.def("Prepend", (void (TDataStd_ReferenceList::*)(const TDF_Label &)) &TDataStd_ReferenceList::Prepend, "None", py::arg("value"));
cls_TDataStd_ReferenceList.def("Append", (void (TDataStd_ReferenceList::*)(const TDF_Label &)) &TDataStd_ReferenceList::Append, "None", py::arg("value"));
cls_TDataStd_ReferenceList.def("SetID", (void (TDataStd_ReferenceList::*)(const Standard_GUID &)) &TDataStd_ReferenceList::SetID, "Sets the explicit GUID (user defined) for the attribute.", py::arg("theGuid"));
cls_TDataStd_ReferenceList.def("SetID", (void (TDataStd_ReferenceList::*)()) &TDataStd_ReferenceList::SetID, "Sets default GUID for the attribute.");
cls_TDataStd_ReferenceList.def("InsertBefore", (Standard_Boolean (TDataStd_ReferenceList::*)(const TDF_Label &, const TDF_Label &)) &TDataStd_ReferenceList::InsertBefore, "Inserts the <value> before the first meet of <before_value>.", py::arg("value"), py::arg("before_value"));
cls_TDataStd_ReferenceList.def("InsertBefore", (Standard_Boolean (TDataStd_ReferenceList::*)(const Standard_Integer, const TDF_Label &)) &TDataStd_ReferenceList::InsertBefore, "Inserts the label before the <index> position. The indices start with 1 .. Extent().", py::arg("index"), py::arg("before_value"));
cls_TDataStd_ReferenceList.def("InsertAfter", (Standard_Boolean (TDataStd_ReferenceList::*)(const TDF_Label &, const TDF_Label &)) &TDataStd_ReferenceList::InsertAfter, "Inserts the <value> after the first meet of <after_value>.", py::arg("value"), py::arg("after_value"));
cls_TDataStd_ReferenceList.def("InsertAfter", (Standard_Boolean (TDataStd_ReferenceList::*)(const Standard_Integer, const TDF_Label &)) &TDataStd_ReferenceList::InsertAfter, "Inserts the label after the <index> position. The indices start with 1 .. Extent().", py::arg("index"), py::arg("after_value"));
cls_TDataStd_ReferenceList.def("Remove", (Standard_Boolean (TDataStd_ReferenceList::*)(const TDF_Label &)) &TDataStd_ReferenceList::Remove, "Removes the first meet of the <value>.", py::arg("value"));
cls_TDataStd_ReferenceList.def("Remove", (Standard_Boolean (TDataStd_ReferenceList::*)(const Standard_Integer)) &TDataStd_ReferenceList::Remove, "Removes a label at 'index' position.", py::arg("index"));
cls_TDataStd_ReferenceList.def("Clear", (void (TDataStd_ReferenceList::*)()) &TDataStd_ReferenceList::Clear, "None");
cls_TDataStd_ReferenceList.def("First", (const TDF_Label & (TDataStd_ReferenceList::*)() const) &TDataStd_ReferenceList::First, "None");
cls_TDataStd_ReferenceList.def("Last", (const TDF_Label & (TDataStd_ReferenceList::*)() const) &TDataStd_ReferenceList::Last, "None");
cls_TDataStd_ReferenceList.def("List", (const TDF_LabelList & (TDataStd_ReferenceList::*)() const) &TDataStd_ReferenceList::List, "None");
cls_TDataStd_ReferenceList.def("ID", (const Standard_GUID & (TDataStd_ReferenceList::*)() const) &TDataStd_ReferenceList::ID, "None");
cls_TDataStd_ReferenceList.def("Restore", (void (TDataStd_ReferenceList::*)(const opencascade::handle<TDF_Attribute> &)) &TDataStd_ReferenceList::Restore, "None", py::arg("With"));
cls_TDataStd_ReferenceList.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TDataStd_ReferenceList::*)() const) &TDataStd_ReferenceList::NewEmpty, "None");
cls_TDataStd_ReferenceList.def("Paste", (void (TDataStd_ReferenceList::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TDataStd_ReferenceList::Paste, "None", py::arg("Into"), py::arg("RT"));
cls_TDataStd_ReferenceList.def("References", (void (TDataStd_ReferenceList::*)(const opencascade::handle<TDF_DataSet> &) const) &TDataStd_ReferenceList::References, "None", py::arg("DS"));
cls_TDataStd_ReferenceList.def("Dump", (Standard_OStream & (TDataStd_ReferenceList::*)(Standard_OStream &) const) &TDataStd_ReferenceList::Dump, "None", py::arg("anOS"));
cls_TDataStd_ReferenceList.def_static("get_type_name_", (const char * (*)()) &TDataStd_ReferenceList::get_type_name, "None");
cls_TDataStd_ReferenceList.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDataStd_ReferenceList::get_type_descriptor, "None");
cls_TDataStd_ReferenceList.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDataStd_ReferenceList::*)() const) &TDataStd_ReferenceList::DynamicType, "None");

// Enums

}