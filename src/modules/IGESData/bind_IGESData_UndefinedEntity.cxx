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
#include <IGESData_IGESEntity.hxx>
#include <Standard_Handle.hxx>
#include <Interface_UndefinedContent.hxx>
#include <Standard_TypeDef.hxx>
#include <IGESData_DefType.hxx>
#include <IGESData_DefList.hxx>
#include <IGESData_IGESReaderData.hxx>
#include <IGESData_DirPart.hxx>
#include <Interface_Check.hxx>
#include <IGESData_ParamReader.hxx>
#include <IGESData_IGESWriter.hxx>
#include <IGESData_UndefinedEntity.hxx>
#include <Standard_Type.hxx>

void bind_IGESData_UndefinedEntity(py::module &mod){

py::class_<IGESData_UndefinedEntity, opencascade::handle<IGESData_UndefinedEntity>, IGESData_IGESEntity> cls_IGESData_UndefinedEntity(mod, "IGESData_UndefinedEntity", "undefined (unknown or error) entity specific of IGES DirPart can be correct or not : if it is not, a flag indicates it, and each corrupted field has an associated error flag");

// Constructors
cls_IGESData_UndefinedEntity.def(py::init<>());

// Fields

// Methods
cls_IGESData_UndefinedEntity.def("UndefinedContent", (opencascade::handle<Interface_UndefinedContent> (IGESData_UndefinedEntity::*)() const) &IGESData_UndefinedEntity::UndefinedContent, "Returns own data as an UndefinedContent");
cls_IGESData_UndefinedEntity.def("ChangeableContent", (opencascade::handle<Interface_UndefinedContent> (IGESData_UndefinedEntity::*)()) &IGESData_UndefinedEntity::ChangeableContent, "Returns own data as an UndefinedContent, in order to touch it");
cls_IGESData_UndefinedEntity.def("SetNewContent", (void (IGESData_UndefinedEntity::*)(const opencascade::handle<Interface_UndefinedContent> &)) &IGESData_UndefinedEntity::SetNewContent, "Redefines a completely new UndefinedContent Used by a Copy which begins by ShallowCopy, for instance", py::arg("cont"));
cls_IGESData_UndefinedEntity.def("IsOKDirPart", (Standard_Boolean (IGESData_UndefinedEntity::*)() const) &IGESData_UndefinedEntity::IsOKDirPart, "says if DirPart is OK or not (if not, it is erroneous) Note that if it is not, Def* methods can return Error status");
cls_IGESData_UndefinedEntity.def("DirStatus", (Standard_Integer (IGESData_UndefinedEntity::*)() const) &IGESData_UndefinedEntity::DirStatus, "returns Directory Error Status (used for Copy)");
cls_IGESData_UndefinedEntity.def("SetOKDirPart", (void (IGESData_UndefinedEntity::*)()) &IGESData_UndefinedEntity::SetOKDirPart, "Erases the Directory Error Status Warning : Be sure that data are consistent to call this method ...");
cls_IGESData_UndefinedEntity.def("DefLineFont", (IGESData_DefType (IGESData_UndefinedEntity::*)() const) &IGESData_UndefinedEntity::DefLineFont, "returns Error status if necessary, else calls original method");
cls_IGESData_UndefinedEntity.def("DefLevel", (IGESData_DefList (IGESData_UndefinedEntity::*)() const) &IGESData_UndefinedEntity::DefLevel, "returns Error status if necessary, else calls original method");
cls_IGESData_UndefinedEntity.def("DefView", (IGESData_DefList (IGESData_UndefinedEntity::*)() const) &IGESData_UndefinedEntity::DefView, "returns Error status if necessary, else calls original method");
cls_IGESData_UndefinedEntity.def("DefColor", (IGESData_DefType (IGESData_UndefinedEntity::*)() const) &IGESData_UndefinedEntity::DefColor, "returns Error status if necessary, else calls original method");
cls_IGESData_UndefinedEntity.def("HasSubScriptNumber", (Standard_Boolean (IGESData_UndefinedEntity::*)() const) &IGESData_UndefinedEntity::HasSubScriptNumber, "returns Error status if necessary, else calls original method (that is, if SubScript field is not blank or positive integer)");
cls_IGESData_UndefinedEntity.def("ReadDir", (Standard_Boolean (IGESData_UndefinedEntity::*)(const opencascade::handle<IGESData_IGESReaderData> &, IGESData_DirPart &, opencascade::handle<Interface_Check> &)) &IGESData_UndefinedEntity::ReadDir, "Computes the Directory Error Status, to be called before standard ReadDir from IGESReaderTool Returns True if OK (hence, Directory can be loaded), Else returns False and the DirPart <DP> is modified (hence, Directory Error Status is non null; and standard Read will work with an acceptable DirectoryPart)", py::arg("IR"), py::arg("DP"), py::arg("ach"));
cls_IGESData_UndefinedEntity.def("ReadOwnParams", (void (IGESData_UndefinedEntity::*)(const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &)) &IGESData_UndefinedEntity::ReadOwnParams, "reads own parameters from file; PR gives access to them, IR detains parameter types and values Here, reads all parameters, integers are considered as entity reference unless they cannot be; no list interpretation No property or associativity list is managed", py::arg("IR"), py::arg("PR"));
cls_IGESData_UndefinedEntity.def("WriteOwnParams", (void (IGESData_UndefinedEntity::*)(IGESData_IGESWriter &) const) &IGESData_UndefinedEntity::WriteOwnParams, "writes parameters to IGESWriter, taken from UndefinedContent", py::arg("IW"));
cls_IGESData_UndefinedEntity.def_static("get_type_name_", (const char * (*)()) &IGESData_UndefinedEntity::get_type_name, "None");
cls_IGESData_UndefinedEntity.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESData_UndefinedEntity::get_type_descriptor, "None");
cls_IGESData_UndefinedEntity.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESData_UndefinedEntity::*)() const) &IGESData_UndefinedEntity::DynamicType, "None");

// Enums

}