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
#include <StepGeom_Axis2Placement3d.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepGeom_CartesianPoint.hxx>
#include <Standard_TypeDef.hxx>
#include <StepGeom_Direction.hxx>
#include <StepFEA_CoordinateSystemType.hxx>
#include <StepFEA_FeaAxis2Placement3d.hxx>
#include <Standard_Type.hxx>

void bind_StepFEA_FeaAxis2Placement3d(py::module &mod){

py::class_<StepFEA_FeaAxis2Placement3d, opencascade::handle<StepFEA_FeaAxis2Placement3d>, StepGeom_Axis2Placement3d> cls_StepFEA_FeaAxis2Placement3d(mod, "StepFEA_FeaAxis2Placement3d", "Representation of STEP entity FeaAxis2Placement3d");

// Constructors
cls_StepFEA_FeaAxis2Placement3d.def(py::init<>());

// Fields

// Methods
cls_StepFEA_FeaAxis2Placement3d.def("Init", (void (StepFEA_FeaAxis2Placement3d::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepGeom_CartesianPoint> &, const Standard_Boolean, const opencascade::handle<StepGeom_Direction> &, const Standard_Boolean, const opencascade::handle<StepGeom_Direction> &, const StepFEA_CoordinateSystemType, const opencascade::handle<TCollection_HAsciiString> &)) &StepFEA_FeaAxis2Placement3d::Init, "Initialize all fields (own and inherited)", py::arg("aRepresentationItem_Name"), py::arg("aPlacement_Location"), py::arg("hasAxis2Placement3d_Axis"), py::arg("aAxis2Placement3d_Axis"), py::arg("hasAxis2Placement3d_RefDirection"), py::arg("aAxis2Placement3d_RefDirection"), py::arg("aSystemType"), py::arg("aDescription"));
cls_StepFEA_FeaAxis2Placement3d.def("SystemType", (StepFEA_CoordinateSystemType (StepFEA_FeaAxis2Placement3d::*)() const) &StepFEA_FeaAxis2Placement3d::SystemType, "Returns field SystemType");
cls_StepFEA_FeaAxis2Placement3d.def("SetSystemType", (void (StepFEA_FeaAxis2Placement3d::*)(const StepFEA_CoordinateSystemType)) &StepFEA_FeaAxis2Placement3d::SetSystemType, "Set field SystemType", py::arg("SystemType"));
cls_StepFEA_FeaAxis2Placement3d.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepFEA_FeaAxis2Placement3d::*)() const) &StepFEA_FeaAxis2Placement3d::Description, "Returns field Description");
cls_StepFEA_FeaAxis2Placement3d.def("SetDescription", (void (StepFEA_FeaAxis2Placement3d::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepFEA_FeaAxis2Placement3d::SetDescription, "Set field Description", py::arg("Description"));
cls_StepFEA_FeaAxis2Placement3d.def_static("get_type_name_", (const char * (*)()) &StepFEA_FeaAxis2Placement3d::get_type_name, "None");
cls_StepFEA_FeaAxis2Placement3d.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_FeaAxis2Placement3d::get_type_descriptor, "None");
cls_StepFEA_FeaAxis2Placement3d.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_FeaAxis2Placement3d::*)() const) &StepFEA_FeaAxis2Placement3d::DynamicType, "None");

// Enums

}