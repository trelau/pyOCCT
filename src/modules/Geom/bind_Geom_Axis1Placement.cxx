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
#include <Geom_AxisPlacement.hxx>
#include <gp_Ax1.hxx>
#include <gp_Pnt.hxx>
#include <gp_Dir.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Axis1Placement.hxx>
#include <gp_Trsf.hxx>
#include <Geom_Geometry.hxx>
#include <Standard_Type.hxx>

void bind_Geom_Axis1Placement(py::module &mod){

py::class_<Geom_Axis1Placement, opencascade::handle<Geom_Axis1Placement>, Geom_AxisPlacement> cls_Geom_Axis1Placement(mod, "Geom_Axis1Placement", "Describes an axis in 3D space. An axis is defined by: - its origin, also termed the 'Location point' of the axis, - its unit vector, termed the 'Direction' of the axis. Note: Geom_Axis1Placement axes provide the same kind of 'geometric' services as gp_Ax1 axes but have more complex data structures. The geometric objects provided by the Geom package use gp_Ax1 objects to include axes in their data structures, or to define an axis of symmetry or axis of rotation. Geom_Axis1Placement axes are used in a context where they can be shared by several objects contained inside a common data structure.");

// Constructors
cls_Geom_Axis1Placement.def(py::init<const gp_Ax1 &>(), py::arg("A1"));
cls_Geom_Axis1Placement.def(py::init<const gp_Pnt &, const gp_Dir &>(), py::arg("P"), py::arg("V"));

// Fields

// Methods
cls_Geom_Axis1Placement.def("Ax1", (const gp_Ax1 & (Geom_Axis1Placement::*)() const) &Geom_Axis1Placement::Ax1, "Returns a non transient copy of <me>.");
cls_Geom_Axis1Placement.def("Reverse", (void (Geom_Axis1Placement::*)()) &Geom_Axis1Placement::Reverse, "Reverses the direction of the axis placement.");
cls_Geom_Axis1Placement.def("Reversed", (opencascade::handle<Geom_Axis1Placement> (Geom_Axis1Placement::*)() const) &Geom_Axis1Placement::Reversed, "Returns a copy of <me> reversed.");
cls_Geom_Axis1Placement.def("SetDirection", (void (Geom_Axis1Placement::*)(const gp_Dir &)) &Geom_Axis1Placement::SetDirection, "Assigns V to the unit vector of this axis.", py::arg("V"));
cls_Geom_Axis1Placement.def("Transform", (void (Geom_Axis1Placement::*)(const gp_Trsf &)) &Geom_Axis1Placement::Transform, "Applies the transformation T to this axis.", py::arg("T"));
cls_Geom_Axis1Placement.def("Copy", (opencascade::handle<Geom_Geometry> (Geom_Axis1Placement::*)() const) &Geom_Axis1Placement::Copy, "Creates a new object, which is a copy of this axis.");
cls_Geom_Axis1Placement.def_static("get_type_name_", (const char * (*)()) &Geom_Axis1Placement::get_type_name, "None");
cls_Geom_Axis1Placement.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Geom_Axis1Placement::get_type_descriptor, "None");
cls_Geom_Axis1Placement.def("DynamicType", (const opencascade::handle<Standard_Type> & (Geom_Axis1Placement::*)() const) &Geom_Axis1Placement::DynamicType, "None");

// Enums

}