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
#include <Intf_Polygon2d.hxx>
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt2d.hxx>
#include <IntPatch_Polygo.hxx>

void bind_IntPatch_Polygo(py::module &mod){

py::class_<IntPatch_Polygo, Intf_Polygon2d> cls_IntPatch_Polygo(mod, "IntPatch_Polygo", "None");

// Fields

// Methods
// cls_IntPatch_Polygo.def_static("operator new_", (void * (*)(size_t)) &IntPatch_Polygo::operator new, "None", py::arg("theSize"));
// cls_IntPatch_Polygo.def_static("operator delete_", (void (*)(void *)) &IntPatch_Polygo::operator delete, "None", py::arg("theAddress"));
// cls_IntPatch_Polygo.def_static("operator new[]_", (void * (*)(size_t)) &IntPatch_Polygo::operator new[], "None", py::arg("theSize"));
// cls_IntPatch_Polygo.def_static("operator delete[]_", (void (*)(void *)) &IntPatch_Polygo::operator delete[], "None", py::arg("theAddress"));
// cls_IntPatch_Polygo.def_static("operator new_", (void * (*)(size_t, void *)) &IntPatch_Polygo::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntPatch_Polygo.def_static("operator delete_", (void (*)(void *, void *)) &IntPatch_Polygo::operator delete, "None", py::arg(""), py::arg(""));
cls_IntPatch_Polygo.def("Error", (Standard_Real (IntPatch_Polygo::*)() const) &IntPatch_Polygo::Error, "None");
cls_IntPatch_Polygo.def("NbPoints", (Standard_Integer (IntPatch_Polygo::*)() const) &IntPatch_Polygo::NbPoints, "None");
cls_IntPatch_Polygo.def("Point", (gp_Pnt2d (IntPatch_Polygo::*)(const Standard_Integer) const) &IntPatch_Polygo::Point, "None", py::arg("Index"));
cls_IntPatch_Polygo.def("DeflectionOverEstimation", (Standard_Real (IntPatch_Polygo::*)() const) &IntPatch_Polygo::DeflectionOverEstimation, "Returns the tolerance of the polygon.");
cls_IntPatch_Polygo.def("NbSegments", (Standard_Integer (IntPatch_Polygo::*)() const) &IntPatch_Polygo::NbSegments, "Returns the number of Segments in the polyline.");
cls_IntPatch_Polygo.def("Segment", (void (IntPatch_Polygo::*)(const Standard_Integer, gp_Pnt2d &, gp_Pnt2d &) const) &IntPatch_Polygo::Segment, "Returns the points of the segment <Index> in the Polygon.", py::arg("theIndex"), py::arg("theBegin"), py::arg("theEnd"));
cls_IntPatch_Polygo.def("Dump", (void (IntPatch_Polygo::*)() const) &IntPatch_Polygo::Dump, "None");

// Enums

}