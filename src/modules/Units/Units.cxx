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

void bind_Units(py::module &);
void bind_Units_Dimensions(py::module &);
void bind_Units_Unit(py::module &);
void bind_Units_UtsSequence(py::module &);
void bind_Units_UnitsSequence(py::module &);
void bind_Units_Quantity(py::module &);
void bind_Units_QtsSequence(py::module &);
void bind_Units_QuantitiesSequence(py::module &);
void bind_Units_Explorer(py::module &);
void bind_Units_Token(py::module &);
void bind_Units_TksSequence(py::module &);
void bind_Units_TokensSequence(py::module &);
void bind_Units_Lexicon(py::module &);
void bind_Units_Sentence(py::module &);
void bind_Units_MathSentence(py::module &);
void bind_Units_Measurement(py::module &);
void bind_Units_NoSuchType(py::module &);
void bind_Units_NoSuchUnit(py::module &);
void bind_Units_ShiftedToken(py::module &);
void bind_Units_ShiftedUnit(py::module &);
void bind_Units_UnitsDictionary(py::module &);
void bind_Units_UnitSentence(py::module &);
void bind_Units_UnitsLexicon(py::module &);
void bind_Units_UnitsSystem(py::module &);

PYBIND11_MODULE(Units, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.NCollection");

bind_Units(mod);
bind_Units_Dimensions(mod);
bind_Units_Unit(mod);
bind_Units_UtsSequence(mod);
bind_Units_UnitsSequence(mod);
bind_Units_Quantity(mod);
bind_Units_QtsSequence(mod);
bind_Units_QuantitiesSequence(mod);
bind_Units_Explorer(mod);
bind_Units_Token(mod);
bind_Units_TksSequence(mod);
bind_Units_TokensSequence(mod);
bind_Units_Lexicon(mod);
bind_Units_Sentence(mod);
bind_Units_MathSentence(mod);
bind_Units_Measurement(mod);
bind_Units_NoSuchType(mod);
bind_Units_NoSuchUnit(mod);
bind_Units_ShiftedToken(mod);
bind_Units_ShiftedUnit(mod);
bind_Units_UnitsDictionary(mod);
bind_Units_UnitSentence(mod);
bind_Units_UnitsLexicon(mod);
bind_Units_UnitsSystem(mod);

}
