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
#include <TopOpeBRepBuild_BlockIterator.hxx>

void bind_TopOpeBRepBuild_BlockIterator(py::module &mod){

py::class_<TopOpeBRepBuild_BlockIterator> cls_TopOpeBRepBuild_BlockIterator(mod, "TopOpeBRepBuild_BlockIterator", "Iterator on the elements of a block.");

// Constructors
cls_TopOpeBRepBuild_BlockIterator.def(py::init<>());
cls_TopOpeBRepBuild_BlockIterator.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("Lower"), py::arg("Upper"));

// Fields

// Methods
// cls_TopOpeBRepBuild_BlockIterator.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepBuild_BlockIterator::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_BlockIterator.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepBuild_BlockIterator::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_BlockIterator.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepBuild_BlockIterator::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_BlockIterator.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepBuild_BlockIterator::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_BlockIterator.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepBuild_BlockIterator::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepBuild_BlockIterator.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepBuild_BlockIterator::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepBuild_BlockIterator.def("Initialize", (void (TopOpeBRepBuild_BlockIterator::*)()) &TopOpeBRepBuild_BlockIterator::Initialize, "None");
cls_TopOpeBRepBuild_BlockIterator.def("More", (Standard_Boolean (TopOpeBRepBuild_BlockIterator::*)() const) &TopOpeBRepBuild_BlockIterator::More, "None");
cls_TopOpeBRepBuild_BlockIterator.def("Next", (void (TopOpeBRepBuild_BlockIterator::*)()) &TopOpeBRepBuild_BlockIterator::Next, "None");
cls_TopOpeBRepBuild_BlockIterator.def("Value", (Standard_Integer (TopOpeBRepBuild_BlockIterator::*)() const) &TopOpeBRepBuild_BlockIterator::Value, "None");
cls_TopOpeBRepBuild_BlockIterator.def("Extent", (Standard_Integer (TopOpeBRepBuild_BlockIterator::*)() const) &TopOpeBRepBuild_BlockIterator::Extent, "None");

// Enums

}