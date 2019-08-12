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
#include <BinLDrivers_DocumentStorageDriver.hxx>
#include <Standard_Handle.hxx>
#include <BinMDF_ADriverTable.hxx>
#include <Message_Messenger.hxx>
#include <BinLDrivers_DocumentSection.hxx>
#include <Standard_OStream.hxx>
#include <Standard_TypeDef.hxx>
#include <BinDrivers_DocumentStorageDriver.hxx>
#include <Standard_Type.hxx>

void bind_BinDrivers_DocumentStorageDriver(py::module &mod){

py::class_<BinDrivers_DocumentStorageDriver, opencascade::handle<BinDrivers_DocumentStorageDriver>, BinLDrivers_DocumentStorageDriver> cls_BinDrivers_DocumentStorageDriver(mod, "BinDrivers_DocumentStorageDriver", "persistent implemention of storage a document in a binary file");

// Constructors
cls_BinDrivers_DocumentStorageDriver.def(py::init<>());

// Fields

// Methods
cls_BinDrivers_DocumentStorageDriver.def("AttributeDrivers", (opencascade::handle<BinMDF_ADriverTable> (BinDrivers_DocumentStorageDriver::*)(const opencascade::handle<Message_Messenger> &)) &BinDrivers_DocumentStorageDriver::AttributeDrivers, "None", py::arg("theMsgDriver"));
cls_BinDrivers_DocumentStorageDriver.def("WriteShapeSection", (void (BinDrivers_DocumentStorageDriver::*)(BinLDrivers_DocumentSection &, Standard_OStream &)) &BinDrivers_DocumentStorageDriver::WriteShapeSection, "implements the procedure of writing a shape section to file", py::arg("theDocSection"), py::arg("theOS"));
cls_BinDrivers_DocumentStorageDriver.def("IsWithTriangles", (Standard_Boolean (BinDrivers_DocumentStorageDriver::*)() const) &BinDrivers_DocumentStorageDriver::IsWithTriangles, "Return true if shape should be stored with triangles.");
cls_BinDrivers_DocumentStorageDriver.def("SetWithTriangles", (void (BinDrivers_DocumentStorageDriver::*)(const opencascade::handle<Message_Messenger> &, const Standard_Boolean)) &BinDrivers_DocumentStorageDriver::SetWithTriangles, "Set if triangulation should be stored or not.", py::arg("theMessageDriver"), py::arg("theWithTriangulation"));
cls_BinDrivers_DocumentStorageDriver.def_static("get_type_name_", (const char * (*)()) &BinDrivers_DocumentStorageDriver::get_type_name, "None");
cls_BinDrivers_DocumentStorageDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinDrivers_DocumentStorageDriver::get_type_descriptor, "None");
cls_BinDrivers_DocumentStorageDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinDrivers_DocumentStorageDriver::*)() const) &BinDrivers_DocumentStorageDriver::DynamicType, "None");

// Enums

}