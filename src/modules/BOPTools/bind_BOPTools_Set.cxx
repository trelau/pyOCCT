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
#include <NCollection_BaseAllocator.hxx>
#include <BOPTools_Set.hxx>
#include <TopoDS_Shape.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <Standard_TypeDef.hxx>
#include <TopTools_ListOfShape.hxx>

void bind_BOPTools_Set(py::module &mod){

py::class_<BOPTools_Set, std::unique_ptr<BOPTools_Set, Deleter<BOPTools_Set>>> cls_BOPTools_Set(mod, "BOPTools_Set", "None");

// Constructors
cls_BOPTools_Set.def(py::init<>());
cls_BOPTools_Set.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));

// Fields

// Methods
// cls_BOPTools_Set.def_static("operator new_", (void * (*)(size_t)) &BOPTools_Set::operator new, "None", py::arg("theSize"));
// cls_BOPTools_Set.def_static("operator delete_", (void (*)(void *)) &BOPTools_Set::operator delete, "None", py::arg("theAddress"));
// cls_BOPTools_Set.def_static("operator new[]_", (void * (*)(size_t)) &BOPTools_Set::operator new[], "None", py::arg("theSize"));
// cls_BOPTools_Set.def_static("operator delete[]_", (void (*)(void *)) &BOPTools_Set::operator delete[], "None", py::arg("theAddress"));
// cls_BOPTools_Set.def_static("operator new_", (void * (*)(size_t, void *)) &BOPTools_Set::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BOPTools_Set.def_static("operator delete_", (void (*)(void *, void *)) &BOPTools_Set::operator delete, "None", py::arg(""), py::arg(""));
cls_BOPTools_Set.def("Assign", (BOPTools_Set & (BOPTools_Set::*)(const BOPTools_Set &)) &BOPTools_Set::Assign, "None", py::arg("Other"));
// cls_BOPTools_Set.def("operator=", (BOPTools_Set & (BOPTools_Set::*)(const BOPTools_Set &)) &BOPTools_Set::operator=, "None", py::arg("Other"));
cls_BOPTools_Set.def("Shape", (const TopoDS_Shape & (BOPTools_Set::*)() const) &BOPTools_Set::Shape, "None");
cls_BOPTools_Set.def("Add", (void (BOPTools_Set::*)(const TopoDS_Shape &, const TopAbs_ShapeEnum)) &BOPTools_Set::Add, "None", py::arg("theS"), py::arg("theType"));
cls_BOPTools_Set.def("NbShapes", (Standard_Integer (BOPTools_Set::*)() const) &BOPTools_Set::NbShapes, "None");
cls_BOPTools_Set.def("IsEqual", (Standard_Boolean (BOPTools_Set::*)(const BOPTools_Set &) const) &BOPTools_Set::IsEqual, "None", py::arg("aOther"));
cls_BOPTools_Set.def("HashCode", (Standard_Integer (BOPTools_Set::*)(const Standard_Integer) const) &BOPTools_Set::HashCode, "None", py::arg("Upper"));

// Enums

}