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
#include <Expr_SingleRelation.hxx>
#include <Expr_Array1OfSingleRelation.hxx>
#include <Expr_RelationIterator.hxx>

void bind_Expr_RelationIterator(py::module &mod){

py::class_<Expr_RelationIterator, std::unique_ptr<Expr_RelationIterator, Deleter<Expr_RelationIterator>>> cls_Expr_RelationIterator(mod, "Expr_RelationIterator", "Iterates on every basic relation contained in a GeneralRelation.");

// Constructors
cls_Expr_RelationIterator.def(py::init<const opencascade::handle<Expr_GeneralRelation> &>(), py::arg("rel"));

// Fields

// Methods
// cls_Expr_RelationIterator.def_static("operator new_", (void * (*)(size_t)) &Expr_RelationIterator::operator new, "None", py::arg("theSize"));
// cls_Expr_RelationIterator.def_static("operator delete_", (void (*)(void *)) &Expr_RelationIterator::operator delete, "None", py::arg("theAddress"));
// cls_Expr_RelationIterator.def_static("operator new[]_", (void * (*)(size_t)) &Expr_RelationIterator::operator new[], "None", py::arg("theSize"));
// cls_Expr_RelationIterator.def_static("operator delete[]_", (void (*)(void *)) &Expr_RelationIterator::operator delete[], "None", py::arg("theAddress"));
// cls_Expr_RelationIterator.def_static("operator new_", (void * (*)(size_t, void *)) &Expr_RelationIterator::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Expr_RelationIterator.def_static("operator delete_", (void (*)(void *, void *)) &Expr_RelationIterator::operator delete, "None", py::arg(""), py::arg(""));
cls_Expr_RelationIterator.def("More", (Standard_Boolean (Expr_RelationIterator::*)() const) &Expr_RelationIterator::More, "Returns False if no other relation remains.");
cls_Expr_RelationIterator.def("Next", (void (Expr_RelationIterator::*)()) &Expr_RelationIterator::Next, "None");
cls_Expr_RelationIterator.def("Value", (opencascade::handle<Expr_SingleRelation> (Expr_RelationIterator::*)() const) &Expr_RelationIterator::Value, "Returns current basic relation. Exception is raised if no more relation remains.");

// Enums

}