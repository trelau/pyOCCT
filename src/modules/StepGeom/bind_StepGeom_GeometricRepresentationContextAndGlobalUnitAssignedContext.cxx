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
#include <StepRepr_GlobalUnitAssignedContext.hxx>
#include <Standard_TypeDef.hxx>
#include <StepBasic_HArray1OfNamedUnit.hxx>
#include <StepBasic_NamedUnit.hxx>
#include <StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext.hxx>
#include <Standard_Type.hxx>

void bind_StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext(py::module &mod){

py::class_<StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext, opencascade::handle<StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext>, StepRepr_RepresentationContext> cls_StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext(mod, "StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext", "None");

// Constructors
cls_StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext.def(py::init<>());

// Fields

// Methods
cls_StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext.def("Init", (void (StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepGeom_GeometricRepresentationContext> &, const opencascade::handle<StepRepr_GlobalUnitAssignedContext> &)) &StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext::Init, "None", py::arg("aContextIdentifier"), py::arg("aContextType"), py::arg("aGeometricRepresentationContext"), py::arg("aGlobalUnitAssignedContext"));
cls_StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext.def("Init", (void (StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Integer, const opencascade::handle<StepBasic_HArray1OfNamedUnit> &)) &StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext::Init, "None", py::arg("aContextIdentifier"), py::arg("aContextType"), py::arg("aCoordinateSpaceDimension"), py::arg("aUnits"));
cls_StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext.def("SetGeometricRepresentationContext", (void (StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext::*)(const opencascade::handle<StepGeom_GeometricRepresentationContext> &)) &StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext::SetGeometricRepresentationContext, "None", py::arg("aGeometricRepresentationContext"));
cls_StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext.def("GeometricRepresentationContext", (opencascade::handle<StepGeom_GeometricRepresentationContext> (StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext::*)() const) &StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext::GeometricRepresentationContext, "None");
cls_StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext.def("SetGlobalUnitAssignedContext", (void (StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext::*)(const opencascade::handle<StepRepr_GlobalUnitAssignedContext> &)) &StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext::SetGlobalUnitAssignedContext, "None", py::arg("aGlobalUnitAssignedContext"));
cls_StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext.def("GlobalUnitAssignedContext", (opencascade::handle<StepRepr_GlobalUnitAssignedContext> (StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext::*)() const) &StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext::GlobalUnitAssignedContext, "None");
cls_StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext.def("SetCoordinateSpaceDimension", (void (StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext::*)(const Standard_Integer)) &StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext::SetCoordinateSpaceDimension, "None", py::arg("aCoordinateSpaceDimension"));
cls_StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext.def("CoordinateSpaceDimension", (Standard_Integer (StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext::*)() const) &StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext::CoordinateSpaceDimension, "None");
cls_StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext.def("SetUnits", (void (StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext::*)(const opencascade::handle<StepBasic_HArray1OfNamedUnit> &)) &StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext::SetUnits, "None", py::arg("aUnits"));
cls_StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext.def("Units", (opencascade::handle<StepBasic_HArray1OfNamedUnit> (StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext::*)() const) &StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext::Units, "None");
cls_StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext.def("UnitsValue", (opencascade::handle<StepBasic_NamedUnit> (StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext::*)(const Standard_Integer) const) &StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext::UnitsValue, "None", py::arg("num"));
cls_StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext.def("NbUnits", (Standard_Integer (StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext::*)() const) &StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext::NbUnits, "None");
cls_StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext.def_static("get_type_name_", (const char * (*)()) &StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext::get_type_name, "None");
cls_StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext::get_type_descriptor, "None");
cls_StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext::*)() const) &StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext::DynamicType, "None");

// Enums

}