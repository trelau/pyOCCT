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
#include <BinMDF_ADriverTable.hxx>
#include <Message_Messenger.hxx>
#include <BinTObjDrivers.hxx>

void bind_BinTObjDrivers(py::module &mod){

py::class_<BinTObjDrivers, std::unique_ptr<BinTObjDrivers>> cls_BinTObjDrivers(mod, "BinTObjDrivers", "Class for registering storage/retrieval drivers for TObj Bin persistence");

// Constructors

// Fields

// Methods
cls_BinTObjDrivers.def_static("Factory_", (const opencascade::handle<Standard_Transient> & (*)(const Standard_GUID &)) &BinTObjDrivers::Factory, "None", py::arg("aGUID"));
cls_BinTObjDrivers.def_static("DefineFormat_", (void (*)(const opencascade::handle<TDocStd_Application> &)) &BinTObjDrivers::DefineFormat, "Defines format 'TObjBin' and registers its read and write drivers in the specified application", py::arg("theApp"));
cls_BinTObjDrivers.def_static("AddDrivers_", (void (*)(const opencascade::handle<BinMDF_ADriverTable> &, const opencascade::handle<Message_Messenger> &)) &BinTObjDrivers::AddDrivers, "None", py::arg("aDriverTable"), py::arg("aMsgDrv"));

// Enums

}