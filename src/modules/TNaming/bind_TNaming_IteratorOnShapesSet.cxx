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
#include <TNaming_ShapesSet.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Shape.hxx>
#include <TopTools_MapOfShape.hxx>
#include <TNaming_IteratorOnShapesSet.hxx>

void bind_TNaming_IteratorOnShapesSet(py::module &mod){

py::class_<TNaming_IteratorOnShapesSet, std::unique_ptr<TNaming_IteratorOnShapesSet, Deleter<TNaming_IteratorOnShapesSet>>> cls_TNaming_IteratorOnShapesSet(mod, "TNaming_IteratorOnShapesSet", "None");

// Constructors
cls_TNaming_IteratorOnShapesSet.def(py::init<>());
cls_TNaming_IteratorOnShapesSet.def(py::init<const TNaming_ShapesSet &>(), py::arg("S"));

// Fields

// Methods
// cls_TNaming_IteratorOnShapesSet.def_static("operator new_", (void * (*)(size_t)) &TNaming_IteratorOnShapesSet::operator new, "None", py::arg("theSize"));
// cls_TNaming_IteratorOnShapesSet.def_static("operator delete_", (void (*)(void *)) &TNaming_IteratorOnShapesSet::operator delete, "None", py::arg("theAddress"));
// cls_TNaming_IteratorOnShapesSet.def_static("operator new[]_", (void * (*)(size_t)) &TNaming_IteratorOnShapesSet::operator new[], "None", py::arg("theSize"));
// cls_TNaming_IteratorOnShapesSet.def_static("operator delete[]_", (void (*)(void *)) &TNaming_IteratorOnShapesSet::operator delete[], "None", py::arg("theAddress"));
// cls_TNaming_IteratorOnShapesSet.def_static("operator new_", (void * (*)(size_t, void *)) &TNaming_IteratorOnShapesSet::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TNaming_IteratorOnShapesSet.def_static("operator delete_", (void (*)(void *, void *)) &TNaming_IteratorOnShapesSet::operator delete, "None", py::arg(""), py::arg(""));
cls_TNaming_IteratorOnShapesSet.def("Init", (void (TNaming_IteratorOnShapesSet::*)(const TNaming_ShapesSet &)) &TNaming_IteratorOnShapesSet::Init, "Initialize the iteration", py::arg("S"));
cls_TNaming_IteratorOnShapesSet.def("More", (Standard_Boolean (TNaming_IteratorOnShapesSet::*)() const) &TNaming_IteratorOnShapesSet::More, "Returns True if there is a current Item in the iteration.");
cls_TNaming_IteratorOnShapesSet.def("Next", (void (TNaming_IteratorOnShapesSet::*)()) &TNaming_IteratorOnShapesSet::Next, "Move to the next Item");
cls_TNaming_IteratorOnShapesSet.def("Value", (const TopoDS_Shape & (TNaming_IteratorOnShapesSet::*)() const) &TNaming_IteratorOnShapesSet::Value, "None");

// Enums

}