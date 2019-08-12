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
#include <MoniTool_RealVal.hxx>
#include <Standard_Type.hxx>

void bind_MoniTool_RealVal(py::module &mod){

py::class_<MoniTool_RealVal, opencascade::handle<MoniTool_RealVal>, Standard_Transient> cls_MoniTool_RealVal(mod, "MoniTool_RealVal", "A Real through a Handle (i.e. managed as TShared)");

// Constructors
cls_MoniTool_RealVal.def(py::init<>());
cls_MoniTool_RealVal.def(py::init<const Standard_Real>(), py::arg("val"));

// Fields

// Methods
cls_MoniTool_RealVal.def("Value", (Standard_Real (MoniTool_RealVal::*)() const) &MoniTool_RealVal::Value, "None");
cls_MoniTool_RealVal.def("CValue", (Standard_Real & (MoniTool_RealVal::*)()) &MoniTool_RealVal::CValue, "None");
cls_MoniTool_RealVal.def_static("get_type_name_", (const char * (*)()) &MoniTool_RealVal::get_type_name, "None");
cls_MoniTool_RealVal.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MoniTool_RealVal::get_type_descriptor, "None");
cls_MoniTool_RealVal.def("DynamicType", (const opencascade::handle<Standard_Type> & (MoniTool_RealVal::*)() const) &MoniTool_RealVal::DynamicType, "None");

// Enums

}