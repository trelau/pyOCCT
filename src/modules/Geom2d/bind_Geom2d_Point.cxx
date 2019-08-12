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
#include <Geom2d_Geometry.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt2d.hxx>
#include <Standard_Handle.hxx>
#include <Geom2d_Point.hxx>
#include <Standard_Type.hxx>

void bind_Geom2d_Point(py::module &mod){

py::class_<Geom2d_Point, opencascade::handle<Geom2d_Point>, Geom2d_Geometry> cls_Geom2d_Point(mod, "Geom2d_Point", "The abstract class Point describes the common behavior of geometric points in 2D space. The Geom2d package also provides the concrete class Geom2d_CartesianPoint.");

// Fields

// Methods
cls_Geom2d_Point.def("Coord", [](Geom2d_Point &self, Standard_Real & X, Standard_Real & Y){ self.Coord(X, Y); return std::tuple<Standard_Real &, Standard_Real &>(X, Y); }, "returns the Coordinates of <me>.", py::arg("X"), py::arg("Y"));
cls_Geom2d_Point.def("Pnt2d", (gp_Pnt2d (Geom2d_Point::*)() const) &Geom2d_Point::Pnt2d, "returns a non persistent copy of <me>");
cls_Geom2d_Point.def("X", (Standard_Real (Geom2d_Point::*)() const) &Geom2d_Point::X, "returns the X coordinate of <me>.");
cls_Geom2d_Point.def("Y", (Standard_Real (Geom2d_Point::*)() const) &Geom2d_Point::Y, "returns the Y coordinate of <me>.");
cls_Geom2d_Point.def("Distance", (Standard_Real (Geom2d_Point::*)(const opencascade::handle<Geom2d_Point> &) const) &Geom2d_Point::Distance, "computes the distance between <me> and <Other>.", py::arg("Other"));
cls_Geom2d_Point.def("SquareDistance", (Standard_Real (Geom2d_Point::*)(const opencascade::handle<Geom2d_Point> &) const) &Geom2d_Point::SquareDistance, "computes the square distance between <me> and <Other>.", py::arg("Other"));
cls_Geom2d_Point.def_static("get_type_name_", (const char * (*)()) &Geom2d_Point::get_type_name, "None");
cls_Geom2d_Point.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Geom2d_Point::get_type_descriptor, "None");
cls_Geom2d_Point.def("DynamicType", (const opencascade::handle<Standard_Type> & (Geom2d_Point::*)() const) &Geom2d_Point::DynamicType, "None");

// Enums

}