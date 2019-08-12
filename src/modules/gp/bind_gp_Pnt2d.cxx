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
#include <Standard.hxx>
#include <gp_XY.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Ax2d.hxx>
#include <gp_Trsf2d.hxx>
#include <gp_Vec2d.hxx>

void bind_gp_Pnt2d(py::module &mod){

py::class_<gp_Pnt2d, std::unique_ptr<gp_Pnt2d, Deleter<gp_Pnt2d>>> cls_gp_Pnt2d(mod, "gp_Pnt2d", "Defines a non-persistent 2D cartesian point.");

// Constructors
cls_gp_Pnt2d.def(py::init<>());
cls_gp_Pnt2d.def(py::init<const gp_XY &>(), py::arg("Coord"));
cls_gp_Pnt2d.def(py::init<const Standard_Real, const Standard_Real>(), py::arg("Xp"), py::arg("Yp"));

// Fields

// Methods
// cls_gp_Pnt2d.def_static("operator new_", (void * (*)(size_t)) &gp_Pnt2d::operator new, "None", py::arg("theSize"));
// cls_gp_Pnt2d.def_static("operator delete_", (void (*)(void *)) &gp_Pnt2d::operator delete, "None", py::arg("theAddress"));
// cls_gp_Pnt2d.def_static("operator new[]_", (void * (*)(size_t)) &gp_Pnt2d::operator new[], "None", py::arg("theSize"));
// cls_gp_Pnt2d.def_static("operator delete[]_", (void (*)(void *)) &gp_Pnt2d::operator delete[], "None", py::arg("theAddress"));
// cls_gp_Pnt2d.def_static("operator new_", (void * (*)(size_t, void *)) &gp_Pnt2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gp_Pnt2d.def_static("operator delete_", (void (*)(void *, void *)) &gp_Pnt2d::operator delete, "None", py::arg(""), py::arg(""));
cls_gp_Pnt2d.def("SetCoord", (void (gp_Pnt2d::*)(const Standard_Integer, const Standard_Real)) &gp_Pnt2d::SetCoord, "Assigns the value Xi to the coordinate that corresponds to Index: Index = 1 => X is modified Index = 2 => Y is modified Raises OutOfRange if Index != {1, 2}.", py::arg("Index"), py::arg("Xi"));
cls_gp_Pnt2d.def("SetCoord", (void (gp_Pnt2d::*)(const Standard_Real, const Standard_Real)) &gp_Pnt2d::SetCoord, "For this point, assigns the values Xp and Yp to its two coordinates", py::arg("Xp"), py::arg("Yp"));
cls_gp_Pnt2d.def("SetX", (void (gp_Pnt2d::*)(const Standard_Real)) &gp_Pnt2d::SetX, "Assigns the given value to the X coordinate of this point.", py::arg("X"));
cls_gp_Pnt2d.def("SetY", (void (gp_Pnt2d::*)(const Standard_Real)) &gp_Pnt2d::SetY, "Assigns the given value to the Y coordinate of this point.", py::arg("Y"));
cls_gp_Pnt2d.def("SetXY", (void (gp_Pnt2d::*)(const gp_XY &)) &gp_Pnt2d::SetXY, "Assigns the two coordinates of Coord to this point.", py::arg("Coord"));
cls_gp_Pnt2d.def("Coord", (Standard_Real (gp_Pnt2d::*)(const Standard_Integer) const) &gp_Pnt2d::Coord, "Returns the coordinate of range Index : Index = 1 => X is returned Index = 2 => Y is returned Raises OutOfRange if Index != {1, 2}.", py::arg("Index"));
cls_gp_Pnt2d.def("Coord", [](gp_Pnt2d &self, Standard_Real & Xp, Standard_Real & Yp){ self.Coord(Xp, Yp); return std::tuple<Standard_Real &, Standard_Real &>(Xp, Yp); }, "For this point returns its two coordinates as a number pair.", py::arg("Xp"), py::arg("Yp"));
cls_gp_Pnt2d.def("X", (Standard_Real (gp_Pnt2d::*)() const) &gp_Pnt2d::X, "For this point, returns its X coordinate.");
cls_gp_Pnt2d.def("Y", (Standard_Real (gp_Pnt2d::*)() const) &gp_Pnt2d::Y, "For this point, returns its Y coordinate.");
cls_gp_Pnt2d.def("XY", (const gp_XY & (gp_Pnt2d::*)() const) &gp_Pnt2d::XY, "For this point, returns its two coordinates as a number pair.");
cls_gp_Pnt2d.def("Coord", (const gp_XY & (gp_Pnt2d::*)() const) &gp_Pnt2d::Coord, "For this point, returns its two coordinates as a number pair.");
cls_gp_Pnt2d.def("ChangeCoord", (gp_XY & (gp_Pnt2d::*)()) &gp_Pnt2d::ChangeCoord, "Returns the coordinates of this point. Note: This syntax allows direct modification of the returned value.");
cls_gp_Pnt2d.def("IsEqual", (Standard_Boolean (gp_Pnt2d::*)(const gp_Pnt2d &, const Standard_Real) const) &gp_Pnt2d::IsEqual, "Comparison Returns True if the distance between the two points is lower or equal to LinearTolerance.", py::arg("Other"), py::arg("LinearTolerance"));
cls_gp_Pnt2d.def("Distance", (Standard_Real (gp_Pnt2d::*)(const gp_Pnt2d &) const) &gp_Pnt2d::Distance, "Computes the distance between two points.", py::arg("Other"));
cls_gp_Pnt2d.def("SquareDistance", (Standard_Real (gp_Pnt2d::*)(const gp_Pnt2d &) const) &gp_Pnt2d::SquareDistance, "Computes the square distance between two points.", py::arg("Other"));
cls_gp_Pnt2d.def("Mirror", (void (gp_Pnt2d::*)(const gp_Pnt2d &)) &gp_Pnt2d::Mirror, "Performs the symmetrical transformation of a point with respect to the point P which is the center of the symmetry.", py::arg("P"));
cls_gp_Pnt2d.def("Mirrored", (gp_Pnt2d (gp_Pnt2d::*)(const gp_Pnt2d &) const) &gp_Pnt2d::Mirrored, "Performs the symmetrical transformation of a point with respect to an axis placement which is the axis", py::arg("P"));
cls_gp_Pnt2d.def("Mirror", (void (gp_Pnt2d::*)(const gp_Ax2d &)) &gp_Pnt2d::Mirror, "None", py::arg("A"));
cls_gp_Pnt2d.def("Mirrored", (gp_Pnt2d (gp_Pnt2d::*)(const gp_Ax2d &) const) &gp_Pnt2d::Mirrored, "Rotates a point. A1 is the axis of the rotation. Ang is the angular value of the rotation in radians.", py::arg("A"));
cls_gp_Pnt2d.def("Rotate", (void (gp_Pnt2d::*)(const gp_Pnt2d &, const Standard_Real)) &gp_Pnt2d::Rotate, "None", py::arg("P"), py::arg("Ang"));
cls_gp_Pnt2d.def("Rotated", (gp_Pnt2d (gp_Pnt2d::*)(const gp_Pnt2d &, const Standard_Real) const) &gp_Pnt2d::Rotated, "Scales a point. S is the scaling value.", py::arg("P"), py::arg("Ang"));
cls_gp_Pnt2d.def("Scale", (void (gp_Pnt2d::*)(const gp_Pnt2d &, const Standard_Real)) &gp_Pnt2d::Scale, "None", py::arg("P"), py::arg("S"));
cls_gp_Pnt2d.def("Scaled", (gp_Pnt2d (gp_Pnt2d::*)(const gp_Pnt2d &, const Standard_Real) const) &gp_Pnt2d::Scaled, "Transforms a point with the transformation T.", py::arg("P"), py::arg("S"));
cls_gp_Pnt2d.def("Transform", (void (gp_Pnt2d::*)(const gp_Trsf2d &)) &gp_Pnt2d::Transform, "None", py::arg("T"));
cls_gp_Pnt2d.def("Transformed", (gp_Pnt2d (gp_Pnt2d::*)(const gp_Trsf2d &) const) &gp_Pnt2d::Transformed, "Translates a point in the direction of the vector V. The magnitude of the translation is the vector's magnitude.", py::arg("T"));
cls_gp_Pnt2d.def("Translate", (void (gp_Pnt2d::*)(const gp_Vec2d &)) &gp_Pnt2d::Translate, "None", py::arg("V"));
cls_gp_Pnt2d.def("Translated", (gp_Pnt2d (gp_Pnt2d::*)(const gp_Vec2d &) const) &gp_Pnt2d::Translated, "Translates a point from the point P1 to the point P2.", py::arg("V"));
cls_gp_Pnt2d.def("Translate", (void (gp_Pnt2d::*)(const gp_Pnt2d &, const gp_Pnt2d &)) &gp_Pnt2d::Translate, "None", py::arg("P1"), py::arg("P2"));
cls_gp_Pnt2d.def("Translated", (gp_Pnt2d (gp_Pnt2d::*)(const gp_Pnt2d &, const gp_Pnt2d &) const) &gp_Pnt2d::Translated, "None", py::arg("P1"), py::arg("P2"));

// Enums

}