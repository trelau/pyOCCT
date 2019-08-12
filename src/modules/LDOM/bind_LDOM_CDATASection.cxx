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
#include <LDOM_Text.hxx>
#include <LDOM_CDATASection.hxx>
#include <LDOM_CharacterData.hxx>
#include <LDOM_Document.hxx>
#include <LDOM_BasicText.hxx>
#include <Standard_Handle.hxx>
#include <LDOM_MemManager.hxx>

void bind_LDOM_CDATASection(py::module &mod){

py::class_<LDOM_CDATASection, std::unique_ptr<LDOM_CDATASection, Deleter<LDOM_CDATASection>>, LDOM_Text> cls_LDOM_CDATASection(mod, "LDOM_CDATASection", "None");

// Constructors
cls_LDOM_CDATASection.def(py::init<>());
cls_LDOM_CDATASection.def(py::init<const LDOM_CDATASection &>(), py::arg("theOther"));

// Fields

// Methods
// cls_LDOM_CDATASection.def("operator=", (LDOM_CDATASection & (LDOM_CDATASection::*)(const LDOM_NullPtr *)) &LDOM_CDATASection::operator=, "None", py::arg("theNull"));
// cls_LDOM_CDATASection.def("operator=", (LDOM_CDATASection & (LDOM_CDATASection::*)(const LDOM_CDATASection &)) &LDOM_CDATASection::operator=, "None", py::arg("theOther"));

// Enums

}