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
#include <TDataStd_Variable.hxx>
#include <StdObjMgt_ReadData.hxx>
#include <StdObjMgt_WriteData.hxx>
#include <StdObjMgt_Persistent.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <StdLPersistent_HString.hxx>
#include <StdLPersistent_Variable.hxx>

void bind_StdLPersistent_Variable(py::module &mod){

bind_StdObjMgt_Attribute<TDataStd_Variable>(mod, "StdObjMgt_Attribute_TDataStd_Variable", py::module_local());

py::class_<StdLPersistent_Variable, opencascade::handle<StdLPersistent_Variable>, StdObjMgt_Attribute<TDataStd_Variable>> cls_StdLPersistent_Variable(mod, "StdLPersistent_Variable", "None");

// Constructors

// Fields

// Methods
cls_StdLPersistent_Variable.def("Read", (void (StdLPersistent_Variable::*)(StdObjMgt_ReadData &)) &StdLPersistent_Variable::Read, "Read persistent data from a file.", py::arg("theReadData"));
cls_StdLPersistent_Variable.def("Write", (void (StdLPersistent_Variable::*)(StdObjMgt_WriteData &) const) &StdLPersistent_Variable::Write, "Write persistent data to a file.", py::arg("theWriteData"));
cls_StdLPersistent_Variable.def("PChildren", (void (StdLPersistent_Variable::*)(StdObjMgt_Persistent::SequenceOfPersistent &) const) &StdLPersistent_Variable::PChildren, "Gets persistent child objects", py::arg("theChildren"));
cls_StdLPersistent_Variable.def("PName", (Standard_CString (StdLPersistent_Variable::*)() const) &StdLPersistent_Variable::PName, "Returns persistent type name");
cls_StdLPersistent_Variable.def("Import", (void (StdLPersistent_Variable::*)(const opencascade::handle<TDataStd_Variable> &) const) &StdLPersistent_Variable::Import, "Import transient attribuite from the persistent data.", py::arg("theAttribute"));

// Enums

}