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
#include <IFSelect_SelectRootComps.hxx>
#include <Standard_Type.hxx>

void bind_IFSelect_SelectRootComps(py::module &mod){

py::class_<IFSelect_SelectRootComps, opencascade::handle<IFSelect_SelectRootComps>, IFSelect_SelectExtract> cls_IFSelect_SelectRootComps(mod, "IFSelect_SelectRootComps", "A SelectRootComps sorts the Entities which are part of Strong Componants, local roots of a set of Entities : they can be Single Componants (containing one Entity) or Cycles This class gives a more secure result than SelectRoots (which considers only Single Componants) but is longer to work : it can be used when there can be or there are cycles in a Model For each cycle, one Entity is given arbitrarily Reject works as for SelectRoots : Strong Componants defined in the input list which are not local roots are given");

// Constructors
cls_IFSelect_SelectRootComps.def(py::init<>());

// Fields

// Methods
cls_IFSelect_SelectRootComps.def("RootResult", (Interface_EntityIterator (IFSelect_SelectRootComps::*)(const Interface_Graph &) const) &IFSelect_SelectRootComps::RootResult, "Returns the list of local root strong componants, by one Entity par componant. It is redefined for a purpose of effeciency : calling a Sort routine for each Entity would cost more ressource than to work in once using a Map RootResult takes in account the Direct status", py::arg("G"));
cls_IFSelect_SelectRootComps.def("Sort", (Standard_Boolean (IFSelect_SelectRootComps::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &) const) &IFSelect_SelectRootComps::Sort, "Returns always True, because RootResult has done work", py::arg("rank"), py::arg("ent"), py::arg("model"));
cls_IFSelect_SelectRootComps.def("ExtractLabel", (TCollection_AsciiString (IFSelect_SelectRootComps::*)() const) &IFSelect_SelectRootComps::ExtractLabel, "Returns a text defining the criterium : 'Local Root Componants'");
cls_IFSelect_SelectRootComps.def_static("get_type_name_", (const char * (*)()) &IFSelect_SelectRootComps::get_type_name, "None");
cls_IFSelect_SelectRootComps.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_SelectRootComps::get_type_descriptor, "None");
cls_IFSelect_SelectRootComps.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_SelectRootComps::*)() const) &IFSelect_SelectRootComps::DynamicType, "None");

// Enums

}