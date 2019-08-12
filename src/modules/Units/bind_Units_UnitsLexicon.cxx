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
#include <Units_Lexicon.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Units_UnitsLexicon.hxx>
#include <Standard_Type.hxx>

void bind_Units_UnitsLexicon(py::module &mod){

py::class_<Units_UnitsLexicon, opencascade::handle<Units_UnitsLexicon>, Units_Lexicon> cls_Units_UnitsLexicon(mod, "Units_UnitsLexicon", "This class defines a lexicon useful to analyse and recognize the different key words included in a sentence. The lexicon is stored in a sequence of tokens.");

// Constructors
cls_Units_UnitsLexicon.def(py::init<>());

// Fields

// Methods
cls_Units_UnitsLexicon.def("Creates", [](Units_UnitsLexicon &self) -> void { return self.Creates(); });
cls_Units_UnitsLexicon.def("Creates", (void (Units_UnitsLexicon::*)(const Standard_Boolean)) &Units_UnitsLexicon::Creates, "Reads the files <afilename1> and <afilename2> to create a sequence of tokens stored in <thesequenceoftokens>.", py::arg("amode"));
cls_Units_UnitsLexicon.def("Dump", (void (Units_UnitsLexicon::*)() const) &Units_UnitsLexicon::Dump, "Useful for debugging.");
cls_Units_UnitsLexicon.def_static("get_type_name_", (const char * (*)()) &Units_UnitsLexicon::get_type_name, "None");
cls_Units_UnitsLexicon.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Units_UnitsLexicon::get_type_descriptor, "None");
cls_Units_UnitsLexicon.def("DynamicType", (const opencascade::handle<Standard_Type> & (Units_UnitsLexicon::*)() const) &Units_UnitsLexicon::DynamicType, "None");

// Enums

}