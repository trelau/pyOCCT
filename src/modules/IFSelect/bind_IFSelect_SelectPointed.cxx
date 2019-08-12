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
#include <IFSelect_SelectBase.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Transient.hxx>
#include <TColStd_HSequenceOfTransient.hxx>
#include <Interface_CopyControl.hxx>
#include <IFSelect_Transformer.hxx>
#include <Interface_EntityIterator.hxx>
#include <Interface_Graph.hxx>
#include <TCollection_AsciiString.hxx>
#include <IFSelect_SelectPointed.hxx>
#include <Standard_Type.hxx>
#include <TColStd_SequenceOfTransient.hxx>

void bind_IFSelect_SelectPointed(py::module &mod){

py::class_<IFSelect_SelectPointed, opencascade::handle<IFSelect_SelectPointed>, IFSelect_SelectBase> cls_IFSelect_SelectPointed(mod, "IFSelect_SelectPointed", "This type of Selection is intended to describe a direct selection without an explicit criterium, for instance the result of picking viewed entities on a graphic screen");

// Constructors
cls_IFSelect_SelectPointed.def(py::init<>());

// Fields

// Methods
cls_IFSelect_SelectPointed.def("Clear", (void (IFSelect_SelectPointed::*)()) &IFSelect_SelectPointed::Clear, "Clears the list of selected items Also says the list is unset All Add* methods and SetList say the list is set");
cls_IFSelect_SelectPointed.def("IsSet", (Standard_Boolean (IFSelect_SelectPointed::*)() const) &IFSelect_SelectPointed::IsSet, "Tells if the list has been set. Even if empty");
cls_IFSelect_SelectPointed.def("SetEntity", (void (IFSelect_SelectPointed::*)(const opencascade::handle<Standard_Transient> &)) &IFSelect_SelectPointed::SetEntity, "As SetList but with only one entity If <ent> is Null, the list is said as being set but is empty", py::arg("item"));
cls_IFSelect_SelectPointed.def("SetList", (void (IFSelect_SelectPointed::*)(const opencascade::handle<TColStd_HSequenceOfTransient> &)) &IFSelect_SelectPointed::SetList, "Sets a given list to define the list of selected items <list> can be empty or null : in this case, the list is said as being set, but it is empty", py::arg("list"));
cls_IFSelect_SelectPointed.def("Add", (Standard_Boolean (IFSelect_SelectPointed::*)(const opencascade::handle<Standard_Transient> &)) &IFSelect_SelectPointed::Add, "Adds an item. Returns True if Done, False if <item> is already in the selected list", py::arg("item"));
cls_IFSelect_SelectPointed.def("Remove", (Standard_Boolean (IFSelect_SelectPointed::*)(const opencascade::handle<Standard_Transient> &)) &IFSelect_SelectPointed::Remove, "Removes an item. Returns True if Done, False if <item> was not in the selected list", py::arg("item"));
cls_IFSelect_SelectPointed.def("Toggle", (Standard_Boolean (IFSelect_SelectPointed::*)(const opencascade::handle<Standard_Transient> &)) &IFSelect_SelectPointed::Toggle, "Toggles status of an item : adds it if not pointed or removes it if already pointed. Returns the new status (Pointed or not)", py::arg("item"));
cls_IFSelect_SelectPointed.def("AddList", (Standard_Boolean (IFSelect_SelectPointed::*)(const opencascade::handle<TColStd_HSequenceOfTransient> &)) &IFSelect_SelectPointed::AddList, "Adds all the items defined in a list. Returns True if at least one item has been added, False else", py::arg("list"));
cls_IFSelect_SelectPointed.def("RemoveList", (Standard_Boolean (IFSelect_SelectPointed::*)(const opencascade::handle<TColStd_HSequenceOfTransient> &)) &IFSelect_SelectPointed::RemoveList, "Removes all the items defined in a list. Returns True if at least one item has been removed, False else", py::arg("list"));
cls_IFSelect_SelectPointed.def("ToggleList", (Standard_Boolean (IFSelect_SelectPointed::*)(const opencascade::handle<TColStd_HSequenceOfTransient> &)) &IFSelect_SelectPointed::ToggleList, "Toggles status of all the items defined in a list : adds it if not pointed or removes it if already pointed.", py::arg("list"));
cls_IFSelect_SelectPointed.def("Rank", (Standard_Integer (IFSelect_SelectPointed::*)(const opencascade::handle<Standard_Transient> &) const) &IFSelect_SelectPointed::Rank, "Returns the rank of an item in the selected list, or 0.", py::arg("item"));
cls_IFSelect_SelectPointed.def("NbItems", (Standard_Integer (IFSelect_SelectPointed::*)() const) &IFSelect_SelectPointed::NbItems, "Returns the count of selected items");
cls_IFSelect_SelectPointed.def("Item", (opencascade::handle<Standard_Transient> (IFSelect_SelectPointed::*)(const Standard_Integer) const) &IFSelect_SelectPointed::Item, "Returns an item given its rank, or a Null Handle", py::arg("num"));
cls_IFSelect_SelectPointed.def("Update", (void (IFSelect_SelectPointed::*)(const opencascade::handle<Interface_CopyControl> &)) &IFSelect_SelectPointed::Update, "Rebuilds the selected list. Any selected entity which has a bound result is replaced by this result, else it is removed.", py::arg("control"));
cls_IFSelect_SelectPointed.def("Update", (void (IFSelect_SelectPointed::*)(const opencascade::handle<IFSelect_Transformer> &)) &IFSelect_SelectPointed::Update, "Rebuilds the selected list, by querying a Transformer (same principle as from a CopyControl)", py::arg("trf"));
cls_IFSelect_SelectPointed.def("RootResult", (Interface_EntityIterator (IFSelect_SelectPointed::*)(const Interface_Graph &) const) &IFSelect_SelectPointed::RootResult, "Returns the list of selected items. Only the selected entities which are present in the graph are given (this result assures uniqueness).", py::arg("G"));
cls_IFSelect_SelectPointed.def("Label", (TCollection_AsciiString (IFSelect_SelectPointed::*)() const) &IFSelect_SelectPointed::Label, "Returns a text which identifies the type of selection made. It is 'Pointed Entities'");
cls_IFSelect_SelectPointed.def_static("get_type_name_", (const char * (*)()) &IFSelect_SelectPointed::get_type_name, "None");
cls_IFSelect_SelectPointed.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_SelectPointed::get_type_descriptor, "None");
cls_IFSelect_SelectPointed.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_SelectPointed::*)() const) &IFSelect_SelectPointed::DynamicType, "None");

// Enums

}