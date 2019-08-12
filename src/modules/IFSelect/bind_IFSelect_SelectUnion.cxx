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
#include <IFSelect_SelectCombine.hxx>
#include <Interface_EntityIterator.hxx>
#include <Interface_Graph.hxx>
#include <TCollection_AsciiString.hxx>
#include <Standard_Handle.hxx>
#include <IFSelect_SelectUnion.hxx>
#include <Standard_Type.hxx>

void bind_IFSelect_SelectUnion(py::module &mod){

py::class_<IFSelect_SelectUnion, opencascade::handle<IFSelect_SelectUnion>, IFSelect_SelectCombine> cls_IFSelect_SelectUnion(mod, "IFSelect_SelectUnion", "A SelectUnion cumulates the Entities issued from several other Selections (union of results : 'OR' operator)");

// Constructors
cls_IFSelect_SelectUnion.def(py::init<>());

// Fields

// Methods
cls_IFSelect_SelectUnion.def("RootResult", (Interface_EntityIterator (IFSelect_SelectUnion::*)(const Interface_Graph &) const) &IFSelect_SelectUnion::RootResult, "Returns the list of selected Entities, which is the addition result from all input selections. Uniqueness is guaranteed.", py::arg("G"));
cls_IFSelect_SelectUnion.def("Label", (TCollection_AsciiString (IFSelect_SelectUnion::*)() const) &IFSelect_SelectUnion::Label, "Returns a text defining the criterium : 'Union (OR)'");
cls_IFSelect_SelectUnion.def_static("get_type_name_", (const char * (*)()) &IFSelect_SelectUnion::get_type_name, "None");
cls_IFSelect_SelectUnion.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_SelectUnion::get_type_descriptor, "None");
cls_IFSelect_SelectUnion.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_SelectUnion::*)() const) &IFSelect_SelectUnion::DynamicType, "None");

// Enums

}