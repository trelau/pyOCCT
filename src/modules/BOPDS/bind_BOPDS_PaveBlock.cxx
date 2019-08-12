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
#include <BOPDS_Pave.hxx>
#include <Standard_TypeDef.hxx>
#include <BOPDS_PaveBlock.hxx>
#include <BOPDS_ListOfPave.hxx>
#include <BOPDS_ListOfPaveBlock.hxx>
#include <Bnd_Box.hxx>
#include <Standard_Type.hxx>
#include <TColStd_MapOfInteger.hxx>

void bind_BOPDS_PaveBlock(py::module &mod){

py::class_<BOPDS_PaveBlock, opencascade::handle<BOPDS_PaveBlock>, Standard_Transient> cls_BOPDS_PaveBlock(mod, "BOPDS_PaveBlock", "The class BOPDS_PaveBlock is to store the information about pave block on an edge. Two adjacent paves on edge make up pave block.");

// Constructors
cls_BOPDS_PaveBlock.def(py::init<>());
cls_BOPDS_PaveBlock.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));

// Fields

// Methods
cls_BOPDS_PaveBlock.def("SetPave1", (void (BOPDS_PaveBlock::*)(const BOPDS_Pave &)) &BOPDS_PaveBlock::SetPave1, "Modifier Sets the first pave <thePave>", py::arg("thePave"));
cls_BOPDS_PaveBlock.def("Pave1", (const BOPDS_Pave & (BOPDS_PaveBlock::*)() const) &BOPDS_PaveBlock::Pave1, "Selector Returns the first pave");
cls_BOPDS_PaveBlock.def("SetPave2", (void (BOPDS_PaveBlock::*)(const BOPDS_Pave &)) &BOPDS_PaveBlock::SetPave2, "Modifier Sets the second pave <thePave>", py::arg("thePave"));
cls_BOPDS_PaveBlock.def("Pave2", (const BOPDS_Pave & (BOPDS_PaveBlock::*)() const) &BOPDS_PaveBlock::Pave2, "Selector Returns the second pave");
cls_BOPDS_PaveBlock.def("SetEdge", (void (BOPDS_PaveBlock::*)(const Standard_Integer)) &BOPDS_PaveBlock::SetEdge, "Modifier Sets the index of edge of pave block <theEdge>", py::arg("theEdge"));
cls_BOPDS_PaveBlock.def("Edge", (Standard_Integer (BOPDS_PaveBlock::*)() const) &BOPDS_PaveBlock::Edge, "Selector Returns the index of edge of pave block");
cls_BOPDS_PaveBlock.def("HasEdge", (Standard_Boolean (BOPDS_PaveBlock::*)() const) &BOPDS_PaveBlock::HasEdge, "Query Returns true if the pave block has edge");
cls_BOPDS_PaveBlock.def("HasEdge", [](BOPDS_PaveBlock &self, Standard_Integer & theEdge){ Standard_Boolean rv = self.HasEdge(theEdge); return std::tuple<Standard_Boolean, Standard_Integer &>(rv, theEdge); }, "Query Returns true if the pave block has edge Returns the index of edge <theEdge>", py::arg("theEdge"));
cls_BOPDS_PaveBlock.def("SetOriginalEdge", (void (BOPDS_PaveBlock::*)(const Standard_Integer)) &BOPDS_PaveBlock::SetOriginalEdge, "Modifier Sets the index of original edge of the pave block <theEdge>", py::arg("theEdge"));
cls_BOPDS_PaveBlock.def("OriginalEdge", (Standard_Integer (BOPDS_PaveBlock::*)() const) &BOPDS_PaveBlock::OriginalEdge, "Selector Returns the index of original edge of pave block");
cls_BOPDS_PaveBlock.def("IsSplitEdge", (Standard_Boolean (BOPDS_PaveBlock::*)() const) &BOPDS_PaveBlock::IsSplitEdge, "Query Returns true if the edge is equal to the original edge of the pave block");
cls_BOPDS_PaveBlock.def("Range", [](BOPDS_PaveBlock &self, Standard_Real & theT1, Standard_Real & theT2){ self.Range(theT1, theT2); return std::tuple<Standard_Real &, Standard_Real &>(theT1, theT2); }, "Selector Returns the parametric range <theT1,theT2> of the pave block", py::arg("theT1"), py::arg("theT2"));
cls_BOPDS_PaveBlock.def("HasSameBounds", (Standard_Boolean (BOPDS_PaveBlock::*)(const opencascade::handle<BOPDS_PaveBlock> &) const) &BOPDS_PaveBlock::HasSameBounds, "Query Returns true if the pave block has pave indices that equal to the pave indices of the pave block <theOther>", py::arg("theOther"));
cls_BOPDS_PaveBlock.def("Indices", [](BOPDS_PaveBlock &self, Standard_Integer & theIndex1, Standard_Integer & theIndex2){ self.Indices(theIndex1, theIndex2); return std::tuple<Standard_Integer &, Standard_Integer &>(theIndex1, theIndex2); }, "Selector Returns the pave indices <theIndex1,theIndex2> of the pave block", py::arg("theIndex1"), py::arg("theIndex2"));
cls_BOPDS_PaveBlock.def("IsToUpdate", (Standard_Boolean (BOPDS_PaveBlock::*)() const) &BOPDS_PaveBlock::IsToUpdate, "Query Returns true if the pave block contains extra paves");
cls_BOPDS_PaveBlock.def("AppendExtPave", (void (BOPDS_PaveBlock::*)(const BOPDS_Pave &)) &BOPDS_PaveBlock::AppendExtPave, "Modifier Appends extra paves <thePave>", py::arg("thePave"));
cls_BOPDS_PaveBlock.def("AppendExtPave1", (void (BOPDS_PaveBlock::*)(const BOPDS_Pave &)) &BOPDS_PaveBlock::AppendExtPave1, "Modifier Appends extra pave <thePave>", py::arg("thePave"));
cls_BOPDS_PaveBlock.def("RemoveExtPave", (void (BOPDS_PaveBlock::*)(const Standard_Integer)) &BOPDS_PaveBlock::RemoveExtPave, "Modifier Removes a pave with the given vertex number from extra paves", py::arg("theVertNum"));
cls_BOPDS_PaveBlock.def("ExtPaves", (const BOPDS_ListOfPave & (BOPDS_PaveBlock::*)() const) &BOPDS_PaveBlock::ExtPaves, "Selector Returns the extra paves");
cls_BOPDS_PaveBlock.def("ChangeExtPaves", (BOPDS_ListOfPave & (BOPDS_PaveBlock::*)()) &BOPDS_PaveBlock::ChangeExtPaves, "Selector / Modifier Returns the extra paves");
cls_BOPDS_PaveBlock.def("Update", [](BOPDS_PaveBlock &self, BOPDS_ListOfPaveBlock & a0) -> void { return self.Update(a0); });
cls_BOPDS_PaveBlock.def("Update", (void (BOPDS_PaveBlock::*)(BOPDS_ListOfPaveBlock &, const Standard_Boolean)) &BOPDS_PaveBlock::Update, "Modifier Updates the pave block. The extra paves are used to create new pave blocks <theLPB>. <theFlag> - if true, the first pave and the second pave are used to produce new pave blocks.", py::arg("theLPB"), py::arg("theFlag"));
cls_BOPDS_PaveBlock.def("ContainsParameter", [](BOPDS_PaveBlock &self, const Standard_Real thePrm, const Standard_Real theTol, Standard_Integer & theInd){ Standard_Boolean rv = self.ContainsParameter(thePrm, theTol, theInd); return std::tuple<Standard_Boolean, Standard_Integer &>(rv, theInd); }, "Query Returns true if the extra paves contain the pave with given value of the parameter <thePrm> <theTol> - the value of the tolerance to compare <theInd> - index of the found pave", py::arg("thePrm"), py::arg("theTol"), py::arg("theInd"));
cls_BOPDS_PaveBlock.def("SetShrunkData", (void (BOPDS_PaveBlock::*)(const Standard_Real, const Standard_Real, const Bnd_Box &, const Standard_Boolean)) &BOPDS_PaveBlock::SetShrunkData, "Modifier Sets the shrunk data for the pave block <theTS1>, <theTS2> - shrunk range <theBox> - the bounding box <theIsSplittable> - defines whether the edge can be split", py::arg("theTS1"), py::arg("theTS2"), py::arg("theBox"), py::arg("theIsSplittable"));
cls_BOPDS_PaveBlock.def("ShrunkData", [](BOPDS_PaveBlock &self, Standard_Real & theTS1, Standard_Real & theTS2, Bnd_Box & theBox, Standard_Boolean & theIsSplittable){ self.ShrunkData(theTS1, theTS2, theBox, theIsSplittable); return std::tuple<Standard_Real &, Standard_Real &, Standard_Boolean &>(theTS1, theTS2, theIsSplittable); }, "Selector Returns the shrunk data for the pave block <theTS1>, <theTS2> - shrunk range <theBox> - the bounding box <theIsSplittable> - defines whether the edge can be split", py::arg("theTS1"), py::arg("theTS2"), py::arg("theBox"), py::arg("theIsSplittable"));
cls_BOPDS_PaveBlock.def("HasShrunkData", (Standard_Boolean (BOPDS_PaveBlock::*)() const) &BOPDS_PaveBlock::HasShrunkData, "Query Returns true if the pave block contains the shrunk data");
cls_BOPDS_PaveBlock.def("Dump", (void (BOPDS_PaveBlock::*)() const) &BOPDS_PaveBlock::Dump, "None");
cls_BOPDS_PaveBlock.def("IsSplittable", (Standard_Boolean (BOPDS_PaveBlock::*)() const) &BOPDS_PaveBlock::IsSplittable, "Query Returns FALSE if the pave block has a too short shrunk range and cannot be split, otherwise returns TRUE");
cls_BOPDS_PaveBlock.def_static("get_type_name_", (const char * (*)()) &BOPDS_PaveBlock::get_type_name, "None");
cls_BOPDS_PaveBlock.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BOPDS_PaveBlock::get_type_descriptor, "None");
cls_BOPDS_PaveBlock.def("DynamicType", (const opencascade::handle<Standard_Type> & (BOPDS_PaveBlock::*)() const) &BOPDS_PaveBlock::DynamicType, "None");

// Enums

}