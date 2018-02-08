/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC (info@laughlinresearch.com)

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
#include <pyOCCT_Common.hpp>

#include <LDOM_Document.hxx>
#include <Standard_TypeDef.hxx>
#include <TCollection_AsciiString.hxx>
#include <LDOMParser.hxx>

PYBIND11_MODULE(LDOMParser, mod) {

	// IMPORT
	py::module::import("OCCT.LDOM");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.TCollection");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\LDOMParser.hxx
	py::class_<LDOMParser, std::unique_ptr<LDOMParser, Deleter<LDOMParser>>> cls_LDOMParser(mod, "LDOMParser", "None");
	cls_LDOMParser.def(py::init<>());
	cls_LDOMParser.def("getDocument", (LDOM_Document (LDOMParser::*)()) &LDOMParser::getDocument, "None");
	cls_LDOMParser.def("parse", (Standard_Boolean (LDOMParser::*)(const char *const)) &LDOMParser::parse, "None", py::arg("aFileName"));
	cls_LDOMParser.def("parse", [](LDOMParser &self, std::istream & a0) -> Standard_Boolean { return self.parse(a0); }, py::arg("anInput"));
	cls_LDOMParser.def("parse", [](LDOMParser &self, std::istream & a0, const Standard_Boolean a1) -> Standard_Boolean { return self.parse(a0, a1); }, py::arg("anInput"), py::arg("theTagPerStep"));
	cls_LDOMParser.def("parse", (Standard_Boolean (LDOMParser::*)(std::istream &, const Standard_Boolean, const Standard_Boolean)) &LDOMParser::parse, "None", py::arg("anInput"), py::arg("theTagPerStep"), py::arg("theWithoutRoot"));
	cls_LDOMParser.def("GetError", (const TCollection_AsciiString & (LDOMParser::*)(TCollection_AsciiString &) const ) &LDOMParser::GetError, "None", py::arg("aData"));


}
