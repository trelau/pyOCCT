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
#include <IFSelect_SelectAnyList.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Transient.hxx>
#include <Standard_TypeDef.hxx>
#include <Interface_EntityIterator.hxx>
#include <IFSelect_SelectInList.hxx>
#include <Standard_Type.hxx>

void bind_IFSelect_SelectInList(py::module &mod){

py::class_<IFSelect_SelectInList, opencascade::handle<IFSelect_SelectInList>, IFSelect_SelectAnyList> cls_IFSelect_SelectInList(mod, "IFSelect_SelectInList", "A SelectInList kind Selection selects a List of an Entity, which is composed of single Entities To know the list on which to work, SelectInList has two deferred methods : NbItems (inherited from SelectAnyList) and ListedEntity (which gives an item as an Entity) which must be defined to get a List in an Entity of the required Type (and consider that list is empty if Entity has not required Type)");

// Fields

// Methods
cls_IFSelect_SelectInList.def("ListedEntity", (opencascade::handle<Standard_Transient> (IFSelect_SelectInList::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &) const) &IFSelect_SelectInList::ListedEntity, "Returns an Entity, given its rank in the list", py::arg("num"), py::arg("ent"));
cls_IFSelect_SelectInList.def("FillResult", (void (IFSelect_SelectInList::*)(const Standard_Integer, const Standard_Integer, const opencascade::handle<Standard_Transient> &, Interface_EntityIterator &) const) &IFSelect_SelectInList::FillResult, "Puts into the result, the sub-entities of the list, from n1 to n2 included. Remark that adequation with Entity's type and length of list has already been made at this stage Called by RootResult; calls ListedEntity (see below)", py::arg("n1"), py::arg("n2"), py::arg("ent"), py::arg("result"));
cls_IFSelect_SelectInList.def_static("get_type_name_", (const char * (*)()) &IFSelect_SelectInList::get_type_name, "None");
cls_IFSelect_SelectInList.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_SelectInList::get_type_descriptor, "None");
cls_IFSelect_SelectInList.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_SelectInList::*)() const) &IFSelect_SelectInList::DynamicType, "None");

// Enums

}