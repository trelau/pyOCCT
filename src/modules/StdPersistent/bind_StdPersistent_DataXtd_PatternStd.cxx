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
#include <TDataXtd_PatternStd.hxx>
#include <StdObjMgt_ReadData.hxx>
#include <StdObjMgt_WriteData.hxx>
#include <StdObjMgt_Persistent.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <StdPersistent_DataXtd_PatternStd.hxx>

void bind_StdPersistent_DataXtd_PatternStd(py::module &mod){

bind_StdObjMgt_Attribute<TDataXtd_PatternStd>(mod, "StdObjMgt_Attribute_TDataXtd_PatternStd", py::module_local());

py::class_<StdPersistent_DataXtd_PatternStd, opencascade::handle<StdPersistent_DataXtd_PatternStd>, StdObjMgt_Attribute<TDataXtd_PatternStd>> cls_StdPersistent_DataXtd_PatternStd(mod, "StdPersistent_DataXtd_PatternStd", "None");

// Constructors

// Fields

// Methods
cls_StdPersistent_DataXtd_PatternStd.def("Read", (void (StdPersistent_DataXtd_PatternStd::*)(StdObjMgt_ReadData &)) &StdPersistent_DataXtd_PatternStd::Read, "Read persistent data from a file.", py::arg("theReadData"));
cls_StdPersistent_DataXtd_PatternStd.def("Write", (void (StdPersistent_DataXtd_PatternStd::*)(StdObjMgt_WriteData &)) &StdPersistent_DataXtd_PatternStd::Write, "Write persistent data to a file.", py::arg("theWriteData"));
cls_StdPersistent_DataXtd_PatternStd.def("PChildren", (void (StdPersistent_DataXtd_PatternStd::*)(StdObjMgt_Persistent::SequenceOfPersistent &) const) &StdPersistent_DataXtd_PatternStd::PChildren, "Gets persistent child objects", py::arg("theChildren"));
cls_StdPersistent_DataXtd_PatternStd.def("PName", (Standard_CString (StdPersistent_DataXtd_PatternStd::*)() const) &StdPersistent_DataXtd_PatternStd::PName, "Returns persistent type name");
// cls_StdPersistent_DataXtd_PatternStd.def("Import", (void (StdPersistent_DataXtd_PatternStd::*)(const opencascade::handle<TDataXtd_PatternStd> &) const) &StdPersistent_DataXtd_PatternStd::Import, "Import transient attribuite from the persistent data.", py::arg("theAttribute"));

// Enums

}