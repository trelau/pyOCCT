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
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_BaseSequence.hxx>

void bind_NCollection_SeqNode(py::module &mod){

py::class_<NCollection_SeqNode, std::unique_ptr<NCollection_SeqNode>> cls_NCollection_SeqNode(mod, "NCollection_SeqNode", "None");

// Constructors
// cls_NCollection_SeqNode.def(py::init<>());

// Fields

// Methods
// cls_NCollection_SeqNode.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &NCollection_SeqNode::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_NCollection_SeqNode.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &NCollection_SeqNode::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_NCollection_SeqNode.def("Next", (NCollection_SeqNode * (NCollection_SeqNode::*)() const) &NCollection_SeqNode::Next, "None");
cls_NCollection_SeqNode.def("Previous", (NCollection_SeqNode * (NCollection_SeqNode::*)() const) &NCollection_SeqNode::Previous, "None");
cls_NCollection_SeqNode.def("SetNext", (void (NCollection_SeqNode::*)(NCollection_SeqNode *)) &NCollection_SeqNode::SetNext, "None", py::arg("theNext"));
cls_NCollection_SeqNode.def("SetPrevious", (void (NCollection_SeqNode::*)(NCollection_SeqNode *)) &NCollection_SeqNode::SetPrevious, "None", py::arg("thePrev"));

// Enums

}