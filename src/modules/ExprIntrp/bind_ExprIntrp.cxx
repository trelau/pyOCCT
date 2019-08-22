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
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <ExprIntrp_Generator.hxx>
#include <TCollection_AsciiString.hxx>
#include <ExprIntrp_GenExp.hxx>
#include <ExprIntrp_GenFct.hxx>
#include <ExprIntrp_GenRel.hxx>
#include <ExprIntrp_Analysis.hxx>
#include <ExprIntrp.hxx>

void bind_ExprIntrp(py::module &mod){

py::class_<ExprIntrp> cls_ExprIntrp(mod, "ExprIntrp", "Describes an interpreter for GeneralExpressions, GeneralFunctions, and GeneralRelations defined in package Expr.");

// Constructors

// Fields

// Methods
// cls_ExprIntrp.def_static("operator new_", (void * (*)(size_t)) &ExprIntrp::operator new, "None", py::arg("theSize"));
// cls_ExprIntrp.def_static("operator delete_", (void (*)(void *)) &ExprIntrp::operator delete, "None", py::arg("theAddress"));
// cls_ExprIntrp.def_static("operator new[]_", (void * (*)(size_t)) &ExprIntrp::operator new[], "None", py::arg("theSize"));
// cls_ExprIntrp.def_static("operator delete[]_", (void (*)(void *)) &ExprIntrp::operator delete[], "None", py::arg("theAddress"));
// cls_ExprIntrp.def_static("operator new_", (void * (*)(size_t, void *)) &ExprIntrp::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_ExprIntrp.def_static("operator delete_", (void (*)(void *, void *)) &ExprIntrp::operator delete, "None", py::arg(""), py::arg(""));

// Enums

}