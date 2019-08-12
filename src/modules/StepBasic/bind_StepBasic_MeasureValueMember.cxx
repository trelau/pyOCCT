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
#include <StepData_SelectReal.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <StepBasic_MeasureValueMember.hxx>
#include <Standard_Type.hxx>

void bind_StepBasic_MeasureValueMember(py::module &mod){

py::class_<StepBasic_MeasureValueMember, opencascade::handle<StepBasic_MeasureValueMember>, StepData_SelectReal> cls_StepBasic_MeasureValueMember(mod, "StepBasic_MeasureValueMember", "for Select MeasureValue, i.e. : length_measure,time_measure,plane_angle_measure, solid_angle_measure,ratio_measure,parameter_value, context_dependent_measure,positive_length_measure, positive_plane_angle_measure,positive_ratio_measure, area_measure,volume_measure, count_measure");

// Constructors
cls_StepBasic_MeasureValueMember.def(py::init<>());

// Fields

// Methods
cls_StepBasic_MeasureValueMember.def("HasName", (Standard_Boolean (StepBasic_MeasureValueMember::*)() const) &StepBasic_MeasureValueMember::HasName, "None");
cls_StepBasic_MeasureValueMember.def("Name", (Standard_CString (StepBasic_MeasureValueMember::*)() const) &StepBasic_MeasureValueMember::Name, "None");
cls_StepBasic_MeasureValueMember.def("SetName", (Standard_Boolean (StepBasic_MeasureValueMember::*)(const Standard_CString)) &StepBasic_MeasureValueMember::SetName, "None", py::arg("name"));
cls_StepBasic_MeasureValueMember.def_static("get_type_name_", (const char * (*)()) &StepBasic_MeasureValueMember::get_type_name, "None");
cls_StepBasic_MeasureValueMember.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_MeasureValueMember::get_type_descriptor, "None");
cls_StepBasic_MeasureValueMember.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_MeasureValueMember::*)() const) &StepBasic_MeasureValueMember::DynamicType, "None");

// Enums

}