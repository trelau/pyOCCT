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

void bind_NCollection_CellFilter_Action(py::module &);
void bind_GetCapacity(py::module &);
void bind_NCollection_BaseAllocator(py::module &);
void bind_NCollection_SeqNode(py::module &);
void bind_NCollection_DelSeqNode(py::module &);
void bind_NCollection_BaseSequence(py::module &);
void bind_NCollection_Buffer(py::module &);
void bind_NCollection_ListNode(py::module &);
void bind_NCollection_DelListNode(py::module &);
void bind_NCollection_BaseList(py::module &);
void bind_NCollection_BaseVector(py::module &);
void bind_NCollection_DelMapNode(py::module &);
void bind_NCollection_BaseMap(py::module &);
void bind_NCollection_IncAllocator(py::module &);
void bind_NCollection_CellFilter_InspectorXYZ(py::module &);
void bind_NCollection_CellFilter_InspectorXY(py::module &);
void bind_NCollection_StdAllocator(py::module &);
void bind_NCollection_Utf8Iter(py::module &);
void bind_NCollection_Utf16Iter(py::module &);
void bind_NCollection_Utf32Iter(py::module &);
void bind_NCollection_UtfWideIter(py::module &);
void bind_NCollection_Utf8String(py::module &);
void bind_NCollection_Utf16String(py::module &);
void bind_NCollection_Utf32String(py::module &);
void bind_NCollection_UtfWideString(py::module &);
void bind_NCollection_UtfStringTool(py::module &);
void bind_NCollection_String(py::module &);
void bind_NCollection_AccAllocator(py::module &);
void bind_NCollection_AlignedAllocator(py::module &);
void bind_NCollection_HeapAllocator(py::module &);
void bind_Standard_Size(py::module &);
void bind_NCollection_SparseArrayBase(py::module &);
void bind_NCollection_WinHeapAllocator(py::module &);

PYBIND11_MODULE(NCollection, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.Precision");

bind_NCollection_CellFilter_Action(mod);
bind_GetCapacity(mod);
bind_NCollection_BaseAllocator(mod);
bind_NCollection_SeqNode(mod);
bind_NCollection_DelSeqNode(mod);
bind_NCollection_BaseSequence(mod);
bind_NCollection_Buffer(mod);
bind_NCollection_ListNode(mod);
bind_NCollection_DelListNode(mod);
bind_NCollection_BaseList(mod);
bind_NCollection_BaseVector(mod);
bind_NCollection_DelMapNode(mod);
bind_NCollection_BaseMap(mod);
bind_NCollection_IncAllocator(mod);
bind_NCollection_CellFilter_InspectorXYZ(mod);
bind_NCollection_CellFilter_InspectorXY(mod);
bind_NCollection_StdAllocator(mod);
bind_NCollection_Utf8Iter(mod);
bind_NCollection_Utf16Iter(mod);
bind_NCollection_Utf32Iter(mod);
bind_NCollection_UtfWideIter(mod);
bind_NCollection_Utf8String(mod);
bind_NCollection_Utf16String(mod);
bind_NCollection_Utf32String(mod);
bind_NCollection_UtfWideString(mod);
bind_NCollection_UtfStringTool(mod);
bind_NCollection_String(mod);
bind_NCollection_AccAllocator(mod);
bind_NCollection_AlignedAllocator(mod);
bind_NCollection_HeapAllocator(mod);
bind_Standard_Size(mod);
bind_NCollection_SparseArrayBase(mod);
bind_NCollection_WinHeapAllocator(mod);

}
