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
#include <BOPAlgo_Builder.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <TopoDS_Shape.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TopTools_MapOfShape.hxx>
#include <BOPAlgo_ToolsProvider.hxx>

void bind_BOPAlgo_ToolsProvider(py::module &mod){

py::class_<BOPAlgo_ToolsProvider, std::unique_ptr<BOPAlgo_ToolsProvider>, BOPAlgo_Builder> cls_BOPAlgo_ToolsProvider(mod, "BOPAlgo_ToolsProvider", "Auxiliary class providing API to operate tool arguments.");

// Constructors
cls_BOPAlgo_ToolsProvider.def(py::init<>());
cls_BOPAlgo_ToolsProvider.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));

// Fields

// Methods
// cls_BOPAlgo_ToolsProvider.def_static("operator new_", (void * (*)(size_t)) &BOPAlgo_ToolsProvider::operator new, "None", py::arg("theSize"));
// cls_BOPAlgo_ToolsProvider.def_static("operator delete_", (void (*)(void *)) &BOPAlgo_ToolsProvider::operator delete, "None", py::arg("theAddress"));
// cls_BOPAlgo_ToolsProvider.def_static("operator new[]_", (void * (*)(size_t)) &BOPAlgo_ToolsProvider::operator new[], "None", py::arg("theSize"));
// cls_BOPAlgo_ToolsProvider.def_static("operator delete[]_", (void (*)(void *)) &BOPAlgo_ToolsProvider::operator delete[], "None", py::arg("theAddress"));
// cls_BOPAlgo_ToolsProvider.def_static("operator new_", (void * (*)(size_t, void *)) &BOPAlgo_ToolsProvider::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BOPAlgo_ToolsProvider.def_static("operator delete_", (void (*)(void *, void *)) &BOPAlgo_ToolsProvider::operator delete, "None", py::arg(""), py::arg(""));
cls_BOPAlgo_ToolsProvider.def("Clear", (void (BOPAlgo_ToolsProvider::*)()) &BOPAlgo_ToolsProvider::Clear, "Clears internal fields and arguments");
cls_BOPAlgo_ToolsProvider.def("AddTool", (void (BOPAlgo_ToolsProvider::*)(const TopoDS_Shape &)) &BOPAlgo_ToolsProvider::AddTool, "Adds Tool argument of the operation", py::arg("theShape"));
cls_BOPAlgo_ToolsProvider.def("SetTools", (void (BOPAlgo_ToolsProvider::*)(const TopTools_ListOfShape &)) &BOPAlgo_ToolsProvider::SetTools, "Adds the Tool arguments of the operation", py::arg("theShapes"));
cls_BOPAlgo_ToolsProvider.def("Tools", (const TopTools_ListOfShape & (BOPAlgo_ToolsProvider::*)() const) &BOPAlgo_ToolsProvider::Tools, "Returns the Tool arguments of the operation");

// Enums

}