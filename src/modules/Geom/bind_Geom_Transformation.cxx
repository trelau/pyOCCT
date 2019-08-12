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
#include <Standard_Handle.hxx>
#include <Geom_Transformation.hxx>
#include <Standard_Type.hxx>
#include <gp_Trsf.hxx>
#include <gp_Pnt.hxx>
#include <gp_Ax1.hxx>
#include <gp_Ax2.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Ax3.hxx>
#include <gp_Vec.hxx>
#include <gp_TrsfForm.hxx>

void bind_Geom_Transformation(py::module &mod){

py::class_<Geom_Transformation, opencascade::handle<Geom_Transformation>, Standard_Transient> cls_Geom_Transformation(mod, "Geom_Transformation", "Describes how to construct the following elementary transformations - translations, - rotations, - symmetries, - scales. The Transformation class can also be used to construct complex transformations by combining these elementary transformations. However, these transformations can never change the type of an object. For example, the projection transformation can change a circle into an ellipse, and therefore change the real type of the object. Such a transformation is forbidden in this environment and cannot be a Geom_Transformation. The transformation can be represented as follow :");

// Constructors
cls_Geom_Transformation.def(py::init<>());
cls_Geom_Transformation.def(py::init<const gp_Trsf &>(), py::arg("T"));

// Fields

// Methods
cls_Geom_Transformation.def_static("get_type_name_", (const char * (*)()) &Geom_Transformation::get_type_name, "None");
cls_Geom_Transformation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Geom_Transformation::get_type_descriptor, "None");
cls_Geom_Transformation.def("DynamicType", (const opencascade::handle<Standard_Type> & (Geom_Transformation::*)() const) &Geom_Transformation::DynamicType, "None");
cls_Geom_Transformation.def("SetMirror", (void (Geom_Transformation::*)(const gp_Pnt &)) &Geom_Transformation::SetMirror, "Makes the transformation into a symmetrical transformation with respect to a point P. P is the center of the symmetry.", py::arg("thePnt"));
cls_Geom_Transformation.def("SetMirror", (void (Geom_Transformation::*)(const gp_Ax1 &)) &Geom_Transformation::SetMirror, "Makes the transformation into a symmetrical transformation with respect to an axis A1. A1 is the center of the axial symmetry.", py::arg("theA1"));
cls_Geom_Transformation.def("SetMirror", (void (Geom_Transformation::*)(const gp_Ax2 &)) &Geom_Transformation::SetMirror, "Makes the transformation into a symmetrical transformation with respect to a plane. The plane of the symmetry is defined with the axis placement A2. It is the plane (Location, XDirection, YDirection).", py::arg("theA2"));
cls_Geom_Transformation.def("SetRotation", (void (Geom_Transformation::*)(const gp_Ax1 &, const Standard_Real)) &Geom_Transformation::SetRotation, "Makes the transformation into a rotation. A1 is the axis rotation and Ang is the angular value of the rotation in radians.", py::arg("theA1"), py::arg("theAng"));
cls_Geom_Transformation.def("SetScale", (void (Geom_Transformation::*)(const gp_Pnt &, const Standard_Real)) &Geom_Transformation::SetScale, "Makes the transformation into a scale. P is the center of the scale and S is the scaling value.", py::arg("thePnt"), py::arg("theScale"));
cls_Geom_Transformation.def("SetTransformation", (void (Geom_Transformation::*)(const gp_Ax3 &, const gp_Ax3 &)) &Geom_Transformation::SetTransformation, "Makes a transformation allowing passage from the coordinate system 'FromSystem1' to the coordinate system 'ToSystem2'. Example : In a C++ implementation : Real x1, y1, z1; // are the coordinates of a point in the // local system FromSystem1 Real x2, y2, z2; // are the coordinates of a point in the // local system ToSystem2 gp_Pnt P1 (x1, y1, z1) Geom_Transformation T; T.SetTransformation (FromSystem1, ToSystem2); gp_Pnt P2 = P1.Transformed (T); P2.Coord (x2, y2, z2);", py::arg("theFromSystem1"), py::arg("theToSystem2"));
cls_Geom_Transformation.def("SetTransformation", (void (Geom_Transformation::*)(const gp_Ax3 &)) &Geom_Transformation::SetTransformation, "Makes the transformation allowing passage from the basic coordinate system {P(0.,0.,0.), VX (1.,0.,0.), VY (0.,1.,0.), VZ (0., 0. ,1.) } to the local coordinate system defined with the Ax2 ToSystem. Same utilisation as the previous method. FromSystem1 is defaulted to the absolute coordinate system.", py::arg("theToSystem"));
cls_Geom_Transformation.def("SetTranslation", (void (Geom_Transformation::*)(const gp_Vec &)) &Geom_Transformation::SetTranslation, "Makes the transformation into a translation. V is the vector of the translation.", py::arg("theVec"));
cls_Geom_Transformation.def("SetTranslation", (void (Geom_Transformation::*)(const gp_Pnt &, const gp_Pnt &)) &Geom_Transformation::SetTranslation, "Makes the transformation into a translation from the point P1 to the point P2.", py::arg("P1"), py::arg("P2"));
cls_Geom_Transformation.def("SetTrsf", (void (Geom_Transformation::*)(const gp_Trsf &)) &Geom_Transformation::SetTrsf, "Converts the gp_Trsf transformation T into this transformation.", py::arg("theTrsf"));
cls_Geom_Transformation.def("IsNegative", (Standard_Boolean (Geom_Transformation::*)() const) &Geom_Transformation::IsNegative, "Checks whether this transformation is an indirect transformation: returns true if the determinant of the matrix of the vectorial part of the transformation is less than 0.");
cls_Geom_Transformation.def("Form", (gp_TrsfForm (Geom_Transformation::*)() const) &Geom_Transformation::Form, "Returns the nature of this transformation as a value of the gp_TrsfForm enumeration.");
cls_Geom_Transformation.def("ScaleFactor", (Standard_Real (Geom_Transformation::*)() const) &Geom_Transformation::ScaleFactor, "Returns the scale value of the transformation.");
cls_Geom_Transformation.def("Trsf", (const gp_Trsf & (Geom_Transformation::*)() const) &Geom_Transformation::Trsf, "Returns a non transient copy of <me>.");
cls_Geom_Transformation.def("Value", (Standard_Real (Geom_Transformation::*)(const Standard_Integer, const Standard_Integer) const) &Geom_Transformation::Value, "Returns the coefficients of the global matrix of transformation. It is a 3 rows X 4 columns matrix.", py::arg("theRow"), py::arg("theCol"));
cls_Geom_Transformation.def("Invert", (void (Geom_Transformation::*)()) &Geom_Transformation::Invert, "Raised if the the transformation is singular. This means that the ScaleFactor is lower or equal to Resolution from package gp.");
cls_Geom_Transformation.def("Inverted", (opencascade::handle<Geom_Transformation> (Geom_Transformation::*)() const) &Geom_Transformation::Inverted, "Raised if the the transformation is singular. This means that the ScaleFactor is lower or equal to Resolution from package gp.");
cls_Geom_Transformation.def("Multiplied", (opencascade::handle<Geom_Transformation> (Geom_Transformation::*)(const opencascade::handle<Geom_Transformation> &) const) &Geom_Transformation::Multiplied, "Computes the transformation composed with Other and <me>. <me> * Other. Returns a new transformation", py::arg("Other"));
cls_Geom_Transformation.def("Multiply", (void (Geom_Transformation::*)(const opencascade::handle<Geom_Transformation> &)) &Geom_Transformation::Multiply, "Computes the transformation composed with Other and <me> . <me> = <me> * Other.", py::arg("theOther"));
cls_Geom_Transformation.def("Power", (void (Geom_Transformation::*)(const Standard_Integer)) &Geom_Transformation::Power, "Computes the following composition of transformations if N > 0 <me> * <me> * .......* <me>. if N = 0 Identity if N < 0 <me>.Invert() * .........* <me>.Invert()", py::arg("N"));
cls_Geom_Transformation.def("Powered", (opencascade::handle<Geom_Transformation> (Geom_Transformation::*)(const Standard_Integer) const) &Geom_Transformation::Powered, "Raised if N < 0 and if the transformation is not inversible", py::arg("N"));
cls_Geom_Transformation.def("PreMultiply", (void (Geom_Transformation::*)(const opencascade::handle<Geom_Transformation> &)) &Geom_Transformation::PreMultiply, "Computes the matrix of the transformation composed with <me> and Other. <me> = Other * <me>", py::arg("Other"));
cls_Geom_Transformation.def("Transforms", [](Geom_Transformation &self, Standard_Real & theX, Standard_Real & theY, Standard_Real & theZ){ self.Transforms(theX, theY, theZ); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(theX, theY, theZ); }, "Applies the transformation <me> to the triplet {X, Y, Z}.", py::arg("theX"), py::arg("theY"), py::arg("theZ"));
cls_Geom_Transformation.def("Copy", (opencascade::handle<Geom_Transformation> (Geom_Transformation::*)() const) &Geom_Transformation::Copy, "Creates a new object which is a copy of this transformation.");

// Enums

}