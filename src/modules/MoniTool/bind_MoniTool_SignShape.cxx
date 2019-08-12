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
#include <MoniTool_SignText.hxx>
#include <Standard_TypeDef.hxx>
#include <TCollection_AsciiString.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Transient.hxx>
#include <MoniTool_SignShape.hxx>
#include <Standard_Type.hxx>

void bind_MoniTool_SignShape(py::module &mod){

py::class_<MoniTool_SignShape, opencascade::handle<MoniTool_SignShape>, MoniTool_SignText> cls_MoniTool_SignShape(mod, "MoniTool_SignShape", "Signs HShape according to its real content (type of Shape) Context is not used");

// Constructors
cls_MoniTool_SignShape.def(py::init<>());

// Fields

// Methods
cls_MoniTool_SignShape.def("Name", (Standard_CString (MoniTool_SignShape::*)() const) &MoniTool_SignShape::Name, "Returns 'SHAPE'");
cls_MoniTool_SignShape.def("Text", (TCollection_AsciiString (MoniTool_SignShape::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Standard_Transient> &) const) &MoniTool_SignShape::Text, "Returns for a HShape, the string of its ShapeEnum The Model is absolutely useless (may be null)", py::arg("ent"), py::arg("context"));
cls_MoniTool_SignShape.def_static("get_type_name_", (const char * (*)()) &MoniTool_SignShape::get_type_name, "None");
cls_MoniTool_SignShape.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MoniTool_SignShape::get_type_descriptor, "None");
cls_MoniTool_SignShape.def("DynamicType", (const opencascade::handle<Standard_Type> & (MoniTool_SignShape::*)() const) &MoniTool_SignShape::DynamicType, "None");

// Enums

}