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
#include <Standard_TypeDef.hxx>
#include <AIS_KindOfInteractive.hxx>
#include <Standard_Handle.hxx>
#include <SelectMgr_EntityOwner.hxx>
#include <TColStd_ListOfInteger.hxx>
#include <AIS_ExclusionFilter.hxx>
#include <Standard_Type.hxx>
#include <TColStd_DataMapOfIntegerListOfInteger.hxx>

void bind_AIS_ExclusionFilter(py::module &mod){

py::class_<AIS_ExclusionFilter, opencascade::handle<AIS_ExclusionFilter>, SelectMgr_Filter> cls_AIS_ExclusionFilter(mod, "AIS_ExclusionFilter", "A framework to reject or to accept only objects of given types and/or signatures. Objects are stored, and the stored objects - along with the flag settings - are used to define the filter. Objects to be filtered are compared with the stored objects added to the filter, and are accepted or rejected according to the exclusion flag setting. - Exclusion flag on - the function IsOk answers true for all objects, except those of the types and signatures stored in the filter framework - Exclusion flag off - the funciton IsOk answers true for all objects which have the same type and signature as the stored ones.");

// Constructors
cls_AIS_ExclusionFilter.def(py::init<>());
cls_AIS_ExclusionFilter.def(py::init<const Standard_Boolean>(), py::arg("ExclusionFlagOn"));
cls_AIS_ExclusionFilter.def(py::init<const AIS_KindOfInteractive>(), py::arg("TypeToExclude"));
cls_AIS_ExclusionFilter.def(py::init<const AIS_KindOfInteractive, const Standard_Boolean>(), py::arg("TypeToExclude"), py::arg("ExclusionFlagOn"));
cls_AIS_ExclusionFilter.def(py::init<const AIS_KindOfInteractive, const Standard_Integer>(), py::arg("TypeToExclude"), py::arg("SignatureInType"));
cls_AIS_ExclusionFilter.def(py::init<const AIS_KindOfInteractive, const Standard_Integer, const Standard_Boolean>(), py::arg("TypeToExclude"), py::arg("SignatureInType"), py::arg("ExclusionFlagOn"));

// Fields

// Methods
cls_AIS_ExclusionFilter.def("IsOk", (Standard_Boolean (AIS_ExclusionFilter::*)(const opencascade::handle<SelectMgr_EntityOwner> &) const) &AIS_ExclusionFilter::IsOk, "None", py::arg("anObj"));
cls_AIS_ExclusionFilter.def("Add", (Standard_Boolean (AIS_ExclusionFilter::*)(const AIS_KindOfInteractive)) &AIS_ExclusionFilter::Add, "Adds the type TypeToExclude to the list of types.", py::arg("TypeToExclude"));
cls_AIS_ExclusionFilter.def("Add", (Standard_Boolean (AIS_ExclusionFilter::*)(const AIS_KindOfInteractive, const Standard_Integer)) &AIS_ExclusionFilter::Add, "None", py::arg("TypeToExclude"), py::arg("SignatureInType"));
cls_AIS_ExclusionFilter.def("Remove", (Standard_Boolean (AIS_ExclusionFilter::*)(const AIS_KindOfInteractive)) &AIS_ExclusionFilter::Remove, "None", py::arg("TypeToExclude"));
cls_AIS_ExclusionFilter.def("Remove", (Standard_Boolean (AIS_ExclusionFilter::*)(const AIS_KindOfInteractive, const Standard_Integer)) &AIS_ExclusionFilter::Remove, "None", py::arg("TypeToExclude"), py::arg("SignatureInType"));
cls_AIS_ExclusionFilter.def("Clear", (void (AIS_ExclusionFilter::*)()) &AIS_ExclusionFilter::Clear, "None");
cls_AIS_ExclusionFilter.def("IsExclusionFlagOn", (Standard_Boolean (AIS_ExclusionFilter::*)() const) &AIS_ExclusionFilter::IsExclusionFlagOn, "None");
cls_AIS_ExclusionFilter.def("SetExclusionFlag", (void (AIS_ExclusionFilter::*)(const Standard_Boolean)) &AIS_ExclusionFilter::SetExclusionFlag, "None", py::arg("Status"));
cls_AIS_ExclusionFilter.def("IsStored", (Standard_Boolean (AIS_ExclusionFilter::*)(const AIS_KindOfInteractive) const) &AIS_ExclusionFilter::IsStored, "None", py::arg("aType"));
cls_AIS_ExclusionFilter.def("ListOfStoredTypes", (void (AIS_ExclusionFilter::*)(TColStd_ListOfInteger &) const) &AIS_ExclusionFilter::ListOfStoredTypes, "None", py::arg("TheList"));
cls_AIS_ExclusionFilter.def("ListOfSignature", (void (AIS_ExclusionFilter::*)(const AIS_KindOfInteractive, TColStd_ListOfInteger &) const) &AIS_ExclusionFilter::ListOfSignature, "None", py::arg("aType"), py::arg("TheStoredList"));
cls_AIS_ExclusionFilter.def_static("get_type_name_", (const char * (*)()) &AIS_ExclusionFilter::get_type_name, "None");
cls_AIS_ExclusionFilter.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_ExclusionFilter::get_type_descriptor, "None");
cls_AIS_ExclusionFilter.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_ExclusionFilter::*)() const) &AIS_ExclusionFilter::DynamicType, "None");

// Enums

}