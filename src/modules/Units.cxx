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
#include <Standard_Transient.hxx>
#include <Standard_Type.hxx>
#include <TCollection_AsciiString.hxx>
#include <TColStd_HSequenceOfHAsciiString.hxx>
#include <TCollection_HAsciiString.hxx>
#include <NCollection_Sequence.hxx>
#include <Units_UtsSequence.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Units_UnitsSequence.hxx>
#include <Units_QtsSequence.hxx>
#include <Units_QuantitiesSequence.hxx>
#include <TColStd_HSequenceOfInteger.hxx>
#include <Units_TksSequence.hxx>
#include <Units_TokensSequence.hxx>
#include <Standard_NoSuchObject.hxx>
#include <Units_NoSuchType.hxx>
#include <Standard_SStream.hxx>
#include <Units_NoSuchUnit.hxx>
#include <bind_NCollection_Sequence.hxx>

PYBIND11_MODULE(Units, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.NCollection");

// CLASS: UNITS
py::class_<Units> cls_Units(mod, "Units", "This package provides all the facilities to create and question a dictionary of units, and also to manipulate measurements which are real values with units.");

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

// CLASS: UNITS_DIMENSIONS
py::class_<Units_Dimensions, opencascade::handle<Units_Dimensions>, Standard_Transient> cls_Units_Dimensions(mod, "Units_Dimensions", "This class includes all the methods to create and manipulate the dimensions of the physical quantities.");

// Constructors
cls_Units_Dimensions.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("amass"), py::arg("alength"), py::arg("atime"), py::arg("anelectriccurrent"), py::arg("athermodynamictemperature"), py::arg("anamountofsubstance"), py::arg("aluminousintensity"), py::arg("aplaneangle"), py::arg("asolidangle"));

// Methods
cls_Units_Dimensions.def("Mass", (Standard_Real (Units_Dimensions::*)() const) &Units_Dimensions::Mass, "Returns the power of mass stored in the dimensions.");
cls_Units_Dimensions.def("Length", (Standard_Real (Units_Dimensions::*)() const) &Units_Dimensions::Length, "Returns the power of length stored in the dimensions.");
cls_Units_Dimensions.def("Time", (Standard_Real (Units_Dimensions::*)() const) &Units_Dimensions::Time, "Returns the power of time stored in the dimensions.");
cls_Units_Dimensions.def("ElectricCurrent", (Standard_Real (Units_Dimensions::*)() const) &Units_Dimensions::ElectricCurrent, "Returns the power of electrical intensity (current) stored in the dimensions.");
cls_Units_Dimensions.def("ThermodynamicTemperature", (Standard_Real (Units_Dimensions::*)() const) &Units_Dimensions::ThermodynamicTemperature, "Returns the power of temperature stored in the dimensions.");
cls_Units_Dimensions.def("AmountOfSubstance", (Standard_Real (Units_Dimensions::*)() const) &Units_Dimensions::AmountOfSubstance, "Returns the power of quantity of material (mole) stored in the dimensions.");
cls_Units_Dimensions.def("LuminousIntensity", (Standard_Real (Units_Dimensions::*)() const) &Units_Dimensions::LuminousIntensity, "Returns the power of light intensity stored in the dimensions.");
cls_Units_Dimensions.def("PlaneAngle", (Standard_Real (Units_Dimensions::*)() const) &Units_Dimensions::PlaneAngle, "Returns the power of plane angle stored in the dimensions.");
cls_Units_Dimensions.def("SolidAngle", (Standard_Real (Units_Dimensions::*)() const) &Units_Dimensions::SolidAngle, "Returns the power of solid angle stored in the dimensions.");
cls_Units_Dimensions.def("Quantity", (Standard_CString (Units_Dimensions::*)() const) &Units_Dimensions::Quantity, "Returns the quantity string of the dimension");
cls_Units_Dimensions.def("Multiply", (opencascade::handle<Units_Dimensions> (Units_Dimensions::*)(const opencascade::handle<Units_Dimensions> &) const) &Units_Dimensions::Multiply, "Creates and returns a new Dimensions object which is the result of the multiplication of <me> and <adimensions>.", py::arg("adimensions"));
cls_Units_Dimensions.def("Divide", (opencascade::handle<Units_Dimensions> (Units_Dimensions::*)(const opencascade::handle<Units_Dimensions> &) const) &Units_Dimensions::Divide, "Creates and returns a new Dimensions object which is the result of the division of <me> by <adimensions>.", py::arg("adimensions"));
cls_Units_Dimensions.def("Power", (opencascade::handle<Units_Dimensions> (Units_Dimensions::*)(const Standard_Real) const) &Units_Dimensions::Power, "Creates and returns a new Dimensions object which is the result of the power of <me> and <anexponent>.", py::arg("anexponent"));
cls_Units_Dimensions.def("IsEqual", (Standard_Boolean (Units_Dimensions::*)(const opencascade::handle<Units_Dimensions> &) const) &Units_Dimensions::IsEqual, "Returns true if <me> and <adimensions> have the same dimensions, false otherwise.", py::arg("adimensions"));
cls_Units_Dimensions.def("IsNotEqual", (Standard_Boolean (Units_Dimensions::*)(const opencascade::handle<Units_Dimensions> &) const) &Units_Dimensions::IsNotEqual, "Returns false if <me> and <adimensions> have the same dimensions, true otherwise.", py::arg("adimensions"));
cls_Units_Dimensions.def("Dump", (void (Units_Dimensions::*)(const Standard_Integer) const) &Units_Dimensions::Dump, "Useful for degugging.", py::arg("ashift"));
cls_Units_Dimensions.def_static("ALess_", (opencascade::handle<Units_Dimensions> (*)()) &Units_Dimensions::ALess, "None");
cls_Units_Dimensions.def_static("AMass_", (opencascade::handle<Units_Dimensions> (*)()) &Units_Dimensions::AMass, "None");
cls_Units_Dimensions.def_static("ALength_", (opencascade::handle<Units_Dimensions> (*)()) &Units_Dimensions::ALength, "None");
cls_Units_Dimensions.def_static("ATime_", (opencascade::handle<Units_Dimensions> (*)()) &Units_Dimensions::ATime, "None");
cls_Units_Dimensions.def_static("AElectricCurrent_", (opencascade::handle<Units_Dimensions> (*)()) &Units_Dimensions::AElectricCurrent, "None");
cls_Units_Dimensions.def_static("AThermodynamicTemperature_", (opencascade::handle<Units_Dimensions> (*)()) &Units_Dimensions::AThermodynamicTemperature, "None");
cls_Units_Dimensions.def_static("AAmountOfSubstance_", (opencascade::handle<Units_Dimensions> (*)()) &Units_Dimensions::AAmountOfSubstance, "None");
cls_Units_Dimensions.def_static("ALuminousIntensity_", (opencascade::handle<Units_Dimensions> (*)()) &Units_Dimensions::ALuminousIntensity, "None");
cls_Units_Dimensions.def_static("APlaneAngle_", (opencascade::handle<Units_Dimensions> (*)()) &Units_Dimensions::APlaneAngle, "None");
cls_Units_Dimensions.def_static("ASolidAngle_", (opencascade::handle<Units_Dimensions> (*)()) &Units_Dimensions::ASolidAngle, "Returns the basic dimensions.");
cls_Units_Dimensions.def_static("get_type_name_", (const char * (*)()) &Units_Dimensions::get_type_name, "None");
cls_Units_Dimensions.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Units_Dimensions::get_type_descriptor, "None");
cls_Units_Dimensions.def("DynamicType", (const opencascade::handle<Standard_Type> & (Units_Dimensions::*)() const) &Units_Dimensions::DynamicType, "None");

// CLASS: UNITS_UNIT
py::class_<Units_Unit, opencascade::handle<Units_Unit>, Standard_Transient> cls_Units_Unit(mod, "Units_Unit", "This class defines an elementary word contained in a physical quantity.");

// Constructors
cls_Units_Unit.def(py::init<const Standard_CString, const Standard_CString, const Standard_Real, const opencascade::handle<Units_Quantity> &>(), py::arg("aname"), py::arg("asymbol"), py::arg("avalue"), py::arg("aquantity"));
cls_Units_Unit.def(py::init<const Standard_CString, const Standard_CString>(), py::arg("aname"), py::arg("asymbol"));
cls_Units_Unit.def(py::init<const Standard_CString>(), py::arg("aname"));

// Methods
cls_Units_Unit.def("Name", (TCollection_AsciiString (Units_Unit::*)() const) &Units_Unit::Name, "Returns the name of the unit <thename>");
cls_Units_Unit.def("Symbol", (void (Units_Unit::*)(const Standard_CString)) &Units_Unit::Symbol, "Adds a new symbol <asymbol> attached to <me>.", py::arg("asymbol"));
cls_Units_Unit.def("Value", (Standard_Real (Units_Unit::*)() const) &Units_Unit::Value, "Returns the value in relation with the International System of Units.");
cls_Units_Unit.def("Quantity", (opencascade::handle<Units_Quantity> (Units_Unit::*)() const) &Units_Unit::Quantity, "Returns <thequantity> contained in <me>.");
cls_Units_Unit.def("SymbolsSequence", (opencascade::handle<TColStd_HSequenceOfHAsciiString> (Units_Unit::*)() const) &Units_Unit::SymbolsSequence, "Returns the sequence of symbols <thesymbolssequence>");
cls_Units_Unit.def("Value", (void (Units_Unit::*)(const Standard_Real)) &Units_Unit::Value, "Sets the value <avalue> to <me>.", py::arg("avalue"));
cls_Units_Unit.def("Quantity", (void (Units_Unit::*)(const opencascade::handle<Units_Quantity> &)) &Units_Unit::Quantity, "Sets the physical Quantity <aquantity> to <me>.", py::arg("aquantity"));
cls_Units_Unit.def("Token", (opencascade::handle<Units_Token> (Units_Unit::*)() const) &Units_Unit::Token, "Starting with <me>, returns a new Token object.");
cls_Units_Unit.def("IsEqual", (Standard_Boolean (Units_Unit::*)(const Standard_CString) const) &Units_Unit::IsEqual, "Compares all the symbols linked within <me> with the name of <atoken>, and returns True if there is one symbol equal to the name, False otherwise.", py::arg("astring"));
cls_Units_Unit.def("Dump", (void (Units_Unit::*)(const Standard_Integer, const Standard_Integer) const) &Units_Unit::Dump, "Useful for debugging", py::arg("ashift"), py::arg("alevel"));
cls_Units_Unit.def_static("get_type_name_", (const char * (*)()) &Units_Unit::get_type_name, "None");
cls_Units_Unit.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Units_Unit::get_type_descriptor, "None");
cls_Units_Unit.def("DynamicType", (const opencascade::handle<Standard_Type> & (Units_Unit::*)() const) &Units_Unit::DynamicType, "None");

// TYPEDEF: UNITS_UTSSEQUENCE
bind_NCollection_Sequence<opencascade::handle<Units_Unit> >(mod, "Units_UtsSequence", py::module_local(false));

// CLASS: UNITS_UNITSSEQUENCE
py::class_<Units_UnitsSequence, opencascade::handle<Units_UnitsSequence>, Standard_Transient> cls_Units_UnitsSequence(mod, "Units_UnitsSequence", "None", py::multiple_inheritance());

// Constructors
cls_Units_UnitsSequence.def(py::init<>());
cls_Units_UnitsSequence.def(py::init<const Units_UtsSequence &>(), py::arg("theOther"));

// Methods
// cls_Units_UnitsSequence.def_static("operator new_", (void * (*)(size_t)) &Units_UnitsSequence::operator new, "None", py::arg("theSize"));
// cls_Units_UnitsSequence.def_static("operator delete_", (void (*)(void *)) &Units_UnitsSequence::operator delete, "None", py::arg("theAddress"));
// cls_Units_UnitsSequence.def_static("operator new[]_", (void * (*)(size_t)) &Units_UnitsSequence::operator new[], "None", py::arg("theSize"));
// cls_Units_UnitsSequence.def_static("operator delete[]_", (void (*)(void *)) &Units_UnitsSequence::operator delete[], "None", py::arg("theAddress"));
// cls_Units_UnitsSequence.def_static("operator new_", (void * (*)(size_t, void *)) &Units_UnitsSequence::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Units_UnitsSequence.def_static("operator delete_", (void (*)(void *, void *)) &Units_UnitsSequence::operator delete, "None", py::arg(""), py::arg(""));
// cls_Units_UnitsSequence.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &Units_UnitsSequence::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_Units_UnitsSequence.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &Units_UnitsSequence::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_Units_UnitsSequence.def("Sequence", (const Units_UtsSequence & (Units_UnitsSequence::*)() const) &Units_UnitsSequence::Sequence, "None");
cls_Units_UnitsSequence.def("Append", (void (Units_UnitsSequence::*)(const Units_UtsSequence::value_type &)) &Units_UnitsSequence::Append, "None", py::arg("theItem"));
cls_Units_UnitsSequence.def("Append", (void (Units_UnitsSequence::*)(Units_UtsSequence &)) &Units_UnitsSequence::Append, "None", py::arg("theSequence"));
cls_Units_UnitsSequence.def("ChangeSequence", (Units_UtsSequence & (Units_UnitsSequence::*)()) &Units_UnitsSequence::ChangeSequence, "None");
cls_Units_UnitsSequence.def_static("get_type_name_", (const char * (*)()) &Units_UnitsSequence::get_type_name, "None");
cls_Units_UnitsSequence.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Units_UnitsSequence::get_type_descriptor, "None");
cls_Units_UnitsSequence.def("DynamicType", (const opencascade::handle<Standard_Type> & (Units_UnitsSequence::*)() const) &Units_UnitsSequence::DynamicType, "None");

// CLASS: UNITS_QUANTITY
py::class_<Units_Quantity, opencascade::handle<Units_Quantity>, Standard_Transient> cls_Units_Quantity(mod, "Units_Quantity", "This class stores in its field all the possible units of all the unit systems for a given physical quantity. Each unit's value is expressed in the S.I. unit system.");

// Constructors
cls_Units_Quantity.def(py::init<const Standard_CString, const opencascade::handle<Units_Dimensions> &, const opencascade::handle<Units_UnitsSequence> &>(), py::arg("aname"), py::arg("adimensions"), py::arg("aunitssequence"));

// Methods
cls_Units_Quantity.def("Name", (TCollection_AsciiString (Units_Quantity::*)() const) &Units_Quantity::Name, "Returns in a AsciiString from TCollection the name of the quantity.");
cls_Units_Quantity.def("Dimensions", (opencascade::handle<Units_Dimensions> (Units_Quantity::*)() const) &Units_Quantity::Dimensions, "Returns the physical dimensions of the quantity.");
cls_Units_Quantity.def("Sequence", (opencascade::handle<Units_UnitsSequence> (Units_Quantity::*)() const) &Units_Quantity::Sequence, "Returns <theunitssequence>, which is the sequence of all the units stored for this physical quantity.");
cls_Units_Quantity.def("IsEqual", (Standard_Boolean (Units_Quantity::*)(const Standard_CString) const) &Units_Quantity::IsEqual, "Returns True if the name of the Quantity <me> is equal to <astring>, False otherwise.", py::arg("astring"));
cls_Units_Quantity.def("Dump", (void (Units_Quantity::*)(const Standard_Integer, const Standard_Integer) const) &Units_Quantity::Dump, "Useful for debugging.", py::arg("ashift"), py::arg("alevel"));
cls_Units_Quantity.def_static("get_type_name_", (const char * (*)()) &Units_Quantity::get_type_name, "None");
cls_Units_Quantity.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Units_Quantity::get_type_descriptor, "None");
cls_Units_Quantity.def("DynamicType", (const opencascade::handle<Standard_Type> & (Units_Quantity::*)() const) &Units_Quantity::DynamicType, "None");

// TYPEDEF: UNITS_QTSSEQUENCE
bind_NCollection_Sequence<opencascade::handle<Units_Quantity> >(mod, "Units_QtsSequence", py::module_local(false));

// CLASS: UNITS_QUANTITIESSEQUENCE
py::class_<Units_QuantitiesSequence, opencascade::handle<Units_QuantitiesSequence>, Standard_Transient> cls_Units_QuantitiesSequence(mod, "Units_QuantitiesSequence", "None", py::multiple_inheritance());

// Constructors
cls_Units_QuantitiesSequence.def(py::init<>());
cls_Units_QuantitiesSequence.def(py::init<const Units_QtsSequence &>(), py::arg("theOther"));

// Methods
// cls_Units_QuantitiesSequence.def_static("operator new_", (void * (*)(size_t)) &Units_QuantitiesSequence::operator new, "None", py::arg("theSize"));
// cls_Units_QuantitiesSequence.def_static("operator delete_", (void (*)(void *)) &Units_QuantitiesSequence::operator delete, "None", py::arg("theAddress"));
// cls_Units_QuantitiesSequence.def_static("operator new[]_", (void * (*)(size_t)) &Units_QuantitiesSequence::operator new[], "None", py::arg("theSize"));
// cls_Units_QuantitiesSequence.def_static("operator delete[]_", (void (*)(void *)) &Units_QuantitiesSequence::operator delete[], "None", py::arg("theAddress"));
// cls_Units_QuantitiesSequence.def_static("operator new_", (void * (*)(size_t, void *)) &Units_QuantitiesSequence::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Units_QuantitiesSequence.def_static("operator delete_", (void (*)(void *, void *)) &Units_QuantitiesSequence::operator delete, "None", py::arg(""), py::arg(""));
// cls_Units_QuantitiesSequence.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &Units_QuantitiesSequence::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_Units_QuantitiesSequence.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &Units_QuantitiesSequence::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_Units_QuantitiesSequence.def("Sequence", (const Units_QtsSequence & (Units_QuantitiesSequence::*)() const) &Units_QuantitiesSequence::Sequence, "None");
cls_Units_QuantitiesSequence.def("Append", (void (Units_QuantitiesSequence::*)(const Units_QtsSequence::value_type &)) &Units_QuantitiesSequence::Append, "None", py::arg("theItem"));
cls_Units_QuantitiesSequence.def("Append", (void (Units_QuantitiesSequence::*)(Units_QtsSequence &)) &Units_QuantitiesSequence::Append, "None", py::arg("theSequence"));
cls_Units_QuantitiesSequence.def("ChangeSequence", (Units_QtsSequence & (Units_QuantitiesSequence::*)()) &Units_QuantitiesSequence::ChangeSequence, "None");
cls_Units_QuantitiesSequence.def_static("get_type_name_", (const char * (*)()) &Units_QuantitiesSequence::get_type_name, "None");
cls_Units_QuantitiesSequence.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Units_QuantitiesSequence::get_type_descriptor, "None");
cls_Units_QuantitiesSequence.def("DynamicType", (const opencascade::handle<Standard_Type> & (Units_QuantitiesSequence::*)() const) &Units_QuantitiesSequence::DynamicType, "None");

// CLASS: UNITS_EXPLORER
py::class_<Units_Explorer> cls_Units_Explorer(mod, "Units_Explorer", "This class provides all the services to explore UnitsSystem or UnitsDictionary.");

// Constructors
cls_Units_Explorer.def(py::init<>());
cls_Units_Explorer.def(py::init<const opencascade::handle<Units_UnitsSystem> &>(), py::arg("aunitssystem"));
cls_Units_Explorer.def(py::init<const opencascade::handle<Units_UnitsDictionary> &>(), py::arg("aunitsdictionary"));
cls_Units_Explorer.def(py::init<const opencascade::handle<Units_UnitsSystem> &, const Standard_CString>(), py::arg("aunitssystem"), py::arg("aquantity"));
cls_Units_Explorer.def(py::init<const opencascade::handle<Units_UnitsDictionary> &, const Standard_CString>(), py::arg("aunitsdictionary"), py::arg("aquantity"));

// Methods
// cls_Units_Explorer.def_static("operator new_", (void * (*)(size_t)) &Units_Explorer::operator new, "None", py::arg("theSize"));
// cls_Units_Explorer.def_static("operator delete_", (void (*)(void *)) &Units_Explorer::operator delete, "None", py::arg("theAddress"));
// cls_Units_Explorer.def_static("operator new[]_", (void * (*)(size_t)) &Units_Explorer::operator new[], "None", py::arg("theSize"));
// cls_Units_Explorer.def_static("operator delete[]_", (void (*)(void *)) &Units_Explorer::operator delete[], "None", py::arg("theAddress"));
// cls_Units_Explorer.def_static("operator new_", (void * (*)(size_t, void *)) &Units_Explorer::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Units_Explorer.def_static("operator delete_", (void (*)(void *, void *)) &Units_Explorer::operator delete, "None", py::arg(""), py::arg(""));
cls_Units_Explorer.def("Init", (void (Units_Explorer::*)(const opencascade::handle<Units_UnitsSystem> &)) &Units_Explorer::Init, "Initializes the instance of the class with the UnitsSystem <aunitssystem>.", py::arg("aunitssystem"));
cls_Units_Explorer.def("Init", (void (Units_Explorer::*)(const opencascade::handle<Units_UnitsDictionary> &)) &Units_Explorer::Init, "Initializes the instance of the class with the UnitsDictionary <aunitsdictionary>.", py::arg("aunitsdictionary"));
cls_Units_Explorer.def("Init", (void (Units_Explorer::*)(const opencascade::handle<Units_UnitsSystem> &, const Standard_CString)) &Units_Explorer::Init, "Initializes the instance of the class with the UnitsSystem <aunitssystem> and positioned at the quantity <aquantity>.", py::arg("aunitssystem"), py::arg("aquantity"));
cls_Units_Explorer.def("Init", (void (Units_Explorer::*)(const opencascade::handle<Units_UnitsDictionary> &, const Standard_CString)) &Units_Explorer::Init, "Initializes the instance of the class with the UnitsDictionary <aunitsdictionary> and positioned at the quantity <aquantity>.", py::arg("aunitsdictionary"), py::arg("aquantity"));
cls_Units_Explorer.def("MoreQuantity", (Standard_Boolean (Units_Explorer::*)() const) &Units_Explorer::MoreQuantity, "Returns True if there is another Quantity to explore, False otherwise.");
cls_Units_Explorer.def("NextQuantity", (void (Units_Explorer::*)()) &Units_Explorer::NextQuantity, "Sets the next Quantity current.");
cls_Units_Explorer.def("Quantity", (TCollection_AsciiString (Units_Explorer::*)() const) &Units_Explorer::Quantity, "Returns the name of the current Quantity.");
cls_Units_Explorer.def("MoreUnit", (Standard_Boolean (Units_Explorer::*)() const) &Units_Explorer::MoreUnit, "Returns True if there is another Unit to explore, False otherwise.");
cls_Units_Explorer.def("NextUnit", (void (Units_Explorer::*)()) &Units_Explorer::NextUnit, "Sets the next Unit current.");
cls_Units_Explorer.def("Unit", (TCollection_AsciiString (Units_Explorer::*)() const) &Units_Explorer::Unit, "Returns the name of the current unit.");
cls_Units_Explorer.def("IsActive", (Standard_Boolean (Units_Explorer::*)() const) &Units_Explorer::IsActive, "If the units system to explore is a user system, returns True if the current unit is active, False otherwise.");

// CLASS: UNITS_TOKEN
py::class_<Units_Token, opencascade::handle<Units_Token>, Standard_Transient> cls_Units_Token(mod, "Units_Token", "This class defines an elementary word contained in a Sentence object.");

// Constructors
cls_Units_Token.def(py::init<>());
cls_Units_Token.def(py::init<const Standard_CString>(), py::arg("aword"));
cls_Units_Token.def(py::init<const opencascade::handle<Units_Token> &>(), py::arg("atoken"));
cls_Units_Token.def(py::init<const Standard_CString, const Standard_CString>(), py::arg("aword"), py::arg("amean"));
cls_Units_Token.def(py::init<const Standard_CString, const Standard_CString, const Standard_Real>(), py::arg("aword"), py::arg("amean"), py::arg("avalue"));
cls_Units_Token.def(py::init<const Standard_CString, const Standard_CString, const Standard_Real, const opencascade::handle<Units_Dimensions> &>(), py::arg("aword"), py::arg("amean"), py::arg("avalue"), py::arg("adimension"));

// Methods
cls_Units_Token.def("Creates", (opencascade::handle<Units_Token> (Units_Token::*)() const) &Units_Token::Creates, "Creates and returns a token, which is a ShiftedToken.");
cls_Units_Token.def("Length", (Standard_Integer (Units_Token::*)() const) &Units_Token::Length, "Returns the length of the word.");
cls_Units_Token.def("Word", (TCollection_AsciiString (Units_Token::*)() const) &Units_Token::Word, "Returns the string <theword>");
cls_Units_Token.def("Word", (void (Units_Token::*)(const Standard_CString)) &Units_Token::Word, "Sets the field <theword> to <aword>.", py::arg("aword"));
cls_Units_Token.def("Mean", (TCollection_AsciiString (Units_Token::*)() const) &Units_Token::Mean, "Returns the significance of the word <theword>, which is in the field <themean>.");
cls_Units_Token.def("Mean", (void (Units_Token::*)(const Standard_CString)) &Units_Token::Mean, "Sets the field <themean> to <amean>.", py::arg("amean"));
cls_Units_Token.def("Value", (Standard_Real (Units_Token::*)() const) &Units_Token::Value, "Returns the value stored in the field <thevalue>.");
cls_Units_Token.def("Value", (void (Units_Token::*)(const Standard_Real)) &Units_Token::Value, "Sets the field <thevalue> to <avalue>.", py::arg("avalue"));
cls_Units_Token.def("Dimensions", (opencascade::handle<Units_Dimensions> (Units_Token::*)() const) &Units_Token::Dimensions, "Returns the dimensions of the token <thedimensions>.");
cls_Units_Token.def("Dimensions", (void (Units_Token::*)(const opencascade::handle<Units_Dimensions> &)) &Units_Token::Dimensions, "Sets the field <thedimensions> to <adimensions>.", py::arg("adimensions"));
cls_Units_Token.def("Update", (void (Units_Token::*)(const Standard_CString)) &Units_Token::Update, "Updates the token <me> with the additional signification <amean> by concatenation of the two strings <themean> and <amean>. If the two significations are the same , an information message is written in the output device.", py::arg("amean"));
cls_Units_Token.def("Add", (opencascade::handle<Units_Token> (Units_Token::*)(const Standard_Integer) const) &Units_Token::Add, "None", py::arg("aninteger"));
cls_Units_Token.def("Add", (opencascade::handle<Units_Token> (Units_Token::*)(const opencascade::handle<Units_Token> &) const) &Units_Token::Add, "Returns a token which is the addition of <me> and another token <atoken>. The addition is possible if and only if the dimensions are the same.", py::arg("atoken"));
cls_Units_Token.def("Subtract", (opencascade::handle<Units_Token> (Units_Token::*)(const opencascade::handle<Units_Token> &) const) &Units_Token::Subtract, "Returns a token which is the subtraction of <me> and another token <atoken>. The subtraction is possible if and only if the dimensions are the same.", py::arg("atoken"));
cls_Units_Token.def("Multiply", (opencascade::handle<Units_Token> (Units_Token::*)(const opencascade::handle<Units_Token> &) const) &Units_Token::Multiply, "Returns a token which is the product of <me> and another token <atoken>.", py::arg("atoken"));
cls_Units_Token.def("Multiplied", (Standard_Real (Units_Token::*)(const Standard_Real) const) &Units_Token::Multiplied, "This virtual method is called by the Measurement methods, to compute the measurement during a conversion.", py::arg("avalue"));
cls_Units_Token.def("Divide", (opencascade::handle<Units_Token> (Units_Token::*)(const opencascade::handle<Units_Token> &) const) &Units_Token::Divide, "Returns a token which is the division of <me> by another token <atoken>.", py::arg("atoken"));
cls_Units_Token.def("Divided", (Standard_Real (Units_Token::*)(const Standard_Real) const) &Units_Token::Divided, "This virtual method is called by the Measurement methods, to compute the measurement during a conversion.", py::arg("avalue"));
cls_Units_Token.def("Power", (opencascade::handle<Units_Token> (Units_Token::*)(const opencascade::handle<Units_Token> &) const) &Units_Token::Power, "Returns a token which is <me> to the power of another token <atoken>. The computation is possible only if <atoken> is a dimensionless constant.", py::arg("atoken"));
cls_Units_Token.def("Power", (opencascade::handle<Units_Token> (Units_Token::*)(const Standard_Real) const) &Units_Token::Power, "Returns a token which is <me> to the power of <anexponent>.", py::arg("anexponent"));
cls_Units_Token.def("IsEqual", (Standard_Boolean (Units_Token::*)(const Standard_CString) const) &Units_Token::IsEqual, "Returns true if the field <theword> and the string <astring> are the same, false otherwise.", py::arg("astring"));
cls_Units_Token.def("IsEqual", (Standard_Boolean (Units_Token::*)(const opencascade::handle<Units_Token> &) const) &Units_Token::IsEqual, "Returns true if the field <theword> and the string <theword> contained in the token <atoken> are the same, false otherwise.", py::arg("atoken"));
cls_Units_Token.def("IsNotEqual", (Standard_Boolean (Units_Token::*)(const Standard_CString) const) &Units_Token::IsNotEqual, "Returns false if the field <theword> and the string <astring> are the same, true otherwise.", py::arg("astring"));
cls_Units_Token.def("IsNotEqual", (Standard_Boolean (Units_Token::*)(const opencascade::handle<Units_Token> &) const) &Units_Token::IsNotEqual, "Returns false if the field <theword> and the string <theword> contained in the token <atoken> are the same, true otherwise.", py::arg("atoken"));
cls_Units_Token.def("IsLessOrEqual", (Standard_Boolean (Units_Token::*)(const Standard_CString) const) &Units_Token::IsLessOrEqual, "Returns true if the field <theword> is strictly contained at the beginning of the string <astring>, false otherwise.", py::arg("astring"));
cls_Units_Token.def("IsGreater", (Standard_Boolean (Units_Token::*)(const Standard_CString) const) &Units_Token::IsGreater, "Returns false if the field <theword> is strictly contained at the beginning of the string <astring>, true otherwise.", py::arg("astring"));
cls_Units_Token.def("IsGreater", (Standard_Boolean (Units_Token::*)(const opencascade::handle<Units_Token> &) const) &Units_Token::IsGreater, "Returns false if the field <theword> is strictly contained at the beginning of the string <astring>, true otherwise.", py::arg("atoken"));
cls_Units_Token.def("IsGreaterOrEqual", (Standard_Boolean (Units_Token::*)(const opencascade::handle<Units_Token> &) const) &Units_Token::IsGreaterOrEqual, "Returns true if the string <astring> is strictly contained at the beginning of the field <theword> false otherwise.", py::arg("atoken"));
cls_Units_Token.def("Dump", (void (Units_Token::*)(const Standard_Integer, const Standard_Integer) const) &Units_Token::Dump, "Useful for debugging", py::arg("ashift"), py::arg("alevel"));
cls_Units_Token.def_static("get_type_name_", (const char * (*)()) &Units_Token::get_type_name, "None");
cls_Units_Token.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Units_Token::get_type_descriptor, "None");
cls_Units_Token.def("DynamicType", (const opencascade::handle<Standard_Type> & (Units_Token::*)() const) &Units_Token::DynamicType, "None");

// TYPEDEF: UNITS_TKSSEQUENCE
bind_NCollection_Sequence<opencascade::handle<Units_Token> >(mod, "Units_TksSequence", py::module_local(false));

// CLASS: UNITS_TOKENSSEQUENCE
py::class_<Units_TokensSequence, opencascade::handle<Units_TokensSequence>, Standard_Transient> cls_Units_TokensSequence(mod, "Units_TokensSequence", "None", py::multiple_inheritance());

// Constructors
cls_Units_TokensSequence.def(py::init<>());
cls_Units_TokensSequence.def(py::init<const Units_TksSequence &>(), py::arg("theOther"));

// Methods
// cls_Units_TokensSequence.def_static("operator new_", (void * (*)(size_t)) &Units_TokensSequence::operator new, "None", py::arg("theSize"));
// cls_Units_TokensSequence.def_static("operator delete_", (void (*)(void *)) &Units_TokensSequence::operator delete, "None", py::arg("theAddress"));
// cls_Units_TokensSequence.def_static("operator new[]_", (void * (*)(size_t)) &Units_TokensSequence::operator new[], "None", py::arg("theSize"));
// cls_Units_TokensSequence.def_static("operator delete[]_", (void (*)(void *)) &Units_TokensSequence::operator delete[], "None", py::arg("theAddress"));
// cls_Units_TokensSequence.def_static("operator new_", (void * (*)(size_t, void *)) &Units_TokensSequence::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Units_TokensSequence.def_static("operator delete_", (void (*)(void *, void *)) &Units_TokensSequence::operator delete, "None", py::arg(""), py::arg(""));
// cls_Units_TokensSequence.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &Units_TokensSequence::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_Units_TokensSequence.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &Units_TokensSequence::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_Units_TokensSequence.def("Sequence", (const Units_TksSequence & (Units_TokensSequence::*)() const) &Units_TokensSequence::Sequence, "None");
cls_Units_TokensSequence.def("Append", (void (Units_TokensSequence::*)(const Units_TksSequence::value_type &)) &Units_TokensSequence::Append, "None", py::arg("theItem"));
cls_Units_TokensSequence.def("Append", (void (Units_TokensSequence::*)(Units_TksSequence &)) &Units_TokensSequence::Append, "None", py::arg("theSequence"));
cls_Units_TokensSequence.def("ChangeSequence", (Units_TksSequence & (Units_TokensSequence::*)()) &Units_TokensSequence::ChangeSequence, "None");
cls_Units_TokensSequence.def_static("get_type_name_", (const char * (*)()) &Units_TokensSequence::get_type_name, "None");
cls_Units_TokensSequence.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Units_TokensSequence::get_type_descriptor, "None");
cls_Units_TokensSequence.def("DynamicType", (const opencascade::handle<Standard_Type> & (Units_TokensSequence::*)() const) &Units_TokensSequence::DynamicType, "None");

// CLASS: UNITS_LEXICON
py::class_<Units_Lexicon, opencascade::handle<Units_Lexicon>, Standard_Transient> cls_Units_Lexicon(mod, "Units_Lexicon", "This class defines a lexicon useful to analyse and recognize the different key words included in a sentence. The lexicon is stored in a sequence of tokens.");

// Constructors
cls_Units_Lexicon.def(py::init<>());

// Methods
cls_Units_Lexicon.def("Creates", (void (Units_Lexicon::*)()) &Units_Lexicon::Creates, "Reads the file <afilename> to create a sequence of tokens stored in <thesequenceoftokens>.");
cls_Units_Lexicon.def("Sequence", (opencascade::handle<Units_TokensSequence> (Units_Lexicon::*)() const) &Units_Lexicon::Sequence, "Returns the first item of the sequence of tokens.");
cls_Units_Lexicon.def("AddToken", (void (Units_Lexicon::*)(const Standard_CString, const Standard_CString, const Standard_Real)) &Units_Lexicon::AddToken, "Adds to the lexicon a new token with <aword>, <amean>, <avalue> as arguments. If there is already a token with the field <theword> equal to <aword>, the existing token is updated.", py::arg("aword"), py::arg("amean"), py::arg("avalue"));
cls_Units_Lexicon.def("Dump", (void (Units_Lexicon::*)() const) &Units_Lexicon::Dump, "Useful for debugging.");
cls_Units_Lexicon.def_static("get_type_name_", (const char * (*)()) &Units_Lexicon::get_type_name, "None");
cls_Units_Lexicon.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Units_Lexicon::get_type_descriptor, "None");
cls_Units_Lexicon.def("DynamicType", (const opencascade::handle<Standard_Type> & (Units_Lexicon::*)() const) &Units_Lexicon::DynamicType, "None");

// CLASS: UNITS_SENTENCE
py::class_<Units_Sentence> cls_Units_Sentence(mod, "Units_Sentence", "This class describes all the methods to create and compute an expression contained in a string.");

// Constructors
cls_Units_Sentence.def(py::init<const opencascade::handle<Units_Lexicon> &, const Standard_CString>(), py::arg("alexicon"), py::arg("astring"));

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

// CLASS: UNITS_MATHSENTENCE
py::class_<Units_MathSentence, Units_Sentence> cls_Units_MathSentence(mod, "Units_MathSentence", "This class defines all the methods to create and compute an algebraic formula.");

// Constructors
cls_Units_MathSentence.def(py::init<const Standard_CString>(), py::arg("astring"));

// Methods
// cls_Units_MathSentence.def_static("operator new_", (void * (*)(size_t)) &Units_MathSentence::operator new, "None", py::arg("theSize"));
// cls_Units_MathSentence.def_static("operator delete_", (void (*)(void *)) &Units_MathSentence::operator delete, "None", py::arg("theAddress"));
// cls_Units_MathSentence.def_static("operator new[]_", (void * (*)(size_t)) &Units_MathSentence::operator new[], "None", py::arg("theSize"));
// cls_Units_MathSentence.def_static("operator delete[]_", (void (*)(void *)) &Units_MathSentence::operator delete[], "None", py::arg("theAddress"));
// cls_Units_MathSentence.def_static("operator new_", (void * (*)(size_t, void *)) &Units_MathSentence::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Units_MathSentence.def_static("operator delete_", (void (*)(void *, void *)) &Units_MathSentence::operator delete, "None", py::arg(""), py::arg(""));

// CLASS: UNITS_MEASUREMENT
py::class_<Units_Measurement> cls_Units_Measurement(mod, "Units_Measurement", "This class defines a measurement which is the association of a real value and a unit.");

// Constructors
cls_Units_Measurement.def(py::init<>());
cls_Units_Measurement.def(py::init<const Standard_Real, const opencascade::handle<Units_Token> &>(), py::arg("avalue"), py::arg("atoken"));
cls_Units_Measurement.def(py::init<const Standard_Real, const Standard_CString>(), py::arg("avalue"), py::arg("aunit"));

// Methods
// cls_Units_Measurement.def_static("operator new_", (void * (*)(size_t)) &Units_Measurement::operator new, "None", py::arg("theSize"));
// cls_Units_Measurement.def_static("operator delete_", (void (*)(void *)) &Units_Measurement::operator delete, "None", py::arg("theAddress"));
// cls_Units_Measurement.def_static("operator new[]_", (void * (*)(size_t)) &Units_Measurement::operator new[], "None", py::arg("theSize"));
// cls_Units_Measurement.def_static("operator delete[]_", (void (*)(void *)) &Units_Measurement::operator delete[], "None", py::arg("theAddress"));
// cls_Units_Measurement.def_static("operator new_", (void * (*)(size_t, void *)) &Units_Measurement::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Units_Measurement.def_static("operator delete_", (void (*)(void *, void *)) &Units_Measurement::operator delete, "None", py::arg(""), py::arg(""));
cls_Units_Measurement.def("Convert", (void (Units_Measurement::*)(const Standard_CString)) &Units_Measurement::Convert, "Converts (if possible) the measurement object into another unit. <aunit> must have the same dimensionality as the unit contained in the token <thetoken>.", py::arg("aunit"));
cls_Units_Measurement.def("Integer", (Units_Measurement (Units_Measurement::*)() const) &Units_Measurement::Integer, "Returns a Measurement object with the integer value of the measurement contained in <me>.");
cls_Units_Measurement.def("Fractional", (Units_Measurement (Units_Measurement::*)() const) &Units_Measurement::Fractional, "Returns a Measurement object with the fractional value of the measurement contained in <me>.");
cls_Units_Measurement.def("Measurement", (Standard_Real (Units_Measurement::*)() const) &Units_Measurement::Measurement, "Returns the value of the measurement.");
cls_Units_Measurement.def("Token", (opencascade::handle<Units_Token> (Units_Measurement::*)() const) &Units_Measurement::Token, "Returns the token contained in <me>.");
cls_Units_Measurement.def("Add", (Units_Measurement (Units_Measurement::*)(const Units_Measurement &) const) &Units_Measurement::Add, "Returns (if it is possible) a measurement which is the addition of <me> and <ameasurement>. The chosen returned unit is the unit of <me>.", py::arg("ameasurement"));
cls_Units_Measurement.def("__add__", (Units_Measurement (Units_Measurement::*)(const Units_Measurement &) const) &Units_Measurement::operator+, py::is_operator(), "None", py::arg("ameasurement"));
cls_Units_Measurement.def("Subtract", (Units_Measurement (Units_Measurement::*)(const Units_Measurement &) const) &Units_Measurement::Subtract, "Returns (if it is possible) a measurement which is the subtraction of <me> and <ameasurement>. The chosen returned unit is the unit of <me>.", py::arg("ameasurement"));
cls_Units_Measurement.def("__sub__", (Units_Measurement (Units_Measurement::*)(const Units_Measurement &) const) &Units_Measurement::operator-, py::is_operator(), "None", py::arg("ameasurement"));
cls_Units_Measurement.def("Multiply", (Units_Measurement (Units_Measurement::*)(const Units_Measurement &) const) &Units_Measurement::Multiply, "Returns a measurement which is the multiplication of <me> and <ameasurement>.", py::arg("ameasurement"));
cls_Units_Measurement.def("__mul__", (Units_Measurement (Units_Measurement::*)(const Units_Measurement &) const) &Units_Measurement::operator*, py::is_operator(), "None", py::arg("ameasurement"));
cls_Units_Measurement.def("Multiply", (Units_Measurement (Units_Measurement::*)(const Standard_Real) const) &Units_Measurement::Multiply, "Returns a measurement which is the multiplication of <me> with the value <avalue>.", py::arg("avalue"));
cls_Units_Measurement.def("__mul__", (Units_Measurement (Units_Measurement::*)(const Standard_Real) const) &Units_Measurement::operator*, py::is_operator(), "None", py::arg("avalue"));
cls_Units_Measurement.def("Divide", (Units_Measurement (Units_Measurement::*)(const Units_Measurement &) const) &Units_Measurement::Divide, "Returns a measurement which is the division of <me> by <ameasurement>.", py::arg("ameasurement"));
cls_Units_Measurement.def("__truediv__", (Units_Measurement (Units_Measurement::*)(const Units_Measurement &) const) &Units_Measurement::operator/, py::is_operator(), "None", py::arg("ameasurement"));
cls_Units_Measurement.def("Divide", (Units_Measurement (Units_Measurement::*)(const Standard_Real) const) &Units_Measurement::Divide, "Returns a measurement which is the division of <me> by the constant <avalue>.", py::arg("avalue"));
cls_Units_Measurement.def("__truediv__", (Units_Measurement (Units_Measurement::*)(const Standard_Real) const) &Units_Measurement::operator/, py::is_operator(), "None", py::arg("avalue"));
cls_Units_Measurement.def("Power", (Units_Measurement (Units_Measurement::*)(const Standard_Real) const) &Units_Measurement::Power, "Returns a measurement which is <me> powered <anexponent>.", py::arg("anexponent"));
cls_Units_Measurement.def("HasToken", (Standard_Boolean (Units_Measurement::*)() const) &Units_Measurement::HasToken, "None");
cls_Units_Measurement.def("Dump", (void (Units_Measurement::*)() const) &Units_Measurement::Dump, "Useful for debugging.");

// CLASS: UNITS_NOSUCHTYPE
py::class_<Units_NoSuchType, opencascade::handle<Units_NoSuchType>, Standard_NoSuchObject> cls_Units_NoSuchType(mod, "Units_NoSuchType", "None");

// Constructors
cls_Units_NoSuchType.def(py::init<>());
cls_Units_NoSuchType.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_Units_NoSuchType.def_static("Raise_", (void (*)(const Standard_CString)) &Units_NoSuchType::Raise, "None", py::arg("theMessage"));
cls_Units_NoSuchType.def_static("Raise_", (void (*)(Standard_SStream &)) &Units_NoSuchType::Raise, "None", py::arg("theMessage"));
cls_Units_NoSuchType.def_static("NewInstance_", (opencascade::handle<Units_NoSuchType> (*)(const Standard_CString)) &Units_NoSuchType::NewInstance, "None", py::arg("theMessage"));
cls_Units_NoSuchType.def_static("get_type_name_", (const char * (*)()) &Units_NoSuchType::get_type_name, "None");
cls_Units_NoSuchType.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Units_NoSuchType::get_type_descriptor, "None");
cls_Units_NoSuchType.def("DynamicType", (const opencascade::handle<Standard_Type> & (Units_NoSuchType::*)() const) &Units_NoSuchType::DynamicType, "None");

// CLASS: UNITS_NOSUCHUNIT
py::class_<Units_NoSuchUnit, opencascade::handle<Units_NoSuchUnit>, Standard_NoSuchObject> cls_Units_NoSuchUnit(mod, "Units_NoSuchUnit", "None");

// Constructors
cls_Units_NoSuchUnit.def(py::init<>());
cls_Units_NoSuchUnit.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_Units_NoSuchUnit.def_static("Raise_", (void (*)(const Standard_CString)) &Units_NoSuchUnit::Raise, "None", py::arg("theMessage"));
cls_Units_NoSuchUnit.def_static("Raise_", (void (*)(Standard_SStream &)) &Units_NoSuchUnit::Raise, "None", py::arg("theMessage"));
cls_Units_NoSuchUnit.def_static("NewInstance_", (opencascade::handle<Units_NoSuchUnit> (*)(const Standard_CString)) &Units_NoSuchUnit::NewInstance, "None", py::arg("theMessage"));
cls_Units_NoSuchUnit.def_static("get_type_name_", (const char * (*)()) &Units_NoSuchUnit::get_type_name, "None");
cls_Units_NoSuchUnit.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Units_NoSuchUnit::get_type_descriptor, "None");
cls_Units_NoSuchUnit.def("DynamicType", (const opencascade::handle<Standard_Type> & (Units_NoSuchUnit::*)() const) &Units_NoSuchUnit::DynamicType, "None");

// CLASS: UNITS_SHIFTEDTOKEN
py::class_<Units_ShiftedToken, opencascade::handle<Units_ShiftedToken>, Units_Token> cls_Units_ShiftedToken(mod, "Units_ShiftedToken", "The ShiftedToken class inherits from Token and describes tokens which have a gap in addition of the multiplicative factor. This kind of token allows the description of linear functions which do not pass through the origin, of the form :");

// Constructors
cls_Units_ShiftedToken.def(py::init<const Standard_CString, const Standard_CString, const Standard_Real, const Standard_Real, const opencascade::handle<Units_Dimensions> &>(), py::arg("aword"), py::arg("amean"), py::arg("avalue"), py::arg("amove"), py::arg("adimensions"));

// Methods
cls_Units_ShiftedToken.def("Creates", (opencascade::handle<Units_Token> (Units_ShiftedToken::*)() const) &Units_ShiftedToken::Creates, "Creates and returns a token, which is a ShiftedToken.");
cls_Units_ShiftedToken.def("Move", (Standard_Real (Units_ShiftedToken::*)() const) &Units_ShiftedToken::Move, "Returns the gap <themove>");
cls_Units_ShiftedToken.def("Multiplied", (Standard_Real (Units_ShiftedToken::*)(const Standard_Real) const) &Units_ShiftedToken::Multiplied, "This virtual method is called by the Measurement methods, to compute the measurement during a conversion.", py::arg("avalue"));
cls_Units_ShiftedToken.def("Divided", (Standard_Real (Units_ShiftedToken::*)(const Standard_Real) const) &Units_ShiftedToken::Divided, "This virtual method is called by the Measurement methods, to compute the measurement during a conversion.", py::arg("avalue"));
cls_Units_ShiftedToken.def("Dump", (void (Units_ShiftedToken::*)(const Standard_Integer, const Standard_Integer) const) &Units_ShiftedToken::Dump, "None", py::arg("ashift"), py::arg("alevel"));
cls_Units_ShiftedToken.def_static("get_type_name_", (const char * (*)()) &Units_ShiftedToken::get_type_name, "None");
cls_Units_ShiftedToken.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Units_ShiftedToken::get_type_descriptor, "None");
cls_Units_ShiftedToken.def("DynamicType", (const opencascade::handle<Standard_Type> & (Units_ShiftedToken::*)() const) &Units_ShiftedToken::DynamicType, "None");

// CLASS: UNITS_SHIFTEDUNIT
py::class_<Units_ShiftedUnit, opencascade::handle<Units_ShiftedUnit>, Units_Unit> cls_Units_ShiftedUnit(mod, "Units_ShiftedUnit", "This class is useful to describe units with a shifted origin in relation to another unit. A well known example is the Celsius degrees in relation to Kelvin degrees. The shift of the Celsius origin is 273.15 Kelvin degrees.");

// Constructors
cls_Units_ShiftedUnit.def(py::init<const Standard_CString, const Standard_CString, const Standard_Real, const Standard_Real, const opencascade::handle<Units_Quantity> &>(), py::arg("aname"), py::arg("asymbol"), py::arg("avalue"), py::arg("amove"), py::arg("aquantity"));
cls_Units_ShiftedUnit.def(py::init<const Standard_CString, const Standard_CString>(), py::arg("aname"), py::arg("asymbol"));
cls_Units_ShiftedUnit.def(py::init<const Standard_CString>(), py::arg("aname"));

// Methods
cls_Units_ShiftedUnit.def("Move", (void (Units_ShiftedUnit::*)(const Standard_Real)) &Units_ShiftedUnit::Move, "Sets the field <themove> to <amove>", py::arg("amove"));
cls_Units_ShiftedUnit.def("Move", (Standard_Real (Units_ShiftedUnit::*)() const) &Units_ShiftedUnit::Move, "Returns the shifted value <themove>.");
cls_Units_ShiftedUnit.def("Token", (opencascade::handle<Units_Token> (Units_ShiftedUnit::*)() const) &Units_ShiftedUnit::Token, "This redefined method returns a ShiftedToken object.");
cls_Units_ShiftedUnit.def("Dump", (void (Units_ShiftedUnit::*)(const Standard_Integer, const Standard_Integer) const) &Units_ShiftedUnit::Dump, "None", py::arg("ashift"), py::arg("alevel"));
cls_Units_ShiftedUnit.def_static("get_type_name_", (const char * (*)()) &Units_ShiftedUnit::get_type_name, "None");
cls_Units_ShiftedUnit.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Units_ShiftedUnit::get_type_descriptor, "None");
cls_Units_ShiftedUnit.def("DynamicType", (const opencascade::handle<Standard_Type> & (Units_ShiftedUnit::*)() const) &Units_ShiftedUnit::DynamicType, "None");

// CLASS: UNITS_UNITSDICTIONARY
py::class_<Units_UnitsDictionary, opencascade::handle<Units_UnitsDictionary>, Standard_Transient> cls_Units_UnitsDictionary(mod, "Units_UnitsDictionary", "This class creates a dictionary of all the units you want to know.");

// Constructors
cls_Units_UnitsDictionary.def(py::init<>());

// Methods
cls_Units_UnitsDictionary.def("Creates", (void (Units_UnitsDictionary::*)()) &Units_UnitsDictionary::Creates, "Returns a UnitsDictionary object which contains the sequence of all the units you want to consider, physical quantity by physical quantity.");
cls_Units_UnitsDictionary.def("Sequence", (opencascade::handle<Units_QuantitiesSequence> (Units_UnitsDictionary::*)() const) &Units_UnitsDictionary::Sequence, "Returns the head of the sequence of physical quantities.");
cls_Units_UnitsDictionary.def("ActiveUnit", (TCollection_AsciiString (Units_UnitsDictionary::*)(const Standard_CString) const) &Units_UnitsDictionary::ActiveUnit, "Returns for <aquantity> the active unit.", py::arg("aquantity"));
cls_Units_UnitsDictionary.def("Dump", (void (Units_UnitsDictionary::*)(const Standard_Integer) const) &Units_UnitsDictionary::Dump, "Dumps only the sequence of quantities without the units if <alevel> is equal to zero, and for each quantity all the units stored if <alevel> is equal to one.", py::arg("alevel"));
cls_Units_UnitsDictionary.def("Dump", (void (Units_UnitsDictionary::*)(const opencascade::handle<Units_Dimensions> &) const) &Units_UnitsDictionary::Dump, "Dumps for a designated physical dimensions <adimensions> all the previously stored units.", py::arg("adimensions"));
cls_Units_UnitsDictionary.def_static("get_type_name_", (const char * (*)()) &Units_UnitsDictionary::get_type_name, "None");
cls_Units_UnitsDictionary.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Units_UnitsDictionary::get_type_descriptor, "None");
cls_Units_UnitsDictionary.def("DynamicType", (const opencascade::handle<Standard_Type> & (Units_UnitsDictionary::*)() const) &Units_UnitsDictionary::DynamicType, "None");

// CLASS: UNITS_UNITSENTENCE
py::class_<Units_UnitSentence, Units_Sentence> cls_Units_UnitSentence(mod, "Units_UnitSentence", "This class describes all the facilities to manipulate and compute units contained in a string expression.");

// Constructors
cls_Units_UnitSentence.def(py::init<const Standard_CString>(), py::arg("astring"));
cls_Units_UnitSentence.def(py::init<const Standard_CString, const opencascade::handle<Units_QuantitiesSequence> &>(), py::arg("astring"), py::arg("aquantitiessequence"));

// Methods
// cls_Units_UnitSentence.def_static("operator new_", (void * (*)(size_t)) &Units_UnitSentence::operator new, "None", py::arg("theSize"));
// cls_Units_UnitSentence.def_static("operator delete_", (void (*)(void *)) &Units_UnitSentence::operator delete, "None", py::arg("theAddress"));
// cls_Units_UnitSentence.def_static("operator new[]_", (void * (*)(size_t)) &Units_UnitSentence::operator new[], "None", py::arg("theSize"));
// cls_Units_UnitSentence.def_static("operator delete[]_", (void (*)(void *)) &Units_UnitSentence::operator delete[], "None", py::arg("theAddress"));
// cls_Units_UnitSentence.def_static("operator new_", (void * (*)(size_t, void *)) &Units_UnitSentence::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Units_UnitSentence.def_static("operator delete_", (void (*)(void *, void *)) &Units_UnitSentence::operator delete, "None", py::arg(""), py::arg(""));
cls_Units_UnitSentence.def("Analyse", (void (Units_UnitSentence::*)()) &Units_UnitSentence::Analyse, "Analyzes the sequence of tokens created by the constructor to find the true significance of each token.");
cls_Units_UnitSentence.def("SetUnits", (void (Units_UnitSentence::*)(const opencascade::handle<Units_QuantitiesSequence> &)) &Units_UnitSentence::SetUnits, "For each token which represents a unit, finds in the sequence of physical quantities all the characteristics of the unit found.", py::arg("aquantitiessequence"));

// CLASS: UNITS_UNITSLEXICON
py::class_<Units_UnitsLexicon, opencascade::handle<Units_UnitsLexicon>, Units_Lexicon> cls_Units_UnitsLexicon(mod, "Units_UnitsLexicon", "This class defines a lexicon useful to analyse and recognize the different key words included in a sentence. The lexicon is stored in a sequence of tokens.");

// Constructors
cls_Units_UnitsLexicon.def(py::init<>());

// Methods
cls_Units_UnitsLexicon.def("Creates", [](Units_UnitsLexicon &self) -> void { return self.Creates(); });
cls_Units_UnitsLexicon.def("Creates", (void (Units_UnitsLexicon::*)(const Standard_Boolean)) &Units_UnitsLexicon::Creates, "Reads the files <afilename1> and <afilename2> to create a sequence of tokens stored in <thesequenceoftokens>.", py::arg("amode"));
cls_Units_UnitsLexicon.def("Dump", (void (Units_UnitsLexicon::*)() const) &Units_UnitsLexicon::Dump, "Useful for debugging.");
cls_Units_UnitsLexicon.def_static("get_type_name_", (const char * (*)()) &Units_UnitsLexicon::get_type_name, "None");
cls_Units_UnitsLexicon.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Units_UnitsLexicon::get_type_descriptor, "None");
cls_Units_UnitsLexicon.def("DynamicType", (const opencascade::handle<Standard_Type> & (Units_UnitsLexicon::*)() const) &Units_UnitsLexicon::DynamicType, "None");

// CLASS: UNITS_UNITSSYSTEM
py::class_<Units_UnitsSystem, opencascade::handle<Units_UnitsSystem>, Standard_Transient> cls_Units_UnitsSystem(mod, "Units_UnitsSystem", "This class allows the user to define his own system of units.");

// Constructors
cls_Units_UnitsSystem.def(py::init<>());
cls_Units_UnitsSystem.def(py::init<const Standard_CString>(), py::arg("aName"));
cls_Units_UnitsSystem.def(py::init<const Standard_CString, const Standard_Boolean>(), py::arg("aName"), py::arg("Verbose"));

// Methods
cls_Units_UnitsSystem.def("QuantitiesSequence", (opencascade::handle<Units_QuantitiesSequence> (Units_UnitsSystem::*)() const) &Units_UnitsSystem::QuantitiesSequence, "Returns the sequence of refined quantities.");
cls_Units_UnitsSystem.def("ActiveUnitsSequence", (opencascade::handle<TColStd_HSequenceOfInteger> (Units_UnitsSystem::*)() const) &Units_UnitsSystem::ActiveUnitsSequence, "Returns a sequence of integer in correspondance with the sequence of quantities, which indicates, for each redefined quantity, the index into the sequence of units, of the active unit.");
cls_Units_UnitsSystem.def("Specify", (void (Units_UnitsSystem::*)(const Standard_CString, const Standard_CString)) &Units_UnitsSystem::Specify, "Specifies for <aquantity> the unit <aunit> used.", py::arg("aquantity"), py::arg("aunit"));
cls_Units_UnitsSystem.def("Remove", (void (Units_UnitsSystem::*)(const Standard_CString, const Standard_CString)) &Units_UnitsSystem::Remove, "Removes for <aquantity> the unit <aunit> used.", py::arg("aquantity"), py::arg("aunit"));
cls_Units_UnitsSystem.def("Activate", (void (Units_UnitsSystem::*)(const Standard_CString, const Standard_CString)) &Units_UnitsSystem::Activate, "Specifies for <aquantity> the unit <aunit> used.", py::arg("aquantity"), py::arg("aunit"));
cls_Units_UnitsSystem.def("Activates", (void (Units_UnitsSystem::*)()) &Units_UnitsSystem::Activates, "Activates the first unit of all defined system quantities");
cls_Units_UnitsSystem.def("ActiveUnit", (TCollection_AsciiString (Units_UnitsSystem::*)(const Standard_CString) const) &Units_UnitsSystem::ActiveUnit, "Returns for <aquantity> the active unit.", py::arg("aquantity"));
cls_Units_UnitsSystem.def("ConvertValueToUserSystem", (Standard_Real (Units_UnitsSystem::*)(const Standard_CString, const Standard_Real, const Standard_CString) const) &Units_UnitsSystem::ConvertValueToUserSystem, "Converts a real value <avalue> from the unit <aunit> belonging to the physical dimensions <aquantity> to the corresponding unit of the user system.", py::arg("aquantity"), py::arg("avalue"), py::arg("aunit"));
cls_Units_UnitsSystem.def("ConvertSIValueToUserSystem", (Standard_Real (Units_UnitsSystem::*)(const Standard_CString, const Standard_Real) const) &Units_UnitsSystem::ConvertSIValueToUserSystem, "Converts the real value <avalue> from the S.I. system of units to the user system of units. <aquantity> is the physical dimensions of the measurement.", py::arg("aquantity"), py::arg("avalue"));
cls_Units_UnitsSystem.def("ConvertUserSystemValueToSI", (Standard_Real (Units_UnitsSystem::*)(const Standard_CString, const Standard_Real) const) &Units_UnitsSystem::ConvertUserSystemValueToSI, "Converts the real value <avalue> from the user system of units to the S.I. system of units. <aquantity> is the physical dimensions of the measurement.", py::arg("aquantity"), py::arg("avalue"));
cls_Units_UnitsSystem.def("Dump", (void (Units_UnitsSystem::*)() const) &Units_UnitsSystem::Dump, "None");
cls_Units_UnitsSystem.def("IsEmpty", (Standard_Boolean (Units_UnitsSystem::*)() const) &Units_UnitsSystem::IsEmpty, "Returns TRUE if no units has been defined in the system.");
cls_Units_UnitsSystem.def_static("get_type_name_", (const char * (*)()) &Units_UnitsSystem::get_type_name, "None");
cls_Units_UnitsSystem.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Units_UnitsSystem::get_type_descriptor, "None");
cls_Units_UnitsSystem.def("DynamicType", (const opencascade::handle<Standard_Type> & (Units_UnitsSystem::*)() const) &Units_UnitsSystem::DynamicType, "None");


}
