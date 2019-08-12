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
#include <IFSelect_SelectBase.hxx>
#include <Interface_EntityIterator.hxx>
#include <Interface_Graph.hxx>
#include <TCollection_AsciiString.hxx>
#include <Standard_Handle.hxx>
#include <IFSelect_SelectModelRoots.hxx>
#include <Standard_Type.hxx>

void bind_IFSelect_SelectModelRoots(py::module &mod){

py::class_<IFSelect_SelectModelRoots, opencascade::handle<IFSelect_SelectModelRoots>, IFSelect_SelectBase> cls_IFSelect_SelectModelRoots(mod, "IFSelect_SelectModelRoots", "A SelectModelRoots gets all the Root Entities of an InterfaceModel. Remember that a 'Root Entity' is defined as having no Sharing Entity (if there is a Loop between Entities, none of them can be a 'Root').");

// Constructors
cls_IFSelect_SelectModelRoots.def(py::init<>());

// Fields

// Methods
cls_IFSelect_SelectModelRoots.def("RootResult", (Interface_EntityIterator (IFSelect_SelectModelRoots::*)(const Interface_Graph &) const) &IFSelect_SelectModelRoots::RootResult, "Returns the list of selected entities : the Roots of the Model (note that this result assures naturally uniqueness)", py::arg("G"));
cls_IFSelect_SelectModelRoots.def("Label", (TCollection_AsciiString (IFSelect_SelectModelRoots::*)() const) &IFSelect_SelectModelRoots::Label, "Returns a text defining the criterium : 'Model Roots'");
cls_IFSelect_SelectModelRoots.def_static("get_type_name_", (const char * (*)()) &IFSelect_SelectModelRoots::get_type_name, "None");
cls_IFSelect_SelectModelRoots.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_SelectModelRoots::get_type_descriptor, "None");
cls_IFSelect_SelectModelRoots.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_SelectModelRoots::*)() const) &IFSelect_SelectModelRoots::DynamicType, "None");

// Enums

}