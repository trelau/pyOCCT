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
#include <TDataXtd_Constraint.hxx>
#include <StdObjMgt_ReadData.hxx>
#include <StdObjMgt_WriteData.hxx>
#include <StdObjMgt_Persistent.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <StdLPersistent_HArray1.hxx>
#include <StdPersistent_DataXtd_Constraint.hxx>

void bind_StdPersistent_DataXtd_Constraint(py::module &mod){

bind_StdObjMgt_Attribute<TDataXtd_Constraint>(mod, "StdObjMgt_Attribute_TDataXtd_Constraint", py::module_local());

py::class_<StdPersistent_DataXtd_Constraint, opencascade::handle<StdPersistent_DataXtd_Constraint>, StdObjMgt_Attribute<TDataXtd_Constraint>> cls_StdPersistent_DataXtd_Constraint(mod, "StdPersistent_DataXtd_Constraint", "None");

// Constructors

// Fields

// Methods
cls_StdPersistent_DataXtd_Constraint.def("Read", (void (StdPersistent_DataXtd_Constraint::*)(StdObjMgt_ReadData &)) &StdPersistent_DataXtd_Constraint::Read, "Read persistent data from a file.", py::arg("theReadData"));
cls_StdPersistent_DataXtd_Constraint.def("Write", (void (StdPersistent_DataXtd_Constraint::*)(StdObjMgt_WriteData &) const) &StdPersistent_DataXtd_Constraint::Write, "Write persistent data to a file.", py::arg("theWriteData"));
cls_StdPersistent_DataXtd_Constraint.def("PChildren", (void (StdPersistent_DataXtd_Constraint::*)(StdObjMgt_Persistent::SequenceOfPersistent &) const) &StdPersistent_DataXtd_Constraint::PChildren, "Gets persistent child objects", py::arg("theChildren"));
cls_StdPersistent_DataXtd_Constraint.def("PName", (Standard_CString (StdPersistent_DataXtd_Constraint::*)() const) &StdPersistent_DataXtd_Constraint::PName, "Returns persistent type name");
// cls_StdPersistent_DataXtd_Constraint.def("Import", (void (StdPersistent_DataXtd_Constraint::*)(const opencascade::handle<TDataXtd_Constraint> &) const) &StdPersistent_DataXtd_Constraint::Import, "Import transient attribuite from the persistent data.", py::arg("theAttribute"));

// Enums

}