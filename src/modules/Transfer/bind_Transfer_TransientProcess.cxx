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
#include <Transfer_ProcessForTransient.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Interface_InterfaceModel.hxx>
#include <Interface_HGraph.hxx>
#include <Interface_Graph.hxx>
#include <Standard_Transient.hxx>
#include <Standard_Type.hxx>
#include <NCollection_DataMap.hxx>
#include <TCollection_AsciiString.hxx>
#include <Message_Messenger.hxx>
#include <Interface_EntityIterator.hxx>
#include <TColStd_HSequenceOfTransient.hxx>
#include <Transfer_TransientProcess.hxx>

void bind_Transfer_TransientProcess(py::module &mod){

py::class_<Transfer_TransientProcess, opencascade::handle<Transfer_TransientProcess>, Transfer_ProcessForTransient> cls_Transfer_TransientProcess(mod, "Transfer_TransientProcess", "Adds specific features to the generic definition : TransientProcess is intended to work from an InterfaceModel to a set of application objects.");

// Constructors
cls_Transfer_TransientProcess.def(py::init<>());
cls_Transfer_TransientProcess.def(py::init<const Standard_Integer>(), py::arg("nb"));

// Fields

// Methods
cls_Transfer_TransientProcess.def("SetModel", (void (Transfer_TransientProcess::*)(const opencascade::handle<Interface_InterfaceModel> &)) &Transfer_TransientProcess::SetModel, "Sets an InterfaceModel, used by StartTrace, CheckList, queries on Integrity, to give informations significant for each norm.", py::arg("model"));
cls_Transfer_TransientProcess.def("Model", (opencascade::handle<Interface_InterfaceModel> (Transfer_TransientProcess::*)() const) &Transfer_TransientProcess::Model, "Returns the Model used for StartTrace");
cls_Transfer_TransientProcess.def("SetGraph", (void (Transfer_TransientProcess::*)(const opencascade::handle<Interface_HGraph> &)) &Transfer_TransientProcess::SetGraph, "Sets a Graph : superseedes SetModel if already done", py::arg("HG"));
cls_Transfer_TransientProcess.def("HasGraph", (Standard_Boolean (Transfer_TransientProcess::*)() const) &Transfer_TransientProcess::HasGraph, "None");
cls_Transfer_TransientProcess.def("HGraph", (opencascade::handle<Interface_HGraph> (Transfer_TransientProcess::*)() const) &Transfer_TransientProcess::HGraph, "None");
cls_Transfer_TransientProcess.def("Graph", (const Interface_Graph & (Transfer_TransientProcess::*)() const) &Transfer_TransientProcess::Graph, "None");
cls_Transfer_TransientProcess.def("SetContext", (void (Transfer_TransientProcess::*)(const Standard_CString, const opencascade::handle<Standard_Transient> &)) &Transfer_TransientProcess::SetContext, "Sets a Context : according to receiving appli, to be interpreted by the Actor", py::arg("name"), py::arg("ctx"));
cls_Transfer_TransientProcess.def("GetContext", (Standard_Boolean (Transfer_TransientProcess::*)(const Standard_CString, const opencascade::handle<Standard_Type> &, opencascade::handle<Standard_Transient> &) const) &Transfer_TransientProcess::GetContext, "Returns the Context attached to a name, if set and if it is Kind of the type, else a Null Handle Returns True if OK, False if no Context", py::arg("name"), py::arg("type"), py::arg("ctx"));
cls_Transfer_TransientProcess.def("Context", (NCollection_DataMap<TCollection_AsciiString, opencascade::handle<Standard_Transient> > & (Transfer_TransientProcess::*)()) &Transfer_TransientProcess::Context, "Returns (modifiable) the whole definition of Context Rather for internal use (ex.: preparing and setting in once)");
cls_Transfer_TransientProcess.def("PrintTrace", (void (Transfer_TransientProcess::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Message_Messenger> &) const) &Transfer_TransientProcess::PrintTrace, "Specific printing to trace an entity : prints label and type (if model is set)", py::arg("start"), py::arg("S"));
cls_Transfer_TransientProcess.def("CheckNum", (Standard_Integer (Transfer_TransientProcess::*)(const opencascade::handle<Standard_Transient> &) const) &Transfer_TransientProcess::CheckNum, "Specific number of a starting object for check-list : Number in model", py::arg("ent"));
cls_Transfer_TransientProcess.def("TypedSharings", (Interface_EntityIterator (Transfer_TransientProcess::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Standard_Type> &) const) &Transfer_TransientProcess::TypedSharings, "Returns the list of sharings entities, AT ANY LEVEL, which are kind of a given type. Calls TypedSharings from Graph Returns an empty list if the Graph has not been aknowledged", py::arg("start"), py::arg("type"));
cls_Transfer_TransientProcess.def("IsDataLoaded", (Standard_Boolean (Transfer_TransientProcess::*)(const opencascade::handle<Standard_Transient> &) const) &Transfer_TransientProcess::IsDataLoaded, "Tells if an entity is well loaded from file (even if its data fail on checking, they are present). Mostly often, answers True. Else, there was a syntactic error in the file. A non-loaded entity MAY NOT BE transferred, unless its Report (in the model) is interpreted", py::arg("ent"));
cls_Transfer_TransientProcess.def("IsDataFail", (Standard_Boolean (Transfer_TransientProcess::*)(const opencascade::handle<Standard_Transient> &) const) &Transfer_TransientProcess::IsDataFail, "Tells if an entity fails on data checking (load time, syntactic, or semantic check). Normally, should answer False. It is not prudent to try transferring an entity which fails on data checking", py::arg("ent"));
cls_Transfer_TransientProcess.def("PrintStats", (void (Transfer_TransientProcess::*)(const Standard_Integer, const opencascade::handle<Message_Messenger> &) const) &Transfer_TransientProcess::PrintStats, "Prints statistics on a given output, according mode", py::arg("mode"), py::arg("S"));
cls_Transfer_TransientProcess.def("RootsForTransfer", (opencascade::handle<TColStd_HSequenceOfTransient> (Transfer_TransientProcess::*)()) &Transfer_TransientProcess::RootsForTransfer, "None");
cls_Transfer_TransientProcess.def_static("get_type_name_", (const char * (*)()) &Transfer_TransientProcess::get_type_name, "None");
cls_Transfer_TransientProcess.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Transfer_TransientProcess::get_type_descriptor, "None");
cls_Transfer_TransientProcess.def("DynamicType", (const opencascade::handle<Standard_Type> & (Transfer_TransientProcess::*)() const) &Transfer_TransientProcess::DynamicType, "None");

// Enums

}