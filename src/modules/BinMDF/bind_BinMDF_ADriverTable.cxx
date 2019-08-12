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
#include <BinMDF_ADriver.hxx>
#include <TColStd_IndexedMapOfTransient.hxx>
#include <TColStd_SequenceOfAsciiString.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Type.hxx>
#include <BinMDF_ADriverTable.hxx>
#include <BinMDF_TypeADriverMap.hxx>
#include <BinMDF_TypeIdMap.hxx>

void bind_BinMDF_ADriverTable(py::module &mod){

py::class_<BinMDF_ADriverTable, opencascade::handle<BinMDF_ADriverTable>, Standard_Transient> cls_BinMDF_ADriverTable(mod, "BinMDF_ADriverTable", "A driver table is an object building links between object types and object drivers. In the translation process, a driver table is asked to give a translation driver for each current object to be translated.");

// Constructors
cls_BinMDF_ADriverTable.def(py::init<>());

// Fields

// Methods
cls_BinMDF_ADriverTable.def("AddDriver", (void (BinMDF_ADriverTable::*)(const opencascade::handle<BinMDF_ADriver> &)) &BinMDF_ADriverTable::AddDriver, "Adds a translation driver <theDriver>.", py::arg("theDriver"));
cls_BinMDF_ADriverTable.def("AssignIds", (void (BinMDF_ADriverTable::*)(const TColStd_IndexedMapOfTransient &)) &BinMDF_ADriverTable::AssignIds, "Assigns the IDs to the drivers of the given Types. It uses indices in the map as IDs. Useful in storage procedure.", py::arg("theTypes"));
cls_BinMDF_ADriverTable.def("AssignIds", (void (BinMDF_ADriverTable::*)(const TColStd_SequenceOfAsciiString &)) &BinMDF_ADriverTable::AssignIds, "Assigns the IDs to the drivers of the given Type Names; It uses indices in the sequence as IDs. Useful in retrieval procedure.", py::arg("theTypeNames"));
cls_BinMDF_ADriverTable.def("GetDriver", (Standard_Integer (BinMDF_ADriverTable::*)(const opencascade::handle<Standard_Type> &, opencascade::handle<BinMDF_ADriver> &) const) &BinMDF_ADriverTable::GetDriver, "Gets a driver <theDriver> according to <theType>. Returns Type ID if the driver was assigned an ID; 0 otherwise.", py::arg("theType"), py::arg("theDriver"));
cls_BinMDF_ADriverTable.def("GetDriver", (opencascade::handle<BinMDF_ADriver> (BinMDF_ADriverTable::*)(const Standard_Integer) const) &BinMDF_ADriverTable::GetDriver, "Returns a driver according to <theTypeId>. Returns null handle if a driver is not found", py::arg("theTypeId"));
cls_BinMDF_ADriverTable.def_static("get_type_name_", (const char * (*)()) &BinMDF_ADriverTable::get_type_name, "None");
cls_BinMDF_ADriverTable.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMDF_ADriverTable::get_type_descriptor, "None");
cls_BinMDF_ADriverTable.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMDF_ADriverTable::*)() const) &BinMDF_ADriverTable::DynamicType, "None");

// Enums

}