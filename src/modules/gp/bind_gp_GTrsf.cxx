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
#include <gp_Mat.hxx>
#include <gp_XYZ.hxx>
#include <gp_Ax1.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Ax2.hxx>
#include <gp_TrsfForm.hxx>
#include <gp_GTrsf.hxx>

void bind_gp_GTrsf(py::module &mod){

py::class_<gp_GTrsf, std::unique_ptr<gp_GTrsf, Deleter<gp_GTrsf>>> cls_gp_GTrsf(mod, "gp_GTrsf", "Defines a non-persistent transformation in 3D space. This transformation is a general transformation. It can be a Trsf from gp, an affinity, or you can define your own transformation giving the matrix of transformation.");

// Constructors
cls_gp_GTrsf.def(py::init<>());
cls_gp_GTrsf.def(py::init<const gp_Trsf &>(), py::arg("T"));
cls_gp_GTrsf.def(py::init<const gp_Mat &, const gp_XYZ &>(), py::arg("M"), py::arg("V"));

// Fields

// Methods
// cls_gp_GTrsf.def_static("operator new_", (void * (*)(size_t)) &gp_GTrsf::operator new, "None", py::arg("theSize"));
// cls_gp_GTrsf.def_static("operator delete_", (void (*)(void *)) &gp_GTrsf::operator delete, "None", py::arg("theAddress"));
// cls_gp_GTrsf.def_static("operator new[]_", (void * (*)(size_t)) &gp_GTrsf::operator new[], "None", py::arg("theSize"));
// cls_gp_GTrsf.def_static("operator delete[]_", (void (*)(void *)) &gp_GTrsf::operator delete[], "None", py::arg("theAddress"));
// cls_gp_GTrsf.def_static("operator new_", (void * (*)(size_t, void *)) &gp_GTrsf::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gp_GTrsf.def_static("operator delete_", (void (*)(void *, void *)) &gp_GTrsf::operator delete, "None", py::arg(""), py::arg(""));
cls_gp_GTrsf.def("SetAffinity", (void (gp_GTrsf::*)(const gp_Ax1 &, const Standard_Real)) &gp_GTrsf::SetAffinity, "Changes this transformation into an affinity of ratio Ratio with respect to the axis A1. Note: an affinity is a point-by-point transformation that transforms any point P into a point P' such that if H is the orthogonal projection of P on the axis A1 or the plane A2, the vectors HP and HP' satisfy: HP' = Ratio * HP.", py::arg("A1"), py::arg("Ratio"));
cls_gp_GTrsf.def("SetAffinity", (void (gp_GTrsf::*)(const gp_Ax2 &, const Standard_Real)) &gp_GTrsf::SetAffinity, "Changes this transformation into an affinity of ratio Ratio with respect to the plane defined by the origin, the 'X Direction' and the 'Y Direction' of coordinate system A2. Note: an affinity is a point-by-point transformation that transforms any point P into a point P' such that if H is the orthogonal projection of P on the axis A1 or the plane A2, the vectors HP and HP' satisfy: HP' = Ratio * HP.", py::arg("A2"), py::arg("Ratio"));
cls_gp_GTrsf.def("SetValue", (void (gp_GTrsf::*)(const Standard_Integer, const Standard_Integer, const Standard_Real)) &gp_GTrsf::SetValue, "Replaces the coefficient (Row, Col) of the matrix representing this transformation by Value. Raises OutOfRange if Row < 1 or Row > 3 or Col < 1 or Col > 4", py::arg("Row"), py::arg("Col"), py::arg("Value"));
cls_gp_GTrsf.def("SetVectorialPart", (void (gp_GTrsf::*)(const gp_Mat &)) &gp_GTrsf::SetVectorialPart, "Replaces the vectorial part of this transformation by Matrix.", py::arg("Matrix"));
cls_gp_GTrsf.def("SetTranslationPart", (void (gp_GTrsf::*)(const gp_XYZ &)) &gp_GTrsf::SetTranslationPart, "Replaces the translation part of this transformation by the coordinates of the number triple Coord.", py::arg("Coord"));
cls_gp_GTrsf.def("SetTrsf", (void (gp_GTrsf::*)(const gp_Trsf &)) &gp_GTrsf::SetTrsf, "Assigns the vectorial and translation parts of T to this transformation.", py::arg("T"));
cls_gp_GTrsf.def("IsNegative", (Standard_Boolean (gp_GTrsf::*)() const) &gp_GTrsf::IsNegative, "Returns true if the determinant of the vectorial part of this transformation is negative.");
cls_gp_GTrsf.def("IsSingular", (Standard_Boolean (gp_GTrsf::*)() const) &gp_GTrsf::IsSingular, "Returns true if this transformation is singular (and therefore, cannot be inverted). Note: The Gauss LU decomposition is used to invert the transformation matrix. Consequently, the transformation is considered as singular if the largest pivot found is less than or equal to gp::Resolution(). Warning If this transformation is singular, it cannot be inverted.");
cls_gp_GTrsf.def("Form", (gp_TrsfForm (gp_GTrsf::*)() const) &gp_GTrsf::Form, "Returns the nature of the transformation. It can be an identity transformation, a rotation, a translation, a mirror transformation (relative to a point, an axis or a plane), a scaling transformation, a compound transformation or some other type of transformation.");
cls_gp_GTrsf.def("SetForm", (void (gp_GTrsf::*)()) &gp_GTrsf::SetForm, "verify and set the shape of the GTrsf Other or CompoundTrsf Ex : myGTrsf.SetValue(row1,col1,val1); myGTrsf.SetValue(row2,col2,val2); ... myGTrsf.SetForm();");
cls_gp_GTrsf.def("TranslationPart", (const gp_XYZ & (gp_GTrsf::*)() const) &gp_GTrsf::TranslationPart, "Returns the translation part of the GTrsf.");
cls_gp_GTrsf.def("VectorialPart", (const gp_Mat & (gp_GTrsf::*)() const) &gp_GTrsf::VectorialPart, "Computes the vectorial part of the GTrsf. The returned Matrix is a 3*3 matrix.");
cls_gp_GTrsf.def("Value", (Standard_Real (gp_GTrsf::*)(const Standard_Integer, const Standard_Integer) const) &gp_GTrsf::Value, "Returns the coefficients of the global matrix of transformation. Raises OutOfRange if Row < 1 or Row > 3 or Col < 1 or Col > 4", py::arg("Row"), py::arg("Col"));
cls_gp_GTrsf.def("__call__", (Standard_Real (gp_GTrsf::*)(const Standard_Integer, const Standard_Integer) const) &gp_GTrsf::operator(), py::is_operator(), "None", py::arg("Row"), py::arg("Col"));
cls_gp_GTrsf.def("Invert", (void (gp_GTrsf::*)()) &gp_GTrsf::Invert, "None");
cls_gp_GTrsf.def("Inverted", (gp_GTrsf (gp_GTrsf::*)() const) &gp_GTrsf::Inverted, "Computes the reverse transformation. Raises an exception if the matrix of the transformation is not inversible.");
cls_gp_GTrsf.def("Multiplied", (gp_GTrsf (gp_GTrsf::*)(const gp_GTrsf &) const) &gp_GTrsf::Multiplied, "Computes the transformation composed from T and <me>. In a C++ implementation you can also write Tcomposed = <me> * T. Example : GTrsf T1, T2, Tcomp; ............... //composition : Tcomp = T2.Multiplied(T1); // or (Tcomp = T2 * T1) // transformation of a point XYZ P(10.,3.,4.); XYZ P1(P); Tcomp.Transforms(P1); //using Tcomp XYZ P2(P); T1.Transforms(P2); //using T1 then T2 T2.Transforms(P2); // P1 = P2 !!!", py::arg("T"));
cls_gp_GTrsf.def("__mul__", (gp_GTrsf (gp_GTrsf::*)(const gp_GTrsf &) const) &gp_GTrsf::operator*, py::is_operator(), "None", py::arg("T"));
cls_gp_GTrsf.def("Multiply", (void (gp_GTrsf::*)(const gp_GTrsf &)) &gp_GTrsf::Multiply, "Computes the transformation composed with <me> and T. <me> = <me> * T", py::arg("T"));
cls_gp_GTrsf.def("__imul__", (void (gp_GTrsf::*)(const gp_GTrsf &)) &gp_GTrsf::operator*=, py::is_operator(), "None", py::arg("T"));
cls_gp_GTrsf.def("PreMultiply", (void (gp_GTrsf::*)(const gp_GTrsf &)) &gp_GTrsf::PreMultiply, "Computes the product of the transformation T and this transformation and assigns the result to this transformation. this = T * this", py::arg("T"));
cls_gp_GTrsf.def("Power", (void (gp_GTrsf::*)(const Standard_Integer)) &gp_GTrsf::Power, "None", py::arg("N"));
cls_gp_GTrsf.def("Powered", (gp_GTrsf (gp_GTrsf::*)(const Standard_Integer) const) &gp_GTrsf::Powered, "Computes: - the product of this transformation multiplied by itself N times, if N is positive, or - the product of the inverse of this transformation multiplied by itself |N| times, if N is negative. If N equals zero, the result is equal to the Identity transformation. I.e.: <me> * <me> * .......* <me>, N time. if N =0 <me> = Identity if N < 0 <me> = <me>.Inverse() *...........* <me>.Inverse().", py::arg("N"));
cls_gp_GTrsf.def("Transforms", (void (gp_GTrsf::*)(gp_XYZ &) const) &gp_GTrsf::Transforms, "None", py::arg("Coord"));
cls_gp_GTrsf.def("Transforms", [](gp_GTrsf &self, Standard_Real & X, Standard_Real & Y, Standard_Real & Z){ self.Transforms(X, Y, Z); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(X, Y, Z); }, "Transforms a triplet XYZ with a GTrsf.", py::arg("X"), py::arg("Y"), py::arg("Z"));
cls_gp_GTrsf.def("Trsf", (gp_Trsf (gp_GTrsf::*)() const) &gp_GTrsf::Trsf, "None");

// Enums

}