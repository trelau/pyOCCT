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
#include <StepDimTol_DatumReferenceModifierType.hxx>
#include <Standard_Handle.hxx>
#include <StepBasic_LengthMeasureWithUnit.hxx>
#include <StepDimTol_DatumReferenceModifierWithValue.hxx>
#include <Standard_Type.hxx>

void bind_StepDimTol_DatumReferenceModifierWithValue(py::module &mod){

py::class_<StepDimTol_DatumReferenceModifierWithValue, opencascade::handle<StepDimTol_DatumReferenceModifierWithValue>, Standard_Transient> cls_StepDimTol_DatumReferenceModifierWithValue(mod, "StepDimTol_DatumReferenceModifierWithValue", "Representation of STEP entity DatumReferenceModifierWithValue");

// Constructors
cls_StepDimTol_DatumReferenceModifierWithValue.def(py::init<>());

// Fields

// Methods
cls_StepDimTol_DatumReferenceModifierWithValue.def("Init", (void (StepDimTol_DatumReferenceModifierWithValue::*)(const StepDimTol_DatumReferenceModifierType &, const opencascade::handle<StepBasic_LengthMeasureWithUnit> &)) &StepDimTol_DatumReferenceModifierWithValue::Init, "Initialize all fields (own and inherited)", py::arg("theModifierType"), py::arg("theModifierValue"));
cls_StepDimTol_DatumReferenceModifierWithValue.def("ModifierType", (StepDimTol_DatumReferenceModifierType (StepDimTol_DatumReferenceModifierWithValue::*)() const) &StepDimTol_DatumReferenceModifierWithValue::ModifierType, "Returns field ModifierType");
cls_StepDimTol_DatumReferenceModifierWithValue.def("SetModifierType", (void (StepDimTol_DatumReferenceModifierWithValue::*)(const StepDimTol_DatumReferenceModifierType &)) &StepDimTol_DatumReferenceModifierWithValue::SetModifierType, "Set field ModifierType", py::arg("theModifierType"));
cls_StepDimTol_DatumReferenceModifierWithValue.def("ModifierValue", (opencascade::handle<StepBasic_LengthMeasureWithUnit> (StepDimTol_DatumReferenceModifierWithValue::*)()) &StepDimTol_DatumReferenceModifierWithValue::ModifierValue, "Returns field ModifierValue");
cls_StepDimTol_DatumReferenceModifierWithValue.def("SetModifierValue", (void (StepDimTol_DatumReferenceModifierWithValue::*)(const opencascade::handle<StepBasic_LengthMeasureWithUnit> &)) &StepDimTol_DatumReferenceModifierWithValue::SetModifierValue, "Set field ModifierValue", py::arg("theModifierValue"));
cls_StepDimTol_DatumReferenceModifierWithValue.def_static("get_type_name_", (const char * (*)()) &StepDimTol_DatumReferenceModifierWithValue::get_type_name, "None");
cls_StepDimTol_DatumReferenceModifierWithValue.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_DatumReferenceModifierWithValue::get_type_descriptor, "None");
cls_StepDimTol_DatumReferenceModifierWithValue.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_DatumReferenceModifierWithValue::*)() const) &StepDimTol_DatumReferenceModifierWithValue::DynamicType, "None");

// Enums

}