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
#include <HLRAlgo_EdgesBlock.hxx>
#include <TopAbs_Orientation.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Type.hxx>
#include <TColStd_Array1OfInteger.hxx>

void bind_HLRAlgo_EdgesBlock(py::module &mod){

py::class_<HLRAlgo_EdgesBlock, opencascade::handle<HLRAlgo_EdgesBlock>, Standard_Transient> cls_HLRAlgo_EdgesBlock(mod, "HLRAlgo_EdgesBlock", "An EdgesBlock is a set of Edges. It is used by the DataStructure to structure the Edges.");

// Constructors
cls_HLRAlgo_EdgesBlock.def(py::init<const Standard_Integer>(), py::arg("NbEdges"));

// Fields

// Methods
cls_HLRAlgo_EdgesBlock.def("NbEdges", (Standard_Integer (HLRAlgo_EdgesBlock::*)() const) &HLRAlgo_EdgesBlock::NbEdges, "None");
cls_HLRAlgo_EdgesBlock.def("Edge", (void (HLRAlgo_EdgesBlock::*)(const Standard_Integer, const Standard_Integer)) &HLRAlgo_EdgesBlock::Edge, "None", py::arg("I"), py::arg("EI"));
cls_HLRAlgo_EdgesBlock.def("Edge", (Standard_Integer (HLRAlgo_EdgesBlock::*)(const Standard_Integer) const) &HLRAlgo_EdgesBlock::Edge, "None", py::arg("I"));
cls_HLRAlgo_EdgesBlock.def("Orientation", (void (HLRAlgo_EdgesBlock::*)(const Standard_Integer, const TopAbs_Orientation)) &HLRAlgo_EdgesBlock::Orientation, "None", py::arg("I"), py::arg("Or"));
cls_HLRAlgo_EdgesBlock.def("Orientation", (TopAbs_Orientation (HLRAlgo_EdgesBlock::*)(const Standard_Integer) const) &HLRAlgo_EdgesBlock::Orientation, "None", py::arg("I"));
cls_HLRAlgo_EdgesBlock.def("OutLine", (Standard_Boolean (HLRAlgo_EdgesBlock::*)(const Standard_Integer) const) &HLRAlgo_EdgesBlock::OutLine, "None", py::arg("I"));
cls_HLRAlgo_EdgesBlock.def("OutLine", (void (HLRAlgo_EdgesBlock::*)(const Standard_Integer, const Standard_Boolean)) &HLRAlgo_EdgesBlock::OutLine, "None", py::arg("I"), py::arg("B"));
cls_HLRAlgo_EdgesBlock.def("Internal", (Standard_Boolean (HLRAlgo_EdgesBlock::*)(const Standard_Integer) const) &HLRAlgo_EdgesBlock::Internal, "None", py::arg("I"));
cls_HLRAlgo_EdgesBlock.def("Internal", (void (HLRAlgo_EdgesBlock::*)(const Standard_Integer, const Standard_Boolean)) &HLRAlgo_EdgesBlock::Internal, "None", py::arg("I"), py::arg("B"));
cls_HLRAlgo_EdgesBlock.def("Double", (Standard_Boolean (HLRAlgo_EdgesBlock::*)(const Standard_Integer) const) &HLRAlgo_EdgesBlock::Double, "None", py::arg("I"));
cls_HLRAlgo_EdgesBlock.def("Double", (void (HLRAlgo_EdgesBlock::*)(const Standard_Integer, const Standard_Boolean)) &HLRAlgo_EdgesBlock::Double, "None", py::arg("I"), py::arg("B"));
cls_HLRAlgo_EdgesBlock.def("IsoLine", (Standard_Boolean (HLRAlgo_EdgesBlock::*)(const Standard_Integer) const) &HLRAlgo_EdgesBlock::IsoLine, "None", py::arg("I"));
cls_HLRAlgo_EdgesBlock.def("IsoLine", (void (HLRAlgo_EdgesBlock::*)(const Standard_Integer, const Standard_Boolean)) &HLRAlgo_EdgesBlock::IsoLine, "None", py::arg("I"), py::arg("B"));
cls_HLRAlgo_EdgesBlock.def("UpdateMinMax", (void (HLRAlgo_EdgesBlock::*)(const HLRAlgo_EdgesBlock::MinMaxIndices &)) &HLRAlgo_EdgesBlock::UpdateMinMax, "None", py::arg("TotMinMax"));
cls_HLRAlgo_EdgesBlock.def("MinMax", (HLRAlgo_EdgesBlock::MinMaxIndices & (HLRAlgo_EdgesBlock::*)()) &HLRAlgo_EdgesBlock::MinMax, "None");
cls_HLRAlgo_EdgesBlock.def_static("get_type_name_", (const char * (*)()) &HLRAlgo_EdgesBlock::get_type_name, "None");
cls_HLRAlgo_EdgesBlock.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &HLRAlgo_EdgesBlock::get_type_descriptor, "None");
cls_HLRAlgo_EdgesBlock.def("DynamicType", (const opencascade::handle<Standard_Type> & (HLRAlgo_EdgesBlock::*)() const) &HLRAlgo_EdgesBlock::DynamicType, "None");

// Enums

}