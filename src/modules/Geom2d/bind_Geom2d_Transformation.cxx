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
#include <gp_Trsf2d.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Ax2d.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Vec2d.hxx>
#include <gp_TrsfForm.hxx>
#include <Standard_Handle.hxx>
#include <Geom2d_Transformation.hxx>
#include <Standard_Type.hxx>

void bind_Geom2d_Transformation(py::module &mod){

py::class_<Geom2d_Transformation, opencascade::handle<Geom2d_Transformation>, Standard_Transient> cls_Geom2d_Transformation(mod, "Geom2d_Transformation", "The class Transformation allows to create Translation, Rotation, Symmetry, Scaling and complex transformations obtained by combination of the previous elementary transformations. The Transformation class can also be used to construct complex transformations by combining these elementary transformations. However, these transformations can never change the type of an object. For example, the projection transformation can change a circle into an ellipse, and therefore change the real type of the object. Such a transformation is forbidden in this environment and cannot be a Geom2d_Transformation. The transformation can be represented as follow :");

// Constructors
cls_Geom2d_Transformation.def(py::init<>());
cls_Geom2d_Transformation.def(py::init<const gp_Trsf2d &>(), py::arg("T"));

// Fields

// Methods
cls_Geom2d_Transformation.def("SetMirror", (void (Geom2d_Transformation::*)(const gp_Pnt2d &)) &Geom2d_Transformation::SetMirror, "Makes the transformation into a symmetrical transformation with respect to a point P. P is the center of the symmetry.", py::arg("P"));
cls_Geom2d_Transformation.def("SetMirror", (void (Geom2d_Transformation::*)(const gp_Ax2d &)) &Geom2d_Transformation::SetMirror, "Makes the transformation into a symmetrical transformation with respect to an axis A. A is the center of the axial symmetry.", py::arg("A"));
cls_Geom2d_Transformation.def("SetRotation", (void (Geom2d_Transformation::*)(const gp_Pnt2d &, const Standard_Real)) &Geom2d_Transformation::SetRotation, "Assigns to this transformation the geometric properties of a rotation at angle Ang (in radians) about point P.", py::arg("P"), py::arg("Ang"));
cls_Geom2d_Transformation.def("SetScale", (void (Geom2d_Transformation::*)(const gp_Pnt2d &, const Standard_Real)) &Geom2d_Transformation::SetScale, "Makes the transformation into a scale. P is the center of the scale and S is the scaling value.", py::arg("P"), py::arg("S"));
cls_Geom2d_Transformation.def("SetTransformation", (void (Geom2d_Transformation::*)(const gp_Ax2d &, const gp_Ax2d &)) &Geom2d_Transformation::SetTransformation, "Makes a transformation allowing passage from the coordinate system 'FromSystem1' to the coordinate system 'ToSystem2'.", py::arg("FromSystem1"), py::arg("ToSystem2"));
cls_Geom2d_Transformation.def("SetTransformation", (void (Geom2d_Transformation::*)(const gp_Ax2d &)) &Geom2d_Transformation::SetTransformation, "Makes the transformation allowing passage from the basic coordinate system {P(0.,0.,0.), VX (1.,0.,0.), VY (0.,1.,0.)} to the local coordinate system defined with the Ax2d ToSystem.", py::arg("ToSystem"));
cls_Geom2d_Transformation.def("SetTranslation", (void (Geom2d_Transformation::*)(const gp_Vec2d &)) &Geom2d_Transformation::SetTranslation, "Makes the transformation into a translation. V is the vector of the translation.", py::arg("V"));
cls_Geom2d_Transformation.def("SetTranslation", (void (Geom2d_Transformation::*)(const gp_Pnt2d &, const gp_Pnt2d &)) &Geom2d_Transformation::SetTranslation, "Makes the transformation into a translation from the point P1 to the point P2.", py::arg("P1"), py::arg("P2"));
cls_Geom2d_Transformation.def("SetTrsf2d", (void (Geom2d_Transformation::*)(const gp_Trsf2d &)) &Geom2d_Transformation::SetTrsf2d, "Makes the transformation into a transformation T from package gp.", py::arg("T"));
cls_Geom2d_Transformation.def("IsNegative", (Standard_Boolean (Geom2d_Transformation::*)() const) &Geom2d_Transformation::IsNegative, "Checks whether this transformation is an indirect transformation: returns true if the determinant of the matrix of the vectorial part of the transformation is less than 0.");
cls_Geom2d_Transformation.def("Form", (gp_TrsfForm (Geom2d_Transformation::*)() const) &Geom2d_Transformation::Form, "Returns the nature of this transformation as a value of the gp_TrsfForm enumeration. Returns the nature of the transformation. It can be Identity, Rotation, Translation, PntMirror, Ax1Mirror, Scale, CompoundTrsf");
cls_Geom2d_Transformation.def("ScaleFactor", (Standard_Real (Geom2d_Transformation::*)() const) &Geom2d_Transformation::ScaleFactor, "Returns the scale value of the transformation.");
cls_Geom2d_Transformation.def("Trsf2d", (gp_Trsf2d (Geom2d_Transformation::*)() const) &Geom2d_Transformation::Trsf2d, "Converts this transformation into a gp_Trsf2d transformation. Returns a non persistent copy of <me>. -C++: return const&");
cls_Geom2d_Transformation.def("Value", (Standard_Real (Geom2d_Transformation::*)(const Standard_Integer, const Standard_Integer) const) &Geom2d_Transformation::Value, "Returns the coefficients of the global matrix of tranformation. It is a 2 rows X 3 columns matrix.", py::arg("Row"), py::arg("Col"));
cls_Geom2d_Transformation.def("Invert", (void (Geom2d_Transformation::*)()) &Geom2d_Transformation::Invert, "Computes the inverse of this transformation. and assigns the result to this transformatio");
cls_Geom2d_Transformation.def("Inverted", (opencascade::handle<Geom2d_Transformation> (Geom2d_Transformation::*)() const) &Geom2d_Transformation::Inverted, "Computes the inverse of this transformation and creates a new one. Raises ConstructionError if the the transformation is singular. This means that the ScaleFactor is lower or equal to Resolution from package gp.");
cls_Geom2d_Transformation.def("Multiplied", (opencascade::handle<Geom2d_Transformation> (Geom2d_Transformation::*)(const opencascade::handle<Geom2d_Transformation> &) const) &Geom2d_Transformation::Multiplied, "Computes the transformation composed with Other and <me>. <me> * Other. Returns a new transformation", py::arg("Other"));
cls_Geom2d_Transformation.def("__mul__", (opencascade::handle<Geom2d_Transformation> (Geom2d_Transformation::*)(const opencascade::handle<Geom2d_Transformation> &) const) &Geom2d_Transformation::operator*, py::is_operator(), "None", py::arg("Other"));
cls_Geom2d_Transformation.def("Multiply", (void (Geom2d_Transformation::*)(const opencascade::handle<Geom2d_Transformation> &)) &Geom2d_Transformation::Multiply, "Computes the transformation composed with Other and <me> . <me> = <me> * Other.", py::arg("Other"));
cls_Geom2d_Transformation.def("__imul__", (void (Geom2d_Transformation::*)(const opencascade::handle<Geom2d_Transformation> &)) &Geom2d_Transformation::operator*=, py::is_operator(), "None", py::arg("Other"));
cls_Geom2d_Transformation.def("Power", (void (Geom2d_Transformation::*)(const Standard_Integer)) &Geom2d_Transformation::Power, "Raised if N < 0 and if the transformation is not inversible", py::arg("N"));
cls_Geom2d_Transformation.def("Powered", (opencascade::handle<Geom2d_Transformation> (Geom2d_Transformation::*)(const Standard_Integer) const) &Geom2d_Transformation::Powered, "Raised if N < 0 and if the transformation is not inversible", py::arg("N"));
cls_Geom2d_Transformation.def("PreMultiply", (void (Geom2d_Transformation::*)(const opencascade::handle<Geom2d_Transformation> &)) &Geom2d_Transformation::PreMultiply, "Computes the matrix of the transformation composed with <me> and Other. <me> = Other * <me>", py::arg("Other"));
cls_Geom2d_Transformation.def("Transforms", [](Geom2d_Transformation &self, Standard_Real & X, Standard_Real & Y){ self.Transforms(X, Y); return std::tuple<Standard_Real &, Standard_Real &>(X, Y); }, "Applies the transformation <me> to the triplet {X, Y}.", py::arg("X"), py::arg("Y"));
cls_Geom2d_Transformation.def("Copy", (opencascade::handle<Geom2d_Transformation> (Geom2d_Transformation::*)() const) &Geom2d_Transformation::Copy, "Creates a new object, which is a copy of this transformation.");
cls_Geom2d_Transformation.def_static("get_type_name_", (const char * (*)()) &Geom2d_Transformation::get_type_name, "None");
cls_Geom2d_Transformation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Geom2d_Transformation::get_type_descriptor, "None");
cls_Geom2d_Transformation.def("DynamicType", (const opencascade::handle<Standard_Type> & (Geom2d_Transformation::*)() const) &Geom2d_Transformation::DynamicType, "None");

// Enums

}