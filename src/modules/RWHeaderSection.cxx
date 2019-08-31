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
#include <Standard.hxx>
#include <RWHeaderSection_ReadWriteModule.hxx>
#include <RWHeaderSection_GeneralModule.hxx>
#include <RWHeaderSection_RWFileName.hxx>
#include <RWHeaderSection_RWFileDescription.hxx>
#include <RWHeaderSection_RWFileSchema.hxx>
#include <RWHeaderSection.hxx>
#include <StepData_GeneralModule.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Transient.hxx>
#include <Interface_EntityIterator.hxx>
#include <Interface_ShareTool.hxx>
#include <Interface_Check.hxx>
#include <Interface_CopyTool.hxx>
#include <Standard_Type.hxx>
#include <StepData_ReadWriteModule.hxx>
#include <TCollection_AsciiString.hxx>
#include <TColStd_SequenceOfAsciiString.hxx>
#include <StepData_StepReaderData.hxx>
#include <StepData_StepWriter.hxx>
#include <HeaderSection_FileDescription.hxx>
#include <HeaderSection_FileName.hxx>
#include <HeaderSection_FileSchema.hxx>

PYBIND11_MODULE(RWHeaderSection, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.StepData");
py::module::import("OCCT.Interface");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.HeaderSection");

// CLASS: RWHEADERSECTION
py::class_<RWHeaderSection> cls_RWHeaderSection(mod, "RWHeaderSection", "None");

// Methods
// cls_RWHeaderSection.def_static("operator new_", (void * (*)(size_t)) &RWHeaderSection::operator new, "None", py::arg("theSize"));
// cls_RWHeaderSection.def_static("operator delete_", (void (*)(void *)) &RWHeaderSection::operator delete, "None", py::arg("theAddress"));
// cls_RWHeaderSection.def_static("operator new[]_", (void * (*)(size_t)) &RWHeaderSection::operator new[], "None", py::arg("theSize"));
// cls_RWHeaderSection.def_static("operator delete[]_", (void (*)(void *)) &RWHeaderSection::operator delete[], "None", py::arg("theAddress"));
// cls_RWHeaderSection.def_static("operator new_", (void * (*)(size_t, void *)) &RWHeaderSection::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWHeaderSection.def_static("operator delete_", (void (*)(void *, void *)) &RWHeaderSection::operator delete, "None", py::arg(""), py::arg(""));
cls_RWHeaderSection.def_static("Init_", (void (*)()) &RWHeaderSection::Init, "enforced the initialisation of the libraries");

// CLASS: RWHEADERSECTION_GENERALMODULE
py::class_<RWHeaderSection_GeneralModule, opencascade::handle<RWHeaderSection_GeneralModule>, StepData_GeneralModule> cls_RWHeaderSection_GeneralModule(mod, "RWHeaderSection_GeneralModule", "Defines General Services for HeaderSection Entities (Share,Check,Copy; Trace already inherited) Depends (for case numbers) of Protocol from HeaderSection");

// Constructors
cls_RWHeaderSection_GeneralModule.def(py::init<>());

// Methods
cls_RWHeaderSection_GeneralModule.def("FillSharedCase", (void (RWHeaderSection_GeneralModule::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, Interface_EntityIterator &) const) &RWHeaderSection_GeneralModule::FillSharedCase, "Specific filling of the list of Entities shared by an Entity <ent>, according to a Case Number <CN> (provided by HeaderSection Protocol).", py::arg("CN"), py::arg("ent"), py::arg("iter"));
cls_RWHeaderSection_GeneralModule.def("CheckCase", (void (RWHeaderSection_GeneralModule::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const) &RWHeaderSection_GeneralModule::CheckCase, "Specific Checking of an Entity <ent>", py::arg("CN"), py::arg("ent"), py::arg("shares"), py::arg("ach"));
cls_RWHeaderSection_GeneralModule.def("CopyCase", (void (RWHeaderSection_GeneralModule::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const opencascade::handle<Standard_Transient> &, Interface_CopyTool &) const) &RWHeaderSection_GeneralModule::CopyCase, "Specific Copy ('Deep') from <entfrom> to <entto> (same type) by using a CopyTool which provides its working Map. Use method Transferred from CopyTool to work", py::arg("CN"), py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_RWHeaderSection_GeneralModule.def("NewVoid", (Standard_Boolean (RWHeaderSection_GeneralModule::*)(const Standard_Integer, opencascade::handle<Standard_Transient> &) const) &RWHeaderSection_GeneralModule::NewVoid, "None", py::arg("CN"), py::arg("ent"));
cls_RWHeaderSection_GeneralModule.def_static("get_type_name_", (const char * (*)()) &RWHeaderSection_GeneralModule::get_type_name, "None");
cls_RWHeaderSection_GeneralModule.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &RWHeaderSection_GeneralModule::get_type_descriptor, "None");
cls_RWHeaderSection_GeneralModule.def("DynamicType", (const opencascade::handle<Standard_Type> & (RWHeaderSection_GeneralModule::*)() const) &RWHeaderSection_GeneralModule::DynamicType, "None");

// CLASS: RWHEADERSECTION_READWRITEMODULE
py::class_<RWHeaderSection_ReadWriteModule, opencascade::handle<RWHeaderSection_ReadWriteModule>, StepData_ReadWriteModule> cls_RWHeaderSection_ReadWriteModule(mod, "RWHeaderSection_ReadWriteModule", "General module to read and write HeaderSection entities");

// Constructors
cls_RWHeaderSection_ReadWriteModule.def(py::init<>());

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

// CLASS: RWHEADERSECTION_RWFILEDESCRIPTION
py::class_<RWHeaderSection_RWFileDescription> cls_RWHeaderSection_RWFileDescription(mod, "RWHeaderSection_RWFileDescription", "Read & Write Module for FileDescription");

// Constructors
cls_RWHeaderSection_RWFileDescription.def(py::init<>());

// Methods
// cls_RWHeaderSection_RWFileDescription.def_static("operator new_", (void * (*)(size_t)) &RWHeaderSection_RWFileDescription::operator new, "None", py::arg("theSize"));
// cls_RWHeaderSection_RWFileDescription.def_static("operator delete_", (void (*)(void *)) &RWHeaderSection_RWFileDescription::operator delete, "None", py::arg("theAddress"));
// cls_RWHeaderSection_RWFileDescription.def_static("operator new[]_", (void * (*)(size_t)) &RWHeaderSection_RWFileDescription::operator new[], "None", py::arg("theSize"));
// cls_RWHeaderSection_RWFileDescription.def_static("operator delete[]_", (void (*)(void *)) &RWHeaderSection_RWFileDescription::operator delete[], "None", py::arg("theAddress"));
// cls_RWHeaderSection_RWFileDescription.def_static("operator new_", (void * (*)(size_t, void *)) &RWHeaderSection_RWFileDescription::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWHeaderSection_RWFileDescription.def_static("operator delete_", (void (*)(void *, void *)) &RWHeaderSection_RWFileDescription::operator delete, "None", py::arg(""), py::arg(""));
cls_RWHeaderSection_RWFileDescription.def("ReadStep", (void (RWHeaderSection_RWFileDescription::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<HeaderSection_FileDescription> &) const) &RWHeaderSection_RWFileDescription::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWHeaderSection_RWFileDescription.def("WriteStep", (void (RWHeaderSection_RWFileDescription::*)(StepData_StepWriter &, const opencascade::handle<HeaderSection_FileDescription> &) const) &RWHeaderSection_RWFileDescription::WriteStep, "None", py::arg("SW"), py::arg("ent"));

// CLASS: RWHEADERSECTION_RWFILENAME
py::class_<RWHeaderSection_RWFileName> cls_RWHeaderSection_RWFileName(mod, "RWHeaderSection_RWFileName", "Read & Write Module for FileName");

// Constructors
cls_RWHeaderSection_RWFileName.def(py::init<>());

// Methods
// cls_RWHeaderSection_RWFileName.def_static("operator new_", (void * (*)(size_t)) &RWHeaderSection_RWFileName::operator new, "None", py::arg("theSize"));
// cls_RWHeaderSection_RWFileName.def_static("operator delete_", (void (*)(void *)) &RWHeaderSection_RWFileName::operator delete, "None", py::arg("theAddress"));
// cls_RWHeaderSection_RWFileName.def_static("operator new[]_", (void * (*)(size_t)) &RWHeaderSection_RWFileName::operator new[], "None", py::arg("theSize"));
// cls_RWHeaderSection_RWFileName.def_static("operator delete[]_", (void (*)(void *)) &RWHeaderSection_RWFileName::operator delete[], "None", py::arg("theAddress"));
// cls_RWHeaderSection_RWFileName.def_static("operator new_", (void * (*)(size_t, void *)) &RWHeaderSection_RWFileName::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWHeaderSection_RWFileName.def_static("operator delete_", (void (*)(void *, void *)) &RWHeaderSection_RWFileName::operator delete, "None", py::arg(""), py::arg(""));
cls_RWHeaderSection_RWFileName.def("ReadStep", (void (RWHeaderSection_RWFileName::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<HeaderSection_FileName> &) const) &RWHeaderSection_RWFileName::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWHeaderSection_RWFileName.def("WriteStep", (void (RWHeaderSection_RWFileName::*)(StepData_StepWriter &, const opencascade::handle<HeaderSection_FileName> &) const) &RWHeaderSection_RWFileName::WriteStep, "None", py::arg("SW"), py::arg("ent"));

// CLASS: RWHEADERSECTION_RWFILESCHEMA
py::class_<RWHeaderSection_RWFileSchema> cls_RWHeaderSection_RWFileSchema(mod, "RWHeaderSection_RWFileSchema", "Read & Write Module for FileSchema");

// Constructors
cls_RWHeaderSection_RWFileSchema.def(py::init<>());

// Methods
// cls_RWHeaderSection_RWFileSchema.def_static("operator new_", (void * (*)(size_t)) &RWHeaderSection_RWFileSchema::operator new, "None", py::arg("theSize"));
// cls_RWHeaderSection_RWFileSchema.def_static("operator delete_", (void (*)(void *)) &RWHeaderSection_RWFileSchema::operator delete, "None", py::arg("theAddress"));
// cls_RWHeaderSection_RWFileSchema.def_static("operator new[]_", (void * (*)(size_t)) &RWHeaderSection_RWFileSchema::operator new[], "None", py::arg("theSize"));
// cls_RWHeaderSection_RWFileSchema.def_static("operator delete[]_", (void (*)(void *)) &RWHeaderSection_RWFileSchema::operator delete[], "None", py::arg("theAddress"));
// cls_RWHeaderSection_RWFileSchema.def_static("operator new_", (void * (*)(size_t, void *)) &RWHeaderSection_RWFileSchema::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWHeaderSection_RWFileSchema.def_static("operator delete_", (void (*)(void *, void *)) &RWHeaderSection_RWFileSchema::operator delete, "None", py::arg(""), py::arg(""));
cls_RWHeaderSection_RWFileSchema.def("ReadStep", (void (RWHeaderSection_RWFileSchema::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<HeaderSection_FileSchema> &) const) &RWHeaderSection_RWFileSchema::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWHeaderSection_RWFileSchema.def("WriteStep", (void (RWHeaderSection_RWFileSchema::*)(StepData_StepWriter &, const opencascade::handle<HeaderSection_FileSchema> &) const) &RWHeaderSection_RWFileSchema::WriteStep, "None", py::arg("SW"), py::arg("ent"));


}
