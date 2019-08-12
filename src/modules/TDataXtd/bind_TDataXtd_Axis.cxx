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
#include <TDataXtd_Axis.hxx>
#include <TDF_Label.hxx>
#include <gp_Lin.hxx>
#include <TDF_RelocationTable.hxx>
#include <Standard_OStream.hxx>
#include <Standard_Type.hxx>

void bind_TDataXtd_Axis(py::module &mod){

py::class_<TDataXtd_Axis, opencascade::handle<TDataXtd_Axis>, TDF_Attribute> cls_TDataXtd_Axis(mod, "TDataXtd_Axis", "The basis to define an axis attribute.");

// Constructors
cls_TDataXtd_Axis.def(py::init<>());

// Fields

// Methods
cls_TDataXtd_Axis.def_static("GetID_", (const Standard_GUID & (*)()) &TDataXtd_Axis::GetID, "class methods ============= Returns the GUID for an axis.");
cls_TDataXtd_Axis.def_static("Set_", (opencascade::handle<TDataXtd_Axis> (*)(const TDF_Label &)) &TDataXtd_Axis::Set, "Finds or creates an axis attribute defined by the label. In the case of a creation of an axis, a compatible named shape should already be associated with label. Exceptions Standard_NullObject if no compatible named shape is associated with the label.", py::arg("label"));
cls_TDataXtd_Axis.def_static("Set_", (opencascade::handle<TDataXtd_Axis> (*)(const TDF_Label &, const gp_Lin &)) &TDataXtd_Axis::Set, "Find, or create, an Axis attribute and set <P> as generated in the associated NamedShape. Axis methods ============", py::arg("label"), py::arg("L"));
cls_TDataXtd_Axis.def("ID", (const Standard_GUID & (TDataXtd_Axis::*)() const) &TDataXtd_Axis::ID, "None");
cls_TDataXtd_Axis.def("Restore", (void (TDataXtd_Axis::*)(const opencascade::handle<TDF_Attribute> &)) &TDataXtd_Axis::Restore, "None", py::arg("with"));
cls_TDataXtd_Axis.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TDataXtd_Axis::*)() const) &TDataXtd_Axis::NewEmpty, "None");
cls_TDataXtd_Axis.def("Paste", (void (TDataXtd_Axis::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TDataXtd_Axis::Paste, "None", py::arg("into"), py::arg("RT"));
cls_TDataXtd_Axis.def("Dump", (Standard_OStream & (TDataXtd_Axis::*)(Standard_OStream &) const) &TDataXtd_Axis::Dump, "None", py::arg("anOS"));
cls_TDataXtd_Axis.def_static("get_type_name_", (const char * (*)()) &TDataXtd_Axis::get_type_name, "None");
cls_TDataXtd_Axis.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDataXtd_Axis::get_type_descriptor, "None");
cls_TDataXtd_Axis.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDataXtd_Axis::*)() const) &TDataXtd_Axis::DynamicType, "None");

// Enums

}