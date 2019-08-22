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
#include <LDOMString.hxx>
#include <LDOM_DocumentType.hxx>
#include <LDOM_LDOMImplementation.hxx>

void bind_LDOM_LDOMImplementation(py::module &mod){

py::class_<LDOM_LDOMImplementation> cls_LDOM_LDOMImplementation(mod, "LDOM_LDOMImplementation", "None");

// Constructors

// Fields

// Methods
cls_LDOM_LDOMImplementation.def_static("createDocument_", (LDOM_Document (*)(const LDOMString &, const LDOMString &, const LDOM_DocumentType &)) &LDOM_LDOMImplementation::createDocument, "None", py::arg("aNamespaceURI"), py::arg("aQualifiedName"), py::arg("aDocType"));

// Enums

}