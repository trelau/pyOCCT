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
#include <Standard_Handle.hxx>
#include <TDF_DataSet.hxx>
#include <TDF_RelocationTable.hxx>
#include <TDF_IDFilter.hxx>
#include <Standard_TypeDef.hxx>
#include <TDF_Label.hxx>
#include <TDF_LabelDataMap.hxx>
#include <TDF_AttributeDataMap.hxx>
#include <TDF_LabelMap.hxx>
#include <TDF_AttributeMap.hxx>
#include <TDF_CopyTool.hxx>

void bind_TDF_CopyTool(py::module &mod){

py::class_<TDF_CopyTool> cls_TDF_CopyTool(mod, "TDF_CopyTool", "This class provides services to build, copy or paste a set of information.");

// Constructors

// Fields

// Methods
// cls_TDF_CopyTool.def_static("operator new_", (void * (*)(size_t)) &TDF_CopyTool::operator new, "None", py::arg("theSize"));
// cls_TDF_CopyTool.def_static("operator delete_", (void (*)(void *)) &TDF_CopyTool::operator delete, "None", py::arg("theAddress"));
// cls_TDF_CopyTool.def_static("operator new[]_", (void * (*)(size_t)) &TDF_CopyTool::operator new[], "None", py::arg("theSize"));
// cls_TDF_CopyTool.def_static("operator delete[]_", (void (*)(void *)) &TDF_CopyTool::operator delete[], "None", py::arg("theAddress"));
// cls_TDF_CopyTool.def_static("operator new_", (void * (*)(size_t, void *)) &TDF_CopyTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TDF_CopyTool.def_static("operator delete_", (void (*)(void *, void *)) &TDF_CopyTool::operator delete, "None", py::arg(""), py::arg(""));
cls_TDF_CopyTool.def_static("Copy_", (void (*)(const opencascade::handle<TDF_DataSet> &, const opencascade::handle<TDF_RelocationTable> &)) &TDF_CopyTool::Copy, "Copy <aSourceDataSet> with using and updating <aRelocationTable>. This method ignores target attributes privilege over source ones.", py::arg("aSourceDataSet"), py::arg("aRelocationTable"));
cls_TDF_CopyTool.def_static("Copy_", (void (*)(const opencascade::handle<TDF_DataSet> &, const opencascade::handle<TDF_RelocationTable> &, const TDF_IDFilter &)) &TDF_CopyTool::Copy, "Copy <aSourceDataSet> using and updating <aRelocationTable>. Use <aPrivilegeFilter> to give a list of IDs for which the target attribute prevails over the source one.", py::arg("aSourceDataSet"), py::arg("aRelocationTable"), py::arg("aPrivilegeFilter"));
cls_TDF_CopyTool.def_static("Copy_", (void (*)(const opencascade::handle<TDF_DataSet> &, const opencascade::handle<TDF_RelocationTable> &, const TDF_IDFilter &, const TDF_IDFilter &, const Standard_Boolean)) &TDF_CopyTool::Copy, "Copy <aSourceDataSet> using and updating <aRelocationTable>. Use <aPrivilegeFilter> to give a list of IDs for which the target attribute prevails over the source one. If <setSelfContained> is set to true, every TDF_Reference will be replaced by the referenced structure according to <aRefFilter>.", py::arg("aSourceDataSet"), py::arg("aRelocationTable"), py::arg("aPrivilegeFilter"), py::arg("aRefFilter"), py::arg("setSelfContained"));

// Enums

}