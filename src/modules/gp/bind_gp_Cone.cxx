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
#include <gp_Cone.hxx>
#include <gp_Ax2.hxx>
#include <gp_Trsf.hxx>
#include <gp_Vec.hxx>

void bind_gp_Cone(py::module &mod){

py::class_<gp_Cone> cls_gp_Cone(mod, "gp_Cone", "Defines an infinite conical surface. A cone is defined by its half-angle at the apex and positioned in space with a coordinate system (a gp_Ax3 object) and a 'reference radius' where: - the 'main Axis' of the coordinate system is the axis of revolution of the cone, - the plane defined by the origin, the 'X Direction' and the 'Y Direction' of the coordinate system is the reference plane of the cone; the intersection of the cone with this reference plane is a circle of radius equal to the reference radius, if the half-angle is positive, the apex of the cone is on the negative side of the 'main Axis' of the coordinate system. If the half-angle is negative, the apex is on the positive side. This coordinate system is the 'local coordinate system' of the cone. Note: when a gp_Cone cone is converted into a Geom_ConicalSurface cone, some implicit properties of its local coordinate system are used explicitly: - its origin, 'X Direction', 'Y Direction' and 'main Direction' are used directly to define the parametric directions on the cone and the origin of the parameters, - its implicit orientation (right-handed or left-handed) gives the orientation (direct or indirect) of the Geom_ConicalSurface cone. See Also gce_MakeCone which provides functions for more complex cone constructions Geom_ConicalSurface which provides additional functions for constructing cones and works, in particular, with the parametric equations of cones gp_Ax3");

// Constructors
cls_gp_Cone.def(py::init<>());
cls_gp_Cone.def(py::init<const gp_Ax3 &, const Standard_Real, const Standard_Real>(), py::arg("A3"), py::arg("Ang"), py::arg("Radius"));

// Fields

// Methods
// cls_gp_Cone.def_static("operator new_", (void * (*)(size_t)) &gp_Cone::operator new, "None", py::arg("theSize"));
// cls_gp_Cone.def_static("operator delete_", (void (*)(void *)) &gp_Cone::operator delete, "None", py::arg("theAddress"));
// cls_gp_Cone.def_static("operator new[]_", (void * (*)(size_t)) &gp_Cone::operator new[], "None", py::arg("theSize"));
// cls_gp_Cone.def_static("operator delete[]_", (void (*)(void *)) &gp_Cone::operator delete[], "None", py::arg("theAddress"));
// cls_gp_Cone.def_static("operator new_", (void * (*)(size_t, void *)) &gp_Cone::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gp_Cone.def_static("operator delete_", (void (*)(void *, void *)) &gp_Cone::operator delete, "None", py::arg(""), py::arg(""));
cls_gp_Cone.def("SetAxis", (void (gp_Cone::*)(const gp_Ax1 &)) &gp_Cone::SetAxis, "Changes the symmetry axis of the cone. Raises ConstructionError the direction of A1 is parallel to the 'XDirection' of the coordinate system of the cone.", py::arg("A1"));
cls_gp_Cone.def("SetLocation", (void (gp_Cone::*)(const gp_Pnt &)) &gp_Cone::SetLocation, "Changes the location of the cone.", py::arg("Loc"));
cls_gp_Cone.def("SetPosition", (void (gp_Cone::*)(const gp_Ax3 &)) &gp_Cone::SetPosition, "Changes the local coordinate system of the cone. This coordinate system defines the reference plane of the cone.", py::arg("A3"));
cls_gp_Cone.def("SetRadius", (void (gp_Cone::*)(const Standard_Real)) &gp_Cone::SetRadius, "Changes the radius of the cone in the reference plane of the cone. Raised if R < 0.0", py::arg("R"));
cls_gp_Cone.def("SetSemiAngle", (void (gp_Cone::*)(const Standard_Real)) &gp_Cone::SetSemiAngle, "Changes the semi-angle of the cone. Ang is the conical surface semi-angle ]0,PI/2[. Raises ConstructionError if Ang < Resolution from gp or Ang >= PI/2 - Resolution", py::arg("Ang"));
cls_gp_Cone.def("Apex", (gp_Pnt (gp_Cone::*)() const) &gp_Cone::Apex, "Computes the cone's top. The Apex of the cone is on the negative side of the symmetry axis of the cone.");
cls_gp_Cone.def("UReverse", (void (gp_Cone::*)()) &gp_Cone::UReverse, "Reverses the U parametrization of the cone reversing the YAxis.");
cls_gp_Cone.def("VReverse", (void (gp_Cone::*)()) &gp_Cone::VReverse, "Reverses the V parametrization of the cone reversing the ZAxis.");
cls_gp_Cone.def("Direct", (Standard_Boolean (gp_Cone::*)() const) &gp_Cone::Direct, "Returns true if the local coordinate system of this cone is right-handed.");
cls_gp_Cone.def("Axis", (const gp_Ax1 & (gp_Cone::*)() const) &gp_Cone::Axis, "returns the symmetry axis of the cone.");
cls_gp_Cone.def("Coefficients", [](gp_Cone &self, Standard_Real & A1, Standard_Real & A2, Standard_Real & A3, Standard_Real & B1, Standard_Real & B2, Standard_Real & B3, Standard_Real & C1, Standard_Real & C2, Standard_Real & C3, Standard_Real & D){ self.Coefficients(A1, A2, A3, B1, B2, B3, C1, C2, C3, D); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(A1, A2, A3, B1, B2, B3, C1, C2, C3, D); }, "Computes the coefficients of the implicit equation of the quadric in the absolute cartesian coordinates system : A1.X**2 + A2.Y**2 + A3.Z**2 + 2.(B1.X.Y + B2.X.Z + B3.Y.Z) + 2.(C1.X + C2.Y + C3.Z) + D = 0.0", py::arg("A1"), py::arg("A2"), py::arg("A3"), py::arg("B1"), py::arg("B2"), py::arg("B3"), py::arg("C1"), py::arg("C2"), py::arg("C3"), py::arg("D"));
cls_gp_Cone.def("Location", (const gp_Pnt & (gp_Cone::*)() const) &gp_Cone::Location, "returns the 'Location' point of the cone.");
cls_gp_Cone.def("Position", (const gp_Ax3 & (gp_Cone::*)() const) &gp_Cone::Position, "Returns the local coordinates system of the cone.");
cls_gp_Cone.def("RefRadius", (Standard_Real (gp_Cone::*)() const) &gp_Cone::RefRadius, "Returns the radius of the cone in the reference plane.");
cls_gp_Cone.def("SemiAngle", (Standard_Real (gp_Cone::*)() const) &gp_Cone::SemiAngle, "Returns the half-angle at the apex of this cone.");
cls_gp_Cone.def("XAxis", (gp_Ax1 (gp_Cone::*)() const) &gp_Cone::XAxis, "Returns the XAxis of the reference plane.");
cls_gp_Cone.def("YAxis", (gp_Ax1 (gp_Cone::*)() const) &gp_Cone::YAxis, "Returns the YAxis of the reference plane.");
cls_gp_Cone.def("Mirror", (void (gp_Cone::*)(const gp_Pnt &)) &gp_Cone::Mirror, "None", py::arg("P"));
cls_gp_Cone.def("Mirrored", (gp_Cone (gp_Cone::*)(const gp_Pnt &) const) &gp_Cone::Mirrored, "Performs the symmetrical transformation of a cone with respect to the point P which is the center of the symmetry.", py::arg("P"));
cls_gp_Cone.def("Mirror", (void (gp_Cone::*)(const gp_Ax1 &)) &gp_Cone::Mirror, "None", py::arg("A1"));
cls_gp_Cone.def("Mirrored", (gp_Cone (gp_Cone::*)(const gp_Ax1 &) const) &gp_Cone::Mirrored, "Performs the symmetrical transformation of a cone with respect to an axis placement which is the axis of the symmetry.", py::arg("A1"));
cls_gp_Cone.def("Mirror", (void (gp_Cone::*)(const gp_Ax2 &)) &gp_Cone::Mirror, "None", py::arg("A2"));
cls_gp_Cone.def("Mirrored", (gp_Cone (gp_Cone::*)(const gp_Ax2 &) const) &gp_Cone::Mirrored, "Performs the symmetrical transformation of a cone with respect to a plane. The axis placement A2 locates the plane of the of the symmetry : (Location, XDirection, YDirection).", py::arg("A2"));
cls_gp_Cone.def("Rotate", (void (gp_Cone::*)(const gp_Ax1 &, const Standard_Real)) &gp_Cone::Rotate, "None", py::arg("A1"), py::arg("Ang"));
cls_gp_Cone.def("Rotated", (gp_Cone (gp_Cone::*)(const gp_Ax1 &, const Standard_Real) const) &gp_Cone::Rotated, "Rotates a cone. A1 is the axis of the rotation. Ang is the angular value of the rotation in radians.", py::arg("A1"), py::arg("Ang"));
cls_gp_Cone.def("Scale", (void (gp_Cone::*)(const gp_Pnt &, const Standard_Real)) &gp_Cone::Scale, "None", py::arg("P"), py::arg("S"));
cls_gp_Cone.def("Scaled", (gp_Cone (gp_Cone::*)(const gp_Pnt &, const Standard_Real) const) &gp_Cone::Scaled, "Scales a cone. S is the scaling value. The absolute value of S is used to scale the cone", py::arg("P"), py::arg("S"));
cls_gp_Cone.def("Transform", (void (gp_Cone::*)(const gp_Trsf &)) &gp_Cone::Transform, "None", py::arg("T"));
cls_gp_Cone.def("Transformed", (gp_Cone (gp_Cone::*)(const gp_Trsf &) const) &gp_Cone::Transformed, "Transforms a cone with the transformation T from class Trsf.", py::arg("T"));
cls_gp_Cone.def("Translate", (void (gp_Cone::*)(const gp_Vec &)) &gp_Cone::Translate, "None", py::arg("V"));
cls_gp_Cone.def("Translated", (gp_Cone (gp_Cone::*)(const gp_Vec &) const) &gp_Cone::Translated, "Translates a cone in the direction of the vector V. The magnitude of the translation is the vector's magnitude.", py::arg("V"));
cls_gp_Cone.def("Translate", (void (gp_Cone::*)(const gp_Pnt &, const gp_Pnt &)) &gp_Cone::Translate, "None", py::arg("P1"), py::arg("P2"));
cls_gp_Cone.def("Translated", (gp_Cone (gp_Cone::*)(const gp_Pnt &, const gp_Pnt &) const) &gp_Cone::Translated, "Translates a cone from the point P1 to the point P2.", py::arg("P1"), py::arg("P2"));

// Enums

}