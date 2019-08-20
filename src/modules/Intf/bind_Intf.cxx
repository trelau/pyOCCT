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
#include <gp_Pnt.hxx>
#include <gp_XYZ.hxx>
#include <Standard_TypeDef.hxx>
#include <Intf_Polygon2d.hxx>
#include <Intf_SectionPoint.hxx>
#include <Intf_SectionLine.hxx>
#include <Intf_TangentZone.hxx>
#include <Intf_Interference.hxx>
#include <Intf_Tool.hxx>
#include <Intf_InterferencePolygon2d.hxx>
#include <Intf.hxx>

void bind_Intf(py::module &mod){

py::class_<Intf, std::unique_ptr<Intf>> cls_Intf(mod, "Intf", "Interference computation between polygons, lines and polyhedra with only triangular facets. These objects are polygonal representations of complex curves and triangulated representations of complex surfaces.");

// Constructors

// Fields

// Methods
// cls_Intf.def_static("operator new_", (void * (*)(size_t)) &Intf::operator new, "None", py::arg("theSize"));
// cls_Intf.def_static("operator delete_", (void (*)(void *)) &Intf::operator delete, "None", py::arg("theAddress"));
// cls_Intf.def_static("operator new[]_", (void * (*)(size_t)) &Intf::operator new[], "None", py::arg("theSize"));
// cls_Intf.def_static("operator delete[]_", (void (*)(void *)) &Intf::operator delete[], "None", py::arg("theAddress"));
// cls_Intf.def_static("operator new_", (void * (*)(size_t, void *)) &Intf::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Intf.def_static("operator delete_", (void (*)(void *, void *)) &Intf::operator delete, "None", py::arg(""), py::arg(""));
cls_Intf.def_static("PlaneEquation_", [](const gp_Pnt & P1, const gp_Pnt & P2, const gp_Pnt & P3, gp_XYZ & NormalVector, Standard_Real & PolarDistance){ Intf::PlaneEquation(P1, P2, P3, NormalVector, PolarDistance); return PolarDistance; }, "Computes the interference between two polygons in 2d. Result : points of intersections and zones of tangence. Computes the interference between a polygon or a straight line and a polyhedron. Points of intersection and zones of tangence. Give the plane equation of the triangle <P1> <P2> <P3>.", py::arg("P1"), py::arg("P2"), py::arg("P3"), py::arg("NormalVector"), py::arg("PolarDistance"));
cls_Intf.def_static("Contain_", (Standard_Boolean (*)(const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &)) &Intf::Contain, "Compute if the triangle <P1> <P2> <P3> contain <ThePnt>.", py::arg("P1"), py::arg("P2"), py::arg("P3"), py::arg("ThePnt"));

// Enums

}