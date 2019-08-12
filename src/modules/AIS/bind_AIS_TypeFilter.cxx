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
#include <AIS_KindOfInteractive.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <SelectMgr_EntityOwner.hxx>
#include <AIS_TypeFilter.hxx>
#include <Standard_Type.hxx>

void bind_AIS_TypeFilter(py::module &mod){

py::class_<AIS_TypeFilter, opencascade::handle<AIS_TypeFilter>, SelectMgr_Filter> cls_AIS_TypeFilter(mod, "AIS_TypeFilter", "Selects Interactive Objects through their types. The filter questions each Interactive Object in local context to determine whether it has an non-null owner, and if so, whether it is of the desired type. If the object returns true in each case, it is kept. If not, it is rejected. By default, the interactive object has a None type and a signature of 0. A filter for type specifies a choice of type out of a range at any level enumerated for type or kind. The choice could be for kind of interactive object, of dimension, of unit, or type of axis, plane or attribute. If you want to give a particular type and signature to your Interactive Object, you must redefine two virtual methods: Type and Signature. This filter is used in both Neutral Point and open local contexts. In the Collector viewer, you can only locate Interactive Objects which answer positively to the positioned filters when a local context is open. Warning When you close a local context, all temporary interactive objects are deleted, all selection modes concerning the context are cancelled, and all content filters are emptied.");

// Constructors
cls_AIS_TypeFilter.def(py::init<const AIS_KindOfInteractive>(), py::arg("aGivenKind"));

// Fields

// Methods
cls_AIS_TypeFilter.def("IsOk", (Standard_Boolean (AIS_TypeFilter::*)(const opencascade::handle<SelectMgr_EntityOwner> &) const) &AIS_TypeFilter::IsOk, "Returns False if the transient is not an Interactive Object, or if the type of the Interactive Object is not the same as that stored in the filter.", py::arg("anobj"));
cls_AIS_TypeFilter.def_static("get_type_name_", (const char * (*)()) &AIS_TypeFilter::get_type_name, "None");
cls_AIS_TypeFilter.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_TypeFilter::get_type_descriptor, "None");
cls_AIS_TypeFilter.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_TypeFilter::*)() const) &AIS_TypeFilter::DynamicType, "None");

// Enums

}