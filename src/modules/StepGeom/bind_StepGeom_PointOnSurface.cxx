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
#include <StepGeom_Point.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepGeom_Surface.hxx>
#include <Standard_TypeDef.hxx>
#include <StepGeom_PointOnSurface.hxx>
#include <Standard_Type.hxx>

void bind_StepGeom_PointOnSurface(py::module &mod){

py::class_<StepGeom_PointOnSurface, opencascade::handle<StepGeom_PointOnSurface>, StepGeom_Point> cls_StepGeom_PointOnSurface(mod, "StepGeom_PointOnSurface", "None");

// Constructors
cls_StepGeom_PointOnSurface.def(py::init<>());

// Fields

// Methods
cls_StepGeom_PointOnSurface.def("Init", (void (StepGeom_PointOnSurface::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepGeom_Surface> &, const Standard_Real, const Standard_Real)) &StepGeom_PointOnSurface::Init, "None", py::arg("aName"), py::arg("aBasisSurface"), py::arg("aPointParameterU"), py::arg("aPointParameterV"));
cls_StepGeom_PointOnSurface.def("SetBasisSurface", (void (StepGeom_PointOnSurface::*)(const opencascade::handle<StepGeom_Surface> &)) &StepGeom_PointOnSurface::SetBasisSurface, "None", py::arg("aBasisSurface"));
cls_StepGeom_PointOnSurface.def("BasisSurface", (opencascade::handle<StepGeom_Surface> (StepGeom_PointOnSurface::*)() const) &StepGeom_PointOnSurface::BasisSurface, "None");
cls_StepGeom_PointOnSurface.def("SetPointParameterU", (void (StepGeom_PointOnSurface::*)(const Standard_Real)) &StepGeom_PointOnSurface::SetPointParameterU, "None", py::arg("aPointParameterU"));
cls_StepGeom_PointOnSurface.def("PointParameterU", (Standard_Real (StepGeom_PointOnSurface::*)() const) &StepGeom_PointOnSurface::PointParameterU, "None");
cls_StepGeom_PointOnSurface.def("SetPointParameterV", (void (StepGeom_PointOnSurface::*)(const Standard_Real)) &StepGeom_PointOnSurface::SetPointParameterV, "None", py::arg("aPointParameterV"));
cls_StepGeom_PointOnSurface.def("PointParameterV", (Standard_Real (StepGeom_PointOnSurface::*)() const) &StepGeom_PointOnSurface::PointParameterV, "None");
cls_StepGeom_PointOnSurface.def_static("get_type_name_", (const char * (*)()) &StepGeom_PointOnSurface::get_type_name, "None");
cls_StepGeom_PointOnSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_PointOnSurface::get_type_descriptor, "None");
cls_StepGeom_PointOnSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_PointOnSurface::*)() const) &StepGeom_PointOnSurface::DynamicType, "None");

// Enums

}