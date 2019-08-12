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
#include <Standard_Transient.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Units_Quantity.hxx>
#include <TCollection_AsciiString.hxx>
#include <TColStd_HSequenceOfHAsciiString.hxx>
#include <Units_Token.hxx>
#include <Units_Unit.hxx>
#include <Standard_Type.hxx>
#include <TCollection_HAsciiString.hxx>

void bind_Units_Unit(py::module &mod){

py::class_<Units_Unit, opencascade::handle<Units_Unit>, Standard_Transient> cls_Units_Unit(mod, "Units_Unit", "This class defines an elementary word contained in a physical quantity.");

// Constructors
cls_Units_Unit.def(py::init<const Standard_CString, const Standard_CString, const Standard_Real, const opencascade::handle<Units_Quantity> &>(), py::arg("aname"), py::arg("asymbol"), py::arg("avalue"), py::arg("aquantity"));
cls_Units_Unit.def(py::init<const Standard_CString, const Standard_CString>(), py::arg("aname"), py::arg("asymbol"));
cls_Units_Unit.def(py::init<const Standard_CString>(), py::arg("aname"));

// Fields

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

// Enums

}