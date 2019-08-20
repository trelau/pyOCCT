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
#include <OpenGl_Element.hxx>
#include <OpenGl_Group.hxx>
#include <Standard.hxx>

void bind_OpenGl_ElementNode(py::module &mod){

py::class_<OpenGl_ElementNode, std::unique_ptr<OpenGl_ElementNode>> cls_OpenGl_ElementNode(mod, "OpenGl_ElementNode", "None");

// Constructors

// Fields
cls_OpenGl_ElementNode.def_readwrite("elem", &OpenGl_ElementNode::elem, "None");
cls_OpenGl_ElementNode.def_readwrite("next", &OpenGl_ElementNode::next, "None");

// Methods
// cls_OpenGl_ElementNode.def_static("operator new_", (void * (*)(size_t)) &OpenGl_ElementNode::operator new, "None", py::arg("theSize"));
// cls_OpenGl_ElementNode.def_static("operator delete_", (void (*)(void *)) &OpenGl_ElementNode::operator delete, "None", py::arg("theAddress"));
// cls_OpenGl_ElementNode.def_static("operator new[]_", (void * (*)(size_t)) &OpenGl_ElementNode::operator new[], "None", py::arg("theSize"));
// cls_OpenGl_ElementNode.def_static("operator delete[]_", (void (*)(void *)) &OpenGl_ElementNode::operator delete[], "None", py::arg("theAddress"));
// cls_OpenGl_ElementNode.def_static("operator new_", (void * (*)(size_t, void *)) &OpenGl_ElementNode::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_OpenGl_ElementNode.def_static("operator delete_", (void (*)(void *, void *)) &OpenGl_ElementNode::operator delete, "None", py::arg(""), py::arg(""));

// Enums

}