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
#include <Standard_Handle.hxx>
#include <Standard_TypeDef.hxx>
#include <SelectMgr_ListOfFilter.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <SelectMgr_CompositionFilter.hxx>
#include <Standard_Type.hxx>

void bind_SelectMgr_CompositionFilter(py::module &mod){

py::class_<SelectMgr_CompositionFilter, opencascade::handle<SelectMgr_CompositionFilter>, SelectMgr_Filter> cls_SelectMgr_CompositionFilter(mod, "SelectMgr_CompositionFilter", "A framework to define a compound filter composed of two or more simple filters.");

// Fields

// Methods
cls_SelectMgr_CompositionFilter.def("Add", (void (SelectMgr_CompositionFilter::*)(const opencascade::handle<SelectMgr_Filter> &)) &SelectMgr_CompositionFilter::Add, "Adds the filter afilter to a filter object created by a filter class inheriting this framework.", py::arg("afilter"));
cls_SelectMgr_CompositionFilter.def("Remove", (void (SelectMgr_CompositionFilter::*)(const opencascade::handle<SelectMgr_Filter> &)) &SelectMgr_CompositionFilter::Remove, "Removes the filter aFilter from this framework.", py::arg("aFilter"));
cls_SelectMgr_CompositionFilter.def("IsEmpty", (Standard_Boolean (SelectMgr_CompositionFilter::*)() const) &SelectMgr_CompositionFilter::IsEmpty, "Returns true if this framework is empty.");
cls_SelectMgr_CompositionFilter.def("IsIn", (Standard_Boolean (SelectMgr_CompositionFilter::*)(const opencascade::handle<SelectMgr_Filter> &) const) &SelectMgr_CompositionFilter::IsIn, "Returns true if the filter aFilter is in this framework.", py::arg("aFilter"));
cls_SelectMgr_CompositionFilter.def("StoredFilters", (const SelectMgr_ListOfFilter & (SelectMgr_CompositionFilter::*)() const) &SelectMgr_CompositionFilter::StoredFilters, "Returns the list of stored filters from this framework.");
cls_SelectMgr_CompositionFilter.def("Clear", (void (SelectMgr_CompositionFilter::*)()) &SelectMgr_CompositionFilter::Clear, "Clears the filters used in this framework.");
cls_SelectMgr_CompositionFilter.def("ActsOn", (Standard_Boolean (SelectMgr_CompositionFilter::*)(const TopAbs_ShapeEnum) const) &SelectMgr_CompositionFilter::ActsOn, "None", py::arg("aStandardMode"));
cls_SelectMgr_CompositionFilter.def_static("get_type_name_", (const char * (*)()) &SelectMgr_CompositionFilter::get_type_name, "None");
cls_SelectMgr_CompositionFilter.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &SelectMgr_CompositionFilter::get_type_descriptor, "None");
cls_SelectMgr_CompositionFilter.def("DynamicType", (const opencascade::handle<Standard_Type> & (SelectMgr_CompositionFilter::*)() const) &SelectMgr_CompositionFilter::DynamicType, "None");

// Enums

}