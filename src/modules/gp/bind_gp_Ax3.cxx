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
#include <gp_Pnt.hxx>
#include <gp_Dir.hxx>
#include <gp_Ax1.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Ax3.hxx>
#include <gp_Trsf.hxx>
#include <gp_Vec.hxx>

void bind_gp_Ax3(py::module &mod){

py::class_<gp_Ax3> cls_gp_Ax3(mod, "gp_Ax3", "Describes a coordinate system in 3D space. Unlike a gp_Ax2 coordinate system, a gp_Ax3 can be right-handed ('direct sense') or left-handed ('indirect sense'). A coordinate system is defined by: - its origin (also referred to as its 'Location point'), and - three orthogonal unit vectors, termed the 'X Direction', the 'Y Direction' and the 'Direction' (also referred to as the 'main Direction'). The 'Direction' of the coordinate system is called its 'main Direction' because whenever this unit vector is modified, the 'X Direction' and the 'Y Direction' are recomputed. However, when we modify either the 'X Direction' or the 'Y Direction', 'Direction' is not modified. 'Direction' is also the 'Z Direction'. The 'main Direction' is always parallel to the cross product of its 'X Direction' and 'Y Direction'. If the coordinate system is right-handed, it satisfies the equation: 'main Direction' = 'X Direction' ^ 'Y Direction' and if it is left-handed, it satisfies the equation: 'main Direction' = -'X Direction' ^ 'Y Direction' A coordinate system is used: - to describe geometric entities, in particular to position them. The local coordinate system of a geometric entity serves the same purpose as the STEP function 'axis placement three axes', or - to define geometric transformations. Note: - We refer to the 'X Axis', 'Y Axis' and 'Z Axis', respectively, as the axes having: - the origin of the coordinate system as their origin, and - the unit vectors 'X Direction', 'Y Direction' and 'main Direction', respectively, as their unit vectors. - The 'Z Axis' is also the 'main Axis'. - gp_Ax2 is used to define a coordinate system that must be always right-handed.");

// Constructors
cls_gp_Ax3.def(py::init<>());
cls_gp_Ax3.def(py::init<const gp_Ax2 &>(), py::arg("A"));
cls_gp_Ax3.def(py::init<const gp_Pnt &, const gp_Dir &, const gp_Dir &>(), py::arg("P"), py::arg("N"), py::arg("Vx"));
cls_gp_Ax3.def(py::init<const gp_Pnt &, const gp_Dir &>(), py::arg("P"), py::arg("V"));

// Fields

// Methods
// cls_gp_Ax3.def_static("operator new_", (void * (*)(size_t)) &gp_Ax3::operator new, "None", py::arg("theSize"));
// cls_gp_Ax3.def_static("operator delete_", (void (*)(void *)) &gp_Ax3::operator delete, "None", py::arg("theAddress"));
// cls_gp_Ax3.def_static("operator new[]_", (void * (*)(size_t)) &gp_Ax3::operator new[], "None", py::arg("theSize"));
// cls_gp_Ax3.def_static("operator delete[]_", (void (*)(void *)) &gp_Ax3::operator delete[], "None", py::arg("theAddress"));
// cls_gp_Ax3.def_static("operator new_", (void * (*)(size_t, void *)) &gp_Ax3::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gp_Ax3.def_static("operator delete_", (void (*)(void *, void *)) &gp_Ax3::operator delete, "None", py::arg(""), py::arg(""));
cls_gp_Ax3.def("XReverse", (void (gp_Ax3::*)()) &gp_Ax3::XReverse, "Reverses the X direction of <me>.");
cls_gp_Ax3.def("YReverse", (void (gp_Ax3::*)()) &gp_Ax3::YReverse, "Reverses the Y direction of <me>.");
cls_gp_Ax3.def("ZReverse", (void (gp_Ax3::*)()) &gp_Ax3::ZReverse, "Reverses the Z direction of <me>.");
cls_gp_Ax3.def("SetAxis", (void (gp_Ax3::*)(const gp_Ax1 &)) &gp_Ax3::SetAxis, "Assigns the origin and 'main Direction' of the axis A1 to this coordinate system, then recomputes its 'X Direction' and 'Y Direction'. Note: - The new 'X Direction' is computed as follows: new 'X Direction' = V1 ^(previous 'X Direction' ^ V) where V is the 'Direction' of A1. - The orientation of this coordinate system (right-handed or left-handed) is not modified. Raises ConstructionError if the 'Direction' of <A1> and the 'XDirection' of <me> are parallel (same or opposite orientation) because it is impossible to calculate the new 'XDirection' and the new 'YDirection'.", py::arg("A1"));
cls_gp_Ax3.def("SetDirection", (void (gp_Ax3::*)(const gp_Dir &)) &gp_Ax3::SetDirection, "Changes the main direction of this coordinate system, then recomputes its 'X Direction' and 'Y Direction'. Note: - The new 'X Direction' is computed as follows: new 'X Direction' = V ^ (previous 'X Direction' ^ V). - The orientation of this coordinate system (left- or right-handed) is not modified. Raises ConstructionError if <V< and the previous 'XDirection' are parallel because it is impossible to calculate the new 'XDirection' and the new 'YDirection'.", py::arg("V"));
cls_gp_Ax3.def("SetLocation", (void (gp_Ax3::*)(const gp_Pnt &)) &gp_Ax3::SetLocation, "Changes the 'Location' point (origin) of <me>.", py::arg("P"));
cls_gp_Ax3.def("SetXDirection", (void (gp_Ax3::*)(const gp_Dir &)) &gp_Ax3::SetXDirection, "Changes the 'Xdirection' of <me>. The main direction 'Direction' is not modified, the 'Ydirection' is modified. If <Vx> is not normal to the main direction then <XDirection> is computed as follows XDirection = Direction ^ (Vx ^ Direction). Raises ConstructionError if <Vx> is parallel (same or opposite orientation) to the main direction of <me>", py::arg("Vx"));
cls_gp_Ax3.def("SetYDirection", (void (gp_Ax3::*)(const gp_Dir &)) &gp_Ax3::SetYDirection, "Changes the 'Ydirection' of <me>. The main direction is not modified but the 'Xdirection' is changed. If <Vy> is not normal to the main direction then 'YDirection' is computed as follows YDirection = Direction ^ (<Vy> ^ Direction). Raises ConstructionError if <Vy> is parallel to the main direction of <me>", py::arg("Vy"));
cls_gp_Ax3.def("Angle", (Standard_Real (gp_Ax3::*)(const gp_Ax3 &) const) &gp_Ax3::Angle, "Computes the angular value between the main direction of <me> and the main direction of <Other>. Returns the angle between 0 and PI in radians.", py::arg("Other"));
cls_gp_Ax3.def("Axis", (const gp_Ax1 & (gp_Ax3::*)() const) &gp_Ax3::Axis, "Returns the main axis of <me>. It is the 'Location' point and the main 'Direction'.");
cls_gp_Ax3.def("Ax2", (gp_Ax2 (gp_Ax3::*)() const) &gp_Ax3::Ax2, "Computes a right-handed coordinate system with the same 'X Direction' and 'Y Direction' as those of this coordinate system, then recomputes the 'main Direction'. If this coordinate system is right-handed, the result returned is the same coordinate system. If this coordinate system is left-handed, the result is reversed.");
cls_gp_Ax3.def("Direction", (const gp_Dir & (gp_Ax3::*)() const) &gp_Ax3::Direction, "Returns the main direction of <me>.");
cls_gp_Ax3.def("Location", (const gp_Pnt & (gp_Ax3::*)() const) &gp_Ax3::Location, "Returns the 'Location' point (origin) of <me>.");
cls_gp_Ax3.def("XDirection", (const gp_Dir & (gp_Ax3::*)() const) &gp_Ax3::XDirection, "Returns the 'XDirection' of <me>.");
cls_gp_Ax3.def("YDirection", (const gp_Dir & (gp_Ax3::*)() const) &gp_Ax3::YDirection, "Returns the 'YDirection' of <me>.");
cls_gp_Ax3.def("Direct", (Standard_Boolean (gp_Ax3::*)() const) &gp_Ax3::Direct, "Returns True if the coordinate system is right-handed. i.e. XDirection().Crossed(YDirection()).Dot(Direction()) > 0");
cls_gp_Ax3.def("IsCoplanar", (Standard_Boolean (gp_Ax3::*)(const gp_Ax3 &, const Standard_Real, const Standard_Real) const) &gp_Ax3::IsCoplanar, "Returns True if . the distance between the 'Location' point of <me> and <Other> is lower or equal to LinearTolerance and . the distance between the 'Location' point of <Other> and <me> is lower or equal to LinearTolerance and . the main direction of <me> and the main direction of <Other> are parallel (same or opposite orientation).", py::arg("Other"), py::arg("LinearTolerance"), py::arg("AngularTolerance"));
cls_gp_Ax3.def("IsCoplanar", (Standard_Boolean (gp_Ax3::*)(const gp_Ax1 &, const Standard_Real, const Standard_Real) const) &gp_Ax3::IsCoplanar, "Returns True if . the distance between <me> and the 'Location' point of A1 is lower of equal to LinearTolerance and . the distance between A1 and the 'Location' point of <me> is lower or equal to LinearTolerance and . the main direction of <me> and the direction of A1 are normal.", py::arg("A1"), py::arg("LinearTolerance"), py::arg("AngularTolerance"));
cls_gp_Ax3.def("Mirror", (void (gp_Ax3::*)(const gp_Pnt &)) &gp_Ax3::Mirror, "None", py::arg("P"));
cls_gp_Ax3.def("Mirrored", (gp_Ax3 (gp_Ax3::*)(const gp_Pnt &) const) &gp_Ax3::Mirrored, "Performs the symmetrical transformation of an axis placement with respect to the point P which is the center of the symmetry. Warnings : The main direction of the axis placement is not changed. The 'XDirection' and the 'YDirection' are reversed. So the axis placement stay right handed.", py::arg("P"));
cls_gp_Ax3.def("Mirror", (void (gp_Ax3::*)(const gp_Ax1 &)) &gp_Ax3::Mirror, "None", py::arg("A1"));
cls_gp_Ax3.def("Mirrored", (gp_Ax3 (gp_Ax3::*)(const gp_Ax1 &) const) &gp_Ax3::Mirrored, "Performs the symmetrical transformation of an axis placement with respect to an axis placement which is the axis of the symmetry. The transformation is performed on the 'Location' point, on the 'XDirection' and 'YDirection'. The resulting main 'Direction' is the cross product between the 'XDirection' and the 'YDirection' after transformation.", py::arg("A1"));
cls_gp_Ax3.def("Mirror", (void (gp_Ax3::*)(const gp_Ax2 &)) &gp_Ax3::Mirror, "None", py::arg("A2"));
cls_gp_Ax3.def("Mirrored", (gp_Ax3 (gp_Ax3::*)(const gp_Ax2 &) const) &gp_Ax3::Mirrored, "Performs the symmetrical transformation of an axis placement with respect to a plane. The axis placement <A2> locates the plane of the symmetry : (Location, XDirection, YDirection). The transformation is performed on the 'Location' point, on the 'XDirection' and 'YDirection'. The resulting main 'Direction' is the cross product between the 'XDirection' and the 'YDirection' after transformation.", py::arg("A2"));
cls_gp_Ax3.def("Rotate", (void (gp_Ax3::*)(const gp_Ax1 &, const Standard_Real)) &gp_Ax3::Rotate, "None", py::arg("A1"), py::arg("Ang"));
cls_gp_Ax3.def("Rotated", (gp_Ax3 (gp_Ax3::*)(const gp_Ax1 &, const Standard_Real) const) &gp_Ax3::Rotated, "Rotates an axis placement. <A1> is the axis of the rotation . Ang is the angular value of the rotation in radians.", py::arg("A1"), py::arg("Ang"));
cls_gp_Ax3.def("Scale", (void (gp_Ax3::*)(const gp_Pnt &, const Standard_Real)) &gp_Ax3::Scale, "None", py::arg("P"), py::arg("S"));
cls_gp_Ax3.def("Scaled", (gp_Ax3 (gp_Ax3::*)(const gp_Pnt &, const Standard_Real) const) &gp_Ax3::Scaled, "Applies a scaling transformation on the axis placement. The 'Location' point of the axisplacement is modified. Warnings : If the scale <S> is negative : . the main direction of the axis placement is not changed. . The 'XDirection' and the 'YDirection' are reversed. So the axis placement stay right handed.", py::arg("P"), py::arg("S"));
cls_gp_Ax3.def("Transform", (void (gp_Ax3::*)(const gp_Trsf &)) &gp_Ax3::Transform, "None", py::arg("T"));
cls_gp_Ax3.def("Transformed", (gp_Ax3 (gp_Ax3::*)(const gp_Trsf &) const) &gp_Ax3::Transformed, "Transforms an axis placement with a Trsf. The 'Location' point, the 'XDirection' and the 'YDirection' are transformed with T. The resulting main 'Direction' of <me> is the cross product between the 'XDirection' and the 'YDirection' after transformation.", py::arg("T"));
cls_gp_Ax3.def("Translate", (void (gp_Ax3::*)(const gp_Vec &)) &gp_Ax3::Translate, "None", py::arg("V"));
cls_gp_Ax3.def("Translated", (gp_Ax3 (gp_Ax3::*)(const gp_Vec &) const) &gp_Ax3::Translated, "Translates an axis plaxement in the direction of the vector <V>. The magnitude of the translation is the vector's magnitude.", py::arg("V"));
cls_gp_Ax3.def("Translate", (void (gp_Ax3::*)(const gp_Pnt &, const gp_Pnt &)) &gp_Ax3::Translate, "None", py::arg("P1"), py::arg("P2"));
cls_gp_Ax3.def("Translated", (gp_Ax3 (gp_Ax3::*)(const gp_Pnt &, const gp_Pnt &) const) &gp_Ax3::Translated, "Translates an axis placement from the point <P1> to the point <P2>.", py::arg("P1"), py::arg("P2"));

// Enums

}