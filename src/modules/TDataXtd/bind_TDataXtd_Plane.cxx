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
#include <TDataXtd_Plane.hxx>
#include <TDF_Label.hxx>
#include <gp_Pln.hxx>
#include <TDF_RelocationTable.hxx>
#include <Standard_OStream.hxx>
#include <Standard_Type.hxx>

void bind_TDataXtd_Plane(py::module &mod){

py::class_<TDataXtd_Plane, opencascade::handle<TDataXtd_Plane>, TDF_Attribute> cls_TDataXtd_Plane(mod, "TDataXtd_Plane", "The basis to define a plane attribute. Warning: Use TDataXtd_Geometry attribute to retrieve the gp_Pln of the Plane attribute");

// Constructors
cls_TDataXtd_Plane.def(py::init<>());

// Fields

// Methods
cls_TDataXtd_Plane.def_static("GetID_", (const Standard_GUID & (*)()) &TDataXtd_Plane::GetID, "class methods =============");
cls_TDataXtd_Plane.def_static("Set_", (opencascade::handle<TDataXtd_Plane> (*)(const TDF_Label &)) &TDataXtd_Plane::Set, "Finds or creates the plane attribute defined by the label label. Warning If you are creating the attribute with this syntax, a planar face should already be associated with label.", py::arg("label"));
cls_TDataXtd_Plane.def_static("Set_", (opencascade::handle<TDataXtd_Plane> (*)(const TDF_Label &, const gp_Pln &)) &TDataXtd_Plane::Set, "Finds, or creates, a Plane attribute and sets <P> as generated the associated NamedShape. Plane methods =============", py::arg("label"), py::arg("P"));
cls_TDataXtd_Plane.def("ID", (const Standard_GUID & (TDataXtd_Plane::*)() const) &TDataXtd_Plane::ID, "None");
cls_TDataXtd_Plane.def("Restore", (void (TDataXtd_Plane::*)(const opencascade::handle<TDF_Attribute> &)) &TDataXtd_Plane::Restore, "None", py::arg("With"));
cls_TDataXtd_Plane.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TDataXtd_Plane::*)() const) &TDataXtd_Plane::NewEmpty, "None");
cls_TDataXtd_Plane.def("Paste", (void (TDataXtd_Plane::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TDataXtd_Plane::Paste, "None", py::arg("Into"), py::arg("RT"));
cls_TDataXtd_Plane.def("Dump", (Standard_OStream & (TDataXtd_Plane::*)(Standard_OStream &) const) &TDataXtd_Plane::Dump, "None", py::arg("anOS"));
cls_TDataXtd_Plane.def_static("get_type_name_", (const char * (*)()) &TDataXtd_Plane::get_type_name, "None");
cls_TDataXtd_Plane.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDataXtd_Plane::get_type_descriptor, "None");
cls_TDataXtd_Plane.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDataXtd_Plane::*)() const) &TDataXtd_Plane::DynamicType, "None");

// Enums

}