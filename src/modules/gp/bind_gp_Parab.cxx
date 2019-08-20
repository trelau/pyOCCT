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
#include <gp_Parab.hxx>
#include <gp_Trsf.hxx>
#include <gp_Vec.hxx>

void bind_gp_Parab(py::module &mod){

py::class_<gp_Parab, std::unique_ptr<gp_Parab>> cls_gp_Parab(mod, "gp_Parab", "Describes a parabola in 3D space. A parabola is defined by its focal length (that is, the distance between its focus and apex) and positioned in space with a coordinate system (a gp_Ax2 object) where: - the origin of the coordinate system is on the apex of the parabola, - the 'X Axis' of the coordinate system is the axis of symmetry; the parabola is on the positive side of this axis, and - the origin, 'X Direction' and 'Y Direction' of the coordinate system define the plane of the parabola. The equation of the parabola in this coordinate system, which is the 'local coordinate system' of the parabola, is: Y**2 = (2*P) * X. where P, referred to as the parameter of the parabola, is the distance between the focus and the directrix (P is twice the focal length). The 'main Direction' of the local coordinate system gives the normal vector to the plane of the parabola. See Also gce_MakeParab which provides functions for more complex parabola constructions Geom_Parabola which provides additional functions for constructing parabolas and works, in particular, with the parametric equations of parabolas");

// Constructors
cls_gp_Parab.def(py::init<>());
cls_gp_Parab.def(py::init<const gp_Ax2 &, const Standard_Real>(), py::arg("A2"), py::arg("Focal"));
cls_gp_Parab.def(py::init<const gp_Ax1 &, const gp_Pnt &>(), py::arg("D"), py::arg("F"));

// Fields

// Methods
// cls_gp_Parab.def_static("operator new_", (void * (*)(size_t)) &gp_Parab::operator new, "None", py::arg("theSize"));
// cls_gp_Parab.def_static("operator delete_", (void (*)(void *)) &gp_Parab::operator delete, "None", py::arg("theAddress"));
// cls_gp_Parab.def_static("operator new[]_", (void * (*)(size_t)) &gp_Parab::operator new[], "None", py::arg("theSize"));
// cls_gp_Parab.def_static("operator delete[]_", (void (*)(void *)) &gp_Parab::operator delete[], "None", py::arg("theAddress"));
// cls_gp_Parab.def_static("operator new_", (void * (*)(size_t, void *)) &gp_Parab::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gp_Parab.def_static("operator delete_", (void (*)(void *, void *)) &gp_Parab::operator delete, "None", py::arg(""), py::arg(""));
cls_gp_Parab.def("SetAxis", (void (gp_Parab::*)(const gp_Ax1 &)) &gp_Parab::SetAxis, "Modifies this parabola by redefining its local coordinate system so that - its origin and 'main Direction' become those of the axis A1 (the 'X Direction' and 'Y Direction' are then recomputed in the same way as for any gp_Ax2) Raises ConstructionError if the direction of A1 is parallel to the previous XAxis of the parabola.", py::arg("A1"));
cls_gp_Parab.def("SetFocal", (void (gp_Parab::*)(const Standard_Real)) &gp_Parab::SetFocal, "Changes the focal distance of the parabola. Raises ConstructionError if Focal < 0.0", py::arg("Focal"));
cls_gp_Parab.def("SetLocation", (void (gp_Parab::*)(const gp_Pnt &)) &gp_Parab::SetLocation, "Changes the location of the parabola. It is the vertex of the parabola.", py::arg("P"));
cls_gp_Parab.def("SetPosition", (void (gp_Parab::*)(const gp_Ax2 &)) &gp_Parab::SetPosition, "Changes the local coordinate system of the parabola.", py::arg("A2"));
cls_gp_Parab.def("Axis", (const gp_Ax1 & (gp_Parab::*)() const) &gp_Parab::Axis, "Returns the main axis of the parabola. It is the axis normal to the plane of the parabola passing through the vertex of the parabola.");
cls_gp_Parab.def("Directrix", (gp_Ax1 (gp_Parab::*)() const) &gp_Parab::Directrix, "Computes the directrix of this parabola. The directrix is: - a line parallel to the 'Y Direction' of the local coordinate system of this parabola, and - located on the negative side of the axis of symmetry, at a distance from the apex which is equal to the focal length of this parabola. The directrix is returned as an axis (a gp_Ax1 object), the origin of which is situated on the 'X Axis' of this parabola.");
cls_gp_Parab.def("Focal", (Standard_Real (gp_Parab::*)() const) &gp_Parab::Focal, "Returns the distance between the vertex and the focus of the parabola.");
cls_gp_Parab.def("Focus", (gp_Pnt (gp_Parab::*)() const) &gp_Parab::Focus, "- Computes the focus of the parabola.");
cls_gp_Parab.def("Location", (const gp_Pnt & (gp_Parab::*)() const) &gp_Parab::Location, "Returns the vertex of the parabola. It is the 'Location' point of the coordinate system of the parabola.");
cls_gp_Parab.def("Parameter", (Standard_Real (gp_Parab::*)() const) &gp_Parab::Parameter, "Computes the parameter of the parabola. It is the distance between the focus and the directrix of the parabola. This distance is twice the focal length.");
cls_gp_Parab.def("Position", (const gp_Ax2 & (gp_Parab::*)() const) &gp_Parab::Position, "Returns the local coordinate system of the parabola.");
cls_gp_Parab.def("XAxis", (gp_Ax1 (gp_Parab::*)() const) &gp_Parab::XAxis, "Returns the symmetry axis of the parabola. The location point of the axis is the vertex of the parabola.");
cls_gp_Parab.def("YAxis", (gp_Ax1 (gp_Parab::*)() const) &gp_Parab::YAxis, "It is an axis parallel to the directrix of the parabola. The location point of this axis is the vertex of the parabola.");
cls_gp_Parab.def("Mirror", (void (gp_Parab::*)(const gp_Pnt &)) &gp_Parab::Mirror, "None", py::arg("P"));
cls_gp_Parab.def("Mirrored", (gp_Parab (gp_Parab::*)(const gp_Pnt &) const) &gp_Parab::Mirrored, "Performs the symmetrical transformation of a parabola with respect to the point P which is the center of the symmetry.", py::arg("P"));
cls_gp_Parab.def("Mirror", (void (gp_Parab::*)(const gp_Ax1 &)) &gp_Parab::Mirror, "None", py::arg("A1"));
cls_gp_Parab.def("Mirrored", (gp_Parab (gp_Parab::*)(const gp_Ax1 &) const) &gp_Parab::Mirrored, "Performs the symmetrical transformation of a parabola with respect to an axis placement which is the axis of the symmetry.", py::arg("A1"));
cls_gp_Parab.def("Mirror", (void (gp_Parab::*)(const gp_Ax2 &)) &gp_Parab::Mirror, "None", py::arg("A2"));
cls_gp_Parab.def("Mirrored", (gp_Parab (gp_Parab::*)(const gp_Ax2 &) const) &gp_Parab::Mirrored, "Performs the symmetrical transformation of a parabola with respect to a plane. The axis placement A2 locates the plane of the symmetry (Location, XDirection, YDirection).", py::arg("A2"));
cls_gp_Parab.def("Rotate", (void (gp_Parab::*)(const gp_Ax1 &, const Standard_Real)) &gp_Parab::Rotate, "None", py::arg("A1"), py::arg("Ang"));
cls_gp_Parab.def("Rotated", (gp_Parab (gp_Parab::*)(const gp_Ax1 &, const Standard_Real) const) &gp_Parab::Rotated, "Rotates a parabola. A1 is the axis of the rotation. Ang is the angular value of the rotation in radians.", py::arg("A1"), py::arg("Ang"));
cls_gp_Parab.def("Scale", (void (gp_Parab::*)(const gp_Pnt &, const Standard_Real)) &gp_Parab::Scale, "None", py::arg("P"), py::arg("S"));
cls_gp_Parab.def("Scaled", (gp_Parab (gp_Parab::*)(const gp_Pnt &, const Standard_Real) const) &gp_Parab::Scaled, "Scales a parabola. S is the scaling value. If S is negative the direction of the symmetry axis XAxis is reversed and the direction of the YAxis too.", py::arg("P"), py::arg("S"));
cls_gp_Parab.def("Transform", (void (gp_Parab::*)(const gp_Trsf &)) &gp_Parab::Transform, "None", py::arg("T"));
cls_gp_Parab.def("Transformed", (gp_Parab (gp_Parab::*)(const gp_Trsf &) const) &gp_Parab::Transformed, "Transforms a parabola with the transformation T from class Trsf.", py::arg("T"));
cls_gp_Parab.def("Translate", (void (gp_Parab::*)(const gp_Vec &)) &gp_Parab::Translate, "None", py::arg("V"));
cls_gp_Parab.def("Translated", (gp_Parab (gp_Parab::*)(const gp_Vec &) const) &gp_Parab::Translated, "Translates a parabola in the direction of the vector V. The magnitude of the translation is the vector's magnitude.", py::arg("V"));
cls_gp_Parab.def("Translate", (void (gp_Parab::*)(const gp_Pnt &, const gp_Pnt &)) &gp_Parab::Translate, "None", py::arg("P1"), py::arg("P2"));
cls_gp_Parab.def("Translated", (gp_Parab (gp_Parab::*)(const gp_Pnt &, const gp_Pnt &) const) &gp_Parab::Translated, "Translates a parabola from the point P1 to the point P2.", py::arg("P1"), py::arg("P2"));

// Enums

}