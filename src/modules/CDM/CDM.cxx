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

void bind_CDM_CanCloseStatus(py::module &);
void bind_CDM_Application(py::module &);
void bind_CDM_DocumentPointer(py::module &);
void bind_CDM_Reference(py::module &);
void bind_CDM_ListOfReferences(py::module &);
void bind_CDM_ListIteratorOfListOfReferences(py::module &);
void bind_CDM_Document(py::module &);
void bind_CDM_ListOfDocument(py::module &);
void bind_CDM_ListIteratorOfListOfDocument(py::module &);
void bind_CDM_DocumentHasher(py::module &);
void bind_CDM_MapOfDocument(py::module &);
void bind_CDM_MapIteratorOfMapOfDocument(py::module &);
void bind_CDM_MetaDataLookUpTable(py::module &);
void bind_CDM_DataMapIteratorOfMetaDataLookUpTable(py::module &);
void bind_CDM_PresentationDirectory(py::module &);
void bind_CDM_DataMapIteratorOfPresentationDirectory(py::module &);
void bind_CDM_MetaData(py::module &);
void bind_CDM_NamesDirectory(py::module &);
void bind_CDM_ReferenceIterator(py::module &);

PYBIND11_MODULE(CDM, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.Resource");
py::module::import("OCCT.Message");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.TColStd");

bind_CDM_CanCloseStatus(mod);
bind_CDM_Application(mod);
bind_CDM_DocumentPointer(mod);
bind_CDM_Reference(mod);
bind_CDM_ListOfReferences(mod);
bind_CDM_ListIteratorOfListOfReferences(mod);
bind_CDM_Document(mod);
bind_CDM_ListOfDocument(mod);
bind_CDM_ListIteratorOfListOfDocument(mod);
bind_CDM_DocumentHasher(mod);
bind_CDM_MapOfDocument(mod);
bind_CDM_MapIteratorOfMapOfDocument(mod);
bind_CDM_MetaDataLookUpTable(mod);
bind_CDM_DataMapIteratorOfMetaDataLookUpTable(mod);
bind_CDM_PresentationDirectory(mod);
bind_CDM_DataMapIteratorOfPresentationDirectory(mod);
bind_CDM_MetaData(mod);
bind_CDM_NamesDirectory(mod);
bind_CDM_ReferenceIterator(mod);

}
