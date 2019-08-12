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
#include <IFSelect_SelectExplore.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Transient.hxx>
#include <Interface_Graph.hxx>
#include <Interface_EntityIterator.hxx>
#include <TCollection_AsciiString.hxx>
#include <IGESSelect_SelectBypassGroup.hxx>
#include <Standard_Type.hxx>

void bind_IGESSelect_SelectBypassGroup(py::module &mod){

py::class_<IGESSelect_SelectBypassGroup, opencascade::handle<IGESSelect_SelectBypassGroup>, IFSelect_SelectExplore> cls_IGESSelect_SelectBypassGroup(mod, "IGESSelect_SelectBypassGroup", "Selects a list built as follows : Groups are entities type 402, forms 1,7,14,15 (Group, Ordered or not, 'WithoutBackPointer' or not)");

// Constructors
cls_IGESSelect_SelectBypassGroup.def(py::init<>());
cls_IGESSelect_SelectBypassGroup.def(py::init<const Standard_Integer>(), py::arg("level"));

// Fields

// Methods
cls_IGESSelect_SelectBypassGroup.def("Explore", (Standard_Boolean (IGESSelect_SelectBypassGroup::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const Interface_Graph &, Interface_EntityIterator &) const) &IGESSelect_SelectBypassGroup::Explore, "Explores an entity : for a Group, gives its elements Else, takes the entity itself", py::arg("level"), py::arg("ent"), py::arg("G"), py::arg("explored"));
cls_IGESSelect_SelectBypassGroup.def("ExploreLabel", (TCollection_AsciiString (IGESSelect_SelectBypassGroup::*)() const) &IGESSelect_SelectBypassGroup::ExploreLabel, "Returns a text defining the criterium : 'Content of Group'");
cls_IGESSelect_SelectBypassGroup.def_static("get_type_name_", (const char * (*)()) &IGESSelect_SelectBypassGroup::get_type_name, "None");
cls_IGESSelect_SelectBypassGroup.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSelect_SelectBypassGroup::get_type_descriptor, "None");
cls_IGESSelect_SelectBypassGroup.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSelect_SelectBypassGroup::*)() const) &IGESSelect_SelectBypassGroup::DynamicType, "None");

// Enums

}