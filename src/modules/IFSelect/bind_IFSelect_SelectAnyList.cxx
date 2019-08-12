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
#include <IFSelect_SelectDeduct.hxx>
#include <Interface_EntityIterator.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Transient.hxx>
#include <IFSelect_IntParam.hxx>
#include <Interface_Graph.hxx>
#include <TCollection_AsciiString.hxx>
#include <IFSelect_SelectAnyList.hxx>
#include <Standard_Type.hxx>

void bind_IFSelect_SelectAnyList(py::module &mod){

py::class_<IFSelect_SelectAnyList, opencascade::handle<IFSelect_SelectAnyList>, IFSelect_SelectDeduct> cls_IFSelect_SelectAnyList(mod, "IFSelect_SelectAnyList", "A SelectAnyList kind Selection selects a List of an Entity, as well as this Entity contains some. A List contains sub-entities as one per Item, or several (for instance if an Entity binds couples of sub-entities, each item is one of these couples). Remark that only Entities are taken into account (neither Reals, nor Strings, etc...)");

// Fields

// Methods
cls_IFSelect_SelectAnyList.def("KeepInputEntity", (void (IFSelect_SelectAnyList::*)(Interface_EntityIterator &) const) &IFSelect_SelectAnyList::KeepInputEntity, "Keeps Input Entity, as having required type. It works by keeping in <iter>, only suitable Entities (SelectType can be used). Called by RootResult (which waits for ONE ENTITY MAX)", py::arg("iter"));
cls_IFSelect_SelectAnyList.def("NbItems", (Standard_Integer (IFSelect_SelectAnyList::*)(const opencascade::handle<Standard_Transient> &) const) &IFSelect_SelectAnyList::NbItems, "Returns count of Items in the list in the Entity <ent> If <ent> has not required type, returned value must be Zero", py::arg("ent"));
cls_IFSelect_SelectAnyList.def("SetRange", (void (IFSelect_SelectAnyList::*)(const opencascade::handle<IFSelect_IntParam> &, const opencascade::handle<IFSelect_IntParam> &)) &IFSelect_SelectAnyList::SetRange, "Sets a Range for numbers, with a lower and a upper limits", py::arg("rankfrom"), py::arg("rankto"));
cls_IFSelect_SelectAnyList.def("SetOne", (void (IFSelect_SelectAnyList::*)(const opencascade::handle<IFSelect_IntParam> &)) &IFSelect_SelectAnyList::SetOne, "Sets a unique number (only one Entity will be sorted as True)", py::arg("rank"));
cls_IFSelect_SelectAnyList.def("SetFrom", (void (IFSelect_SelectAnyList::*)(const opencascade::handle<IFSelect_IntParam> &)) &IFSelect_SelectAnyList::SetFrom, "Sets a Lower limit but no upper limit", py::arg("rankfrom"));
cls_IFSelect_SelectAnyList.def("SetUntil", (void (IFSelect_SelectAnyList::*)(const opencascade::handle<IFSelect_IntParam> &)) &IFSelect_SelectAnyList::SetUntil, "Sets an Upper limit but no lower limit (equivalent to lower 1)", py::arg("rankto"));
cls_IFSelect_SelectAnyList.def("HasLower", (Standard_Boolean (IFSelect_SelectAnyList::*)() const) &IFSelect_SelectAnyList::HasLower, "Returns True if a Lower limit is defined");
cls_IFSelect_SelectAnyList.def("Lower", (opencascade::handle<IFSelect_IntParam> (IFSelect_SelectAnyList::*)() const) &IFSelect_SelectAnyList::Lower, "Returns Lower limit (if there is; else, value is senseless)");
cls_IFSelect_SelectAnyList.def("LowerValue", (Standard_Integer (IFSelect_SelectAnyList::*)() const) &IFSelect_SelectAnyList::LowerValue, "Returns Integer Value of Lower Limit (0 if none)");
cls_IFSelect_SelectAnyList.def("HasUpper", (Standard_Boolean (IFSelect_SelectAnyList::*)() const) &IFSelect_SelectAnyList::HasUpper, "Returns True if a Lower limit is defined");
cls_IFSelect_SelectAnyList.def("Upper", (opencascade::handle<IFSelect_IntParam> (IFSelect_SelectAnyList::*)() const) &IFSelect_SelectAnyList::Upper, "Returns Upper limit (if there is; else, value is senseless)");
cls_IFSelect_SelectAnyList.def("UpperValue", (Standard_Integer (IFSelect_SelectAnyList::*)() const) &IFSelect_SelectAnyList::UpperValue, "Returns Integer Value of Upper Limit (0 if none)");
cls_IFSelect_SelectAnyList.def("RootResult", (Interface_EntityIterator (IFSelect_SelectAnyList::*)(const Interface_Graph &) const) &IFSelect_SelectAnyList::RootResult, "Returns the list of selected entities (list of entities complying with rank criterium) Error if the input list has more than one Item", py::arg("G"));
cls_IFSelect_SelectAnyList.def("FillResult", (void (IFSelect_SelectAnyList::*)(const Standard_Integer, const Standard_Integer, const opencascade::handle<Standard_Transient> &, Interface_EntityIterator &) const) &IFSelect_SelectAnyList::FillResult, "Puts into <res>, the sub-entities of the list, from n1 to n2 included. Remark that adequation with Entity's type and length of list has already been made at this stage Called by RootResult", py::arg("n1"), py::arg("n2"), py::arg("ent"), py::arg("res"));
cls_IFSelect_SelectAnyList.def("Label", (TCollection_AsciiString (IFSelect_SelectAnyList::*)() const) &IFSelect_SelectAnyList::Label, "Returns a text defining the criterium : 'Componants of List ' then Specific List Label, then, following cases : ' From .. Until ..' or 'From ..' or 'Until ..' or 'Rank no ..' Specific type is given by deferred method ListLabel");
cls_IFSelect_SelectAnyList.def("ListLabel", (TCollection_AsciiString (IFSelect_SelectAnyList::*)() const) &IFSelect_SelectAnyList::ListLabel, "Returns the specific label for the list, which is included as a part of Label");
cls_IFSelect_SelectAnyList.def_static("get_type_name_", (const char * (*)()) &IFSelect_SelectAnyList::get_type_name, "None");
cls_IFSelect_SelectAnyList.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_SelectAnyList::get_type_descriptor, "None");
cls_IFSelect_SelectAnyList.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_SelectAnyList::*)() const) &IFSelect_SelectAnyList::DynamicType, "None");

// Enums

}