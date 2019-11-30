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
#include <RWStepAP214_ReadWriteModule.hxx>
#include <RWStepAP214_GeneralModule.hxx>
#include <RWStepAP214_RWAutoDesignActualDateAndTimeAssignment.hxx>
#include <RWStepAP214_RWAutoDesignActualDateAssignment.hxx>
#include <RWStepAP214_RWAutoDesignApprovalAssignment.hxx>
#include <RWStepAP214_RWAutoDesignDateAndPersonAssignment.hxx>
#include <RWStepAP214_RWAutoDesignGroupAssignment.hxx>
#include <RWStepAP214_RWAutoDesignNominalDateAndTimeAssignment.hxx>
#include <RWStepAP214_RWAutoDesignNominalDateAssignment.hxx>
#include <RWStepAP214_RWAutoDesignOrganizationAssignment.hxx>
#include <RWStepAP214_RWAutoDesignPersonAndOrganizationAssignment.hxx>
#include <RWStepAP214_RWAutoDesignPresentedItem.hxx>
#include <RWStepAP214_RWAutoDesignSecurityClassificationAssignment.hxx>
#include <RWStepAP214_RWAutoDesignDocumentReference.hxx>
#include <RWStepAP214_RWAppliedDateAndTimeAssignment.hxx>
#include <RWStepAP214_RWAppliedDateAssignment.hxx>
#include <RWStepAP214_RWAppliedApprovalAssignment.hxx>
#include <RWStepAP214_RWAppliedGroupAssignment.hxx>
#include <RWStepAP214_RWAppliedOrganizationAssignment.hxx>
#include <RWStepAP214_RWAppliedPersonAndOrganizationAssignment.hxx>
#include <RWStepAP214_RWAppliedPresentedItem.hxx>
#include <RWStepAP214_RWAppliedSecurityClassificationAssignment.hxx>
#include <RWStepAP214_RWAppliedDocumentReference.hxx>
#include <RWStepAP214_RWAppliedExternalIdentificationAssignment.hxx>
#include <RWStepAP214_RWClass.hxx>
#include <RWStepAP214_RWExternallyDefinedClass.hxx>
#include <RWStepAP214_RWExternallyDefinedGeneralProperty.hxx>
#include <RWStepAP214_RWRepItemGroup.hxx>
#include <RWStepAP214.hxx>
#include <StepData_GeneralModule.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Transient.hxx>
#include <Interface_EntityIterator.hxx>
#include <Interface_ShareTool.hxx>
#include <Interface_Check.hxx>
#include <Interface_CopyTool.hxx>
#include <TCollection_HAsciiString.hxx>
#include <Standard_Std.hxx>
#include <Standard_Type.hxx>
#include <StepData_ReadWriteModule.hxx>
#include <TCollection_AsciiString.hxx>
#include <TColStd_SequenceOfAsciiString.hxx>
#include <StepData_StepReaderData.hxx>
#include <StepData_StepWriter.hxx>
#include <StepAP214_AppliedApprovalAssignment.hxx>
#include <StepAP214_AppliedDateAndTimeAssignment.hxx>
#include <StepAP214_AppliedDateAssignment.hxx>
#include <StepAP214_AppliedDocumentReference.hxx>
#include <StepAP214_AppliedExternalIdentificationAssignment.hxx>
#include <StepAP214_AppliedGroupAssignment.hxx>
#include <StepAP214_AppliedOrganizationAssignment.hxx>
#include <StepAP214_AppliedPersonAndOrganizationAssignment.hxx>
#include <StepAP214_AppliedPresentedItem.hxx>
#include <StepAP214_AppliedSecurityClassificationAssignment.hxx>
#include <StepAP214_AutoDesignActualDateAndTimeAssignment.hxx>
#include <StepAP214_AutoDesignActualDateAssignment.hxx>
#include <StepAP214_AutoDesignApprovalAssignment.hxx>
#include <StepAP214_AutoDesignDateAndPersonAssignment.hxx>
#include <StepAP214_AutoDesignDocumentReference.hxx>
#include <StepAP214_AutoDesignGroupAssignment.hxx>
#include <StepAP214_AutoDesignNominalDateAndTimeAssignment.hxx>
#include <StepAP214_AutoDesignNominalDateAssignment.hxx>
#include <StepAP214_AutoDesignOrganizationAssignment.hxx>
#include <StepAP214_AutoDesignPersonAndOrganizationAssignment.hxx>
#include <StepAP214_AutoDesignPresentedItem.hxx>
#include <StepAP214_AutoDesignSecurityClassificationAssignment.hxx>
#include <StepAP214_Class.hxx>
#include <StepAP214_ExternallyDefinedClass.hxx>
#include <StepAP214_ExternallyDefinedGeneralProperty.hxx>
#include <StepAP214_RepItemGroup.hxx>

PYBIND11_MODULE(RWStepAP214, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.StepData");
py::module::import("OCCT.Interface");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.StepAP214");

// CLASS: RWSTEPAP214
py::class_<RWStepAP214> cls_RWStepAP214(mod, "RWStepAP214", "None");

// Methods
// cls_RWStepAP214.def_static("operator new_", (void * (*)(size_t)) &RWStepAP214::operator new, "None", py::arg("theSize"));
// cls_RWStepAP214.def_static("operator delete_", (void (*)(void *)) &RWStepAP214::operator delete, "None", py::arg("theAddress"));
// cls_RWStepAP214.def_static("operator new[]_", (void * (*)(size_t)) &RWStepAP214::operator new[], "None", py::arg("theSize"));
// cls_RWStepAP214.def_static("operator delete[]_", (void (*)(void *)) &RWStepAP214::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepAP214.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepAP214::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepAP214.def_static("operator delete_", (void (*)(void *, void *)) &RWStepAP214::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepAP214.def_static("Init_", (void (*)()) &RWStepAP214::Init, "enforced the initialisation of the libraries");

// CLASS: RWSTEPAP214_GENERALMODULE
py::class_<RWStepAP214_GeneralModule, opencascade::handle<RWStepAP214_GeneralModule>, StepData_GeneralModule> cls_RWStepAP214_GeneralModule(mod, "RWStepAP214_GeneralModule", "Defines General Services for StepAP214 Entities (Share,Check,Copy; Trace already inherited) Depends (for case numbers) of Protocol from StepAP214");

// Constructors
cls_RWStepAP214_GeneralModule.def(py::init<>());

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

// CLASS: RWSTEPAP214_READWRITEMODULE
py::class_<RWStepAP214_ReadWriteModule, opencascade::handle<RWStepAP214_ReadWriteModule>, StepData_ReadWriteModule> cls_RWStepAP214_ReadWriteModule(mod, "RWStepAP214_ReadWriteModule", "General module to read and write StepAP214 entities");

// Constructors
cls_RWStepAP214_ReadWriteModule.def(py::init<>());

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

// CLASS: RWSTEPAP214_RWAPPLIEDAPPROVALASSIGNMENT
py::class_<RWStepAP214_RWAppliedApprovalAssignment> cls_RWStepAP214_RWAppliedApprovalAssignment(mod, "RWStepAP214_RWAppliedApprovalAssignment", "Read & Write Module for AppliedApprovalAssignment");

// Constructors
cls_RWStepAP214_RWAppliedApprovalAssignment.def(py::init<>());

// Methods
// cls_RWStepAP214_RWAppliedApprovalAssignment.def_static("operator new_", (void * (*)(size_t)) &RWStepAP214_RWAppliedApprovalAssignment::operator new, "None", py::arg("theSize"));
// cls_RWStepAP214_RWAppliedApprovalAssignment.def_static("operator delete_", (void (*)(void *)) &RWStepAP214_RWAppliedApprovalAssignment::operator delete, "None", py::arg("theAddress"));
// cls_RWStepAP214_RWAppliedApprovalAssignment.def_static("operator new[]_", (void * (*)(size_t)) &RWStepAP214_RWAppliedApprovalAssignment::operator new[], "None", py::arg("theSize"));
// cls_RWStepAP214_RWAppliedApprovalAssignment.def_static("operator delete[]_", (void (*)(void *)) &RWStepAP214_RWAppliedApprovalAssignment::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepAP214_RWAppliedApprovalAssignment.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepAP214_RWAppliedApprovalAssignment::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepAP214_RWAppliedApprovalAssignment.def_static("operator delete_", (void (*)(void *, void *)) &RWStepAP214_RWAppliedApprovalAssignment::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepAP214_RWAppliedApprovalAssignment.def("ReadStep", (void (RWStepAP214_RWAppliedApprovalAssignment::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepAP214_AppliedApprovalAssignment> &) const) &RWStepAP214_RWAppliedApprovalAssignment::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepAP214_RWAppliedApprovalAssignment.def("WriteStep", (void (RWStepAP214_RWAppliedApprovalAssignment::*)(StepData_StepWriter &, const opencascade::handle<StepAP214_AppliedApprovalAssignment> &) const) &RWStepAP214_RWAppliedApprovalAssignment::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepAP214_RWAppliedApprovalAssignment.def("Share", (void (RWStepAP214_RWAppliedApprovalAssignment::*)(const opencascade::handle<StepAP214_AppliedApprovalAssignment> &, Interface_EntityIterator &) const) &RWStepAP214_RWAppliedApprovalAssignment::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPAP214_RWAPPLIEDDATEANDTIMEASSIGNMENT
py::class_<RWStepAP214_RWAppliedDateAndTimeAssignment> cls_RWStepAP214_RWAppliedDateAndTimeAssignment(mod, "RWStepAP214_RWAppliedDateAndTimeAssignment", "Read & Write Module for AppliedDateAndTimeAssignment");

// Constructors
cls_RWStepAP214_RWAppliedDateAndTimeAssignment.def(py::init<>());

// Methods
// cls_RWStepAP214_RWAppliedDateAndTimeAssignment.def_static("operator new_", (void * (*)(size_t)) &RWStepAP214_RWAppliedDateAndTimeAssignment::operator new, "None", py::arg("theSize"));
// cls_RWStepAP214_RWAppliedDateAndTimeAssignment.def_static("operator delete_", (void (*)(void *)) &RWStepAP214_RWAppliedDateAndTimeAssignment::operator delete, "None", py::arg("theAddress"));
// cls_RWStepAP214_RWAppliedDateAndTimeAssignment.def_static("operator new[]_", (void * (*)(size_t)) &RWStepAP214_RWAppliedDateAndTimeAssignment::operator new[], "None", py::arg("theSize"));
// cls_RWStepAP214_RWAppliedDateAndTimeAssignment.def_static("operator delete[]_", (void (*)(void *)) &RWStepAP214_RWAppliedDateAndTimeAssignment::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepAP214_RWAppliedDateAndTimeAssignment.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepAP214_RWAppliedDateAndTimeAssignment::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepAP214_RWAppliedDateAndTimeAssignment.def_static("operator delete_", (void (*)(void *, void *)) &RWStepAP214_RWAppliedDateAndTimeAssignment::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepAP214_RWAppliedDateAndTimeAssignment.def("ReadStep", (void (RWStepAP214_RWAppliedDateAndTimeAssignment::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepAP214_AppliedDateAndTimeAssignment> &) const) &RWStepAP214_RWAppliedDateAndTimeAssignment::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepAP214_RWAppliedDateAndTimeAssignment.def("WriteStep", (void (RWStepAP214_RWAppliedDateAndTimeAssignment::*)(StepData_StepWriter &, const opencascade::handle<StepAP214_AppliedDateAndTimeAssignment> &) const) &RWStepAP214_RWAppliedDateAndTimeAssignment::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepAP214_RWAppliedDateAndTimeAssignment.def("Share", (void (RWStepAP214_RWAppliedDateAndTimeAssignment::*)(const opencascade::handle<StepAP214_AppliedDateAndTimeAssignment> &, Interface_EntityIterator &) const) &RWStepAP214_RWAppliedDateAndTimeAssignment::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPAP214_RWAPPLIEDDATEASSIGNMENT
py::class_<RWStepAP214_RWAppliedDateAssignment> cls_RWStepAP214_RWAppliedDateAssignment(mod, "RWStepAP214_RWAppliedDateAssignment", "Read & Write Module for AppliedDateAssignment");

// Constructors
cls_RWStepAP214_RWAppliedDateAssignment.def(py::init<>());

// Methods
// cls_RWStepAP214_RWAppliedDateAssignment.def_static("operator new_", (void * (*)(size_t)) &RWStepAP214_RWAppliedDateAssignment::operator new, "None", py::arg("theSize"));
// cls_RWStepAP214_RWAppliedDateAssignment.def_static("operator delete_", (void (*)(void *)) &RWStepAP214_RWAppliedDateAssignment::operator delete, "None", py::arg("theAddress"));
// cls_RWStepAP214_RWAppliedDateAssignment.def_static("operator new[]_", (void * (*)(size_t)) &RWStepAP214_RWAppliedDateAssignment::operator new[], "None", py::arg("theSize"));
// cls_RWStepAP214_RWAppliedDateAssignment.def_static("operator delete[]_", (void (*)(void *)) &RWStepAP214_RWAppliedDateAssignment::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepAP214_RWAppliedDateAssignment.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepAP214_RWAppliedDateAssignment::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepAP214_RWAppliedDateAssignment.def_static("operator delete_", (void (*)(void *, void *)) &RWStepAP214_RWAppliedDateAssignment::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepAP214_RWAppliedDateAssignment.def("ReadStep", (void (RWStepAP214_RWAppliedDateAssignment::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepAP214_AppliedDateAssignment> &) const) &RWStepAP214_RWAppliedDateAssignment::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepAP214_RWAppliedDateAssignment.def("WriteStep", (void (RWStepAP214_RWAppliedDateAssignment::*)(StepData_StepWriter &, const opencascade::handle<StepAP214_AppliedDateAssignment> &) const) &RWStepAP214_RWAppliedDateAssignment::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepAP214_RWAppliedDateAssignment.def("Share", (void (RWStepAP214_RWAppliedDateAssignment::*)(const opencascade::handle<StepAP214_AppliedDateAssignment> &, Interface_EntityIterator &) const) &RWStepAP214_RWAppliedDateAssignment::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPAP214_RWAPPLIEDDOCUMENTREFERENCE
py::class_<RWStepAP214_RWAppliedDocumentReference> cls_RWStepAP214_RWAppliedDocumentReference(mod, "RWStepAP214_RWAppliedDocumentReference", "Read & Write Module for AppliedDocumentReference");

// Constructors
cls_RWStepAP214_RWAppliedDocumentReference.def(py::init<>());

// Methods
// cls_RWStepAP214_RWAppliedDocumentReference.def_static("operator new_", (void * (*)(size_t)) &RWStepAP214_RWAppliedDocumentReference::operator new, "None", py::arg("theSize"));
// cls_RWStepAP214_RWAppliedDocumentReference.def_static("operator delete_", (void (*)(void *)) &RWStepAP214_RWAppliedDocumentReference::operator delete, "None", py::arg("theAddress"));
// cls_RWStepAP214_RWAppliedDocumentReference.def_static("operator new[]_", (void * (*)(size_t)) &RWStepAP214_RWAppliedDocumentReference::operator new[], "None", py::arg("theSize"));
// cls_RWStepAP214_RWAppliedDocumentReference.def_static("operator delete[]_", (void (*)(void *)) &RWStepAP214_RWAppliedDocumentReference::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepAP214_RWAppliedDocumentReference.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepAP214_RWAppliedDocumentReference::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepAP214_RWAppliedDocumentReference.def_static("operator delete_", (void (*)(void *, void *)) &RWStepAP214_RWAppliedDocumentReference::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepAP214_RWAppliedDocumentReference.def("ReadStep", (void (RWStepAP214_RWAppliedDocumentReference::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepAP214_AppliedDocumentReference> &) const) &RWStepAP214_RWAppliedDocumentReference::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepAP214_RWAppliedDocumentReference.def("WriteStep", (void (RWStepAP214_RWAppliedDocumentReference::*)(StepData_StepWriter &, const opencascade::handle<StepAP214_AppliedDocumentReference> &) const) &RWStepAP214_RWAppliedDocumentReference::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepAP214_RWAppliedDocumentReference.def("Share", (void (RWStepAP214_RWAppliedDocumentReference::*)(const opencascade::handle<StepAP214_AppliedDocumentReference> &, Interface_EntityIterator &) const) &RWStepAP214_RWAppliedDocumentReference::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPAP214_RWAPPLIEDEXTERNALIDENTIFICATIONASSIGNMENT
py::class_<RWStepAP214_RWAppliedExternalIdentificationAssignment> cls_RWStepAP214_RWAppliedExternalIdentificationAssignment(mod, "RWStepAP214_RWAppliedExternalIdentificationAssignment", "Read & Write tool for AppliedExternalIdentificationAssignment");

// Constructors
cls_RWStepAP214_RWAppliedExternalIdentificationAssignment.def(py::init<>());

// Methods
// cls_RWStepAP214_RWAppliedExternalIdentificationAssignment.def_static("operator new_", (void * (*)(size_t)) &RWStepAP214_RWAppliedExternalIdentificationAssignment::operator new, "None", py::arg("theSize"));
// cls_RWStepAP214_RWAppliedExternalIdentificationAssignment.def_static("operator delete_", (void (*)(void *)) &RWStepAP214_RWAppliedExternalIdentificationAssignment::operator delete, "None", py::arg("theAddress"));
// cls_RWStepAP214_RWAppliedExternalIdentificationAssignment.def_static("operator new[]_", (void * (*)(size_t)) &RWStepAP214_RWAppliedExternalIdentificationAssignment::operator new[], "None", py::arg("theSize"));
// cls_RWStepAP214_RWAppliedExternalIdentificationAssignment.def_static("operator delete[]_", (void (*)(void *)) &RWStepAP214_RWAppliedExternalIdentificationAssignment::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepAP214_RWAppliedExternalIdentificationAssignment.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepAP214_RWAppliedExternalIdentificationAssignment::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepAP214_RWAppliedExternalIdentificationAssignment.def_static("operator delete_", (void (*)(void *, void *)) &RWStepAP214_RWAppliedExternalIdentificationAssignment::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepAP214_RWAppliedExternalIdentificationAssignment.def("ReadStep", (void (RWStepAP214_RWAppliedExternalIdentificationAssignment::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepAP214_AppliedExternalIdentificationAssignment> &) const) &RWStepAP214_RWAppliedExternalIdentificationAssignment::ReadStep, "Reads AppliedExternalIdentificationAssignment", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepAP214_RWAppliedExternalIdentificationAssignment.def("WriteStep", (void (RWStepAP214_RWAppliedExternalIdentificationAssignment::*)(StepData_StepWriter &, const opencascade::handle<StepAP214_AppliedExternalIdentificationAssignment> &) const) &RWStepAP214_RWAppliedExternalIdentificationAssignment::WriteStep, "Writes AppliedExternalIdentificationAssignment", py::arg("SW"), py::arg("ent"));
cls_RWStepAP214_RWAppliedExternalIdentificationAssignment.def("Share", (void (RWStepAP214_RWAppliedExternalIdentificationAssignment::*)(const opencascade::handle<StepAP214_AppliedExternalIdentificationAssignment> &, Interface_EntityIterator &) const) &RWStepAP214_RWAppliedExternalIdentificationAssignment::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPAP214_RWAPPLIEDGROUPASSIGNMENT
py::class_<RWStepAP214_RWAppliedGroupAssignment> cls_RWStepAP214_RWAppliedGroupAssignment(mod, "RWStepAP214_RWAppliedGroupAssignment", "Read & Write tool for AppliedGroupAssignment");

// Constructors
cls_RWStepAP214_RWAppliedGroupAssignment.def(py::init<>());

// Methods
// cls_RWStepAP214_RWAppliedGroupAssignment.def_static("operator new_", (void * (*)(size_t)) &RWStepAP214_RWAppliedGroupAssignment::operator new, "None", py::arg("theSize"));
// cls_RWStepAP214_RWAppliedGroupAssignment.def_static("operator delete_", (void (*)(void *)) &RWStepAP214_RWAppliedGroupAssignment::operator delete, "None", py::arg("theAddress"));
// cls_RWStepAP214_RWAppliedGroupAssignment.def_static("operator new[]_", (void * (*)(size_t)) &RWStepAP214_RWAppliedGroupAssignment::operator new[], "None", py::arg("theSize"));
// cls_RWStepAP214_RWAppliedGroupAssignment.def_static("operator delete[]_", (void (*)(void *)) &RWStepAP214_RWAppliedGroupAssignment::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepAP214_RWAppliedGroupAssignment.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepAP214_RWAppliedGroupAssignment::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepAP214_RWAppliedGroupAssignment.def_static("operator delete_", (void (*)(void *, void *)) &RWStepAP214_RWAppliedGroupAssignment::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepAP214_RWAppliedGroupAssignment.def("ReadStep", (void (RWStepAP214_RWAppliedGroupAssignment::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepAP214_AppliedGroupAssignment> &) const) &RWStepAP214_RWAppliedGroupAssignment::ReadStep, "Reads AppliedGroupAssignment", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepAP214_RWAppliedGroupAssignment.def("WriteStep", (void (RWStepAP214_RWAppliedGroupAssignment::*)(StepData_StepWriter &, const opencascade::handle<StepAP214_AppliedGroupAssignment> &) const) &RWStepAP214_RWAppliedGroupAssignment::WriteStep, "Writes AppliedGroupAssignment", py::arg("SW"), py::arg("ent"));
cls_RWStepAP214_RWAppliedGroupAssignment.def("Share", (void (RWStepAP214_RWAppliedGroupAssignment::*)(const opencascade::handle<StepAP214_AppliedGroupAssignment> &, Interface_EntityIterator &) const) &RWStepAP214_RWAppliedGroupAssignment::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPAP214_RWAPPLIEDORGANIZATIONASSIGNMENT
py::class_<RWStepAP214_RWAppliedOrganizationAssignment> cls_RWStepAP214_RWAppliedOrganizationAssignment(mod, "RWStepAP214_RWAppliedOrganizationAssignment", "Read & Write Module for AppliedOrganizationAssignment");

// Constructors
cls_RWStepAP214_RWAppliedOrganizationAssignment.def(py::init<>());

// Methods
// cls_RWStepAP214_RWAppliedOrganizationAssignment.def_static("operator new_", (void * (*)(size_t)) &RWStepAP214_RWAppliedOrganizationAssignment::operator new, "None", py::arg("theSize"));
// cls_RWStepAP214_RWAppliedOrganizationAssignment.def_static("operator delete_", (void (*)(void *)) &RWStepAP214_RWAppliedOrganizationAssignment::operator delete, "None", py::arg("theAddress"));
// cls_RWStepAP214_RWAppliedOrganizationAssignment.def_static("operator new[]_", (void * (*)(size_t)) &RWStepAP214_RWAppliedOrganizationAssignment::operator new[], "None", py::arg("theSize"));
// cls_RWStepAP214_RWAppliedOrganizationAssignment.def_static("operator delete[]_", (void (*)(void *)) &RWStepAP214_RWAppliedOrganizationAssignment::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepAP214_RWAppliedOrganizationAssignment.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepAP214_RWAppliedOrganizationAssignment::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepAP214_RWAppliedOrganizationAssignment.def_static("operator delete_", (void (*)(void *, void *)) &RWStepAP214_RWAppliedOrganizationAssignment::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepAP214_RWAppliedOrganizationAssignment.def("ReadStep", (void (RWStepAP214_RWAppliedOrganizationAssignment::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepAP214_AppliedOrganizationAssignment> &) const) &RWStepAP214_RWAppliedOrganizationAssignment::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepAP214_RWAppliedOrganizationAssignment.def("WriteStep", (void (RWStepAP214_RWAppliedOrganizationAssignment::*)(StepData_StepWriter &, const opencascade::handle<StepAP214_AppliedOrganizationAssignment> &) const) &RWStepAP214_RWAppliedOrganizationAssignment::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepAP214_RWAppliedOrganizationAssignment.def("Share", (void (RWStepAP214_RWAppliedOrganizationAssignment::*)(const opencascade::handle<StepAP214_AppliedOrganizationAssignment> &, Interface_EntityIterator &) const) &RWStepAP214_RWAppliedOrganizationAssignment::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPAP214_RWAPPLIEDPERSONANDORGANIZATIONASSIGNMENT
py::class_<RWStepAP214_RWAppliedPersonAndOrganizationAssignment> cls_RWStepAP214_RWAppliedPersonAndOrganizationAssignment(mod, "RWStepAP214_RWAppliedPersonAndOrganizationAssignment", "Read & Write Module for AppliedPersonAndOrganizationAssignment");

// Constructors
cls_RWStepAP214_RWAppliedPersonAndOrganizationAssignment.def(py::init<>());

// Methods
// cls_RWStepAP214_RWAppliedPersonAndOrganizationAssignment.def_static("operator new_", (void * (*)(size_t)) &RWStepAP214_RWAppliedPersonAndOrganizationAssignment::operator new, "None", py::arg("theSize"));
// cls_RWStepAP214_RWAppliedPersonAndOrganizationAssignment.def_static("operator delete_", (void (*)(void *)) &RWStepAP214_RWAppliedPersonAndOrganizationAssignment::operator delete, "None", py::arg("theAddress"));
// cls_RWStepAP214_RWAppliedPersonAndOrganizationAssignment.def_static("operator new[]_", (void * (*)(size_t)) &RWStepAP214_RWAppliedPersonAndOrganizationAssignment::operator new[], "None", py::arg("theSize"));
// cls_RWStepAP214_RWAppliedPersonAndOrganizationAssignment.def_static("operator delete[]_", (void (*)(void *)) &RWStepAP214_RWAppliedPersonAndOrganizationAssignment::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepAP214_RWAppliedPersonAndOrganizationAssignment.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepAP214_RWAppliedPersonAndOrganizationAssignment::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepAP214_RWAppliedPersonAndOrganizationAssignment.def_static("operator delete_", (void (*)(void *, void *)) &RWStepAP214_RWAppliedPersonAndOrganizationAssignment::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepAP214_RWAppliedPersonAndOrganizationAssignment.def("ReadStep", (void (RWStepAP214_RWAppliedPersonAndOrganizationAssignment::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepAP214_AppliedPersonAndOrganizationAssignment> &) const) &RWStepAP214_RWAppliedPersonAndOrganizationAssignment::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepAP214_RWAppliedPersonAndOrganizationAssignment.def("WriteStep", (void (RWStepAP214_RWAppliedPersonAndOrganizationAssignment::*)(StepData_StepWriter &, const opencascade::handle<StepAP214_AppliedPersonAndOrganizationAssignment> &) const) &RWStepAP214_RWAppliedPersonAndOrganizationAssignment::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepAP214_RWAppliedPersonAndOrganizationAssignment.def("Share", (void (RWStepAP214_RWAppliedPersonAndOrganizationAssignment::*)(const opencascade::handle<StepAP214_AppliedPersonAndOrganizationAssignment> &, Interface_EntityIterator &) const) &RWStepAP214_RWAppliedPersonAndOrganizationAssignment::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPAP214_RWAPPLIEDPRESENTEDITEM
py::class_<RWStepAP214_RWAppliedPresentedItem> cls_RWStepAP214_RWAppliedPresentedItem(mod, "RWStepAP214_RWAppliedPresentedItem", "Read & Write Module for AppliedPresentedItem");

// Constructors
cls_RWStepAP214_RWAppliedPresentedItem.def(py::init<>());

// Methods
// cls_RWStepAP214_RWAppliedPresentedItem.def_static("operator new_", (void * (*)(size_t)) &RWStepAP214_RWAppliedPresentedItem::operator new, "None", py::arg("theSize"));
// cls_RWStepAP214_RWAppliedPresentedItem.def_static("operator delete_", (void (*)(void *)) &RWStepAP214_RWAppliedPresentedItem::operator delete, "None", py::arg("theAddress"));
// cls_RWStepAP214_RWAppliedPresentedItem.def_static("operator new[]_", (void * (*)(size_t)) &RWStepAP214_RWAppliedPresentedItem::operator new[], "None", py::arg("theSize"));
// cls_RWStepAP214_RWAppliedPresentedItem.def_static("operator delete[]_", (void (*)(void *)) &RWStepAP214_RWAppliedPresentedItem::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepAP214_RWAppliedPresentedItem.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepAP214_RWAppliedPresentedItem::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepAP214_RWAppliedPresentedItem.def_static("operator delete_", (void (*)(void *, void *)) &RWStepAP214_RWAppliedPresentedItem::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepAP214_RWAppliedPresentedItem.def("ReadStep", (void (RWStepAP214_RWAppliedPresentedItem::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepAP214_AppliedPresentedItem> &) const) &RWStepAP214_RWAppliedPresentedItem::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepAP214_RWAppliedPresentedItem.def("WriteStep", (void (RWStepAP214_RWAppliedPresentedItem::*)(StepData_StepWriter &, const opencascade::handle<StepAP214_AppliedPresentedItem> &) const) &RWStepAP214_RWAppliedPresentedItem::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepAP214_RWAppliedPresentedItem.def("Share", (void (RWStepAP214_RWAppliedPresentedItem::*)(const opencascade::handle<StepAP214_AppliedPresentedItem> &, Interface_EntityIterator &) const) &RWStepAP214_RWAppliedPresentedItem::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPAP214_RWAPPLIEDSECURITYCLASSIFICATIONASSIGNMENT
py::class_<RWStepAP214_RWAppliedSecurityClassificationAssignment> cls_RWStepAP214_RWAppliedSecurityClassificationAssignment(mod, "RWStepAP214_RWAppliedSecurityClassificationAssignment", "None");

// Constructors
cls_RWStepAP214_RWAppliedSecurityClassificationAssignment.def(py::init<>());

// Methods
// cls_RWStepAP214_RWAppliedSecurityClassificationAssignment.def_static("operator new_", (void * (*)(size_t)) &RWStepAP214_RWAppliedSecurityClassificationAssignment::operator new, "None", py::arg("theSize"));
// cls_RWStepAP214_RWAppliedSecurityClassificationAssignment.def_static("operator delete_", (void (*)(void *)) &RWStepAP214_RWAppliedSecurityClassificationAssignment::operator delete, "None", py::arg("theAddress"));
// cls_RWStepAP214_RWAppliedSecurityClassificationAssignment.def_static("operator new[]_", (void * (*)(size_t)) &RWStepAP214_RWAppliedSecurityClassificationAssignment::operator new[], "None", py::arg("theSize"));
// cls_RWStepAP214_RWAppliedSecurityClassificationAssignment.def_static("operator delete[]_", (void (*)(void *)) &RWStepAP214_RWAppliedSecurityClassificationAssignment::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepAP214_RWAppliedSecurityClassificationAssignment.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepAP214_RWAppliedSecurityClassificationAssignment::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepAP214_RWAppliedSecurityClassificationAssignment.def_static("operator delete_", (void (*)(void *, void *)) &RWStepAP214_RWAppliedSecurityClassificationAssignment::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepAP214_RWAppliedSecurityClassificationAssignment.def("ReadStep", (void (RWStepAP214_RWAppliedSecurityClassificationAssignment::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepAP214_AppliedSecurityClassificationAssignment> &) const) &RWStepAP214_RWAppliedSecurityClassificationAssignment::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepAP214_RWAppliedSecurityClassificationAssignment.def("WriteStep", (void (RWStepAP214_RWAppliedSecurityClassificationAssignment::*)(StepData_StepWriter &, const opencascade::handle<StepAP214_AppliedSecurityClassificationAssignment> &) const) &RWStepAP214_RWAppliedSecurityClassificationAssignment::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepAP214_RWAppliedSecurityClassificationAssignment.def("Share", (void (RWStepAP214_RWAppliedSecurityClassificationAssignment::*)(const opencascade::handle<StepAP214_AppliedSecurityClassificationAssignment> &, Interface_EntityIterator &) const) &RWStepAP214_RWAppliedSecurityClassificationAssignment::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPAP214_RWAUTODESIGNACTUALDATEANDTIMEASSIGNMENT
py::class_<RWStepAP214_RWAutoDesignActualDateAndTimeAssignment> cls_RWStepAP214_RWAutoDesignActualDateAndTimeAssignment(mod, "RWStepAP214_RWAutoDesignActualDateAndTimeAssignment", "Read & Write Module for AutoDesignActualDateAndTimeAssignment");

// Constructors
cls_RWStepAP214_RWAutoDesignActualDateAndTimeAssignment.def(py::init<>());

// Methods
// cls_RWStepAP214_RWAutoDesignActualDateAndTimeAssignment.def_static("operator new_", (void * (*)(size_t)) &RWStepAP214_RWAutoDesignActualDateAndTimeAssignment::operator new, "None", py::arg("theSize"));
// cls_RWStepAP214_RWAutoDesignActualDateAndTimeAssignment.def_static("operator delete_", (void (*)(void *)) &RWStepAP214_RWAutoDesignActualDateAndTimeAssignment::operator delete, "None", py::arg("theAddress"));
// cls_RWStepAP214_RWAutoDesignActualDateAndTimeAssignment.def_static("operator new[]_", (void * (*)(size_t)) &RWStepAP214_RWAutoDesignActualDateAndTimeAssignment::operator new[], "None", py::arg("theSize"));
// cls_RWStepAP214_RWAutoDesignActualDateAndTimeAssignment.def_static("operator delete[]_", (void (*)(void *)) &RWStepAP214_RWAutoDesignActualDateAndTimeAssignment::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepAP214_RWAutoDesignActualDateAndTimeAssignment.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepAP214_RWAutoDesignActualDateAndTimeAssignment::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepAP214_RWAutoDesignActualDateAndTimeAssignment.def_static("operator delete_", (void (*)(void *, void *)) &RWStepAP214_RWAutoDesignActualDateAndTimeAssignment::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepAP214_RWAutoDesignActualDateAndTimeAssignment.def("ReadStep", (void (RWStepAP214_RWAutoDesignActualDateAndTimeAssignment::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepAP214_AutoDesignActualDateAndTimeAssignment> &) const) &RWStepAP214_RWAutoDesignActualDateAndTimeAssignment::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepAP214_RWAutoDesignActualDateAndTimeAssignment.def("WriteStep", (void (RWStepAP214_RWAutoDesignActualDateAndTimeAssignment::*)(StepData_StepWriter &, const opencascade::handle<StepAP214_AutoDesignActualDateAndTimeAssignment> &) const) &RWStepAP214_RWAutoDesignActualDateAndTimeAssignment::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepAP214_RWAutoDesignActualDateAndTimeAssignment.def("Share", (void (RWStepAP214_RWAutoDesignActualDateAndTimeAssignment::*)(const opencascade::handle<StepAP214_AutoDesignActualDateAndTimeAssignment> &, Interface_EntityIterator &) const) &RWStepAP214_RWAutoDesignActualDateAndTimeAssignment::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPAP214_RWAUTODESIGNACTUALDATEASSIGNMENT
py::class_<RWStepAP214_RWAutoDesignActualDateAssignment> cls_RWStepAP214_RWAutoDesignActualDateAssignment(mod, "RWStepAP214_RWAutoDesignActualDateAssignment", "Read & Write Module for AutoDesignActualDateAssignment");

// Constructors
cls_RWStepAP214_RWAutoDesignActualDateAssignment.def(py::init<>());

// Methods
// cls_RWStepAP214_RWAutoDesignActualDateAssignment.def_static("operator new_", (void * (*)(size_t)) &RWStepAP214_RWAutoDesignActualDateAssignment::operator new, "None", py::arg("theSize"));
// cls_RWStepAP214_RWAutoDesignActualDateAssignment.def_static("operator delete_", (void (*)(void *)) &RWStepAP214_RWAutoDesignActualDateAssignment::operator delete, "None", py::arg("theAddress"));
// cls_RWStepAP214_RWAutoDesignActualDateAssignment.def_static("operator new[]_", (void * (*)(size_t)) &RWStepAP214_RWAutoDesignActualDateAssignment::operator new[], "None", py::arg("theSize"));
// cls_RWStepAP214_RWAutoDesignActualDateAssignment.def_static("operator delete[]_", (void (*)(void *)) &RWStepAP214_RWAutoDesignActualDateAssignment::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepAP214_RWAutoDesignActualDateAssignment.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepAP214_RWAutoDesignActualDateAssignment::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepAP214_RWAutoDesignActualDateAssignment.def_static("operator delete_", (void (*)(void *, void *)) &RWStepAP214_RWAutoDesignActualDateAssignment::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepAP214_RWAutoDesignActualDateAssignment.def("ReadStep", (void (RWStepAP214_RWAutoDesignActualDateAssignment::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepAP214_AutoDesignActualDateAssignment> &) const) &RWStepAP214_RWAutoDesignActualDateAssignment::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepAP214_RWAutoDesignActualDateAssignment.def("WriteStep", (void (RWStepAP214_RWAutoDesignActualDateAssignment::*)(StepData_StepWriter &, const opencascade::handle<StepAP214_AutoDesignActualDateAssignment> &) const) &RWStepAP214_RWAutoDesignActualDateAssignment::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepAP214_RWAutoDesignActualDateAssignment.def("Share", (void (RWStepAP214_RWAutoDesignActualDateAssignment::*)(const opencascade::handle<StepAP214_AutoDesignActualDateAssignment> &, Interface_EntityIterator &) const) &RWStepAP214_RWAutoDesignActualDateAssignment::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPAP214_RWAUTODESIGNAPPROVALASSIGNMENT
py::class_<RWStepAP214_RWAutoDesignApprovalAssignment> cls_RWStepAP214_RWAutoDesignApprovalAssignment(mod, "RWStepAP214_RWAutoDesignApprovalAssignment", "Read & Write Module for AutoDesignApprovalAssignment");

// Constructors
cls_RWStepAP214_RWAutoDesignApprovalAssignment.def(py::init<>());

// Methods
// cls_RWStepAP214_RWAutoDesignApprovalAssignment.def_static("operator new_", (void * (*)(size_t)) &RWStepAP214_RWAutoDesignApprovalAssignment::operator new, "None", py::arg("theSize"));
// cls_RWStepAP214_RWAutoDesignApprovalAssignment.def_static("operator delete_", (void (*)(void *)) &RWStepAP214_RWAutoDesignApprovalAssignment::operator delete, "None", py::arg("theAddress"));
// cls_RWStepAP214_RWAutoDesignApprovalAssignment.def_static("operator new[]_", (void * (*)(size_t)) &RWStepAP214_RWAutoDesignApprovalAssignment::operator new[], "None", py::arg("theSize"));
// cls_RWStepAP214_RWAutoDesignApprovalAssignment.def_static("operator delete[]_", (void (*)(void *)) &RWStepAP214_RWAutoDesignApprovalAssignment::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepAP214_RWAutoDesignApprovalAssignment.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepAP214_RWAutoDesignApprovalAssignment::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepAP214_RWAutoDesignApprovalAssignment.def_static("operator delete_", (void (*)(void *, void *)) &RWStepAP214_RWAutoDesignApprovalAssignment::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepAP214_RWAutoDesignApprovalAssignment.def("ReadStep", (void (RWStepAP214_RWAutoDesignApprovalAssignment::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepAP214_AutoDesignApprovalAssignment> &) const) &RWStepAP214_RWAutoDesignApprovalAssignment::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepAP214_RWAutoDesignApprovalAssignment.def("WriteStep", (void (RWStepAP214_RWAutoDesignApprovalAssignment::*)(StepData_StepWriter &, const opencascade::handle<StepAP214_AutoDesignApprovalAssignment> &) const) &RWStepAP214_RWAutoDesignApprovalAssignment::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepAP214_RWAutoDesignApprovalAssignment.def("Share", (void (RWStepAP214_RWAutoDesignApprovalAssignment::*)(const opencascade::handle<StepAP214_AutoDesignApprovalAssignment> &, Interface_EntityIterator &) const) &RWStepAP214_RWAutoDesignApprovalAssignment::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPAP214_RWAUTODESIGNDATEANDPERSONASSIGNMENT
py::class_<RWStepAP214_RWAutoDesignDateAndPersonAssignment> cls_RWStepAP214_RWAutoDesignDateAndPersonAssignment(mod, "RWStepAP214_RWAutoDesignDateAndPersonAssignment", "Read & Write Module for AutoDesignDateAndPersonAssignment");

// Constructors
cls_RWStepAP214_RWAutoDesignDateAndPersonAssignment.def(py::init<>());

// Methods
// cls_RWStepAP214_RWAutoDesignDateAndPersonAssignment.def_static("operator new_", (void * (*)(size_t)) &RWStepAP214_RWAutoDesignDateAndPersonAssignment::operator new, "None", py::arg("theSize"));
// cls_RWStepAP214_RWAutoDesignDateAndPersonAssignment.def_static("operator delete_", (void (*)(void *)) &RWStepAP214_RWAutoDesignDateAndPersonAssignment::operator delete, "None", py::arg("theAddress"));
// cls_RWStepAP214_RWAutoDesignDateAndPersonAssignment.def_static("operator new[]_", (void * (*)(size_t)) &RWStepAP214_RWAutoDesignDateAndPersonAssignment::operator new[], "None", py::arg("theSize"));
// cls_RWStepAP214_RWAutoDesignDateAndPersonAssignment.def_static("operator delete[]_", (void (*)(void *)) &RWStepAP214_RWAutoDesignDateAndPersonAssignment::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepAP214_RWAutoDesignDateAndPersonAssignment.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepAP214_RWAutoDesignDateAndPersonAssignment::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepAP214_RWAutoDesignDateAndPersonAssignment.def_static("operator delete_", (void (*)(void *, void *)) &RWStepAP214_RWAutoDesignDateAndPersonAssignment::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepAP214_RWAutoDesignDateAndPersonAssignment.def("ReadStep", (void (RWStepAP214_RWAutoDesignDateAndPersonAssignment::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepAP214_AutoDesignDateAndPersonAssignment> &) const) &RWStepAP214_RWAutoDesignDateAndPersonAssignment::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepAP214_RWAutoDesignDateAndPersonAssignment.def("WriteStep", (void (RWStepAP214_RWAutoDesignDateAndPersonAssignment::*)(StepData_StepWriter &, const opencascade::handle<StepAP214_AutoDesignDateAndPersonAssignment> &) const) &RWStepAP214_RWAutoDesignDateAndPersonAssignment::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepAP214_RWAutoDesignDateAndPersonAssignment.def("Share", (void (RWStepAP214_RWAutoDesignDateAndPersonAssignment::*)(const opencascade::handle<StepAP214_AutoDesignDateAndPersonAssignment> &, Interface_EntityIterator &) const) &RWStepAP214_RWAutoDesignDateAndPersonAssignment::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPAP214_RWAUTODESIGNDOCUMENTREFERENCE
py::class_<RWStepAP214_RWAutoDesignDocumentReference> cls_RWStepAP214_RWAutoDesignDocumentReference(mod, "RWStepAP214_RWAutoDesignDocumentReference", "Read & Write Module for AutoDesignDocumentReference");

// Constructors
cls_RWStepAP214_RWAutoDesignDocumentReference.def(py::init<>());

// Methods
// cls_RWStepAP214_RWAutoDesignDocumentReference.def_static("operator new_", (void * (*)(size_t)) &RWStepAP214_RWAutoDesignDocumentReference::operator new, "None", py::arg("theSize"));
// cls_RWStepAP214_RWAutoDesignDocumentReference.def_static("operator delete_", (void (*)(void *)) &RWStepAP214_RWAutoDesignDocumentReference::operator delete, "None", py::arg("theAddress"));
// cls_RWStepAP214_RWAutoDesignDocumentReference.def_static("operator new[]_", (void * (*)(size_t)) &RWStepAP214_RWAutoDesignDocumentReference::operator new[], "None", py::arg("theSize"));
// cls_RWStepAP214_RWAutoDesignDocumentReference.def_static("operator delete[]_", (void (*)(void *)) &RWStepAP214_RWAutoDesignDocumentReference::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepAP214_RWAutoDesignDocumentReference.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepAP214_RWAutoDesignDocumentReference::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepAP214_RWAutoDesignDocumentReference.def_static("operator delete_", (void (*)(void *, void *)) &RWStepAP214_RWAutoDesignDocumentReference::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepAP214_RWAutoDesignDocumentReference.def("ReadStep", (void (RWStepAP214_RWAutoDesignDocumentReference::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepAP214_AutoDesignDocumentReference> &) const) &RWStepAP214_RWAutoDesignDocumentReference::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepAP214_RWAutoDesignDocumentReference.def("WriteStep", (void (RWStepAP214_RWAutoDesignDocumentReference::*)(StepData_StepWriter &, const opencascade::handle<StepAP214_AutoDesignDocumentReference> &) const) &RWStepAP214_RWAutoDesignDocumentReference::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepAP214_RWAutoDesignDocumentReference.def("Share", (void (RWStepAP214_RWAutoDesignDocumentReference::*)(const opencascade::handle<StepAP214_AutoDesignDocumentReference> &, Interface_EntityIterator &) const) &RWStepAP214_RWAutoDesignDocumentReference::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPAP214_RWAUTODESIGNGROUPASSIGNMENT
py::class_<RWStepAP214_RWAutoDesignGroupAssignment> cls_RWStepAP214_RWAutoDesignGroupAssignment(mod, "RWStepAP214_RWAutoDesignGroupAssignment", "Read & Write Module for AutoDesignGroupAssignment");

// Constructors
cls_RWStepAP214_RWAutoDesignGroupAssignment.def(py::init<>());

// Methods
// cls_RWStepAP214_RWAutoDesignGroupAssignment.def_static("operator new_", (void * (*)(size_t)) &RWStepAP214_RWAutoDesignGroupAssignment::operator new, "None", py::arg("theSize"));
// cls_RWStepAP214_RWAutoDesignGroupAssignment.def_static("operator delete_", (void (*)(void *)) &RWStepAP214_RWAutoDesignGroupAssignment::operator delete, "None", py::arg("theAddress"));
// cls_RWStepAP214_RWAutoDesignGroupAssignment.def_static("operator new[]_", (void * (*)(size_t)) &RWStepAP214_RWAutoDesignGroupAssignment::operator new[], "None", py::arg("theSize"));
// cls_RWStepAP214_RWAutoDesignGroupAssignment.def_static("operator delete[]_", (void (*)(void *)) &RWStepAP214_RWAutoDesignGroupAssignment::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepAP214_RWAutoDesignGroupAssignment.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepAP214_RWAutoDesignGroupAssignment::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepAP214_RWAutoDesignGroupAssignment.def_static("operator delete_", (void (*)(void *, void *)) &RWStepAP214_RWAutoDesignGroupAssignment::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepAP214_RWAutoDesignGroupAssignment.def("ReadStep", (void (RWStepAP214_RWAutoDesignGroupAssignment::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepAP214_AutoDesignGroupAssignment> &) const) &RWStepAP214_RWAutoDesignGroupAssignment::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepAP214_RWAutoDesignGroupAssignment.def("WriteStep", (void (RWStepAP214_RWAutoDesignGroupAssignment::*)(StepData_StepWriter &, const opencascade::handle<StepAP214_AutoDesignGroupAssignment> &) const) &RWStepAP214_RWAutoDesignGroupAssignment::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepAP214_RWAutoDesignGroupAssignment.def("Share", (void (RWStepAP214_RWAutoDesignGroupAssignment::*)(const opencascade::handle<StepAP214_AutoDesignGroupAssignment> &, Interface_EntityIterator &) const) &RWStepAP214_RWAutoDesignGroupAssignment::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPAP214_RWAUTODESIGNNOMINALDATEANDTIMEASSIGNMENT
py::class_<RWStepAP214_RWAutoDesignNominalDateAndTimeAssignment> cls_RWStepAP214_RWAutoDesignNominalDateAndTimeAssignment(mod, "RWStepAP214_RWAutoDesignNominalDateAndTimeAssignment", "Read & Write Module for AutoDesignNominalDateAndTimeAssignment");

// Constructors
cls_RWStepAP214_RWAutoDesignNominalDateAndTimeAssignment.def(py::init<>());

// Methods
// cls_RWStepAP214_RWAutoDesignNominalDateAndTimeAssignment.def_static("operator new_", (void * (*)(size_t)) &RWStepAP214_RWAutoDesignNominalDateAndTimeAssignment::operator new, "None", py::arg("theSize"));
// cls_RWStepAP214_RWAutoDesignNominalDateAndTimeAssignment.def_static("operator delete_", (void (*)(void *)) &RWStepAP214_RWAutoDesignNominalDateAndTimeAssignment::operator delete, "None", py::arg("theAddress"));
// cls_RWStepAP214_RWAutoDesignNominalDateAndTimeAssignment.def_static("operator new[]_", (void * (*)(size_t)) &RWStepAP214_RWAutoDesignNominalDateAndTimeAssignment::operator new[], "None", py::arg("theSize"));
// cls_RWStepAP214_RWAutoDesignNominalDateAndTimeAssignment.def_static("operator delete[]_", (void (*)(void *)) &RWStepAP214_RWAutoDesignNominalDateAndTimeAssignment::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepAP214_RWAutoDesignNominalDateAndTimeAssignment.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepAP214_RWAutoDesignNominalDateAndTimeAssignment::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepAP214_RWAutoDesignNominalDateAndTimeAssignment.def_static("operator delete_", (void (*)(void *, void *)) &RWStepAP214_RWAutoDesignNominalDateAndTimeAssignment::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepAP214_RWAutoDesignNominalDateAndTimeAssignment.def("ReadStep", (void (RWStepAP214_RWAutoDesignNominalDateAndTimeAssignment::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepAP214_AutoDesignNominalDateAndTimeAssignment> &) const) &RWStepAP214_RWAutoDesignNominalDateAndTimeAssignment::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepAP214_RWAutoDesignNominalDateAndTimeAssignment.def("WriteStep", (void (RWStepAP214_RWAutoDesignNominalDateAndTimeAssignment::*)(StepData_StepWriter &, const opencascade::handle<StepAP214_AutoDesignNominalDateAndTimeAssignment> &) const) &RWStepAP214_RWAutoDesignNominalDateAndTimeAssignment::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepAP214_RWAutoDesignNominalDateAndTimeAssignment.def("Share", (void (RWStepAP214_RWAutoDesignNominalDateAndTimeAssignment::*)(const opencascade::handle<StepAP214_AutoDesignNominalDateAndTimeAssignment> &, Interface_EntityIterator &) const) &RWStepAP214_RWAutoDesignNominalDateAndTimeAssignment::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPAP214_RWAUTODESIGNNOMINALDATEASSIGNMENT
py::class_<RWStepAP214_RWAutoDesignNominalDateAssignment> cls_RWStepAP214_RWAutoDesignNominalDateAssignment(mod, "RWStepAP214_RWAutoDesignNominalDateAssignment", "Read & Write Module for AutoDesignNominalDateAssignment");

// Constructors
cls_RWStepAP214_RWAutoDesignNominalDateAssignment.def(py::init<>());

// Methods
// cls_RWStepAP214_RWAutoDesignNominalDateAssignment.def_static("operator new_", (void * (*)(size_t)) &RWStepAP214_RWAutoDesignNominalDateAssignment::operator new, "None", py::arg("theSize"));
// cls_RWStepAP214_RWAutoDesignNominalDateAssignment.def_static("operator delete_", (void (*)(void *)) &RWStepAP214_RWAutoDesignNominalDateAssignment::operator delete, "None", py::arg("theAddress"));
// cls_RWStepAP214_RWAutoDesignNominalDateAssignment.def_static("operator new[]_", (void * (*)(size_t)) &RWStepAP214_RWAutoDesignNominalDateAssignment::operator new[], "None", py::arg("theSize"));
// cls_RWStepAP214_RWAutoDesignNominalDateAssignment.def_static("operator delete[]_", (void (*)(void *)) &RWStepAP214_RWAutoDesignNominalDateAssignment::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepAP214_RWAutoDesignNominalDateAssignment.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepAP214_RWAutoDesignNominalDateAssignment::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepAP214_RWAutoDesignNominalDateAssignment.def_static("operator delete_", (void (*)(void *, void *)) &RWStepAP214_RWAutoDesignNominalDateAssignment::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepAP214_RWAutoDesignNominalDateAssignment.def("ReadStep", (void (RWStepAP214_RWAutoDesignNominalDateAssignment::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepAP214_AutoDesignNominalDateAssignment> &) const) &RWStepAP214_RWAutoDesignNominalDateAssignment::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepAP214_RWAutoDesignNominalDateAssignment.def("WriteStep", (void (RWStepAP214_RWAutoDesignNominalDateAssignment::*)(StepData_StepWriter &, const opencascade::handle<StepAP214_AutoDesignNominalDateAssignment> &) const) &RWStepAP214_RWAutoDesignNominalDateAssignment::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepAP214_RWAutoDesignNominalDateAssignment.def("Share", (void (RWStepAP214_RWAutoDesignNominalDateAssignment::*)(const opencascade::handle<StepAP214_AutoDesignNominalDateAssignment> &, Interface_EntityIterator &) const) &RWStepAP214_RWAutoDesignNominalDateAssignment::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPAP214_RWAUTODESIGNORGANIZATIONASSIGNMENT
py::class_<RWStepAP214_RWAutoDesignOrganizationAssignment> cls_RWStepAP214_RWAutoDesignOrganizationAssignment(mod, "RWStepAP214_RWAutoDesignOrganizationAssignment", "Read & Write Module for AutoDesignOrganizationAssignment");

// Constructors
cls_RWStepAP214_RWAutoDesignOrganizationAssignment.def(py::init<>());

// Methods
// cls_RWStepAP214_RWAutoDesignOrganizationAssignment.def_static("operator new_", (void * (*)(size_t)) &RWStepAP214_RWAutoDesignOrganizationAssignment::operator new, "None", py::arg("theSize"));
// cls_RWStepAP214_RWAutoDesignOrganizationAssignment.def_static("operator delete_", (void (*)(void *)) &RWStepAP214_RWAutoDesignOrganizationAssignment::operator delete, "None", py::arg("theAddress"));
// cls_RWStepAP214_RWAutoDesignOrganizationAssignment.def_static("operator new[]_", (void * (*)(size_t)) &RWStepAP214_RWAutoDesignOrganizationAssignment::operator new[], "None", py::arg("theSize"));
// cls_RWStepAP214_RWAutoDesignOrganizationAssignment.def_static("operator delete[]_", (void (*)(void *)) &RWStepAP214_RWAutoDesignOrganizationAssignment::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepAP214_RWAutoDesignOrganizationAssignment.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepAP214_RWAutoDesignOrganizationAssignment::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepAP214_RWAutoDesignOrganizationAssignment.def_static("operator delete_", (void (*)(void *, void *)) &RWStepAP214_RWAutoDesignOrganizationAssignment::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepAP214_RWAutoDesignOrganizationAssignment.def("ReadStep", (void (RWStepAP214_RWAutoDesignOrganizationAssignment::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepAP214_AutoDesignOrganizationAssignment> &) const) &RWStepAP214_RWAutoDesignOrganizationAssignment::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepAP214_RWAutoDesignOrganizationAssignment.def("WriteStep", (void (RWStepAP214_RWAutoDesignOrganizationAssignment::*)(StepData_StepWriter &, const opencascade::handle<StepAP214_AutoDesignOrganizationAssignment> &) const) &RWStepAP214_RWAutoDesignOrganizationAssignment::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepAP214_RWAutoDesignOrganizationAssignment.def("Share", (void (RWStepAP214_RWAutoDesignOrganizationAssignment::*)(const opencascade::handle<StepAP214_AutoDesignOrganizationAssignment> &, Interface_EntityIterator &) const) &RWStepAP214_RWAutoDesignOrganizationAssignment::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPAP214_RWAUTODESIGNPERSONANDORGANIZATIONASSIGNMENT
py::class_<RWStepAP214_RWAutoDesignPersonAndOrganizationAssignment> cls_RWStepAP214_RWAutoDesignPersonAndOrganizationAssignment(mod, "RWStepAP214_RWAutoDesignPersonAndOrganizationAssignment", "Read & Write Module for AutoDesignPersonAndOrganizationAssignment");

// Constructors
cls_RWStepAP214_RWAutoDesignPersonAndOrganizationAssignment.def(py::init<>());

// Methods
// cls_RWStepAP214_RWAutoDesignPersonAndOrganizationAssignment.def_static("operator new_", (void * (*)(size_t)) &RWStepAP214_RWAutoDesignPersonAndOrganizationAssignment::operator new, "None", py::arg("theSize"));
// cls_RWStepAP214_RWAutoDesignPersonAndOrganizationAssignment.def_static("operator delete_", (void (*)(void *)) &RWStepAP214_RWAutoDesignPersonAndOrganizationAssignment::operator delete, "None", py::arg("theAddress"));
// cls_RWStepAP214_RWAutoDesignPersonAndOrganizationAssignment.def_static("operator new[]_", (void * (*)(size_t)) &RWStepAP214_RWAutoDesignPersonAndOrganizationAssignment::operator new[], "None", py::arg("theSize"));
// cls_RWStepAP214_RWAutoDesignPersonAndOrganizationAssignment.def_static("operator delete[]_", (void (*)(void *)) &RWStepAP214_RWAutoDesignPersonAndOrganizationAssignment::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepAP214_RWAutoDesignPersonAndOrganizationAssignment.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepAP214_RWAutoDesignPersonAndOrganizationAssignment::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepAP214_RWAutoDesignPersonAndOrganizationAssignment.def_static("operator delete_", (void (*)(void *, void *)) &RWStepAP214_RWAutoDesignPersonAndOrganizationAssignment::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepAP214_RWAutoDesignPersonAndOrganizationAssignment.def("ReadStep", (void (RWStepAP214_RWAutoDesignPersonAndOrganizationAssignment::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepAP214_AutoDesignPersonAndOrganizationAssignment> &) const) &RWStepAP214_RWAutoDesignPersonAndOrganizationAssignment::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepAP214_RWAutoDesignPersonAndOrganizationAssignment.def("WriteStep", (void (RWStepAP214_RWAutoDesignPersonAndOrganizationAssignment::*)(StepData_StepWriter &, const opencascade::handle<StepAP214_AutoDesignPersonAndOrganizationAssignment> &) const) &RWStepAP214_RWAutoDesignPersonAndOrganizationAssignment::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepAP214_RWAutoDesignPersonAndOrganizationAssignment.def("Share", (void (RWStepAP214_RWAutoDesignPersonAndOrganizationAssignment::*)(const opencascade::handle<StepAP214_AutoDesignPersonAndOrganizationAssignment> &, Interface_EntityIterator &) const) &RWStepAP214_RWAutoDesignPersonAndOrganizationAssignment::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPAP214_RWAUTODESIGNPRESENTEDITEM
py::class_<RWStepAP214_RWAutoDesignPresentedItem> cls_RWStepAP214_RWAutoDesignPresentedItem(mod, "RWStepAP214_RWAutoDesignPresentedItem", "Read & Write Module for AutoDesignPresentedItem");

// Constructors
cls_RWStepAP214_RWAutoDesignPresentedItem.def(py::init<>());

// Methods
// cls_RWStepAP214_RWAutoDesignPresentedItem.def_static("operator new_", (void * (*)(size_t)) &RWStepAP214_RWAutoDesignPresentedItem::operator new, "None", py::arg("theSize"));
// cls_RWStepAP214_RWAutoDesignPresentedItem.def_static("operator delete_", (void (*)(void *)) &RWStepAP214_RWAutoDesignPresentedItem::operator delete, "None", py::arg("theAddress"));
// cls_RWStepAP214_RWAutoDesignPresentedItem.def_static("operator new[]_", (void * (*)(size_t)) &RWStepAP214_RWAutoDesignPresentedItem::operator new[], "None", py::arg("theSize"));
// cls_RWStepAP214_RWAutoDesignPresentedItem.def_static("operator delete[]_", (void (*)(void *)) &RWStepAP214_RWAutoDesignPresentedItem::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepAP214_RWAutoDesignPresentedItem.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepAP214_RWAutoDesignPresentedItem::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepAP214_RWAutoDesignPresentedItem.def_static("operator delete_", (void (*)(void *, void *)) &RWStepAP214_RWAutoDesignPresentedItem::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepAP214_RWAutoDesignPresentedItem.def("ReadStep", (void (RWStepAP214_RWAutoDesignPresentedItem::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepAP214_AutoDesignPresentedItem> &) const) &RWStepAP214_RWAutoDesignPresentedItem::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepAP214_RWAutoDesignPresentedItem.def("WriteStep", (void (RWStepAP214_RWAutoDesignPresentedItem::*)(StepData_StepWriter &, const opencascade::handle<StepAP214_AutoDesignPresentedItem> &) const) &RWStepAP214_RWAutoDesignPresentedItem::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepAP214_RWAutoDesignPresentedItem.def("Share", (void (RWStepAP214_RWAutoDesignPresentedItem::*)(const opencascade::handle<StepAP214_AutoDesignPresentedItem> &, Interface_EntityIterator &) const) &RWStepAP214_RWAutoDesignPresentedItem::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPAP214_RWAUTODESIGNSECURITYCLASSIFICATIONASSIGNMENT
py::class_<RWStepAP214_RWAutoDesignSecurityClassificationAssignment> cls_RWStepAP214_RWAutoDesignSecurityClassificationAssignment(mod, "RWStepAP214_RWAutoDesignSecurityClassificationAssignment", "Read & Write Module for AutoDesignSecurityClassificationAssignment");

// Constructors
cls_RWStepAP214_RWAutoDesignSecurityClassificationAssignment.def(py::init<>());

// Methods
// cls_RWStepAP214_RWAutoDesignSecurityClassificationAssignment.def_static("operator new_", (void * (*)(size_t)) &RWStepAP214_RWAutoDesignSecurityClassificationAssignment::operator new, "None", py::arg("theSize"));
// cls_RWStepAP214_RWAutoDesignSecurityClassificationAssignment.def_static("operator delete_", (void (*)(void *)) &RWStepAP214_RWAutoDesignSecurityClassificationAssignment::operator delete, "None", py::arg("theAddress"));
// cls_RWStepAP214_RWAutoDesignSecurityClassificationAssignment.def_static("operator new[]_", (void * (*)(size_t)) &RWStepAP214_RWAutoDesignSecurityClassificationAssignment::operator new[], "None", py::arg("theSize"));
// cls_RWStepAP214_RWAutoDesignSecurityClassificationAssignment.def_static("operator delete[]_", (void (*)(void *)) &RWStepAP214_RWAutoDesignSecurityClassificationAssignment::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepAP214_RWAutoDesignSecurityClassificationAssignment.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepAP214_RWAutoDesignSecurityClassificationAssignment::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepAP214_RWAutoDesignSecurityClassificationAssignment.def_static("operator delete_", (void (*)(void *, void *)) &RWStepAP214_RWAutoDesignSecurityClassificationAssignment::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepAP214_RWAutoDesignSecurityClassificationAssignment.def("ReadStep", (void (RWStepAP214_RWAutoDesignSecurityClassificationAssignment::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepAP214_AutoDesignSecurityClassificationAssignment> &) const) &RWStepAP214_RWAutoDesignSecurityClassificationAssignment::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepAP214_RWAutoDesignSecurityClassificationAssignment.def("WriteStep", (void (RWStepAP214_RWAutoDesignSecurityClassificationAssignment::*)(StepData_StepWriter &, const opencascade::handle<StepAP214_AutoDesignSecurityClassificationAssignment> &) const) &RWStepAP214_RWAutoDesignSecurityClassificationAssignment::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepAP214_RWAutoDesignSecurityClassificationAssignment.def("Share", (void (RWStepAP214_RWAutoDesignSecurityClassificationAssignment::*)(const opencascade::handle<StepAP214_AutoDesignSecurityClassificationAssignment> &, Interface_EntityIterator &) const) &RWStepAP214_RWAutoDesignSecurityClassificationAssignment::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPAP214_RWCLASS
py::class_<RWStepAP214_RWClass> cls_RWStepAP214_RWClass(mod, "RWStepAP214_RWClass", "Read & Write tool for Class");

// Constructors
cls_RWStepAP214_RWClass.def(py::init<>());

// Methods
// cls_RWStepAP214_RWClass.def_static("operator new_", (void * (*)(size_t)) &RWStepAP214_RWClass::operator new, "None", py::arg("theSize"));
// cls_RWStepAP214_RWClass.def_static("operator delete_", (void (*)(void *)) &RWStepAP214_RWClass::operator delete, "None", py::arg("theAddress"));
// cls_RWStepAP214_RWClass.def_static("operator new[]_", (void * (*)(size_t)) &RWStepAP214_RWClass::operator new[], "None", py::arg("theSize"));
// cls_RWStepAP214_RWClass.def_static("operator delete[]_", (void (*)(void *)) &RWStepAP214_RWClass::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepAP214_RWClass.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepAP214_RWClass::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepAP214_RWClass.def_static("operator delete_", (void (*)(void *, void *)) &RWStepAP214_RWClass::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepAP214_RWClass.def("ReadStep", (void (RWStepAP214_RWClass::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepAP214_Class> &) const) &RWStepAP214_RWClass::ReadStep, "Reads Class", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepAP214_RWClass.def("WriteStep", (void (RWStepAP214_RWClass::*)(StepData_StepWriter &, const opencascade::handle<StepAP214_Class> &) const) &RWStepAP214_RWClass::WriteStep, "Writes Class", py::arg("SW"), py::arg("ent"));
cls_RWStepAP214_RWClass.def("Share", (void (RWStepAP214_RWClass::*)(const opencascade::handle<StepAP214_Class> &, Interface_EntityIterator &) const) &RWStepAP214_RWClass::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPAP214_RWEXTERNALLYDEFINEDCLASS
py::class_<RWStepAP214_RWExternallyDefinedClass> cls_RWStepAP214_RWExternallyDefinedClass(mod, "RWStepAP214_RWExternallyDefinedClass", "Read & Write tool for ExternallyDefinedClass");

// Constructors
cls_RWStepAP214_RWExternallyDefinedClass.def(py::init<>());

// Methods
// cls_RWStepAP214_RWExternallyDefinedClass.def_static("operator new_", (void * (*)(size_t)) &RWStepAP214_RWExternallyDefinedClass::operator new, "None", py::arg("theSize"));
// cls_RWStepAP214_RWExternallyDefinedClass.def_static("operator delete_", (void (*)(void *)) &RWStepAP214_RWExternallyDefinedClass::operator delete, "None", py::arg("theAddress"));
// cls_RWStepAP214_RWExternallyDefinedClass.def_static("operator new[]_", (void * (*)(size_t)) &RWStepAP214_RWExternallyDefinedClass::operator new[], "None", py::arg("theSize"));
// cls_RWStepAP214_RWExternallyDefinedClass.def_static("operator delete[]_", (void (*)(void *)) &RWStepAP214_RWExternallyDefinedClass::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepAP214_RWExternallyDefinedClass.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepAP214_RWExternallyDefinedClass::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepAP214_RWExternallyDefinedClass.def_static("operator delete_", (void (*)(void *, void *)) &RWStepAP214_RWExternallyDefinedClass::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepAP214_RWExternallyDefinedClass.def("ReadStep", (void (RWStepAP214_RWExternallyDefinedClass::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepAP214_ExternallyDefinedClass> &) const) &RWStepAP214_RWExternallyDefinedClass::ReadStep, "Reads ExternallyDefinedClass", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepAP214_RWExternallyDefinedClass.def("WriteStep", (void (RWStepAP214_RWExternallyDefinedClass::*)(StepData_StepWriter &, const opencascade::handle<StepAP214_ExternallyDefinedClass> &) const) &RWStepAP214_RWExternallyDefinedClass::WriteStep, "Writes ExternallyDefinedClass", py::arg("SW"), py::arg("ent"));
cls_RWStepAP214_RWExternallyDefinedClass.def("Share", (void (RWStepAP214_RWExternallyDefinedClass::*)(const opencascade::handle<StepAP214_ExternallyDefinedClass> &, Interface_EntityIterator &) const) &RWStepAP214_RWExternallyDefinedClass::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPAP214_RWEXTERNALLYDEFINEDGENERALPROPERTY
py::class_<RWStepAP214_RWExternallyDefinedGeneralProperty> cls_RWStepAP214_RWExternallyDefinedGeneralProperty(mod, "RWStepAP214_RWExternallyDefinedGeneralProperty", "Read & Write tool for ExternallyDefinedGeneralProperty");

// Constructors
cls_RWStepAP214_RWExternallyDefinedGeneralProperty.def(py::init<>());

// Methods
// cls_RWStepAP214_RWExternallyDefinedGeneralProperty.def_static("operator new_", (void * (*)(size_t)) &RWStepAP214_RWExternallyDefinedGeneralProperty::operator new, "None", py::arg("theSize"));
// cls_RWStepAP214_RWExternallyDefinedGeneralProperty.def_static("operator delete_", (void (*)(void *)) &RWStepAP214_RWExternallyDefinedGeneralProperty::operator delete, "None", py::arg("theAddress"));
// cls_RWStepAP214_RWExternallyDefinedGeneralProperty.def_static("operator new[]_", (void * (*)(size_t)) &RWStepAP214_RWExternallyDefinedGeneralProperty::operator new[], "None", py::arg("theSize"));
// cls_RWStepAP214_RWExternallyDefinedGeneralProperty.def_static("operator delete[]_", (void (*)(void *)) &RWStepAP214_RWExternallyDefinedGeneralProperty::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepAP214_RWExternallyDefinedGeneralProperty.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepAP214_RWExternallyDefinedGeneralProperty::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepAP214_RWExternallyDefinedGeneralProperty.def_static("operator delete_", (void (*)(void *, void *)) &RWStepAP214_RWExternallyDefinedGeneralProperty::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepAP214_RWExternallyDefinedGeneralProperty.def("ReadStep", (void (RWStepAP214_RWExternallyDefinedGeneralProperty::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepAP214_ExternallyDefinedGeneralProperty> &) const) &RWStepAP214_RWExternallyDefinedGeneralProperty::ReadStep, "Reads ExternallyDefinedGeneralProperty", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepAP214_RWExternallyDefinedGeneralProperty.def("WriteStep", (void (RWStepAP214_RWExternallyDefinedGeneralProperty::*)(StepData_StepWriter &, const opencascade::handle<StepAP214_ExternallyDefinedGeneralProperty> &) const) &RWStepAP214_RWExternallyDefinedGeneralProperty::WriteStep, "Writes ExternallyDefinedGeneralProperty", py::arg("SW"), py::arg("ent"));
cls_RWStepAP214_RWExternallyDefinedGeneralProperty.def("Share", (void (RWStepAP214_RWExternallyDefinedGeneralProperty::*)(const opencascade::handle<StepAP214_ExternallyDefinedGeneralProperty> &, Interface_EntityIterator &) const) &RWStepAP214_RWExternallyDefinedGeneralProperty::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPAP214_RWREPITEMGROUP
py::class_<RWStepAP214_RWRepItemGroup> cls_RWStepAP214_RWRepItemGroup(mod, "RWStepAP214_RWRepItemGroup", "Read & Write tool for RepItemGroup");

// Constructors
cls_RWStepAP214_RWRepItemGroup.def(py::init<>());

// Methods
// cls_RWStepAP214_RWRepItemGroup.def_static("operator new_", (void * (*)(size_t)) &RWStepAP214_RWRepItemGroup::operator new, "None", py::arg("theSize"));
// cls_RWStepAP214_RWRepItemGroup.def_static("operator delete_", (void (*)(void *)) &RWStepAP214_RWRepItemGroup::operator delete, "None", py::arg("theAddress"));
// cls_RWStepAP214_RWRepItemGroup.def_static("operator new[]_", (void * (*)(size_t)) &RWStepAP214_RWRepItemGroup::operator new[], "None", py::arg("theSize"));
// cls_RWStepAP214_RWRepItemGroup.def_static("operator delete[]_", (void (*)(void *)) &RWStepAP214_RWRepItemGroup::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepAP214_RWRepItemGroup.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepAP214_RWRepItemGroup::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepAP214_RWRepItemGroup.def_static("operator delete_", (void (*)(void *, void *)) &RWStepAP214_RWRepItemGroup::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepAP214_RWRepItemGroup.def("ReadStep", (void (RWStepAP214_RWRepItemGroup::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepAP214_RepItemGroup> &) const) &RWStepAP214_RWRepItemGroup::ReadStep, "Reads RepItemGroup", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepAP214_RWRepItemGroup.def("WriteStep", (void (RWStepAP214_RWRepItemGroup::*)(StepData_StepWriter &, const opencascade::handle<StepAP214_RepItemGroup> &) const) &RWStepAP214_RWRepItemGroup::WriteStep, "Writes RepItemGroup", py::arg("SW"), py::arg("ent"));
cls_RWStepAP214_RWRepItemGroup.def("Share", (void (RWStepAP214_RWRepItemGroup::*)(const opencascade::handle<StepAP214_RepItemGroup> &, Interface_EntityIterator &) const) &RWStepAP214_RWRepItemGroup::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));


}
