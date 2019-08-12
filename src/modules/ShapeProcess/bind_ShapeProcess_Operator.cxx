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
#include <ShapeProcess_Context.hxx>
#include <ShapeProcess_Operator.hxx>
#include <Standard_Type.hxx>

void bind_ShapeProcess_Operator(py::module &mod){

py::class_<ShapeProcess_Operator, opencascade::handle<ShapeProcess_Operator>, Standard_Transient> cls_ShapeProcess_Operator(mod, "ShapeProcess_Operator", "Abstract Operator class providing a tool to perform an operation on Context");

// Fields

// Methods
cls_ShapeProcess_Operator.def("Perform", (Standard_Boolean (ShapeProcess_Operator::*)(const opencascade::handle<ShapeProcess_Context> &)) &ShapeProcess_Operator::Perform, "Performs operation and eventually records changes in the context", py::arg("context"));
cls_ShapeProcess_Operator.def_static("get_type_name_", (const char * (*)()) &ShapeProcess_Operator::get_type_name, "None");
cls_ShapeProcess_Operator.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeProcess_Operator::get_type_descriptor, "None");
cls_ShapeProcess_Operator.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeProcess_Operator::*)() const) &ShapeProcess_Operator::DynamicType, "None");

// Enums

}