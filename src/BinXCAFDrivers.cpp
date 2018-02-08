/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC (info@laughlinresearch.com)

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
#include <pyOCCT_Common.hpp>

#include <BinDrivers_DocumentStorageDriver.hxx>
#include <Standard_Handle.hxx>
#include <BinMDF_ADriverTable.hxx>
#include <CDM_MessageDriver.hxx>
#include <Standard_Type.hxx>
#include <BinXCAFDrivers_DocumentStorageDriver.hxx>
#include <BinDrivers_DocumentRetrievalDriver.hxx>
#include <BinXCAFDrivers_DocumentRetrievalDriver.hxx>
#include <Standard_Transient.hxx>
#include <Standard_GUID.hxx>
#include <TDocStd_Application.hxx>
#include <BinXCAFDrivers.hxx>

PYBIND11_MODULE(BinXCAFDrivers, mod) {

	// IMPORT
	py::module::import("OCCT.BinDrivers");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.BinMDF");
	py::module::import("OCCT.CDM");
	py::module::import("OCCT.TDocStd");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\BinXCAFDrivers_DocumentStorageDriver.hxx
	py::class_<BinXCAFDrivers_DocumentStorageDriver, opencascade::handle<BinXCAFDrivers_DocumentStorageDriver>, BinDrivers_DocumentStorageDriver> cls_BinXCAFDrivers_DocumentStorageDriver(mod, "BinXCAFDrivers_DocumentStorageDriver", "None");
	cls_BinXCAFDrivers_DocumentStorageDriver.def(py::init<>());
	cls_BinXCAFDrivers_DocumentStorageDriver.def("AttributeDrivers", (opencascade::handle<BinMDF_ADriverTable> (BinXCAFDrivers_DocumentStorageDriver::*)(const opencascade::handle<CDM_MessageDriver> &)) &BinXCAFDrivers_DocumentStorageDriver::AttributeDrivers, "None", py::arg("theMsgDriver"));
	cls_BinXCAFDrivers_DocumentStorageDriver.def_static("get_type_name_", (const char * (*)()) &BinXCAFDrivers_DocumentStorageDriver::get_type_name, "None");
	cls_BinXCAFDrivers_DocumentStorageDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinXCAFDrivers_DocumentStorageDriver::get_type_descriptor, "None");
	cls_BinXCAFDrivers_DocumentStorageDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinXCAFDrivers_DocumentStorageDriver::*)() const ) &BinXCAFDrivers_DocumentStorageDriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BinXCAFDrivers_DocumentRetrievalDriver.hxx
	py::class_<BinXCAFDrivers_DocumentRetrievalDriver, opencascade::handle<BinXCAFDrivers_DocumentRetrievalDriver>, BinDrivers_DocumentRetrievalDriver> cls_BinXCAFDrivers_DocumentRetrievalDriver(mod, "BinXCAFDrivers_DocumentRetrievalDriver", "None");
	cls_BinXCAFDrivers_DocumentRetrievalDriver.def(py::init<>());
	cls_BinXCAFDrivers_DocumentRetrievalDriver.def("AttributeDrivers", (opencascade::handle<BinMDF_ADriverTable> (BinXCAFDrivers_DocumentRetrievalDriver::*)(const opencascade::handle<CDM_MessageDriver> &)) &BinXCAFDrivers_DocumentRetrievalDriver::AttributeDrivers, "None", py::arg("theMsgDriver"));
	cls_BinXCAFDrivers_DocumentRetrievalDriver.def_static("get_type_name_", (const char * (*)()) &BinXCAFDrivers_DocumentRetrievalDriver::get_type_name, "None");
	cls_BinXCAFDrivers_DocumentRetrievalDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinXCAFDrivers_DocumentRetrievalDriver::get_type_descriptor, "None");
	cls_BinXCAFDrivers_DocumentRetrievalDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinXCAFDrivers_DocumentRetrievalDriver::*)() const ) &BinXCAFDrivers_DocumentRetrievalDriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BinXCAFDrivers.hxx
	py::class_<BinXCAFDrivers, std::unique_ptr<BinXCAFDrivers, Deleter<BinXCAFDrivers>>> cls_BinXCAFDrivers(mod, "BinXCAFDrivers", "None");
	cls_BinXCAFDrivers.def(py::init<>());
	cls_BinXCAFDrivers.def_static("Factory_", (const opencascade::handle<Standard_Transient> & (*)(const Standard_GUID &)) &BinXCAFDrivers::Factory, "None", py::arg("theGUID"));
	cls_BinXCAFDrivers.def_static("DefineFormat_", (void (*)(const opencascade::handle<TDocStd_Application> &)) &BinXCAFDrivers::DefineFormat, "Defines format 'BinXCAF' and registers its read and write drivers in the specified application", py::arg("theApp"));
	cls_BinXCAFDrivers.def_static("AttributeDrivers_", (opencascade::handle<BinMDF_ADriverTable> (*)(const opencascade::handle<CDM_MessageDriver> &)) &BinXCAFDrivers::AttributeDrivers, "Creates the table of drivers of types supported", py::arg("MsgDrv"));


}
