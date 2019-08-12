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

void bind_PCDM_ReaderStatus(py::module &);
void bind_PCDM_StoreStatus(py::module &);
void bind_PCDM_TypeOfFileDriver(py::module &);
void bind_PCDM_Reader(py::module &);
void bind_PCDM_Reference(py::module &);
void bind_PCDM_SequenceOfReference(py::module &);
void bind_PCDM_ReferenceIterator(py::module &);
void bind_PCDM_RetrievalDriver(py::module &);
void bind_PCDM_Writer(py::module &);
void bind_PCDM_Document(py::module &);
void bind_PCDM_SequenceOfDocument(py::module &);
void bind_PCDM_StorageDriver(py::module &);
void bind_PCDM_BaseDriverPointer(py::module &);
void bind_PCDM(py::module &);
void bind_PCDM_DOMHeaderParser(py::module &);
void bind_PCDM_DriverError(py::module &);
void bind_PCDM_ReadWriter(py::module &);
void bind_PCDM_ReadWriter_1(py::module &);

PYBIND11_MODULE(PCDM, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.CDM");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.Storage");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.Message");
py::module::import("OCCT.LDOMParser");
py::module::import("OCCT.LDOM");
py::module::import("OCCT.LDOMString");
py::module::import("OCCT.TColStd");

bind_PCDM_ReaderStatus(mod);
bind_PCDM_StoreStatus(mod);
bind_PCDM_TypeOfFileDriver(mod);
bind_PCDM_Reader(mod);
bind_PCDM_Reference(mod);
bind_PCDM_SequenceOfReference(mod);
bind_PCDM_ReferenceIterator(mod);
bind_PCDM_RetrievalDriver(mod);
bind_PCDM_Writer(mod);
bind_PCDM_Document(mod);
bind_PCDM_SequenceOfDocument(mod);
bind_PCDM_StorageDriver(mod);
bind_PCDM_BaseDriverPointer(mod);
bind_PCDM(mod);
bind_PCDM_DOMHeaderParser(mod);
bind_PCDM_DriverError(mod);
bind_PCDM_ReadWriter(mod);
bind_PCDM_ReadWriter_1(mod);

}
