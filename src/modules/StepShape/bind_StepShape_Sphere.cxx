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
#include <StepGeom_GeometricRepresentationItem.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <Standard_TypeDef.hxx>
#include <StepGeom_Point.hxx>
#include <StepShape_Sphere.hxx>
#include <Standard_Type.hxx>

void bind_StepShape_Sphere(py::module &mod){

py::class_<StepShape_Sphere, opencascade::handle<StepShape_Sphere>, StepGeom_GeometricRepresentationItem> cls_StepShape_Sphere(mod, "StepShape_Sphere", "None");

// Constructors
cls_StepShape_Sphere.def(py::init<>());

// Fields

// Methods
cls_StepShape_Sphere.def("Init", (void (StepShape_Sphere::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Real, const opencascade::handle<StepGeom_Point> &)) &StepShape_Sphere::Init, "None", py::arg("aName"), py::arg("aRadius"), py::arg("aCentre"));
cls_StepShape_Sphere.def("SetRadius", (void (StepShape_Sphere::*)(const Standard_Real)) &StepShape_Sphere::SetRadius, "None", py::arg("aRadius"));
cls_StepShape_Sphere.def("Radius", (Standard_Real (StepShape_Sphere::*)() const) &StepShape_Sphere::Radius, "None");
cls_StepShape_Sphere.def("SetCentre", (void (StepShape_Sphere::*)(const opencascade::handle<StepGeom_Point> &)) &StepShape_Sphere::SetCentre, "None", py::arg("aCentre"));
cls_StepShape_Sphere.def("Centre", (opencascade::handle<StepGeom_Point> (StepShape_Sphere::*)() const) &StepShape_Sphere::Centre, "None");
cls_StepShape_Sphere.def_static("get_type_name_", (const char * (*)()) &StepShape_Sphere::get_type_name, "None");
cls_StepShape_Sphere.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_Sphere::get_type_descriptor, "None");
cls_StepShape_Sphere.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_Sphere::*)() const) &StepShape_Sphere::DynamicType, "None");

// Enums

}