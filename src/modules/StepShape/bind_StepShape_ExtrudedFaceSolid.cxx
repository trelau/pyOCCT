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
#include <StepShape_SweptFaceSolid.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepShape_FaceSurface.hxx>
#include <StepGeom_Direction.hxx>
#include <Standard_TypeDef.hxx>
#include <StepShape_ExtrudedFaceSolid.hxx>
#include <Standard_Type.hxx>

void bind_StepShape_ExtrudedFaceSolid(py::module &mod){

py::class_<StepShape_ExtrudedFaceSolid, opencascade::handle<StepShape_ExtrudedFaceSolid>, StepShape_SweptFaceSolid> cls_StepShape_ExtrudedFaceSolid(mod, "StepShape_ExtrudedFaceSolid", "None");

// Constructors
cls_StepShape_ExtrudedFaceSolid.def(py::init<>());

// Fields

// Methods
cls_StepShape_ExtrudedFaceSolid.def("Init", (void (StepShape_ExtrudedFaceSolid::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepShape_FaceSurface> &, const opencascade::handle<StepGeom_Direction> &, const Standard_Real)) &StepShape_ExtrudedFaceSolid::Init, "None", py::arg("aName"), py::arg("aSweptArea"), py::arg("aExtrudedDirection"), py::arg("aDepth"));
cls_StepShape_ExtrudedFaceSolid.def("SetExtrudedDirection", (void (StepShape_ExtrudedFaceSolid::*)(const opencascade::handle<StepGeom_Direction> &)) &StepShape_ExtrudedFaceSolid::SetExtrudedDirection, "None", py::arg("aExtrudedDirection"));
cls_StepShape_ExtrudedFaceSolid.def("ExtrudedDirection", (opencascade::handle<StepGeom_Direction> (StepShape_ExtrudedFaceSolid::*)() const) &StepShape_ExtrudedFaceSolid::ExtrudedDirection, "None");
cls_StepShape_ExtrudedFaceSolid.def("SetDepth", (void (StepShape_ExtrudedFaceSolid::*)(const Standard_Real)) &StepShape_ExtrudedFaceSolid::SetDepth, "None", py::arg("aDepth"));
cls_StepShape_ExtrudedFaceSolid.def("Depth", (Standard_Real (StepShape_ExtrudedFaceSolid::*)() const) &StepShape_ExtrudedFaceSolid::Depth, "None");
cls_StepShape_ExtrudedFaceSolid.def_static("get_type_name_", (const char * (*)()) &StepShape_ExtrudedFaceSolid::get_type_name, "None");
cls_StepShape_ExtrudedFaceSolid.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_ExtrudedFaceSolid::get_type_descriptor, "None");
cls_StepShape_ExtrudedFaceSolid.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_ExtrudedFaceSolid::*)() const) &StepShape_ExtrudedFaceSolid::DynamicType, "None");

// Enums

}