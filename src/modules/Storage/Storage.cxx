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

void bind_Storage_Error(py::module &);
void bind_Storage_OpenMode(py::module &);
void bind_Storage_SolveMode(py::module &);
void bind_Storage_HeaderData(py::module &);
void bind_Storage_Root(py::module &);
void bind_Storage_SeqOfRoot(py::module &);
void bind_Storage_HSeqOfRoot(py::module &);
void bind_Storage_Data(py::module &);
void bind_Storage_Position(py::module &);
void bind_Storage_BaseDriver(py::module &);
void bind_Storage(py::module &);
void bind_Storage_CallBack(py::module &);
void bind_Storage_ArrayOfCallBack(py::module &);
void bind_Storage_ArrayOfSchema(py::module &);
void bind_Storage_Bucket(py::module &);
void bind_Storage_BucketOfPersistent(py::module &);
void bind_Storage_BucketIterator(py::module &);
void bind_Storage_TypedCallBack(py::module &);
void bind_Storage_MapOfCallBack(py::module &);
void bind_Storage_DataMapIteratorOfMapOfCallBack(py::module &);
void bind_Storage_MapOfPers(py::module &);
void bind_Storage_DataMapIteratorOfMapOfPers(py::module &);
void bind_Storage_DefaultCallBack(py::module &);
void bind_Storage_HArrayOfCallBack(py::module &);
void bind_Storage_Schema(py::module &);
void bind_Storage_PArray(py::module &);
void bind_Storage_HPArray(py::module &);
void bind_Storage_InternalData(py::module &);
void bind_Storage_HArrayOfSchema(py::module &);
void bind_Storage_PType(py::module &);
void bind_Storage_RootData(py::module &);
void bind_Storage_StreamReadError(py::module &);
void bind_Storage_StreamExtCharParityError(py::module &);
void bind_Storage_StreamFormatError(py::module &);
void bind_Storage_StreamModeError(py::module &);
void bind_Storage_StreamTypeMismatchError(py::module &);
void bind_Storage_StreamUnknownTypeError(py::module &);
void bind_Storage_StreamWriteError(py::module &);
void bind_Storage_TypeData(py::module &);

PYBIND11_MODULE(Storage, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.NCollection");

bind_Storage_Error(mod);
bind_Storage_OpenMode(mod);
bind_Storage_SolveMode(mod);
bind_Storage_HeaderData(mod);
bind_Storage_Root(mod);
bind_Storage_SeqOfRoot(mod);
bind_Storage_HSeqOfRoot(mod);
bind_Storage_Data(mod);
bind_Storage_Position(mod);
bind_Storage_BaseDriver(mod);
bind_Storage(mod);
bind_Storage_CallBack(mod);
bind_Storage_ArrayOfCallBack(mod);
bind_Storage_ArrayOfSchema(mod);
bind_Storage_Bucket(mod);
bind_Storage_BucketOfPersistent(mod);
bind_Storage_BucketIterator(mod);
bind_Storage_TypedCallBack(mod);
bind_Storage_MapOfCallBack(mod);
bind_Storage_DataMapIteratorOfMapOfCallBack(mod);
bind_Storage_MapOfPers(mod);
bind_Storage_DataMapIteratorOfMapOfPers(mod);
bind_Storage_DefaultCallBack(mod);
bind_Storage_HArrayOfCallBack(mod);
bind_Storage_Schema(mod);
bind_Storage_PArray(mod);
bind_Storage_HPArray(mod);
bind_Storage_InternalData(mod);
bind_Storage_HArrayOfSchema(mod);
bind_Storage_PType(mod);
bind_Storage_RootData(mod);
bind_Storage_StreamReadError(mod);
bind_Storage_StreamExtCharParityError(mod);
bind_Storage_StreamFormatError(mod);
bind_Storage_StreamModeError(mod);
bind_Storage_StreamTypeMismatchError(mod);
bind_Storage_StreamUnknownTypeError(mod);
bind_Storage_StreamWriteError(mod);
bind_Storage_TypeData(mod);

}
