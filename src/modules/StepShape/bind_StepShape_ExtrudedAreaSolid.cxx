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
#include <StepShape_SweptAreaSolid.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepGeom_CurveBoundedSurface.hxx>
#include <StepGeom_Direction.hxx>
#include <Standard_TypeDef.hxx>
#include <StepShape_ExtrudedAreaSolid.hxx>
#include <Standard_Type.hxx>

void bind_StepShape_ExtrudedAreaSolid(py::module &mod){

py::class_<StepShape_ExtrudedAreaSolid, opencascade::handle<StepShape_ExtrudedAreaSolid>, StepShape_SweptAreaSolid> cls_StepShape_ExtrudedAreaSolid(mod, "StepShape_ExtrudedAreaSolid", "None");

// Constructors
cls_StepShape_ExtrudedAreaSolid.def(py::init<>());

// Fields

// Methods
cls_StepShape_ExtrudedAreaSolid.def("Init", (void (StepShape_ExtrudedAreaSolid::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepGeom_CurveBoundedSurface> &, const opencascade::handle<StepGeom_Direction> &, const Standard_Real)) &StepShape_ExtrudedAreaSolid::Init, "None", py::arg("aName"), py::arg("aSweptArea"), py::arg("aExtrudedDirection"), py::arg("aDepth"));
cls_StepShape_ExtrudedAreaSolid.def("SetExtrudedDirection", (void (StepShape_ExtrudedAreaSolid::*)(const opencascade::handle<StepGeom_Direction> &)) &StepShape_ExtrudedAreaSolid::SetExtrudedDirection, "None", py::arg("aExtrudedDirection"));
cls_StepShape_ExtrudedAreaSolid.def("ExtrudedDirection", (opencascade::handle<StepGeom_Direction> (StepShape_ExtrudedAreaSolid::*)() const) &StepShape_ExtrudedAreaSolid::ExtrudedDirection, "None");
cls_StepShape_ExtrudedAreaSolid.def("SetDepth", (void (StepShape_ExtrudedAreaSolid::*)(const Standard_Real)) &StepShape_ExtrudedAreaSolid::SetDepth, "None", py::arg("aDepth"));
cls_StepShape_ExtrudedAreaSolid.def("Depth", (Standard_Real (StepShape_ExtrudedAreaSolid::*)() const) &StepShape_ExtrudedAreaSolid::Depth, "None");
cls_StepShape_ExtrudedAreaSolid.def_static("get_type_name_", (const char * (*)()) &StepShape_ExtrudedAreaSolid::get_type_name, "None");
cls_StepShape_ExtrudedAreaSolid.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_ExtrudedAreaSolid::get_type_descriptor, "None");
cls_StepShape_ExtrudedAreaSolid.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_ExtrudedAreaSolid::*)() const) &StepShape_ExtrudedAreaSolid::DynamicType, "None");

// Enums

}