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
#include <Geom_Conic.hxx>
#include <gp_Hypr.hxx>
#include <gp_Ax2.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Ax1.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>
#include <gp_Trsf.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Geometry.hxx>
#include <Geom_Hyperbola.hxx>
#include <Standard_Type.hxx>

void bind_Geom_Hyperbola(py::module &mod){

py::class_<Geom_Hyperbola, opencascade::handle<Geom_Hyperbola>, Geom_Conic> cls_Geom_Hyperbola(mod, "Geom_Hyperbola", "Describes a branch of a hyperbola in 3D space. A hyperbola is defined by its major and minor radii and, as with any conic curve, is positioned in space with a right-handed coordinate system (gp_Ax2 object) where: - the origin is the center of the hyperbola, - the 'X Direction' defines the major axis, and - the 'Y Direction' defines the minor axis. The origin, 'X Direction' and 'Y Direction' of this coordinate system define the plane of the hyperbola. The coordinate system is the local coordinate system of the hyperbola. The branch of the hyperbola described is the one located on the positive side of the major axis. The 'main Direction' of the local coordinate system is a vector normal to the plane of the hyperbola. The axis, of which the origin and unit vector are respectively the origin and 'main Direction' of the local coordinate system, is termed the 'Axis' or 'main Axis' of the hyperbola. The 'main Direction' of the local coordinate system gives an explicit orientation to the hyperbola, determining the direction in which the parameter increases along the hyperbola. The Geom_Hyperbola hyperbola is parameterized as follows: P(U) = O + MajRad*Cosh(U)*XDir + MinRad*Sinh(U)*YDir, where: - P is the point of parameter U, - O, XDir and YDir are respectively the origin, 'X Direction' and 'Y Direction' of its local coordinate system, - MajRad and MinRad are the major and minor radii of the hyperbola. The 'X Axis' of the local coordinate system therefore defines the origin of the parameter of the hyperbola. The parameter range is ] -infinite, +infinite [. The following diagram illustrates the respective positions, in the plane of the hyperbola, of the three branches of hyperbolas constructed using the functions OtherBranch, ConjugateBranch1 and ConjugateBranch2: Defines the main branch of an hyperbola. ^YAxis | FirstConjugateBranch | Other | Main --------------------- C ------------------------------>XAxis Branch | Branch | SecondConjugateBranch | Warning The value of the major radius (on the major axis) can be less than the value of the minor radius (on the minor axis).");

// Constructors
cls_Geom_Hyperbola.def(py::init<const gp_Hypr &>(), py::arg("H"));
cls_Geom_Hyperbola.def(py::init<const gp_Ax2 &, const Standard_Real, const Standard_Real>(), py::arg("A2"), py::arg("MajorRadius"), py::arg("MinorRadius"));

// Fields

// Methods
cls_Geom_Hyperbola.def("SetHypr", (void (Geom_Hyperbola::*)(const gp_Hypr &)) &Geom_Hyperbola::SetHypr, "Converts the gp_Hypr hyperbola H into this hyperbola.", py::arg("H"));
cls_Geom_Hyperbola.def("SetMajorRadius", (void (Geom_Hyperbola::*)(const Standard_Real)) &Geom_Hyperbola::SetMajorRadius, "Assigns a value to the major radius of this hyperbola. Exceptions Standard_ConstructionError if: - MajorRadius is less than 0.0, or - MinorRadius is less than 0.0.Raised if MajorRadius < 0.0", py::arg("MajorRadius"));
cls_Geom_Hyperbola.def("SetMinorRadius", (void (Geom_Hyperbola::*)(const Standard_Real)) &Geom_Hyperbola::SetMinorRadius, "Assigns a value to the minor radius of this hyperbola. Exceptions Standard_ConstructionError if: - MajorRadius is less than 0.0, or - MinorRadius is less than 0.0.Raised if MajorRadius < 0.0", py::arg("MinorRadius"));
cls_Geom_Hyperbola.def("Hypr", (gp_Hypr (Geom_Hyperbola::*)() const) &Geom_Hyperbola::Hypr, "returns the non transient parabola from gp with the same geometric properties as <me>.");
cls_Geom_Hyperbola.def("ReversedParameter", (Standard_Real (Geom_Hyperbola::*)(const Standard_Real) const) &Geom_Hyperbola::ReversedParameter, "Computes the parameter on the reversed hyperbola, for the point of parameter U on this hyperbola. For a hyperbola, the returned value is: -U.", py::arg("U"));
cls_Geom_Hyperbola.def("FirstParameter", (Standard_Real (Geom_Hyperbola::*)() const) &Geom_Hyperbola::FirstParameter, "Returns RealFirst from Standard.");
cls_Geom_Hyperbola.def("LastParameter", (Standard_Real (Geom_Hyperbola::*)() const) &Geom_Hyperbola::LastParameter, "returns RealLast from Standard.");
cls_Geom_Hyperbola.def("IsClosed", (Standard_Boolean (Geom_Hyperbola::*)() const) &Geom_Hyperbola::IsClosed, "Returns False.");
cls_Geom_Hyperbola.def("IsPeriodic", (Standard_Boolean (Geom_Hyperbola::*)() const) &Geom_Hyperbola::IsPeriodic, "return False for an hyperbola.");
cls_Geom_Hyperbola.def("Asymptote1", (gp_Ax1 (Geom_Hyperbola::*)() const) &Geom_Hyperbola::Asymptote1, "In the local coordinate system of the hyperbola the equation of the hyperbola is (X*X)/(A*A) - (Y*Y)/(B*B) = 1.0 and the equation of the first asymptote is Y = (B/A)*X. Raises ConstructionError if MajorRadius = 0.0");
cls_Geom_Hyperbola.def("Asymptote2", (gp_Ax1 (Geom_Hyperbola::*)() const) &Geom_Hyperbola::Asymptote2, "In the local coordinate system of the hyperbola the equation of the hyperbola is (X*X)/(A*A) - (Y*Y)/(B*B) = 1.0 and the equation of the first asymptote is Y = -(B/A)*X. Raises ConstructionError if MajorRadius = 0.0");
cls_Geom_Hyperbola.def("ConjugateBranch1", (gp_Hypr (Geom_Hyperbola::*)() const) &Geom_Hyperbola::ConjugateBranch1, "This branch of hyperbola is on the positive side of the YAxis of <me>.");
cls_Geom_Hyperbola.def("ConjugateBranch2", (gp_Hypr (Geom_Hyperbola::*)() const) &Geom_Hyperbola::ConjugateBranch2, "This branch of hyperbola is on the negative side of the YAxis of <me>. Note: The diagram given under the class purpose indicates where these two branches of hyperbola are positioned in relation to this branch of hyperbola.");
cls_Geom_Hyperbola.def("Directrix1", (gp_Ax1 (Geom_Hyperbola::*)() const) &Geom_Hyperbola::Directrix1, "This directrix is the line normal to the XAxis of the hyperbola in the local plane (Z = 0) at a distance d = MajorRadius / e from the center of the hyperbola, where e is the eccentricity of the hyperbola. This line is parallel to the YAxis. The intersection point between directrix1 and the XAxis is the location point of the directrix1. This point is on the positive side of the XAxis.");
cls_Geom_Hyperbola.def("Directrix2", (gp_Ax1 (Geom_Hyperbola::*)() const) &Geom_Hyperbola::Directrix2, "This line is obtained by the symmetrical transformation of 'directrix1' with respect to the YAxis of the hyperbola.");
cls_Geom_Hyperbola.def("Eccentricity", (Standard_Real (Geom_Hyperbola::*)() const) &Geom_Hyperbola::Eccentricity, "Returns the excentricity of the hyperbola (e > 1). If f is the distance between the location of the hyperbola and the Focus1 then the eccentricity e = f / MajorRadius. raised if MajorRadius = 0.0");
cls_Geom_Hyperbola.def("Focal", (Standard_Real (Geom_Hyperbola::*)() const) &Geom_Hyperbola::Focal, "Computes the focal distance. It is the distance between the two focus of the hyperbola.");
cls_Geom_Hyperbola.def("Focus1", (gp_Pnt (Geom_Hyperbola::*)() const) &Geom_Hyperbola::Focus1, "Returns the first focus of the hyperbola. This focus is on the positive side of the XAxis of the hyperbola.");
cls_Geom_Hyperbola.def("Focus2", (gp_Pnt (Geom_Hyperbola::*)() const) &Geom_Hyperbola::Focus2, "Returns the second focus of the hyperbola. This focus is on the negative side of the XAxis of the hyperbola.");
cls_Geom_Hyperbola.def("MajorRadius", (Standard_Real (Geom_Hyperbola::*)() const) &Geom_Hyperbola::MajorRadius, "Returns the major or minor radius of this hyperbola. The major radius is also the distance between the center of the hyperbola and the apex of the main branch (located on the 'X Axis' of the hyperbola).");
cls_Geom_Hyperbola.def("MinorRadius", (Standard_Real (Geom_Hyperbola::*)() const) &Geom_Hyperbola::MinorRadius, "Returns the major or minor radius of this hyperbola. The minor radius is also the distance between the center of the hyperbola and the apex of a conjugate branch (located on the 'Y Axis' of the hyperbola).");
cls_Geom_Hyperbola.def("OtherBranch", (gp_Hypr (Geom_Hyperbola::*)() const) &Geom_Hyperbola::OtherBranch, "Computes the 'other' branch of this hyperbola. This is the symmetrical branch with respect to the center of this hyperbola. Note: The diagram given under the class purpose indicates where the 'other' branch is positioned in relation to this branch of the hyperbola.");
cls_Geom_Hyperbola.def("Parameter", (Standard_Real (Geom_Hyperbola::*)() const) &Geom_Hyperbola::Parameter, "Returns p = (e * e - 1) * MajorRadius where e is the eccentricity of the hyperbola. raised if MajorRadius = 0.0");
cls_Geom_Hyperbola.def("D0", (void (Geom_Hyperbola::*)(const Standard_Real, gp_Pnt &) const) &Geom_Hyperbola::D0, "Returns in P the point of parameter U. P = C + MajorRadius * Cosh (U) * XDir + MinorRadius * Sinh (U) * YDir where C is the center of the hyperbola , XDir the XDirection and YDir the YDirection of the hyperbola's local coordinate system.", py::arg("U"), py::arg("P"));
cls_Geom_Hyperbola.def("D1", (void (Geom_Hyperbola::*)(const Standard_Real, gp_Pnt &, gp_Vec &) const) &Geom_Hyperbola::D1, "Returns the point P of parameter U and the first derivative V1.", py::arg("U"), py::arg("P"), py::arg("V1"));
cls_Geom_Hyperbola.def("D2", (void (Geom_Hyperbola::*)(const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &) const) &Geom_Hyperbola::D2, "Returns the point P of parameter U, the first and second derivatives V1 and V2.", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"));
cls_Geom_Hyperbola.def("D3", (void (Geom_Hyperbola::*)(const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &) const) &Geom_Hyperbola::D3, "Returns the point P of parameter U, the first second and third derivatives V1 V2 and V3.", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"));
cls_Geom_Hyperbola.def("DN", (gp_Vec (Geom_Hyperbola::*)(const Standard_Real, const Standard_Integer) const) &Geom_Hyperbola::DN, "The returned vector gives the value of the derivative for the order of derivation N. Raised if N < 1.", py::arg("U"), py::arg("N"));
cls_Geom_Hyperbola.def("Transform", (void (Geom_Hyperbola::*)(const gp_Trsf &)) &Geom_Hyperbola::Transform, "Applies the transformation T to this hyperbola.", py::arg("T"));
cls_Geom_Hyperbola.def("Copy", (opencascade::handle<Geom_Geometry> (Geom_Hyperbola::*)() const) &Geom_Hyperbola::Copy, "Creates a new object which is a copy of this hyperbola.");
cls_Geom_Hyperbola.def_static("get_type_name_", (const char * (*)()) &Geom_Hyperbola::get_type_name, "None");
cls_Geom_Hyperbola.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Geom_Hyperbola::get_type_descriptor, "None");
cls_Geom_Hyperbola.def("DynamicType", (const opencascade::handle<Standard_Type> & (Geom_Hyperbola::*)() const) &Geom_Hyperbola::DynamicType, "None");

// Enums

}