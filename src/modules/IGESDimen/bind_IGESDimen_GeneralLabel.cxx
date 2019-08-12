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
#include <IGESDimen_HArray1OfLeaderArrow.hxx>
#include <Standard_TypeDef.hxx>
#include <IGESDimen_LeaderArrow.hxx>
#include <IGESDimen_GeneralLabel.hxx>
#include <Standard_Type.hxx>

void bind_IGESDimen_GeneralLabel(py::module &mod){

py::class_<IGESDimen_GeneralLabel, opencascade::handle<IGESDimen_GeneralLabel>, IGESData_IGESEntity> cls_IGESDimen_GeneralLabel(mod, "IGESDimen_GeneralLabel", "defines GeneralLabel, Type <210> Form <0> in package IGESDimen Used for general labeling with leaders");

// Constructors
cls_IGESDimen_GeneralLabel.def(py::init<>());

// Fields

// Methods
cls_IGESDimen_GeneralLabel.def("Init", (void (IGESDimen_GeneralLabel::*)(const opencascade::handle<IGESDimen_GeneralNote> &, const opencascade::handle<IGESDimen_HArray1OfLeaderArrow> &)) &IGESDimen_GeneralLabel::Init, "This method is used to set the fields of the class GeneralLabel - aNote : General Note Entity - someLeaders : Associated Leader Entities", py::arg("aNote"), py::arg("someLeaders"));
cls_IGESDimen_GeneralLabel.def("Note", (opencascade::handle<IGESDimen_GeneralNote> (IGESDimen_GeneralLabel::*)() const) &IGESDimen_GeneralLabel::Note, "returns General Note Entity");
cls_IGESDimen_GeneralLabel.def("NbLeaders", (Standard_Integer (IGESDimen_GeneralLabel::*)() const) &IGESDimen_GeneralLabel::NbLeaders, "returns Number of Leaders");
cls_IGESDimen_GeneralLabel.def("Leader", (opencascade::handle<IGESDimen_LeaderArrow> (IGESDimen_GeneralLabel::*)(const Standard_Integer) const) &IGESDimen_GeneralLabel::Leader, "returns Leader Entity raises exception if Index <= 0 or Index > NbLeaders()", py::arg("Index"));
cls_IGESDimen_GeneralLabel.def_static("get_type_name_", (const char * (*)()) &IGESDimen_GeneralLabel::get_type_name, "None");
cls_IGESDimen_GeneralLabel.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESDimen_GeneralLabel::get_type_descriptor, "None");
cls_IGESDimen_GeneralLabel.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESDimen_GeneralLabel::*)() const) &IGESDimen_GeneralLabel::DynamicType, "None");

// Enums

}