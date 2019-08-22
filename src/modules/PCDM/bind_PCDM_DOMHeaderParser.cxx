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
#include <LDOMParser.hxx>
#include <TCollection_AsciiString.hxx>
#include <Standard_TypeDef.hxx>
#include <LDOM_Element.hxx>
#include <LDOMString.hxx>
#include <PCDM_DOMHeaderParser.hxx>

void bind_PCDM_DOMHeaderParser(py::module &mod){

py::class_<PCDM_DOMHeaderParser, LDOMParser> cls_PCDM_DOMHeaderParser(mod, "PCDM_DOMHeaderParser", "None");

// Constructors

// Fields

// Methods
// cls_PCDM_DOMHeaderParser.def("SetStartElementName", (void (PCDM_DOMHeaderParser::*)(const TCollection_AsciiString &)) &PCDM_DOMHeaderParser::SetStartElementName, "None", py::arg("aStartElementName"));
// cls_PCDM_DOMHeaderParser.def("SetEndElementName", (void (PCDM_DOMHeaderParser::*)(const TCollection_AsciiString &)) &PCDM_DOMHeaderParser::SetEndElementName, "None", py::arg("anEndElementName"));
cls_PCDM_DOMHeaderParser.def("startElement", (Standard_Boolean (PCDM_DOMHeaderParser::*)()) &PCDM_DOMHeaderParser::startElement, "None");
cls_PCDM_DOMHeaderParser.def("endElement", (Standard_Boolean (PCDM_DOMHeaderParser::*)()) &PCDM_DOMHeaderParser::endElement, "None");
cls_PCDM_DOMHeaderParser.def("GetElement", (const LDOM_Element & (PCDM_DOMHeaderParser::*)() const) &PCDM_DOMHeaderParser::GetElement, "None");

// Enums

}