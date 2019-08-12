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
#include <TObj_Partition.hxx>
#include <TDF_Label.hxx>
#include <Standard_TypeDef.hxx>
#include <TObj_Persistence.hxx>
#include <Standard_Handle.hxx>
#include <TObj_Object.hxx>
#include <TObj_HiddenPartition.hxx>
#include <Standard_Type.hxx>

void bind_TObj_HiddenPartition(py::module &mod){

py::class_<TObj_HiddenPartition, opencascade::handle<TObj_HiddenPartition>, TObj_Partition> cls_TObj_HiddenPartition(mod, "TObj_HiddenPartition", "This class is partition is predefined hidden flag");

// Constructors
cls_TObj_HiddenPartition.def(py::init<const TDF_Label &>(), py::arg("theLabel"));

// Fields

// Methods
cls_TObj_HiddenPartition.def("GetTypeFlags", (Standard_Integer (TObj_HiddenPartition::*)() const) &TObj_HiddenPartition::GetTypeFlags, "Returns all flags of father except Visible");
cls_TObj_HiddenPartition.def_static("get_type_name_", (const char * (*)()) &TObj_HiddenPartition::get_type_name, "None");
cls_TObj_HiddenPartition.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TObj_HiddenPartition::get_type_descriptor, "None");
cls_TObj_HiddenPartition.def("DynamicType", (const opencascade::handle<Standard_Type> & (TObj_HiddenPartition::*)() const) &TObj_HiddenPartition::DynamicType, "None");

// Enums

}