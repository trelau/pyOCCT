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
#include <IGESSelect_SelectBypassSubfigure.hxx>
#include <Standard_Type.hxx>

void bind_IGESSelect_SelectBypassSubfigure(py::module &mod){

py::class_<IGESSelect_SelectBypassSubfigure, opencascade::handle<IGESSelect_SelectBypassSubfigure>, IFSelect_SelectExplore> cls_IGESSelect_SelectBypassSubfigure(mod, "IGESSelect_SelectBypassSubfigure", "Selects a list built as follows : Subfigures correspond to * Definition (basic : type 308, or Network : type 320) * Instance (Singular : type 408, or Network : 420, or patterns : 412,414)");

// Constructors
cls_IGESSelect_SelectBypassSubfigure.def(py::init<>());
cls_IGESSelect_SelectBypassSubfigure.def(py::init<const Standard_Integer>(), py::arg("level"));

// Fields

// Methods
cls_IGESSelect_SelectBypassSubfigure.def("Explore", (Standard_Boolean (IGESSelect_SelectBypassSubfigure::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const Interface_Graph &, Interface_EntityIterator &) const) &IGESSelect_SelectBypassSubfigure::Explore, "Explores an entity : for a Subfigure, gives its elements Else, takes the entity itself", py::arg("level"), py::arg("ent"), py::arg("G"), py::arg("explored"));
cls_IGESSelect_SelectBypassSubfigure.def("ExploreLabel", (TCollection_AsciiString (IGESSelect_SelectBypassSubfigure::*)() const) &IGESSelect_SelectBypassSubfigure::ExploreLabel, "Returns a text defining the criterium : 'Content of Subfigure'");
cls_IGESSelect_SelectBypassSubfigure.def_static("get_type_name_", (const char * (*)()) &IGESSelect_SelectBypassSubfigure::get_type_name, "None");
cls_IGESSelect_SelectBypassSubfigure.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSelect_SelectBypassSubfigure::get_type_descriptor, "None");
cls_IGESSelect_SelectBypassSubfigure.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSelect_SelectBypassSubfigure::*)() const) &IGESSelect_SelectBypassSubfigure::DynamicType, "None");

// Enums

}