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
#include <gp_Pnt2d.hxx>
#include <gp_Ax2d.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Vec2d.hxx>
#include <gp_Trsf2d.hxx>
#include <Standard_Handle.hxx>
#include <Geom2d_Geometry.hxx>
#include <Standard_Type.hxx>

void bind_Geom2d_Geometry(py::module &mod){

py::class_<Geom2d_Geometry, opencascade::handle<Geom2d_Geometry>, Standard_Transient> cls_Geom2d_Geometry(mod, "Geom2d_Geometry", "The general abstract class Geometry in 2D space describes the common behaviour of all the geometric entities.");

// Fields

// Methods
cls_Geom2d_Geometry.def("Mirror", (void (Geom2d_Geometry::*)(const gp_Pnt2d &)) &Geom2d_Geometry::Mirror, "Performs the symmetrical transformation of a Geometry with respect to the point P which is the center of the symmetry and assigns the result to this geometric object.", py::arg("P"));
cls_Geom2d_Geometry.def("Mirror", (void (Geom2d_Geometry::*)(const gp_Ax2d &)) &Geom2d_Geometry::Mirror, "Performs the symmetrical transformation of a Geometry with respect to an axis placement which is the axis of the symmetry.", py::arg("A"));
cls_Geom2d_Geometry.def("Rotate", (void (Geom2d_Geometry::*)(const gp_Pnt2d &, const Standard_Real)) &Geom2d_Geometry::Rotate, "Rotates a Geometry. P is the center of the rotation. Ang is the angular value of the rotation in radians.", py::arg("P"), py::arg("Ang"));
cls_Geom2d_Geometry.def("Scale", (void (Geom2d_Geometry::*)(const gp_Pnt2d &, const Standard_Real)) &Geom2d_Geometry::Scale, "Scales a Geometry. S is the scaling value.", py::arg("P"), py::arg("S"));
cls_Geom2d_Geometry.def("Translate", (void (Geom2d_Geometry::*)(const gp_Vec2d &)) &Geom2d_Geometry::Translate, "Translates a Geometry. V is the vector of the tanslation.", py::arg("V"));
cls_Geom2d_Geometry.def("Translate", (void (Geom2d_Geometry::*)(const gp_Pnt2d &, const gp_Pnt2d &)) &Geom2d_Geometry::Translate, "Translates a Geometry from the point P1 to the point P2.", py::arg("P1"), py::arg("P2"));
cls_Geom2d_Geometry.def("Transform", (void (Geom2d_Geometry::*)(const gp_Trsf2d &)) &Geom2d_Geometry::Transform, "Transformation of a geometric object. This tansformation can be a translation, a rotation, a symmetry, a scaling or a complex transformation obtained by combination of the previous elementaries transformations. (see class Transformation of the package Geom2d). The following transformations have the same properties as the previous ones but they don't modified the object itself. A copy of the object is returned.", py::arg("T"));
cls_Geom2d_Geometry.def("Mirrored", (opencascade::handle<Geom2d_Geometry> (Geom2d_Geometry::*)(const gp_Pnt2d &) const) &Geom2d_Geometry::Mirrored, "None", py::arg("P"));
cls_Geom2d_Geometry.def("Mirrored", (opencascade::handle<Geom2d_Geometry> (Geom2d_Geometry::*)(const gp_Ax2d &) const) &Geom2d_Geometry::Mirrored, "None", py::arg("A"));
cls_Geom2d_Geometry.def("Rotated", (opencascade::handle<Geom2d_Geometry> (Geom2d_Geometry::*)(const gp_Pnt2d &, const Standard_Real) const) &Geom2d_Geometry::Rotated, "None", py::arg("P"), py::arg("Ang"));
cls_Geom2d_Geometry.def("Scaled", (opencascade::handle<Geom2d_Geometry> (Geom2d_Geometry::*)(const gp_Pnt2d &, const Standard_Real) const) &Geom2d_Geometry::Scaled, "None", py::arg("P"), py::arg("S"));
cls_Geom2d_Geometry.def("Transformed", (opencascade::handle<Geom2d_Geometry> (Geom2d_Geometry::*)(const gp_Trsf2d &) const) &Geom2d_Geometry::Transformed, "None", py::arg("T"));
cls_Geom2d_Geometry.def("Translated", (opencascade::handle<Geom2d_Geometry> (Geom2d_Geometry::*)(const gp_Vec2d &) const) &Geom2d_Geometry::Translated, "None", py::arg("V"));
cls_Geom2d_Geometry.def("Translated", (opencascade::handle<Geom2d_Geometry> (Geom2d_Geometry::*)(const gp_Pnt2d &, const gp_Pnt2d &) const) &Geom2d_Geometry::Translated, "None", py::arg("P1"), py::arg("P2"));
cls_Geom2d_Geometry.def("Copy", (opencascade::handle<Geom2d_Geometry> (Geom2d_Geometry::*)() const) &Geom2d_Geometry::Copy, "None");
cls_Geom2d_Geometry.def_static("get_type_name_", (const char * (*)()) &Geom2d_Geometry::get_type_name, "None");
cls_Geom2d_Geometry.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Geom2d_Geometry::get_type_descriptor, "None");
cls_Geom2d_Geometry.def("DynamicType", (const opencascade::handle<Standard_Type> & (Geom2d_Geometry::*)() const) &Geom2d_Geometry::DynamicType, "None");

// Enums

}