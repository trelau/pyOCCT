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
#include <XmlMDF_ADriver.hxx>
#include <XmlMDF_TypeADriverMap.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Type.hxx>
#include <XmlMDF_ADriverTable.hxx>

void bind_XmlMDF_ADriverTable(py::module &mod){

py::class_<XmlMDF_ADriverTable, opencascade::handle<XmlMDF_ADriverTable>, Standard_Transient> cls_XmlMDF_ADriverTable(mod, "XmlMDF_ADriverTable", "A driver table is an object building links between object types and object drivers. In the translation process, a driver table is asked to give a translation driver for each current object to be translated.");

// Constructors
cls_XmlMDF_ADriverTable.def(py::init<>());

// Fields

// Methods
cls_XmlMDF_ADriverTable.def("AddDriver", (void (XmlMDF_ADriverTable::*)(const opencascade::handle<XmlMDF_ADriver> &)) &XmlMDF_ADriverTable::AddDriver, "Sets a translation driver: <aDriver>.", py::arg("anHDriver"));
cls_XmlMDF_ADriverTable.def("GetDrivers", (const XmlMDF_TypeADriverMap & (XmlMDF_ADriverTable::*)() const) &XmlMDF_ADriverTable::GetDrivers, "Gets a map of drivers.");
cls_XmlMDF_ADriverTable.def("GetDriver", (Standard_Boolean (XmlMDF_ADriverTable::*)(const opencascade::handle<Standard_Type> &, opencascade::handle<XmlMDF_ADriver> &) const) &XmlMDF_ADriverTable::GetDriver, "Gets a driver <aDriver> according to <aType>", py::arg("aType"), py::arg("anHDriver"));
cls_XmlMDF_ADriverTable.def_static("get_type_name_", (const char * (*)()) &XmlMDF_ADriverTable::get_type_name, "None");
cls_XmlMDF_ADriverTable.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlMDF_ADriverTable::get_type_descriptor, "None");
cls_XmlMDF_ADriverTable.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlMDF_ADriverTable::*)() const) &XmlMDF_ADriverTable::DynamicType, "None");

// Enums

}