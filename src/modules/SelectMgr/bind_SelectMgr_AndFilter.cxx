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
#include <SelectMgr_CompositionFilter.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <SelectMgr_EntityOwner.hxx>
#include <SelectMgr_AndFilter.hxx>
#include <Standard_Type.hxx>

void bind_SelectMgr_AndFilter(py::module &mod){

py::class_<SelectMgr_AndFilter, opencascade::handle<SelectMgr_AndFilter>, SelectMgr_CompositionFilter> cls_SelectMgr_AndFilter(mod, "SelectMgr_AndFilter", "A framework to define a selection filter for two or more types of entity.");

// Constructors
cls_SelectMgr_AndFilter.def(py::init<>());

// Fields

// Methods
cls_SelectMgr_AndFilter.def("IsOk", (Standard_Boolean (SelectMgr_AndFilter::*)(const opencascade::handle<SelectMgr_EntityOwner> &) const) &SelectMgr_AndFilter::IsOk, "None", py::arg("anobj"));
cls_SelectMgr_AndFilter.def_static("get_type_name_", (const char * (*)()) &SelectMgr_AndFilter::get_type_name, "None");
cls_SelectMgr_AndFilter.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &SelectMgr_AndFilter::get_type_descriptor, "None");
cls_SelectMgr_AndFilter.def("DynamicType", (const opencascade::handle<Standard_Type> & (SelectMgr_AndFilter::*)() const) &SelectMgr_AndFilter::DynamicType, "None");

// Enums

}