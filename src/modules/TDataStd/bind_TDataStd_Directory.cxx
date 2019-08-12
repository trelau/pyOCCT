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
#include <TDataStd_Directory.hxx>
#include <Standard_GUID.hxx>
#include <TDF_RelocationTable.hxx>
#include <TDF_DataSet.hxx>
#include <Standard_OStream.hxx>
#include <Standard_Type.hxx>

void bind_TDataStd_Directory(py::module &mod){

py::class_<TDataStd_Directory, opencascade::handle<TDataStd_Directory>, TDF_Attribute> cls_TDataStd_Directory(mod, "TDataStd_Directory", "Associates a directory in the data framework with a TDataStd_TagSource attribute. You can create a new directory label and add sub-directory or object labels to it,");

// Constructors
cls_TDataStd_Directory.def(py::init<>());

// Fields

// Methods
cls_TDataStd_Directory.def_static("Find_", (Standard_Boolean (*)(const TDF_Label &, opencascade::handle<TDataStd_Directory> &)) &TDataStd_Directory::Find, "class methods ============= Searches for a directory attribute on the label current, or on one of the father labels of current. If a directory attribute is found, true is returned, and the attribute found is set as D.", py::arg("current"), py::arg("D"));
cls_TDataStd_Directory.def_static("New_", (opencascade::handle<TDataStd_Directory> (*)(const TDF_Label &)) &TDataStd_Directory::New, "Creates an enpty Directory attribute, located at <label>. Raises if <label> has attribute", py::arg("label"));
cls_TDataStd_Directory.def_static("AddDirectory_", (opencascade::handle<TDataStd_Directory> (*)(const opencascade::handle<TDataStd_Directory> &)) &TDataStd_Directory::AddDirectory, "Creates a new sub-label and sets the sub-directory dir on that label.", py::arg("dir"));
cls_TDataStd_Directory.def_static("MakeObjectLabel_", (TDF_Label (*)(const opencascade::handle<TDataStd_Directory> &)) &TDataStd_Directory::MakeObjectLabel, "Makes new label and returns it to insert other object attributes (sketch,part...etc...)", py::arg("dir"));
cls_TDataStd_Directory.def_static("GetID_", (const Standard_GUID & (*)()) &TDataStd_Directory::GetID, "Directory methods ===============");
cls_TDataStd_Directory.def("ID", (const Standard_GUID & (TDataStd_Directory::*)() const) &TDataStd_Directory::ID, "None");
cls_TDataStd_Directory.def("Restore", (void (TDataStd_Directory::*)(const opencascade::handle<TDF_Attribute> &)) &TDataStd_Directory::Restore, "None", py::arg("with"));
cls_TDataStd_Directory.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TDataStd_Directory::*)() const) &TDataStd_Directory::NewEmpty, "None");
cls_TDataStd_Directory.def("Paste", (void (TDataStd_Directory::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TDataStd_Directory::Paste, "None", py::arg("into"), py::arg("RT"));
cls_TDataStd_Directory.def("References", (void (TDataStd_Directory::*)(const opencascade::handle<TDF_DataSet> &) const) &TDataStd_Directory::References, "None", py::arg("DS"));
cls_TDataStd_Directory.def("Dump", (Standard_OStream & (TDataStd_Directory::*)(Standard_OStream &) const) &TDataStd_Directory::Dump, "None", py::arg("anOS"));
cls_TDataStd_Directory.def_static("get_type_name_", (const char * (*)()) &TDataStd_Directory::get_type_name, "None");
cls_TDataStd_Directory.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDataStd_Directory::get_type_descriptor, "None");
cls_TDataStd_Directory.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDataStd_Directory::*)() const) &TDataStd_Directory::DynamicType, "None");

// Enums

}