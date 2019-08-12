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
#include <Interface_InterfaceModel.hxx>
#include <TCollection_AsciiString.hxx>
#include <IFSelect_SelectExtract.hxx>
#include <Standard_Type.hxx>

void bind_IFSelect_SelectExtract(py::module &mod){

py::class_<IFSelect_SelectExtract, opencascade::handle<IFSelect_SelectExtract>, IFSelect_SelectDeduct> cls_IFSelect_SelectExtract(mod, "IFSelect_SelectExtract", "A SelectExtract determines a list of Entities from an Input Selection, as a sub-list of the Input Result It works by applying a sort criterium on each Entity of the Input. This criterium can be applied Direct to Pick Items (default case) or Reverse to Remove Item");

// Fields

// Methods
cls_IFSelect_SelectExtract.def("IsDirect", (Standard_Boolean (IFSelect_SelectExtract::*)() const) &IFSelect_SelectExtract::IsDirect, "Returns True if Sort criterium is Direct, False if Reverse");
cls_IFSelect_SelectExtract.def("SetDirect", (void (IFSelect_SelectExtract::*)(const Standard_Boolean)) &IFSelect_SelectExtract::SetDirect, "Sets Sort criterium sense to a new value (True : Direct , False : Reverse)", py::arg("direct"));
cls_IFSelect_SelectExtract.def("RootResult", (Interface_EntityIterator (IFSelect_SelectExtract::*)(const Interface_Graph &) const) &IFSelect_SelectExtract::RootResult, "Returns the list of selected entities. Works by calling the method Sort on each input Entity : the Entity is kept as output if Sort returns the same value as Direct status", py::arg("G"));
cls_IFSelect_SelectExtract.def("Sort", (Standard_Boolean (IFSelect_SelectExtract::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &) const) &IFSelect_SelectExtract::Sort, "Returns True for an Entity if it satisfies the Sort criterium It receives : - <rank>, the rank of the Entity in the Iteration, - <ent> , the Entity itself, and - <model>, the Starting Model Hence, the Entity to check is 'model->Value(num)' (but an InterfaceModel allows other checks) This method is specific to each class of SelectExtract", py::arg("rank"), py::arg("ent"), py::arg("model"));
cls_IFSelect_SelectExtract.def("SortInGraph", (Standard_Boolean (IFSelect_SelectExtract::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const Interface_Graph &) const) &IFSelect_SelectExtract::SortInGraph, "Works as Sort but works on the Graph Default directly calls Sort, but it can be redefined If SortInGraph is redefined, Sort should be defined even if not called (to avoid deferred methods in a final class)", py::arg("rank"), py::arg("ent"), py::arg("G"));
cls_IFSelect_SelectExtract.def("Label", (TCollection_AsciiString (IFSelect_SelectExtract::*)() const) &IFSelect_SelectExtract::Label, "Returns a text saying 'Picked' or 'Removed', plus the specific criterium returned by ExtractLabel (see below)");
cls_IFSelect_SelectExtract.def("ExtractLabel", (TCollection_AsciiString (IFSelect_SelectExtract::*)() const) &IFSelect_SelectExtract::ExtractLabel, "Returns a text defining the criterium for extraction");
cls_IFSelect_SelectExtract.def_static("get_type_name_", (const char * (*)()) &IFSelect_SelectExtract::get_type_name, "None");
cls_IFSelect_SelectExtract.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_SelectExtract::get_type_descriptor, "None");
cls_IFSelect_SelectExtract.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_SelectExtract::*)() const) &IFSelect_SelectExtract::DynamicType, "None");

// Enums

}