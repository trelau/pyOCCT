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
#include <Units_Token.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Units_Dimensions.hxx>
#include <Units_ShiftedToken.hxx>
#include <Standard_Type.hxx>

void bind_Units_ShiftedToken(py::module &mod){

py::class_<Units_ShiftedToken, opencascade::handle<Units_ShiftedToken>, Units_Token> cls_Units_ShiftedToken(mod, "Units_ShiftedToken", "The ShiftedToken class inherits from Token and describes tokens which have a gap in addition of the multiplicative factor. This kind of token allows the description of linear functions which do not pass through the origin, of the form :");

// Constructors
cls_Units_ShiftedToken.def(py::init<const Standard_CString, const Standard_CString, const Standard_Real, const Standard_Real, const opencascade::handle<Units_Dimensions> &>(), py::arg("aword"), py::arg("amean"), py::arg("avalue"), py::arg("amove"), py::arg("adimensions"));

// Fields

// Methods
cls_Units_ShiftedToken.def("Creates", (opencascade::handle<Units_Token> (Units_ShiftedToken::*)() const) &Units_ShiftedToken::Creates, "Creates and returns a token, which is a ShiftedToken.");
cls_Units_ShiftedToken.def("Move", (Standard_Real (Units_ShiftedToken::*)() const) &Units_ShiftedToken::Move, "Returns the gap <themove>");
cls_Units_ShiftedToken.def("Multiplied", (Standard_Real (Units_ShiftedToken::*)(const Standard_Real) const) &Units_ShiftedToken::Multiplied, "This virtual method is called by the Measurement methods, to compute the measurement during a conversion.", py::arg("avalue"));
cls_Units_ShiftedToken.def("Divided", (Standard_Real (Units_ShiftedToken::*)(const Standard_Real) const) &Units_ShiftedToken::Divided, "This virtual method is called by the Measurement methods, to compute the measurement during a conversion.", py::arg("avalue"));
cls_Units_ShiftedToken.def("Dump", (void (Units_ShiftedToken::*)(const Standard_Integer, const Standard_Integer) const) &Units_ShiftedToken::Dump, "None", py::arg("ashift"), py::arg("alevel"));
cls_Units_ShiftedToken.def_static("get_type_name_", (const char * (*)()) &Units_ShiftedToken::get_type_name, "None");
cls_Units_ShiftedToken.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Units_ShiftedToken::get_type_descriptor, "None");
cls_Units_ShiftedToken.def("DynamicType", (const opencascade::handle<Standard_Type> & (Units_ShiftedToken::*)() const) &Units_ShiftedToken::DynamicType, "None");

// Enums

}