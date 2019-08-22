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
#include <Geom_Curve.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>
#include <gp_Dir.hxx>
#include <LProp_Status.hxx>
#include <GeomLProp_CLProps.hxx>

void bind_GeomLProp_CLProps(py::module &mod){

py::class_<GeomLProp_CLProps> cls_GeomLProp_CLProps(mod, "GeomLProp_CLProps", "None");

// Constructors
cls_GeomLProp_CLProps.def(py::init<const opencascade::handle<Geom_Curve> &, const Standard_Integer, const Standard_Real>(), py::arg("C"), py::arg("N"), py::arg("Resolution"));
cls_GeomLProp_CLProps.def(py::init<const opencascade::handle<Geom_Curve> &, const Standard_Real, const Standard_Integer, const Standard_Real>(), py::arg("C"), py::arg("U"), py::arg("N"), py::arg("Resolution"));
cls_GeomLProp_CLProps.def(py::init<const Standard_Integer, const Standard_Real>(), py::arg("N"), py::arg("Resolution"));

// Fields

// Methods
// cls_GeomLProp_CLProps.def_static("operator new_", (void * (*)(size_t)) &GeomLProp_CLProps::operator new, "None", py::arg("theSize"));
// cls_GeomLProp_CLProps.def_static("operator delete_", (void (*)(void *)) &GeomLProp_CLProps::operator delete, "None", py::arg("theAddress"));
// cls_GeomLProp_CLProps.def_static("operator new[]_", (void * (*)(size_t)) &GeomLProp_CLProps::operator new[], "None", py::arg("theSize"));
// cls_GeomLProp_CLProps.def_static("operator delete[]_", (void (*)(void *)) &GeomLProp_CLProps::operator delete[], "None", py::arg("theAddress"));
// cls_GeomLProp_CLProps.def_static("operator new_", (void * (*)(size_t, void *)) &GeomLProp_CLProps::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomLProp_CLProps.def_static("operator delete_", (void (*)(void *, void *)) &GeomLProp_CLProps::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomLProp_CLProps.def("SetParameter", (void (GeomLProp_CLProps::*)(const Standard_Real)) &GeomLProp_CLProps::SetParameter, "Initializes the local properties of the curve for the parameter value <U>.", py::arg("U"));
cls_GeomLProp_CLProps.def("SetCurve", (void (GeomLProp_CLProps::*)(const opencascade::handle<Geom_Curve> &)) &GeomLProp_CLProps::SetCurve, "Initializes the local properties of the curve for the new curve.", py::arg("C"));
cls_GeomLProp_CLProps.def("Value", (const gp_Pnt & (GeomLProp_CLProps::*)() const) &GeomLProp_CLProps::Value, "Returns the Point.");
cls_GeomLProp_CLProps.def("D1", (const gp_Vec & (GeomLProp_CLProps::*)()) &GeomLProp_CLProps::D1, "Returns the first derivative. The derivative is computed if it has not been yet.");
cls_GeomLProp_CLProps.def("D2", (const gp_Vec & (GeomLProp_CLProps::*)()) &GeomLProp_CLProps::D2, "Returns the second derivative. The derivative is computed if it has not been yet.");
cls_GeomLProp_CLProps.def("D3", (const gp_Vec & (GeomLProp_CLProps::*)()) &GeomLProp_CLProps::D3, "Returns the third derivative. The derivative is computed if it has not been yet.");
cls_GeomLProp_CLProps.def("IsTangentDefined", (Standard_Boolean (GeomLProp_CLProps::*)()) &GeomLProp_CLProps::IsTangentDefined, "Returns True if the tangent is defined. For example, the tangent is not defined if the three first derivatives are all null.");
cls_GeomLProp_CLProps.def("Tangent", (void (GeomLProp_CLProps::*)(gp_Dir &)) &GeomLProp_CLProps::Tangent, "output the tangent direction <D>", py::arg("D"));
cls_GeomLProp_CLProps.def("Curvature", (Standard_Real (GeomLProp_CLProps::*)()) &GeomLProp_CLProps::Curvature, "Returns the curvature.");
cls_GeomLProp_CLProps.def("Normal", (void (GeomLProp_CLProps::*)(gp_Dir &)) &GeomLProp_CLProps::Normal, "Returns the normal direction <N>.", py::arg("N"));
cls_GeomLProp_CLProps.def("CentreOfCurvature", (void (GeomLProp_CLProps::*)(gp_Pnt &)) &GeomLProp_CLProps::CentreOfCurvature, "Returns the centre of curvature <P>.", py::arg("P"));

// Enums

}