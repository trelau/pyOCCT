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
#include <StepGeom_Point.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepGeom_CartesianTransformationOperator.hxx>
#include <StepGeom_PointReplica.hxx>
#include <Standard_Type.hxx>

void bind_StepGeom_PointReplica(py::module &mod){

py::class_<StepGeom_PointReplica, opencascade::handle<StepGeom_PointReplica>, StepGeom_Point> cls_StepGeom_PointReplica(mod, "StepGeom_PointReplica", "None");

// Constructors
cls_StepGeom_PointReplica.def(py::init<>());

// Fields

// Methods
cls_StepGeom_PointReplica.def("Init", (void (StepGeom_PointReplica::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepGeom_Point> &, const opencascade::handle<StepGeom_CartesianTransformationOperator> &)) &StepGeom_PointReplica::Init, "None", py::arg("aName"), py::arg("aParentPt"), py::arg("aTransformation"));
cls_StepGeom_PointReplica.def("SetParentPt", (void (StepGeom_PointReplica::*)(const opencascade::handle<StepGeom_Point> &)) &StepGeom_PointReplica::SetParentPt, "None", py::arg("aParentPt"));
cls_StepGeom_PointReplica.def("ParentPt", (opencascade::handle<StepGeom_Point> (StepGeom_PointReplica::*)() const) &StepGeom_PointReplica::ParentPt, "None");
cls_StepGeom_PointReplica.def("SetTransformation", (void (StepGeom_PointReplica::*)(const opencascade::handle<StepGeom_CartesianTransformationOperator> &)) &StepGeom_PointReplica::SetTransformation, "None", py::arg("aTransformation"));
cls_StepGeom_PointReplica.def("Transformation", (opencascade::handle<StepGeom_CartesianTransformationOperator> (StepGeom_PointReplica::*)() const) &StepGeom_PointReplica::Transformation, "None");
cls_StepGeom_PointReplica.def_static("get_type_name_", (const char * (*)()) &StepGeom_PointReplica::get_type_name, "None");
cls_StepGeom_PointReplica.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_PointReplica::get_type_descriptor, "None");
cls_StepGeom_PointReplica.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_PointReplica::*)() const) &StepGeom_PointReplica::DynamicType, "None");

// Enums

}