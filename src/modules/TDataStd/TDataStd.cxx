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

void bind_TDataStd_RealEnum(py::module &);
void bind_TDataStd_IntegerArray(py::module &);
void bind_TDataStd_RealArray(py::module &);
void bind_TDataStd_ByteArray(py::module &);
void bind_TDataStd_ExtStringArray(py::module &);
void bind_TDataStd_BooleanArray(py::module &);
void bind_TDataStd_LabelArray1(py::module &);
void bind_TDataStd_HLabelArray1(py::module &);
void bind_TDataStd_ReferenceArray(py::module &);
void bind_TDataStd_IntegerList(py::module &);
void bind_TDataStd_RealList(py::module &);
void bind_TDataStd_ListOfExtendedString(py::module &);
void bind_TDataStd_ListIteratorOfListOfExtendedString(py::module &);
void bind_TDataStd_ExtStringList(py::module &);
void bind_TDataStd_ListOfByte(py::module &);
void bind_TDataStd_ListIteratorOfListOfByte(py::module &);
void bind_TDataStd_BooleanList(py::module &);
void bind_TDataStd_ReferenceList(py::module &);
void bind_TDataStd_IntPackedMap(py::module &);
void bind_TDataStd_Expression(py::module &);
void bind_TDataStd_Relation(py::module &);
void bind_TDataStd_DataMapOfStringReal(py::module &);
void bind_TDataStd_DataMapIteratorOfDataMapOfStringReal(py::module &);
void bind_TDataStd_DataMapOfStringString(py::module &);
void bind_TDataStd_DataMapIteratorOfDataMapOfStringString(py::module &);
void bind_TDataStd_DataMapOfStringByte(py::module &);
void bind_TDataStd_DataMapIteratorOfDataMapOfStringByte(py::module &);
void bind_TDataStd_DataMapOfStringHArray1OfInteger(py::module &);
void bind_TDataStd_DataMapIteratorOfDataMapOfStringHArray1OfInteger(py::module &);
void bind_TDataStd_DataMapOfStringHArray1OfReal(py::module &);
void bind_TDataStd_DataMapIteratorOfDataMapOfStringHArray1OfReal(py::module &);
void bind_TDataStd_NamedData(py::module &);
void bind_TDataStd_Real(py::module &);
void bind_TDataStd_PtrTreeNode(py::module &);
void bind_TDataStd_TreeNode(py::module &);
void bind_TDataStd_Integer(py::module &);
void bind_TDataStd_UAttribute(py::module &);
void bind_TDataStd_Name(py::module &);
void bind_TDataStd_Comment(py::module &);
void bind_TDataStd_AsciiString(py::module &);
void bind_TDataStd_Variable(py::module &);
void bind_TDataStd_Directory(py::module &);
void bind_TDataStd_Tick(py::module &);
void bind_TDataStd_NoteBook(py::module &);
void bind_TDataStd(py::module &);
void bind_TDataStd_ChildNodeIterator(py::module &);
void bind_TDataStd_Current(py::module &);
void bind_TDataStd_DeltaOnModificationOfByteArray(py::module &);
void bind_TDataStd_DeltaOnModificationOfExtStringArray(py::module &);
void bind_TDataStd_DeltaOnModificationOfIntArray(py::module &);
void bind_TDataStd_DeltaOnModificationOfIntPackedMap(py::module &);
void bind_TDataStd_DeltaOnModificationOfRealArray(py::module &);
void bind_TDataStd_HDataMapOfStringByte(py::module &);
void bind_TDataStd_HDataMapOfStringHArray1OfInteger(py::module &);
void bind_TDataStd_HDataMapOfStringHArray1OfReal(py::module &);
void bind_TDataStd_HDataMapOfStringInteger(py::module &);
void bind_TDataStd_HDataMapOfStringReal(py::module &);
void bind_TDataStd_HDataMapOfStringString(py::module &);

PYBIND11_MODULE(TDataStd, mod) {

py::module::import("OCCT.TDF");
py::module::import("OCCT.Standard");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.NCollection");

bind_TDataStd_RealEnum(mod);
bind_TDataStd_IntegerArray(mod);
bind_TDataStd_RealArray(mod);
bind_TDataStd_ByteArray(mod);
bind_TDataStd_ExtStringArray(mod);
bind_TDataStd_BooleanArray(mod);
bind_TDataStd_LabelArray1(mod);
bind_TDataStd_HLabelArray1(mod);
bind_TDataStd_ReferenceArray(mod);
bind_TDataStd_IntegerList(mod);
bind_TDataStd_RealList(mod);
bind_TDataStd_ListOfExtendedString(mod);
bind_TDataStd_ListIteratorOfListOfExtendedString(mod);
bind_TDataStd_ExtStringList(mod);
bind_TDataStd_ListOfByte(mod);
bind_TDataStd_ListIteratorOfListOfByte(mod);
bind_TDataStd_BooleanList(mod);
bind_TDataStd_ReferenceList(mod);
bind_TDataStd_IntPackedMap(mod);
bind_TDataStd_Expression(mod);
bind_TDataStd_Relation(mod);
bind_TDataStd_DataMapOfStringReal(mod);
bind_TDataStd_DataMapIteratorOfDataMapOfStringReal(mod);
bind_TDataStd_DataMapOfStringString(mod);
bind_TDataStd_DataMapIteratorOfDataMapOfStringString(mod);
bind_TDataStd_DataMapOfStringByte(mod);
bind_TDataStd_DataMapIteratorOfDataMapOfStringByte(mod);
bind_TDataStd_DataMapOfStringHArray1OfInteger(mod);
bind_TDataStd_DataMapIteratorOfDataMapOfStringHArray1OfInteger(mod);
bind_TDataStd_DataMapOfStringHArray1OfReal(mod);
bind_TDataStd_DataMapIteratorOfDataMapOfStringHArray1OfReal(mod);
bind_TDataStd_NamedData(mod);
bind_TDataStd_Real(mod);
bind_TDataStd_PtrTreeNode(mod);
bind_TDataStd_TreeNode(mod);
bind_TDataStd_Integer(mod);
bind_TDataStd_UAttribute(mod);
bind_TDataStd_Name(mod);
bind_TDataStd_Comment(mod);
bind_TDataStd_AsciiString(mod);
bind_TDataStd_Variable(mod);
bind_TDataStd_Directory(mod);
bind_TDataStd_Tick(mod);
bind_TDataStd_NoteBook(mod);
bind_TDataStd(mod);
bind_TDataStd_ChildNodeIterator(mod);
bind_TDataStd_Current(mod);
bind_TDataStd_DeltaOnModificationOfByteArray(mod);
bind_TDataStd_DeltaOnModificationOfExtStringArray(mod);
bind_TDataStd_DeltaOnModificationOfIntArray(mod);
bind_TDataStd_DeltaOnModificationOfIntPackedMap(mod);
bind_TDataStd_DeltaOnModificationOfRealArray(mod);
bind_TDataStd_HDataMapOfStringByte(mod);
bind_TDataStd_HDataMapOfStringHArray1OfInteger(mod);
bind_TDataStd_HDataMapOfStringHArray1OfReal(mod);
bind_TDataStd_HDataMapOfStringInteger(mod);
bind_TDataStd_HDataMapOfStringReal(mod);
bind_TDataStd_HDataMapOfStringString(mod);

}
