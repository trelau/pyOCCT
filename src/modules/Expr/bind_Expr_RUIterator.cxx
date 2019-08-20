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
#include <Expr_GeneralRelation.hxx>
#include <Standard_TypeDef.hxx>
#include <Expr_NamedUnknown.hxx>
#include <Expr_MapOfNamedUnknown.hxx>
#include <Expr_RUIterator.hxx>

void bind_Expr_RUIterator(py::module &mod){

py::class_<Expr_RUIterator, std::unique_ptr<Expr_RUIterator>> cls_Expr_RUIterator(mod, "Expr_RUIterator", "Iterates on NamedUnknowns in a GeneralRelation.");

// Constructors
cls_Expr_RUIterator.def(py::init<const opencascade::handle<Expr_GeneralRelation> &>(), py::arg("rel"));

// Fields

// Methods
// cls_Expr_RUIterator.def_static("operator new_", (void * (*)(size_t)) &Expr_RUIterator::operator new, "None", py::arg("theSize"));
// cls_Expr_RUIterator.def_static("operator delete_", (void (*)(void *)) &Expr_RUIterator::operator delete, "None", py::arg("theAddress"));
// cls_Expr_RUIterator.def_static("operator new[]_", (void * (*)(size_t)) &Expr_RUIterator::operator new[], "None", py::arg("theSize"));
// cls_Expr_RUIterator.def_static("operator delete[]_", (void (*)(void *)) &Expr_RUIterator::operator delete[], "None", py::arg("theAddress"));
// cls_Expr_RUIterator.def_static("operator new_", (void * (*)(size_t, void *)) &Expr_RUIterator::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Expr_RUIterator.def_static("operator delete_", (void (*)(void *, void *)) &Expr_RUIterator::operator delete, "None", py::arg(""), py::arg(""));
cls_Expr_RUIterator.def("More", (Standard_Boolean (Expr_RUIterator::*)() const) &Expr_RUIterator::More, "Returns False if on other unknown remains.");
cls_Expr_RUIterator.def("Next", (void (Expr_RUIterator::*)()) &Expr_RUIterator::Next, "None");
cls_Expr_RUIterator.def("Value", (opencascade::handle<Expr_NamedUnknown> (Expr_RUIterator::*)() const) &Expr_RUIterator::Value, "Returns current NamedUnknown. Raises exception if no more unknowns remain.");

// Enums

}