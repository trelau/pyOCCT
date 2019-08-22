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
#include <BRepAdaptor_Curve.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>
#include <gp_Dir.hxx>
#include <LProp_Status.hxx>
#include <BRepLProp_CLProps.hxx>

void bind_BRepLProp_CLProps(py::module &mod){

py::class_<BRepLProp_CLProps> cls_BRepLProp_CLProps(mod, "BRepLProp_CLProps", "None");

// Constructors
cls_BRepLProp_CLProps.def(py::init<const BRepAdaptor_Curve &, const Standard_Integer, const Standard_Real>(), py::arg("C"), py::arg("N"), py::arg("Resolution"));
cls_BRepLProp_CLProps.def(py::init<const BRepAdaptor_Curve &, const Standard_Real, const Standard_Integer, const Standard_Real>(), py::arg("C"), py::arg("U"), py::arg("N"), py::arg("Resolution"));
cls_BRepLProp_CLProps.def(py::init<const Standard_Integer, const Standard_Real>(), py::arg("N"), py::arg("Resolution"));

// Fields

// Methods
// cls_BRepLProp_CLProps.def_static("operator new_", (void * (*)(size_t)) &BRepLProp_CLProps::operator new, "None", py::arg("theSize"));
// cls_BRepLProp_CLProps.def_static("operator delete_", (void (*)(void *)) &BRepLProp_CLProps::operator delete, "None", py::arg("theAddress"));
// cls_BRepLProp_CLProps.def_static("operator new[]_", (void * (*)(size_t)) &BRepLProp_CLProps::operator new[], "None", py::arg("theSize"));
// cls_BRepLProp_CLProps.def_static("operator delete[]_", (void (*)(void *)) &BRepLProp_CLProps::operator delete[], "None", py::arg("theAddress"));
// cls_BRepLProp_CLProps.def_static("operator new_", (void * (*)(size_t, void *)) &BRepLProp_CLProps::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepLProp_CLProps.def_static("operator delete_", (void (*)(void *, void *)) &BRepLProp_CLProps::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepLProp_CLProps.def("SetParameter", (void (BRepLProp_CLProps::*)(const Standard_Real)) &BRepLProp_CLProps::SetParameter, "Initializes the local properties of the curve for the parameter value <U>.", py::arg("U"));
cls_BRepLProp_CLProps.def("SetCurve", (void (BRepLProp_CLProps::*)(const BRepAdaptor_Curve &)) &BRepLProp_CLProps::SetCurve, "Initializes the local properties of the curve for the new curve.", py::arg("C"));
cls_BRepLProp_CLProps.def("Value", (const gp_Pnt & (BRepLProp_CLProps::*)() const) &BRepLProp_CLProps::Value, "Returns the Point.");
cls_BRepLProp_CLProps.def("D1", (const gp_Vec & (BRepLProp_CLProps::*)()) &BRepLProp_CLProps::D1, "Returns the first derivative. The derivative is computed if it has not been yet.");
cls_BRepLProp_CLProps.def("D2", (const gp_Vec & (BRepLProp_CLProps::*)()) &BRepLProp_CLProps::D2, "Returns the second derivative. The derivative is computed if it has not been yet.");
cls_BRepLProp_CLProps.def("D3", (const gp_Vec & (BRepLProp_CLProps::*)()) &BRepLProp_CLProps::D3, "Returns the third derivative. The derivative is computed if it has not been yet.");
cls_BRepLProp_CLProps.def("IsTangentDefined", (Standard_Boolean (BRepLProp_CLProps::*)()) &BRepLProp_CLProps::IsTangentDefined, "Returns True if the tangent is defined. For example, the tangent is not defined if the three first derivatives are all null.");
cls_BRepLProp_CLProps.def("Tangent", (void (BRepLProp_CLProps::*)(gp_Dir &)) &BRepLProp_CLProps::Tangent, "output the tangent direction <D>", py::arg("D"));
cls_BRepLProp_CLProps.def("Curvature", (Standard_Real (BRepLProp_CLProps::*)()) &BRepLProp_CLProps::Curvature, "Returns the curvature.");
cls_BRepLProp_CLProps.def("Normal", (void (BRepLProp_CLProps::*)(gp_Dir &)) &BRepLProp_CLProps::Normal, "Returns the normal direction <N>.", py::arg("N"));
cls_BRepLProp_CLProps.def("CentreOfCurvature", (void (BRepLProp_CLProps::*)(gp_Pnt &)) &BRepLProp_CLProps::CentreOfCurvature, "Returns the centre of curvature <P>.", py::arg("P"));

// Enums

}