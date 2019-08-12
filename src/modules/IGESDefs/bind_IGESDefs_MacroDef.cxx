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
#include <TCollection_HAsciiString.hxx>
#include <Standard_TypeDef.hxx>
#include <Interface_HArray1OfHAsciiString.hxx>
#include <IGESDefs_MacroDef.hxx>
#include <Standard_Type.hxx>

void bind_IGESDefs_MacroDef(py::module &mod){

py::class_<IGESDefs_MacroDef, opencascade::handle<IGESDefs_MacroDef>, IGESData_IGESEntity> cls_IGESDefs_MacroDef(mod, "IGESDefs_MacroDef", "defines IGES Macro Definition Entity, Type <306> Form <0> in package IGESDefs This Class specifies the action of a specific MACRO. After specification MACRO can be used as necessary by means of MACRO class instance entity.");

// Constructors
cls_IGESDefs_MacroDef.def(py::init<>());

// Fields

// Methods
cls_IGESDefs_MacroDef.def("Init", (void (IGESDefs_MacroDef::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Integer, const opencascade::handle<Interface_HArray1OfHAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &)) &IGESDefs_MacroDef::Init, "This method is used to set the fields of the class MacroDef - macro : MACRO - entityTypeID : Entity Type ID - langStatements : Language Statements - endMacro : END MACRO", py::arg("macro"), py::arg("entityTypeID"), py::arg("langStatements"), py::arg("endMacro"));
cls_IGESDefs_MacroDef.def("NbStatements", (Standard_Integer (IGESDefs_MacroDef::*)() const) &IGESDefs_MacroDef::NbStatements, "returns the number of language statements");
cls_IGESDefs_MacroDef.def("MACRO", (opencascade::handle<TCollection_HAsciiString> (IGESDefs_MacroDef::*)() const) &IGESDefs_MacroDef::MACRO, "returns the MACRO(Literal)");
cls_IGESDefs_MacroDef.def("EntityTypeID", (Standard_Integer (IGESDefs_MacroDef::*)() const) &IGESDefs_MacroDef::EntityTypeID, "returns the Entity Type ID");
cls_IGESDefs_MacroDef.def("LanguageStatement", (opencascade::handle<TCollection_HAsciiString> (IGESDefs_MacroDef::*)(const Standard_Integer) const) &IGESDefs_MacroDef::LanguageStatement, "None", py::arg("StatNum"));
cls_IGESDefs_MacroDef.def("ENDMACRO", (opencascade::handle<TCollection_HAsciiString> (IGESDefs_MacroDef::*)() const) &IGESDefs_MacroDef::ENDMACRO, "returns the ENDM(Literal)");
cls_IGESDefs_MacroDef.def_static("get_type_name_", (const char * (*)()) &IGESDefs_MacroDef::get_type_name, "None");
cls_IGESDefs_MacroDef.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESDefs_MacroDef::get_type_descriptor, "None");
cls_IGESDefs_MacroDef.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESDefs_MacroDef::*)() const) &IGESDefs_MacroDef::DynamicType, "None");

// Enums

}