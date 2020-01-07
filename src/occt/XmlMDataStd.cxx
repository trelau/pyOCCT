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
#include <XmlMDataStd_NameDriver.hxx>
#include <XmlMDataStd_IntegerDriver.hxx>
#include <XmlMDataStd_RealDriver.hxx>
#include <XmlMDataStd_IntegerArrayDriver.hxx>
#include <XmlMDataStd_RealArrayDriver.hxx>
#include <XmlMDataStd_ExtStringArrayDriver.hxx>
#include <XmlMDataStd_UAttributeDriver.hxx>
#include <XmlMDataStd_DirectoryDriver.hxx>
#include <XmlMDataStd_CommentDriver.hxx>
#include <XmlMDataStd_VariableDriver.hxx>
#include <XmlMDataStd_ExpressionDriver.hxx>
#include <XmlMDataStd_RelationDriver.hxx>
#include <XmlMDataStd_NoteBookDriver.hxx>
#include <XmlMDataStd_TreeNodeDriver.hxx>
#include <XmlMDataStd_TickDriver.hxx>
#include <XmlMDataStd_IntegerListDriver.hxx>
#include <XmlMDataStd_RealListDriver.hxx>
#include <XmlMDataStd_ExtStringListDriver.hxx>
#include <XmlMDataStd_BooleanListDriver.hxx>
#include <XmlMDataStd_ReferenceListDriver.hxx>
#include <XmlMDataStd_BooleanArrayDriver.hxx>
#include <XmlMDataStd_ReferenceArrayDriver.hxx>
#include <XmlMDataStd_ByteArrayDriver.hxx>
#include <XmlMDataStd_NamedDataDriver.hxx>
#include <XmlMDataStd_AsciiStringDriver.hxx>
#include <XmlMDataStd_IntPackedMapDriver.hxx>
#include <XmlMDataStd.hxx>
#include <XmlMDF_ADriver.hxx>
#include <TDF_Attribute.hxx>
#include <Standard_TypeDef.hxx>
#include <XmlObjMgt_Persistent.hxx>
#include <XmlObjMgt_RRelocationTable.hxx>
#include <XmlObjMgt_SRelocationTable.hxx>
#include <Standard_Std.hxx>
#include <Standard_Type.hxx>

PYBIND11_MODULE(XmlMDataStd, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.XmlMDF");
py::module::import("OCCT.Message");
py::module::import("OCCT.TDF");
py::module::import("OCCT.XmlObjMgt");

// CLASS: XMLMDATASTD
py::class_<XmlMDataStd> cls_XmlMDataStd(mod, "XmlMDataStd", "Storage and Retrieval drivers for modelling attributes. Transient attributes are defined in package TDataStd.");

// Constructors
cls_XmlMDataStd.def(py::init<>());

// Methods
// cls_XmlMDataStd.def_static("operator new_", (void * (*)(size_t)) &XmlMDataStd::operator new, "None", py::arg("theSize"));
// cls_XmlMDataStd.def_static("operator delete_", (void (*)(void *)) &XmlMDataStd::operator delete, "None", py::arg("theAddress"));
// cls_XmlMDataStd.def_static("operator new[]_", (void * (*)(size_t)) &XmlMDataStd::operator new[], "None", py::arg("theSize"));
// cls_XmlMDataStd.def_static("operator delete[]_", (void (*)(void *)) &XmlMDataStd::operator delete[], "None", py::arg("theAddress"));
// cls_XmlMDataStd.def_static("operator new_", (void * (*)(size_t, void *)) &XmlMDataStd::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_XmlMDataStd.def_static("operator delete_", (void (*)(void *, void *)) &XmlMDataStd::operator delete, "None", py::arg(""), py::arg(""));
cls_XmlMDataStd.def_static("AddDrivers_", (void (*)(const opencascade::handle<XmlMDF_ADriverTable> &, const opencascade::handle<Message_Messenger> &)) &XmlMDataStd::AddDrivers, "Adds the attribute drivers to <aDriverTable>.", py::arg("aDriverTable"), py::arg("anMsgDrv"));

// CLASS: XMLMDATASTD_ASCIISTRINGDRIVER
py::class_<XmlMDataStd_AsciiStringDriver, opencascade::handle<XmlMDataStd_AsciiStringDriver>, XmlMDF_ADriver> cls_XmlMDataStd_AsciiStringDriver(mod, "XmlMDataStd_AsciiStringDriver", "TDataStd_AsciiString attribute Driver.");

// Constructors
cls_XmlMDataStd_AsciiStringDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Methods
cls_XmlMDataStd_AsciiStringDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XmlMDataStd_AsciiStringDriver::*)() const) &XmlMDataStd_AsciiStringDriver::NewEmpty, "None");
cls_XmlMDataStd_AsciiStringDriver.def("Paste", (Standard_Boolean (XmlMDataStd_AsciiStringDriver::*)(const XmlObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, XmlObjMgt_RRelocationTable &) const) &XmlMDataStd_AsciiStringDriver::Paste, "persistent -> transient (retrieve)", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMDataStd_AsciiStringDriver.def("Paste", (void (XmlMDataStd_AsciiStringDriver::*)(const opencascade::handle<TDF_Attribute> &, XmlObjMgt_Persistent &, XmlObjMgt_SRelocationTable &) const) &XmlMDataStd_AsciiStringDriver::Paste, "transient -> persistent (store)", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMDataStd_AsciiStringDriver.def_static("get_type_name_", (const char * (*)()) &XmlMDataStd_AsciiStringDriver::get_type_name, "None");
cls_XmlMDataStd_AsciiStringDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlMDataStd_AsciiStringDriver::get_type_descriptor, "None");
cls_XmlMDataStd_AsciiStringDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlMDataStd_AsciiStringDriver::*)() const) &XmlMDataStd_AsciiStringDriver::DynamicType, "None");

// CLASS: XMLMDATASTD_BOOLEANARRAYDRIVER
py::class_<XmlMDataStd_BooleanArrayDriver, opencascade::handle<XmlMDataStd_BooleanArrayDriver>, XmlMDF_ADriver> cls_XmlMDataStd_BooleanArrayDriver(mod, "XmlMDataStd_BooleanArrayDriver", "None");

// Constructors
cls_XmlMDataStd_BooleanArrayDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Methods
cls_XmlMDataStd_BooleanArrayDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XmlMDataStd_BooleanArrayDriver::*)() const) &XmlMDataStd_BooleanArrayDriver::NewEmpty, "None");
cls_XmlMDataStd_BooleanArrayDriver.def("Paste", (Standard_Boolean (XmlMDataStd_BooleanArrayDriver::*)(const XmlObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, XmlObjMgt_RRelocationTable &) const) &XmlMDataStd_BooleanArrayDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMDataStd_BooleanArrayDriver.def("Paste", (void (XmlMDataStd_BooleanArrayDriver::*)(const opencascade::handle<TDF_Attribute> &, XmlObjMgt_Persistent &, XmlObjMgt_SRelocationTable &) const) &XmlMDataStd_BooleanArrayDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMDataStd_BooleanArrayDriver.def_static("get_type_name_", (const char * (*)()) &XmlMDataStd_BooleanArrayDriver::get_type_name, "None");
cls_XmlMDataStd_BooleanArrayDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlMDataStd_BooleanArrayDriver::get_type_descriptor, "None");
cls_XmlMDataStd_BooleanArrayDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlMDataStd_BooleanArrayDriver::*)() const) &XmlMDataStd_BooleanArrayDriver::DynamicType, "None");

// CLASS: XMLMDATASTD_BOOLEANLISTDRIVER
py::class_<XmlMDataStd_BooleanListDriver, opencascade::handle<XmlMDataStd_BooleanListDriver>, XmlMDF_ADriver> cls_XmlMDataStd_BooleanListDriver(mod, "XmlMDataStd_BooleanListDriver", "None");

// Constructors
cls_XmlMDataStd_BooleanListDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Methods
cls_XmlMDataStd_BooleanListDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XmlMDataStd_BooleanListDriver::*)() const) &XmlMDataStd_BooleanListDriver::NewEmpty, "None");
cls_XmlMDataStd_BooleanListDriver.def("Paste", (Standard_Boolean (XmlMDataStd_BooleanListDriver::*)(const XmlObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, XmlObjMgt_RRelocationTable &) const) &XmlMDataStd_BooleanListDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMDataStd_BooleanListDriver.def("Paste", (void (XmlMDataStd_BooleanListDriver::*)(const opencascade::handle<TDF_Attribute> &, XmlObjMgt_Persistent &, XmlObjMgt_SRelocationTable &) const) &XmlMDataStd_BooleanListDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMDataStd_BooleanListDriver.def_static("get_type_name_", (const char * (*)()) &XmlMDataStd_BooleanListDriver::get_type_name, "None");
cls_XmlMDataStd_BooleanListDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlMDataStd_BooleanListDriver::get_type_descriptor, "None");
cls_XmlMDataStd_BooleanListDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlMDataStd_BooleanListDriver::*)() const) &XmlMDataStd_BooleanListDriver::DynamicType, "None");

// CLASS: XMLMDATASTD_BYTEARRAYDRIVER
py::class_<XmlMDataStd_ByteArrayDriver, opencascade::handle<XmlMDataStd_ByteArrayDriver>, XmlMDF_ADriver> cls_XmlMDataStd_ByteArrayDriver(mod, "XmlMDataStd_ByteArrayDriver", "None");

// Constructors
cls_XmlMDataStd_ByteArrayDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Methods
cls_XmlMDataStd_ByteArrayDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XmlMDataStd_ByteArrayDriver::*)() const) &XmlMDataStd_ByteArrayDriver::NewEmpty, "None");
cls_XmlMDataStd_ByteArrayDriver.def("Paste", (Standard_Boolean (XmlMDataStd_ByteArrayDriver::*)(const XmlObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, XmlObjMgt_RRelocationTable &) const) &XmlMDataStd_ByteArrayDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMDataStd_ByteArrayDriver.def("Paste", (void (XmlMDataStd_ByteArrayDriver::*)(const opencascade::handle<TDF_Attribute> &, XmlObjMgt_Persistent &, XmlObjMgt_SRelocationTable &) const) &XmlMDataStd_ByteArrayDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMDataStd_ByteArrayDriver.def_static("get_type_name_", (const char * (*)()) &XmlMDataStd_ByteArrayDriver::get_type_name, "None");
cls_XmlMDataStd_ByteArrayDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlMDataStd_ByteArrayDriver::get_type_descriptor, "None");
cls_XmlMDataStd_ByteArrayDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlMDataStd_ByteArrayDriver::*)() const) &XmlMDataStd_ByteArrayDriver::DynamicType, "None");

// CLASS: XMLMDATASTD_COMMENTDRIVER
py::class_<XmlMDataStd_CommentDriver, opencascade::handle<XmlMDataStd_CommentDriver>, XmlMDF_ADriver> cls_XmlMDataStd_CommentDriver(mod, "XmlMDataStd_CommentDriver", "Attribute Driver.");

// Constructors
cls_XmlMDataStd_CommentDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Methods
cls_XmlMDataStd_CommentDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XmlMDataStd_CommentDriver::*)() const) &XmlMDataStd_CommentDriver::NewEmpty, "None");
cls_XmlMDataStd_CommentDriver.def("Paste", (Standard_Boolean (XmlMDataStd_CommentDriver::*)(const XmlObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, XmlObjMgt_RRelocationTable &) const) &XmlMDataStd_CommentDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMDataStd_CommentDriver.def("Paste", (void (XmlMDataStd_CommentDriver::*)(const opencascade::handle<TDF_Attribute> &, XmlObjMgt_Persistent &, XmlObjMgt_SRelocationTable &) const) &XmlMDataStd_CommentDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMDataStd_CommentDriver.def_static("get_type_name_", (const char * (*)()) &XmlMDataStd_CommentDriver::get_type_name, "None");
cls_XmlMDataStd_CommentDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlMDataStd_CommentDriver::get_type_descriptor, "None");
cls_XmlMDataStd_CommentDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlMDataStd_CommentDriver::*)() const) &XmlMDataStd_CommentDriver::DynamicType, "None");

// CLASS: XMLMDATASTD_DIRECTORYDRIVER
py::class_<XmlMDataStd_DirectoryDriver, opencascade::handle<XmlMDataStd_DirectoryDriver>, XmlMDF_ADriver> cls_XmlMDataStd_DirectoryDriver(mod, "XmlMDataStd_DirectoryDriver", "Attribute Driver.");

// Constructors
cls_XmlMDataStd_DirectoryDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Methods
cls_XmlMDataStd_DirectoryDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XmlMDataStd_DirectoryDriver::*)() const) &XmlMDataStd_DirectoryDriver::NewEmpty, "None");
cls_XmlMDataStd_DirectoryDriver.def("Paste", (Standard_Boolean (XmlMDataStd_DirectoryDriver::*)(const XmlObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, XmlObjMgt_RRelocationTable &) const) &XmlMDataStd_DirectoryDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMDataStd_DirectoryDriver.def("Paste", (void (XmlMDataStd_DirectoryDriver::*)(const opencascade::handle<TDF_Attribute> &, XmlObjMgt_Persistent &, XmlObjMgt_SRelocationTable &) const) &XmlMDataStd_DirectoryDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMDataStd_DirectoryDriver.def_static("get_type_name_", (const char * (*)()) &XmlMDataStd_DirectoryDriver::get_type_name, "None");
cls_XmlMDataStd_DirectoryDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlMDataStd_DirectoryDriver::get_type_descriptor, "None");
cls_XmlMDataStd_DirectoryDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlMDataStd_DirectoryDriver::*)() const) &XmlMDataStd_DirectoryDriver::DynamicType, "None");

// CLASS: XMLMDATASTD_EXPRESSIONDRIVER
py::class_<XmlMDataStd_ExpressionDriver, opencascade::handle<XmlMDataStd_ExpressionDriver>, XmlMDF_ADriver> cls_XmlMDataStd_ExpressionDriver(mod, "XmlMDataStd_ExpressionDriver", "Attribute Driver.");

// Constructors
cls_XmlMDataStd_ExpressionDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Methods
cls_XmlMDataStd_ExpressionDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XmlMDataStd_ExpressionDriver::*)() const) &XmlMDataStd_ExpressionDriver::NewEmpty, "None");
cls_XmlMDataStd_ExpressionDriver.def("Paste", (Standard_Boolean (XmlMDataStd_ExpressionDriver::*)(const XmlObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, XmlObjMgt_RRelocationTable &) const) &XmlMDataStd_ExpressionDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMDataStd_ExpressionDriver.def("Paste", (void (XmlMDataStd_ExpressionDriver::*)(const opencascade::handle<TDF_Attribute> &, XmlObjMgt_Persistent &, XmlObjMgt_SRelocationTable &) const) &XmlMDataStd_ExpressionDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMDataStd_ExpressionDriver.def_static("get_type_name_", (const char * (*)()) &XmlMDataStd_ExpressionDriver::get_type_name, "None");
cls_XmlMDataStd_ExpressionDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlMDataStd_ExpressionDriver::get_type_descriptor, "None");
cls_XmlMDataStd_ExpressionDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlMDataStd_ExpressionDriver::*)() const) &XmlMDataStd_ExpressionDriver::DynamicType, "None");

// CLASS: XMLMDATASTD_EXTSTRINGARRAYDRIVER
py::class_<XmlMDataStd_ExtStringArrayDriver, opencascade::handle<XmlMDataStd_ExtStringArrayDriver>, XmlMDF_ADriver> cls_XmlMDataStd_ExtStringArrayDriver(mod, "XmlMDataStd_ExtStringArrayDriver", "Attribute Driver.");

// Constructors
cls_XmlMDataStd_ExtStringArrayDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Methods
cls_XmlMDataStd_ExtStringArrayDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XmlMDataStd_ExtStringArrayDriver::*)() const) &XmlMDataStd_ExtStringArrayDriver::NewEmpty, "None");
cls_XmlMDataStd_ExtStringArrayDriver.def("Paste", (Standard_Boolean (XmlMDataStd_ExtStringArrayDriver::*)(const XmlObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, XmlObjMgt_RRelocationTable &) const) &XmlMDataStd_ExtStringArrayDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMDataStd_ExtStringArrayDriver.def("Paste", (void (XmlMDataStd_ExtStringArrayDriver::*)(const opencascade::handle<TDF_Attribute> &, XmlObjMgt_Persistent &, XmlObjMgt_SRelocationTable &) const) &XmlMDataStd_ExtStringArrayDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMDataStd_ExtStringArrayDriver.def_static("get_type_name_", (const char * (*)()) &XmlMDataStd_ExtStringArrayDriver::get_type_name, "None");
cls_XmlMDataStd_ExtStringArrayDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlMDataStd_ExtStringArrayDriver::get_type_descriptor, "None");
cls_XmlMDataStd_ExtStringArrayDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlMDataStd_ExtStringArrayDriver::*)() const) &XmlMDataStd_ExtStringArrayDriver::DynamicType, "None");

// CLASS: XMLMDATASTD_EXTSTRINGLISTDRIVER
py::class_<XmlMDataStd_ExtStringListDriver, opencascade::handle<XmlMDataStd_ExtStringListDriver>, XmlMDF_ADriver> cls_XmlMDataStd_ExtStringListDriver(mod, "XmlMDataStd_ExtStringListDriver", "None");

// Constructors
cls_XmlMDataStd_ExtStringListDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Methods
cls_XmlMDataStd_ExtStringListDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XmlMDataStd_ExtStringListDriver::*)() const) &XmlMDataStd_ExtStringListDriver::NewEmpty, "None");
cls_XmlMDataStd_ExtStringListDriver.def("Paste", (Standard_Boolean (XmlMDataStd_ExtStringListDriver::*)(const XmlObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, XmlObjMgt_RRelocationTable &) const) &XmlMDataStd_ExtStringListDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMDataStd_ExtStringListDriver.def("Paste", (void (XmlMDataStd_ExtStringListDriver::*)(const opencascade::handle<TDF_Attribute> &, XmlObjMgt_Persistent &, XmlObjMgt_SRelocationTable &) const) &XmlMDataStd_ExtStringListDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMDataStd_ExtStringListDriver.def_static("get_type_name_", (const char * (*)()) &XmlMDataStd_ExtStringListDriver::get_type_name, "None");
cls_XmlMDataStd_ExtStringListDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlMDataStd_ExtStringListDriver::get_type_descriptor, "None");
cls_XmlMDataStd_ExtStringListDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlMDataStd_ExtStringListDriver::*)() const) &XmlMDataStd_ExtStringListDriver::DynamicType, "None");

// CLASS: XMLMDATASTD_INTEGERARRAYDRIVER
py::class_<XmlMDataStd_IntegerArrayDriver, opencascade::handle<XmlMDataStd_IntegerArrayDriver>, XmlMDF_ADriver> cls_XmlMDataStd_IntegerArrayDriver(mod, "XmlMDataStd_IntegerArrayDriver", "Attribute Driver.");

// Constructors
cls_XmlMDataStd_IntegerArrayDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Methods
cls_XmlMDataStd_IntegerArrayDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XmlMDataStd_IntegerArrayDriver::*)() const) &XmlMDataStd_IntegerArrayDriver::NewEmpty, "None");
cls_XmlMDataStd_IntegerArrayDriver.def("Paste", (Standard_Boolean (XmlMDataStd_IntegerArrayDriver::*)(const XmlObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, XmlObjMgt_RRelocationTable &) const) &XmlMDataStd_IntegerArrayDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMDataStd_IntegerArrayDriver.def("Paste", (void (XmlMDataStd_IntegerArrayDriver::*)(const opencascade::handle<TDF_Attribute> &, XmlObjMgt_Persistent &, XmlObjMgt_SRelocationTable &) const) &XmlMDataStd_IntegerArrayDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMDataStd_IntegerArrayDriver.def_static("get_type_name_", (const char * (*)()) &XmlMDataStd_IntegerArrayDriver::get_type_name, "None");
cls_XmlMDataStd_IntegerArrayDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlMDataStd_IntegerArrayDriver::get_type_descriptor, "None");
cls_XmlMDataStd_IntegerArrayDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlMDataStd_IntegerArrayDriver::*)() const) &XmlMDataStd_IntegerArrayDriver::DynamicType, "None");

// CLASS: XMLMDATASTD_INTEGERDRIVER
py::class_<XmlMDataStd_IntegerDriver, opencascade::handle<XmlMDataStd_IntegerDriver>, XmlMDF_ADriver> cls_XmlMDataStd_IntegerDriver(mod, "XmlMDataStd_IntegerDriver", "Attribute Driver.");

// Constructors
cls_XmlMDataStd_IntegerDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Methods
cls_XmlMDataStd_IntegerDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XmlMDataStd_IntegerDriver::*)() const) &XmlMDataStd_IntegerDriver::NewEmpty, "None");
cls_XmlMDataStd_IntegerDriver.def("Paste", (Standard_Boolean (XmlMDataStd_IntegerDriver::*)(const XmlObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, XmlObjMgt_RRelocationTable &) const) &XmlMDataStd_IntegerDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMDataStd_IntegerDriver.def("Paste", (void (XmlMDataStd_IntegerDriver::*)(const opencascade::handle<TDF_Attribute> &, XmlObjMgt_Persistent &, XmlObjMgt_SRelocationTable &) const) &XmlMDataStd_IntegerDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMDataStd_IntegerDriver.def_static("get_type_name_", (const char * (*)()) &XmlMDataStd_IntegerDriver::get_type_name, "None");
cls_XmlMDataStd_IntegerDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlMDataStd_IntegerDriver::get_type_descriptor, "None");
cls_XmlMDataStd_IntegerDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlMDataStd_IntegerDriver::*)() const) &XmlMDataStd_IntegerDriver::DynamicType, "None");

// CLASS: XMLMDATASTD_INTEGERLISTDRIVER
py::class_<XmlMDataStd_IntegerListDriver, opencascade::handle<XmlMDataStd_IntegerListDriver>, XmlMDF_ADriver> cls_XmlMDataStd_IntegerListDriver(mod, "XmlMDataStd_IntegerListDriver", "None");

// Constructors
cls_XmlMDataStd_IntegerListDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Methods
cls_XmlMDataStd_IntegerListDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XmlMDataStd_IntegerListDriver::*)() const) &XmlMDataStd_IntegerListDriver::NewEmpty, "None");
cls_XmlMDataStd_IntegerListDriver.def("Paste", (Standard_Boolean (XmlMDataStd_IntegerListDriver::*)(const XmlObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, XmlObjMgt_RRelocationTable &) const) &XmlMDataStd_IntegerListDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMDataStd_IntegerListDriver.def("Paste", (void (XmlMDataStd_IntegerListDriver::*)(const opencascade::handle<TDF_Attribute> &, XmlObjMgt_Persistent &, XmlObjMgt_SRelocationTable &) const) &XmlMDataStd_IntegerListDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMDataStd_IntegerListDriver.def_static("get_type_name_", (const char * (*)()) &XmlMDataStd_IntegerListDriver::get_type_name, "None");
cls_XmlMDataStd_IntegerListDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlMDataStd_IntegerListDriver::get_type_descriptor, "None");
cls_XmlMDataStd_IntegerListDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlMDataStd_IntegerListDriver::*)() const) &XmlMDataStd_IntegerListDriver::DynamicType, "None");

// CLASS: XMLMDATASTD_INTPACKEDMAPDRIVER
py::class_<XmlMDataStd_IntPackedMapDriver, opencascade::handle<XmlMDataStd_IntPackedMapDriver>, XmlMDF_ADriver> cls_XmlMDataStd_IntPackedMapDriver(mod, "XmlMDataStd_IntPackedMapDriver", "TDataStd_IntPackedMap attribute Driver.");

// Constructors
cls_XmlMDataStd_IntPackedMapDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Methods
cls_XmlMDataStd_IntPackedMapDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XmlMDataStd_IntPackedMapDriver::*)() const) &XmlMDataStd_IntPackedMapDriver::NewEmpty, "None");
cls_XmlMDataStd_IntPackedMapDriver.def("Paste", (Standard_Boolean (XmlMDataStd_IntPackedMapDriver::*)(const XmlObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, XmlObjMgt_RRelocationTable &) const) &XmlMDataStd_IntPackedMapDriver::Paste, "persistent -> transient (retrieve)", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMDataStd_IntPackedMapDriver.def("Paste", (void (XmlMDataStd_IntPackedMapDriver::*)(const opencascade::handle<TDF_Attribute> &, XmlObjMgt_Persistent &, XmlObjMgt_SRelocationTable &) const) &XmlMDataStd_IntPackedMapDriver::Paste, "transient -> persistent (store)", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMDataStd_IntPackedMapDriver.def_static("get_type_name_", (const char * (*)()) &XmlMDataStd_IntPackedMapDriver::get_type_name, "None");
cls_XmlMDataStd_IntPackedMapDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlMDataStd_IntPackedMapDriver::get_type_descriptor, "None");
cls_XmlMDataStd_IntPackedMapDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlMDataStd_IntPackedMapDriver::*)() const) &XmlMDataStd_IntPackedMapDriver::DynamicType, "None");

// CLASS: XMLMDATASTD_NAMEDDATADRIVER
py::class_<XmlMDataStd_NamedDataDriver, opencascade::handle<XmlMDataStd_NamedDataDriver>, XmlMDF_ADriver> cls_XmlMDataStd_NamedDataDriver(mod, "XmlMDataStd_NamedDataDriver", "None");

// Constructors
cls_XmlMDataStd_NamedDataDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Methods
cls_XmlMDataStd_NamedDataDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XmlMDataStd_NamedDataDriver::*)() const) &XmlMDataStd_NamedDataDriver::NewEmpty, "None");
cls_XmlMDataStd_NamedDataDriver.def("Paste", (Standard_Boolean (XmlMDataStd_NamedDataDriver::*)(const XmlObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, XmlObjMgt_RRelocationTable &) const) &XmlMDataStd_NamedDataDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMDataStd_NamedDataDriver.def("Paste", (void (XmlMDataStd_NamedDataDriver::*)(const opencascade::handle<TDF_Attribute> &, XmlObjMgt_Persistent &, XmlObjMgt_SRelocationTable &) const) &XmlMDataStd_NamedDataDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMDataStd_NamedDataDriver.def_static("get_type_name_", (const char * (*)()) &XmlMDataStd_NamedDataDriver::get_type_name, "None");
cls_XmlMDataStd_NamedDataDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlMDataStd_NamedDataDriver::get_type_descriptor, "None");
cls_XmlMDataStd_NamedDataDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlMDataStd_NamedDataDriver::*)() const) &XmlMDataStd_NamedDataDriver::DynamicType, "None");

// CLASS: XMLMDATASTD_NAMEDRIVER
py::class_<XmlMDataStd_NameDriver, opencascade::handle<XmlMDataStd_NameDriver>, XmlMDF_ADriver> cls_XmlMDataStd_NameDriver(mod, "XmlMDataStd_NameDriver", "Attribute Driver.");

// Constructors
cls_XmlMDataStd_NameDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Methods
cls_XmlMDataStd_NameDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XmlMDataStd_NameDriver::*)() const) &XmlMDataStd_NameDriver::NewEmpty, "None");
cls_XmlMDataStd_NameDriver.def("Paste", (Standard_Boolean (XmlMDataStd_NameDriver::*)(const XmlObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, XmlObjMgt_RRelocationTable &) const) &XmlMDataStd_NameDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMDataStd_NameDriver.def("Paste", (void (XmlMDataStd_NameDriver::*)(const opencascade::handle<TDF_Attribute> &, XmlObjMgt_Persistent &, XmlObjMgt_SRelocationTable &) const) &XmlMDataStd_NameDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMDataStd_NameDriver.def_static("get_type_name_", (const char * (*)()) &XmlMDataStd_NameDriver::get_type_name, "None");
cls_XmlMDataStd_NameDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlMDataStd_NameDriver::get_type_descriptor, "None");
cls_XmlMDataStd_NameDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlMDataStd_NameDriver::*)() const) &XmlMDataStd_NameDriver::DynamicType, "None");

// CLASS: XMLMDATASTD_NOTEBOOKDRIVER
py::class_<XmlMDataStd_NoteBookDriver, opencascade::handle<XmlMDataStd_NoteBookDriver>, XmlMDF_ADriver> cls_XmlMDataStd_NoteBookDriver(mod, "XmlMDataStd_NoteBookDriver", "Attribute Driver.");

// Constructors
cls_XmlMDataStd_NoteBookDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Methods
cls_XmlMDataStd_NoteBookDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XmlMDataStd_NoteBookDriver::*)() const) &XmlMDataStd_NoteBookDriver::NewEmpty, "None");
cls_XmlMDataStd_NoteBookDriver.def("Paste", (Standard_Boolean (XmlMDataStd_NoteBookDriver::*)(const XmlObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, XmlObjMgt_RRelocationTable &) const) &XmlMDataStd_NoteBookDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMDataStd_NoteBookDriver.def("Paste", (void (XmlMDataStd_NoteBookDriver::*)(const opencascade::handle<TDF_Attribute> &, XmlObjMgt_Persistent &, XmlObjMgt_SRelocationTable &) const) &XmlMDataStd_NoteBookDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMDataStd_NoteBookDriver.def_static("get_type_name_", (const char * (*)()) &XmlMDataStd_NoteBookDriver::get_type_name, "None");
cls_XmlMDataStd_NoteBookDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlMDataStd_NoteBookDriver::get_type_descriptor, "None");
cls_XmlMDataStd_NoteBookDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlMDataStd_NoteBookDriver::*)() const) &XmlMDataStd_NoteBookDriver::DynamicType, "None");

// CLASS: XMLMDATASTD_REALARRAYDRIVER
py::class_<XmlMDataStd_RealArrayDriver, opencascade::handle<XmlMDataStd_RealArrayDriver>, XmlMDF_ADriver> cls_XmlMDataStd_RealArrayDriver(mod, "XmlMDataStd_RealArrayDriver", "Attribute Driver.");

// Constructors
cls_XmlMDataStd_RealArrayDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Methods
cls_XmlMDataStd_RealArrayDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XmlMDataStd_RealArrayDriver::*)() const) &XmlMDataStd_RealArrayDriver::NewEmpty, "None");
cls_XmlMDataStd_RealArrayDriver.def("Paste", (Standard_Boolean (XmlMDataStd_RealArrayDriver::*)(const XmlObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, XmlObjMgt_RRelocationTable &) const) &XmlMDataStd_RealArrayDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMDataStd_RealArrayDriver.def("Paste", (void (XmlMDataStd_RealArrayDriver::*)(const opencascade::handle<TDF_Attribute> &, XmlObjMgt_Persistent &, XmlObjMgt_SRelocationTable &) const) &XmlMDataStd_RealArrayDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMDataStd_RealArrayDriver.def_static("get_type_name_", (const char * (*)()) &XmlMDataStd_RealArrayDriver::get_type_name, "None");
cls_XmlMDataStd_RealArrayDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlMDataStd_RealArrayDriver::get_type_descriptor, "None");
cls_XmlMDataStd_RealArrayDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlMDataStd_RealArrayDriver::*)() const) &XmlMDataStd_RealArrayDriver::DynamicType, "None");

// CLASS: XMLMDATASTD_REALDRIVER
py::class_<XmlMDataStd_RealDriver, opencascade::handle<XmlMDataStd_RealDriver>, XmlMDF_ADriver> cls_XmlMDataStd_RealDriver(mod, "XmlMDataStd_RealDriver", "Attribute Driver.");

// Constructors
cls_XmlMDataStd_RealDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Methods
cls_XmlMDataStd_RealDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XmlMDataStd_RealDriver::*)() const) &XmlMDataStd_RealDriver::NewEmpty, "None");
cls_XmlMDataStd_RealDriver.def("Paste", (Standard_Boolean (XmlMDataStd_RealDriver::*)(const XmlObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, XmlObjMgt_RRelocationTable &) const) &XmlMDataStd_RealDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMDataStd_RealDriver.def("Paste", (void (XmlMDataStd_RealDriver::*)(const opencascade::handle<TDF_Attribute> &, XmlObjMgt_Persistent &, XmlObjMgt_SRelocationTable &) const) &XmlMDataStd_RealDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMDataStd_RealDriver.def_static("get_type_name_", (const char * (*)()) &XmlMDataStd_RealDriver::get_type_name, "None");
cls_XmlMDataStd_RealDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlMDataStd_RealDriver::get_type_descriptor, "None");
cls_XmlMDataStd_RealDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlMDataStd_RealDriver::*)() const) &XmlMDataStd_RealDriver::DynamicType, "None");

// CLASS: XMLMDATASTD_REALLISTDRIVER
py::class_<XmlMDataStd_RealListDriver, opencascade::handle<XmlMDataStd_RealListDriver>, XmlMDF_ADriver> cls_XmlMDataStd_RealListDriver(mod, "XmlMDataStd_RealListDriver", "None");

// Constructors
cls_XmlMDataStd_RealListDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Methods
cls_XmlMDataStd_RealListDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XmlMDataStd_RealListDriver::*)() const) &XmlMDataStd_RealListDriver::NewEmpty, "None");
cls_XmlMDataStd_RealListDriver.def("Paste", (Standard_Boolean (XmlMDataStd_RealListDriver::*)(const XmlObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, XmlObjMgt_RRelocationTable &) const) &XmlMDataStd_RealListDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMDataStd_RealListDriver.def("Paste", (void (XmlMDataStd_RealListDriver::*)(const opencascade::handle<TDF_Attribute> &, XmlObjMgt_Persistent &, XmlObjMgt_SRelocationTable &) const) &XmlMDataStd_RealListDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMDataStd_RealListDriver.def_static("get_type_name_", (const char * (*)()) &XmlMDataStd_RealListDriver::get_type_name, "None");
cls_XmlMDataStd_RealListDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlMDataStd_RealListDriver::get_type_descriptor, "None");
cls_XmlMDataStd_RealListDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlMDataStd_RealListDriver::*)() const) &XmlMDataStd_RealListDriver::DynamicType, "None");

// CLASS: XMLMDATASTD_REFERENCEARRAYDRIVER
py::class_<XmlMDataStd_ReferenceArrayDriver, opencascade::handle<XmlMDataStd_ReferenceArrayDriver>, XmlMDF_ADriver> cls_XmlMDataStd_ReferenceArrayDriver(mod, "XmlMDataStd_ReferenceArrayDriver", "None");

// Constructors
cls_XmlMDataStd_ReferenceArrayDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Methods
cls_XmlMDataStd_ReferenceArrayDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XmlMDataStd_ReferenceArrayDriver::*)() const) &XmlMDataStd_ReferenceArrayDriver::NewEmpty, "None");
cls_XmlMDataStd_ReferenceArrayDriver.def("Paste", (Standard_Boolean (XmlMDataStd_ReferenceArrayDriver::*)(const XmlObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, XmlObjMgt_RRelocationTable &) const) &XmlMDataStd_ReferenceArrayDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMDataStd_ReferenceArrayDriver.def("Paste", (void (XmlMDataStd_ReferenceArrayDriver::*)(const opencascade::handle<TDF_Attribute> &, XmlObjMgt_Persistent &, XmlObjMgt_SRelocationTable &) const) &XmlMDataStd_ReferenceArrayDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMDataStd_ReferenceArrayDriver.def_static("get_type_name_", (const char * (*)()) &XmlMDataStd_ReferenceArrayDriver::get_type_name, "None");
cls_XmlMDataStd_ReferenceArrayDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlMDataStd_ReferenceArrayDriver::get_type_descriptor, "None");
cls_XmlMDataStd_ReferenceArrayDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlMDataStd_ReferenceArrayDriver::*)() const) &XmlMDataStd_ReferenceArrayDriver::DynamicType, "None");

// CLASS: XMLMDATASTD_REFERENCELISTDRIVER
py::class_<XmlMDataStd_ReferenceListDriver, opencascade::handle<XmlMDataStd_ReferenceListDriver>, XmlMDF_ADriver> cls_XmlMDataStd_ReferenceListDriver(mod, "XmlMDataStd_ReferenceListDriver", "None");

// Constructors
cls_XmlMDataStd_ReferenceListDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Methods
cls_XmlMDataStd_ReferenceListDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XmlMDataStd_ReferenceListDriver::*)() const) &XmlMDataStd_ReferenceListDriver::NewEmpty, "None");
cls_XmlMDataStd_ReferenceListDriver.def("Paste", (Standard_Boolean (XmlMDataStd_ReferenceListDriver::*)(const XmlObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, XmlObjMgt_RRelocationTable &) const) &XmlMDataStd_ReferenceListDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMDataStd_ReferenceListDriver.def("Paste", (void (XmlMDataStd_ReferenceListDriver::*)(const opencascade::handle<TDF_Attribute> &, XmlObjMgt_Persistent &, XmlObjMgt_SRelocationTable &) const) &XmlMDataStd_ReferenceListDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMDataStd_ReferenceListDriver.def_static("get_type_name_", (const char * (*)()) &XmlMDataStd_ReferenceListDriver::get_type_name, "None");
cls_XmlMDataStd_ReferenceListDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlMDataStd_ReferenceListDriver::get_type_descriptor, "None");
cls_XmlMDataStd_ReferenceListDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlMDataStd_ReferenceListDriver::*)() const) &XmlMDataStd_ReferenceListDriver::DynamicType, "None");

// CLASS: XMLMDATASTD_RELATIONDRIVER
py::class_<XmlMDataStd_RelationDriver, opencascade::handle<XmlMDataStd_RelationDriver>, XmlMDF_ADriver> cls_XmlMDataStd_RelationDriver(mod, "XmlMDataStd_RelationDriver", "Attribute Driver.");

// Constructors
cls_XmlMDataStd_RelationDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Methods
cls_XmlMDataStd_RelationDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XmlMDataStd_RelationDriver::*)() const) &XmlMDataStd_RelationDriver::NewEmpty, "None");
cls_XmlMDataStd_RelationDriver.def("Paste", (Standard_Boolean (XmlMDataStd_RelationDriver::*)(const XmlObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, XmlObjMgt_RRelocationTable &) const) &XmlMDataStd_RelationDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMDataStd_RelationDriver.def("Paste", (void (XmlMDataStd_RelationDriver::*)(const opencascade::handle<TDF_Attribute> &, XmlObjMgt_Persistent &, XmlObjMgt_SRelocationTable &) const) &XmlMDataStd_RelationDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMDataStd_RelationDriver.def_static("get_type_name_", (const char * (*)()) &XmlMDataStd_RelationDriver::get_type_name, "None");
cls_XmlMDataStd_RelationDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlMDataStd_RelationDriver::get_type_descriptor, "None");
cls_XmlMDataStd_RelationDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlMDataStd_RelationDriver::*)() const) &XmlMDataStd_RelationDriver::DynamicType, "None");

// CLASS: XMLMDATASTD_TICKDRIVER
py::class_<XmlMDataStd_TickDriver, opencascade::handle<XmlMDataStd_TickDriver>, XmlMDF_ADriver> cls_XmlMDataStd_TickDriver(mod, "XmlMDataStd_TickDriver", "None");

// Constructors
cls_XmlMDataStd_TickDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Methods
cls_XmlMDataStd_TickDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XmlMDataStd_TickDriver::*)() const) &XmlMDataStd_TickDriver::NewEmpty, "None");
cls_XmlMDataStd_TickDriver.def("Paste", (Standard_Boolean (XmlMDataStd_TickDriver::*)(const XmlObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, XmlObjMgt_RRelocationTable &) const) &XmlMDataStd_TickDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMDataStd_TickDriver.def("Paste", (void (XmlMDataStd_TickDriver::*)(const opencascade::handle<TDF_Attribute> &, XmlObjMgt_Persistent &, XmlObjMgt_SRelocationTable &) const) &XmlMDataStd_TickDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMDataStd_TickDriver.def_static("get_type_name_", (const char * (*)()) &XmlMDataStd_TickDriver::get_type_name, "None");
cls_XmlMDataStd_TickDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlMDataStd_TickDriver::get_type_descriptor, "None");
cls_XmlMDataStd_TickDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlMDataStd_TickDriver::*)() const) &XmlMDataStd_TickDriver::DynamicType, "None");

// CLASS: XMLMDATASTD_TREENODEDRIVER
py::class_<XmlMDataStd_TreeNodeDriver, opencascade::handle<XmlMDataStd_TreeNodeDriver>, XmlMDF_ADriver> cls_XmlMDataStd_TreeNodeDriver(mod, "XmlMDataStd_TreeNodeDriver", "Attribute Driver.");

// Constructors
cls_XmlMDataStd_TreeNodeDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Methods
cls_XmlMDataStd_TreeNodeDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XmlMDataStd_TreeNodeDriver::*)() const) &XmlMDataStd_TreeNodeDriver::NewEmpty, "None");
cls_XmlMDataStd_TreeNodeDriver.def("Paste", (Standard_Boolean (XmlMDataStd_TreeNodeDriver::*)(const XmlObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, XmlObjMgt_RRelocationTable &) const) &XmlMDataStd_TreeNodeDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMDataStd_TreeNodeDriver.def("Paste", (void (XmlMDataStd_TreeNodeDriver::*)(const opencascade::handle<TDF_Attribute> &, XmlObjMgt_Persistent &, XmlObjMgt_SRelocationTable &) const) &XmlMDataStd_TreeNodeDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMDataStd_TreeNodeDriver.def_static("get_type_name_", (const char * (*)()) &XmlMDataStd_TreeNodeDriver::get_type_name, "None");
cls_XmlMDataStd_TreeNodeDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlMDataStd_TreeNodeDriver::get_type_descriptor, "None");
cls_XmlMDataStd_TreeNodeDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlMDataStd_TreeNodeDriver::*)() const) &XmlMDataStd_TreeNodeDriver::DynamicType, "None");

// CLASS: XMLMDATASTD_UATTRIBUTEDRIVER
py::class_<XmlMDataStd_UAttributeDriver, opencascade::handle<XmlMDataStd_UAttributeDriver>, XmlMDF_ADriver> cls_XmlMDataStd_UAttributeDriver(mod, "XmlMDataStd_UAttributeDriver", "Attribute Driver.");

// Constructors
cls_XmlMDataStd_UAttributeDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Methods
cls_XmlMDataStd_UAttributeDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XmlMDataStd_UAttributeDriver::*)() const) &XmlMDataStd_UAttributeDriver::NewEmpty, "None");
cls_XmlMDataStd_UAttributeDriver.def("Paste", (Standard_Boolean (XmlMDataStd_UAttributeDriver::*)(const XmlObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, XmlObjMgt_RRelocationTable &) const) &XmlMDataStd_UAttributeDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMDataStd_UAttributeDriver.def("Paste", (void (XmlMDataStd_UAttributeDriver::*)(const opencascade::handle<TDF_Attribute> &, XmlObjMgt_Persistent &, XmlObjMgt_SRelocationTable &) const) &XmlMDataStd_UAttributeDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMDataStd_UAttributeDriver.def_static("get_type_name_", (const char * (*)()) &XmlMDataStd_UAttributeDriver::get_type_name, "None");
cls_XmlMDataStd_UAttributeDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlMDataStd_UAttributeDriver::get_type_descriptor, "None");
cls_XmlMDataStd_UAttributeDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlMDataStd_UAttributeDriver::*)() const) &XmlMDataStd_UAttributeDriver::DynamicType, "None");

// CLASS: XMLMDATASTD_VARIABLEDRIVER
py::class_<XmlMDataStd_VariableDriver, opencascade::handle<XmlMDataStd_VariableDriver>, XmlMDF_ADriver> cls_XmlMDataStd_VariableDriver(mod, "XmlMDataStd_VariableDriver", "Attribute Driver.");

// Constructors
cls_XmlMDataStd_VariableDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Methods
cls_XmlMDataStd_VariableDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XmlMDataStd_VariableDriver::*)() const) &XmlMDataStd_VariableDriver::NewEmpty, "None");
cls_XmlMDataStd_VariableDriver.def("Paste", (Standard_Boolean (XmlMDataStd_VariableDriver::*)(const XmlObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, XmlObjMgt_RRelocationTable &) const) &XmlMDataStd_VariableDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMDataStd_VariableDriver.def("Paste", (void (XmlMDataStd_VariableDriver::*)(const opencascade::handle<TDF_Attribute> &, XmlObjMgt_Persistent &, XmlObjMgt_SRelocationTable &) const) &XmlMDataStd_VariableDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMDataStd_VariableDriver.def_static("get_type_name_", (const char * (*)()) &XmlMDataStd_VariableDriver::get_type_name, "None");
cls_XmlMDataStd_VariableDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlMDataStd_VariableDriver::get_type_descriptor, "None");
cls_XmlMDataStd_VariableDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlMDataStd_VariableDriver::*)() const) &XmlMDataStd_VariableDriver::DynamicType, "None");


}
