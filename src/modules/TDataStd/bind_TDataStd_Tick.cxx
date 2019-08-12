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
#include <TDataStd_Tick.hxx>
#include <TDF_Label.hxx>
#include <TDF_RelocationTable.hxx>
#include <Standard_OStream.hxx>
#include <Standard_Type.hxx>

void bind_TDataStd_Tick(py::module &mod){

py::class_<TDataStd_Tick, opencascade::handle<TDataStd_Tick>, TDF_Attribute> cls_TDataStd_Tick(mod, "TDataStd_Tick", "Defines a boolean attribute. If it exists at a label - true, Otherwise - false.");

// Constructors
cls_TDataStd_Tick.def(py::init<>());

// Fields

// Methods
cls_TDataStd_Tick.def_static("GetID_", (const Standard_GUID & (*)()) &TDataStd_Tick::GetID, "Static methods ==============");
cls_TDataStd_Tick.def_static("Set_", (opencascade::handle<TDataStd_Tick> (*)(const TDF_Label &)) &TDataStd_Tick::Set, "Find, or create, a Tick attribute. Tick methods ============", py::arg("label"));
cls_TDataStd_Tick.def("ID", (const Standard_GUID & (TDataStd_Tick::*)() const) &TDataStd_Tick::ID, "None");
cls_TDataStd_Tick.def("Restore", (void (TDataStd_Tick::*)(const opencascade::handle<TDF_Attribute> &)) &TDataStd_Tick::Restore, "None", py::arg("With"));
cls_TDataStd_Tick.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TDataStd_Tick::*)() const) &TDataStd_Tick::NewEmpty, "None");
cls_TDataStd_Tick.def("Paste", (void (TDataStd_Tick::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TDataStd_Tick::Paste, "None", py::arg("Into"), py::arg("RT"));
cls_TDataStd_Tick.def("Dump", (Standard_OStream & (TDataStd_Tick::*)(Standard_OStream &) const) &TDataStd_Tick::Dump, "None", py::arg("anOS"));
cls_TDataStd_Tick.def_static("get_type_name_", (const char * (*)()) &TDataStd_Tick::get_type_name, "None");
cls_TDataStd_Tick.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDataStd_Tick::get_type_descriptor, "None");
cls_TDataStd_Tick.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDataStd_Tick::*)() const) &TDataStd_Tick::DynamicType, "None");

// Enums

}