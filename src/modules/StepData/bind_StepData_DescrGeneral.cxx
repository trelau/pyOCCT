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
#include <Standard_Handle.hxx>
#include <StepData_Protocol.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Transient.hxx>
#include <Interface_EntityIterator.hxx>
#include <Interface_ShareTool.hxx>
#include <Interface_Check.hxx>
#include <Interface_CopyTool.hxx>
#include <StepData_DescrGeneral.hxx>
#include <Standard_Type.hxx>

void bind_StepData_DescrGeneral(py::module &mod){

py::class_<StepData_DescrGeneral, opencascade::handle<StepData_DescrGeneral>, StepData_GeneralModule> cls_StepData_DescrGeneral(mod, "StepData_DescrGeneral", "Works with a Protocol by considering its entity descriptions");

// Constructors
cls_StepData_DescrGeneral.def(py::init<const opencascade::handle<StepData_Protocol> &>(), py::arg("proto"));

// Fields

// Methods
cls_StepData_DescrGeneral.def("FillSharedCase", (void (StepData_DescrGeneral::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, Interface_EntityIterator &) const) &StepData_DescrGeneral::FillSharedCase, "None", py::arg("CN"), py::arg("ent"), py::arg("iter"));
cls_StepData_DescrGeneral.def("CheckCase", (void (StepData_DescrGeneral::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const) &StepData_DescrGeneral::CheckCase, "None", py::arg("CN"), py::arg("ent"), py::arg("shares"), py::arg("ach"));
cls_StepData_DescrGeneral.def("CopyCase", (void (StepData_DescrGeneral::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const opencascade::handle<Standard_Transient> &, Interface_CopyTool &) const) &StepData_DescrGeneral::CopyCase, "None", py::arg("CN"), py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_StepData_DescrGeneral.def("NewVoid", (Standard_Boolean (StepData_DescrGeneral::*)(const Standard_Integer, opencascade::handle<Standard_Transient> &) const) &StepData_DescrGeneral::NewVoid, "None", py::arg("CN"), py::arg("ent"));
cls_StepData_DescrGeneral.def_static("get_type_name_", (const char * (*)()) &StepData_DescrGeneral::get_type_name, "None");
cls_StepData_DescrGeneral.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepData_DescrGeneral::get_type_descriptor, "None");
cls_StepData_DescrGeneral.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepData_DescrGeneral::*)() const) &StepData_DescrGeneral::DynamicType, "None");

// Enums

}