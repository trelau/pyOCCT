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
#include <Standard_TypeDef.hxx>
#include <Interface_EntityIterator.hxx>
#include <Interface_Graph.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Transient.hxx>
#include <TCollection_AsciiString.hxx>
#include <IFSelect_SelectExplore.hxx>
#include <Standard_Type.hxx>

void bind_IFSelect_SelectExplore(py::module &mod){

py::class_<IFSelect_SelectExplore, opencascade::handle<IFSelect_SelectExplore>, IFSelect_SelectDeduct> cls_IFSelect_SelectExplore(mod, "IFSelect_SelectExplore", "A SelectExplore determines from an input list of Entities, a list obtained by a way of exploration. This implies the possibility of recursive exploration : the output list is itself reused as input, etc... Examples : Shared Entities, can be considered at one level (immediate shared) or more, or max level");

// Fields

// Methods
cls_IFSelect_SelectExplore.def("Level", (Standard_Integer (IFSelect_SelectExplore::*)() const) &IFSelect_SelectExplore::Level, "Returns the required exploring level");
cls_IFSelect_SelectExplore.def("RootResult", (Interface_EntityIterator (IFSelect_SelectExplore::*)(const Interface_Graph &) const) &IFSelect_SelectExplore::RootResult, "Returns the list of selected entities. Works by calling the method Explore on each input entity : it can be rejected, taken for output, or to explore. If the maximum level has not yet been attained, or if no max level is specified, entities to be explored are themselves used as if they were input", py::arg("G"));
cls_IFSelect_SelectExplore.def("Explore", (Standard_Boolean (IFSelect_SelectExplore::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const Interface_Graph &, Interface_EntityIterator &) const) &IFSelect_SelectExplore::Explore, "Analyses and, if required, Explores an entity, as follows : The explored list starts as empty, it has to be filled by this method. If it returns False, <ent> is rejected for result (this is to be used only as safety) If it returns True and <explored> remains empty, <ent> is taken itself for result, not explored If it returns True and <explored> is not empty, the content of this list is considered : If maximum level is attained, it is taken for result Else (or no max), each of its entity will be itself explored", py::arg("level"), py::arg("ent"), py::arg("G"), py::arg("explored"));
cls_IFSelect_SelectExplore.def("Label", (TCollection_AsciiString (IFSelect_SelectExplore::*)() const) &IFSelect_SelectExplore::Label, "Returns a text saying '(Recursive)' or '(Level nn)' plus specific criterium returned by ExploreLabel (see below)");
cls_IFSelect_SelectExplore.def("ExploreLabel", (TCollection_AsciiString (IFSelect_SelectExplore::*)() const) &IFSelect_SelectExplore::ExploreLabel, "Returns a text defining the way of exploration");
cls_IFSelect_SelectExplore.def_static("get_type_name_", (const char * (*)()) &IFSelect_SelectExplore::get_type_name, "None");
cls_IFSelect_SelectExplore.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_SelectExplore::get_type_descriptor, "None");
cls_IFSelect_SelectExplore.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_SelectExplore::*)() const) &IFSelect_SelectExplore::DynamicType, "None");

// Enums

}