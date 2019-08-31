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
#include <TopTools_LocationSet.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <XmlMDF_ADriverTable.hxx>
#include <Message_Messenger.hxx>
#include <XmlMXCAFDoc_AreaDriver.hxx>
#include <XmlMXCAFDoc_CentroidDriver.hxx>
#include <XmlMXCAFDoc_ColorDriver.hxx>
#include <XmlMXCAFDoc_GraphNodeDriver.hxx>
#include <XmlMXCAFDoc_LocationDriver.hxx>
#include <XmlMXCAFDoc_VolumeDriver.hxx>
#include <XmlMXCAFDoc_DatumDriver.hxx>
#include <XmlMXCAFDoc_DimTolDriver.hxx>
#include <XmlMXCAFDoc_MaterialDriver.hxx>
#include <XmlMXCAFDoc_ClippingPlaneToolDriver.hxx>
#include <XmlMXCAFDoc_ColorToolDriver.hxx>
#include <XmlMXCAFDoc_DocumentToolDriver.hxx>
#include <XmlMXCAFDoc_LayerToolDriver.hxx>
#include <XmlMXCAFDoc_ShapeToolDriver.hxx>
#include <XmlMXCAFDoc_DimTolToolDriver.hxx>
#include <XmlMXCAFDoc_MaterialToolDriver.hxx>
#include <XmlMXCAFDoc_ViewToolDriver.hxx>
#include <XmlMXCAFDoc.hxx>
#include <XmlMDF_ADriver.hxx>
#include <TDF_Attribute.hxx>
#include <Standard_TypeDef.hxx>
#include <XmlObjMgt_Persistent.hxx>
#include <XmlObjMgt_RRelocationTable.hxx>
#include <XmlObjMgt_SRelocationTable.hxx>
#include <Standard_Type.hxx>
#include <XmlMXCAFDoc_AssemblyItemRefDriver.hxx>
#include <TopLoc_Location.hxx>
#include <XmlObjMgt_Element.hxx>
#include <TopTools_LocationSetPtr.hxx>
#include <XmlMXCAFDoc_NoteDriver.hxx>
#include <XmlMXCAFDoc_NoteCommentDriver.hxx>
#include <XmlMXCAFDoc_NoteBalloonDriver.hxx>
#include <XmlMXCAFDoc_NoteBinDataDriver.hxx>
#include <XmlMXCAFDoc_NotesToolDriver.hxx>

PYBIND11_MODULE(XmlMXCAFDoc, mod) {

py::module::import("OCCT.TopTools");
py::module::import("OCCT.Standard");
py::module::import("OCCT.XmlMDF");
py::module::import("OCCT.Message");
py::module::import("OCCT.TDF");
py::module::import("OCCT.XmlObjMgt");
py::module::import("OCCT.TopLoc");

// CLASS: XMLMXCAFDOC
py::class_<XmlMXCAFDoc> cls_XmlMXCAFDoc(mod, "XmlMXCAFDoc", "Storage and Retrieval drivers for modelling attributes. Transient attributes are defined in package XCAFDoc");

// Methods
// cls_XmlMXCAFDoc.def_static("operator new_", (void * (*)(size_t)) &XmlMXCAFDoc::operator new, "None", py::arg("theSize"));
// cls_XmlMXCAFDoc.def_static("operator delete_", (void (*)(void *)) &XmlMXCAFDoc::operator delete, "None", py::arg("theAddress"));
// cls_XmlMXCAFDoc.def_static("operator new[]_", (void * (*)(size_t)) &XmlMXCAFDoc::operator new[], "None", py::arg("theSize"));
// cls_XmlMXCAFDoc.def_static("operator delete[]_", (void (*)(void *)) &XmlMXCAFDoc::operator delete[], "None", py::arg("theAddress"));
// cls_XmlMXCAFDoc.def_static("operator new_", (void * (*)(size_t, void *)) &XmlMXCAFDoc::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_XmlMXCAFDoc.def_static("operator delete_", (void (*)(void *, void *)) &XmlMXCAFDoc::operator delete, "None", py::arg(""), py::arg(""));
cls_XmlMXCAFDoc.def_static("AddDrivers_", (void (*)(const opencascade::handle<XmlMDF_ADriverTable> &, const opencascade::handle<Message_Messenger> &)) &XmlMXCAFDoc::AddDrivers, "Adds the attribute drivers to <aDriverTable>.", py::arg("aDriverTable"), py::arg("anMsgDrv"));

// CLASS: XMLMXCAFDOC_AREADRIVER
py::class_<XmlMXCAFDoc_AreaDriver, opencascade::handle<XmlMXCAFDoc_AreaDriver>, XmlMDF_ADriver> cls_XmlMXCAFDoc_AreaDriver(mod, "XmlMXCAFDoc_AreaDriver", "Attribute Driver.");

// Constructors
cls_XmlMXCAFDoc_AreaDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Methods
cls_XmlMXCAFDoc_AreaDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XmlMXCAFDoc_AreaDriver::*)() const) &XmlMXCAFDoc_AreaDriver::NewEmpty, "None");
cls_XmlMXCAFDoc_AreaDriver.def("Paste", (Standard_Boolean (XmlMXCAFDoc_AreaDriver::*)(const XmlObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, XmlObjMgt_RRelocationTable &) const) &XmlMXCAFDoc_AreaDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMXCAFDoc_AreaDriver.def("Paste", (void (XmlMXCAFDoc_AreaDriver::*)(const opencascade::handle<TDF_Attribute> &, XmlObjMgt_Persistent &, XmlObjMgt_SRelocationTable &) const) &XmlMXCAFDoc_AreaDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMXCAFDoc_AreaDriver.def_static("get_type_name_", (const char * (*)()) &XmlMXCAFDoc_AreaDriver::get_type_name, "None");
cls_XmlMXCAFDoc_AreaDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlMXCAFDoc_AreaDriver::get_type_descriptor, "None");
cls_XmlMXCAFDoc_AreaDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlMXCAFDoc_AreaDriver::*)() const) &XmlMXCAFDoc_AreaDriver::DynamicType, "None");

// CLASS: XMLMXCAFDOC_ASSEMBLYITEMREFDRIVER
py::class_<XmlMXCAFDoc_AssemblyItemRefDriver, opencascade::handle<XmlMXCAFDoc_AssemblyItemRefDriver>, XmlMDF_ADriver> cls_XmlMXCAFDoc_AssemblyItemRefDriver(mod, "XmlMXCAFDoc_AssemblyItemRefDriver", "Attribute Driver.");

// Constructors
cls_XmlMXCAFDoc_AssemblyItemRefDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Methods
cls_XmlMXCAFDoc_AssemblyItemRefDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XmlMXCAFDoc_AssemblyItemRefDriver::*)() const) &XmlMXCAFDoc_AssemblyItemRefDriver::NewEmpty, "None");
cls_XmlMXCAFDoc_AssemblyItemRefDriver.def("Paste", (Standard_Boolean (XmlMXCAFDoc_AssemblyItemRefDriver::*)(const XmlObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, XmlObjMgt_RRelocationTable &) const) &XmlMXCAFDoc_AssemblyItemRefDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
cls_XmlMXCAFDoc_AssemblyItemRefDriver.def("Paste", (void (XmlMXCAFDoc_AssemblyItemRefDriver::*)(const opencascade::handle<TDF_Attribute> &, XmlObjMgt_Persistent &, XmlObjMgt_SRelocationTable &) const) &XmlMXCAFDoc_AssemblyItemRefDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
cls_XmlMXCAFDoc_AssemblyItemRefDriver.def_static("get_type_name_", (const char * (*)()) &XmlMXCAFDoc_AssemblyItemRefDriver::get_type_name, "None");
cls_XmlMXCAFDoc_AssemblyItemRefDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlMXCAFDoc_AssemblyItemRefDriver::get_type_descriptor, "None");
cls_XmlMXCAFDoc_AssemblyItemRefDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlMXCAFDoc_AssemblyItemRefDriver::*)() const) &XmlMXCAFDoc_AssemblyItemRefDriver::DynamicType, "None");

// CLASS: XMLMXCAFDOC_CENTROIDDRIVER
py::class_<XmlMXCAFDoc_CentroidDriver, opencascade::handle<XmlMXCAFDoc_CentroidDriver>, XmlMDF_ADriver> cls_XmlMXCAFDoc_CentroidDriver(mod, "XmlMXCAFDoc_CentroidDriver", "Attribute Driver.");

// Constructors
cls_XmlMXCAFDoc_CentroidDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Methods
cls_XmlMXCAFDoc_CentroidDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XmlMXCAFDoc_CentroidDriver::*)() const) &XmlMXCAFDoc_CentroidDriver::NewEmpty, "None");
cls_XmlMXCAFDoc_CentroidDriver.def("Paste", (Standard_Boolean (XmlMXCAFDoc_CentroidDriver::*)(const XmlObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, XmlObjMgt_RRelocationTable &) const) &XmlMXCAFDoc_CentroidDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMXCAFDoc_CentroidDriver.def("Paste", (void (XmlMXCAFDoc_CentroidDriver::*)(const opencascade::handle<TDF_Attribute> &, XmlObjMgt_Persistent &, XmlObjMgt_SRelocationTable &) const) &XmlMXCAFDoc_CentroidDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMXCAFDoc_CentroidDriver.def_static("get_type_name_", (const char * (*)()) &XmlMXCAFDoc_CentroidDriver::get_type_name, "None");
cls_XmlMXCAFDoc_CentroidDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlMXCAFDoc_CentroidDriver::get_type_descriptor, "None");
cls_XmlMXCAFDoc_CentroidDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlMXCAFDoc_CentroidDriver::*)() const) &XmlMXCAFDoc_CentroidDriver::DynamicType, "None");

// CLASS: XMLMXCAFDOC_CLIPPINGPLANETOOLDRIVER
py::class_<XmlMXCAFDoc_ClippingPlaneToolDriver, opencascade::handle<XmlMXCAFDoc_ClippingPlaneToolDriver>, XmlMDF_ADriver> cls_XmlMXCAFDoc_ClippingPlaneToolDriver(mod, "XmlMXCAFDoc_ClippingPlaneToolDriver", "Attribute Driver.");

// Constructors
cls_XmlMXCAFDoc_ClippingPlaneToolDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMsgDriver"));

// Methods
cls_XmlMXCAFDoc_ClippingPlaneToolDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XmlMXCAFDoc_ClippingPlaneToolDriver::*)() const) &XmlMXCAFDoc_ClippingPlaneToolDriver::NewEmpty, "None");
cls_XmlMXCAFDoc_ClippingPlaneToolDriver.def("Paste", (Standard_Boolean (XmlMXCAFDoc_ClippingPlaneToolDriver::*)(const XmlObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, XmlObjMgt_RRelocationTable &) const) &XmlMXCAFDoc_ClippingPlaneToolDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
cls_XmlMXCAFDoc_ClippingPlaneToolDriver.def("Paste", (void (XmlMXCAFDoc_ClippingPlaneToolDriver::*)(const opencascade::handle<TDF_Attribute> &, XmlObjMgt_Persistent &, XmlObjMgt_SRelocationTable &) const) &XmlMXCAFDoc_ClippingPlaneToolDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
cls_XmlMXCAFDoc_ClippingPlaneToolDriver.def_static("get_type_name_", (const char * (*)()) &XmlMXCAFDoc_ClippingPlaneToolDriver::get_type_name, "None");
cls_XmlMXCAFDoc_ClippingPlaneToolDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlMXCAFDoc_ClippingPlaneToolDriver::get_type_descriptor, "None");
cls_XmlMXCAFDoc_ClippingPlaneToolDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlMXCAFDoc_ClippingPlaneToolDriver::*)() const) &XmlMXCAFDoc_ClippingPlaneToolDriver::DynamicType, "None");

// CLASS: XMLMXCAFDOC_COLORDRIVER
py::class_<XmlMXCAFDoc_ColorDriver, opencascade::handle<XmlMXCAFDoc_ColorDriver>, XmlMDF_ADriver> cls_XmlMXCAFDoc_ColorDriver(mod, "XmlMXCAFDoc_ColorDriver", "Attribute Driver.");

// Constructors
cls_XmlMXCAFDoc_ColorDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Methods
cls_XmlMXCAFDoc_ColorDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XmlMXCAFDoc_ColorDriver::*)() const) &XmlMXCAFDoc_ColorDriver::NewEmpty, "None");
cls_XmlMXCAFDoc_ColorDriver.def("Paste", (Standard_Boolean (XmlMXCAFDoc_ColorDriver::*)(const XmlObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, XmlObjMgt_RRelocationTable &) const) &XmlMXCAFDoc_ColorDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMXCAFDoc_ColorDriver.def("Paste", (void (XmlMXCAFDoc_ColorDriver::*)(const opencascade::handle<TDF_Attribute> &, XmlObjMgt_Persistent &, XmlObjMgt_SRelocationTable &) const) &XmlMXCAFDoc_ColorDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMXCAFDoc_ColorDriver.def_static("get_type_name_", (const char * (*)()) &XmlMXCAFDoc_ColorDriver::get_type_name, "None");
cls_XmlMXCAFDoc_ColorDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlMXCAFDoc_ColorDriver::get_type_descriptor, "None");
cls_XmlMXCAFDoc_ColorDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlMXCAFDoc_ColorDriver::*)() const) &XmlMXCAFDoc_ColorDriver::DynamicType, "None");

// CLASS: XMLMXCAFDOC_COLORTOOLDRIVER
py::class_<XmlMXCAFDoc_ColorToolDriver, opencascade::handle<XmlMXCAFDoc_ColorToolDriver>, XmlMDF_ADriver> cls_XmlMXCAFDoc_ColorToolDriver(mod, "XmlMXCAFDoc_ColorToolDriver", "Attribute Driver.");

// Constructors
cls_XmlMXCAFDoc_ColorToolDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMsgDriver"));

// Methods
cls_XmlMXCAFDoc_ColorToolDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XmlMXCAFDoc_ColorToolDriver::*)() const) &XmlMXCAFDoc_ColorToolDriver::NewEmpty, "None");
cls_XmlMXCAFDoc_ColorToolDriver.def("Paste", (Standard_Boolean (XmlMXCAFDoc_ColorToolDriver::*)(const XmlObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, XmlObjMgt_RRelocationTable &) const) &XmlMXCAFDoc_ColorToolDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
cls_XmlMXCAFDoc_ColorToolDriver.def("Paste", (void (XmlMXCAFDoc_ColorToolDriver::*)(const opencascade::handle<TDF_Attribute> &, XmlObjMgt_Persistent &, XmlObjMgt_SRelocationTable &) const) &XmlMXCAFDoc_ColorToolDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
cls_XmlMXCAFDoc_ColorToolDriver.def_static("get_type_name_", (const char * (*)()) &XmlMXCAFDoc_ColorToolDriver::get_type_name, "None");
cls_XmlMXCAFDoc_ColorToolDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlMXCAFDoc_ColorToolDriver::get_type_descriptor, "None");
cls_XmlMXCAFDoc_ColorToolDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlMXCAFDoc_ColorToolDriver::*)() const) &XmlMXCAFDoc_ColorToolDriver::DynamicType, "None");

// CLASS: XMLMXCAFDOC_DATUMDRIVER
py::class_<XmlMXCAFDoc_DatumDriver, opencascade::handle<XmlMXCAFDoc_DatumDriver>, XmlMDF_ADriver> cls_XmlMXCAFDoc_DatumDriver(mod, "XmlMXCAFDoc_DatumDriver", "Attribute Driver.");

// Constructors
cls_XmlMXCAFDoc_DatumDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Methods
cls_XmlMXCAFDoc_DatumDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XmlMXCAFDoc_DatumDriver::*)() const) &XmlMXCAFDoc_DatumDriver::NewEmpty, "None");
cls_XmlMXCAFDoc_DatumDriver.def("Paste", (Standard_Boolean (XmlMXCAFDoc_DatumDriver::*)(const XmlObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, XmlObjMgt_RRelocationTable &) const) &XmlMXCAFDoc_DatumDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMXCAFDoc_DatumDriver.def("Paste", (void (XmlMXCAFDoc_DatumDriver::*)(const opencascade::handle<TDF_Attribute> &, XmlObjMgt_Persistent &, XmlObjMgt_SRelocationTable &) const) &XmlMXCAFDoc_DatumDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMXCAFDoc_DatumDriver.def_static("get_type_name_", (const char * (*)()) &XmlMXCAFDoc_DatumDriver::get_type_name, "None");
cls_XmlMXCAFDoc_DatumDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlMXCAFDoc_DatumDriver::get_type_descriptor, "None");
cls_XmlMXCAFDoc_DatumDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlMXCAFDoc_DatumDriver::*)() const) &XmlMXCAFDoc_DatumDriver::DynamicType, "None");

// CLASS: XMLMXCAFDOC_DIMTOLDRIVER
py::class_<XmlMXCAFDoc_DimTolDriver, opencascade::handle<XmlMXCAFDoc_DimTolDriver>, XmlMDF_ADriver> cls_XmlMXCAFDoc_DimTolDriver(mod, "XmlMXCAFDoc_DimTolDriver", "Attribute Driver.");

// Constructors
cls_XmlMXCAFDoc_DimTolDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Methods
cls_XmlMXCAFDoc_DimTolDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XmlMXCAFDoc_DimTolDriver::*)() const) &XmlMXCAFDoc_DimTolDriver::NewEmpty, "None");
cls_XmlMXCAFDoc_DimTolDriver.def("Paste", (Standard_Boolean (XmlMXCAFDoc_DimTolDriver::*)(const XmlObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, XmlObjMgt_RRelocationTable &) const) &XmlMXCAFDoc_DimTolDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMXCAFDoc_DimTolDriver.def("Paste", (void (XmlMXCAFDoc_DimTolDriver::*)(const opencascade::handle<TDF_Attribute> &, XmlObjMgt_Persistent &, XmlObjMgt_SRelocationTable &) const) &XmlMXCAFDoc_DimTolDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMXCAFDoc_DimTolDriver.def_static("get_type_name_", (const char * (*)()) &XmlMXCAFDoc_DimTolDriver::get_type_name, "None");
cls_XmlMXCAFDoc_DimTolDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlMXCAFDoc_DimTolDriver::get_type_descriptor, "None");
cls_XmlMXCAFDoc_DimTolDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlMXCAFDoc_DimTolDriver::*)() const) &XmlMXCAFDoc_DimTolDriver::DynamicType, "None");

// CLASS: XMLMXCAFDOC_DIMTOLTOOLDRIVER
py::class_<XmlMXCAFDoc_DimTolToolDriver, opencascade::handle<XmlMXCAFDoc_DimTolToolDriver>, XmlMDF_ADriver> cls_XmlMXCAFDoc_DimTolToolDriver(mod, "XmlMXCAFDoc_DimTolToolDriver", "Attribute Driver.");

// Constructors
cls_XmlMXCAFDoc_DimTolToolDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMsgDriver"));

// Methods
cls_XmlMXCAFDoc_DimTolToolDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XmlMXCAFDoc_DimTolToolDriver::*)() const) &XmlMXCAFDoc_DimTolToolDriver::NewEmpty, "None");
cls_XmlMXCAFDoc_DimTolToolDriver.def("Paste", (Standard_Boolean (XmlMXCAFDoc_DimTolToolDriver::*)(const XmlObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, XmlObjMgt_RRelocationTable &) const) &XmlMXCAFDoc_DimTolToolDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
cls_XmlMXCAFDoc_DimTolToolDriver.def("Paste", (void (XmlMXCAFDoc_DimTolToolDriver::*)(const opencascade::handle<TDF_Attribute> &, XmlObjMgt_Persistent &, XmlObjMgt_SRelocationTable &) const) &XmlMXCAFDoc_DimTolToolDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
cls_XmlMXCAFDoc_DimTolToolDriver.def_static("get_type_name_", (const char * (*)()) &XmlMXCAFDoc_DimTolToolDriver::get_type_name, "None");
cls_XmlMXCAFDoc_DimTolToolDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlMXCAFDoc_DimTolToolDriver::get_type_descriptor, "None");
cls_XmlMXCAFDoc_DimTolToolDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlMXCAFDoc_DimTolToolDriver::*)() const) &XmlMXCAFDoc_DimTolToolDriver::DynamicType, "None");

// CLASS: XMLMXCAFDOC_DOCUMENTTOOLDRIVER
py::class_<XmlMXCAFDoc_DocumentToolDriver, opencascade::handle<XmlMXCAFDoc_DocumentToolDriver>, XmlMDF_ADriver> cls_XmlMXCAFDoc_DocumentToolDriver(mod, "XmlMXCAFDoc_DocumentToolDriver", "Attribute Driver.");

// Constructors
cls_XmlMXCAFDoc_DocumentToolDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMsgDriver"));

// Methods
cls_XmlMXCAFDoc_DocumentToolDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XmlMXCAFDoc_DocumentToolDriver::*)() const) &XmlMXCAFDoc_DocumentToolDriver::NewEmpty, "None");
cls_XmlMXCAFDoc_DocumentToolDriver.def("Paste", (Standard_Boolean (XmlMXCAFDoc_DocumentToolDriver::*)(const XmlObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, XmlObjMgt_RRelocationTable &) const) &XmlMXCAFDoc_DocumentToolDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
cls_XmlMXCAFDoc_DocumentToolDriver.def("Paste", (void (XmlMXCAFDoc_DocumentToolDriver::*)(const opencascade::handle<TDF_Attribute> &, XmlObjMgt_Persistent &, XmlObjMgt_SRelocationTable &) const) &XmlMXCAFDoc_DocumentToolDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
cls_XmlMXCAFDoc_DocumentToolDriver.def_static("get_type_name_", (const char * (*)()) &XmlMXCAFDoc_DocumentToolDriver::get_type_name, "None");
cls_XmlMXCAFDoc_DocumentToolDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlMXCAFDoc_DocumentToolDriver::get_type_descriptor, "None");
cls_XmlMXCAFDoc_DocumentToolDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlMXCAFDoc_DocumentToolDriver::*)() const) &XmlMXCAFDoc_DocumentToolDriver::DynamicType, "None");

// CLASS: XMLMXCAFDOC_GRAPHNODEDRIVER
py::class_<XmlMXCAFDoc_GraphNodeDriver, opencascade::handle<XmlMXCAFDoc_GraphNodeDriver>, XmlMDF_ADriver> cls_XmlMXCAFDoc_GraphNodeDriver(mod, "XmlMXCAFDoc_GraphNodeDriver", "Attribute Driver.");

// Constructors
cls_XmlMXCAFDoc_GraphNodeDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Methods
cls_XmlMXCAFDoc_GraphNodeDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XmlMXCAFDoc_GraphNodeDriver::*)() const) &XmlMXCAFDoc_GraphNodeDriver::NewEmpty, "None");
cls_XmlMXCAFDoc_GraphNodeDriver.def("Paste", (Standard_Boolean (XmlMXCAFDoc_GraphNodeDriver::*)(const XmlObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, XmlObjMgt_RRelocationTable &) const) &XmlMXCAFDoc_GraphNodeDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMXCAFDoc_GraphNodeDriver.def("Paste", (void (XmlMXCAFDoc_GraphNodeDriver::*)(const opencascade::handle<TDF_Attribute> &, XmlObjMgt_Persistent &, XmlObjMgt_SRelocationTable &) const) &XmlMXCAFDoc_GraphNodeDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMXCAFDoc_GraphNodeDriver.def_static("get_type_name_", (const char * (*)()) &XmlMXCAFDoc_GraphNodeDriver::get_type_name, "None");
cls_XmlMXCAFDoc_GraphNodeDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlMXCAFDoc_GraphNodeDriver::get_type_descriptor, "None");
cls_XmlMXCAFDoc_GraphNodeDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlMXCAFDoc_GraphNodeDriver::*)() const) &XmlMXCAFDoc_GraphNodeDriver::DynamicType, "None");

// CLASS: XMLMXCAFDOC_LAYERTOOLDRIVER
py::class_<XmlMXCAFDoc_LayerToolDriver, opencascade::handle<XmlMXCAFDoc_LayerToolDriver>, XmlMDF_ADriver> cls_XmlMXCAFDoc_LayerToolDriver(mod, "XmlMXCAFDoc_LayerToolDriver", "Attribute Driver.");

// Constructors
cls_XmlMXCAFDoc_LayerToolDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMsgDriver"));

// Methods
cls_XmlMXCAFDoc_LayerToolDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XmlMXCAFDoc_LayerToolDriver::*)() const) &XmlMXCAFDoc_LayerToolDriver::NewEmpty, "None");
cls_XmlMXCAFDoc_LayerToolDriver.def("Paste", (Standard_Boolean (XmlMXCAFDoc_LayerToolDriver::*)(const XmlObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, XmlObjMgt_RRelocationTable &) const) &XmlMXCAFDoc_LayerToolDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
cls_XmlMXCAFDoc_LayerToolDriver.def("Paste", (void (XmlMXCAFDoc_LayerToolDriver::*)(const opencascade::handle<TDF_Attribute> &, XmlObjMgt_Persistent &, XmlObjMgt_SRelocationTable &) const) &XmlMXCAFDoc_LayerToolDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
cls_XmlMXCAFDoc_LayerToolDriver.def_static("get_type_name_", (const char * (*)()) &XmlMXCAFDoc_LayerToolDriver::get_type_name, "None");
cls_XmlMXCAFDoc_LayerToolDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlMXCAFDoc_LayerToolDriver::get_type_descriptor, "None");
cls_XmlMXCAFDoc_LayerToolDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlMXCAFDoc_LayerToolDriver::*)() const) &XmlMXCAFDoc_LayerToolDriver::DynamicType, "None");

// CLASS: XMLMXCAFDOC_LOCATIONDRIVER
py::class_<XmlMXCAFDoc_LocationDriver, opencascade::handle<XmlMXCAFDoc_LocationDriver>, XmlMDF_ADriver> cls_XmlMXCAFDoc_LocationDriver(mod, "XmlMXCAFDoc_LocationDriver", "Attribute Driver.");

// Constructors
cls_XmlMXCAFDoc_LocationDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Methods
cls_XmlMXCAFDoc_LocationDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XmlMXCAFDoc_LocationDriver::*)() const) &XmlMXCAFDoc_LocationDriver::NewEmpty, "None");
cls_XmlMXCAFDoc_LocationDriver.def("Paste", (Standard_Boolean (XmlMXCAFDoc_LocationDriver::*)(const XmlObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, XmlObjMgt_RRelocationTable &) const) &XmlMXCAFDoc_LocationDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMXCAFDoc_LocationDriver.def("Paste", (void (XmlMXCAFDoc_LocationDriver::*)(const opencascade::handle<TDF_Attribute> &, XmlObjMgt_Persistent &, XmlObjMgt_SRelocationTable &) const) &XmlMXCAFDoc_LocationDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMXCAFDoc_LocationDriver.def("Translate", (void (XmlMXCAFDoc_LocationDriver::*)(const TopLoc_Location &, XmlObjMgt_Element &, XmlObjMgt_SRelocationTable &) const) &XmlMXCAFDoc_LocationDriver::Translate, "Translate a non storable Location to a storable Location.", py::arg("theLoc"), py::arg("theParent"), py::arg("theMap"));
cls_XmlMXCAFDoc_LocationDriver.def("Translate", (Standard_Boolean (XmlMXCAFDoc_LocationDriver::*)(const XmlObjMgt_Element &, TopLoc_Location &, XmlObjMgt_RRelocationTable &) const) &XmlMXCAFDoc_LocationDriver::Translate, "Translate a storable Location to a non storable Location.", py::arg("theParent"), py::arg("theLoc"), py::arg("theMap"));
cls_XmlMXCAFDoc_LocationDriver.def("SetSharedLocations", (void (XmlMXCAFDoc_LocationDriver::*)(const TopTools_LocationSetPtr &)) &XmlMXCAFDoc_LocationDriver::SetSharedLocations, "None", py::arg("theLocations"));
cls_XmlMXCAFDoc_LocationDriver.def_static("get_type_name_", (const char * (*)()) &XmlMXCAFDoc_LocationDriver::get_type_name, "None");
cls_XmlMXCAFDoc_LocationDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlMXCAFDoc_LocationDriver::get_type_descriptor, "None");
cls_XmlMXCAFDoc_LocationDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlMXCAFDoc_LocationDriver::*)() const) &XmlMXCAFDoc_LocationDriver::DynamicType, "None");

// CLASS: XMLMXCAFDOC_MATERIALDRIVER
py::class_<XmlMXCAFDoc_MaterialDriver, opencascade::handle<XmlMXCAFDoc_MaterialDriver>, XmlMDF_ADriver> cls_XmlMXCAFDoc_MaterialDriver(mod, "XmlMXCAFDoc_MaterialDriver", "Attribute Driver.");

// Constructors
cls_XmlMXCAFDoc_MaterialDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Methods
cls_XmlMXCAFDoc_MaterialDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XmlMXCAFDoc_MaterialDriver::*)() const) &XmlMXCAFDoc_MaterialDriver::NewEmpty, "None");
cls_XmlMXCAFDoc_MaterialDriver.def("Paste", (Standard_Boolean (XmlMXCAFDoc_MaterialDriver::*)(const XmlObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, XmlObjMgt_RRelocationTable &) const) &XmlMXCAFDoc_MaterialDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMXCAFDoc_MaterialDriver.def("Paste", (void (XmlMXCAFDoc_MaterialDriver::*)(const opencascade::handle<TDF_Attribute> &, XmlObjMgt_Persistent &, XmlObjMgt_SRelocationTable &) const) &XmlMXCAFDoc_MaterialDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMXCAFDoc_MaterialDriver.def_static("get_type_name_", (const char * (*)()) &XmlMXCAFDoc_MaterialDriver::get_type_name, "None");
cls_XmlMXCAFDoc_MaterialDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlMXCAFDoc_MaterialDriver::get_type_descriptor, "None");
cls_XmlMXCAFDoc_MaterialDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlMXCAFDoc_MaterialDriver::*)() const) &XmlMXCAFDoc_MaterialDriver::DynamicType, "None");

// CLASS: XMLMXCAFDOC_MATERIALTOOLDRIVER
py::class_<XmlMXCAFDoc_MaterialToolDriver, opencascade::handle<XmlMXCAFDoc_MaterialToolDriver>, XmlMDF_ADriver> cls_XmlMXCAFDoc_MaterialToolDriver(mod, "XmlMXCAFDoc_MaterialToolDriver", "Attribute Driver.");

// Constructors
cls_XmlMXCAFDoc_MaterialToolDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMsgDriver"));

// Methods
cls_XmlMXCAFDoc_MaterialToolDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XmlMXCAFDoc_MaterialToolDriver::*)() const) &XmlMXCAFDoc_MaterialToolDriver::NewEmpty, "None");
cls_XmlMXCAFDoc_MaterialToolDriver.def("Paste", (Standard_Boolean (XmlMXCAFDoc_MaterialToolDriver::*)(const XmlObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, XmlObjMgt_RRelocationTable &) const) &XmlMXCAFDoc_MaterialToolDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
cls_XmlMXCAFDoc_MaterialToolDriver.def("Paste", (void (XmlMXCAFDoc_MaterialToolDriver::*)(const opencascade::handle<TDF_Attribute> &, XmlObjMgt_Persistent &, XmlObjMgt_SRelocationTable &) const) &XmlMXCAFDoc_MaterialToolDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
cls_XmlMXCAFDoc_MaterialToolDriver.def_static("get_type_name_", (const char * (*)()) &XmlMXCAFDoc_MaterialToolDriver::get_type_name, "None");
cls_XmlMXCAFDoc_MaterialToolDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlMXCAFDoc_MaterialToolDriver::get_type_descriptor, "None");
cls_XmlMXCAFDoc_MaterialToolDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlMXCAFDoc_MaterialToolDriver::*)() const) &XmlMXCAFDoc_MaterialToolDriver::DynamicType, "None");

// CLASS: XMLMXCAFDOC_NOTEDRIVER
py::class_<XmlMXCAFDoc_NoteDriver, opencascade::handle<XmlMXCAFDoc_NoteDriver>, XmlMDF_ADriver> cls_XmlMXCAFDoc_NoteDriver(mod, "XmlMXCAFDoc_NoteDriver", "Attribute Driver.");

// Methods
cls_XmlMXCAFDoc_NoteDriver.def("Paste", (Standard_Boolean (XmlMXCAFDoc_NoteDriver::*)(const XmlObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, XmlObjMgt_RRelocationTable &) const) &XmlMXCAFDoc_NoteDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
cls_XmlMXCAFDoc_NoteDriver.def("Paste", (void (XmlMXCAFDoc_NoteDriver::*)(const opencascade::handle<TDF_Attribute> &, XmlObjMgt_Persistent &, XmlObjMgt_SRelocationTable &) const) &XmlMXCAFDoc_NoteDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
cls_XmlMXCAFDoc_NoteDriver.def_static("get_type_name_", (const char * (*)()) &XmlMXCAFDoc_NoteDriver::get_type_name, "None");
cls_XmlMXCAFDoc_NoteDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlMXCAFDoc_NoteDriver::get_type_descriptor, "None");
cls_XmlMXCAFDoc_NoteDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlMXCAFDoc_NoteDriver::*)() const) &XmlMXCAFDoc_NoteDriver::DynamicType, "None");

// CLASS: XMLMXCAFDOC_NOTECOMMENTDRIVER
py::class_<XmlMXCAFDoc_NoteCommentDriver, opencascade::handle<XmlMXCAFDoc_NoteCommentDriver>, XmlMXCAFDoc_NoteDriver> cls_XmlMXCAFDoc_NoteCommentDriver(mod, "XmlMXCAFDoc_NoteCommentDriver", "Attribute Driver.");

// Constructors
cls_XmlMXCAFDoc_NoteCommentDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Methods
cls_XmlMXCAFDoc_NoteCommentDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XmlMXCAFDoc_NoteCommentDriver::*)() const) &XmlMXCAFDoc_NoteCommentDriver::NewEmpty, "None");
cls_XmlMXCAFDoc_NoteCommentDriver.def("Paste", (Standard_Boolean (XmlMXCAFDoc_NoteCommentDriver::*)(const XmlObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, XmlObjMgt_RRelocationTable &) const) &XmlMXCAFDoc_NoteCommentDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
cls_XmlMXCAFDoc_NoteCommentDriver.def("Paste", (void (XmlMXCAFDoc_NoteCommentDriver::*)(const opencascade::handle<TDF_Attribute> &, XmlObjMgt_Persistent &, XmlObjMgt_SRelocationTable &) const) &XmlMXCAFDoc_NoteCommentDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
cls_XmlMXCAFDoc_NoteCommentDriver.def_static("get_type_name_", (const char * (*)()) &XmlMXCAFDoc_NoteCommentDriver::get_type_name, "None");
cls_XmlMXCAFDoc_NoteCommentDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlMXCAFDoc_NoteCommentDriver::get_type_descriptor, "None");
cls_XmlMXCAFDoc_NoteCommentDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlMXCAFDoc_NoteCommentDriver::*)() const) &XmlMXCAFDoc_NoteCommentDriver::DynamicType, "None");

// CLASS: XMLMXCAFDOC_NOTEBALLOONDRIVER
py::class_<XmlMXCAFDoc_NoteBalloonDriver, opencascade::handle<XmlMXCAFDoc_NoteBalloonDriver>, XmlMXCAFDoc_NoteCommentDriver> cls_XmlMXCAFDoc_NoteBalloonDriver(mod, "XmlMXCAFDoc_NoteBalloonDriver", "Attribute Driver.");

// Constructors
cls_XmlMXCAFDoc_NoteBalloonDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Methods
cls_XmlMXCAFDoc_NoteBalloonDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XmlMXCAFDoc_NoteBalloonDriver::*)() const) &XmlMXCAFDoc_NoteBalloonDriver::NewEmpty, "None");
cls_XmlMXCAFDoc_NoteBalloonDriver.def_static("get_type_name_", (const char * (*)()) &XmlMXCAFDoc_NoteBalloonDriver::get_type_name, "None");
cls_XmlMXCAFDoc_NoteBalloonDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlMXCAFDoc_NoteBalloonDriver::get_type_descriptor, "None");
cls_XmlMXCAFDoc_NoteBalloonDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlMXCAFDoc_NoteBalloonDriver::*)() const) &XmlMXCAFDoc_NoteBalloonDriver::DynamicType, "None");

// CLASS: XMLMXCAFDOC_NOTEBINDATADRIVER
py::class_<XmlMXCAFDoc_NoteBinDataDriver, opencascade::handle<XmlMXCAFDoc_NoteBinDataDriver>, XmlMXCAFDoc_NoteDriver> cls_XmlMXCAFDoc_NoteBinDataDriver(mod, "XmlMXCAFDoc_NoteBinDataDriver", "Attribute Driver.");

// Constructors
cls_XmlMXCAFDoc_NoteBinDataDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Methods
cls_XmlMXCAFDoc_NoteBinDataDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XmlMXCAFDoc_NoteBinDataDriver::*)() const) &XmlMXCAFDoc_NoteBinDataDriver::NewEmpty, "None");
cls_XmlMXCAFDoc_NoteBinDataDriver.def("Paste", (Standard_Boolean (XmlMXCAFDoc_NoteBinDataDriver::*)(const XmlObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, XmlObjMgt_RRelocationTable &) const) &XmlMXCAFDoc_NoteBinDataDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
cls_XmlMXCAFDoc_NoteBinDataDriver.def("Paste", (void (XmlMXCAFDoc_NoteBinDataDriver::*)(const opencascade::handle<TDF_Attribute> &, XmlObjMgt_Persistent &, XmlObjMgt_SRelocationTable &) const) &XmlMXCAFDoc_NoteBinDataDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
cls_XmlMXCAFDoc_NoteBinDataDriver.def_static("get_type_name_", (const char * (*)()) &XmlMXCAFDoc_NoteBinDataDriver::get_type_name, "None");
cls_XmlMXCAFDoc_NoteBinDataDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlMXCAFDoc_NoteBinDataDriver::get_type_descriptor, "None");
cls_XmlMXCAFDoc_NoteBinDataDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlMXCAFDoc_NoteBinDataDriver::*)() const) &XmlMXCAFDoc_NoteBinDataDriver::DynamicType, "None");

// CLASS: XMLMXCAFDOC_NOTESTOOLDRIVER
py::class_<XmlMXCAFDoc_NotesToolDriver, opencascade::handle<XmlMXCAFDoc_NotesToolDriver>, XmlMDF_ADriver> cls_XmlMXCAFDoc_NotesToolDriver(mod, "XmlMXCAFDoc_NotesToolDriver", "Attribute Driver.");

// Constructors
cls_XmlMXCAFDoc_NotesToolDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMsgDriver"));

// Methods
cls_XmlMXCAFDoc_NotesToolDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XmlMXCAFDoc_NotesToolDriver::*)() const) &XmlMXCAFDoc_NotesToolDriver::NewEmpty, "None");
cls_XmlMXCAFDoc_NotesToolDriver.def("Paste", (Standard_Boolean (XmlMXCAFDoc_NotesToolDriver::*)(const XmlObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, XmlObjMgt_RRelocationTable &) const) &XmlMXCAFDoc_NotesToolDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
cls_XmlMXCAFDoc_NotesToolDriver.def("Paste", (void (XmlMXCAFDoc_NotesToolDriver::*)(const opencascade::handle<TDF_Attribute> &, XmlObjMgt_Persistent &, XmlObjMgt_SRelocationTable &) const) &XmlMXCAFDoc_NotesToolDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
cls_XmlMXCAFDoc_NotesToolDriver.def_static("get_type_name_", (const char * (*)()) &XmlMXCAFDoc_NotesToolDriver::get_type_name, "None");
cls_XmlMXCAFDoc_NotesToolDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlMXCAFDoc_NotesToolDriver::get_type_descriptor, "None");
cls_XmlMXCAFDoc_NotesToolDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlMXCAFDoc_NotesToolDriver::*)() const) &XmlMXCAFDoc_NotesToolDriver::DynamicType, "None");

// CLASS: XMLMXCAFDOC_SHAPETOOLDRIVER
py::class_<XmlMXCAFDoc_ShapeToolDriver, opencascade::handle<XmlMXCAFDoc_ShapeToolDriver>, XmlMDF_ADriver> cls_XmlMXCAFDoc_ShapeToolDriver(mod, "XmlMXCAFDoc_ShapeToolDriver", "Attribute Driver.");

// Constructors
cls_XmlMXCAFDoc_ShapeToolDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMsgDriver"));

// Methods
cls_XmlMXCAFDoc_ShapeToolDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XmlMXCAFDoc_ShapeToolDriver::*)() const) &XmlMXCAFDoc_ShapeToolDriver::NewEmpty, "None");
cls_XmlMXCAFDoc_ShapeToolDriver.def("Paste", (Standard_Boolean (XmlMXCAFDoc_ShapeToolDriver::*)(const XmlObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, XmlObjMgt_RRelocationTable &) const) &XmlMXCAFDoc_ShapeToolDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
cls_XmlMXCAFDoc_ShapeToolDriver.def("Paste", (void (XmlMXCAFDoc_ShapeToolDriver::*)(const opencascade::handle<TDF_Attribute> &, XmlObjMgt_Persistent &, XmlObjMgt_SRelocationTable &) const) &XmlMXCAFDoc_ShapeToolDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
cls_XmlMXCAFDoc_ShapeToolDriver.def_static("get_type_name_", (const char * (*)()) &XmlMXCAFDoc_ShapeToolDriver::get_type_name, "None");
cls_XmlMXCAFDoc_ShapeToolDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlMXCAFDoc_ShapeToolDriver::get_type_descriptor, "None");
cls_XmlMXCAFDoc_ShapeToolDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlMXCAFDoc_ShapeToolDriver::*)() const) &XmlMXCAFDoc_ShapeToolDriver::DynamicType, "None");

// CLASS: XMLMXCAFDOC_VIEWTOOLDRIVER
py::class_<XmlMXCAFDoc_ViewToolDriver, opencascade::handle<XmlMXCAFDoc_ViewToolDriver>, XmlMDF_ADriver> cls_XmlMXCAFDoc_ViewToolDriver(mod, "XmlMXCAFDoc_ViewToolDriver", "Attribute Driver.");

// Constructors
cls_XmlMXCAFDoc_ViewToolDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMsgDriver"));

// Methods
cls_XmlMXCAFDoc_ViewToolDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XmlMXCAFDoc_ViewToolDriver::*)() const) &XmlMXCAFDoc_ViewToolDriver::NewEmpty, "None");
cls_XmlMXCAFDoc_ViewToolDriver.def("Paste", (Standard_Boolean (XmlMXCAFDoc_ViewToolDriver::*)(const XmlObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, XmlObjMgt_RRelocationTable &) const) &XmlMXCAFDoc_ViewToolDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
cls_XmlMXCAFDoc_ViewToolDriver.def("Paste", (void (XmlMXCAFDoc_ViewToolDriver::*)(const opencascade::handle<TDF_Attribute> &, XmlObjMgt_Persistent &, XmlObjMgt_SRelocationTable &) const) &XmlMXCAFDoc_ViewToolDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
cls_XmlMXCAFDoc_ViewToolDriver.def_static("get_type_name_", (const char * (*)()) &XmlMXCAFDoc_ViewToolDriver::get_type_name, "None");
cls_XmlMXCAFDoc_ViewToolDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlMXCAFDoc_ViewToolDriver::get_type_descriptor, "None");
cls_XmlMXCAFDoc_ViewToolDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlMXCAFDoc_ViewToolDriver::*)() const) &XmlMXCAFDoc_ViewToolDriver::DynamicType, "None");

// CLASS: XMLMXCAFDOC_VOLUMEDRIVER
py::class_<XmlMXCAFDoc_VolumeDriver, opencascade::handle<XmlMXCAFDoc_VolumeDriver>, XmlMDF_ADriver> cls_XmlMXCAFDoc_VolumeDriver(mod, "XmlMXCAFDoc_VolumeDriver", "Attribute Driver.");

// Constructors
cls_XmlMXCAFDoc_VolumeDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Methods
cls_XmlMXCAFDoc_VolumeDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XmlMXCAFDoc_VolumeDriver::*)() const) &XmlMXCAFDoc_VolumeDriver::NewEmpty, "None");
cls_XmlMXCAFDoc_VolumeDriver.def("Paste", (Standard_Boolean (XmlMXCAFDoc_VolumeDriver::*)(const XmlObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, XmlObjMgt_RRelocationTable &) const) &XmlMXCAFDoc_VolumeDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMXCAFDoc_VolumeDriver.def("Paste", (void (XmlMXCAFDoc_VolumeDriver::*)(const opencascade::handle<TDF_Attribute> &, XmlObjMgt_Persistent &, XmlObjMgt_SRelocationTable &) const) &XmlMXCAFDoc_VolumeDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMXCAFDoc_VolumeDriver.def_static("get_type_name_", (const char * (*)()) &XmlMXCAFDoc_VolumeDriver::get_type_name, "None");
cls_XmlMXCAFDoc_VolumeDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlMXCAFDoc_VolumeDriver::get_type_descriptor, "None");
cls_XmlMXCAFDoc_VolumeDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlMXCAFDoc_VolumeDriver::*)() const) &XmlMXCAFDoc_VolumeDriver::DynamicType, "None");


}
