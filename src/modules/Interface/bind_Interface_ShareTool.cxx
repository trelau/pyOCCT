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
#include <Standard_Handle.hxx>
#include <Interface_InterfaceModel.hxx>
#include <Interface_GeneralLib.hxx>
#include <Interface_GTool.hxx>
#include <Interface_Protocol.hxx>
#include <Interface_Graph.hxx>
#include <Interface_HGraph.hxx>
#include <Interface_EntityIterator.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Transient.hxx>
#include <Standard_Type.hxx>
#include <Message_Messenger.hxx>
#include <Interface_ShareTool.hxx>

void bind_Interface_ShareTool(py::module &mod){

py::class_<Interface_ShareTool, std::unique_ptr<Interface_ShareTool, Deleter<Interface_ShareTool>>> cls_Interface_ShareTool(mod, "Interface_ShareTool", "Builds the Graph of Dependancies, from the General Service 'Shared' -> builds for each Entity of a Model, the Shared and Sharing Lists, and gives access to them. Allows to complete with Implied References (which are not regarded as Shared Entities, but are nevertheless Referenced), this can be usefull for Reference Checking");

// Constructors
cls_Interface_ShareTool.def(py::init<const opencascade::handle<Interface_InterfaceModel> &, const Interface_GeneralLib &>(), py::arg("amodel"), py::arg("lib"));
cls_Interface_ShareTool.def(py::init<const opencascade::handle<Interface_InterfaceModel> &, const opencascade::handle<Interface_GTool> &>(), py::arg("amodel"), py::arg("gtool"));
cls_Interface_ShareTool.def(py::init<const opencascade::handle<Interface_InterfaceModel> &, const opencascade::handle<Interface_Protocol> &>(), py::arg("amodel"), py::arg("protocol"));
cls_Interface_ShareTool.def(py::init<const opencascade::handle<Interface_InterfaceModel> &>(), py::arg("amodel"));
cls_Interface_ShareTool.def(py::init<const Interface_Graph &>(), py::arg("agraph"));
cls_Interface_ShareTool.def(py::init<const opencascade::handle<Interface_HGraph> &>(), py::arg("ahgraph"));

// Fields

// Methods
// cls_Interface_ShareTool.def_static("operator new_", (void * (*)(size_t)) &Interface_ShareTool::operator new, "None", py::arg("theSize"));
// cls_Interface_ShareTool.def_static("operator delete_", (void (*)(void *)) &Interface_ShareTool::operator delete, "None", py::arg("theAddress"));
// cls_Interface_ShareTool.def_static("operator new[]_", (void * (*)(size_t)) &Interface_ShareTool::operator new[], "None", py::arg("theSize"));
// cls_Interface_ShareTool.def_static("operator delete[]_", (void (*)(void *)) &Interface_ShareTool::operator delete[], "None", py::arg("theAddress"));
// cls_Interface_ShareTool.def_static("operator new_", (void * (*)(size_t, void *)) &Interface_ShareTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Interface_ShareTool.def_static("operator delete_", (void (*)(void *, void *)) &Interface_ShareTool::operator delete, "None", py::arg(""), py::arg(""));
cls_Interface_ShareTool.def("Model", (opencascade::handle<Interface_InterfaceModel> (Interface_ShareTool::*)() const) &Interface_ShareTool::Model, "Returns the Model used for Creation (directly or for Graph)");
cls_Interface_ShareTool.def("Graph", (const Interface_Graph & (Interface_ShareTool::*)() const) &Interface_ShareTool::Graph, "Returns the data used by the ShareTool to work Can then be used directly (read only)");
cls_Interface_ShareTool.def("RootEntities", (Interface_EntityIterator (Interface_ShareTool::*)() const) &Interface_ShareTool::RootEntities, "Returns the Entities which are not Shared (their Sharing List is empty) in the Model");
cls_Interface_ShareTool.def("IsShared", (Standard_Boolean (Interface_ShareTool::*)(const opencascade::handle<Standard_Transient> &) const) &Interface_ShareTool::IsShared, "Returns True if <ent> is Shared by other Entities in the Model", py::arg("ent"));
cls_Interface_ShareTool.def("Shareds", (Interface_EntityIterator (Interface_ShareTool::*)(const opencascade::handle<Standard_Transient> &) const) &Interface_ShareTool::Shareds, "Returns the List of Entities Shared by a given Entity <ent>", py::arg("ent"));
cls_Interface_ShareTool.def("Sharings", (Interface_EntityIterator (Interface_ShareTool::*)(const opencascade::handle<Standard_Transient> &) const) &Interface_ShareTool::Sharings, "Returns the List of Entities Sharing a given Entity <ent>", py::arg("ent"));
cls_Interface_ShareTool.def("NbTypedSharings", (Standard_Integer (Interface_ShareTool::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Standard_Type> &) const) &Interface_ShareTool::NbTypedSharings, "Returns the count of Sharing Entities of an Entity, which are Kind of a given Type", py::arg("ent"), py::arg("atype"));
cls_Interface_ShareTool.def("TypedSharing", (opencascade::handle<Standard_Transient> (Interface_ShareTool::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Standard_Type> &) const) &Interface_ShareTool::TypedSharing, "Returns the Sharing Entity of an Entity, which is Kind of a given Type. Allows to access a Sharing Entity of a given type when there is one and only one (current case)", py::arg("ent"), py::arg("atype"));
cls_Interface_ShareTool.def("All", [](Interface_ShareTool &self, const opencascade::handle<Standard_Transient> & a0) -> Interface_EntityIterator { return self.All(a0); });
cls_Interface_ShareTool.def("All", (Interface_EntityIterator (Interface_ShareTool::*)(const opencascade::handle<Standard_Transient> &, const Standard_Boolean) const) &Interface_ShareTool::All, "Returns the complete list of entities shared by <ent> at any level, including <ent> itself If <ent> is the Model, considers the concatenation of AllShared for each root If <rootlast> is True (D), the list starts with lower level entities and ends by the root. Else, the root is first and the lower level entities are at end", py::arg("ent"), py::arg("rootlast"));
cls_Interface_ShareTool.def("Print", (void (Interface_ShareTool::*)(const Interface_EntityIterator &, const opencascade::handle<Message_Messenger> &) const) &Interface_ShareTool::Print, "Utility method which Prints the content of an iterator (by their Numbers)", py::arg("iter"), py::arg("S"));

// Enums

}