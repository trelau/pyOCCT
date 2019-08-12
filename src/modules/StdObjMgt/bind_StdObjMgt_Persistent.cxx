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
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <StdObjMgt_Persistent.hxx>
#include <StdObjMgt_ReadData.hxx>
#include <StdObjMgt_WriteData.hxx>
#include <NCollection_Sequence.hxx>
#include <Standard_TypeDef.hxx>
#include <TDocStd_Document.hxx>
#include <TDF_Attribute.hxx>
#include <TCollection_HAsciiString.hxx>
#include <TCollection_HExtendedString.hxx>
#include <TDF_Label.hxx>
#include <TDF_Data.hxx>

void bind_StdObjMgt_Persistent(py::module &mod){

py::class_<StdObjMgt_Persistent, opencascade::handle<StdObjMgt_Persistent>, Standard_Transient> cls_StdObjMgt_Persistent(mod, "StdObjMgt_Persistent", "Root class for a temporary persistent object that reads data from a file and then creates transient object using the data.");

// Fields

// Methods
cls_StdObjMgt_Persistent.def("Read", (void (StdObjMgt_Persistent::*)(StdObjMgt_ReadData &)) &StdObjMgt_Persistent::Read, "Read persistent data from a file.", py::arg("theReadData"));
cls_StdObjMgt_Persistent.def("Write", (void (StdObjMgt_Persistent::*)(StdObjMgt_WriteData &) const) &StdObjMgt_Persistent::Write, "Write persistent data to a file.", py::arg("theWriteData"));
cls_StdObjMgt_Persistent.def("PChildren", (void (StdObjMgt_Persistent::*)(StdObjMgt_Persistent::SequenceOfPersistent &) const) &StdObjMgt_Persistent::PChildren, "Gets persistent child objects", py::arg(""));
cls_StdObjMgt_Persistent.def("PName", (Standard_CString (StdObjMgt_Persistent::*)() const) &StdObjMgt_Persistent::PName, "Returns persistent type name");
cls_StdObjMgt_Persistent.def("ImportDocument", (void (StdObjMgt_Persistent::*)(const opencascade::handle<TDocStd_Document> &) const) &StdObjMgt_Persistent::ImportDocument, "Import transient document from the persistent data (to be overriden by document class; does nothing by default for other classes).", py::arg("theDocument"));
cls_StdObjMgt_Persistent.def("CreateAttribute", (opencascade::handle<TDF_Attribute> (StdObjMgt_Persistent::*)()) &StdObjMgt_Persistent::CreateAttribute, "Create an empty transient attribuite (to be overriden by attribute classes; does nothing and returns a null handle by default for other classes).");
cls_StdObjMgt_Persistent.def("GetAttribute", (opencascade::handle<TDF_Attribute> (StdObjMgt_Persistent::*)() const) &StdObjMgt_Persistent::GetAttribute, "Get transient attribuite for the persistent data (to be overriden by attribute classes; returns a null handle by default for non-attribute classes).");
cls_StdObjMgt_Persistent.def("ImportAttribute", (void (StdObjMgt_Persistent::*)()) &StdObjMgt_Persistent::ImportAttribute, "Import transient attribuite from the persistent data (to be overriden by attribute classes; does nothing by default for non-attribute classes).");
cls_StdObjMgt_Persistent.def("AsciiString", (opencascade::handle<TCollection_HAsciiString> (StdObjMgt_Persistent::*)() const) &StdObjMgt_Persistent::AsciiString, "Get referenced ASCII string (to be overriden by ASCII string class; returns a null handle by default for other classes).");
cls_StdObjMgt_Persistent.def("ExtString", (opencascade::handle<TCollection_HExtendedString> (StdObjMgt_Persistent::*)() const) &StdObjMgt_Persistent::ExtString, "Get referenced extended string (to be overriden by extended string class; returns a null handle by default for other classes).");
cls_StdObjMgt_Persistent.def("Label", (TDF_Label (StdObjMgt_Persistent::*)(const opencascade::handle<TDF_Data> &) const) &StdObjMgt_Persistent::Label, "Get a label expressed by referenced extended string (to be overriden by extended string class; returns a null label by default for other classes).", py::arg("theDF"));
cls_StdObjMgt_Persistent.def("TypeNum", (Standard_Integer (StdObjMgt_Persistent::*)() const) &StdObjMgt_Persistent::TypeNum, "Returns the assigned persistent type number");
cls_StdObjMgt_Persistent.def("TypeNum", (void (StdObjMgt_Persistent::*)(Standard_Integer)) &StdObjMgt_Persistent::TypeNum, "Assigns a persistent type number to the object", py::arg("theTypeNum"));
cls_StdObjMgt_Persistent.def("RefNum", (Standard_Integer (StdObjMgt_Persistent::*)() const) &StdObjMgt_Persistent::RefNum, "Returns the object reference number");
cls_StdObjMgt_Persistent.def("RefNum", (void (StdObjMgt_Persistent::*)(Standard_Integer)) &StdObjMgt_Persistent::RefNum, "Sets an object reference number", py::arg("theRefNum"));

// Enums

}