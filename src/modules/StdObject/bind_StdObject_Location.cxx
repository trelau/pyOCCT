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
#include <StdObjMgt_Persistent.hxx>
#include <TopLoc_Location.hxx>
#include <StdObject_Location.hxx>
#include <StdObjMgt_TransientPersistentMap.hxx>
#include <Standard_Handle.hxx>
#include <StdObjMgt_ReadData.hxx>
#include <StdObjMgt_WriteData.hxx>

void bind_StdObject_Location(py::module &mod){

py::class_<StdObject_Location, std::unique_ptr<StdObject_Location, Deleter<StdObject_Location>>> cls_StdObject_Location(mod, "StdObject_Location", "None");

// Constructors

// Fields

// Methods
cls_StdObject_Location.def("PChildren", (void (StdObject_Location::*)(StdObjMgt_Persistent::SequenceOfPersistent &) const) &StdObject_Location::PChildren, "Gets persistent child objects", py::arg("theChildren"));
// cls_StdObject_Location.def("Import", (TopLoc_Location (StdObject_Location::*)() const) &StdObject_Location::Import, "Import transient object from the persistent data.");
cls_StdObject_Location.def_static("Translate_", (StdObject_Location (*)(const TopLoc_Location &, StdObjMgt_TransientPersistentMap &)) &StdObject_Location::Translate, "Creates a persistent wrapper object for a location", py::arg("theLoc"), py::arg("theMap"));

// Enums

}