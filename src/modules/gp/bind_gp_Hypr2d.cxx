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
#include <gp_Hypr2d.hxx>
#include <gp_Trsf2d.hxx>
#include <gp_Vec2d.hxx>

void bind_gp_Hypr2d(py::module &mod){

py::class_<gp_Hypr2d, std::unique_ptr<gp_Hypr2d, Deleter<gp_Hypr2d>>> cls_gp_Hypr2d(mod, "gp_Hypr2d", "Describes a branch of a hyperbola in the plane (2D space). A hyperbola is defined by its major and minor radii, and positioned in the plane with a coordinate system (a gp_Ax22d object) of which: - the origin is the center of the hyperbola, - the 'X Direction' defines the major axis of the hyperbola, and - the 'Y Direction' defines the minor axis of the hyperbola. This coordinate system is the 'local coordinate system' of the hyperbola. The orientation of this coordinate system (direct or indirect) gives an implicit orientation to the hyperbola. In this coordinate system, the equation of the hyperbola is: X*X/(MajorRadius**2)-Y*Y/(MinorRadius**2) = 1.0 The branch of the hyperbola described is the one located on the positive side of the major axis. The following schema shows the plane of the hyperbola, and in it, the respective positions of the three branches of hyperbolas constructed with the functions OtherBranch, ConjugateBranch1, and ConjugateBranch2: ^YAxis | FirstConjugateBranch | Other | Main --------------------- C ------------------------------>XAxis Branch | Branch | | SecondConjugateBranch |");

// Constructors
cls_gp_Hypr2d.def(py::init<>());
cls_gp_Hypr2d.def(py::init<const gp_Ax2d &, const Standard_Real, const Standard_Real>(), py::arg("MajorAxis"), py::arg("MajorRadius"), py::arg("MinorRadius"));
cls_gp_Hypr2d.def(py::init<const gp_Ax2d &, const Standard_Real, const Standard_Real, const Standard_Boolean>(), py::arg("MajorAxis"), py::arg("MajorRadius"), py::arg("MinorRadius"), py::arg("Sense"));
cls_gp_Hypr2d.def(py::init<const gp_Ax22d &, const Standard_Real, const Standard_Real>(), py::arg("A"), py::arg("MajorRadius"), py::arg("MinorRadius"));

// Fields

// Methods
// cls_gp_Hypr2d.def_static("operator new_", (void * (*)(size_t)) &gp_Hypr2d::operator new, "None", py::arg("theSize"));
// cls_gp_Hypr2d.def_static("operator delete_", (void (*)(void *)) &gp_Hypr2d::operator delete, "None", py::arg("theAddress"));
// cls_gp_Hypr2d.def_static("operator new[]_", (void * (*)(size_t)) &gp_Hypr2d::operator new[], "None", py::arg("theSize"));
// cls_gp_Hypr2d.def_static("operator delete[]_", (void (*)(void *)) &gp_Hypr2d::operator delete[], "None", py::arg("theAddress"));
// cls_gp_Hypr2d.def_static("operator new_", (void * (*)(size_t, void *)) &gp_Hypr2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gp_Hypr2d.def_static("operator delete_", (void (*)(void *, void *)) &gp_Hypr2d::operator delete, "None", py::arg(""), py::arg(""));
cls_gp_Hypr2d.def("SetLocation", (void (gp_Hypr2d::*)(const gp_Pnt2d &)) &gp_Hypr2d::SetLocation, "Modifies this hyperbola, by redefining its local coordinate system so that its origin becomes P.", py::arg("P"));
cls_gp_Hypr2d.def("SetMajorRadius", (void (gp_Hypr2d::*)(const Standard_Real)) &gp_Hypr2d::SetMajorRadius, "Modifies the major or minor radius of this hyperbola. Exceptions Standard_ConstructionError if MajorRadius or MinorRadius is negative.", py::arg("MajorRadius"));
cls_gp_Hypr2d.def("SetMinorRadius", (void (gp_Hypr2d::*)(const Standard_Real)) &gp_Hypr2d::SetMinorRadius, "Modifies the major or minor radius of this hyperbola. Exceptions Standard_ConstructionError if MajorRadius or MinorRadius is negative.", py::arg("MinorRadius"));
cls_gp_Hypr2d.def("SetAxis", (void (gp_Hypr2d::*)(const gp_Ax22d &)) &gp_Hypr2d::SetAxis, "Modifies this hyperbola, by redefining its local coordinate system so that it becomes A.", py::arg("A"));
cls_gp_Hypr2d.def("SetXAxis", (void (gp_Hypr2d::*)(const gp_Ax2d &)) &gp_Hypr2d::SetXAxis, "Changes the major axis of the hyperbola. The minor axis is recomputed and the location of the hyperbola too.", py::arg("A"));
cls_gp_Hypr2d.def("SetYAxis", (void (gp_Hypr2d::*)(const gp_Ax2d &)) &gp_Hypr2d::SetYAxis, "Changes the minor axis of the hyperbola.The minor axis is recomputed and the location of the hyperbola too.", py::arg("A"));
cls_gp_Hypr2d.def("Asymptote1", (gp_Ax2d (gp_Hypr2d::*)() const) &gp_Hypr2d::Asymptote1, "In the local coordinate system of the hyperbola the equation of the hyperbola is (X*X)/(A*A) - (Y*Y)/(B*B) = 1.0 and the equation of the first asymptote is Y = (B/A)*X where A is the major radius of the hyperbola and B the minor radius of the hyperbola. Raises ConstructionError if MajorRadius = 0.0");
cls_gp_Hypr2d.def("Asymptote2", (gp_Ax2d (gp_Hypr2d::*)() const) &gp_Hypr2d::Asymptote2, "In the local coordinate system of the hyperbola the equation of the hyperbola is (X*X)/(A*A) - (Y*Y)/(B*B) = 1.0 and the equation of the first asymptote is Y = -(B/A)*X where A is the major radius of the hyperbola and B the minor radius of the hyperbola. Raises ConstructionError if MajorRadius = 0.0");
cls_gp_Hypr2d.def("Coefficients", [](gp_Hypr2d &self, Standard_Real & A, Standard_Real & B, Standard_Real & C, Standard_Real & D, Standard_Real & E, Standard_Real & F){ self.Coefficients(A, B, C, D, E, F); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(A, B, C, D, E, F); }, "Computes the coefficients of the implicit equation of the hyperbola : A * (X**2) + B * (Y**2) + 2*C*(X*Y) + 2*D*X + 2*E*Y + F = 0.", py::arg("A"), py::arg("B"), py::arg("C"), py::arg("D"), py::arg("E"), py::arg("F"));
cls_gp_Hypr2d.def("ConjugateBranch1", (gp_Hypr2d (gp_Hypr2d::*)() const) &gp_Hypr2d::ConjugateBranch1, "Computes the branch of hyperbola which is on the positive side of the 'YAxis' of <me>.");
cls_gp_Hypr2d.def("ConjugateBranch2", (gp_Hypr2d (gp_Hypr2d::*)() const) &gp_Hypr2d::ConjugateBranch2, "Computes the branch of hyperbola which is on the negative side of the 'YAxis' of <me>.");
cls_gp_Hypr2d.def("Directrix1", (gp_Ax2d (gp_Hypr2d::*)() const) &gp_Hypr2d::Directrix1, "Computes the directrix which is the line normal to the XAxis of the hyperbola in the local plane (Z = 0) at a distance d = MajorRadius / e from the center of the hyperbola, where e is the eccentricity of the hyperbola. This line is parallel to the 'YAxis'. The intersection point between the 'Directrix1' and the 'XAxis' is the 'Location' point of the 'Directrix1'. This point is on the positive side of the 'XAxis'.");
cls_gp_Hypr2d.def("Directrix2", (gp_Ax2d (gp_Hypr2d::*)() const) &gp_Hypr2d::Directrix2, "This line is obtained by the symmetrical transformation of 'Directrix1' with respect to the 'YAxis' of the hyperbola.");
cls_gp_Hypr2d.def("Eccentricity", (Standard_Real (gp_Hypr2d::*)() const) &gp_Hypr2d::Eccentricity, "Returns the excentricity of the hyperbola (e > 1). If f is the distance between the location of the hyperbola and the Focus1 then the eccentricity e = f / MajorRadius. Raises DomainError if MajorRadius = 0.0.");
cls_gp_Hypr2d.def("Focal", (Standard_Real (gp_Hypr2d::*)() const) &gp_Hypr2d::Focal, "Computes the focal distance. It is the distance between the 'Location' of the hyperbola and 'Focus1' or 'Focus2'.");
cls_gp_Hypr2d.def("Focus1", (gp_Pnt2d (gp_Hypr2d::*)() const) &gp_Hypr2d::Focus1, "Returns the first focus of the hyperbola. This focus is on the positive side of the 'XAxis' of the hyperbola.");
cls_gp_Hypr2d.def("Focus2", (gp_Pnt2d (gp_Hypr2d::*)() const) &gp_Hypr2d::Focus2, "Returns the second focus of the hyperbola. This focus is on the negative side of the 'XAxis' of the hyperbola.");
cls_gp_Hypr2d.def("Location", (const gp_Pnt2d & (gp_Hypr2d::*)() const) &gp_Hypr2d::Location, "Returns the location point of the hyperbola. It is the intersection point between the 'XAxis' and the 'YAxis'.");
cls_gp_Hypr2d.def("MajorRadius", (Standard_Real (gp_Hypr2d::*)() const) &gp_Hypr2d::MajorRadius, "Returns the major radius of the hyperbola (it is the radius corresponding to the 'XAxis' of the hyperbola).");
cls_gp_Hypr2d.def("MinorRadius", (Standard_Real (gp_Hypr2d::*)() const) &gp_Hypr2d::MinorRadius, "Returns the minor radius of the hyperbola (it is the radius corresponding to the 'YAxis' of the hyperbola).");
cls_gp_Hypr2d.def("OtherBranch", (gp_Hypr2d (gp_Hypr2d::*)() const) &gp_Hypr2d::OtherBranch, "Returns the branch of hyperbola obtained by doing the symmetrical transformation of <me> with respect to the 'YAxis' of <me>.");
cls_gp_Hypr2d.def("Parameter", (Standard_Real (gp_Hypr2d::*)() const) &gp_Hypr2d::Parameter, "Returns p = (e * e - 1) * MajorRadius where e is the eccentricity of the hyperbola. Raises DomainError if MajorRadius = 0.0");
cls_gp_Hypr2d.def("Axis", (const gp_Ax22d & (gp_Hypr2d::*)() const) &gp_Hypr2d::Axis, "Returns the axisplacement of the hyperbola.");
cls_gp_Hypr2d.def("XAxis", (gp_Ax2d (gp_Hypr2d::*)() const) &gp_Hypr2d::XAxis, "Computes an axis whose - the origin is the center of this hyperbola, and - the unit vector is the 'X Direction' or 'Y Direction' respectively of the local coordinate system of this hyperbola Returns the major axis of the hyperbola.");
cls_gp_Hypr2d.def("YAxis", (gp_Ax2d (gp_Hypr2d::*)() const) &gp_Hypr2d::YAxis, "Computes an axis whose - the origin is the center of this hyperbola, and - the unit vector is the 'X Direction' or 'Y Direction' respectively of the local coordinate system of this hyperbola Returns the minor axis of the hyperbola.");
cls_gp_Hypr2d.def("Reverse", (void (gp_Hypr2d::*)()) &gp_Hypr2d::Reverse, "None");
cls_gp_Hypr2d.def("Reversed", (gp_Hypr2d (gp_Hypr2d::*)() const) &gp_Hypr2d::Reversed, "Reverses the orientation of the local coordinate system of this hyperbola (the 'Y Axis' is reversed). Therefore, the implicit orientation of this hyperbola is reversed. Note: - Reverse assigns the result to this hyperbola, while - Reversed creates a new one.");
cls_gp_Hypr2d.def("IsDirect", (Standard_Boolean (gp_Hypr2d::*)() const) &gp_Hypr2d::IsDirect, "Returns true if the local coordinate system is direct and false in the other case.");
cls_gp_Hypr2d.def("Mirror", (void (gp_Hypr2d::*)(const gp_Pnt2d &)) &gp_Hypr2d::Mirror, "None", py::arg("P"));
cls_gp_Hypr2d.def("Mirrored", (gp_Hypr2d (gp_Hypr2d::*)(const gp_Pnt2d &) const) &gp_Hypr2d::Mirrored, "Performs the symmetrical transformation of an hyperbola with respect to the point P which is the center of the symmetry.", py::arg("P"));
cls_gp_Hypr2d.def("Mirror", (void (gp_Hypr2d::*)(const gp_Ax2d &)) &gp_Hypr2d::Mirror, "None", py::arg("A"));
cls_gp_Hypr2d.def("Mirrored", (gp_Hypr2d (gp_Hypr2d::*)(const gp_Ax2d &) const) &gp_Hypr2d::Mirrored, "Performs the symmetrical transformation of an hyperbola with respect to an axis placement which is the axis of the symmetry.", py::arg("A"));
cls_gp_Hypr2d.def("Rotate", (void (gp_Hypr2d::*)(const gp_Pnt2d &, const Standard_Real)) &gp_Hypr2d::Rotate, "None", py::arg("P"), py::arg("Ang"));
cls_gp_Hypr2d.def("Rotated", (gp_Hypr2d (gp_Hypr2d::*)(const gp_Pnt2d &, const Standard_Real) const) &gp_Hypr2d::Rotated, "Rotates an hyperbola. P is the center of the rotation. Ang is the angular value of the rotation in radians.", py::arg("P"), py::arg("Ang"));
cls_gp_Hypr2d.def("Scale", (void (gp_Hypr2d::*)(const gp_Pnt2d &, const Standard_Real)) &gp_Hypr2d::Scale, "None", py::arg("P"), py::arg("S"));
cls_gp_Hypr2d.def("Scaled", (gp_Hypr2d (gp_Hypr2d::*)(const gp_Pnt2d &, const Standard_Real) const) &gp_Hypr2d::Scaled, "Scales an hyperbola. <S> is the scaling value. If <S> is positive only the location point is modified. But if <S> is negative the 'XAxis' is reversed and the 'YAxis' too.", py::arg("P"), py::arg("S"));
cls_gp_Hypr2d.def("Transform", (void (gp_Hypr2d::*)(const gp_Trsf2d &)) &gp_Hypr2d::Transform, "None", py::arg("T"));
cls_gp_Hypr2d.def("Transformed", (gp_Hypr2d (gp_Hypr2d::*)(const gp_Trsf2d &) const) &gp_Hypr2d::Transformed, "Transforms an hyperbola with the transformation T from class Trsf2d.", py::arg("T"));
cls_gp_Hypr2d.def("Translate", (void (gp_Hypr2d::*)(const gp_Vec2d &)) &gp_Hypr2d::Translate, "None", py::arg("V"));
cls_gp_Hypr2d.def("Translated", (gp_Hypr2d (gp_Hypr2d::*)(const gp_Vec2d &) const) &gp_Hypr2d::Translated, "Translates an hyperbola in the direction of the vector V. The magnitude of the translation is the vector's magnitude.", py::arg("V"));
cls_gp_Hypr2d.def("Translate", (void (gp_Hypr2d::*)(const gp_Pnt2d &, const gp_Pnt2d &)) &gp_Hypr2d::Translate, "None", py::arg("P1"), py::arg("P2"));
cls_gp_Hypr2d.def("Translated", (gp_Hypr2d (gp_Hypr2d::*)(const gp_Pnt2d &, const gp_Pnt2d &) const) &gp_Hypr2d::Translated, "Translates an hyperbola from the point P1 to the point P2.", py::arg("P1"), py::arg("P2"));

// Enums

}