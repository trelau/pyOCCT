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
#include <StepGeom_GeometricRepresentationItem.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <Standard_TypeDef.hxx>
#include <StepGeom_Direction.hxx>
#include <StepGeom_CartesianPoint.hxx>
#include <StepGeom_CartesianTransformationOperator.hxx>
#include <Standard_Type.hxx>

void bind_StepGeom_CartesianTransformationOperator(py::module &mod){

py::class_<StepGeom_CartesianTransformationOperator, opencascade::handle<StepGeom_CartesianTransformationOperator>, StepGeom_GeometricRepresentationItem> cls_StepGeom_CartesianTransformationOperator(mod, "StepGeom_CartesianTransformationOperator", "None");

// Constructors
cls_StepGeom_CartesianTransformationOperator.def(py::init<>());

// Fields

// Methods
cls_StepGeom_CartesianTransformationOperator.def("Init", (void (StepGeom_CartesianTransformationOperator::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<StepGeom_Direction> &, const Standard_Boolean, const opencascade::handle<StepGeom_Direction> &, const opencascade::handle<StepGeom_CartesianPoint> &, const Standard_Boolean, const Standard_Real)) &StepGeom_CartesianTransformationOperator::Init, "None", py::arg("aName"), py::arg("hasAaxis1"), py::arg("aAxis1"), py::arg("hasAaxis2"), py::arg("aAxis2"), py::arg("aLocalOrigin"), py::arg("hasAscale"), py::arg("aScale"));
cls_StepGeom_CartesianTransformationOperator.def("SetAxis1", (void (StepGeom_CartesianTransformationOperator::*)(const opencascade::handle<StepGeom_Direction> &)) &StepGeom_CartesianTransformationOperator::SetAxis1, "None", py::arg("aAxis1"));
cls_StepGeom_CartesianTransformationOperator.def("UnSetAxis1", (void (StepGeom_CartesianTransformationOperator::*)()) &StepGeom_CartesianTransformationOperator::UnSetAxis1, "None");
cls_StepGeom_CartesianTransformationOperator.def("Axis1", (opencascade::handle<StepGeom_Direction> (StepGeom_CartesianTransformationOperator::*)() const) &StepGeom_CartesianTransformationOperator::Axis1, "None");
cls_StepGeom_CartesianTransformationOperator.def("HasAxis1", (Standard_Boolean (StepGeom_CartesianTransformationOperator::*)() const) &StepGeom_CartesianTransformationOperator::HasAxis1, "None");
cls_StepGeom_CartesianTransformationOperator.def("SetAxis2", (void (StepGeom_CartesianTransformationOperator::*)(const opencascade::handle<StepGeom_Direction> &)) &StepGeom_CartesianTransformationOperator::SetAxis2, "None", py::arg("aAxis2"));
cls_StepGeom_CartesianTransformationOperator.def("UnSetAxis2", (void (StepGeom_CartesianTransformationOperator::*)()) &StepGeom_CartesianTransformationOperator::UnSetAxis2, "None");
cls_StepGeom_CartesianTransformationOperator.def("Axis2", (opencascade::handle<StepGeom_Direction> (StepGeom_CartesianTransformationOperator::*)() const) &StepGeom_CartesianTransformationOperator::Axis2, "None");
cls_StepGeom_CartesianTransformationOperator.def("HasAxis2", (Standard_Boolean (StepGeom_CartesianTransformationOperator::*)() const) &StepGeom_CartesianTransformationOperator::HasAxis2, "None");
cls_StepGeom_CartesianTransformationOperator.def("SetLocalOrigin", (void (StepGeom_CartesianTransformationOperator::*)(const opencascade::handle<StepGeom_CartesianPoint> &)) &StepGeom_CartesianTransformationOperator::SetLocalOrigin, "None", py::arg("aLocalOrigin"));
cls_StepGeom_CartesianTransformationOperator.def("LocalOrigin", (opencascade::handle<StepGeom_CartesianPoint> (StepGeom_CartesianTransformationOperator::*)() const) &StepGeom_CartesianTransformationOperator::LocalOrigin, "None");
cls_StepGeom_CartesianTransformationOperator.def("SetScale", (void (StepGeom_CartesianTransformationOperator::*)(const Standard_Real)) &StepGeom_CartesianTransformationOperator::SetScale, "None", py::arg("aScale"));
cls_StepGeom_CartesianTransformationOperator.def("UnSetScale", (void (StepGeom_CartesianTransformationOperator::*)()) &StepGeom_CartesianTransformationOperator::UnSetScale, "None");
cls_StepGeom_CartesianTransformationOperator.def("Scale", (Standard_Real (StepGeom_CartesianTransformationOperator::*)() const) &StepGeom_CartesianTransformationOperator::Scale, "None");
cls_StepGeom_CartesianTransformationOperator.def("HasScale", (Standard_Boolean (StepGeom_CartesianTransformationOperator::*)() const) &StepGeom_CartesianTransformationOperator::HasScale, "None");
cls_StepGeom_CartesianTransformationOperator.def_static("get_type_name_", (const char * (*)()) &StepGeom_CartesianTransformationOperator::get_type_name, "None");
cls_StepGeom_CartesianTransformationOperator.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_CartesianTransformationOperator::get_type_descriptor, "None");
cls_StepGeom_CartesianTransformationOperator.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_CartesianTransformationOperator::*)() const) &StepGeom_CartesianTransformationOperator::DynamicType, "None");

// Enums

}