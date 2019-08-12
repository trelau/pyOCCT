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
#include <bind_StdObjMgt_Attribute.hxx>
#include <StdObjMgt_Attribute.hxx>
#include <TDataStd_NamedData.hxx>
#include <StdLPersistent_NamedData.hxx>
#include <StdObjMgt_ReadData.hxx>
#include <StdObjMgt_WriteData.hxx>
#include <TCollection_ExtendedString.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <StdLPersistent_HArray1.hxx>
#include <StdObjMgt_Persistent.hxx>
#include <StdLPersistent_HArray2.hxx>

void bind_StdLPersistent_NamedData(py::module &mod){

bind_StdObjMgt_Attribute<TDataStd_NamedData>(mod, "StdObjMgt_Attribute_TDataStd_NamedData", py::module_local());

py::class_<StdLPersistent_NamedData, opencascade::handle<StdLPersistent_NamedData>, StdObjMgt_Attribute<TDataStd_NamedData>> cls_StdLPersistent_NamedData(mod, "StdLPersistent_NamedData", "None");

// Constructors

// Fields

// Methods
cls_StdLPersistent_NamedData.def("Read", (void (StdLPersistent_NamedData::*)(StdObjMgt_ReadData &)) &StdLPersistent_NamedData::Read, "Read persistent data from a file.", py::arg("theReadData"));
cls_StdLPersistent_NamedData.def("Write", (void (StdLPersistent_NamedData::*)(StdObjMgt_WriteData &) const) &StdLPersistent_NamedData::Write, "Write persistent data to a file.", py::arg("theWriteData"));
cls_StdLPersistent_NamedData.def("PChildren", (void (StdLPersistent_NamedData::*)(StdObjMgt_Persistent::SequenceOfPersistent &) const) &StdLPersistent_NamedData::PChildren, "Gets persistent child objects", py::arg(""));
cls_StdLPersistent_NamedData.def("PName", (Standard_CString (StdLPersistent_NamedData::*)() const) &StdLPersistent_NamedData::PName, "Returns persistent type name");
// cls_StdLPersistent_NamedData.def("Import", (void (StdLPersistent_NamedData::*)(const opencascade::handle<TDataStd_NamedData> &) const) &StdLPersistent_NamedData::Import, "Import transient attribuite from the persistent data.", py::arg("theAttribute"));

// Enums

}