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
#include <ShapeProcess_Operator.hxx>
#include <ShapeProcess_OperFunc.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <ShapeProcess_Context.hxx>
#include <ShapeProcess_UOperator.hxx>
#include <Standard_Type.hxx>

void bind_ShapeProcess_UOperator(py::module &mod){

py::class_<ShapeProcess_UOperator, opencascade::handle<ShapeProcess_UOperator>, ShapeProcess_Operator> cls_ShapeProcess_UOperator(mod, "ShapeProcess_UOperator", "Defines operator as container for static function OperFunc. This allows user to create new operators without creation of new classes");

// Constructors
cls_ShapeProcess_UOperator.def(py::init<const ShapeProcess_OperFunc>(), py::arg("func"));

// Fields

// Methods
cls_ShapeProcess_UOperator.def("Perform", (Standard_Boolean (ShapeProcess_UOperator::*)(const opencascade::handle<ShapeProcess_Context> &)) &ShapeProcess_UOperator::Perform, "Performs operation and records changes in the context", py::arg("context"));
cls_ShapeProcess_UOperator.def_static("get_type_name_", (const char * (*)()) &ShapeProcess_UOperator::get_type_name, "None");
cls_ShapeProcess_UOperator.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeProcess_UOperator::get_type_descriptor, "None");
cls_ShapeProcess_UOperator.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeProcess_UOperator::*)() const) &ShapeProcess_UOperator::DynamicType, "None");

// Enums

}