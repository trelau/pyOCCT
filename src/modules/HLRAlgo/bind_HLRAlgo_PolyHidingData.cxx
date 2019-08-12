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
#include <gp_XYZ.hxx>
#include <HLRAlgo_PolyHidingData.hxx>

void bind_HLRAlgo_PolyHidingData(py::module &mod){

py::class_<HLRAlgo_PolyHidingData, std::unique_ptr<HLRAlgo_PolyHidingData, Deleter<HLRAlgo_PolyHidingData>>> cls_HLRAlgo_PolyHidingData(mod, "HLRAlgo_PolyHidingData", "Data structure of a set of Hiding Triangles.");

// Constructors
cls_HLRAlgo_PolyHidingData.def(py::init<>());

// Fields

// Methods
// cls_HLRAlgo_PolyHidingData.def_static("operator new_", (void * (*)(size_t)) &HLRAlgo_PolyHidingData::operator new, "None", py::arg("theSize"));
// cls_HLRAlgo_PolyHidingData.def_static("operator delete_", (void (*)(void *)) &HLRAlgo_PolyHidingData::operator delete, "None", py::arg("theAddress"));
// cls_HLRAlgo_PolyHidingData.def_static("operator new[]_", (void * (*)(size_t)) &HLRAlgo_PolyHidingData::operator new[], "None", py::arg("theSize"));
// cls_HLRAlgo_PolyHidingData.def_static("operator delete[]_", (void (*)(void *)) &HLRAlgo_PolyHidingData::operator delete[], "None", py::arg("theAddress"));
// cls_HLRAlgo_PolyHidingData.def_static("operator new_", (void * (*)(size_t, void *)) &HLRAlgo_PolyHidingData::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRAlgo_PolyHidingData.def_static("operator delete_", (void (*)(void *, void *)) &HLRAlgo_PolyHidingData::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRAlgo_PolyHidingData.def("Set", (void (HLRAlgo_PolyHidingData::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &HLRAlgo_PolyHidingData::Set, "None", py::arg("Index"), py::arg("Minim"), py::arg("Maxim"), py::arg("A"), py::arg("B"), py::arg("C"), py::arg("D"));
cls_HLRAlgo_PolyHidingData.def("Indices", (HLRAlgo_PolyHidingData::TriangleIndices & (HLRAlgo_PolyHidingData::*)()) &HLRAlgo_PolyHidingData::Indices, "None");
cls_HLRAlgo_PolyHidingData.def("Plane", (HLRAlgo_PolyHidingData::PlaneT & (HLRAlgo_PolyHidingData::*)()) &HLRAlgo_PolyHidingData::Plane, "None");

// Enums

}