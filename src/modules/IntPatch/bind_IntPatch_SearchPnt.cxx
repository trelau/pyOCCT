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
#include <Intf_InterferencePolygon2d.hxx>
#include <IntPatch_SearchPnt.hxx>

void bind_IntPatch_SearchPnt(py::module &mod){

py::class_<Intf_InterferencePolygon2d, std::unique_ptr<Intf_InterferencePolygon2d>, Intf_Interference> cls_IntPatch_SearchPnt(mod, "IntPatch_SearchPnt", "Computes the interference between two polygons or the self intersection of a polygon in two dimensions.", py::module_local());

// Constructors
cls_IntPatch_SearchPnt.def(py::init<>());
cls_IntPatch_SearchPnt.def(py::init<const Intf_Polygon2d &, const Intf_Polygon2d &>(), py::arg("Obje1"), py::arg("Obje2"));
cls_IntPatch_SearchPnt.def(py::init<const Intf_Polygon2d &>(), py::arg("Obje"));

// Fields

// Methods
// cls_IntPatch_SearchPnt.def_static("operator new_", (void * (*)(size_t)) &Intf_InterferencePolygon2d::operator new, "None", py::arg("theSize"));
// cls_IntPatch_SearchPnt.def_static("operator delete_", (void (*)(void *)) &Intf_InterferencePolygon2d::operator delete, "None", py::arg("theAddress"));
// cls_IntPatch_SearchPnt.def_static("operator new[]_", (void * (*)(size_t)) &Intf_InterferencePolygon2d::operator new[], "None", py::arg("theSize"));
// cls_IntPatch_SearchPnt.def_static("operator delete[]_", (void (*)(void *)) &Intf_InterferencePolygon2d::operator delete[], "None", py::arg("theAddress"));
// cls_IntPatch_SearchPnt.def_static("operator new_", (void * (*)(size_t, void *)) &Intf_InterferencePolygon2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntPatch_SearchPnt.def_static("operator delete_", (void (*)(void *, void *)) &Intf_InterferencePolygon2d::operator delete, "None", py::arg(""), py::arg(""));
cls_IntPatch_SearchPnt.def("Perform", (void (Intf_InterferencePolygon2d::*)(const Intf_Polygon2d &, const Intf_Polygon2d &)) &Intf_InterferencePolygon2d::Perform, "Computes an interference between two Polygons.", py::arg("Obje1"), py::arg("Obje2"));
cls_IntPatch_SearchPnt.def("Perform", (void (Intf_InterferencePolygon2d::*)(const Intf_Polygon2d &)) &Intf_InterferencePolygon2d::Perform, "Computes the self interference of a Polygon.", py::arg("Obje"));
cls_IntPatch_SearchPnt.def("Pnt2dValue", (gp_Pnt2d (Intf_InterferencePolygon2d::*)(const Standard_Integer) const) &Intf_InterferencePolygon2d::Pnt2dValue, "Gives the geometrical 2d point of the intersection point at address <Index> in the interference.", py::arg("Index"));

// Enums

}