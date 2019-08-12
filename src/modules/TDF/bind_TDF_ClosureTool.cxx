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
#include <TDF_ClosureMode.hxx>
#include <TDF_Label.hxx>
#include <TDF_LabelMap.hxx>
#include <TDF_AttributeMap.hxx>
#include <TDF_ClosureTool.hxx>

void bind_TDF_ClosureTool(py::module &mod){

py::class_<TDF_ClosureTool, std::unique_ptr<TDF_ClosureTool, Deleter<TDF_ClosureTool>>> cls_TDF_ClosureTool(mod, "TDF_ClosureTool", "This class provides services to build the closure of an information set. This class gives services around the transitive enclosure of a set of information, starting from a list of label. You can set closure options by using IDFilter (to select or exclude specific attribute IDs) and CopyOption objects and by giving to Closure method.");

// Constructors

// Fields

// Methods
// cls_TDF_ClosureTool.def_static("operator new_", (void * (*)(size_t)) &TDF_ClosureTool::operator new, "None", py::arg("theSize"));
// cls_TDF_ClosureTool.def_static("operator delete_", (void (*)(void *)) &TDF_ClosureTool::operator delete, "None", py::arg("theAddress"));
// cls_TDF_ClosureTool.def_static("operator new[]_", (void * (*)(size_t)) &TDF_ClosureTool::operator new[], "None", py::arg("theSize"));
// cls_TDF_ClosureTool.def_static("operator delete[]_", (void (*)(void *)) &TDF_ClosureTool::operator delete[], "None", py::arg("theAddress"));
// cls_TDF_ClosureTool.def_static("operator new_", (void * (*)(size_t, void *)) &TDF_ClosureTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TDF_ClosureTool.def_static("operator delete_", (void (*)(void *, void *)) &TDF_ClosureTool::operator delete, "None", py::arg(""), py::arg(""));
cls_TDF_ClosureTool.def_static("Closure_", (void (*)(const opencascade::handle<TDF_DataSet> &)) &TDF_ClosureTool::Closure, "Builds the transitive closure of label and attribute sets into <aDataSet>.", py::arg("aDataSet"));
cls_TDF_ClosureTool.def_static("Closure_", (void (*)(const opencascade::handle<TDF_DataSet> &, const TDF_IDFilter &, const TDF_ClosureMode &)) &TDF_ClosureTool::Closure, "Builds the transitive closure of label and attribute sets into <aDataSet>. Uses <aFilter> to determine if an attribute has to be taken in account or not. Uses <aMode> for various way of closing.", py::arg("aDataSet"), py::arg("aFilter"), py::arg("aMode"));
cls_TDF_ClosureTool.def_static("Closure_", (void (*)(const TDF_Label &, TDF_LabelMap &, TDF_AttributeMap &, const TDF_IDFilter &, const TDF_ClosureMode &)) &TDF_ClosureTool::Closure, "Builds the transitive closure of <aLabel>.", py::arg("aLabel"), py::arg("aLabMap"), py::arg("anAttMap"), py::arg("aFilter"), py::arg("aMode"));

// Enums

}