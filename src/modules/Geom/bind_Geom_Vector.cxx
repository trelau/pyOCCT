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
#include <Standard_Handle.hxx>
#include <Geom_Vector.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Vec.hxx>
#include <Standard_Type.hxx>

void bind_Geom_Vector(py::module &mod){

py::class_<Geom_Vector, opencascade::handle<Geom_Vector>, Geom_Geometry> cls_Geom_Vector(mod, "Geom_Vector", "The abstract class Vector describes the common behavior of vectors in 3D space. The Geom package provides two concrete classes of vectors: Geom_Direction (unit vector) and Geom_VectorWithMagnitude.");

// Fields

// Methods
cls_Geom_Vector.def("Reverse", (void (Geom_Vector::*)()) &Geom_Vector::Reverse, "Reverses the vector <me>.");
cls_Geom_Vector.def("Reversed", (opencascade::handle<Geom_Vector> (Geom_Vector::*)() const) &Geom_Vector::Reversed, "Returns a copy of <me> reversed.");
cls_Geom_Vector.def("Angle", (Standard_Real (Geom_Vector::*)(const opencascade::handle<Geom_Vector> &) const) &Geom_Vector::Angle, "Computes the angular value, in radians, between this vector and vector Other. The result is a value between 0 and Pi. Exceptions gp_VectorWithNullMagnitude if: - the magnitude of this vector is less than or equal to gp::Resolution(), or - the magnitude of vector Other is less than or equal to gp::Resolution().", py::arg("Other"));
cls_Geom_Vector.def("AngleWithRef", (Standard_Real (Geom_Vector::*)(const opencascade::handle<Geom_Vector> &, const opencascade::handle<Geom_Vector> &) const) &Geom_Vector::AngleWithRef, "Computes the angular value, in radians, between this vector and vector Other. The result is a value between -Pi and Pi. The vector VRef defines the positive sense of rotation: the angular value is positive if the cross product this ^ Other has the same orientation as VRef (in relation to the plane defined by this vector and vector Other). Otherwise, it is negative. Exceptions Standard_DomainError if this vector, vector Other and vector VRef are coplanar, except if this vector and vector Other are parallel. gp_VectorWithNullMagnitude if the magnitude of this vector, vector Other or vector VRef is less than or equal to gp::Resolution().", py::arg("Other"), py::arg("VRef"));
cls_Geom_Vector.def("Coord", [](Geom_Vector &self, Standard_Real & X, Standard_Real & Y, Standard_Real & Z){ self.Coord(X, Y, Z); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(X, Y, Z); }, "Returns the coordinates X, Y and Z of this vector.", py::arg("X"), py::arg("Y"), py::arg("Z"));
cls_Geom_Vector.def("Magnitude", (Standard_Real (Geom_Vector::*)() const) &Geom_Vector::Magnitude, "Returns the Magnitude of <me>.");
cls_Geom_Vector.def("SquareMagnitude", (Standard_Real (Geom_Vector::*)() const) &Geom_Vector::SquareMagnitude, "Returns the square magnitude of <me>.");
cls_Geom_Vector.def("X", (Standard_Real (Geom_Vector::*)() const) &Geom_Vector::X, "Returns the X coordinate of <me>.");
cls_Geom_Vector.def("Y", (Standard_Real (Geom_Vector::*)() const) &Geom_Vector::Y, "Returns the Y coordinate of <me>.");
cls_Geom_Vector.def("Z", (Standard_Real (Geom_Vector::*)() const) &Geom_Vector::Z, "Returns the Z coordinate of <me>.");
cls_Geom_Vector.def("Cross", (void (Geom_Vector::*)(const opencascade::handle<Geom_Vector> &)) &Geom_Vector::Cross, "Computes the cross product between <me> and <Other>.", py::arg("Other"));
cls_Geom_Vector.def("Crossed", (opencascade::handle<Geom_Vector> (Geom_Vector::*)(const opencascade::handle<Geom_Vector> &) const) &Geom_Vector::Crossed, "Computes the cross product between <me> and <Other>. A new direction is returned.", py::arg("Other"));
cls_Geom_Vector.def("CrossCross", (void (Geom_Vector::*)(const opencascade::handle<Geom_Vector> &, const opencascade::handle<Geom_Vector> &)) &Geom_Vector::CrossCross, "Computes the triple vector product <me> ^(V1 ^ V2).", py::arg("V1"), py::arg("V2"));
cls_Geom_Vector.def("CrossCrossed", (opencascade::handle<Geom_Vector> (Geom_Vector::*)(const opencascade::handle<Geom_Vector> &, const opencascade::handle<Geom_Vector> &) const) &Geom_Vector::CrossCrossed, "Computes the triple vector product <me> ^(V1 ^ V2).", py::arg("V1"), py::arg("V2"));
cls_Geom_Vector.def("Dot", (Standard_Real (Geom_Vector::*)(const opencascade::handle<Geom_Vector> &) const) &Geom_Vector::Dot, "Computes the scalar product of this vector and vector Other.", py::arg("Other"));
cls_Geom_Vector.def("DotCross", (Standard_Real (Geom_Vector::*)(const opencascade::handle<Geom_Vector> &, const opencascade::handle<Geom_Vector> &) const) &Geom_Vector::DotCross, "Computes the triple scalar product. Returns me . (V1 ^ V2)", py::arg("V1"), py::arg("V2"));
cls_Geom_Vector.def("Vec", (const gp_Vec & (Geom_Vector::*)() const) &Geom_Vector::Vec, "Converts this vector into a gp_Vec vector.");
cls_Geom_Vector.def_static("get_type_name_", (const char * (*)()) &Geom_Vector::get_type_name, "None");
cls_Geom_Vector.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Geom_Vector::get_type_descriptor, "None");
cls_Geom_Vector.def("DynamicType", (const opencascade::handle<Standard_Type> & (Geom_Vector::*)() const) &Geom_Vector::DynamicType, "None");

// Enums

}