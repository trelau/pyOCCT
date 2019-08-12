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
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <CDF_Directory.hxx>
#include <Standard_TypeDef.hxx>
#include <CDM_Document.hxx>
#include <CDM_ListOfDocument.hxx>
#include <CDF_DirectoryIterator.hxx>

void bind_CDF_DirectoryIterator(py::module &mod){

py::class_<CDF_DirectoryIterator, std::unique_ptr<CDF_DirectoryIterator, Deleter<CDF_DirectoryIterator>>> cls_CDF_DirectoryIterator(mod, "CDF_DirectoryIterator", "None");

// Constructors
cls_CDF_DirectoryIterator.def(py::init<>());
cls_CDF_DirectoryIterator.def(py::init<const opencascade::handle<CDF_Directory> &>(), py::arg("aDirectory"));

// Fields

// Methods
// cls_CDF_DirectoryIterator.def_static("operator new_", (void * (*)(size_t)) &CDF_DirectoryIterator::operator new, "None", py::arg("theSize"));
// cls_CDF_DirectoryIterator.def_static("operator delete_", (void (*)(void *)) &CDF_DirectoryIterator::operator delete, "None", py::arg("theAddress"));
// cls_CDF_DirectoryIterator.def_static("operator new[]_", (void * (*)(size_t)) &CDF_DirectoryIterator::operator new[], "None", py::arg("theSize"));
// cls_CDF_DirectoryIterator.def_static("operator delete[]_", (void (*)(void *)) &CDF_DirectoryIterator::operator delete[], "None", py::arg("theAddress"));
// cls_CDF_DirectoryIterator.def_static("operator new_", (void * (*)(size_t, void *)) &CDF_DirectoryIterator::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_CDF_DirectoryIterator.def_static("operator delete_", (void (*)(void *, void *)) &CDF_DirectoryIterator::operator delete, "None", py::arg(""), py::arg(""));
cls_CDF_DirectoryIterator.def("MoreDocument", (Standard_Boolean (CDF_DirectoryIterator::*)()) &CDF_DirectoryIterator::MoreDocument, "Returns True if there are more entries to return");
cls_CDF_DirectoryIterator.def("NextDocument", (void (CDF_DirectoryIterator::*)()) &CDF_DirectoryIterator::NextDocument, "Go to the next entry (if there is not, Value will raise an exception)");
cls_CDF_DirectoryIterator.def("Document", (opencascade::handle<CDM_Document> (CDF_DirectoryIterator::*)()) &CDF_DirectoryIterator::Document, "Returns item value of current entry");

// Enums

}