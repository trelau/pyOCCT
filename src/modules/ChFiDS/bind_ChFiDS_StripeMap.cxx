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
#include <TopoDS_Vertex.hxx>
#include <Standard_Handle.hxx>
#include <ChFiDS_Stripe.hxx>
#include <Standard_TypeDef.hxx>
#include <ChFiDS_ListOfStripe.hxx>
#include <ChFiDS_IndexedDataMapOfVertexListOfStripe.hxx>
#include <ChFiDS_StripeMap.hxx>

void bind_ChFiDS_StripeMap(py::module &mod){

py::class_<ChFiDS_StripeMap, std::unique_ptr<ChFiDS_StripeMap, Deleter<ChFiDS_StripeMap>>> cls_ChFiDS_StripeMap(mod, "ChFiDS_StripeMap", "encapsulation of IndexedDataMapOfVertexListOfStripe");

// Constructors
cls_ChFiDS_StripeMap.def(py::init<>());

// Fields

// Methods
// cls_ChFiDS_StripeMap.def_static("operator new_", (void * (*)(size_t)) &ChFiDS_StripeMap::operator new, "None", py::arg("theSize"));
// cls_ChFiDS_StripeMap.def_static("operator delete_", (void (*)(void *)) &ChFiDS_StripeMap::operator delete, "None", py::arg("theAddress"));
// cls_ChFiDS_StripeMap.def_static("operator new[]_", (void * (*)(size_t)) &ChFiDS_StripeMap::operator new[], "None", py::arg("theSize"));
// cls_ChFiDS_StripeMap.def_static("operator delete[]_", (void (*)(void *)) &ChFiDS_StripeMap::operator delete[], "None", py::arg("theAddress"));
// cls_ChFiDS_StripeMap.def_static("operator new_", (void * (*)(size_t, void *)) &ChFiDS_StripeMap::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_ChFiDS_StripeMap.def_static("operator delete_", (void (*)(void *, void *)) &ChFiDS_StripeMap::operator delete, "None", py::arg(""), py::arg(""));
cls_ChFiDS_StripeMap.def("Add", (void (ChFiDS_StripeMap::*)(const TopoDS_Vertex &, const opencascade::handle<ChFiDS_Stripe> &)) &ChFiDS_StripeMap::Add, "None", py::arg("V"), py::arg("F"));
cls_ChFiDS_StripeMap.def("Extent", (Standard_Integer (ChFiDS_StripeMap::*)() const) &ChFiDS_StripeMap::Extent, "None");
cls_ChFiDS_StripeMap.def("FindFromKey", (const ChFiDS_ListOfStripe & (ChFiDS_StripeMap::*)(const TopoDS_Vertex &) const) &ChFiDS_StripeMap::FindFromKey, "None", py::arg("V"));
cls_ChFiDS_StripeMap.def("__call__", (const ChFiDS_ListOfStripe & (ChFiDS_StripeMap::*)(const TopoDS_Vertex &) const) &ChFiDS_StripeMap::operator(), py::is_operator(), "None", py::arg("V"));
cls_ChFiDS_StripeMap.def("FindFromIndex", (const ChFiDS_ListOfStripe & (ChFiDS_StripeMap::*)(const Standard_Integer) const) &ChFiDS_StripeMap::FindFromIndex, "None", py::arg("I"));
cls_ChFiDS_StripeMap.def("__call__", (const ChFiDS_ListOfStripe & (ChFiDS_StripeMap::*)(const Standard_Integer) const) &ChFiDS_StripeMap::operator(), py::is_operator(), "None", py::arg("I"));
cls_ChFiDS_StripeMap.def("FindKey", (const TopoDS_Vertex & (ChFiDS_StripeMap::*)(const Standard_Integer) const) &ChFiDS_StripeMap::FindKey, "None", py::arg("I"));
cls_ChFiDS_StripeMap.def("Clear", (void (ChFiDS_StripeMap::*)()) &ChFiDS_StripeMap::Clear, "None");

// Enums

}