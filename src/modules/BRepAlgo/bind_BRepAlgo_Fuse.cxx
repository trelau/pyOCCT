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
#include <BRepAlgo_BooleanOperation.hxx>
#include <Standard.hxx>
#include <TopoDS_Shape.hxx>
#include <BRepAlgo_Fuse.hxx>

void bind_BRepAlgo_Fuse(py::module &mod){

py::class_<BRepAlgo_Fuse, std::unique_ptr<BRepAlgo_Fuse>, BRepAlgo_BooleanOperation> cls_BRepAlgo_Fuse(mod, "BRepAlgo_Fuse", "Describes functions for performing a topological fusion operation (Boolean union). A Fuse object provides the framework for: - defining the construction of a fused shape, - implementing the construction algorithm, and - consulting the result.");

// Constructors
cls_BRepAlgo_Fuse.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &>(), py::arg("S1"), py::arg("S2"));

// Fields

// Methods
// cls_BRepAlgo_Fuse.def_static("operator new_", (void * (*)(size_t)) &BRepAlgo_Fuse::operator new, "None", py::arg("theSize"));
// cls_BRepAlgo_Fuse.def_static("operator delete_", (void (*)(void *)) &BRepAlgo_Fuse::operator delete, "None", py::arg("theAddress"));
// cls_BRepAlgo_Fuse.def_static("operator new[]_", (void * (*)(size_t)) &BRepAlgo_Fuse::operator new[], "None", py::arg("theSize"));
// cls_BRepAlgo_Fuse.def_static("operator delete[]_", (void (*)(void *)) &BRepAlgo_Fuse::operator delete[], "None", py::arg("theAddress"));
// cls_BRepAlgo_Fuse.def_static("operator new_", (void * (*)(size_t, void *)) &BRepAlgo_Fuse::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepAlgo_Fuse.def_static("operator delete_", (void (*)(void *, void *)) &BRepAlgo_Fuse::operator delete, "None", py::arg(""), py::arg(""));

// Enums

}