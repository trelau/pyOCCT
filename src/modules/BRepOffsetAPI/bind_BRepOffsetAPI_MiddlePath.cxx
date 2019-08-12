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
#include <BRepBuilderAPI_MakeShape.hxx>
#include <Standard.hxx>
#include <TopoDS_Shape.hxx>
#include <TopoDS_Wire.hxx>
#include <Standard_TypeDef.hxx>
#include <TopTools_MapOfShape.hxx>
#include <BRepOffsetAPI_SequenceOfSequenceOfShape.hxx>
#include <BRepOffsetAPI_MiddlePath.hxx>

void bind_BRepOffsetAPI_MiddlePath(py::module &mod){

py::class_<BRepOffsetAPI_MiddlePath, std::unique_ptr<BRepOffsetAPI_MiddlePath, Deleter<BRepOffsetAPI_MiddlePath>>, BRepBuilderAPI_MakeShape> cls_BRepOffsetAPI_MiddlePath(mod, "BRepOffsetAPI_MiddlePath", "Describes functions to build a middle path of a pipe-like shape");

// Constructors
cls_BRepOffsetAPI_MiddlePath.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Shape &>(), py::arg("aShape"), py::arg("StartShape"), py::arg("EndShape"));

// Fields

// Methods
// cls_BRepOffsetAPI_MiddlePath.def_static("operator new_", (void * (*)(size_t)) &BRepOffsetAPI_MiddlePath::operator new, "None", py::arg("theSize"));
// cls_BRepOffsetAPI_MiddlePath.def_static("operator delete_", (void (*)(void *)) &BRepOffsetAPI_MiddlePath::operator delete, "None", py::arg("theAddress"));
// cls_BRepOffsetAPI_MiddlePath.def_static("operator new[]_", (void * (*)(size_t)) &BRepOffsetAPI_MiddlePath::operator new[], "None", py::arg("theSize"));
// cls_BRepOffsetAPI_MiddlePath.def_static("operator delete[]_", (void (*)(void *)) &BRepOffsetAPI_MiddlePath::operator delete[], "None", py::arg("theAddress"));
// cls_BRepOffsetAPI_MiddlePath.def_static("operator new_", (void * (*)(size_t, void *)) &BRepOffsetAPI_MiddlePath::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepOffsetAPI_MiddlePath.def_static("operator delete_", (void (*)(void *, void *)) &BRepOffsetAPI_MiddlePath::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepOffsetAPI_MiddlePath.def("Build", (void (BRepOffsetAPI_MiddlePath::*)()) &BRepOffsetAPI_MiddlePath::Build, "None");

// Enums

}