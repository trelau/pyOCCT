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
#include <TNaming_NamedShape.hxx>
#include <TDF_Label.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Shape.hxx>
#include <TNaming_Evolution.hxx>
#include <TNaming_NewShapeIterator.hxx>
#include <TNaming_OldShapeIterator.hxx>
#include <TNaming_PtrNode.hxx>
#include <TNaming_Iterator.hxx>

void bind_TNaming_Iterator(py::module &mod){

py::class_<TNaming_Iterator> cls_TNaming_Iterator(mod, "TNaming_Iterator", "A tool to visit the contents of a named shape attribute. Pairs of shapes in the attribute are iterated, one being the pre-modification or the old shape, and the other the post-modification or the new shape. This allows you to have a full access to all contents of an attribute. If, on the other hand, you are only interested in topological entities stored in the attribute, you can use the functions GetShape and CurrentShape in TNaming_Tool.");

// Constructors
cls_TNaming_Iterator.def(py::init<const opencascade::handle<TNaming_NamedShape> &>(), py::arg("anAtt"));
cls_TNaming_Iterator.def(py::init<const TDF_Label &>(), py::arg("aLabel"));
cls_TNaming_Iterator.def(py::init<const TDF_Label &, const Standard_Integer>(), py::arg("aLabel"), py::arg("aTrans"));

// Fields

// Methods
// cls_TNaming_Iterator.def_static("operator new_", (void * (*)(size_t)) &TNaming_Iterator::operator new, "None", py::arg("theSize"));
// cls_TNaming_Iterator.def_static("operator delete_", (void (*)(void *)) &TNaming_Iterator::operator delete, "None", py::arg("theAddress"));
// cls_TNaming_Iterator.def_static("operator new[]_", (void * (*)(size_t)) &TNaming_Iterator::operator new[], "None", py::arg("theSize"));
// cls_TNaming_Iterator.def_static("operator delete[]_", (void (*)(void *)) &TNaming_Iterator::operator delete[], "None", py::arg("theAddress"));
// cls_TNaming_Iterator.def_static("operator new_", (void * (*)(size_t, void *)) &TNaming_Iterator::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TNaming_Iterator.def_static("operator delete_", (void (*)(void *, void *)) &TNaming_Iterator::operator delete, "None", py::arg(""), py::arg(""));
cls_TNaming_Iterator.def("More", (Standard_Boolean (TNaming_Iterator::*)() const) &TNaming_Iterator::More, "Returns True if there is a current Item in the iteration.");
cls_TNaming_Iterator.def("Next", (void (TNaming_Iterator::*)()) &TNaming_Iterator::Next, "Moves the iteration to the next Item");
cls_TNaming_Iterator.def("OldShape", (const TopoDS_Shape & (TNaming_Iterator::*)() const) &TNaming_Iterator::OldShape, "Returns the old shape in this iterator object. This shape can be a null one.");
cls_TNaming_Iterator.def("NewShape", (const TopoDS_Shape & (TNaming_Iterator::*)() const) &TNaming_Iterator::NewShape, "Returns the new shape in this iterator object.");
cls_TNaming_Iterator.def("IsModification", (Standard_Boolean (TNaming_Iterator::*)() const) &TNaming_Iterator::IsModification, "Returns true if the new shape is a modification (split, fuse,etc...) of the old shape.");
cls_TNaming_Iterator.def("Evolution", (TNaming_Evolution (TNaming_Iterator::*)() const) &TNaming_Iterator::Evolution, "None");

// Enums

}