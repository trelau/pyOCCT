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
#include <Standard_Type.hxx>
#include <Transfer_StatusResult.hxx>
#include <Transfer_StatusExec.hxx>
#include <Interface_Check.hxx>

void bind_Transfer_Binder(py::module &mod){

py::class_<Transfer_Binder, opencascade::handle<Transfer_Binder>, Standard_Transient> cls_Transfer_Binder(mod, "Transfer_Binder", "A Binder is an auxiliary object to Map the Result of the Transfer of a given Object : it records the Result of the Unitary Transfer (Resulting Object), status of progress and error (if any) of the Process");

// Fields

// Methods
cls_Transfer_Binder.def("Merge", (void (Transfer_Binder::*)(const opencascade::handle<Transfer_Binder> &)) &Transfer_Binder::Merge, "Merges basic data (Check, ExecStatus) from another Binder but keeps its result. Used when a binder is replaced by another one, this allows to keep messages", py::arg("other"));
cls_Transfer_Binder.def("IsMultiple", (Standard_Boolean (Transfer_Binder::*)() const) &Transfer_Binder::IsMultiple, "Returns True if a Binder has several results, either by itself or because it has next results Can be defined by sub-classes.");
cls_Transfer_Binder.def("ResultType", (opencascade::handle<Standard_Type> (Transfer_Binder::*)() const) &Transfer_Binder::ResultType, "Returns the Type which characterizes the Result (if known)");
cls_Transfer_Binder.def("ResultTypeName", (Standard_CString (Transfer_Binder::*)() const) &Transfer_Binder::ResultTypeName, "Returns the Name of the Type which characterizes the Result Can be returned even if ResultType itself is unknown");
cls_Transfer_Binder.def("AddResult", (void (Transfer_Binder::*)(const opencascade::handle<Transfer_Binder> &)) &Transfer_Binder::AddResult, "Adds a next result (at the end of the list) Remark : this information is not processed by Merge", py::arg("next"));
cls_Transfer_Binder.def("NextResult", (opencascade::handle<Transfer_Binder> (Transfer_Binder::*)() const) &Transfer_Binder::NextResult, "Returns the next result, Null if none");
cls_Transfer_Binder.def("HasResult", (Standard_Boolean (Transfer_Binder::*)() const) &Transfer_Binder::HasResult, "Returns True if a Result is available (StatusResult = Defined) A Unique Result will be gotten by Result (which must be defined in each sub-class according to result type) For a Multiple Result, see class MultipleBinder For other case, specific access has to be forecast");
cls_Transfer_Binder.def("SetAlreadyUsed", (void (Transfer_Binder::*)()) &Transfer_Binder::SetAlreadyUsed, "Declares that result is now used by another one, it means that it cannot be modified (by Rebind)");
cls_Transfer_Binder.def("Status", (Transfer_StatusResult (Transfer_Binder::*)() const) &Transfer_Binder::Status, "Returns status, which can be Initial (not yet done), Made (a result is recorded, not yet shared), Used (it is shared and cannot be modified)");
cls_Transfer_Binder.def("StatusExec", (Transfer_StatusExec (Transfer_Binder::*)() const) &Transfer_Binder::StatusExec, "Returns execution status");
cls_Transfer_Binder.def("SetStatusExec", (void (Transfer_Binder::*)(const Transfer_StatusExec)) &Transfer_Binder::SetStatusExec, "Modifies execution status; called by TransferProcess only (for StatusError, rather use SetError, below)", py::arg("stat"));
cls_Transfer_Binder.def("AddFail", [](Transfer_Binder &self, const Standard_CString a0) -> void { return self.AddFail(a0); });
cls_Transfer_Binder.def("AddFail", (void (Transfer_Binder::*)(const Standard_CString, const Standard_CString)) &Transfer_Binder::AddFail, "Used to declare an individual transfer as beeing erroneous (Status is set to Void, StatusExec is set to Error, <errmess> is added to Check's list of Fails) It is possible to record several messages of error", py::arg("mess"), py::arg("orig"));
cls_Transfer_Binder.def("AddWarning", [](Transfer_Binder &self, const Standard_CString a0) -> void { return self.AddWarning(a0); });
cls_Transfer_Binder.def("AddWarning", (void (Transfer_Binder::*)(const Standard_CString, const Standard_CString)) &Transfer_Binder::AddWarning, "Used to attach a Warning Message to an individual Transfer It has no effect on the Status", py::arg("mess"), py::arg("orig"));
cls_Transfer_Binder.def("Check", (const opencascade::handle<Interface_Check> (Transfer_Binder::*)() const) &Transfer_Binder::Check, "Returns Check which stores Fail messages Note that no Entity is associated in this Check");
cls_Transfer_Binder.def("CCheck", (opencascade::handle<Interface_Check> (Transfer_Binder::*)()) &Transfer_Binder::CCheck, "Returns Check which stores Fail messages, in order to modify it (adding messages, or replacing it)");
cls_Transfer_Binder.def_static("get_type_name_", (const char * (*)()) &Transfer_Binder::get_type_name, "None");
cls_Transfer_Binder.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Transfer_Binder::get_type_descriptor, "None");
cls_Transfer_Binder.def("DynamicType", (const opencascade::handle<Standard_Type> & (Transfer_Binder::*)() const) &Transfer_Binder::DynamicType, "None");

// Enums

}