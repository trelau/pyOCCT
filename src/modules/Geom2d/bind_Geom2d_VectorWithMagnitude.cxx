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
#include <gp_Vec2d.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt2d.hxx>
#include <Standard_Handle.hxx>
#include <Geom2d_VectorWithMagnitude.hxx>
#include <gp_Trsf2d.hxx>
#include <Geom2d_Geometry.hxx>
#include <Standard_Type.hxx>

void bind_Geom2d_VectorWithMagnitude(py::module &mod){

py::class_<Geom2d_VectorWithMagnitude, opencascade::handle<Geom2d_VectorWithMagnitude>, Geom2d_Vector> cls_Geom2d_VectorWithMagnitude(mod, "Geom2d_VectorWithMagnitude", "Defines a vector with magnitude. A vector with magnitude can have a zero length.");

// Constructors
cls_Geom2d_VectorWithMagnitude.def(py::init<const gp_Vec2d &>(), py::arg("V"));
cls_Geom2d_VectorWithMagnitude.def(py::init<const Standard_Real, const Standard_Real>(), py::arg("X"), py::arg("Y"));
cls_Geom2d_VectorWithMagnitude.def(py::init<const gp_Pnt2d &, const gp_Pnt2d &>(), py::arg("P1"), py::arg("P2"));

// Fields

// Methods
cls_Geom2d_VectorWithMagnitude.def("SetCoord", (void (Geom2d_VectorWithMagnitude::*)(const Standard_Real, const Standard_Real)) &Geom2d_VectorWithMagnitude::SetCoord, "Set <me> to X, Y coordinates.", py::arg("X"), py::arg("Y"));
cls_Geom2d_VectorWithMagnitude.def("SetVec2d", (void (Geom2d_VectorWithMagnitude::*)(const gp_Vec2d &)) &Geom2d_VectorWithMagnitude::SetVec2d, "None", py::arg("V"));
cls_Geom2d_VectorWithMagnitude.def("SetX", (void (Geom2d_VectorWithMagnitude::*)(const Standard_Real)) &Geom2d_VectorWithMagnitude::SetX, "Changes the X coordinate of <me>.", py::arg("X"));
cls_Geom2d_VectorWithMagnitude.def("SetY", (void (Geom2d_VectorWithMagnitude::*)(const Standard_Real)) &Geom2d_VectorWithMagnitude::SetY, "Changes the Y coordinate of <me>", py::arg("Y"));
cls_Geom2d_VectorWithMagnitude.def("Magnitude", (Standard_Real (Geom2d_VectorWithMagnitude::*)() const) &Geom2d_VectorWithMagnitude::Magnitude, "Returns the magnitude of <me>.");
cls_Geom2d_VectorWithMagnitude.def("SquareMagnitude", (Standard_Real (Geom2d_VectorWithMagnitude::*)() const) &Geom2d_VectorWithMagnitude::SquareMagnitude, "Returns the square magnitude of <me>.");
cls_Geom2d_VectorWithMagnitude.def("Add", (void (Geom2d_VectorWithMagnitude::*)(const opencascade::handle<Geom2d_Vector> &)) &Geom2d_VectorWithMagnitude::Add, "Adds the Vector Other to <me>.", py::arg("Other"));
cls_Geom2d_VectorWithMagnitude.def("__iadd__", (void (Geom2d_VectorWithMagnitude::*)(const opencascade::handle<Geom2d_Vector> &)) &Geom2d_VectorWithMagnitude::operator+=, py::is_operator(), "None", py::arg("Other"));
cls_Geom2d_VectorWithMagnitude.def("Added", (opencascade::handle<Geom2d_VectorWithMagnitude> (Geom2d_VectorWithMagnitude::*)(const opencascade::handle<Geom2d_Vector> &) const) &Geom2d_VectorWithMagnitude::Added, "Adds the vector Other to <me>.", py::arg("Other"));
cls_Geom2d_VectorWithMagnitude.def("__add__", (opencascade::handle<Geom2d_VectorWithMagnitude> (Geom2d_VectorWithMagnitude::*)(const opencascade::handle<Geom2d_Vector> &) const) &Geom2d_VectorWithMagnitude::operator+, py::is_operator(), "None", py::arg("Other"));
cls_Geom2d_VectorWithMagnitude.def("Crossed", (Standard_Real (Geom2d_VectorWithMagnitude::*)(const opencascade::handle<Geom2d_Vector> &) const) &Geom2d_VectorWithMagnitude::Crossed, "Computes the cross product between <me> and Other <me> ^ Other. A new vector is returned.", py::arg("Other"));
cls_Geom2d_VectorWithMagnitude.def("operator^", (Standard_Real (Geom2d_VectorWithMagnitude::*)(const opencascade::handle<Geom2d_Vector> &) const) &Geom2d_VectorWithMagnitude::operator^, "None", py::arg("Other"));
cls_Geom2d_VectorWithMagnitude.def("Divide", (void (Geom2d_VectorWithMagnitude::*)(const Standard_Real)) &Geom2d_VectorWithMagnitude::Divide, "Divides <me> by a scalar.", py::arg("Scalar"));
cls_Geom2d_VectorWithMagnitude.def("__itruediv__", (void (Geom2d_VectorWithMagnitude::*)(const Standard_Real)) &Geom2d_VectorWithMagnitude::operator/=, py::is_operator(), "None", py::arg("Scalar"));
cls_Geom2d_VectorWithMagnitude.def("Divided", (opencascade::handle<Geom2d_VectorWithMagnitude> (Geom2d_VectorWithMagnitude::*)(const Standard_Real) const) &Geom2d_VectorWithMagnitude::Divided, "Divides <me> by a scalar. A new vector is returned.", py::arg("Scalar"));
cls_Geom2d_VectorWithMagnitude.def("__truediv__", (opencascade::handle<Geom2d_VectorWithMagnitude> (Geom2d_VectorWithMagnitude::*)(const Standard_Real) const) &Geom2d_VectorWithMagnitude::operator/, py::is_operator(), "None", py::arg("Scalar"));
cls_Geom2d_VectorWithMagnitude.def("Multiplied", (opencascade::handle<Geom2d_VectorWithMagnitude> (Geom2d_VectorWithMagnitude::*)(const Standard_Real) const) &Geom2d_VectorWithMagnitude::Multiplied, "Computes the product of the vector <me> by a scalar. A new vector is returned.", py::arg("Scalar"));
cls_Geom2d_VectorWithMagnitude.def("Multiply", (void (Geom2d_VectorWithMagnitude::*)(const Standard_Real)) &Geom2d_VectorWithMagnitude::Multiply, "Computes the product of the vector <me> by a scalar.", py::arg("Scalar"));
cls_Geom2d_VectorWithMagnitude.def("__imul__", (void (Geom2d_VectorWithMagnitude::*)(const Standard_Real)) &Geom2d_VectorWithMagnitude::operator*=, py::is_operator(), "None", py::arg("Scalar"));
cls_Geom2d_VectorWithMagnitude.def("Normalize", (void (Geom2d_VectorWithMagnitude::*)()) &Geom2d_VectorWithMagnitude::Normalize, "Normalizes <me>.");
cls_Geom2d_VectorWithMagnitude.def("Normalized", (opencascade::handle<Geom2d_VectorWithMagnitude> (Geom2d_VectorWithMagnitude::*)() const) &Geom2d_VectorWithMagnitude::Normalized, "Returns a copy of <me> Normalized.");
cls_Geom2d_VectorWithMagnitude.def("Subtract", (void (Geom2d_VectorWithMagnitude::*)(const opencascade::handle<Geom2d_Vector> &)) &Geom2d_VectorWithMagnitude::Subtract, "Subtracts the Vector Other to <me>.", py::arg("Other"));
cls_Geom2d_VectorWithMagnitude.def("__isub__", (void (Geom2d_VectorWithMagnitude::*)(const opencascade::handle<Geom2d_Vector> &)) &Geom2d_VectorWithMagnitude::operator-=, py::is_operator(), "None", py::arg("Other"));
cls_Geom2d_VectorWithMagnitude.def("Subtracted", (opencascade::handle<Geom2d_VectorWithMagnitude> (Geom2d_VectorWithMagnitude::*)(const opencascade::handle<Geom2d_Vector> &) const) &Geom2d_VectorWithMagnitude::Subtracted, "Subtracts the vector Other to <me>. A new vector is returned.", py::arg("Other"));
cls_Geom2d_VectorWithMagnitude.def("__sub__", (opencascade::handle<Geom2d_VectorWithMagnitude> (Geom2d_VectorWithMagnitude::*)(const opencascade::handle<Geom2d_Vector> &) const) &Geom2d_VectorWithMagnitude::operator-, py::is_operator(), "None", py::arg("Other"));
cls_Geom2d_VectorWithMagnitude.def("Transform", (void (Geom2d_VectorWithMagnitude::*)(const gp_Trsf2d &)) &Geom2d_VectorWithMagnitude::Transform, "Applies the transformation T to this vector.", py::arg("T"));
cls_Geom2d_VectorWithMagnitude.def("Copy", (opencascade::handle<Geom2d_Geometry> (Geom2d_VectorWithMagnitude::*)() const) &Geom2d_VectorWithMagnitude::Copy, "Creates a new object which is a copy of this vector.");
cls_Geom2d_VectorWithMagnitude.def_static("get_type_name_", (const char * (*)()) &Geom2d_VectorWithMagnitude::get_type_name, "None");
cls_Geom2d_VectorWithMagnitude.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Geom2d_VectorWithMagnitude::get_type_descriptor, "None");
cls_Geom2d_VectorWithMagnitude.def("DynamicType", (const opencascade::handle<Standard_Type> & (Geom2d_VectorWithMagnitude::*)() const) &Geom2d_VectorWithMagnitude::DynamicType, "None");

// Enums

}