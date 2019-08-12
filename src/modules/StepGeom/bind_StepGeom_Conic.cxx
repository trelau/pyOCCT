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
#include <StepGeom_Axis2Placement.hxx>
#include <StepGeom_Conic.hxx>
#include <Standard_Type.hxx>

void bind_StepGeom_Conic(py::module &mod){

py::class_<StepGeom_Conic, opencascade::handle<StepGeom_Conic>, StepGeom_Curve> cls_StepGeom_Conic(mod, "StepGeom_Conic", "None");

// Constructors
cls_StepGeom_Conic.def(py::init<>());

// Fields

// Methods
cls_StepGeom_Conic.def("Init", (void (StepGeom_Conic::*)(const opencascade::handle<TCollection_HAsciiString> &, const StepGeom_Axis2Placement &)) &StepGeom_Conic::Init, "None", py::arg("aName"), py::arg("aPosition"));
cls_StepGeom_Conic.def("SetPosition", (void (StepGeom_Conic::*)(const StepGeom_Axis2Placement &)) &StepGeom_Conic::SetPosition, "None", py::arg("aPosition"));
cls_StepGeom_Conic.def("Position", (StepGeom_Axis2Placement (StepGeom_Conic::*)() const) &StepGeom_Conic::Position, "None");
cls_StepGeom_Conic.def_static("get_type_name_", (const char * (*)()) &StepGeom_Conic::get_type_name, "None");
cls_StepGeom_Conic.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_Conic::get_type_descriptor, "None");
cls_StepGeom_Conic.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_Conic::*)() const) &StepGeom_Conic::DynamicType, "None");

// Enums

}