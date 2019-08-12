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
#include <IFSelect_SelectControl.hxx>
#include <Interface_EntityIterator.hxx>
#include <Interface_Graph.hxx>
#include <TCollection_AsciiString.hxx>
#include <Standard_Handle.hxx>
#include <IFSelect_SelectDiff.hxx>
#include <Standard_Type.hxx>
#include <Standard_TypeDef.hxx>

void bind_IFSelect_SelectDiff(py::module &mod){

py::class_<IFSelect_SelectDiff, opencascade::handle<IFSelect_SelectDiff>, IFSelect_SelectControl> cls_IFSelect_SelectDiff(mod, "IFSelect_SelectDiff", "A SelectDiff keeps the entities from a Selection, the Main Input, which are not listed by the Second Input");

// Constructors
cls_IFSelect_SelectDiff.def(py::init<>());

// Fields

// Methods
cls_IFSelect_SelectDiff.def("RootResult", (Interface_EntityIterator (IFSelect_SelectDiff::*)(const Interface_Graph &) const) &IFSelect_SelectDiff::RootResult, "Returns the list of selected entities : they are the Entities gotten from the Main Input but not from the Diff Input", py::arg("G"));
cls_IFSelect_SelectDiff.def("Label", (TCollection_AsciiString (IFSelect_SelectDiff::*)() const) &IFSelect_SelectDiff::Label, "Returns a text defining the criterium : 'Difference'");
cls_IFSelect_SelectDiff.def_static("get_type_name_", (const char * (*)()) &IFSelect_SelectDiff::get_type_name, "None");
cls_IFSelect_SelectDiff.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_SelectDiff::get_type_descriptor, "None");
cls_IFSelect_SelectDiff.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_SelectDiff::*)() const) &IFSelect_SelectDiff::DynamicType, "None");

// Enums

}