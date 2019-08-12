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
#include <StepData_GeneralModule.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Transient.hxx>
#include <Interface_EntityIterator.hxx>
#include <Interface_ShareTool.hxx>
#include <Interface_Check.hxx>
#include <Interface_CopyTool.hxx>
#include <TCollection_HAsciiString.hxx>
#include <RWStepAP214_GeneralModule.hxx>
#include <Standard_Type.hxx>

void bind_RWStepAP214_GeneralModule(py::module &mod){

py::class_<RWStepAP214_GeneralModule, opencascade::handle<RWStepAP214_GeneralModule>, StepData_GeneralModule> cls_RWStepAP214_GeneralModule(mod, "RWStepAP214_GeneralModule", "Defines General Services for StepAP214 Entities (Share,Check,Copy; Trace already inherited) Depends (for case numbers) of Protocol from StepAP214");

// Constructors
cls_RWStepAP214_GeneralModule.def(py::init<>());

// Fields

// Methods
cls_RWStepAP214_GeneralModule.def("FillSharedCase", (void (RWStepAP214_GeneralModule::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, Interface_EntityIterator &) const) &RWStepAP214_GeneralModule::FillSharedCase, "Specific filling of the list of Entities shared by an Entity <ent>, according to a Case Number <CN> (provided by StepAP214 Protocol).", py::arg("CN"), py::arg("ent"), py::arg("iter"));
cls_RWStepAP214_GeneralModule.def("CheckCase", (void (RWStepAP214_GeneralModule::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const) &RWStepAP214_GeneralModule::CheckCase, "Specific Checking of an Entity <ent>", py::arg("CN"), py::arg("ent"), py::arg("shares"), py::arg("ach"));
cls_RWStepAP214_GeneralModule.def("CopyCase", (void (RWStepAP214_GeneralModule::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const opencascade::handle<Standard_Transient> &, Interface_CopyTool &) const) &RWStepAP214_GeneralModule::CopyCase, "Specific Copy ('Deep') from <entfrom> to <entto> (same type) by using a CopyTool which provides its working Map. Use method Transferred from CopyTool to work", py::arg("CN"), py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_RWStepAP214_GeneralModule.def("NewVoid", (Standard_Boolean (RWStepAP214_GeneralModule::*)(const Standard_Integer, opencascade::handle<Standard_Transient> &) const) &RWStepAP214_GeneralModule::NewVoid, "None", py::arg("CN"), py::arg("ent"));
cls_RWStepAP214_GeneralModule.def("CategoryNumber", (Standard_Integer (RWStepAP214_GeneralModule::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const Interface_ShareTool &) const) &RWStepAP214_GeneralModule::CategoryNumber, "None", py::arg("CN"), py::arg("ent"), py::arg("shares"));
cls_RWStepAP214_GeneralModule.def("Name", (opencascade::handle<TCollection_HAsciiString> (RWStepAP214_GeneralModule::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const Interface_ShareTool &) const) &RWStepAP214_GeneralModule::Name, "Returns the name of a STEP Entity according to its type", py::arg("CN"), py::arg("ent"), py::arg("shares"));
cls_RWStepAP214_GeneralModule.def_static("get_type_name_", (const char * (*)()) &RWStepAP214_GeneralModule::get_type_name, "None");
cls_RWStepAP214_GeneralModule.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &RWStepAP214_GeneralModule::get_type_descriptor, "None");
cls_RWStepAP214_GeneralModule.def("DynamicType", (const opencascade::handle<Standard_Type> & (RWStepAP214_GeneralModule::*)() const) &RWStepAP214_GeneralModule::DynamicType, "None");

// Enums

}