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
#include <StdObjMgt_Persistent.hxx>
#include <StdObjMgt_ReadData.hxx>
#include <StdObjMgt_WriteData.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <TDF_Data.hxx>
#include <StdLPersistent_HArray1.hxx>
#include <StdLPersistent_Data.hxx>

void bind_StdLPersistent_Data(py::module &mod){

py::class_<StdLPersistent_Data, opencascade::handle<StdLPersistent_Data>, StdObjMgt_Persistent> cls_StdLPersistent_Data(mod, "StdLPersistent_Data", "None");

// Constructors

// Fields

// Methods
cls_StdLPersistent_Data.def("Read", (void (StdLPersistent_Data::*)(StdObjMgt_ReadData &)) &StdLPersistent_Data::Read, "Read persistent data from a file.", py::arg("theReadData"));
cls_StdLPersistent_Data.def("Write", (void (StdLPersistent_Data::*)(StdObjMgt_WriteData &) const) &StdLPersistent_Data::Write, "Write persistent data to a file.", py::arg("theWriteData"));
cls_StdLPersistent_Data.def("PChildren", (void (StdLPersistent_Data::*)(StdObjMgt_Persistent::SequenceOfPersistent &) const) &StdLPersistent_Data::PChildren, "Gets persistent child objects", py::arg("theChildren"));
cls_StdLPersistent_Data.def("PName", (Standard_CString (StdLPersistent_Data::*)() const) &StdLPersistent_Data::PName, "Returns persistent type name");
cls_StdLPersistent_Data.def("Import", (opencascade::handle<TDF_Data> (StdLPersistent_Data::*)() const) &StdLPersistent_Data::Import, "Import transient data from the persistent data.");

// Enums

}