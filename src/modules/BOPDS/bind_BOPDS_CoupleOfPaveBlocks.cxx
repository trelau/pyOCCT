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
#include <BOPDS_PaveBlock.hxx>
#include <Standard_TypeDef.hxx>
#include <BOPDS_CoupleOfPaveBlocks.hxx>

void bind_BOPDS_CoupleOfPaveBlocks(py::module &mod){

py::class_<BOPDS_CoupleOfPaveBlocks, std::unique_ptr<BOPDS_CoupleOfPaveBlocks, Deleter<BOPDS_CoupleOfPaveBlocks>>> cls_BOPDS_CoupleOfPaveBlocks(mod, "BOPDS_CoupleOfPaveBlocks", "The Class BOPDS_CoupleOfPaveBlocks is to store the information about two pave blocks and some satellite information");

// Constructors
cls_BOPDS_CoupleOfPaveBlocks.def(py::init<>());
cls_BOPDS_CoupleOfPaveBlocks.def(py::init<const opencascade::handle<BOPDS_PaveBlock> &, const opencascade::handle<BOPDS_PaveBlock> &>(), py::arg("thePB1"), py::arg("thePB2"));

// Fields

// Methods
cls_BOPDS_CoupleOfPaveBlocks.def("SetIndex", (void (BOPDS_CoupleOfPaveBlocks::*)(const Standard_Integer)) &BOPDS_CoupleOfPaveBlocks::SetIndex, "Sets an index", py::arg("theIndex"));
cls_BOPDS_CoupleOfPaveBlocks.def("Index", (Standard_Integer (BOPDS_CoupleOfPaveBlocks::*)() const) &BOPDS_CoupleOfPaveBlocks::Index, "Returns the index");
cls_BOPDS_CoupleOfPaveBlocks.def("SetIndexInterf", (void (BOPDS_CoupleOfPaveBlocks::*)(const Standard_Integer)) &BOPDS_CoupleOfPaveBlocks::SetIndexInterf, "Sets an index of an interference", py::arg("theIndex"));
cls_BOPDS_CoupleOfPaveBlocks.def("IndexInterf", (Standard_Integer (BOPDS_CoupleOfPaveBlocks::*)() const) &BOPDS_CoupleOfPaveBlocks::IndexInterf, "Returns the index of an interference");
cls_BOPDS_CoupleOfPaveBlocks.def("SetPaveBlocks", (void (BOPDS_CoupleOfPaveBlocks::*)(const opencascade::handle<BOPDS_PaveBlock> &, const opencascade::handle<BOPDS_PaveBlock> &)) &BOPDS_CoupleOfPaveBlocks::SetPaveBlocks, "Sets pave blocks", py::arg("thePB1"), py::arg("thePB2"));
cls_BOPDS_CoupleOfPaveBlocks.def("PaveBlocks", (void (BOPDS_CoupleOfPaveBlocks::*)(opencascade::handle<BOPDS_PaveBlock> &, opencascade::handle<BOPDS_PaveBlock> &) const) &BOPDS_CoupleOfPaveBlocks::PaveBlocks, "Returns pave blocks", py::arg("thePB1"), py::arg("thePB2"));
cls_BOPDS_CoupleOfPaveBlocks.def("SetPaveBlock1", (void (BOPDS_CoupleOfPaveBlocks::*)(const opencascade::handle<BOPDS_PaveBlock> &)) &BOPDS_CoupleOfPaveBlocks::SetPaveBlock1, "Sets the first pave block", py::arg("thePB"));
cls_BOPDS_CoupleOfPaveBlocks.def("PaveBlock1", (const opencascade::handle<BOPDS_PaveBlock> & (BOPDS_CoupleOfPaveBlocks::*)() const) &BOPDS_CoupleOfPaveBlocks::PaveBlock1, "Returns the first pave block");
cls_BOPDS_CoupleOfPaveBlocks.def("SetPaveBlock2", (void (BOPDS_CoupleOfPaveBlocks::*)(const opencascade::handle<BOPDS_PaveBlock> &)) &BOPDS_CoupleOfPaveBlocks::SetPaveBlock2, "Sets the second pave block", py::arg("thePB"));
cls_BOPDS_CoupleOfPaveBlocks.def("PaveBlock2", (const opencascade::handle<BOPDS_PaveBlock> & (BOPDS_CoupleOfPaveBlocks::*)() const) &BOPDS_CoupleOfPaveBlocks::PaveBlock2, "Returns the second pave block");
cls_BOPDS_CoupleOfPaveBlocks.def("SetTolerance", (void (BOPDS_CoupleOfPaveBlocks::*)(const Standard_Real)) &BOPDS_CoupleOfPaveBlocks::SetTolerance, "Sets the tolerance associated with this couple", py::arg("theTol"));
cls_BOPDS_CoupleOfPaveBlocks.def("Tolerance", (Standard_Real (BOPDS_CoupleOfPaveBlocks::*)() const) &BOPDS_CoupleOfPaveBlocks::Tolerance, "Returns the tolerance associated with this couple");

// Enums

}