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
#include <TDF_Label.hxx>
#include <gp_Pnt.hxx>
#include <Standard_Handle.hxx>
#include <TDataXtd_Position.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_GUID.hxx>
#include <TDF_RelocationTable.hxx>
#include <Standard_Type.hxx>

void bind_TDataXtd_Position(py::module &mod){

py::class_<TDataXtd_Position, opencascade::handle<TDataXtd_Position>, TDF_Attribute> cls_TDataXtd_Position(mod, "TDataXtd_Position", "Position of a Label");

// Constructors
cls_TDataXtd_Position.def(py::init<>());

// Fields

// Methods
cls_TDataXtd_Position.def_static("Set_", (void (*)(const TDF_Label &, const gp_Pnt &)) &TDataXtd_Position::Set, "Create if not found the TDataXtd_Position attribute set its position to <aPos>", py::arg("aLabel"), py::arg("aPos"));
cls_TDataXtd_Position.def_static("Set_", (opencascade::handle<TDataXtd_Position> (*)(const TDF_Label &)) &TDataXtd_Position::Set, "Find an existing, or create an empty, Position. the Position attribute is returned.", py::arg("aLabel"));
cls_TDataXtd_Position.def_static("Get_", (Standard_Boolean (*)(const TDF_Label &, gp_Pnt &)) &TDataXtd_Position::Get, "Search label <aLabel) for the TDataXtd_Position attribute and get its position if found returns True", py::arg("aLabel"), py::arg("aPos"));
cls_TDataXtd_Position.def("ID", (const Standard_GUID & (TDataXtd_Position::*)() const) &TDataXtd_Position::ID, "Returns the ID of the attribute.");
cls_TDataXtd_Position.def_static("GetID_", (const Standard_GUID & (*)()) &TDataXtd_Position::GetID, "Returns the ID of the attribute.");
cls_TDataXtd_Position.def("Restore", (void (TDataXtd_Position::*)(const opencascade::handle<TDF_Attribute> &)) &TDataXtd_Position::Restore, "Restores the contents from <anAttribute> into this one. It is used when aborting a transaction.", py::arg("anAttribute"));
cls_TDataXtd_Position.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TDataXtd_Position::*)() const) &TDataXtd_Position::NewEmpty, "Returns an new empty attribute from the good end type. It is used by the copy algorithm.");
cls_TDataXtd_Position.def("Paste", (void (TDataXtd_Position::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TDataXtd_Position::Paste, "This method is different from the 'Copy' one, because it is used when copying an attribute from a source structure into a target structure. This method pastes the current attribute to the label corresponding to the insertor. The pasted attribute may be a brand new one or a new version of the previous one.", py::arg("intoAttribute"), py::arg("aRelocTationable"));
cls_TDataXtd_Position.def("GetPosition", (const gp_Pnt & (TDataXtd_Position::*)() const) &TDataXtd_Position::GetPosition, "None");
cls_TDataXtd_Position.def("SetPosition", (void (TDataXtd_Position::*)(const gp_Pnt &)) &TDataXtd_Position::SetPosition, "None", py::arg("aPos"));
cls_TDataXtd_Position.def_static("get_type_name_", (const char * (*)()) &TDataXtd_Position::get_type_name, "None");
cls_TDataXtd_Position.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDataXtd_Position::get_type_descriptor, "None");
cls_TDataXtd_Position.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDataXtd_Position::*)() const) &TDataXtd_Position::DynamicType, "None");

// Enums

}