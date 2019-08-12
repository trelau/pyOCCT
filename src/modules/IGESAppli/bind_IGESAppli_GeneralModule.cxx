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
#include <IGESData_GeneralModule.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <IGESData_IGESEntity.hxx>
#include <Interface_EntityIterator.hxx>
#include <IGESData_DirChecker.hxx>
#include <Interface_ShareTool.hxx>
#include <Interface_Check.hxx>
#include <Standard_Transient.hxx>
#include <Interface_CopyTool.hxx>
#include <IGESAppli_GeneralModule.hxx>
#include <Standard_Type.hxx>

void bind_IGESAppli_GeneralModule(py::module &mod){

py::class_<IGESAppli_GeneralModule, opencascade::handle<IGESAppli_GeneralModule>, IGESData_GeneralModule> cls_IGESAppli_GeneralModule(mod, "IGESAppli_GeneralModule", "Definition of General Services for IGESAppli (specific part) This Services comprise : Shared & Implied Lists, Copy, Check");

// Constructors
cls_IGESAppli_GeneralModule.def(py::init<>());

// Fields

// Methods
cls_IGESAppli_GeneralModule.def("OwnSharedCase", (void (IGESAppli_GeneralModule::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &, Interface_EntityIterator &) const) &IGESAppli_GeneralModule::OwnSharedCase, "Lists the Entities shared by a given IGESEntity <ent>, from its specific parameters : specific for each type", py::arg("CN"), py::arg("ent"), py::arg("iter"));
cls_IGESAppli_GeneralModule.def("DirChecker", (IGESData_DirChecker (IGESAppli_GeneralModule::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &) const) &IGESAppli_GeneralModule::DirChecker, "Returns a DirChecker, specific for each type of Entity (identified by its Case Number) : this DirChecker defines constraints which must be respected by the DirectoryPart", py::arg("CN"), py::arg("ent"));
cls_IGESAppli_GeneralModule.def("OwnCheckCase", (void (IGESAppli_GeneralModule::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const) &IGESAppli_GeneralModule::OwnCheckCase, "Performs Specific Semantic Check for each type of Entity", py::arg("CN"), py::arg("ent"), py::arg("shares"), py::arg("ach"));
cls_IGESAppli_GeneralModule.def("NewVoid", (Standard_Boolean (IGESAppli_GeneralModule::*)(const Standard_Integer, opencascade::handle<Standard_Transient> &) const) &IGESAppli_GeneralModule::NewVoid, "Specific creation of a new void entity", py::arg("CN"), py::arg("entto"));
cls_IGESAppli_GeneralModule.def("OwnCopyCase", (void (IGESAppli_GeneralModule::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &, const opencascade::handle<IGESData_IGESEntity> &, Interface_CopyTool &) const) &IGESAppli_GeneralModule::OwnCopyCase, "Copies parameters which are specific of each Type of Entity", py::arg("CN"), py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_IGESAppli_GeneralModule.def("CategoryNumber", (Standard_Integer (IGESAppli_GeneralModule::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const Interface_ShareTool &) const) &IGESAppli_GeneralModule::CategoryNumber, "Returns a category number which characterizes an entity FEA for : ElementResults,FiniteElement,Node&Co Piping for : Flow & Co Professional for : others (in fact Schematics)", py::arg("CN"), py::arg("ent"), py::arg("shares"));
cls_IGESAppli_GeneralModule.def_static("get_type_name_", (const char * (*)()) &IGESAppli_GeneralModule::get_type_name, "None");
cls_IGESAppli_GeneralModule.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESAppli_GeneralModule::get_type_descriptor, "None");
cls_IGESAppli_GeneralModule.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESAppli_GeneralModule::*)() const) &IGESAppli_GeneralModule::DynamicType, "None");

// Enums

}