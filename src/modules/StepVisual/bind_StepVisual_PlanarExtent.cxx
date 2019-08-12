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
#include <StepVisual_PlanarExtent.hxx>
#include <Standard_Type.hxx>

void bind_StepVisual_PlanarExtent(py::module &mod){

py::class_<StepVisual_PlanarExtent, opencascade::handle<StepVisual_PlanarExtent>, StepGeom_GeometricRepresentationItem> cls_StepVisual_PlanarExtent(mod, "StepVisual_PlanarExtent", "None");

// Constructors
cls_StepVisual_PlanarExtent.def(py::init<>());

// Fields

// Methods
cls_StepVisual_PlanarExtent.def("Init", (void (StepVisual_PlanarExtent::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Real, const Standard_Real)) &StepVisual_PlanarExtent::Init, "None", py::arg("aName"), py::arg("aSizeInX"), py::arg("aSizeInY"));
cls_StepVisual_PlanarExtent.def("SetSizeInX", (void (StepVisual_PlanarExtent::*)(const Standard_Real)) &StepVisual_PlanarExtent::SetSizeInX, "None", py::arg("aSizeInX"));
cls_StepVisual_PlanarExtent.def("SizeInX", (Standard_Real (StepVisual_PlanarExtent::*)() const) &StepVisual_PlanarExtent::SizeInX, "None");
cls_StepVisual_PlanarExtent.def("SetSizeInY", (void (StepVisual_PlanarExtent::*)(const Standard_Real)) &StepVisual_PlanarExtent::SetSizeInY, "None", py::arg("aSizeInY"));
cls_StepVisual_PlanarExtent.def("SizeInY", (Standard_Real (StepVisual_PlanarExtent::*)() const) &StepVisual_PlanarExtent::SizeInY, "None");
cls_StepVisual_PlanarExtent.def_static("get_type_name_", (const char * (*)()) &StepVisual_PlanarExtent::get_type_name, "None");
cls_StepVisual_PlanarExtent.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_PlanarExtent::get_type_descriptor, "None");
cls_StepVisual_PlanarExtent.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_PlanarExtent::*)() const) &StepVisual_PlanarExtent::DynamicType, "None");

// Enums

}