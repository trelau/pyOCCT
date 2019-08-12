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
#include <BRepAlgoAPI_BooleanOperation.hxx>
#include <Standard.hxx>
#include <BOPAlgo_PaveFiller.hxx>
#include <TopoDS_Shape.hxx>
#include <BRepAlgoAPI_Fuse.hxx>

void bind_BRepAlgoAPI_Fuse(py::module &mod){

py::class_<BRepAlgoAPI_Fuse, std::unique_ptr<BRepAlgoAPI_Fuse, Deleter<BRepAlgoAPI_Fuse>>, BRepAlgoAPI_BooleanOperation> cls_BRepAlgoAPI_Fuse(mod, "BRepAlgoAPI_Fuse", "The class provides Boolean fusion operation between arguments and tools (Boolean Union).");

// Constructors
cls_BRepAlgoAPI_Fuse.def(py::init<>());
cls_BRepAlgoAPI_Fuse.def(py::init<const BOPAlgo_PaveFiller &>(), py::arg("PF"));
cls_BRepAlgoAPI_Fuse.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &>(), py::arg("S1"), py::arg("S2"));
cls_BRepAlgoAPI_Fuse.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &, const BOPAlgo_PaveFiller &>(), py::arg("S1"), py::arg("S2"), py::arg("aDSF"));

// Fields

// Methods
// cls_BRepAlgoAPI_Fuse.def_static("operator new_", (void * (*)(size_t)) &BRepAlgoAPI_Fuse::operator new, "None", py::arg("theSize"));
// cls_BRepAlgoAPI_Fuse.def_static("operator delete_", (void (*)(void *)) &BRepAlgoAPI_Fuse::operator delete, "None", py::arg("theAddress"));
// cls_BRepAlgoAPI_Fuse.def_static("operator new[]_", (void * (*)(size_t)) &BRepAlgoAPI_Fuse::operator new[], "None", py::arg("theSize"));
// cls_BRepAlgoAPI_Fuse.def_static("operator delete[]_", (void (*)(void *)) &BRepAlgoAPI_Fuse::operator delete[], "None", py::arg("theAddress"));
// cls_BRepAlgoAPI_Fuse.def_static("operator new_", (void * (*)(size_t, void *)) &BRepAlgoAPI_Fuse::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepAlgoAPI_Fuse.def_static("operator delete_", (void (*)(void *, void *)) &BRepAlgoAPI_Fuse::operator delete, "None", py::arg(""), py::arg(""));

// Enums

}