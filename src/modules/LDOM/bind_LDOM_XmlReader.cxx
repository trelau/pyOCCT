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
#include <LDOM_MemManager.hxx>
#include <TCollection_AsciiString.hxx>
#include <Standard_TypeDef.hxx>
#include <LDOM_XmlReader.hxx>
#include <Standard_IStream.hxx>
#include <LDOM_OSStream.hxx>
#include <LDOM_BasicElement.hxx>
#include <LDOMBasicString.hxx>
#include <LDOM_BasicNode.hxx>

void bind_LDOM_XmlReader(py::module &mod){

py::class_<LDOM_XmlReader, std::unique_ptr<LDOM_XmlReader, Deleter<LDOM_XmlReader>>> cls_LDOM_XmlReader(mod, "LDOM_XmlReader", "None");

// Constructors
// cls_LDOM_XmlReader.def(py::init<const opencascade::handle<LDOM_MemManager> &, TCollection_AsciiString &>(), py::arg("aDocument"), py::arg("anErrorString"));
// cls_LDOM_XmlReader.def(py::init<const opencascade::handle<LDOM_MemManager> &, TCollection_AsciiString &, const Standard_Boolean>(), py::arg("aDocument"), py::arg("anErrorString"), py::arg("theTagPerStep"));

// Fields

// Methods
// cls_LDOM_XmlReader.def("ReadRecord", (LDOM_XmlReader::RecordType (LDOM_XmlReader::*)(Standard_IStream &, LDOM_OSStream &)) &LDOM_XmlReader::ReadRecord, "None", py::arg("theIStream"), py::arg("theData"));
cls_LDOM_XmlReader.def("GetElement", (LDOM_BasicElement & (LDOM_XmlReader::*)() const) &LDOM_XmlReader::GetElement, "None");
// cls_LDOM_XmlReader.def("CreateElement", (void (LDOM_XmlReader::*)(const char *, const Standard_Integer)) &LDOM_XmlReader::CreateElement, "None", py::arg("theName"), py::arg("theLen"));
// cls_LDOM_XmlReader.def_static("getInteger_", (Standard_Boolean (*)(LDOMBasicString &, const char *, const char *)) &LDOM_XmlReader::getInteger, "None", py::arg("theValue"), py::arg("theStart"), py::arg("theEnd"));

// Enums
py::enum_<LDOM_XmlReader::RecordType>(cls_LDOM_XmlReader, "RecordType", "None")
	.value("XML_UNKNOWN", LDOM_XmlReader::RecordType::XML_UNKNOWN)
	.value("XML_HEADER", LDOM_XmlReader::RecordType::XML_HEADER)
	.value("XML_DOCTYPE", LDOM_XmlReader::RecordType::XML_DOCTYPE)
	.value("XML_COMMENT", LDOM_XmlReader::RecordType::XML_COMMENT)
	.value("XML_START_ELEMENT", LDOM_XmlReader::RecordType::XML_START_ELEMENT)
	.value("XML_END_ELEMENT", LDOM_XmlReader::RecordType::XML_END_ELEMENT)
	.value("XML_FULL_ELEMENT", LDOM_XmlReader::RecordType::XML_FULL_ELEMENT)
	.value("XML_TEXT", LDOM_XmlReader::RecordType::XML_TEXT)
	.value("XML_CDATA", LDOM_XmlReader::RecordType::XML_CDATA)
	.value("XML_EOF", LDOM_XmlReader::RecordType::XML_EOF)
	.export_values();

}