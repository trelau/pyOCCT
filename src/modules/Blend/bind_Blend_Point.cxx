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
#include <gp_Pnt.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Vec.hxx>
#include <gp_Vec2d.hxx>
#include <Blend_Point.hxx>

void bind_Blend_Point(py::module &mod){

py::class_<Blend_Point> cls_Blend_Point(mod, "Blend_Point", "None");

// Constructors
cls_Blend_Point.def(py::init<>());
cls_Blend_Point.def(py::init<const gp_Pnt &, const gp_Pnt &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const gp_Vec &, const gp_Vec &, const gp_Vec2d &, const gp_Vec2d &>(), py::arg("Pt1"), py::arg("Pt2"), py::arg("Param"), py::arg("U1"), py::arg("V1"), py::arg("U2"), py::arg("V2"), py::arg("Tg1"), py::arg("Tg2"), py::arg("Tg12d"), py::arg("Tg22d"));
cls_Blend_Point.def(py::init<const gp_Pnt &, const gp_Pnt &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Pt1"), py::arg("Pt2"), py::arg("Param"), py::arg("U1"), py::arg("V1"), py::arg("U2"), py::arg("V2"));
cls_Blend_Point.def(py::init<const gp_Pnt &, const gp_Pnt &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const gp_Vec &, const gp_Vec &, const gp_Vec2d &>(), py::arg("Pts"), py::arg("Ptc"), py::arg("Param"), py::arg("U"), py::arg("V"), py::arg("W"), py::arg("Tgs"), py::arg("Tgc"), py::arg("Tg2d"));
cls_Blend_Point.def(py::init<const gp_Pnt &, const gp_Pnt &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Pts"), py::arg("Ptc"), py::arg("Param"), py::arg("U"), py::arg("V"), py::arg("W"));
cls_Blend_Point.def(py::init<const gp_Pnt &, const gp_Pnt &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const gp_Vec &, const gp_Vec &, const gp_Vec2d &, const gp_Vec2d &>(), py::arg("Pt1"), py::arg("Pt2"), py::arg("Param"), py::arg("U1"), py::arg("V1"), py::arg("U2"), py::arg("V2"), py::arg("PC"), py::arg("Tg1"), py::arg("Tg2"), py::arg("Tg12d"), py::arg("Tg22d"));
cls_Blend_Point.def(py::init<const gp_Pnt &, const gp_Pnt &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Pt1"), py::arg("Pt2"), py::arg("Param"), py::arg("U1"), py::arg("V1"), py::arg("U2"), py::arg("V2"), py::arg("PC"));
cls_Blend_Point.def(py::init<const gp_Pnt &, const gp_Pnt &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const gp_Vec &, const gp_Vec &, const gp_Vec2d &, const gp_Vec2d &>(), py::arg("Pt1"), py::arg("Pt2"), py::arg("Param"), py::arg("U1"), py::arg("V1"), py::arg("U2"), py::arg("V2"), py::arg("PC1"), py::arg("PC2"), py::arg("Tg1"), py::arg("Tg2"), py::arg("Tg12d"), py::arg("Tg22d"));
cls_Blend_Point.def(py::init<const gp_Pnt &, const gp_Pnt &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Pt1"), py::arg("Pt2"), py::arg("Param"), py::arg("U1"), py::arg("V1"), py::arg("U2"), py::arg("V2"), py::arg("PC1"), py::arg("PC2"));

// Fields

// Methods
// cls_Blend_Point.def_static("operator new_", (void * (*)(size_t)) &Blend_Point::operator new, "None", py::arg("theSize"));
// cls_Blend_Point.def_static("operator delete_", (void (*)(void *)) &Blend_Point::operator delete, "None", py::arg("theAddress"));
// cls_Blend_Point.def_static("operator new[]_", (void * (*)(size_t)) &Blend_Point::operator new[], "None", py::arg("theSize"));
// cls_Blend_Point.def_static("operator delete[]_", (void (*)(void *)) &Blend_Point::operator delete[], "None", py::arg("theAddress"));
// cls_Blend_Point.def_static("operator new_", (void * (*)(size_t, void *)) &Blend_Point::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Blend_Point.def_static("operator delete_", (void (*)(void *, void *)) &Blend_Point::operator delete, "None", py::arg(""), py::arg(""));
cls_Blend_Point.def("SetValue", (void (Blend_Point::*)(const gp_Pnt &, const gp_Pnt &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const gp_Vec &, const gp_Vec &, const gp_Vec2d &, const gp_Vec2d &)) &Blend_Point::SetValue, "Set the values for a point on 2 surfaces, with tangents.", py::arg("Pt1"), py::arg("Pt2"), py::arg("Param"), py::arg("U1"), py::arg("V1"), py::arg("U2"), py::arg("V2"), py::arg("Tg1"), py::arg("Tg2"), py::arg("Tg12d"), py::arg("Tg22d"));
cls_Blend_Point.def("SetValue", (void (Blend_Point::*)(const gp_Pnt &, const gp_Pnt &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &Blend_Point::SetValue, "Set the values for a point on 2 surfaces, without tangents.", py::arg("Pt1"), py::arg("Pt2"), py::arg("Param"), py::arg("U1"), py::arg("V1"), py::arg("U2"), py::arg("V2"));
cls_Blend_Point.def("SetValue", (void (Blend_Point::*)(const gp_Pnt &, const gp_Pnt &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const gp_Vec &, const gp_Vec &, const gp_Vec2d &)) &Blend_Point::SetValue, "Set the values for a point on a surface and a curve, with tangents.", py::arg("Pts"), py::arg("Ptc"), py::arg("Param"), py::arg("U"), py::arg("V"), py::arg("W"), py::arg("Tgs"), py::arg("Tgc"), py::arg("Tg2d"));
cls_Blend_Point.def("SetValue", (void (Blend_Point::*)(const gp_Pnt &, const gp_Pnt &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &Blend_Point::SetValue, "Set the values for a point on a surface and a curve, without tangents.", py::arg("Pts"), py::arg("Ptc"), py::arg("Param"), py::arg("U"), py::arg("V"), py::arg("W"));
cls_Blend_Point.def("SetValue", (void (Blend_Point::*)(const gp_Pnt &, const gp_Pnt &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const gp_Vec &, const gp_Vec &, const gp_Vec2d &, const gp_Vec2d &)) &Blend_Point::SetValue, "Creates a point on a surface and a curve on surface, with tangents.", py::arg("Pt1"), py::arg("Pt2"), py::arg("Param"), py::arg("U1"), py::arg("V1"), py::arg("U2"), py::arg("V2"), py::arg("PC"), py::arg("Tg1"), py::arg("Tg2"), py::arg("Tg12d"), py::arg("Tg22d"));
cls_Blend_Point.def("SetValue", (void (Blend_Point::*)(const gp_Pnt &, const gp_Pnt &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &Blend_Point::SetValue, "Creates a point on a surface and a curve on surface, without tangents.", py::arg("Pt1"), py::arg("Pt2"), py::arg("Param"), py::arg("U1"), py::arg("V1"), py::arg("U2"), py::arg("V2"), py::arg("PC"));
cls_Blend_Point.def("SetValue", (void (Blend_Point::*)(const gp_Pnt &, const gp_Pnt &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const gp_Vec &, const gp_Vec &, const gp_Vec2d &, const gp_Vec2d &)) &Blend_Point::SetValue, "Creates a point on two curves on surfaces, with tangents.", py::arg("Pt1"), py::arg("Pt2"), py::arg("Param"), py::arg("U1"), py::arg("V1"), py::arg("U2"), py::arg("V2"), py::arg("PC1"), py::arg("PC2"), py::arg("Tg1"), py::arg("Tg2"), py::arg("Tg12d"), py::arg("Tg22d"));
cls_Blend_Point.def("SetValue", (void (Blend_Point::*)(const gp_Pnt &, const gp_Pnt &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &Blend_Point::SetValue, "Creates a point on two curves on surfaces, without tangents.", py::arg("Pt1"), py::arg("Pt2"), py::arg("Param"), py::arg("U1"), py::arg("V1"), py::arg("U2"), py::arg("V2"), py::arg("PC1"), py::arg("PC2"));
cls_Blend_Point.def("SetValue", (void (Blend_Point::*)(const gp_Pnt &, const gp_Pnt &, const Standard_Real, const Standard_Real, const Standard_Real)) &Blend_Point::SetValue, "Creates a point on two curves.", py::arg("Pt1"), py::arg("Pt2"), py::arg("Param"), py::arg("PC1"), py::arg("PC2"));
cls_Blend_Point.def("SetParameter", (void (Blend_Point::*)(const Standard_Real)) &Blend_Point::SetParameter, "Changes parameter on existing point", py::arg("Param"));
cls_Blend_Point.def("Parameter", (Standard_Real (Blend_Point::*)() const) &Blend_Point::Parameter, "None");
cls_Blend_Point.def("IsTangencyPoint", (Standard_Boolean (Blend_Point::*)() const) &Blend_Point::IsTangencyPoint, "Returns Standard_True if it was not possible to compute the tangent vectors at PointOnS1 and/or PointOnS2.");
cls_Blend_Point.def("PointOnS1", (const gp_Pnt & (Blend_Point::*)() const) &Blend_Point::PointOnS1, "None");
cls_Blend_Point.def("PointOnS2", (const gp_Pnt & (Blend_Point::*)() const) &Blend_Point::PointOnS2, "None");
cls_Blend_Point.def("ParametersOnS1", [](Blend_Point &self, Standard_Real & U, Standard_Real & V){ self.ParametersOnS1(U, V); return std::tuple<Standard_Real &, Standard_Real &>(U, V); }, "None", py::arg("U"), py::arg("V"));
cls_Blend_Point.def("ParametersOnS2", [](Blend_Point &self, Standard_Real & U, Standard_Real & V){ self.ParametersOnS2(U, V); return std::tuple<Standard_Real &, Standard_Real &>(U, V); }, "None", py::arg("U"), py::arg("V"));
cls_Blend_Point.def("TangentOnS1", (const gp_Vec & (Blend_Point::*)() const) &Blend_Point::TangentOnS1, "None");
cls_Blend_Point.def("TangentOnS2", (const gp_Vec & (Blend_Point::*)() const) &Blend_Point::TangentOnS2, "None");
cls_Blend_Point.def("Tangent2dOnS1", (gp_Vec2d (Blend_Point::*)() const) &Blend_Point::Tangent2dOnS1, "None");
cls_Blend_Point.def("Tangent2dOnS2", (gp_Vec2d (Blend_Point::*)() const) &Blend_Point::Tangent2dOnS2, "None");
cls_Blend_Point.def("PointOnS", (const gp_Pnt & (Blend_Point::*)() const) &Blend_Point::PointOnS, "None");
cls_Blend_Point.def("PointOnC", (const gp_Pnt & (Blend_Point::*)() const) &Blend_Point::PointOnC, "None");
cls_Blend_Point.def("ParametersOnS", [](Blend_Point &self, Standard_Real & U, Standard_Real & V){ self.ParametersOnS(U, V); return std::tuple<Standard_Real &, Standard_Real &>(U, V); }, "None", py::arg("U"), py::arg("V"));
cls_Blend_Point.def("ParameterOnC", (Standard_Real (Blend_Point::*)() const) &Blend_Point::ParameterOnC, "None");
cls_Blend_Point.def("TangentOnS", (const gp_Vec & (Blend_Point::*)() const) &Blend_Point::TangentOnS, "None");
cls_Blend_Point.def("TangentOnC", (const gp_Vec & (Blend_Point::*)() const) &Blend_Point::TangentOnC, "None");
cls_Blend_Point.def("Tangent2d", (gp_Vec2d (Blend_Point::*)() const) &Blend_Point::Tangent2d, "None");
cls_Blend_Point.def("PointOnC1", (const gp_Pnt & (Blend_Point::*)() const) &Blend_Point::PointOnC1, "None");
cls_Blend_Point.def("PointOnC2", (const gp_Pnt & (Blend_Point::*)() const) &Blend_Point::PointOnC2, "None");
cls_Blend_Point.def("ParameterOnC1", (Standard_Real (Blend_Point::*)() const) &Blend_Point::ParameterOnC1, "None");
cls_Blend_Point.def("ParameterOnC2", (Standard_Real (Blend_Point::*)() const) &Blend_Point::ParameterOnC2, "None");
cls_Blend_Point.def("TangentOnC1", (const gp_Vec & (Blend_Point::*)() const) &Blend_Point::TangentOnC1, "None");
cls_Blend_Point.def("TangentOnC2", (const gp_Vec & (Blend_Point::*)() const) &Blend_Point::TangentOnC2, "None");

// Enums

}