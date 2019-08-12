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
#include <Adaptor3d_HSurface.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>
#include <gp_Dir.hxx>
#include <LProp_Status.hxx>
#include <LProp3d_SLProps.hxx>

void bind_LProp3d_SLProps(py::module &mod){

py::class_<LProp3d_SLProps, std::unique_ptr<LProp3d_SLProps, Deleter<LProp3d_SLProps>>> cls_LProp3d_SLProps(mod, "LProp3d_SLProps", "None");

// Constructors
cls_LProp3d_SLProps.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Real>(), py::arg("S"), py::arg("U"), py::arg("V"), py::arg("N"), py::arg("Resolution"));
cls_LProp3d_SLProps.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Integer, const Standard_Real>(), py::arg("S"), py::arg("N"), py::arg("Resolution"));
cls_LProp3d_SLProps.def(py::init<const Standard_Integer, const Standard_Real>(), py::arg("N"), py::arg("Resolution"));

// Fields

// Methods
// cls_LProp3d_SLProps.def_static("operator new_", (void * (*)(size_t)) &LProp3d_SLProps::operator new, "None", py::arg("theSize"));
// cls_LProp3d_SLProps.def_static("operator delete_", (void (*)(void *)) &LProp3d_SLProps::operator delete, "None", py::arg("theAddress"));
// cls_LProp3d_SLProps.def_static("operator new[]_", (void * (*)(size_t)) &LProp3d_SLProps::operator new[], "None", py::arg("theSize"));
// cls_LProp3d_SLProps.def_static("operator delete[]_", (void (*)(void *)) &LProp3d_SLProps::operator delete[], "None", py::arg("theAddress"));
// cls_LProp3d_SLProps.def_static("operator new_", (void * (*)(size_t, void *)) &LProp3d_SLProps::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_LProp3d_SLProps.def_static("operator delete_", (void (*)(void *, void *)) &LProp3d_SLProps::operator delete, "None", py::arg(""), py::arg(""));
cls_LProp3d_SLProps.def("SetSurface", (void (LProp3d_SLProps::*)(const opencascade::handle<Adaptor3d_HSurface> &)) &LProp3d_SLProps::SetSurface, "Initializes the local properties of the surface S for the new surface.", py::arg("S"));
cls_LProp3d_SLProps.def("SetParameters", (void (LProp3d_SLProps::*)(const Standard_Real, const Standard_Real)) &LProp3d_SLProps::SetParameters, "Initializes the local properties of the surface S for the new parameter values (<U>, <V>).", py::arg("U"), py::arg("V"));
cls_LProp3d_SLProps.def("Value", (const gp_Pnt & (LProp3d_SLProps::*)() const) &LProp3d_SLProps::Value, "Returns the point.");
cls_LProp3d_SLProps.def("D1U", (const gp_Vec & (LProp3d_SLProps::*)()) &LProp3d_SLProps::D1U, "Returns the first U derivative. The derivative is computed if it has not been yet.");
cls_LProp3d_SLProps.def("D1V", (const gp_Vec & (LProp3d_SLProps::*)()) &LProp3d_SLProps::D1V, "Returns the first V derivative. The derivative is computed if it has not been yet.");
cls_LProp3d_SLProps.def("D2U", (const gp_Vec & (LProp3d_SLProps::*)()) &LProp3d_SLProps::D2U, "Returns the second U derivatives The derivative is computed if it has not been yet.");
cls_LProp3d_SLProps.def("D2V", (const gp_Vec & (LProp3d_SLProps::*)()) &LProp3d_SLProps::D2V, "Returns the second V derivative. The derivative is computed if it has not been yet.");
cls_LProp3d_SLProps.def("DUV", (const gp_Vec & (LProp3d_SLProps::*)()) &LProp3d_SLProps::DUV, "Returns the second UV cross-derivative. The derivative is computed if it has not been yet.");
cls_LProp3d_SLProps.def("IsTangentUDefined", (Standard_Boolean (LProp3d_SLProps::*)()) &LProp3d_SLProps::IsTangentUDefined, "returns True if the U tangent is defined. For example, the tangent is not defined if the two first U derivatives are null.");
cls_LProp3d_SLProps.def("TangentU", (void (LProp3d_SLProps::*)(gp_Dir &)) &LProp3d_SLProps::TangentU, "Returns the tangent direction <D> on the iso-V.", py::arg("D"));
cls_LProp3d_SLProps.def("IsTangentVDefined", (Standard_Boolean (LProp3d_SLProps::*)()) &LProp3d_SLProps::IsTangentVDefined, "returns if the V tangent is defined. For example, the tangent is not defined if the two first V derivatives are null.");
cls_LProp3d_SLProps.def("TangentV", (void (LProp3d_SLProps::*)(gp_Dir &)) &LProp3d_SLProps::TangentV, "Returns the tangent direction <D> on the iso-V.", py::arg("D"));
cls_LProp3d_SLProps.def("IsNormalDefined", (Standard_Boolean (LProp3d_SLProps::*)()) &LProp3d_SLProps::IsNormalDefined, "Tells if the normal is defined.");
cls_LProp3d_SLProps.def("Normal", (const gp_Dir & (LProp3d_SLProps::*)()) &LProp3d_SLProps::Normal, "Returns the normal direction.");
cls_LProp3d_SLProps.def("IsCurvatureDefined", (Standard_Boolean (LProp3d_SLProps::*)()) &LProp3d_SLProps::IsCurvatureDefined, "returns True if the curvature is defined.");
cls_LProp3d_SLProps.def("IsUmbilic", (Standard_Boolean (LProp3d_SLProps::*)()) &LProp3d_SLProps::IsUmbilic, "returns True if the point is umbilic (i.e. if the curvature is constant).");
cls_LProp3d_SLProps.def("MaxCurvature", (Standard_Real (LProp3d_SLProps::*)()) &LProp3d_SLProps::MaxCurvature, "Returns the maximum curvature");
cls_LProp3d_SLProps.def("MinCurvature", (Standard_Real (LProp3d_SLProps::*)()) &LProp3d_SLProps::MinCurvature, "Returns the minimum curvature");
cls_LProp3d_SLProps.def("CurvatureDirections", (void (LProp3d_SLProps::*)(gp_Dir &, gp_Dir &)) &LProp3d_SLProps::CurvatureDirections, "Returns the direction of the maximum and minimum curvature <MaxD> and <MinD>", py::arg("MaxD"), py::arg("MinD"));
cls_LProp3d_SLProps.def("MeanCurvature", (Standard_Real (LProp3d_SLProps::*)()) &LProp3d_SLProps::MeanCurvature, "Returns the mean curvature.");
cls_LProp3d_SLProps.def("GaussianCurvature", (Standard_Real (LProp3d_SLProps::*)()) &LProp3d_SLProps::GaussianCurvature, "Returns the Gaussian curvature");

// Enums

}