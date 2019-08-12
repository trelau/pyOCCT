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
#include <Transfer_Finder.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Transient.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Type.hxx>
#include <Transfer_TransientMapper.hxx>

void bind_Transfer_TransientMapper(py::module &mod){

py::class_<Transfer_TransientMapper, opencascade::handle<Transfer_TransientMapper>, Transfer_Finder> cls_Transfer_TransientMapper(mod, "Transfer_TransientMapper", "None");

// Constructors
cls_Transfer_TransientMapper.def(py::init<const opencascade::handle<Standard_Transient> &>(), py::arg("akey"));

// Fields

// Methods
cls_Transfer_TransientMapper.def("Value", (const opencascade::handle<Standard_Transient> & (Transfer_TransientMapper::*)() const) &Transfer_TransientMapper::Value, "Returns the contained value");
cls_Transfer_TransientMapper.def("Equates", (Standard_Boolean (Transfer_TransientMapper::*)(const opencascade::handle<Transfer_Finder> &) const) &Transfer_TransientMapper::Equates, "Specific testof equallity : defined as False if <other> has not the same true Type, else contents are compared (by C++ operator ==)", py::arg("other"));
cls_Transfer_TransientMapper.def("ValueType", (opencascade::handle<Standard_Type> (Transfer_TransientMapper::*)() const) &Transfer_TransientMapper::ValueType, "Returns the Type of the Value. By default, returns the DynamicType of <me>, but can be redefined");
cls_Transfer_TransientMapper.def("ValueTypeName", (Standard_CString (Transfer_TransientMapper::*)() const) &Transfer_TransientMapper::ValueTypeName, "Returns the name of the Type of the Value. Default is name of ValueType, unless it is for a non-handled object");
cls_Transfer_TransientMapper.def_static("get_type_name_", (const char * (*)()) &Transfer_TransientMapper::get_type_name, "None");
cls_Transfer_TransientMapper.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Transfer_TransientMapper::get_type_descriptor, "None");
cls_Transfer_TransientMapper.def("DynamicType", (const opencascade::handle<Standard_Type> & (Transfer_TransientMapper::*)() const) &Transfer_TransientMapper::DynamicType, "None");

// Enums

}