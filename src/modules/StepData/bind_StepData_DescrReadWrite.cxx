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
#include <Standard_Handle.hxx>
#include <StepData_Protocol.hxx>
#include <Standard_TypeDef.hxx>
#include <TCollection_AsciiString.hxx>
#include <TColStd_SequenceOfAsciiString.hxx>
#include <StepData_StepReaderData.hxx>
#include <Interface_Check.hxx>
#include <Standard_Transient.hxx>
#include <StepData_StepWriter.hxx>
#include <StepData_DescrReadWrite.hxx>
#include <Standard_Type.hxx>

void bind_StepData_DescrReadWrite(py::module &mod){

py::class_<StepData_DescrReadWrite, opencascade::handle<StepData_DescrReadWrite>, StepData_ReadWriteModule> cls_StepData_DescrReadWrite(mod, "StepData_DescrReadWrite", "None");

// Constructors
cls_StepData_DescrReadWrite.def(py::init<const opencascade::handle<StepData_Protocol> &>(), py::arg("proto"));

// Fields

// Methods
cls_StepData_DescrReadWrite.def("CaseStep", (Standard_Integer (StepData_DescrReadWrite::*)(const TCollection_AsciiString &) const) &StepData_DescrReadWrite::CaseStep, "None", py::arg("atype"));
cls_StepData_DescrReadWrite.def("CaseStep", (Standard_Integer (StepData_DescrReadWrite::*)(const TColStd_SequenceOfAsciiString &) const) &StepData_DescrReadWrite::CaseStep, "None", py::arg("types"));
cls_StepData_DescrReadWrite.def("IsComplex", (Standard_Boolean (StepData_DescrReadWrite::*)(const Standard_Integer) const) &StepData_DescrReadWrite::IsComplex, "None", py::arg("CN"));
cls_StepData_DescrReadWrite.def("StepType", (const TCollection_AsciiString & (StepData_DescrReadWrite::*)(const Standard_Integer) const) &StepData_DescrReadWrite::StepType, "None", py::arg("CN"));
cls_StepData_DescrReadWrite.def("ComplexType", (Standard_Boolean (StepData_DescrReadWrite::*)(const Standard_Integer, TColStd_SequenceOfAsciiString &) const) &StepData_DescrReadWrite::ComplexType, "None", py::arg("CN"), py::arg("types"));
cls_StepData_DescrReadWrite.def("ReadStep", (void (StepData_DescrReadWrite::*)(const Standard_Integer, const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<Standard_Transient> &) const) &StepData_DescrReadWrite::ReadStep, "None", py::arg("CN"), py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_StepData_DescrReadWrite.def("WriteStep", (void (StepData_DescrReadWrite::*)(const Standard_Integer, StepData_StepWriter &, const opencascade::handle<Standard_Transient> &) const) &StepData_DescrReadWrite::WriteStep, "None", py::arg("CN"), py::arg("SW"), py::arg("ent"));
cls_StepData_DescrReadWrite.def_static("get_type_name_", (const char * (*)()) &StepData_DescrReadWrite::get_type_name, "None");
cls_StepData_DescrReadWrite.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepData_DescrReadWrite::get_type_descriptor, "None");
cls_StepData_DescrReadWrite.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepData_DescrReadWrite::*)() const) &StepData_DescrReadWrite::DynamicType, "None");

// Enums

}