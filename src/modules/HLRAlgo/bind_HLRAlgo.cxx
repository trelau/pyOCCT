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
#include <Standard_TypeDef.hxx>
#include <HLRAlgo_EdgesBlock.hxx>
#include <HLRAlgo.hxx>

void bind_HLRAlgo(py::module &mod){

py::class_<HLRAlgo, std::unique_ptr<HLRAlgo>> cls_HLRAlgo(mod, "HLRAlgo", "In order to have the precision required in industrial design, drawings need to offer the possibility of removing lines, which are hidden in a given projection. To do this, the Hidden Line Removal component provides two algorithms: HLRBRep_Algo and HLRBRep_PolyAlgo. These algorithms remove or indicate lines hidden by surfaces. For a given projection, they calculate a set of lines characteristic of the object being represented. They are also used in conjunction with extraction utilities, which reconstruct a new, simplified shape from a selection of calculation results. This new shape is made up of edges, which represent the lines of the visualized shape in a plane. This plane is the projection plane. HLRBRep_Algo takes into account the shape itself. HLRBRep_PolyAlgo works with a polyhedral simplification of the shape. When you use HLRBRep_Algo, you obtain an exact result, whereas, when you use HLRBRep_PolyAlgo, you reduce computation time but obtain polygonal segments.");

// Constructors

// Fields

// Methods
// cls_HLRAlgo.def_static("operator new_", (void * (*)(size_t)) &HLRAlgo::operator new, "None", py::arg("theSize"));
// cls_HLRAlgo.def_static("operator delete_", (void (*)(void *)) &HLRAlgo::operator delete, "None", py::arg("theAddress"));
// cls_HLRAlgo.def_static("operator new[]_", (void * (*)(size_t)) &HLRAlgo::operator new[], "None", py::arg("theSize"));
// cls_HLRAlgo.def_static("operator delete[]_", (void (*)(void *)) &HLRAlgo::operator delete[], "None", py::arg("theAddress"));
// cls_HLRAlgo.def_static("operator new_", (void * (*)(size_t, void *)) &HLRAlgo::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRAlgo.def_static("operator delete_", (void (*)(void *, void *)) &HLRAlgo::operator delete, "None", py::arg(""), py::arg(""));
// cls_HLRAlgo.def_static("UpdateMinMax_", (void (*)(const Standard_Real, const Standard_Real, const Standard_Real, Standard_Real [16], Standard_Real [16])) &HLRAlgo::UpdateMinMax, "Iterator on the visible or hidden parts of an EdgeStatus.", py::arg("x"), py::arg("y"), py::arg("z"), py::arg("Min"), py::arg("Max"));
// cls_HLRAlgo.def_static("EnlargeMinMax_", (void (*)(const Standard_Real, Standard_Real [16], Standard_Real [16])) &HLRAlgo::EnlargeMinMax, "None", py::arg("tol"), py::arg("Min"), py::arg("Max"));
// cls_HLRAlgo.def_static("InitMinMax_", (void (*)(const Standard_Real, Standard_Real [16], Standard_Real [16])) &HLRAlgo::InitMinMax, "None", py::arg("Big"), py::arg("Min"), py::arg("Max"));
cls_HLRAlgo.def_static("EncodeMinMax_", (void (*)(HLRAlgo_EdgesBlock::MinMaxIndices &, HLRAlgo_EdgesBlock::MinMaxIndices &, HLRAlgo_EdgesBlock::MinMaxIndices &)) &HLRAlgo::EncodeMinMax, "None", py::arg("Min"), py::arg("Max"), py::arg("MinMax"));
cls_HLRAlgo.def_static("SizeBox_", (Standard_Real (*)(HLRAlgo_EdgesBlock::MinMaxIndices &, HLRAlgo_EdgesBlock::MinMaxIndices &)) &HLRAlgo::SizeBox, "None", py::arg("Min"), py::arg("Max"));
cls_HLRAlgo.def_static("DecodeMinMax_", (void (*)(const HLRAlgo_EdgesBlock::MinMaxIndices &, HLRAlgo_EdgesBlock::MinMaxIndices &, HLRAlgo_EdgesBlock::MinMaxIndices &)) &HLRAlgo::DecodeMinMax, "None", py::arg("MinMax"), py::arg("Min"), py::arg("Max"));
cls_HLRAlgo.def_static("CopyMinMax_", (void (*)(HLRAlgo_EdgesBlock::MinMaxIndices &, HLRAlgo_EdgesBlock::MinMaxIndices &, HLRAlgo_EdgesBlock::MinMaxIndices &, HLRAlgo_EdgesBlock::MinMaxIndices &)) &HLRAlgo::CopyMinMax, "None", py::arg("IMin"), py::arg("IMax"), py::arg("OMin"), py::arg("OMax"));
cls_HLRAlgo.def_static("AddMinMax_", (void (*)(HLRAlgo_EdgesBlock::MinMaxIndices &, HLRAlgo_EdgesBlock::MinMaxIndices &, HLRAlgo_EdgesBlock::MinMaxIndices &, HLRAlgo_EdgesBlock::MinMaxIndices &)) &HLRAlgo::AddMinMax, "None", py::arg("IMin"), py::arg("IMax"), py::arg("OMin"), py::arg("OMax"));

// Enums

}