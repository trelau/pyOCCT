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
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepDimTol_ToleranceZoneForm.hxx>
#include <Standard_Type.hxx>

void bind_StepDimTol_ToleranceZoneForm(py::module &mod){

py::class_<StepDimTol_ToleranceZoneForm, opencascade::handle<StepDimTol_ToleranceZoneForm>, Standard_Transient> cls_StepDimTol_ToleranceZoneForm(mod, "StepDimTol_ToleranceZoneForm", "Added for Dimensional Tolerances");

// Constructors
cls_StepDimTol_ToleranceZoneForm.def(py::init<>());

// Fields

// Methods
cls_StepDimTol_ToleranceZoneForm.def("Init", (void (StepDimTol_ToleranceZoneForm::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepDimTol_ToleranceZoneForm::Init, "Init all field own and inherited", py::arg("theName"));
cls_StepDimTol_ToleranceZoneForm.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepDimTol_ToleranceZoneForm::*)()) &StepDimTol_ToleranceZoneForm::Name, "Returns field Name");
cls_StepDimTol_ToleranceZoneForm.def("SetName", (void (StepDimTol_ToleranceZoneForm::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepDimTol_ToleranceZoneForm::SetName, "Set field Name", py::arg("theName"));
cls_StepDimTol_ToleranceZoneForm.def_static("get_type_name_", (const char * (*)()) &StepDimTol_ToleranceZoneForm::get_type_name, "None");
cls_StepDimTol_ToleranceZoneForm.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_ToleranceZoneForm::get_type_descriptor, "None");
cls_StepDimTol_ToleranceZoneForm.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_ToleranceZoneForm::*)() const) &StepDimTol_ToleranceZoneForm::DynamicType, "None");

// Enums

}