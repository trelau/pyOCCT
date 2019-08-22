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
#include <TDF_Label.hxx>
#include <TDF_IDFilter.hxx>
#include <Standard_TypeDef.hxx>
#include <TDF_AttributeMap.hxx>
#include <Standard_Handle.hxx>
#include <TDF_DataSet.hxx>
#include <TDF_RelocationTable.hxx>
#include <TDF_CopyLabel.hxx>

void bind_TDF_CopyLabel(py::module &mod){

py::class_<TDF_CopyLabel> cls_TDF_CopyLabel(mod, "TDF_CopyLabel", "This class gives copy of source label hierarchy");

// Constructors
cls_TDF_CopyLabel.def(py::init<>());
cls_TDF_CopyLabel.def(py::init<const TDF_Label &, const TDF_Label &>(), py::arg("aSource"), py::arg("aTarget"));

// Fields

// Methods
// cls_TDF_CopyLabel.def_static("operator new_", (void * (*)(size_t)) &TDF_CopyLabel::operator new, "None", py::arg("theSize"));
// cls_TDF_CopyLabel.def_static("operator delete_", (void (*)(void *)) &TDF_CopyLabel::operator delete, "None", py::arg("theAddress"));
// cls_TDF_CopyLabel.def_static("operator new[]_", (void * (*)(size_t)) &TDF_CopyLabel::operator new[], "None", py::arg("theSize"));
// cls_TDF_CopyLabel.def_static("operator delete[]_", (void (*)(void *)) &TDF_CopyLabel::operator delete[], "None", py::arg("theAddress"));
// cls_TDF_CopyLabel.def_static("operator new_", (void * (*)(size_t, void *)) &TDF_CopyLabel::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TDF_CopyLabel.def_static("operator delete_", (void (*)(void *, void *)) &TDF_CopyLabel::operator delete, "None", py::arg(""), py::arg(""));
cls_TDF_CopyLabel.def("Load", (void (TDF_CopyLabel::*)(const TDF_Label &, const TDF_Label &)) &TDF_CopyLabel::Load, "Loads src and tgt labels", py::arg("aSource"), py::arg("aTarget"));
cls_TDF_CopyLabel.def("UseFilter", (void (TDF_CopyLabel::*)(const TDF_IDFilter &)) &TDF_CopyLabel::UseFilter, "Sets filter", py::arg("aFilter"));
cls_TDF_CopyLabel.def_static("ExternalReferences_", (Standard_Boolean (*)(const TDF_Label &, TDF_AttributeMap &, const TDF_IDFilter &)) &TDF_CopyLabel::ExternalReferences, "Check external references and if exist fills the aExternals Map", py::arg("Lab"), py::arg("aExternals"), py::arg("aFilter"));
cls_TDF_CopyLabel.def_static("ExternalReferences_", (void (*)(const TDF_Label &, const TDF_Label &, TDF_AttributeMap &, const TDF_IDFilter &, opencascade::handle<TDF_DataSet> &)) &TDF_CopyLabel::ExternalReferences, "Check external references and if exist fills the aExternals Map", py::arg("aRefLab"), py::arg("Lab"), py::arg("aExternals"), py::arg("aFilter"), py::arg("aDataSet"));
cls_TDF_CopyLabel.def("Perform", (void (TDF_CopyLabel::*)()) &TDF_CopyLabel::Perform, "performs algorithm of selfcontained copy");
cls_TDF_CopyLabel.def("IsDone", (Standard_Boolean (TDF_CopyLabel::*)() const) &TDF_CopyLabel::IsDone, "None");
cls_TDF_CopyLabel.def("RelocationTable", (const opencascade::handle<TDF_RelocationTable> & (TDF_CopyLabel::*)() const) &TDF_CopyLabel::RelocationTable, "returns relocation table");

// Enums

}