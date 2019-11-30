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
#include <StdLDrivers_DocumentRetrievalDriver.hxx>
#include <Standard_Std.hxx>
#include <StdDrivers_DocumentRetrievalDriver.hxx>
#include <Standard_Type.hxx>

PYBIND11_MODULE(StdDrivers, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.TDocStd");
py::module::import("OCCT.StdObjMgt");
py::module::import("OCCT.StdLDrivers");

// CLASS: STDDRIVERS
py::class_<StdDrivers> cls_StdDrivers(mod, "StdDrivers", "None");

// Methods
cls_StdDrivers.def_static("Factory_", (opencascade::handle<Standard_Transient> (*)(const Standard_GUID &)) &StdDrivers::Factory, "Depending from the ID, returns a list of storage or retrieval attribute drivers. Used for plugin", py::arg("aGUID"));
cls_StdDrivers.def_static("DefineFormat_", (void (*)(const opencascade::handle<TDocStd_Application> &)) &StdDrivers::DefineFormat, "Defines format 'MDTV-Standard' and registers its retrieval driver in the specified application", py::arg("theApp"));
cls_StdDrivers.def_static("BindTypes_", (void (*)(StdObjMgt_MapOfInstantiators &)) &StdDrivers::BindTypes, "Register types.", py::arg("theMap"));

// CLASS: STDDRIVERS_DOCUMENTRETRIEVALDRIVER
py::class_<StdDrivers_DocumentRetrievalDriver, opencascade::handle<StdDrivers_DocumentRetrievalDriver>, StdLDrivers_DocumentRetrievalDriver> cls_StdDrivers_DocumentRetrievalDriver(mod, "StdDrivers_DocumentRetrievalDriver", "retrieval driver of a Part document");

// Methods
cls_StdDrivers_DocumentRetrievalDriver.def_static("get_type_name_", (const char * (*)()) &StdDrivers_DocumentRetrievalDriver::get_type_name, "None");
cls_StdDrivers_DocumentRetrievalDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StdDrivers_DocumentRetrievalDriver::get_type_descriptor, "None");
cls_StdDrivers_DocumentRetrievalDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (StdDrivers_DocumentRetrievalDriver::*)() const) &StdDrivers_DocumentRetrievalDriver::DynamicType, "None");


}
