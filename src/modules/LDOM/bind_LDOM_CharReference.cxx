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
#include <LDOM_CharReference.hxx>

void bind_LDOM_CharReference(py::module &mod){

py::class_<LDOM_CharReference, std::unique_ptr<LDOM_CharReference>> cls_LDOM_CharReference(mod, "LDOM_CharReference", "None");

// Constructors

// Fields

// Methods
// cls_LDOM_CharReference.def_static("Decode_", [](char * theSrc, Standard_Integer & theLen){ char * rv = LDOM_CharReference::Decode(theSrc, theLen); return std::tuple<char *, Standard_Integer &>(rv, theLen); }, "None", py::arg("theSrc"), py::arg("theLen"));
// cls_LDOM_CharReference.def_static("Encode_", [](const char * theSrc, Standard_Integer & theLen, const Standard_Boolean isAttribute){ char * rv = LDOM_CharReference::Encode(theSrc, theLen, isAttribute); return std::tuple<char *, Standard_Integer &>(rv, theLen); }, "None", py::arg("theSrc"), py::arg("theLen"), py::arg("isAttribute"));

// Enums

}