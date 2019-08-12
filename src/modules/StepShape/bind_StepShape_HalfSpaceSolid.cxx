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
#include <StepGeom_Surface.hxx>
#include <Standard_TypeDef.hxx>
#include <StepShape_HalfSpaceSolid.hxx>
#include <Standard_Type.hxx>

void bind_StepShape_HalfSpaceSolid(py::module &mod){

py::class_<StepShape_HalfSpaceSolid, opencascade::handle<StepShape_HalfSpaceSolid>, StepGeom_GeometricRepresentationItem> cls_StepShape_HalfSpaceSolid(mod, "StepShape_HalfSpaceSolid", "None");

// Constructors
cls_StepShape_HalfSpaceSolid.def(py::init<>());

// Fields

// Methods
cls_StepShape_HalfSpaceSolid.def("Init", (void (StepShape_HalfSpaceSolid::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepGeom_Surface> &, const Standard_Boolean)) &StepShape_HalfSpaceSolid::Init, "None", py::arg("aName"), py::arg("aBaseSurface"), py::arg("aAgreementFlag"));
cls_StepShape_HalfSpaceSolid.def("SetBaseSurface", (void (StepShape_HalfSpaceSolid::*)(const opencascade::handle<StepGeom_Surface> &)) &StepShape_HalfSpaceSolid::SetBaseSurface, "None", py::arg("aBaseSurface"));
cls_StepShape_HalfSpaceSolid.def("BaseSurface", (opencascade::handle<StepGeom_Surface> (StepShape_HalfSpaceSolid::*)() const) &StepShape_HalfSpaceSolid::BaseSurface, "None");
cls_StepShape_HalfSpaceSolid.def("SetAgreementFlag", (void (StepShape_HalfSpaceSolid::*)(const Standard_Boolean)) &StepShape_HalfSpaceSolid::SetAgreementFlag, "None", py::arg("aAgreementFlag"));
cls_StepShape_HalfSpaceSolid.def("AgreementFlag", (Standard_Boolean (StepShape_HalfSpaceSolid::*)() const) &StepShape_HalfSpaceSolid::AgreementFlag, "None");
cls_StepShape_HalfSpaceSolid.def_static("get_type_name_", (const char * (*)()) &StepShape_HalfSpaceSolid::get_type_name, "None");
cls_StepShape_HalfSpaceSolid.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_HalfSpaceSolid::get_type_descriptor, "None");
cls_StepShape_HalfSpaceSolid.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_HalfSpaceSolid::*)() const) &StepShape_HalfSpaceSolid::DynamicType, "None");

// Enums

}