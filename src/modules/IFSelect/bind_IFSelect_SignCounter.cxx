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
#include <IFSelect_SignatureList.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <IFSelect_Signature.hxx>
#include <Standard_Transient.hxx>
#include <Interface_InterfaceModel.hxx>
#include <TColStd_HSequenceOfTransient.hxx>
#include <Interface_Graph.hxx>
#include <IFSelect_Selection.hxx>
#include <TCollection_HAsciiString.hxx>
#include <IFSelect_SignCounter.hxx>
#include <Standard_Type.hxx>
#include <TColStd_MapOfTransient.hxx>

void bind_IFSelect_SignCounter(py::module &mod){

py::class_<IFSelect_SignCounter, opencascade::handle<IFSelect_SignCounter>, IFSelect_SignatureList> cls_IFSelect_SignCounter(mod, "IFSelect_SignCounter", "SignCounter gives the frame to count signatures associated with entities, deducted from them. Ex.: their Dynamic Type.");

// Constructors
cls_IFSelect_SignCounter.def(py::init<>());
cls_IFSelect_SignCounter.def(py::init<const Standard_Boolean>(), py::arg("withmap"));
cls_IFSelect_SignCounter.def(py::init<const Standard_Boolean, const Standard_Boolean>(), py::arg("withmap"), py::arg("withlist"));
cls_IFSelect_SignCounter.def(py::init<const opencascade::handle<IFSelect_Signature> &>(), py::arg("matcher"));
cls_IFSelect_SignCounter.def(py::init<const opencascade::handle<IFSelect_Signature> &, const Standard_Boolean>(), py::arg("matcher"), py::arg("withmap"));
cls_IFSelect_SignCounter.def(py::init<const opencascade::handle<IFSelect_Signature> &, const Standard_Boolean, const Standard_Boolean>(), py::arg("matcher"), py::arg("withmap"), py::arg("withlist"));

// Fields

// Methods
cls_IFSelect_SignCounter.def("Signature", (opencascade::handle<IFSelect_Signature> (IFSelect_SignCounter::*)() const) &IFSelect_SignCounter::Signature, "Returns the Signature used to count entities. It can be null.");
cls_IFSelect_SignCounter.def("SetMap", (void (IFSelect_SignCounter::*)(const Standard_Boolean)) &IFSelect_SignCounter::SetMap, "Changes the control status. The map is not cleared, simply its use changes", py::arg("withmap"));
cls_IFSelect_SignCounter.def("AddEntity", (Standard_Boolean (IFSelect_SignCounter::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &)) &IFSelect_SignCounter::AddEntity, "Adds an entity by considering its signature, which is given by call to method AddSign Returns True if added, False if already in the map (and map control status set)", py::arg("ent"), py::arg("model"));
cls_IFSelect_SignCounter.def("AddSign", (void (IFSelect_SignCounter::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &)) &IFSelect_SignCounter::AddSign, "Adds an entity (already filtered by Map) with its signature. This signature can be computed with the containing model. Its value is provided by the object Signature given at start, if no Signature is defined, it does nothing.", py::arg("ent"), py::arg("model"));
cls_IFSelect_SignCounter.def("AddList", (void (IFSelect_SignCounter::*)(const opencascade::handle<TColStd_HSequenceOfTransient> &, const opencascade::handle<Interface_InterfaceModel> &)) &IFSelect_SignCounter::AddList, "Adds a list of entities by adding each of the items", py::arg("list"), py::arg("model"));
cls_IFSelect_SignCounter.def("AddWithGraph", (void (IFSelect_SignCounter::*)(const opencascade::handle<TColStd_HSequenceOfTransient> &, const Interface_Graph &)) &IFSelect_SignCounter::AddWithGraph, "Adds a list of entities in the context given by the graph Default just call basic AddList Can be redefined to get a signature computed with the graph", py::arg("list"), py::arg("graph"));
cls_IFSelect_SignCounter.def("AddModel", (void (IFSelect_SignCounter::*)(const opencascade::handle<Interface_InterfaceModel> &)) &IFSelect_SignCounter::AddModel, "Adds all the entities contained in a Model", py::arg("model"));
cls_IFSelect_SignCounter.def("AddFromSelection", (void (IFSelect_SignCounter::*)(const opencascade::handle<IFSelect_Selection> &, const Interface_Graph &)) &IFSelect_SignCounter::AddFromSelection, "Adds the result determined by a Selection from a Graph Remark : does not impact at all data from SetSelection & Co", py::arg("sel"), py::arg("G"));
cls_IFSelect_SignCounter.def("SetSelection", (void (IFSelect_SignCounter::*)(const opencascade::handle<IFSelect_Selection> &)) &IFSelect_SignCounter::SetSelection, "Sets a Selection as input : this causes content to be cleared then the Selection to be ready to compute (but not immediatly)", py::arg("sel"));
cls_IFSelect_SignCounter.def("Selection", (opencascade::handle<IFSelect_Selection> (IFSelect_SignCounter::*)() const) &IFSelect_SignCounter::Selection, "Returns the selection, or a null Handle");
cls_IFSelect_SignCounter.def("SetSelMode", (void (IFSelect_SignCounter::*)(const Standard_Integer)) &IFSelect_SignCounter::SetSelMode, "Changes the mode of working with the selection : -1 just clears optimisation data and nothing else 0 clears it 1 inhibits it for computing (but no clearing) 2 sets it active for computing Default at creation is 0, after SetSelection (not null) is 2", py::arg("selmode"));
cls_IFSelect_SignCounter.def("SelMode", (Standard_Integer (IFSelect_SignCounter::*)() const) &IFSelect_SignCounter::SelMode, "Returns the mode of working with the selection");
cls_IFSelect_SignCounter.def("ComputeSelected", [](IFSelect_SignCounter &self, const Interface_Graph & a0) -> Standard_Boolean { return self.ComputeSelected(a0); });
cls_IFSelect_SignCounter.def("ComputeSelected", (Standard_Boolean (IFSelect_SignCounter::*)(const Interface_Graph &, const Standard_Boolean)) &IFSelect_SignCounter::ComputeSelected, "Computes from the selection result, if selection is active (mode 2). If selection is not defined (mode 0) or is inhibited (mode 1) does nothing. Returns True if computation is done (or optimised), False else This method is called by ComputeCounter from WorkSession", py::arg("G"), py::arg("forced"));
cls_IFSelect_SignCounter.def("Sign", (opencascade::handle<TCollection_HAsciiString> (IFSelect_SignCounter::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &) const) &IFSelect_SignCounter::Sign, "Determines and returns the value of the signature for an entity as an HAsciiString. This method works exactly as AddSign, which is optimized", py::arg("ent"), py::arg("model"));
cls_IFSelect_SignCounter.def("ComputedSign", (Standard_CString (IFSelect_SignCounter::*)(const opencascade::handle<Standard_Transient> &, const Interface_Graph &)) &IFSelect_SignCounter::ComputedSign, "Applies AddWithGraph on one entity, and returns the Signature Value which has been recorded To do this, Add is called with SignOnly Mode True during the call, the returned value is LastValue", py::arg("ent"), py::arg("G"));
cls_IFSelect_SignCounter.def_static("get_type_name_", (const char * (*)()) &IFSelect_SignCounter::get_type_name, "None");
cls_IFSelect_SignCounter.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_SignCounter::get_type_descriptor, "None");
cls_IFSelect_SignCounter.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_SignCounter::*)() const) &IFSelect_SignCounter::DynamicType, "None");

// Enums

}