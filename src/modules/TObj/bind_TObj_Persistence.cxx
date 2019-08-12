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
#include <Standard_Handle.hxx>
#include <TObj_Object.hxx>
#include <Standard_TypeDef.hxx>
#include <TDF_Label.hxx>
#include <Standard_OStream.hxx>
#include <TObj_Container.hxx>
#include <TObj_Persistence.hxx>

void bind_TObj_Persistence(py::module &mod){

py::class_<TObj_Persistence, std::unique_ptr<TObj_Persistence, py::nodelete>> cls_TObj_Persistence(mod, "TObj_Persistence", "This class is intended to be a root of tools (one per class) to manage persistence of objects inherited from TObj_Object It provides a mechanism to recover correctly typed objects (subtypes of TObj_Object) out of their persistent names");

// Fields

// Methods
cls_TObj_Persistence.def_static("CreateNewObject_", (opencascade::handle<TObj_Object> (*)(const Standard_CString, const TDF_Label &)) &TObj_Persistence::CreateNewObject, "Creates and returns a new object of the registered type If the type is not registered, returns Null handle", py::arg("theType"), py::arg("theLabel"));
cls_TObj_Persistence.def_static("DumpTypes_", (void (*)(Standard_OStream &)) &TObj_Persistence::DumpTypes, "Dumps names of all the types registered for persistence to the specified stream", py::arg("theOs"));

// Enums

}