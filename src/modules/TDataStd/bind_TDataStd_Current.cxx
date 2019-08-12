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
#include <TDF_Label.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <TDF_RelocationTable.hxx>
#include <Standard_OStream.hxx>
#include <TDataStd_Current.hxx>
#include <Standard_Type.hxx>

void bind_TDataStd_Current(py::module &mod){

py::class_<TDataStd_Current, opencascade::handle<TDataStd_Current>, TDF_Attribute> cls_TDataStd_Current(mod, "TDataStd_Current", "this attribute, located at root label, manage an access to a current label.");

// Constructors
cls_TDataStd_Current.def(py::init<>());

// Fields

// Methods
cls_TDataStd_Current.def_static("GetID_", (const Standard_GUID & (*)()) &TDataStd_Current::GetID, "class methods =============");
cls_TDataStd_Current.def_static("Set_", (void (*)(const TDF_Label &)) &TDataStd_Current::Set, "Set <L> as current of <L> Framework.", py::arg("L"));
cls_TDataStd_Current.def_static("Get_", (TDF_Label (*)(const TDF_Label &)) &TDataStd_Current::Get, "returns current of <acces> Framework. raise if (!Has)", py::arg("acces"));
cls_TDataStd_Current.def_static("Has_", (Standard_Boolean (*)(const TDF_Label &)) &TDataStd_Current::Has, "returns True if a current label is managed in <acces> Framework. class methods =============", py::arg("acces"));
cls_TDataStd_Current.def("SetLabel", (void (TDataStd_Current::*)(const TDF_Label &)) &TDataStd_Current::SetLabel, "None", py::arg("current"));
cls_TDataStd_Current.def("GetLabel", (TDF_Label (TDataStd_Current::*)() const) &TDataStd_Current::GetLabel, "None");
cls_TDataStd_Current.def("ID", (const Standard_GUID & (TDataStd_Current::*)() const) &TDataStd_Current::ID, "None");
cls_TDataStd_Current.def("Restore", (void (TDataStd_Current::*)(const opencascade::handle<TDF_Attribute> &)) &TDataStd_Current::Restore, "None", py::arg("With"));
cls_TDataStd_Current.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TDataStd_Current::*)() const) &TDataStd_Current::NewEmpty, "None");
cls_TDataStd_Current.def("Paste", (void (TDataStd_Current::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TDataStd_Current::Paste, "None", py::arg("Into"), py::arg("RT"));
cls_TDataStd_Current.def("Dump", (Standard_OStream & (TDataStd_Current::*)(Standard_OStream &) const) &TDataStd_Current::Dump, "None", py::arg("anOS"));
cls_TDataStd_Current.def_static("get_type_name_", (const char * (*)()) &TDataStd_Current::get_type_name, "None");
cls_TDataStd_Current.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDataStd_Current::get_type_descriptor, "None");
cls_TDataStd_Current.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDataStd_Current::*)() const) &TDataStd_Current::DynamicType, "None");

// Enums

}