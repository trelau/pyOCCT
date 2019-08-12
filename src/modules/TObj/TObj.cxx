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

void bind_HashCode(py::module &);
void bind_IsEqual(py::module &);
void bind_TObj_Application(py::module &);
void bind_TObj_Assistant(py::module &);
void bind_TObj_DeletingMode(py::module &);
void bind_TObj_SequenceOfObject(py::module &);
void bind_TObj_HSequenceOfObject(py::module &);
void bind_TObj_Object(py::module &);
void bind_TObj_DataMapOfNameLabel(py::module &);
void bind_TObj_DataMapOfObjectHSequenceOcafObjects(py::module &);
void bind_TObj_DataMapOfStringPointer(py::module &);
void bind_TObj_Persistence(py::module &);
void bind_TObj_Partition(py::module &);
void bind_TObj_Model(py::module &);
void bind_TObj_CheckModel(py::module &);
void bind_TObj_HiddenPartition(py::module &);
void bind_TObj_ObjectIterator(py::module &);
void bind_TObj_LabelIterator(py::module &);
void bind_TObj_SequenceOfIterator(py::module &);
void bind_TObj_ModelIterator(py::module &);
void bind_TObj_OcafObjectIterator(py::module &);
void bind_TObj_ReferenceIterator(py::module &);
void bind_TObj_SequenceIterator(py::module &);
void bind_TObj_TIntSparseArray_VecOfData(py::module &);
void bind_TObj_TIntSparseArray_MapOfData(py::module &);
void bind_TObj_TIntSparseArray(py::module &);
void bind_TObj_TModel(py::module &);
void bind_TObj_TNameContainer(py::module &);
void bind_TObj_TObject(py::module &);
void bind_TObj_TReference(py::module &);
void bind_TObj_TXYZ(py::module &);

PYBIND11_MODULE(TObj, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.TDocStd");
py::module::import("OCCT.Message");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.TDF");
py::module::import("OCCT.gp");

bind_HashCode(mod);
bind_IsEqual(mod);
bind_TObj_Application(mod);
bind_TObj_Assistant(mod);
bind_TObj_DeletingMode(mod);
bind_TObj_SequenceOfObject(mod);
bind_TObj_HSequenceOfObject(mod);
bind_TObj_Object(mod);
bind_TObj_DataMapOfNameLabel(mod);
bind_TObj_DataMapOfObjectHSequenceOcafObjects(mod);
bind_TObj_DataMapOfStringPointer(mod);
bind_TObj_Persistence(mod);
bind_TObj_Partition(mod);
bind_TObj_Model(mod);
bind_TObj_CheckModel(mod);
bind_TObj_HiddenPartition(mod);
bind_TObj_ObjectIterator(mod);
bind_TObj_LabelIterator(mod);
bind_TObj_SequenceOfIterator(mod);
bind_TObj_ModelIterator(mod);
bind_TObj_OcafObjectIterator(mod);
bind_TObj_ReferenceIterator(mod);
bind_TObj_SequenceIterator(mod);
bind_TObj_TIntSparseArray_VecOfData(mod);
bind_TObj_TIntSparseArray_MapOfData(mod);
bind_TObj_TIntSparseArray(mod);
bind_TObj_TModel(mod);
bind_TObj_TNameContainer(mod);
bind_TObj_TObject(mod);
bind_TObj_TReference(mod);
bind_TObj_TXYZ(mod);

}
