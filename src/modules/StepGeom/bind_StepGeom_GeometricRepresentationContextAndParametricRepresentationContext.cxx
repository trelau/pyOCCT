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
#include <StepRepr_RepresentationContext.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepGeom_GeometricRepresentationContext.hxx>
#include <StepRepr_ParametricRepresentationContext.hxx>
#include <Standard_TypeDef.hxx>
#include <StepGeom_GeometricRepresentationContextAndParametricRepresentationContext.hxx>
#include <Standard_Type.hxx>

void bind_StepGeom_GeometricRepresentationContextAndParametricRepresentationContext(py::module &mod){

py::class_<StepGeom_GeometricRepresentationContextAndParametricRepresentationContext, opencascade::handle<StepGeom_GeometricRepresentationContextAndParametricRepresentationContext>, StepRepr_RepresentationContext> cls_StepGeom_GeometricRepresentationContextAndParametricRepresentationContext(mod, "StepGeom_GeometricRepresentationContextAndParametricRepresentationContext", "None");

// Constructors
cls_StepGeom_GeometricRepresentationContextAndParametricRepresentationContext.def(py::init<>());

// Fields

// Methods
cls_StepGeom_GeometricRepresentationContextAndParametricRepresentationContext.def("Init", (void (StepGeom_GeometricRepresentationContextAndParametricRepresentationContext::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepGeom_GeometricRepresentationContext> &, const opencascade::handle<StepRepr_ParametricRepresentationContext> &)) &StepGeom_GeometricRepresentationContextAndParametricRepresentationContext::Init, "None", py::arg("aContextIdentifier"), py::arg("aContextType"), py::arg("aGeometricRepresentationContext"), py::arg("aParametricRepresentationContext"));
cls_StepGeom_GeometricRepresentationContextAndParametricRepresentationContext.def("Init", (void (StepGeom_GeometricRepresentationContextAndParametricRepresentationContext::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Integer)) &StepGeom_GeometricRepresentationContextAndParametricRepresentationContext::Init, "None", py::arg("aContextIdentifier"), py::arg("aContextType"), py::arg("aCoordinateSpaceDimension"));
cls_StepGeom_GeometricRepresentationContextAndParametricRepresentationContext.def("SetGeometricRepresentationContext", (void (StepGeom_GeometricRepresentationContextAndParametricRepresentationContext::*)(const opencascade::handle<StepGeom_GeometricRepresentationContext> &)) &StepGeom_GeometricRepresentationContextAndParametricRepresentationContext::SetGeometricRepresentationContext, "None", py::arg("aGeometricRepresentationContext"));
cls_StepGeom_GeometricRepresentationContextAndParametricRepresentationContext.def("GeometricRepresentationContext", (opencascade::handle<StepGeom_GeometricRepresentationContext> (StepGeom_GeometricRepresentationContextAndParametricRepresentationContext::*)() const) &StepGeom_GeometricRepresentationContextAndParametricRepresentationContext::GeometricRepresentationContext, "None");
cls_StepGeom_GeometricRepresentationContextAndParametricRepresentationContext.def("SetParametricRepresentationContext", (void (StepGeom_GeometricRepresentationContextAndParametricRepresentationContext::*)(const opencascade::handle<StepRepr_ParametricRepresentationContext> &)) &StepGeom_GeometricRepresentationContextAndParametricRepresentationContext::SetParametricRepresentationContext, "None", py::arg("aParametricRepresentationContext"));
cls_StepGeom_GeometricRepresentationContextAndParametricRepresentationContext.def("ParametricRepresentationContext", (opencascade::handle<StepRepr_ParametricRepresentationContext> (StepGeom_GeometricRepresentationContextAndParametricRepresentationContext::*)() const) &StepGeom_GeometricRepresentationContextAndParametricRepresentationContext::ParametricRepresentationContext, "None");
cls_StepGeom_GeometricRepresentationContextAndParametricRepresentationContext.def("SetCoordinateSpaceDimension", (void (StepGeom_GeometricRepresentationContextAndParametricRepresentationContext::*)(const Standard_Integer)) &StepGeom_GeometricRepresentationContextAndParametricRepresentationContext::SetCoordinateSpaceDimension, "None", py::arg("aCoordinateSpaceDimension"));
cls_StepGeom_GeometricRepresentationContextAndParametricRepresentationContext.def("CoordinateSpaceDimension", (Standard_Integer (StepGeom_GeometricRepresentationContextAndParametricRepresentationContext::*)() const) &StepGeom_GeometricRepresentationContextAndParametricRepresentationContext::CoordinateSpaceDimension, "None");
cls_StepGeom_GeometricRepresentationContextAndParametricRepresentationContext.def_static("get_type_name_", (const char * (*)()) &StepGeom_GeometricRepresentationContextAndParametricRepresentationContext::get_type_name, "None");
cls_StepGeom_GeometricRepresentationContextAndParametricRepresentationContext.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_GeometricRepresentationContextAndParametricRepresentationContext::get_type_descriptor, "None");
cls_StepGeom_GeometricRepresentationContextAndParametricRepresentationContext.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_GeometricRepresentationContextAndParametricRepresentationContext::*)() const) &StepGeom_GeometricRepresentationContextAndParametricRepresentationContext::DynamicType, "None");

// Enums

}