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
#include <IGESData_IGESEntity.hxx>
#include <Standard_Handle.hxx>
#include <IGESDimen_GeneralNote.hxx>
#include <IGESDimen_LeaderArrow.hxx>
#include <gp_XY.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Pnt.hxx>
#include <IGESDimen_RadiusDimension.hxx>
#include <Standard_Type.hxx>

void bind_IGESDimen_RadiusDimension(py::module &mod){

py::class_<IGESDimen_RadiusDimension, opencascade::handle<IGESDimen_RadiusDimension>, IGESData_IGESEntity> cls_IGESDimen_RadiusDimension(mod, "IGESDimen_RadiusDimension", "Defines IGES Radius Dimension, type <222> Form <0, 1>, in package IGESDimen. A Radius Dimension Entity consists of a General Note, a leader, and an arc center point. A second form of this entity accounts for the occasional need to have two leader entities referenced.");

// Constructors
cls_IGESDimen_RadiusDimension.def(py::init<>());

// Fields

// Methods
cls_IGESDimen_RadiusDimension.def("Init", (void (IGESDimen_RadiusDimension::*)(const opencascade::handle<IGESDimen_GeneralNote> &, const opencascade::handle<IGESDimen_LeaderArrow> &, const gp_XY &, const opencascade::handle<IGESDimen_LeaderArrow> &)) &IGESDimen_RadiusDimension::Init, "None", py::arg("aNote"), py::arg("anArrow"), py::arg("arcCenter"), py::arg("anotherArrow"));
cls_IGESDimen_RadiusDimension.def("InitForm", (void (IGESDimen_RadiusDimension::*)(const Standard_Integer)) &IGESDimen_RadiusDimension::InitForm, "Allows to change Form Number (1 admits null arrow)", py::arg("form"));
cls_IGESDimen_RadiusDimension.def("Note", (opencascade::handle<IGESDimen_GeneralNote> (IGESDimen_RadiusDimension::*)() const) &IGESDimen_RadiusDimension::Note, "returns the General Note entity");
cls_IGESDimen_RadiusDimension.def("Leader", (opencascade::handle<IGESDimen_LeaderArrow> (IGESDimen_RadiusDimension::*)() const) &IGESDimen_RadiusDimension::Leader, "returns the Leader Arrow entity");
cls_IGESDimen_RadiusDimension.def("Center", (gp_Pnt2d (IGESDimen_RadiusDimension::*)() const) &IGESDimen_RadiusDimension::Center, "returns the coordinates of the Arc Center");
cls_IGESDimen_RadiusDimension.def("TransformedCenter", (gp_Pnt (IGESDimen_RadiusDimension::*)() const) &IGESDimen_RadiusDimension::TransformedCenter, "returns the coordinates of the Arc Center after Transformation (Z coord taken from ZDepth of Leader Entity)");
cls_IGESDimen_RadiusDimension.def("HasLeader2", (Standard_Boolean (IGESDimen_RadiusDimension::*)() const) &IGESDimen_RadiusDimension::HasLeader2, "returns True if form is 1, False if 0");
cls_IGESDimen_RadiusDimension.def("Leader2", (opencascade::handle<IGESDimen_LeaderArrow> (IGESDimen_RadiusDimension::*)() const) &IGESDimen_RadiusDimension::Leader2, "returns Null handle if Form is 0");
cls_IGESDimen_RadiusDimension.def_static("get_type_name_", (const char * (*)()) &IGESDimen_RadiusDimension::get_type_name, "None");
cls_IGESDimen_RadiusDimension.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESDimen_RadiusDimension::get_type_descriptor, "None");
cls_IGESDimen_RadiusDimension.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESDimen_RadiusDimension::*)() const) &IGESDimen_RadiusDimension::DynamicType, "None");

// Enums

}