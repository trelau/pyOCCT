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
#include <Geom2d_Vector.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Dir2d.hxx>
#include <Standard_Handle.hxx>
#include <gp_Trsf2d.hxx>
#include <Geom2d_Geometry.hxx>
#include <Geom2d_Direction.hxx>
#include <Standard_Type.hxx>

void bind_Geom2d_Direction(py::module &mod){

py::class_<Geom2d_Direction, opencascade::handle<Geom2d_Direction>, Geom2d_Vector> cls_Geom2d_Direction(mod, "Geom2d_Direction", "The class Direction specifies a vector that is never null. It is a unit vector.");

// Constructors
cls_Geom2d_Direction.def(py::init<const Standard_Real, const Standard_Real>(), py::arg("X"), py::arg("Y"));
cls_Geom2d_Direction.def(py::init<const gp_Dir2d &>(), py::arg("V"));

// Fields

// Methods
cls_Geom2d_Direction.def("SetCoord", (void (Geom2d_Direction::*)(const Standard_Real, const Standard_Real)) &Geom2d_Direction::SetCoord, "Assigns the coordinates X and Y to this unit vector, then normalizes it. Exceptions Standard_ConstructionError if Sqrt(X*X + Y*Y) is less than or equal to gp::Resolution().", py::arg("X"), py::arg("Y"));
cls_Geom2d_Direction.def("SetDir2d", (void (Geom2d_Direction::*)(const gp_Dir2d &)) &Geom2d_Direction::SetDir2d, "Converts the gp_Dir2d unit vector V into this unit vector.", py::arg("V"));
cls_Geom2d_Direction.def("SetX", (void (Geom2d_Direction::*)(const Standard_Real)) &Geom2d_Direction::SetX, "Assigns a value to the X coordinate of this unit vector, then normalizes it. Exceptions Standard_ConstructionError if the value assigned causes the magnitude of the vector to become less than or equal to gp::Resolution().", py::arg("X"));
cls_Geom2d_Direction.def("SetY", (void (Geom2d_Direction::*)(const Standard_Real)) &Geom2d_Direction::SetY, "Assigns a value to the Y coordinate of this unit vector, then normalizes it. Exceptions Standard_ConstructionError if the value assigned causes the magnitude of the vector to become less than or equal to gp::Resolution().", py::arg("Y"));
cls_Geom2d_Direction.def("Dir2d", (gp_Dir2d (Geom2d_Direction::*)() const) &Geom2d_Direction::Dir2d, "Converts this unit vector into a gp_Dir2d unit vector.");
cls_Geom2d_Direction.def("Magnitude", (Standard_Real (Geom2d_Direction::*)() const) &Geom2d_Direction::Magnitude, "returns 1.0");
cls_Geom2d_Direction.def("SquareMagnitude", (Standard_Real (Geom2d_Direction::*)() const) &Geom2d_Direction::SquareMagnitude, "returns 1.0");
cls_Geom2d_Direction.def("Crossed", (Standard_Real (Geom2d_Direction::*)(const opencascade::handle<Geom2d_Vector> &) const) &Geom2d_Direction::Crossed, "Computes the cross product between <me> and <Other>.", py::arg("Other"));
cls_Geom2d_Direction.def("operator^", (Standard_Real (Geom2d_Direction::*)(const opencascade::handle<Geom2d_Vector> &) const) &Geom2d_Direction::operator^, "None", py::arg("Other"));
cls_Geom2d_Direction.def("Transform", (void (Geom2d_Direction::*)(const gp_Trsf2d &)) &Geom2d_Direction::Transform, "Applies the transformation T to this unit vector, then normalizes it.", py::arg("T"));
cls_Geom2d_Direction.def("Copy", (opencascade::handle<Geom2d_Geometry> (Geom2d_Direction::*)() const) &Geom2d_Direction::Copy, "Creates a new object which is a copy of this unit vector.");
cls_Geom2d_Direction.def_static("get_type_name_", (const char * (*)()) &Geom2d_Direction::get_type_name, "None");
cls_Geom2d_Direction.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Geom2d_Direction::get_type_descriptor, "None");
cls_Geom2d_Direction.def("DynamicType", (const opencascade::handle<Standard_Type> & (Geom2d_Direction::*)() const) &Geom2d_Direction::DynamicType, "None");

// Enums

}