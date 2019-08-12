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
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <AIS_Selection.hxx>
#include <Standard_Type.hxx>
#include <AIS_SelectStatus.hxx>
#include <SelectMgr_EntityOwner.hxx>
#include <Standard_TypeDef.hxx>
#include <AIS_NListOfEntityOwner.hxx>
#include <NCollection_List.hxx>
#include <NCollection_DataMap.hxx>

void bind_AIS_Selection(py::module &mod){

py::class_<AIS_Selection, opencascade::handle<AIS_Selection>, Standard_Transient> cls_AIS_Selection(mod, "AIS_Selection", "Class holding the list of selected owners.");

// Constructors
cls_AIS_Selection.def(py::init<>());

// Fields

// Methods
cls_AIS_Selection.def_static("get_type_name_", (const char * (*)()) &AIS_Selection::get_type_name, "None");
cls_AIS_Selection.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_Selection::get_type_descriptor, "None");
cls_AIS_Selection.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_Selection::*)() const) &AIS_Selection::DynamicType, "None");
cls_AIS_Selection.def("Clear", (void (AIS_Selection::*)()) &AIS_Selection::Clear, "removes all the object of the selection.");
cls_AIS_Selection.def("Select", (AIS_SelectStatus (AIS_Selection::*)(const opencascade::handle<SelectMgr_EntityOwner> &)) &AIS_Selection::Select, "if the object is not yet in the selection, it will be added. if the object is already in the selection, it will be removed.", py::arg("theObject"));
cls_AIS_Selection.def("AddSelect", (AIS_SelectStatus (AIS_Selection::*)(const opencascade::handle<SelectMgr_EntityOwner> &)) &AIS_Selection::AddSelect, "the object is always add int the selection. faster when the number of objects selected is great.", py::arg("theObject"));
cls_AIS_Selection.def("ClearAndSelect", (void (AIS_Selection::*)(const opencascade::handle<SelectMgr_EntityOwner> &)) &AIS_Selection::ClearAndSelect, "clears the selection and adds the object in the selection.", py::arg("theObject"));
cls_AIS_Selection.def("IsSelected", (Standard_Boolean (AIS_Selection::*)(const opencascade::handle<SelectMgr_EntityOwner> &) const) &AIS_Selection::IsSelected, "checks if the object is in the selection.", py::arg("theObject"));
cls_AIS_Selection.def("Objects", (const AIS_NListOfEntityOwner & (AIS_Selection::*)() const) &AIS_Selection::Objects, "Return the list of selected objects.");
cls_AIS_Selection.def("Extent", (Standard_Integer (AIS_Selection::*)() const) &AIS_Selection::Extent, "Return the number of selected objects.");
cls_AIS_Selection.def("IsEmpty", (Standard_Boolean (AIS_Selection::*)() const) &AIS_Selection::IsEmpty, "Return true if list of selected objects is empty.");
cls_AIS_Selection.def("Init", (void (AIS_Selection::*)()) &AIS_Selection::Init, "Start iteration through selected objects.");
cls_AIS_Selection.def("More", (Standard_Boolean (AIS_Selection::*)() const) &AIS_Selection::More, "Return true if iterator points to selected object.");
cls_AIS_Selection.def("Next", (void (AIS_Selection::*)()) &AIS_Selection::Next, "Continue iteration through selected objects.");
cls_AIS_Selection.def("Value", (const opencascade::handle<SelectMgr_EntityOwner> & (AIS_Selection::*)() const) &AIS_Selection::Value, "Return selected object at iterator position.");

// Enums

}