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
#include <TColStd_Array1OfReal.hxx>
#include <gp_Torus.hxx>
#include <gp_Ax2.hxx>
#include <gp_Trsf.hxx>
#include <gp_Vec.hxx>

void bind_gp_Torus(py::module &mod){

py::class_<gp_Torus, std::unique_ptr<gp_Torus>> cls_gp_Torus(mod, "gp_Torus", "Describes a torus. A torus is defined by its major and minor radii and positioned in space with a coordinate system (a gp_Ax3 object) as follows: - The origin of the coordinate system is the center of the torus; - The surface is obtained by rotating a circle of radius equal to the minor radius of the torus about the 'main Direction' of the coordinate system. This circle is located in the plane defined by the origin, the 'X Direction' and the 'main Direction' of the coordinate system. It is centered on the 'X Axis' of this coordinate system, and located at a distance, from the origin of this coordinate system, equal to the major radius of the torus; - The 'X Direction' and 'Y Direction' define the reference plane of the torus. The coordinate system described above is the 'local coordinate system' of the torus. Note: when a gp_Torus torus is converted into a Geom_ToroidalSurface torus, some implicit properties of its local coordinate system are used explicitly: - its origin, 'X Direction', 'Y Direction' and 'main Direction' are used directly to define the parametric directions on the torus and the origin of the parameters, - its implicit orientation (right-handed or left-handed) gives the orientation (direct, indirect) to the Geom_ToroidalSurface torus. See Also gce_MakeTorus which provides functions for more complex torus constructions Geom_ToroidalSurface which provides additional functions for constructing tori and works, in particular, with the parametric equations of tori.");

// Constructors
cls_gp_Torus.def(py::init<>());
cls_gp_Torus.def(py::init<const gp_Ax3 &, const Standard_Real, const Standard_Real>(), py::arg("A3"), py::arg("MajorRadius"), py::arg("MinorRadius"));

// Fields

// Methods
// cls_gp_Torus.def_static("operator new_", (void * (*)(size_t)) &gp_Torus::operator new, "None", py::arg("theSize"));
// cls_gp_Torus.def_static("operator delete_", (void (*)(void *)) &gp_Torus::operator delete, "None", py::arg("theAddress"));
// cls_gp_Torus.def_static("operator new[]_", (void * (*)(size_t)) &gp_Torus::operator new[], "None", py::arg("theSize"));
// cls_gp_Torus.def_static("operator delete[]_", (void (*)(void *)) &gp_Torus::operator delete[], "None", py::arg("theAddress"));
// cls_gp_Torus.def_static("operator new_", (void * (*)(size_t, void *)) &gp_Torus::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gp_Torus.def_static("operator delete_", (void (*)(void *, void *)) &gp_Torus::operator delete, "None", py::arg(""), py::arg(""));
cls_gp_Torus.def("SetAxis", (void (gp_Torus::*)(const gp_Ax1 &)) &gp_Torus::SetAxis, "Modifies this torus, by redefining its local coordinate system so that: - its origin and 'main Direction' become those of the axis A1 (the 'X Direction' and 'Y Direction' are then recomputed). Raises ConstructionError if the direction of A1 is parallel to the 'XDirection' of the coordinate system of the toroidal surface.", py::arg("A1"));
cls_gp_Torus.def("SetLocation", (void (gp_Torus::*)(const gp_Pnt &)) &gp_Torus::SetLocation, "Changes the location of the torus.", py::arg("Loc"));
cls_gp_Torus.def("SetMajorRadius", (void (gp_Torus::*)(const Standard_Real)) &gp_Torus::SetMajorRadius, "Assigns value to the major radius of this torus. Raises ConstructionError if MajorRadius - MinorRadius <= Resolution()", py::arg("MajorRadius"));
cls_gp_Torus.def("SetMinorRadius", (void (gp_Torus::*)(const Standard_Real)) &gp_Torus::SetMinorRadius, "Assigns value to the minor radius of this torus. Raises ConstructionError if MinorRadius < 0.0 or if MajorRadius - MinorRadius <= Resolution from gp.", py::arg("MinorRadius"));
cls_gp_Torus.def("SetPosition", (void (gp_Torus::*)(const gp_Ax3 &)) &gp_Torus::SetPosition, "Changes the local coordinate system of the surface.", py::arg("A3"));
cls_gp_Torus.def("Area", (Standard_Real (gp_Torus::*)() const) &gp_Torus::Area, "Computes the area of the torus.");
cls_gp_Torus.def("UReverse", (void (gp_Torus::*)()) &gp_Torus::UReverse, "Reverses the U parametrization of the torus reversing the YAxis.");
cls_gp_Torus.def("VReverse", (void (gp_Torus::*)()) &gp_Torus::VReverse, "Reverses the V parametrization of the torus reversing the ZAxis.");
cls_gp_Torus.def("Direct", (Standard_Boolean (gp_Torus::*)() const) &gp_Torus::Direct, "returns true if the Ax3, the local coordinate system of this torus, is right handed.");
cls_gp_Torus.def("Axis", (const gp_Ax1 & (gp_Torus::*)() const) &gp_Torus::Axis, "returns the symmetry axis of the torus.");
cls_gp_Torus.def("Coefficients", (void (gp_Torus::*)(TColStd_Array1OfReal &) const) &gp_Torus::Coefficients, "Computes the coefficients of the implicit equation of the surface in the absolute Cartesian coordinate system: Coef(1) * X^4 + Coef(2) * Y^4 + Coef(3) * Z^4 + Coef(4) * X^3 * Y + Coef(5) * X^3 * Z + Coef(6) * Y^3 * X + Coef(7) * Y^3 * Z + Coef(8) * Z^3 * X + Coef(9) * Z^3 * Y + Coef(10) * X^2 * Y^2 + Coef(11) * X^2 * Z^2 + Coef(12) * Y^2 * Z^2 + Coef(13) * X^2 * Y * Z + Coef(14) * X * Y^2 * Z + Coef(15) * X * Y * Z^2 + Coef(16) * X^3 + Coef(17) * Y^3 + Coef(18) * Z^3 + Coef(19) * X^2 * Y + Coef(20) * X^2 * Z + Coef(21) * Y^2 * X + Coef(22) * Y^2 * Z + Coef(23) * Z^2 * X + Coef(24) * Z^2 * Y + Coef(25) * X * Y * Z + Coef(26) * X^2 + Coef(27) * Y^2 + Coef(28) * Z^2 + Coef(29) * X * Y + Coef(30) * X * Z + Coef(31) * Y * Z + Coef(32) * X + Coef(33) * Y + Coef(34) * Z + Coef(35) = 0.0 Raises DimensionError if the length of Coef is lower than 35.", py::arg("Coef"));
cls_gp_Torus.def("Location", (const gp_Pnt & (gp_Torus::*)() const) &gp_Torus::Location, "Returns the Torus's location.");
cls_gp_Torus.def("Position", (const gp_Ax3 & (gp_Torus::*)() const) &gp_Torus::Position, "Returns the local coordinates system of the torus.");
cls_gp_Torus.def("MajorRadius", (Standard_Real (gp_Torus::*)() const) &gp_Torus::MajorRadius, "returns the major radius of the torus.");
cls_gp_Torus.def("MinorRadius", (Standard_Real (gp_Torus::*)() const) &gp_Torus::MinorRadius, "returns the minor radius of the torus.");
cls_gp_Torus.def("Volume", (Standard_Real (gp_Torus::*)() const) &gp_Torus::Volume, "Computes the volume of the torus.");
cls_gp_Torus.def("XAxis", (gp_Ax1 (gp_Torus::*)() const) &gp_Torus::XAxis, "returns the axis X of the torus.");
cls_gp_Torus.def("YAxis", (gp_Ax1 (gp_Torus::*)() const) &gp_Torus::YAxis, "returns the axis Y of the torus.");
cls_gp_Torus.def("Mirror", (void (gp_Torus::*)(const gp_Pnt &)) &gp_Torus::Mirror, "None", py::arg("P"));
cls_gp_Torus.def("Mirrored", (gp_Torus (gp_Torus::*)(const gp_Pnt &) const) &gp_Torus::Mirrored, "Performs the symmetrical transformation of a torus with respect to the point P which is the center of the symmetry.", py::arg("P"));
cls_gp_Torus.def("Mirror", (void (gp_Torus::*)(const gp_Ax1 &)) &gp_Torus::Mirror, "None", py::arg("A1"));
cls_gp_Torus.def("Mirrored", (gp_Torus (gp_Torus::*)(const gp_Ax1 &) const) &gp_Torus::Mirrored, "Performs the symmetrical transformation of a torus with respect to an axis placement which is the axis of the symmetry.", py::arg("A1"));
cls_gp_Torus.def("Mirror", (void (gp_Torus::*)(const gp_Ax2 &)) &gp_Torus::Mirror, "None", py::arg("A2"));
cls_gp_Torus.def("Mirrored", (gp_Torus (gp_Torus::*)(const gp_Ax2 &) const) &gp_Torus::Mirrored, "Performs the symmetrical transformation of a torus with respect to a plane. The axis placement A2 locates the plane of the of the symmetry : (Location, XDirection, YDirection).", py::arg("A2"));
cls_gp_Torus.def("Rotate", (void (gp_Torus::*)(const gp_Ax1 &, const Standard_Real)) &gp_Torus::Rotate, "None", py::arg("A1"), py::arg("Ang"));
cls_gp_Torus.def("Rotated", (gp_Torus (gp_Torus::*)(const gp_Ax1 &, const Standard_Real) const) &gp_Torus::Rotated, "Rotates a torus. A1 is the axis of the rotation. Ang is the angular value of the rotation in radians.", py::arg("A1"), py::arg("Ang"));
cls_gp_Torus.def("Scale", (void (gp_Torus::*)(const gp_Pnt &, const Standard_Real)) &gp_Torus::Scale, "None", py::arg("P"), py::arg("S"));
cls_gp_Torus.def("Scaled", (gp_Torus (gp_Torus::*)(const gp_Pnt &, const Standard_Real) const) &gp_Torus::Scaled, "Scales a torus. S is the scaling value. The absolute value of S is used to scale the torus", py::arg("P"), py::arg("S"));
cls_gp_Torus.def("Transform", (void (gp_Torus::*)(const gp_Trsf &)) &gp_Torus::Transform, "None", py::arg("T"));
cls_gp_Torus.def("Transformed", (gp_Torus (gp_Torus::*)(const gp_Trsf &) const) &gp_Torus::Transformed, "Transforms a torus with the transformation T from class Trsf.", py::arg("T"));
cls_gp_Torus.def("Translate", (void (gp_Torus::*)(const gp_Vec &)) &gp_Torus::Translate, "None", py::arg("V"));
cls_gp_Torus.def("Translated", (gp_Torus (gp_Torus::*)(const gp_Vec &) const) &gp_Torus::Translated, "Translates a torus in the direction of the vector V. The magnitude of the translation is the vector's magnitude.", py::arg("V"));
cls_gp_Torus.def("Translate", (void (gp_Torus::*)(const gp_Pnt &, const gp_Pnt &)) &gp_Torus::Translate, "None", py::arg("P1"), py::arg("P2"));
cls_gp_Torus.def("Translated", (gp_Torus (gp_Torus::*)(const gp_Pnt &, const gp_Pnt &) const) &gp_Torus::Translated, "Translates a torus from the point P1 to the point P2.", py::arg("P1"), py::arg("P2"));

// Enums

}