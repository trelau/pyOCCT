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
#include <Interface_InterfaceModel.hxx>
#include <Standard_TypeDef.hxx>
#include <Transfer_TransientProcess.hxx>
#include <Transfer_ResultFromTransient.hxx>
#include <TColStd_HSequenceOfTransient.hxx>
#include <Interface_CheckStatus.hxx>
#include <Interface_CheckIterator.hxx>
#include <Transfer_ResultFromModel.hxx>
#include <Standard_Type.hxx>
#include <TCollection_AsciiString.hxx>

void bind_Transfer_ResultFromModel(py::module &mod){

py::class_<Transfer_ResultFromModel, opencascade::handle<Transfer_ResultFromModel>, Standard_Transient> cls_Transfer_ResultFromModel(mod, "Transfer_ResultFromModel", "ResultFromModel is used to store a final result stored in a TransientProcess, respectfully to its structuration in scopes by using a set of ResultFromTransient Hence, it can be regarded as a passive equivalent of the stored data in the TransientProcess, while an Iterator gives a flat view of it.");

// Constructors
cls_Transfer_ResultFromModel.def(py::init<>());

// Fields

// Methods
cls_Transfer_ResultFromModel.def("SetModel", (void (Transfer_ResultFromModel::*)(const opencascade::handle<Interface_InterfaceModel> &)) &Transfer_ResultFromModel::SetModel, "Sets starting Model", py::arg("model"));
cls_Transfer_ResultFromModel.def("SetFileName", (void (Transfer_ResultFromModel::*)(const Standard_CString)) &Transfer_ResultFromModel::SetFileName, "Sets starting File Name", py::arg("filename"));
cls_Transfer_ResultFromModel.def("Model", (opencascade::handle<Interface_InterfaceModel> (Transfer_ResultFromModel::*)() const) &Transfer_ResultFromModel::Model, "Returns starting Model (null if not set)");
cls_Transfer_ResultFromModel.def("FileName", (Standard_CString (Transfer_ResultFromModel::*)() const) &Transfer_ResultFromModel::FileName, "Returns starting File Name (empty if not set)");
cls_Transfer_ResultFromModel.def("Fill", (Standard_Boolean (Transfer_ResultFromModel::*)(const opencascade::handle<Transfer_TransientProcess> &, const opencascade::handle<Standard_Transient> &)) &Transfer_ResultFromModel::Fill, "Fills from a TransientProcess, with the result attached to a starting entity. Considers its Model if it is set. This action produces a structured set of ResultFromTransient, considering scopes, starting by that of <ent>. If <ent> has no recorded result, it remains empty Returns True if a result is recorded, False else", py::arg("TP"), py::arg("ent"));
cls_Transfer_ResultFromModel.def("Strip", (void (Transfer_ResultFromModel::*)(const Standard_Integer)) &Transfer_ResultFromModel::Strip, "Clears some data attached to binders used by TransientProcess, which become useless once the transfer has been done, by calling Strip on its ResultFromTransient", py::arg("mode"));
cls_Transfer_ResultFromModel.def("FillBack", (void (Transfer_ResultFromModel::*)(const opencascade::handle<Transfer_TransientProcess> &) const) &Transfer_ResultFromModel::FillBack, "Fills back a TransientProcess from the structured set of binders. Also sets the Model.", py::arg("TP"));
cls_Transfer_ResultFromModel.def("HasResult", (Standard_Boolean (Transfer_ResultFromModel::*)() const) &Transfer_ResultFromModel::HasResult, "Returns True if a Result is recorded");
cls_Transfer_ResultFromModel.def("MainResult", (opencascade::handle<Transfer_ResultFromTransient> (Transfer_ResultFromModel::*)() const) &Transfer_ResultFromModel::MainResult, "Returns the main recorded ResultFromTransient, or a null");
cls_Transfer_ResultFromModel.def("SetMainResult", (void (Transfer_ResultFromModel::*)(const opencascade::handle<Transfer_ResultFromTransient> &)) &Transfer_ResultFromModel::SetMainResult, "Sets a new value for the main recorded ResultFromTransient", py::arg("amain"));
cls_Transfer_ResultFromModel.def("MainLabel", (Standard_CString (Transfer_ResultFromModel::*)() const) &Transfer_ResultFromModel::MainLabel, "Returns the label in starting model attached to main entity (updated by Fill or SetMainResult, if Model is known)");
cls_Transfer_ResultFromModel.def("MainNumber", (Standard_Integer (Transfer_ResultFromModel::*)() const) &Transfer_ResultFromModel::MainNumber, "Returns the label in starting model attached to main entity");
cls_Transfer_ResultFromModel.def("ResultFromKey", (opencascade::handle<Transfer_ResultFromTransient> (Transfer_ResultFromModel::*)(const opencascade::handle<Standard_Transient> &) const) &Transfer_ResultFromModel::ResultFromKey, "Searches for a key (starting entity) and returns its result Returns a null handle if not found", py::arg("start"));
cls_Transfer_ResultFromModel.def("Results", (opencascade::handle<TColStd_HSequenceOfTransient> (Transfer_ResultFromModel::*)(const Standard_Integer) const) &Transfer_ResultFromModel::Results, "Internal method which returns the list of ResultFromTransient, according level (2:complete; 1:sub-level 1; 0:main only)", py::arg("level"));
cls_Transfer_ResultFromModel.def("TransferredList", [](Transfer_ResultFromModel &self) -> opencascade::handle<TColStd_HSequenceOfTransient> { return self.TransferredList(); });
cls_Transfer_ResultFromModel.def("TransferredList", (opencascade::handle<TColStd_HSequenceOfTransient> (Transfer_ResultFromModel::*)(const Standard_Integer) const) &Transfer_ResultFromModel::TransferredList, "Returns the list of recorded starting entities, ending by the root. Entities with check but no transfer result are ignored <level> = 2 (D), considers the complete list <level> = 1 considers the main result plus immediate subs <level> = 0 just the main result", py::arg("level"));
cls_Transfer_ResultFromModel.def("CheckedList", (opencascade::handle<TColStd_HSequenceOfTransient> (Transfer_ResultFromModel::*)(const Interface_CheckStatus, const Standard_Boolean) const) &Transfer_ResultFromModel::CheckedList, "Returns the list of starting entities to which a check status is attached. <check> = -2 , all entities whatever the check (see result) <check> = -1 , entities with no fail (warning allowed) <check> = 0 , entities with no check at all <check> = 1 , entities with warning but no fail <check> = 2 , entities with fail <result> : if True, only entities with an attached result Remark : result True and check=0 will give an empty list", py::arg("check"), py::arg("result"));
cls_Transfer_ResultFromModel.def("CheckList", [](Transfer_ResultFromModel &self, const Standard_Boolean a0) -> Interface_CheckIterator { return self.CheckList(a0); });
cls_Transfer_ResultFromModel.def("CheckList", (Interface_CheckIterator (Transfer_ResultFromModel::*)(const Standard_Boolean, const Standard_Integer) const) &Transfer_ResultFromModel::CheckList, "Returns the check-list of this set of results <erronly> true : only fails are considered <level> = 0 : considers only main binder <level> = 1 : considers main binder plus immediate subs <level> = 2 (D) : considers all checks", py::arg("erronly"), py::arg("level"));
cls_Transfer_ResultFromModel.def("CheckStatus", (Interface_CheckStatus (Transfer_ResultFromModel::*)() const) &Transfer_ResultFromModel::CheckStatus, "Returns the check status with corresponds to the content of this ResultFromModel; considers all levels of transfer (worst status). Returns CheckAny if not yet computed Reads it from recorded status if already computed, else recomputes one");
cls_Transfer_ResultFromModel.def("ComputeCheckStatus", (Interface_CheckStatus (Transfer_ResultFromModel::*)(const Standard_Boolean)) &Transfer_ResultFromModel::ComputeCheckStatus, "Computes and records check status (see CheckStatus) Does not computes it if already done and <enforce> False", py::arg("enforce"));
cls_Transfer_ResultFromModel.def_static("get_type_name_", (const char * (*)()) &Transfer_ResultFromModel::get_type_name, "None");
cls_Transfer_ResultFromModel.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Transfer_ResultFromModel::get_type_descriptor, "None");
cls_Transfer_ResultFromModel.def("DynamicType", (const opencascade::handle<Standard_Type> & (Transfer_ResultFromModel::*)() const) &Transfer_ResultFromModel::DynamicType, "None");

// Enums

}