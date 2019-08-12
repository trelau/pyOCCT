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
#include <Interface_Graph.hxx>
#include <TCollection_AsciiString.hxx>
#include <Standard_Handle.hxx>
#include <IFSelect_SelectSharing.hxx>
#include <Standard_Type.hxx>

void bind_IFSelect_SelectSharing(py::module &mod){

py::class_<IFSelect_SelectSharing, opencascade::handle<IFSelect_SelectSharing>, IFSelect_SelectDeduct> cls_IFSelect_SelectSharing(mod, "IFSelect_SelectSharing", "A SelectSharing selects Entities which directly Share (Level One) the Entities of the Input list Remark : if an Entity of the Input List directly shares another one, it is of course present in the Result List");

// Constructors
cls_IFSelect_SelectSharing.def(py::init<>());

// Fields

// Methods
cls_IFSelect_SelectSharing.def("RootResult", (Interface_EntityIterator (IFSelect_SelectSharing::*)(const Interface_Graph &) const) &IFSelect_SelectSharing::RootResult, "Returns the list of selected entities (list of entities which share (level one) those of input list)", py::arg("G"));
cls_IFSelect_SelectSharing.def("Label", (TCollection_AsciiString (IFSelect_SelectSharing::*)() const) &IFSelect_SelectSharing::Label, "Returns a text defining the criterium : 'Sharing (one level)'");
cls_IFSelect_SelectSharing.def_static("get_type_name_", (const char * (*)()) &IFSelect_SelectSharing::get_type_name, "None");
cls_IFSelect_SelectSharing.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_SelectSharing::get_type_descriptor, "None");
cls_IFSelect_SelectSharing.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_SelectSharing::*)() const) &IFSelect_SelectSharing::DynamicType, "None");

// Enums

}