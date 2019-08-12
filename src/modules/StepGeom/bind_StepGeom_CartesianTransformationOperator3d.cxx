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
#include <StepGeom_CartesianTransformationOperator.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <Standard_TypeDef.hxx>
#include <StepGeom_Direction.hxx>
#include <StepGeom_CartesianPoint.hxx>
#include <StepGeom_CartesianTransformationOperator3d.hxx>
#include <Standard_Type.hxx>

void bind_StepGeom_CartesianTransformationOperator3d(py::module &mod){

py::class_<StepGeom_CartesianTransformationOperator3d, opencascade::handle<StepGeom_CartesianTransformationOperator3d>, StepGeom_CartesianTransformationOperator> cls_StepGeom_CartesianTransformationOperator3d(mod, "StepGeom_CartesianTransformationOperator3d", "None");

// Constructors
cls_StepGeom_CartesianTransformationOperator3d.def(py::init<>());

// Fields

// Methods
cls_StepGeom_CartesianTransformationOperator3d.def("Init", (void (StepGeom_CartesianTransformationOperator3d::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<StepGeom_Direction> &, const Standard_Boolean, const opencascade::handle<StepGeom_Direction> &, const opencascade::handle<StepGeom_CartesianPoint> &, const Standard_Boolean, const Standard_Real, const Standard_Boolean, const opencascade::handle<StepGeom_Direction> &)) &StepGeom_CartesianTransformationOperator3d::Init, "None", py::arg("aName"), py::arg("hasAaxis1"), py::arg("aAxis1"), py::arg("hasAaxis2"), py::arg("aAxis2"), py::arg("aLocalOrigin"), py::arg("hasAscale"), py::arg("aScale"), py::arg("hasAaxis3"), py::arg("aAxis3"));
cls_StepGeom_CartesianTransformationOperator3d.def("SetAxis3", (void (StepGeom_CartesianTransformationOperator3d::*)(const opencascade::handle<StepGeom_Direction> &)) &StepGeom_CartesianTransformationOperator3d::SetAxis3, "None", py::arg("aAxis3"));
cls_StepGeom_CartesianTransformationOperator3d.def("UnSetAxis3", (void (StepGeom_CartesianTransformationOperator3d::*)()) &StepGeom_CartesianTransformationOperator3d::UnSetAxis3, "None");
cls_StepGeom_CartesianTransformationOperator3d.def("Axis3", (opencascade::handle<StepGeom_Direction> (StepGeom_CartesianTransformationOperator3d::*)() const) &StepGeom_CartesianTransformationOperator3d::Axis3, "None");
cls_StepGeom_CartesianTransformationOperator3d.def("HasAxis3", (Standard_Boolean (StepGeom_CartesianTransformationOperator3d::*)() const) &StepGeom_CartesianTransformationOperator3d::HasAxis3, "None");
cls_StepGeom_CartesianTransformationOperator3d.def_static("get_type_name_", (const char * (*)()) &StepGeom_CartesianTransformationOperator3d::get_type_name, "None");
cls_StepGeom_CartesianTransformationOperator3d.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_CartesianTransformationOperator3d::get_type_descriptor, "None");
cls_StepGeom_CartesianTransformationOperator3d.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_CartesianTransformationOperator3d::*)() const) &StepGeom_CartesianTransformationOperator3d::DynamicType, "None");

// Enums

}