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
#include <XCAFDoc_Note.hxx>
#include <Standard_Handle.hxx>
#include <XCAFDoc_NoteBinData.hxx>
#include <Standard_Type.hxx>
#include <Standard_GUID.hxx>
#include <TDF_Label.hxx>
#include <TCollection_ExtendedString.hxx>
#include <TCollection_AsciiString.hxx>
#include <OSD_File.hxx>
#include <TColStd_HArray1OfByte.hxx>
#include <Standard_TypeDef.hxx>
#include <TDF_Attribute.hxx>
#include <TDF_RelocationTable.hxx>
#include <Standard_OStream.hxx>

void bind_XCAFDoc_NoteBinData(py::module &mod){

py::class_<XCAFDoc_NoteBinData, opencascade::handle<XCAFDoc_NoteBinData>, XCAFDoc_Note> cls_XCAFDoc_NoteBinData(mod, "XCAFDoc_NoteBinData", "None");

// Constructors
cls_XCAFDoc_NoteBinData.def(py::init<>());

// Fields

// Methods
cls_XCAFDoc_NoteBinData.def_static("get_type_name_", (const char * (*)()) &XCAFDoc_NoteBinData::get_type_name, "None");
cls_XCAFDoc_NoteBinData.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XCAFDoc_NoteBinData::get_type_descriptor, "None");
cls_XCAFDoc_NoteBinData.def("DynamicType", (const opencascade::handle<Standard_Type> & (XCAFDoc_NoteBinData::*)() const) &XCAFDoc_NoteBinData::DynamicType, "None");
cls_XCAFDoc_NoteBinData.def_static("GetID_", (const Standard_GUID & (*)()) &XCAFDoc_NoteBinData::GetID, "Returns default attribute GUID");
cls_XCAFDoc_NoteBinData.def_static("Get_", (opencascade::handle<XCAFDoc_NoteBinData> (*)(const TDF_Label &)) &XCAFDoc_NoteBinData::Get, "Finds a binary data attribute on the given label and returns it, if it is found", py::arg("theLabel"));
cls_XCAFDoc_NoteBinData.def_static("Set_", (opencascade::handle<XCAFDoc_NoteBinData> (*)(const TDF_Label &, const TCollection_ExtendedString &, const TCollection_ExtendedString &, const TCollection_ExtendedString &, const TCollection_AsciiString &, OSD_File &)) &XCAFDoc_NoteBinData::Set, "Create (if not exist) a binary note with data loaded from a binary file.", py::arg("theLabel"), py::arg("theUserName"), py::arg("theTimeStamp"), py::arg("theTitle"), py::arg("theMIMEtype"), py::arg("theFile"));
cls_XCAFDoc_NoteBinData.def_static("Set_", (opencascade::handle<XCAFDoc_NoteBinData> (*)(const TDF_Label &, const TCollection_ExtendedString &, const TCollection_ExtendedString &, const TCollection_ExtendedString &, const TCollection_AsciiString &, const opencascade::handle<TColStd_HArray1OfByte> &)) &XCAFDoc_NoteBinData::Set, "Create (if not exist) a binary note byte data array.", py::arg("theLabel"), py::arg("theUserName"), py::arg("theTimeStamp"), py::arg("theTitle"), py::arg("theMIMEtype"), py::arg("theData"));
cls_XCAFDoc_NoteBinData.def("Set", (Standard_Boolean (XCAFDoc_NoteBinData::*)(const TCollection_ExtendedString &, const TCollection_AsciiString &, OSD_File &)) &XCAFDoc_NoteBinData::Set, "Sets title, MIME type and data from a binary file.", py::arg("theTitle"), py::arg("theMIMEtype"), py::arg("theFile"));
cls_XCAFDoc_NoteBinData.def("Set", (void (XCAFDoc_NoteBinData::*)(const TCollection_ExtendedString &, const TCollection_AsciiString &, const opencascade::handle<TColStd_HArray1OfByte> &)) &XCAFDoc_NoteBinData::Set, "Sets title, MIME type and data from a byte array.", py::arg("theTitle"), py::arg("theMIMEtype"), py::arg("theData"));
cls_XCAFDoc_NoteBinData.def("Title", (const TCollection_ExtendedString & (XCAFDoc_NoteBinData::*)() const) &XCAFDoc_NoteBinData::Title, "Returns the note title.");
cls_XCAFDoc_NoteBinData.def("MIMEtype", (const TCollection_AsciiString & (XCAFDoc_NoteBinData::*)() const) &XCAFDoc_NoteBinData::MIMEtype, "Returns data MIME type.");
cls_XCAFDoc_NoteBinData.def("Size", (Standard_Integer (XCAFDoc_NoteBinData::*)() const) &XCAFDoc_NoteBinData::Size, "Size of data in bytes.");
cls_XCAFDoc_NoteBinData.def("Data", (const opencascade::handle<TColStd_HArray1OfByte> & (XCAFDoc_NoteBinData::*)() const) &XCAFDoc_NoteBinData::Data, "Returns byte data array.");
cls_XCAFDoc_NoteBinData.def("ID", (const Standard_GUID & (XCAFDoc_NoteBinData::*)() const) &XCAFDoc_NoteBinData::ID, "None");
cls_XCAFDoc_NoteBinData.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XCAFDoc_NoteBinData::*)() const) &XCAFDoc_NoteBinData::NewEmpty, "None");
cls_XCAFDoc_NoteBinData.def("Restore", (void (XCAFDoc_NoteBinData::*)(const opencascade::handle<TDF_Attribute> &)) &XCAFDoc_NoteBinData::Restore, "None", py::arg("theAttrFrom"));
cls_XCAFDoc_NoteBinData.def("Paste", (void (XCAFDoc_NoteBinData::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &XCAFDoc_NoteBinData::Paste, "None", py::arg("theAttrInto"), py::arg("theRT"));
cls_XCAFDoc_NoteBinData.def("Dump", (Standard_OStream & (XCAFDoc_NoteBinData::*)(Standard_OStream &) const) &XCAFDoc_NoteBinData::Dump, "None", py::arg("theOS"));

// Enums

}