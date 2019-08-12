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

void bind_TColStd_Array1OfReal(py::module &);
void bind_TColStd_HArray1OfReal(py::module &);
void bind_TColStd_Array1OfInteger(py::module &);
void bind_TColStd_HArray1OfInteger(py::module &);
void bind_TColStd_Array2OfReal(py::module &);
void bind_TColStd_SequenceOfReal(py::module &);
void bind_TColStd_HSequenceOfReal(py::module &);
void bind_TColStd_HArray2OfReal(py::module &);
void bind_TColStd_ListOfInteger(py::module &);
void bind_TColStd_ListIteratorOfListOfInteger(py::module &);
void bind_TColStd_Array1OfByte(py::module &);
void bind_TColStd_HArray1OfByte(py::module &);
void bind_TColStd_IndexedDataMapOfStringString(py::module &);
void bind_TColStd_ListOfTransient(py::module &);
void bind_TColStd_ListIteratorOfListOfTransient(py::module &);
void bind_TColStd_SequenceOfInteger(py::module &);
void bind_TColStd_MapTransientHasher(py::module &);
void bind_TColStd_MapOfTransient(py::module &);
void bind_TColStd_MapIteratorOfMapOfTransient(py::module &);
void bind_TColStd_MapIntegerHasher(py::module &);
void bind_TColStd_SequenceOfExtendedString(py::module &);
void bind_TColStd_DataMapOfIntegerListOfInteger(py::module &);
void bind_TColStd_DataMapIteratorOfDataMapOfIntegerListOfInteger(py::module &);
void bind_TColStd_MapOfInteger(py::module &);
void bind_TColStd_MapIteratorOfMapOfInteger(py::module &);
void bind_TColStd_Array1OfTransient(py::module &);
void bind_TColStd_Array1OfAsciiString(py::module &);
void bind_TColStd_SequenceOfHAsciiString(py::module &);
void bind_TColStd_HSequenceOfHAsciiString(py::module &);
void bind_TColStd_Array2OfInteger(py::module &);
void bind_TColStd_HArray2OfInteger(py::module &);
void bind_TColStd_SequenceOfAsciiString(py::module &);
void bind_TColStd_SequenceOfAddress(py::module &);
void bind_TColStd_DataMapOfIntegerTransient(py::module &);
void bind_TColStd_DataMapIteratorOfDataMapOfIntegerTransient(py::module &);
void bind_TColStd_HSequenceOfAsciiString(py::module &);
void bind_TColStd_IndexedMapOfTransient(py::module &);
void bind_TColStd_DataMapOfAsciiStringInteger(py::module &);
void bind_TColStd_DataMapIteratorOfDataMapOfAsciiStringInteger(py::module &);
void bind_TColStd_DataMapOfIntegerInteger(py::module &);
void bind_TColStd_DataMapIteratorOfDataMapOfIntegerInteger(py::module &);
void bind_TColStd_Array1OfListOfInteger(py::module &);
void bind_TColStd_HArray1OfListOfInteger(py::module &);
void bind_TColStd_DataMapOfIntegerReal(py::module &);
void bind_TColStd_DataMapIteratorOfDataMapOfIntegerReal(py::module &);
void bind_TColStd_PackedMapOfInteger(py::module &);
void bind_TColStd_IndexedMapOfInteger(py::module &);
void bind_TColStd_SequenceOfBoolean(py::module &);
void bind_TColStd_Array1OfBoolean(py::module &);
void bind_TColStd_MapOfAsciiString(py::module &);
void bind_TColStd_MapIteratorOfMapOfAsciiString(py::module &);
void bind_TColStd_Array2OfBoolean(py::module &);
void bind_TColStd_IndexedDataMapOfTransientTransient(py::module &);
void bind_TColStd_DataMapOfStringInteger(py::module &);
void bind_TColStd_DataMapIteratorOfDataMapOfStringInteger(py::module &);
void bind_TColStd_ListOfReal(py::module &);
void bind_TColStd_ListIteratorOfListOfReal(py::module &);
void bind_TColStd_ListOfAsciiString(py::module &);
void bind_TColStd_ListIteratorOfListOfAsciiString(py::module &);
void bind_TColStd_HArray1OfBoolean(py::module &);
void bind_TColStd_HSequenceOfInteger(py::module &);
void bind_TColStd_HArray1OfTransient(py::module &);
void bind_TColStd_SequenceOfTransient(py::module &);
void bind_TColStd_HSequenceOfTransient(py::module &);
void bind_TColStd_Array2OfTransient(py::module &);
void bind_TColStd_HArray2OfTransient(py::module &);
void bind_TColStd_HPackedMapOfInteger(py::module &);
void bind_TColStd_HArray1OfAsciiString(py::module &);
void bind_TColStd_SequenceOfHExtendedString(py::module &);
void bind_TColStd_HSequenceOfHExtendedString(py::module &);
void bind_TColStd_MapIteratorOfPackedMapOfInteger(py::module &);
void bind_TColStd_Array1OfExtendedString(py::module &);
void bind_TColStd_HArray1OfExtendedString(py::module &);
void bind_TColStd_Array1OfCharacter(py::module &);
void bind_TColStd_Array2OfCharacter(py::module &);
void bind_TColStd_DataMapOfTransientTransient(py::module &);
void bind_TColStd_DataMapIteratorOfDataMapOfTransientTransient(py::module &);
void bind_TColStd_HArray1OfCharacter(py::module &);
void bind_TColStd_HArray2OfBoolean(py::module &);
void bind_TColStd_HArray2OfCharacter(py::module &);
void bind_TColStd_HSequenceOfExtendedString(py::module &);
void bind_TColStd_MapRealHasher(py::module &);
void bind_TColStd_IndexedMapOfReal(py::module &);
void bind_TColStd_MapOfReal(py::module &);
void bind_TColStd_MapIteratorOfMapOfReal(py::module &);

PYBIND11_MODULE(TColStd, mod) {

py::module::import("OCCT.NCollection");
py::module::import("OCCT.Standard");
py::module::import("OCCT.TCollection");

bind_TColStd_Array1OfReal(mod);
bind_TColStd_HArray1OfReal(mod);
bind_TColStd_Array1OfInteger(mod);
bind_TColStd_HArray1OfInteger(mod);
bind_TColStd_Array2OfReal(mod);
bind_TColStd_SequenceOfReal(mod);
bind_TColStd_HSequenceOfReal(mod);
bind_TColStd_HArray2OfReal(mod);
bind_TColStd_ListOfInteger(mod);
bind_TColStd_ListIteratorOfListOfInteger(mod);
bind_TColStd_Array1OfByte(mod);
bind_TColStd_HArray1OfByte(mod);
bind_TColStd_IndexedDataMapOfStringString(mod);
bind_TColStd_ListOfTransient(mod);
bind_TColStd_ListIteratorOfListOfTransient(mod);
bind_TColStd_SequenceOfInteger(mod);
bind_TColStd_MapTransientHasher(mod);
bind_TColStd_MapOfTransient(mod);
bind_TColStd_MapIteratorOfMapOfTransient(mod);
bind_TColStd_MapIntegerHasher(mod);
bind_TColStd_SequenceOfExtendedString(mod);
bind_TColStd_DataMapOfIntegerListOfInteger(mod);
bind_TColStd_DataMapIteratorOfDataMapOfIntegerListOfInteger(mod);
bind_TColStd_MapOfInteger(mod);
bind_TColStd_MapIteratorOfMapOfInteger(mod);
bind_TColStd_Array1OfTransient(mod);
bind_TColStd_Array1OfAsciiString(mod);
bind_TColStd_SequenceOfHAsciiString(mod);
bind_TColStd_HSequenceOfHAsciiString(mod);
bind_TColStd_Array2OfInteger(mod);
bind_TColStd_HArray2OfInteger(mod);
bind_TColStd_SequenceOfAsciiString(mod);
bind_TColStd_SequenceOfAddress(mod);
bind_TColStd_DataMapOfIntegerTransient(mod);
bind_TColStd_DataMapIteratorOfDataMapOfIntegerTransient(mod);
bind_TColStd_HSequenceOfAsciiString(mod);
bind_TColStd_IndexedMapOfTransient(mod);
bind_TColStd_DataMapOfAsciiStringInteger(mod);
bind_TColStd_DataMapIteratorOfDataMapOfAsciiStringInteger(mod);
bind_TColStd_DataMapOfIntegerInteger(mod);
bind_TColStd_DataMapIteratorOfDataMapOfIntegerInteger(mod);
bind_TColStd_Array1OfListOfInteger(mod);
bind_TColStd_HArray1OfListOfInteger(mod);
bind_TColStd_DataMapOfIntegerReal(mod);
bind_TColStd_DataMapIteratorOfDataMapOfIntegerReal(mod);
bind_TColStd_PackedMapOfInteger(mod);
bind_TColStd_IndexedMapOfInteger(mod);
bind_TColStd_SequenceOfBoolean(mod);
bind_TColStd_Array1OfBoolean(mod);
bind_TColStd_MapOfAsciiString(mod);
bind_TColStd_MapIteratorOfMapOfAsciiString(mod);
bind_TColStd_Array2OfBoolean(mod);
bind_TColStd_IndexedDataMapOfTransientTransient(mod);
bind_TColStd_DataMapOfStringInteger(mod);
bind_TColStd_DataMapIteratorOfDataMapOfStringInteger(mod);
bind_TColStd_ListOfReal(mod);
bind_TColStd_ListIteratorOfListOfReal(mod);
bind_TColStd_ListOfAsciiString(mod);
bind_TColStd_ListIteratorOfListOfAsciiString(mod);
bind_TColStd_HArray1OfBoolean(mod);
bind_TColStd_HSequenceOfInteger(mod);
bind_TColStd_HArray1OfTransient(mod);
bind_TColStd_SequenceOfTransient(mod);
bind_TColStd_HSequenceOfTransient(mod);
bind_TColStd_Array2OfTransient(mod);
bind_TColStd_HArray2OfTransient(mod);
bind_TColStd_HPackedMapOfInteger(mod);
bind_TColStd_HArray1OfAsciiString(mod);
bind_TColStd_SequenceOfHExtendedString(mod);
bind_TColStd_HSequenceOfHExtendedString(mod);
bind_TColStd_MapIteratorOfPackedMapOfInteger(mod);
bind_TColStd_Array1OfExtendedString(mod);
bind_TColStd_HArray1OfExtendedString(mod);
bind_TColStd_Array1OfCharacter(mod);
bind_TColStd_Array2OfCharacter(mod);
bind_TColStd_DataMapOfTransientTransient(mod);
bind_TColStd_DataMapIteratorOfDataMapOfTransientTransient(mod);
bind_TColStd_HArray1OfCharacter(mod);
bind_TColStd_HArray2OfBoolean(mod);
bind_TColStd_HArray2OfCharacter(mod);
bind_TColStd_HSequenceOfExtendedString(mod);
bind_TColStd_MapRealHasher(mod);
bind_TColStd_IndexedMapOfReal(mod);
bind_TColStd_MapOfReal(mod);
bind_TColStd_MapIteratorOfMapOfReal(mod);

}
