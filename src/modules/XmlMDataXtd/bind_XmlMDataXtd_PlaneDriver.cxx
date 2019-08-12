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
#include <XmlMDataXtd_PlaneDriver.hxx>
#include <Standard_Type.hxx>

void bind_XmlMDataXtd_PlaneDriver(py::module &mod){

py::class_<XmlMDataXtd_PlaneDriver, opencascade::handle<XmlMDataXtd_PlaneDriver>, XmlMDF_ADriver> cls_XmlMDataXtd_PlaneDriver(mod, "XmlMDataXtd_PlaneDriver", "Attribute Driver.");

// Constructors
cls_XmlMDataXtd_PlaneDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Fields

// Methods
cls_XmlMDataXtd_PlaneDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XmlMDataXtd_PlaneDriver::*)() const) &XmlMDataXtd_PlaneDriver::NewEmpty, "None");
cls_XmlMDataXtd_PlaneDriver.def("Paste", (Standard_Boolean (XmlMDataXtd_PlaneDriver::*)(const XmlObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, XmlObjMgt_RRelocationTable &) const) &XmlMDataXtd_PlaneDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMDataXtd_PlaneDriver.def("Paste", (void (XmlMDataXtd_PlaneDriver::*)(const opencascade::handle<TDF_Attribute> &, XmlObjMgt_Persistent &, XmlObjMgt_SRelocationTable &) const) &XmlMDataXtd_PlaneDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMDataXtd_PlaneDriver.def_static("get_type_name_", (const char * (*)()) &XmlMDataXtd_PlaneDriver::get_type_name, "None");
cls_XmlMDataXtd_PlaneDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlMDataXtd_PlaneDriver::get_type_descriptor, "None");
cls_XmlMDataXtd_PlaneDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlMDataXtd_PlaneDriver::*)() const) &XmlMDataXtd_PlaneDriver::DynamicType, "None");

// Enums

}