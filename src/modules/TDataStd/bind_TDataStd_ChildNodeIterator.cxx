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
#include <Standard_Handle.hxx>
#include <TDataStd_TreeNode.hxx>
#include <Standard_TypeDef.hxx>
#include <TDataStd_ChildNodeIterator.hxx>

void bind_TDataStd_ChildNodeIterator(py::module &mod){

py::class_<TDataStd_ChildNodeIterator> cls_TDataStd_ChildNodeIterator(mod, "TDataStd_ChildNodeIterator", "Iterates on the ChildStepren step of a step, at the first level only. It is possible to ask the iterator to explore all the sub step levels of the given one, with the option 'allLevels'.");

// Constructors
cls_TDataStd_ChildNodeIterator.def(py::init<>());
cls_TDataStd_ChildNodeIterator.def(py::init<const opencascade::handle<TDataStd_TreeNode> &>(), py::arg("aTreeNode"));
cls_TDataStd_ChildNodeIterator.def(py::init<const opencascade::handle<TDataStd_TreeNode> &, const Standard_Boolean>(), py::arg("aTreeNode"), py::arg("allLevels"));

// Fields

// Methods
// cls_TDataStd_ChildNodeIterator.def_static("operator new_", (void * (*)(size_t)) &TDataStd_ChildNodeIterator::operator new, "None", py::arg("theSize"));
// cls_TDataStd_ChildNodeIterator.def_static("operator delete_", (void (*)(void *)) &TDataStd_ChildNodeIterator::operator delete, "None", py::arg("theAddress"));
// cls_TDataStd_ChildNodeIterator.def_static("operator new[]_", (void * (*)(size_t)) &TDataStd_ChildNodeIterator::operator new[], "None", py::arg("theSize"));
// cls_TDataStd_ChildNodeIterator.def_static("operator delete[]_", (void (*)(void *)) &TDataStd_ChildNodeIterator::operator delete[], "None", py::arg("theAddress"));
// cls_TDataStd_ChildNodeIterator.def_static("operator new_", (void * (*)(size_t, void *)) &TDataStd_ChildNodeIterator::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TDataStd_ChildNodeIterator.def_static("operator delete_", (void (*)(void *, void *)) &TDataStd_ChildNodeIterator::operator delete, "None", py::arg(""), py::arg(""));
cls_TDataStd_ChildNodeIterator.def("Initialize", [](TDataStd_ChildNodeIterator &self, const opencascade::handle<TDataStd_TreeNode> & a0) -> void { return self.Initialize(a0); });
cls_TDataStd_ChildNodeIterator.def("Initialize", (void (TDataStd_ChildNodeIterator::*)(const opencascade::handle<TDataStd_TreeNode> &, const Standard_Boolean)) &TDataStd_ChildNodeIterator::Initialize, "Initializes the iteration on the Children Step of the given Step. If <allLevels> option is set to true, it explores not only the first, but all the sub Step levels.", py::arg("aTreeNode"), py::arg("allLevels"));
cls_TDataStd_ChildNodeIterator.def("More", (Standard_Boolean (TDataStd_ChildNodeIterator::*)() const) &TDataStd_ChildNodeIterator::More, "Returns True if there is a current Item in the iteration.");
cls_TDataStd_ChildNodeIterator.def("Next", (void (TDataStd_ChildNodeIterator::*)()) &TDataStd_ChildNodeIterator::Next, "Move to the next Item");
cls_TDataStd_ChildNodeIterator.def("NextBrother", (void (TDataStd_ChildNodeIterator::*)()) &TDataStd_ChildNodeIterator::NextBrother, "Move to the next Brother. If there is none, go up etc. This method is interesting only with 'allLevels' behavior, because it avoids to explore the current Step ChildStepren.");
cls_TDataStd_ChildNodeIterator.def("Value", (const opencascade::handle<TDataStd_TreeNode> & (TDataStd_ChildNodeIterator::*)() const) &TDataStd_ChildNodeIterator::Value, "Returns the current item; a null Step if there is no one.");

// Enums

}