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
#include <StdObjMgt_WriteData.hxx>
#include <Storage_BaseDriver.hxx>
#include <Standard_Handle.hxx>
#include <StdObjMgt_Persistent.hxx>
#include <Standard_TypeDef.hxx>

void bind_StdObjMgt_WriteData(py::module &mod){

py::class_<StdObjMgt_WriteData, std::unique_ptr<StdObjMgt_WriteData>> cls_StdObjMgt_WriteData(mod, "StdObjMgt_WriteData", "Auxiliary data used to write persistent objects to a file.");

// Constructors
cls_StdObjMgt_WriteData.def(py::init<Storage_BaseDriver &>(), py::arg("theDriver"));

// Fields

// Methods
cls_StdObjMgt_WriteData.def("WritePersistentObject", (void (StdObjMgt_WriteData::*)(const opencascade::handle<StdObjMgt_Persistent> &)) &StdObjMgt_WriteData::WritePersistentObject, "None", py::arg("thePersistent"));
cls_StdObjMgt_WriteData.def("bits_left", (StdObjMgt_WriteData & (StdObjMgt_WriteData::*)(const opencascade::handle<StdObjMgt_Persistent> &)) &StdObjMgt_WriteData::operator<<, py::is_operator(), "None", py::arg("thePersistent"));
cls_StdObjMgt_WriteData.def("bits_left", (StdObjMgt_WriteData & (StdObjMgt_WriteData::*)(const Standard_Character &)) &StdObjMgt_WriteData::operator<<, py::is_operator(), "None", py::arg("theValue"));
cls_StdObjMgt_WriteData.def("bits_left", (StdObjMgt_WriteData & (StdObjMgt_WriteData::*)(const Standard_ExtCharacter &)) &StdObjMgt_WriteData::operator<<, py::is_operator(), "None", py::arg("theValue"));
cls_StdObjMgt_WriteData.def("bits_left", (StdObjMgt_WriteData & (StdObjMgt_WriteData::*)(const Standard_Integer &)) &StdObjMgt_WriteData::operator<<, py::is_operator(), "None", py::arg("theValue"));
cls_StdObjMgt_WriteData.def("bits_left", (StdObjMgt_WriteData & (StdObjMgt_WriteData::*)(const Standard_Boolean &)) &StdObjMgt_WriteData::operator<<, py::is_operator(), "None", py::arg("theValue"));
cls_StdObjMgt_WriteData.def("bits_left", (StdObjMgt_WriteData & (StdObjMgt_WriteData::*)(const Standard_Real &)) &StdObjMgt_WriteData::operator<<, py::is_operator(), "None", py::arg("theValue"));
cls_StdObjMgt_WriteData.def("bits_left", (StdObjMgt_WriteData & (StdObjMgt_WriteData::*)(const Standard_ShortReal &)) &StdObjMgt_WriteData::operator<<, py::is_operator(), "None", py::arg("theValue"));

// Enums

}