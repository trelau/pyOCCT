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
#include <gp_Pnt.hxx>
#include <gp_Dir.hxx>
#include <gp_Ax1.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Ax2.hxx>
#include <gp_Trsf.hxx>
#include <gp_Vec.hxx>

void bind_gp_Ax2(py::module &mod){

py::class_<gp_Ax2, std::unique_ptr<gp_Ax2>> cls_gp_Ax2(mod, "gp_Ax2", "Describes a right-handed coordinate system in 3D space. A coordinate system is defined by: - its origin (also referred to as its 'Location point'), and - three orthogonal unit vectors, termed respectively the 'X Direction', the 'Y Direction' and the 'Direction' (also referred to as the 'main Direction'). The 'Direction' of the coordinate system is called its 'main Direction' because whenever this unit vector is modified, the 'X Direction' and the 'Y Direction' are recomputed. However, when we modify either the 'X Direction' or the 'Y Direction', 'Direction' is not modified. The 'main Direction' is also the 'Z Direction'. Since an Ax2 coordinate system is right-handed, its 'main Direction' is always equal to the cross product of its 'X Direction' and 'Y Direction'. (To define a left-handed coordinate system, use gp_Ax3.) A coordinate system is used: - to describe geometric entities, in particular to position them. The local coordinate system of a geometric entity serves the same purpose as the STEP function 'axis placement two axes', or - to define geometric transformations. Note: we refer to the 'X Axis', 'Y Axis' and 'Z Axis', respectively, as to axes having: - the origin of the coordinate system as their origin, and - the unit vectors 'X Direction', 'Y Direction' and 'main Direction', respectively, as their unit vectors. The 'Z Axis' is also the 'main Axis'.");

// Constructors
cls_gp_Ax2.def(py::init<>());
cls_gp_Ax2.def(py::init<const gp_Pnt &, const gp_Dir &, const gp_Dir &>(), py::arg("P"), py::arg("N"), py::arg("Vx"));
cls_gp_Ax2.def(py::init<const gp_Pnt &, const gp_Dir &>(), py::arg("P"), py::arg("V"));

// Fields

// Methods
// cls_gp_Ax2.def_static("operator new_", (void * (*)(size_t)) &gp_Ax2::operator new, "None", py::arg("theSize"));
// cls_gp_Ax2.def_static("operator delete_", (void (*)(void *)) &gp_Ax2::operator delete, "None", py::arg("theAddress"));
// cls_gp_Ax2.def_static("operator new[]_", (void * (*)(size_t)) &gp_Ax2::operator new[], "None", py::arg("theSize"));
// cls_gp_Ax2.def_static("operator delete[]_", (void (*)(void *)) &gp_Ax2::operator delete[], "None", py::arg("theAddress"));
// cls_gp_Ax2.def_static("operator new_", (void * (*)(size_t, void *)) &gp_Ax2::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gp_Ax2.def_static("operator delete_", (void (*)(void *, void *)) &gp_Ax2::operator delete, "None", py::arg(""), py::arg(""));
cls_gp_Ax2.def("SetAxis", (void (gp_Ax2::*)(const gp_Ax1 &)) &gp_Ax2::SetAxis, "Assigns the origin and 'main Direction' of the axis A1 to this coordinate system, then recomputes its 'X Direction' and 'Y Direction'. Note: The new 'X Direction' is computed as follows: new 'X Direction' = V1 ^(previous 'X Direction' ^ V) where V is the 'Direction' of A1. Exceptions Standard_ConstructionError if A1 is parallel to the 'X Direction' of this coordinate system.", py::arg("A1"));
cls_gp_Ax2.def("SetDirection", (void (gp_Ax2::*)(const gp_Dir &)) &gp_Ax2::SetDirection, "Changes the 'main Direction' of this coordinate system, then recomputes its 'X Direction' and 'Y Direction'. Note: the new 'X Direction' is computed as follows: new 'X Direction' = V ^ (previous 'X Direction' ^ V) Exceptions Standard_ConstructionError if V is parallel to the 'X Direction' of this coordinate system.", py::arg("V"));
cls_gp_Ax2.def("SetLocation", (void (gp_Ax2::*)(const gp_Pnt &)) &gp_Ax2::SetLocation, "Changes the 'Location' point (origin) of <me>.", py::arg("P"));
cls_gp_Ax2.def("SetXDirection", (void (gp_Ax2::*)(const gp_Dir &)) &gp_Ax2::SetXDirection, "Changes the 'Xdirection' of <me>. The main direction 'Direction' is not modified, the 'Ydirection' is modified. If <Vx> is not normal to the main direction then <XDirection> is computed as follows XDirection = Direction ^ (Vx ^ Direction). Exceptions Standard_ConstructionError if Vx or Vy is parallel to the 'main Direction' of this coordinate system.", py::arg("Vx"));
cls_gp_Ax2.def("SetYDirection", (void (gp_Ax2::*)(const gp_Dir &)) &gp_Ax2::SetYDirection, "Changes the 'Ydirection' of <me>. The main direction is not modified but the 'Xdirection' is changed. If <Vy> is not normal to the main direction then 'YDirection' is computed as follows YDirection = Direction ^ (<Vy> ^ Direction). Exceptions Standard_ConstructionError if Vx or Vy is parallel to the 'main Direction' of this coordinate system.", py::arg("Vy"));
cls_gp_Ax2.def("Angle", (Standard_Real (gp_Ax2::*)(const gp_Ax2 &) const) &gp_Ax2::Angle, "Computes the angular value, in radians, between the main direction of <me> and the main direction of <Other>. Returns the angle between 0 and PI in radians.", py::arg("Other"));
cls_gp_Ax2.def("Axis", (const gp_Ax1 & (gp_Ax2::*)() const) &gp_Ax2::Axis, "Returns the main axis of <me>. It is the 'Location' point and the main 'Direction'.");
cls_gp_Ax2.def("Direction", (const gp_Dir & (gp_Ax2::*)() const) &gp_Ax2::Direction, "Returns the main direction of <me>.");
cls_gp_Ax2.def("Location", (const gp_Pnt & (gp_Ax2::*)() const) &gp_Ax2::Location, "Returns the 'Location' point (origin) of <me>.");
cls_gp_Ax2.def("XDirection", (const gp_Dir & (gp_Ax2::*)() const) &gp_Ax2::XDirection, "Returns the 'XDirection' of <me>.");
cls_gp_Ax2.def("YDirection", (const gp_Dir & (gp_Ax2::*)() const) &gp_Ax2::YDirection, "Returns the 'YDirection' of <me>.");
cls_gp_Ax2.def("IsCoplanar", (Standard_Boolean (gp_Ax2::*)(const gp_Ax2 &, const Standard_Real, const Standard_Real) const) &gp_Ax2::IsCoplanar, "None", py::arg("Other"), py::arg("LinearTolerance"), py::arg("AngularTolerance"));
cls_gp_Ax2.def("IsCoplanar", (Standard_Boolean (gp_Ax2::*)(const gp_Ax1 &, const Standard_Real, const Standard_Real) const) &gp_Ax2::IsCoplanar, "Returns True if . the distance between <me> and the 'Location' point of A1 is lower of equal to LinearTolerance and . the main direction of <me> and the direction of A1 are normal. Note: the tolerance criterion for angular equality is given by AngularTolerance.", py::arg("A1"), py::arg("LinearTolerance"), py::arg("AngularTolerance"));
cls_gp_Ax2.def("Mirror", (void (gp_Ax2::*)(const gp_Pnt &)) &gp_Ax2::Mirror, "Performs a symmetrical transformation of this coordinate system with respect to: - the point P, and assigns the result to this coordinate system. Warning This transformation is always performed on the origin. In case of a reflection with respect to a point: - the main direction of the coordinate system is not changed, and - the 'X Direction' and the 'Y Direction' are simply reversed In case of a reflection with respect to an axis or a plane: - the transformation is applied to the 'X Direction' and the 'Y Direction', then - the 'main Direction' is recomputed as the cross product 'X Direction' ^ 'Y Direction'. This maintains the right-handed property of the coordinate system.", py::arg("P"));
cls_gp_Ax2.def("Mirrored", (gp_Ax2 (gp_Ax2::*)(const gp_Pnt &) const) &gp_Ax2::Mirrored, "Performs a symmetrical transformation of this coordinate system with respect to: - the point P, and creates a new one. Warning This transformation is always performed on the origin. In case of a reflection with respect to a point: - the main direction of the coordinate system is not changed, and - the 'X Direction' and the 'Y Direction' are simply reversed In case of a reflection with respect to an axis or a plane: - the transformation is applied to the 'X Direction' and the 'Y Direction', then - the 'main Direction' is recomputed as the cross product 'X Direction' ^ 'Y Direction'. This maintains the right-handed property of the coordinate system.", py::arg("P"));
cls_gp_Ax2.def("Mirror", (void (gp_Ax2::*)(const gp_Ax1 &)) &gp_Ax2::Mirror, "Performs a symmetrical transformation of this coordinate system with respect to: - the axis A1, and assigns the result to this coordinate systeme. Warning This transformation is always performed on the origin. In case of a reflection with respect to a point: - the main direction of the coordinate system is not changed, and - the 'X Direction' and the 'Y Direction' are simply reversed In case of a reflection with respect to an axis or a plane: - the transformation is applied to the 'X Direction' and the 'Y Direction', then - the 'main Direction' is recomputed as the cross product 'X Direction' ^ 'Y Direction'. This maintains the right-handed property of the coordinate system.", py::arg("A1"));
cls_gp_Ax2.def("Mirrored", (gp_Ax2 (gp_Ax2::*)(const gp_Ax1 &) const) &gp_Ax2::Mirrored, "Performs a symmetrical transformation of this coordinate system with respect to: - the axis A1, and creates a new one. Warning This transformation is always performed on the origin. In case of a reflection with respect to a point: - the main direction of the coordinate system is not changed, and - the 'X Direction' and the 'Y Direction' are simply reversed In case of a reflection with respect to an axis or a plane: - the transformation is applied to the 'X Direction' and the 'Y Direction', then - the 'main Direction' is recomputed as the cross product 'X Direction' ^ 'Y Direction'. This maintains the right-handed property of the coordinate system.", py::arg("A1"));
cls_gp_Ax2.def("Mirror", (void (gp_Ax2::*)(const gp_Ax2 &)) &gp_Ax2::Mirror, "Performs a symmetrical transformation of this coordinate system with respect to: - the plane defined by the origin, 'X Direction' and 'Y Direction' of coordinate system A2 and assigns the result to this coordinate systeme. Warning This transformation is always performed on the origin. In case of a reflection with respect to a point: - the main direction of the coordinate system is not changed, and - the 'X Direction' and the 'Y Direction' are simply reversed In case of a reflection with respect to an axis or a plane: - the transformation is applied to the 'X Direction' and the 'Y Direction', then - the 'main Direction' is recomputed as the cross product 'X Direction' ^ 'Y Direction'. This maintains the right-handed property of the coordinate system.", py::arg("A2"));
cls_gp_Ax2.def("Mirrored", (gp_Ax2 (gp_Ax2::*)(const gp_Ax2 &) const) &gp_Ax2::Mirrored, "Performs a symmetrical transformation of this coordinate system with respect to: - the plane defined by the origin, 'X Direction' and 'Y Direction' of coordinate system A2 and creates a new one. Warning This transformation is always performed on the origin. In case of a reflection with respect to a point: - the main direction of the coordinate system is not changed, and - the 'X Direction' and the 'Y Direction' are simply reversed In case of a reflection with respect to an axis or a plane: - the transformation is applied to the 'X Direction' and the 'Y Direction', then - the 'main Direction' is recomputed as the cross product 'X Direction' ^ 'Y Direction'. This maintains the right-handed property of the coordinate system.", py::arg("A2"));
cls_gp_Ax2.def("Rotate", (void (gp_Ax2::*)(const gp_Ax1 &, const Standard_Real)) &gp_Ax2::Rotate, "None", py::arg("A1"), py::arg("Ang"));
cls_gp_Ax2.def("Rotated", (gp_Ax2 (gp_Ax2::*)(const gp_Ax1 &, const Standard_Real) const) &gp_Ax2::Rotated, "Rotates an axis placement. <A1> is the axis of the rotation . Ang is the angular value of the rotation in radians.", py::arg("A1"), py::arg("Ang"));
cls_gp_Ax2.def("Scale", (void (gp_Ax2::*)(const gp_Pnt &, const Standard_Real)) &gp_Ax2::Scale, "None", py::arg("P"), py::arg("S"));
cls_gp_Ax2.def("Scaled", (gp_Ax2 (gp_Ax2::*)(const gp_Pnt &, const Standard_Real) const) &gp_Ax2::Scaled, "Applies a scaling transformation on the axis placement. The 'Location' point of the axisplacement is modified. Warnings : If the scale <S> is negative : . the main direction of the axis placement is not changed. . The 'XDirection' and the 'YDirection' are reversed. So the axis placement stay right handed.", py::arg("P"), py::arg("S"));
cls_gp_Ax2.def("Transform", (void (gp_Ax2::*)(const gp_Trsf &)) &gp_Ax2::Transform, "None", py::arg("T"));
cls_gp_Ax2.def("Transformed", (gp_Ax2 (gp_Ax2::*)(const gp_Trsf &) const) &gp_Ax2::Transformed, "Transforms an axis placement with a Trsf. The 'Location' point, the 'XDirection' and the 'YDirection' are transformed with T. The resulting main 'Direction' of <me> is the cross product between the 'XDirection' and the 'YDirection' after transformation.", py::arg("T"));
cls_gp_Ax2.def("Translate", (void (gp_Ax2::*)(const gp_Vec &)) &gp_Ax2::Translate, "None", py::arg("V"));
cls_gp_Ax2.def("Translated", (gp_Ax2 (gp_Ax2::*)(const gp_Vec &) const) &gp_Ax2::Translated, "Translates an axis plaxement in the direction of the vector <V>. The magnitude of the translation is the vector's magnitude.", py::arg("V"));
cls_gp_Ax2.def("Translate", (void (gp_Ax2::*)(const gp_Pnt &, const gp_Pnt &)) &gp_Ax2::Translate, "None", py::arg("P1"), py::arg("P2"));
cls_gp_Ax2.def("Translated", (gp_Ax2 (gp_Ax2::*)(const gp_Pnt &, const gp_Pnt &) const) &gp_Ax2::Translated, "Translates an axis placement from the point <P1> to the point <P2>.", py::arg("P1"), py::arg("P2"));

// Enums

}