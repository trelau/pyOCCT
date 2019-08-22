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
#include <HLRBRep_FaceData.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <HLRAlgo_EdgesBlock.hxx>
#include <TopAbs_Orientation.hxx>
#include <HLRAlgo_WiresBlock.hxx>
#include <HLRBRep_FaceIterator.hxx>

void bind_HLRBRep_FaceIterator(py::module &mod){

py::class_<HLRBRep_FaceIterator> cls_HLRBRep_FaceIterator(mod, "HLRBRep_FaceIterator", "None");

// Constructors
cls_HLRBRep_FaceIterator.def(py::init<>());

// Fields

// Methods
// cls_HLRBRep_FaceIterator.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_FaceIterator::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_FaceIterator.def_static("operator delete_", (void (*)(void *)) &HLRBRep_FaceIterator::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_FaceIterator.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_FaceIterator::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_FaceIterator.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_FaceIterator::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_FaceIterator.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_FaceIterator::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_FaceIterator.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_FaceIterator::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_FaceIterator.def("InitEdge", (void (HLRBRep_FaceIterator::*)(HLRBRep_FaceData &)) &HLRBRep_FaceIterator::InitEdge, "Begin an exploration of the edges of the face <fd>", py::arg("fd"));
cls_HLRBRep_FaceIterator.def("MoreEdge", (Standard_Boolean (HLRBRep_FaceIterator::*)() const) &HLRBRep_FaceIterator::MoreEdge, "None");
cls_HLRBRep_FaceIterator.def("NextEdge", (void (HLRBRep_FaceIterator::*)()) &HLRBRep_FaceIterator::NextEdge, "None");
cls_HLRBRep_FaceIterator.def("BeginningOfWire", (Standard_Boolean (HLRBRep_FaceIterator::*)() const) &HLRBRep_FaceIterator::BeginningOfWire, "Returns True if the current edge is the first of a wire.");
cls_HLRBRep_FaceIterator.def("EndOfWire", (Standard_Boolean (HLRBRep_FaceIterator::*)() const) &HLRBRep_FaceIterator::EndOfWire, "Returns True if the current edge is the last of a wire.");
cls_HLRBRep_FaceIterator.def("SkipWire", (void (HLRBRep_FaceIterator::*)()) &HLRBRep_FaceIterator::SkipWire, "Skip the current wire in the exploration.");
cls_HLRBRep_FaceIterator.def("Wire", (opencascade::handle<HLRAlgo_EdgesBlock> (HLRBRep_FaceIterator::*)() const) &HLRBRep_FaceIterator::Wire, "Returns the edges of the current wire.");
cls_HLRBRep_FaceIterator.def("Edge", (Standard_Integer (HLRBRep_FaceIterator::*)() const) &HLRBRep_FaceIterator::Edge, "None");
cls_HLRBRep_FaceIterator.def("Orientation", (TopAbs_Orientation (HLRBRep_FaceIterator::*)() const) &HLRBRep_FaceIterator::Orientation, "None");
cls_HLRBRep_FaceIterator.def("OutLine", (Standard_Boolean (HLRBRep_FaceIterator::*)() const) &HLRBRep_FaceIterator::OutLine, "None");
cls_HLRBRep_FaceIterator.def("Internal", (Standard_Boolean (HLRBRep_FaceIterator::*)() const) &HLRBRep_FaceIterator::Internal, "None");
cls_HLRBRep_FaceIterator.def("Double", (Standard_Boolean (HLRBRep_FaceIterator::*)() const) &HLRBRep_FaceIterator::Double, "None");
cls_HLRBRep_FaceIterator.def("IsoLine", (Standard_Boolean (HLRBRep_FaceIterator::*)() const) &HLRBRep_FaceIterator::IsoLine, "None");

// Enums

}