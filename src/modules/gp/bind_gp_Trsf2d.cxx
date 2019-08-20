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
#include <gp_Trsf.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Ax2d.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Vec2d.hxx>
#include <gp_TrsfForm.hxx>
#include <gp_XY.hxx>
#include <gp_Mat2d.hxx>
#include <gp_Trsf2d.hxx>
#include <gp_GTrsf2d.hxx>

void bind_gp_Trsf2d(py::module &mod){

py::class_<gp_Trsf2d, std::unique_ptr<gp_Trsf2d>> cls_gp_Trsf2d(mod, "gp_Trsf2d", "Defines a non-persistent transformation in 2D space. The following transformations are implemented : . Translation, Rotation, Scale . Symmetry with respect to a point and a line. Complex transformations can be obtained by combining the previous elementary transformations using the method Multiply. The transformations can be represented as follow :");

// Constructors
cls_gp_Trsf2d.def(py::init<>());
cls_gp_Trsf2d.def(py::init<const gp_Trsf &>(), py::arg("T"));

// Fields

// Methods
// cls_gp_Trsf2d.def_static("operator new_", (void * (*)(size_t)) &gp_Trsf2d::operator new, "None", py::arg("theSize"));
// cls_gp_Trsf2d.def_static("operator delete_", (void (*)(void *)) &gp_Trsf2d::operator delete, "None", py::arg("theAddress"));
// cls_gp_Trsf2d.def_static("operator new[]_", (void * (*)(size_t)) &gp_Trsf2d::operator new[], "None", py::arg("theSize"));
// cls_gp_Trsf2d.def_static("operator delete[]_", (void (*)(void *)) &gp_Trsf2d::operator delete[], "None", py::arg("theAddress"));
// cls_gp_Trsf2d.def_static("operator new_", (void * (*)(size_t, void *)) &gp_Trsf2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gp_Trsf2d.def_static("operator delete_", (void (*)(void *, void *)) &gp_Trsf2d::operator delete, "None", py::arg(""), py::arg(""));
cls_gp_Trsf2d.def("SetMirror", (void (gp_Trsf2d::*)(const gp_Pnt2d &)) &gp_Trsf2d::SetMirror, "Changes the transformation into a symmetrical transformation. P is the center of the symmetry.", py::arg("P"));
cls_gp_Trsf2d.def("SetMirror", (void (gp_Trsf2d::*)(const gp_Ax2d &)) &gp_Trsf2d::SetMirror, "Changes the transformation into a symmetrical transformation. A is the center of the axial symmetry.", py::arg("A"));
cls_gp_Trsf2d.def("SetRotation", (void (gp_Trsf2d::*)(const gp_Pnt2d &, const Standard_Real)) &gp_Trsf2d::SetRotation, "Changes the transformation into a rotation. P is the rotation's center and Ang is the angular value of the rotation in radian.", py::arg("P"), py::arg("Ang"));
cls_gp_Trsf2d.def("SetScale", (void (gp_Trsf2d::*)(const gp_Pnt2d &, const Standard_Real)) &gp_Trsf2d::SetScale, "Changes the transformation into a scale. P is the center of the scale and S is the scaling value.", py::arg("P"), py::arg("S"));
cls_gp_Trsf2d.def("SetTransformation", (void (gp_Trsf2d::*)(const gp_Ax2d &, const gp_Ax2d &)) &gp_Trsf2d::SetTransformation, "Changes a transformation allowing passage from the coordinate system 'FromSystem1' to the coordinate system 'ToSystem2'.", py::arg("FromSystem1"), py::arg("ToSystem2"));
cls_gp_Trsf2d.def("SetTransformation", (void (gp_Trsf2d::*)(const gp_Ax2d &)) &gp_Trsf2d::SetTransformation, "Changes the transformation allowing passage from the basic coordinate system {P(0.,0.,0.), VX (1.,0.,0.), VY (0.,1.,0.)} to the local coordinate system defined with the Ax2d ToSystem.", py::arg("ToSystem"));
cls_gp_Trsf2d.def("SetTranslation", (void (gp_Trsf2d::*)(const gp_Vec2d &)) &gp_Trsf2d::SetTranslation, "Changes the transformation into a translation. V is the vector of the translation.", py::arg("V"));
cls_gp_Trsf2d.def("SetTranslation", (void (gp_Trsf2d::*)(const gp_Pnt2d &, const gp_Pnt2d &)) &gp_Trsf2d::SetTranslation, "Makes the transformation into a translation from the point P1 to the point P2.", py::arg("P1"), py::arg("P2"));
cls_gp_Trsf2d.def("SetTranslationPart", (void (gp_Trsf2d::*)(const gp_Vec2d &)) &gp_Trsf2d::SetTranslationPart, "Replaces the translation vector with V.", py::arg("V"));
cls_gp_Trsf2d.def("SetScaleFactor", (void (gp_Trsf2d::*)(const Standard_Real)) &gp_Trsf2d::SetScaleFactor, "Modifies the scale factor.", py::arg("S"));
cls_gp_Trsf2d.def("IsNegative", (Standard_Boolean (gp_Trsf2d::*)() const) &gp_Trsf2d::IsNegative, "Returns true if the determinant of the vectorial part of this transformation is negative..");
cls_gp_Trsf2d.def("Form", (gp_TrsfForm (gp_Trsf2d::*)() const) &gp_Trsf2d::Form, "Returns the nature of the transformation. It can be an identity transformation, a rotation, a translation, a mirror (relative to a point or an axis), a scaling transformation, or a compound transformation.");
cls_gp_Trsf2d.def("ScaleFactor", (Standard_Real (gp_Trsf2d::*)() const) &gp_Trsf2d::ScaleFactor, "Returns the scale factor.");
cls_gp_Trsf2d.def("TranslationPart", (const gp_XY & (gp_Trsf2d::*)() const) &gp_Trsf2d::TranslationPart, "Returns the translation part of the transformation's matrix");
cls_gp_Trsf2d.def("VectorialPart", (gp_Mat2d (gp_Trsf2d::*)() const) &gp_Trsf2d::VectorialPart, "Returns the vectorial part of the transformation. It is a 2*2 matrix which includes the scale factor.");
cls_gp_Trsf2d.def("HVectorialPart", (const gp_Mat2d & (gp_Trsf2d::*)() const) &gp_Trsf2d::HVectorialPart, "Returns the homogeneous vectorial part of the transformation. It is a 2*2 matrix which doesn't include the scale factor. The coefficients of this matrix must be multiplied by the scale factor to obtain the coefficients of the transformation.");
cls_gp_Trsf2d.def("RotationPart", (Standard_Real (gp_Trsf2d::*)() const) &gp_Trsf2d::RotationPart, "Returns the angle corresponding to the rotational component of the transformation matrix (operation opposite to SetRotation()).");
cls_gp_Trsf2d.def("Value", (Standard_Real (gp_Trsf2d::*)(const Standard_Integer, const Standard_Integer) const) &gp_Trsf2d::Value, "Returns the coefficients of the transformation's matrix. It is a 2 rows * 3 columns matrix. Raises OutOfRange if Row < 1 or Row > 2 or Col < 1 or Col > 3", py::arg("Row"), py::arg("Col"));
cls_gp_Trsf2d.def("Invert", (void (gp_Trsf2d::*)()) &gp_Trsf2d::Invert, "None");
cls_gp_Trsf2d.def("Inverted", (gp_Trsf2d (gp_Trsf2d::*)() const) &gp_Trsf2d::Inverted, "Computes the reverse transformation. Raises an exception if the matrix of the transformation is not inversible, it means that the scale factor is lower or equal to Resolution from package gp.");
cls_gp_Trsf2d.def("Multiplied", (gp_Trsf2d (gp_Trsf2d::*)(const gp_Trsf2d &) const) &gp_Trsf2d::Multiplied, "None", py::arg("T"));
cls_gp_Trsf2d.def("__mul__", (gp_Trsf2d (gp_Trsf2d::*)(const gp_Trsf2d &) const) &gp_Trsf2d::operator*, py::is_operator(), "None", py::arg("T"));
cls_gp_Trsf2d.def("Multiply", (void (gp_Trsf2d::*)(const gp_Trsf2d &)) &gp_Trsf2d::Multiply, "Computes the transformation composed from <me> and T. <me> = <me> * T", py::arg("T"));
cls_gp_Trsf2d.def("__imul__", (void (gp_Trsf2d::*)(const gp_Trsf2d &)) &gp_Trsf2d::operator*=, py::is_operator(), "None", py::arg("T"));
cls_gp_Trsf2d.def("PreMultiply", (void (gp_Trsf2d::*)(const gp_Trsf2d &)) &gp_Trsf2d::PreMultiply, "Computes the transformation composed from <me> and T. <me> = T * <me>", py::arg("T"));
cls_gp_Trsf2d.def("Power", (void (gp_Trsf2d::*)(const Standard_Integer)) &gp_Trsf2d::Power, "None", py::arg("N"));
cls_gp_Trsf2d.def("Powered", (gp_Trsf2d (gp_Trsf2d::*)(const Standard_Integer)) &gp_Trsf2d::Powered, "Computes the following composition of transformations <me> * <me> * .......* <me>, N time. if N = 0 <me> = Identity if N < 0 <me> = <me>.Inverse() *...........* <me>.Inverse().", py::arg("N"));
cls_gp_Trsf2d.def("Transforms", [](gp_Trsf2d &self, Standard_Real & X, Standard_Real & Y){ self.Transforms(X, Y); return std::tuple<Standard_Real &, Standard_Real &>(X, Y); }, "None", py::arg("X"), py::arg("Y"));
cls_gp_Trsf2d.def("Transforms", (void (gp_Trsf2d::*)(gp_XY &) const) &gp_Trsf2d::Transforms, "Transforms a doublet XY with a Trsf2d", py::arg("Coord"));
cls_gp_Trsf2d.def("SetValues", (void (gp_Trsf2d::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &gp_Trsf2d::SetValues, "Sets the coefficients of the transformation. The transformation of the point x,y is the point x',y' with :", py::arg("a11"), py::arg("a12"), py::arg("a13"), py::arg("a21"), py::arg("a22"), py::arg("a23"));

// Enums

}