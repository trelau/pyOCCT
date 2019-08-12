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
#include <IFSelect_Activator.hxx>
#include <IFSelect_ReturnStatus.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <IFSelect_SessionPilot.hxx>
#include <StepSelect_Activator.hxx>
#include <Standard_Type.hxx>

void bind_StepSelect_Activator(py::module &mod){

py::class_<StepSelect_Activator, opencascade::handle<StepSelect_Activator>, IFSelect_Activator> cls_StepSelect_Activator(mod, "StepSelect_Activator", "Performs Actions specific to StepSelect, i.e. creation of Step Selections and Counters, plus dumping specific to Step");

// Constructors
cls_StepSelect_Activator.def(py::init<>());

// Fields

// Methods
cls_StepSelect_Activator.def("Do", (IFSelect_ReturnStatus (StepSelect_Activator::*)(const Standard_Integer, const opencascade::handle<IFSelect_SessionPilot> &)) &StepSelect_Activator::Do, "Executes a Command Line for StepSelect", py::arg("number"), py::arg("pilot"));
cls_StepSelect_Activator.def("Help", (Standard_CString (StepSelect_Activator::*)(const Standard_Integer) const) &StepSelect_Activator::Help, "Sends a short help message for StepSelect commands", py::arg("number"));
cls_StepSelect_Activator.def_static("get_type_name_", (const char * (*)()) &StepSelect_Activator::get_type_name, "None");
cls_StepSelect_Activator.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepSelect_Activator::get_type_descriptor, "None");
cls_StepSelect_Activator.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepSelect_Activator::*)() const) &StepSelect_Activator::DynamicType, "None");

// Enums

}