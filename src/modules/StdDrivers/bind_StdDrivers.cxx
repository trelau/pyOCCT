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
#include <Standard_Transient.hxx>
#include <Standard_GUID.hxx>
#include <TDocStd_Application.hxx>
#include <StdObjMgt_MapOfInstantiators.hxx>
#include <StdDrivers.hxx>

void bind_StdDrivers(py::module &mod){

py::class_<StdDrivers, std::unique_ptr<StdDrivers>> cls_StdDrivers(mod, "StdDrivers", "None");

// Constructors

// Fields

// Methods
cls_StdDrivers.def_static("Factory_", (opencascade::handle<Standard_Transient> (*)(const Standard_GUID &)) &StdDrivers::Factory, "Depending from the ID, returns a list of storage or retrieval attribute drivers. Used for plugin", py::arg("aGUID"));
cls_StdDrivers.def_static("DefineFormat_", (void (*)(const opencascade::handle<TDocStd_Application> &)) &StdDrivers::DefineFormat, "Defines format 'MDTV-Standard' and registers its retrieval driver in the specified application", py::arg("theApp"));
cls_StdDrivers.def_static("BindTypes_", (void (*)(StdObjMgt_MapOfInstantiators &)) &StdDrivers::BindTypes, "Register types.", py::arg("theMap"));

// Enums

}