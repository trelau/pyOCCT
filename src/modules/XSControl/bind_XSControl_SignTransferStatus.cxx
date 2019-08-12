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
#include <IFSelect_Signature.hxx>
#include <Standard_Handle.hxx>
#include <XSControl_TransferReader.hxx>
#include <Transfer_TransientProcess.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Transient.hxx>
#include <Interface_InterfaceModel.hxx>
#include <XSControl_SignTransferStatus.hxx>
#include <Standard_Type.hxx>

void bind_XSControl_SignTransferStatus(py::module &mod){

py::class_<XSControl_SignTransferStatus, opencascade::handle<XSControl_SignTransferStatus>, IFSelect_Signature> cls_XSControl_SignTransferStatus(mod, "XSControl_SignTransferStatus", "This Signatures gives the Transfer Status of an entity, as recorded in a TransferProcess. It can be : - Void : not recorded, or recorded as void with no message (attributes are not taken into account) - Warning : no result, warning message(s), no fail - Fail : no result, fail messages (with or without warning) - Result.. : result, no message (neither warning nor fail) Result.. i.e. Result:TypeName of the result - Result../Warning : result, with warning but no fail - Result../Fail : result, with fail (.e. bad result) - Fail on run : no result yet recorded, no message, but an exception occurred while recording the result (this should not appear and indicates a programming error)");

// Constructors
cls_XSControl_SignTransferStatus.def(py::init<>());
cls_XSControl_SignTransferStatus.def(py::init<const opencascade::handle<XSControl_TransferReader> &>(), py::arg("TR"));

// Fields

// Methods
cls_XSControl_SignTransferStatus.def("SetReader", (void (XSControl_SignTransferStatus::*)(const opencascade::handle<XSControl_TransferReader> &)) &XSControl_SignTransferStatus::SetReader, "Sets a TransferReader to work", py::arg("TR"));
cls_XSControl_SignTransferStatus.def("SetMap", (void (XSControl_SignTransferStatus::*)(const opencascade::handle<Transfer_TransientProcess> &)) &XSControl_SignTransferStatus::SetMap, "Sets a precise map to sign entities This definition oversedes the creation with a TransferReader", py::arg("TP"));
cls_XSControl_SignTransferStatus.def("Map", (opencascade::handle<Transfer_TransientProcess> (XSControl_SignTransferStatus::*)() const) &XSControl_SignTransferStatus::Map, "Returns the TransientProcess used as precised one Returns a Null Handle for a creation from a TransferReader without any further setting");
cls_XSControl_SignTransferStatus.def("Reader", (opencascade::handle<XSControl_TransferReader> (XSControl_SignTransferStatus::*)() const) &XSControl_SignTransferStatus::Reader, "Returns the Reader (if created with a Reader) Returns a Null Handle if not created with a Reader");
cls_XSControl_SignTransferStatus.def("Value", (Standard_CString (XSControl_SignTransferStatus::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &) const) &XSControl_SignTransferStatus::Value, "Returns the Signature for a Transient object, as its transfer status", py::arg("ent"), py::arg("model"));
cls_XSControl_SignTransferStatus.def_static("get_type_name_", (const char * (*)()) &XSControl_SignTransferStatus::get_type_name, "None");
cls_XSControl_SignTransferStatus.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XSControl_SignTransferStatus::get_type_descriptor, "None");
cls_XSControl_SignTransferStatus.def("DynamicType", (const opencascade::handle<Standard_Type> & (XSControl_SignTransferStatus::*)() const) &XSControl_SignTransferStatus::DynamicType, "None");

// Enums

}