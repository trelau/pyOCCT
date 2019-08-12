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
#include <StepDimTol_GeometricToleranceWithDatumReference.hxx>
#include <Standard_Handle.hxx>
#include <StepDimTol_ConcentricityTolerance.hxx>
#include <Standard_Type.hxx>

void bind_StepDimTol_ConcentricityTolerance(py::module &mod){

py::class_<StepDimTol_ConcentricityTolerance, opencascade::handle<StepDimTol_ConcentricityTolerance>, StepDimTol_GeometricToleranceWithDatumReference> cls_StepDimTol_ConcentricityTolerance(mod, "StepDimTol_ConcentricityTolerance", "Representation of STEP entity ConcentricityTolerance");

// Constructors
cls_StepDimTol_ConcentricityTolerance.def(py::init<>());

// Fields

// Methods
cls_StepDimTol_ConcentricityTolerance.def_static("get_type_name_", (const char * (*)()) &StepDimTol_ConcentricityTolerance::get_type_name, "None");
cls_StepDimTol_ConcentricityTolerance.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_ConcentricityTolerance::get_type_descriptor, "None");
cls_StepDimTol_ConcentricityTolerance.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_ConcentricityTolerance::*)() const) &StepDimTol_ConcentricityTolerance::DynamicType, "None");

// Enums

}