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
#include <TDF_IDFilter.hxx>
#include <TDF_RelocationTable.hxx>
#include <Standard_TypeDef.hxx>
#include <TDF_Label.hxx>
#include <TDF_ComparisonTool.hxx>

void bind_TDF_ComparisonTool(py::module &mod){

py::class_<TDF_ComparisonTool> cls_TDF_ComparisonTool(mod, "TDF_ComparisonTool", "This class provides services to compare sets of information. The use of this tool can works after a copy, acted by a CopyTool.");

// Constructors

// Fields

// Methods
// cls_TDF_ComparisonTool.def_static("operator new_", (void * (*)(size_t)) &TDF_ComparisonTool::operator new, "None", py::arg("theSize"));
// cls_TDF_ComparisonTool.def_static("operator delete_", (void (*)(void *)) &TDF_ComparisonTool::operator delete, "None", py::arg("theAddress"));
// cls_TDF_ComparisonTool.def_static("operator new[]_", (void * (*)(size_t)) &TDF_ComparisonTool::operator new[], "None", py::arg("theSize"));
// cls_TDF_ComparisonTool.def_static("operator delete[]_", (void (*)(void *)) &TDF_ComparisonTool::operator delete[], "None", py::arg("theAddress"));
// cls_TDF_ComparisonTool.def_static("operator new_", (void * (*)(size_t, void *)) &TDF_ComparisonTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TDF_ComparisonTool.def_static("operator delete_", (void (*)(void *, void *)) &TDF_ComparisonTool::operator delete, "None", py::arg(""), py::arg(""));
cls_TDF_ComparisonTool.def_static("Compare_", (void (*)(const opencascade::handle<TDF_DataSet> &, const opencascade::handle<TDF_DataSet> &, const TDF_IDFilter &, const opencascade::handle<TDF_RelocationTable> &)) &TDF_ComparisonTool::Compare, "Compares <aSourceDataSet> with <aTargetDataSet>, updating <aRelocationTable> with labels and attributes found in both sets.", py::arg("aSourceDataSet"), py::arg("aTargetDataSet"), py::arg("aFilter"), py::arg("aRelocationTable"));
cls_TDF_ComparisonTool.def_static("SourceUnbound_", [](const opencascade::handle<TDF_DataSet> & a0, const opencascade::handle<TDF_RelocationTable> & a1, const TDF_IDFilter & a2, const opencascade::handle<TDF_DataSet> & a3) -> Standard_Boolean { return TDF_ComparisonTool::SourceUnbound(a0, a1, a2, a3); });
cls_TDF_ComparisonTool.def_static("SourceUnbound_", (Standard_Boolean (*)(const opencascade::handle<TDF_DataSet> &, const opencascade::handle<TDF_RelocationTable> &, const TDF_IDFilter &, const opencascade::handle<TDF_DataSet> &, const Standard_Integer)) &TDF_ComparisonTool::SourceUnbound, "Finds from <aRefDataSet> all the keys not bound into <aRelocationTable> and put them into <aDiffDataSet>. Returns True if the difference contains at least one key. (A key is a source object).", py::arg("aRefDataSet"), py::arg("aRelocationTable"), py::arg("aFilter"), py::arg("aDiffDataSet"), py::arg("anOption"));
cls_TDF_ComparisonTool.def_static("TargetUnbound_", [](const opencascade::handle<TDF_DataSet> & a0, const opencascade::handle<TDF_RelocationTable> & a1, const TDF_IDFilter & a2, const opencascade::handle<TDF_DataSet> & a3) -> Standard_Boolean { return TDF_ComparisonTool::TargetUnbound(a0, a1, a2, a3); });
cls_TDF_ComparisonTool.def_static("TargetUnbound_", (Standard_Boolean (*)(const opencascade::handle<TDF_DataSet> &, const opencascade::handle<TDF_RelocationTable> &, const TDF_IDFilter &, const opencascade::handle<TDF_DataSet> &, const Standard_Integer)) &TDF_ComparisonTool::TargetUnbound, "Substracts from <aRefDataSet> all the items bound into <aRelocationTable>. The result is put into <aDiffDataSet>. Returns True if the difference contains at least one item. (An item is a target object).", py::arg("aRefDataSet"), py::arg("aRelocationTable"), py::arg("aFilter"), py::arg("aDiffDataSet"), py::arg("anOption"));
cls_TDF_ComparisonTool.def_static("Cut_", (void (*)(const opencascade::handle<TDF_DataSet> &)) &TDF_ComparisonTool::Cut, "Removes attributes from <aDataSet>.", py::arg("aDataSet"));
cls_TDF_ComparisonTool.def_static("IsSelfContained_", (Standard_Boolean (*)(const TDF_Label &, const opencascade::handle<TDF_DataSet> &)) &TDF_ComparisonTool::IsSelfContained, "Returns true if all the labels of <aDataSet> are descendant of <aLabel>.", py::arg("aLabel"), py::arg("aDataSet"));

// Enums

}