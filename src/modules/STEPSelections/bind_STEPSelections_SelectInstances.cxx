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
#include <Interface_EntityIterator.hxx>
#include <Interface_Graph.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Transient.hxx>
#include <TCollection_AsciiString.hxx>
#include <STEPSelections_SelectInstances.hxx>
#include <Standard_Type.hxx>

void bind_STEPSelections_SelectInstances(py::module &mod){

py::class_<STEPSelections_SelectInstances, opencascade::handle<STEPSelections_SelectInstances>, IFSelect_SelectExplore> cls_STEPSelections_SelectInstances(mod, "STEPSelections_SelectInstances", "None");

// Constructors
cls_STEPSelections_SelectInstances.def(py::init<>());

// Fields

// Methods
cls_STEPSelections_SelectInstances.def("RootResult", (Interface_EntityIterator (STEPSelections_SelectInstances::*)(const Interface_Graph &) const) &STEPSelections_SelectInstances::RootResult, "None", py::arg("G"));
cls_STEPSelections_SelectInstances.def("Explore", (Standard_Boolean (STEPSelections_SelectInstances::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const Interface_Graph &, Interface_EntityIterator &) const) &STEPSelections_SelectInstances::Explore, "None", py::arg("level"), py::arg("ent"), py::arg("G"), py::arg("explored"));
cls_STEPSelections_SelectInstances.def("ExploreLabel", (TCollection_AsciiString (STEPSelections_SelectInstances::*)() const) &STEPSelections_SelectInstances::ExploreLabel, "Returns a text defining the criterium : 'Instances'");
cls_STEPSelections_SelectInstances.def_static("get_type_name_", (const char * (*)()) &STEPSelections_SelectInstances::get_type_name, "None");
cls_STEPSelections_SelectInstances.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &STEPSelections_SelectInstances::get_type_descriptor, "None");
cls_STEPSelections_SelectInstances.def("DynamicType", (const opencascade::handle<Standard_Type> & (STEPSelections_SelectInstances::*)() const) &STEPSelections_SelectInstances::DynamicType, "None");

// Enums

}