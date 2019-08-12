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
#include <TDocStd_Document.hxx>
#include <StdLPersistent_Data.hxx>
#include <StdLPersistent_Document.hxx>

void bind_StdLPersistent_Document(py::module &mod){

py::class_<StdLPersistent_Document, opencascade::handle<StdLPersistent_Document>, StdObjMgt_Persistent> cls_StdLPersistent_Document(mod, "StdLPersistent_Document", "None");

// Constructors

// Fields

// Methods
cls_StdLPersistent_Document.def("Read", (void (StdLPersistent_Document::*)(StdObjMgt_ReadData &)) &StdLPersistent_Document::Read, "Read persistent data from a file.", py::arg("theReadData"));
cls_StdLPersistent_Document.def("Write", (void (StdLPersistent_Document::*)(StdObjMgt_WriteData &) const) &StdLPersistent_Document::Write, "Read persistent data from a file.", py::arg("theWriteData"));
cls_StdLPersistent_Document.def("PChildren", (void (StdLPersistent_Document::*)(StdObjMgt_Persistent::SequenceOfPersistent &) const) &StdLPersistent_Document::PChildren, "Gets persistent child objects", py::arg(""));
cls_StdLPersistent_Document.def("PName", (Standard_CString (StdLPersistent_Document::*)() const) &StdLPersistent_Document::PName, "Returns persistent type name");
cls_StdLPersistent_Document.def("ImportDocument", (void (StdLPersistent_Document::*)(const opencascade::handle<TDocStd_Document> &) const) &StdLPersistent_Document::ImportDocument, "Import transient document from the persistent data.", py::arg("theDocument"));

// Enums

}