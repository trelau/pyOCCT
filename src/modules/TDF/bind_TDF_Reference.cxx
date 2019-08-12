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
#include <Standard_GUID.hxx>
#include <Standard_Handle.hxx>
#include <TDF_Reference.hxx>
#include <TDF_Label.hxx>
#include <TDF_RelocationTable.hxx>
#include <TDF_DataSet.hxx>
#include <Standard_OStream.hxx>
#include <Standard_Type.hxx>

void bind_TDF_Reference(py::module &mod){

py::class_<TDF_Reference, opencascade::handle<TDF_Reference>, TDF_Attribute> cls_TDF_Reference(mod, "TDF_Reference", "This attribute is used to store in the framework a reference to an other label.");

// Constructors
cls_TDF_Reference.def(py::init<>());

// Fields

// Methods
cls_TDF_Reference.def_static("GetID_", (const Standard_GUID & (*)()) &TDF_Reference::GetID, "None");
cls_TDF_Reference.def_static("Set_", (opencascade::handle<TDF_Reference> (*)(const TDF_Label &, const TDF_Label &)) &TDF_Reference::Set, "None", py::arg("I"), py::arg("Origin"));
cls_TDF_Reference.def("Set", (void (TDF_Reference::*)(const TDF_Label &)) &TDF_Reference::Set, "None", py::arg("Origin"));
cls_TDF_Reference.def("Get", (TDF_Label (TDF_Reference::*)() const) &TDF_Reference::Get, "None");
cls_TDF_Reference.def("ID", (const Standard_GUID & (TDF_Reference::*)() const) &TDF_Reference::ID, "None");
cls_TDF_Reference.def("Restore", (void (TDF_Reference::*)(const opencascade::handle<TDF_Attribute> &)) &TDF_Reference::Restore, "None", py::arg("With"));
cls_TDF_Reference.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TDF_Reference::*)() const) &TDF_Reference::NewEmpty, "None");
cls_TDF_Reference.def("Paste", (void (TDF_Reference::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TDF_Reference::Paste, "None", py::arg("Into"), py::arg("RT"));
cls_TDF_Reference.def("References", (void (TDF_Reference::*)(const opencascade::handle<TDF_DataSet> &) const) &TDF_Reference::References, "None", py::arg("DS"));
cls_TDF_Reference.def("Dump", (Standard_OStream & (TDF_Reference::*)(Standard_OStream &) const) &TDF_Reference::Dump, "None", py::arg("anOS"));
cls_TDF_Reference.def_static("get_type_name_", (const char * (*)()) &TDF_Reference::get_type_name, "None");
cls_TDF_Reference.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDF_Reference::get_type_descriptor, "None");
cls_TDF_Reference.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDF_Reference::*)() const) &TDF_Reference::DynamicType, "None");

// Enums

}