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
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <Standard_TypeDef.hxx>
#include <IFSelect_Selection.hxx>
#include <IFSelect_SelectionIterator.hxx>
#include <TCollection_AsciiString.hxx>
#include <Interface_EntityIterator.hxx>
#include <Interface_Graph.hxx>
#include <IFGraph_SubPartsIterator.hxx>
#include <IFSelect_Dispatch.hxx>
#include <Standard_Type.hxx>

void bind_IFSelect_Dispatch(py::module &mod){

py::class_<IFSelect_Dispatch, opencascade::handle<IFSelect_Dispatch>, Standard_Transient> cls_IFSelect_Dispatch(mod, "IFSelect_Dispatch", "This class allows to describe how a set of Entities has to be dispatched into resulting Packets : a Packet is a sub-set of the initial set of entities.");

// Fields

// Methods
cls_IFSelect_Dispatch.def("SetRootName", (void (IFSelect_Dispatch::*)(const opencascade::handle<TCollection_HAsciiString> &)) &IFSelect_Dispatch::SetRootName, "Sets a Root Name as an HAsciiString To reset it, give a Null Handle (then, a ShareOut will have to define the Default Root Name)", py::arg("name"));
cls_IFSelect_Dispatch.def("HasRootName", (Standard_Boolean (IFSelect_Dispatch::*)() const) &IFSelect_Dispatch::HasRootName, "Returns True if a specific Root Name has been set (else, the Default Root Name has to be used)");
cls_IFSelect_Dispatch.def("RootName", (const opencascade::handle<TCollection_HAsciiString> & (IFSelect_Dispatch::*)() const) &IFSelect_Dispatch::RootName, "Returns the Root Name for files produced by this dispatch It is empty if it has not been set or if it has been reset");
cls_IFSelect_Dispatch.def("SetFinalSelection", (void (IFSelect_Dispatch::*)(const opencascade::handle<IFSelect_Selection> &)) &IFSelect_Dispatch::SetFinalSelection, "Stores (or Changes) the Final Selection for a Dispatch", py::arg("sel"));
cls_IFSelect_Dispatch.def("FinalSelection", (opencascade::handle<IFSelect_Selection> (IFSelect_Dispatch::*)() const) &IFSelect_Dispatch::FinalSelection, "Returns the Final Selection of a Dispatch we 'd like : C++ : return const &");
cls_IFSelect_Dispatch.def("Selections", (IFSelect_SelectionIterator (IFSelect_Dispatch::*)() const) &IFSelect_Dispatch::Selections, "Returns the complete list of source Selections (starting from FinalSelection)");
cls_IFSelect_Dispatch.def("CanHaveRemainder", (Standard_Boolean (IFSelect_Dispatch::*)() const) &IFSelect_Dispatch::CanHaveRemainder, "Returns True if a Dispatch can have a Remainder, i.e. if its criterium can let entities apart. It is a potential answer, remainder can be empty at run-time even if answer is True. (to attach a RemainderFromDispatch Selection is not allowed if answer is True). Default answer given here is False (can be redefined)");
cls_IFSelect_Dispatch.def("LimitedMax", [](IFSelect_Dispatch &self, const Standard_Integer nbent, Standard_Integer & max){ Standard_Boolean rv = self.LimitedMax(nbent, max); return std::tuple<Standard_Boolean, Standard_Integer &>(rv, max); }, "Returns True if a Dispatch generates a count of Packets always less than or equal to a maximum value : it can be computed from the total count of Entities to be dispatched : <nbent>. If answer is False, no limited maximum is expected for account If answer is True, expected maximum is given in argument <max> Default answer given here is False (can be redefined)", py::arg("nbent"), py::arg("max"));
cls_IFSelect_Dispatch.def("Label", (TCollection_AsciiString (IFSelect_Dispatch::*)() const) &IFSelect_Dispatch::Label, "Returns a text which defines the way a Dispatch produces packets (which will become files) from its Input");
cls_IFSelect_Dispatch.def("GetEntities", (Interface_EntityIterator (IFSelect_Dispatch::*)(const Interface_Graph &) const) &IFSelect_Dispatch::GetEntities, "Gets Unique Root Entities from the Final Selection, given an input Graph This the starting step for an Evaluation (Packets - Remainder)", py::arg("G"));
cls_IFSelect_Dispatch.def("Packets", (void (IFSelect_Dispatch::*)(const Interface_Graph &, IFGraph_SubPartsIterator &) const) &IFSelect_Dispatch::Packets, "Returns the list of produced Packets into argument <pack>. Each Packet corresponds to a Part, the Entities listed are the Roots given by the Selection. Input is given as a Graph. Thus, to create a file from a packet, it suffices to take the entities listed in a Part of Packets (that is, a Packet) without worrying about Shared entities This method can raise an Exception if data are not coherent", py::arg("G"), py::arg("packs"));
cls_IFSelect_Dispatch.def("Packeted", (Interface_EntityIterator (IFSelect_Dispatch::*)(const Interface_Graph &) const) &IFSelect_Dispatch::Packeted, "Returns the list of all Input Entities (see GetEntities) which are put in a Packet. That is, Entities listed in GetEntities but not in Remainder (see below). Input is given as a Graph.", py::arg("G"));
cls_IFSelect_Dispatch.def("Remainder", (Interface_EntityIterator (IFSelect_Dispatch::*)(const Interface_Graph &) const) &IFSelect_Dispatch::Remainder, "Returns Remainder which is a set of Entities. Can be empty. Default evaluation is empty (has to be redefined if CanHaveRemainder is redefined to return True).", py::arg("G"));
cls_IFSelect_Dispatch.def_static("get_type_name_", (const char * (*)()) &IFSelect_Dispatch::get_type_name, "None");
cls_IFSelect_Dispatch.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_Dispatch::get_type_descriptor, "None");
cls_IFSelect_Dispatch.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_Dispatch::*)() const) &IFSelect_Dispatch::DynamicType, "None");

// Enums

}