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
#include <Geom_Surface.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>
#include <gp_Dir.hxx>
#include <LProp_Status.hxx>
#include <GeomLProp_SLProps.hxx>

void bind_GeomLProp_SLProps(py::module &mod){

py::class_<GeomLProp_SLProps> cls_GeomLProp_SLProps(mod, "GeomLProp_SLProps", "None");

// Constructors
cls_GeomLProp_SLProps.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Real>(), py::arg("S"), py::arg("U"), py::arg("V"), py::arg("N"), py::arg("Resolution"));
cls_GeomLProp_SLProps.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Integer, const Standard_Real>(), py::arg("S"), py::arg("N"), py::arg("Resolution"));
cls_GeomLProp_SLProps.def(py::init<const Standard_Integer, const Standard_Real>(), py::arg("N"), py::arg("Resolution"));

// Fields

// Methods
// cls_GeomLProp_SLProps.def_static("operator new_", (void * (*)(size_t)) &GeomLProp_SLProps::operator new, "None", py::arg("theSize"));
// cls_GeomLProp_SLProps.def_static("operator delete_", (void (*)(void *)) &GeomLProp_SLProps::operator delete, "None", py::arg("theAddress"));
// cls_GeomLProp_SLProps.def_static("operator new[]_", (void * (*)(size_t)) &GeomLProp_SLProps::operator new[], "None", py::arg("theSize"));
// cls_GeomLProp_SLProps.def_static("operator delete[]_", (void (*)(void *)) &GeomLProp_SLProps::operator delete[], "None", py::arg("theAddress"));
// cls_GeomLProp_SLProps.def_static("operator new_", (void * (*)(size_t, void *)) &GeomLProp_SLProps::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomLProp_SLProps.def_static("operator delete_", (void (*)(void *, void *)) &GeomLProp_SLProps::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomLProp_SLProps.def("SetSurface", (void (GeomLProp_SLProps::*)(const opencascade::handle<Geom_Surface> &)) &GeomLProp_SLProps::SetSurface, "Initializes the local properties of the surface S for the new surface.", py::arg("S"));
cls_GeomLProp_SLProps.def("SetParameters", (void (GeomLProp_SLProps::*)(const Standard_Real, const Standard_Real)) &GeomLProp_SLProps::SetParameters, "Initializes the local properties of the surface S for the new parameter values (<U>, <V>).", py::arg("U"), py::arg("V"));
cls_GeomLProp_SLProps.def("Value", (const gp_Pnt & (GeomLProp_SLProps::*)() const) &GeomLProp_SLProps::Value, "Returns the point.");
cls_GeomLProp_SLProps.def("D1U", (const gp_Vec & (GeomLProp_SLProps::*)()) &GeomLProp_SLProps::D1U, "Returns the first U derivative. The derivative is computed if it has not been yet.");
cls_GeomLProp_SLProps.def("D1V", (const gp_Vec & (GeomLProp_SLProps::*)()) &GeomLProp_SLProps::D1V, "Returns the first V derivative. The derivative is computed if it has not been yet.");
cls_GeomLProp_SLProps.def("D2U", (const gp_Vec & (GeomLProp_SLProps::*)()) &GeomLProp_SLProps::D2U, "Returns the second U derivatives The derivative is computed if it has not been yet.");
cls_GeomLProp_SLProps.def("D2V", (const gp_Vec & (GeomLProp_SLProps::*)()) &GeomLProp_SLProps::D2V, "Returns the second V derivative. The derivative is computed if it has not been yet.");
cls_GeomLProp_SLProps.def("DUV", (const gp_Vec & (GeomLProp_SLProps::*)()) &GeomLProp_SLProps::DUV, "Returns the second UV cross-derivative. The derivative is computed if it has not been yet.");
cls_GeomLProp_SLProps.def("IsTangentUDefined", (Standard_Boolean (GeomLProp_SLProps::*)()) &GeomLProp_SLProps::IsTangentUDefined, "returns True if the U tangent is defined. For example, the tangent is not defined if the two first U derivatives are null.");
cls_GeomLProp_SLProps.def("TangentU", (void (GeomLProp_SLProps::*)(gp_Dir &)) &GeomLProp_SLProps::TangentU, "Returns the tangent direction <D> on the iso-V.", py::arg("D"));
cls_GeomLProp_SLProps.def("IsTangentVDefined", (Standard_Boolean (GeomLProp_SLProps::*)()) &GeomLProp_SLProps::IsTangentVDefined, "returns if the V tangent is defined. For example, the tangent is not defined if the two first V derivatives are null.");
cls_GeomLProp_SLProps.def("TangentV", (void (GeomLProp_SLProps::*)(gp_Dir &)) &GeomLProp_SLProps::TangentV, "Returns the tangent direction <D> on the iso-V.", py::arg("D"));
cls_GeomLProp_SLProps.def("IsNormalDefined", (Standard_Boolean (GeomLProp_SLProps::*)()) &GeomLProp_SLProps::IsNormalDefined, "Tells if the normal is defined.");
cls_GeomLProp_SLProps.def("Normal", (const gp_Dir & (GeomLProp_SLProps::*)()) &GeomLProp_SLProps::Normal, "Returns the normal direction.");
cls_GeomLProp_SLProps.def("IsCurvatureDefined", (Standard_Boolean (GeomLProp_SLProps::*)()) &GeomLProp_SLProps::IsCurvatureDefined, "returns True if the curvature is defined.");
cls_GeomLProp_SLProps.def("IsUmbilic", (Standard_Boolean (GeomLProp_SLProps::*)()) &GeomLProp_SLProps::IsUmbilic, "returns True if the point is umbilic (i.e. if the curvature is constant).");
cls_GeomLProp_SLProps.def("MaxCurvature", (Standard_Real (GeomLProp_SLProps::*)()) &GeomLProp_SLProps::MaxCurvature, "Returns the maximum curvature");
cls_GeomLProp_SLProps.def("MinCurvature", (Standard_Real (GeomLProp_SLProps::*)()) &GeomLProp_SLProps::MinCurvature, "Returns the minimum curvature");
cls_GeomLProp_SLProps.def("CurvatureDirections", (void (GeomLProp_SLProps::*)(gp_Dir &, gp_Dir &)) &GeomLProp_SLProps::CurvatureDirections, "Returns the direction of the maximum and minimum curvature <MaxD> and <MinD>", py::arg("MaxD"), py::arg("MinD"));
cls_GeomLProp_SLProps.def("MeanCurvature", (Standard_Real (GeomLProp_SLProps::*)()) &GeomLProp_SLProps::MeanCurvature, "Returns the mean curvature.");
cls_GeomLProp_SLProps.def("GaussianCurvature", (Standard_Real (GeomLProp_SLProps::*)()) &GeomLProp_SLProps::GaussianCurvature, "Returns the Gaussian curvature");

// Enums

}