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
#include <Standard_Handle.hxx>
#include <Units_TokensSequence.hxx>
#include <Standard_TypeDef.hxx>
#include <Units_Lexicon.hxx>
#include <Standard_Type.hxx>

void bind_Units_Lexicon(py::module &mod){

py::class_<Units_Lexicon, opencascade::handle<Units_Lexicon>, Standard_Transient> cls_Units_Lexicon(mod, "Units_Lexicon", "This class defines a lexicon useful to analyse and recognize the different key words included in a sentence. The lexicon is stored in a sequence of tokens.");

// Constructors
cls_Units_Lexicon.def(py::init<>());

// Fields

// Methods
cls_Units_Lexicon.def("Creates", (void (Units_Lexicon::*)()) &Units_Lexicon::Creates, "Reads the file <afilename> to create a sequence of tokens stored in <thesequenceoftokens>.");
cls_Units_Lexicon.def("Sequence", (opencascade::handle<Units_TokensSequence> (Units_Lexicon::*)() const) &Units_Lexicon::Sequence, "Returns the first item of the sequence of tokens.");
cls_Units_Lexicon.def("AddToken", (void (Units_Lexicon::*)(const Standard_CString, const Standard_CString, const Standard_Real)) &Units_Lexicon::AddToken, "Adds to the lexicon a new token with <aword>, <amean>, <avalue> as arguments. If there is already a token with the field <theword> equal to <aword>, the existing token is updated.", py::arg("aword"), py::arg("amean"), py::arg("avalue"));
cls_Units_Lexicon.def("Dump", (void (Units_Lexicon::*)() const) &Units_Lexicon::Dump, "Useful for debugging.");
cls_Units_Lexicon.def_static("get_type_name_", (const char * (*)()) &Units_Lexicon::get_type_name, "None");
cls_Units_Lexicon.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Units_Lexicon::get_type_descriptor, "None");
cls_Units_Lexicon.def("DynamicType", (const opencascade::handle<Standard_Type> & (Units_Lexicon::*)() const) &Units_Lexicon::DynamicType, "None");

// Enums

}