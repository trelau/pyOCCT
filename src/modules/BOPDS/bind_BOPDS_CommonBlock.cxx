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
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <BOPDS_PaveBlock.hxx>
#include <BOPDS_ListOfPaveBlock.hxx>
#include <Standard_TypeDef.hxx>
#include <TColStd_ListOfInteger.hxx>
#include <BOPDS_CommonBlock.hxx>
#include <Standard_Type.hxx>

void bind_BOPDS_CommonBlock(py::module &mod){

py::class_<BOPDS_CommonBlock, opencascade::handle<BOPDS_CommonBlock>, Standard_Transient> cls_BOPDS_CommonBlock(mod, "BOPDS_CommonBlock", "The class BOPDS_CommonBlock is to store the information about pave blocks that have geometrical coincidence (in terms of a tolerance) with: a) other pave block(s); b) face(s). First pave block in the common block (real pave block) is always a pave block with the minimal index of the original edge.");

// Constructors
cls_BOPDS_CommonBlock.def(py::init<>());
cls_BOPDS_CommonBlock.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));

// Fields

// Methods
cls_BOPDS_CommonBlock.def("AddPaveBlock", (void (BOPDS_CommonBlock::*)(const opencascade::handle<BOPDS_PaveBlock> &)) &BOPDS_CommonBlock::AddPaveBlock, "Modifier Adds the pave block <aPB> to the list of pave blocks of the common block", py::arg("aPB"));
cls_BOPDS_CommonBlock.def("SetPaveBlocks", (void (BOPDS_CommonBlock::*)(const BOPDS_ListOfPaveBlock &)) &BOPDS_CommonBlock::SetPaveBlocks, "Modifier Adds the list of pave blocks <aLPB> to the list of pave blocks of the common block", py::arg("aLPB"));
cls_BOPDS_CommonBlock.def("AddFace", (void (BOPDS_CommonBlock::*)(const Standard_Integer)) &BOPDS_CommonBlock::AddFace, "Modifier Adds the index of the face <aF> to the list of indices of faces of the common block", py::arg("aF"));
cls_BOPDS_CommonBlock.def("SetFaces", (void (BOPDS_CommonBlock::*)(const TColStd_ListOfInteger &)) &BOPDS_CommonBlock::SetFaces, "Modifier Sets the list of indices of faces <aLF> of the common block", py::arg("aLF"));
cls_BOPDS_CommonBlock.def("AppendFaces", (void (BOPDS_CommonBlock::*)(TColStd_ListOfInteger &)) &BOPDS_CommonBlock::AppendFaces, "Modifier Appends the list of indices of faces <aLF> to the list of indices of faces of the common block (the input list is emptied)", py::arg("aLF"));
cls_BOPDS_CommonBlock.def("PaveBlocks", (const BOPDS_ListOfPaveBlock & (BOPDS_CommonBlock::*)() const) &BOPDS_CommonBlock::PaveBlocks, "Selector Returns the list of pave blocks of the common block");
cls_BOPDS_CommonBlock.def("Faces", (const TColStd_ListOfInteger & (BOPDS_CommonBlock::*)() const) &BOPDS_CommonBlock::Faces, "Selector Returns the list of indices of faces of the common block");
cls_BOPDS_CommonBlock.def("PaveBlock1", (const opencascade::handle<BOPDS_PaveBlock> & (BOPDS_CommonBlock::*)() const) &BOPDS_CommonBlock::PaveBlock1, "Selector Returns the first pave block of the common block");
cls_BOPDS_CommonBlock.def("PaveBlockOnEdge", (opencascade::handle<BOPDS_PaveBlock> & (BOPDS_CommonBlock::*)(const Standard_Integer)) &BOPDS_CommonBlock::PaveBlockOnEdge, "Selector Returns the pave block that belongs to the edge with index <theIx>", py::arg("theIndex"));
cls_BOPDS_CommonBlock.def("IsPaveBlockOnFace", (Standard_Boolean (BOPDS_CommonBlock::*)(const Standard_Integer) const) &BOPDS_CommonBlock::IsPaveBlockOnFace, "Query Returns true if the common block contains a pave block that belongs to the face with index <theIx>", py::arg("theIndex"));
cls_BOPDS_CommonBlock.def("IsPaveBlockOnEdge", (Standard_Boolean (BOPDS_CommonBlock::*)(const Standard_Integer) const) &BOPDS_CommonBlock::IsPaveBlockOnEdge, "Query Returns true if the common block contains a pave block that belongs to the edge with index <theIx>", py::arg("theIndex"));
cls_BOPDS_CommonBlock.def("Contains", (Standard_Boolean (BOPDS_CommonBlock::*)(const opencascade::handle<BOPDS_PaveBlock> &) const) &BOPDS_CommonBlock::Contains, "Query Returns true if the common block contains a pave block that is equal to <thePB>", py::arg("thePB"));
cls_BOPDS_CommonBlock.def("Contains", (Standard_Boolean (BOPDS_CommonBlock::*)(const Standard_Integer) const) &BOPDS_CommonBlock::Contains, "Query Returns true if the common block contains the face with index equal to <theF>", py::arg("theF"));
cls_BOPDS_CommonBlock.def("SetEdge", (void (BOPDS_CommonBlock::*)(const Standard_Integer)) &BOPDS_CommonBlock::SetEdge, "Modifier Assign the index <theEdge> as the edge index to all pave blocks of the common block", py::arg("theEdge"));
cls_BOPDS_CommonBlock.def("Edge", (Standard_Integer (BOPDS_CommonBlock::*)() const) &BOPDS_CommonBlock::Edge, "Selector Returns the index of the edge of all pave blocks of the common block");
cls_BOPDS_CommonBlock.def("Dump", (void (BOPDS_CommonBlock::*)() const) &BOPDS_CommonBlock::Dump, "None");
cls_BOPDS_CommonBlock.def("SetRealPaveBlock", (void (BOPDS_CommonBlock::*)(const opencascade::handle<BOPDS_PaveBlock> &)) &BOPDS_CommonBlock::SetRealPaveBlock, "Moves the pave blocks in the list to make the given pave block to be the first. It will be representative for the whole group.", py::arg("thePB"));
cls_BOPDS_CommonBlock.def_static("get_type_name_", (const char * (*)()) &BOPDS_CommonBlock::get_type_name, "None");
cls_BOPDS_CommonBlock.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BOPDS_CommonBlock::get_type_descriptor, "None");
cls_BOPDS_CommonBlock.def("DynamicType", (const opencascade::handle<Standard_Type> & (BOPDS_CommonBlock::*)() const) &BOPDS_CommonBlock::DynamicType, "None");

// Enums

}