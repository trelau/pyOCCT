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
#include <Standard_TypeDef.hxx>
#include <gp_Ax1.hxx>
#include <gp_Pnt.hxx>
#include <gp_Cylinder.hxx>
#include <gp_Ax2.hxx>
#include <gp_Trsf.hxx>
#include <gp_Vec.hxx>

void bind_gp_Cylinder(py::module &mod){

py::class_<gp_Cylinder, std::unique_ptr<gp_Cylinder, Deleter<gp_Cylinder>>> cls_gp_Cylinder(mod, "gp_Cylinder", "Describes an infinite cylindrical surface. A cylinder is defined by its radius and positioned in space with a coordinate system (a gp_Ax3 object), the 'main Axis' of which is the axis of the cylinder. This coordinate system is the 'local coordinate system' of the cylinder. Note: when a gp_Cylinder cylinder is converted into a Geom_CylindricalSurface cylinder, some implicit properties of its local coordinate system are used explicitly: - its origin, 'X Direction', 'Y Direction' and 'main Direction' are used directly to define the parametric directions on the cylinder and the origin of the parameters, - its implicit orientation (right-handed or left-handed) gives an orientation (direct or indirect) to the Geom_CylindricalSurface cylinder. See Also gce_MakeCylinder which provides functions for more complex cylinder constructions Geom_CylindricalSurface which provides additional functions for constructing cylinders and works, in particular, with the parametric equations of cylinders gp_Ax3");

// Constructors
cls_gp_Cylinder.def(py::init<>());
cls_gp_Cylinder.def(py::init<const gp_Ax3 &, const Standard_Real>(), py::arg("A3"), py::arg("Radius"));

// Fields

// Methods
// cls_gp_Cylinder.def_static("operator new_", (void * (*)(size_t)) &gp_Cylinder::operator new, "None", py::arg("theSize"));
// cls_gp_Cylinder.def_static("operator delete_", (void (*)(void *)) &gp_Cylinder::operator delete, "None", py::arg("theAddress"));
// cls_gp_Cylinder.def_static("operator new[]_", (void * (*)(size_t)) &gp_Cylinder::operator new[], "None", py::arg("theSize"));
// cls_gp_Cylinder.def_static("operator delete[]_", (void (*)(void *)) &gp_Cylinder::operator delete[], "None", py::arg("theAddress"));
// cls_gp_Cylinder.def_static("operator new_", (void * (*)(size_t, void *)) &gp_Cylinder::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gp_Cylinder.def_static("operator delete_", (void (*)(void *, void *)) &gp_Cylinder::operator delete, "None", py::arg(""), py::arg(""));
cls_gp_Cylinder.def("SetAxis", (void (gp_Cylinder::*)(const gp_Ax1 &)) &gp_Cylinder::SetAxis, "Changes the symmetry axis of the cylinder. Raises ConstructionError if the direction of A1 is parallel to the 'XDirection' of the coordinate system of the cylinder.", py::arg("A1"));
cls_gp_Cylinder.def("SetLocation", (void (gp_Cylinder::*)(const gp_Pnt &)) &gp_Cylinder::SetLocation, "Changes the location of the surface.", py::arg("Loc"));
cls_gp_Cylinder.def("SetPosition", (void (gp_Cylinder::*)(const gp_Ax3 &)) &gp_Cylinder::SetPosition, "Change the local coordinate system of the surface.", py::arg("A3"));
cls_gp_Cylinder.def("SetRadius", (void (gp_Cylinder::*)(const Standard_Real)) &gp_Cylinder::SetRadius, "Modifies the radius of this cylinder. Exceptions Standard_ConstructionError if R is negative.", py::arg("R"));
cls_gp_Cylinder.def("UReverse", (void (gp_Cylinder::*)()) &gp_Cylinder::UReverse, "Reverses the U parametrization of the cylinder reversing the YAxis.");
cls_gp_Cylinder.def("VReverse", (void (gp_Cylinder::*)()) &gp_Cylinder::VReverse, "Reverses the V parametrization of the plane reversing the Axis.");
cls_gp_Cylinder.def("Direct", (Standard_Boolean (gp_Cylinder::*)() const) &gp_Cylinder::Direct, "Returns true if the local coordinate system of this cylinder is right-handed.");
cls_gp_Cylinder.def("Axis", (const gp_Ax1 & (gp_Cylinder::*)() const) &gp_Cylinder::Axis, "Returns the symmetry axis of the cylinder.");
cls_gp_Cylinder.def("Coefficients", [](gp_Cylinder &self, Standard_Real & A1, Standard_Real & A2, Standard_Real & A3, Standard_Real & B1, Standard_Real & B2, Standard_Real & B3, Standard_Real & C1, Standard_Real & C2, Standard_Real & C3, Standard_Real & D){ self.Coefficients(A1, A2, A3, B1, B2, B3, C1, C2, C3, D); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(A1, A2, A3, B1, B2, B3, C1, C2, C3, D); }, "Computes the coefficients of the implicit equation of the quadric in the absolute cartesian coordinate system : A1.X**2 + A2.Y**2 + A3.Z**2 + 2.(B1.X.Y + B2.X.Z + B3.Y.Z) + 2.(C1.X + C2.Y + C3.Z) + D = 0.0", py::arg("A1"), py::arg("A2"), py::arg("A3"), py::arg("B1"), py::arg("B2"), py::arg("B3"), py::arg("C1"), py::arg("C2"), py::arg("C3"), py::arg("D"));
cls_gp_Cylinder.def("Location", (const gp_Pnt & (gp_Cylinder::*)() const) &gp_Cylinder::Location, "Returns the 'Location' point of the cylinder.");
cls_gp_Cylinder.def("Position", (const gp_Ax3 & (gp_Cylinder::*)() const) &gp_Cylinder::Position, "Returns the local coordinate system of the cylinder.");
cls_gp_Cylinder.def("Radius", (Standard_Real (gp_Cylinder::*)() const) &gp_Cylinder::Radius, "Returns the radius of the cylinder.");
cls_gp_Cylinder.def("XAxis", (gp_Ax1 (gp_Cylinder::*)() const) &gp_Cylinder::XAxis, "Returns the axis X of the cylinder.");
cls_gp_Cylinder.def("YAxis", (gp_Ax1 (gp_Cylinder::*)() const) &gp_Cylinder::YAxis, "Returns the axis Y of the cylinder.");
cls_gp_Cylinder.def("Mirror", (void (gp_Cylinder::*)(const gp_Pnt &)) &gp_Cylinder::Mirror, "None", py::arg("P"));
cls_gp_Cylinder.def("Mirrored", (gp_Cylinder (gp_Cylinder::*)(const gp_Pnt &) const) &gp_Cylinder::Mirrored, "Performs the symmetrical transformation of a cylinder with respect to the point P which is the center of the symmetry.", py::arg("P"));
cls_gp_Cylinder.def("Mirror", (void (gp_Cylinder::*)(const gp_Ax1 &)) &gp_Cylinder::Mirror, "None", py::arg("A1"));
cls_gp_Cylinder.def("Mirrored", (gp_Cylinder (gp_Cylinder::*)(const gp_Ax1 &) const) &gp_Cylinder::Mirrored, "Performs the symmetrical transformation of a cylinder with respect to an axis placement which is the axis of the symmetry.", py::arg("A1"));
cls_gp_Cylinder.def("Mirror", (void (gp_Cylinder::*)(const gp_Ax2 &)) &gp_Cylinder::Mirror, "None", py::arg("A2"));
cls_gp_Cylinder.def("Mirrored", (gp_Cylinder (gp_Cylinder::*)(const gp_Ax2 &) const) &gp_Cylinder::Mirrored, "Performs the symmetrical transformation of a cylinder with respect to a plane. The axis placement A2 locates the plane of the of the symmetry : (Location, XDirection, YDirection).", py::arg("A2"));
cls_gp_Cylinder.def("Rotate", (void (gp_Cylinder::*)(const gp_Ax1 &, const Standard_Real)) &gp_Cylinder::Rotate, "None", py::arg("A1"), py::arg("Ang"));
cls_gp_Cylinder.def("Rotated", (gp_Cylinder (gp_Cylinder::*)(const gp_Ax1 &, const Standard_Real) const) &gp_Cylinder::Rotated, "Rotates a cylinder. A1 is the axis of the rotation. Ang is the angular value of the rotation in radians.", py::arg("A1"), py::arg("Ang"));
cls_gp_Cylinder.def("Scale", (void (gp_Cylinder::*)(const gp_Pnt &, const Standard_Real)) &gp_Cylinder::Scale, "None", py::arg("P"), py::arg("S"));
cls_gp_Cylinder.def("Scaled", (gp_Cylinder (gp_Cylinder::*)(const gp_Pnt &, const Standard_Real) const) &gp_Cylinder::Scaled, "Scales a cylinder. S is the scaling value. The absolute value of S is used to scale the cylinder", py::arg("P"), py::arg("S"));
cls_gp_Cylinder.def("Transform", (void (gp_Cylinder::*)(const gp_Trsf &)) &gp_Cylinder::Transform, "None", py::arg("T"));
cls_gp_Cylinder.def("Transformed", (gp_Cylinder (gp_Cylinder::*)(const gp_Trsf &) const) &gp_Cylinder::Transformed, "Transforms a cylinder with the transformation T from class Trsf.", py::arg("T"));
cls_gp_Cylinder.def("Translate", (void (gp_Cylinder::*)(const gp_Vec &)) &gp_Cylinder::Translate, "None", py::arg("V"));
cls_gp_Cylinder.def("Translated", (gp_Cylinder (gp_Cylinder::*)(const gp_Vec &) const) &gp_Cylinder::Translated, "Translates a cylinder in the direction of the vector V. The magnitude of the translation is the vector's magnitude.", py::arg("V"));
cls_gp_Cylinder.def("Translate", (void (gp_Cylinder::*)(const gp_Pnt &, const gp_Pnt &)) &gp_Cylinder::Translate, "None", py::arg("P1"), py::arg("P2"));
cls_gp_Cylinder.def("Translated", (gp_Cylinder (gp_Cylinder::*)(const gp_Pnt &, const gp_Pnt &) const) &gp_Cylinder::Translated, "Translates a cylinder from the point P1 to the point P2.", py::arg("P1"), py::arg("P2"));

// Enums

}