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
#include <IGESData_DefaultGeneral.hxx>
#include <Standard_Type.hxx>

void bind_IGESData_DefaultGeneral(py::module &mod){

py::class_<IGESData_DefaultGeneral, opencascade::handle<IGESData_DefaultGeneral>, IGESData_GeneralModule> cls_IGESData_DefaultGeneral(mod, "IGESData_DefaultGeneral", "Processes the specific case of UndefinedEntity from IGESData (Case Number 1)");

// Constructors
cls_IGESData_DefaultGeneral.def(py::init<>());

// Fields

// Methods
cls_IGESData_DefaultGeneral.def("OwnSharedCase", (void (IGESData_DefaultGeneral::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &, Interface_EntityIterator &) const) &IGESData_DefaultGeneral::OwnSharedCase, "Lists the Entities shared by an IGESEntity, which must be an UndefinedEntity", py::arg("CN"), py::arg("ent"), py::arg("iter"));
cls_IGESData_DefaultGeneral.def("DirChecker", (IGESData_DirChecker (IGESData_DefaultGeneral::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &) const) &IGESData_DefaultGeneral::DirChecker, "Returns a DirChecker, specific for each type of Entity Here, Returns an empty DirChecker (no constraint to check)", py::arg("CN"), py::arg("ent"));
cls_IGESData_DefaultGeneral.def("OwnCheckCase", (void (IGESData_DefaultGeneral::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const) &IGESData_DefaultGeneral::OwnCheckCase, "Performs Specific Semantic Check for each type of Entity Here, does nothing (no constraint to check)", py::arg("CN"), py::arg("ent"), py::arg("shares"), py::arg("ach"));
cls_IGESData_DefaultGeneral.def("NewVoid", (Standard_Boolean (IGESData_DefaultGeneral::*)(const Standard_Integer, opencascade::handle<Standard_Transient> &) const) &IGESData_DefaultGeneral::NewVoid, "Specific creation of a new void entity (UndefinedEntity only)", py::arg("CN"), py::arg("entto"));
cls_IGESData_DefaultGeneral.def("OwnCopyCase", (void (IGESData_DefaultGeneral::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &, const opencascade::handle<IGESData_IGESEntity> &, Interface_CopyTool &) const) &IGESData_DefaultGeneral::OwnCopyCase, "Copies parameters which are specific of each Type of Entity", py::arg("CN"), py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_IGESData_DefaultGeneral.def_static("get_type_name_", (const char * (*)()) &IGESData_DefaultGeneral::get_type_name, "None");
cls_IGESData_DefaultGeneral.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESData_DefaultGeneral::get_type_descriptor, "None");
cls_IGESData_DefaultGeneral.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESData_DefaultGeneral::*)() const) &IGESData_DefaultGeneral::DynamicType, "None");

// Enums

}