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
#include <IGESGeom_GeneralModule.hxx>
#include <Standard_Type.hxx>

void bind_IGESGeom_GeneralModule(py::module &mod){

py::class_<IGESGeom_GeneralModule, opencascade::handle<IGESGeom_GeneralModule>, IGESData_GeneralModule> cls_IGESGeom_GeneralModule(mod, "IGESGeom_GeneralModule", "Definition of General Services for IGESGeom (specific part) This Services comprise : Shared & Implied Lists, Copy, Check");

// Constructors
cls_IGESGeom_GeneralModule.def(py::init<>());

// Fields

// Methods
cls_IGESGeom_GeneralModule.def("OwnSharedCase", (void (IGESGeom_GeneralModule::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &, Interface_EntityIterator &) const) &IGESGeom_GeneralModule::OwnSharedCase, "Lists the Entities shared by a given IGESEntity <ent>, from its specific parameters : specific for each type", py::arg("CN"), py::arg("ent"), py::arg("iter"));
cls_IGESGeom_GeneralModule.def("DirChecker", (IGESData_DirChecker (IGESGeom_GeneralModule::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &) const) &IGESGeom_GeneralModule::DirChecker, "Returns a DirChecker, specific for each type of Entity (identified by its Case Number) : this DirChecker defines constraints which must be respected by the DirectoryPart", py::arg("CN"), py::arg("ent"));
cls_IGESGeom_GeneralModule.def("OwnCheckCase", (void (IGESGeom_GeneralModule::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const) &IGESGeom_GeneralModule::OwnCheckCase, "Performs Specific Semantic Check for each type of Entity", py::arg("CN"), py::arg("ent"), py::arg("shares"), py::arg("ach"));
cls_IGESGeom_GeneralModule.def("NewVoid", (Standard_Boolean (IGESGeom_GeneralModule::*)(const Standard_Integer, opencascade::handle<Standard_Transient> &) const) &IGESGeom_GeneralModule::NewVoid, "Specific creation of a new void entity", py::arg("CN"), py::arg("entto"));
cls_IGESGeom_GeneralModule.def("OwnCopyCase", (void (IGESGeom_GeneralModule::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &, const opencascade::handle<IGESData_IGESEntity> &, Interface_CopyTool &) const) &IGESGeom_GeneralModule::OwnCopyCase, "Copies parameters which are specific of each Type of Entity", py::arg("CN"), py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_IGESGeom_GeneralModule.def("CategoryNumber", (Standard_Integer (IGESGeom_GeneralModule::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const Interface_ShareTool &) const) &IGESGeom_GeneralModule::CategoryNumber, "Returns a category number which characterizes an entity Shape for all, but Drawing for : Flash; Point with a symbol; Plane with a symbol", py::arg("CN"), py::arg("ent"), py::arg("shares"));
cls_IGESGeom_GeneralModule.def_static("get_type_name_", (const char * (*)()) &IGESGeom_GeneralModule::get_type_name, "None");
cls_IGESGeom_GeneralModule.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESGeom_GeneralModule::get_type_descriptor, "None");
cls_IGESGeom_GeneralModule.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESGeom_GeneralModule::*)() const) &IGESGeom_GeneralModule::DynamicType, "None");

// Enums

}