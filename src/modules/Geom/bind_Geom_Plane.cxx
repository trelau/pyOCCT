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
#include <Geom_ElementarySurface.hxx>
#include <gp_Ax3.hxx>
#include <gp_Pln.hxx>
#include <gp_Pnt.hxx>
#include <gp_Dir.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Trsf.hxx>
#include <gp_GTrsf2d.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Curve.hxx>
#include <gp_Vec.hxx>
#include <Geom_Geometry.hxx>
#include <Geom_Plane.hxx>
#include <Standard_Type.hxx>

void bind_Geom_Plane(py::module &mod){

py::class_<Geom_Plane, opencascade::handle<Geom_Plane>, Geom_ElementarySurface> cls_Geom_Plane(mod, "Geom_Plane", "Describes a plane in 3D space. A plane is positioned in space by a coordinate system (a gp_Ax3 object) such that the plane is defined by the origin, 'X Direction' and 'Y Direction' of this coordinate system. This coordinate system is the 'local coordinate system' of the plane. The following apply: - Its 'X Direction' and 'Y Direction' are respectively the u and v parametric directions of the plane. - Its origin is the origin of the u and v parameters (also called the 'origin' of the plane). - Its 'main Direction' is a vector normal to the plane. This normal vector gives the orientation of the plane only if the local coordinate system is 'direct'. (The orientation of the plane is always defined by the 'X Direction' and the 'Y Direction' of its local coordinate system.) The parametric equation of the plane is: P(u, v) = O + u*XDir + v*YDir where O, XDir and YDir are respectively the origin, the 'X Direction' and the 'Y Direction' of the local coordinate system of the plane. The parametric range of the two parameters u and v is ] -infinity, +infinity [.");

// Constructors
cls_Geom_Plane.def(py::init<const gp_Ax3 &>(), py::arg("A3"));
cls_Geom_Plane.def(py::init<const gp_Pln &>(), py::arg("Pl"));
cls_Geom_Plane.def(py::init<const gp_Pnt &, const gp_Dir &>(), py::arg("P"), py::arg("V"));
cls_Geom_Plane.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("A"), py::arg("B"), py::arg("C"), py::arg("D"));

// Fields

// Methods
cls_Geom_Plane.def("SetPln", (void (Geom_Plane::*)(const gp_Pln &)) &Geom_Plane::SetPln, "Set <me> so that <me> has the same geometric properties as Pl.", py::arg("Pl"));
cls_Geom_Plane.def("Pln", (gp_Pln (Geom_Plane::*)() const) &Geom_Plane::Pln, "Converts this plane into a gp_Pln plane.");
cls_Geom_Plane.def("UReverse", (void (Geom_Plane::*)()) &Geom_Plane::UReverse, "Changes the orientation of this plane in the u (or v) parametric direction. The bounds of the plane are not changed but the given parametric direction is reversed. Hence the orientation of the surface is reversed.");
cls_Geom_Plane.def("UReversedParameter", (Standard_Real (Geom_Plane::*)(const Standard_Real) const) &Geom_Plane::UReversedParameter, "Computes the u parameter on the modified plane, produced when reversing the u parametric of this plane, for any point of u parameter U on this plane. In the case of a plane, these methods return - -U.", py::arg("U"));
cls_Geom_Plane.def("VReverse", (void (Geom_Plane::*)()) &Geom_Plane::VReverse, "Changes the orientation of this plane in the u (or v) parametric direction. The bounds of the plane are not changed but the given parametric direction is reversed. Hence the orientation of the surface is reversed.");
cls_Geom_Plane.def("VReversedParameter", (Standard_Real (Geom_Plane::*)(const Standard_Real) const) &Geom_Plane::VReversedParameter, "Computes the v parameter on the modified plane, produced when reversing the v parametric of this plane, for any point of v parameter V on this plane. In the case of a plane, these methods return -V.", py::arg("V"));
cls_Geom_Plane.def("TransformParameters", [](Geom_Plane &self, Standard_Real & U, Standard_Real & V, const gp_Trsf & T){ self.TransformParameters(U, V, T); return std::tuple<Standard_Real &, Standard_Real &>(U, V); }, "Computes the parameters on the transformed surface for the transform of the point of parameters U,V on <me>. me->Transformed(T)->Value(U',V') is the same point as me->Value(U,V).Transformed(T) Where U',V' are the new values of U,V after calling me->TranformParameters(U,V,T) This methods multiplies U and V by T.ScaleFactor()", py::arg("U"), py::arg("V"), py::arg("T"));
cls_Geom_Plane.def("ParametricTransformation", (gp_GTrsf2d (Geom_Plane::*)(const gp_Trsf &) const) &Geom_Plane::ParametricTransformation, "Returns a 2d transformation used to find the new parameters of a point on the transformed surface. me->Transformed(T)->Value(U',V') is the same point as me->Value(U,V).Transformed(T) Where U',V' are obtained by transforming U,V with th 2d transformation returned by me->ParametricTransformation(T) This methods returns a scale centered on the origin with T.ScaleFactor", py::arg("T"));
cls_Geom_Plane.def("Bounds", [](Geom_Plane &self, Standard_Real & U1, Standard_Real & U2, Standard_Real & V1, Standard_Real & V2){ self.Bounds(U1, U2, V1, V2); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(U1, U2, V1, V2); }, "Returns the parametric bounds U1, U2, V1 and V2 of this plane. Because a plane is an infinite surface, the following is always true: - U1 = V1 = Standard_Real::RealFirst() - U2 = V2 = Standard_Real::RealLast().", py::arg("U1"), py::arg("U2"), py::arg("V1"), py::arg("V2"));
cls_Geom_Plane.def("Coefficients", [](Geom_Plane &self, Standard_Real & A, Standard_Real & B, Standard_Real & C, Standard_Real & D){ self.Coefficients(A, B, C, D); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(A, B, C, D); }, "Computes the normalized coefficients of the plane's cartesian equation : Ax + By + Cz + D = 0.0", py::arg("A"), py::arg("B"), py::arg("C"), py::arg("D"));
cls_Geom_Plane.def("IsUClosed", (Standard_Boolean (Geom_Plane::*)() const) &Geom_Plane::IsUClosed, "return False");
cls_Geom_Plane.def("IsVClosed", (Standard_Boolean (Geom_Plane::*)() const) &Geom_Plane::IsVClosed, "return False");
cls_Geom_Plane.def("IsUPeriodic", (Standard_Boolean (Geom_Plane::*)() const) &Geom_Plane::IsUPeriodic, "return False.");
cls_Geom_Plane.def("IsVPeriodic", (Standard_Boolean (Geom_Plane::*)() const) &Geom_Plane::IsVPeriodic, "return False.");
cls_Geom_Plane.def("UIso", (opencascade::handle<Geom_Curve> (Geom_Plane::*)(const Standard_Real) const) &Geom_Plane::UIso, "Computes the U isoparametric curve. This is a Line parallel to the YAxis of the plane.", py::arg("U"));
cls_Geom_Plane.def("VIso", (opencascade::handle<Geom_Curve> (Geom_Plane::*)(const Standard_Real) const) &Geom_Plane::VIso, "Computes the V isoparametric curve. This is a Line parallel to the XAxis of the plane.", py::arg("V"));
cls_Geom_Plane.def("D0", (void (Geom_Plane::*)(const Standard_Real, const Standard_Real, gp_Pnt &) const) &Geom_Plane::D0, "Computes the point P (U, V) on <me>. P = O + U * XDir + V * YDir. where O is the 'Location' point of the plane, XDir the 'XDirection' and YDir the 'YDirection' of the plane's local coordinate system.", py::arg("U"), py::arg("V"), py::arg("P"));
cls_Geom_Plane.def("D1", (void (Geom_Plane::*)(const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &) const) &Geom_Plane::D1, "Computes the current point and the first derivatives in the directions U and V.", py::arg("U"), py::arg("V"), py::arg("P"), py::arg("D1U"), py::arg("D1V"));
cls_Geom_Plane.def("D2", (void (Geom_Plane::*)(const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &) const) &Geom_Plane::D2, "Computes the current point, the first and the second derivatives in the directions U and V.", py::arg("U"), py::arg("V"), py::arg("P"), py::arg("D1U"), py::arg("D1V"), py::arg("D2U"), py::arg("D2V"), py::arg("D2UV"));
cls_Geom_Plane.def("D3", (void (Geom_Plane::*)(const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &) const) &Geom_Plane::D3, "Computes the current point, the first,the second and the third derivatives in the directions U and V.", py::arg("U"), py::arg("V"), py::arg("P"), py::arg("D1U"), py::arg("D1V"), py::arg("D2U"), py::arg("D2V"), py::arg("D2UV"), py::arg("D3U"), py::arg("D3V"), py::arg("D3UUV"), py::arg("D3UVV"));
cls_Geom_Plane.def("DN", (gp_Vec (Geom_Plane::*)(const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Integer) const) &Geom_Plane::DN, "Computes the derivative of order Nu in the direction u and Nv in the direction v. Raised if Nu + Nv < 1 or Nu < 0 or Nv < 0.", py::arg("U"), py::arg("V"), py::arg("Nu"), py::arg("Nv"));
cls_Geom_Plane.def("Transform", (void (Geom_Plane::*)(const gp_Trsf &)) &Geom_Plane::Transform, "Applies the transformation T to this plane.", py::arg("T"));
cls_Geom_Plane.def("Copy", (opencascade::handle<Geom_Geometry> (Geom_Plane::*)() const) &Geom_Plane::Copy, "Creates a new object which is a copy of this plane.");
cls_Geom_Plane.def_static("get_type_name_", (const char * (*)()) &Geom_Plane::get_type_name, "None");
cls_Geom_Plane.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Geom_Plane::get_type_descriptor, "None");
cls_Geom_Plane.def("DynamicType", (const opencascade::handle<Standard_Type> & (Geom_Plane::*)() const) &Geom_Plane::DynamicType, "None");

// Enums

}