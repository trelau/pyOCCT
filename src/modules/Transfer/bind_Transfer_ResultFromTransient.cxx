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
#include <Transfer_Binder.hxx>
#include <Standard_TypeDef.hxx>
#include <Interface_Check.hxx>
#include <Interface_CheckStatus.hxx>
#include <Transfer_ResultFromTransient.hxx>
#include <TColStd_IndexedMapOfTransient.hxx>
#include <Transfer_TransientProcess.hxx>
#include <Standard_Type.hxx>
#include <TColStd_HSequenceOfTransient.hxx>

void bind_Transfer_ResultFromTransient(py::module &mod){

py::class_<Transfer_ResultFromTransient, opencascade::handle<Transfer_ResultFromTransient>, Standard_Transient> cls_Transfer_ResultFromTransient(mod, "Transfer_ResultFromTransient", "This class, in conjunction with ResultFromModel, allows to record the result of a transfer initially stored in a TransientProcess.");

// Constructors
cls_Transfer_ResultFromTransient.def(py::init<>());

// Fields

// Methods
cls_Transfer_ResultFromTransient.def("SetStart", (void (Transfer_ResultFromTransient::*)(const opencascade::handle<Standard_Transient> &)) &Transfer_ResultFromTransient::SetStart, "Sets starting entity", py::arg("start"));
cls_Transfer_ResultFromTransient.def("SetBinder", (void (Transfer_ResultFromTransient::*)(const opencascade::handle<Transfer_Binder> &)) &Transfer_ResultFromTransient::SetBinder, "Sets Binder (for result plus individual check)", py::arg("binder"));
cls_Transfer_ResultFromTransient.def("Start", (opencascade::handle<Standard_Transient> (Transfer_ResultFromTransient::*)() const) &Transfer_ResultFromTransient::Start, "Returns the starting entity");
cls_Transfer_ResultFromTransient.def("Binder", (opencascade::handle<Transfer_Binder> (Transfer_ResultFromTransient::*)() const) &Transfer_ResultFromTransient::Binder, "Returns the binder");
cls_Transfer_ResultFromTransient.def("HasResult", (Standard_Boolean (Transfer_ResultFromTransient::*)() const) &Transfer_ResultFromTransient::HasResult, "Returns True if a result is recorded");
cls_Transfer_ResultFromTransient.def("Check", (const opencascade::handle<Interface_Check> (Transfer_ResultFromTransient::*)() const) &Transfer_ResultFromTransient::Check, "Returns the check (or an empty one if no binder)");
cls_Transfer_ResultFromTransient.def("CheckStatus", (Interface_CheckStatus (Transfer_ResultFromTransient::*)() const) &Transfer_ResultFromTransient::CheckStatus, "Returns the check status");
cls_Transfer_ResultFromTransient.def("ClearSubs", (void (Transfer_ResultFromTransient::*)()) &Transfer_ResultFromTransient::ClearSubs, "Clears the list of (immediate) sub-results");
cls_Transfer_ResultFromTransient.def("AddSubResult", (void (Transfer_ResultFromTransient::*)(const opencascade::handle<Transfer_ResultFromTransient> &)) &Transfer_ResultFromTransient::AddSubResult, "Adds a sub-result", py::arg("sub"));
cls_Transfer_ResultFromTransient.def("NbSubResults", (Standard_Integer (Transfer_ResultFromTransient::*)() const) &Transfer_ResultFromTransient::NbSubResults, "Returns the count of recorded sub-results");
cls_Transfer_ResultFromTransient.def("SubResult", (opencascade::handle<Transfer_ResultFromTransient> (Transfer_ResultFromTransient::*)(const Standard_Integer) const) &Transfer_ResultFromTransient::SubResult, "Returns a sub-result, given its rank", py::arg("num"));
cls_Transfer_ResultFromTransient.def("ResultFromKey", (opencascade::handle<Transfer_ResultFromTransient> (Transfer_ResultFromTransient::*)(const opencascade::handle<Standard_Transient> &) const) &Transfer_ResultFromTransient::ResultFromKey, "Returns the ResultFromTransient attached to a given starting entity (the key). Returns a null handle if not found", py::arg("key"));
cls_Transfer_ResultFromTransient.def("FillMap", (void (Transfer_ResultFromTransient::*)(TColStd_IndexedMapOfTransient &) const) &Transfer_ResultFromTransient::FillMap, "This method is used by ResultFromModel to collate the list of ResultFromTransient, avoiding duplications with a map Remark : <me> is already in the map and has not to be bound", py::arg("map"));
cls_Transfer_ResultFromTransient.def("Fill", (void (Transfer_ResultFromTransient::*)(const opencascade::handle<Transfer_TransientProcess> &)) &Transfer_ResultFromTransient::Fill, "Fills from a TransientProcess, with the starting entity which must have been set before. It works with scopes, calls Fill on each of its sub-results", py::arg("TP"));
cls_Transfer_ResultFromTransient.def("Strip", (void (Transfer_ResultFromTransient::*)()) &Transfer_ResultFromTransient::Strip, "Clears some data attached to binders used by TransientProcess, which become useless once the transfer has been done : the list of sub-scoped binders, which is now recorded as sub-results");
cls_Transfer_ResultFromTransient.def("FillBack", (void (Transfer_ResultFromTransient::*)(const opencascade::handle<Transfer_TransientProcess> &) const) &Transfer_ResultFromTransient::FillBack, "Fills back a TransientProcess with definition of a ResultFromTransient, respectfully to its structuration in scopes", py::arg("TP"));
cls_Transfer_ResultFromTransient.def_static("get_type_name_", (const char * (*)()) &Transfer_ResultFromTransient::get_type_name, "None");
cls_Transfer_ResultFromTransient.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Transfer_ResultFromTransient::get_type_descriptor, "None");
cls_Transfer_ResultFromTransient.def("DynamicType", (const opencascade::handle<Standard_Type> & (Transfer_ResultFromTransient::*)() const) &Transfer_ResultFromTransient::DynamicType, "None");

// Enums

}