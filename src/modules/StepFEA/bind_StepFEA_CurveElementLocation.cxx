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
#include <StepFEA_FeaParametricPoint.hxx>
#include <StepFEA_CurveElementLocation.hxx>
#include <Standard_Type.hxx>

void bind_StepFEA_CurveElementLocation(py::module &mod){

py::class_<StepFEA_CurveElementLocation, opencascade::handle<StepFEA_CurveElementLocation>, Standard_Transient> cls_StepFEA_CurveElementLocation(mod, "StepFEA_CurveElementLocation", "Representation of STEP entity CurveElementLocation");

// Constructors
cls_StepFEA_CurveElementLocation.def(py::init<>());

// Fields

// Methods
cls_StepFEA_CurveElementLocation.def("Init", (void (StepFEA_CurveElementLocation::*)(const opencascade::handle<StepFEA_FeaParametricPoint> &)) &StepFEA_CurveElementLocation::Init, "Initialize all fields (own and inherited)", py::arg("aCoordinate"));
cls_StepFEA_CurveElementLocation.def("Coordinate", (opencascade::handle<StepFEA_FeaParametricPoint> (StepFEA_CurveElementLocation::*)() const) &StepFEA_CurveElementLocation::Coordinate, "Returns field Coordinate");
cls_StepFEA_CurveElementLocation.def("SetCoordinate", (void (StepFEA_CurveElementLocation::*)(const opencascade::handle<StepFEA_FeaParametricPoint> &)) &StepFEA_CurveElementLocation::SetCoordinate, "Set field Coordinate", py::arg("Coordinate"));
cls_StepFEA_CurveElementLocation.def_static("get_type_name_", (const char * (*)()) &StepFEA_CurveElementLocation::get_type_name, "None");
cls_StepFEA_CurveElementLocation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_CurveElementLocation::get_type_descriptor, "None");
cls_StepFEA_CurveElementLocation.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_CurveElementLocation::*)() const) &StepFEA_CurveElementLocation::DynamicType, "None");

// Enums

}