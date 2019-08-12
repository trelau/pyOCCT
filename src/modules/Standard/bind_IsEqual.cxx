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
#include <Standard_TypeDef.hxx>
#include <Standard_Integer.hxx>
#include <Standard_Address.hxx>
#include <Standard_Size.hxx>
#include <Standard_Real.hxx>
#include <Standard_Character.hxx>
#include <Standard_ExtCharacter.hxx>
#include <Standard_CString.hxx>
#include <Standard_ShortReal.hxx>
#include <Standard_Time.hxx>

void bind_IsEqual(py::module &mod){

mod.def("IsEqual", (Standard_Boolean (*) (const Standard_Integer, const Standard_Integer)) &IsEqual, "None", py::arg("theOne"), py::arg("theTwo"));

mod.def("IsEqual", (Standard_Boolean (*) (const Standard_Utf32Char, const Standard_Utf32Char)) &IsEqual, "None", py::arg("theOne"), py::arg("theTwo"));

mod.def("IsEqual", (Standard_Boolean (*) (const Standard_Address, const Standard_Address)) &IsEqual, "None", py::arg("One"), py::arg("Two"));

mod.def("IsEqual", (Standard_Boolean (*) (const Standard_Size, const Standard_Size)) &IsEqual, "None", py::arg("One"), py::arg("Two"));

mod.def("IsEqual", (Standard_Boolean (*) (const Standard_Real, const Standard_Real)) &IsEqual, "None", py::arg("Value1"), py::arg("Value2"));

mod.def("IsEqual", (Standard_Boolean (*) (const Standard_Character, const Standard_Character)) &IsEqual, "None", py::arg("One"), py::arg("Two"));

mod.def("IsEqual", (Standard_Boolean (*) (const Standard_ExtCharacter, const Standard_ExtCharacter)) &IsEqual, "None", py::arg("One"), py::arg("Two"));

mod.def("IsEqual", (Standard_Boolean (*) (const Standard_CString, const Standard_CString)) &IsEqual, "Returns Standard_True if two strings are equal", py::arg("theOne"), py::arg("theTwo"));

mod.def("IsEqual", (Standard_Boolean (*) (const Standard_ShortReal, const Standard_ShortReal)) &IsEqual, "None", py::arg("Value1"), py::arg("Value2"));

mod.def("IsEqual", (Standard_Boolean (*) (const Standard_Time, const Standard_Time)) &IsEqual, "None", py::arg("theOne"), py::arg("theTwo"));

}