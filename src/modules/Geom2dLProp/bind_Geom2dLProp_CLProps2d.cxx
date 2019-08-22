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
#include <Standard_Handle.hxx>
#include <Geom2d_Curve.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Vec2d.hxx>
#include <gp_Dir2d.hxx>
#include <LProp_Status.hxx>
#include <Geom2dLProp_CLProps2d.hxx>

void bind_Geom2dLProp_CLProps2d(py::module &mod){

py::class_<Geom2dLProp_CLProps2d> cls_Geom2dLProp_CLProps2d(mod, "Geom2dLProp_CLProps2d", "None");

// Constructors
cls_Geom2dLProp_CLProps2d.def(py::init<const opencascade::handle<Geom2d_Curve> &, const Standard_Integer, const Standard_Real>(), py::arg("C"), py::arg("N"), py::arg("Resolution"));
cls_Geom2dLProp_CLProps2d.def(py::init<const opencascade::handle<Geom2d_Curve> &, const Standard_Real, const Standard_Integer, const Standard_Real>(), py::arg("C"), py::arg("U"), py::arg("N"), py::arg("Resolution"));
cls_Geom2dLProp_CLProps2d.def(py::init<const Standard_Integer, const Standard_Real>(), py::arg("N"), py::arg("Resolution"));

// Fields

// Methods
// cls_Geom2dLProp_CLProps2d.def_static("operator new_", (void * (*)(size_t)) &Geom2dLProp_CLProps2d::operator new, "None", py::arg("theSize"));
// cls_Geom2dLProp_CLProps2d.def_static("operator delete_", (void (*)(void *)) &Geom2dLProp_CLProps2d::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dLProp_CLProps2d.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dLProp_CLProps2d::operator new[], "None", py::arg("theSize"));
// cls_Geom2dLProp_CLProps2d.def_static("operator delete[]_", (void (*)(void *)) &Geom2dLProp_CLProps2d::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dLProp_CLProps2d.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dLProp_CLProps2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dLProp_CLProps2d.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dLProp_CLProps2d::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dLProp_CLProps2d.def("SetParameter", (void (Geom2dLProp_CLProps2d::*)(const Standard_Real)) &Geom2dLProp_CLProps2d::SetParameter, "Initializes the local properties of the curve for the parameter value <U>.", py::arg("U"));
cls_Geom2dLProp_CLProps2d.def("SetCurve", (void (Geom2dLProp_CLProps2d::*)(const opencascade::handle<Geom2d_Curve> &)) &Geom2dLProp_CLProps2d::SetCurve, "Initializes the local properties of the curve for the new curve.", py::arg("C"));
cls_Geom2dLProp_CLProps2d.def("Value", (const gp_Pnt2d & (Geom2dLProp_CLProps2d::*)() const) &Geom2dLProp_CLProps2d::Value, "Returns the Point.");
cls_Geom2dLProp_CLProps2d.def("D1", (const gp_Vec2d & (Geom2dLProp_CLProps2d::*)()) &Geom2dLProp_CLProps2d::D1, "Returns the first derivative. The derivative is computed if it has not been yet.");
cls_Geom2dLProp_CLProps2d.def("D2", (const gp_Vec2d & (Geom2dLProp_CLProps2d::*)()) &Geom2dLProp_CLProps2d::D2, "Returns the second derivative. The derivative is computed if it has not been yet.");
cls_Geom2dLProp_CLProps2d.def("D3", (const gp_Vec2d & (Geom2dLProp_CLProps2d::*)()) &Geom2dLProp_CLProps2d::D3, "Returns the third derivative. The derivative is computed if it has not been yet.");
cls_Geom2dLProp_CLProps2d.def("IsTangentDefined", (Standard_Boolean (Geom2dLProp_CLProps2d::*)()) &Geom2dLProp_CLProps2d::IsTangentDefined, "Returns True if the tangent is defined. For example, the tangent is not defined if the three first derivatives are all null.");
cls_Geom2dLProp_CLProps2d.def("Tangent", (void (Geom2dLProp_CLProps2d::*)(gp_Dir2d &)) &Geom2dLProp_CLProps2d::Tangent, "output the tangent direction <D>", py::arg("D"));
cls_Geom2dLProp_CLProps2d.def("Curvature", (Standard_Real (Geom2dLProp_CLProps2d::*)()) &Geom2dLProp_CLProps2d::Curvature, "Returns the curvature.");
cls_Geom2dLProp_CLProps2d.def("Normal", (void (Geom2dLProp_CLProps2d::*)(gp_Dir2d &)) &Geom2dLProp_CLProps2d::Normal, "Returns the normal direction <N>.", py::arg("N"));
cls_Geom2dLProp_CLProps2d.def("CentreOfCurvature", (void (Geom2dLProp_CLProps2d::*)(gp_Pnt2d &)) &Geom2dLProp_CLProps2d::CentreOfCurvature, "Returns the centre of curvature <P>.", py::arg("P"));

// Enums

}