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
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <SelectMgr_EntityOwner.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <SelectMgr_Filter.hxx>
#include <Standard_Type.hxx>

void bind_SelectMgr_Filter(py::module &mod){

py::class_<SelectMgr_Filter, opencascade::handle<SelectMgr_Filter>, Standard_Transient> cls_SelectMgr_Filter(mod, "SelectMgr_Filter", "The root class to define filter objects for selection. Advance handling of objects requires the services of filters. These only allow dynamic detection and selection of objects which correspond to the criteria defined in each. Eight standard filters inheriting SelectMgr_Filter are defined in Open CASCADE. You can create your own filters by defining new filter classes inheriting this framework. You use these filters by loading them into an AIS interactive context.");

// Fields

// Methods
cls_SelectMgr_Filter.def("IsOk", (Standard_Boolean (SelectMgr_Filter::*)(const opencascade::handle<SelectMgr_EntityOwner> &) const) &SelectMgr_Filter::IsOk, "Indicates that the selected Interactive Object passes the filter. The owner, anObj, can be either direct or user. A direct owner is the corresponding construction element, whereas a user is the compound shape of which the entity forms a part. When an object is detected by the mouse - in AIS, this is done through a context selector - its owner is passed to the filter as an argument. If the object returns Standard_True, it is kept; if not, it is rejected. If you are creating a filter class inheriting this framework, and the daughter class is to be used in an AIS local context, you will need to implement the virtual function ActsOn.", py::arg("anObj"));
cls_SelectMgr_Filter.def("ActsOn", (Standard_Boolean (SelectMgr_Filter::*)(const TopAbs_ShapeEnum) const) &SelectMgr_Filter::ActsOn, "Returns true in an AIS local context, if this filter operates on a type of subshape defined in a filter class inheriting this framework. This function completes IsOk in an AIS local context.", py::arg("aStandardMode"));
cls_SelectMgr_Filter.def_static("get_type_name_", (const char * (*)()) &SelectMgr_Filter::get_type_name, "None");
cls_SelectMgr_Filter.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &SelectMgr_Filter::get_type_descriptor, "None");
cls_SelectMgr_Filter.def("DynamicType", (const opencascade::handle<Standard_Type> & (SelectMgr_Filter::*)() const) &SelectMgr_Filter::DynamicType, "None");

// Enums

}