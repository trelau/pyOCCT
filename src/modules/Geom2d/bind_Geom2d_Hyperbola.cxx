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
#include <Geom2d_Conic.hxx>
#include <gp_Hypr2d.hxx>
#include <gp_Ax2d.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Ax22d.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Vec2d.hxx>
#include <gp_Trsf2d.hxx>
#include <Standard_Handle.hxx>
#include <Geom2d_Geometry.hxx>
#include <Geom2d_Hyperbola.hxx>
#include <Standard_Type.hxx>

void bind_Geom2d_Hyperbola(py::module &mod){

py::class_<Geom2d_Hyperbola, opencascade::handle<Geom2d_Hyperbola>, Geom2d_Conic> cls_Geom2d_Hyperbola(mod, "Geom2d_Hyperbola", "Describes a branch of a hyperbola in the plane (2D space). A hyperbola is defined by its major and minor radii and, as with any conic curve, is positioned in the plane with a coordinate system (gp_Ax22d object) where: - the origin is the center of the hyperbola, - the 'X Direction' defines the major axis, and - the 'Y Direction' defines the minor axis. This coordinate system is the local coordinate system of the hyperbola. The branch of the hyperbola described is the one located on the positive side of the major axis. The orientation (direct or indirect) of the local coordinate system gives an explicit orientation to the hyperbola, determining the direction in which the parameter increases along the hyperbola. The Geom2d_Hyperbola hyperbola is parameterized as follows: P(U) = O + MajRad*Cosh(U)*XDir + MinRad*Sinh(U)*YDir where: - P is the point of parameter U, - O, XDir and YDir are respectively the origin, 'X Direction' and 'Y Direction' of its local coordinate system, - MajRad and MinRad are the major and minor radii of the hyperbola. The 'X Axis' of the local coordinate system therefore defines the origin of the parameter of the hyperbola. The parameter range is ] -infinite,+infinite [. The following diagram illustrates the respective positions, in the plane of the hyperbola, of the three branches of hyperbolas constructed using the functions OtherBranch, ConjugateBranch1 and ConjugateBranch2: ^YAxis | FirstConjugateBranch | Other | Main --------------------- C --------------------->XAxis Branch | Branch | SecondConjugateBranch | Warning The value of the major radius (on the major axis) can be less than the value of the minor radius (on the minor axis). See Also GCE2d_MakeHyperbola which provides functions for more complex hyperbola constructions gp_Ax22d gp_Hypr2d for an equivalent, non-parameterized data structure");

// Constructors
cls_Geom2d_Hyperbola.def(py::init<const gp_Hypr2d &>(), py::arg("H"));
cls_Geom2d_Hyperbola.def(py::init<const gp_Ax2d &, const Standard_Real, const Standard_Real>(), py::arg("MajorAxis"), py::arg("MajorRadius"), py::arg("MinorRadius"));
cls_Geom2d_Hyperbola.def(py::init<const gp_Ax2d &, const Standard_Real, const Standard_Real, const Standard_Boolean>(), py::arg("MajorAxis"), py::arg("MajorRadius"), py::arg("MinorRadius"), py::arg("Sense"));
cls_Geom2d_Hyperbola.def(py::init<const gp_Ax22d &, const Standard_Real, const Standard_Real>(), py::arg("Axis"), py::arg("MajorRadius"), py::arg("MinorRadius"));

// Fields

// Methods
cls_Geom2d_Hyperbola.def("SetHypr2d", (void (Geom2d_Hyperbola::*)(const gp_Hypr2d &)) &Geom2d_Hyperbola::SetHypr2d, "Converts the gp_Hypr2d hyperbola H into this hyperbola.", py::arg("H"));
cls_Geom2d_Hyperbola.def("SetMajorRadius", (void (Geom2d_Hyperbola::*)(const Standard_Real)) &Geom2d_Hyperbola::SetMajorRadius, "Assigns a value to the major or minor radius of this hyperbola. Exceptions Standard_ConstructionError if: - MajorRadius is less than 0.0, - MinorRadius is less than 0.0.", py::arg("MajorRadius"));
cls_Geom2d_Hyperbola.def("SetMinorRadius", (void (Geom2d_Hyperbola::*)(const Standard_Real)) &Geom2d_Hyperbola::SetMinorRadius, "Assigns a value to the major or minor radius of this hyperbola. Exceptions Standard_ConstructionError if: - MajorRadius is less than 0.0, - MinorRadius is less than 0.0.", py::arg("MinorRadius"));
cls_Geom2d_Hyperbola.def("Hypr2d", (gp_Hypr2d (Geom2d_Hyperbola::*)() const) &Geom2d_Hyperbola::Hypr2d, "Converts this hyperbola into a gp_Hypr2d one.");
cls_Geom2d_Hyperbola.def("ReversedParameter", (Standard_Real (Geom2d_Hyperbola::*)(const Standard_Real) const) &Geom2d_Hyperbola::ReversedParameter, "Computes the parameter on the reversed hyperbola, for the point of parameter U on this hyperbola. For a hyperbola, the returned value is -U.", py::arg("U"));
cls_Geom2d_Hyperbola.def("FirstParameter", (Standard_Real (Geom2d_Hyperbola::*)() const) &Geom2d_Hyperbola::FirstParameter, "Returns RealFirst from Standard.");
cls_Geom2d_Hyperbola.def("LastParameter", (Standard_Real (Geom2d_Hyperbola::*)() const) &Geom2d_Hyperbola::LastParameter, "returns RealLast from Standard.");
cls_Geom2d_Hyperbola.def("IsClosed", (Standard_Boolean (Geom2d_Hyperbola::*)() const) &Geom2d_Hyperbola::IsClosed, "Returns False.");
cls_Geom2d_Hyperbola.def("IsPeriodic", (Standard_Boolean (Geom2d_Hyperbola::*)() const) &Geom2d_Hyperbola::IsPeriodic, "return False for an hyperbola.");
cls_Geom2d_Hyperbola.def("Asymptote1", (gp_Ax2d (Geom2d_Hyperbola::*)() const) &Geom2d_Hyperbola::Asymptote1, "In the local coordinate system of the hyperbola the equation of the hyperbola is (X*X)/(A*A) - (Y*Y)/(B*B) = 1.0 and the equation of the first asymptote is Y = (B/A)*X where A is the major radius of the hyperbola and B is the minor radius of the hyperbola. Raised if MajorRadius = 0.0");
cls_Geom2d_Hyperbola.def("Asymptote2", (gp_Ax2d (Geom2d_Hyperbola::*)() const) &Geom2d_Hyperbola::Asymptote2, "In the local coordinate system of the hyperbola the equation of the hyperbola is (X*X)/(A*A) - (Y*Y)/(B*B) = 1.0 and the equation of the first asymptote is Y = -(B/A)*X. where A is the major radius of the hyperbola and B is the minor radius of the hyperbola. raised if MajorRadius = 0.0");
cls_Geom2d_Hyperbola.def("ConjugateBranch1", (gp_Hypr2d (Geom2d_Hyperbola::*)() const) &Geom2d_Hyperbola::ConjugateBranch1, "Computes the first conjugate branch relative to this hyperbola. Note: The diagram given under the class purpose indicates where these two branches of hyperbola are positioned in relation to this branch of hyperbola.");
cls_Geom2d_Hyperbola.def("ConjugateBranch2", (gp_Hypr2d (Geom2d_Hyperbola::*)() const) &Geom2d_Hyperbola::ConjugateBranch2, "Computes the second conjugate branch relative to this hyperbola. Note: The diagram given under the class purpose indicates where these two branches of hyperbola are positioned in relation to this branch of hyperbola.");
cls_Geom2d_Hyperbola.def("Directrix1", (gp_Ax2d (Geom2d_Hyperbola::*)() const) &Geom2d_Hyperbola::Directrix1, "This directrix is the line normal to the XAxis of the hyperbola in the local plane (Z = 0) at a distance d = MajorRadius / e from the center of the hyperbola, where e is the eccentricity of the hyperbola. This line is parallel to the 'YAxis'. The intersection point between directrix1 and the 'XAxis' is the location point of the directrix1. This point is on the positive side of the 'XAxis'.");
cls_Geom2d_Hyperbola.def("Directrix2", (gp_Ax2d (Geom2d_Hyperbola::*)() const) &Geom2d_Hyperbola::Directrix2, "This line is obtained by the symmetrical transformation of 'Directrix1' with respect to the 'YAxis' of the hyperbola.");
cls_Geom2d_Hyperbola.def("Eccentricity", (Standard_Real (Geom2d_Hyperbola::*)() const) &Geom2d_Hyperbola::Eccentricity, "Returns the excentricity of the hyperbola (e > 1). If f is the distance between the location of the hyperbola and the Focus1 then the eccentricity e = f / MajorRadius. raised if MajorRadius = 0.0");
cls_Geom2d_Hyperbola.def("Focal", (Standard_Real (Geom2d_Hyperbola::*)() const) &Geom2d_Hyperbola::Focal, "Computes the focal distance. It is the distance between the two focus of the hyperbola.");
cls_Geom2d_Hyperbola.def("Focus1", (gp_Pnt2d (Geom2d_Hyperbola::*)() const) &Geom2d_Hyperbola::Focus1, "Returns the first focus of the hyperbola. This focus is on the positive side of the 'XAxis' of the hyperbola.");
cls_Geom2d_Hyperbola.def("Focus2", (gp_Pnt2d (Geom2d_Hyperbola::*)() const) &Geom2d_Hyperbola::Focus2, "Returns the second focus of the hyperbola. This focus is on the negative side of the 'XAxis' of the hyperbola.");
cls_Geom2d_Hyperbola.def("MajorRadius", (Standard_Real (Geom2d_Hyperbola::*)() const) &Geom2d_Hyperbola::MajorRadius, "Returns the major or minor radius of this hyperbola. The major radius is also the distance between the center of the hyperbola and the apex of the main branch (located on the 'X Axis' of the hyperbola).");
cls_Geom2d_Hyperbola.def("MinorRadius", (Standard_Real (Geom2d_Hyperbola::*)() const) &Geom2d_Hyperbola::MinorRadius, "Returns the major or minor radius of this hyperbola. The minor radius is also the distance between the center of the hyperbola and the apex of a conjugate branch (located on the 'Y Axis' of the hyperbola).");
cls_Geom2d_Hyperbola.def("OtherBranch", (gp_Hypr2d (Geom2d_Hyperbola::*)() const) &Geom2d_Hyperbola::OtherBranch, "Computes the 'other' branch of this hyperbola. This is a symmetrical branch with respect to the center of this hyperbola. Note: The diagram given under the class purpose indicates where the 'other' branch is positioned in relation to this branch of the hyperbola. ^ YAxis | FirstConjugateBranch | Other | Main ---------------------------- C ------------------------------------------&gtXAxis Branch | Branch | | SecondConjugateBranch | Warning The major radius can be less than the minor radius.");
cls_Geom2d_Hyperbola.def("Parameter", (Standard_Real (Geom2d_Hyperbola::*)() const) &Geom2d_Hyperbola::Parameter, "Computes the parameter of this hyperbola. The parameter is: p = (e*e - 1) * MajorRadius where e is the eccentricity of this hyperbola and MajorRadius its major radius. Exceptions Standard_DomainError if the major radius of this hyperbola is null.");
cls_Geom2d_Hyperbola.def("D0", (void (Geom2d_Hyperbola::*)(const Standard_Real, gp_Pnt2d &) const) &Geom2d_Hyperbola::D0, "Returns in P the point of parameter U. P = C + MajorRadius * Cosh (U) * XDir + MinorRadius * Sinh (U) * YDir where C is the center of the hyperbola , XDir the XDirection and YDir the YDirection of the hyperbola's local coordinate system.", py::arg("U"), py::arg("P"));
cls_Geom2d_Hyperbola.def("D1", (void (Geom2d_Hyperbola::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &) const) &Geom2d_Hyperbola::D1, "Returns the point P of parameter U and the first derivative V1.", py::arg("U"), py::arg("P"), py::arg("V1"));
cls_Geom2d_Hyperbola.def("D2", (void (Geom2d_Hyperbola::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &) const) &Geom2d_Hyperbola::D2, "Returns the point P of parameter U, the first and second derivatives V1 and V2.", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"));
cls_Geom2d_Hyperbola.def("D3", (void (Geom2d_Hyperbola::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &, gp_Vec2d &) const) &Geom2d_Hyperbola::D3, "Returns the point P of parameter U, the first second and third derivatives V1 V2 and V3.", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"));
cls_Geom2d_Hyperbola.def("DN", (gp_Vec2d (Geom2d_Hyperbola::*)(const Standard_Real, const Standard_Integer) const) &Geom2d_Hyperbola::DN, "For the point of parameter U of this hyperbola, computes the vector corresponding to the Nth derivative. Exceptions Standard_RangeError if N is less than 1.", py::arg("U"), py::arg("N"));
cls_Geom2d_Hyperbola.def("Transform", (void (Geom2d_Hyperbola::*)(const gp_Trsf2d &)) &Geom2d_Hyperbola::Transform, "Applies the transformation T to this hyperbola.", py::arg("T"));
cls_Geom2d_Hyperbola.def("Copy", (opencascade::handle<Geom2d_Geometry> (Geom2d_Hyperbola::*)() const) &Geom2d_Hyperbola::Copy, "Creates a new object which is a copy of this hyperbola.");
cls_Geom2d_Hyperbola.def_static("get_type_name_", (const char * (*)()) &Geom2d_Hyperbola::get_type_name, "None");
cls_Geom2d_Hyperbola.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Geom2d_Hyperbola::get_type_descriptor, "None");
cls_Geom2d_Hyperbola.def("DynamicType", (const opencascade::handle<Standard_Type> & (Geom2d_Hyperbola::*)() const) &Geom2d_Hyperbola::DynamicType, "None");

// Enums

}