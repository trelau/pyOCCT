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
#include <Interface_InterfaceModel.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Transient.hxx>
#include <Standard_TypeDef.hxx>
#include <Interface_EntityIterator.hxx>
#include <Standard_Type.hxx>
#include <Interface_Check.hxx>
#include <Message_Messenger.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepData_StepModel.hxx>
#include <Interface_EntityList.hxx>
#include <TColStd_HArray1OfInteger.hxx>

void bind_StepData_StepModel(py::module &mod){

py::class_<StepData_StepModel, opencascade::handle<StepData_StepModel>, Interface_InterfaceModel> cls_StepData_StepModel(mod, "StepData_StepModel", "Gives access to - entities in a STEP file, - the STEP file header.");

// Constructors
cls_StepData_StepModel.def(py::init<>());

// Fields

// Methods
cls_StepData_StepModel.def("Entity", (opencascade::handle<Standard_Transient> (StepData_StepModel::*)(const Standard_Integer) const) &StepData_StepModel::Entity, "returns entity given its rank. Same as InterfaceEntity, but with a shorter name", py::arg("num"));
cls_StepData_StepModel.def("GetFromAnother", (void (StepData_StepModel::*)(const opencascade::handle<Interface_InterfaceModel> &)) &StepData_StepModel::GetFromAnother, "gets header from another Model (uses Header Protocol)", py::arg("other"));
cls_StepData_StepModel.def("NewEmptyModel", (opencascade::handle<Interface_InterfaceModel> (StepData_StepModel::*)() const) &StepData_StepModel::NewEmptyModel, "Returns a New Empty Model, same type as <me>, i.e. StepModel");
cls_StepData_StepModel.def("Header", (Interface_EntityIterator (StepData_StepModel::*)() const) &StepData_StepModel::Header, "returns Header entities under the form of an iterator");
cls_StepData_StepModel.def("HasHeaderEntity", (Standard_Boolean (StepData_StepModel::*)(const opencascade::handle<Standard_Type> &) const) &StepData_StepModel::HasHeaderEntity, "says if a Header entity has a specifed type", py::arg("atype"));
cls_StepData_StepModel.def("HeaderEntity", (opencascade::handle<Standard_Transient> (StepData_StepModel::*)(const opencascade::handle<Standard_Type> &) const) &StepData_StepModel::HeaderEntity, "Returns Header entity with specified type, if there is", py::arg("atype"));
cls_StepData_StepModel.def("ClearHeader", (void (StepData_StepModel::*)()) &StepData_StepModel::ClearHeader, "Clears the Header");
cls_StepData_StepModel.def("AddHeaderEntity", (void (StepData_StepModel::*)(const opencascade::handle<Standard_Transient> &)) &StepData_StepModel::AddHeaderEntity, "Adds an Entity to the Header", py::arg("ent"));
cls_StepData_StepModel.def("VerifyCheck", (void (StepData_StepModel::*)(opencascade::handle<Interface_Check> &) const) &StepData_StepModel::VerifyCheck, "Specific Check, checks Header Items with HeaderProtocol", py::arg("ach"));
cls_StepData_StepModel.def("DumpHeader", [](StepData_StepModel &self, const opencascade::handle<Message_Messenger> & a0) -> void { return self.DumpHeader(a0); });
cls_StepData_StepModel.def("DumpHeader", (void (StepData_StepModel::*)(const opencascade::handle<Message_Messenger> &, const Standard_Integer) const) &StepData_StepModel::DumpHeader, "Dumps the Header, with the Header Protocol of StepData. If the Header Protocol is not defined, for each Header Entity, prints its Type. Else sends the Header under the form of HEADER Section of an Ascii Step File <level> is not used because Header is not so big", py::arg("S"), py::arg("level"));
cls_StepData_StepModel.def("ClearLabels", (void (StepData_StepModel::*)()) &StepData_StepModel::ClearLabels, "erases specific labels, i.e. clears the map (entity-ident)");
cls_StepData_StepModel.def("SetIdentLabel", (void (StepData_StepModel::*)(const opencascade::handle<Standard_Transient> &, const Standard_Integer)) &StepData_StepModel::SetIdentLabel, "Attaches an ident to an entity to produce a label (does nothing if <ent> is not in <me>)", py::arg("ent"), py::arg("ident"));
cls_StepData_StepModel.def("IdentLabel", (Standard_Integer (StepData_StepModel::*)(const opencascade::handle<Standard_Transient> &) const) &StepData_StepModel::IdentLabel, "returns the label ident attached to an entity, 0 if not in me", py::arg("ent"));
cls_StepData_StepModel.def("PrintLabel", (void (StepData_StepModel::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Message_Messenger> &) const) &StepData_StepModel::PrintLabel, "Prints label specific to STEP norm for a given entity, i.e. if a LabelIdent has been recorded, its value with '#', else the number in the model with '#' and between ()", py::arg("ent"), py::arg("S"));
cls_StepData_StepModel.def("StringLabel", (opencascade::handle<TCollection_HAsciiString> (StepData_StepModel::*)(const opencascade::handle<Standard_Transient> &) const) &StepData_StepModel::StringLabel, "Returns a string with the label attached to a given entity, same form as for PrintLabel", py::arg("ent"));
cls_StepData_StepModel.def_static("get_type_name_", (const char * (*)()) &StepData_StepModel::get_type_name, "None");
cls_StepData_StepModel.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepData_StepModel::get_type_descriptor, "None");
cls_StepData_StepModel.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepData_StepModel::*)() const) &StepData_StepModel::DynamicType, "None");

// Enums

}