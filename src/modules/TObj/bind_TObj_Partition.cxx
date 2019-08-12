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
#include <TObj_Object.hxx>
#include <TDF_Label.hxx>
#include <Standard_Handle.hxx>
#include <TObj_Partition.hxx>
#include <Standard_TypeDef.hxx>
#include <TCollection_HExtendedString.hxx>
#include <TObj_Persistence.hxx>
#include <Standard_Type.hxx>
#include <TObj_Model.hxx>

void bind_TObj_Partition(py::module &mod){

py::class_<TObj_Partition, opencascade::handle<TObj_Partition>, TObj_Object> cls_TObj_Partition(mod, "TObj_Partition", "This class privides tool handling one of partitions (the set of homogenious elements) in the OCAF based model`s data structure");

// Constructors

// Fields

// Methods
cls_TObj_Partition.def_static("Create_", (opencascade::handle<TObj_Partition> (*)(const TDF_Label &)) &TObj_Partition::Create, "Creates a new partition on given label.", py::arg("theLabel"));
cls_TObj_Partition.def("SetName", (Standard_Boolean (TObj_Partition::*)(const opencascade::handle<TCollection_HExtendedString> &) const) &TObj_Partition::SetName, "Sets name of the object. partition does not check unique of own name", py::arg("theName"));
cls_TObj_Partition.def("AfterRetrieval", (void (TObj_Partition::*)()) &TObj_Partition::AfterRetrieval, "Preforms updating the links and dependances of the object which are not stored in persistence. Does not register the partition name");
cls_TObj_Partition.def("NewLabel", (TDF_Label (TObj_Partition::*)() const) &TObj_Partition::NewLabel, "Creates and Returns label for new object in partition.");
cls_TObj_Partition.def("SetNamePrefix", (void (TObj_Partition::*)(const opencascade::handle<TCollection_HExtendedString> &)) &TObj_Partition::SetNamePrefix, "Sets prefix for names of the objects in partition.", py::arg("thePrefix"));
cls_TObj_Partition.def("GetNamePrefix", (opencascade::handle<TCollection_HExtendedString> (TObj_Partition::*)() const) &TObj_Partition::GetNamePrefix, "Returns prefix for names of the objects in partition.");
cls_TObj_Partition.def("GetNewName", [](TObj_Partition &self) -> opencascade::handle<TCollection_HExtendedString> { return self.GetNewName(); });
cls_TObj_Partition.def("GetNewName", (opencascade::handle<TCollection_HExtendedString> (TObj_Partition::*)(const Standard_Boolean)) &TObj_Partition::GetNewName, "Generates and returns name for new object in partition. if theIsToChangeCount is true partition icrease own counter to generate new name next time starting from new counter value", py::arg("theIsToChangeCount"));
cls_TObj_Partition.def("GetLastIndex", (Standard_Integer (TObj_Partition::*)() const) &TObj_Partition::GetLastIndex, "Return Last index in partition (reserved);");
cls_TObj_Partition.def("SetLastIndex", (void (TObj_Partition::*)(const Standard_Integer)) &TObj_Partition::SetLastIndex, "Sets Last index in partition (reserved);", py::arg("theIndex"));
cls_TObj_Partition.def_static("GetPartition_", (opencascade::handle<TObj_Partition> (*)(const opencascade::handle<TObj_Object> &)) &TObj_Partition::GetPartition, "Returns the partition in which object is stored. Null partition returned if not found", py::arg("theObject"));
cls_TObj_Partition.def("Update", (Standard_Boolean (TObj_Partition::*)()) &TObj_Partition::Update, "Does nothing in the partition.");
cls_TObj_Partition.def_static("get_type_name_", (const char * (*)()) &TObj_Partition::get_type_name, "None");
cls_TObj_Partition.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TObj_Partition::get_type_descriptor, "None");
cls_TObj_Partition.def("DynamicType", (const opencascade::handle<Standard_Type> & (TObj_Partition::*)() const) &TObj_Partition::DynamicType, "None");

// Enums

}