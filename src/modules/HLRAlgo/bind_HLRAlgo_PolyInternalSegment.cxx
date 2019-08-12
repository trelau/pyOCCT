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
#include <HLRAlgo_PolyInternalSegment.hxx>

void bind_HLRAlgo_PolyInternalSegment(py::module &mod){

py::class_<HLRAlgo_PolyInternalSegment, std::unique_ptr<HLRAlgo_PolyInternalSegment, Deleter<HLRAlgo_PolyInternalSegment>>> cls_HLRAlgo_PolyInternalSegment(mod, "HLRAlgo_PolyInternalSegment", "to Update OutLines.");

// Constructors

// Fields
cls_HLRAlgo_PolyInternalSegment.def_readwrite("LstSg1", &HLRAlgo_PolyInternalSegment::LstSg1, "None");
cls_HLRAlgo_PolyInternalSegment.def_readwrite("LstSg2", &HLRAlgo_PolyInternalSegment::LstSg2, "None");
cls_HLRAlgo_PolyInternalSegment.def_readwrite("NxtSg1", &HLRAlgo_PolyInternalSegment::NxtSg1, "None");
cls_HLRAlgo_PolyInternalSegment.def_readwrite("NxtSg2", &HLRAlgo_PolyInternalSegment::NxtSg2, "None");
cls_HLRAlgo_PolyInternalSegment.def_readwrite("Conex1", &HLRAlgo_PolyInternalSegment::Conex1, "None");
cls_HLRAlgo_PolyInternalSegment.def_readwrite("Conex2", &HLRAlgo_PolyInternalSegment::Conex2, "None");

// Methods
// cls_HLRAlgo_PolyInternalSegment.def_static("operator new_", (void * (*)(size_t)) &HLRAlgo_PolyInternalSegment::operator new, "None", py::arg("theSize"));
// cls_HLRAlgo_PolyInternalSegment.def_static("operator delete_", (void (*)(void *)) &HLRAlgo_PolyInternalSegment::operator delete, "None", py::arg("theAddress"));
// cls_HLRAlgo_PolyInternalSegment.def_static("operator new[]_", (void * (*)(size_t)) &HLRAlgo_PolyInternalSegment::operator new[], "None", py::arg("theSize"));
// cls_HLRAlgo_PolyInternalSegment.def_static("operator delete[]_", (void (*)(void *)) &HLRAlgo_PolyInternalSegment::operator delete[], "None", py::arg("theAddress"));
// cls_HLRAlgo_PolyInternalSegment.def_static("operator new_", (void * (*)(size_t, void *)) &HLRAlgo_PolyInternalSegment::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRAlgo_PolyInternalSegment.def_static("operator delete_", (void (*)(void *, void *)) &HLRAlgo_PolyInternalSegment::operator delete, "None", py::arg(""), py::arg(""));

// Enums

}