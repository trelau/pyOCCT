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
#include <StepRepr_GlobalUncertaintyAssignedContext.hxx>
#include <Standard_TypeDef.hxx>
#include <StepBasic_HArray1OfNamedUnit.hxx>
#include <StepBasic_HArray1OfUncertaintyMeasureWithUnit.hxx>
#include <StepBasic_NamedUnit.hxx>
#include <StepBasic_UncertaintyMeasureWithUnit.hxx>
#include <StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx.hxx>
#include <Standard_Type.hxx>

void bind_StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx(py::module &mod){

py::class_<StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx, opencascade::handle<StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx>, StepRepr_RepresentationContext> cls_StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx(mod, "StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx", "None");

// Constructors
cls_StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx.def(py::init<>());

// Fields

// Methods
cls_StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx.def("Init", (void (StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepGeom_GeometricRepresentationContext> &, const opencascade::handle<StepRepr_GlobalUnitAssignedContext> &, const opencascade::handle<StepRepr_GlobalUncertaintyAssignedContext> &)) &StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx::Init, "None", py::arg("aContextIdentifier"), py::arg("aContextType"), py::arg("aGeometricRepresentationCtx"), py::arg("aGlobalUnitAssignedCtx"), py::arg("aGlobalUncertaintyAssignedCtx"));
cls_StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx.def("Init", (void (StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Integer, const opencascade::handle<StepBasic_HArray1OfNamedUnit> &, const opencascade::handle<StepBasic_HArray1OfUncertaintyMeasureWithUnit> &)) &StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx::Init, "None", py::arg("aContextIdentifier"), py::arg("aContextType"), py::arg("aCoordinateSpaceDimension"), py::arg("aUnits"), py::arg("anUncertainty"));
cls_StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx.def("SetGeometricRepresentationContext", (void (StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx::*)(const opencascade::handle<StepGeom_GeometricRepresentationContext> &)) &StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx::SetGeometricRepresentationContext, "None", py::arg("aGeometricRepresentationContext"));
cls_StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx.def("GeometricRepresentationContext", (opencascade::handle<StepGeom_GeometricRepresentationContext> (StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx::*)() const) &StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx::GeometricRepresentationContext, "None");
cls_StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx.def("SetGlobalUnitAssignedContext", (void (StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx::*)(const opencascade::handle<StepRepr_GlobalUnitAssignedContext> &)) &StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx::SetGlobalUnitAssignedContext, "None", py::arg("aGlobalUnitAssignedContext"));
cls_StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx.def("GlobalUnitAssignedContext", (opencascade::handle<StepRepr_GlobalUnitAssignedContext> (StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx::*)() const) &StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx::GlobalUnitAssignedContext, "None");
cls_StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx.def("SetGlobalUncertaintyAssignedContext", (void (StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx::*)(const opencascade::handle<StepRepr_GlobalUncertaintyAssignedContext> &)) &StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx::SetGlobalUncertaintyAssignedContext, "None", py::arg("aGlobalUncertaintyAssignedCtx"));
cls_StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx.def("GlobalUncertaintyAssignedContext", (opencascade::handle<StepRepr_GlobalUncertaintyAssignedContext> (StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx::*)() const) &StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx::GlobalUncertaintyAssignedContext, "None");
cls_StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx.def("SetCoordinateSpaceDimension", (void (StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx::*)(const Standard_Integer)) &StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx::SetCoordinateSpaceDimension, "None", py::arg("aCoordinateSpaceDimension"));
cls_StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx.def("CoordinateSpaceDimension", (Standard_Integer (StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx::*)() const) &StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx::CoordinateSpaceDimension, "None");
cls_StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx.def("SetUnits", (void (StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx::*)(const opencascade::handle<StepBasic_HArray1OfNamedUnit> &)) &StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx::SetUnits, "None", py::arg("aUnits"));
cls_StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx.def("Units", (opencascade::handle<StepBasic_HArray1OfNamedUnit> (StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx::*)() const) &StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx::Units, "None");
cls_StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx.def("UnitsValue", (opencascade::handle<StepBasic_NamedUnit> (StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx::*)(const Standard_Integer) const) &StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx::UnitsValue, "None", py::arg("num"));
cls_StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx.def("NbUnits", (Standard_Integer (StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx::*)() const) &StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx::NbUnits, "None");
cls_StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx.def("SetUncertainty", (void (StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx::*)(const opencascade::handle<StepBasic_HArray1OfUncertaintyMeasureWithUnit> &)) &StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx::SetUncertainty, "None", py::arg("aUncertainty"));
cls_StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx.def("Uncertainty", (opencascade::handle<StepBasic_HArray1OfUncertaintyMeasureWithUnit> (StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx::*)() const) &StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx::Uncertainty, "None");
cls_StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx.def("UncertaintyValue", (opencascade::handle<StepBasic_UncertaintyMeasureWithUnit> (StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx::*)(const Standard_Integer) const) &StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx::UncertaintyValue, "None", py::arg("num"));
cls_StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx.def("NbUncertainty", (Standard_Integer (StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx::*)() const) &StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx::NbUncertainty, "None");
cls_StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx.def_static("get_type_name_", (const char * (*)()) &StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx::get_type_name, "None");
cls_StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx::get_type_descriptor, "None");
cls_StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx::*)() const) &StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx::DynamicType, "None");

// Enums

}