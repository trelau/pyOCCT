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
#include <gp_Ax2d.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Dir2d.hxx>
#include <Standard_Handle.hxx>
#include <Geom2d_AxisPlacement.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Trsf2d.hxx>
#include <Standard_Type.hxx>

void bind_Geom2d_AxisPlacement(py::module &mod){

py::class_<Geom2d_AxisPlacement, opencascade::handle<Geom2d_AxisPlacement>, Geom2d_Geometry> cls_Geom2d_AxisPlacement(mod, "Geom2d_AxisPlacement", "Describes an axis in 2D space. An axis is defined by: - its origin, also termed the 'Location point' of the axis, - its unit vector, termed the 'Direction' of the axis. Note: Geom2d_AxisPlacement axes provide the same kind of 'geometric' services as gp_Ax2d axes but have more complex data structures. The geometric objects provided by the Geom2d package use gp_Ax2d objects to include axes in their data structures, or to define an axis of symmetry or axis of rotation. Geom2d_AxisPlacement axes are used in a context where they can be shared by several objects contained inside a common data structure.");

// Constructors
cls_Geom2d_AxisPlacement.def(py::init<const gp_Ax2d &>(), py::arg("A"));
cls_Geom2d_AxisPlacement.def(py::init<const gp_Pnt2d &, const gp_Dir2d &>(), py::arg("P"), py::arg("V"));

// Fields

// Methods
cls_Geom2d_AxisPlacement.def("Reverse", (void (Geom2d_AxisPlacement::*)()) &Geom2d_AxisPlacement::Reverse, "None");
cls_Geom2d_AxisPlacement.def("Reversed", (opencascade::handle<Geom2d_AxisPlacement> (Geom2d_AxisPlacement::*)() const) &Geom2d_AxisPlacement::Reversed, "Reverses the unit vector of this axis. Note: - Reverse assigns the result to this axis, while - Reversed creates a new one.");
cls_Geom2d_AxisPlacement.def("SetAxis", (void (Geom2d_AxisPlacement::*)(const gp_Ax2d &)) &Geom2d_AxisPlacement::SetAxis, "Changes the complete definition of the axis placement.", py::arg("A"));
cls_Geom2d_AxisPlacement.def("SetDirection", (void (Geom2d_AxisPlacement::*)(const gp_Dir2d &)) &Geom2d_AxisPlacement::SetDirection, "Changes the 'Direction' of the axis placement.", py::arg("V"));
cls_Geom2d_AxisPlacement.def("SetLocation", (void (Geom2d_AxisPlacement::*)(const gp_Pnt2d &)) &Geom2d_AxisPlacement::SetLocation, "Changes the 'Location' point (origin) of the axis placement.", py::arg("P"));
cls_Geom2d_AxisPlacement.def("Angle", (Standard_Real (Geom2d_AxisPlacement::*)(const opencascade::handle<Geom2d_AxisPlacement> &) const) &Geom2d_AxisPlacement::Angle, "Computes the angle between the 'Direction' of two axis placement in radians. The result is comprised between -Pi and Pi.", py::arg("Other"));
cls_Geom2d_AxisPlacement.def("Ax2d", (gp_Ax2d (Geom2d_AxisPlacement::*)() const) &Geom2d_AxisPlacement::Ax2d, "Converts this axis into a gp_Ax2d axis.");
cls_Geom2d_AxisPlacement.def("Direction", (gp_Dir2d (Geom2d_AxisPlacement::*)() const) &Geom2d_AxisPlacement::Direction, "Returns the 'Direction' of <me>. -C++: return const&");
cls_Geom2d_AxisPlacement.def("Location", (gp_Pnt2d (Geom2d_AxisPlacement::*)() const) &Geom2d_AxisPlacement::Location, "Returns the 'Location' point (origin) of the axis placement. -C++: return const&");
cls_Geom2d_AxisPlacement.def("Transform", (void (Geom2d_AxisPlacement::*)(const gp_Trsf2d &)) &Geom2d_AxisPlacement::Transform, "Applies the transformation T to this axis.", py::arg("T"));
cls_Geom2d_AxisPlacement.def("Copy", (opencascade::handle<Geom2d_Geometry> (Geom2d_AxisPlacement::*)() const) &Geom2d_AxisPlacement::Copy, "Creates a new object which is a copy of this axis.");
cls_Geom2d_AxisPlacement.def_static("get_type_name_", (const char * (*)()) &Geom2d_AxisPlacement::get_type_name, "None");
cls_Geom2d_AxisPlacement.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Geom2d_AxisPlacement::get_type_descriptor, "None");
cls_Geom2d_AxisPlacement.def("DynamicType", (const opencascade::handle<Standard_Type> & (Geom2d_AxisPlacement::*)() const) &Geom2d_AxisPlacement::DynamicType, "None");

// Enums

}