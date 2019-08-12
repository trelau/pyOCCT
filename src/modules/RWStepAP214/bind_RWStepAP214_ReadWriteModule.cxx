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
#include <StepData_ReadWriteModule.hxx>
#include <Standard_TypeDef.hxx>
#include <TCollection_AsciiString.hxx>
#include <TColStd_SequenceOfAsciiString.hxx>
#include <Standard_Handle.hxx>
#include <StepData_StepReaderData.hxx>
#include <Interface_Check.hxx>
#include <Standard_Transient.hxx>
#include <StepData_StepWriter.hxx>
#include <RWStepAP214_ReadWriteModule.hxx>
#include <Standard_Type.hxx>

void bind_RWStepAP214_ReadWriteModule(py::module &mod){

py::class_<RWStepAP214_ReadWriteModule, opencascade::handle<RWStepAP214_ReadWriteModule>, StepData_ReadWriteModule> cls_RWStepAP214_ReadWriteModule(mod, "RWStepAP214_ReadWriteModule", "General module to read and write StepAP214 entities");

// Constructors
cls_RWStepAP214_ReadWriteModule.def(py::init<>());

// Fields

// Methods
cls_RWStepAP214_ReadWriteModule.def("CaseStep", (Standard_Integer (RWStepAP214_ReadWriteModule::*)(const TCollection_AsciiString &) const) &RWStepAP214_ReadWriteModule::CaseStep, "associates a positive Case Number to each type of StepAP214 entity, given as a String defined in the EXPRESS form", py::arg("atype"));
cls_RWStepAP214_ReadWriteModule.def("CaseStep", (Standard_Integer (RWStepAP214_ReadWriteModule::*)(const TColStd_SequenceOfAsciiString &) const) &RWStepAP214_ReadWriteModule::CaseStep, "associates a positive Case Number to each type of StepAP214 Complex entity, given as a String defined in the EXPRESS form", py::arg("types"));
cls_RWStepAP214_ReadWriteModule.def("IsComplex", (Standard_Boolean (RWStepAP214_ReadWriteModule::*)(const Standard_Integer) const) &RWStepAP214_ReadWriteModule::IsComplex, "returns True if the Case Number corresponds to a Complex Type", py::arg("CN"));
cls_RWStepAP214_ReadWriteModule.def("StepType", (const TCollection_AsciiString & (RWStepAP214_ReadWriteModule::*)(const Standard_Integer) const) &RWStepAP214_ReadWriteModule::StepType, "returns a StepType (defined in EXPRESS form which belongs to a Type of Entity, identified by its CaseNumber determined by Protocol", py::arg("CN"));
cls_RWStepAP214_ReadWriteModule.def("ComplexType", (Standard_Boolean (RWStepAP214_ReadWriteModule::*)(const Standard_Integer, TColStd_SequenceOfAsciiString &) const) &RWStepAP214_ReadWriteModule::ComplexType, "None", py::arg("CN"), py::arg("types"));
cls_RWStepAP214_ReadWriteModule.def("ReadStep", (void (RWStepAP214_ReadWriteModule::*)(const Standard_Integer, const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<Standard_Transient> &) const) &RWStepAP214_ReadWriteModule::ReadStep, "None", py::arg("CN"), py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepAP214_ReadWriteModule.def("WriteStep", (void (RWStepAP214_ReadWriteModule::*)(const Standard_Integer, StepData_StepWriter &, const opencascade::handle<Standard_Transient> &) const) &RWStepAP214_ReadWriteModule::WriteStep, "None", py::arg("CN"), py::arg("SW"), py::arg("ent"));
cls_RWStepAP214_ReadWriteModule.def_static("get_type_name_", (const char * (*)()) &RWStepAP214_ReadWriteModule::get_type_name, "None");
cls_RWStepAP214_ReadWriteModule.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &RWStepAP214_ReadWriteModule::get_type_descriptor, "None");
cls_RWStepAP214_ReadWriteModule.def("DynamicType", (const opencascade::handle<Standard_Type> & (RWStepAP214_ReadWriteModule::*)() const) &RWStepAP214_ReadWriteModule::DynamicType, "None");

// Enums

}