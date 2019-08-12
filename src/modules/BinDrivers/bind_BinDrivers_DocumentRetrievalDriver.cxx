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
#include <BinLDrivers_DocumentRetrievalDriver.hxx>
#include <Standard_Handle.hxx>
#include <BinMDF_ADriverTable.hxx>
#include <Message_Messenger.hxx>
#include <BinLDrivers_DocumentSection.hxx>
#include <Standard_IStream.hxx>
#include <Standard_TypeDef.hxx>
#include <Storage_Position.hxx>
#include <BinDrivers_DocumentRetrievalDriver.hxx>
#include <Standard_Type.hxx>

void bind_BinDrivers_DocumentRetrievalDriver(py::module &mod){

py::class_<BinDrivers_DocumentRetrievalDriver, opencascade::handle<BinDrivers_DocumentRetrievalDriver>, BinLDrivers_DocumentRetrievalDriver> cls_BinDrivers_DocumentRetrievalDriver(mod, "BinDrivers_DocumentRetrievalDriver", "None");

// Constructors
cls_BinDrivers_DocumentRetrievalDriver.def(py::init<>());

// Fields

// Methods
cls_BinDrivers_DocumentRetrievalDriver.def("AttributeDrivers", (opencascade::handle<BinMDF_ADriverTable> (BinDrivers_DocumentRetrievalDriver::*)(const opencascade::handle<Message_Messenger> &)) &BinDrivers_DocumentRetrievalDriver::AttributeDrivers, "None", py::arg("theMsgDriver"));
cls_BinDrivers_DocumentRetrievalDriver.def("ReadShapeSection", [](BinDrivers_DocumentRetrievalDriver &self, BinLDrivers_DocumentSection & a0, Standard_IStream & a1) -> void { return self.ReadShapeSection(a0, a1); });
cls_BinDrivers_DocumentRetrievalDriver.def("ReadShapeSection", (void (BinDrivers_DocumentRetrievalDriver::*)(BinLDrivers_DocumentSection &, Standard_IStream &, const Standard_Boolean)) &BinDrivers_DocumentRetrievalDriver::ReadShapeSection, "None", py::arg("theSection"), py::arg("theIS"), py::arg("isMess"));
cls_BinDrivers_DocumentRetrievalDriver.def("CheckShapeSection", (void (BinDrivers_DocumentRetrievalDriver::*)(const Storage_Position &, Standard_IStream &)) &BinDrivers_DocumentRetrievalDriver::CheckShapeSection, "None", py::arg("thePos"), py::arg("theIS"));
cls_BinDrivers_DocumentRetrievalDriver.def("Clear", (void (BinDrivers_DocumentRetrievalDriver::*)()) &BinDrivers_DocumentRetrievalDriver::Clear, "Clears the NamedShape driver");
cls_BinDrivers_DocumentRetrievalDriver.def("PropagateDocumentVersion", (void (BinDrivers_DocumentRetrievalDriver::*)(const Standard_Integer)) &BinDrivers_DocumentRetrievalDriver::PropagateDocumentVersion, "None", py::arg("theVersion"));
cls_BinDrivers_DocumentRetrievalDriver.def_static("get_type_name_", (const char * (*)()) &BinDrivers_DocumentRetrievalDriver::get_type_name, "None");
cls_BinDrivers_DocumentRetrievalDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinDrivers_DocumentRetrievalDriver::get_type_descriptor, "None");
cls_BinDrivers_DocumentRetrievalDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinDrivers_DocumentRetrievalDriver::*)() const) &BinDrivers_DocumentRetrievalDriver::DynamicType, "None");

// Enums

}