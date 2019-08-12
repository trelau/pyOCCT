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
#include <XmlMDF_ADriver.hxx>
#include <Standard_Handle.hxx>
#include <Message_Messenger.hxx>
#include <TDF_Attribute.hxx>
#include <Standard_TypeDef.hxx>
#include <XmlObjMgt_Persistent.hxx>
#include <XmlObjMgt_RRelocationTable.hxx>
#include <XmlObjMgt_SRelocationTable.hxx>
#include <XmlMDataStd_CommentDriver.hxx>
#include <Standard_Type.hxx>

void bind_XmlMDataStd_CommentDriver(py::module &mod){

py::class_<XmlMDataStd_CommentDriver, opencascade::handle<XmlMDataStd_CommentDriver>, XmlMDF_ADriver> cls_XmlMDataStd_CommentDriver(mod, "XmlMDataStd_CommentDriver", "Attribute Driver.");

// Constructors
cls_XmlMDataStd_CommentDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Fields

// Methods
cls_XmlMDataStd_CommentDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XmlMDataStd_CommentDriver::*)() const) &XmlMDataStd_CommentDriver::NewEmpty, "None");
cls_XmlMDataStd_CommentDriver.def("Paste", (Standard_Boolean (XmlMDataStd_CommentDriver::*)(const XmlObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, XmlObjMgt_RRelocationTable &) const) &XmlMDataStd_CommentDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMDataStd_CommentDriver.def("Paste", (void (XmlMDataStd_CommentDriver::*)(const opencascade::handle<TDF_Attribute> &, XmlObjMgt_Persistent &, XmlObjMgt_SRelocationTable &) const) &XmlMDataStd_CommentDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMDataStd_CommentDriver.def_static("get_type_name_", (const char * (*)()) &XmlMDataStd_CommentDriver::get_type_name, "None");
cls_XmlMDataStd_CommentDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlMDataStd_CommentDriver::get_type_descriptor, "None");
cls_XmlMDataStd_CommentDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlMDataStd_CommentDriver::*)() const) &XmlMDataStd_CommentDriver::DynamicType, "None");

// Enums

}