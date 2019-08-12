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
#include <Standard_Handle.hxx>
#include <TPrsStd_DriverTable.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_GUID.hxx>
#include <TPrsStd_Driver.hxx>
#include <Standard_Type.hxx>
#include <TPrsStd_DataMapOfGUIDDriver.hxx>

void bind_TPrsStd_DriverTable(py::module &mod){

py::class_<TPrsStd_DriverTable, opencascade::handle<TPrsStd_DriverTable>, Standard_Transient> cls_TPrsStd_DriverTable(mod, "TPrsStd_DriverTable", "This class is a container to record (AddDriver) binding between GUID and TPrsStd_Driver. You create a new instance of TPrsStd_Driver and use the method AddDriver to load it into the driver table. the method");

// Constructors
cls_TPrsStd_DriverTable.def(py::init<>());

// Fields

// Methods
cls_TPrsStd_DriverTable.def_static("Get_", (opencascade::handle<TPrsStd_DriverTable> (*)()) &TPrsStd_DriverTable::Get, "Returns the static table. If it does not exist, creates it and fills it with standard drivers.");
cls_TPrsStd_DriverTable.def("InitStandardDrivers", (void (TPrsStd_DriverTable::*)()) &TPrsStd_DriverTable::InitStandardDrivers, "Fills the table with standard drivers");
cls_TPrsStd_DriverTable.def("AddDriver", (Standard_Boolean (TPrsStd_DriverTable::*)(const Standard_GUID &, const opencascade::handle<TPrsStd_Driver> &)) &TPrsStd_DriverTable::AddDriver, "Returns true if the driver has been added successfully to the driver table.", py::arg("guid"), py::arg("driver"));
cls_TPrsStd_DriverTable.def("FindDriver", (Standard_Boolean (TPrsStd_DriverTable::*)(const Standard_GUID &, opencascade::handle<TPrsStd_Driver> &) const) &TPrsStd_DriverTable::FindDriver, "Returns true if the driver was found.", py::arg("guid"), py::arg("driver"));
cls_TPrsStd_DriverTable.def("RemoveDriver", (Standard_Boolean (TPrsStd_DriverTable::*)(const Standard_GUID &)) &TPrsStd_DriverTable::RemoveDriver, "Removes a driver with the given GUID. Returns true if the driver has been removed successfully.", py::arg("guid"));
cls_TPrsStd_DriverTable.def("Clear", (void (TPrsStd_DriverTable::*)()) &TPrsStd_DriverTable::Clear, "Removes all drivers. Returns true if the driver has been removed successfully. If this method is used, the InitStandardDrivers method should be called to fill the table with standard drivers.");
cls_TPrsStd_DriverTable.def_static("get_type_name_", (const char * (*)()) &TPrsStd_DriverTable::get_type_name, "None");
cls_TPrsStd_DriverTable.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TPrsStd_DriverTable::get_type_descriptor, "None");
cls_TPrsStd_DriverTable.def("DynamicType", (const opencascade::handle<Standard_Type> & (TPrsStd_DriverTable::*)() const) &TPrsStd_DriverTable::DynamicType, "None");

// Enums

}