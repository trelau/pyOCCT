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
#include <Standard_OStream.hxx>
#include <Standard_TypeDef.hxx>
#include <LDOM_OSStream.hxx>

void bind_LDOM_OSStream(py::module &mod){

py::class_<LDOM_OSStream, std::unique_ptr<LDOM_OSStream, Deleter<LDOM_OSStream>>> cls_LDOM_OSStream(mod, "LDOM_OSStream", "Subclass if std::ostream allowing to increase performance of outputting data into a string avoiding reallocation of buffer. Class LDOM_OSStream implements output into a sequence of strings and getting the result as a string. It inherits Standard_OStream (ostream). Beside methods of ostream, it also has additional useful methods: str(), Length() and Clear().");

// Constructors
cls_LDOM_OSStream.def(py::init<const Standard_Integer>(), py::arg("theMaxBuf"));

// Fields

// Methods
cls_LDOM_OSStream.def("str", (Standard_CString (LDOM_OSStream::*)() const) &LDOM_OSStream::str, "None");
cls_LDOM_OSStream.def("Length", (Standard_Integer (LDOM_OSStream::*)() const) &LDOM_OSStream::Length, "None");
cls_LDOM_OSStream.def("Clear", (void (LDOM_OSStream::*)()) &LDOM_OSStream::Clear, "None");

// Enums

}