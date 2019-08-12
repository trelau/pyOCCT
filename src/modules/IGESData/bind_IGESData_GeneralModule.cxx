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
#include <Interface_GeneralModule.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Transient.hxx>
#include <Interface_EntityIterator.hxx>
#include <IGESData_IGESEntity.hxx>
#include <Interface_ShareTool.hxx>
#include <Interface_Check.hxx>
#include <IGESData_DirChecker.hxx>
#include <Interface_CopyTool.hxx>
#include <TCollection_HAsciiString.hxx>
#include <IGESData_GeneralModule.hxx>
#include <Standard_Type.hxx>

void bind_IGESData_GeneralModule(py::module &mod){

py::class_<IGESData_GeneralModule, opencascade::handle<IGESData_GeneralModule>, Interface_GeneralModule> cls_IGESData_GeneralModule(mod, "IGESData_GeneralModule", "Definition of General Services adapted to IGES. This Services comprise : Shared & Implied Lists, Copy, Check They are adapted according to the organisation of IGES Entities : Directory Part, Lists of Associativities and Properties are specifically processed");

// Fields

// Methods
cls_IGESData_GeneralModule.def("FillSharedCase", (void (IGESData_GeneralModule::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, Interface_EntityIterator &) const) &IGESData_GeneralModule::FillSharedCase, "Fills the list of Entities shared by an IGESEntity <ent>, according a Case Number <CN> (formerly computed by CaseNum). Considers Properties and Directory Part, and calls OwnSharedCase (which is adapted to each Type of Entity)", py::arg("CN"), py::arg("ent"), py::arg("iter"));
cls_IGESData_GeneralModule.def("OwnSharedCase", (void (IGESData_GeneralModule::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &, Interface_EntityIterator &) const) &IGESData_GeneralModule::OwnSharedCase, "Lists the Entities shared by a given IGESEntity <ent>, from its specific parameters : specific for each type", py::arg("CN"), py::arg("ent"), py::arg("iter"));
cls_IGESData_GeneralModule.def("ListImpliedCase", (void (IGESData_GeneralModule::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, Interface_EntityIterator &) const) &IGESData_GeneralModule::ListImpliedCase, "Lists the Implied References of <ent>. Here, these are the Associativities, plus the Entities defined by OwnSharedCase", py::arg("CN"), py::arg("ent"), py::arg("iter"));
cls_IGESData_GeneralModule.def("OwnImpliedCase", (void (IGESData_GeneralModule::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &, Interface_EntityIterator &) const) &IGESData_GeneralModule::OwnImpliedCase, "Specific list of Entities implied by a given IGESEntity <ent> (in addition to Associativities). By default, there are none, but this method can be redefined as required", py::arg("CN"), py::arg("ent"), py::arg("iter"));
cls_IGESData_GeneralModule.def("CheckCase", (void (IGESData_GeneralModule::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const) &IGESData_GeneralModule::CheckCase, "Semantic Checking of an IGESEntity. Performs general Checks, which use DirChecker, then call OwnCheck which does a check specific for each type of Entity", py::arg("CN"), py::arg("ent"), py::arg("shares"), py::arg("ach"));
cls_IGESData_GeneralModule.def("DirChecker", (IGESData_DirChecker (IGESData_GeneralModule::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &) const) &IGESData_GeneralModule::DirChecker, "Returns a DirChecker, specific for each type of Entity (identified by its Case Number) : this DirChecker defines constraints which must be respected by the DirectoryPart", py::arg("CN"), py::arg("ent"));
cls_IGESData_GeneralModule.def("OwnCheckCase", (void (IGESData_GeneralModule::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const) &IGESData_GeneralModule::OwnCheckCase, "Performs Specific Semantic Check for each type of Entity", py::arg("CN"), py::arg("ent"), py::arg("shares"), py::arg("ach"));
cls_IGESData_GeneralModule.def("CanCopy", (Standard_Boolean (IGESData_GeneralModule::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &) const) &IGESData_GeneralModule::CanCopy, "Specific answer to the question 'is Copy properly implemented' For IGES, answer is always True", py::arg("CN"), py::arg("ent"));
cls_IGESData_GeneralModule.def("NewVoid", (Standard_Boolean (IGESData_GeneralModule::*)(const Standard_Integer, opencascade::handle<Standard_Transient> &) const) &IGESData_GeneralModule::NewVoid, "Specific creation of a new void entity", py::arg("CN"), py::arg("entto"));
cls_IGESData_GeneralModule.def("CopyCase", (void (IGESData_GeneralModule::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const opencascade::handle<Standard_Transient> &, Interface_CopyTool &) const) &IGESData_GeneralModule::CopyCase, "Copy ('Deep') from <entfrom> to <entto> (same type) by using a CopyTool which provides its working Map. For IGESEntities, Copies general data (Directory Part, List of Properties) and call OwnCopyCase", py::arg("CN"), py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_IGESData_GeneralModule.def("OwnCopyCase", (void (IGESData_GeneralModule::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &, const opencascade::handle<IGESData_IGESEntity> &, Interface_CopyTool &) const) &IGESData_GeneralModule::OwnCopyCase, "Copies parameters which are specific of each Type of Entity", py::arg("CN"), py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_IGESData_GeneralModule.def("RenewImpliedCase", (void (IGESData_GeneralModule::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const opencascade::handle<Standard_Transient> &, const Interface_CopyTool &) const) &IGESData_GeneralModule::RenewImpliedCase, "Renewing of Implied References. For IGESEntities, Copies general data(List of Associativities) and calls OwnRenewCase", py::arg("CN"), py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_IGESData_GeneralModule.def("OwnRenewCase", (void (IGESData_GeneralModule::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &, const opencascade::handle<IGESData_IGESEntity> &, const Interface_CopyTool &) const) &IGESData_GeneralModule::OwnRenewCase, "Renews parameters which are specific of each Type of Entity : the provided default does nothing, but this method may be redefined as required", py::arg("CN"), py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_IGESData_GeneralModule.def("WhenDeleteCase", (void (IGESData_GeneralModule::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const Standard_Boolean) const) &IGESData_GeneralModule::WhenDeleteCase, "Prepares an IGES Entity for delete : works on directory part then calls OwnDeleteCase While dispatch requires to copy the entities, <dispatched> is ignored, entities are cleared in any case", py::arg("CN"), py::arg("ent"), py::arg("dispatched"));
cls_IGESData_GeneralModule.def("OwnDeleteCase", (void (IGESData_GeneralModule::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &) const) &IGESData_GeneralModule::OwnDeleteCase, "Specific preparation for delete, acts on own parameters Default does nothing, to be redefined as required", py::arg("CN"), py::arg("ent"));
cls_IGESData_GeneralModule.def("Name", (opencascade::handle<TCollection_HAsciiString> (IGESData_GeneralModule::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const Interface_ShareTool &) const) &IGESData_GeneralModule::Name, "Returns the name of an IGES Entity (its NameValue) Can be redefined for an even more specific case ...", py::arg("CN"), py::arg("ent"), py::arg("shares"));
cls_IGESData_GeneralModule.def_static("get_type_name_", (const char * (*)()) &IGESData_GeneralModule::get_type_name, "None");
cls_IGESData_GeneralModule.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESData_GeneralModule::get_type_descriptor, "None");
cls_IGESData_GeneralModule.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESData_GeneralModule::*)() const) &IGESData_GeneralModule::DynamicType, "None");

// Enums

}