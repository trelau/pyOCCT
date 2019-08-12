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
#include <Standard_Transient.hxx>
#include <Standard_TypeDef.hxx>
#include <LDOMBasicString.hxx>
#include <LDOM_MemManager.hxx>
#include <LDOM_BasicElement.hxx>
#include <LDOM_Document.hxx>
#include <LDOMParser.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Type.hxx>

void bind_LDOM_MemManager(py::module &mod){

py::class_<LDOM_MemManager, opencascade::handle<LDOM_MemManager>, Standard_Transient> cls_LDOM_MemManager(mod, "LDOM_MemManager", "None");

// Constructors
cls_LDOM_MemManager.def(py::init<const Standard_Integer>(), py::arg("aBlockSize"));

// Fields

// Methods
cls_LDOM_MemManager.def("Allocate", (void * (LDOM_MemManager::*)(const Standard_Integer)) &LDOM_MemManager::Allocate, "None", py::arg("aSize"));
// cls_LDOM_MemManager.def("HashedAllocate", [](LDOM_MemManager &self, const char * aString, const Standard_Integer theLen, Standard_Integer & theHash){ const char * rv = self.HashedAllocate(aString, theLen, theHash); return std::tuple<const char *, Standard_Integer &>(rv, theHash); }, "None", py::arg("aString"), py::arg("theLen"), py::arg("theHash"));
// cls_LDOM_MemManager.def("HashedAllocate", (void (LDOM_MemManager::*)(const char *, const Standard_Integer, LDOMBasicString &)) &LDOM_MemManager::HashedAllocate, "None", py::arg("aString"), py::arg("theLen"), py::arg("theResult"));
// cls_LDOM_MemManager.def_static("Hash_", (Standard_Integer (*)(const char *, const Standard_Integer)) &LDOM_MemManager::Hash, "None", py::arg("theString"), py::arg("theLen"));
// cls_LDOM_MemManager.def_static("CompareStrings_", (Standard_Boolean (*)(const char *, const Standard_Integer, const char *)) &LDOM_MemManager::CompareStrings, "None", py::arg("theString"), py::arg("theHashValue"), py::arg("theHashedStr"));
cls_LDOM_MemManager.def("Self", (const LDOM_MemManager & (LDOM_MemManager::*)() const) &LDOM_MemManager::Self, "None");
cls_LDOM_MemManager.def("RootElement", (const LDOM_BasicElement * (LDOM_MemManager::*)() const) &LDOM_MemManager::RootElement, "None");
cls_LDOM_MemManager.def_static("get_type_name_", (const char * (*)()) &LDOM_MemManager::get_type_name, "None");
cls_LDOM_MemManager.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &LDOM_MemManager::get_type_descriptor, "None");
cls_LDOM_MemManager.def("DynamicType", (const opencascade::handle<Standard_Type> & (LDOM_MemManager::*)() const) &LDOM_MemManager::DynamicType, "None");

// Enums

}