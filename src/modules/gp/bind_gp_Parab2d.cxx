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
#include <gp_Parab2d.hxx>
#include <gp_Trsf2d.hxx>
#include <gp_Vec2d.hxx>

void bind_gp_Parab2d(py::module &mod){

py::class_<gp_Parab2d, std::unique_ptr<gp_Parab2d, Deleter<gp_Parab2d>>> cls_gp_Parab2d(mod, "gp_Parab2d", "Describes a parabola in the plane (2D space). A parabola is defined by its focal length (that is, the distance between its focus and apex) and positioned in the plane with a coordinate system (a gp_Ax22d object) where: - the origin of the coordinate system is on the apex of the parabola, and - the 'X Axis' of the coordinate system is the axis of symmetry; the parabola is on the positive side of this axis. This coordinate system is the 'local coordinate system' of the parabola. Its orientation (direct or indirect sense) gives an implicit orientation to the parabola. In this coordinate system, the equation for the parabola is: Y**2 = (2*P) * X. where P, referred to as the parameter of the parabola, is the distance between the focus and the directrix (P is twice the focal length). See Also GCE2d_MakeParab2d which provides functions for more complex parabola constructions Geom2d_Parabola which provides additional functions for constructing parabolas and works, in particular, with the parametric equations of parabolas");

// Constructors
cls_gp_Parab2d.def(py::init<>());
cls_gp_Parab2d.def(py::init<const gp_Ax2d &, const Standard_Real>(), py::arg("theMirrorAxis"), py::arg("theFocalLength"));
cls_gp_Parab2d.def(py::init<const gp_Ax2d &, const Standard_Real, const Standard_Boolean>(), py::arg("theMirrorAxis"), py::arg("theFocalLength"), py::arg("theSense"));
cls_gp_Parab2d.def(py::init<const gp_Ax22d &, const Standard_Real>(), py::arg("theAxes"), py::arg("theFocalLength"));
cls_gp_Parab2d.def(py::init<const gp_Ax2d &, const gp_Pnt2d &>(), py::arg("theDirectrix"), py::arg("theFocus"));
cls_gp_Parab2d.def(py::init<const gp_Ax2d &, const gp_Pnt2d &, const Standard_Boolean>(), py::arg("theDirectrix"), py::arg("theFocus"), py::arg("theSense"));

// Fields

// Methods
// cls_gp_Parab2d.def_static("operator new_", (void * (*)(size_t)) &gp_Parab2d::operator new, "None", py::arg("theSize"));
// cls_gp_Parab2d.def_static("operator delete_", (void (*)(void *)) &gp_Parab2d::operator delete, "None", py::arg("theAddress"));
// cls_gp_Parab2d.def_static("operator new[]_", (void * (*)(size_t)) &gp_Parab2d::operator new[], "None", py::arg("theSize"));
// cls_gp_Parab2d.def_static("operator delete[]_", (void (*)(void *)) &gp_Parab2d::operator delete[], "None", py::arg("theAddress"));
// cls_gp_Parab2d.def_static("operator new_", (void * (*)(size_t, void *)) &gp_Parab2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gp_Parab2d.def_static("operator delete_", (void (*)(void *, void *)) &gp_Parab2d::operator delete, "None", py::arg(""), py::arg(""));
cls_gp_Parab2d.def("SetFocal", (void (gp_Parab2d::*)(const Standard_Real)) &gp_Parab2d::SetFocal, "Changes the focal distance of the parabola Warnings : It is possible to have Focal = 0. Raises ConstructionError if Focal < 0.0", py::arg("Focal"));
cls_gp_Parab2d.def("SetLocation", (void (gp_Parab2d::*)(const gp_Pnt2d &)) &gp_Parab2d::SetLocation, "Changes the 'Location' point of the parabola. It is the vertex of the parabola.", py::arg("P"));
cls_gp_Parab2d.def("SetMirrorAxis", (void (gp_Parab2d::*)(const gp_Ax2d &)) &gp_Parab2d::SetMirrorAxis, "Modifies this parabola, by redefining its local coordinate system so that its origin and 'X Direction' become those of the axis MA. The 'Y Direction' of the local coordinate system is then recomputed. The orientation of the local coordinate system is not modified.", py::arg("A"));
cls_gp_Parab2d.def("SetAxis", (void (gp_Parab2d::*)(const gp_Ax22d &)) &gp_Parab2d::SetAxis, "Changes the local coordinate system of the parabola. The 'Location' point of A becomes the vertex of the parabola.", py::arg("A"));
cls_gp_Parab2d.def("Coefficients", [](gp_Parab2d &self, Standard_Real & A, Standard_Real & B, Standard_Real & C, Standard_Real & D, Standard_Real & E, Standard_Real & F){ self.Coefficients(A, B, C, D, E, F); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(A, B, C, D, E, F); }, "Computes the coefficients of the implicit equation of the parabola (in WCS - World Coordinate System). A * (X**2) + B * (Y**2) + 2*C*(X*Y) + 2*D*X + 2*E*Y + F = 0.", py::arg("A"), py::arg("B"), py::arg("C"), py::arg("D"), py::arg("E"), py::arg("F"));
cls_gp_Parab2d.def("Directrix", (gp_Ax2d (gp_Parab2d::*)() const) &gp_Parab2d::Directrix, "Computes the directrix of the parabola. The directrix is: - a line parallel to the 'Y Direction' of the local coordinate system of this parabola, and - located on the negative side of the axis of symmetry, at a distance from the apex which is equal to the focal length of this parabola. The directrix is returned as an axis (a gp_Ax2d object), the origin of which is situated on the 'X Axis' of this parabola.");
cls_gp_Parab2d.def("Focal", (Standard_Real (gp_Parab2d::*)() const) &gp_Parab2d::Focal, "Returns the distance between the vertex and the focus of the parabola.");
cls_gp_Parab2d.def("Focus", (gp_Pnt2d (gp_Parab2d::*)() const) &gp_Parab2d::Focus, "Returns the focus of the parabola.");
cls_gp_Parab2d.def("Location", (gp_Pnt2d (gp_Parab2d::*)() const) &gp_Parab2d::Location, "Returns the vertex of the parabola.");
cls_gp_Parab2d.def("MirrorAxis", (gp_Ax2d (gp_Parab2d::*)() const) &gp_Parab2d::MirrorAxis, "Returns the symmetry axis of the parabola. The 'Location' point of this axis is the vertex of the parabola.");
cls_gp_Parab2d.def("Axis", (gp_Ax22d (gp_Parab2d::*)() const) &gp_Parab2d::Axis, "Returns the local coordinate system of the parabola. The 'Location' point of this axis is the vertex of the parabola.");
cls_gp_Parab2d.def("Parameter", (Standard_Real (gp_Parab2d::*)() const) &gp_Parab2d::Parameter, "Returns the distance between the focus and the directrix of the parabola.");
cls_gp_Parab2d.def("Reverse", (void (gp_Parab2d::*)()) &gp_Parab2d::Reverse, "None");
cls_gp_Parab2d.def("Reversed", (gp_Parab2d (gp_Parab2d::*)() const) &gp_Parab2d::Reversed, "Reverses the orientation of the local coordinate system of this parabola (the 'Y Direction' is reversed). Therefore, the implicit orientation of this parabola is reversed. Note: - Reverse assigns the result to this parabola, while - Reversed creates a new one.");
cls_gp_Parab2d.def("IsDirect", (Standard_Boolean (gp_Parab2d::*)() const) &gp_Parab2d::IsDirect, "Returns true if the local coordinate system is direct and false in the other case.");
cls_gp_Parab2d.def("Mirror", (void (gp_Parab2d::*)(const gp_Pnt2d &)) &gp_Parab2d::Mirror, "None", py::arg("P"));
cls_gp_Parab2d.def("Mirrored", (gp_Parab2d (gp_Parab2d::*)(const gp_Pnt2d &) const) &gp_Parab2d::Mirrored, "Performs the symmetrical transformation of a parabola with respect to the point P which is the center of the symmetry", py::arg("P"));
cls_gp_Parab2d.def("Mirror", (void (gp_Parab2d::*)(const gp_Ax2d &)) &gp_Parab2d::Mirror, "None", py::arg("A"));
cls_gp_Parab2d.def("Mirrored", (gp_Parab2d (gp_Parab2d::*)(const gp_Ax2d &) const) &gp_Parab2d::Mirrored, "Performs the symmetrical transformation of a parabola with respect to an axis placement which is the axis of the symmetry.", py::arg("A"));
cls_gp_Parab2d.def("Rotate", (void (gp_Parab2d::*)(const gp_Pnt2d &, const Standard_Real)) &gp_Parab2d::Rotate, "None", py::arg("P"), py::arg("Ang"));
cls_gp_Parab2d.def("Rotated", (gp_Parab2d (gp_Parab2d::*)(const gp_Pnt2d &, const Standard_Real) const) &gp_Parab2d::Rotated, "Rotates a parabola. P is the center of the rotation. Ang is the angular value of the rotation in radians.", py::arg("P"), py::arg("Ang"));
cls_gp_Parab2d.def("Scale", (void (gp_Parab2d::*)(const gp_Pnt2d &, const Standard_Real)) &gp_Parab2d::Scale, "None", py::arg("P"), py::arg("S"));
cls_gp_Parab2d.def("Scaled", (gp_Parab2d (gp_Parab2d::*)(const gp_Pnt2d &, const Standard_Real) const) &gp_Parab2d::Scaled, "Scales a parabola. S is the scaling value. If S is negative the direction of the symmetry axis 'XAxis' is reversed and the direction of the 'YAxis' too.", py::arg("P"), py::arg("S"));
cls_gp_Parab2d.def("Transform", (void (gp_Parab2d::*)(const gp_Trsf2d &)) &gp_Parab2d::Transform, "None", py::arg("T"));
cls_gp_Parab2d.def("Transformed", (gp_Parab2d (gp_Parab2d::*)(const gp_Trsf2d &) const) &gp_Parab2d::Transformed, "Transforms an parabola with the transformation T from class Trsf2d.", py::arg("T"));
cls_gp_Parab2d.def("Translate", (void (gp_Parab2d::*)(const gp_Vec2d &)) &gp_Parab2d::Translate, "None", py::arg("V"));
cls_gp_Parab2d.def("Translated", (gp_Parab2d (gp_Parab2d::*)(const gp_Vec2d &) const) &gp_Parab2d::Translated, "Translates a parabola in the direction of the vector V. The magnitude of the translation is the vector's magnitude.", py::arg("V"));
cls_gp_Parab2d.def("Translate", (void (gp_Parab2d::*)(const gp_Pnt2d &, const gp_Pnt2d &)) &gp_Parab2d::Translate, "None", py::arg("P1"), py::arg("P2"));
cls_gp_Parab2d.def("Translated", (gp_Parab2d (gp_Parab2d::*)(const gp_Pnt2d &, const gp_Pnt2d &) const) &gp_Parab2d::Translated, "Translates a parabola from the point P1 to the point P2.", py::arg("P1"), py::arg("P2"));

// Enums

}