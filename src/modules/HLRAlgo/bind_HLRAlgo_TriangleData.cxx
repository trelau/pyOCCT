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
#include <HLRAlgo_TriangleData.hxx>

void bind_HLRAlgo_TriangleData(py::module &mod){

py::class_<HLRAlgo_TriangleData, std::unique_ptr<HLRAlgo_TriangleData>> cls_HLRAlgo_TriangleData(mod, "HLRAlgo_TriangleData", "Data structure of a triangle.");

// Constructors

// Fields
cls_HLRAlgo_TriangleData.def_readwrite("Node1", &HLRAlgo_TriangleData::Node1, "None");
cls_HLRAlgo_TriangleData.def_readwrite("Node2", &HLRAlgo_TriangleData::Node2, "None");
cls_HLRAlgo_TriangleData.def_readwrite("Node3", &HLRAlgo_TriangleData::Node3, "None");
cls_HLRAlgo_TriangleData.def_readwrite("Flags", &HLRAlgo_TriangleData::Flags, "None");

// Methods
// cls_HLRAlgo_TriangleData.def_static("operator new_", (void * (*)(size_t)) &HLRAlgo_TriangleData::operator new, "None", py::arg("theSize"));
// cls_HLRAlgo_TriangleData.def_static("operator delete_", (void (*)(void *)) &HLRAlgo_TriangleData::operator delete, "None", py::arg("theAddress"));
// cls_HLRAlgo_TriangleData.def_static("operator new[]_", (void * (*)(size_t)) &HLRAlgo_TriangleData::operator new[], "None", py::arg("theSize"));
// cls_HLRAlgo_TriangleData.def_static("operator delete[]_", (void (*)(void *)) &HLRAlgo_TriangleData::operator delete[], "None", py::arg("theAddress"));
// cls_HLRAlgo_TriangleData.def_static("operator new_", (void * (*)(size_t, void *)) &HLRAlgo_TriangleData::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRAlgo_TriangleData.def_static("operator delete_", (void (*)(void *, void *)) &HLRAlgo_TriangleData::operator delete, "None", py::arg(""), py::arg(""));

// Enums

}