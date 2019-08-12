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
#include <IFSelect_Selection.hxx>
#include <Standard_Handle.hxx>
#include <Standard_TypeDef.hxx>
#include <IFSelect_SelectPointed.hxx>
#include <Interface_EntityIterator.hxx>
#include <Interface_Graph.hxx>
#include <IFSelect_SelectionIterator.hxx>
#include <IFSelect_SelectDeduct.hxx>
#include <Standard_Type.hxx>

void bind_IFSelect_SelectDeduct(py::module &mod){

py::class_<IFSelect_SelectDeduct, opencascade::handle<IFSelect_SelectDeduct>, IFSelect_Selection> cls_IFSelect_SelectDeduct(mod, "IFSelect_SelectDeduct", "A SelectDeduct determines a list of Entities from an Input Selection, by a computation : Output list is not obliged to be a sub-list of Input list (for more specific, see SelectExtract for filtered sub-lists, and SelectExplore for recurcive exploration)");

// Fields

// Methods
cls_IFSelect_SelectDeduct.def("SetInput", (void (IFSelect_SelectDeduct::*)(const opencascade::handle<IFSelect_Selection> &)) &IFSelect_SelectDeduct::SetInput, "Defines or Changes the Input Selection", py::arg("sel"));
cls_IFSelect_SelectDeduct.def("Input", (opencascade::handle<IFSelect_Selection> (IFSelect_SelectDeduct::*)() const) &IFSelect_SelectDeduct::Input, "Returns the Input Selection");
cls_IFSelect_SelectDeduct.def("HasInput", (Standard_Boolean (IFSelect_SelectDeduct::*)() const) &IFSelect_SelectDeduct::HasInput, "Returns True if the Input Selection is defined, False else");
cls_IFSelect_SelectDeduct.def("HasAlternate", (Standard_Boolean (IFSelect_SelectDeduct::*)() const) &IFSelect_SelectDeduct::HasAlternate, "Tells if an Alternate List has been set, i.e. : the Alternate Definition is present and set");
cls_IFSelect_SelectDeduct.def("Alternate", (opencascade::handle<IFSelect_SelectPointed> & (IFSelect_SelectDeduct::*)()) &IFSelect_SelectDeduct::Alternate, "Returns the Alternate Definition It is returned modifiable, hence an already defined SelectPointed can be used But if it was not yet defined, it is created the first time");
cls_IFSelect_SelectDeduct.def("InputResult", (Interface_EntityIterator (IFSelect_SelectDeduct::*)(const Interface_Graph &) const) &IFSelect_SelectDeduct::InputResult, "Returns the Result determined by Input Selection, as Unique if Input Selection is not defined, returns an empty list.", py::arg("G"));
cls_IFSelect_SelectDeduct.def("FillIterator", (void (IFSelect_SelectDeduct::*)(IFSelect_SelectionIterator &) const) &IFSelect_SelectDeduct::FillIterator, "Puts in an Iterator the Selections from which 'me' depends This list contains one Selection : the InputSelection", py::arg("iter"));
cls_IFSelect_SelectDeduct.def_static("get_type_name_", (const char * (*)()) &IFSelect_SelectDeduct::get_type_name, "None");
cls_IFSelect_SelectDeduct.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_SelectDeduct::get_type_descriptor, "None");
cls_IFSelect_SelectDeduct.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_SelectDeduct::*)() const) &IFSelect_SelectDeduct::DynamicType, "None");

// Enums

}