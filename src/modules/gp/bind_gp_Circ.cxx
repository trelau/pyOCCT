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
#include <gp_Ax2.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Ax1.hxx>
#include <gp_Pnt.hxx>
#include <gp_Circ.hxx>
#include <gp_Trsf.hxx>
#include <gp_Vec.hxx>

void bind_gp_Circ(py::module &mod){

py::class_<gp_Circ, std::unique_ptr<gp_Circ, Deleter<gp_Circ>>> cls_gp_Circ(mod, "gp_Circ", "Describes a circle in 3D space. A circle is defined by its radius and positioned in space with a coordinate system (a gp_Ax2 object) as follows: - the origin of the coordinate system is the center of the circle, and - the origin, 'X Direction' and 'Y Direction' of the coordinate system define the plane of the circle. This positioning coordinate system is the 'local coordinate system' of the circle. Its 'main Direction' gives the normal vector to the plane of the circle. The 'main Axis' of the coordinate system is referred to as the 'Axis' of the circle. Note: when a gp_Circ circle is converted into a Geom_Circle circle, some implicit properties of the circle are used explicitly: - the 'main Direction' of the local coordinate system gives an implicit orientation to the circle (and defines its trigonometric sense), - this orientation corresponds to the direction in which parameter values increase, - the starting point for parameterization is that of the 'X Axis' of the local coordinate system (i.e. the 'X Axis' of the circle). See Also gce_MakeCirc which provides functions for more complex circle constructions Geom_Circle which provides additional functions for constructing circles and works, in particular, with the parametric equations of circles");

// Constructors
cls_gp_Circ.def(py::init<>());
cls_gp_Circ.def(py::init<const gp_Ax2 &, const Standard_Real>(), py::arg("A2"), py::arg("Radius"));

// Fields

// Methods
// cls_gp_Circ.def_static("operator new_", (void * (*)(size_t)) &gp_Circ::operator new, "None", py::arg("theSize"));
// cls_gp_Circ.def_static("operator delete_", (void (*)(void *)) &gp_Circ::operator delete, "None", py::arg("theAddress"));
// cls_gp_Circ.def_static("operator new[]_", (void * (*)(size_t)) &gp_Circ::operator new[], "None", py::arg("theSize"));
// cls_gp_Circ.def_static("operator delete[]_", (void (*)(void *)) &gp_Circ::operator delete[], "None", py::arg("theAddress"));
// cls_gp_Circ.def_static("operator new_", (void * (*)(size_t, void *)) &gp_Circ::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gp_Circ.def_static("operator delete_", (void (*)(void *, void *)) &gp_Circ::operator delete, "None", py::arg(""), py::arg(""));
cls_gp_Circ.def("SetAxis", (void (gp_Circ::*)(const gp_Ax1 &)) &gp_Circ::SetAxis, "Changes the main axis of the circle. It is the axis perpendicular to the plane of the circle. Raises ConstructionError if the direction of A1 is parallel to the 'XAxis' of the circle.", py::arg("A1"));
cls_gp_Circ.def("SetLocation", (void (gp_Circ::*)(const gp_Pnt &)) &gp_Circ::SetLocation, "Changes the 'Location' point (center) of the circle.", py::arg("P"));
cls_gp_Circ.def("SetPosition", (void (gp_Circ::*)(const gp_Ax2 &)) &gp_Circ::SetPosition, "Changes the position of the circle.", py::arg("A2"));
cls_gp_Circ.def("SetRadius", (void (gp_Circ::*)(const Standard_Real)) &gp_Circ::SetRadius, "Modifies the radius of this circle. Warning. This class does not prevent the creation of a circle where Radius is null. Exceptions Standard_ConstructionError if Radius is negative.", py::arg("Radius"));
cls_gp_Circ.def("Area", (Standard_Real (gp_Circ::*)() const) &gp_Circ::Area, "Computes the area of the circle.");
cls_gp_Circ.def("Axis", (const gp_Ax1 & (gp_Circ::*)() const) &gp_Circ::Axis, "Returns the main axis of the circle. It is the axis perpendicular to the plane of the circle, passing through the 'Location' point (center) of the circle.");
cls_gp_Circ.def("Length", (Standard_Real (gp_Circ::*)() const) &gp_Circ::Length, "Computes the circumference of the circle.");
cls_gp_Circ.def("Location", (const gp_Pnt & (gp_Circ::*)() const) &gp_Circ::Location, "Returns the center of the circle. It is the 'Location' point of the local coordinate system of the circle");
cls_gp_Circ.def("Position", (const gp_Ax2 & (gp_Circ::*)() const) &gp_Circ::Position, "Returns the position of the circle. It is the local coordinate system of the circle.");
cls_gp_Circ.def("Radius", (Standard_Real (gp_Circ::*)() const) &gp_Circ::Radius, "Returns the radius of this circle.");
cls_gp_Circ.def("XAxis", (gp_Ax1 (gp_Circ::*)() const) &gp_Circ::XAxis, "Returns the 'XAxis' of the circle. This axis is perpendicular to the axis of the conic. This axis and the 'Yaxis' define the plane of the conic.");
cls_gp_Circ.def("YAxis", (gp_Ax1 (gp_Circ::*)() const) &gp_Circ::YAxis, "Returns the 'YAxis' of the circle. This axis and the 'Xaxis' define the plane of the conic. The 'YAxis' is perpendicular to the 'Xaxis'.");
cls_gp_Circ.def("Distance", (Standard_Real (gp_Circ::*)(const gp_Pnt &) const) &gp_Circ::Distance, "Computes the minimum of distance between the point P and any point on the circumference of the circle.", py::arg("P"));
cls_gp_Circ.def("SquareDistance", (Standard_Real (gp_Circ::*)(const gp_Pnt &) const) &gp_Circ::SquareDistance, "Computes the square distance between <me> and the point P.", py::arg("P"));
cls_gp_Circ.def("Contains", (Standard_Boolean (gp_Circ::*)(const gp_Pnt &, const Standard_Real) const) &gp_Circ::Contains, "Returns True if the point P is on the circumference. The distance between <me> and <P> must be lower or equal to LinearTolerance.", py::arg("P"), py::arg("LinearTolerance"));
cls_gp_Circ.def("Mirror", (void (gp_Circ::*)(const gp_Pnt &)) &gp_Circ::Mirror, "None", py::arg("P"));
cls_gp_Circ.def("Mirrored", (gp_Circ (gp_Circ::*)(const gp_Pnt &) const) &gp_Circ::Mirrored, "Performs the symmetrical transformation of a circle with respect to the point P which is the center of the symmetry.", py::arg("P"));
cls_gp_Circ.def("Mirror", (void (gp_Circ::*)(const gp_Ax1 &)) &gp_Circ::Mirror, "None", py::arg("A1"));
cls_gp_Circ.def("Mirrored", (gp_Circ (gp_Circ::*)(const gp_Ax1 &) const) &gp_Circ::Mirrored, "Performs the symmetrical transformation of a circle with respect to an axis placement which is the axis of the symmetry.", py::arg("A1"));
cls_gp_Circ.def("Mirror", (void (gp_Circ::*)(const gp_Ax2 &)) &gp_Circ::Mirror, "None", py::arg("A2"));
cls_gp_Circ.def("Mirrored", (gp_Circ (gp_Circ::*)(const gp_Ax2 &) const) &gp_Circ::Mirrored, "Performs the symmetrical transformation of a circle with respect to a plane. The axis placement A2 locates the plane of the of the symmetry : (Location, XDirection, YDirection).", py::arg("A2"));
cls_gp_Circ.def("Rotate", (void (gp_Circ::*)(const gp_Ax1 &, const Standard_Real)) &gp_Circ::Rotate, "None", py::arg("A1"), py::arg("Ang"));
cls_gp_Circ.def("Rotated", (gp_Circ (gp_Circ::*)(const gp_Ax1 &, const Standard_Real) const) &gp_Circ::Rotated, "Rotates a circle. A1 is the axis of the rotation. Ang is the angular value of the rotation in radians.", py::arg("A1"), py::arg("Ang"));
cls_gp_Circ.def("Scale", (void (gp_Circ::*)(const gp_Pnt &, const Standard_Real)) &gp_Circ::Scale, "None", py::arg("P"), py::arg("S"));
cls_gp_Circ.def("Scaled", (gp_Circ (gp_Circ::*)(const gp_Pnt &, const Standard_Real) const) &gp_Circ::Scaled, "Scales a circle. S is the scaling value. Warnings : If S is negative the radius stay positive but the 'XAxis' and the 'YAxis' are reversed as for an ellipse.", py::arg("P"), py::arg("S"));
cls_gp_Circ.def("Transform", (void (gp_Circ::*)(const gp_Trsf &)) &gp_Circ::Transform, "None", py::arg("T"));
cls_gp_Circ.def("Transformed", (gp_Circ (gp_Circ::*)(const gp_Trsf &) const) &gp_Circ::Transformed, "Transforms a circle with the transformation T from class Trsf.", py::arg("T"));
cls_gp_Circ.def("Translate", (void (gp_Circ::*)(const gp_Vec &)) &gp_Circ::Translate, "None", py::arg("V"));
cls_gp_Circ.def("Translated", (gp_Circ (gp_Circ::*)(const gp_Vec &) const) &gp_Circ::Translated, "Translates a circle in the direction of the vector V. The magnitude of the translation is the vector's magnitude.", py::arg("V"));
cls_gp_Circ.def("Translate", (void (gp_Circ::*)(const gp_Pnt &, const gp_Pnt &)) &gp_Circ::Translate, "None", py::arg("P1"), py::arg("P2"));
cls_gp_Circ.def("Translated", (gp_Circ (gp_Circ::*)(const gp_Pnt &, const gp_Pnt &) const) &gp_Circ::Translated, "Translates a circle from the point P1 to the point P2.", py::arg("P1"), py::arg("P2"));

// Enums

}