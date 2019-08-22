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
#include <Standard.hxx>
#include <Interface_Graph.hxx>
#include <Interface_CopyTool.hxx>
#include <Standard_TypeDef.hxx>
#include <Interface_EntityIterator.hxx>
#include <Standard_Handle.hxx>
#include <Interface_InterfaceModel.hxx>
#include <Interface_Protocol.hxx>
#include <Interface_CopyControl.hxx>
#include <Standard_Transient.hxx>
#include <IFSelect_GeneralModifier.hxx>
#include <Interface_Check.hxx>
#include <Interface_CheckIterator.hxx>
#include <TCollection_AsciiString.hxx>
#include <IFSelect_ContextModif.hxx>

void bind_IFSelect_ContextModif(py::module &mod){

py::class_<IFSelect_ContextModif> cls_IFSelect_ContextModif(mod, "IFSelect_ContextModif", "This class gathers various informations used by Model Modifiers apart from the target model itself, and the CopyTool which must be passed directly.");

// Constructors
cls_IFSelect_ContextModif.def(py::init<const Interface_Graph &, const Interface_CopyTool &>(), py::arg("graph"), py::arg("TC"));
cls_IFSelect_ContextModif.def(py::init<const Interface_Graph &, const Interface_CopyTool &, const Standard_CString>(), py::arg("graph"), py::arg("TC"), py::arg("filename"));
cls_IFSelect_ContextModif.def(py::init<const Interface_Graph &>(), py::arg("graph"));
cls_IFSelect_ContextModif.def(py::init<const Interface_Graph &, const Standard_CString>(), py::arg("graph"), py::arg("filename"));

// Fields

// Methods
// cls_IFSelect_ContextModif.def_static("operator new_", (void * (*)(size_t)) &IFSelect_ContextModif::operator new, "None", py::arg("theSize"));
// cls_IFSelect_ContextModif.def_static("operator delete_", (void (*)(void *)) &IFSelect_ContextModif::operator delete, "None", py::arg("theAddress"));
// cls_IFSelect_ContextModif.def_static("operator new[]_", (void * (*)(size_t)) &IFSelect_ContextModif::operator new[], "None", py::arg("theSize"));
// cls_IFSelect_ContextModif.def_static("operator delete[]_", (void (*)(void *)) &IFSelect_ContextModif::operator delete[], "None", py::arg("theAddress"));
// cls_IFSelect_ContextModif.def_static("operator new_", (void * (*)(size_t, void *)) &IFSelect_ContextModif::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IFSelect_ContextModif.def_static("operator delete_", (void (*)(void *, void *)) &IFSelect_ContextModif::operator delete, "None", py::arg(""), py::arg(""));
cls_IFSelect_ContextModif.def("Select", (void (IFSelect_ContextModif::*)(Interface_EntityIterator &)) &IFSelect_ContextModif::Select, "This method requires ContextModif to be applied with a filter. If a ModelModifier is defined with a Selection criterium, the result of this Selection is used as a filter : - if none of its items has been transferred, the modification does not apply at all - else, the Modifier can query for what entities were selected and what are their results - if this method is not called before working, the Modifier has to work on the whole Model", py::arg("list"));
cls_IFSelect_ContextModif.def("OriginalGraph", (const Interface_Graph & (IFSelect_ContextModif::*)() const) &IFSelect_ContextModif::OriginalGraph, "Returns the original Graph (compared to OriginalModel, it gives more query capabilitites)");
cls_IFSelect_ContextModif.def("OriginalModel", (opencascade::handle<Interface_InterfaceModel> (IFSelect_ContextModif::*)() const) &IFSelect_ContextModif::OriginalModel, "Returns the original model");
cls_IFSelect_ContextModif.def("SetProtocol", (void (IFSelect_ContextModif::*)(const opencascade::handle<Interface_Protocol> &)) &IFSelect_ContextModif::SetProtocol, "Allows to transmit a Protocol as part of a ContextModif", py::arg("proto"));
cls_IFSelect_ContextModif.def("Protocol", (opencascade::handle<Interface_Protocol> (IFSelect_ContextModif::*)() const) &IFSelect_ContextModif::Protocol, "Returns the Protocol (Null if not set)");
cls_IFSelect_ContextModif.def("HasFileName", (Standard_Boolean (IFSelect_ContextModif::*)() const) &IFSelect_ContextModif::HasFileName, "Returns True if a non empty file name has been defined");
cls_IFSelect_ContextModif.def("FileName", (Standard_CString (IFSelect_ContextModif::*)() const) &IFSelect_ContextModif::FileName, "Returns File Name (can be empty)");
cls_IFSelect_ContextModif.def("Control", (opencascade::handle<Interface_CopyControl> (IFSelect_ContextModif::*)() const) &IFSelect_ContextModif::Control, "Returns the map for a direct use, if required");
cls_IFSelect_ContextModif.def("IsForNone", (Standard_Boolean (IFSelect_ContextModif::*)() const) &IFSelect_ContextModif::IsForNone, "Returns True if Select has determined that a Modifier may not be run (filter defined and empty)");
cls_IFSelect_ContextModif.def("IsForAll", (Standard_Boolean (IFSelect_ContextModif::*)() const) &IFSelect_ContextModif::IsForAll, "Returns True if no filter is defined : a Modifier has to work on all entities of the resulting (target) model");
cls_IFSelect_ContextModif.def("IsTransferred", (Standard_Boolean (IFSelect_ContextModif::*)(const opencascade::handle<Standard_Transient> &) const) &IFSelect_ContextModif::IsTransferred, "Returns True if a starting item has been transferred", py::arg("ent"));
cls_IFSelect_ContextModif.def("IsSelected", (Standard_Boolean (IFSelect_ContextModif::*)(const opencascade::handle<Standard_Transient> &) const) &IFSelect_ContextModif::IsSelected, "Returns True if a starting item has been transferred and selected", py::arg("ent"));
// cls_IFSelect_ContextModif.def("Search", (Standard_Boolean (IFSelect_ContextModif::*)(const opencascade::handle<Standard_Transient> &, opencascade::handle<Standard_Transient> &) const) &IFSelect_ContextModif::Search, "Returns True if a starting entity has been transferred, and the result is in <res>. Returns False else (direct call to the map)", py::arg("ent"), py::arg("res"));
cls_IFSelect_ContextModif.def("SelectedOriginal", (Interface_EntityIterator (IFSelect_ContextModif::*)() const) &IFSelect_ContextModif::SelectedOriginal, "Returns the list of original selected items. See also the iteration");
cls_IFSelect_ContextModif.def("SelectedResult", (Interface_EntityIterator (IFSelect_ContextModif::*)() const) &IFSelect_ContextModif::SelectedResult, "Returns the list of resulting counterparts of selected items. See also the iteration");
cls_IFSelect_ContextModif.def("SelectedCount", (Standard_Integer (IFSelect_ContextModif::*)() const) &IFSelect_ContextModif::SelectedCount, "Returns the count of selected and transferred items");
cls_IFSelect_ContextModif.def("Start", (void (IFSelect_ContextModif::*)()) &IFSelect_ContextModif::Start, "Starts an iteration on selected items. It takes into account IsForAll/IsForNone, by really iterating on all selected items.");
cls_IFSelect_ContextModif.def("More", (Standard_Boolean (IFSelect_ContextModif::*)() const) &IFSelect_ContextModif::More, "Returns True until the iteration has finished");
cls_IFSelect_ContextModif.def("Next", (void (IFSelect_ContextModif::*)()) &IFSelect_ContextModif::Next, "Advances the iteration");
cls_IFSelect_ContextModif.def("ValueOriginal", (opencascade::handle<Standard_Transient> (IFSelect_ContextModif::*)() const) &IFSelect_ContextModif::ValueOriginal, "Returns the current selected item in the original model");
cls_IFSelect_ContextModif.def("ValueResult", (opencascade::handle<Standard_Transient> (IFSelect_ContextModif::*)() const) &IFSelect_ContextModif::ValueResult, "Returns the result counterpart of current selected item (in the target model)");
cls_IFSelect_ContextModif.def("TraceModifier", (void (IFSelect_ContextModif::*)(const opencascade::handle<IFSelect_GeneralModifier> &)) &IFSelect_ContextModif::TraceModifier, "Traces the application of a Modifier. Works with default trace File and Level. Fills the trace if default trace level is at least 1. Traces the Modifier (its Label) and its Selection if there is one (its Label). To be called after Select (because status IsForAll is printed) Worths to trace a global modification. See also Trace below", py::arg("modif"));
cls_IFSelect_ContextModif.def("Trace", [](IFSelect_ContextModif &self) -> void { return self.Trace(); });
cls_IFSelect_ContextModif.def("Trace", (void (IFSelect_ContextModif::*)(const Standard_CString)) &IFSelect_ContextModif::Trace, "Traces the modification of the current entity (see above, ValueOriginal and ValueResult) for default trace level >= 2. To be called on each indivudual entity really modified <mess> is an optionnal additional message", py::arg("mess"));
cls_IFSelect_ContextModif.def("AddCheck", (void (IFSelect_ContextModif::*)(const opencascade::handle<Interface_Check> &)) &IFSelect_ContextModif::AddCheck, "Adds a Check to the CheckList. If it is empty, nothing is done If it concerns an Entity from the Original Model (by SetEntity) to which another Check is attached, it is merged to it. Else, it is added or merged as to GlobalCheck.", py::arg("check"));
cls_IFSelect_ContextModif.def("AddWarning", [](IFSelect_ContextModif &self, const opencascade::handle<Standard_Transient> & a0, const Standard_CString a1) -> void { return self.AddWarning(a0, a1); });
cls_IFSelect_ContextModif.def("AddWarning", (void (IFSelect_ContextModif::*)(const opencascade::handle<Standard_Transient> &, const Standard_CString, const Standard_CString)) &IFSelect_ContextModif::AddWarning, "Adds a Warning Message for an Entity from the original Model If <start> is not an Entity from the original model (e.g. the model itself) this message is added to Global Check.", py::arg("start"), py::arg("mess"), py::arg("orig"));
cls_IFSelect_ContextModif.def("AddFail", [](IFSelect_ContextModif &self, const opencascade::handle<Standard_Transient> & a0, const Standard_CString a1) -> void { return self.AddFail(a0, a1); });
cls_IFSelect_ContextModif.def("AddFail", (void (IFSelect_ContextModif::*)(const opencascade::handle<Standard_Transient> &, const Standard_CString, const Standard_CString)) &IFSelect_ContextModif::AddFail, "Adds a Fail Message for an Entity from the original Model If <start> is not an Entity from the original model (e.g. the model itself) this message is added to Global Check.", py::arg("start"), py::arg("mess"), py::arg("orig"));
cls_IFSelect_ContextModif.def("CCheck", [](IFSelect_ContextModif &self) -> opencascade::handle<Interface_Check> { return self.CCheck(); });
cls_IFSelect_ContextModif.def("CCheck", (opencascade::handle<Interface_Check> (IFSelect_ContextModif::*)(const Standard_Integer)) &IFSelect_ContextModif::CCheck, "Returns a Check given an Entity number (in the original Model) by default a Global Check. Creates it the first time. It can then be acknowledged on the spot, in condition that the caller works by reference ('Interface_Check& check = ...')", py::arg("num"));
cls_IFSelect_ContextModif.def("CCheck", (opencascade::handle<Interface_Check> (IFSelect_ContextModif::*)(const opencascade::handle<Standard_Transient> &)) &IFSelect_ContextModif::CCheck, "Returns a Check attached to an Entity from the original Model It can then be acknowledged on the spot, in condition that the caller works by reference ('Interface_Check& check = ...')", py::arg("start"));
cls_IFSelect_ContextModif.def("CheckList", (Interface_CheckIterator (IFSelect_ContextModif::*)() const) &IFSelect_ContextModif::CheckList, "Returns the complete CheckList");

// Enums

}