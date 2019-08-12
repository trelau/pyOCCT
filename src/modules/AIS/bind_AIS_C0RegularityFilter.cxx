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
#include <SelectMgr_Filter.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_TypeDef.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <Standard_Handle.hxx>
#include <SelectMgr_EntityOwner.hxx>
#include <AIS_C0RegularityFilter.hxx>
#include <Standard_Type.hxx>
#include <TopTools_MapOfShape.hxx>

void bind_AIS_C0RegularityFilter(py::module &mod){

py::class_<AIS_C0RegularityFilter, opencascade::handle<AIS_C0RegularityFilter>, SelectMgr_Filter> cls_AIS_C0RegularityFilter(mod, "AIS_C0RegularityFilter", "None");

// Constructors
cls_AIS_C0RegularityFilter.def(py::init<const TopoDS_Shape &>(), py::arg("aShape"));

// Fields

// Methods
cls_AIS_C0RegularityFilter.def("ActsOn", (Standard_Boolean (AIS_C0RegularityFilter::*)(const TopAbs_ShapeEnum) const) &AIS_C0RegularityFilter::ActsOn, "None", py::arg("aType"));
cls_AIS_C0RegularityFilter.def("IsOk", (Standard_Boolean (AIS_C0RegularityFilter::*)(const opencascade::handle<SelectMgr_EntityOwner> &) const) &AIS_C0RegularityFilter::IsOk, "None", py::arg("EO"));
cls_AIS_C0RegularityFilter.def_static("get_type_name_", (const char * (*)()) &AIS_C0RegularityFilter::get_type_name, "None");
cls_AIS_C0RegularityFilter.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_C0RegularityFilter::get_type_descriptor, "None");
cls_AIS_C0RegularityFilter.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_C0RegularityFilter::*)() const) &AIS_C0RegularityFilter::DynamicType, "None");

// Enums

}