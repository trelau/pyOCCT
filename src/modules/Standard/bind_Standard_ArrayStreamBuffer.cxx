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
#include <Standard_ArrayStreamBuffer.hxx>

void bind_Standard_ArrayStreamBuffer(py::module &mod){

py::class_<Standard_ArrayStreamBuffer, std::unique_ptr<Standard_ArrayStreamBuffer, Deleter<Standard_ArrayStreamBuffer>>> cls_Standard_ArrayStreamBuffer(mod, "Standard_ArrayStreamBuffer", "Custom buffer object implementing STL interface std::streambuf for streamed reading from allocated memory block. Implements minimal sub-set of methods for passing buffer to std::istream, including seek support.");

// Constructors
cls_Standard_ArrayStreamBuffer.def(py::init<const char *, const size_t>(), py::arg("theBegin"), py::arg("theSize"));

// Fields

// Methods
cls_Standard_ArrayStreamBuffer.def("Init", (void (Standard_ArrayStreamBuffer::*)(const char *, const size_t)) &Standard_ArrayStreamBuffer::Init, "(Re)-initialize the stream. Passed pointer is stored as is (memory is NOT copied nor released with destructor).", py::arg("theBegin"), py::arg("theSize"));
cls_Standard_ArrayStreamBuffer.def("xsgetn", (std::streamsize (Standard_ArrayStreamBuffer::*)(char *, std::streamsize)) &Standard_ArrayStreamBuffer::xsgetn, "Read a bunch of bytes at once.", py::arg("thePtr"), py::arg("theCount"));

// Enums

}