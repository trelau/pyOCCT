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
#include <Geom_Geometry.hxx>
#include <gp_Ax1.hxx>
#include <gp_Dir.hxx>
#include <gp_Pnt.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Geom_AxisPlacement.hxx>
#include <Standard_Type.hxx>

void bind_Geom_AxisPlacement(py::module &mod){

py::class_<Geom_AxisPlacement, opencascade::handle<Geom_AxisPlacement>, Geom_Geometry> cls_Geom_AxisPlacement(mod, "Geom_AxisPlacement", "The abstract class AxisPlacement describes the common behavior of positioning systems in 3D space, such as axis or coordinate systems. The Geom package provides two implementations of 3D positioning systems: - the axis (Geom_Axis1Placement class), which is defined by: - its origin, also termed the 'Location point' of the axis, - its unit vector, termed the 'Direction' or 'main Direction' of the axis; - the right-handed coordinate system (Geom_Axis2Placement class), which is defined by: - its origin, also termed the 'Location point' of the coordinate system, - three orthogonal unit vectors, termed respectively the 'X Direction', the 'Y Direction' and the 'Direction' of the coordinate system. As the coordinate system is right-handed, these unit vectors have the following relation: 'Direction' = 'X Direction' ^ 'Y Direction'. The 'Direction' is also called the 'main Direction' because, when the unit vector is modified, the 'X Direction' and 'Y Direction' are recomputed, whereas when the 'X Direction' or 'Y Direction' is modified, the 'main Direction' does not change. The axis whose origin is the origin of the positioning system and whose unit vector is its 'main Direction' is also called the 'Axis' or 'main Axis' of the positioning system.");

// Fields

// Methods
cls_Geom_AxisPlacement.def("SetAxis", (void (Geom_AxisPlacement::*)(const gp_Ax1 &)) &Geom_AxisPlacement::SetAxis, "Assigns A1 as the 'main Axis' of this positioning system. This modifies - its origin, and - its 'main Direction'. If this positioning system is a Geom_Axis2Placement, then its 'X Direction' and 'Y Direction' are recomputed. Exceptions For a Geom_Axis2Placement: Standard_ConstructionError if A1 and the previous 'X Direction' of the coordinate system are parallel.", py::arg("A1"));
cls_Geom_AxisPlacement.def("SetDirection", (void (Geom_AxisPlacement::*)(const gp_Dir &)) &Geom_AxisPlacement::SetDirection, "Changes the direction of the axis placement. If <me> is an axis placement two axis the main 'Direction' is modified and the 'XDirection' and 'YDirection' are recomputed. Raises ConstructionError only for an axis placement two axis if V and the previous 'XDirection' are parallel because it is not possible to calculate the new 'XDirection' and the new 'YDirection'.", py::arg("V"));
cls_Geom_AxisPlacement.def("SetLocation", (void (Geom_AxisPlacement::*)(const gp_Pnt &)) &Geom_AxisPlacement::SetLocation, "Assigns the point P as the origin of this positioning system.", py::arg("P"));
cls_Geom_AxisPlacement.def("Angle", (Standard_Real (Geom_AxisPlacement::*)(const opencascade::handle<Geom_AxisPlacement> &) const) &Geom_AxisPlacement::Angle, "Computes the angular value, in radians, between the 'main Direction' of this positioning system and that of positioning system Other. The result is a value between 0 and Pi.", py::arg("Other"));
cls_Geom_AxisPlacement.def("Axis", (const gp_Ax1 & (Geom_AxisPlacement::*)() const) &Geom_AxisPlacement::Axis, "Returns the main axis of the axis placement. For an 'Axis2placement' it is the main axis (Location, Direction ). For an 'Axis1Placement' this method returns a copy of <me>.");
cls_Geom_AxisPlacement.def("Direction", (gp_Dir (Geom_AxisPlacement::*)() const) &Geom_AxisPlacement::Direction, "Returns the main 'Direction' of an axis placement.");
cls_Geom_AxisPlacement.def("Location", (gp_Pnt (Geom_AxisPlacement::*)() const) &Geom_AxisPlacement::Location, "Returns the Location point (origin) of the axis placement.");
cls_Geom_AxisPlacement.def_static("get_type_name_", (const char * (*)()) &Geom_AxisPlacement::get_type_name, "None");
cls_Geom_AxisPlacement.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Geom_AxisPlacement::get_type_descriptor, "None");
cls_Geom_AxisPlacement.def("DynamicType", (const opencascade::handle<Standard_Type> & (Geom_AxisPlacement::*)() const) &Geom_AxisPlacement::DynamicType, "None");

// Enums

}