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
#include <Standard_TypeDef.hxx>
#include <Standard_OStream.hxx>
#include <LDOM_Document.hxx>
#include <LDOM_Node.hxx>
#include <LDOM_XmlWriter.hxx>
#include <LDOMBasicString.hxx>

void bind_LDOM_XmlWriter(py::module &mod){

py::class_<LDOM_XmlWriter> cls_LDOM_XmlWriter(mod, "LDOM_XmlWriter", "None");

// Constructors
cls_LDOM_XmlWriter.def(py::init<>());
cls_LDOM_XmlWriter.def(py::init<const char *>(), py::arg("theEncoding"));

// Fields

// Methods
cls_LDOM_XmlWriter.def("SetIndentation", (void (LDOM_XmlWriter::*)(const Standard_Integer)) &LDOM_XmlWriter::SetIndentation, "None", py::arg("theIndent"));
cls_LDOM_XmlWriter.def("Write", (void (LDOM_XmlWriter::*)(Standard_OStream &, const LDOM_Document &)) &LDOM_XmlWriter::Write, "None", py::arg("theOStream"), py::arg("theDoc"));
cls_LDOM_XmlWriter.def("Write", (void (LDOM_XmlWriter::*)(Standard_OStream &, const LDOM_Node &)) &LDOM_XmlWriter::Write, "None", py::arg("theOStream"), py::arg("theNode"));

// Enums

}