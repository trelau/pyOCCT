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
#include <TDF_Label.hxx>
#include <TNaming_NewShapeIterator.hxx>
#include <TNaming_Iterator.hxx>
#include <Standard_Handle.hxx>
#include <TNaming_NamedShape.hxx>
#include <TNaming_Tool.hxx>
#include <TNaming_Name.hxx>
#include <TNaming_Naming.hxx>
#include <TNaming_UsedShapes.hxx>
#include <TNaming_PtrNode.hxx>

void bind_TNaming_NewShapeIterator(py::module &mod){

py::class_<TNaming_NewShapeIterator> cls_TNaming_NewShapeIterator(mod, "TNaming_NewShapeIterator", "Iterates on all the descendants of a shape");

// Constructors
cls_TNaming_NewShapeIterator.def(py::init<const TopoDS_Shape &, const Standard_Integer, const TDF_Label &>(), py::arg("aShape"), py::arg("Transaction"), py::arg("access"));
cls_TNaming_NewShapeIterator.def(py::init<const TopoDS_Shape &, const TDF_Label &>(), py::arg("aShape"), py::arg("access"));
cls_TNaming_NewShapeIterator.def(py::init<const TNaming_NewShapeIterator &>(), py::arg("anIterator"));
cls_TNaming_NewShapeIterator.def(py::init<const TNaming_Iterator &>(), py::arg("anIterator"));

// Fields

// Methods
// cls_TNaming_NewShapeIterator.def_static("operator new_", (void * (*)(size_t)) &TNaming_NewShapeIterator::operator new, "None", py::arg("theSize"));
// cls_TNaming_NewShapeIterator.def_static("operator delete_", (void (*)(void *)) &TNaming_NewShapeIterator::operator delete, "None", py::arg("theAddress"));
// cls_TNaming_NewShapeIterator.def_static("operator new[]_", (void * (*)(size_t)) &TNaming_NewShapeIterator::operator new[], "None", py::arg("theSize"));
// cls_TNaming_NewShapeIterator.def_static("operator delete[]_", (void (*)(void *)) &TNaming_NewShapeIterator::operator delete[], "None", py::arg("theAddress"));
// cls_TNaming_NewShapeIterator.def_static("operator new_", (void * (*)(size_t, void *)) &TNaming_NewShapeIterator::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TNaming_NewShapeIterator.def_static("operator delete_", (void (*)(void *, void *)) &TNaming_NewShapeIterator::operator delete, "None", py::arg(""), py::arg(""));
cls_TNaming_NewShapeIterator.def("More", (Standard_Boolean (TNaming_NewShapeIterator::*)() const) &TNaming_NewShapeIterator::More, "None");
cls_TNaming_NewShapeIterator.def("Next", (void (TNaming_NewShapeIterator::*)()) &TNaming_NewShapeIterator::Next, "None");
cls_TNaming_NewShapeIterator.def("Label", (TDF_Label (TNaming_NewShapeIterator::*)() const) &TNaming_NewShapeIterator::Label, "None");
cls_TNaming_NewShapeIterator.def("NamedShape", (opencascade::handle<TNaming_NamedShape> (TNaming_NewShapeIterator::*)() const) &TNaming_NewShapeIterator::NamedShape, "None");
cls_TNaming_NewShapeIterator.def("Shape", (const TopoDS_Shape & (TNaming_NewShapeIterator::*)() const) &TNaming_NewShapeIterator::Shape, "Warning! Can be a Null Shape if a descendant is deleted.");
cls_TNaming_NewShapeIterator.def("IsModification", (Standard_Boolean (TNaming_NewShapeIterator::*)() const) &TNaming_NewShapeIterator::IsModification, "True if the new shape is a modification (split, fuse,etc...) of the old shape.");

// Enums

}