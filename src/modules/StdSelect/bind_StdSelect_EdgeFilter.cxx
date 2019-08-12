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
#include <StdSelect_TypeOfEdge.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <SelectMgr_EntityOwner.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <StdSelect_EdgeFilter.hxx>
#include <Standard_Type.hxx>

void bind_StdSelect_EdgeFilter(py::module &mod){

py::class_<StdSelect_EdgeFilter, opencascade::handle<StdSelect_EdgeFilter>, SelectMgr_Filter> cls_StdSelect_EdgeFilter(mod, "StdSelect_EdgeFilter", "A framework to define a filter to select a specific type of edge. The types available include: - any edge - a linear edge - a circular edge.");

// Constructors
cls_StdSelect_EdgeFilter.def(py::init<const StdSelect_TypeOfEdge>(), py::arg("Edge"));

// Fields

// Methods
cls_StdSelect_EdgeFilter.def("SetType", (void (StdSelect_EdgeFilter::*)(const StdSelect_TypeOfEdge)) &StdSelect_EdgeFilter::SetType, "Sets the type of edge aNewType. aNewType is to be highlighted in selection.", py::arg("aNewType"));
cls_StdSelect_EdgeFilter.def("Type", (StdSelect_TypeOfEdge (StdSelect_EdgeFilter::*)() const) &StdSelect_EdgeFilter::Type, "Returns the type of edge to be highlighted in selection.");
cls_StdSelect_EdgeFilter.def("IsOk", (Standard_Boolean (StdSelect_EdgeFilter::*)(const opencascade::handle<SelectMgr_EntityOwner> &) const) &StdSelect_EdgeFilter::IsOk, "None", py::arg("anobj"));
cls_StdSelect_EdgeFilter.def("ActsOn", (Standard_Boolean (StdSelect_EdgeFilter::*)(const TopAbs_ShapeEnum) const) &StdSelect_EdgeFilter::ActsOn, "None", py::arg("aStandardMode"));
cls_StdSelect_EdgeFilter.def_static("get_type_name_", (const char * (*)()) &StdSelect_EdgeFilter::get_type_name, "None");
cls_StdSelect_EdgeFilter.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StdSelect_EdgeFilter::get_type_descriptor, "None");
cls_StdSelect_EdgeFilter.def("DynamicType", (const opencascade::handle<Standard_Type> & (StdSelect_EdgeFilter::*)() const) &StdSelect_EdgeFilter::DynamicType, "None");

// Enums

}