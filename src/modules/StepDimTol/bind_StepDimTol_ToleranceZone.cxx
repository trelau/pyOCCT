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
#include <StepRepr_ShapeAspect.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepRepr_ProductDefinitionShape.hxx>
#include <StepData_Logical.hxx>
#include <StepDimTol_HArray1OfToleranceZoneTarget.hxx>
#include <StepDimTol_ToleranceZoneForm.hxx>
#include <Standard_TypeDef.hxx>
#include <StepDimTol_ToleranceZoneTarget.hxx>
#include <StepDimTol_ToleranceZone.hxx>
#include <Standard_Type.hxx>

void bind_StepDimTol_ToleranceZone(py::module &mod){

py::class_<StepDimTol_ToleranceZone, opencascade::handle<StepDimTol_ToleranceZone>, StepRepr_ShapeAspect> cls_StepDimTol_ToleranceZone(mod, "StepDimTol_ToleranceZone", "Representation of STEP entity ToleranceZone");

// Constructors
cls_StepDimTol_ToleranceZone.def(py::init<>());

// Fields

// Methods
cls_StepDimTol_ToleranceZone.def("Init", (void (StepDimTol_ToleranceZone::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepRepr_ProductDefinitionShape> &, const StepData_Logical, const opencascade::handle<StepDimTol_HArray1OfToleranceZoneTarget> &, const opencascade::handle<StepDimTol_ToleranceZoneForm> &)) &StepDimTol_ToleranceZone::Init, "Initialize all fields (own and inherited)", py::arg("theName"), py::arg("theDescription"), py::arg("theOfShape"), py::arg("theProductDefinitional"), py::arg("theDefiningTolerance"), py::arg("theForm"));
cls_StepDimTol_ToleranceZone.def("DefiningTolerance", (opencascade::handle<StepDimTol_HArray1OfToleranceZoneTarget> (StepDimTol_ToleranceZone::*)() const) &StepDimTol_ToleranceZone::DefiningTolerance, "Returns field DefiningTolerance");
cls_StepDimTol_ToleranceZone.def("SetDefiningTolerance", (void (StepDimTol_ToleranceZone::*)(const opencascade::handle<StepDimTol_HArray1OfToleranceZoneTarget> &)) &StepDimTol_ToleranceZone::SetDefiningTolerance, "Set field DefiningTolerance", py::arg("theDefiningTolerance"));
cls_StepDimTol_ToleranceZone.def("NbDefiningTolerances", (Standard_Integer (StepDimTol_ToleranceZone::*)() const) &StepDimTol_ToleranceZone::NbDefiningTolerances, "Returns number of Defining Tolerances");
cls_StepDimTol_ToleranceZone.def("DefiningToleranceValue", (StepDimTol_ToleranceZoneTarget (StepDimTol_ToleranceZone::*)(const Standard_Integer) const) &StepDimTol_ToleranceZone::DefiningToleranceValue, "Returns Defining Tolerance with the given number", py::arg("theNum"));
cls_StepDimTol_ToleranceZone.def("SetDefiningToleranceValue", (void (StepDimTol_ToleranceZone::*)(const Standard_Integer, const StepDimTol_ToleranceZoneTarget &)) &StepDimTol_ToleranceZone::SetDefiningToleranceValue, "Sets Defining Tolerance with given number", py::arg("theNum"), py::arg("theItem"));
cls_StepDimTol_ToleranceZone.def("Form", (opencascade::handle<StepDimTol_ToleranceZoneForm> (StepDimTol_ToleranceZone::*)()) &StepDimTol_ToleranceZone::Form, "Returns field Form");
cls_StepDimTol_ToleranceZone.def("SetForm", (void (StepDimTol_ToleranceZone::*)(const opencascade::handle<StepDimTol_ToleranceZoneForm> &)) &StepDimTol_ToleranceZone::SetForm, "Set field Form", py::arg("theForm"));
cls_StepDimTol_ToleranceZone.def_static("get_type_name_", (const char * (*)()) &StepDimTol_ToleranceZone::get_type_name, "None");
cls_StepDimTol_ToleranceZone.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_ToleranceZone::get_type_descriptor, "None");
cls_StepDimTol_ToleranceZone.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_ToleranceZone::*)() const) &StepDimTol_ToleranceZone::DynamicType, "None");

// Enums

}