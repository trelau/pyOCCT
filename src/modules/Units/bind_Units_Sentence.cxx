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
#include <Units_Lexicon.hxx>
#include <Standard_TypeDef.hxx>
#include <Units_TokensSequence.hxx>
#include <Units_Token.hxx>
#include <Units_Sentence.hxx>

void bind_Units_Sentence(py::module &mod){

py::class_<Units_Sentence, std::unique_ptr<Units_Sentence>> cls_Units_Sentence(mod, "Units_Sentence", "This class describes all the methods to create and compute an expression contained in a string.");

// Constructors
cls_Units_Sentence.def(py::init<const opencascade::handle<Units_Lexicon> &, const Standard_CString>(), py::arg("alexicon"), py::arg("astring"));

// Fields

// Methods
// cls_Units_Sentence.def_static("operator new_", (void * (*)(size_t)) &Units_Sentence::operator new, "None", py::arg("theSize"));
// cls_Units_Sentence.def_static("operator delete_", (void (*)(void *)) &Units_Sentence::operator delete, "None", py::arg("theAddress"));
// cls_Units_Sentence.def_static("operator new[]_", (void * (*)(size_t)) &Units_Sentence::operator new[], "None", py::arg("theSize"));
// cls_Units_Sentence.def_static("operator delete[]_", (void (*)(void *)) &Units_Sentence::operator delete[], "None", py::arg("theAddress"));
// cls_Units_Sentence.def_static("operator new_", (void * (*)(size_t, void *)) &Units_Sentence::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Units_Sentence.def_static("operator delete_", (void (*)(void *, void *)) &Units_Sentence::operator delete, "None", py::arg(""), py::arg(""));
cls_Units_Sentence.def("SetConstants", (void (Units_Sentence::*)()) &Units_Sentence::SetConstants, "For each constant encountered, sets the value.");
cls_Units_Sentence.def("Sequence", (opencascade::handle<Units_TokensSequence> (Units_Sentence::*)() const) &Units_Sentence::Sequence, "Returns <thesequenceoftokens>.");
cls_Units_Sentence.def("Sequence", (void (Units_Sentence::*)(const opencascade::handle<Units_TokensSequence> &)) &Units_Sentence::Sequence, "Sets the field <thesequenceoftokens> to <asequenceoftokens>.", py::arg("asequenceoftokens"));
cls_Units_Sentence.def("Evaluate", (opencascade::handle<Units_Token> (Units_Sentence::*)()) &Units_Sentence::Evaluate, "Computes and returns in a token the result of the expression.");
cls_Units_Sentence.def("IsDone", (Standard_Boolean (Units_Sentence::*)() const) &Units_Sentence::IsDone, "Return True if number of created tokens > 0 (i.e creation of sentence is succesfull)");
cls_Units_Sentence.def("Dump", (void (Units_Sentence::*)() const) &Units_Sentence::Dump, "Useful for debugging.");

// Enums

}