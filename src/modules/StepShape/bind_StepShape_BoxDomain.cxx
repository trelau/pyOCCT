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
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <StepGeom_CartesianPoint.hxx>
#include <Standard_TypeDef.hxx>
#include <StepShape_BoxDomain.hxx>
#include <Standard_Type.hxx>

void bind_StepShape_BoxDomain(py::module &mod){

py::class_<StepShape_BoxDomain, opencascade::handle<StepShape_BoxDomain>, Standard_Transient> cls_StepShape_BoxDomain(mod, "StepShape_BoxDomain", "None");

// Constructors
cls_StepShape_BoxDomain.def(py::init<>());

// Fields

// Methods
cls_StepShape_BoxDomain.def("Init", (void (StepShape_BoxDomain::*)(const opencascade::handle<StepGeom_CartesianPoint> &, const Standard_Real, const Standard_Real, const Standard_Real)) &StepShape_BoxDomain::Init, "None", py::arg("aCorner"), py::arg("aXlength"), py::arg("aYlength"), py::arg("aZlength"));
cls_StepShape_BoxDomain.def("SetCorner", (void (StepShape_BoxDomain::*)(const opencascade::handle<StepGeom_CartesianPoint> &)) &StepShape_BoxDomain::SetCorner, "None", py::arg("aCorner"));
cls_StepShape_BoxDomain.def("Corner", (opencascade::handle<StepGeom_CartesianPoint> (StepShape_BoxDomain::*)() const) &StepShape_BoxDomain::Corner, "None");
cls_StepShape_BoxDomain.def("SetXlength", (void (StepShape_BoxDomain::*)(const Standard_Real)) &StepShape_BoxDomain::SetXlength, "None", py::arg("aXlength"));
cls_StepShape_BoxDomain.def("Xlength", (Standard_Real (StepShape_BoxDomain::*)() const) &StepShape_BoxDomain::Xlength, "None");
cls_StepShape_BoxDomain.def("SetYlength", (void (StepShape_BoxDomain::*)(const Standard_Real)) &StepShape_BoxDomain::SetYlength, "None", py::arg("aYlength"));
cls_StepShape_BoxDomain.def("Ylength", (Standard_Real (StepShape_BoxDomain::*)() const) &StepShape_BoxDomain::Ylength, "None");
cls_StepShape_BoxDomain.def("SetZlength", (void (StepShape_BoxDomain::*)(const Standard_Real)) &StepShape_BoxDomain::SetZlength, "None", py::arg("aZlength"));
cls_StepShape_BoxDomain.def("Zlength", (Standard_Real (StepShape_BoxDomain::*)() const) &StepShape_BoxDomain::Zlength, "None");
cls_StepShape_BoxDomain.def_static("get_type_name_", (const char * (*)()) &StepShape_BoxDomain::get_type_name, "None");
cls_StepShape_BoxDomain.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_BoxDomain::get_type_descriptor, "None");
cls_StepShape_BoxDomain.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_BoxDomain::*)() const) &StepShape_BoxDomain::DynamicType, "None");

// Enums

}