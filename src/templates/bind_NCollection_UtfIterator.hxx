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
#ifndef __NCollection_UtfIterator__
#define __NCollection_UtfIterator__

#include <NCollection_UtfIterator.hxx>
#include <Standard_TypeDef.hxx>

template <typename Type>
void bind_NCollection_UtfIterator(py::module &mod, std::string const &name, py::module_local const &local){

py::class_<NCollection_UtfIterator<Type>> cls_NCollection_UtfIterator(mod, name.c_str(), "Template class for Unicode strings support.", local);

// Constructors
cls_NCollection_UtfIterator.def(py::init<const Type *>(), py::arg("theString"));

// Methods
cls_NCollection_UtfIterator.def("Init", (void (NCollection_UtfIterator<Type>::*)(const Type *)) &NCollection_UtfIterator<Type>::Init, "Initialize iterator within specified NULL-terminated string.", py::arg("theString"));
cls_NCollection_UtfIterator.def("plus_plus", (NCollection_UtfIterator<Type> & (NCollection_UtfIterator<Type>::*)()) &NCollection_UtfIterator<Type>::operator++, py::is_operator(), "Pre-increment operator. Reads the next unicode symbol. Notice - no protection against overrun!");
cls_NCollection_UtfIterator.def("plus_plus", (NCollection_UtfIterator<Type> (NCollection_UtfIterator<Type>::*)(int)) &NCollection_UtfIterator<Type>::operator++, py::is_operator(), "Post-increment operator. Notice - no protection against overrun!", py::arg(""));
cls_NCollection_UtfIterator.def("__eq__", (bool (NCollection_UtfIterator<Type>::*)(const NCollection_UtfIterator<Type> &) const) &NCollection_UtfIterator<Type>::operator==, py::is_operator(), "Equality operator.", py::arg("theRight"));
cls_NCollection_UtfIterator.def("IsValid", (bool (NCollection_UtfIterator<Type>::*)() const) &NCollection_UtfIterator<Type>::IsValid, "Return true if Unicode symbol is within valid range.");
cls_NCollection_UtfIterator.def("__mul__", (Standard_Utf32Char (NCollection_UtfIterator<Type>::*)() const) &NCollection_UtfIterator<Type>::operator*, py::is_operator(), "Dereference operator.");
cls_NCollection_UtfIterator.def("BufferHere", (const Type * (NCollection_UtfIterator<Type>::*)() const) &NCollection_UtfIterator<Type>::BufferHere, "Buffer-fetching getter.");
cls_NCollection_UtfIterator.def("ChangeBufferHere", (Type * (NCollection_UtfIterator<Type>::*)()) &NCollection_UtfIterator<Type>::ChangeBufferHere, "Buffer-fetching getter. Dangerous! Iterator should be reinitialized on buffer change.");
cls_NCollection_UtfIterator.def("BufferNext", (const Type * (NCollection_UtfIterator<Type>::*)() const) &NCollection_UtfIterator<Type>::BufferNext, "Buffer-fetching getter.");
cls_NCollection_UtfIterator.def("Index", (Standard_Integer (NCollection_UtfIterator<Type>::*)() const) &NCollection_UtfIterator<Type>::Index, "Returns the index displacement from iterator intialization (first symbol has index 0)");
cls_NCollection_UtfIterator.def("AdvanceBytesUtf8", (Standard_Integer (NCollection_UtfIterator<Type>::*)() const) &NCollection_UtfIterator<Type>::AdvanceBytesUtf8, "Returns the advance in bytes to store current symbol in UTF-8. 0 means an invalid symbol; 1-4 bytes are valid range.");
cls_NCollection_UtfIterator.def("AdvanceBytesUtf16", (Standard_Integer (NCollection_UtfIterator<Type>::*)() const) &NCollection_UtfIterator<Type>::AdvanceBytesUtf16, "Returns the advance in bytes to store current symbol in UTF-16. 0 means an invalid symbol; 2 bytes is a general case; 4 bytes for surrogate pair.");
cls_NCollection_UtfIterator.def("AdvanceCodeUnitsUtf16", (Standard_Integer (NCollection_UtfIterator<Type>::*)() const) &NCollection_UtfIterator<Type>::AdvanceCodeUnitsUtf16, "Returns the advance in bytes to store current symbol in UTF-16. 0 means an invalid symbol; 1 16-bit code unit is a general case; 2 16-bit code units for surrogate pair.");
cls_NCollection_UtfIterator.def("AdvanceBytesUtf32", (Standard_Integer (NCollection_UtfIterator<Type>::*)() const) &NCollection_UtfIterator<Type>::AdvanceBytesUtf32, "Returns the advance in bytes to store current symbol in UTF-32. Always 4 bytes (method for consistency).");
cls_NCollection_UtfIterator.def("GetUtf8", (Standard_Utf8Char * (NCollection_UtfIterator<Type>::*)(Standard_Utf8Char *) const) &NCollection_UtfIterator<Type>::GetUtf8, "Fill the UTF-8 buffer within current Unicode symbol. Use method AdvanceUtf8() to allocate buffer with enough size.", py::arg("theBuffer"));
cls_NCollection_UtfIterator.def("GetUtf8", (Standard_Utf8UChar * (NCollection_UtfIterator<Type>::*)(Standard_Utf8UChar *) const) &NCollection_UtfIterator<Type>::GetUtf8, "None", py::arg("theBuffer"));
cls_NCollection_UtfIterator.def("GetUtf16", (Standard_Utf16Char * (NCollection_UtfIterator<Type>::*)(Standard_Utf16Char *) const) &NCollection_UtfIterator<Type>::GetUtf16, "Fill the UTF-16 buffer within current Unicode symbol. Use method AdvanceUtf16() to allocate buffer with enough size.", py::arg("theBuffer"));
cls_NCollection_UtfIterator.def("GetUtf32", (Standard_Utf32Char * (NCollection_UtfIterator<Type>::*)(Standard_Utf32Char *) const) &NCollection_UtfIterator<Type>::GetUtf32, "Fill the UTF-32 buffer within current Unicode symbol. Use method AdvanceUtf32() to allocate buffer with enough size.", py::arg("theBuffer"));

}

#endif