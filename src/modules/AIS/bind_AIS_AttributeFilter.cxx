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
#include <Quantity_NameOfColor.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <SelectMgr_EntityOwner.hxx>
#include <AIS_AttributeFilter.hxx>
#include <Standard_Type.hxx>

void bind_AIS_AttributeFilter(py::module &mod){

py::class_<AIS_AttributeFilter, opencascade::handle<AIS_AttributeFilter>, SelectMgr_Filter> cls_AIS_AttributeFilter(mod, "AIS_AttributeFilter", "Selects Interactive Objects, which have the desired width or color. The filter questions each Interactive Object in local context to determine whether it has an non-null owner, and if so, whether it has the required color and width attributes. If the object returns true in each case, it is kept. If not, it is rejected. This filter is used only in an open local context. In the Collector viewer, you can only locate Interactive Objects, which answer positively to the filters, which are in position when a local context is open.");

// Constructors
cls_AIS_AttributeFilter.def(py::init<>());
cls_AIS_AttributeFilter.def(py::init<const Quantity_NameOfColor>(), py::arg("aCol"));
cls_AIS_AttributeFilter.def(py::init<const Standard_Real>(), py::arg("aWidth"));

// Fields

// Methods
cls_AIS_AttributeFilter.def("HasColor", (Standard_Boolean (AIS_AttributeFilter::*)() const) &AIS_AttributeFilter::HasColor, "Indicates that the Interactive Object has the color setting specified by the argument aCol at construction time.");
cls_AIS_AttributeFilter.def("HasWidth", (Standard_Boolean (AIS_AttributeFilter::*)() const) &AIS_AttributeFilter::HasWidth, "Indicates that the Interactive Object has the width setting specified by the argument aWidth at construction time.");
cls_AIS_AttributeFilter.def("SetColor", (void (AIS_AttributeFilter::*)(const Quantity_NameOfColor)) &AIS_AttributeFilter::SetColor, "Sets the color aCol. This must be chosen from the list of colors in Quantity_NameOfColor.", py::arg("aCol"));
cls_AIS_AttributeFilter.def("SetWidth", (void (AIS_AttributeFilter::*)(const Standard_Real)) &AIS_AttributeFilter::SetWidth, "Sets the line width aWidth.", py::arg("aWidth"));
cls_AIS_AttributeFilter.def("UnsetColor", (void (AIS_AttributeFilter::*)()) &AIS_AttributeFilter::UnsetColor, "Removes the setting for color from the filter.");
cls_AIS_AttributeFilter.def("UnsetWidth", (void (AIS_AttributeFilter::*)()) &AIS_AttributeFilter::UnsetWidth, "Removes the setting for width from the filter.");
cls_AIS_AttributeFilter.def("IsOk", (Standard_Boolean (AIS_AttributeFilter::*)(const opencascade::handle<SelectMgr_EntityOwner> &) const) &AIS_AttributeFilter::IsOk, "Indicates that the selected Interactive Object passes the filter. The owner, anObj, can be either direct or user. A direct owner is the corresponding construction element, whereas a user is the compound shape of which the entity forms a part. If the Interactive Object returns Standard_True when detected by the Local Context selector through the mouse, the object is kept; if not, it is rejected.", py::arg("anObj"));
cls_AIS_AttributeFilter.def_static("get_type_name_", (const char * (*)()) &AIS_AttributeFilter::get_type_name, "None");
cls_AIS_AttributeFilter.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_AttributeFilter::get_type_descriptor, "None");
cls_AIS_AttributeFilter.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_AttributeFilter::*)() const) &AIS_AttributeFilter::DynamicType, "None");

// Enums

}