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
#include <TFunction_DriverTable.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_GUID.hxx>
#include <TFunction_Driver.hxx>
#include <Standard_OStream.hxx>
#include <Standard_Type.hxx>
#include <TFunction_DataMapOfGUIDDriver.hxx>
#include <TFunction_HArray1OfDataMapOfGUIDDriver.hxx>

void bind_TFunction_DriverTable(py::module &mod){

py::class_<TFunction_DriverTable, opencascade::handle<TFunction_DriverTable>, Standard_Transient> cls_TFunction_DriverTable(mod, "TFunction_DriverTable", "A container for instances of drivers. You create a new instance of TFunction_Driver and use the method AddDriver to load it into the driver table.");

// Constructors
cls_TFunction_DriverTable.def(py::init<>());

// Fields

// Methods
cls_TFunction_DriverTable.def_static("Get_", (opencascade::handle<TFunction_DriverTable> (*)()) &TFunction_DriverTable::Get, "Returns the driver table. If a driver does not exist, creates it.");
cls_TFunction_DriverTable.def("AddDriver", [](TFunction_DriverTable &self, const Standard_GUID & a0, const opencascade::handle<TFunction_Driver> & a1) -> Standard_Boolean { return self.AddDriver(a0, a1); });
cls_TFunction_DriverTable.def("AddDriver", (Standard_Boolean (TFunction_DriverTable::*)(const Standard_GUID &, const opencascade::handle<TFunction_Driver> &, const Standard_Integer)) &TFunction_DriverTable::AddDriver, "Returns true if the driver has been added successfully to the driver table.", py::arg("guid"), py::arg("driver"), py::arg("thread"));
cls_TFunction_DriverTable.def("HasDriver", [](TFunction_DriverTable &self, const Standard_GUID & a0) -> Standard_Boolean { return self.HasDriver(a0); });
cls_TFunction_DriverTable.def("HasDriver", (Standard_Boolean (TFunction_DriverTable::*)(const Standard_GUID &, const Standard_Integer) const) &TFunction_DriverTable::HasDriver, "Returns true if the driver exists in the driver table.", py::arg("guid"), py::arg("thread"));
cls_TFunction_DriverTable.def("FindDriver", [](TFunction_DriverTable &self, const Standard_GUID & a0, opencascade::handle<TFunction_Driver> & a1) -> Standard_Boolean { return self.FindDriver(a0, a1); });
cls_TFunction_DriverTable.def("FindDriver", (Standard_Boolean (TFunction_DriverTable::*)(const Standard_GUID &, opencascade::handle<TFunction_Driver> &, const Standard_Integer) const) &TFunction_DriverTable::FindDriver, "Returns true if the driver was found.", py::arg("guid"), py::arg("driver"), py::arg("thread"));
cls_TFunction_DriverTable.def("Dump", (Standard_OStream & (TFunction_DriverTable::*)(Standard_OStream &) const) &TFunction_DriverTable::Dump, "None", py::arg("anOS"));
cls_TFunction_DriverTable.def("bits_left", (Standard_OStream & (TFunction_DriverTable::*)(Standard_OStream &) const) &TFunction_DriverTable::operator<<, py::is_operator(), "None", py::arg("anOS"));
cls_TFunction_DriverTable.def("RemoveDriver", [](TFunction_DriverTable &self, const Standard_GUID & a0) -> Standard_Boolean { return self.RemoveDriver(a0); });
cls_TFunction_DriverTable.def("RemoveDriver", (Standard_Boolean (TFunction_DriverTable::*)(const Standard_GUID &, const Standard_Integer)) &TFunction_DriverTable::RemoveDriver, "Removes a driver with the given GUID. Returns true if the driver has been removed successfully.", py::arg("guid"), py::arg("thread"));
cls_TFunction_DriverTable.def("Clear", (void (TFunction_DriverTable::*)()) &TFunction_DriverTable::Clear, "Removes all drivers. Returns true if the driver has been removed successfully.");
cls_TFunction_DriverTable.def_static("get_type_name_", (const char * (*)()) &TFunction_DriverTable::get_type_name, "None");
cls_TFunction_DriverTable.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TFunction_DriverTable::get_type_descriptor, "None");
cls_TFunction_DriverTable.def("DynamicType", (const opencascade::handle<Standard_Type> & (TFunction_DriverTable::*)() const) &TFunction_DriverTable::DynamicType, "None");

// Enums

}