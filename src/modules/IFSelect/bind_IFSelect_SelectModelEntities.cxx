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
#include <IFSelect_SelectModelEntities.hxx>
#include <Standard_Type.hxx>

void bind_IFSelect_SelectModelEntities(py::module &mod){

py::class_<IFSelect_SelectModelEntities, opencascade::handle<IFSelect_SelectModelEntities>, IFSelect_SelectBase> cls_IFSelect_SelectModelEntities(mod, "IFSelect_SelectModelEntities", "A SelectModelEntities gets all the Entities of an InterfaceModel.");

// Constructors
cls_IFSelect_SelectModelEntities.def(py::init<>());

// Fields

// Methods
cls_IFSelect_SelectModelEntities.def("RootResult", (Interface_EntityIterator (IFSelect_SelectModelEntities::*)(const Interface_Graph &) const) &IFSelect_SelectModelEntities::RootResult, "Returns the list of selected entities : the Entities of the Model (note that this result assures naturally uniqueness)", py::arg("G"));
cls_IFSelect_SelectModelEntities.def("CompleteResult", (Interface_EntityIterator (IFSelect_SelectModelEntities::*)(const Interface_Graph &) const) &IFSelect_SelectModelEntities::CompleteResult, "The complete list of Entities (including shared ones) ... is exactly identical to RootResults in this case", py::arg("G"));
cls_IFSelect_SelectModelEntities.def("Label", (TCollection_AsciiString (IFSelect_SelectModelEntities::*)() const) &IFSelect_SelectModelEntities::Label, "Returns a text defining the criterium : 'Model Entities'");
cls_IFSelect_SelectModelEntities.def_static("get_type_name_", (const char * (*)()) &IFSelect_SelectModelEntities::get_type_name, "None");
cls_IFSelect_SelectModelEntities.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_SelectModelEntities::get_type_descriptor, "None");
cls_IFSelect_SelectModelEntities.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_SelectModelEntities::*)() const) &IFSelect_SelectModelEntities::DynamicType, "None");

// Enums

}