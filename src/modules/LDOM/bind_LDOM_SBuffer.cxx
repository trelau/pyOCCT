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
#include <LDOM_OSStream.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_TypeDef.hxx>

void bind_LDOM_SBuffer(py::module &mod){

py::class_<LDOM_SBuffer, std::unique_ptr<LDOM_SBuffer, Deleter<LDOM_SBuffer>>> cls_LDOM_SBuffer(mod, "LDOM_SBuffer", "Class LDOM_SBuffer inherits streambuf and redefines some virtual methods of it (overflow() and xsputn()). This class contains pointers on first and current element of sequence, also it has methods for the sequence management.");

// Constructors
cls_LDOM_SBuffer.def(py::init<const Standard_Integer>(), py::arg("theMaxBuf"));

// Fields

// Methods
cls_LDOM_SBuffer.def("str", (Standard_CString (LDOM_SBuffer::*)() const) &LDOM_SBuffer::str, "Concatenates strings of all sequence elements into one string. Space for output string is allocated with operator new. Caller of this function is responsible for memory release after the string usage.");
cls_LDOM_SBuffer.def("Length", (Standard_Integer (LDOM_SBuffer::*)() const) &LDOM_SBuffer::Length, "Returns full length of data contained");
cls_LDOM_SBuffer.def("Clear", (void (LDOM_SBuffer::*)()) &LDOM_SBuffer::Clear, "Clears first element of sequence and removes all others");
cls_LDOM_SBuffer.def("overflow", [](LDOM_SBuffer &self) -> int { return self.overflow(); });
cls_LDOM_SBuffer.def("overflow", (int (LDOM_SBuffer::*)(int)) &LDOM_SBuffer::overflow, "None", py::arg("c"));
cls_LDOM_SBuffer.def("underflow", (int (LDOM_SBuffer::*)()) &LDOM_SBuffer::underflow, "None");
cls_LDOM_SBuffer.def("xsputn", (std::streamsize (LDOM_SBuffer::*)(const char *, std::streamsize)) &LDOM_SBuffer::xsputn, "None", py::arg("s"), py::arg("n"));

// Enums

}