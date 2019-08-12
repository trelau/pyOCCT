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
#include <Units_UnitsDictionary.hxx>
#include <Units_Quantity.hxx>
#include <Units_Lexicon.hxx>
#include <Units_Dimensions.hxx>
#include <Units_Unit.hxx>
#include <Units_ShiftedUnit.hxx>
#include <Units_Token.hxx>
#include <Units_ShiftedToken.hxx>
#include <Units_UnitsSystem.hxx>
#include <Units_Explorer.hxx>
#include <Units_Sentence.hxx>
#include <Units_MathSentence.hxx>
#include <Units_UnitSentence.hxx>
#include <Units_UnitsLexicon.hxx>
#include <Units_Measurement.hxx>
#include <Units.hxx>

void bind_Units(py::module &mod){

py::class_<Units, std::unique_ptr<Units, Deleter<Units>>> cls_Units(mod, "Units", "This package provides all the facilities to create and question a dictionary of units, and also to manipulate measurements which are real values with units.");

// Constructors

// Fields

// Methods
// cls_Units.def_static("operator new_", (void * (*)(size_t)) &Units::operator new, "None", py::arg("theSize"));
// cls_Units.def_static("operator delete_", (void (*)(void *)) &Units::operator delete, "None", py::arg("theAddress"));
// cls_Units.def_static("operator new[]_", (void * (*)(size_t)) &Units::operator new[], "None", py::arg("theSize"));
// cls_Units.def_static("operator delete[]_", (void (*)(void *)) &Units::operator delete[], "None", py::arg("theAddress"));
// cls_Units.def_static("operator new_", (void * (*)(size_t, void *)) &Units::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Units.def_static("operator delete_", (void (*)(void *, void *)) &Units::operator delete, "None", py::arg(""), py::arg(""));
cls_Units.def_static("UnitsFile_", (void (*)(const Standard_CString)) &Units::UnitsFile, "Defines the location of the file containing all the information useful in creating the dictionary of all the units known to the system.", py::arg("afile"));
cls_Units.def_static("LexiconFile_", (void (*)(const Standard_CString)) &Units::LexiconFile, "Defines the location of the file containing the lexicon useful in manipulating composite units.", py::arg("afile"));
cls_Units.def_static("DictionaryOfUnits_", []() -> opencascade::handle<Units_UnitsDictionary> { return Units::DictionaryOfUnits(); });
cls_Units.def_static("DictionaryOfUnits_", (opencascade::handle<Units_UnitsDictionary> (*)(const Standard_Boolean)) &Units::DictionaryOfUnits, "Returns a unique instance of the dictionary of units. If <amode> is True, then it forces the recomputation of the dictionary of units.", py::arg("amode"));
cls_Units.def_static("Quantity_", (opencascade::handle<Units_Quantity> (*)(const Standard_CString)) &Units::Quantity, "Returns a unique quantity instance corresponding to <aquantity>.", py::arg("aquantity"));
cls_Units.def_static("FirstQuantity_", (Standard_CString (*)(const Standard_CString)) &Units::FirstQuantity, "Returns the first quantity string founded from the unit <aUnit>.", py::arg("aunit"));
cls_Units.def_static("LexiconUnits_", []() -> opencascade::handle<Units_Lexicon> { return Units::LexiconUnits(); });
cls_Units.def_static("LexiconUnits_", (opencascade::handle<Units_Lexicon> (*)(const Standard_Boolean)) &Units::LexiconUnits, "Returns a unique instance of the Units_Lexicon. If <amode> is True, it forces the recomputation of the dictionary of units, and by consequence the completion of the Units_Lexicon.", py::arg("amode"));
cls_Units.def_static("LexiconFormula_", (opencascade::handle<Units_Lexicon> (*)()) &Units::LexiconFormula, "Return a unique instance of LexiconFormula.");
cls_Units.def_static("NullDimensions_", (opencascade::handle<Units_Dimensions> (*)()) &Units::NullDimensions, "Returns always the same instance of Dimensions.");
cls_Units.def_static("Convert_", (Standard_Real (*)(const Standard_Real, const Standard_CString, const Standard_CString)) &Units::Convert, "Converts <avalue> expressed in <afirstunit> into the <asecondunit>.", py::arg("avalue"), py::arg("afirstunit"), py::arg("asecondunit"));
cls_Units.def_static("ToSI_", (Standard_Real (*)(const Standard_Real, const Standard_CString)) &Units::ToSI, "None", py::arg("aData"), py::arg("aUnit"));
cls_Units.def_static("ToSI_", (Standard_Real (*)(const Standard_Real, const Standard_CString, opencascade::handle<Units_Dimensions> &)) &Units::ToSI, "None", py::arg("aData"), py::arg("aUnit"), py::arg("aDim"));
cls_Units.def_static("FromSI_", (Standard_Real (*)(const Standard_Real, const Standard_CString)) &Units::FromSI, "None", py::arg("aData"), py::arg("aUnit"));
cls_Units.def_static("FromSI_", (Standard_Real (*)(const Standard_Real, const Standard_CString, opencascade::handle<Units_Dimensions> &)) &Units::FromSI, "None", py::arg("aData"), py::arg("aUnit"), py::arg("aDim"));
cls_Units.def_static("Dimensions_", (opencascade::handle<Units_Dimensions> (*)(const Standard_CString)) &Units::Dimensions, "return the dimension associated to the Type", py::arg("aType"));

// Enums

}