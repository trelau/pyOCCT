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
#include <Expr_GeneralExpression.hxx>
#include <Standard_TypeDef.hxx>
#include <Expr_NamedUnknown.hxx>
#include <Expr_MapOfNamedUnknown.hxx>
#include <Expr_UnknownIterator.hxx>

void bind_Expr_UnknownIterator(py::module &mod){

py::class_<Expr_UnknownIterator, std::unique_ptr<Expr_UnknownIterator, Deleter<Expr_UnknownIterator>>> cls_Expr_UnknownIterator(mod, "Expr_UnknownIterator", "Describes an iterator on NamedUnknowns contained in any GeneralExpression.");

// Constructors
cls_Expr_UnknownIterator.def(py::init<const opencascade::handle<Expr_GeneralExpression> &>(), py::arg("exp"));

// Fields

// Methods
// cls_Expr_UnknownIterator.def_static("operator new_", (void * (*)(size_t)) &Expr_UnknownIterator::operator new, "None", py::arg("theSize"));
// cls_Expr_UnknownIterator.def_static("operator delete_", (void (*)(void *)) &Expr_UnknownIterator::operator delete, "None", py::arg("theAddress"));
// cls_Expr_UnknownIterator.def_static("operator new[]_", (void * (*)(size_t)) &Expr_UnknownIterator::operator new[], "None", py::arg("theSize"));
// cls_Expr_UnknownIterator.def_static("operator delete[]_", (void (*)(void *)) &Expr_UnknownIterator::operator delete[], "None", py::arg("theAddress"));
// cls_Expr_UnknownIterator.def_static("operator new_", (void * (*)(size_t, void *)) &Expr_UnknownIterator::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Expr_UnknownIterator.def_static("operator delete_", (void (*)(void *, void *)) &Expr_UnknownIterator::operator delete, "None", py::arg(""), py::arg(""));
cls_Expr_UnknownIterator.def("More", (Standard_Boolean (Expr_UnknownIterator::*)() const) &Expr_UnknownIterator::More, "None");
cls_Expr_UnknownIterator.def("Next", (void (Expr_UnknownIterator::*)()) &Expr_UnknownIterator::Next, "None");
cls_Expr_UnknownIterator.def("Value", (opencascade::handle<Expr_NamedUnknown> (Expr_UnknownIterator::*)() const) &Expr_UnknownIterator::Value, "None");

// Enums

}