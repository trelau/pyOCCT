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
#include <StepFEA_DegreeOfFreedom.hxx>
#include <StepElement_MeasureOrUnspecifiedValue.hxx>
#include <Standard_Handle.hxx>
#include <StepFEA_FreedomAndCoefficient.hxx>
#include <Standard_Type.hxx>

void bind_StepFEA_FreedomAndCoefficient(py::module &mod){

py::class_<StepFEA_FreedomAndCoefficient, opencascade::handle<StepFEA_FreedomAndCoefficient>, Standard_Transient> cls_StepFEA_FreedomAndCoefficient(mod, "StepFEA_FreedomAndCoefficient", "Representation of STEP entity FreedomAndCoefficient");

// Constructors
cls_StepFEA_FreedomAndCoefficient.def(py::init<>());

// Fields

// Methods
cls_StepFEA_FreedomAndCoefficient.def("Init", (void (StepFEA_FreedomAndCoefficient::*)(const StepFEA_DegreeOfFreedom &, const StepElement_MeasureOrUnspecifiedValue &)) &StepFEA_FreedomAndCoefficient::Init, "Initialize all fields (own and inherited)", py::arg("aFreedom"), py::arg("aA"));
cls_StepFEA_FreedomAndCoefficient.def("Freedom", (StepFEA_DegreeOfFreedom (StepFEA_FreedomAndCoefficient::*)() const) &StepFEA_FreedomAndCoefficient::Freedom, "Returns field Freedom");
cls_StepFEA_FreedomAndCoefficient.def("SetFreedom", (void (StepFEA_FreedomAndCoefficient::*)(const StepFEA_DegreeOfFreedom &)) &StepFEA_FreedomAndCoefficient::SetFreedom, "Set field Freedom", py::arg("Freedom"));
cls_StepFEA_FreedomAndCoefficient.def("A", (StepElement_MeasureOrUnspecifiedValue (StepFEA_FreedomAndCoefficient::*)() const) &StepFEA_FreedomAndCoefficient::A, "Returns field A");
cls_StepFEA_FreedomAndCoefficient.def("SetA", (void (StepFEA_FreedomAndCoefficient::*)(const StepElement_MeasureOrUnspecifiedValue &)) &StepFEA_FreedomAndCoefficient::SetA, "Set field A", py::arg("A"));
cls_StepFEA_FreedomAndCoefficient.def_static("get_type_name_", (const char * (*)()) &StepFEA_FreedomAndCoefficient::get_type_name, "None");
cls_StepFEA_FreedomAndCoefficient.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_FreedomAndCoefficient::get_type_descriptor, "None");
cls_StepFEA_FreedomAndCoefficient.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_FreedomAndCoefficient::*)() const) &StepFEA_FreedomAndCoefficient::DynamicType, "None");

// Enums

}