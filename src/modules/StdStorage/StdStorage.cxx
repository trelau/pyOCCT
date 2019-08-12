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

void bind_StdStorage(py::module &);
void bind_StdStorage_Bucket(py::module &);
void bind_StdStorage_BucketOfPersistent(py::module &);
void bind_StdStorage_BucketIterator(py::module &);
void bind_StdStorage_Data(py::module &);
void bind_StdStorage_HeaderData(py::module &);
void bind_StdStorage_Root(py::module &);
void bind_StdStorage_SequenceOfRoots(py::module &);
void bind_StdStorage_HSequenceOfRoots(py::module &);
void bind_StdStorage_MapOfRoots(py::module &);
void bind_StdStorage_DataMapIteratorOfMapOfRoots(py::module &);
void bind_StdStorage_MapOfTypes(py::module &);
void bind_StdStorage_RootData(py::module &);
void bind_StdStorage_TypeData(py::module &);

PYBIND11_MODULE(StdStorage, mod) {

py::module::import("OCCT.TCollection");
py::module::import("OCCT.Storage");
py::module::import("OCCT.Standard");
py::module::import("OCCT.StdObjMgt");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.NCollection");

bind_StdStorage(mod);
bind_StdStorage_Bucket(mod);
bind_StdStorage_BucketOfPersistent(mod);
bind_StdStorage_BucketIterator(mod);
bind_StdStorage_Data(mod);
bind_StdStorage_HeaderData(mod);
bind_StdStorage_Root(mod);
bind_StdStorage_SequenceOfRoots(mod);
bind_StdStorage_HSequenceOfRoots(mod);
bind_StdStorage_MapOfRoots(mod);
bind_StdStorage_DataMapIteratorOfMapOfRoots(mod);
bind_StdStorage_MapOfTypes(mod);
bind_StdStorage_RootData(mod);
bind_StdStorage_TypeData(mod);

}
