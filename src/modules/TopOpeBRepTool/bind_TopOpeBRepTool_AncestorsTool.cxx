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
#include <TopoDS_Shape.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <TopTools_IndexedDataMapOfShapeListOfShape.hxx>
#include <TopOpeBRepTool_AncestorsTool.hxx>

void bind_TopOpeBRepTool_AncestorsTool(py::module &mod){

py::class_<TopOpeBRepTool_AncestorsTool, std::unique_ptr<TopOpeBRepTool_AncestorsTool>> cls_TopOpeBRepTool_AncestorsTool(mod, "TopOpeBRepTool_AncestorsTool", "Describes the ancestors tool needed by the class DSFiller from TopOpeInter.");

// Constructors

// Fields

// Methods
// cls_TopOpeBRepTool_AncestorsTool.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepTool_AncestorsTool::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepTool_AncestorsTool.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepTool_AncestorsTool::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepTool_AncestorsTool.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepTool_AncestorsTool::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepTool_AncestorsTool.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepTool_AncestorsTool::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepTool_AncestorsTool.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepTool_AncestorsTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepTool_AncestorsTool.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepTool_AncestorsTool::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepTool_AncestorsTool.def_static("MakeAncestors_", (void (*)(const TopoDS_Shape &, const TopAbs_ShapeEnum, const TopAbs_ShapeEnum, TopTools_IndexedDataMapOfShapeListOfShape &)) &TopOpeBRepTool_AncestorsTool::MakeAncestors, "same as package method TopExp::MapShapeListOfShapes()", py::arg("S"), py::arg("TS"), py::arg("TA"), py::arg("M"));

// Enums

}