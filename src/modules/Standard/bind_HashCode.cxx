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
#include <Standard_CString.hxx>
#include <Standard_Transient.hxx>
#include <Standard_ThreadId.hxx>

void bind_HashCode(py::module &mod){

mod.def("HashCode", (Standard_Integer (*) (const Standard_Integer, const Standard_Integer)) &HashCode, "None", py::arg("theMe"), py::arg("theUpper"));

mod.def("HashCode", (Standard_Integer (*) (const long long, const Standard_Integer)) &HashCode, "None", py::arg("theMe"), py::arg("theUpper"));

mod.def("HashCode", (Standard_Integer (*) (const Standard_Utf32Char, const Standard_Integer)) &HashCode, "None", py::arg("theMe"), py::arg("theUpper"));

mod.def("HashCode", (Standard_Integer (*) (const Standard_Address, const Standard_Integer)) &HashCode, "None", py::arg("Value"), py::arg("Upper"));

mod.def("HashCode", (Standard_Integer (*) (const Standard_Size, const Standard_Integer)) &HashCode, "None", py::arg("Val"), py::arg("Upper"));

mod.def("HashCode", (Standard_Integer (*) (const Standard_CString, const Standard_Integer, const Standard_Integer)) &HashCode, "Returns bounded hash code for the first theLen characters in the string theStr, in range [1, theUpper]", py::arg("theStr"), py::arg("theLen"), py::arg("theUpper"));

mod.def("HashCode", (Standard_Integer (*) (const Standard_Transient *, const Standard_Integer)) &HashCode, "Global method HashCode(), for use in hash maps", py::arg("theObject"), py::arg("theUpper"));

mod.def("HashCode", (Standard_Integer (*) (const Standard_ThreadId, const Standard_Integer)) &HashCode, "None", py::arg("Value"), py::arg("Upper"));

}