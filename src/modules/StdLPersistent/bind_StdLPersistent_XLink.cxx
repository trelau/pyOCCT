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
#include <TDocStd_XLink.hxx>
#include <StdObjMgt_ReadData.hxx>
#include <StdObjMgt_WriteData.hxx>
#include <StdObjMgt_Persistent.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <StdLPersistent_HString.hxx>
#include <StdLPersistent_XLink.hxx>

void bind_StdLPersistent_XLink(py::module &mod){

bind_StdObjMgt_Attribute<TDocStd_XLink>(mod, "StdObjMgt_Attribute_TDocStd_XLink", py::module_local());

py::class_<StdLPersistent_XLink, opencascade::handle<StdLPersistent_XLink>, StdObjMgt_Attribute<TDocStd_XLink>> cls_StdLPersistent_XLink(mod, "StdLPersistent_XLink", "None");

// Constructors

// Fields

// Methods
cls_StdLPersistent_XLink.def("Read", (void (StdLPersistent_XLink::*)(StdObjMgt_ReadData &)) &StdLPersistent_XLink::Read, "Read persistent data from a file.", py::arg("theReadData"));
cls_StdLPersistent_XLink.def("Write", (void (StdLPersistent_XLink::*)(StdObjMgt_WriteData &) const) &StdLPersistent_XLink::Write, "Write persistent data to a file.", py::arg("theWriteData"));
cls_StdLPersistent_XLink.def("PChildren", (void (StdLPersistent_XLink::*)(StdObjMgt_Persistent::SequenceOfPersistent &) const) &StdLPersistent_XLink::PChildren, "Gets persistent child objects", py::arg("theChildren"));
cls_StdLPersistent_XLink.def("PName", (Standard_CString (StdLPersistent_XLink::*)() const) &StdLPersistent_XLink::PName, "Returns persistent type name");
cls_StdLPersistent_XLink.def("Import", (void (StdLPersistent_XLink::*)(const opencascade::handle<TDocStd_XLink> &) const) &StdLPersistent_XLink::Import, "Import transient attribuite from the persistent data.", py::arg("theAttribute"));

// Enums

}