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
#include <BinMDF_ADriverTable.hxx>
#include <Message_Messenger.hxx>
#include <BinTObjDrivers.hxx>
#include <BinLDrivers_DocumentRetrievalDriver.hxx>
#include <Standard_Std.hxx>
#include <BinTObjDrivers_DocumentRetrievalDriver.hxx>
#include <Standard_Type.hxx>
#include <BinLDrivers_DocumentStorageDriver.hxx>
#include <BinTObjDrivers_DocumentStorageDriver.hxx>
#include <BinMDF_ADriver.hxx>
#include <TDF_Attribute.hxx>
#include <Standard_TypeDef.hxx>
#include <BinObjMgt_Persistent.hxx>
#include <BinObjMgt_RRelocationTable.hxx>
#include <BinObjMgt_SRelocationTable.hxx>
#include <BinTObjDrivers_IntSparseArrayDriver.hxx>
#include <BinTObjDrivers_ModelDriver.hxx>
#include <BinTObjDrivers_ObjectDriver.hxx>
#include <BinTObjDrivers_ReferenceDriver.hxx>
#include <BinTObjDrivers_XYZDriver.hxx>

PYBIND11_MODULE(BinTObjDrivers, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.TDocStd");
py::module::import("OCCT.BinMDF");
py::module::import("OCCT.Message");
py::module::import("OCCT.BinLDrivers");
py::module::import("OCCT.TDF");
py::module::import("OCCT.BinObjMgt");

// CLASS: BINTOBJDRIVERS
py::class_<BinTObjDrivers> cls_BinTObjDrivers(mod, "BinTObjDrivers", "Class for registering storage/retrieval drivers for TObj Bin persistence");

// Methods
cls_BinTObjDrivers.def_static("Factory_", (const opencascade::handle<Standard_Transient> & (*)(const Standard_GUID &)) &BinTObjDrivers::Factory, "None", py::arg("aGUID"));
cls_BinTObjDrivers.def_static("DefineFormat_", (void (*)(const opencascade::handle<TDocStd_Application> &)) &BinTObjDrivers::DefineFormat, "Defines format 'TObjBin' and registers its read and write drivers in the specified application", py::arg("theApp"));
cls_BinTObjDrivers.def_static("AddDrivers_", (void (*)(const opencascade::handle<BinMDF_ADriverTable> &, const opencascade::handle<Message_Messenger> &)) &BinTObjDrivers::AddDrivers, "None", py::arg("aDriverTable"), py::arg("aMsgDrv"));

// CLASS: BINTOBJDRIVERS_DOCUMENTRETRIEVALDRIVER
py::class_<BinTObjDrivers_DocumentRetrievalDriver, opencascade::handle<BinTObjDrivers_DocumentRetrievalDriver>, BinLDrivers_DocumentRetrievalDriver> cls_BinTObjDrivers_DocumentRetrievalDriver(mod, "BinTObjDrivers_DocumentRetrievalDriver", "None");

// Constructors
cls_BinTObjDrivers_DocumentRetrievalDriver.def(py::init<>());

// Methods
cls_BinTObjDrivers_DocumentRetrievalDriver.def("AttributeDrivers", (opencascade::handle<BinMDF_ADriverTable> (BinTObjDrivers_DocumentRetrievalDriver::*)(const opencascade::handle<Message_Messenger> &)) &BinTObjDrivers_DocumentRetrievalDriver::AttributeDrivers, "None", py::arg("theMsgDriver"));
cls_BinTObjDrivers_DocumentRetrievalDriver.def_static("get_type_name_", (const char * (*)()) &BinTObjDrivers_DocumentRetrievalDriver::get_type_name, "None");
cls_BinTObjDrivers_DocumentRetrievalDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinTObjDrivers_DocumentRetrievalDriver::get_type_descriptor, "None");
cls_BinTObjDrivers_DocumentRetrievalDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinTObjDrivers_DocumentRetrievalDriver::*)() const) &BinTObjDrivers_DocumentRetrievalDriver::DynamicType, "None");

// CLASS: BINTOBJDRIVERS_DOCUMENTSTORAGEDRIVER
py::class_<BinTObjDrivers_DocumentStorageDriver, opencascade::handle<BinTObjDrivers_DocumentStorageDriver>, BinLDrivers_DocumentStorageDriver> cls_BinTObjDrivers_DocumentStorageDriver(mod, "BinTObjDrivers_DocumentStorageDriver", "None");

// Constructors
cls_BinTObjDrivers_DocumentStorageDriver.def(py::init<>());

// Methods
cls_BinTObjDrivers_DocumentStorageDriver.def("AttributeDrivers", (opencascade::handle<BinMDF_ADriverTable> (BinTObjDrivers_DocumentStorageDriver::*)(const opencascade::handle<Message_Messenger> &)) &BinTObjDrivers_DocumentStorageDriver::AttributeDrivers, "None", py::arg("theMsgDriver"));
cls_BinTObjDrivers_DocumentStorageDriver.def_static("get_type_name_", (const char * (*)()) &BinTObjDrivers_DocumentStorageDriver::get_type_name, "None");
cls_BinTObjDrivers_DocumentStorageDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinTObjDrivers_DocumentStorageDriver::get_type_descriptor, "None");
cls_BinTObjDrivers_DocumentStorageDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinTObjDrivers_DocumentStorageDriver::*)() const) &BinTObjDrivers_DocumentStorageDriver::DynamicType, "None");

// CLASS: BINTOBJDRIVERS_INTSPARSEARRAYDRIVER
py::class_<BinTObjDrivers_IntSparseArrayDriver, opencascade::handle<BinTObjDrivers_IntSparseArrayDriver>, BinMDF_ADriver> cls_BinTObjDrivers_IntSparseArrayDriver(mod, "BinTObjDrivers_IntSparseArrayDriver", "None");

// Constructors
cls_BinTObjDrivers_IntSparseArrayDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Methods
cls_BinTObjDrivers_IntSparseArrayDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinTObjDrivers_IntSparseArrayDriver::*)() const) &BinTObjDrivers_IntSparseArrayDriver::NewEmpty, "None");
cls_BinTObjDrivers_IntSparseArrayDriver.def("Paste", (Standard_Boolean (BinTObjDrivers_IntSparseArrayDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const) &BinTObjDrivers_IntSparseArrayDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
cls_BinTObjDrivers_IntSparseArrayDriver.def("Paste", (void (BinTObjDrivers_IntSparseArrayDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const) &BinTObjDrivers_IntSparseArrayDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
cls_BinTObjDrivers_IntSparseArrayDriver.def_static("get_type_name_", (const char * (*)()) &BinTObjDrivers_IntSparseArrayDriver::get_type_name, "None");
cls_BinTObjDrivers_IntSparseArrayDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinTObjDrivers_IntSparseArrayDriver::get_type_descriptor, "None");
cls_BinTObjDrivers_IntSparseArrayDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinTObjDrivers_IntSparseArrayDriver::*)() const) &BinTObjDrivers_IntSparseArrayDriver::DynamicType, "None");

// CLASS: BINTOBJDRIVERS_MODELDRIVER
py::class_<BinTObjDrivers_ModelDriver, opencascade::handle<BinTObjDrivers_ModelDriver>, BinMDF_ADriver> cls_BinTObjDrivers_ModelDriver(mod, "BinTObjDrivers_ModelDriver", "None");

// Constructors
cls_BinTObjDrivers_ModelDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Methods
cls_BinTObjDrivers_ModelDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinTObjDrivers_ModelDriver::*)() const) &BinTObjDrivers_ModelDriver::NewEmpty, "None");
cls_BinTObjDrivers_ModelDriver.def("Paste", (Standard_Boolean (BinTObjDrivers_ModelDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const) &BinTObjDrivers_ModelDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_BinTObjDrivers_ModelDriver.def("Paste", (void (BinTObjDrivers_ModelDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const) &BinTObjDrivers_ModelDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_BinTObjDrivers_ModelDriver.def_static("get_type_name_", (const char * (*)()) &BinTObjDrivers_ModelDriver::get_type_name, "None");
cls_BinTObjDrivers_ModelDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinTObjDrivers_ModelDriver::get_type_descriptor, "None");
cls_BinTObjDrivers_ModelDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinTObjDrivers_ModelDriver::*)() const) &BinTObjDrivers_ModelDriver::DynamicType, "None");

// CLASS: BINTOBJDRIVERS_OBJECTDRIVER
py::class_<BinTObjDrivers_ObjectDriver, opencascade::handle<BinTObjDrivers_ObjectDriver>, BinMDF_ADriver> cls_BinTObjDrivers_ObjectDriver(mod, "BinTObjDrivers_ObjectDriver", "None");

// Constructors
cls_BinTObjDrivers_ObjectDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Methods
cls_BinTObjDrivers_ObjectDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinTObjDrivers_ObjectDriver::*)() const) &BinTObjDrivers_ObjectDriver::NewEmpty, "None");
cls_BinTObjDrivers_ObjectDriver.def("Paste", (Standard_Boolean (BinTObjDrivers_ObjectDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const) &BinTObjDrivers_ObjectDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_BinTObjDrivers_ObjectDriver.def("Paste", (void (BinTObjDrivers_ObjectDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const) &BinTObjDrivers_ObjectDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_BinTObjDrivers_ObjectDriver.def_static("get_type_name_", (const char * (*)()) &BinTObjDrivers_ObjectDriver::get_type_name, "None");
cls_BinTObjDrivers_ObjectDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinTObjDrivers_ObjectDriver::get_type_descriptor, "None");
cls_BinTObjDrivers_ObjectDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinTObjDrivers_ObjectDriver::*)() const) &BinTObjDrivers_ObjectDriver::DynamicType, "None");

// CLASS: BINTOBJDRIVERS_REFERENCEDRIVER
py::class_<BinTObjDrivers_ReferenceDriver, opencascade::handle<BinTObjDrivers_ReferenceDriver>, BinMDF_ADriver> cls_BinTObjDrivers_ReferenceDriver(mod, "BinTObjDrivers_ReferenceDriver", "None");

// Constructors
cls_BinTObjDrivers_ReferenceDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Methods
cls_BinTObjDrivers_ReferenceDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinTObjDrivers_ReferenceDriver::*)() const) &BinTObjDrivers_ReferenceDriver::NewEmpty, "None");
cls_BinTObjDrivers_ReferenceDriver.def("Paste", (Standard_Boolean (BinTObjDrivers_ReferenceDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const) &BinTObjDrivers_ReferenceDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_BinTObjDrivers_ReferenceDriver.def("Paste", (void (BinTObjDrivers_ReferenceDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const) &BinTObjDrivers_ReferenceDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_BinTObjDrivers_ReferenceDriver.def_static("get_type_name_", (const char * (*)()) &BinTObjDrivers_ReferenceDriver::get_type_name, "None");
cls_BinTObjDrivers_ReferenceDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinTObjDrivers_ReferenceDriver::get_type_descriptor, "None");
cls_BinTObjDrivers_ReferenceDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinTObjDrivers_ReferenceDriver::*)() const) &BinTObjDrivers_ReferenceDriver::DynamicType, "None");

// CLASS: BINTOBJDRIVERS_XYZDRIVER
py::class_<BinTObjDrivers_XYZDriver, opencascade::handle<BinTObjDrivers_XYZDriver>, BinMDF_ADriver> cls_BinTObjDrivers_XYZDriver(mod, "BinTObjDrivers_XYZDriver", "None");

// Constructors
cls_BinTObjDrivers_XYZDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Methods
cls_BinTObjDrivers_XYZDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinTObjDrivers_XYZDriver::*)() const) &BinTObjDrivers_XYZDriver::NewEmpty, "None");
cls_BinTObjDrivers_XYZDriver.def("Paste", (Standard_Boolean (BinTObjDrivers_XYZDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const) &BinTObjDrivers_XYZDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
cls_BinTObjDrivers_XYZDriver.def("Paste", (void (BinTObjDrivers_XYZDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const) &BinTObjDrivers_XYZDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
cls_BinTObjDrivers_XYZDriver.def_static("get_type_name_", (const char * (*)()) &BinTObjDrivers_XYZDriver::get_type_name, "None");
cls_BinTObjDrivers_XYZDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinTObjDrivers_XYZDriver::get_type_descriptor, "None");
cls_BinTObjDrivers_XYZDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinTObjDrivers_XYZDriver::*)() const) &BinTObjDrivers_XYZDriver::DynamicType, "None");


}
