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
#include <Standard_OutOfRange.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <V3d_BadValue.hxx>
#include <Standard_SStream.hxx>
#include <Standard_Type.hxx>

void bind_V3d_BadValue(py::module &mod){

py::class_<V3d_BadValue, opencascade::handle<V3d_BadValue>, Standard_OutOfRange> cls_V3d_BadValue(mod, "V3d_BadValue", "None");

// Constructors
cls_V3d_BadValue.def(py::init<>());
cls_V3d_BadValue.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Fields

// Methods
cls_V3d_BadValue.def_static("Raise_", (void (*)(const Standard_CString)) &V3d_BadValue::Raise, "None", py::arg("theMessage"));
cls_V3d_BadValue.def_static("Raise_", (void (*)(Standard_SStream &)) &V3d_BadValue::Raise, "None", py::arg("theMessage"));
cls_V3d_BadValue.def_static("NewInstance_", (opencascade::handle<V3d_BadValue> (*)(const Standard_CString)) &V3d_BadValue::NewInstance, "None", py::arg("theMessage"));
cls_V3d_BadValue.def_static("get_type_name_", (const char * (*)()) &V3d_BadValue::get_type_name, "None");
cls_V3d_BadValue.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &V3d_BadValue::get_type_descriptor, "None");
cls_V3d_BadValue.def("DynamicType", (const opencascade::handle<Standard_Type> & (V3d_BadValue::*)() const) &V3d_BadValue::DynamicType, "None");

// Enums

}