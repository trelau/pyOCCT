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
#include <Standard_Transient.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <TDF_Attribute.hxx>
#include <Standard_Type.hxx>
#include <TCollection_AsciiString.hxx>
#include <XmlObjMgt_Persistent.hxx>
#include <XmlObjMgt_RRelocationTable.hxx>
#include <XmlObjMgt_SRelocationTable.hxx>
#include <Standard_Std.hxx>
#include <XmlMDF_ADriver.hxx>
#include <Message_Messenger.hxx>
#include <XmlMDF.hxx>
#include <NCollection_DataMap.hxx>
#include <XmlMDF_MapOfDriver.hxx>
#include <Standard.hxx>
#include <TDF_Data.hxx>
#include <XmlObjMgt_Element.hxx>
#include <XmlMDF_ADriverTable.hxx>
#include <TDF_Label.hxx>
#include <XmlMDF_TagSourceDriver.hxx>
#include <XmlMDF_ReferenceDriver.hxx>
#include <TColStd_MapTransientHasher.hxx>
#include <XmlMDF_TypeADriverMap.hxx>
#include <bind_NCollection_DataMap.hxx>

PYBIND11_MODULE(XmlMDF, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.TDF");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.XmlObjMgt");
py::module::import("OCCT.Message");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.TColStd");

// CLASS: XMLMDF_ADRIVER
py::class_<XmlMDF_ADriver, opencascade::handle<XmlMDF_ADriver>, Standard_Transient> cls_XmlMDF_ADriver(mod, "XmlMDF_ADriver", "Attribute Storage/Retrieval Driver.");

// Methods
cls_XmlMDF_ADriver.def("VersionNumber", (Standard_Integer (XmlMDF_ADriver::*)() const) &XmlMDF_ADriver::VersionNumber, "Returns the version number from which the driver is available.");
cls_XmlMDF_ADriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XmlMDF_ADriver::*)() const) &XmlMDF_ADriver::NewEmpty, "Creates a new attribute from TDF.");
cls_XmlMDF_ADriver.def("SourceType", (opencascade::handle<Standard_Type> (XmlMDF_ADriver::*)() const) &XmlMDF_ADriver::SourceType, "Returns the type of source object, inheriting from Attribute from TDF.");
cls_XmlMDF_ADriver.def("TypeName", (const TCollection_AsciiString & (XmlMDF_ADriver::*)() const) &XmlMDF_ADriver::TypeName, "Returns the full XML tag name (including NS prefix)");
cls_XmlMDF_ADriver.def("Paste", (Standard_Boolean (XmlMDF_ADriver::*)(const XmlObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, XmlObjMgt_RRelocationTable &) const) &XmlMDF_ADriver::Paste, "Translate the contents of <aSource> and put it into <aTarget>, using the relocation table <aRelocTable> to keep the sharings.", py::arg("aSource"), py::arg("aTarget"), py::arg("aRelocTable"));
cls_XmlMDF_ADriver.def("Paste", (void (XmlMDF_ADriver::*)(const opencascade::handle<TDF_Attribute> &, XmlObjMgt_Persistent &, XmlObjMgt_SRelocationTable &) const) &XmlMDF_ADriver::Paste, "Translate the contents of <aSource> and put it into <aTarget>, using the relocation table <aRelocTable> to keep the sharings.", py::arg("aSource"), py::arg("aTarget"), py::arg("aRelocTable"));
cls_XmlMDF_ADriver.def_static("get_type_name_", (const char * (*)()) &XmlMDF_ADriver::get_type_name, "None");
cls_XmlMDF_ADriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlMDF_ADriver::get_type_descriptor, "None");
cls_XmlMDF_ADriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlMDF_ADriver::*)() const) &XmlMDF_ADriver::DynamicType, "None");

// TYPEDEF: XMLMDF_MAPOFDRIVER
bind_NCollection_DataMap<TCollection_AsciiString, opencascade::handle<XmlMDF_ADriver>, TCollection_AsciiString>(mod, "XmlMDF_MapOfDriver", py::module_local(false));

// TYPEDEF: XMLMDF_DATAMAPITERATOROFMAPOFDRIVER

// CLASS: XMLMDF
py::class_<XmlMDF> cls_XmlMDF(mod, "XmlMDF", "This package provides classes and methods to translate a transient DF into a persistent one and vice versa.");

// Constructors
cls_XmlMDF.def(py::init<>());

// Methods
// cls_XmlMDF.def_static("operator new_", (void * (*)(size_t)) &XmlMDF::operator new, "None", py::arg("theSize"));
// cls_XmlMDF.def_static("operator delete_", (void (*)(void *)) &XmlMDF::operator delete, "None", py::arg("theAddress"));
// cls_XmlMDF.def_static("operator new[]_", (void * (*)(size_t)) &XmlMDF::operator new[], "None", py::arg("theSize"));
// cls_XmlMDF.def_static("operator delete[]_", (void (*)(void *)) &XmlMDF::operator delete[], "None", py::arg("theAddress"));
// cls_XmlMDF.def_static("operator new_", (void * (*)(size_t, void *)) &XmlMDF::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_XmlMDF.def_static("operator delete_", (void (*)(void *, void *)) &XmlMDF::operator delete, "None", py::arg(""), py::arg(""));
cls_XmlMDF.def_static("FromTo_", (void (*)(const opencascade::handle<TDF_Data> &, XmlObjMgt_Element &, XmlObjMgt_SRelocationTable &, const opencascade::handle<XmlMDF_ADriverTable> &)) &XmlMDF::FromTo, "Translates a transient <aSource> into a persistent <aTarget>.", py::arg("aSource"), py::arg("aTarget"), py::arg("aReloc"), py::arg("aDrivers"));
cls_XmlMDF.def_static("FromTo_", (Standard_Boolean (*)(const XmlObjMgt_Element &, opencascade::handle<TDF_Data> &, XmlObjMgt_RRelocationTable &, const opencascade::handle<XmlMDF_ADriverTable> &)) &XmlMDF::FromTo, "Translates a persistent <aSource> into a transient <aTarget>. Returns True if completed successfully (False on error)", py::arg("aSource"), py::arg("aTarget"), py::arg("aReloc"), py::arg("aDrivers"));
cls_XmlMDF.def_static("AddDrivers_", (void (*)(const opencascade::handle<XmlMDF_ADriverTable> &, const opencascade::handle<Message_Messenger> &)) &XmlMDF::AddDrivers, "Adds the attribute storage drivers to <aDriverSeq>.", py::arg("aDriverTable"), py::arg("theMessageDriver"));

// TYPEDEF: XMLMDF_TYPEADRIVERMAP
bind_NCollection_DataMap<opencascade::handle<Standard_Type>, opencascade::handle<XmlMDF_ADriver>, NCollection_DefaultHasher<opencascade::handle<Standard_Transient> > >(mod, "XmlMDF_TypeADriverMap", py::module_local(false));

// TYPEDEF: XMLMDF_DATAMAPITERATOROFTYPEADRIVERMAP

// CLASS: XMLMDF_ADRIVERTABLE
py::class_<XmlMDF_ADriverTable, opencascade::handle<XmlMDF_ADriverTable>, Standard_Transient> cls_XmlMDF_ADriverTable(mod, "XmlMDF_ADriverTable", "A driver table is an object building links between object types and object drivers. In the translation process, a driver table is asked to give a translation driver for each current object to be translated.");

// Constructors
cls_XmlMDF_ADriverTable.def(py::init<>());

// Methods
cls_XmlMDF_ADriverTable.def("AddDriver", (void (XmlMDF_ADriverTable::*)(const opencascade::handle<XmlMDF_ADriver> &)) &XmlMDF_ADriverTable::AddDriver, "Sets a translation driver: <aDriver>.", py::arg("anHDriver"));
cls_XmlMDF_ADriverTable.def("GetDrivers", (const XmlMDF_TypeADriverMap & (XmlMDF_ADriverTable::*)() const) &XmlMDF_ADriverTable::GetDrivers, "Gets a map of drivers.");
cls_XmlMDF_ADriverTable.def("GetDriver", (Standard_Boolean (XmlMDF_ADriverTable::*)(const opencascade::handle<Standard_Type> &, opencascade::handle<XmlMDF_ADriver> &) const) &XmlMDF_ADriverTable::GetDriver, "Gets a driver <aDriver> according to <aType>", py::arg("aType"), py::arg("anHDriver"));
cls_XmlMDF_ADriverTable.def_static("get_type_name_", (const char * (*)()) &XmlMDF_ADriverTable::get_type_name, "None");
cls_XmlMDF_ADriverTable.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlMDF_ADriverTable::get_type_descriptor, "None");
cls_XmlMDF_ADriverTable.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlMDF_ADriverTable::*)() const) &XmlMDF_ADriverTable::DynamicType, "None");

// CLASS: XMLMDF_REFERENCEDRIVER
py::class_<XmlMDF_ReferenceDriver, opencascade::handle<XmlMDF_ReferenceDriver>, XmlMDF_ADriver> cls_XmlMDF_ReferenceDriver(mod, "XmlMDF_ReferenceDriver", "Attribute Driver.");

// Constructors
cls_XmlMDF_ReferenceDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Methods
cls_XmlMDF_ReferenceDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XmlMDF_ReferenceDriver::*)() const) &XmlMDF_ReferenceDriver::NewEmpty, "None");
cls_XmlMDF_ReferenceDriver.def("Paste", (Standard_Boolean (XmlMDF_ReferenceDriver::*)(const XmlObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, XmlObjMgt_RRelocationTable &) const) &XmlMDF_ReferenceDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMDF_ReferenceDriver.def("Paste", (void (XmlMDF_ReferenceDriver::*)(const opencascade::handle<TDF_Attribute> &, XmlObjMgt_Persistent &, XmlObjMgt_SRelocationTable &) const) &XmlMDF_ReferenceDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMDF_ReferenceDriver.def_static("get_type_name_", (const char * (*)()) &XmlMDF_ReferenceDriver::get_type_name, "None");
cls_XmlMDF_ReferenceDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlMDF_ReferenceDriver::get_type_descriptor, "None");
cls_XmlMDF_ReferenceDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlMDF_ReferenceDriver::*)() const) &XmlMDF_ReferenceDriver::DynamicType, "None");

// CLASS: XMLMDF_TAGSOURCEDRIVER
py::class_<XmlMDF_TagSourceDriver, opencascade::handle<XmlMDF_TagSourceDriver>, XmlMDF_ADriver> cls_XmlMDF_TagSourceDriver(mod, "XmlMDF_TagSourceDriver", "Attribute Driver.");

// Constructors
cls_XmlMDF_TagSourceDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Methods
cls_XmlMDF_TagSourceDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XmlMDF_TagSourceDriver::*)() const) &XmlMDF_TagSourceDriver::NewEmpty, "None");
cls_XmlMDF_TagSourceDriver.def("Paste", (Standard_Boolean (XmlMDF_TagSourceDriver::*)(const XmlObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, XmlObjMgt_RRelocationTable &) const) &XmlMDF_TagSourceDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMDF_TagSourceDriver.def("Paste", (void (XmlMDF_TagSourceDriver::*)(const opencascade::handle<TDF_Attribute> &, XmlObjMgt_Persistent &, XmlObjMgt_SRelocationTable &) const) &XmlMDF_TagSourceDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMDF_TagSourceDriver.def_static("get_type_name_", (const char * (*)()) &XmlMDF_TagSourceDriver::get_type_name, "None");
cls_XmlMDF_TagSourceDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlMDF_TagSourceDriver::get_type_descriptor, "None");
cls_XmlMDF_TagSourceDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlMDF_TagSourceDriver::*)() const) &XmlMDF_TagSourceDriver::DynamicType, "None");


}
