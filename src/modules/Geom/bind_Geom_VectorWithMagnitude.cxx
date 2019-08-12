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
#include <gp_Vec.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <Standard_Handle.hxx>
#include <Geom_VectorWithMagnitude.hxx>
#include <gp_Trsf.hxx>
#include <Geom_Geometry.hxx>
#include <Standard_Type.hxx>

void bind_Geom_VectorWithMagnitude(py::module &mod){

py::class_<Geom_VectorWithMagnitude, opencascade::handle<Geom_VectorWithMagnitude>, Geom_Vector> cls_Geom_VectorWithMagnitude(mod, "Geom_VectorWithMagnitude", "Defines a vector with magnitude. A vector with magnitude can have a zero length.");

// Constructors
cls_Geom_VectorWithMagnitude.def(py::init<const gp_Vec &>(), py::arg("V"));
cls_Geom_VectorWithMagnitude.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("X"), py::arg("Y"), py::arg("Z"));
cls_Geom_VectorWithMagnitude.def(py::init<const gp_Pnt &, const gp_Pnt &>(), py::arg("P1"), py::arg("P2"));

// Fields

// Methods
cls_Geom_VectorWithMagnitude.def("SetCoord", (void (Geom_VectorWithMagnitude::*)(const Standard_Real, const Standard_Real, const Standard_Real)) &Geom_VectorWithMagnitude::SetCoord, "Assigns the values X, Y and Z to the coordinates of this vector.", py::arg("X"), py::arg("Y"), py::arg("Z"));
cls_Geom_VectorWithMagnitude.def("SetVec", (void (Geom_VectorWithMagnitude::*)(const gp_Vec &)) &Geom_VectorWithMagnitude::SetVec, "Converts the gp_Vec vector V into this vector.", py::arg("V"));
cls_Geom_VectorWithMagnitude.def("SetX", (void (Geom_VectorWithMagnitude::*)(const Standard_Real)) &Geom_VectorWithMagnitude::SetX, "Changes the X coordinate of <me>.", py::arg("X"));
cls_Geom_VectorWithMagnitude.def("SetY", (void (Geom_VectorWithMagnitude::*)(const Standard_Real)) &Geom_VectorWithMagnitude::SetY, "Changes the Y coordinate of <me>", py::arg("Y"));
cls_Geom_VectorWithMagnitude.def("SetZ", (void (Geom_VectorWithMagnitude::*)(const Standard_Real)) &Geom_VectorWithMagnitude::SetZ, "Changes the Z coordinate of <me>.", py::arg("Z"));
cls_Geom_VectorWithMagnitude.def("Magnitude", (Standard_Real (Geom_VectorWithMagnitude::*)() const) &Geom_VectorWithMagnitude::Magnitude, "Returns the magnitude of <me>.");
cls_Geom_VectorWithMagnitude.def("SquareMagnitude", (Standard_Real (Geom_VectorWithMagnitude::*)() const) &Geom_VectorWithMagnitude::SquareMagnitude, "Returns the square magnitude of <me>.");
cls_Geom_VectorWithMagnitude.def("Add", (void (Geom_VectorWithMagnitude::*)(const opencascade::handle<Geom_Vector> &)) &Geom_VectorWithMagnitude::Add, "Adds the Vector Other to <me>.", py::arg("Other"));
cls_Geom_VectorWithMagnitude.def("Added", (opencascade::handle<Geom_VectorWithMagnitude> (Geom_VectorWithMagnitude::*)(const opencascade::handle<Geom_Vector> &) const) &Geom_VectorWithMagnitude::Added, "Adds the vector Other to <me>.", py::arg("Other"));
cls_Geom_VectorWithMagnitude.def("Cross", (void (Geom_VectorWithMagnitude::*)(const opencascade::handle<Geom_Vector> &)) &Geom_VectorWithMagnitude::Cross, "Computes the cross product between <me> and Other <me> ^ Other.", py::arg("Other"));
cls_Geom_VectorWithMagnitude.def("Crossed", (opencascade::handle<Geom_Vector> (Geom_VectorWithMagnitude::*)(const opencascade::handle<Geom_Vector> &) const) &Geom_VectorWithMagnitude::Crossed, "Computes the cross product between <me> and Other <me> ^ Other. A new vector is returned.", py::arg("Other"));
cls_Geom_VectorWithMagnitude.def("CrossCross", (void (Geom_VectorWithMagnitude::*)(const opencascade::handle<Geom_Vector> &, const opencascade::handle<Geom_Vector> &)) &Geom_VectorWithMagnitude::CrossCross, "Computes the triple vector product <me> ^ (V1 ^ V2).", py::arg("V1"), py::arg("V2"));
cls_Geom_VectorWithMagnitude.def("CrossCrossed", (opencascade::handle<Geom_Vector> (Geom_VectorWithMagnitude::*)(const opencascade::handle<Geom_Vector> &, const opencascade::handle<Geom_Vector> &) const) &Geom_VectorWithMagnitude::CrossCrossed, "Computes the triple vector product <me> ^ (V1 ^ V2). A new vector is returned.", py::arg("V1"), py::arg("V2"));
cls_Geom_VectorWithMagnitude.def("Divide", (void (Geom_VectorWithMagnitude::*)(const Standard_Real)) &Geom_VectorWithMagnitude::Divide, "Divides <me> by a scalar.", py::arg("Scalar"));
cls_Geom_VectorWithMagnitude.def("Divided", (opencascade::handle<Geom_VectorWithMagnitude> (Geom_VectorWithMagnitude::*)(const Standard_Real) const) &Geom_VectorWithMagnitude::Divided, "Divides <me> by a scalar. A new vector is returned.", py::arg("Scalar"));
cls_Geom_VectorWithMagnitude.def("Multiplied", (opencascade::handle<Geom_VectorWithMagnitude> (Geom_VectorWithMagnitude::*)(const Standard_Real) const) &Geom_VectorWithMagnitude::Multiplied, "Computes the product of the vector <me> by a scalar. A new vector is returned.", py::arg("Scalar"));
cls_Geom_VectorWithMagnitude.def("Multiply", (void (Geom_VectorWithMagnitude::*)(const Standard_Real)) &Geom_VectorWithMagnitude::Multiply, "Computes the product of the vector <me> by a scalar.", py::arg("Scalar"));
cls_Geom_VectorWithMagnitude.def("Normalize", (void (Geom_VectorWithMagnitude::*)()) &Geom_VectorWithMagnitude::Normalize, "Normalizes <me>.");
cls_Geom_VectorWithMagnitude.def("Normalized", (opencascade::handle<Geom_VectorWithMagnitude> (Geom_VectorWithMagnitude::*)() const) &Geom_VectorWithMagnitude::Normalized, "Returns a copy of <me> Normalized.");
cls_Geom_VectorWithMagnitude.def("Subtract", (void (Geom_VectorWithMagnitude::*)(const opencascade::handle<Geom_Vector> &)) &Geom_VectorWithMagnitude::Subtract, "Subtracts the Vector Other to <me>.", py::arg("Other"));
cls_Geom_VectorWithMagnitude.def("Subtracted", (opencascade::handle<Geom_VectorWithMagnitude> (Geom_VectorWithMagnitude::*)(const opencascade::handle<Geom_Vector> &) const) &Geom_VectorWithMagnitude::Subtracted, "Subtracts the vector Other to <me>. A new vector is returned.", py::arg("Other"));
cls_Geom_VectorWithMagnitude.def("Transform", (void (Geom_VectorWithMagnitude::*)(const gp_Trsf &)) &Geom_VectorWithMagnitude::Transform, "Applies the transformation T to this vector.", py::arg("T"));
cls_Geom_VectorWithMagnitude.def("Copy", (opencascade::handle<Geom_Geometry> (Geom_VectorWithMagnitude::*)() const) &Geom_VectorWithMagnitude::Copy, "Creates a new object which is a copy of this vector.");
cls_Geom_VectorWithMagnitude.def_static("get_type_name_", (const char * (*)()) &Geom_VectorWithMagnitude::get_type_name, "None");
cls_Geom_VectorWithMagnitude.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Geom_VectorWithMagnitude::get_type_descriptor, "None");
cls_Geom_VectorWithMagnitude.def("DynamicType", (const opencascade::handle<Standard_Type> & (Geom_VectorWithMagnitude::*)() const) &Geom_VectorWithMagnitude::DynamicType, "None");

// Enums

}