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
#include <Standard.hxx>
#include <Standard_GUID.hxx>
#include <TCollection_ExtendedString.hxx>
#include <Standard_TypeDef.hxx>
#include <TDF_Data.hxx>
#include <TDF_Label.hxx>
#include <TDF_Attribute.hxx>
#include <TDF_TagSource.hxx>
#include <TDF_Reference.hxx>
#include <TDF_ClosureMode.hxx>
#include <TDF_ClosureTool.hxx>
#include <TDF_CopyTool.hxx>
#include <TDF_CopyLabel.hxx>
#include <TDF_ComparisonTool.hxx>
#include <TDF_Transaction.hxx>
#include <TDF_Delta.hxx>
#include <TDF_AttributeDelta.hxx>
#include <TDF_DeltaOnAddition.hxx>
#include <TDF_DeltaOnForget.hxx>
#include <TDF_DeltaOnResume.hxx>
#include <TDF_DeltaOnRemoval.hxx>
#include <TDF_DeltaOnModification.hxx>
#include <TDF_DefaultDeltaOnRemoval.hxx>
#include <TDF_DefaultDeltaOnModification.hxx>
#include <TDF_ChildIterator.hxx>
#include <TDF_ChildIDIterator.hxx>
#include <TDF_DataSet.hxx>
#include <TDF_RelocationTable.hxx>
#include <TDF_Tool.hxx>
#include <TDF_LabelMapHasher.hxx>
#include <TDF_IDFilter.hxx>
#include <TDF.hxx>

void bind_TDF(py::module &mod){

py::class_<TDF, std::unique_ptr<TDF>> cls_TDF(mod, "TDF", "This package provides data framework for binding features and data structures.");

// Constructors

// Fields

// Methods
// cls_TDF.def_static("operator new_", (void * (*)(size_t)) &TDF::operator new, "None", py::arg("theSize"));
// cls_TDF.def_static("operator delete_", (void (*)(void *)) &TDF::operator delete, "None", py::arg("theAddress"));
// cls_TDF.def_static("operator new[]_", (void * (*)(size_t)) &TDF::operator new[], "None", py::arg("theSize"));
// cls_TDF.def_static("operator delete[]_", (void (*)(void *)) &TDF::operator delete[], "None", py::arg("theAddress"));
// cls_TDF.def_static("operator new_", (void * (*)(size_t, void *)) &TDF::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TDF.def_static("operator delete_", (void (*)(void *, void *)) &TDF::operator delete, "None", py::arg(""), py::arg(""));
cls_TDF.def_static("LowestID_", (const Standard_GUID & (*)()) &TDF::LowestID, "Returns ID '00000000-0000-0000-0000-000000000000', sometimes used as null ID.");
cls_TDF.def_static("UppestID_", (const Standard_GUID & (*)()) &TDF::UppestID, "Returns ID 'ffffffff-ffff-ffff-ffff-ffffffffffff'.");
cls_TDF.def_static("AddLinkGUIDToProgID_", (void (*)(const Standard_GUID &, const TCollection_ExtendedString &)) &TDF::AddLinkGUIDToProgID, "Sets link between GUID and ProgID in hidden DataMap", py::arg("ID"), py::arg("ProgID"));
cls_TDF.def_static("GUIDFromProgID_", (Standard_Boolean (*)(const TCollection_ExtendedString &, Standard_GUID &)) &TDF::GUIDFromProgID, "Returns True if there is GUID for given <ProgID> then GUID is returned in <ID>", py::arg("ProgID"), py::arg("ID"));
cls_TDF.def_static("ProgIDFromGUID_", (Standard_Boolean (*)(const Standard_GUID &, TCollection_ExtendedString &)) &TDF::ProgIDFromGUID, "Returns True if there is ProgID for given <ID> then ProgID is returned in <ProgID>", py::arg("ID"), py::arg("ProgID"));

// Enums

}