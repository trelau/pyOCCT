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
#include <SelectBasics_EntityOwner.hxx>
#include <Standard_Type.hxx>
#include <Standard_TypeDef.hxx>
#include <TopLoc_Location.hxx>

void bind_SelectBasics_EntityOwner(py::module &mod){

py::class_<SelectBasics_EntityOwner, opencascade::handle<SelectBasics_EntityOwner>, Standard_Transient> cls_SelectBasics_EntityOwner(mod, "SelectBasics_EntityOwner", "defines an abstract owner of sensitive primitives. Owners are typically used to establish a connection between sensitive entities and high-level objects (e.g. presentations).");

// Fields

// Methods
cls_SelectBasics_EntityOwner.def_static("get_type_name_", (const char * (*)()) &SelectBasics_EntityOwner::get_type_name, "None");
cls_SelectBasics_EntityOwner.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &SelectBasics_EntityOwner::get_type_descriptor, "None");
cls_SelectBasics_EntityOwner.def("DynamicType", (const opencascade::handle<Standard_Type> & (SelectBasics_EntityOwner::*)() const) &SelectBasics_EntityOwner::DynamicType, "None");
cls_SelectBasics_EntityOwner.def("SetPriority", (void (SelectBasics_EntityOwner::*)(const Standard_Integer)) &SelectBasics_EntityOwner::SetPriority, "sets the selectable priority of the owner", py::arg("thePriority"));
cls_SelectBasics_EntityOwner.def("Priority", (Standard_Integer (SelectBasics_EntityOwner::*)() const) &SelectBasics_EntityOwner::Priority, "None");
cls_SelectBasics_EntityOwner.def("HasLocation", (Standard_Boolean (SelectBasics_EntityOwner::*)() const) &SelectBasics_EntityOwner::HasLocation, "None");
cls_SelectBasics_EntityOwner.def("SetLocation", (void (SelectBasics_EntityOwner::*)(const TopLoc_Location &)) &SelectBasics_EntityOwner::SetLocation, "None", py::arg("aLoc"));
cls_SelectBasics_EntityOwner.def("ResetLocation", (void (SelectBasics_EntityOwner::*)()) &SelectBasics_EntityOwner::ResetLocation, "None");
cls_SelectBasics_EntityOwner.def("Location", (TopLoc_Location (SelectBasics_EntityOwner::*)() const) &SelectBasics_EntityOwner::Location, "None");
cls_SelectBasics_EntityOwner.def("Set", (void (SelectBasics_EntityOwner::*)(const Standard_Integer)) &SelectBasics_EntityOwner::Set, "sets the selectable priority of the owner", py::arg("thePriority"));

// Enums

}