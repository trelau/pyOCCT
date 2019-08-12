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
#include <TDataXtd_Placement.hxx>
#include <TDF_Label.hxx>
#include <TDF_RelocationTable.hxx>
#include <Standard_OStream.hxx>
#include <Standard_Type.hxx>

void bind_TDataXtd_Placement(py::module &mod){

py::class_<TDataXtd_Placement, opencascade::handle<TDataXtd_Placement>, TDF_Attribute> cls_TDataXtd_Placement(mod, "TDataXtd_Placement", "None");

// Constructors
cls_TDataXtd_Placement.def(py::init<>());

// Fields

// Methods
cls_TDataXtd_Placement.def_static("GetID_", (const Standard_GUID & (*)()) &TDataXtd_Placement::GetID, "class methods =============");
cls_TDataXtd_Placement.def_static("Set_", (opencascade::handle<TDataXtd_Placement> (*)(const TDF_Label &)) &TDataXtd_Placement::Set, "Find, or create, an Placement attribute. the Placement attribute is returned. Placement methods =================", py::arg("label"));
cls_TDataXtd_Placement.def("ID", (const Standard_GUID & (TDataXtd_Placement::*)() const) &TDataXtd_Placement::ID, "None");
cls_TDataXtd_Placement.def("Restore", (void (TDataXtd_Placement::*)(const opencascade::handle<TDF_Attribute> &)) &TDataXtd_Placement::Restore, "None", py::arg("With"));
cls_TDataXtd_Placement.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TDataXtd_Placement::*)() const) &TDataXtd_Placement::NewEmpty, "None");
cls_TDataXtd_Placement.def("Paste", (void (TDataXtd_Placement::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TDataXtd_Placement::Paste, "None", py::arg("Into"), py::arg("RT"));
cls_TDataXtd_Placement.def("Dump", (Standard_OStream & (TDataXtd_Placement::*)(Standard_OStream &) const) &TDataXtd_Placement::Dump, "None", py::arg("anOS"));
cls_TDataXtd_Placement.def_static("get_type_name_", (const char * (*)()) &TDataXtd_Placement::get_type_name, "None");
cls_TDataXtd_Placement.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDataXtd_Placement::get_type_descriptor, "None");
cls_TDataXtd_Placement.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDataXtd_Placement::*)() const) &TDataXtd_Placement::DynamicType, "None");

// Enums

}