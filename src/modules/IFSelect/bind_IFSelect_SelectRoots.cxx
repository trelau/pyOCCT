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
#include <IFSelect_SelectExtract.hxx>
#include <Interface_EntityIterator.hxx>
#include <Interface_Graph.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Transient.hxx>
#include <Interface_InterfaceModel.hxx>
#include <TCollection_AsciiString.hxx>
#include <IFSelect_SelectRoots.hxx>
#include <Standard_Type.hxx>

void bind_IFSelect_SelectRoots(py::module &mod){

py::class_<IFSelect_SelectRoots, opencascade::handle<IFSelect_SelectRoots>, IFSelect_SelectExtract> cls_IFSelect_SelectRoots(mod, "IFSelect_SelectRoots", "A SelectRoots sorts the Entities which are local roots of a set of Entities (not shared by other Entities inside this set, even if they are shared by other Entities outside it)");

// Constructors
cls_IFSelect_SelectRoots.def(py::init<>());

// Fields

// Methods
cls_IFSelect_SelectRoots.def("RootResult", (Interface_EntityIterator (IFSelect_SelectRoots::*)(const Interface_Graph &) const) &IFSelect_SelectRoots::RootResult, "Returns the list of local roots. It is redefined for a purpose of effeciency : calling a Sort routine for each Entity would cost more ressource than to work in once using a Map RootResult takes in account the Direct status", py::arg("G"));
cls_IFSelect_SelectRoots.def("Sort", (Standard_Boolean (IFSelect_SelectRoots::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &) const) &IFSelect_SelectRoots::Sort, "Returns always True, because RootResult has done work", py::arg("rank"), py::arg("ent"), py::arg("model"));
cls_IFSelect_SelectRoots.def("ExtractLabel", (TCollection_AsciiString (IFSelect_SelectRoots::*)() const) &IFSelect_SelectRoots::ExtractLabel, "Returns a text defining the criterium : 'Local Root Entities'");
cls_IFSelect_SelectRoots.def_static("get_type_name_", (const char * (*)()) &IFSelect_SelectRoots::get_type_name, "None");
cls_IFSelect_SelectRoots.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_SelectRoots::get_type_descriptor, "None");
cls_IFSelect_SelectRoots.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_SelectRoots::*)() const) &IFSelect_SelectRoots::DynamicType, "None");

// Enums

}