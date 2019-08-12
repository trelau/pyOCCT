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
#include <TDF_IDList.hxx>
#include <TDocStd_Application.hxx>
#include <TDocStd_Document.hxx>
#include <TDocStd_Context.hxx>
#include <TDocStd_XLink.hxx>
#include <TDocStd_XLinkIterator.hxx>
#include <TDocStd_XLinkTool.hxx>
#include <TDocStd_Owner.hxx>
#include <TDocStd_Modified.hxx>
#include <TDocStd_XLinkRoot.hxx>
#include <TDocStd_PathParser.hxx>
#include <TDocStd_CompoundDelta.hxx>
#include <TDocStd_ApplicationDelta.hxx>
#include <TDocStd_MultiTransactionManager.hxx>
#include <TDocStd.hxx>

void bind_TDocStd(py::module &mod){

py::class_<TDocStd, std::unique_ptr<TDocStd, Deleter<TDocStd>>> cls_TDocStd(mod, "TDocStd", "This package define CAF main classes.");

// Constructors

// Fields

// Methods
// cls_TDocStd.def_static("operator new_", (void * (*)(size_t)) &TDocStd::operator new, "None", py::arg("theSize"));
// cls_TDocStd.def_static("operator delete_", (void (*)(void *)) &TDocStd::operator delete, "None", py::arg("theAddress"));
// cls_TDocStd.def_static("operator new[]_", (void * (*)(size_t)) &TDocStd::operator new[], "None", py::arg("theSize"));
// cls_TDocStd.def_static("operator delete[]_", (void (*)(void *)) &TDocStd::operator delete[], "None", py::arg("theAddress"));
// cls_TDocStd.def_static("operator new_", (void * (*)(size_t, void *)) &TDocStd::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TDocStd.def_static("operator delete_", (void (*)(void *, void *)) &TDocStd::operator delete, "None", py::arg(""), py::arg(""));
cls_TDocStd.def_static("IDList_", (void (*)(TDF_IDList &)) &TDocStd::IDList, "specific GUID of this package ============================= Appends to <anIDList> the list of the attributes IDs of this package. CAUTION: <anIDList> is NOT cleared before use.", py::arg("anIDList"));

// Enums

}