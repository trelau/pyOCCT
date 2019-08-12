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
#include <TDataXtd_Point.hxx>
#include <TDF_Label.hxx>
#include <gp_Pnt.hxx>
#include <TDF_RelocationTable.hxx>
#include <Standard_OStream.hxx>
#include <Standard_Type.hxx>

void bind_TDataXtd_Point(py::module &mod){

py::class_<TDataXtd_Point, opencascade::handle<TDataXtd_Point>, TDF_Attribute> cls_TDataXtd_Point(mod, "TDataXtd_Point", "The basis to define a point attribute. The topological attribute must contain a vertex. You use this class to create reference points in a design.");

// Constructors
cls_TDataXtd_Point.def(py::init<>());

// Fields

// Methods
cls_TDataXtd_Point.def_static("GetID_", (const Standard_GUID & (*)()) &TDataXtd_Point::GetID, "class methods =============");
cls_TDataXtd_Point.def_static("Set_", (opencascade::handle<TDataXtd_Point> (*)(const TDF_Label &)) &TDataXtd_Point::Set, "Sets the label Label as a point attribute. If no object is found, a point attribute is created.", py::arg("label"));
cls_TDataXtd_Point.def_static("Set_", (opencascade::handle<TDataXtd_Point> (*)(const TDF_Label &, const gp_Pnt &)) &TDataXtd_Point::Set, "Sets the label Label as a point attribute containing the point P. If no object is found, a point attribute is created. Point methods =============", py::arg("label"), py::arg("P"));
cls_TDataXtd_Point.def("ID", (const Standard_GUID & (TDataXtd_Point::*)() const) &TDataXtd_Point::ID, "None");
cls_TDataXtd_Point.def("Restore", (void (TDataXtd_Point::*)(const opencascade::handle<TDF_Attribute> &)) &TDataXtd_Point::Restore, "None", py::arg("With"));
cls_TDataXtd_Point.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TDataXtd_Point::*)() const) &TDataXtd_Point::NewEmpty, "None");
cls_TDataXtd_Point.def("Paste", (void (TDataXtd_Point::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TDataXtd_Point::Paste, "None", py::arg("Into"), py::arg("RT"));
cls_TDataXtd_Point.def("Dump", (Standard_OStream & (TDataXtd_Point::*)(Standard_OStream &) const) &TDataXtd_Point::Dump, "None", py::arg("anOS"));
cls_TDataXtd_Point.def_static("get_type_name_", (const char * (*)()) &TDataXtd_Point::get_type_name, "None");
cls_TDataXtd_Point.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDataXtd_Point::get_type_descriptor, "None");
cls_TDataXtd_Point.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDataXtd_Point::*)() const) &TDataXtd_Point::DynamicType, "None");

// Enums

}