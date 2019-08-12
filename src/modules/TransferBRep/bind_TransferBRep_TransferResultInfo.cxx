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
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <TransferBRep_TransferResultInfo.hxx>
#include <Standard_Type.hxx>

void bind_TransferBRep_TransferResultInfo(py::module &mod){

py::class_<TransferBRep_TransferResultInfo, opencascade::handle<TransferBRep_TransferResultInfo>, Standard_Transient> cls_TransferBRep_TransferResultInfo(mod, "TransferBRep_TransferResultInfo", "Data structure for storing information on transfer result. At the moment it dispatches information for the following types: - result, - result + warning(s), - result + fail(s), - result + warning(s) + fail(s) - no result, - no result + warning(s), - no result + fail(s), - no result + warning(s) + fail(s),");

// Constructors
cls_TransferBRep_TransferResultInfo.def(py::init<>());

// Fields

// Methods
cls_TransferBRep_TransferResultInfo.def("Clear", (void (TransferBRep_TransferResultInfo::*)()) &TransferBRep_TransferResultInfo::Clear, "Resets all the fields.");
cls_TransferBRep_TransferResultInfo.def("Result", (Standard_Integer & (TransferBRep_TransferResultInfo::*)()) &TransferBRep_TransferResultInfo::Result, "None");
cls_TransferBRep_TransferResultInfo.def("ResultWarning", (Standard_Integer & (TransferBRep_TransferResultInfo::*)()) &TransferBRep_TransferResultInfo::ResultWarning, "None");
cls_TransferBRep_TransferResultInfo.def("ResultFail", (Standard_Integer & (TransferBRep_TransferResultInfo::*)()) &TransferBRep_TransferResultInfo::ResultFail, "None");
cls_TransferBRep_TransferResultInfo.def("ResultWarningFail", (Standard_Integer & (TransferBRep_TransferResultInfo::*)()) &TransferBRep_TransferResultInfo::ResultWarningFail, "None");
cls_TransferBRep_TransferResultInfo.def("NoResult", (Standard_Integer & (TransferBRep_TransferResultInfo::*)()) &TransferBRep_TransferResultInfo::NoResult, "None");
cls_TransferBRep_TransferResultInfo.def("NoResultWarning", (Standard_Integer & (TransferBRep_TransferResultInfo::*)()) &TransferBRep_TransferResultInfo::NoResultWarning, "None");
cls_TransferBRep_TransferResultInfo.def("NoResultFail", (Standard_Integer & (TransferBRep_TransferResultInfo::*)()) &TransferBRep_TransferResultInfo::NoResultFail, "None");
cls_TransferBRep_TransferResultInfo.def("NoResultWarningFail", (Standard_Integer & (TransferBRep_TransferResultInfo::*)()) &TransferBRep_TransferResultInfo::NoResultWarningFail, "None");
cls_TransferBRep_TransferResultInfo.def_static("get_type_name_", (const char * (*)()) &TransferBRep_TransferResultInfo::get_type_name, "None");
cls_TransferBRep_TransferResultInfo.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TransferBRep_TransferResultInfo::get_type_descriptor, "None");
cls_TransferBRep_TransferResultInfo.def("DynamicType", (const opencascade::handle<Standard_Type> & (TransferBRep_TransferResultInfo::*)() const) &TransferBRep_TransferResultInfo::DynamicType, "None");

// Enums

}