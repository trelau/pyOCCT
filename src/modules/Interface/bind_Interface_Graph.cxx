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
#include <Standard_TypeDef.hxx>
#include <Interface_Protocol.hxx>
#include <Interface_GTool.hxx>
#include <Interface_Graph.hxx>
#include <Standard_Transient.hxx>
#include <Interface_BitMap.hxx>
#include <Interface_EntityIterator.hxx>
#include <TColStd_HSequenceOfTransient.hxx>
#include <Standard_Type.hxx>
#include <TCollection_HAsciiString.hxx>
#include <TColStd_HArray1OfListOfInteger.hxx>
#include <TCollection_AsciiString.hxx>
#include <TColStd_HArray1OfInteger.hxx>

void bind_Interface_Graph(py::module &mod){

py::class_<Interface_Graph, std::unique_ptr<Interface_Graph, Deleter<Interface_Graph>>> cls_Interface_Graph(mod, "Interface_Graph", "Gives basic data structure for operating and storing graph results (usage is normally internal) Entities are Mapped according their Number in the Model");

// Constructors
cls_Interface_Graph.def(py::init<const opencascade::handle<Interface_InterfaceModel> &, const Interface_GeneralLib &>(), py::arg("amodel"), py::arg("lib"));
cls_Interface_Graph.def(py::init<const opencascade::handle<Interface_InterfaceModel> &, const Interface_GeneralLib &, const Standard_Boolean>(), py::arg("amodel"), py::arg("lib"), py::arg("theModeStats"));
cls_Interface_Graph.def(py::init<const opencascade::handle<Interface_InterfaceModel> &, const opencascade::handle<Interface_Protocol> &>(), py::arg("amodel"), py::arg("protocol"));
cls_Interface_Graph.def(py::init<const opencascade::handle<Interface_InterfaceModel> &, const opencascade::handle<Interface_Protocol> &, const Standard_Boolean>(), py::arg("amodel"), py::arg("protocol"), py::arg("theModeStats"));
cls_Interface_Graph.def(py::init<const opencascade::handle<Interface_InterfaceModel> &, const opencascade::handle<Interface_GTool> &>(), py::arg("amodel"), py::arg("gtool"));
cls_Interface_Graph.def(py::init<const opencascade::handle<Interface_InterfaceModel> &, const opencascade::handle<Interface_GTool> &, const Standard_Boolean>(), py::arg("amodel"), py::arg("gtool"), py::arg("theModeStats"));
cls_Interface_Graph.def(py::init<const opencascade::handle<Interface_InterfaceModel> &>(), py::arg("amodel"));
cls_Interface_Graph.def(py::init<const opencascade::handle<Interface_InterfaceModel> &, const Standard_Boolean>(), py::arg("amodel"), py::arg("theModeStats"));
cls_Interface_Graph.def(py::init<const Interface_Graph &>(), py::arg("agraph"));
cls_Interface_Graph.def(py::init<const Interface_Graph &, const Standard_Boolean>(), py::arg("agraph"), py::arg("copied"));

// Fields

// Methods
// cls_Interface_Graph.def_static("operator new_", (void * (*)(size_t)) &Interface_Graph::operator new, "None", py::arg("theSize"));
// cls_Interface_Graph.def_static("operator delete_", (void (*)(void *)) &Interface_Graph::operator delete, "None", py::arg("theAddress"));
// cls_Interface_Graph.def_static("operator new[]_", (void * (*)(size_t)) &Interface_Graph::operator new[], "None", py::arg("theSize"));
// cls_Interface_Graph.def_static("operator delete[]_", (void (*)(void *)) &Interface_Graph::operator delete[], "None", py::arg("theAddress"));
// cls_Interface_Graph.def_static("operator new_", (void * (*)(size_t, void *)) &Interface_Graph::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Interface_Graph.def_static("operator delete_", (void (*)(void *, void *)) &Interface_Graph::operator delete, "None", py::arg(""), py::arg(""));
cls_Interface_Graph.def("Reset", (void (Interface_Graph::*)()) &Interface_Graph::Reset, "Erases data, making graph ready to rebegin from void (also resets Shared lists redefinitions)");
cls_Interface_Graph.def("ResetStatus", (void (Interface_Graph::*)()) &Interface_Graph::ResetStatus, "Erases Status (Values and Flags of Presence), making graph ready to rebegin from void. Does not concerns Shared lists");
cls_Interface_Graph.def("Size", (Standard_Integer (Interface_Graph::*)() const) &Interface_Graph::Size, "Returns size (max nb of entities, i.e. Model's nb of entities)");
cls_Interface_Graph.def("NbStatuses", (Standard_Integer (Interface_Graph::*)() const) &Interface_Graph::NbStatuses, "Returns size of array of statuses");
cls_Interface_Graph.def("EntityNumber", (Standard_Integer (Interface_Graph::*)(const opencascade::handle<Standard_Transient> &) const) &Interface_Graph::EntityNumber, "Returns the Number of the entity in the Map, computed at creation time (Entities loaded from the Model) Returns 0 if <ent> not contained by Model used to create <me> (that is, <ent> is unknown from <me>)", py::arg("ent"));
cls_Interface_Graph.def("IsPresent", (Standard_Boolean (Interface_Graph::*)(const Standard_Integer) const) &Interface_Graph::IsPresent, "Returns True if an Entity is noted as present in the graph (See methods Get... which determine this status) Returns False if <num> is out of range too", py::arg("num"));
cls_Interface_Graph.def("IsPresent", (Standard_Boolean (Interface_Graph::*)(const opencascade::handle<Standard_Transient> &) const) &Interface_Graph::IsPresent, "Same as above but directly on an Entity <ent> : if it is not contained in the Model, returns False. Else calls IsPresent(num) with <num> given by EntityNumber", py::arg("ent"));
cls_Interface_Graph.def("Entity", (const opencascade::handle<Standard_Transient> & (Interface_Graph::*)(const Standard_Integer) const) &Interface_Graph::Entity, "Returns mapped Entity given its no (if it is present)", py::arg("num"));
cls_Interface_Graph.def("Status", (Standard_Integer (Interface_Graph::*)(const Standard_Integer) const) &Interface_Graph::Status, "Returns Status associated to a numero (only to read it)", py::arg("num"));
cls_Interface_Graph.def("SetStatus", (void (Interface_Graph::*)(const Standard_Integer, const Standard_Integer)) &Interface_Graph::SetStatus, "Modifies Status associated to a numero", py::arg("num"), py::arg("stat"));
cls_Interface_Graph.def("RemoveItem", (void (Interface_Graph::*)(const Standard_Integer)) &Interface_Graph::RemoveItem, "Clears Entity and sets Status to 0, for a numero", py::arg("num"));
cls_Interface_Graph.def("ChangeStatus", (void (Interface_Graph::*)(const Standard_Integer, const Standard_Integer)) &Interface_Graph::ChangeStatus, "Changes all status which value is oldstat to new value newstat", py::arg("oldstat"), py::arg("newstat"));
cls_Interface_Graph.def("RemoveStatus", (void (Interface_Graph::*)(const Standard_Integer)) &Interface_Graph::RemoveStatus, "Removes all items of which status has a given value stat", py::arg("stat"));
cls_Interface_Graph.def("BitMap", (const Interface_BitMap & (Interface_Graph::*)() const) &Interface_Graph::BitMap, "Returns the Bit Map in order to read or edit flag values");
cls_Interface_Graph.def("CBitMap", (Interface_BitMap & (Interface_Graph::*)()) &Interface_Graph::CBitMap, "Returns the Bit Map in order to edit it (add new flags)");
cls_Interface_Graph.def("Model", (const opencascade::handle<Interface_InterfaceModel> & (Interface_Graph::*)() const) &Interface_Graph::Model, "Returns the Model with which this Graph was created");
cls_Interface_Graph.def("GetFromModel", (void (Interface_Graph::*)()) &Interface_Graph::GetFromModel, "Loads Graph with all Entities contained in the Model");
cls_Interface_Graph.def("GetFromEntity", [](Interface_Graph &self, const opencascade::handle<Standard_Transient> & a0, const Standard_Boolean a1) -> void { return self.GetFromEntity(a0, a1); });
cls_Interface_Graph.def("GetFromEntity", (void (Interface_Graph::*)(const opencascade::handle<Standard_Transient> &, const Standard_Boolean, const Standard_Integer)) &Interface_Graph::GetFromEntity, "Gets an Entity, plus its shared ones (at every level) if 'shared' is True. New items are set to status 'newstat' Items already present in graph remain unchanged Of course, redefinitions of Shared lists are taken into account if there are some", py::arg("ent"), py::arg("shared"), py::arg("newstat"));
cls_Interface_Graph.def("GetFromEntity", (void (Interface_Graph::*)(const opencascade::handle<Standard_Transient> &, const Standard_Boolean, const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &Interface_Graph::GetFromEntity, "Gets an Entity, plus its shared ones (at every level) if 'shared' is True. New items are set to status 'newstat'. Items already present in graph are processed as follows : - if they already have status 'newstat', they remain unchanged - if they have another status, this one is modified : if cumul is True, to former status + overlapstat (cumul) if cumul is False, to overlapstat (enforce)", py::arg("ent"), py::arg("shared"), py::arg("newstat"), py::arg("overlapstat"), py::arg("cumul"));
cls_Interface_Graph.def("GetFromIter", (void (Interface_Graph::*)(const Interface_EntityIterator &, const Standard_Integer)) &Interface_Graph::GetFromIter, "Gets Entities given by an EntityIterator. Entities which were not yet present in the graph are mapped with status 'newstat' Entities already present remain unchanged", py::arg("iter"), py::arg("newstat"));
cls_Interface_Graph.def("GetFromIter", (void (Interface_Graph::*)(const Interface_EntityIterator &, const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &Interface_Graph::GetFromIter, "Gets Entities given by an EntityIterator and distinguishes those already present in the Graph : - new entities added to the Graph with status 'newstst' - entities already present with status = 'newstat' remain unchanged - entities already present with status different form 'newstat' have their status modified : if cumul is True, to former status + overlapstat (cumul) if cumul is False, to overlapstat (enforce) (Note : works as GetEntity, shared = False, for each entity)", py::arg("iter"), py::arg("newstat"), py::arg("overlapstat"), py::arg("cumul"));
cls_Interface_Graph.def("GetFromGraph", (void (Interface_Graph::*)(const Interface_Graph &)) &Interface_Graph::GetFromGraph, "Gets all present items from another graph", py::arg("agraph"));
cls_Interface_Graph.def("GetFromGraph", (void (Interface_Graph::*)(const Interface_Graph &, const Standard_Integer)) &Interface_Graph::GetFromGraph, "Gets items from another graph which have a specific Status", py::arg("agraph"), py::arg("stat"));
cls_Interface_Graph.def("HasShareErrors", (Standard_Boolean (Interface_Graph::*)(const opencascade::handle<Standard_Transient> &) const) &Interface_Graph::HasShareErrors, "Returns True if <ent> or the list of entities shared by <ent> (not redefined) contains items unknown from this Graph Remark : apart from the status HasShareError, these items are ignored", py::arg("ent"));
cls_Interface_Graph.def("GetShareds", (opencascade::handle<TColStd_HSequenceOfTransient> (Interface_Graph::*)(const opencascade::handle<Standard_Transient> &) const) &Interface_Graph::GetShareds, "Returns the sequence of Entities Shared by an Entity", py::arg("ent"));
cls_Interface_Graph.def("Shareds", (Interface_EntityIterator (Interface_Graph::*)(const opencascade::handle<Standard_Transient> &) const) &Interface_Graph::Shareds, "Returns the list of Entities Shared by an Entity, as recorded by the Graph. That is, by default Basic Shared List, else it can be redefined by methods SetShare, SetNoShare ... see below", py::arg("ent"));
cls_Interface_Graph.def("Sharings", (Interface_EntityIterator (Interface_Graph::*)(const opencascade::handle<Standard_Transient> &) const) &Interface_Graph::Sharings, "Returns the list of Entities which Share an Entity, computed from the Basic or Redefined Shared Lists", py::arg("ent"));
cls_Interface_Graph.def("GetSharings", (opencascade::handle<TColStd_HSequenceOfTransient> (Interface_Graph::*)(const opencascade::handle<Standard_Transient> &) const) &Interface_Graph::GetSharings, "Returns the sequence of Entities Sharings by an Entity", py::arg("ent"));
cls_Interface_Graph.def("TypedSharings", (Interface_EntityIterator (Interface_Graph::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Standard_Type> &) const) &Interface_Graph::TypedSharings, "Returns the list of sharings entities, AT ANY LEVEL, which are kind of a given type. A sharing entity kind of this type ends the exploration of its branch", py::arg("ent"), py::arg("type"));
cls_Interface_Graph.def("RootEntities", (Interface_EntityIterator (Interface_Graph::*)() const) &Interface_Graph::RootEntities, "Returns the Entities which are not Shared (their Sharing List is empty) in the Model");
cls_Interface_Graph.def("Name", (opencascade::handle<TCollection_HAsciiString> (Interface_Graph::*)(const opencascade::handle<Standard_Transient> &) const) &Interface_Graph::Name, "Determines the name attached to an entity, by using the general service Name in GeneralModule Returns a null handle if no name could be computed or if the entity is not in the model", py::arg("ent"));
cls_Interface_Graph.def("SharingTable", (const opencascade::handle<TColStd_HArray1OfListOfInteger> & (Interface_Graph::*)() const) &Interface_Graph::SharingTable, "Returns the Table of Sharing lists. Used to Create another Graph from <me>");
cls_Interface_Graph.def("ModeStat", (Standard_Boolean (Interface_Graph::*)() const) &Interface_Graph::ModeStat, "Returns mode resposible for computation of statuses;");

// Enums

}