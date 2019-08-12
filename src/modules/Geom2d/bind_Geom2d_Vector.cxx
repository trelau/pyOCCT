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
#include <Standard_Handle.hxx>
#include <Geom2d_Vector.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Vec2d.hxx>
#include <Standard_Type.hxx>

void bind_Geom2d_Vector(py::module &mod){

py::class_<Geom2d_Vector, opencascade::handle<Geom2d_Vector>, Geom2d_Geometry> cls_Geom2d_Vector(mod, "Geom2d_Vector", "The abstract class Vector describes the common behavior of vectors in 2D space. The Geom2d package provides two concrete classes of vectors: Geom2d_Direction (unit vector) and Geom2d_VectorWithMagnitude.");

// Fields

// Methods
cls_Geom2d_Vector.def("Reverse", (void (Geom2d_Vector::*)()) &Geom2d_Vector::Reverse, "Reverses the vector <me>.");
cls_Geom2d_Vector.def("Reversed", (opencascade::handle<Geom2d_Vector> (Geom2d_Vector::*)() const) &Geom2d_Vector::Reversed, "Returns a copy of <me> reversed.");
cls_Geom2d_Vector.def("Angle", (Standard_Real (Geom2d_Vector::*)(const opencascade::handle<Geom2d_Vector> &) const) &Geom2d_Vector::Angle, "Computes the angular value, in radians, between this vector and vector Other. The result is a value between -Pi and Pi. The orientation is from this vector to vector Other. Raises VectorWithNullMagnitude if one of the two vectors is a vector with null magnitude because the angular value is indefinite.", py::arg("Other"));
cls_Geom2d_Vector.def("Coord", [](Geom2d_Vector &self, Standard_Real & X, Standard_Real & Y){ self.Coord(X, Y); return std::tuple<Standard_Real &, Standard_Real &>(X, Y); }, "Returns the coordinates of <me>.", py::arg("X"), py::arg("Y"));
cls_Geom2d_Vector.def("Magnitude", (Standard_Real (Geom2d_Vector::*)() const) &Geom2d_Vector::Magnitude, "Returns the Magnitude of <me>.");
cls_Geom2d_Vector.def("SquareMagnitude", (Standard_Real (Geom2d_Vector::*)() const) &Geom2d_Vector::SquareMagnitude, "Returns the square magnitude of <me>.");
cls_Geom2d_Vector.def("X", (Standard_Real (Geom2d_Vector::*)() const) &Geom2d_Vector::X, "Returns the X coordinate of <me>.");
cls_Geom2d_Vector.def("Y", (Standard_Real (Geom2d_Vector::*)() const) &Geom2d_Vector::Y, "Returns the Y coordinate of <me>.");
cls_Geom2d_Vector.def("Crossed", (Standard_Real (Geom2d_Vector::*)(const opencascade::handle<Geom2d_Vector> &) const) &Geom2d_Vector::Crossed, "Cross product of <me> with the vector <Other>.", py::arg("Other"));
cls_Geom2d_Vector.def("Dot", (Standard_Real (Geom2d_Vector::*)(const opencascade::handle<Geom2d_Vector> &) const) &Geom2d_Vector::Dot, "Returns the scalar product of 2 Vectors.", py::arg("Other"));
cls_Geom2d_Vector.def("Vec2d", (gp_Vec2d (Geom2d_Vector::*)() const) &Geom2d_Vector::Vec2d, "Returns a non persistent copy of <me>.");
cls_Geom2d_Vector.def_static("get_type_name_", (const char * (*)()) &Geom2d_Vector::get_type_name, "None");
cls_Geom2d_Vector.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Geom2d_Vector::get_type_descriptor, "None");
cls_Geom2d_Vector.def("DynamicType", (const opencascade::handle<Standard_Type> & (Geom2d_Vector::*)() const) &Geom2d_Vector::DynamicType, "None");

// Enums

}