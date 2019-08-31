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
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <XmlMDF_ADriverTable.hxx>
#include <Message_Messenger.hxx>
#include <XmlMDocStd_XLinkDriver.hxx>
#include <XmlMDocStd.hxx>
#include <XmlMDF_ADriver.hxx>
#include <TDF_Attribute.hxx>
#include <Standard_TypeDef.hxx>
#include <XmlObjMgt_Persistent.hxx>
#include <XmlObjMgt_RRelocationTable.hxx>
#include <XmlObjMgt_SRelocationTable.hxx>
#include <Standard_Type.hxx>

PYBIND11_MODULE(XmlMDocStd, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.XmlMDF");
py::module::import("OCCT.Message");
py::module::import("OCCT.TDF");
py::module::import("OCCT.XmlObjMgt");

// CLASS: XMLMDOCSTD
py::class_<XmlMDocStd> cls_XmlMDocStd(mod, "XmlMDocStd", "Driver for TDocStd_XLink");

// Methods
// cls_XmlMDocStd.def_static("operator new_", (void * (*)(size_t)) &XmlMDocStd::operator new, "None", py::arg("theSize"));
// cls_XmlMDocStd.def_static("operator delete_", (void (*)(void *)) &XmlMDocStd::operator delete, "None", py::arg("theAddress"));
// cls_XmlMDocStd.def_static("operator new[]_", (void * (*)(size_t)) &XmlMDocStd::operator new[], "None", py::arg("theSize"));
// cls_XmlMDocStd.def_static("operator delete[]_", (void (*)(void *)) &XmlMDocStd::operator delete[], "None", py::arg("theAddress"));
// cls_XmlMDocStd.def_static("operator new_", (void * (*)(size_t, void *)) &XmlMDocStd::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_XmlMDocStd.def_static("operator delete_", (void (*)(void *, void *)) &XmlMDocStd::operator delete, "None", py::arg(""), py::arg(""));
cls_XmlMDocStd.def_static("AddDrivers_", (void (*)(const opencascade::handle<XmlMDF_ADriverTable> &, const opencascade::handle<Message_Messenger> &)) &XmlMDocStd::AddDrivers, "Adds the attribute drivers to <aDriverTable>.", py::arg("aDriverTable"), py::arg("theMessageDriver"));

// CLASS: XMLMDOCSTD_XLINKDRIVER
py::class_<XmlMDocStd_XLinkDriver, opencascade::handle<XmlMDocStd_XLinkDriver>, XmlMDF_ADriver> cls_XmlMDocStd_XLinkDriver(mod, "XmlMDocStd_XLinkDriver", "Attribute Driver.");

// Constructors
cls_XmlMDocStd_XLinkDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Methods
cls_XmlMDocStd_XLinkDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XmlMDocStd_XLinkDriver::*)() const) &XmlMDocStd_XLinkDriver::NewEmpty, "None");
cls_XmlMDocStd_XLinkDriver.def("Paste", (Standard_Boolean (XmlMDocStd_XLinkDriver::*)(const XmlObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, XmlObjMgt_RRelocationTable &) const) &XmlMDocStd_XLinkDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMDocStd_XLinkDriver.def("Paste", (void (XmlMDocStd_XLinkDriver::*)(const opencascade::handle<TDF_Attribute> &, XmlObjMgt_Persistent &, XmlObjMgt_SRelocationTable &) const) &XmlMDocStd_XLinkDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMDocStd_XLinkDriver.def_static("get_type_name_", (const char * (*)()) &XmlMDocStd_XLinkDriver::get_type_name, "None");
cls_XmlMDocStd_XLinkDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlMDocStd_XLinkDriver::get_type_descriptor, "None");
cls_XmlMDocStd_XLinkDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlMDocStd_XLinkDriver::*)() const) &XmlMDocStd_XLinkDriver::DynamicType, "None");


}
