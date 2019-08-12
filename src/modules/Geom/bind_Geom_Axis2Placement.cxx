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
#include <gp_Ax2.hxx>
#include <gp_Pnt.hxx>
#include <gp_Dir.hxx>
#include <gp_Trsf.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Geometry.hxx>
#include <Geom_Axis2Placement.hxx>
#include <Standard_Type.hxx>

void bind_Geom_Axis2Placement(py::module &mod){

py::class_<Geom_Axis2Placement, opencascade::handle<Geom_Axis2Placement>, Geom_AxisPlacement> cls_Geom_Axis2Placement(mod, "Geom_Axis2Placement", "Describes a right-handed coordinate system in 3D space. A coordinate system is defined by: - its origin, also termed the 'Location point' of the coordinate system, - three orthogonal unit vectors, termed respectively the 'X Direction', 'Y Direction' and 'Direction' (or 'main Direction') of the coordinate system. As a Geom_Axis2Placement coordinate system is right-handed, its 'Direction' is always equal to the cross product of its 'X Direction' and 'Y Direction'. The 'Direction' of a coordinate system is called the 'main Direction' because when this unit vector is modified, the 'X Direction' and 'Y Direction' are recomputed, whereas when the 'X Direction' or 'Y Direction' is changed, the 'main Direction' is retained. The 'main Direction' is also the 'Z Direction'. Note: Geom_Axis2Placement coordinate systems provide the same kind of 'geometric' services as gp_Ax2 coordinate systems but have more complex data structures. The geometric objects provided by the Geom package use gp_Ax2 objects to include coordinate systems in their data structures, or to define the geometric transformations, which are applied to them. Geom_Axis2Placement coordinate systems are used in a context where they can be shared by several objects contained inside a common data structure.");

// Constructors
cls_Geom_Axis2Placement.def(py::init<const gp_Ax2 &>(), py::arg("A2"));
cls_Geom_Axis2Placement.def(py::init<const gp_Pnt &, const gp_Dir &, const gp_Dir &>(), py::arg("P"), py::arg("N"), py::arg("Vx"));

// Fields

// Methods
cls_Geom_Axis2Placement.def("SetAx2", (void (Geom_Axis2Placement::*)(const gp_Ax2 &)) &Geom_Axis2Placement::SetAx2, "Assigns the origin and the three unit vectors of A2 to this coordinate system.", py::arg("A2"));
cls_Geom_Axis2Placement.def("SetDirection", (void (Geom_Axis2Placement::*)(const gp_Dir &)) &Geom_Axis2Placement::SetDirection, "Changes the main direction of the axis placement. The 'Xdirection' is modified : New XDirection = V ^ (Previous_Xdirection ^ V).", py::arg("V"));
cls_Geom_Axis2Placement.def("SetXDirection", (void (Geom_Axis2Placement::*)(const gp_Dir &)) &Geom_Axis2Placement::SetXDirection, "Changes the 'XDirection' of the axis placement, Vx is the new 'XDirection'. If Vx is not normal to the main direction then 'XDirection' is computed as follow : XDirection = Direction ^ ( Vx ^ Direction). The main direction is not modified. Raised if Vx and 'Direction' are parallel.", py::arg("Vx"));
cls_Geom_Axis2Placement.def("SetYDirection", (void (Geom_Axis2Placement::*)(const gp_Dir &)) &Geom_Axis2Placement::SetYDirection, "Changes the 'YDirection' of the axis placement, Vy is the new 'YDirection'. If Vy is not normal to the main direction then 'YDirection' is computed as follow : YDirection = Direction ^ ( Vy ^ Direction). The main direction is not modified. The 'XDirection' is modified. Raised if Vy and the main direction are parallel.", py::arg("Vy"));
cls_Geom_Axis2Placement.def("Ax2", (gp_Ax2 (Geom_Axis2Placement::*)() const) &Geom_Axis2Placement::Ax2, "Returns a non transient copy of <me>.");
cls_Geom_Axis2Placement.def("XDirection", (const gp_Dir & (Geom_Axis2Placement::*)() const) &Geom_Axis2Placement::XDirection, "Returns the 'XDirection'. This is a unit vector.");
cls_Geom_Axis2Placement.def("YDirection", (const gp_Dir & (Geom_Axis2Placement::*)() const) &Geom_Axis2Placement::YDirection, "Returns the 'YDirection'. This is a unit vector.");
cls_Geom_Axis2Placement.def("Transform", (void (Geom_Axis2Placement::*)(const gp_Trsf &)) &Geom_Axis2Placement::Transform, "Transforms an axis placement with a Trsf. The 'Location' point, the 'XDirection' and the 'YDirection' are transformed with T. The resulting main 'Direction' of <me> is the cross product between the 'XDirection' and the 'YDirection' after transformation.", py::arg("T"));
cls_Geom_Axis2Placement.def("Copy", (opencascade::handle<Geom_Geometry> (Geom_Axis2Placement::*)() const) &Geom_Axis2Placement::Copy, "Creates a new object which is a copy of this coordinate system.");
cls_Geom_Axis2Placement.def_static("get_type_name_", (const char * (*)()) &Geom_Axis2Placement::get_type_name, "None");
cls_Geom_Axis2Placement.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Geom_Axis2Placement::get_type_descriptor, "None");
cls_Geom_Axis2Placement.def("DynamicType", (const opencascade::handle<Standard_Type> & (Geom_Axis2Placement::*)() const) &Geom_Axis2Placement::DynamicType, "None");

// Enums

}