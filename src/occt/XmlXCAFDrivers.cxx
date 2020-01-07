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
#include <Standard_Handle.hxx>
#include <Standard_Transient.hxx>
#include <Standard_GUID.hxx>
#include <TDocStd_Application.hxx>
#include <XmlXCAFDrivers.hxx>
#include <XmlDrivers_DocumentRetrievalDriver.hxx>
#include <XmlMDF_ADriverTable.hxx>
#include <Message_Messenger.hxx>
#include <Standard_Std.hxx>
#include <XmlXCAFDrivers_DocumentRetrievalDriver.hxx>
#include <Standard_Type.hxx>
#include <XmlDrivers_DocumentStorageDriver.hxx>
#include <TCollection_ExtendedString.hxx>
#include <XmlXCAFDrivers_DocumentStorageDriver.hxx>

PYBIND11_MODULE(XmlXCAFDrivers, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.TDocStd");
py::module::import("OCCT.XmlDrivers");
py::module::import("OCCT.XmlMDF");
py::module::import("OCCT.Message");
py::module::import("OCCT.TCollection");

// CLASS: XMLXCAFDRIVERS
py::class_<XmlXCAFDrivers> cls_XmlXCAFDrivers(mod, "XmlXCAFDrivers", "None");

// Constructors
cls_XmlXCAFDrivers.def(py::init<>());

// Methods
cls_XmlXCAFDrivers.def_static("Factory_", (const opencascade::handle<Standard_Transient> & (*)(const Standard_GUID &)) &XmlXCAFDrivers::Factory, "Depending from the ID, returns a list of storage or retrieval attribute drivers. Used for plugin.", py::arg("aGUID"));
cls_XmlXCAFDrivers.def_static("DefineFormat_", (void (*)(const opencascade::handle<TDocStd_Application> &)) &XmlXCAFDrivers::DefineFormat, "Defines format 'XmlXCAF' and registers its read and write drivers in the specified application", py::arg("theApp"));

// CLASS: XMLXCAFDRIVERS_DOCUMENTRETRIEVALDRIVER
py::class_<XmlXCAFDrivers_DocumentRetrievalDriver, opencascade::handle<XmlXCAFDrivers_DocumentRetrievalDriver>, XmlDrivers_DocumentRetrievalDriver> cls_XmlXCAFDrivers_DocumentRetrievalDriver(mod, "XmlXCAFDrivers_DocumentRetrievalDriver", "retrieval driver of a XS document");

// Constructors
cls_XmlXCAFDrivers_DocumentRetrievalDriver.def(py::init<>());

// Methods
cls_XmlXCAFDrivers_DocumentRetrievalDriver.def("AttributeDrivers", (opencascade::handle<XmlMDF_ADriverTable> (XmlXCAFDrivers_DocumentRetrievalDriver::*)(const opencascade::handle<Message_Messenger> &)) &XmlXCAFDrivers_DocumentRetrievalDriver::AttributeDrivers, "None", py::arg("theMsgDriver"));
cls_XmlXCAFDrivers_DocumentRetrievalDriver.def_static("get_type_name_", (const char * (*)()) &XmlXCAFDrivers_DocumentRetrievalDriver::get_type_name, "None");
cls_XmlXCAFDrivers_DocumentRetrievalDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlXCAFDrivers_DocumentRetrievalDriver::get_type_descriptor, "None");
cls_XmlXCAFDrivers_DocumentRetrievalDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlXCAFDrivers_DocumentRetrievalDriver::*)() const) &XmlXCAFDrivers_DocumentRetrievalDriver::DynamicType, "None");

// CLASS: XMLXCAFDRIVERS_DOCUMENTSTORAGEDRIVER
py::class_<XmlXCAFDrivers_DocumentStorageDriver, opencascade::handle<XmlXCAFDrivers_DocumentStorageDriver>, XmlDrivers_DocumentStorageDriver> cls_XmlXCAFDrivers_DocumentStorageDriver(mod, "XmlXCAFDrivers_DocumentStorageDriver", "storage driver of a XS document");

// Constructors
cls_XmlXCAFDrivers_DocumentStorageDriver.def(py::init<const TCollection_ExtendedString &>(), py::arg("theCopyright"));

// Methods
cls_XmlXCAFDrivers_DocumentStorageDriver.def("AttributeDrivers", (opencascade::handle<XmlMDF_ADriverTable> (XmlXCAFDrivers_DocumentStorageDriver::*)(const opencascade::handle<Message_Messenger> &)) &XmlXCAFDrivers_DocumentStorageDriver::AttributeDrivers, "None", py::arg("theMsgDriver"));
cls_XmlXCAFDrivers_DocumentStorageDriver.def_static("get_type_name_", (const char * (*)()) &XmlXCAFDrivers_DocumentStorageDriver::get_type_name, "None");
cls_XmlXCAFDrivers_DocumentStorageDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlXCAFDrivers_DocumentStorageDriver::get_type_descriptor, "None");
cls_XmlXCAFDrivers_DocumentStorageDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlXCAFDrivers_DocumentStorageDriver::*)() const) &XmlXCAFDrivers_DocumentStorageDriver::DynamicType, "None");


}
