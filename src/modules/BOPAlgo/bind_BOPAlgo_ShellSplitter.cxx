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
#include <BOPAlgo_Algo.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <TopoDS_Shape.hxx>
#include <TopTools_ListOfShape.hxx>
#include <BOPTools_ConnexityBlock.hxx>
#include <BOPTools_ListOfConnexityBlock.hxx>
#include <BOPAlgo_ShellSplitter.hxx>

void bind_BOPAlgo_ShellSplitter(py::module &mod){

py::class_<BOPAlgo_ShellSplitter, BOPAlgo_Algo> cls_BOPAlgo_ShellSplitter(mod, "BOPAlgo_ShellSplitter", "The class provides the splitting of the set of connected faces on separate loops");

// Constructors
cls_BOPAlgo_ShellSplitter.def(py::init<>());
cls_BOPAlgo_ShellSplitter.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));

// Fields

// Methods
// cls_BOPAlgo_ShellSplitter.def_static("operator new_", (void * (*)(size_t)) &BOPAlgo_ShellSplitter::operator new, "None", py::arg("theSize"));
// cls_BOPAlgo_ShellSplitter.def_static("operator delete_", (void (*)(void *)) &BOPAlgo_ShellSplitter::operator delete, "None", py::arg("theAddress"));
// cls_BOPAlgo_ShellSplitter.def_static("operator new[]_", (void * (*)(size_t)) &BOPAlgo_ShellSplitter::operator new[], "None", py::arg("theSize"));
// cls_BOPAlgo_ShellSplitter.def_static("operator delete[]_", (void (*)(void *)) &BOPAlgo_ShellSplitter::operator delete[], "None", py::arg("theAddress"));
// cls_BOPAlgo_ShellSplitter.def_static("operator new_", (void * (*)(size_t, void *)) &BOPAlgo_ShellSplitter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BOPAlgo_ShellSplitter.def_static("operator delete_", (void (*)(void *, void *)) &BOPAlgo_ShellSplitter::operator delete, "None", py::arg(""), py::arg(""));
cls_BOPAlgo_ShellSplitter.def("AddStartElement", (void (BOPAlgo_ShellSplitter::*)(const TopoDS_Shape &)) &BOPAlgo_ShellSplitter::AddStartElement, "adds a face <theS> to process", py::arg("theS"));
cls_BOPAlgo_ShellSplitter.def("StartElements", (const TopTools_ListOfShape & (BOPAlgo_ShellSplitter::*)() const) &BOPAlgo_ShellSplitter::StartElements, "return the faces to process");
cls_BOPAlgo_ShellSplitter.def("Perform", (void (BOPAlgo_ShellSplitter::*)()) &BOPAlgo_ShellSplitter::Perform, "performs the algorithm");
cls_BOPAlgo_ShellSplitter.def("Shells", (const TopTools_ListOfShape & (BOPAlgo_ShellSplitter::*)() const) &BOPAlgo_ShellSplitter::Shells, "returns the loops");
cls_BOPAlgo_ShellSplitter.def_static("SplitBlock_", (void (*)(BOPTools_ConnexityBlock &)) &BOPAlgo_ShellSplitter::SplitBlock, "None", py::arg("theCB"));

// Enums

}