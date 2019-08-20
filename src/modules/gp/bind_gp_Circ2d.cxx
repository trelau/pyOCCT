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
#include <Standard_TypeDef.hxx>
#include <gp_Ax22d.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Circ2d.hxx>
#include <gp_Trsf2d.hxx>
#include <gp_Vec2d.hxx>

void bind_gp_Circ2d(py::module &mod){

py::class_<gp_Circ2d, std::unique_ptr<gp_Circ2d>> cls_gp_Circ2d(mod, "gp_Circ2d", "Describes a circle in the plane (2D space). A circle is defined by its radius and positioned in the plane with a coordinate system (a gp_Ax22d object) as follows: - the origin of the coordinate system is the center of the circle, and - the orientation (direct or indirect) of the coordinate system gives an implicit orientation to the circle (and defines its trigonometric sense). This positioning coordinate system is the 'local coordinate system' of the circle. Note: when a gp_Circ2d circle is converted into a Geom2d_Circle circle, some implicit properties of the circle are used explicitly: - the implicit orientation corresponds to the direction in which parameter values increase, - the starting point for parameterization is that of the 'X Axis' of the local coordinate system (i.e. the 'X Axis' of the circle). See Also GccAna and Geom2dGcc packages which provide functions for constructing circles defined by geometric constraints gce_MakeCirc2d which provides functions for more complex circle constructions Geom2d_Circle which provides additional functions for constructing circles and works, with the parametric equations of circles in particular gp_Ax22d");

// Constructors
cls_gp_Circ2d.def(py::init<>());
cls_gp_Circ2d.def(py::init<const gp_Ax2d &, const Standard_Real>(), py::arg("XAxis"), py::arg("Radius"));
cls_gp_Circ2d.def(py::init<const gp_Ax2d &, const Standard_Real, const Standard_Boolean>(), py::arg("XAxis"), py::arg("Radius"), py::arg("Sense"));
cls_gp_Circ2d.def(py::init<const gp_Ax22d &, const Standard_Real>(), py::arg("Axis"), py::arg("Radius"));

// Fields

// Methods
// cls_gp_Circ2d.def_static("operator new_", (void * (*)(size_t)) &gp_Circ2d::operator new, "None", py::arg("theSize"));
// cls_gp_Circ2d.def_static("operator delete_", (void (*)(void *)) &gp_Circ2d::operator delete, "None", py::arg("theAddress"));
// cls_gp_Circ2d.def_static("operator new[]_", (void * (*)(size_t)) &gp_Circ2d::operator new[], "None", py::arg("theSize"));
// cls_gp_Circ2d.def_static("operator delete[]_", (void (*)(void *)) &gp_Circ2d::operator delete[], "None", py::arg("theAddress"));
// cls_gp_Circ2d.def_static("operator new_", (void * (*)(size_t, void *)) &gp_Circ2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gp_Circ2d.def_static("operator delete_", (void (*)(void *, void *)) &gp_Circ2d::operator delete, "None", py::arg(""), py::arg(""));
cls_gp_Circ2d.def("SetLocation", (void (gp_Circ2d::*)(const gp_Pnt2d &)) &gp_Circ2d::SetLocation, "Changes the location point (center) of the circle.", py::arg("P"));
cls_gp_Circ2d.def("SetXAxis", (void (gp_Circ2d::*)(const gp_Ax2d &)) &gp_Circ2d::SetXAxis, "Changes the X axis of the circle.", py::arg("A"));
cls_gp_Circ2d.def("SetAxis", (void (gp_Circ2d::*)(const gp_Ax22d &)) &gp_Circ2d::SetAxis, "Changes the X axis of the circle.", py::arg("A"));
cls_gp_Circ2d.def("SetYAxis", (void (gp_Circ2d::*)(const gp_Ax2d &)) &gp_Circ2d::SetYAxis, "Changes the Y axis of the circle.", py::arg("A"));
cls_gp_Circ2d.def("SetRadius", (void (gp_Circ2d::*)(const Standard_Real)) &gp_Circ2d::SetRadius, "Modifies the radius of this circle. This class does not prevent the creation of a circle where Radius is null. Exceptions Standard_ConstructionError if Radius is negative.", py::arg("Radius"));
cls_gp_Circ2d.def("Area", (Standard_Real (gp_Circ2d::*)() const) &gp_Circ2d::Area, "Computes the area of the circle.");
cls_gp_Circ2d.def("Coefficients", [](gp_Circ2d &self, Standard_Real & A, Standard_Real & B, Standard_Real & C, Standard_Real & D, Standard_Real & E, Standard_Real & F){ self.Coefficients(A, B, C, D, E, F); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(A, B, C, D, E, F); }, "Returns the normalized coefficients from the implicit equation of the circle : A * (X**2) + B * (Y**2) + 2*C*(X*Y) + 2*D*X + 2*E*Y + F = 0.0", py::arg("A"), py::arg("B"), py::arg("C"), py::arg("D"), py::arg("E"), py::arg("F"));
cls_gp_Circ2d.def("Contains", (Standard_Boolean (gp_Circ2d::*)(const gp_Pnt2d &, const Standard_Real) const) &gp_Circ2d::Contains, "Does <me> contain P ? Returns True if the distance between P and any point on the circumference of the circle is lower of equal to <LinearTolerance>.", py::arg("P"), py::arg("LinearTolerance"));
cls_gp_Circ2d.def("Distance", (Standard_Real (gp_Circ2d::*)(const gp_Pnt2d &) const) &gp_Circ2d::Distance, "Computes the minimum of distance between the point P and any point on the circumference of the circle.", py::arg("P"));
cls_gp_Circ2d.def("SquareDistance", (Standard_Real (gp_Circ2d::*)(const gp_Pnt2d &) const) &gp_Circ2d::SquareDistance, "Computes the square distance between <me> and the point P.", py::arg("P"));
cls_gp_Circ2d.def("Length", (Standard_Real (gp_Circ2d::*)() const) &gp_Circ2d::Length, "computes the circumference of the circle.");
cls_gp_Circ2d.def("Location", (const gp_Pnt2d & (gp_Circ2d::*)() const) &gp_Circ2d::Location, "Returns the location point (center) of the circle.");
cls_gp_Circ2d.def("Radius", (Standard_Real (gp_Circ2d::*)() const) &gp_Circ2d::Radius, "Returns the radius value of the circle.");
cls_gp_Circ2d.def("Axis", (const gp_Ax22d & (gp_Circ2d::*)() const) &gp_Circ2d::Axis, "returns the position of the circle.");
cls_gp_Circ2d.def("Position", (const gp_Ax22d & (gp_Circ2d::*)() const) &gp_Circ2d::Position, "returns the position of the circle. Idem Axis(me).");
cls_gp_Circ2d.def("XAxis", (gp_Ax2d (gp_Circ2d::*)() const) &gp_Circ2d::XAxis, "returns the X axis of the circle.");
cls_gp_Circ2d.def("YAxis", (gp_Ax2d (gp_Circ2d::*)() const) &gp_Circ2d::YAxis, "Returns the Y axis of the circle. Reverses the direction of the circle.");
cls_gp_Circ2d.def("Reverse", (void (gp_Circ2d::*)()) &gp_Circ2d::Reverse, "Reverses the orientation of the local coordinate system of this circle (the 'Y Direction' is reversed) and therefore changes the implicit orientation of this circle. Reverse assigns the result to this circle,");
cls_gp_Circ2d.def("Reversed", (gp_Circ2d (gp_Circ2d::*)() const) &gp_Circ2d::Reversed, "Reverses the orientation of the local coordinate system of this circle (the 'Y Direction' is reversed) and therefore changes the implicit orientation of this circle. Reversed creates a new circle.");
cls_gp_Circ2d.def("IsDirect", (Standard_Boolean (gp_Circ2d::*)() const) &gp_Circ2d::IsDirect, "Returns true if the local coordinate system is direct and false in the other case.");
cls_gp_Circ2d.def("Mirror", (void (gp_Circ2d::*)(const gp_Pnt2d &)) &gp_Circ2d::Mirror, "None", py::arg("P"));
cls_gp_Circ2d.def("Mirrored", (gp_Circ2d (gp_Circ2d::*)(const gp_Pnt2d &) const) &gp_Circ2d::Mirrored, "Performs the symmetrical transformation of a circle with respect to the point P which is the center of the symmetry", py::arg("P"));
cls_gp_Circ2d.def("Mirror", (void (gp_Circ2d::*)(const gp_Ax2d &)) &gp_Circ2d::Mirror, "None", py::arg("A"));
cls_gp_Circ2d.def("Mirrored", (gp_Circ2d (gp_Circ2d::*)(const gp_Ax2d &) const) &gp_Circ2d::Mirrored, "Performs the symmetrical transformation of a circle with respect to an axis placement which is the axis of the symmetry.", py::arg("A"));
cls_gp_Circ2d.def("Rotate", (void (gp_Circ2d::*)(const gp_Pnt2d &, const Standard_Real)) &gp_Circ2d::Rotate, "None", py::arg("P"), py::arg("Ang"));
cls_gp_Circ2d.def("Rotated", (gp_Circ2d (gp_Circ2d::*)(const gp_Pnt2d &, const Standard_Real) const) &gp_Circ2d::Rotated, "Rotates a circle. P is the center of the rotation. Ang is the angular value of the rotation in radians.", py::arg("P"), py::arg("Ang"));
cls_gp_Circ2d.def("Scale", (void (gp_Circ2d::*)(const gp_Pnt2d &, const Standard_Real)) &gp_Circ2d::Scale, "None", py::arg("P"), py::arg("S"));
cls_gp_Circ2d.def("Scaled", (gp_Circ2d (gp_Circ2d::*)(const gp_Pnt2d &, const Standard_Real) const) &gp_Circ2d::Scaled, "Scales a circle. S is the scaling value. Warnings : If S is negative the radius stay positive but the 'XAxis' and the 'YAxis' are reversed as for an ellipse.", py::arg("P"), py::arg("S"));
cls_gp_Circ2d.def("Transform", (void (gp_Circ2d::*)(const gp_Trsf2d &)) &gp_Circ2d::Transform, "None", py::arg("T"));
cls_gp_Circ2d.def("Transformed", (gp_Circ2d (gp_Circ2d::*)(const gp_Trsf2d &) const) &gp_Circ2d::Transformed, "Transforms a circle with the transformation T from class Trsf2d.", py::arg("T"));
cls_gp_Circ2d.def("Translate", (void (gp_Circ2d::*)(const gp_Vec2d &)) &gp_Circ2d::Translate, "None", py::arg("V"));
cls_gp_Circ2d.def("Translated", (gp_Circ2d (gp_Circ2d::*)(const gp_Vec2d &) const) &gp_Circ2d::Translated, "Translates a circle in the direction of the vector V. The magnitude of the translation is the vector's magnitude.", py::arg("V"));
cls_gp_Circ2d.def("Translate", (void (gp_Circ2d::*)(const gp_Pnt2d &, const gp_Pnt2d &)) &gp_Circ2d::Translate, "None", py::arg("P1"), py::arg("P2"));
cls_gp_Circ2d.def("Translated", (gp_Circ2d (gp_Circ2d::*)(const gp_Pnt2d &, const gp_Pnt2d &) const) &gp_Circ2d::Translated, "Translates a circle from the point P1 to the point P2.", py::arg("P1"), py::arg("P2"));

// Enums

}