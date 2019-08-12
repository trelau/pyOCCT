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
#include <StdSelect_TypeOfFace.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <SelectMgr_EntityOwner.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <StdSelect_FaceFilter.hxx>
#include <Standard_Type.hxx>

void bind_StdSelect_FaceFilter(py::module &mod){

py::class_<StdSelect_FaceFilter, opencascade::handle<StdSelect_FaceFilter>, SelectMgr_Filter> cls_StdSelect_FaceFilter(mod, "StdSelect_FaceFilter", "A framework to define a filter to select a specific type of face. The types available include: - any face - a planar face - a cylindrical face - a spherical face - a toroidal face - a revol face.");

// Constructors
cls_StdSelect_FaceFilter.def(py::init<const StdSelect_TypeOfFace>(), py::arg("aTypeOfFace"));

// Fields

// Methods
cls_StdSelect_FaceFilter.def("SetType", (void (StdSelect_FaceFilter::*)(const StdSelect_TypeOfFace)) &StdSelect_FaceFilter::SetType, "Sets the type of face aNewType. aNewType is to be highlighted in selection.", py::arg("aNewType"));
cls_StdSelect_FaceFilter.def("Type", (StdSelect_TypeOfFace (StdSelect_FaceFilter::*)() const) &StdSelect_FaceFilter::Type, "Returns the type of face to be highlighted in selection.");
cls_StdSelect_FaceFilter.def("IsOk", (Standard_Boolean (StdSelect_FaceFilter::*)(const opencascade::handle<SelectMgr_EntityOwner> &) const) &StdSelect_FaceFilter::IsOk, "None", py::arg("anobj"));
cls_StdSelect_FaceFilter.def("ActsOn", (Standard_Boolean (StdSelect_FaceFilter::*)(const TopAbs_ShapeEnum) const) &StdSelect_FaceFilter::ActsOn, "None", py::arg("aStandardMode"));
cls_StdSelect_FaceFilter.def_static("get_type_name_", (const char * (*)()) &StdSelect_FaceFilter::get_type_name, "None");
cls_StdSelect_FaceFilter.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StdSelect_FaceFilter::get_type_descriptor, "None");
cls_StdSelect_FaceFilter.def("DynamicType", (const opencascade::handle<Standard_Type> & (StdSelect_FaceFilter::*)() const) &StdSelect_FaceFilter::DynamicType, "None");

// Enums

}