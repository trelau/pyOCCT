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
#include <pyOCCT_Common.hxx>

#include <Utils_SALOME_Exception.hxx>

PYBIND11_MODULE(Utils, mod) {

	// FUNCTIONS
	/* FIXME
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\Utils_SALOME_Exception.hxx
	mod.def("bits_left", (std::ostream & (*)(std::ostream &, const SALOME_Exception &)) &operator<<, py::is_operator(), "None", py::arg(""), py::arg(""));
	*/
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\Utils_SALOME_Exception.hxx
	mod.def("makeText", (const char * (*)(const char *, const char *, const unsigned int)) &makeText, "None", py::arg("text"), py::arg("fileName"), py::arg("lineNumber"));

	// CLASSES
	/*
	py::class_<SALOME_Exception, std::exception> cls_SALOME_Exception(mod, "SALOME_Exception", "None");
	cls_SALOME_Exception.def(py::init<const char *>(), py::arg("text"));
	cls_SALOME_Exception.def(py::init<const char *, const char *>(), py::arg("text"), py::arg("fileName"));
	cls_SALOME_Exception.def(py::init<const char *, const char *, const unsigned int>(), py::arg("text"), py::arg("fileName"), py::arg("lineNumber"));
	cls_SALOME_Exception.def(py::init([] (const SALOME_Exception &other) {return new SALOME_Exception(other);}), "Copy constructor", py::arg("other"));
	cls_SALOME_Exception.def("what", (const char * (SALOME_Exception::*)() const ) &SALOME_Exception::what, "None");
	*/

	py::register_exception<SALOME_Exception>(mod, "PySALOME_Exception");

}
