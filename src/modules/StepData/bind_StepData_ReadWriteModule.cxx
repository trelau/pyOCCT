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
#include <Interface_ReaderModule.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Interface_FileReaderData.hxx>
#include <TCollection_AsciiString.hxx>
#include <TColStd_SequenceOfAsciiString.hxx>
#include <Interface_Check.hxx>
#include <Standard_Transient.hxx>
#include <StepData_StepReaderData.hxx>
#include <StepData_StepWriter.hxx>
#include <StepData_ReadWriteModule.hxx>
#include <Standard_Type.hxx>

void bind_StepData_ReadWriteModule(py::module &mod){

py::class_<StepData_ReadWriteModule, opencascade::handle<StepData_ReadWriteModule>, Interface_ReaderModule> cls_StepData_ReadWriteModule(mod, "StepData_ReadWriteModule", "Defines basic File Access Module (Recognize, Read, Write) That is : ReaderModule (Recognize & Read) + Write for StepWriter (for a more centralized description) Warning : A sub-class of ReadWriteModule, which belongs to a particular Protocol, must use the same definition for Case Numbers (give the same Value for a StepType defined as a String from a File as the Protocol does for the corresponding Entity)");

// Fields

// Methods
cls_StepData_ReadWriteModule.def("CaseNum", (Standard_Integer (StepData_ReadWriteModule::*)(const opencascade::handle<Interface_FileReaderData> &, const Standard_Integer) const) &StepData_ReadWriteModule::CaseNum, "Translate the Type of record <num> in <data> to a positive Case Number, or 0 if failed. Works with a StepReaderData, in which the Type of an Entity is defined as a String : Reads the RecordType <num> then calls CaseNum (this type) Warning : The methods CaseStep, StepType and Recognize, must be in phase (triplets CaseNum-StepType-Type of Object)", py::arg("data"), py::arg("num"));
cls_StepData_ReadWriteModule.def("CaseStep", (Standard_Integer (StepData_ReadWriteModule::*)(const TCollection_AsciiString &) const) &StepData_ReadWriteModule::CaseStep, "Defines Case Numbers corresponding to the recognized Types Called by CaseNum (data,num) above for a Simple Type Entity Warning : CaseStep must give the same Value as Protocol does for the Entity type which corresponds to this Type given as a String", py::arg("atype"));
cls_StepData_ReadWriteModule.def("CaseStep", (Standard_Integer (StepData_ReadWriteModule::*)(const TColStd_SequenceOfAsciiString &) const) &StepData_ReadWriteModule::CaseStep, "Same a above but for a Complex Type Entity ('Plex') The provided Default recognizes nothing", py::arg("types"));
cls_StepData_ReadWriteModule.def("IsComplex", (Standard_Boolean (StepData_ReadWriteModule::*)(const Standard_Integer) const) &StepData_ReadWriteModule::IsComplex, "Returns True if the Case Number corresponds to a Complex Type ('Plex'). Remember that all possible combinations must be aknowledged to be processed Default is False for all cases. For a Protocol which defines possible Plexes, this method must be redefined.", py::arg("CN"));
cls_StepData_ReadWriteModule.def("StepType", (const TCollection_AsciiString & (StepData_ReadWriteModule::*)(const Standard_Integer) const) &StepData_ReadWriteModule::StepType, "Function specific to STEP, which delivers the StepType as it is recorded in and read from a File compliant with STEP. This method is symmetric to the method CaseStep. StepType can be different from Dynamic Type's name, but belongs to the same class of Object. Returns an empty String if <CN> is zero. Warning : For a Complex Type Entity, returns an Empty String (Complex Type must be managed by users)", py::arg("CN"));
cls_StepData_ReadWriteModule.def("ShortType", (TCollection_AsciiString (StepData_ReadWriteModule::*)(const Standard_Integer) const) &StepData_ReadWriteModule::ShortType, "Function specific to STEP. Some STEP Types have a short form This method can be redefined to fill it By default, returns an empty string, which is then interpreted to take normal form from StepType", py::arg("CN"));
cls_StepData_ReadWriteModule.def("ComplexType", (Standard_Boolean (StepData_ReadWriteModule::*)(const Standard_Integer, TColStd_SequenceOfAsciiString &) const) &StepData_ReadWriteModule::ComplexType, "Function specific to STEP, which delivers the list of types which corresponds to a complex type. If <CN> is not for a complex type, this method returns False. Else it returns True and fills the list in alphabetic order. The default returns False. To be redefined as required.", py::arg("CN"), py::arg("types"));
cls_StepData_ReadWriteModule.def("Read", (void (StepData_ReadWriteModule::*)(const Standard_Integer, const opencascade::handle<Interface_FileReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<Standard_Transient> &) const) &StepData_ReadWriteModule::Read, "General Read Function, calls ReadStep", py::arg("CN"), py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_StepData_ReadWriteModule.def("ReadStep", (void (StepData_ReadWriteModule::*)(const Standard_Integer, const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<Standard_Transient> &) const) &StepData_ReadWriteModule::ReadStep, "Specific Read Function. Works with StepReaderData", py::arg("CN"), py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_StepData_ReadWriteModule.def("WriteStep", (void (StepData_ReadWriteModule::*)(const Standard_Integer, StepData_StepWriter &, const opencascade::handle<Standard_Transient> &) const) &StepData_ReadWriteModule::WriteStep, "Write Function, switched by CaseNum", py::arg("CN"), py::arg("SW"), py::arg("ent"));
cls_StepData_ReadWriteModule.def_static("get_type_name_", (const char * (*)()) &StepData_ReadWriteModule::get_type_name, "None");
cls_StepData_ReadWriteModule.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepData_ReadWriteModule::get_type_descriptor, "None");
cls_StepData_ReadWriteModule.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepData_ReadWriteModule::*)() const) &StepData_ReadWriteModule::DynamicType, "None");

// Enums

}