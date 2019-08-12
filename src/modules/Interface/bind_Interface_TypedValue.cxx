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
#include <MoniTool_TypedValue.hxx>
#include <Standard_TypeDef.hxx>
#include <Interface_ParamType.hxx>
#include <MoniTool_ValueType.hxx>
#include <Standard_Handle.hxx>
#include <Interface_TypedValue.hxx>
#include <Standard_Type.hxx>
#include <TCollection_AsciiString.hxx>
#include <TColStd_HArray1OfAsciiString.hxx>
#include <NCollection_DataMap.hxx>
#include <TCollection_HAsciiString.hxx>
#include <Standard_Transient.hxx>

void bind_Interface_TypedValue(py::module &mod){

py::class_<Interface_TypedValue, opencascade::handle<Interface_TypedValue>, MoniTool_TypedValue> cls_Interface_TypedValue(mod, "Interface_TypedValue", "Now strictly equivalent to TypedValue from MoniTool, except for ParamType which remains for compatibility reasons");

// Constructors
cls_Interface_TypedValue.def(py::init<const Standard_CString>(), py::arg("name"));
cls_Interface_TypedValue.def(py::init<const Standard_CString, const Interface_ParamType>(), py::arg("name"), py::arg("type"));
cls_Interface_TypedValue.def(py::init<const Standard_CString, const Interface_ParamType, const Standard_CString>(), py::arg("name"), py::arg("type"), py::arg("init"));

// Fields

// Methods
cls_Interface_TypedValue.def("Type", (Interface_ParamType (Interface_TypedValue::*)() const) &Interface_TypedValue::Type, "Returns the type I.E. calls ValueType then makes correspondance between ParamType from Interface (which remains for compatibility reasons) and ValueType from MoniTool");
cls_Interface_TypedValue.def_static("ParamTypeToValueType_", (MoniTool_ValueType (*)(const Interface_ParamType)) &Interface_TypedValue::ParamTypeToValueType, "Correspondance ParamType from Interface to ValueType from MoniTool", py::arg("typ"));
cls_Interface_TypedValue.def_static("ValueTypeToParamType_", (Interface_ParamType (*)(const MoniTool_ValueType)) &Interface_TypedValue::ValueTypeToParamType, "Correspondance ParamType from Interface to ValueType from MoniTool", py::arg("typ"));
cls_Interface_TypedValue.def_static("get_type_name_", (const char * (*)()) &Interface_TypedValue::get_type_name, "None");
cls_Interface_TypedValue.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Interface_TypedValue::get_type_descriptor, "None");
cls_Interface_TypedValue.def("DynamicType", (const opencascade::handle<Standard_Type> & (Interface_TypedValue::*)() const) &Interface_TypedValue::DynamicType, "None");

// Enums

}