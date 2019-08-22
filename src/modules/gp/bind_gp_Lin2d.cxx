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
#include <gp_Ax2d.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Dir2d.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Lin2d.hxx>
#include <gp_Trsf2d.hxx>
#include <gp_Vec2d.hxx>

void bind_gp_Lin2d(py::module &mod){

py::class_<gp_Lin2d> cls_gp_Lin2d(mod, "gp_Lin2d", "Describes a line in 2D space. A line is positioned in the plane with an axis (a gp_Ax2d object) which gives the line its origin and unit vector. A line and an axis are similar objects, thus, we can convert one into the other. A line provides direct access to the majority of the edit and query functions available on its positioning axis. In addition, however, a line has specific functions for computing distances and positions. See Also GccAna and Geom2dGcc packages which provide functions for constructing lines defined by geometric constraints gce_MakeLin2d which provides functions for more complex line constructions Geom2d_Line which provides additional functions for constructing lines and works, in particular, with the parametric equations of lines");

// Constructors
cls_gp_Lin2d.def(py::init<>());
cls_gp_Lin2d.def(py::init<const gp_Ax2d &>(), py::arg("A"));
cls_gp_Lin2d.def(py::init<const gp_Pnt2d &, const gp_Dir2d &>(), py::arg("P"), py::arg("V"));
cls_gp_Lin2d.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("A"), py::arg("B"), py::arg("C"));

// Fields

// Methods
// cls_gp_Lin2d.def_static("operator new_", (void * (*)(size_t)) &gp_Lin2d::operator new, "None", py::arg("theSize"));
// cls_gp_Lin2d.def_static("operator delete_", (void (*)(void *)) &gp_Lin2d::operator delete, "None", py::arg("theAddress"));
// cls_gp_Lin2d.def_static("operator new[]_", (void * (*)(size_t)) &gp_Lin2d::operator new[], "None", py::arg("theSize"));
// cls_gp_Lin2d.def_static("operator delete[]_", (void (*)(void *)) &gp_Lin2d::operator delete[], "None", py::arg("theAddress"));
// cls_gp_Lin2d.def_static("operator new_", (void * (*)(size_t, void *)) &gp_Lin2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gp_Lin2d.def_static("operator delete_", (void (*)(void *, void *)) &gp_Lin2d::operator delete, "None", py::arg(""), py::arg(""));
cls_gp_Lin2d.def("Reverse", (void (gp_Lin2d::*)()) &gp_Lin2d::Reverse, "None");
cls_gp_Lin2d.def("Reversed", (gp_Lin2d (gp_Lin2d::*)() const) &gp_Lin2d::Reversed, "Reverses the positioning axis of this line. Note: - Reverse assigns the result to this line, while - Reversed creates a new one.");
cls_gp_Lin2d.def("SetDirection", (void (gp_Lin2d::*)(const gp_Dir2d &)) &gp_Lin2d::SetDirection, "Changes the direction of the line.", py::arg("V"));
cls_gp_Lin2d.def("SetLocation", (void (gp_Lin2d::*)(const gp_Pnt2d &)) &gp_Lin2d::SetLocation, "Changes the origin of the line.", py::arg("P"));
cls_gp_Lin2d.def("SetPosition", (void (gp_Lin2d::*)(const gp_Ax2d &)) &gp_Lin2d::SetPosition, "Complete redefinition of the line. The 'Location' point of <A> is the origin of the line. The 'Direction' of <A> is the direction of the line.", py::arg("A"));
cls_gp_Lin2d.def("Coefficients", [](gp_Lin2d &self, Standard_Real & A, Standard_Real & B, Standard_Real & C){ self.Coefficients(A, B, C); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(A, B, C); }, "Returns the normalized coefficients of the line : A * X + B * Y + C = 0.", py::arg("A"), py::arg("B"), py::arg("C"));
cls_gp_Lin2d.def("Direction", (const gp_Dir2d & (gp_Lin2d::*)() const) &gp_Lin2d::Direction, "Returns the direction of the line.");
cls_gp_Lin2d.def("Location", (const gp_Pnt2d & (gp_Lin2d::*)() const) &gp_Lin2d::Location, "Returns the location point (origin) of the line.");
cls_gp_Lin2d.def("Position", (const gp_Ax2d & (gp_Lin2d::*)() const) &gp_Lin2d::Position, "Returns the axis placement one axis whith the same location and direction as <me>.");
cls_gp_Lin2d.def("Angle", (Standard_Real (gp_Lin2d::*)(const gp_Lin2d &) const) &gp_Lin2d::Angle, "Computes the angle between two lines in radians.", py::arg("Other"));
cls_gp_Lin2d.def("Contains", (Standard_Boolean (gp_Lin2d::*)(const gp_Pnt2d &, const Standard_Real) const) &gp_Lin2d::Contains, "Returns true if this line contains the point P, that is, if the distance between point P and this line is less than or equal to LinearTolerance.", py::arg("P"), py::arg("LinearTolerance"));
cls_gp_Lin2d.def("Distance", (Standard_Real (gp_Lin2d::*)(const gp_Pnt2d &) const) &gp_Lin2d::Distance, "Computes the distance between <me> and the point <P>.", py::arg("P"));
cls_gp_Lin2d.def("Distance", (Standard_Real (gp_Lin2d::*)(const gp_Lin2d &) const) &gp_Lin2d::Distance, "Computes the distance between two lines.", py::arg("Other"));
cls_gp_Lin2d.def("SquareDistance", (Standard_Real (gp_Lin2d::*)(const gp_Pnt2d &) const) &gp_Lin2d::SquareDistance, "Computes the square distance between <me> and the point <P>.", py::arg("P"));
cls_gp_Lin2d.def("SquareDistance", (Standard_Real (gp_Lin2d::*)(const gp_Lin2d &) const) &gp_Lin2d::SquareDistance, "Computes the square distance between two lines.", py::arg("Other"));
cls_gp_Lin2d.def("Normal", (gp_Lin2d (gp_Lin2d::*)(const gp_Pnt2d &) const) &gp_Lin2d::Normal, "Computes the line normal to the direction of <me>, passing through the point <P>.", py::arg("P"));
cls_gp_Lin2d.def("Mirror", (void (gp_Lin2d::*)(const gp_Pnt2d &)) &gp_Lin2d::Mirror, "None", py::arg("P"));
cls_gp_Lin2d.def("Mirrored", (gp_Lin2d (gp_Lin2d::*)(const gp_Pnt2d &) const) &gp_Lin2d::Mirrored, "Performs the symmetrical transformation of a line with respect to the point <P> which is the center of the symmetry", py::arg("P"));
cls_gp_Lin2d.def("Mirror", (void (gp_Lin2d::*)(const gp_Ax2d &)) &gp_Lin2d::Mirror, "None", py::arg("A"));
cls_gp_Lin2d.def("Mirrored", (gp_Lin2d (gp_Lin2d::*)(const gp_Ax2d &) const) &gp_Lin2d::Mirrored, "Performs the symmetrical transformation of a line with respect to an axis placement which is the axis of the symmetry.", py::arg("A"));
cls_gp_Lin2d.def("Rotate", (void (gp_Lin2d::*)(const gp_Pnt2d &, const Standard_Real)) &gp_Lin2d::Rotate, "None", py::arg("P"), py::arg("Ang"));
cls_gp_Lin2d.def("Rotated", (gp_Lin2d (gp_Lin2d::*)(const gp_Pnt2d &, const Standard_Real) const) &gp_Lin2d::Rotated, "Rotates a line. P is the center of the rotation. Ang is the angular value of the rotation in radians.", py::arg("P"), py::arg("Ang"));
cls_gp_Lin2d.def("Scale", (void (gp_Lin2d::*)(const gp_Pnt2d &, const Standard_Real)) &gp_Lin2d::Scale, "None", py::arg("P"), py::arg("S"));
cls_gp_Lin2d.def("Scaled", (gp_Lin2d (gp_Lin2d::*)(const gp_Pnt2d &, const Standard_Real) const) &gp_Lin2d::Scaled, "Scales a line. S is the scaling value. Only the origin of the line is modified.", py::arg("P"), py::arg("S"));
cls_gp_Lin2d.def("Transform", (void (gp_Lin2d::*)(const gp_Trsf2d &)) &gp_Lin2d::Transform, "None", py::arg("T"));
cls_gp_Lin2d.def("Transformed", (gp_Lin2d (gp_Lin2d::*)(const gp_Trsf2d &) const) &gp_Lin2d::Transformed, "Transforms a line with the transformation T from class Trsf2d.", py::arg("T"));
cls_gp_Lin2d.def("Translate", (void (gp_Lin2d::*)(const gp_Vec2d &)) &gp_Lin2d::Translate, "None", py::arg("V"));
cls_gp_Lin2d.def("Translated", (gp_Lin2d (gp_Lin2d::*)(const gp_Vec2d &) const) &gp_Lin2d::Translated, "Translates a line in the direction of the vector V. The magnitude of the translation is the vector's magnitude.", py::arg("V"));
cls_gp_Lin2d.def("Translate", (void (gp_Lin2d::*)(const gp_Pnt2d &, const gp_Pnt2d &)) &gp_Lin2d::Translate, "None", py::arg("P1"), py::arg("P2"));
cls_gp_Lin2d.def("Translated", (gp_Lin2d (gp_Lin2d::*)(const gp_Pnt2d &, const gp_Pnt2d &) const) &gp_Lin2d::Translated, "Translates a line from the point P1 to the point P2.", py::arg("P1"), py::arg("P2"));

// Enums

}