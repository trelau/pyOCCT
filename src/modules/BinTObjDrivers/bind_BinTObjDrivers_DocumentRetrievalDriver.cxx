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
#include <BinTObjDrivers_DocumentRetrievalDriver.hxx>
#include <Standard_Type.hxx>

void bind_BinTObjDrivers_DocumentRetrievalDriver(py::module &mod){

py::class_<BinTObjDrivers_DocumentRetrievalDriver, opencascade::handle<BinTObjDrivers_DocumentRetrievalDriver>, BinLDrivers_DocumentRetrievalDriver> cls_BinTObjDrivers_DocumentRetrievalDriver(mod, "BinTObjDrivers_DocumentRetrievalDriver", "None");

// Constructors
cls_BinTObjDrivers_DocumentRetrievalDriver.def(py::init<>());

// Fields

// Methods
cls_BinTObjDrivers_DocumentRetrievalDriver.def("AttributeDrivers", (opencascade::handle<BinMDF_ADriverTable> (BinTObjDrivers_DocumentRetrievalDriver::*)(const opencascade::handle<Message_Messenger> &)) &BinTObjDrivers_DocumentRetrievalDriver::AttributeDrivers, "None", py::arg("theMsgDriver"));
cls_BinTObjDrivers_DocumentRetrievalDriver.def_static("get_type_name_", (const char * (*)()) &BinTObjDrivers_DocumentRetrievalDriver::get_type_name, "None");
cls_BinTObjDrivers_DocumentRetrievalDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinTObjDrivers_DocumentRetrievalDriver::get_type_descriptor, "None");
cls_BinTObjDrivers_DocumentRetrievalDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinTObjDrivers_DocumentRetrievalDriver::*)() const) &BinTObjDrivers_DocumentRetrievalDriver::DynamicType, "None");

// Enums

}