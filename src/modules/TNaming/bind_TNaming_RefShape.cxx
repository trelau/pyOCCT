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
#include <TNaming_PtrNode.hxx>
#include <TDF_Label.hxx>
#include <Standard_Handle.hxx>
#include <TNaming_NamedShape.hxx>
#include <TNaming_RefShape.hxx>

void bind_TNaming_RefShape(py::module &mod){

py::class_<TNaming_RefShape> cls_TNaming_RefShape(mod, "TNaming_RefShape", "None");

// Constructors
cls_TNaming_RefShape.def(py::init<>());
cls_TNaming_RefShape.def(py::init<const TopoDS_Shape &>(), py::arg("S"));

// Fields

// Methods
// cls_TNaming_RefShape.def_static("operator new_", (void * (*)(size_t)) &TNaming_RefShape::operator new, "None", py::arg("theSize"));
// cls_TNaming_RefShape.def_static("operator delete_", (void (*)(void *)) &TNaming_RefShape::operator delete, "None", py::arg("theAddress"));
// cls_TNaming_RefShape.def_static("operator new[]_", (void * (*)(size_t)) &TNaming_RefShape::operator new[], "None", py::arg("theSize"));
// cls_TNaming_RefShape.def_static("operator delete[]_", (void (*)(void *)) &TNaming_RefShape::operator delete[], "None", py::arg("theAddress"));
// cls_TNaming_RefShape.def_static("operator new_", (void * (*)(size_t, void *)) &TNaming_RefShape::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TNaming_RefShape.def_static("operator delete_", (void (*)(void *, void *)) &TNaming_RefShape::operator delete, "None", py::arg(""), py::arg(""));
cls_TNaming_RefShape.def("Shape", (void (TNaming_RefShape::*)(const TopoDS_Shape &)) &TNaming_RefShape::Shape, "None", py::arg("S"));
// cls_TNaming_RefShape.def("FirstUse", (void (TNaming_RefShape::*)(const TNaming_PtrNode &)) &TNaming_RefShape::FirstUse, "None", py::arg("aPtr"));
// cls_TNaming_RefShape.def("FirstUse", (TNaming_PtrNode (TNaming_RefShape::*)() const) &TNaming_RefShape::FirstUse, "None");
cls_TNaming_RefShape.def("Shape", (const TopoDS_Shape & (TNaming_RefShape::*)() const) &TNaming_RefShape::Shape, "None");
cls_TNaming_RefShape.def("Label", (TDF_Label (TNaming_RefShape::*)() const) &TNaming_RefShape::Label, "None");
cls_TNaming_RefShape.def("NamedShape", (opencascade::handle<TNaming_NamedShape> (TNaming_RefShape::*)() const) &TNaming_RefShape::NamedShape, "None");

// Enums

}