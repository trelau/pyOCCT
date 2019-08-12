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
#include <Standard_Transient.hxx>
#include <gp_Pnt.hxx>
#include <gp_Ax1.hxx>
#include <gp_Ax2.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Vec.hxx>
#include <gp_Trsf.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Geometry.hxx>
#include <Standard_Type.hxx>

void bind_Geom_Geometry(py::module &mod){

py::class_<Geom_Geometry, opencascade::handle<Geom_Geometry>, Standard_Transient> cls_Geom_Geometry(mod, "Geom_Geometry", "The abstract class Geometry for 3D space is the root class of all geometric objects from the Geom package. It describes the common behavior of these objects when: - applying geometric transformations to objects, and - constructing objects by geometric transformation (including copying). Warning Only transformations which do not modify the nature of the geometry can be applied to Geom objects: this is the case with translations, rotations, symmetries and scales; this is also the case with gp_Trsf composite transformations which are used to define the geometric transformations applied using the Transform or Transformed functions. Note: Geometry defines the 'prototype' of the abstract method Transform which is defined for each concrete type of derived object. All other transformations are implemented using the Transform method.");

// Fields

// Methods
cls_Geom_Geometry.def("Mirror", (void (Geom_Geometry::*)(const gp_Pnt &)) &Geom_Geometry::Mirror, "Performs the symmetrical transformation of a Geometry with respect to the point P which is the center of the symmetry.", py::arg("P"));
cls_Geom_Geometry.def("Mirror", (void (Geom_Geometry::*)(const gp_Ax1 &)) &Geom_Geometry::Mirror, "Performs the symmetrical transformation of a Geometry with respect to an axis placement which is the axis of the symmetry.", py::arg("A1"));
cls_Geom_Geometry.def("Mirror", (void (Geom_Geometry::*)(const gp_Ax2 &)) &Geom_Geometry::Mirror, "Performs the symmetrical transformation of a Geometry with respect to a plane. The axis placement A2 locates the plane of the symmetry : (Location, XDirection, YDirection).", py::arg("A2"));
cls_Geom_Geometry.def("Rotate", (void (Geom_Geometry::*)(const gp_Ax1 &, const Standard_Real)) &Geom_Geometry::Rotate, "Rotates a Geometry. A1 is the axis of the rotation. Ang is the angular value of the rotation in radians.", py::arg("A1"), py::arg("Ang"));
cls_Geom_Geometry.def("Scale", (void (Geom_Geometry::*)(const gp_Pnt &, const Standard_Real)) &Geom_Geometry::Scale, "Scales a Geometry. S is the scaling value.", py::arg("P"), py::arg("S"));
cls_Geom_Geometry.def("Translate", (void (Geom_Geometry::*)(const gp_Vec &)) &Geom_Geometry::Translate, "Translates a Geometry. V is the vector of the tanslation.", py::arg("V"));
cls_Geom_Geometry.def("Translate", (void (Geom_Geometry::*)(const gp_Pnt &, const gp_Pnt &)) &Geom_Geometry::Translate, "Translates a Geometry from the point P1 to the point P2.", py::arg("P1"), py::arg("P2"));
cls_Geom_Geometry.def("Transform", (void (Geom_Geometry::*)(const gp_Trsf &)) &Geom_Geometry::Transform, "Transformation of a geometric object. This tansformation can be a translation, a rotation, a symmetry, a scaling or a complex transformation obtained by combination of the previous elementaries transformations. (see class Transformation of the package Geom).", py::arg("T"));
cls_Geom_Geometry.def("Mirrored", (opencascade::handle<Geom_Geometry> (Geom_Geometry::*)(const gp_Pnt &) const) &Geom_Geometry::Mirrored, "None", py::arg("P"));
cls_Geom_Geometry.def("Mirrored", (opencascade::handle<Geom_Geometry> (Geom_Geometry::*)(const gp_Ax1 &) const) &Geom_Geometry::Mirrored, "None", py::arg("A1"));
cls_Geom_Geometry.def("Mirrored", (opencascade::handle<Geom_Geometry> (Geom_Geometry::*)(const gp_Ax2 &) const) &Geom_Geometry::Mirrored, "None", py::arg("A2"));
cls_Geom_Geometry.def("Rotated", (opencascade::handle<Geom_Geometry> (Geom_Geometry::*)(const gp_Ax1 &, const Standard_Real) const) &Geom_Geometry::Rotated, "None", py::arg("A1"), py::arg("Ang"));
cls_Geom_Geometry.def("Scaled", (opencascade::handle<Geom_Geometry> (Geom_Geometry::*)(const gp_Pnt &, const Standard_Real) const) &Geom_Geometry::Scaled, "None", py::arg("P"), py::arg("S"));
cls_Geom_Geometry.def("Transformed", (opencascade::handle<Geom_Geometry> (Geom_Geometry::*)(const gp_Trsf &) const) &Geom_Geometry::Transformed, "None", py::arg("T"));
cls_Geom_Geometry.def("Translated", (opencascade::handle<Geom_Geometry> (Geom_Geometry::*)(const gp_Vec &) const) &Geom_Geometry::Translated, "None", py::arg("V"));
cls_Geom_Geometry.def("Translated", (opencascade::handle<Geom_Geometry> (Geom_Geometry::*)(const gp_Pnt &, const gp_Pnt &) const) &Geom_Geometry::Translated, "None", py::arg("P1"), py::arg("P2"));
cls_Geom_Geometry.def("Copy", (opencascade::handle<Geom_Geometry> (Geom_Geometry::*)() const) &Geom_Geometry::Copy, "Creates a new object which is a copy of this geometric object.");
cls_Geom_Geometry.def_static("get_type_name_", (const char * (*)()) &Geom_Geometry::get_type_name, "None");
cls_Geom_Geometry.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Geom_Geometry::get_type_descriptor, "None");
cls_Geom_Geometry.def("DynamicType", (const opencascade::handle<Standard_Type> & (Geom_Geometry::*)() const) &Geom_Geometry::DynamicType, "None");

// Enums

}