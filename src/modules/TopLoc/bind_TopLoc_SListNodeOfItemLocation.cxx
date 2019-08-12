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
#include <TopLoc_ItemLocation.hxx>
#include <TopLoc_SListOfItemLocation.hxx>
#include <Standard_Handle.hxx>
#include <TopLoc_SListNodeOfItemLocation.hxx>
#include <Standard_Type.hxx>

void bind_TopLoc_SListNodeOfItemLocation(py::module &mod){

py::class_<TopLoc_SListNodeOfItemLocation, opencascade::handle<TopLoc_SListNodeOfItemLocation>, Standard_Transient> cls_TopLoc_SListNodeOfItemLocation(mod, "TopLoc_SListNodeOfItemLocation", "None");

// Constructors
cls_TopLoc_SListNodeOfItemLocation.def(py::init<const TopLoc_ItemLocation &, const TopLoc_SListOfItemLocation &>(), py::arg("I"), py::arg("aTail"));

// Fields

// Methods
cls_TopLoc_SListNodeOfItemLocation.def("Tail", (TopLoc_SListOfItemLocation & (TopLoc_SListNodeOfItemLocation::*)() const) &TopLoc_SListNodeOfItemLocation::Tail, "None");
cls_TopLoc_SListNodeOfItemLocation.def("Value", (TopLoc_ItemLocation & (TopLoc_SListNodeOfItemLocation::*)() const) &TopLoc_SListNodeOfItemLocation::Value, "None");
cls_TopLoc_SListNodeOfItemLocation.def_static("get_type_name_", (const char * (*)()) &TopLoc_SListNodeOfItemLocation::get_type_name, "None");
cls_TopLoc_SListNodeOfItemLocation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TopLoc_SListNodeOfItemLocation::get_type_descriptor, "None");
cls_TopLoc_SListNodeOfItemLocation.def("DynamicType", (const opencascade::handle<Standard_Type> & (TopLoc_SListNodeOfItemLocation::*)() const) &TopLoc_SListNodeOfItemLocation::DynamicType, "None");

// Enums

}