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
#include <TColStd_IndexedDataMapOfTransientTransient.hxx>
#include <Standard_Handle.hxx>
#include <TNaming_TranslateTool.hxx>
#include <TopLoc_Location.hxx>
#include <TNaming_CopyShape.hxx>

void bind_TNaming_CopyShape(py::module &mod){

py::class_<TNaming_CopyShape, std::unique_ptr<TNaming_CopyShape>> cls_TNaming_CopyShape(mod, "TNaming_CopyShape", "None");

// Constructors

// Fields

// Methods
// cls_TNaming_CopyShape.def_static("operator new_", (void * (*)(size_t)) &TNaming_CopyShape::operator new, "None", py::arg("theSize"));
// cls_TNaming_CopyShape.def_static("operator delete_", (void (*)(void *)) &TNaming_CopyShape::operator delete, "None", py::arg("theAddress"));
// cls_TNaming_CopyShape.def_static("operator new[]_", (void * (*)(size_t)) &TNaming_CopyShape::operator new[], "None", py::arg("theSize"));
// cls_TNaming_CopyShape.def_static("operator delete[]_", (void (*)(void *)) &TNaming_CopyShape::operator delete[], "None", py::arg("theAddress"));
// cls_TNaming_CopyShape.def_static("operator new_", (void * (*)(size_t, void *)) &TNaming_CopyShape::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TNaming_CopyShape.def_static("operator delete_", (void (*)(void *, void *)) &TNaming_CopyShape::operator delete, "None", py::arg(""), py::arg(""));
cls_TNaming_CopyShape.def_static("CopyTool_", (void (*)(const TopoDS_Shape &, TColStd_IndexedDataMapOfTransientTransient &, TopoDS_Shape &)) &TNaming_CopyShape::CopyTool, "Makes copy a set of shape(s), using the aMap", py::arg("aShape"), py::arg("aMap"), py::arg("aResult"));
cls_TNaming_CopyShape.def_static("Translate_", (void (*)(const TopoDS_Shape &, TColStd_IndexedDataMapOfTransientTransient &, TopoDS_Shape &, const opencascade::handle<TNaming_TranslateTool> &)) &TNaming_CopyShape::Translate, "Translates a Transient shape(s) to Transient", py::arg("aShape"), py::arg("aMap"), py::arg("aResult"), py::arg("TrTool"));
cls_TNaming_CopyShape.def_static("Translate_", (TopLoc_Location (*)(const TopLoc_Location &, TColStd_IndexedDataMapOfTransientTransient &)) &TNaming_CopyShape::Translate, "Translates a Topological Location to an other Top. Location", py::arg("L"), py::arg("aMap"));

// Enums

}