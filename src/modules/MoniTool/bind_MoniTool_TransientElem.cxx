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
#include <MoniTool_Element.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Transient.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Type.hxx>
#include <MoniTool_TransientElem.hxx>

void bind_MoniTool_TransientElem(py::module &mod){

py::class_<MoniTool_TransientElem, opencascade::handle<MoniTool_TransientElem>, MoniTool_Element> cls_MoniTool_TransientElem(mod, "MoniTool_TransientElem", "an TransientElem defines an Element for a specific input class its definition includes the value of the Key to be mapped, and the HashCoder associated to the class of the Key");

// Constructors
cls_MoniTool_TransientElem.def(py::init<const opencascade::handle<Standard_Transient> &>(), py::arg("akey"));

// Fields

// Methods
cls_MoniTool_TransientElem.def("Value", (const opencascade::handle<Standard_Transient> & (MoniTool_TransientElem::*)() const) &MoniTool_TransientElem::Value, "Returns the contained value");
cls_MoniTool_TransientElem.def("Equates", (Standard_Boolean (MoniTool_TransientElem::*)(const opencascade::handle<MoniTool_Element> &) const) &MoniTool_TransientElem::Equates, "Specific testof equallity : defined as False if <other> has not the same true Type, else contents are compared (by C++ operator ==)", py::arg("other"));
cls_MoniTool_TransientElem.def("ValueType", (opencascade::handle<Standard_Type> (MoniTool_TransientElem::*)() const) &MoniTool_TransientElem::ValueType, "Returns the Type of the Value. By default, returns the DynamicType of <me>, but can be redefined");
cls_MoniTool_TransientElem.def("ValueTypeName", (Standard_CString (MoniTool_TransientElem::*)() const) &MoniTool_TransientElem::ValueTypeName, "Returns the name of the Type of the Value. Default is name of ValueType, unless it is for a non-handled object");
cls_MoniTool_TransientElem.def_static("get_type_name_", (const char * (*)()) &MoniTool_TransientElem::get_type_name, "None");
cls_MoniTool_TransientElem.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MoniTool_TransientElem::get_type_descriptor, "None");
cls_MoniTool_TransientElem.def("DynamicType", (const opencascade::handle<Standard_Type> & (MoniTool_TransientElem::*)() const) &MoniTool_TransientElem::DynamicType, "None");

// Enums

}