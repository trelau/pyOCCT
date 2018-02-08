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

#include <LDOMBasicString.hxx>
#include <LDOMString.hxx>
#include <Standard_TypeDef.hxx>
#include <LDOM_MemManager.hxx>

PYBIND11_MODULE(LDOMString, mod) {

	// IMPORT
	py::module::import("OCCT.LDOMBasicString");
	py::module::import("OCCT.Standard");

	py::module other_mod;

	// IMPORT GUARDS
	struct ImportLDOM{
		ImportLDOM() { py::module::import("OCCT.LDOM"); }
	};


	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\LDOMString.hxx
	py::class_<LDOMString, std::unique_ptr<LDOMString, Deleter<LDOMString>>, LDOMBasicString> cls_LDOMString(mod, "LDOMString", "None");
	cls_LDOMString.def(py::init<>());
	cls_LDOMString.def(py::init([] (const LDOMString &other) {return new LDOMString(other);}), "Copy constructor", py::arg("other"));
	cls_LDOMString.def(py::init<const Standard_Integer>(), py::arg("aValue"));
	cls_LDOMString.def(py::init<const char *>(), py::arg("aValue"));
	cls_LDOMString.def("getOwnerDocument", (const LDOM_MemManager & (LDOMString::*)() const ) &LDOMString::getOwnerDocument, "None", py::call_guard<ImportLDOM>());
	// FIXME cls_LDOMString.def("assign", (LDOMString & (LDOMString::*)(const LDOM_NullPtr *)) &LDOMString::operator=, py::is_operator(), "None", py::arg("aNull"));
	cls_LDOMString.def("assign", (LDOMString & (LDOMString::*)(const LDOMString &)) &LDOMString::operator=, py::is_operator(), "None", py::arg("anOther"));


}
