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
#include <Units_Sentence.hxx>
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <Units_MathSentence.hxx>

void bind_Units_MathSentence(py::module &mod){

py::class_<Units_MathSentence, Units_Sentence> cls_Units_MathSentence(mod, "Units_MathSentence", "This class defines all the methods to create and compute an algebraic formula.");

// Constructors
cls_Units_MathSentence.def(py::init<const Standard_CString>(), py::arg("astring"));

// Fields

// Methods
// cls_Units_MathSentence.def_static("operator new_", (void * (*)(size_t)) &Units_MathSentence::operator new, "None", py::arg("theSize"));
// cls_Units_MathSentence.def_static("operator delete_", (void (*)(void *)) &Units_MathSentence::operator delete, "None", py::arg("theAddress"));
// cls_Units_MathSentence.def_static("operator new[]_", (void * (*)(size_t)) &Units_MathSentence::operator new[], "None", py::arg("theSize"));
// cls_Units_MathSentence.def_static("operator delete[]_", (void (*)(void *)) &Units_MathSentence::operator delete[], "None", py::arg("theAddress"));
// cls_Units_MathSentence.def_static("operator new_", (void * (*)(size_t, void *)) &Units_MathSentence::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Units_MathSentence.def_static("operator delete_", (void (*)(void *, void *)) &Units_MathSentence::operator delete, "None", py::arg(""), py::arg(""));

// Enums

}