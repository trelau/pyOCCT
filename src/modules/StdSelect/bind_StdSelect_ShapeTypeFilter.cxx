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
#include <TopAbs_ShapeEnum.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <SelectMgr_EntityOwner.hxx>
#include <StdSelect_ShapeTypeFilter.hxx>
#include <Standard_Type.hxx>

void bind_StdSelect_ShapeTypeFilter(py::module &mod){

py::class_<StdSelect_ShapeTypeFilter, opencascade::handle<StdSelect_ShapeTypeFilter>, SelectMgr_Filter> cls_StdSelect_ShapeTypeFilter(mod, "StdSelect_ShapeTypeFilter", "A filter framework which allows you to define a filter for a specific shape type. The types available include: - compound - compsolid - solid - shell - face - wire - edge - vertex.");

// Constructors
cls_StdSelect_ShapeTypeFilter.def(py::init<const TopAbs_ShapeEnum>(), py::arg("aType"));

// Fields

// Methods
cls_StdSelect_ShapeTypeFilter.def("IsOk", (Standard_Boolean (StdSelect_ShapeTypeFilter::*)(const opencascade::handle<SelectMgr_EntityOwner> &) const) &StdSelect_ShapeTypeFilter::IsOk, "None", py::arg("anobj"));
cls_StdSelect_ShapeTypeFilter.def("Type", (TopAbs_ShapeEnum (StdSelect_ShapeTypeFilter::*)() const) &StdSelect_ShapeTypeFilter::Type, "Returns the type of shape selected by the filter.");
cls_StdSelect_ShapeTypeFilter.def("ActsOn", (Standard_Boolean (StdSelect_ShapeTypeFilter::*)(const TopAbs_ShapeEnum) const) &StdSelect_ShapeTypeFilter::ActsOn, "None", py::arg("aStandardMode"));
cls_StdSelect_ShapeTypeFilter.def_static("get_type_name_", (const char * (*)()) &StdSelect_ShapeTypeFilter::get_type_name, "None");
cls_StdSelect_ShapeTypeFilter.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StdSelect_ShapeTypeFilter::get_type_descriptor, "None");
cls_StdSelect_ShapeTypeFilter.def("DynamicType", (const opencascade::handle<Standard_Type> & (StdSelect_ShapeTypeFilter::*)() const) &StdSelect_ShapeTypeFilter::DynamicType, "None");

// Enums

}