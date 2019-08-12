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
#include <gp_Trsf2d.hxx>
#include <gp_Mat2d.hxx>
#include <gp_XY.hxx>
#include <gp_Ax2d.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_TrsfForm.hxx>
#include <gp_GTrsf2d.hxx>

void bind_gp_GTrsf2d(py::module &mod){

py::class_<gp_GTrsf2d, std::unique_ptr<gp_GTrsf2d, Deleter<gp_GTrsf2d>>> cls_gp_GTrsf2d(mod, "gp_GTrsf2d", "Defines a non persistent transformation in 2D space. This transformation is a general transformation. It can be a Trsf2d from package gp, an affinity, or you can define your own transformation giving the corresponding matrix of transformation.");

// Constructors
cls_gp_GTrsf2d.def(py::init<>());
cls_gp_GTrsf2d.def(py::init<const gp_Trsf2d &>(), py::arg("T"));
cls_gp_GTrsf2d.def(py::init<const gp_Mat2d &, const gp_XY &>(), py::arg("M"), py::arg("V"));

// Fields

// Methods
// cls_gp_GTrsf2d.def_static("operator new_", (void * (*)(size_t)) &gp_GTrsf2d::operator new, "None", py::arg("theSize"));
// cls_gp_GTrsf2d.def_static("operator delete_", (void (*)(void *)) &gp_GTrsf2d::operator delete, "None", py::arg("theAddress"));
// cls_gp_GTrsf2d.def_static("operator new[]_", (void * (*)(size_t)) &gp_GTrsf2d::operator new[], "None", py::arg("theSize"));
// cls_gp_GTrsf2d.def_static("operator delete[]_", (void (*)(void *)) &gp_GTrsf2d::operator delete[], "None", py::arg("theAddress"));
// cls_gp_GTrsf2d.def_static("operator new_", (void * (*)(size_t, void *)) &gp_GTrsf2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gp_GTrsf2d.def_static("operator delete_", (void (*)(void *, void *)) &gp_GTrsf2d::operator delete, "None", py::arg(""), py::arg(""));
cls_gp_GTrsf2d.def("SetAffinity", (void (gp_GTrsf2d::*)(const gp_Ax2d &, const Standard_Real)) &gp_GTrsf2d::SetAffinity, "Changes this transformation into an affinity of ratio Ratio with respect to the axis A. Note: An affinity is a point-by-point transformation that transforms any point P into a point P' such that if H is the orthogonal projection of P on the axis A, the vectors HP and HP' satisfy: HP' = Ratio * HP.", py::arg("A"), py::arg("Ratio"));
cls_gp_GTrsf2d.def("SetValue", (void (gp_GTrsf2d::*)(const Standard_Integer, const Standard_Integer, const Standard_Real)) &gp_GTrsf2d::SetValue, "Replaces the coefficient (Row, Col) of the matrix representing this transformation by Value, Raises OutOfRange if Row < 1 or Row > 2 or Col < 1 or Col > 3", py::arg("Row"), py::arg("Col"), py::arg("Value"));
cls_gp_GTrsf2d.def("SetTranslationPart", (void (gp_GTrsf2d::*)(const gp_XY &)) &gp_GTrsf2d::SetTranslationPart, "Replacesthe translation part of this transformation by the coordinates of the number pair Coord.", py::arg("Coord"));
cls_gp_GTrsf2d.def("SetTrsf2d", (void (gp_GTrsf2d::*)(const gp_Trsf2d &)) &gp_GTrsf2d::SetTrsf2d, "Assigns the vectorial and translation parts of T to this transformation.", py::arg("T"));
cls_gp_GTrsf2d.def("SetVectorialPart", (void (gp_GTrsf2d::*)(const gp_Mat2d &)) &gp_GTrsf2d::SetVectorialPart, "Replaces the vectorial part of this transformation by Matrix.", py::arg("Matrix"));
cls_gp_GTrsf2d.def("IsNegative", (Standard_Boolean (gp_GTrsf2d::*)() const) &gp_GTrsf2d::IsNegative, "Returns true if the determinant of the vectorial part of this transformation is negative.");
cls_gp_GTrsf2d.def("IsSingular", (Standard_Boolean (gp_GTrsf2d::*)() const) &gp_GTrsf2d::IsSingular, "Returns true if this transformation is singular (and therefore, cannot be inverted). Note: The Gauss LU decomposition is used to invert the transformation matrix. Consequently, the transformation is considered as singular if the largest pivot found is less than or equal to gp::Resolution(). Warning If this transformation is singular, it cannot be inverted.");
cls_gp_GTrsf2d.def("Form", (gp_TrsfForm (gp_GTrsf2d::*)() const) &gp_GTrsf2d::Form, "Returns the nature of the transformation. It can be an identity transformation, a rotation, a translation, a mirror transformation (relative to a point or axis), a scaling transformation, a compound transformation or some other type of transformation.");
cls_gp_GTrsf2d.def("TranslationPart", (const gp_XY & (gp_GTrsf2d::*)() const) &gp_GTrsf2d::TranslationPart, "Returns the translation part of the GTrsf2d.");
cls_gp_GTrsf2d.def("VectorialPart", (const gp_Mat2d & (gp_GTrsf2d::*)() const) &gp_GTrsf2d::VectorialPart, "Computes the vectorial part of the GTrsf2d. The returned Matrix is a 2*2 matrix.");
cls_gp_GTrsf2d.def("Value", (Standard_Real (gp_GTrsf2d::*)(const Standard_Integer, const Standard_Integer) const) &gp_GTrsf2d::Value, "Returns the coefficients of the global matrix of transformation. Raised OutOfRange if Row < 1 or Row > 2 or Col < 1 or Col > 3", py::arg("Row"), py::arg("Col"));
cls_gp_GTrsf2d.def("__call__", (Standard_Real (gp_GTrsf2d::*)(const Standard_Integer, const Standard_Integer) const) &gp_GTrsf2d::operator(), py::is_operator(), "None", py::arg("Row"), py::arg("Col"));
cls_gp_GTrsf2d.def("Invert", (void (gp_GTrsf2d::*)()) &gp_GTrsf2d::Invert, "None");
cls_gp_GTrsf2d.def("Inverted", (gp_GTrsf2d (gp_GTrsf2d::*)() const) &gp_GTrsf2d::Inverted, "Computes the reverse transformation. Raised an exception if the matrix of the transformation is not inversible.");
cls_gp_GTrsf2d.def("Multiplied", (gp_GTrsf2d (gp_GTrsf2d::*)(const gp_GTrsf2d &) const) &gp_GTrsf2d::Multiplied, "Computes the transformation composed with T and <me>. In a C++ implementation you can also write Tcomposed = <me> * T. Example : GTrsf2d T1, T2, Tcomp; ............... //composition : Tcomp = T2.Multiplied(T1); // or (Tcomp = T2 * T1) // transformation of a point XY P(10.,3.); XY P1(P); Tcomp.Transforms(P1); //using Tcomp XY P2(P); T1.Transforms(P2); //using T1 then T2 T2.Transforms(P2); // P1 = P2 !!!", py::arg("T"));
cls_gp_GTrsf2d.def("__mul__", (gp_GTrsf2d (gp_GTrsf2d::*)(const gp_GTrsf2d &) const) &gp_GTrsf2d::operator*, py::is_operator(), "None", py::arg("T"));
cls_gp_GTrsf2d.def("Multiply", (void (gp_GTrsf2d::*)(const gp_GTrsf2d &)) &gp_GTrsf2d::Multiply, "None", py::arg("T"));
cls_gp_GTrsf2d.def("__imul__", (void (gp_GTrsf2d::*)(const gp_GTrsf2d &)) &gp_GTrsf2d::operator*=, py::is_operator(), "None", py::arg("T"));
cls_gp_GTrsf2d.def("PreMultiply", (void (gp_GTrsf2d::*)(const gp_GTrsf2d &)) &gp_GTrsf2d::PreMultiply, "Computes the product of the transformation T and this transformation, and assigns the result to this transformation: this = T * this", py::arg("T"));
cls_gp_GTrsf2d.def("Power", (void (gp_GTrsf2d::*)(const Standard_Integer)) &gp_GTrsf2d::Power, "None", py::arg("N"));
cls_gp_GTrsf2d.def("Powered", (gp_GTrsf2d (gp_GTrsf2d::*)(const Standard_Integer) const) &gp_GTrsf2d::Powered, "Computes the following composition of transformations <me> * <me> * .......* <me>, N time. if N = 0 <me> = Identity if N < 0 <me> = <me>.Inverse() *...........* <me>.Inverse().", py::arg("N"));
cls_gp_GTrsf2d.def("Transforms", (void (gp_GTrsf2d::*)(gp_XY &) const) &gp_GTrsf2d::Transforms, "None", py::arg("Coord"));
cls_gp_GTrsf2d.def("Transformed", (gp_XY (gp_GTrsf2d::*)(const gp_XY &) const) &gp_GTrsf2d::Transformed, "None", py::arg("Coord"));
cls_gp_GTrsf2d.def("Transforms", [](gp_GTrsf2d &self, Standard_Real & X, Standard_Real & Y){ self.Transforms(X, Y); return std::tuple<Standard_Real &, Standard_Real &>(X, Y); }, "Applies this transformation to the coordinates: - of the number pair Coord, or - X and Y.", py::arg("X"), py::arg("Y"));
cls_gp_GTrsf2d.def("Trsf2d", (gp_Trsf2d (gp_GTrsf2d::*)() const) &gp_GTrsf2d::Trsf2d, "Converts this transformation into a gp_Trsf2d transformation. Exceptions Standard_ConstructionError if this transformation cannot be converted, i.e. if its form is gp_Other.");

// Enums

}