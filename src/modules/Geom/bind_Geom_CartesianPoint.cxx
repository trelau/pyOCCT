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
#include <Geom_Point.hxx>
#include <gp_Pnt.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Trsf.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Geometry.hxx>
#include <Geom_CartesianPoint.hxx>
#include <Standard_Type.hxx>

void bind_Geom_CartesianPoint(py::module &mod){

py::class_<Geom_CartesianPoint, opencascade::handle<Geom_CartesianPoint>, Geom_Point> cls_Geom_CartesianPoint(mod, "Geom_CartesianPoint", "Describes a point in 3D space. A Geom_CartesianPoint is defined by a gp_Pnt point, with its three Cartesian coordinates X, Y and Z.");

// Constructors
cls_Geom_CartesianPoint.def(py::init<const gp_Pnt &>(), py::arg("P"));
cls_Geom_CartesianPoint.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("X"), py::arg("Y"), py::arg("Z"));

// Fields

// Methods
cls_Geom_CartesianPoint.def("SetCoord", (void (Geom_CartesianPoint::*)(const Standard_Real, const Standard_Real, const Standard_Real)) &Geom_CartesianPoint::SetCoord, "Assigns the coordinates X, Y and Z to this point.", py::arg("X"), py::arg("Y"), py::arg("Z"));
cls_Geom_CartesianPoint.def("SetPnt", (void (Geom_CartesianPoint::*)(const gp_Pnt &)) &Geom_CartesianPoint::SetPnt, "Set <me> to P.X(), P.Y(), P.Z() coordinates.", py::arg("P"));
cls_Geom_CartesianPoint.def("SetX", (void (Geom_CartesianPoint::*)(const Standard_Real)) &Geom_CartesianPoint::SetX, "Changes the X coordinate of me.", py::arg("X"));
cls_Geom_CartesianPoint.def("SetY", (void (Geom_CartesianPoint::*)(const Standard_Real)) &Geom_CartesianPoint::SetY, "Changes the Y coordinate of me.", py::arg("Y"));
cls_Geom_CartesianPoint.def("SetZ", (void (Geom_CartesianPoint::*)(const Standard_Real)) &Geom_CartesianPoint::SetZ, "Changes the Z coordinate of me.", py::arg("Z"));
cls_Geom_CartesianPoint.def("Coord", [](Geom_CartesianPoint &self, Standard_Real & X, Standard_Real & Y, Standard_Real & Z){ self.Coord(X, Y, Z); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(X, Y, Z); }, "Returns the coordinates of <me>.", py::arg("X"), py::arg("Y"), py::arg("Z"));
cls_Geom_CartesianPoint.def("Pnt", (gp_Pnt (Geom_CartesianPoint::*)() const) &Geom_CartesianPoint::Pnt, "Returns a non transient cartesian point with the same coordinates as <me>.");
cls_Geom_CartesianPoint.def("X", (Standard_Real (Geom_CartesianPoint::*)() const) &Geom_CartesianPoint::X, "Returns the X coordinate of <me>.");
cls_Geom_CartesianPoint.def("Y", (Standard_Real (Geom_CartesianPoint::*)() const) &Geom_CartesianPoint::Y, "Returns the Y coordinate of <me>.");
cls_Geom_CartesianPoint.def("Z", (Standard_Real (Geom_CartesianPoint::*)() const) &Geom_CartesianPoint::Z, "Returns the Z coordinate of <me>.");
cls_Geom_CartesianPoint.def("Transform", (void (Geom_CartesianPoint::*)(const gp_Trsf &)) &Geom_CartesianPoint::Transform, "Applies the transformation T to this point.", py::arg("T"));
cls_Geom_CartesianPoint.def("Copy", (opencascade::handle<Geom_Geometry> (Geom_CartesianPoint::*)() const) &Geom_CartesianPoint::Copy, "Creates a new object which is a copy of this point.");
cls_Geom_CartesianPoint.def_static("get_type_name_", (const char * (*)()) &Geom_CartesianPoint::get_type_name, "None");
cls_Geom_CartesianPoint.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Geom_CartesianPoint::get_type_descriptor, "None");
cls_Geom_CartesianPoint.def("DynamicType", (const opencascade::handle<Standard_Type> & (Geom_CartesianPoint::*)() const) &Geom_CartesianPoint::DynamicType, "None");

// Enums

}