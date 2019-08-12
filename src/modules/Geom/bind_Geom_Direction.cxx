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
#include <Geom_Vector.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Dir.hxx>
#include <Standard_Handle.hxx>
#include <gp_Trsf.hxx>
#include <Geom_Geometry.hxx>
#include <Geom_Direction.hxx>
#include <Standard_Type.hxx>

void bind_Geom_Direction(py::module &mod){

py::class_<Geom_Direction, opencascade::handle<Geom_Direction>, Geom_Vector> cls_Geom_Direction(mod, "Geom_Direction", "The class Direction specifies a vector that is never null. It is a unit vector.");

// Constructors
cls_Geom_Direction.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("X"), py::arg("Y"), py::arg("Z"));
cls_Geom_Direction.def(py::init<const gp_Dir &>(), py::arg("V"));

// Fields

// Methods
cls_Geom_Direction.def("SetCoord", (void (Geom_Direction::*)(const Standard_Real, const Standard_Real, const Standard_Real)) &Geom_Direction::SetCoord, "Sets <me> to X,Y,Z coordinates.", py::arg("X"), py::arg("Y"), py::arg("Z"));
cls_Geom_Direction.def("SetDir", (void (Geom_Direction::*)(const gp_Dir &)) &Geom_Direction::SetDir, "Converts the gp_Dir unit vector V into this unit vector.", py::arg("V"));
cls_Geom_Direction.def("SetX", (void (Geom_Direction::*)(const Standard_Real)) &Geom_Direction::SetX, "Changes the X coordinate of <me>.", py::arg("X"));
cls_Geom_Direction.def("SetY", (void (Geom_Direction::*)(const Standard_Real)) &Geom_Direction::SetY, "Changes the Y coordinate of <me>.", py::arg("Y"));
cls_Geom_Direction.def("SetZ", (void (Geom_Direction::*)(const Standard_Real)) &Geom_Direction::SetZ, "Changes the Z coordinate of <me>.", py::arg("Z"));
cls_Geom_Direction.def("Dir", (gp_Dir (Geom_Direction::*)() const) &Geom_Direction::Dir, "Returns the non transient direction with the same coordinates as <me>.");
cls_Geom_Direction.def("Magnitude", (Standard_Real (Geom_Direction::*)() const) &Geom_Direction::Magnitude, "returns 1.0 which is the magnitude of any unit vector.");
cls_Geom_Direction.def("SquareMagnitude", (Standard_Real (Geom_Direction::*)() const) &Geom_Direction::SquareMagnitude, "returns 1.0 which is the square magnitude of any unit vector.");
cls_Geom_Direction.def("Cross", (void (Geom_Direction::*)(const opencascade::handle<Geom_Vector> &)) &Geom_Direction::Cross, "Computes the cross product between <me> and <Other>.", py::arg("Other"));
cls_Geom_Direction.def("CrossCross", (void (Geom_Direction::*)(const opencascade::handle<Geom_Vector> &, const opencascade::handle<Geom_Vector> &)) &Geom_Direction::CrossCross, "Computes the triple vector product <me> ^(V1 ^ V2).", py::arg("V1"), py::arg("V2"));
cls_Geom_Direction.def("Crossed", (opencascade::handle<Geom_Vector> (Geom_Direction::*)(const opencascade::handle<Geom_Vector> &) const) &Geom_Direction::Crossed, "Computes the cross product between <me> and <Other>. A new direction is returned.", py::arg("Other"));
cls_Geom_Direction.def("CrossCrossed", (opencascade::handle<Geom_Vector> (Geom_Direction::*)(const opencascade::handle<Geom_Vector> &, const opencascade::handle<Geom_Vector> &) const) &Geom_Direction::CrossCrossed, "Computes the triple vector product <me> ^(V1 ^ V2).", py::arg("V1"), py::arg("V2"));
cls_Geom_Direction.def("Transform", (void (Geom_Direction::*)(const gp_Trsf &)) &Geom_Direction::Transform, "Applies the transformation T to this unit vector, then normalizes it.", py::arg("T"));
cls_Geom_Direction.def("Copy", (opencascade::handle<Geom_Geometry> (Geom_Direction::*)() const) &Geom_Direction::Copy, "Creates a new object which is a copy of this unit vector.");
cls_Geom_Direction.def_static("get_type_name_", (const char * (*)()) &Geom_Direction::get_type_name, "None");
cls_Geom_Direction.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Geom_Direction::get_type_descriptor, "None");
cls_Geom_Direction.def("DynamicType", (const opencascade::handle<Standard_Type> & (Geom_Direction::*)() const) &Geom_Direction::DynamicType, "None");

// Enums

}