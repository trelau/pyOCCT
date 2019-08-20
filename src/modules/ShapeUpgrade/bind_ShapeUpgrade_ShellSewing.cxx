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
#include <Standard_TypeDef.hxx>
#include <TopTools_IndexedMapOfShape.hxx>
#include <Standard_Handle.hxx>
#include <ShapeBuild_ReShape.hxx>
#include <ShapeUpgrade_ShellSewing.hxx>

void bind_ShapeUpgrade_ShellSewing(py::module &mod){

py::class_<ShapeUpgrade_ShellSewing, std::unique_ptr<ShapeUpgrade_ShellSewing>> cls_ShapeUpgrade_ShellSewing(mod, "ShapeUpgrade_ShellSewing", "This class provides a tool for applying sewing algorithm from BRepBuilderAPI: it takes a shape, calls sewing for each shell, and then replaces sewed shells with use of ShapeBuild_ReShape");

// Constructors
cls_ShapeUpgrade_ShellSewing.def(py::init<>());

// Fields

// Methods
// cls_ShapeUpgrade_ShellSewing.def_static("operator new_", (void * (*)(size_t)) &ShapeUpgrade_ShellSewing::operator new, "None", py::arg("theSize"));
// cls_ShapeUpgrade_ShellSewing.def_static("operator delete_", (void (*)(void *)) &ShapeUpgrade_ShellSewing::operator delete, "None", py::arg("theAddress"));
// cls_ShapeUpgrade_ShellSewing.def_static("operator new[]_", (void * (*)(size_t)) &ShapeUpgrade_ShellSewing::operator new[], "None", py::arg("theSize"));
// cls_ShapeUpgrade_ShellSewing.def_static("operator delete[]_", (void (*)(void *)) &ShapeUpgrade_ShellSewing::operator delete[], "None", py::arg("theAddress"));
// cls_ShapeUpgrade_ShellSewing.def_static("operator new_", (void * (*)(size_t, void *)) &ShapeUpgrade_ShellSewing::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_ShapeUpgrade_ShellSewing.def_static("operator delete_", (void (*)(void *, void *)) &ShapeUpgrade_ShellSewing::operator delete, "None", py::arg(""), py::arg(""));
cls_ShapeUpgrade_ShellSewing.def("ApplySewing", [](ShapeUpgrade_ShellSewing &self, const TopoDS_Shape & a0) -> TopoDS_Shape { return self.ApplySewing(a0); });
cls_ShapeUpgrade_ShellSewing.def("ApplySewing", (TopoDS_Shape (ShapeUpgrade_ShellSewing::*)(const TopoDS_Shape &, const Standard_Real)) &ShapeUpgrade_ShellSewing::ApplySewing, "Builds a new shape from a former one, by calling Sewing from BRepBuilderAPI. Rebuilt solids are oriented to be 'not infinite'", py::arg("shape"), py::arg("tol"));

// Enums

}