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
#include <BinMDF_ADriverTable.hxx>
#include <Message_Messenger.hxx>
#include <BinObjMgt_Persistent.hxx>
#include <BinMDataStd.hxx>
#include <Standard_TypeDef.hxx>
#include <BinMDataStd_NameDriver.hxx>
#include <BinMDataStd_IntegerDriver.hxx>
#include <BinMDataStd_RealDriver.hxx>
#include <BinMDataStd_IntegerArrayDriver.hxx>
#include <BinMDataStd_RealArrayDriver.hxx>
#include <BinMDataStd_UAttributeDriver.hxx>
#include <BinMDataStd_DirectoryDriver.hxx>
#include <BinMDataStd_CommentDriver.hxx>
#include <BinMDataStd_VariableDriver.hxx>
#include <BinMDataStd_ExpressionDriver.hxx>
#include <BinMDataStd_RelationDriver.hxx>
#include <BinMDataStd_NoteBookDriver.hxx>
#include <BinMDataStd_TreeNodeDriver.hxx>
#include <BinMDataStd_ExtStringArrayDriver.hxx>
#include <BinMDataStd_TickDriver.hxx>
#include <BinMDataStd_AsciiStringDriver.hxx>
#include <BinMDataStd_IntPackedMapDriver.hxx>
#include <BinMDataStd_IntegerListDriver.hxx>
#include <BinMDataStd_RealListDriver.hxx>
#include <BinMDataStd_ExtStringListDriver.hxx>
#include <BinMDataStd_BooleanListDriver.hxx>
#include <BinMDataStd_ReferenceListDriver.hxx>
#include <BinMDataStd_BooleanArrayDriver.hxx>
#include <BinMDataStd_ReferenceArrayDriver.hxx>
#include <BinMDataStd_ByteArrayDriver.hxx>
#include <BinMDataStd_NamedDataDriver.hxx>
#include <BinMDF_ADriver.hxx>
#include <TDF_Attribute.hxx>
#include <BinObjMgt_RRelocationTable.hxx>
#include <BinObjMgt_SRelocationTable.hxx>
#include <Standard_Std.hxx>
#include <Standard_Type.hxx>

PYBIND11_MODULE(BinMDataStd, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.BinMDF");
py::module::import("OCCT.Message");
py::module::import("OCCT.BinObjMgt");
py::module::import("OCCT.TDF");

// CLASS: BINMDATASTD
py::class_<BinMDataStd> cls_BinMDataStd(mod, "BinMDataStd", "Storage and Retrieval drivers for modelling attributes.");

// Constructors
cls_BinMDataStd.def(py::init<>());

// Methods
// cls_BinMDataStd.def_static("operator new_", (void * (*)(size_t)) &BinMDataStd::operator new, "None", py::arg("theSize"));
// cls_BinMDataStd.def_static("operator delete_", (void (*)(void *)) &BinMDataStd::operator delete, "None", py::arg("theAddress"));
// cls_BinMDataStd.def_static("operator new[]_", (void * (*)(size_t)) &BinMDataStd::operator new[], "None", py::arg("theSize"));
// cls_BinMDataStd.def_static("operator delete[]_", (void (*)(void *)) &BinMDataStd::operator delete[], "None", py::arg("theAddress"));
// cls_BinMDataStd.def_static("operator new_", (void * (*)(size_t, void *)) &BinMDataStd::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BinMDataStd.def_static("operator delete_", (void (*)(void *, void *)) &BinMDataStd::operator delete, "None", py::arg(""), py::arg(""));
cls_BinMDataStd.def_static("AddDrivers_", (void (*)(const opencascade::handle<BinMDF_ADriverTable> &, const opencascade::handle<Message_Messenger> &)) &BinMDataStd::AddDrivers, "Adds the attribute drivers to <theDriverTable>.", py::arg("theDriverTable"), py::arg("aMsgDrv"));

// CLASS: BINMDATASTD_ASCIISTRINGDRIVER
py::class_<BinMDataStd_AsciiStringDriver, opencascade::handle<BinMDataStd_AsciiStringDriver>, BinMDF_ADriver> cls_BinMDataStd_AsciiStringDriver(mod, "BinMDataStd_AsciiStringDriver", "TDataStd_AsciiString attribute Driver.");

// Constructors
cls_BinMDataStd_AsciiStringDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Methods
cls_BinMDataStd_AsciiStringDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMDataStd_AsciiStringDriver::*)() const) &BinMDataStd_AsciiStringDriver::NewEmpty, "None");
cls_BinMDataStd_AsciiStringDriver.def("Paste", (Standard_Boolean (BinMDataStd_AsciiStringDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const) &BinMDataStd_AsciiStringDriver::Paste, "persistent -> transient (retrieve)", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_BinMDataStd_AsciiStringDriver.def("Paste", (void (BinMDataStd_AsciiStringDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const) &BinMDataStd_AsciiStringDriver::Paste, "transient -> persistent (store)", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_BinMDataStd_AsciiStringDriver.def_static("get_type_name_", (const char * (*)()) &BinMDataStd_AsciiStringDriver::get_type_name, "None");
cls_BinMDataStd_AsciiStringDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMDataStd_AsciiStringDriver::get_type_descriptor, "None");
cls_BinMDataStd_AsciiStringDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMDataStd_AsciiStringDriver::*)() const) &BinMDataStd_AsciiStringDriver::DynamicType, "None");

// CLASS: BINMDATASTD_BOOLEANARRAYDRIVER
py::class_<BinMDataStd_BooleanArrayDriver, opencascade::handle<BinMDataStd_BooleanArrayDriver>, BinMDF_ADriver> cls_BinMDataStd_BooleanArrayDriver(mod, "BinMDataStd_BooleanArrayDriver", "None");

// Constructors
cls_BinMDataStd_BooleanArrayDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Methods
cls_BinMDataStd_BooleanArrayDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMDataStd_BooleanArrayDriver::*)() const) &BinMDataStd_BooleanArrayDriver::NewEmpty, "None");
cls_BinMDataStd_BooleanArrayDriver.def("Paste", (Standard_Boolean (BinMDataStd_BooleanArrayDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const) &BinMDataStd_BooleanArrayDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_BinMDataStd_BooleanArrayDriver.def("Paste", (void (BinMDataStd_BooleanArrayDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const) &BinMDataStd_BooleanArrayDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_BinMDataStd_BooleanArrayDriver.def_static("get_type_name_", (const char * (*)()) &BinMDataStd_BooleanArrayDriver::get_type_name, "None");
cls_BinMDataStd_BooleanArrayDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMDataStd_BooleanArrayDriver::get_type_descriptor, "None");
cls_BinMDataStd_BooleanArrayDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMDataStd_BooleanArrayDriver::*)() const) &BinMDataStd_BooleanArrayDriver::DynamicType, "None");

// CLASS: BINMDATASTD_BOOLEANLISTDRIVER
py::class_<BinMDataStd_BooleanListDriver, opencascade::handle<BinMDataStd_BooleanListDriver>, BinMDF_ADriver> cls_BinMDataStd_BooleanListDriver(mod, "BinMDataStd_BooleanListDriver", "None");

// Constructors
cls_BinMDataStd_BooleanListDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Methods
cls_BinMDataStd_BooleanListDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMDataStd_BooleanListDriver::*)() const) &BinMDataStd_BooleanListDriver::NewEmpty, "None");
cls_BinMDataStd_BooleanListDriver.def("Paste", (Standard_Boolean (BinMDataStd_BooleanListDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const) &BinMDataStd_BooleanListDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_BinMDataStd_BooleanListDriver.def("Paste", (void (BinMDataStd_BooleanListDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const) &BinMDataStd_BooleanListDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_BinMDataStd_BooleanListDriver.def_static("get_type_name_", (const char * (*)()) &BinMDataStd_BooleanListDriver::get_type_name, "None");
cls_BinMDataStd_BooleanListDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMDataStd_BooleanListDriver::get_type_descriptor, "None");
cls_BinMDataStd_BooleanListDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMDataStd_BooleanListDriver::*)() const) &BinMDataStd_BooleanListDriver::DynamicType, "None");

// CLASS: BINMDATASTD_BYTEARRAYDRIVER
py::class_<BinMDataStd_ByteArrayDriver, opencascade::handle<BinMDataStd_ByteArrayDriver>, BinMDF_ADriver> cls_BinMDataStd_ByteArrayDriver(mod, "BinMDataStd_ByteArrayDriver", "None");

// Constructors
cls_BinMDataStd_ByteArrayDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Methods
cls_BinMDataStd_ByteArrayDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMDataStd_ByteArrayDriver::*)() const) &BinMDataStd_ByteArrayDriver::NewEmpty, "None");
cls_BinMDataStd_ByteArrayDriver.def("Paste", (Standard_Boolean (BinMDataStd_ByteArrayDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const) &BinMDataStd_ByteArrayDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_BinMDataStd_ByteArrayDriver.def("Paste", (void (BinMDataStd_ByteArrayDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const) &BinMDataStd_ByteArrayDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_BinMDataStd_ByteArrayDriver.def_static("get_type_name_", (const char * (*)()) &BinMDataStd_ByteArrayDriver::get_type_name, "None");
cls_BinMDataStd_ByteArrayDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMDataStd_ByteArrayDriver::get_type_descriptor, "None");
cls_BinMDataStd_ByteArrayDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMDataStd_ByteArrayDriver::*)() const) &BinMDataStd_ByteArrayDriver::DynamicType, "None");

// CLASS: BINMDATASTD_COMMENTDRIVER
py::class_<BinMDataStd_CommentDriver, opencascade::handle<BinMDataStd_CommentDriver>, BinMDF_ADriver> cls_BinMDataStd_CommentDriver(mod, "BinMDataStd_CommentDriver", "Attribute Driver.");

// Constructors
cls_BinMDataStd_CommentDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Methods
cls_BinMDataStd_CommentDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMDataStd_CommentDriver::*)() const) &BinMDataStd_CommentDriver::NewEmpty, "None");
cls_BinMDataStd_CommentDriver.def("Paste", (Standard_Boolean (BinMDataStd_CommentDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const) &BinMDataStd_CommentDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_BinMDataStd_CommentDriver.def("Paste", (void (BinMDataStd_CommentDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const) &BinMDataStd_CommentDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_BinMDataStd_CommentDriver.def_static("get_type_name_", (const char * (*)()) &BinMDataStd_CommentDriver::get_type_name, "None");
cls_BinMDataStd_CommentDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMDataStd_CommentDriver::get_type_descriptor, "None");
cls_BinMDataStd_CommentDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMDataStd_CommentDriver::*)() const) &BinMDataStd_CommentDriver::DynamicType, "None");

// CLASS: BINMDATASTD_DIRECTORYDRIVER
py::class_<BinMDataStd_DirectoryDriver, opencascade::handle<BinMDataStd_DirectoryDriver>, BinMDF_ADriver> cls_BinMDataStd_DirectoryDriver(mod, "BinMDataStd_DirectoryDriver", "Directory attribute Driver.");

// Constructors
cls_BinMDataStd_DirectoryDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Methods
cls_BinMDataStd_DirectoryDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMDataStd_DirectoryDriver::*)() const) &BinMDataStd_DirectoryDriver::NewEmpty, "None");
cls_BinMDataStd_DirectoryDriver.def("Paste", (Standard_Boolean (BinMDataStd_DirectoryDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const) &BinMDataStd_DirectoryDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_BinMDataStd_DirectoryDriver.def("Paste", (void (BinMDataStd_DirectoryDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const) &BinMDataStd_DirectoryDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_BinMDataStd_DirectoryDriver.def_static("get_type_name_", (const char * (*)()) &BinMDataStd_DirectoryDriver::get_type_name, "None");
cls_BinMDataStd_DirectoryDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMDataStd_DirectoryDriver::get_type_descriptor, "None");
cls_BinMDataStd_DirectoryDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMDataStd_DirectoryDriver::*)() const) &BinMDataStd_DirectoryDriver::DynamicType, "None");

// CLASS: BINMDATASTD_EXPRESSIONDRIVER
py::class_<BinMDataStd_ExpressionDriver, opencascade::handle<BinMDataStd_ExpressionDriver>, BinMDF_ADriver> cls_BinMDataStd_ExpressionDriver(mod, "BinMDataStd_ExpressionDriver", "Attribute Driver.");

// Constructors
cls_BinMDataStd_ExpressionDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Methods
cls_BinMDataStd_ExpressionDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMDataStd_ExpressionDriver::*)() const) &BinMDataStd_ExpressionDriver::NewEmpty, "None");
cls_BinMDataStd_ExpressionDriver.def("Paste", (Standard_Boolean (BinMDataStd_ExpressionDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const) &BinMDataStd_ExpressionDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_BinMDataStd_ExpressionDriver.def("Paste", (void (BinMDataStd_ExpressionDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const) &BinMDataStd_ExpressionDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_BinMDataStd_ExpressionDriver.def_static("get_type_name_", (const char * (*)()) &BinMDataStd_ExpressionDriver::get_type_name, "None");
cls_BinMDataStd_ExpressionDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMDataStd_ExpressionDriver::get_type_descriptor, "None");
cls_BinMDataStd_ExpressionDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMDataStd_ExpressionDriver::*)() const) &BinMDataStd_ExpressionDriver::DynamicType, "None");

// CLASS: BINMDATASTD_EXTSTRINGARRAYDRIVER
py::class_<BinMDataStd_ExtStringArrayDriver, opencascade::handle<BinMDataStd_ExtStringArrayDriver>, BinMDF_ADriver> cls_BinMDataStd_ExtStringArrayDriver(mod, "BinMDataStd_ExtStringArrayDriver", "Array of extended string attribute Driver.");

// Constructors
cls_BinMDataStd_ExtStringArrayDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Methods
cls_BinMDataStd_ExtStringArrayDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMDataStd_ExtStringArrayDriver::*)() const) &BinMDataStd_ExtStringArrayDriver::NewEmpty, "None");
cls_BinMDataStd_ExtStringArrayDriver.def("Paste", (Standard_Boolean (BinMDataStd_ExtStringArrayDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const) &BinMDataStd_ExtStringArrayDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_BinMDataStd_ExtStringArrayDriver.def("Paste", (void (BinMDataStd_ExtStringArrayDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const) &BinMDataStd_ExtStringArrayDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_BinMDataStd_ExtStringArrayDriver.def_static("get_type_name_", (const char * (*)()) &BinMDataStd_ExtStringArrayDriver::get_type_name, "None");
cls_BinMDataStd_ExtStringArrayDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMDataStd_ExtStringArrayDriver::get_type_descriptor, "None");
cls_BinMDataStd_ExtStringArrayDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMDataStd_ExtStringArrayDriver::*)() const) &BinMDataStd_ExtStringArrayDriver::DynamicType, "None");

// CLASS: BINMDATASTD_EXTSTRINGLISTDRIVER
py::class_<BinMDataStd_ExtStringListDriver, opencascade::handle<BinMDataStd_ExtStringListDriver>, BinMDF_ADriver> cls_BinMDataStd_ExtStringListDriver(mod, "BinMDataStd_ExtStringListDriver", "None");

// Constructors
cls_BinMDataStd_ExtStringListDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Methods
cls_BinMDataStd_ExtStringListDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMDataStd_ExtStringListDriver::*)() const) &BinMDataStd_ExtStringListDriver::NewEmpty, "None");
cls_BinMDataStd_ExtStringListDriver.def("Paste", (Standard_Boolean (BinMDataStd_ExtStringListDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const) &BinMDataStd_ExtStringListDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_BinMDataStd_ExtStringListDriver.def("Paste", (void (BinMDataStd_ExtStringListDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const) &BinMDataStd_ExtStringListDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_BinMDataStd_ExtStringListDriver.def_static("get_type_name_", (const char * (*)()) &BinMDataStd_ExtStringListDriver::get_type_name, "None");
cls_BinMDataStd_ExtStringListDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMDataStd_ExtStringListDriver::get_type_descriptor, "None");
cls_BinMDataStd_ExtStringListDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMDataStd_ExtStringListDriver::*)() const) &BinMDataStd_ExtStringListDriver::DynamicType, "None");

// CLASS: BINMDATASTD_INTEGERARRAYDRIVER
py::class_<BinMDataStd_IntegerArrayDriver, opencascade::handle<BinMDataStd_IntegerArrayDriver>, BinMDF_ADriver> cls_BinMDataStd_IntegerArrayDriver(mod, "BinMDataStd_IntegerArrayDriver", "Array of Integer attribute Driver.");

// Constructors
cls_BinMDataStd_IntegerArrayDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Methods
cls_BinMDataStd_IntegerArrayDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMDataStd_IntegerArrayDriver::*)() const) &BinMDataStd_IntegerArrayDriver::NewEmpty, "None");
cls_BinMDataStd_IntegerArrayDriver.def("Paste", (Standard_Boolean (BinMDataStd_IntegerArrayDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const) &BinMDataStd_IntegerArrayDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_BinMDataStd_IntegerArrayDriver.def("Paste", (void (BinMDataStd_IntegerArrayDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const) &BinMDataStd_IntegerArrayDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_BinMDataStd_IntegerArrayDriver.def_static("get_type_name_", (const char * (*)()) &BinMDataStd_IntegerArrayDriver::get_type_name, "None");
cls_BinMDataStd_IntegerArrayDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMDataStd_IntegerArrayDriver::get_type_descriptor, "None");
cls_BinMDataStd_IntegerArrayDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMDataStd_IntegerArrayDriver::*)() const) &BinMDataStd_IntegerArrayDriver::DynamicType, "None");

// CLASS: BINMDATASTD_INTEGERDRIVER
py::class_<BinMDataStd_IntegerDriver, opencascade::handle<BinMDataStd_IntegerDriver>, BinMDF_ADriver> cls_BinMDataStd_IntegerDriver(mod, "BinMDataStd_IntegerDriver", "Integer attribute Driver.");

// Constructors
cls_BinMDataStd_IntegerDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Methods
cls_BinMDataStd_IntegerDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMDataStd_IntegerDriver::*)() const) &BinMDataStd_IntegerDriver::NewEmpty, "None");
cls_BinMDataStd_IntegerDriver.def("Paste", (Standard_Boolean (BinMDataStd_IntegerDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const) &BinMDataStd_IntegerDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_BinMDataStd_IntegerDriver.def("Paste", (void (BinMDataStd_IntegerDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const) &BinMDataStd_IntegerDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_BinMDataStd_IntegerDriver.def_static("get_type_name_", (const char * (*)()) &BinMDataStd_IntegerDriver::get_type_name, "None");
cls_BinMDataStd_IntegerDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMDataStd_IntegerDriver::get_type_descriptor, "None");
cls_BinMDataStd_IntegerDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMDataStd_IntegerDriver::*)() const) &BinMDataStd_IntegerDriver::DynamicType, "None");

// CLASS: BINMDATASTD_INTEGERLISTDRIVER
py::class_<BinMDataStd_IntegerListDriver, opencascade::handle<BinMDataStd_IntegerListDriver>, BinMDF_ADriver> cls_BinMDataStd_IntegerListDriver(mod, "BinMDataStd_IntegerListDriver", "None");

// Constructors
cls_BinMDataStd_IntegerListDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Methods
cls_BinMDataStd_IntegerListDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMDataStd_IntegerListDriver::*)() const) &BinMDataStd_IntegerListDriver::NewEmpty, "None");
cls_BinMDataStd_IntegerListDriver.def("Paste", (Standard_Boolean (BinMDataStd_IntegerListDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const) &BinMDataStd_IntegerListDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_BinMDataStd_IntegerListDriver.def("Paste", (void (BinMDataStd_IntegerListDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const) &BinMDataStd_IntegerListDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_BinMDataStd_IntegerListDriver.def_static("get_type_name_", (const char * (*)()) &BinMDataStd_IntegerListDriver::get_type_name, "None");
cls_BinMDataStd_IntegerListDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMDataStd_IntegerListDriver::get_type_descriptor, "None");
cls_BinMDataStd_IntegerListDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMDataStd_IntegerListDriver::*)() const) &BinMDataStd_IntegerListDriver::DynamicType, "None");

// CLASS: BINMDATASTD_INTPACKEDMAPDRIVER
py::class_<BinMDataStd_IntPackedMapDriver, opencascade::handle<BinMDataStd_IntPackedMapDriver>, BinMDF_ADriver> cls_BinMDataStd_IntPackedMapDriver(mod, "BinMDataStd_IntPackedMapDriver", "TDataStd_IntPackedMap attribute Driver.");

// Constructors
cls_BinMDataStd_IntPackedMapDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Methods
cls_BinMDataStd_IntPackedMapDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMDataStd_IntPackedMapDriver::*)() const) &BinMDataStd_IntPackedMapDriver::NewEmpty, "None");
cls_BinMDataStd_IntPackedMapDriver.def("Paste", (Standard_Boolean (BinMDataStd_IntPackedMapDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const) &BinMDataStd_IntPackedMapDriver::Paste, "persistent -> transient (retrieve)", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_BinMDataStd_IntPackedMapDriver.def("Paste", (void (BinMDataStd_IntPackedMapDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const) &BinMDataStd_IntPackedMapDriver::Paste, "transient -> persistent (store)", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_BinMDataStd_IntPackedMapDriver.def_static("get_type_name_", (const char * (*)()) &BinMDataStd_IntPackedMapDriver::get_type_name, "None");
cls_BinMDataStd_IntPackedMapDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMDataStd_IntPackedMapDriver::get_type_descriptor, "None");
cls_BinMDataStd_IntPackedMapDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMDataStd_IntPackedMapDriver::*)() const) &BinMDataStd_IntPackedMapDriver::DynamicType, "None");

// CLASS: BINMDATASTD_NAMEDDATADRIVER
py::class_<BinMDataStd_NamedDataDriver, opencascade::handle<BinMDataStd_NamedDataDriver>, BinMDF_ADriver> cls_BinMDataStd_NamedDataDriver(mod, "BinMDataStd_NamedDataDriver", "None");

// Constructors
cls_BinMDataStd_NamedDataDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Methods
cls_BinMDataStd_NamedDataDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMDataStd_NamedDataDriver::*)() const) &BinMDataStd_NamedDataDriver::NewEmpty, "None");
cls_BinMDataStd_NamedDataDriver.def("Paste", (Standard_Boolean (BinMDataStd_NamedDataDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const) &BinMDataStd_NamedDataDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_BinMDataStd_NamedDataDriver.def("Paste", (void (BinMDataStd_NamedDataDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const) &BinMDataStd_NamedDataDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_BinMDataStd_NamedDataDriver.def_static("get_type_name_", (const char * (*)()) &BinMDataStd_NamedDataDriver::get_type_name, "None");
cls_BinMDataStd_NamedDataDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMDataStd_NamedDataDriver::get_type_descriptor, "None");
cls_BinMDataStd_NamedDataDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMDataStd_NamedDataDriver::*)() const) &BinMDataStd_NamedDataDriver::DynamicType, "None");

// CLASS: BINMDATASTD_NAMEDRIVER
py::class_<BinMDataStd_NameDriver, opencascade::handle<BinMDataStd_NameDriver>, BinMDF_ADriver> cls_BinMDataStd_NameDriver(mod, "BinMDataStd_NameDriver", "TDataStd_Name attribute Driver.");

// Constructors
cls_BinMDataStd_NameDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Methods
cls_BinMDataStd_NameDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMDataStd_NameDriver::*)() const) &BinMDataStd_NameDriver::NewEmpty, "None");
cls_BinMDataStd_NameDriver.def("Paste", (Standard_Boolean (BinMDataStd_NameDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const) &BinMDataStd_NameDriver::Paste, "persistent -> transient (retrieve)", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_BinMDataStd_NameDriver.def("Paste", (void (BinMDataStd_NameDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const) &BinMDataStd_NameDriver::Paste, "transient -> persistent (store)", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_BinMDataStd_NameDriver.def_static("get_type_name_", (const char * (*)()) &BinMDataStd_NameDriver::get_type_name, "None");
cls_BinMDataStd_NameDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMDataStd_NameDriver::get_type_descriptor, "None");
cls_BinMDataStd_NameDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMDataStd_NameDriver::*)() const) &BinMDataStd_NameDriver::DynamicType, "None");

// CLASS: BINMDATASTD_NOTEBOOKDRIVER
py::class_<BinMDataStd_NoteBookDriver, opencascade::handle<BinMDataStd_NoteBookDriver>, BinMDF_ADriver> cls_BinMDataStd_NoteBookDriver(mod, "BinMDataStd_NoteBookDriver", "NoteBook attribute Driver.");

// Constructors
cls_BinMDataStd_NoteBookDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Methods
cls_BinMDataStd_NoteBookDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMDataStd_NoteBookDriver::*)() const) &BinMDataStd_NoteBookDriver::NewEmpty, "None");
cls_BinMDataStd_NoteBookDriver.def("Paste", (Standard_Boolean (BinMDataStd_NoteBookDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const) &BinMDataStd_NoteBookDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_BinMDataStd_NoteBookDriver.def("Paste", (void (BinMDataStd_NoteBookDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const) &BinMDataStd_NoteBookDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_BinMDataStd_NoteBookDriver.def_static("get_type_name_", (const char * (*)()) &BinMDataStd_NoteBookDriver::get_type_name, "None");
cls_BinMDataStd_NoteBookDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMDataStd_NoteBookDriver::get_type_descriptor, "None");
cls_BinMDataStd_NoteBookDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMDataStd_NoteBookDriver::*)() const) &BinMDataStd_NoteBookDriver::DynamicType, "None");

// CLASS: BINMDATASTD_REALARRAYDRIVER
py::class_<BinMDataStd_RealArrayDriver, opencascade::handle<BinMDataStd_RealArrayDriver>, BinMDF_ADriver> cls_BinMDataStd_RealArrayDriver(mod, "BinMDataStd_RealArrayDriver", "Array of Real attribute Driver.");

// Constructors
cls_BinMDataStd_RealArrayDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Methods
cls_BinMDataStd_RealArrayDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMDataStd_RealArrayDriver::*)() const) &BinMDataStd_RealArrayDriver::NewEmpty, "None");
cls_BinMDataStd_RealArrayDriver.def("Paste", (Standard_Boolean (BinMDataStd_RealArrayDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const) &BinMDataStd_RealArrayDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_BinMDataStd_RealArrayDriver.def("Paste", (void (BinMDataStd_RealArrayDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const) &BinMDataStd_RealArrayDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_BinMDataStd_RealArrayDriver.def_static("get_type_name_", (const char * (*)()) &BinMDataStd_RealArrayDriver::get_type_name, "None");
cls_BinMDataStd_RealArrayDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMDataStd_RealArrayDriver::get_type_descriptor, "None");
cls_BinMDataStd_RealArrayDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMDataStd_RealArrayDriver::*)() const) &BinMDataStd_RealArrayDriver::DynamicType, "None");

// CLASS: BINMDATASTD_REALDRIVER
py::class_<BinMDataStd_RealDriver, opencascade::handle<BinMDataStd_RealDriver>, BinMDF_ADriver> cls_BinMDataStd_RealDriver(mod, "BinMDataStd_RealDriver", "Real attribute Driver.");

// Constructors
cls_BinMDataStd_RealDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Methods
cls_BinMDataStd_RealDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMDataStd_RealDriver::*)() const) &BinMDataStd_RealDriver::NewEmpty, "None");
cls_BinMDataStd_RealDriver.def("Paste", (Standard_Boolean (BinMDataStd_RealDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const) &BinMDataStd_RealDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_BinMDataStd_RealDriver.def("Paste", (void (BinMDataStd_RealDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const) &BinMDataStd_RealDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_BinMDataStd_RealDriver.def_static("get_type_name_", (const char * (*)()) &BinMDataStd_RealDriver::get_type_name, "None");
cls_BinMDataStd_RealDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMDataStd_RealDriver::get_type_descriptor, "None");
cls_BinMDataStd_RealDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMDataStd_RealDriver::*)() const) &BinMDataStd_RealDriver::DynamicType, "None");

// CLASS: BINMDATASTD_REALLISTDRIVER
py::class_<BinMDataStd_RealListDriver, opencascade::handle<BinMDataStd_RealListDriver>, BinMDF_ADriver> cls_BinMDataStd_RealListDriver(mod, "BinMDataStd_RealListDriver", "None");

// Constructors
cls_BinMDataStd_RealListDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Methods
cls_BinMDataStd_RealListDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMDataStd_RealListDriver::*)() const) &BinMDataStd_RealListDriver::NewEmpty, "None");
cls_BinMDataStd_RealListDriver.def("Paste", (Standard_Boolean (BinMDataStd_RealListDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const) &BinMDataStd_RealListDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_BinMDataStd_RealListDriver.def("Paste", (void (BinMDataStd_RealListDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const) &BinMDataStd_RealListDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_BinMDataStd_RealListDriver.def_static("get_type_name_", (const char * (*)()) &BinMDataStd_RealListDriver::get_type_name, "None");
cls_BinMDataStd_RealListDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMDataStd_RealListDriver::get_type_descriptor, "None");
cls_BinMDataStd_RealListDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMDataStd_RealListDriver::*)() const) &BinMDataStd_RealListDriver::DynamicType, "None");

// CLASS: BINMDATASTD_REFERENCEARRAYDRIVER
py::class_<BinMDataStd_ReferenceArrayDriver, opencascade::handle<BinMDataStd_ReferenceArrayDriver>, BinMDF_ADriver> cls_BinMDataStd_ReferenceArrayDriver(mod, "BinMDataStd_ReferenceArrayDriver", "None");

// Constructors
cls_BinMDataStd_ReferenceArrayDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Methods
cls_BinMDataStd_ReferenceArrayDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMDataStd_ReferenceArrayDriver::*)() const) &BinMDataStd_ReferenceArrayDriver::NewEmpty, "None");
cls_BinMDataStd_ReferenceArrayDriver.def("Paste", (Standard_Boolean (BinMDataStd_ReferenceArrayDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const) &BinMDataStd_ReferenceArrayDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_BinMDataStd_ReferenceArrayDriver.def("Paste", (void (BinMDataStd_ReferenceArrayDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const) &BinMDataStd_ReferenceArrayDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_BinMDataStd_ReferenceArrayDriver.def_static("get_type_name_", (const char * (*)()) &BinMDataStd_ReferenceArrayDriver::get_type_name, "None");
cls_BinMDataStd_ReferenceArrayDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMDataStd_ReferenceArrayDriver::get_type_descriptor, "None");
cls_BinMDataStd_ReferenceArrayDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMDataStd_ReferenceArrayDriver::*)() const) &BinMDataStd_ReferenceArrayDriver::DynamicType, "None");

// CLASS: BINMDATASTD_REFERENCELISTDRIVER
py::class_<BinMDataStd_ReferenceListDriver, opencascade::handle<BinMDataStd_ReferenceListDriver>, BinMDF_ADriver> cls_BinMDataStd_ReferenceListDriver(mod, "BinMDataStd_ReferenceListDriver", "None");

// Constructors
cls_BinMDataStd_ReferenceListDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Methods
cls_BinMDataStd_ReferenceListDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMDataStd_ReferenceListDriver::*)() const) &BinMDataStd_ReferenceListDriver::NewEmpty, "None");
cls_BinMDataStd_ReferenceListDriver.def("Paste", (Standard_Boolean (BinMDataStd_ReferenceListDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const) &BinMDataStd_ReferenceListDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_BinMDataStd_ReferenceListDriver.def("Paste", (void (BinMDataStd_ReferenceListDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const) &BinMDataStd_ReferenceListDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_BinMDataStd_ReferenceListDriver.def_static("get_type_name_", (const char * (*)()) &BinMDataStd_ReferenceListDriver::get_type_name, "None");
cls_BinMDataStd_ReferenceListDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMDataStd_ReferenceListDriver::get_type_descriptor, "None");
cls_BinMDataStd_ReferenceListDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMDataStd_ReferenceListDriver::*)() const) &BinMDataStd_ReferenceListDriver::DynamicType, "None");

// CLASS: BINMDATASTD_RELATIONDRIVER
py::class_<BinMDataStd_RelationDriver, opencascade::handle<BinMDataStd_RelationDriver>, BinMDF_ADriver> cls_BinMDataStd_RelationDriver(mod, "BinMDataStd_RelationDriver", "Attribute Driver.");

// Constructors
cls_BinMDataStd_RelationDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Methods
cls_BinMDataStd_RelationDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMDataStd_RelationDriver::*)() const) &BinMDataStd_RelationDriver::NewEmpty, "None");
cls_BinMDataStd_RelationDriver.def("Paste", (Standard_Boolean (BinMDataStd_RelationDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const) &BinMDataStd_RelationDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_BinMDataStd_RelationDriver.def("Paste", (void (BinMDataStd_RelationDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const) &BinMDataStd_RelationDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_BinMDataStd_RelationDriver.def_static("get_type_name_", (const char * (*)()) &BinMDataStd_RelationDriver::get_type_name, "None");
cls_BinMDataStd_RelationDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMDataStd_RelationDriver::get_type_descriptor, "None");
cls_BinMDataStd_RelationDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMDataStd_RelationDriver::*)() const) &BinMDataStd_RelationDriver::DynamicType, "None");

// CLASS: BINMDATASTD_TICKDRIVER
py::class_<BinMDataStd_TickDriver, opencascade::handle<BinMDataStd_TickDriver>, BinMDF_ADriver> cls_BinMDataStd_TickDriver(mod, "BinMDataStd_TickDriver", "Tick attribute driver.");

// Constructors
cls_BinMDataStd_TickDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Methods
cls_BinMDataStd_TickDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMDataStd_TickDriver::*)() const) &BinMDataStd_TickDriver::NewEmpty, "None");
cls_BinMDataStd_TickDriver.def("Paste", (Standard_Boolean (BinMDataStd_TickDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const) &BinMDataStd_TickDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_BinMDataStd_TickDriver.def("Paste", (void (BinMDataStd_TickDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const) &BinMDataStd_TickDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_BinMDataStd_TickDriver.def_static("get_type_name_", (const char * (*)()) &BinMDataStd_TickDriver::get_type_name, "None");
cls_BinMDataStd_TickDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMDataStd_TickDriver::get_type_descriptor, "None");
cls_BinMDataStd_TickDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMDataStd_TickDriver::*)() const) &BinMDataStd_TickDriver::DynamicType, "None");

// CLASS: BINMDATASTD_TREENODEDRIVER
py::class_<BinMDataStd_TreeNodeDriver, opencascade::handle<BinMDataStd_TreeNodeDriver>, BinMDF_ADriver> cls_BinMDataStd_TreeNodeDriver(mod, "BinMDataStd_TreeNodeDriver", "Attribute Driver.");

// Constructors
cls_BinMDataStd_TreeNodeDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Methods
cls_BinMDataStd_TreeNodeDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMDataStd_TreeNodeDriver::*)() const) &BinMDataStd_TreeNodeDriver::NewEmpty, "None");
cls_BinMDataStd_TreeNodeDriver.def("Paste", (Standard_Boolean (BinMDataStd_TreeNodeDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const) &BinMDataStd_TreeNodeDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_BinMDataStd_TreeNodeDriver.def("Paste", (void (BinMDataStd_TreeNodeDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const) &BinMDataStd_TreeNodeDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_BinMDataStd_TreeNodeDriver.def_static("get_type_name_", (const char * (*)()) &BinMDataStd_TreeNodeDriver::get_type_name, "None");
cls_BinMDataStd_TreeNodeDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMDataStd_TreeNodeDriver::get_type_descriptor, "None");
cls_BinMDataStd_TreeNodeDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMDataStd_TreeNodeDriver::*)() const) &BinMDataStd_TreeNodeDriver::DynamicType, "None");

// CLASS: BINMDATASTD_UATTRIBUTEDRIVER
py::class_<BinMDataStd_UAttributeDriver, opencascade::handle<BinMDataStd_UAttributeDriver>, BinMDF_ADriver> cls_BinMDataStd_UAttributeDriver(mod, "BinMDataStd_UAttributeDriver", "Attribute Driver.");

// Constructors
cls_BinMDataStd_UAttributeDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Methods
cls_BinMDataStd_UAttributeDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMDataStd_UAttributeDriver::*)() const) &BinMDataStd_UAttributeDriver::NewEmpty, "None");
cls_BinMDataStd_UAttributeDriver.def("Paste", (Standard_Boolean (BinMDataStd_UAttributeDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const) &BinMDataStd_UAttributeDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_BinMDataStd_UAttributeDriver.def("Paste", (void (BinMDataStd_UAttributeDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const) &BinMDataStd_UAttributeDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_BinMDataStd_UAttributeDriver.def_static("get_type_name_", (const char * (*)()) &BinMDataStd_UAttributeDriver::get_type_name, "None");
cls_BinMDataStd_UAttributeDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMDataStd_UAttributeDriver::get_type_descriptor, "None");
cls_BinMDataStd_UAttributeDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMDataStd_UAttributeDriver::*)() const) &BinMDataStd_UAttributeDriver::DynamicType, "None");

// CLASS: BINMDATASTD_VARIABLEDRIVER
py::class_<BinMDataStd_VariableDriver, opencascade::handle<BinMDataStd_VariableDriver>, BinMDF_ADriver> cls_BinMDataStd_VariableDriver(mod, "BinMDataStd_VariableDriver", "Attribute Driver.");

// Constructors
cls_BinMDataStd_VariableDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Methods
cls_BinMDataStd_VariableDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMDataStd_VariableDriver::*)() const) &BinMDataStd_VariableDriver::NewEmpty, "None");
cls_BinMDataStd_VariableDriver.def("Paste", (Standard_Boolean (BinMDataStd_VariableDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const) &BinMDataStd_VariableDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_BinMDataStd_VariableDriver.def("Paste", (void (BinMDataStd_VariableDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const) &BinMDataStd_VariableDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_BinMDataStd_VariableDriver.def_static("get_type_name_", (const char * (*)()) &BinMDataStd_VariableDriver::get_type_name, "None");
cls_BinMDataStd_VariableDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMDataStd_VariableDriver::get_type_descriptor, "None");
cls_BinMDataStd_VariableDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMDataStd_VariableDriver::*)() const) &BinMDataStd_VariableDriver::DynamicType, "None");


}
