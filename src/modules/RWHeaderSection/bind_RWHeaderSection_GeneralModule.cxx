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
#include <RWHeaderSection_GeneralModule.hxx>
#include <Standard_Type.hxx>

void bind_RWHeaderSection_GeneralModule(py::module &mod){

py::class_<RWHeaderSection_GeneralModule, opencascade::handle<RWHeaderSection_GeneralModule>, StepData_GeneralModule> cls_RWHeaderSection_GeneralModule(mod, "RWHeaderSection_GeneralModule", "Defines General Services for HeaderSection Entities (Share,Check,Copy; Trace already inherited) Depends (for case numbers) of Protocol from HeaderSection");

// Constructors
cls_RWHeaderSection_GeneralModule.def(py::init<>());

// Fields

// Methods
cls_RWHeaderSection_GeneralModule.def("FillSharedCase", (void (RWHeaderSection_GeneralModule::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, Interface_EntityIterator &) const) &RWHeaderSection_GeneralModule::FillSharedCase, "Specific filling of the list of Entities shared by an Entity <ent>, according to a Case Number <CN> (provided by HeaderSection Protocol).", py::arg("CN"), py::arg("ent"), py::arg("iter"));
cls_RWHeaderSection_GeneralModule.def("CheckCase", (void (RWHeaderSection_GeneralModule::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const) &RWHeaderSection_GeneralModule::CheckCase, "Specific Checking of an Entity <ent>", py::arg("CN"), py::arg("ent"), py::arg("shares"), py::arg("ach"));
cls_RWHeaderSection_GeneralModule.def("CopyCase", (void (RWHeaderSection_GeneralModule::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const opencascade::handle<Standard_Transient> &, Interface_CopyTool &) const) &RWHeaderSection_GeneralModule::CopyCase, "Specific Copy ('Deep') from <entfrom> to <entto> (same type) by using a CopyTool which provides its working Map. Use method Transferred from CopyTool to work", py::arg("CN"), py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_RWHeaderSection_GeneralModule.def("NewVoid", (Standard_Boolean (RWHeaderSection_GeneralModule::*)(const Standard_Integer, opencascade::handle<Standard_Transient> &) const) &RWHeaderSection_GeneralModule::NewVoid, "None", py::arg("CN"), py::arg("ent"));
cls_RWHeaderSection_GeneralModule.def_static("get_type_name_", (const char * (*)()) &RWHeaderSection_GeneralModule::get_type_name, "None");
cls_RWHeaderSection_GeneralModule.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &RWHeaderSection_GeneralModule::get_type_descriptor, "None");
cls_RWHeaderSection_GeneralModule.def("DynamicType", (const opencascade::handle<Standard_Type> & (RWHeaderSection_GeneralModule::*)() const) &RWHeaderSection_GeneralModule::DynamicType, "None");

// Enums

}