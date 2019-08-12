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
#include <StepData_SelectNamed.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <StepData_SelectArrReal.hxx>
#include <Standard_Type.hxx>

void bind_StepData_SelectArrReal(py::module &mod){

py::class_<StepData_SelectArrReal, opencascade::handle<StepData_SelectArrReal>, StepData_SelectNamed> cls_StepData_SelectArrReal(mod, "StepData_SelectArrReal", "None");

// Constructors
cls_StepData_SelectArrReal.def(py::init<>());

// Fields

// Methods
cls_StepData_SelectArrReal.def("Kind", (Standard_Integer (StepData_SelectArrReal::*)() const) &StepData_SelectArrReal::Kind, "None");
cls_StepData_SelectArrReal.def("ArrReal", (opencascade::handle<TColStd_HArray1OfReal> (StepData_SelectArrReal::*)() const) &StepData_SelectArrReal::ArrReal, "None");
cls_StepData_SelectArrReal.def("SetArrReal", (void (StepData_SelectArrReal::*)(const opencascade::handle<TColStd_HArray1OfReal> &)) &StepData_SelectArrReal::SetArrReal, "None", py::arg("arr"));
cls_StepData_SelectArrReal.def_static("get_type_name_", (const char * (*)()) &StepData_SelectArrReal::get_type_name, "None");
cls_StepData_SelectArrReal.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepData_SelectArrReal::get_type_descriptor, "None");
cls_StepData_SelectArrReal.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepData_SelectArrReal::*)() const) &StepData_SelectArrReal::DynamicType, "None");

// Enums

}