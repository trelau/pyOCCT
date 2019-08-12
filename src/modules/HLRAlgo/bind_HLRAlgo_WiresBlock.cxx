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
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <HLRAlgo_EdgesBlock.hxx>
#include <HLRAlgo_WiresBlock.hxx>
#include <Standard_Type.hxx>
#include <TColStd_Array1OfTransient.hxx>

void bind_HLRAlgo_WiresBlock(py::module &mod){

py::class_<HLRAlgo_WiresBlock, opencascade::handle<HLRAlgo_WiresBlock>, Standard_Transient> cls_HLRAlgo_WiresBlock(mod, "HLRAlgo_WiresBlock", "A WiresBlock is a set of Blocks. It is used by the DataStructure to structure the Edges.");

// Constructors
cls_HLRAlgo_WiresBlock.def(py::init<const Standard_Integer>(), py::arg("NbWires"));

// Fields

// Methods
cls_HLRAlgo_WiresBlock.def("NbWires", (Standard_Integer (HLRAlgo_WiresBlock::*)() const) &HLRAlgo_WiresBlock::NbWires, "None");
cls_HLRAlgo_WiresBlock.def("Set", (void (HLRAlgo_WiresBlock::*)(const Standard_Integer, const opencascade::handle<HLRAlgo_EdgesBlock> &)) &HLRAlgo_WiresBlock::Set, "None", py::arg("I"), py::arg("W"));
cls_HLRAlgo_WiresBlock.def("Wire", (opencascade::handle<HLRAlgo_EdgesBlock> & (HLRAlgo_WiresBlock::*)(const Standard_Integer)) &HLRAlgo_WiresBlock::Wire, "None", py::arg("I"));
cls_HLRAlgo_WiresBlock.def("UpdateMinMax", (void (HLRAlgo_WiresBlock::*)(const HLRAlgo_EdgesBlock::MinMaxIndices &)) &HLRAlgo_WiresBlock::UpdateMinMax, "None", py::arg("theMinMaxes"));
cls_HLRAlgo_WiresBlock.def("MinMax", (HLRAlgo_EdgesBlock::MinMaxIndices & (HLRAlgo_WiresBlock::*)()) &HLRAlgo_WiresBlock::MinMax, "None");
cls_HLRAlgo_WiresBlock.def_static("get_type_name_", (const char * (*)()) &HLRAlgo_WiresBlock::get_type_name, "None");
cls_HLRAlgo_WiresBlock.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &HLRAlgo_WiresBlock::get_type_descriptor, "None");
cls_HLRAlgo_WiresBlock.def("DynamicType", (const opencascade::handle<Standard_Type> & (HLRAlgo_WiresBlock::*)() const) &HLRAlgo_WiresBlock::DynamicType, "None");

// Enums

}