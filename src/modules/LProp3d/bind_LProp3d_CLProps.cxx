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
#include <Adaptor3d_HCurve.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>
#include <gp_Dir.hxx>
#include <LProp_Status.hxx>
#include <LProp3d_CLProps.hxx>

void bind_LProp3d_CLProps(py::module &mod){

py::class_<LProp3d_CLProps, std::unique_ptr<LProp3d_CLProps>> cls_LProp3d_CLProps(mod, "LProp3d_CLProps", "None");

// Constructors
cls_LProp3d_CLProps.def(py::init<const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Integer, const Standard_Real>(), py::arg("C"), py::arg("N"), py::arg("Resolution"));
cls_LProp3d_CLProps.def(py::init<const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Real, const Standard_Integer, const Standard_Real>(), py::arg("C"), py::arg("U"), py::arg("N"), py::arg("Resolution"));
cls_LProp3d_CLProps.def(py::init<const Standard_Integer, const Standard_Real>(), py::arg("N"), py::arg("Resolution"));

// Fields

// Methods
// cls_LProp3d_CLProps.def_static("operator new_", (void * (*)(size_t)) &LProp3d_CLProps::operator new, "None", py::arg("theSize"));
// cls_LProp3d_CLProps.def_static("operator delete_", (void (*)(void *)) &LProp3d_CLProps::operator delete, "None", py::arg("theAddress"));
// cls_LProp3d_CLProps.def_static("operator new[]_", (void * (*)(size_t)) &LProp3d_CLProps::operator new[], "None", py::arg("theSize"));
// cls_LProp3d_CLProps.def_static("operator delete[]_", (void (*)(void *)) &LProp3d_CLProps::operator delete[], "None", py::arg("theAddress"));
// cls_LProp3d_CLProps.def_static("operator new_", (void * (*)(size_t, void *)) &LProp3d_CLProps::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_LProp3d_CLProps.def_static("operator delete_", (void (*)(void *, void *)) &LProp3d_CLProps::operator delete, "None", py::arg(""), py::arg(""));
cls_LProp3d_CLProps.def("SetParameter", (void (LProp3d_CLProps::*)(const Standard_Real)) &LProp3d_CLProps::SetParameter, "Initializes the local properties of the curve for the parameter value <U>.", py::arg("U"));
cls_LProp3d_CLProps.def("SetCurve", (void (LProp3d_CLProps::*)(const opencascade::handle<Adaptor3d_HCurve> &)) &LProp3d_CLProps::SetCurve, "Initializes the local properties of the curve for the new curve.", py::arg("C"));
cls_LProp3d_CLProps.def("Value", (const gp_Pnt & (LProp3d_CLProps::*)() const) &LProp3d_CLProps::Value, "Returns the Point.");
cls_LProp3d_CLProps.def("D1", (const gp_Vec & (LProp3d_CLProps::*)()) &LProp3d_CLProps::D1, "Returns the first derivative. The derivative is computed if it has not been yet.");
cls_LProp3d_CLProps.def("D2", (const gp_Vec & (LProp3d_CLProps::*)()) &LProp3d_CLProps::D2, "Returns the second derivative. The derivative is computed if it has not been yet.");
cls_LProp3d_CLProps.def("D3", (const gp_Vec & (LProp3d_CLProps::*)()) &LProp3d_CLProps::D3, "Returns the third derivative. The derivative is computed if it has not been yet.");
cls_LProp3d_CLProps.def("IsTangentDefined", (Standard_Boolean (LProp3d_CLProps::*)()) &LProp3d_CLProps::IsTangentDefined, "Returns True if the tangent is defined. For example, the tangent is not defined if the three first derivatives are all null.");
cls_LProp3d_CLProps.def("Tangent", (void (LProp3d_CLProps::*)(gp_Dir &)) &LProp3d_CLProps::Tangent, "output the tangent direction <D>", py::arg("D"));
cls_LProp3d_CLProps.def("Curvature", (Standard_Real (LProp3d_CLProps::*)()) &LProp3d_CLProps::Curvature, "Returns the curvature.");
cls_LProp3d_CLProps.def("Normal", (void (LProp3d_CLProps::*)(gp_Dir &)) &LProp3d_CLProps::Normal, "Returns the normal direction <N>.", py::arg("N"));
cls_LProp3d_CLProps.def("CentreOfCurvature", (void (LProp3d_CLProps::*)(gp_Pnt &)) &LProp3d_CLProps::CentreOfCurvature, "Returns the centre of curvature <P>.", py::arg("P"));

// Enums

}