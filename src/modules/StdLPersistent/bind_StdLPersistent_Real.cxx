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
#include <TDataStd_Real.hxx>
#include <StdObjMgt_ReadData.hxx>
#include <StdObjMgt_WriteData.hxx>
#include <StdObjMgt_Persistent.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <TDataStd_RealEnum.hxx>
#include <StdLPersistent_Real.hxx>

void bind_StdLPersistent_Real(py::module &mod){

bind_StdObjMgt_Attribute<TDataStd_Real>(mod, "StdObjMgt_Attribute_TDataStd_Real", py::module_local());

py::class_<StdLPersistent_Real, opencascade::handle<StdLPersistent_Real>, StdObjMgt_Attribute<TDataStd_Real>> cls_StdLPersistent_Real(mod, "StdLPersistent_Real", "None");

// Constructors

// Fields

// Methods
cls_StdLPersistent_Real.def("Read", (void (StdLPersistent_Real::*)(StdObjMgt_ReadData &)) &StdLPersistent_Real::Read, "Read persistent data from a file.", py::arg("theReadData"));
cls_StdLPersistent_Real.def("Write", (void (StdLPersistent_Real::*)(StdObjMgt_WriteData &) const) &StdLPersistent_Real::Write, "Write persistent data from a file.", py::arg("theWriteData"));
cls_StdLPersistent_Real.def("PChildren", (void (StdLPersistent_Real::*)(StdObjMgt_Persistent::SequenceOfPersistent &) const) &StdLPersistent_Real::PChildren, "Gets persistent child objects", py::arg(""));
cls_StdLPersistent_Real.def("PName", (Standard_CString (StdLPersistent_Real::*)() const) &StdLPersistent_Real::PName, "Returns persistent type name");
cls_StdLPersistent_Real.def("Import", (void (StdLPersistent_Real::*)(const opencascade::handle<TDataStd_Real> &) const) &StdLPersistent_Real::Import, "Import transient attribuite from the persistent data.", py::arg("theAttribute"));

// Enums

}