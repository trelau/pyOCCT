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
#include <CDF_MetaDataDriver.hxx>
#include <Standard_TypeDef.hxx>
#include <TCollection_ExtendedString.hxx>
#include <Standard_Handle.hxx>
#include <CDM_Document.hxx>
#include <CDF_FWOSDriver.hxx>
#include <Standard_Type.hxx>
#include <CDM_MetaData.hxx>

void bind_CDF_FWOSDriver(py::module &mod){

py::class_<CDF_FWOSDriver, opencascade::handle<CDF_FWOSDriver>, CDF_MetaDataDriver> cls_CDF_FWOSDriver(mod, "CDF_FWOSDriver", "None");

// Constructors
cls_CDF_FWOSDriver.def(py::init<>());

// Fields

// Methods
cls_CDF_FWOSDriver.def("Find", (Standard_Boolean (CDF_FWOSDriver::*)(const TCollection_ExtendedString &, const TCollection_ExtendedString &, const TCollection_ExtendedString &)) &CDF_FWOSDriver::Find, "indicate whether a file exists corresponding to the folder and the name", py::arg("aFolder"), py::arg("aName"), py::arg("aVersion"));
cls_CDF_FWOSDriver.def("HasReadPermission", (Standard_Boolean (CDF_FWOSDriver::*)(const TCollection_ExtendedString &, const TCollection_ExtendedString &, const TCollection_ExtendedString &)) &CDF_FWOSDriver::HasReadPermission, "None", py::arg("aFolder"), py::arg("aName"), py::arg("aVersion"));
cls_CDF_FWOSDriver.def("FindFolder", (Standard_Boolean (CDF_FWOSDriver::*)(const TCollection_ExtendedString &)) &CDF_FWOSDriver::FindFolder, "None", py::arg("aFolder"));
cls_CDF_FWOSDriver.def("DefaultFolder", (TCollection_ExtendedString (CDF_FWOSDriver::*)()) &CDF_FWOSDriver::DefaultFolder, "None");
cls_CDF_FWOSDriver.def("BuildFileName", (TCollection_ExtendedString (CDF_FWOSDriver::*)(const opencascade::handle<CDM_Document> &)) &CDF_FWOSDriver::BuildFileName, "None", py::arg("aDocument"));
cls_CDF_FWOSDriver.def("SetName", (TCollection_ExtendedString (CDF_FWOSDriver::*)(const opencascade::handle<CDM_Document> &, const TCollection_ExtendedString &)) &CDF_FWOSDriver::SetName, "None", py::arg("aDocument"), py::arg("aName"));
cls_CDF_FWOSDriver.def_static("get_type_name_", (const char * (*)()) &CDF_FWOSDriver::get_type_name, "None");
cls_CDF_FWOSDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &CDF_FWOSDriver::get_type_descriptor, "None");
cls_CDF_FWOSDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (CDF_FWOSDriver::*)() const) &CDF_FWOSDriver::DynamicType, "None");

// Enums

}