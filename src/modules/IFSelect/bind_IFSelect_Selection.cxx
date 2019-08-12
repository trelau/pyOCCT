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
#include <Standard_Transient.hxx>
#include <Interface_EntityIterator.hxx>
#include <Interface_Graph.hxx>
#include <IFSelect_SelectionIterator.hxx>
#include <TCollection_AsciiString.hxx>
#include <Standard_Handle.hxx>
#include <IFSelect_Selection.hxx>
#include <Standard_Type.hxx>
#include <Standard_TypeDef.hxx>

void bind_IFSelect_Selection(py::module &mod){

py::class_<IFSelect_Selection, opencascade::handle<IFSelect_Selection>, Standard_Transient> cls_IFSelect_Selection(mod, "IFSelect_Selection", "A Selection allows to define a set of Interface Entities. Entities to be put on an output file should be identified in a way as independant from such or such execution as possible. This permits to handle comprehensive criteria, and to replay them when a new variant of an input file has to be processed.");

// Fields

// Methods
cls_IFSelect_Selection.def("RootResult", (Interface_EntityIterator (IFSelect_Selection::*)(const Interface_Graph &) const) &IFSelect_Selection::RootResult, "Returns the list of selected entities, computed from Input given as a Graph. Specific to each class of Selection Note that uniqueness of each entity is not required here This method can raise an exception as necessary", py::arg("G"));
cls_IFSelect_Selection.def("UniqueResult", (Interface_EntityIterator (IFSelect_Selection::*)(const Interface_Graph &) const) &IFSelect_Selection::UniqueResult, "Returns the list of selected entities, each of them beeing unique. Default definition works from RootResult. According HasUniqueResult, UniqueResult returns directly RootResult, or build a Unique Result from it with a Graph.", py::arg("G"));
cls_IFSelect_Selection.def("CompleteResult", (Interface_EntityIterator (IFSelect_Selection::*)(const Interface_Graph &) const) &IFSelect_Selection::CompleteResult, "Returns the list of entities involved by a Selection, i.e. UniqueResult plus the shared entities (directly or not)", py::arg("G"));
cls_IFSelect_Selection.def("FillIterator", (void (IFSelect_Selection::*)(IFSelect_SelectionIterator &) const) &IFSelect_Selection::FillIterator, "Puts in an Iterator the Selections from which 'me' depends (there can be zero, or one, or a list). Specific to each class of Selection", py::arg("iter"));
cls_IFSelect_Selection.def("Label", (TCollection_AsciiString (IFSelect_Selection::*)() const) &IFSelect_Selection::Label, "Returns a text which defines the criterium applied by a Selection (can be used to be printed, displayed ...) Specific to each class");
cls_IFSelect_Selection.def_static("get_type_name_", (const char * (*)()) &IFSelect_Selection::get_type_name, "None");
cls_IFSelect_Selection.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_Selection::get_type_descriptor, "None");
cls_IFSelect_Selection.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_Selection::*)() const) &IFSelect_Selection::DynamicType, "None");

// Enums

}