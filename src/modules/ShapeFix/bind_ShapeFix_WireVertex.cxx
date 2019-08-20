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
#include <TopoDS_Wire.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <ShapeExtend_WireData.hxx>
#include <ShapeAnalysis_WireVertex.hxx>
#include <ShapeFix_WireVertex.hxx>

void bind_ShapeFix_WireVertex(py::module &mod){

py::class_<ShapeFix_WireVertex, std::unique_ptr<ShapeFix_WireVertex>> cls_ShapeFix_WireVertex(mod, "ShapeFix_WireVertex", "Fixing disconnected edges in the wire Fixes vertices in the wire on the basis of pre-analysis made by ShapeAnalysis_WireVertex (given as argument). The Wire has formerly been loaded in a ShapeExtend_WireData.");

// Constructors
cls_ShapeFix_WireVertex.def(py::init<>());

// Fields

// Methods
// cls_ShapeFix_WireVertex.def_static("operator new_", (void * (*)(size_t)) &ShapeFix_WireVertex::operator new, "None", py::arg("theSize"));
// cls_ShapeFix_WireVertex.def_static("operator delete_", (void (*)(void *)) &ShapeFix_WireVertex::operator delete, "None", py::arg("theAddress"));
// cls_ShapeFix_WireVertex.def_static("operator new[]_", (void * (*)(size_t)) &ShapeFix_WireVertex::operator new[], "None", py::arg("theSize"));
// cls_ShapeFix_WireVertex.def_static("operator delete[]_", (void (*)(void *)) &ShapeFix_WireVertex::operator delete[], "None", py::arg("theAddress"));
// cls_ShapeFix_WireVertex.def_static("operator new_", (void * (*)(size_t, void *)) &ShapeFix_WireVertex::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_ShapeFix_WireVertex.def_static("operator delete_", (void (*)(void *, void *)) &ShapeFix_WireVertex::operator delete, "None", py::arg(""), py::arg(""));
cls_ShapeFix_WireVertex.def("Init", (void (ShapeFix_WireVertex::*)(const TopoDS_Wire &, const Standard_Real)) &ShapeFix_WireVertex::Init, "Loads the wire, ininializes internal analyzer (ShapeAnalysis_WireVertex) with the given precision, and performs analysis", py::arg("wire"), py::arg("preci"));
cls_ShapeFix_WireVertex.def("Init", (void (ShapeFix_WireVertex::*)(const opencascade::handle<ShapeExtend_WireData> &, const Standard_Real)) &ShapeFix_WireVertex::Init, "Loads the wire, ininializes internal analyzer (ShapeAnalysis_WireVertex) with the given precision, and performs analysis", py::arg("sbwd"), py::arg("preci"));
cls_ShapeFix_WireVertex.def("Init", (void (ShapeFix_WireVertex::*)(const ShapeAnalysis_WireVertex &)) &ShapeFix_WireVertex::Init, "Loads all the data on wire, already analysed by ShapeAnalysis_WireVertex", py::arg("sawv"));
cls_ShapeFix_WireVertex.def("Analyzer", (const ShapeAnalysis_WireVertex & (ShapeFix_WireVertex::*)() const) &ShapeFix_WireVertex::Analyzer, "returns internal analyzer");
cls_ShapeFix_WireVertex.def("WireData", (const opencascade::handle<ShapeExtend_WireData> & (ShapeFix_WireVertex::*)() const) &ShapeFix_WireVertex::WireData, "returns data on wire (fixed)");
cls_ShapeFix_WireVertex.def("Wire", (TopoDS_Wire (ShapeFix_WireVertex::*)() const) &ShapeFix_WireVertex::Wire, "returns resulting wire (fixed)");
cls_ShapeFix_WireVertex.def("FixSame", (Standard_Integer (ShapeFix_WireVertex::*)()) &ShapeFix_WireVertex::FixSame, "Fixes 'Same' or 'Close' status (same vertex may be set, without changing parameters) Returns the count of fixed vertices, 0 if none");
cls_ShapeFix_WireVertex.def("Fix", (Standard_Integer (ShapeFix_WireVertex::*)()) &ShapeFix_WireVertex::Fix, "Fixes all statuses except 'Disjoined', i.e. the cases in which a common value has been set, with or without changing parameters Returns the count of fixed vertices, 0 if none");

// Enums

}