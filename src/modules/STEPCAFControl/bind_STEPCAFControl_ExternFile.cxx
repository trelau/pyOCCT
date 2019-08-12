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
#include <XSControl_WorkSession.hxx>
#include <IFSelect_ReturnStatus.hxx>
#include <Standard_TypeDef.hxx>
#include <TCollection_HAsciiString.hxx>
#include <TDF_Label.hxx>
#include <STEPCAFControl_ExternFile.hxx>
#include <Standard_Type.hxx>

void bind_STEPCAFControl_ExternFile(py::module &mod){

py::class_<STEPCAFControl_ExternFile, opencascade::handle<STEPCAFControl_ExternFile>, Standard_Transient> cls_STEPCAFControl_ExternFile(mod, "STEPCAFControl_ExternFile", "Auxiliary class serving as container for data resulting from translation of external file");

// Constructors
cls_STEPCAFControl_ExternFile.def(py::init<>());

// Fields

// Methods
cls_STEPCAFControl_ExternFile.def("SetWS", (void (STEPCAFControl_ExternFile::*)(const opencascade::handle<XSControl_WorkSession> &)) &STEPCAFControl_ExternFile::SetWS, "None", py::arg("WS"));
cls_STEPCAFControl_ExternFile.def("GetWS", (opencascade::handle<XSControl_WorkSession> (STEPCAFControl_ExternFile::*)() const) &STEPCAFControl_ExternFile::GetWS, "None");
cls_STEPCAFControl_ExternFile.def("SetLoadStatus", (void (STEPCAFControl_ExternFile::*)(const IFSelect_ReturnStatus)) &STEPCAFControl_ExternFile::SetLoadStatus, "None", py::arg("stat"));
cls_STEPCAFControl_ExternFile.def("GetLoadStatus", (IFSelect_ReturnStatus (STEPCAFControl_ExternFile::*)() const) &STEPCAFControl_ExternFile::GetLoadStatus, "None");
cls_STEPCAFControl_ExternFile.def("SetTransferStatus", (void (STEPCAFControl_ExternFile::*)(const Standard_Boolean)) &STEPCAFControl_ExternFile::SetTransferStatus, "None", py::arg("isok"));
cls_STEPCAFControl_ExternFile.def("GetTransferStatus", (Standard_Boolean (STEPCAFControl_ExternFile::*)() const) &STEPCAFControl_ExternFile::GetTransferStatus, "None");
cls_STEPCAFControl_ExternFile.def("SetWriteStatus", (void (STEPCAFControl_ExternFile::*)(const IFSelect_ReturnStatus)) &STEPCAFControl_ExternFile::SetWriteStatus, "None", py::arg("stat"));
cls_STEPCAFControl_ExternFile.def("GetWriteStatus", (IFSelect_ReturnStatus (STEPCAFControl_ExternFile::*)() const) &STEPCAFControl_ExternFile::GetWriteStatus, "None");
cls_STEPCAFControl_ExternFile.def("SetName", (void (STEPCAFControl_ExternFile::*)(const opencascade::handle<TCollection_HAsciiString> &)) &STEPCAFControl_ExternFile::SetName, "None", py::arg("name"));
cls_STEPCAFControl_ExternFile.def("GetName", (opencascade::handle<TCollection_HAsciiString> (STEPCAFControl_ExternFile::*)() const) &STEPCAFControl_ExternFile::GetName, "None");
cls_STEPCAFControl_ExternFile.def("SetLabel", (void (STEPCAFControl_ExternFile::*)(const TDF_Label &)) &STEPCAFControl_ExternFile::SetLabel, "None", py::arg("L"));
cls_STEPCAFControl_ExternFile.def("GetLabel", (TDF_Label (STEPCAFControl_ExternFile::*)() const) &STEPCAFControl_ExternFile::GetLabel, "None");
cls_STEPCAFControl_ExternFile.def_static("get_type_name_", (const char * (*)()) &STEPCAFControl_ExternFile::get_type_name, "None");
cls_STEPCAFControl_ExternFile.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &STEPCAFControl_ExternFile::get_type_descriptor, "None");
cls_STEPCAFControl_ExternFile.def("DynamicType", (const opencascade::handle<Standard_Type> & (STEPCAFControl_ExternFile::*)() const) &STEPCAFControl_ExternFile::DynamicType, "None");

// Enums

}