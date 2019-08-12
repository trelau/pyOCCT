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
#include <IGESData_IGESEntity.hxx>
#include <Standard_Handle.hxx>
#include <IGESData_HArray1OfIGESEntity.hxx>
#include <TColStd_HArray1OfInteger.hxx>
#include <Standard_TypeDef.hxx>
#include <IGESSolid_BooleanTree.hxx>
#include <Standard_Type.hxx>

void bind_IGESSolid_BooleanTree(py::module &mod){

py::class_<IGESSolid_BooleanTree, opencascade::handle<IGESSolid_BooleanTree>, IGESData_IGESEntity> cls_IGESSolid_BooleanTree(mod, "IGESSolid_BooleanTree", "defines BooleanTree, Type <180> Form Number <0> in package IGESSolid The Boolean tree describes a binary tree structure composed of regularized Boolean operations and operands, in post-order notation.");

// Constructors
cls_IGESSolid_BooleanTree.def(py::init<>());

// Fields

// Methods
cls_IGESSolid_BooleanTree.def("Init", (void (IGESSolid_BooleanTree::*)(const opencascade::handle<IGESData_HArray1OfIGESEntity> &, const opencascade::handle<TColStd_HArray1OfInteger> &)) &IGESSolid_BooleanTree::Init, "This method is used to set the fields of the class BooleanTree - operands : Array containing pointer to DE of operands - operations : Array containing integer type for operations", py::arg("operands"), py::arg("operations"));
cls_IGESSolid_BooleanTree.def("Length", (Standard_Integer (IGESSolid_BooleanTree::*)() const) &IGESSolid_BooleanTree::Length, "returns the length of the post-order list");
cls_IGESSolid_BooleanTree.def("IsOperand", (Standard_Boolean (IGESSolid_BooleanTree::*)(const Standard_Integer) const) &IGESSolid_BooleanTree::IsOperand, "returns True if Index'th value in the post-order list is an Operand; else returns False if it is an Integer Operations raises exception if Index < 1 or Index > Length()", py::arg("Index"));
cls_IGESSolid_BooleanTree.def("Operand", (opencascade::handle<IGESData_IGESEntity> (IGESSolid_BooleanTree::*)(const Standard_Integer) const) &IGESSolid_BooleanTree::Operand, "returns the Index'th value in the post-order list only if it is an operand else returns NULL raises exception if Index < 1 or Index > Length()", py::arg("Index"));
cls_IGESSolid_BooleanTree.def("Operation", (Standard_Integer (IGESSolid_BooleanTree::*)(const Standard_Integer) const) &IGESSolid_BooleanTree::Operation, "returns the Index'th value in the post-order list only if it is an operation else returns 0 raises exception if Index < 1 or Index > Length()", py::arg("Index"));
cls_IGESSolid_BooleanTree.def_static("get_type_name_", (const char * (*)()) &IGESSolid_BooleanTree::get_type_name, "None");
cls_IGESSolid_BooleanTree.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSolid_BooleanTree::get_type_descriptor, "None");
cls_IGESSolid_BooleanTree.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSolid_BooleanTree::*)() const) &IGESSolid_BooleanTree::DynamicType, "None");

// Enums

}