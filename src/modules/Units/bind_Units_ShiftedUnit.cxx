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
#include <Units_Unit.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Units_Quantity.hxx>
#include <Units_Token.hxx>
#include <Units_ShiftedUnit.hxx>
#include <Standard_Type.hxx>

void bind_Units_ShiftedUnit(py::module &mod){

py::class_<Units_ShiftedUnit, opencascade::handle<Units_ShiftedUnit>, Units_Unit> cls_Units_ShiftedUnit(mod, "Units_ShiftedUnit", "This class is useful to describe units with a shifted origin in relation to another unit. A well known example is the Celsius degrees in relation to Kelvin degrees. The shift of the Celsius origin is 273.15 Kelvin degrees.");

// Constructors
cls_Units_ShiftedUnit.def(py::init<const Standard_CString, const Standard_CString, const Standard_Real, const Standard_Real, const opencascade::handle<Units_Quantity> &>(), py::arg("aname"), py::arg("asymbol"), py::arg("avalue"), py::arg("amove"), py::arg("aquantity"));
cls_Units_ShiftedUnit.def(py::init<const Standard_CString, const Standard_CString>(), py::arg("aname"), py::arg("asymbol"));
cls_Units_ShiftedUnit.def(py::init<const Standard_CString>(), py::arg("aname"));

// Fields

// Methods
cls_Units_ShiftedUnit.def("Move", (void (Units_ShiftedUnit::*)(const Standard_Real)) &Units_ShiftedUnit::Move, "Sets the field <themove> to <amove>", py::arg("amove"));
cls_Units_ShiftedUnit.def("Move", (Standard_Real (Units_ShiftedUnit::*)() const) &Units_ShiftedUnit::Move, "Returns the shifted value <themove>.");
cls_Units_ShiftedUnit.def("Token", (opencascade::handle<Units_Token> (Units_ShiftedUnit::*)() const) &Units_ShiftedUnit::Token, "This redefined method returns a ShiftedToken object.");
cls_Units_ShiftedUnit.def("Dump", (void (Units_ShiftedUnit::*)(const Standard_Integer, const Standard_Integer) const) &Units_ShiftedUnit::Dump, "None", py::arg("ashift"), py::arg("alevel"));
cls_Units_ShiftedUnit.def_static("get_type_name_", (const char * (*)()) &Units_ShiftedUnit::get_type_name, "None");
cls_Units_ShiftedUnit.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Units_ShiftedUnit::get_type_descriptor, "None");
cls_Units_ShiftedUnit.def("DynamicType", (const opencascade::handle<Standard_Type> & (Units_ShiftedUnit::*)() const) &Units_ShiftedUnit::DynamicType, "None");

// Enums

}