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
#include <Standard_OStream.hxx>
#include <Standard_TypeDef.hxx>
#include <Vrml_Group.hxx>

void bind_Vrml_Group(py::module &mod){

py::class_<Vrml_Group, std::unique_ptr<Vrml_Group>> cls_Vrml_Group(mod, "Vrml_Group", "defines a Group node of VRML specifying group properties. This node defines the base class for all group nodes. Group is a node that contains an ordered list of child nodes. This node is simply a container for the child nodes and does not alter the traversal state in any way. During traversal, state accumulated for a child is passed on to each successive child and then to the parents of the group (Group does not push or pop traversal state as separator does).");

// Constructors
cls_Vrml_Group.def(py::init<>());

// Fields

// Methods
// cls_Vrml_Group.def_static("operator new_", (void * (*)(size_t)) &Vrml_Group::operator new, "None", py::arg("theSize"));
// cls_Vrml_Group.def_static("operator delete_", (void (*)(void *)) &Vrml_Group::operator delete, "None", py::arg("theAddress"));
// cls_Vrml_Group.def_static("operator new[]_", (void * (*)(size_t)) &Vrml_Group::operator new[], "None", py::arg("theSize"));
// cls_Vrml_Group.def_static("operator delete[]_", (void (*)(void *)) &Vrml_Group::operator delete[], "None", py::arg("theAddress"));
// cls_Vrml_Group.def_static("operator new_", (void * (*)(size_t, void *)) &Vrml_Group::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Vrml_Group.def_static("operator delete_", (void (*)(void *, void *)) &Vrml_Group::operator delete, "None", py::arg(""), py::arg(""));
cls_Vrml_Group.def("Print", (Standard_OStream & (Vrml_Group::*)(Standard_OStream &)) &Vrml_Group::Print, "None", py::arg("anOStream"));

// Enums

}