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
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <CDM_Document.hxx>
#include <Standard_TypeDef.hxx>
#include <CDF_DirectoryIterator.hxx>
#include <CDF_Directory.hxx>
#include <Standard_Type.hxx>
#include <CDM_ListOfDocument.hxx>

void bind_CDF_Directory(py::module &mod){

py::class_<CDF_Directory, opencascade::handle<CDF_Directory>, Standard_Transient> cls_CDF_Directory(mod, "CDF_Directory", "A directory is a collection of documents. There is only one instance of a given document in a directory. put.");

// Constructors
cls_CDF_Directory.def(py::init<>());

// Fields

// Methods
cls_CDF_Directory.def("Add", (void (CDF_Directory::*)(const opencascade::handle<CDM_Document> &)) &CDF_Directory::Add, "adds a document into the directory.", py::arg("aDocument"));
cls_CDF_Directory.def("Remove", (void (CDF_Directory::*)(const opencascade::handle<CDM_Document> &)) &CDF_Directory::Remove, "removes the document.", py::arg("aDocument"));
cls_CDF_Directory.def("Contains", (Standard_Boolean (CDF_Directory::*)(const opencascade::handle<CDM_Document> &) const) &CDF_Directory::Contains, "Returns true if the document aDocument is in the directory", py::arg("aDocument"));
cls_CDF_Directory.def("Last", (opencascade::handle<CDM_Document> (CDF_Directory::*)()) &CDF_Directory::Last, "returns the last document (if any) which has been added in the directory.");
cls_CDF_Directory.def("Length", (Standard_Integer (CDF_Directory::*)() const) &CDF_Directory::Length, "returns the number of documents of the directory.");
cls_CDF_Directory.def("IsEmpty", (Standard_Boolean (CDF_Directory::*)() const) &CDF_Directory::IsEmpty, "returns true if the directory is empty.");
cls_CDF_Directory.def_static("get_type_name_", (const char * (*)()) &CDF_Directory::get_type_name, "None");
cls_CDF_Directory.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &CDF_Directory::get_type_descriptor, "None");
cls_CDF_Directory.def("DynamicType", (const opencascade::handle<Standard_Type> & (CDF_Directory::*)() const) &CDF_Directory::DynamicType, "None");

// Enums

}