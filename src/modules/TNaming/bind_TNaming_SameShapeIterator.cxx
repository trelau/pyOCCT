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
#include <TDF_Label.hxx>
#include <Standard_TypeDef.hxx>
#include <TNaming_Tool.hxx>
#include <Standard_Handle.hxx>
#include <TNaming_UsedShapes.hxx>
#include <TNaming_PtrNode.hxx>
#include <TNaming_SameShapeIterator.hxx>

void bind_TNaming_SameShapeIterator(py::module &mod){

py::class_<TNaming_SameShapeIterator> cls_TNaming_SameShapeIterator(mod, "TNaming_SameShapeIterator", "To iterate on all the label which contained a given shape.");

// Constructors
cls_TNaming_SameShapeIterator.def(py::init<const TopoDS_Shape &, const TDF_Label &>(), py::arg("aShape"), py::arg("access"));

// Fields

// Methods
// cls_TNaming_SameShapeIterator.def_static("operator new_", (void * (*)(size_t)) &TNaming_SameShapeIterator::operator new, "None", py::arg("theSize"));
// cls_TNaming_SameShapeIterator.def_static("operator delete_", (void (*)(void *)) &TNaming_SameShapeIterator::operator delete, "None", py::arg("theAddress"));
// cls_TNaming_SameShapeIterator.def_static("operator new[]_", (void * (*)(size_t)) &TNaming_SameShapeIterator::operator new[], "None", py::arg("theSize"));
// cls_TNaming_SameShapeIterator.def_static("operator delete[]_", (void (*)(void *)) &TNaming_SameShapeIterator::operator delete[], "None", py::arg("theAddress"));
// cls_TNaming_SameShapeIterator.def_static("operator new_", (void * (*)(size_t, void *)) &TNaming_SameShapeIterator::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TNaming_SameShapeIterator.def_static("operator delete_", (void (*)(void *, void *)) &TNaming_SameShapeIterator::operator delete, "None", py::arg(""), py::arg(""));
cls_TNaming_SameShapeIterator.def("More", (Standard_Boolean (TNaming_SameShapeIterator::*)() const) &TNaming_SameShapeIterator::More, "None");
cls_TNaming_SameShapeIterator.def("Next", (void (TNaming_SameShapeIterator::*)()) &TNaming_SameShapeIterator::Next, "None");
cls_TNaming_SameShapeIterator.def("Label", (TDF_Label (TNaming_SameShapeIterator::*)() const) &TNaming_SameShapeIterator::Label, "None");

// Enums

}