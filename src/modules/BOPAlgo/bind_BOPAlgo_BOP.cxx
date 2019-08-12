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
#include <BOPAlgo_Operation.hxx>
#include <BOPAlgo_PaveFiller.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Shape.hxx>
#include <BOPAlgo_BOP.hxx>

void bind_BOPAlgo_BOP(py::module &mod){

py::class_<BOPAlgo_BOP, std::unique_ptr<BOPAlgo_BOP, Deleter<BOPAlgo_BOP>>, BOPAlgo_ToolsProvider> cls_BOPAlgo_BOP(mod, "BOPAlgo_BOP", "The class represents the Building part of the Boolean Operations algorithm. The arguments of the algorithms are divided in two groups - *Objects* and *Tools*. The algorithm builds the splits of the given arguments using the intersection results and combines the result of Boolean Operation of given type: - *FUSE* - union of two groups of objects; - *COMMON* - intersection of two groups of objects; - *CUT* - subtraction of one group from the other.");

// Constructors
cls_BOPAlgo_BOP.def(py::init<>());
cls_BOPAlgo_BOP.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));

// Fields

// Methods
// cls_BOPAlgo_BOP.def_static("operator new_", (void * (*)(size_t)) &BOPAlgo_BOP::operator new, "None", py::arg("theSize"));
// cls_BOPAlgo_BOP.def_static("operator delete_", (void (*)(void *)) &BOPAlgo_BOP::operator delete, "None", py::arg("theAddress"));
// cls_BOPAlgo_BOP.def_static("operator new[]_", (void * (*)(size_t)) &BOPAlgo_BOP::operator new[], "None", py::arg("theSize"));
// cls_BOPAlgo_BOP.def_static("operator delete[]_", (void (*)(void *)) &BOPAlgo_BOP::operator delete[], "None", py::arg("theAddress"));
// cls_BOPAlgo_BOP.def_static("operator new_", (void * (*)(size_t, void *)) &BOPAlgo_BOP::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BOPAlgo_BOP.def_static("operator delete_", (void (*)(void *, void *)) &BOPAlgo_BOP::operator delete, "None", py::arg(""), py::arg(""));
cls_BOPAlgo_BOP.def("Clear", (void (BOPAlgo_BOP::*)()) &BOPAlgo_BOP::Clear, "Clears internal fields and arguments");
cls_BOPAlgo_BOP.def("SetOperation", (void (BOPAlgo_BOP::*)(const BOPAlgo_Operation)) &BOPAlgo_BOP::SetOperation, "None", py::arg("theOperation"));
cls_BOPAlgo_BOP.def("Operation", (BOPAlgo_Operation (BOPAlgo_BOP::*)() const) &BOPAlgo_BOP::Operation, "None");
cls_BOPAlgo_BOP.def("Perform", (void (BOPAlgo_BOP::*)()) &BOPAlgo_BOP::Perform, "None");

// Enums

}