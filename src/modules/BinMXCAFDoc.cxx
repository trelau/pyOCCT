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
#include <BinTools_LocationSet.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <BinMDF_ADriverTable.hxx>
#include <Message_Messenger.hxx>
#include <BinMXCAFDoc_AreaDriver.hxx>
#include <BinMXCAFDoc_CentroidDriver.hxx>
#include <BinMXCAFDoc_ClippingPlaneToolDriver.hxx>
#include <BinMXCAFDoc_ColorDriver.hxx>
#include <BinMXCAFDoc_GraphNodeDriver.hxx>
#include <BinMXCAFDoc_LocationDriver.hxx>
#include <BinMXCAFDoc_VolumeDriver.hxx>
#include <BinMXCAFDoc_DatumDriver.hxx>
#include <BinMXCAFDoc_GeomToleranceDriver.hxx>
#include <BinMXCAFDoc_DimensionDriver.hxx>
#include <BinMXCAFDoc_DimTolDriver.hxx>
#include <BinMXCAFDoc_MaterialDriver.hxx>
#include <BinMXCAFDoc_ColorToolDriver.hxx>
#include <BinMXCAFDoc_DocumentToolDriver.hxx>
#include <BinMXCAFDoc_LayerToolDriver.hxx>
#include <BinMXCAFDoc_ShapeToolDriver.hxx>
#include <BinMXCAFDoc_DimTolToolDriver.hxx>
#include <BinMXCAFDoc_MaterialToolDriver.hxx>
#include <BinMXCAFDoc_ViewDriver.hxx>
#include <BinMXCAFDoc_ViewToolDriver.hxx>
#include <BinMXCAFDoc.hxx>
#include <BinMDF_ADriver.hxx>
#include <TDF_Attribute.hxx>
#include <Standard_TypeDef.hxx>
#include <BinObjMgt_Persistent.hxx>
#include <BinObjMgt_RRelocationTable.hxx>
#include <BinObjMgt_SRelocationTable.hxx>
#include <Standard_Std.hxx>
#include <Standard_Type.hxx>
#include <BinMXCAFDoc_AssemblyItemRefDriver.hxx>
#include <TopLoc_Location.hxx>
#include <BinTools_LocationSetPtr.hxx>
#include <BinMXCAFDoc_NoteDriver.hxx>
#include <BinMXCAFDoc_NoteCommentDriver.hxx>
#include <BinMXCAFDoc_NoteBalloonDriver.hxx>
#include <BinMXCAFDoc_NoteBinDataDriver.hxx>
#include <BinMXCAFDoc_NotesToolDriver.hxx>

PYBIND11_MODULE(BinMXCAFDoc, mod) {

py::module::import("OCCT.BinTools");
py::module::import("OCCT.Standard");
py::module::import("OCCT.BinMDF");
py::module::import("OCCT.Message");
py::module::import("OCCT.TDF");
py::module::import("OCCT.BinObjMgt");
py::module::import("OCCT.TopLoc");

// CLASS: BINMXCAFDOC
py::class_<BinMXCAFDoc> cls_BinMXCAFDoc(mod, "BinMXCAFDoc", "None");

// Methods
// cls_BinMXCAFDoc.def_static("operator new_", (void * (*)(size_t)) &BinMXCAFDoc::operator new, "None", py::arg("theSize"));
// cls_BinMXCAFDoc.def_static("operator delete_", (void (*)(void *)) &BinMXCAFDoc::operator delete, "None", py::arg("theAddress"));
// cls_BinMXCAFDoc.def_static("operator new[]_", (void * (*)(size_t)) &BinMXCAFDoc::operator new[], "None", py::arg("theSize"));
// cls_BinMXCAFDoc.def_static("operator delete[]_", (void (*)(void *)) &BinMXCAFDoc::operator delete[], "None", py::arg("theAddress"));
// cls_BinMXCAFDoc.def_static("operator new_", (void * (*)(size_t, void *)) &BinMXCAFDoc::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BinMXCAFDoc.def_static("operator delete_", (void (*)(void *, void *)) &BinMXCAFDoc::operator delete, "None", py::arg(""), py::arg(""));
cls_BinMXCAFDoc.def_static("AddDrivers_", (void (*)(const opencascade::handle<BinMDF_ADriverTable> &, const opencascade::handle<Message_Messenger> &)) &BinMXCAFDoc::AddDrivers, "Adds the attribute drivers to <theDriverTable>.", py::arg("theDriverTable"), py::arg("theMsgDrv"));

// CLASS: BINMXCAFDOC_AREADRIVER
py::class_<BinMXCAFDoc_AreaDriver, opencascade::handle<BinMXCAFDoc_AreaDriver>, BinMDF_ADriver> cls_BinMXCAFDoc_AreaDriver(mod, "BinMXCAFDoc_AreaDriver", "None");

// Constructors
cls_BinMXCAFDoc_AreaDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMsgDriver"));

// Methods
cls_BinMXCAFDoc_AreaDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMXCAFDoc_AreaDriver::*)() const) &BinMXCAFDoc_AreaDriver::NewEmpty, "None");
cls_BinMXCAFDoc_AreaDriver.def("Paste", (Standard_Boolean (BinMXCAFDoc_AreaDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const) &BinMXCAFDoc_AreaDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
cls_BinMXCAFDoc_AreaDriver.def("Paste", (void (BinMXCAFDoc_AreaDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const) &BinMXCAFDoc_AreaDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
cls_BinMXCAFDoc_AreaDriver.def_static("get_type_name_", (const char * (*)()) &BinMXCAFDoc_AreaDriver::get_type_name, "None");
cls_BinMXCAFDoc_AreaDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMXCAFDoc_AreaDriver::get_type_descriptor, "None");
cls_BinMXCAFDoc_AreaDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMXCAFDoc_AreaDriver::*)() const) &BinMXCAFDoc_AreaDriver::DynamicType, "None");

// CLASS: BINMXCAFDOC_ASSEMBLYITEMREFDRIVER
py::class_<BinMXCAFDoc_AssemblyItemRefDriver, opencascade::handle<BinMXCAFDoc_AssemblyItemRefDriver>, BinMDF_ADriver> cls_BinMXCAFDoc_AssemblyItemRefDriver(mod, "BinMXCAFDoc_AssemblyItemRefDriver", "None");

// Constructors
cls_BinMXCAFDoc_AssemblyItemRefDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMsgDriver"));

// Methods
cls_BinMXCAFDoc_AssemblyItemRefDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMXCAFDoc_AssemblyItemRefDriver::*)() const) &BinMXCAFDoc_AssemblyItemRefDriver::NewEmpty, "None");
cls_BinMXCAFDoc_AssemblyItemRefDriver.def("Paste", (Standard_Boolean (BinMXCAFDoc_AssemblyItemRefDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const) &BinMXCAFDoc_AssemblyItemRefDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
cls_BinMXCAFDoc_AssemblyItemRefDriver.def("Paste", (void (BinMXCAFDoc_AssemblyItemRefDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const) &BinMXCAFDoc_AssemblyItemRefDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
cls_BinMXCAFDoc_AssemblyItemRefDriver.def_static("get_type_name_", (const char * (*)()) &BinMXCAFDoc_AssemblyItemRefDriver::get_type_name, "None");
cls_BinMXCAFDoc_AssemblyItemRefDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMXCAFDoc_AssemblyItemRefDriver::get_type_descriptor, "None");
cls_BinMXCAFDoc_AssemblyItemRefDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMXCAFDoc_AssemblyItemRefDriver::*)() const) &BinMXCAFDoc_AssemblyItemRefDriver::DynamicType, "None");

// CLASS: BINMXCAFDOC_CENTROIDDRIVER
py::class_<BinMXCAFDoc_CentroidDriver, opencascade::handle<BinMXCAFDoc_CentroidDriver>, BinMDF_ADriver> cls_BinMXCAFDoc_CentroidDriver(mod, "BinMXCAFDoc_CentroidDriver", "None");

// Constructors
cls_BinMXCAFDoc_CentroidDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMsgDriver"));

// Methods
cls_BinMXCAFDoc_CentroidDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMXCAFDoc_CentroidDriver::*)() const) &BinMXCAFDoc_CentroidDriver::NewEmpty, "None");
cls_BinMXCAFDoc_CentroidDriver.def("Paste", (Standard_Boolean (BinMXCAFDoc_CentroidDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const) &BinMXCAFDoc_CentroidDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
cls_BinMXCAFDoc_CentroidDriver.def("Paste", (void (BinMXCAFDoc_CentroidDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const) &BinMXCAFDoc_CentroidDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
cls_BinMXCAFDoc_CentroidDriver.def_static("get_type_name_", (const char * (*)()) &BinMXCAFDoc_CentroidDriver::get_type_name, "None");
cls_BinMXCAFDoc_CentroidDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMXCAFDoc_CentroidDriver::get_type_descriptor, "None");
cls_BinMXCAFDoc_CentroidDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMXCAFDoc_CentroidDriver::*)() const) &BinMXCAFDoc_CentroidDriver::DynamicType, "None");

// CLASS: BINMXCAFDOC_CLIPPINGPLANETOOLDRIVER
py::class_<BinMXCAFDoc_ClippingPlaneToolDriver, opencascade::handle<BinMXCAFDoc_ClippingPlaneToolDriver>, BinMDF_ADriver> cls_BinMXCAFDoc_ClippingPlaneToolDriver(mod, "BinMXCAFDoc_ClippingPlaneToolDriver", "None");

// Constructors
cls_BinMXCAFDoc_ClippingPlaneToolDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMsgDriver"));

// Methods
cls_BinMXCAFDoc_ClippingPlaneToolDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMXCAFDoc_ClippingPlaneToolDriver::*)() const) &BinMXCAFDoc_ClippingPlaneToolDriver::NewEmpty, "None");
cls_BinMXCAFDoc_ClippingPlaneToolDriver.def("Paste", (Standard_Boolean (BinMXCAFDoc_ClippingPlaneToolDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const) &BinMXCAFDoc_ClippingPlaneToolDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
cls_BinMXCAFDoc_ClippingPlaneToolDriver.def("Paste", (void (BinMXCAFDoc_ClippingPlaneToolDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const) &BinMXCAFDoc_ClippingPlaneToolDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
cls_BinMXCAFDoc_ClippingPlaneToolDriver.def_static("get_type_name_", (const char * (*)()) &BinMXCAFDoc_ClippingPlaneToolDriver::get_type_name, "None");
cls_BinMXCAFDoc_ClippingPlaneToolDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMXCAFDoc_ClippingPlaneToolDriver::get_type_descriptor, "None");
cls_BinMXCAFDoc_ClippingPlaneToolDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMXCAFDoc_ClippingPlaneToolDriver::*)() const) &BinMXCAFDoc_ClippingPlaneToolDriver::DynamicType, "None");

// CLASS: BINMXCAFDOC_COLORDRIVER
py::class_<BinMXCAFDoc_ColorDriver, opencascade::handle<BinMXCAFDoc_ColorDriver>, BinMDF_ADriver> cls_BinMXCAFDoc_ColorDriver(mod, "BinMXCAFDoc_ColorDriver", "None");

// Constructors
cls_BinMXCAFDoc_ColorDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMsgDriver"));

// Methods
cls_BinMXCAFDoc_ColorDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMXCAFDoc_ColorDriver::*)() const) &BinMXCAFDoc_ColorDriver::NewEmpty, "None");
cls_BinMXCAFDoc_ColorDriver.def("Paste", (Standard_Boolean (BinMXCAFDoc_ColorDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const) &BinMXCAFDoc_ColorDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
cls_BinMXCAFDoc_ColorDriver.def("Paste", (void (BinMXCAFDoc_ColorDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const) &BinMXCAFDoc_ColorDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
cls_BinMXCAFDoc_ColorDriver.def_static("get_type_name_", (const char * (*)()) &BinMXCAFDoc_ColorDriver::get_type_name, "None");
cls_BinMXCAFDoc_ColorDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMXCAFDoc_ColorDriver::get_type_descriptor, "None");
cls_BinMXCAFDoc_ColorDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMXCAFDoc_ColorDriver::*)() const) &BinMXCAFDoc_ColorDriver::DynamicType, "None");

// CLASS: BINMXCAFDOC_COLORTOOLDRIVER
py::class_<BinMXCAFDoc_ColorToolDriver, opencascade::handle<BinMXCAFDoc_ColorToolDriver>, BinMDF_ADriver> cls_BinMXCAFDoc_ColorToolDriver(mod, "BinMXCAFDoc_ColorToolDriver", "None");

// Constructors
cls_BinMXCAFDoc_ColorToolDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMsgDriver"));

// Methods
cls_BinMXCAFDoc_ColorToolDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMXCAFDoc_ColorToolDriver::*)() const) &BinMXCAFDoc_ColorToolDriver::NewEmpty, "None");
cls_BinMXCAFDoc_ColorToolDriver.def("Paste", (Standard_Boolean (BinMXCAFDoc_ColorToolDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const) &BinMXCAFDoc_ColorToolDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
cls_BinMXCAFDoc_ColorToolDriver.def("Paste", (void (BinMXCAFDoc_ColorToolDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const) &BinMXCAFDoc_ColorToolDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
cls_BinMXCAFDoc_ColorToolDriver.def_static("get_type_name_", (const char * (*)()) &BinMXCAFDoc_ColorToolDriver::get_type_name, "None");
cls_BinMXCAFDoc_ColorToolDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMXCAFDoc_ColorToolDriver::get_type_descriptor, "None");
cls_BinMXCAFDoc_ColorToolDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMXCAFDoc_ColorToolDriver::*)() const) &BinMXCAFDoc_ColorToolDriver::DynamicType, "None");

// CLASS: BINMXCAFDOC_DATUMDRIVER
py::class_<BinMXCAFDoc_DatumDriver, opencascade::handle<BinMXCAFDoc_DatumDriver>, BinMDF_ADriver> cls_BinMXCAFDoc_DatumDriver(mod, "BinMXCAFDoc_DatumDriver", "None");

// Constructors
cls_BinMXCAFDoc_DatumDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMsgDriver"));

// Methods
cls_BinMXCAFDoc_DatumDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMXCAFDoc_DatumDriver::*)() const) &BinMXCAFDoc_DatumDriver::NewEmpty, "None");
cls_BinMXCAFDoc_DatumDriver.def("Paste", (Standard_Boolean (BinMXCAFDoc_DatumDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const) &BinMXCAFDoc_DatumDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
cls_BinMXCAFDoc_DatumDriver.def("Paste", (void (BinMXCAFDoc_DatumDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const) &BinMXCAFDoc_DatumDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
cls_BinMXCAFDoc_DatumDriver.def_static("get_type_name_", (const char * (*)()) &BinMXCAFDoc_DatumDriver::get_type_name, "None");
cls_BinMXCAFDoc_DatumDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMXCAFDoc_DatumDriver::get_type_descriptor, "None");
cls_BinMXCAFDoc_DatumDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMXCAFDoc_DatumDriver::*)() const) &BinMXCAFDoc_DatumDriver::DynamicType, "None");

// CLASS: BINMXCAFDOC_DIMENSIONDRIVER
py::class_<BinMXCAFDoc_DimensionDriver, opencascade::handle<BinMXCAFDoc_DimensionDriver>, BinMDF_ADriver> cls_BinMXCAFDoc_DimensionDriver(mod, "BinMXCAFDoc_DimensionDriver", "None");

// Constructors
cls_BinMXCAFDoc_DimensionDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMsgDriver"));

// Methods
cls_BinMXCAFDoc_DimensionDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMXCAFDoc_DimensionDriver::*)() const) &BinMXCAFDoc_DimensionDriver::NewEmpty, "None");
cls_BinMXCAFDoc_DimensionDriver.def("Paste", (Standard_Boolean (BinMXCAFDoc_DimensionDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const) &BinMXCAFDoc_DimensionDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
cls_BinMXCAFDoc_DimensionDriver.def("Paste", (void (BinMXCAFDoc_DimensionDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const) &BinMXCAFDoc_DimensionDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
cls_BinMXCAFDoc_DimensionDriver.def_static("get_type_name_", (const char * (*)()) &BinMXCAFDoc_DimensionDriver::get_type_name, "None");
cls_BinMXCAFDoc_DimensionDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMXCAFDoc_DimensionDriver::get_type_descriptor, "None");
cls_BinMXCAFDoc_DimensionDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMXCAFDoc_DimensionDriver::*)() const) &BinMXCAFDoc_DimensionDriver::DynamicType, "None");

// CLASS: BINMXCAFDOC_DIMTOLDRIVER
py::class_<BinMXCAFDoc_DimTolDriver, opencascade::handle<BinMXCAFDoc_DimTolDriver>, BinMDF_ADriver> cls_BinMXCAFDoc_DimTolDriver(mod, "BinMXCAFDoc_DimTolDriver", "None");

// Constructors
cls_BinMXCAFDoc_DimTolDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMsgDriver"));

// Methods
cls_BinMXCAFDoc_DimTolDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMXCAFDoc_DimTolDriver::*)() const) &BinMXCAFDoc_DimTolDriver::NewEmpty, "None");
cls_BinMXCAFDoc_DimTolDriver.def("Paste", (Standard_Boolean (BinMXCAFDoc_DimTolDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const) &BinMXCAFDoc_DimTolDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
cls_BinMXCAFDoc_DimTolDriver.def("Paste", (void (BinMXCAFDoc_DimTolDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const) &BinMXCAFDoc_DimTolDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
cls_BinMXCAFDoc_DimTolDriver.def_static("get_type_name_", (const char * (*)()) &BinMXCAFDoc_DimTolDriver::get_type_name, "None");
cls_BinMXCAFDoc_DimTolDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMXCAFDoc_DimTolDriver::get_type_descriptor, "None");
cls_BinMXCAFDoc_DimTolDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMXCAFDoc_DimTolDriver::*)() const) &BinMXCAFDoc_DimTolDriver::DynamicType, "None");

// CLASS: BINMXCAFDOC_DIMTOLTOOLDRIVER
py::class_<BinMXCAFDoc_DimTolToolDriver, opencascade::handle<BinMXCAFDoc_DimTolToolDriver>, BinMDF_ADriver> cls_BinMXCAFDoc_DimTolToolDriver(mod, "BinMXCAFDoc_DimTolToolDriver", "None");

// Constructors
cls_BinMXCAFDoc_DimTolToolDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMsgDriver"));

// Methods
cls_BinMXCAFDoc_DimTolToolDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMXCAFDoc_DimTolToolDriver::*)() const) &BinMXCAFDoc_DimTolToolDriver::NewEmpty, "None");
cls_BinMXCAFDoc_DimTolToolDriver.def("Paste", (Standard_Boolean (BinMXCAFDoc_DimTolToolDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const) &BinMXCAFDoc_DimTolToolDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
cls_BinMXCAFDoc_DimTolToolDriver.def("Paste", (void (BinMXCAFDoc_DimTolToolDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const) &BinMXCAFDoc_DimTolToolDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
cls_BinMXCAFDoc_DimTolToolDriver.def_static("get_type_name_", (const char * (*)()) &BinMXCAFDoc_DimTolToolDriver::get_type_name, "None");
cls_BinMXCAFDoc_DimTolToolDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMXCAFDoc_DimTolToolDriver::get_type_descriptor, "None");
cls_BinMXCAFDoc_DimTolToolDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMXCAFDoc_DimTolToolDriver::*)() const) &BinMXCAFDoc_DimTolToolDriver::DynamicType, "None");

// CLASS: BINMXCAFDOC_DOCUMENTTOOLDRIVER
py::class_<BinMXCAFDoc_DocumentToolDriver, opencascade::handle<BinMXCAFDoc_DocumentToolDriver>, BinMDF_ADriver> cls_BinMXCAFDoc_DocumentToolDriver(mod, "BinMXCAFDoc_DocumentToolDriver", "None");

// Constructors
cls_BinMXCAFDoc_DocumentToolDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMsgDriver"));

// Methods
cls_BinMXCAFDoc_DocumentToolDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMXCAFDoc_DocumentToolDriver::*)() const) &BinMXCAFDoc_DocumentToolDriver::NewEmpty, "None");
cls_BinMXCAFDoc_DocumentToolDriver.def("Paste", (Standard_Boolean (BinMXCAFDoc_DocumentToolDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const) &BinMXCAFDoc_DocumentToolDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
cls_BinMXCAFDoc_DocumentToolDriver.def("Paste", (void (BinMXCAFDoc_DocumentToolDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const) &BinMXCAFDoc_DocumentToolDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
cls_BinMXCAFDoc_DocumentToolDriver.def_static("get_type_name_", (const char * (*)()) &BinMXCAFDoc_DocumentToolDriver::get_type_name, "None");
cls_BinMXCAFDoc_DocumentToolDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMXCAFDoc_DocumentToolDriver::get_type_descriptor, "None");
cls_BinMXCAFDoc_DocumentToolDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMXCAFDoc_DocumentToolDriver::*)() const) &BinMXCAFDoc_DocumentToolDriver::DynamicType, "None");

// CLASS: BINMXCAFDOC_GEOMTOLERANCEDRIVER
py::class_<BinMXCAFDoc_GeomToleranceDriver, opencascade::handle<BinMXCAFDoc_GeomToleranceDriver>, BinMDF_ADriver> cls_BinMXCAFDoc_GeomToleranceDriver(mod, "BinMXCAFDoc_GeomToleranceDriver", "None");

// Constructors
cls_BinMXCAFDoc_GeomToleranceDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMsgDriver"));

// Methods
cls_BinMXCAFDoc_GeomToleranceDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMXCAFDoc_GeomToleranceDriver::*)() const) &BinMXCAFDoc_GeomToleranceDriver::NewEmpty, "None");
cls_BinMXCAFDoc_GeomToleranceDriver.def("Paste", (Standard_Boolean (BinMXCAFDoc_GeomToleranceDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const) &BinMXCAFDoc_GeomToleranceDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
cls_BinMXCAFDoc_GeomToleranceDriver.def("Paste", (void (BinMXCAFDoc_GeomToleranceDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const) &BinMXCAFDoc_GeomToleranceDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
cls_BinMXCAFDoc_GeomToleranceDriver.def_static("get_type_name_", (const char * (*)()) &BinMXCAFDoc_GeomToleranceDriver::get_type_name, "None");
cls_BinMXCAFDoc_GeomToleranceDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMXCAFDoc_GeomToleranceDriver::get_type_descriptor, "None");
cls_BinMXCAFDoc_GeomToleranceDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMXCAFDoc_GeomToleranceDriver::*)() const) &BinMXCAFDoc_GeomToleranceDriver::DynamicType, "None");

// CLASS: BINMXCAFDOC_GRAPHNODEDRIVER
py::class_<BinMXCAFDoc_GraphNodeDriver, opencascade::handle<BinMXCAFDoc_GraphNodeDriver>, BinMDF_ADriver> cls_BinMXCAFDoc_GraphNodeDriver(mod, "BinMXCAFDoc_GraphNodeDriver", "None");

// Constructors
cls_BinMXCAFDoc_GraphNodeDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMsgDriver"));

// Methods
cls_BinMXCAFDoc_GraphNodeDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMXCAFDoc_GraphNodeDriver::*)() const) &BinMXCAFDoc_GraphNodeDriver::NewEmpty, "None");
cls_BinMXCAFDoc_GraphNodeDriver.def("Paste", (Standard_Boolean (BinMXCAFDoc_GraphNodeDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const) &BinMXCAFDoc_GraphNodeDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
cls_BinMXCAFDoc_GraphNodeDriver.def("Paste", (void (BinMXCAFDoc_GraphNodeDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const) &BinMXCAFDoc_GraphNodeDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
cls_BinMXCAFDoc_GraphNodeDriver.def_static("get_type_name_", (const char * (*)()) &BinMXCAFDoc_GraphNodeDriver::get_type_name, "None");
cls_BinMXCAFDoc_GraphNodeDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMXCAFDoc_GraphNodeDriver::get_type_descriptor, "None");
cls_BinMXCAFDoc_GraphNodeDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMXCAFDoc_GraphNodeDriver::*)() const) &BinMXCAFDoc_GraphNodeDriver::DynamicType, "None");

// CLASS: BINMXCAFDOC_LAYERTOOLDRIVER
py::class_<BinMXCAFDoc_LayerToolDriver, opencascade::handle<BinMXCAFDoc_LayerToolDriver>, BinMDF_ADriver> cls_BinMXCAFDoc_LayerToolDriver(mod, "BinMXCAFDoc_LayerToolDriver", "None");

// Constructors
cls_BinMXCAFDoc_LayerToolDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMsgDriver"));

// Methods
cls_BinMXCAFDoc_LayerToolDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMXCAFDoc_LayerToolDriver::*)() const) &BinMXCAFDoc_LayerToolDriver::NewEmpty, "None");
cls_BinMXCAFDoc_LayerToolDriver.def("Paste", (Standard_Boolean (BinMXCAFDoc_LayerToolDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const) &BinMXCAFDoc_LayerToolDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
cls_BinMXCAFDoc_LayerToolDriver.def("Paste", (void (BinMXCAFDoc_LayerToolDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const) &BinMXCAFDoc_LayerToolDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
cls_BinMXCAFDoc_LayerToolDriver.def_static("get_type_name_", (const char * (*)()) &BinMXCAFDoc_LayerToolDriver::get_type_name, "None");
cls_BinMXCAFDoc_LayerToolDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMXCAFDoc_LayerToolDriver::get_type_descriptor, "None");
cls_BinMXCAFDoc_LayerToolDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMXCAFDoc_LayerToolDriver::*)() const) &BinMXCAFDoc_LayerToolDriver::DynamicType, "None");

// CLASS: BINMXCAFDOC_LOCATIONDRIVER
py::class_<BinMXCAFDoc_LocationDriver, opencascade::handle<BinMXCAFDoc_LocationDriver>, BinMDF_ADriver> cls_BinMXCAFDoc_LocationDriver(mod, "BinMXCAFDoc_LocationDriver", "None");

// Constructors
cls_BinMXCAFDoc_LocationDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMsgDriver"));

// Methods
cls_BinMXCAFDoc_LocationDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMXCAFDoc_LocationDriver::*)() const) &BinMXCAFDoc_LocationDriver::NewEmpty, "None");
cls_BinMXCAFDoc_LocationDriver.def("Paste", (Standard_Boolean (BinMXCAFDoc_LocationDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const) &BinMXCAFDoc_LocationDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
cls_BinMXCAFDoc_LocationDriver.def("Paste", (void (BinMXCAFDoc_LocationDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const) &BinMXCAFDoc_LocationDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
cls_BinMXCAFDoc_LocationDriver.def("Translate", (Standard_Boolean (BinMXCAFDoc_LocationDriver::*)(const BinObjMgt_Persistent &, TopLoc_Location &, BinObjMgt_RRelocationTable &) const) &BinMXCAFDoc_LocationDriver::Translate, "None", py::arg("theSource"), py::arg("theLoc"), py::arg("theMap"));
cls_BinMXCAFDoc_LocationDriver.def("Translate", (void (BinMXCAFDoc_LocationDriver::*)(const TopLoc_Location &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const) &BinMXCAFDoc_LocationDriver::Translate, "Translate transient location to storable", py::arg("theLoc"), py::arg("theTarget"), py::arg("theMap"));
cls_BinMXCAFDoc_LocationDriver.def("SetSharedLocations", (void (BinMXCAFDoc_LocationDriver::*)(const BinTools_LocationSetPtr &)) &BinMXCAFDoc_LocationDriver::SetSharedLocations, "None", py::arg("theLocations"));
cls_BinMXCAFDoc_LocationDriver.def_static("get_type_name_", (const char * (*)()) &BinMXCAFDoc_LocationDriver::get_type_name, "None");
cls_BinMXCAFDoc_LocationDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMXCAFDoc_LocationDriver::get_type_descriptor, "None");
cls_BinMXCAFDoc_LocationDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMXCAFDoc_LocationDriver::*)() const) &BinMXCAFDoc_LocationDriver::DynamicType, "None");

// CLASS: BINMXCAFDOC_MATERIALDRIVER
py::class_<BinMXCAFDoc_MaterialDriver, opencascade::handle<BinMXCAFDoc_MaterialDriver>, BinMDF_ADriver> cls_BinMXCAFDoc_MaterialDriver(mod, "BinMXCAFDoc_MaterialDriver", "None");

// Constructors
cls_BinMXCAFDoc_MaterialDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMsgDriver"));

// Methods
cls_BinMXCAFDoc_MaterialDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMXCAFDoc_MaterialDriver::*)() const) &BinMXCAFDoc_MaterialDriver::NewEmpty, "None");
cls_BinMXCAFDoc_MaterialDriver.def("Paste", (Standard_Boolean (BinMXCAFDoc_MaterialDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const) &BinMXCAFDoc_MaterialDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
cls_BinMXCAFDoc_MaterialDriver.def("Paste", (void (BinMXCAFDoc_MaterialDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const) &BinMXCAFDoc_MaterialDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
cls_BinMXCAFDoc_MaterialDriver.def_static("get_type_name_", (const char * (*)()) &BinMXCAFDoc_MaterialDriver::get_type_name, "None");
cls_BinMXCAFDoc_MaterialDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMXCAFDoc_MaterialDriver::get_type_descriptor, "None");
cls_BinMXCAFDoc_MaterialDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMXCAFDoc_MaterialDriver::*)() const) &BinMXCAFDoc_MaterialDriver::DynamicType, "None");

// CLASS: BINMXCAFDOC_MATERIALTOOLDRIVER
py::class_<BinMXCAFDoc_MaterialToolDriver, opencascade::handle<BinMXCAFDoc_MaterialToolDriver>, BinMDF_ADriver> cls_BinMXCAFDoc_MaterialToolDriver(mod, "BinMXCAFDoc_MaterialToolDriver", "None");

// Constructors
cls_BinMXCAFDoc_MaterialToolDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMsgDriver"));

// Methods
cls_BinMXCAFDoc_MaterialToolDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMXCAFDoc_MaterialToolDriver::*)() const) &BinMXCAFDoc_MaterialToolDriver::NewEmpty, "None");
cls_BinMXCAFDoc_MaterialToolDriver.def("Paste", (Standard_Boolean (BinMXCAFDoc_MaterialToolDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const) &BinMXCAFDoc_MaterialToolDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
cls_BinMXCAFDoc_MaterialToolDriver.def("Paste", (void (BinMXCAFDoc_MaterialToolDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const) &BinMXCAFDoc_MaterialToolDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
cls_BinMXCAFDoc_MaterialToolDriver.def_static("get_type_name_", (const char * (*)()) &BinMXCAFDoc_MaterialToolDriver::get_type_name, "None");
cls_BinMXCAFDoc_MaterialToolDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMXCAFDoc_MaterialToolDriver::get_type_descriptor, "None");
cls_BinMXCAFDoc_MaterialToolDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMXCAFDoc_MaterialToolDriver::*)() const) &BinMXCAFDoc_MaterialToolDriver::DynamicType, "None");

// CLASS: BINMXCAFDOC_NOTEDRIVER
py::class_<BinMXCAFDoc_NoteDriver, opencascade::handle<BinMXCAFDoc_NoteDriver>, BinMDF_ADriver> cls_BinMXCAFDoc_NoteDriver(mod, "BinMXCAFDoc_NoteDriver", "None");

// Methods
cls_BinMXCAFDoc_NoteDriver.def("Paste", (Standard_Boolean (BinMXCAFDoc_NoteDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const) &BinMXCAFDoc_NoteDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
cls_BinMXCAFDoc_NoteDriver.def("Paste", (void (BinMXCAFDoc_NoteDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const) &BinMXCAFDoc_NoteDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
cls_BinMXCAFDoc_NoteDriver.def_static("get_type_name_", (const char * (*)()) &BinMXCAFDoc_NoteDriver::get_type_name, "None");
cls_BinMXCAFDoc_NoteDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMXCAFDoc_NoteDriver::get_type_descriptor, "None");
cls_BinMXCAFDoc_NoteDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMXCAFDoc_NoteDriver::*)() const) &BinMXCAFDoc_NoteDriver::DynamicType, "None");

// CLASS: BINMXCAFDOC_NOTECOMMENTDRIVER
py::class_<BinMXCAFDoc_NoteCommentDriver, opencascade::handle<BinMXCAFDoc_NoteCommentDriver>, BinMXCAFDoc_NoteDriver> cls_BinMXCAFDoc_NoteCommentDriver(mod, "BinMXCAFDoc_NoteCommentDriver", "None");

// Constructors
cls_BinMXCAFDoc_NoteCommentDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMsgDriver"));

// Methods
cls_BinMXCAFDoc_NoteCommentDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMXCAFDoc_NoteCommentDriver::*)() const) &BinMXCAFDoc_NoteCommentDriver::NewEmpty, "None");
cls_BinMXCAFDoc_NoteCommentDriver.def("Paste", (Standard_Boolean (BinMXCAFDoc_NoteCommentDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const) &BinMXCAFDoc_NoteCommentDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
cls_BinMXCAFDoc_NoteCommentDriver.def("Paste", (void (BinMXCAFDoc_NoteCommentDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const) &BinMXCAFDoc_NoteCommentDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
cls_BinMXCAFDoc_NoteCommentDriver.def_static("get_type_name_", (const char * (*)()) &BinMXCAFDoc_NoteCommentDriver::get_type_name, "None");
cls_BinMXCAFDoc_NoteCommentDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMXCAFDoc_NoteCommentDriver::get_type_descriptor, "None");
cls_BinMXCAFDoc_NoteCommentDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMXCAFDoc_NoteCommentDriver::*)() const) &BinMXCAFDoc_NoteCommentDriver::DynamicType, "None");

// CLASS: BINMXCAFDOC_NOTEBALLOONDRIVER
py::class_<BinMXCAFDoc_NoteBalloonDriver, opencascade::handle<BinMXCAFDoc_NoteBalloonDriver>, BinMXCAFDoc_NoteCommentDriver> cls_BinMXCAFDoc_NoteBalloonDriver(mod, "BinMXCAFDoc_NoteBalloonDriver", "None");

// Constructors
cls_BinMXCAFDoc_NoteBalloonDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMsgDriver"));

// Methods
cls_BinMXCAFDoc_NoteBalloonDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMXCAFDoc_NoteBalloonDriver::*)() const) &BinMXCAFDoc_NoteBalloonDriver::NewEmpty, "None");
cls_BinMXCAFDoc_NoteBalloonDriver.def_static("get_type_name_", (const char * (*)()) &BinMXCAFDoc_NoteBalloonDriver::get_type_name, "None");
cls_BinMXCAFDoc_NoteBalloonDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMXCAFDoc_NoteBalloonDriver::get_type_descriptor, "None");
cls_BinMXCAFDoc_NoteBalloonDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMXCAFDoc_NoteBalloonDriver::*)() const) &BinMXCAFDoc_NoteBalloonDriver::DynamicType, "None");

// CLASS: BINMXCAFDOC_NOTEBINDATADRIVER
py::class_<BinMXCAFDoc_NoteBinDataDriver, opencascade::handle<BinMXCAFDoc_NoteBinDataDriver>, BinMXCAFDoc_NoteDriver> cls_BinMXCAFDoc_NoteBinDataDriver(mod, "BinMXCAFDoc_NoteBinDataDriver", "None");

// Constructors
cls_BinMXCAFDoc_NoteBinDataDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMsgDriver"));

// Methods
cls_BinMXCAFDoc_NoteBinDataDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMXCAFDoc_NoteBinDataDriver::*)() const) &BinMXCAFDoc_NoteBinDataDriver::NewEmpty, "None");
cls_BinMXCAFDoc_NoteBinDataDriver.def("Paste", (Standard_Boolean (BinMXCAFDoc_NoteBinDataDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const) &BinMXCAFDoc_NoteBinDataDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
cls_BinMXCAFDoc_NoteBinDataDriver.def("Paste", (void (BinMXCAFDoc_NoteBinDataDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const) &BinMXCAFDoc_NoteBinDataDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
cls_BinMXCAFDoc_NoteBinDataDriver.def_static("get_type_name_", (const char * (*)()) &BinMXCAFDoc_NoteBinDataDriver::get_type_name, "None");
cls_BinMXCAFDoc_NoteBinDataDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMXCAFDoc_NoteBinDataDriver::get_type_descriptor, "None");
cls_BinMXCAFDoc_NoteBinDataDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMXCAFDoc_NoteBinDataDriver::*)() const) &BinMXCAFDoc_NoteBinDataDriver::DynamicType, "None");

// CLASS: BINMXCAFDOC_NOTESTOOLDRIVER
py::class_<BinMXCAFDoc_NotesToolDriver, opencascade::handle<BinMXCAFDoc_NotesToolDriver>, BinMDF_ADriver> cls_BinMXCAFDoc_NotesToolDriver(mod, "BinMXCAFDoc_NotesToolDriver", "None");

// Constructors
cls_BinMXCAFDoc_NotesToolDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMsgDriver"));

// Methods
cls_BinMXCAFDoc_NotesToolDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMXCAFDoc_NotesToolDriver::*)() const) &BinMXCAFDoc_NotesToolDriver::NewEmpty, "None");
cls_BinMXCAFDoc_NotesToolDriver.def("Paste", (Standard_Boolean (BinMXCAFDoc_NotesToolDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const) &BinMXCAFDoc_NotesToolDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
cls_BinMXCAFDoc_NotesToolDriver.def("Paste", (void (BinMXCAFDoc_NotesToolDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const) &BinMXCAFDoc_NotesToolDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
cls_BinMXCAFDoc_NotesToolDriver.def_static("get_type_name_", (const char * (*)()) &BinMXCAFDoc_NotesToolDriver::get_type_name, "None");
cls_BinMXCAFDoc_NotesToolDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMXCAFDoc_NotesToolDriver::get_type_descriptor, "None");
cls_BinMXCAFDoc_NotesToolDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMXCAFDoc_NotesToolDriver::*)() const) &BinMXCAFDoc_NotesToolDriver::DynamicType, "None");

// CLASS: BINMXCAFDOC_SHAPETOOLDRIVER
py::class_<BinMXCAFDoc_ShapeToolDriver, opencascade::handle<BinMXCAFDoc_ShapeToolDriver>, BinMDF_ADriver> cls_BinMXCAFDoc_ShapeToolDriver(mod, "BinMXCAFDoc_ShapeToolDriver", "None");

// Constructors
cls_BinMXCAFDoc_ShapeToolDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMsgDriver"));

// Methods
cls_BinMXCAFDoc_ShapeToolDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMXCAFDoc_ShapeToolDriver::*)() const) &BinMXCAFDoc_ShapeToolDriver::NewEmpty, "None");
cls_BinMXCAFDoc_ShapeToolDriver.def("Paste", (Standard_Boolean (BinMXCAFDoc_ShapeToolDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const) &BinMXCAFDoc_ShapeToolDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
cls_BinMXCAFDoc_ShapeToolDriver.def("Paste", (void (BinMXCAFDoc_ShapeToolDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const) &BinMXCAFDoc_ShapeToolDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
cls_BinMXCAFDoc_ShapeToolDriver.def_static("get_type_name_", (const char * (*)()) &BinMXCAFDoc_ShapeToolDriver::get_type_name, "None");
cls_BinMXCAFDoc_ShapeToolDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMXCAFDoc_ShapeToolDriver::get_type_descriptor, "None");
cls_BinMXCAFDoc_ShapeToolDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMXCAFDoc_ShapeToolDriver::*)() const) &BinMXCAFDoc_ShapeToolDriver::DynamicType, "None");

// CLASS: BINMXCAFDOC_VIEWDRIVER
py::class_<BinMXCAFDoc_ViewDriver, opencascade::handle<BinMXCAFDoc_ViewDriver>, BinMDF_ADriver> cls_BinMXCAFDoc_ViewDriver(mod, "BinMXCAFDoc_ViewDriver", "None");

// Constructors
cls_BinMXCAFDoc_ViewDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMsgDriver"));

// Methods
cls_BinMXCAFDoc_ViewDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMXCAFDoc_ViewDriver::*)() const) &BinMXCAFDoc_ViewDriver::NewEmpty, "None");
cls_BinMXCAFDoc_ViewDriver.def("Paste", (Standard_Boolean (BinMXCAFDoc_ViewDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const) &BinMXCAFDoc_ViewDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
cls_BinMXCAFDoc_ViewDriver.def("Paste", (void (BinMXCAFDoc_ViewDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const) &BinMXCAFDoc_ViewDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
cls_BinMXCAFDoc_ViewDriver.def_static("get_type_name_", (const char * (*)()) &BinMXCAFDoc_ViewDriver::get_type_name, "None");
cls_BinMXCAFDoc_ViewDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMXCAFDoc_ViewDriver::get_type_descriptor, "None");
cls_BinMXCAFDoc_ViewDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMXCAFDoc_ViewDriver::*)() const) &BinMXCAFDoc_ViewDriver::DynamicType, "None");

// CLASS: BINMXCAFDOC_VIEWTOOLDRIVER
py::class_<BinMXCAFDoc_ViewToolDriver, opencascade::handle<BinMXCAFDoc_ViewToolDriver>, BinMDF_ADriver> cls_BinMXCAFDoc_ViewToolDriver(mod, "BinMXCAFDoc_ViewToolDriver", "None");

// Constructors
cls_BinMXCAFDoc_ViewToolDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMsgDriver"));

// Methods
cls_BinMXCAFDoc_ViewToolDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMXCAFDoc_ViewToolDriver::*)() const) &BinMXCAFDoc_ViewToolDriver::NewEmpty, "None");
cls_BinMXCAFDoc_ViewToolDriver.def("Paste", (Standard_Boolean (BinMXCAFDoc_ViewToolDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const) &BinMXCAFDoc_ViewToolDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
cls_BinMXCAFDoc_ViewToolDriver.def("Paste", (void (BinMXCAFDoc_ViewToolDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const) &BinMXCAFDoc_ViewToolDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
cls_BinMXCAFDoc_ViewToolDriver.def_static("get_type_name_", (const char * (*)()) &BinMXCAFDoc_ViewToolDriver::get_type_name, "None");
cls_BinMXCAFDoc_ViewToolDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMXCAFDoc_ViewToolDriver::get_type_descriptor, "None");
cls_BinMXCAFDoc_ViewToolDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMXCAFDoc_ViewToolDriver::*)() const) &BinMXCAFDoc_ViewToolDriver::DynamicType, "None");

// CLASS: BINMXCAFDOC_VOLUMEDRIVER
py::class_<BinMXCAFDoc_VolumeDriver, opencascade::handle<BinMXCAFDoc_VolumeDriver>, BinMDF_ADriver> cls_BinMXCAFDoc_VolumeDriver(mod, "BinMXCAFDoc_VolumeDriver", "None");

// Constructors
cls_BinMXCAFDoc_VolumeDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMsgDriver"));

// Methods
cls_BinMXCAFDoc_VolumeDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMXCAFDoc_VolumeDriver::*)() const) &BinMXCAFDoc_VolumeDriver::NewEmpty, "None");
cls_BinMXCAFDoc_VolumeDriver.def("Paste", (Standard_Boolean (BinMXCAFDoc_VolumeDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const) &BinMXCAFDoc_VolumeDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
cls_BinMXCAFDoc_VolumeDriver.def("Paste", (void (BinMXCAFDoc_VolumeDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const) &BinMXCAFDoc_VolumeDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
cls_BinMXCAFDoc_VolumeDriver.def_static("get_type_name_", (const char * (*)()) &BinMXCAFDoc_VolumeDriver::get_type_name, "None");
cls_BinMXCAFDoc_VolumeDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMXCAFDoc_VolumeDriver::get_type_descriptor, "None");
cls_BinMXCAFDoc_VolumeDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMXCAFDoc_VolumeDriver::*)() const) &BinMXCAFDoc_VolumeDriver::DynamicType, "None");


}
