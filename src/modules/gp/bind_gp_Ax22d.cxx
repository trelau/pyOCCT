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
#include <gp_Pnt2d.hxx>
#include <gp_Dir2d.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Ax2d.hxx>
#include <gp_Ax22d.hxx>
#include <gp_Trsf2d.hxx>
#include <gp_Vec2d.hxx>

void bind_gp_Ax22d(py::module &mod){

py::class_<gp_Ax22d, std::unique_ptr<gp_Ax22d, Deleter<gp_Ax22d>>> cls_gp_Ax22d(mod, "gp_Ax22d", "Describes a coordinate system in a plane (2D space). A coordinate system is defined by: - its origin (also referred to as its 'Location point'), and - two orthogonal unit vectors, respectively, called the 'X Direction' and the 'Y Direction'. A gp_Ax22d may be right-handed ('direct sense') or left-handed ('inverse' or 'indirect sense'). You use a gp_Ax22d to: - describe 2D geometric entities, in particular to position them. The local coordinate system of a geometric entity serves for the same purpose as the STEP function 'axis placement two axes', or - define geometric transformations. Note: we refer to the 'X Axis' and 'Y Axis' as the axes having: - the origin of the coordinate system as their origin, and - the unit vectors 'X Direction' and 'Y Direction', respectively, as their unit vectors.");

// Constructors
cls_gp_Ax22d.def(py::init<>());
cls_gp_Ax22d.def(py::init<const gp_Pnt2d &, const gp_Dir2d &, const gp_Dir2d &>(), py::arg("P"), py::arg("Vx"), py::arg("Vy"));
cls_gp_Ax22d.def(py::init<const gp_Pnt2d &, const gp_Dir2d &>(), py::arg("P"), py::arg("V"));
cls_gp_Ax22d.def(py::init<const gp_Pnt2d &, const gp_Dir2d &, const Standard_Boolean>(), py::arg("P"), py::arg("V"), py::arg("Sense"));
cls_gp_Ax22d.def(py::init<const gp_Ax2d &>(), py::arg("A"));
cls_gp_Ax22d.def(py::init<const gp_Ax2d &, const Standard_Boolean>(), py::arg("A"), py::arg("Sense"));

// Fields

// Methods
// cls_gp_Ax22d.def_static("operator new_", (void * (*)(size_t)) &gp_Ax22d::operator new, "None", py::arg("theSize"));
// cls_gp_Ax22d.def_static("operator delete_", (void (*)(void *)) &gp_Ax22d::operator delete, "None", py::arg("theAddress"));
// cls_gp_Ax22d.def_static("operator new[]_", (void * (*)(size_t)) &gp_Ax22d::operator new[], "None", py::arg("theSize"));
// cls_gp_Ax22d.def_static("operator delete[]_", (void (*)(void *)) &gp_Ax22d::operator delete[], "None", py::arg("theAddress"));
// cls_gp_Ax22d.def_static("operator new_", (void * (*)(size_t, void *)) &gp_Ax22d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gp_Ax22d.def_static("operator delete_", (void (*)(void *, void *)) &gp_Ax22d::operator delete, "None", py::arg(""), py::arg(""));
cls_gp_Ax22d.def("SetAxis", (void (gp_Ax22d::*)(const gp_Ax22d &)) &gp_Ax22d::SetAxis, "Assigns the origin and the two unit vectors of the coordinate system A1 to this coordinate system.", py::arg("A1"));
cls_gp_Ax22d.def("SetXAxis", (void (gp_Ax22d::*)(const gp_Ax2d &)) &gp_Ax22d::SetXAxis, "Changes the XAxis and YAxis ('Location' point and 'Direction') of <me>. The 'YDirection' is recomputed in the same sense as before.", py::arg("A1"));
cls_gp_Ax22d.def("SetYAxis", (void (gp_Ax22d::*)(const gp_Ax2d &)) &gp_Ax22d::SetYAxis, "Changes the XAxis and YAxis ('Location' point and 'Direction') of <me>. The 'XDirection' is recomputed in the same sense as before.", py::arg("A1"));
cls_gp_Ax22d.def("SetLocation", (void (gp_Ax22d::*)(const gp_Pnt2d &)) &gp_Ax22d::SetLocation, "Changes the 'Location' point (origin) of <me>.", py::arg("P"));
cls_gp_Ax22d.def("SetXDirection", (void (gp_Ax22d::*)(const gp_Dir2d &)) &gp_Ax22d::SetXDirection, "Assigns Vx to the 'X Direction' of this coordinate system. The other unit vector of this coordinate system is recomputed, normal to Vx , without modifying the orientation (right-handed or left-handed) of this coordinate system.", py::arg("Vx"));
cls_gp_Ax22d.def("SetYDirection", (void (gp_Ax22d::*)(const gp_Dir2d &)) &gp_Ax22d::SetYDirection, "Assignsr Vy to the 'Y Direction' of this coordinate system. The other unit vector of this coordinate system is recomputed, normal to Vy, without modifying the orientation (right-handed or left-handed) of this coordinate system.", py::arg("Vy"));
cls_gp_Ax22d.def("XAxis", (gp_Ax2d (gp_Ax22d::*)() const) &gp_Ax22d::XAxis, "Returns an axis, for which - the origin is that of this coordinate system, and - the unit vector is either the 'X Direction' of this coordinate system. Note: the result is the 'X Axis' of this coordinate system.");
cls_gp_Ax22d.def("YAxis", (gp_Ax2d (gp_Ax22d::*)() const) &gp_Ax22d::YAxis, "Returns an axis, for which - the origin is that of this coordinate system, and - the unit vector is either the 'Y Direction' of this coordinate system. Note: the result is the 'Y Axis' of this coordinate system.");
cls_gp_Ax22d.def("Location", (const gp_Pnt2d & (gp_Ax22d::*)() const) &gp_Ax22d::Location, "Returns the 'Location' point (origin) of <me>.");
cls_gp_Ax22d.def("XDirection", (const gp_Dir2d & (gp_Ax22d::*)() const) &gp_Ax22d::XDirection, "Returns the 'XDirection' of <me>.");
cls_gp_Ax22d.def("YDirection", (const gp_Dir2d & (gp_Ax22d::*)() const) &gp_Ax22d::YDirection, "Returns the 'YDirection' of <me>.");
cls_gp_Ax22d.def("Mirror", (void (gp_Ax22d::*)(const gp_Pnt2d &)) &gp_Ax22d::Mirror, "None", py::arg("P"));
cls_gp_Ax22d.def("Mirrored", (gp_Ax22d (gp_Ax22d::*)(const gp_Pnt2d &) const) &gp_Ax22d::Mirrored, "Performs the symmetrical transformation of an axis placement with respect to the point P which is the center of the symmetry. Warnings : The main direction of the axis placement is not changed. The 'XDirection' and the 'YDirection' are reversed. So the axis placement stay right handed.", py::arg("P"));
cls_gp_Ax22d.def("Mirror", (void (gp_Ax22d::*)(const gp_Ax2d &)) &gp_Ax22d::Mirror, "None", py::arg("A"));
cls_gp_Ax22d.def("Mirrored", (gp_Ax22d (gp_Ax22d::*)(const gp_Ax2d &) const) &gp_Ax22d::Mirrored, "Performs the symmetrical transformation of an axis placement with respect to an axis placement which is the axis of the symmetry. The transformation is performed on the 'Location' point, on the 'XDirection' and 'YDirection'. The resulting main 'Direction' is the cross product between the 'XDirection' and the 'YDirection' after transformation.", py::arg("A"));
cls_gp_Ax22d.def("Rotate", (void (gp_Ax22d::*)(const gp_Pnt2d &, const Standard_Real)) &gp_Ax22d::Rotate, "None", py::arg("P"), py::arg("Ang"));
cls_gp_Ax22d.def("Rotated", (gp_Ax22d (gp_Ax22d::*)(const gp_Pnt2d &, const Standard_Real) const) &gp_Ax22d::Rotated, "Rotates an axis placement. <A1> is the axis of the rotation . Ang is the angular value of the rotation in radians.", py::arg("P"), py::arg("Ang"));
cls_gp_Ax22d.def("Scale", (void (gp_Ax22d::*)(const gp_Pnt2d &, const Standard_Real)) &gp_Ax22d::Scale, "None", py::arg("P"), py::arg("S"));
cls_gp_Ax22d.def("Scaled", (gp_Ax22d (gp_Ax22d::*)(const gp_Pnt2d &, const Standard_Real) const) &gp_Ax22d::Scaled, "Applies a scaling transformation on the axis placement. The 'Location' point of the axisplacement is modified. Warnings : If the scale <S> is negative : . the main direction of the axis placement is not changed. . The 'XDirection' and the 'YDirection' are reversed. So the axis placement stay right handed.", py::arg("P"), py::arg("S"));
cls_gp_Ax22d.def("Transform", (void (gp_Ax22d::*)(const gp_Trsf2d &)) &gp_Ax22d::Transform, "None", py::arg("T"));
cls_gp_Ax22d.def("Transformed", (gp_Ax22d (gp_Ax22d::*)(const gp_Trsf2d &) const) &gp_Ax22d::Transformed, "Transforms an axis placement with a Trsf. The 'Location' point, the 'XDirection' and the 'YDirection' are transformed with T. The resulting main 'Direction' of <me> is the cross product between the 'XDirection' and the 'YDirection' after transformation.", py::arg("T"));
cls_gp_Ax22d.def("Translate", (void (gp_Ax22d::*)(const gp_Vec2d &)) &gp_Ax22d::Translate, "None", py::arg("V"));
cls_gp_Ax22d.def("Translated", (gp_Ax22d (gp_Ax22d::*)(const gp_Vec2d &) const) &gp_Ax22d::Translated, "Translates an axis plaxement in the direction of the vector <V>. The magnitude of the translation is the vector's magnitude.", py::arg("V"));
cls_gp_Ax22d.def("Translate", (void (gp_Ax22d::*)(const gp_Pnt2d &, const gp_Pnt2d &)) &gp_Ax22d::Translate, "None", py::arg("P1"), py::arg("P2"));
cls_gp_Ax22d.def("Translated", (gp_Ax22d (gp_Ax22d::*)(const gp_Pnt2d &, const gp_Pnt2d &) const) &gp_Ax22d::Translated, "Translates an axis placement from the point <P1> to the point <P2>.", py::arg("P1"), py::arg("P2"));

// Enums

}