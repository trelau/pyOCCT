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
#include <gp_Pnt.hxx>
#include <gp_Ax1.hxx>
#include <gp_Sphere.hxx>
#include <gp_Ax2.hxx>
#include <gp_Trsf.hxx>
#include <gp_Vec.hxx>

void bind_gp_Sphere(py::module &mod){

py::class_<gp_Sphere, std::unique_ptr<gp_Sphere, Deleter<gp_Sphere>>> cls_gp_Sphere(mod, "gp_Sphere", "Describes a sphere. A sphere is defined by its radius and positioned in space with a coordinate system (a gp_Ax3 object). The origin of the coordinate system is the center of the sphere. This coordinate system is the 'local coordinate system' of the sphere. Note: when a gp_Sphere sphere is converted into a Geom_SphericalSurface sphere, some implicit properties of its local coordinate system are used explicitly: - its origin, 'X Direction', 'Y Direction' and 'main Direction' are used directly to define the parametric directions on the sphere and the origin of the parameters, - its implicit orientation (right-handed or left-handed) gives the orientation (direct, indirect) to the Geom_SphericalSurface sphere. See Also gce_MakeSphere which provides functions for more complex sphere constructions Geom_SphericalSurface which provides additional functions for constructing spheres and works, in particular, with the parametric equations of spheres.");

// Constructors
cls_gp_Sphere.def(py::init<>());
cls_gp_Sphere.def(py::init<const gp_Ax3 &, const Standard_Real>(), py::arg("A3"), py::arg("Radius"));

// Fields

// Methods
// cls_gp_Sphere.def_static("operator new_", (void * (*)(size_t)) &gp_Sphere::operator new, "None", py::arg("theSize"));
// cls_gp_Sphere.def_static("operator delete_", (void (*)(void *)) &gp_Sphere::operator delete, "None", py::arg("theAddress"));
// cls_gp_Sphere.def_static("operator new[]_", (void * (*)(size_t)) &gp_Sphere::operator new[], "None", py::arg("theSize"));
// cls_gp_Sphere.def_static("operator delete[]_", (void (*)(void *)) &gp_Sphere::operator delete[], "None", py::arg("theAddress"));
// cls_gp_Sphere.def_static("operator new_", (void * (*)(size_t, void *)) &gp_Sphere::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gp_Sphere.def_static("operator delete_", (void (*)(void *, void *)) &gp_Sphere::operator delete, "None", py::arg(""), py::arg(""));
cls_gp_Sphere.def("SetLocation", (void (gp_Sphere::*)(const gp_Pnt &)) &gp_Sphere::SetLocation, "Changes the center of the sphere.", py::arg("Loc"));
cls_gp_Sphere.def("SetPosition", (void (gp_Sphere::*)(const gp_Ax3 &)) &gp_Sphere::SetPosition, "Changes the local coordinate system of the sphere.", py::arg("A3"));
cls_gp_Sphere.def("SetRadius", (void (gp_Sphere::*)(const Standard_Real)) &gp_Sphere::SetRadius, "Assigns R the radius of the Sphere. Warnings : It is not forbidden to create a sphere with null radius. Raises ConstructionError if R < 0.0", py::arg("R"));
cls_gp_Sphere.def("Area", (Standard_Real (gp_Sphere::*)() const) &gp_Sphere::Area, "Computes the aera of the sphere.");
cls_gp_Sphere.def("Coefficients", [](gp_Sphere &self, Standard_Real & A1, Standard_Real & A2, Standard_Real & A3, Standard_Real & B1, Standard_Real & B2, Standard_Real & B3, Standard_Real & C1, Standard_Real & C2, Standard_Real & C3, Standard_Real & D){ self.Coefficients(A1, A2, A3, B1, B2, B3, C1, C2, C3, D); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(A1, A2, A3, B1, B2, B3, C1, C2, C3, D); }, "Computes the coefficients of the implicit equation of the quadric in the absolute cartesian coordinates system : A1.X**2 + A2.Y**2 + A3.Z**2 + 2.(B1.X.Y + B2.X.Z + B3.Y.Z) + 2.(C1.X + C2.Y + C3.Z) + D = 0.0", py::arg("A1"), py::arg("A2"), py::arg("A3"), py::arg("B1"), py::arg("B2"), py::arg("B3"), py::arg("C1"), py::arg("C2"), py::arg("C3"), py::arg("D"));
cls_gp_Sphere.def("UReverse", (void (gp_Sphere::*)()) &gp_Sphere::UReverse, "Reverses the U parametrization of the sphere reversing the YAxis.");
cls_gp_Sphere.def("VReverse", (void (gp_Sphere::*)()) &gp_Sphere::VReverse, "Reverses the V parametrization of the sphere reversing the ZAxis.");
cls_gp_Sphere.def("Direct", (Standard_Boolean (gp_Sphere::*)() const) &gp_Sphere::Direct, "Returns true if the local coordinate system of this sphere is right-handed.");
cls_gp_Sphere.def("Location", (const gp_Pnt & (gp_Sphere::*)() const) &gp_Sphere::Location, "--- Purpose ; Returns the center of the sphere.");
cls_gp_Sphere.def("Position", (const gp_Ax3 & (gp_Sphere::*)() const) &gp_Sphere::Position, "Returns the local coordinates system of the sphere.");
cls_gp_Sphere.def("Radius", (Standard_Real (gp_Sphere::*)() const) &gp_Sphere::Radius, "Returns the radius of the sphere.");
cls_gp_Sphere.def("Volume", (Standard_Real (gp_Sphere::*)() const) &gp_Sphere::Volume, "Computes the volume of the sphere");
cls_gp_Sphere.def("XAxis", (gp_Ax1 (gp_Sphere::*)() const) &gp_Sphere::XAxis, "Returns the axis X of the sphere.");
cls_gp_Sphere.def("YAxis", (gp_Ax1 (gp_Sphere::*)() const) &gp_Sphere::YAxis, "Returns the axis Y of the sphere.");
cls_gp_Sphere.def("Mirror", (void (gp_Sphere::*)(const gp_Pnt &)) &gp_Sphere::Mirror, "None", py::arg("P"));
cls_gp_Sphere.def("Mirrored", (gp_Sphere (gp_Sphere::*)(const gp_Pnt &) const) &gp_Sphere::Mirrored, "Performs the symmetrical transformation of a sphere with respect to the point P which is the center of the symmetry.", py::arg("P"));
cls_gp_Sphere.def("Mirror", (void (gp_Sphere::*)(const gp_Ax1 &)) &gp_Sphere::Mirror, "None", py::arg("A1"));
cls_gp_Sphere.def("Mirrored", (gp_Sphere (gp_Sphere::*)(const gp_Ax1 &) const) &gp_Sphere::Mirrored, "Performs the symmetrical transformation of a sphere with respect to an axis placement which is the axis of the symmetry.", py::arg("A1"));
cls_gp_Sphere.def("Mirror", (void (gp_Sphere::*)(const gp_Ax2 &)) &gp_Sphere::Mirror, "None", py::arg("A2"));
cls_gp_Sphere.def("Mirrored", (gp_Sphere (gp_Sphere::*)(const gp_Ax2 &) const) &gp_Sphere::Mirrored, "Performs the symmetrical transformation of a sphere with respect to a plane. The axis placement A2 locates the plane of the of the symmetry : (Location, XDirection, YDirection).", py::arg("A2"));
cls_gp_Sphere.def("Rotate", (void (gp_Sphere::*)(const gp_Ax1 &, const Standard_Real)) &gp_Sphere::Rotate, "None", py::arg("A1"), py::arg("Ang"));
cls_gp_Sphere.def("Rotated", (gp_Sphere (gp_Sphere::*)(const gp_Ax1 &, const Standard_Real) const) &gp_Sphere::Rotated, "Rotates a sphere. A1 is the axis of the rotation. Ang is the angular value of the rotation in radians.", py::arg("A1"), py::arg("Ang"));
cls_gp_Sphere.def("Scale", (void (gp_Sphere::*)(const gp_Pnt &, const Standard_Real)) &gp_Sphere::Scale, "None", py::arg("P"), py::arg("S"));
cls_gp_Sphere.def("Scaled", (gp_Sphere (gp_Sphere::*)(const gp_Pnt &, const Standard_Real) const) &gp_Sphere::Scaled, "Scales a sphere. S is the scaling value. The absolute value of S is used to scale the sphere", py::arg("P"), py::arg("S"));
cls_gp_Sphere.def("Transform", (void (gp_Sphere::*)(const gp_Trsf &)) &gp_Sphere::Transform, "None", py::arg("T"));
cls_gp_Sphere.def("Transformed", (gp_Sphere (gp_Sphere::*)(const gp_Trsf &) const) &gp_Sphere::Transformed, "Transforms a sphere with the transformation T from class Trsf.", py::arg("T"));
cls_gp_Sphere.def("Translate", (void (gp_Sphere::*)(const gp_Vec &)) &gp_Sphere::Translate, "None", py::arg("V"));
cls_gp_Sphere.def("Translated", (gp_Sphere (gp_Sphere::*)(const gp_Vec &) const) &gp_Sphere::Translated, "Translates a sphere in the direction of the vector V. The magnitude of the translation is the vector's magnitude.", py::arg("V"));
cls_gp_Sphere.def("Translate", (void (gp_Sphere::*)(const gp_Pnt &, const gp_Pnt &)) &gp_Sphere::Translate, "None", py::arg("P1"), py::arg("P2"));
cls_gp_Sphere.def("Translated", (gp_Sphere (gp_Sphere::*)(const gp_Pnt &, const gp_Pnt &) const) &gp_Sphere::Translated, "Translates a sphere from the point P1 to the point P2.", py::arg("P1"), py::arg("P2"));

// Enums

}