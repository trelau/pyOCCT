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
#include <gp_Ax3.hxx>
#include <gp_Pnt.hxx>
#include <gp_Dir.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Ax1.hxx>
#include <gp_Lin.hxx>
#include <gp_Pln.hxx>
#include <gp_Ax2.hxx>
#include <gp_Trsf.hxx>
#include <gp_Vec.hxx>

void bind_gp_Pln(py::module &mod){

py::class_<gp_Pln, std::unique_ptr<gp_Pln>> cls_gp_Pln(mod, "gp_Pln", "Describes a plane. A plane is positioned in space with a coordinate system (a gp_Ax3 object), such that the plane is defined by the origin, 'X Direction' and 'Y Direction' of this coordinate system, which is the 'local coordinate system' of the plane. The 'main Direction' of the coordinate system is a vector normal to the plane. It gives the plane an implicit orientation such that the plane is said to be 'direct', if the coordinate system is right-handed, or 'indirect' in the other case. Note: when a gp_Pln plane is converted into a Geom_Plane plane, some implicit properties of its local coordinate system are used explicitly: - its origin defines the origin of the two parameters of the planar surface, - its implicit orientation is also that of the Geom_Plane. See Also gce_MakePln which provides functions for more complex plane constructions Geom_Plane which provides additional functions for constructing planes and works, in particular, with the parametric equations of planes");

// Constructors
cls_gp_Pln.def(py::init<>());
cls_gp_Pln.def(py::init<const gp_Ax3 &>(), py::arg("A3"));
cls_gp_Pln.def(py::init<const gp_Pnt &, const gp_Dir &>(), py::arg("P"), py::arg("V"));
cls_gp_Pln.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("A"), py::arg("B"), py::arg("C"), py::arg("D"));

// Fields

// Methods
// cls_gp_Pln.def_static("operator new_", (void * (*)(size_t)) &gp_Pln::operator new, "None", py::arg("theSize"));
// cls_gp_Pln.def_static("operator delete_", (void (*)(void *)) &gp_Pln::operator delete, "None", py::arg("theAddress"));
// cls_gp_Pln.def_static("operator new[]_", (void * (*)(size_t)) &gp_Pln::operator new[], "None", py::arg("theSize"));
// cls_gp_Pln.def_static("operator delete[]_", (void (*)(void *)) &gp_Pln::operator delete[], "None", py::arg("theAddress"));
// cls_gp_Pln.def_static("operator new_", (void * (*)(size_t, void *)) &gp_Pln::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gp_Pln.def_static("operator delete_", (void (*)(void *, void *)) &gp_Pln::operator delete, "None", py::arg(""), py::arg(""));
cls_gp_Pln.def("Coefficients", [](gp_Pln &self, Standard_Real & A, Standard_Real & B, Standard_Real & C, Standard_Real & D){ self.Coefficients(A, B, C, D); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(A, B, C, D); }, "Returns the coefficients of the plane's cartesian equation : A * X + B * Y + C * Z + D = 0.", py::arg("A"), py::arg("B"), py::arg("C"), py::arg("D"));
cls_gp_Pln.def("SetAxis", (void (gp_Pln::*)(const gp_Ax1 &)) &gp_Pln::SetAxis, "Modifies this plane, by redefining its local coordinate system so that - its origin and 'main Direction' become those of the axis A1 (the 'X Direction' and 'Y Direction' are then recomputed). Raises ConstructionError if the A1 is parallel to the 'XAxis' of the plane.", py::arg("A1"));
cls_gp_Pln.def("SetLocation", (void (gp_Pln::*)(const gp_Pnt &)) &gp_Pln::SetLocation, "Changes the origin of the plane.", py::arg("Loc"));
cls_gp_Pln.def("SetPosition", (void (gp_Pln::*)(const gp_Ax3 &)) &gp_Pln::SetPosition, "Changes the local coordinate system of the plane.", py::arg("A3"));
cls_gp_Pln.def("UReverse", (void (gp_Pln::*)()) &gp_Pln::UReverse, "Reverses the U parametrization of the plane reversing the XAxis.");
cls_gp_Pln.def("VReverse", (void (gp_Pln::*)()) &gp_Pln::VReverse, "Reverses the V parametrization of the plane reversing the YAxis.");
cls_gp_Pln.def("Direct", (Standard_Boolean (gp_Pln::*)() const) &gp_Pln::Direct, "returns true if the Ax3 is right handed.");
cls_gp_Pln.def("Axis", (const gp_Ax1 & (gp_Pln::*)() const) &gp_Pln::Axis, "Returns the plane's normal Axis.");
cls_gp_Pln.def("Location", (const gp_Pnt & (gp_Pln::*)() const) &gp_Pln::Location, "Returns the plane's location (origin).");
cls_gp_Pln.def("Position", (const gp_Ax3 & (gp_Pln::*)() const) &gp_Pln::Position, "Returns the local coordinate system of the plane .");
cls_gp_Pln.def("Distance", (Standard_Real (gp_Pln::*)(const gp_Pnt &) const) &gp_Pln::Distance, "Computes the distance between <me> and the point <P>.", py::arg("P"));
cls_gp_Pln.def("Distance", (Standard_Real (gp_Pln::*)(const gp_Lin &) const) &gp_Pln::Distance, "Computes the distance between <me> and the line <L>.", py::arg("L"));
cls_gp_Pln.def("Distance", (Standard_Real (gp_Pln::*)(const gp_Pln &) const) &gp_Pln::Distance, "Computes the distance between two planes.", py::arg("Other"));
cls_gp_Pln.def("SquareDistance", (Standard_Real (gp_Pln::*)(const gp_Pnt &) const) &gp_Pln::SquareDistance, "Computes the square distance between <me> and the point <P>.", py::arg("P"));
cls_gp_Pln.def("SquareDistance", (Standard_Real (gp_Pln::*)(const gp_Lin &) const) &gp_Pln::SquareDistance, "Computes the square distance between <me> and the line <L>.", py::arg("L"));
cls_gp_Pln.def("SquareDistance", (Standard_Real (gp_Pln::*)(const gp_Pln &) const) &gp_Pln::SquareDistance, "Computes the square distance between two planes.", py::arg("Other"));
cls_gp_Pln.def("XAxis", (gp_Ax1 (gp_Pln::*)() const) &gp_Pln::XAxis, "Returns the X axis of the plane.");
cls_gp_Pln.def("YAxis", (gp_Ax1 (gp_Pln::*)() const) &gp_Pln::YAxis, "Returns the Y axis of the plane.");
cls_gp_Pln.def("Contains", (Standard_Boolean (gp_Pln::*)(const gp_Pnt &, const Standard_Real) const) &gp_Pln::Contains, "Returns true if this plane contains the point P. This means that - the distance between point P and this plane is less than or equal to LinearTolerance, or - line L is normal to the 'main Axis' of the local coordinate system of this plane, within the tolerance AngularTolerance, and the distance between the origin of line L and this plane is less than or equal to LinearTolerance.", py::arg("P"), py::arg("LinearTolerance"));
cls_gp_Pln.def("Contains", (Standard_Boolean (gp_Pln::*)(const gp_Lin &, const Standard_Real, const Standard_Real) const) &gp_Pln::Contains, "Returns true if this plane contains the line L. This means that - the distance between point P and this plane is less than or equal to LinearTolerance, or - line L is normal to the 'main Axis' of the local coordinate system of this plane, within the tolerance AngularTolerance, and the distance between the origin of line L and this plane is less than or equal to LinearTolerance.", py::arg("L"), py::arg("LinearTolerance"), py::arg("AngularTolerance"));
cls_gp_Pln.def("Mirror", (void (gp_Pln::*)(const gp_Pnt &)) &gp_Pln::Mirror, "None", py::arg("P"));
cls_gp_Pln.def("Mirrored", (gp_Pln (gp_Pln::*)(const gp_Pnt &) const) &gp_Pln::Mirrored, "Performs the symmetrical transformation of a plane with respect to the point <P> which is the center of the symmetry Warnings : The normal direction to the plane is not changed. The 'XAxis' and the 'YAxis' are reversed.", py::arg("P"));
cls_gp_Pln.def("Mirror", (void (gp_Pln::*)(const gp_Ax1 &)) &gp_Pln::Mirror, "None", py::arg("A1"));
cls_gp_Pln.def("Mirrored", (gp_Pln (gp_Pln::*)(const gp_Ax1 &) const) &gp_Pln::Mirrored, "Performs the symmetrical transformation of a plane with respect to an axis placement which is the axis of the symmetry. The transformation is performed on the 'Location' point, on the 'XAxis' and the 'YAxis'. The resulting normal direction is the cross product between the 'XDirection' and the 'YDirection' after transformation if the initial plane was right handed, else it is the opposite.", py::arg("A1"));
cls_gp_Pln.def("Mirror", (void (gp_Pln::*)(const gp_Ax2 &)) &gp_Pln::Mirror, "None", py::arg("A2"));
cls_gp_Pln.def("Mirrored", (gp_Pln (gp_Pln::*)(const gp_Ax2 &) const) &gp_Pln::Mirrored, "Performs the symmetrical transformation of a plane with respect to an axis placement. The axis placement <A2> locates the plane of the symmetry. The transformation is performed on the 'Location' point, on the 'XAxis' and the 'YAxis'. The resulting normal direction is the cross product between the 'XDirection' and the 'YDirection' after transformation if the initial plane was right handed, else it is the opposite.", py::arg("A2"));
cls_gp_Pln.def("Rotate", (void (gp_Pln::*)(const gp_Ax1 &, const Standard_Real)) &gp_Pln::Rotate, "None", py::arg("A1"), py::arg("Ang"));
cls_gp_Pln.def("Rotated", (gp_Pln (gp_Pln::*)(const gp_Ax1 &, const Standard_Real) const) &gp_Pln::Rotated, "rotates a plane. A1 is the axis of the rotation. Ang is the angular value of the rotation in radians.", py::arg("A1"), py::arg("Ang"));
cls_gp_Pln.def("Scale", (void (gp_Pln::*)(const gp_Pnt &, const Standard_Real)) &gp_Pln::Scale, "None", py::arg("P"), py::arg("S"));
cls_gp_Pln.def("Scaled", (gp_Pln (gp_Pln::*)(const gp_Pnt &, const Standard_Real) const) &gp_Pln::Scaled, "Scales a plane. S is the scaling value.", py::arg("P"), py::arg("S"));
cls_gp_Pln.def("Transform", (void (gp_Pln::*)(const gp_Trsf &)) &gp_Pln::Transform, "None", py::arg("T"));
cls_gp_Pln.def("Transformed", (gp_Pln (gp_Pln::*)(const gp_Trsf &) const) &gp_Pln::Transformed, "Transforms a plane with the transformation T from class Trsf. The transformation is performed on the 'Location' point, on the 'XAxis' and the 'YAxis'. The resulting normal direction is the cross product between the 'XDirection' and the 'YDirection' after transformation.", py::arg("T"));
cls_gp_Pln.def("Translate", (void (gp_Pln::*)(const gp_Vec &)) &gp_Pln::Translate, "None", py::arg("V"));
cls_gp_Pln.def("Translated", (gp_Pln (gp_Pln::*)(const gp_Vec &) const) &gp_Pln::Translated, "Translates a plane in the direction of the vector V. The magnitude of the translation is the vector's magnitude.", py::arg("V"));
cls_gp_Pln.def("Translate", (void (gp_Pln::*)(const gp_Pnt &, const gp_Pnt &)) &gp_Pln::Translate, "None", py::arg("P1"), py::arg("P2"));
cls_gp_Pln.def("Translated", (gp_Pln (gp_Pln::*)(const gp_Pnt &, const gp_Pnt &) const) &gp_Pln::Translated, "Translates a plane from the point P1 to the point P2.", py::arg("P1"), py::arg("P2"));

// Enums

}