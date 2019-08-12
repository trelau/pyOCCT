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
#include <gp_Ax1.hxx>
#include <gp_Pnt.hxx>
#include <gp_Dir.hxx>
#include <gp_Lin.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Ax2.hxx>
#include <gp_Trsf.hxx>
#include <gp_Vec.hxx>

void bind_gp_Lin(py::module &mod){

py::class_<gp_Lin, std::unique_ptr<gp_Lin, Deleter<gp_Lin>>> cls_gp_Lin(mod, "gp_Lin", "Describes a line in 3D space. A line is positioned in space with an axis (a gp_Ax1 object) which gives it an origin and a unit vector. A line and an axis are similar objects, thus, we can convert one into the other. A line provides direct access to the majority of the edit and query functions available on its positioning axis. In addition, however, a line has specific functions for computing distances and positions. See Also gce_MakeLin which provides functions for more complex line constructions Geom_Line which provides additional functions for constructing lines and works, in particular, with the parametric equations of lines");

// Constructors
cls_gp_Lin.def(py::init<>());
cls_gp_Lin.def(py::init<const gp_Ax1 &>(), py::arg("A1"));
cls_gp_Lin.def(py::init<const gp_Pnt &, const gp_Dir &>(), py::arg("P"), py::arg("V"));

// Fields

// Methods
// cls_gp_Lin.def_static("operator new_", (void * (*)(size_t)) &gp_Lin::operator new, "None", py::arg("theSize"));
// cls_gp_Lin.def_static("operator delete_", (void (*)(void *)) &gp_Lin::operator delete, "None", py::arg("theAddress"));
// cls_gp_Lin.def_static("operator new[]_", (void * (*)(size_t)) &gp_Lin::operator new[], "None", py::arg("theSize"));
// cls_gp_Lin.def_static("operator delete[]_", (void (*)(void *)) &gp_Lin::operator delete[], "None", py::arg("theAddress"));
// cls_gp_Lin.def_static("operator new_", (void * (*)(size_t, void *)) &gp_Lin::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gp_Lin.def_static("operator delete_", (void (*)(void *, void *)) &gp_Lin::operator delete, "None", py::arg(""), py::arg(""));
cls_gp_Lin.def("Reverse", (void (gp_Lin::*)()) &gp_Lin::Reverse, "None");
cls_gp_Lin.def("Reversed", (gp_Lin (gp_Lin::*)() const) &gp_Lin::Reversed, "Reverses the direction of the line. Note: - Reverse assigns the result to this line, while - Reversed creates a new one.");
cls_gp_Lin.def("SetDirection", (void (gp_Lin::*)(const gp_Dir &)) &gp_Lin::SetDirection, "Changes the direction of the line.", py::arg("V"));
cls_gp_Lin.def("SetLocation", (void (gp_Lin::*)(const gp_Pnt &)) &gp_Lin::SetLocation, "Changes the location point (origin) of the line.", py::arg("P"));
cls_gp_Lin.def("SetPosition", (void (gp_Lin::*)(const gp_Ax1 &)) &gp_Lin::SetPosition, "Complete redefinition of the line. The 'Location' point of <A1> is the origin of the line. The 'Direction' of <A1> is the direction of the line.", py::arg("A1"));
cls_gp_Lin.def("Direction", (const gp_Dir & (gp_Lin::*)() const) &gp_Lin::Direction, "Returns the direction of the line.");
cls_gp_Lin.def("Location", (const gp_Pnt & (gp_Lin::*)() const) &gp_Lin::Location, "Returns the location point (origin) of the line.");
cls_gp_Lin.def("Position", (const gp_Ax1 & (gp_Lin::*)() const) &gp_Lin::Position, "Returns the axis placement one axis whith the same location and direction as <me>.");
cls_gp_Lin.def("Angle", (Standard_Real (gp_Lin::*)(const gp_Lin &) const) &gp_Lin::Angle, "Computes the angle between two lines in radians.", py::arg("Other"));
cls_gp_Lin.def("Contains", (Standard_Boolean (gp_Lin::*)(const gp_Pnt &, const Standard_Real) const) &gp_Lin::Contains, "Returns true if this line contains the point P, that is, if the distance between point P and this line is less than or equal to LinearTolerance..", py::arg("P"), py::arg("LinearTolerance"));
cls_gp_Lin.def("Distance", (Standard_Real (gp_Lin::*)(const gp_Pnt &) const) &gp_Lin::Distance, "Computes the distance between <me> and the point P.", py::arg("P"));
cls_gp_Lin.def("Distance", (Standard_Real (gp_Lin::*)(const gp_Lin &) const) &gp_Lin::Distance, "Computes the distance between two lines.", py::arg("Other"));
cls_gp_Lin.def("SquareDistance", (Standard_Real (gp_Lin::*)(const gp_Pnt &) const) &gp_Lin::SquareDistance, "Computes the square distance between <me> and the point P.", py::arg("P"));
cls_gp_Lin.def("SquareDistance", (Standard_Real (gp_Lin::*)(const gp_Lin &) const) &gp_Lin::SquareDistance, "Computes the square distance between two lines.", py::arg("Other"));
cls_gp_Lin.def("Normal", (gp_Lin (gp_Lin::*)(const gp_Pnt &) const) &gp_Lin::Normal, "Computes the line normal to the direction of <me>, passing through the point P. Raises ConstructionError if the distance between <me> and the point P is lower or equal to Resolution from gp because there is an infinity of solutions in 3D space.", py::arg("P"));
cls_gp_Lin.def("Mirror", (void (gp_Lin::*)(const gp_Pnt &)) &gp_Lin::Mirror, "None", py::arg("P"));
cls_gp_Lin.def("Mirrored", (gp_Lin (gp_Lin::*)(const gp_Pnt &) const) &gp_Lin::Mirrored, "Performs the symmetrical transformation of a line with respect to the point P which is the center of the symmetry.", py::arg("P"));
cls_gp_Lin.def("Mirror", (void (gp_Lin::*)(const gp_Ax1 &)) &gp_Lin::Mirror, "None", py::arg("A1"));
cls_gp_Lin.def("Mirrored", (gp_Lin (gp_Lin::*)(const gp_Ax1 &) const) &gp_Lin::Mirrored, "Performs the symmetrical transformation of a line with respect to an axis placement which is the axis of the symmetry.", py::arg("A1"));
cls_gp_Lin.def("Mirror", (void (gp_Lin::*)(const gp_Ax2 &)) &gp_Lin::Mirror, "None", py::arg("A2"));
cls_gp_Lin.def("Mirrored", (gp_Lin (gp_Lin::*)(const gp_Ax2 &) const) &gp_Lin::Mirrored, "Performs the symmetrical transformation of a line with respect to a plane. The axis placement <A2> locates the plane of the symmetry : (Location, XDirection, YDirection).", py::arg("A2"));
cls_gp_Lin.def("Rotate", (void (gp_Lin::*)(const gp_Ax1 &, const Standard_Real)) &gp_Lin::Rotate, "None", py::arg("A1"), py::arg("Ang"));
cls_gp_Lin.def("Rotated", (gp_Lin (gp_Lin::*)(const gp_Ax1 &, const Standard_Real) const) &gp_Lin::Rotated, "Rotates a line. A1 is the axis of the rotation. Ang is the angular value of the rotation in radians.", py::arg("A1"), py::arg("Ang"));
cls_gp_Lin.def("Scale", (void (gp_Lin::*)(const gp_Pnt &, const Standard_Real)) &gp_Lin::Scale, "None", py::arg("P"), py::arg("S"));
cls_gp_Lin.def("Scaled", (gp_Lin (gp_Lin::*)(const gp_Pnt &, const Standard_Real) const) &gp_Lin::Scaled, "Scales a line. S is the scaling value. The 'Location' point (origin) of the line is modified. The 'Direction' is reversed if the scale is negative.", py::arg("P"), py::arg("S"));
cls_gp_Lin.def("Transform", (void (gp_Lin::*)(const gp_Trsf &)) &gp_Lin::Transform, "None", py::arg("T"));
cls_gp_Lin.def("Transformed", (gp_Lin (gp_Lin::*)(const gp_Trsf &) const) &gp_Lin::Transformed, "Transforms a line with the transformation T from class Trsf.", py::arg("T"));
cls_gp_Lin.def("Translate", (void (gp_Lin::*)(const gp_Vec &)) &gp_Lin::Translate, "None", py::arg("V"));
cls_gp_Lin.def("Translated", (gp_Lin (gp_Lin::*)(const gp_Vec &) const) &gp_Lin::Translated, "Translates a line in the direction of the vector V. The magnitude of the translation is the vector's magnitude.", py::arg("V"));
cls_gp_Lin.def("Translate", (void (gp_Lin::*)(const gp_Pnt &, const gp_Pnt &)) &gp_Lin::Translate, "None", py::arg("P1"), py::arg("P2"));
cls_gp_Lin.def("Translated", (gp_Lin (gp_Lin::*)(const gp_Pnt &, const gp_Pnt &) const) &gp_Lin::Translated, "Translates a line from the point P1 to the point P2.", py::arg("P1"), py::arg("P2"));

// Enums

}