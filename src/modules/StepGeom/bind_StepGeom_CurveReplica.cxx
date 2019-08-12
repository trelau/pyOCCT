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
#include <StepGeom_Curve.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepGeom_CartesianTransformationOperator.hxx>
#include <StepGeom_CurveReplica.hxx>
#include <Standard_Type.hxx>

void bind_StepGeom_CurveReplica(py::module &mod){

py::class_<StepGeom_CurveReplica, opencascade::handle<StepGeom_CurveReplica>, StepGeom_Curve> cls_StepGeom_CurveReplica(mod, "StepGeom_CurveReplica", "None");

// Constructors
cls_StepGeom_CurveReplica.def(py::init<>());

// Fields

// Methods
cls_StepGeom_CurveReplica.def("Init", (void (StepGeom_CurveReplica::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepGeom_Curve> &, const opencascade::handle<StepGeom_CartesianTransformationOperator> &)) &StepGeom_CurveReplica::Init, "None", py::arg("aName"), py::arg("aParentCurve"), py::arg("aTransformation"));
cls_StepGeom_CurveReplica.def("SetParentCurve", (void (StepGeom_CurveReplica::*)(const opencascade::handle<StepGeom_Curve> &)) &StepGeom_CurveReplica::SetParentCurve, "None", py::arg("aParentCurve"));
cls_StepGeom_CurveReplica.def("ParentCurve", (opencascade::handle<StepGeom_Curve> (StepGeom_CurveReplica::*)() const) &StepGeom_CurveReplica::ParentCurve, "None");
cls_StepGeom_CurveReplica.def("SetTransformation", (void (StepGeom_CurveReplica::*)(const opencascade::handle<StepGeom_CartesianTransformationOperator> &)) &StepGeom_CurveReplica::SetTransformation, "None", py::arg("aTransformation"));
cls_StepGeom_CurveReplica.def("Transformation", (opencascade::handle<StepGeom_CartesianTransformationOperator> (StepGeom_CurveReplica::*)() const) &StepGeom_CurveReplica::Transformation, "None");
cls_StepGeom_CurveReplica.def_static("get_type_name_", (const char * (*)()) &StepGeom_CurveReplica::get_type_name, "None");
cls_StepGeom_CurveReplica.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_CurveReplica::get_type_descriptor, "None");
cls_StepGeom_CurveReplica.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_CurveReplica::*)() const) &StepGeom_CurveReplica::DynamicType, "None");

// Enums

}