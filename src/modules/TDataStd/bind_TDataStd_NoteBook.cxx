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
#include <TDF_Attribute.hxx>
#include <Standard_TypeDef.hxx>
#include <TDF_Label.hxx>
#include <Standard_Handle.hxx>
#include <TDataStd_NoteBook.hxx>
#include <Standard_GUID.hxx>
#include <TDataStd_Real.hxx>
#include <TDataStd_Integer.hxx>
#include <TDF_RelocationTable.hxx>
#include <Standard_OStream.hxx>
#include <Standard_Type.hxx>

void bind_TDataStd_NoteBook(py::module &mod){

py::class_<TDataStd_NoteBook, opencascade::handle<TDataStd_NoteBook>, TDF_Attribute> cls_TDataStd_NoteBook(mod, "TDataStd_NoteBook", "NoteBook Object attribute");

// Constructors
cls_TDataStd_NoteBook.def(py::init<>());

// Fields

// Methods
cls_TDataStd_NoteBook.def_static("Find_", (Standard_Boolean (*)(const TDF_Label &, opencascade::handle<TDataStd_NoteBook> &)) &TDataStd_NoteBook::Find, "class methods ============= try to retrieve a NoteBook attribute at <current> label or in fathers label of <current>. Returns True if found and set <N>.", py::arg("current"), py::arg("N"));
cls_TDataStd_NoteBook.def_static("New_", (opencascade::handle<TDataStd_NoteBook> (*)(const TDF_Label &)) &TDataStd_NoteBook::New, "Create an enpty NoteBook attribute, located at <label>. Raises if <label> has attribute", py::arg("label"));
cls_TDataStd_NoteBook.def_static("GetID_", (const Standard_GUID & (*)()) &TDataStd_NoteBook::GetID, "NoteBook methods ===============");
cls_TDataStd_NoteBook.def("Append", [](TDataStd_NoteBook &self, const Standard_Real a0) -> opencascade::handle<TDataStd_Real> { return self.Append(a0); });
cls_TDataStd_NoteBook.def("Append", (opencascade::handle<TDataStd_Real> (TDataStd_NoteBook::*)(const Standard_Real, const Standard_Boolean)) &TDataStd_NoteBook::Append, "Tool to Create an Integer attribute from <value>, Insert it in a new son label of <me>. The Real attribute is returned.", py::arg("value"), py::arg("isExported"));
cls_TDataStd_NoteBook.def("Append", [](TDataStd_NoteBook &self, const Standard_Integer a0) -> opencascade::handle<TDataStd_Integer> { return self.Append(a0); });
cls_TDataStd_NoteBook.def("Append", (opencascade::handle<TDataStd_Integer> (TDataStd_NoteBook::*)(const Standard_Integer, const Standard_Boolean)) &TDataStd_NoteBook::Append, "Tool to Create an Real attribute from <value>, Insert it in a new son label of <me>. The Integer attribute is returned.", py::arg("value"), py::arg("isExported"));
cls_TDataStd_NoteBook.def("ID", (const Standard_GUID & (TDataStd_NoteBook::*)() const) &TDataStd_NoteBook::ID, "None");
cls_TDataStd_NoteBook.def("Restore", (void (TDataStd_NoteBook::*)(const opencascade::handle<TDF_Attribute> &)) &TDataStd_NoteBook::Restore, "None", py::arg("with"));
cls_TDataStd_NoteBook.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TDataStd_NoteBook::*)() const) &TDataStd_NoteBook::NewEmpty, "None");
cls_TDataStd_NoteBook.def("Paste", (void (TDataStd_NoteBook::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TDataStd_NoteBook::Paste, "None", py::arg("into"), py::arg("RT"));
cls_TDataStd_NoteBook.def("Dump", (Standard_OStream & (TDataStd_NoteBook::*)(Standard_OStream &) const) &TDataStd_NoteBook::Dump, "None", py::arg("anOS"));
cls_TDataStd_NoteBook.def_static("get_type_name_", (const char * (*)()) &TDataStd_NoteBook::get_type_name, "None");
cls_TDataStd_NoteBook.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDataStd_NoteBook::get_type_descriptor, "None");
cls_TDataStd_NoteBook.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDataStd_NoteBook::*)() const) &TDataStd_NoteBook::DynamicType, "None");

// Enums

}