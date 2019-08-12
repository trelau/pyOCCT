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
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <Interface_InterfaceModel.hxx>
#include <Standard_TypeDef.hxx>
#include <Interface_EntityIterator.hxx>
#include <Interface_ShareTool.hxx>
#include <Interface_Check.hxx>
#include <Interface_CopyTool.hxx>
#include <TCollection_HAsciiString.hxx>
#include <Interface_GeneralModule.hxx>
#include <Standard_Type.hxx>

void bind_Interface_GeneralModule(py::module &mod){

py::class_<Interface_GeneralModule, opencascade::handle<Interface_GeneralModule>, Standard_Transient> cls_Interface_GeneralModule(mod, "Interface_GeneralModule", "This class defines general services, which must be provided for each type of Entity (i.e. of Transient Object processed by an Interface) : Shared List, Check, Copy, Delete, Category");

// Fields

// Methods
cls_Interface_GeneralModule.def("FillShared", (void (Interface_GeneralModule::*)(const opencascade::handle<Interface_InterfaceModel> &, const Standard_Integer, const opencascade::handle<Standard_Transient> &, Interface_EntityIterator &) const) &Interface_GeneralModule::FillShared, "Specific filling of the list of Entities shared by an Entity <ent>, according a Case Number <CN> (formerly computed by CaseNum), considered in the context of a Model <model> Default calls FillSharedCase (i.e., ignores the model) Can be redefined to use the model for working", py::arg("model"), py::arg("CN"), py::arg("ent"), py::arg("iter"));
cls_Interface_GeneralModule.def("FillSharedCase", (void (Interface_GeneralModule::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, Interface_EntityIterator &) const) &Interface_GeneralModule::FillSharedCase, "Specific filling of the list of Entities shared by an Entity <ent>, according a Case Number <CN> (formerly computed by CaseNum). Can use the internal utility method Share, below", py::arg("CN"), py::arg("ent"), py::arg("iter"));
cls_Interface_GeneralModule.def("Share", (void (Interface_GeneralModule::*)(Interface_EntityIterator &, const opencascade::handle<Standard_Transient> &) const) &Interface_GeneralModule::Share, "Adds an Entity to a Shared List (uses GetOneItem on <iter>)", py::arg("iter"), py::arg("shared"));
cls_Interface_GeneralModule.def("ListImplied", (void (Interface_GeneralModule::*)(const opencascade::handle<Interface_InterfaceModel> &, const Standard_Integer, const opencascade::handle<Standard_Transient> &, Interface_EntityIterator &) const) &Interface_GeneralModule::ListImplied, "List the Implied References of <ent> considered in the context of a Model <model> : i.e. the Entities which are Referenced while not considered as Shared (not copied if <ent> is, references not renewed by CopyCase but by ImpliedCase, only if referenced Entities have been Copied too) FillShared + ListImplied give the complete list of References Default calls ListImpliedCase (i.e. ignores the model) Can be redefined to use the model for working", py::arg("model"), py::arg("CN"), py::arg("ent"), py::arg("iter"));
cls_Interface_GeneralModule.def("ListImpliedCase", (void (Interface_GeneralModule::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, Interface_EntityIterator &) const) &Interface_GeneralModule::ListImpliedCase, "List the Implied References of <ent> (see above) are Referenced while not considered as Shared (not copied if <ent> is, references not renewed by CopyCase but by ImpliedCase, only if referenced Entities have been Copied too) FillSharedCase + ListImpliedCase give the complete list of Referenced Entities The provided default method does nothing (Implied References are specific of a little amount of Entity Classes).", py::arg("CN"), py::arg("ent"), py::arg("iter"));
cls_Interface_GeneralModule.def("CheckCase", (void (Interface_GeneralModule::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const) &Interface_GeneralModule::CheckCase, "Specific Checking of an Entity <ent> Can check context queried through a ShareTool, as required", py::arg("CN"), py::arg("ent"), py::arg("shares"), py::arg("ach"));
cls_Interface_GeneralModule.def("CanCopy", (Standard_Boolean (Interface_GeneralModule::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &) const) &Interface_GeneralModule::CanCopy, "Specific answer to the question 'is Copy properly implemented' Remark that it should be in phase with the implementation of NewVoid+CopyCase/NewCopyCase Default returns always False, can be redefined", py::arg("CN"), py::arg("ent"));
cls_Interface_GeneralModule.def("Dispatch", (Standard_Boolean (Interface_GeneralModule::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, opencascade::handle<Standard_Transient> &, Interface_CopyTool &) const) &Interface_GeneralModule::Dispatch, "Dispatches an entity Returns True if it works by copy, False if it just duplicates the starting Handle", py::arg("CN"), py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_Interface_GeneralModule.def("NewVoid", (Standard_Boolean (Interface_GeneralModule::*)(const Standard_Integer, opencascade::handle<Standard_Transient> &) const) &Interface_GeneralModule::NewVoid, "Creates a new void entity <entto> according to a Case Number This entity remains to be filled, by reading from a file or by copying from another entity of same type (see CopyCase)", py::arg("CN"), py::arg("entto"));
cls_Interface_GeneralModule.def("CopyCase", (void (Interface_GeneralModule::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const opencascade::handle<Standard_Transient> &, Interface_CopyTool &) const) &Interface_GeneralModule::CopyCase, "Specific Copy ('Deep') from <entfrom> to <entto> (same type) by using a CopyTool which provides its working Map. Use method Transferred from CopyTool to work", py::arg("CN"), py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_Interface_GeneralModule.def("NewCopiedCase", (Standard_Boolean (Interface_GeneralModule::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, opencascade::handle<Standard_Transient> &, Interface_CopyTool &) const) &Interface_GeneralModule::NewCopiedCase, "Specific operator (create+copy) defaulted to do nothing. It can be redefined : When it is not possible to work in two steps (NewVoid then CopyCase). This can occur when there is no default constructor : hence the result <entto> must be created with an effective definition. Remark : if NewCopiedCase is defined, CopyCase has nothing to do Returns True if it has produced something, false else", py::arg("CN"), py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_Interface_GeneralModule.def("RenewImpliedCase", (void (Interface_GeneralModule::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const opencascade::handle<Standard_Transient> &, const Interface_CopyTool &) const) &Interface_GeneralModule::RenewImpliedCase, "Specific Copying of Implied References A Default is provided which does nothing (must current case !) Already copied references (by CopyFrom) must remain unchanged Use method Search from CopyTool to work", py::arg("CN"), py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_Interface_GeneralModule.def("WhenDeleteCase", (void (Interface_GeneralModule::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const Standard_Boolean) const) &Interface_GeneralModule::WhenDeleteCase, "Prepares an entity to be deleted. What does it mean : Basically, any class of entity may define its own destructor By default, it does nothing but calling destructors on fields With the Memory Manager, it is useless to call destructor, it is done automatically when the Handle is nullified(cleared) BUT this is ineffective in looping structures (whatever these are 'Implied' references or not).", py::arg("CN"), py::arg("ent"), py::arg("dispatched"));
cls_Interface_GeneralModule.def("CategoryNumber", (Standard_Integer (Interface_GeneralModule::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const Interface_ShareTool &) const) &Interface_GeneralModule::CategoryNumber, "Returns a category number which characterizes an entity Category Numbers are managed by the class Category <shares> can be used to evaluate this number in the context Default returns 0 which means 'unspecified'", py::arg("CN"), py::arg("ent"), py::arg("shares"));
cls_Interface_GeneralModule.def("Name", (opencascade::handle<TCollection_HAsciiString> (Interface_GeneralModule::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const Interface_ShareTool &) const) &Interface_GeneralModule::Name, "Determines if an entity brings a Name (or widerly, if a Name can be attached to it, through the ShareTool By default, returns a Null Handle (no name can be produced) Can be redefined", py::arg("CN"), py::arg("ent"), py::arg("shares"));
cls_Interface_GeneralModule.def_static("get_type_name_", (const char * (*)()) &Interface_GeneralModule::get_type_name, "None");
cls_Interface_GeneralModule.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Interface_GeneralModule::get_type_descriptor, "None");
cls_Interface_GeneralModule.def("DynamicType", (const opencascade::handle<Standard_Type> & (Interface_GeneralModule::*)() const) &Interface_GeneralModule::DynamicType, "None");

// Enums

}