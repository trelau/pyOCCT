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
#include <Graphic3d_NMapOfTransient.hxx>
#include <SelectMgr_OrFilter.hxx>
#include <Standard_Type.hxx>

void bind_SelectMgr_OrFilter(py::module &mod){

py::class_<SelectMgr_OrFilter, opencascade::handle<SelectMgr_OrFilter>, SelectMgr_CompositionFilter> cls_SelectMgr_OrFilter(mod, "SelectMgr_OrFilter", "A framework to define an or selection filter. This selects one or another type of sensitive entity.");

// Constructors
cls_SelectMgr_OrFilter.def(py::init<>());

// Fields

// Methods
cls_SelectMgr_OrFilter.def("IsOk", (Standard_Boolean (SelectMgr_OrFilter::*)(const opencascade::handle<SelectMgr_EntityOwner> &) const) &SelectMgr_OrFilter::IsOk, "None", py::arg("anobj"));
cls_SelectMgr_OrFilter.def("SetDisabledObjects", (void (SelectMgr_OrFilter::*)(const opencascade::handle<Graphic3d_NMapOfTransient> &)) &SelectMgr_OrFilter::SetDisabledObjects, "Disable selection of specified objects.", py::arg("theObjects"));
cls_SelectMgr_OrFilter.def_static("get_type_name_", (const char * (*)()) &SelectMgr_OrFilter::get_type_name, "None");
cls_SelectMgr_OrFilter.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &SelectMgr_OrFilter::get_type_descriptor, "None");
cls_SelectMgr_OrFilter.def("DynamicType", (const opencascade::handle<Standard_Type> & (SelectMgr_OrFilter::*)() const) &SelectMgr_OrFilter::DynamicType, "None");

// Enums

}