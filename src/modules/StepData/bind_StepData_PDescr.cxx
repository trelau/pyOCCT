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
#include <Standard_Transient.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <StepData_PDescr.hxx>
#include <Standard_Type.hxx>
#include <StepData_EDescr.hxx>
#include <StepData_Field.hxx>
#include <Interface_Check.hxx>
#include <TCollection_AsciiString.hxx>
#include <StepData_EnumTool.hxx>

void bind_StepData_PDescr(py::module &mod){

py::class_<StepData_PDescr, opencascade::handle<StepData_PDescr>, Standard_Transient> cls_StepData_PDescr(mod, "StepData_PDescr", "This class is intended to describe the authorized form for a parameter, as a type or a value for a field");

// Constructors
cls_StepData_PDescr.def(py::init<>());

// Fields

// Methods
cls_StepData_PDescr.def("SetName", (void (StepData_PDescr::*)(const Standard_CString)) &StepData_PDescr::SetName, "None", py::arg("name"));
cls_StepData_PDescr.def("Name", (Standard_CString (StepData_PDescr::*)() const) &StepData_PDescr::Name, "None");
cls_StepData_PDescr.def("SetSelect", (void (StepData_PDescr::*)()) &StepData_PDescr::SetSelect, "Declares this PDescr to be a Select, hence to have members <me> itself can be the first member");
cls_StepData_PDescr.def("AddMember", (void (StepData_PDescr::*)(const opencascade::handle<StepData_PDescr> &)) &StepData_PDescr::AddMember, "Adds a member to a SELECT description", py::arg("member"));
cls_StepData_PDescr.def("SetMemberName", (void (StepData_PDescr::*)(const Standard_CString)) &StepData_PDescr::SetMemberName, "Sets a name for SELECT member. To be used if a member is for an immediate type", py::arg("memname"));
cls_StepData_PDescr.def("SetInteger", (void (StepData_PDescr::*)()) &StepData_PDescr::SetInteger, "Sets <me> for an Integer value");
cls_StepData_PDescr.def("SetReal", (void (StepData_PDescr::*)()) &StepData_PDescr::SetReal, "Sets <me> for a Real value");
cls_StepData_PDescr.def("SetString", (void (StepData_PDescr::*)()) &StepData_PDescr::SetString, "Sets <me> for a String value");
cls_StepData_PDescr.def("SetBoolean", (void (StepData_PDescr::*)()) &StepData_PDescr::SetBoolean, "Sets <me> for a Boolean value (false,true)");
cls_StepData_PDescr.def("SetLogical", (void (StepData_PDescr::*)()) &StepData_PDescr::SetLogical, "Sets <me> for a Logical value (false,true,unknown)");
cls_StepData_PDescr.def("SetEnum", (void (StepData_PDescr::*)()) &StepData_PDescr::SetEnum, "Sets <me> for an Enum value Then, call AddEnumDef ordered from the first one (value 0)");
cls_StepData_PDescr.def("AddEnumDef", (void (StepData_PDescr::*)(const Standard_CString)) &StepData_PDescr::AddEnumDef, "Adds an enum value as a string", py::arg("enumdef"));
cls_StepData_PDescr.def("SetType", (void (StepData_PDescr::*)(const opencascade::handle<Standard_Type> &)) &StepData_PDescr::SetType, "Sets <me> for an Entity which must match a Type (early-bound)", py::arg("atype"));
cls_StepData_PDescr.def("SetDescr", (void (StepData_PDescr::*)(const Standard_CString)) &StepData_PDescr::SetDescr, "Sets <me> for a Described Entity, whose Description must match the type name <dscnam>", py::arg("dscnam"));
cls_StepData_PDescr.def("AddArity", [](StepData_PDescr &self) -> void { return self.AddArity(); });
cls_StepData_PDescr.def("AddArity", (void (StepData_PDescr::*)(const Standard_Integer)) &StepData_PDescr::AddArity, "Adds an arity count to <me>, by default 1 1 : a simple field passes to a LIST/ARRAY etc or a LIST to a LIST OF LIST 2 : a simple field passes to a LIST OF LIST", py::arg("arity"));
cls_StepData_PDescr.def("SetArity", [](StepData_PDescr &self) -> void { return self.SetArity(); });
cls_StepData_PDescr.def("SetArity", (void (StepData_PDescr::*)(const Standard_Integer)) &StepData_PDescr::SetArity, "Directly sets the arity count 0 : simple field 1 : LIST or ARRAY etc 2 : LIST OF LIST", py::arg("arity"));
cls_StepData_PDescr.def("SetFrom", (void (StepData_PDescr::*)(const opencascade::handle<StepData_PDescr> &)) &StepData_PDescr::SetFrom, "Sets <me> as <other> but duplicated Hence, some definition may be changed", py::arg("other"));
cls_StepData_PDescr.def("SetOptional", [](StepData_PDescr &self) -> void { return self.SetOptional(); });
cls_StepData_PDescr.def("SetOptional", (void (StepData_PDescr::*)(const Standard_Boolean)) &StepData_PDescr::SetOptional, "Sets/Unsets <me> to accept undefined values", py::arg("opt"));
cls_StepData_PDescr.def("SetDerived", [](StepData_PDescr &self) -> void { return self.SetDerived(); });
cls_StepData_PDescr.def("SetDerived", (void (StepData_PDescr::*)(const Standard_Boolean)) &StepData_PDescr::SetDerived, "Sets/Unsets <me> to be for a derived field", py::arg("der"));
cls_StepData_PDescr.def("SetField", (void (StepData_PDescr::*)(const Standard_CString, const Standard_Integer)) &StepData_PDescr::SetField, "Sets <me> to describe a field of an entity With a name and a rank", py::arg("name"), py::arg("rank"));
cls_StepData_PDescr.def("IsSelect", (Standard_Boolean (StepData_PDescr::*)() const) &StepData_PDescr::IsSelect, "Tells if <me> is for a SELECT");
cls_StepData_PDescr.def("Member", (opencascade::handle<StepData_PDescr> (StepData_PDescr::*)(const Standard_CString) const) &StepData_PDescr::Member, "For a SELECT, returns the member whose name matches <name> To this member, the following question can then be asked Null Handle if <name> not matched or <me> not a SELECT", py::arg("name"));
cls_StepData_PDescr.def("IsInteger", (Standard_Boolean (StepData_PDescr::*)() const) &StepData_PDescr::IsInteger, "Tells if <me> is for an Integer");
cls_StepData_PDescr.def("IsReal", (Standard_Boolean (StepData_PDescr::*)() const) &StepData_PDescr::IsReal, "Tells if <me> is for a Real value");
cls_StepData_PDescr.def("IsString", (Standard_Boolean (StepData_PDescr::*)() const) &StepData_PDescr::IsString, "Tells if <me> is for a String value");
cls_StepData_PDescr.def("IsBoolean", (Standard_Boolean (StepData_PDescr::*)() const) &StepData_PDescr::IsBoolean, "Tells if <me> is for a Boolean value (false,true)");
cls_StepData_PDescr.def("IsLogical", (Standard_Boolean (StepData_PDescr::*)() const) &StepData_PDescr::IsLogical, "Tells if <me> is for a Logical value (false,true,unknown)");
cls_StepData_PDescr.def("IsEnum", (Standard_Boolean (StepData_PDescr::*)() const) &StepData_PDescr::IsEnum, "Tells if <me> is for an Enum value Then, call AddEnumDef ordered from the first one (value 0) Managed by an EnumTool");
cls_StepData_PDescr.def("EnumMax", (Standard_Integer (StepData_PDescr::*)() const) &StepData_PDescr::EnumMax, "Returns the maximum integer for a suitable value (count - 1)");
cls_StepData_PDescr.def("EnumValue", (Standard_Integer (StepData_PDescr::*)(const Standard_CString) const) &StepData_PDescr::EnumValue, "Returns the numeric value found for an enum text The text must be in capitals and limited by dots A non-suitable text gives a negative value to be returned", py::arg("name"));
cls_StepData_PDescr.def("EnumText", (Standard_CString (StepData_PDescr::*)(const Standard_Integer) const) &StepData_PDescr::EnumText, "Returns the text which corresponds to a numeric value, between 0 and EnumMax. It is limited by dots", py::arg("val"));
cls_StepData_PDescr.def("IsEntity", (Standard_Boolean (StepData_PDescr::*)() const) &StepData_PDescr::IsEntity, "Tells if <me> is for an Entity, either Described or CDL Type");
cls_StepData_PDescr.def("IsType", (Standard_Boolean (StepData_PDescr::*)(const opencascade::handle<Standard_Type> &) const) &StepData_PDescr::IsType, "Tells if <me> is for an entity of a given CDL type (early-bnd) (works for <me> + nexts if <me> is a Select)", py::arg("atype"));
cls_StepData_PDescr.def("Type", (opencascade::handle<Standard_Type> (StepData_PDescr::*)() const) &StepData_PDescr::Type, "Returns the type to match (IsKind), for a CDL Entity (else, null handle)");
cls_StepData_PDescr.def("IsDescr", (Standard_Boolean (StepData_PDescr::*)(const opencascade::handle<StepData_EDescr> &) const) &StepData_PDescr::IsDescr, "Tells if <me> is for a Described entity of a given EDescr (does this EDescr match description name ?). For late-bnd (works for <me> + nexts if <me> is a Select)", py::arg("descr"));
cls_StepData_PDescr.def("DescrName", (Standard_CString (StepData_PDescr::*)() const) &StepData_PDescr::DescrName, "Returns the description (type name) to match, for a Described (else, empty string)");
cls_StepData_PDescr.def("Arity", (Standard_Integer (StepData_PDescr::*)() const) &StepData_PDescr::Arity, "Returns the arity of <me>");
cls_StepData_PDescr.def("Simple", (opencascade::handle<StepData_PDescr> (StepData_PDescr::*)() const) &StepData_PDescr::Simple, "For a LIST or LIST OF LIST, Returns the PDescr for the simpler PDescr. Else, returns <me> This allows to have different attributes for Optional for instance, on a field, and on the parameter of a LIST : [OPTIONAL] LIST OF [OPTIONAL] ...");
cls_StepData_PDescr.def("IsOptional", (Standard_Boolean (StepData_PDescr::*)() const) &StepData_PDescr::IsOptional, "Tells if <me> is Optional");
cls_StepData_PDescr.def("IsDerived", (Standard_Boolean (StepData_PDescr::*)() const) &StepData_PDescr::IsDerived, "Tells if <me> is Derived");
cls_StepData_PDescr.def("IsField", (Standard_Boolean (StepData_PDescr::*)() const) &StepData_PDescr::IsField, "Tells if <me> is a Field. Else it is a Type");
cls_StepData_PDescr.def("FieldName", (Standard_CString (StepData_PDescr::*)() const) &StepData_PDescr::FieldName, "None");
cls_StepData_PDescr.def("FieldRank", (Standard_Integer (StepData_PDescr::*)() const) &StepData_PDescr::FieldRank, "None");
cls_StepData_PDescr.def("Check", (void (StepData_PDescr::*)(const StepData_Field &, opencascade::handle<Interface_Check> &) const) &StepData_PDescr::Check, "Semantic Check of a Field : does it complies with the given description ?", py::arg("afild"), py::arg("ach"));
cls_StepData_PDescr.def_static("get_type_name_", (const char * (*)()) &StepData_PDescr::get_type_name, "None");
cls_StepData_PDescr.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepData_PDescr::get_type_descriptor, "None");
cls_StepData_PDescr.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepData_PDescr::*)() const) &StepData_PDescr::DynamicType, "None");

// Enums

}