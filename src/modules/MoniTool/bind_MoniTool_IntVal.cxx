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
#include <Standard_Transient.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <MoniTool_IntVal.hxx>
#include <Standard_Type.hxx>

void bind_MoniTool_IntVal(py::module &mod){

py::class_<MoniTool_IntVal, opencascade::handle<MoniTool_IntVal>, Standard_Transient> cls_MoniTool_IntVal(mod, "MoniTool_IntVal", "An Integer through a Handle (i.e. managed as TShared)");

// Constructors
cls_MoniTool_IntVal.def(py::init<>());
cls_MoniTool_IntVal.def(py::init<const Standard_Integer>(), py::arg("val"));

// Fields

// Methods
cls_MoniTool_IntVal.def("Value", (Standard_Integer (MoniTool_IntVal::*)() const) &MoniTool_IntVal::Value, "None");
cls_MoniTool_IntVal.def("CValue", (Standard_Integer & (MoniTool_IntVal::*)()) &MoniTool_IntVal::CValue, "None");
cls_MoniTool_IntVal.def_static("get_type_name_", (const char * (*)()) &MoniTool_IntVal::get_type_name, "None");
cls_MoniTool_IntVal.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MoniTool_IntVal::get_type_descriptor, "None");
cls_MoniTool_IntVal.def("DynamicType", (const opencascade::handle<Standard_Type> & (MoniTool_IntVal::*)() const) &MoniTool_IntVal::DynamicType, "None");

// Enums

}