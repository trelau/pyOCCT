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
#include <LDOM_Document.hxx>
#include <Standard_TypeDef.hxx>
#include <TCollection_AsciiString.hxx>
#include <LDOM_Element.hxx>
#include <Standard_IStream.hxx>
#include <LDOMParser.hxx>
#include <LDOM_XmlReader.hxx>
#include <Standard_Handle.hxx>
#include <LDOM_MemManager.hxx>
#include <LDOM_OSStream.hxx>

void bind_LDOMParser(py::module &mod){

py::class_<LDOMParser> cls_LDOMParser(mod, "LDOMParser", "None");

// Constructors
cls_LDOMParser.def(py::init<>());

// Fields

// Methods
cls_LDOMParser.def("getDocument", (LDOM_Document (LDOMParser::*)()) &LDOMParser::getDocument, "None", py::call_guard<ImportLDOM>());
cls_LDOMParser.def("parse", (Standard_Boolean (LDOMParser::*)(const char *const)) &LDOMParser::parse, "None", py::arg("aFileName"));
cls_LDOMParser.def("parse", [](LDOMParser &self, std::istream & a0) -> Standard_Boolean { return self.parse(a0); });
cls_LDOMParser.def("parse", [](LDOMParser &self, std::istream & a0, const Standard_Boolean a1) -> Standard_Boolean { return self.parse(a0, a1); });
cls_LDOMParser.def("parse", (Standard_Boolean (LDOMParser::*)(std::istream &, const Standard_Boolean, const Standard_Boolean)) &LDOMParser::parse, "None", py::arg("anInput"), py::arg("theTagPerStep"), py::arg("theWithoutRoot"));
cls_LDOMParser.def("GetError", (const TCollection_AsciiString & (LDOMParser::*)(TCollection_AsciiString &) const) &LDOMParser::GetError, "None", py::arg("aData"));

// Enums

}