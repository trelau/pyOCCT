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
#include <IFSelect_Modifier.hxx>
#include <IFSelect_ContextModif.hxx>
#include <Standard_Handle.hxx>
#include <Interface_InterfaceModel.hxx>
#include <Interface_Protocol.hxx>
#include <Interface_CopyTool.hxx>
#include <StepData_StepModel.hxx>
#include <StepData_Protocol.hxx>
#include <StepSelect_ModelModifier.hxx>
#include <Standard_Type.hxx>
#include <Standard_TypeDef.hxx>

void bind_StepSelect_ModelModifier(py::module &mod){

py::class_<StepSelect_ModelModifier, opencascade::handle<StepSelect_ModelModifier>, IFSelect_Modifier> cls_StepSelect_ModelModifier(mod, "StepSelect_ModelModifier", "None");

// Fields

// Methods
cls_StepSelect_ModelModifier.def("Perform", (void (StepSelect_ModelModifier::*)(IFSelect_ContextModif &, const opencascade::handle<Interface_InterfaceModel> &, const opencascade::handle<Interface_Protocol> &, Interface_CopyTool &) const) &StepSelect_ModelModifier::Perform, "The inherited Perform does the required cast (and refuses to go further if cast has failed) then calls the instantiated Performing", py::arg("ctx"), py::arg("target"), py::arg("protocol"), py::arg("TC"));
cls_StepSelect_ModelModifier.def("PerformProtocol", (void (StepSelect_ModelModifier::*)(IFSelect_ContextModif &, const opencascade::handle<StepData_StepModel> &, const opencascade::handle<StepData_Protocol> &, Interface_CopyTool &) const) &StepSelect_ModelModifier::PerformProtocol, "Specific Perform with Protocol. It is defined to let the Protocol unused and to call Performing without Protocol (most current case). It can be redefined if specific action requires Protocol.", py::arg("ctx"), py::arg("target"), py::arg("proto"), py::arg("TC"));
cls_StepSelect_ModelModifier.def("Performing", (void (StepSelect_ModelModifier::*)(IFSelect_ContextModif &, const opencascade::handle<StepData_StepModel> &, Interface_CopyTool &) const) &StepSelect_ModelModifier::Performing, "Specific Perform, without Protocol. If Performing with Protocol is redefined, Performing without Protocol must though be defined to do nothing (not called, but demanded by the linker)", py::arg("ctx"), py::arg("target"), py::arg("TC"));
cls_StepSelect_ModelModifier.def_static("get_type_name_", (const char * (*)()) &StepSelect_ModelModifier::get_type_name, "None");
cls_StepSelect_ModelModifier.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepSelect_ModelModifier::get_type_descriptor, "None");
cls_StepSelect_ModelModifier.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepSelect_ModelModifier::*)() const) &StepSelect_ModelModifier::DynamicType, "None");

// Enums

}