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
#include <Standard_Handle.hxx>
#include <TDataStd_UAttribute.hxx>
#include <TDF_Label.hxx>
#include <Standard_GUID.hxx>
#include <TDF_RelocationTable.hxx>
#include <TDF_DataSet.hxx>
#include <Standard_OStream.hxx>
#include <Standard_Type.hxx>

void bind_TDataStd_UAttribute(py::module &mod){

py::class_<TDataStd_UAttribute, opencascade::handle<TDataStd_UAttribute>, TDF_Attribute> cls_TDataStd_UAttribute(mod, "TDataStd_UAttribute", "None");

// Constructors
cls_TDataStd_UAttribute.def(py::init<>());

// Fields

// Methods
cls_TDataStd_UAttribute.def_static("Set_", (opencascade::handle<TDataStd_UAttribute> (*)(const TDF_Label &, const Standard_GUID &)) &TDataStd_UAttribute::Set, "api class methods ============= Find, or create, a UAttribute attribute with <LocalID> as Local GUID. The UAttribute attribute is returned. UAttribute methods ============", py::arg("label"), py::arg("LocalID"));
cls_TDataStd_UAttribute.def("SetID", (void (TDataStd_UAttribute::*)(const Standard_GUID &)) &TDataStd_UAttribute::SetID, "None", py::arg("LocalID"));
cls_TDataStd_UAttribute.def("ID", (const Standard_GUID & (TDataStd_UAttribute::*)() const) &TDataStd_UAttribute::ID, "None");
cls_TDataStd_UAttribute.def("Restore", (void (TDataStd_UAttribute::*)(const opencascade::handle<TDF_Attribute> &)) &TDataStd_UAttribute::Restore, "None", py::arg("with"));
cls_TDataStd_UAttribute.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TDataStd_UAttribute::*)() const) &TDataStd_UAttribute::NewEmpty, "None");
cls_TDataStd_UAttribute.def("Paste", (void (TDataStd_UAttribute::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TDataStd_UAttribute::Paste, "None", py::arg("into"), py::arg("RT"));
cls_TDataStd_UAttribute.def("References", (void (TDataStd_UAttribute::*)(const opencascade::handle<TDF_DataSet> &) const) &TDataStd_UAttribute::References, "None", py::arg("DS"));
cls_TDataStd_UAttribute.def("Dump", (Standard_OStream & (TDataStd_UAttribute::*)(Standard_OStream &) const) &TDataStd_UAttribute::Dump, "None", py::arg("anOS"));
cls_TDataStd_UAttribute.def_static("get_type_name_", (const char * (*)()) &TDataStd_UAttribute::get_type_name, "None");
cls_TDataStd_UAttribute.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDataStd_UAttribute::get_type_descriptor, "None");
cls_TDataStd_UAttribute.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDataStd_UAttribute::*)() const) &TDataStd_UAttribute::DynamicType, "None");

// Enums

}