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
#include <RWHeaderSection_ReadWriteModule.hxx>
#include <Standard_Type.hxx>

void bind_RWHeaderSection_ReadWriteModule(py::module &mod){

py::class_<RWHeaderSection_ReadWriteModule, opencascade::handle<RWHeaderSection_ReadWriteModule>, StepData_ReadWriteModule> cls_RWHeaderSection_ReadWriteModule(mod, "RWHeaderSection_ReadWriteModule", "General module to read and write HeaderSection entities");

// Constructors
cls_RWHeaderSection_ReadWriteModule.def(py::init<>());

// Fields

// Methods
cls_RWHeaderSection_ReadWriteModule.def("CaseStep", (Standard_Integer (RWHeaderSection_ReadWriteModule::*)(const TCollection_AsciiString &) const) &RWHeaderSection_ReadWriteModule::CaseStep, "associates a positive Case Number to each type of HeaderSection entity, given as a String defined in the EXPRESS form", py::arg("atype"));
cls_RWHeaderSection_ReadWriteModule.def("CaseStep", (Standard_Integer (RWHeaderSection_ReadWriteModule::*)(const TColStd_SequenceOfAsciiString &) const) &RWHeaderSection_ReadWriteModule::CaseStep, "associates a positive Case Number to each type of HeaderSection Complex entity, given as a String defined in the EXPRESS form", py::arg("types"));
cls_RWHeaderSection_ReadWriteModule.def("IsComplex", (Standard_Boolean (RWHeaderSection_ReadWriteModule::*)(const Standard_Integer) const) &RWHeaderSection_ReadWriteModule::IsComplex, "returns True if the Case Number corresponds to a Complex Type", py::arg("CN"));
cls_RWHeaderSection_ReadWriteModule.def("StepType", (const TCollection_AsciiString & (RWHeaderSection_ReadWriteModule::*)(const Standard_Integer) const) &RWHeaderSection_ReadWriteModule::StepType, "returns a StepType (defined in EXPRESS form which belongs to a Type of Entity, identified by its CaseNumber determined by Protocol", py::arg("CN"));
cls_RWHeaderSection_ReadWriteModule.def("ReadStep", (void (RWHeaderSection_ReadWriteModule::*)(const Standard_Integer, const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<Standard_Transient> &) const) &RWHeaderSection_ReadWriteModule::ReadStep, "None", py::arg("CN"), py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWHeaderSection_ReadWriteModule.def("WriteStep", (void (RWHeaderSection_ReadWriteModule::*)(const Standard_Integer, StepData_StepWriter &, const opencascade::handle<Standard_Transient> &) const) &RWHeaderSection_ReadWriteModule::WriteStep, "None", py::arg("CN"), py::arg("SW"), py::arg("ent"));
cls_RWHeaderSection_ReadWriteModule.def_static("get_type_name_", (const char * (*)()) &RWHeaderSection_ReadWriteModule::get_type_name, "None");
cls_RWHeaderSection_ReadWriteModule.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &RWHeaderSection_ReadWriteModule::get_type_descriptor, "None");
cls_RWHeaderSection_ReadWriteModule.def("DynamicType", (const opencascade::handle<Standard_Type> & (RWHeaderSection_ReadWriteModule::*)() const) &RWHeaderSection_ReadWriteModule::DynamicType, "None");

// Enums

}