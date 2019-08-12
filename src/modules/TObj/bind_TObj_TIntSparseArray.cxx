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
#include <TObj_TIntSparseArray.hxx>
#include <TDF_Label.hxx>
#include <NCollection_SparseArrayBase.hxx>
#include <NCollection_SparseArray.hxx>
#include <Standard_TypeDef.hxx>
#include <TDF_RelocationTable.hxx>
#include <TDF_DeltaOnModification.hxx>
#include <TDF_AttributeDelta.hxx>
#include <Standard_Type.hxx>

void bind_TObj_TIntSparseArray(py::module &mod){

py::class_<TObj_TIntSparseArray, opencascade::handle<TObj_TIntSparseArray>, TDF_Attribute> cls_TObj_TIntSparseArray(mod, "TObj_TIntSparseArray", "OCAF Attribute to store a set of positive integer values in the OCAF tree. Each value is identified by ID (positive integer). The supporting underlying data structure is NCollection_SparseArray of integers.");

// Constructors
cls_TObj_TIntSparseArray.def(py::init<>());

// Fields

// Methods
cls_TObj_TIntSparseArray.def_static("GetID_", (const Standard_GUID & (*)()) &TObj_TIntSparseArray::GetID, "This method is used in implementation of ID()");
cls_TObj_TIntSparseArray.def("ID", (const Standard_GUID & (TObj_TIntSparseArray::*)() const) &TObj_TIntSparseArray::ID, "Returns the ID of this attribute.");
cls_TObj_TIntSparseArray.def_static("Set_", (opencascade::handle<TObj_TIntSparseArray> (*)(const TDF_Label &)) &TObj_TIntSparseArray::Set, "Creates TObj_TIntSparseArray attribute on given label.", py::arg("theLabel"));
cls_TObj_TIntSparseArray.def("Size", (Standard_Size (TObj_TIntSparseArray::*)() const) &TObj_TIntSparseArray::Size, "Returns the number of stored values in the set");
cls_TObj_TIntSparseArray.def("GetIterator", (TObj_TIntSparseArray::Iterator (TObj_TIntSparseArray::*)() const) &TObj_TIntSparseArray::GetIterator, "Returns iterator on objects contained in the set");
cls_TObj_TIntSparseArray.def("HasValue", (Standard_Boolean (TObj_TIntSparseArray::*)(const Standard_Size) const) &TObj_TIntSparseArray::HasValue, "Returns true if the value with the given ID is present.", py::arg("theId"));
cls_TObj_TIntSparseArray.def("Value", (Standard_Integer (TObj_TIntSparseArray::*)(const Standard_Size) const) &TObj_TIntSparseArray::Value, "Returns the value by its ID. Raises an exception if no value is stored with this ID", py::arg("theId"));
cls_TObj_TIntSparseArray.def("SetValue", (void (TObj_TIntSparseArray::*)(const Standard_Size, const Standard_Integer)) &TObj_TIntSparseArray::SetValue, "Sets the value with the given ID. Raises an exception if theId is not positive", py::arg("theId"), py::arg("theValue"));
cls_TObj_TIntSparseArray.def("UnsetValue", (void (TObj_TIntSparseArray::*)(const Standard_Size)) &TObj_TIntSparseArray::UnsetValue, "Unsets the value with the given ID. Raises an exception if theId is not positive", py::arg("theId"));
cls_TObj_TIntSparseArray.def("Clear", (void (TObj_TIntSparseArray::*)()) &TObj_TIntSparseArray::Clear, "Clears the set");
cls_TObj_TIntSparseArray.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TObj_TIntSparseArray::*)() const) &TObj_TIntSparseArray::NewEmpty, "Returns an new empty TObj_TIntSparseArray attribute. It is used by the copy algorithm.");
cls_TObj_TIntSparseArray.def("BackupCopy", (opencascade::handle<TDF_Attribute> (TObj_TIntSparseArray::*)() const) &TObj_TIntSparseArray::BackupCopy, "Moves this delta into a new other attribute.");
cls_TObj_TIntSparseArray.def("Restore", (void (TObj_TIntSparseArray::*)(const opencascade::handle<TDF_Attribute> &)) &TObj_TIntSparseArray::Restore, "Restores the set using info saved in backup attribute theDelta.", py::arg("theDelta"));
cls_TObj_TIntSparseArray.def("Paste", (void (TObj_TIntSparseArray::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TObj_TIntSparseArray::Paste, "This method is used when copying an attribute from a source structure into a target structure.", py::arg("theInto"), py::arg("theRT"));
cls_TObj_TIntSparseArray.def("BeforeCommitTransaction", (void (TObj_TIntSparseArray::*)()) &TObj_TIntSparseArray::BeforeCommitTransaction, "It is called just before Commit or Abort transaction and does Backup() to create a delta");
cls_TObj_TIntSparseArray.def("DeltaOnModification", (void (TObj_TIntSparseArray::*)(const opencascade::handle<TDF_DeltaOnModification> &)) &TObj_TIntSparseArray::DeltaOnModification, "Applies theDelta to this.", py::arg("theDelta"));
cls_TObj_TIntSparseArray.def("AfterUndo", (Standard_Boolean (TObj_TIntSparseArray::*)(const opencascade::handle<TDF_AttributeDelta> &, const Standard_Boolean)) &TObj_TIntSparseArray::AfterUndo, "Clears my modification delta; called after application of theDelta", py::arg("theDelta"), py::arg("toForce"));
cls_TObj_TIntSparseArray.def("SetDoBackup", (void (TObj_TIntSparseArray::*)(const Standard_Boolean)) &TObj_TIntSparseArray::SetDoBackup, "Sets the flag pointing to the necessity to maintain a modification delta. It is called by the retrieval driver", py::arg("toDo"));
cls_TObj_TIntSparseArray.def("ClearDelta", (void (TObj_TIntSparseArray::*)()) &TObj_TIntSparseArray::ClearDelta, "None");
cls_TObj_TIntSparseArray.def_static("get_type_name_", (const char * (*)()) &TObj_TIntSparseArray::get_type_name, "None");
cls_TObj_TIntSparseArray.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TObj_TIntSparseArray::get_type_descriptor, "None");
cls_TObj_TIntSparseArray.def("DynamicType", (const opencascade::handle<Standard_Type> & (TObj_TIntSparseArray::*)() const) &TObj_TIntSparseArray::DynamicType, "None");

// Enums

}