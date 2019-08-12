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
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <LDOM_Node.hxx>
#include <LDOM_BasicNode.hxx>
#include <LDOM_BasicElement.hxx>
#include <LDOMParser.hxx>

void bind_LDOM_BasicNode(py::module &mod){

py::class_<LDOM_BasicNode, std::unique_ptr<LDOM_BasicNode, Deleter<LDOM_BasicNode>>> cls_LDOM_BasicNode(mod, "LDOM_BasicNode", "None");

// Constructors

// Fields

// Methods
// cls_LDOM_BasicNode.def_static("operator new_", (void * (*)(size_t)) &LDOM_BasicNode::operator new, "None", py::arg("theSize"));
// cls_LDOM_BasicNode.def_static("operator delete_", (void (*)(void *)) &LDOM_BasicNode::operator delete, "None", py::arg("theAddress"));
// cls_LDOM_BasicNode.def_static("operator new[]_", (void * (*)(size_t)) &LDOM_BasicNode::operator new[], "None", py::arg("theSize"));
// cls_LDOM_BasicNode.def_static("operator delete[]_", (void (*)(void *)) &LDOM_BasicNode::operator delete[], "None", py::arg("theAddress"));
// cls_LDOM_BasicNode.def_static("operator new_", (void * (*)(size_t, void *)) &LDOM_BasicNode::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_LDOM_BasicNode.def_static("operator delete_", (void (*)(void *, void *)) &LDOM_BasicNode::operator delete, "None", py::arg(""), py::arg(""));
cls_LDOM_BasicNode.def("isNull", (Standard_Boolean (LDOM_BasicNode::*)() const) &LDOM_BasicNode::isNull, "None");
cls_LDOM_BasicNode.def("getNodeType", (LDOM_Node::NodeType (LDOM_BasicNode::*)() const) &LDOM_BasicNode::getNodeType, "None");
cls_LDOM_BasicNode.def("GetSibling", (const LDOM_BasicNode * (LDOM_BasicNode::*)() const) &LDOM_BasicNode::GetSibling, "None");

// Enums

}