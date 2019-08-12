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
#include <Standard_TypeDef.hxx>
#include <IGESDimen_WitnessLine.hxx>
#include <IGESDimen_LeaderArrow.hxx>
#include <IGESDimen_OrdinateDimension.hxx>
#include <Standard_Type.hxx>

void bind_IGESDimen_OrdinateDimension(py::module &mod){

py::class_<IGESDimen_OrdinateDimension, opencascade::handle<IGESDimen_OrdinateDimension>, IGESData_IGESEntity> cls_IGESDimen_OrdinateDimension(mod, "IGESDimen_OrdinateDimension", "defines IGES Ordinate Dimension, Type <218> Form <0, 1>, in package IGESDimen Note : The ordinate dimension entity is used to indicate dimensions from a common base line. Dimensioning is only permitted along the XT or YT axis.");

// Constructors
cls_IGESDimen_OrdinateDimension.def(py::init<>());

// Fields

// Methods
cls_IGESDimen_OrdinateDimension.def("Init", (void (IGESDimen_OrdinateDimension::*)(const opencascade::handle<IGESDimen_GeneralNote> &, const Standard_Boolean, const opencascade::handle<IGESDimen_WitnessLine> &, const opencascade::handle<IGESDimen_LeaderArrow> &)) &IGESDimen_OrdinateDimension::Init, "None", py::arg("aNote"), py::arg("aType"), py::arg("aLine"), py::arg("anArrow"));
cls_IGESDimen_OrdinateDimension.def("IsLine", (Standard_Boolean (IGESDimen_OrdinateDimension::*)() const) &IGESDimen_OrdinateDimension::IsLine, "returns True if Witness Line and False if Leader (only for Form 0)");
cls_IGESDimen_OrdinateDimension.def("IsLeader", (Standard_Boolean (IGESDimen_OrdinateDimension::*)() const) &IGESDimen_OrdinateDimension::IsLeader, "returns True if Leader and False if Witness Line (only for Form 0)");
cls_IGESDimen_OrdinateDimension.def("Note", (opencascade::handle<IGESDimen_GeneralNote> (IGESDimen_OrdinateDimension::*)() const) &IGESDimen_OrdinateDimension::Note, "returns the General Note entity associated.");
cls_IGESDimen_OrdinateDimension.def("WitnessLine", (opencascade::handle<IGESDimen_WitnessLine> (IGESDimen_OrdinateDimension::*)() const) &IGESDimen_OrdinateDimension::WitnessLine, "returns the Witness Line associated or Null handle");
cls_IGESDimen_OrdinateDimension.def("Leader", (opencascade::handle<IGESDimen_LeaderArrow> (IGESDimen_OrdinateDimension::*)() const) &IGESDimen_OrdinateDimension::Leader, "returns the Leader associated or Null handle");
cls_IGESDimen_OrdinateDimension.def_static("get_type_name_", (const char * (*)()) &IGESDimen_OrdinateDimension::get_type_name, "None");
cls_IGESDimen_OrdinateDimension.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESDimen_OrdinateDimension::get_type_descriptor, "None");
cls_IGESDimen_OrdinateDimension.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESDimen_OrdinateDimension::*)() const) &IGESDimen_OrdinateDimension::DynamicType, "None");

// Enums

}