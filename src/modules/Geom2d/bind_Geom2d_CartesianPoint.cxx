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
#include <Geom2d_Point.hxx>
#include <gp_Pnt2d.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Trsf2d.hxx>
#include <Standard_Handle.hxx>
#include <Geom2d_Geometry.hxx>
#include <Geom2d_CartesianPoint.hxx>
#include <Standard_Type.hxx>

void bind_Geom2d_CartesianPoint(py::module &mod){

py::class_<Geom2d_CartesianPoint, opencascade::handle<Geom2d_CartesianPoint>, Geom2d_Point> cls_Geom2d_CartesianPoint(mod, "Geom2d_CartesianPoint", "Describes a point in 2D space. A Geom2d_CartesianPoint is defined by a gp_Pnt2d point, with its two Cartesian coordinates X and Y.");

// Constructors
cls_Geom2d_CartesianPoint.def(py::init<const gp_Pnt2d &>(), py::arg("P"));
cls_Geom2d_CartesianPoint.def(py::init<const Standard_Real, const Standard_Real>(), py::arg("X"), py::arg("Y"));

// Fields

// Methods
cls_Geom2d_CartesianPoint.def("SetCoord", (void (Geom2d_CartesianPoint::*)(const Standard_Real, const Standard_Real)) &Geom2d_CartesianPoint::SetCoord, "Set <me> to X, Y coordinates.", py::arg("X"), py::arg("Y"));
cls_Geom2d_CartesianPoint.def("SetPnt2d", (void (Geom2d_CartesianPoint::*)(const gp_Pnt2d &)) &Geom2d_CartesianPoint::SetPnt2d, "Set <me> to P.X(), P.Y() coordinates.", py::arg("P"));
cls_Geom2d_CartesianPoint.def("SetX", (void (Geom2d_CartesianPoint::*)(const Standard_Real)) &Geom2d_CartesianPoint::SetX, "Changes the X coordinate of me.", py::arg("X"));
cls_Geom2d_CartesianPoint.def("SetY", (void (Geom2d_CartesianPoint::*)(const Standard_Real)) &Geom2d_CartesianPoint::SetY, "Changes the Y coordinate of me.", py::arg("Y"));
cls_Geom2d_CartesianPoint.def("Coord", [](Geom2d_CartesianPoint &self, Standard_Real & X, Standard_Real & Y){ self.Coord(X, Y); return std::tuple<Standard_Real &, Standard_Real &>(X, Y); }, "Returns the coordinates of <me>.", py::arg("X"), py::arg("Y"));
cls_Geom2d_CartesianPoint.def("Pnt2d", (gp_Pnt2d (Geom2d_CartesianPoint::*)() const) &Geom2d_CartesianPoint::Pnt2d, "Returns a non persistent cartesian point with the same coordinates as <me>. -C++: return const&");
cls_Geom2d_CartesianPoint.def("X", (Standard_Real (Geom2d_CartesianPoint::*)() const) &Geom2d_CartesianPoint::X, "Returns the X coordinate of <me>.");
cls_Geom2d_CartesianPoint.def("Y", (Standard_Real (Geom2d_CartesianPoint::*)() const) &Geom2d_CartesianPoint::Y, "Returns the Y coordinate of <me>.");
cls_Geom2d_CartesianPoint.def("Transform", (void (Geom2d_CartesianPoint::*)(const gp_Trsf2d &)) &Geom2d_CartesianPoint::Transform, "None", py::arg("T"));
cls_Geom2d_CartesianPoint.def("Copy", (opencascade::handle<Geom2d_Geometry> (Geom2d_CartesianPoint::*)() const) &Geom2d_CartesianPoint::Copy, "None");
cls_Geom2d_CartesianPoint.def_static("get_type_name_", (const char * (*)()) &Geom2d_CartesianPoint::get_type_name, "None");
cls_Geom2d_CartesianPoint.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Geom2d_CartesianPoint::get_type_descriptor, "None");
cls_Geom2d_CartesianPoint.def("DynamicType", (const opencascade::handle<Standard_Type> & (Geom2d_CartesianPoint::*)() const) &Geom2d_CartesianPoint::DynamicType, "None");

// Enums

}