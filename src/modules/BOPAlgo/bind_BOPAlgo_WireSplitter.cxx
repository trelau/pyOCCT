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
#include <BOPAlgo_WireEdgeSet.hxx>
#include <IntTools_Context.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TopoDS_Wire.hxx>
#include <TopoDS_Face.hxx>
#include <BOPTools_ConnexityBlock.hxx>
#include <BOPAlgo_PWireEdgeSet.hxx>
#include <BOPTools_ListOfConnexityBlock.hxx>
#include <BOPAlgo_WireSplitter.hxx>

void bind_BOPAlgo_WireSplitter(py::module &mod){

py::class_<BOPAlgo_WireSplitter, std::unique_ptr<BOPAlgo_WireSplitter>, BOPAlgo_Algo> cls_BOPAlgo_WireSplitter(mod, "BOPAlgo_WireSplitter", "The class is to build loops from the given set of edges.");

// Constructors
cls_BOPAlgo_WireSplitter.def(py::init<>());
cls_BOPAlgo_WireSplitter.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));

// Fields

// Methods
// cls_BOPAlgo_WireSplitter.def_static("operator new_", (void * (*)(size_t)) &BOPAlgo_WireSplitter::operator new, "None", py::arg("theSize"));
// cls_BOPAlgo_WireSplitter.def_static("operator delete_", (void (*)(void *)) &BOPAlgo_WireSplitter::operator delete, "None", py::arg("theAddress"));
// cls_BOPAlgo_WireSplitter.def_static("operator new[]_", (void * (*)(size_t)) &BOPAlgo_WireSplitter::operator new[], "None", py::arg("theSize"));
// cls_BOPAlgo_WireSplitter.def_static("operator delete[]_", (void (*)(void *)) &BOPAlgo_WireSplitter::operator delete[], "None", py::arg("theAddress"));
// cls_BOPAlgo_WireSplitter.def_static("operator new_", (void * (*)(size_t, void *)) &BOPAlgo_WireSplitter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BOPAlgo_WireSplitter.def_static("operator delete_", (void (*)(void *, void *)) &BOPAlgo_WireSplitter::operator delete, "None", py::arg(""), py::arg(""));
cls_BOPAlgo_WireSplitter.def("SetWES", (void (BOPAlgo_WireSplitter::*)(const BOPAlgo_WireEdgeSet &)) &BOPAlgo_WireSplitter::SetWES, "None", py::arg("theWES"));
cls_BOPAlgo_WireSplitter.def("WES", (BOPAlgo_WireEdgeSet & (BOPAlgo_WireSplitter::*)()) &BOPAlgo_WireSplitter::WES, "None");
cls_BOPAlgo_WireSplitter.def("SetContext", (void (BOPAlgo_WireSplitter::*)(const opencascade::handle<IntTools_Context> &)) &BOPAlgo_WireSplitter::SetContext, "Sets the context for the algorithm", py::arg("theContext"));
cls_BOPAlgo_WireSplitter.def("Context", (const opencascade::handle<IntTools_Context> & (BOPAlgo_WireSplitter::*)()) &BOPAlgo_WireSplitter::Context, "Returns the context");
cls_BOPAlgo_WireSplitter.def("Perform", (void (BOPAlgo_WireSplitter::*)()) &BOPAlgo_WireSplitter::Perform, "None");
cls_BOPAlgo_WireSplitter.def_static("MakeWire_", (void (*)(TopTools_ListOfShape &, TopoDS_Wire &)) &BOPAlgo_WireSplitter::MakeWire, "None", py::arg("theLE"), py::arg("theW"));
cls_BOPAlgo_WireSplitter.def_static("SplitBlock_", (void (*)(const TopoDS_Face &, BOPTools_ConnexityBlock &, const opencascade::handle<IntTools_Context> &)) &BOPAlgo_WireSplitter::SplitBlock, "None", py::arg("theF"), py::arg("theCB"), py::arg("theContext"));

// Enums

}