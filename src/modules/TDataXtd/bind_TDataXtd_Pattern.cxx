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
#include <TDF_Attribute.hxx>
#include <Standard_GUID.hxx>
#include <Standard_TypeDef.hxx>
#include <TDataXtd_Array1OfTrsf.hxx>
#include <Standard_Handle.hxx>
#include <TDataXtd_Pattern.hxx>
#include <Standard_Type.hxx>

void bind_TDataXtd_Pattern(py::module &mod){

py::class_<TDataXtd_Pattern, opencascade::handle<TDataXtd_Pattern>, TDF_Attribute> cls_TDataXtd_Pattern(mod, "TDataXtd_Pattern", "a general pattern model");

// Fields

// Methods
cls_TDataXtd_Pattern.def_static("GetID_", (const Standard_GUID & (*)()) &TDataXtd_Pattern::GetID, "None");
cls_TDataXtd_Pattern.def("ID", (const Standard_GUID & (TDataXtd_Pattern::*)() const) &TDataXtd_Pattern::ID, "Returns the ID of the attribute.");
cls_TDataXtd_Pattern.def("PatternID", (const Standard_GUID & (TDataXtd_Pattern::*)() const) &TDataXtd_Pattern::PatternID, "Returns the ID of the attribute.");
cls_TDataXtd_Pattern.def("NbTrsfs", (Standard_Integer (TDataXtd_Pattern::*)() const) &TDataXtd_Pattern::NbTrsfs, "Give the number of transformation");
cls_TDataXtd_Pattern.def("ComputeTrsfs", (void (TDataXtd_Pattern::*)(TDataXtd_Array1OfTrsf &) const) &TDataXtd_Pattern::ComputeTrsfs, "Give the transformations", py::arg("Trsfs"));
cls_TDataXtd_Pattern.def_static("get_type_name_", (const char * (*)()) &TDataXtd_Pattern::get_type_name, "None");
cls_TDataXtd_Pattern.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDataXtd_Pattern::get_type_descriptor, "None");
cls_TDataXtd_Pattern.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDataXtd_Pattern::*)() const) &TDataXtd_Pattern::DynamicType, "None");

// Enums

}