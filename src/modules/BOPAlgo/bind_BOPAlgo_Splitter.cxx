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
#include <BOPAlgo_ToolsProvider.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <BOPAlgo_Splitter.hxx>

void bind_BOPAlgo_Splitter(py::module &mod){

py::class_<BOPAlgo_Splitter, std::unique_ptr<BOPAlgo_Splitter>, BOPAlgo_ToolsProvider> cls_BOPAlgo_Splitter(mod, "BOPAlgo_Splitter", "The **Splitter algorithm** is the algorithm for splitting a group of arbitrary shapes by the other group of arbitrary shapes. The arguments of the operation are divided on two groups: *Objects* - shapes that will be split; *Tools* - shapes by which the *Objects* will be split. The result of the operation contains only the split parts of the shapes from the group of *Objects*. The split parts of the shapes from the group of *Tools* are excluded from the result. The shapes can be split by the other shapes from the same group (in case these shapes are interfering).");

// Constructors
cls_BOPAlgo_Splitter.def(py::init<>());
cls_BOPAlgo_Splitter.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));

// Fields

// Methods
// cls_BOPAlgo_Splitter.def_static("operator new_", (void * (*)(size_t)) &BOPAlgo_Splitter::operator new, "None", py::arg("theSize"));
// cls_BOPAlgo_Splitter.def_static("operator delete_", (void (*)(void *)) &BOPAlgo_Splitter::operator delete, "None", py::arg("theAddress"));
// cls_BOPAlgo_Splitter.def_static("operator new[]_", (void * (*)(size_t)) &BOPAlgo_Splitter::operator new[], "None", py::arg("theSize"));
// cls_BOPAlgo_Splitter.def_static("operator delete[]_", (void (*)(void *)) &BOPAlgo_Splitter::operator delete[], "None", py::arg("theAddress"));
// cls_BOPAlgo_Splitter.def_static("operator new_", (void * (*)(size_t, void *)) &BOPAlgo_Splitter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BOPAlgo_Splitter.def_static("operator delete_", (void (*)(void *, void *)) &BOPAlgo_Splitter::operator delete, "None", py::arg(""), py::arg(""));
cls_BOPAlgo_Splitter.def("Perform", (void (BOPAlgo_Splitter::*)()) &BOPAlgo_Splitter::Perform, "Performs the operation");

// Enums

}