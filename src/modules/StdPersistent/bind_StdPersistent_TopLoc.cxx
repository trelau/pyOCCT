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
#include <StdObjMgt_SharedObject.hxx>
#include <TopLoc_Datum3D.hxx>
#include <StdObjMgt_ReadData.hxx>
#include <StdObjMgt_WriteData.hxx>
#include <StdObjMgt_Persistent.hxx>
#include <Standard_TypeDef.hxx>
#include <StdPersistent_TopLoc.hxx>
#include <TopLoc_Location.hxx>
#include <Standard_Handle.hxx>
#include <StdObject_Location.hxx>
#include <StdObjMgt_TransientPersistentMap.hxx>

void bind_StdPersistent_TopLoc(py::module &mod){

py::class_<StdPersistent_TopLoc, std::unique_ptr<StdPersistent_TopLoc, Deleter<StdPersistent_TopLoc>>> cls_StdPersistent_TopLoc(mod, "StdPersistent_TopLoc", "None");

// Constructors

// Fields

// Methods
// cls_StdPersistent_TopLoc.def_static("Translate_", (opencascade::handle<ItemLocation> (*)(const TopLoc_Location &, StdObjMgt_TransientPersistentMap &)) &StdPersistent_TopLoc::Translate, "None", py::arg("theLoc"), py::arg("theMap"));
// cls_StdPersistent_TopLoc.def_static("Translate_", (opencascade::handle<Datum3D> (*)(const opencascade::handle<TopLoc_Datum3D> &, StdObjMgt_TransientPersistentMap &)) &StdPersistent_TopLoc::Translate, "None", py::arg("theDatum"), py::arg("theMap"));

// Enums

}