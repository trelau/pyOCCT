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
#include <Standard_TypeDef.hxx>
#include <Standard_GUID.hxx>
#include <TDF_IDList.hxx>
#include <Standard_Handle.hxx>
#include <TDF_Attribute.hxx>
#include <TDF_IDFilter.hxx>
#include <Standard_OStream.hxx>
#include <TDF_IDMap.hxx>

void bind_TDF_IDFilter(py::module &mod){

py::class_<TDF_IDFilter> cls_TDF_IDFilter(mod, "TDF_IDFilter", "This class offers filtering services around an ID list.");

// Constructors
cls_TDF_IDFilter.def(py::init<>());
cls_TDF_IDFilter.def(py::init<const Standard_Boolean>(), py::arg("ignoreMode"));

// Fields

// Methods
// cls_TDF_IDFilter.def_static("operator new_", (void * (*)(size_t)) &TDF_IDFilter::operator new, "None", py::arg("theSize"));
// cls_TDF_IDFilter.def_static("operator delete_", (void (*)(void *)) &TDF_IDFilter::operator delete, "None", py::arg("theAddress"));
// cls_TDF_IDFilter.def_static("operator new[]_", (void * (*)(size_t)) &TDF_IDFilter::operator new[], "None", py::arg("theSize"));
// cls_TDF_IDFilter.def_static("operator delete[]_", (void (*)(void *)) &TDF_IDFilter::operator delete[], "None", py::arg("theAddress"));
// cls_TDF_IDFilter.def_static("operator new_", (void * (*)(size_t, void *)) &TDF_IDFilter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TDF_IDFilter.def_static("operator delete_", (void (*)(void *, void *)) &TDF_IDFilter::operator delete, "None", py::arg(""), py::arg(""));
cls_TDF_IDFilter.def("IgnoreAll", (void (TDF_IDFilter::*)(const Standard_Boolean)) &TDF_IDFilter::IgnoreAll, "The list of ID is cleared and the filter mode is set to ignore mode if <keep> is true; false otherwise.", py::arg("ignore"));
cls_TDF_IDFilter.def("IgnoreAll", (Standard_Boolean (TDF_IDFilter::*)() const) &TDF_IDFilter::IgnoreAll, "Returns true is the mode is set to 'ignore all but...'.");
cls_TDF_IDFilter.def("Keep", (void (TDF_IDFilter::*)(const Standard_GUID &)) &TDF_IDFilter::Keep, "An attribute with <anID> as ID is to be kept and the filter will answer true to the question IsKept(<anID>).", py::arg("anID"));
cls_TDF_IDFilter.def("Keep", (void (TDF_IDFilter::*)(const TDF_IDList &)) &TDF_IDFilter::Keep, "Attributes with ID owned by <anIDList> are to be kept and the filter will answer true to the question IsKept(<anID>) with ID from <anIDList>.", py::arg("anIDList"));
cls_TDF_IDFilter.def("Ignore", (void (TDF_IDFilter::*)(const Standard_GUID &)) &TDF_IDFilter::Ignore, "An attribute with <anID> as ID is to be ignored and the filter will answer false to the question IsKept(<anID>).", py::arg("anID"));
cls_TDF_IDFilter.def("Ignore", (void (TDF_IDFilter::*)(const TDF_IDList &)) &TDF_IDFilter::Ignore, "Attributes with ID owned by <anIDList> are to be ignored and the filter will answer false to the question IsKept(<anID>) with ID from <anIDList>.", py::arg("anIDList"));
cls_TDF_IDFilter.def("IsKept", (Standard_Boolean (TDF_IDFilter::*)(const Standard_GUID &) const) &TDF_IDFilter::IsKept, "Returns true if the ID is to be kept.", py::arg("anID"));
cls_TDF_IDFilter.def("IsKept", (Standard_Boolean (TDF_IDFilter::*)(const opencascade::handle<TDF_Attribute> &) const) &TDF_IDFilter::IsKept, "Returns true if the attribute is to be kept.", py::arg("anAtt"));
cls_TDF_IDFilter.def("IsIgnored", (Standard_Boolean (TDF_IDFilter::*)(const Standard_GUID &) const) &TDF_IDFilter::IsIgnored, "Returns true if the ID is to be ignored.", py::arg("anID"));
cls_TDF_IDFilter.def("IsIgnored", (Standard_Boolean (TDF_IDFilter::*)(const opencascade::handle<TDF_Attribute> &) const) &TDF_IDFilter::IsIgnored, "Returns true if the attribute is to be ignored.", py::arg("anAtt"));
cls_TDF_IDFilter.def("IDList", (void (TDF_IDFilter::*)(TDF_IDList &) const) &TDF_IDFilter::IDList, "Copies the list of ID to be kept or ignored in <anIDList>. <anIDList> is cleared before use.", py::arg("anIDList"));
cls_TDF_IDFilter.def("Copy", (void (TDF_IDFilter::*)(const TDF_IDFilter &)) &TDF_IDFilter::Copy, "Copies into <me> the contents of <fromFilter>. <me> is cleared before copy.", py::arg("fromFilter"));
cls_TDF_IDFilter.def("Dump", (void (TDF_IDFilter::*)(Standard_OStream &) const) &TDF_IDFilter::Dump, "Writes the contents of <me> to <OS>.", py::arg("anOS"));

// Enums

}