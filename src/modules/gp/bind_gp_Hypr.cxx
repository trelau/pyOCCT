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
#include <gp_Hypr.hxx>
#include <gp_Trsf.hxx>
#include <gp_Vec.hxx>

void bind_gp_Hypr(py::module &mod){

py::class_<gp_Hypr, std::unique_ptr<gp_Hypr>> cls_gp_Hypr(mod, "gp_Hypr", "Describes a branch of a hyperbola in 3D space. A hyperbola is defined by its major and minor radii and positioned in space with a coordinate system (a gp_Ax2 object) of which: - the origin is the center of the hyperbola, - the 'X Direction' defines the major axis of the hyperbola, and - the 'Y Direction' defines the minor axis of the hyperbola. The origin, 'X Direction' and 'Y Direction' of this coordinate system together define the plane of the hyperbola. This coordinate system is the 'local coordinate system' of the hyperbola. In this coordinate system, the equation of the hyperbola is: X*X/(MajorRadius**2)-Y*Y/(MinorRadius**2) = 1.0 The branch of the hyperbola described is the one located on the positive side of the major axis. The 'main Direction' of the local coordinate system is a normal vector to the plane of the hyperbola. This vector gives an implicit orientation to the hyperbola. We refer to the 'main Axis' of the local coordinate system as the 'Axis' of the hyperbola. The following schema shows the plane of the hyperbola, and in it, the respective positions of the three branches of hyperbolas constructed with the functions OtherBranch, ConjugateBranch1, and ConjugateBranch2:");

// Constructors
cls_gp_Hypr.def(py::init<>());
cls_gp_Hypr.def(py::init<const gp_Ax2 &, const Standard_Real, const Standard_Real>(), py::arg("A2"), py::arg("MajorRadius"), py::arg("MinorRadius"));

// Fields

// Methods
// cls_gp_Hypr.def_static("operator new_", (void * (*)(size_t)) &gp_Hypr::operator new, "None", py::arg("theSize"));
// cls_gp_Hypr.def_static("operator delete_", (void (*)(void *)) &gp_Hypr::operator delete, "None", py::arg("theAddress"));
// cls_gp_Hypr.def_static("operator new[]_", (void * (*)(size_t)) &gp_Hypr::operator new[], "None", py::arg("theSize"));
// cls_gp_Hypr.def_static("operator delete[]_", (void (*)(void *)) &gp_Hypr::operator delete[], "None", py::arg("theAddress"));
// cls_gp_Hypr.def_static("operator new_", (void * (*)(size_t, void *)) &gp_Hypr::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gp_Hypr.def_static("operator delete_", (void (*)(void *, void *)) &gp_Hypr::operator delete, "None", py::arg(""), py::arg(""));
cls_gp_Hypr.def("SetAxis", (void (gp_Hypr::*)(const gp_Ax1 &)) &gp_Hypr::SetAxis, "Modifies this hyperbola, by redefining its local coordinate system so that: - its origin and 'main Direction' become those of the axis A1 (the 'X Direction' and 'Y Direction' are then recomputed in the same way as for any gp_Ax2). Raises ConstructionError if the direction of A1 is parallel to the direction of the 'XAxis' of the hyperbola.", py::arg("A1"));
cls_gp_Hypr.def("SetLocation", (void (gp_Hypr::*)(const gp_Pnt &)) &gp_Hypr::SetLocation, "Modifies this hyperbola, by redefining its local coordinate system so that its origin becomes P.", py::arg("P"));
cls_gp_Hypr.def("SetMajorRadius", (void (gp_Hypr::*)(const Standard_Real)) &gp_Hypr::SetMajorRadius, "Modifies the major radius of this hyperbola. Exceptions Standard_ConstructionError if MajorRadius is negative.", py::arg("MajorRadius"));
cls_gp_Hypr.def("SetMinorRadius", (void (gp_Hypr::*)(const Standard_Real)) &gp_Hypr::SetMinorRadius, "Modifies the minor radius of this hyperbola. Exceptions Standard_ConstructionError if MinorRadius is negative.", py::arg("MinorRadius"));
cls_gp_Hypr.def("SetPosition", (void (gp_Hypr::*)(const gp_Ax2 &)) &gp_Hypr::SetPosition, "Modifies this hyperbola, by redefining its local coordinate system so that it becomes A2.", py::arg("A2"));
cls_gp_Hypr.def("Asymptote1", (gp_Ax1 (gp_Hypr::*)() const) &gp_Hypr::Asymptote1, "In the local coordinate system of the hyperbola the equation of the hyperbola is (X*X)/(A*A) - (Y*Y)/(B*B) = 1.0 and the equation of the first asymptote is Y = (B/A)*X where A is the major radius and B is the minor radius. Raises ConstructionError if MajorRadius = 0.0");
cls_gp_Hypr.def("Asymptote2", (gp_Ax1 (gp_Hypr::*)() const) &gp_Hypr::Asymptote2, "In the local coordinate system of the hyperbola the equation of the hyperbola is (X*X)/(A*A) - (Y*Y)/(B*B) = 1.0 and the equation of the first asymptote is Y = -(B/A)*X. where A is the major radius and B is the minor radius. Raises ConstructionError if MajorRadius = 0.0");
cls_gp_Hypr.def("Axis", (const gp_Ax1 & (gp_Hypr::*)() const) &gp_Hypr::Axis, "Returns the axis passing through the center, and normal to the plane of this hyperbola.");
cls_gp_Hypr.def("ConjugateBranch1", (gp_Hypr (gp_Hypr::*)() const) &gp_Hypr::ConjugateBranch1, "Computes the branch of hyperbola which is on the positive side of the 'YAxis' of <me>.");
cls_gp_Hypr.def("ConjugateBranch2", (gp_Hypr (gp_Hypr::*)() const) &gp_Hypr::ConjugateBranch2, "Computes the branch of hyperbola which is on the negative side of the 'YAxis' of <me>.");
cls_gp_Hypr.def("Directrix1", (gp_Ax1 (gp_Hypr::*)() const) &gp_Hypr::Directrix1, "This directrix is the line normal to the XAxis of the hyperbola in the local plane (Z = 0) at a distance d = MajorRadius / e from the center of the hyperbola, where e is the eccentricity of the hyperbola. This line is parallel to the 'YAxis'. The intersection point between the directrix1 and the 'XAxis' is the 'Location' point of the directrix1. This point is on the positive side of the 'XAxis'.");
cls_gp_Hypr.def("Directrix2", (gp_Ax1 (gp_Hypr::*)() const) &gp_Hypr::Directrix2, "This line is obtained by the symmetrical transformation of 'Directrix1' with respect to the 'YAxis' of the hyperbola.");
cls_gp_Hypr.def("Eccentricity", (Standard_Real (gp_Hypr::*)() const) &gp_Hypr::Eccentricity, "Returns the excentricity of the hyperbola (e > 1). If f is the distance between the location of the hyperbola and the Focus1 then the eccentricity e = f / MajorRadius. Raises DomainError if MajorRadius = 0.0");
cls_gp_Hypr.def("Focal", (Standard_Real (gp_Hypr::*)() const) &gp_Hypr::Focal, "Computes the focal distance. It is the distance between the the two focus of the hyperbola.");
cls_gp_Hypr.def("Focus1", (gp_Pnt (gp_Hypr::*)() const) &gp_Hypr::Focus1, "Returns the first focus of the hyperbola. This focus is on the positive side of the 'XAxis' of the hyperbola.");
cls_gp_Hypr.def("Focus2", (gp_Pnt (gp_Hypr::*)() const) &gp_Hypr::Focus2, "Returns the second focus of the hyperbola. This focus is on the negative side of the 'XAxis' of the hyperbola.");
cls_gp_Hypr.def("Location", (const gp_Pnt & (gp_Hypr::*)() const) &gp_Hypr::Location, "Returns the location point of the hyperbola. It is the intersection point between the 'XAxis' and the 'YAxis'.");
cls_gp_Hypr.def("MajorRadius", (Standard_Real (gp_Hypr::*)() const) &gp_Hypr::MajorRadius, "Returns the major radius of the hyperbola. It is the radius on the 'XAxis' of the hyperbola.");
cls_gp_Hypr.def("MinorRadius", (Standard_Real (gp_Hypr::*)() const) &gp_Hypr::MinorRadius, "Returns the minor radius of the hyperbola. It is the radius on the 'YAxis' of the hyperbola.");
cls_gp_Hypr.def("OtherBranch", (gp_Hypr (gp_Hypr::*)() const) &gp_Hypr::OtherBranch, "Returns the branch of hyperbola obtained by doing the symmetrical transformation of <me> with respect to the 'YAxis' of <me>.");
cls_gp_Hypr.def("Parameter", (Standard_Real (gp_Hypr::*)() const) &gp_Hypr::Parameter, "Returns p = (e * e - 1) * MajorRadius where e is the eccentricity of the hyperbola. Raises DomainError if MajorRadius = 0.0");
cls_gp_Hypr.def("Position", (const gp_Ax2 & (gp_Hypr::*)() const) &gp_Hypr::Position, "Returns the coordinate system of the hyperbola.");
cls_gp_Hypr.def("XAxis", (gp_Ax1 (gp_Hypr::*)() const) &gp_Hypr::XAxis, "Computes an axis, whose - the origin is the center of this hyperbola, and - the unit vector is the 'X Direction' of the local coordinate system of this hyperbola. These axes are, the major axis (the 'X Axis') and of this hyperboReturns the 'XAxis' of the hyperbola.");
cls_gp_Hypr.def("YAxis", (gp_Ax1 (gp_Hypr::*)() const) &gp_Hypr::YAxis, "Computes an axis, whose - the origin is the center of this hyperbola, and - the unit vector is the 'Y Direction' of the local coordinate system of this hyperbola. These axes are the minor axis (the 'Y Axis') of this hyperbola");
cls_gp_Hypr.def("Mirror", (void (gp_Hypr::*)(const gp_Pnt &)) &gp_Hypr::Mirror, "None", py::arg("P"));
cls_gp_Hypr.def("Mirrored", (gp_Hypr (gp_Hypr::*)(const gp_Pnt &) const) &gp_Hypr::Mirrored, "Performs the symmetrical transformation of an hyperbola with respect to the point P which is the center of the symmetry.", py::arg("P"));
cls_gp_Hypr.def("Mirror", (void (gp_Hypr::*)(const gp_Ax1 &)) &gp_Hypr::Mirror, "None", py::arg("A1"));
cls_gp_Hypr.def("Mirrored", (gp_Hypr (gp_Hypr::*)(const gp_Ax1 &) const) &gp_Hypr::Mirrored, "Performs the symmetrical transformation of an hyperbola with respect to an axis placement which is the axis of the symmetry.", py::arg("A1"));
cls_gp_Hypr.def("Mirror", (void (gp_Hypr::*)(const gp_Ax2 &)) &gp_Hypr::Mirror, "None", py::arg("A2"));
cls_gp_Hypr.def("Mirrored", (gp_Hypr (gp_Hypr::*)(const gp_Ax2 &) const) &gp_Hypr::Mirrored, "Performs the symmetrical transformation of an hyperbola with respect to a plane. The axis placement A2 locates the plane of the symmetry (Location, XDirection, YDirection).", py::arg("A2"));
cls_gp_Hypr.def("Rotate", (void (gp_Hypr::*)(const gp_Ax1 &, const Standard_Real)) &gp_Hypr::Rotate, "None", py::arg("A1"), py::arg("Ang"));
cls_gp_Hypr.def("Rotated", (gp_Hypr (gp_Hypr::*)(const gp_Ax1 &, const Standard_Real) const) &gp_Hypr::Rotated, "Rotates an hyperbola. A1 is the axis of the rotation. Ang is the angular value of the rotation in radians.", py::arg("A1"), py::arg("Ang"));
cls_gp_Hypr.def("Scale", (void (gp_Hypr::*)(const gp_Pnt &, const Standard_Real)) &gp_Hypr::Scale, "None", py::arg("P"), py::arg("S"));
cls_gp_Hypr.def("Scaled", (gp_Hypr (gp_Hypr::*)(const gp_Pnt &, const Standard_Real) const) &gp_Hypr::Scaled, "Scales an hyperbola. S is the scaling value.", py::arg("P"), py::arg("S"));
cls_gp_Hypr.def("Transform", (void (gp_Hypr::*)(const gp_Trsf &)) &gp_Hypr::Transform, "None", py::arg("T"));
cls_gp_Hypr.def("Transformed", (gp_Hypr (gp_Hypr::*)(const gp_Trsf &) const) &gp_Hypr::Transformed, "Transforms an hyperbola with the transformation T from class Trsf.", py::arg("T"));
cls_gp_Hypr.def("Translate", (void (gp_Hypr::*)(const gp_Vec &)) &gp_Hypr::Translate, "None", py::arg("V"));
cls_gp_Hypr.def("Translated", (gp_Hypr (gp_Hypr::*)(const gp_Vec &) const) &gp_Hypr::Translated, "Translates an hyperbola in the direction of the vector V. The magnitude of the translation is the vector's magnitude.", py::arg("V"));
cls_gp_Hypr.def("Translate", (void (gp_Hypr::*)(const gp_Pnt &, const gp_Pnt &)) &gp_Hypr::Translate, "None", py::arg("P1"), py::arg("P2"));
cls_gp_Hypr.def("Translated", (gp_Hypr (gp_Hypr::*)(const gp_Pnt &, const gp_Pnt &) const) &gp_Hypr::Translated, "Translates an hyperbola from the point P1 to the point P2.", py::arg("P1"), py::arg("P2"));

// Enums

}