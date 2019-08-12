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
#include <XmlLDrivers_DocumentRetrievalDriver.hxx>
#include <Standard_Handle.hxx>
#include <XmlMDF_ADriverTable.hxx>
#include <Message_Messenger.hxx>
#include <XmlMDF_ADriver.hxx>
#include <XmlObjMgt_Element.hxx>
#include <Standard_TypeDef.hxx>
#include <XmlDrivers_DocumentRetrievalDriver.hxx>
#include <Standard_Type.hxx>

void bind_XmlDrivers_DocumentRetrievalDriver(py::module &mod){

py::class_<XmlDrivers_DocumentRetrievalDriver, opencascade::handle<XmlDrivers_DocumentRetrievalDriver>, XmlLDrivers_DocumentRetrievalDriver> cls_XmlDrivers_DocumentRetrievalDriver(mod, "XmlDrivers_DocumentRetrievalDriver", "None");

// Constructors
cls_XmlDrivers_DocumentRetrievalDriver.def(py::init<>());

// Fields

// Methods
cls_XmlDrivers_DocumentRetrievalDriver.def("AttributeDrivers", (opencascade::handle<XmlMDF_ADriverTable> (XmlDrivers_DocumentRetrievalDriver::*)(const opencascade::handle<Message_Messenger> &)) &XmlDrivers_DocumentRetrievalDriver::AttributeDrivers, "None", py::arg("theMsgDriver"));
cls_XmlDrivers_DocumentRetrievalDriver.def("ReadShapeSection", (opencascade::handle<XmlMDF_ADriver> (XmlDrivers_DocumentRetrievalDriver::*)(const XmlObjMgt_Element &, const opencascade::handle<Message_Messenger> &)) &XmlDrivers_DocumentRetrievalDriver::ReadShapeSection, "None", py::arg("thePDoc"), py::arg("theMsgDriver"));
cls_XmlDrivers_DocumentRetrievalDriver.def("ShapeSetCleaning", (void (XmlDrivers_DocumentRetrievalDriver::*)(const opencascade::handle<XmlMDF_ADriver> &)) &XmlDrivers_DocumentRetrievalDriver::ShapeSetCleaning, "None", py::arg("theDriver"));
cls_XmlDrivers_DocumentRetrievalDriver.def("PropagateDocumentVersion", (void (XmlDrivers_DocumentRetrievalDriver::*)(const Standard_Integer)) &XmlDrivers_DocumentRetrievalDriver::PropagateDocumentVersion, "None", py::arg("theDocVersion"));
cls_XmlDrivers_DocumentRetrievalDriver.def_static("get_type_name_", (const char * (*)()) &XmlDrivers_DocumentRetrievalDriver::get_type_name, "None");
cls_XmlDrivers_DocumentRetrievalDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlDrivers_DocumentRetrievalDriver::get_type_descriptor, "None");
cls_XmlDrivers_DocumentRetrievalDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlDrivers_DocumentRetrievalDriver::*)() const) &XmlDrivers_DocumentRetrievalDriver::DynamicType, "None");

// Enums

}