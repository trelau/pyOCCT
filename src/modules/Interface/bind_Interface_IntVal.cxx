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
#include <Interface_IntVal.hxx>
#include <Standard_Type.hxx>

void bind_Interface_IntVal(py::module &mod){

py::class_<Interface_IntVal, opencascade::handle<Interface_IntVal>, Standard_Transient> cls_Interface_IntVal(mod, "Interface_IntVal", "An Integer through a Handle (i.e. managed as TShared)");

// Constructors
cls_Interface_IntVal.def(py::init<>());

// Fields

// Methods
cls_Interface_IntVal.def("Value", (Standard_Integer (Interface_IntVal::*)() const) &Interface_IntVal::Value, "None");
cls_Interface_IntVal.def("CValue", (Standard_Integer & (Interface_IntVal::*)()) &Interface_IntVal::CValue, "None");
cls_Interface_IntVal.def_static("get_type_name_", (const char * (*)()) &Interface_IntVal::get_type_name, "None");
cls_Interface_IntVal.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Interface_IntVal::get_type_descriptor, "None");
cls_Interface_IntVal.def("DynamicType", (const opencascade::handle<Standard_Type> & (Interface_IntVal::*)() const) &Interface_IntVal::DynamicType, "None");

// Enums

}