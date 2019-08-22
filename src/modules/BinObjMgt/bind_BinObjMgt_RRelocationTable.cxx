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
#include <TColStd_DataMapOfIntegerTransient.hxx>
#include <Standard_Handle.hxx>
#include <Storage_HeaderData.hxx>
#include <Standard_TypeDef.hxx>
#include <BinObjMgt_RRelocationTable.hxx>

void bind_BinObjMgt_RRelocationTable(py::module &mod){

py::class_<BinObjMgt_RRelocationTable, TColStd_DataMapOfIntegerTransient> cls_BinObjMgt_RRelocationTable(mod, "BinObjMgt_RRelocationTable", "Retrieval relocation table is modeled as a child class of TColStd_DataMapOfIntegerTransient that stores a handle to the file header section. With that attribute drivers have access to the file header section.");

// Constructors

// Fields

// Methods
cls_BinObjMgt_RRelocationTable.def("GetHeaderData", (const opencascade::handle<Storage_HeaderData> & (BinObjMgt_RRelocationTable::*)() const) &BinObjMgt_RRelocationTable::GetHeaderData, "Returns a handle to the header data of the file that is begin read");
cls_BinObjMgt_RRelocationTable.def("SetHeaderData", (void (BinObjMgt_RRelocationTable::*)(const opencascade::handle<Storage_HeaderData> &)) &BinObjMgt_RRelocationTable::SetHeaderData, "Sets the storage header data.", py::arg("theHeaderData"));
cls_BinObjMgt_RRelocationTable.def("Clear", [](BinObjMgt_RRelocationTable &self) -> void { return self.Clear(); });
cls_BinObjMgt_RRelocationTable.def("Clear", (void (BinObjMgt_RRelocationTable::*)(const Standard_Boolean)) &BinObjMgt_RRelocationTable::Clear, "None", py::arg("doReleaseMemory"));

// Enums

}