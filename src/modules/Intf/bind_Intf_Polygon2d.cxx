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
#include <Bnd_Box2d.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt2d.hxx>
#include <Intf_Polygon2d.hxx>

void bind_Intf_Polygon2d(py::module &mod){

py::class_<Intf_Polygon2d, std::unique_ptr<Intf_Polygon2d>> cls_Intf_Polygon2d(mod, "Intf_Polygon2d", "Describes the necessary polygon information to compute the interferences.");

// Fields

// Methods
// cls_Intf_Polygon2d.def_static("operator new_", (void * (*)(size_t)) &Intf_Polygon2d::operator new, "None", py::arg("theSize"));
// cls_Intf_Polygon2d.def_static("operator delete_", (void (*)(void *)) &Intf_Polygon2d::operator delete, "None", py::arg("theAddress"));
// cls_Intf_Polygon2d.def_static("operator new[]_", (void * (*)(size_t)) &Intf_Polygon2d::operator new[], "None", py::arg("theSize"));
// cls_Intf_Polygon2d.def_static("operator delete[]_", (void (*)(void *)) &Intf_Polygon2d::operator delete[], "None", py::arg("theAddress"));
// cls_Intf_Polygon2d.def_static("operator new_", (void * (*)(size_t, void *)) &Intf_Polygon2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Intf_Polygon2d.def_static("operator delete_", (void (*)(void *, void *)) &Intf_Polygon2d::operator delete, "None", py::arg(""), py::arg(""));
cls_Intf_Polygon2d.def("Bounding", (const Bnd_Box2d & (Intf_Polygon2d::*)() const) &Intf_Polygon2d::Bounding, "Returns the bounding box of the polygon.");
cls_Intf_Polygon2d.def("Closed", (Standard_Boolean (Intf_Polygon2d::*)() const) &Intf_Polygon2d::Closed, "Returns True if the polyline is closed.");
cls_Intf_Polygon2d.def("DeflectionOverEstimation", (Standard_Real (Intf_Polygon2d::*)() const) &Intf_Polygon2d::DeflectionOverEstimation, "Returns the tolerance of the polygon.");
cls_Intf_Polygon2d.def("NbSegments", (Standard_Integer (Intf_Polygon2d::*)() const) &Intf_Polygon2d::NbSegments, "Returns the number of Segments in the polyline.");
cls_Intf_Polygon2d.def("Segment", (void (Intf_Polygon2d::*)(const Standard_Integer, gp_Pnt2d &, gp_Pnt2d &) const) &Intf_Polygon2d::Segment, "Returns the points of the segment <Index> in the Polygon.", py::arg("theIndex"), py::arg("theBegin"), py::arg("theEnd"));

// Enums

}