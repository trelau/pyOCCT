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
#include <Standard_Handle.hxx>
#include <Units_QuantitiesSequence.hxx>
#include <Units_UnitSentence.hxx>

void bind_Units_UnitSentence(py::module &mod){

py::class_<Units_UnitSentence, std::unique_ptr<Units_UnitSentence, Deleter<Units_UnitSentence>>, Units_Sentence> cls_Units_UnitSentence(mod, "Units_UnitSentence", "This class describes all the facilities to manipulate and compute units contained in a string expression.");

// Constructors
cls_Units_UnitSentence.def(py::init<const Standard_CString>(), py::arg("astring"));
cls_Units_UnitSentence.def(py::init<const Standard_CString, const opencascade::handle<Units_QuantitiesSequence> &>(), py::arg("astring"), py::arg("aquantitiessequence"));

// Fields

// Methods
// cls_Units_UnitSentence.def_static("operator new_", (void * (*)(size_t)) &Units_UnitSentence::operator new, "None", py::arg("theSize"));
// cls_Units_UnitSentence.def_static("operator delete_", (void (*)(void *)) &Units_UnitSentence::operator delete, "None", py::arg("theAddress"));
// cls_Units_UnitSentence.def_static("operator new[]_", (void * (*)(size_t)) &Units_UnitSentence::operator new[], "None", py::arg("theSize"));
// cls_Units_UnitSentence.def_static("operator delete[]_", (void (*)(void *)) &Units_UnitSentence::operator delete[], "None", py::arg("theAddress"));
// cls_Units_UnitSentence.def_static("operator new_", (void * (*)(size_t, void *)) &Units_UnitSentence::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Units_UnitSentence.def_static("operator delete_", (void (*)(void *, void *)) &Units_UnitSentence::operator delete, "None", py::arg(""), py::arg(""));
cls_Units_UnitSentence.def("Analyse", (void (Units_UnitSentence::*)()) &Units_UnitSentence::Analyse, "Analyzes the sequence of tokens created by the constructor to find the true significance of each token.");
cls_Units_UnitSentence.def("SetUnits", (void (Units_UnitSentence::*)(const opencascade::handle<Units_QuantitiesSequence> &)) &Units_UnitSentence::SetUnits, "For each token which represents a unit, finds in the sequence of physical quantities all the characteristics of the unit found.", py::arg("aquantitiessequence"));

// Enums

}