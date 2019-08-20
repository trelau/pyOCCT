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
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Transient.hxx>
#include <Standard_Type.hxx>
#include <StepData_PDescr.hxx>
#include <StepData_SelectMember.hxx>
#include <StepData_Logical.hxx>
#include <StepData_SelectType.hxx>

void bind_StepData_SelectType(py::module &mod){

py::class_<StepData_SelectType, std::unique_ptr<StepData_SelectType>> cls_StepData_SelectType(mod, "StepData_SelectType", "SelectType is the basis used for SELECT_TYPE definitions from the EXPRESS form. A SELECT_TYPE in EXPRESS is an enumeration of Types, it corresponds in a way to a Super-Type, but with no specific Methods, and no exclusivity (a given Type can be member of several SELECT_TYPES, plus be itself a SUB_TYPE).");

// Fields

// Methods
// cls_StepData_SelectType.def_static("operator new_", (void * (*)(size_t)) &StepData_SelectType::operator new, "None", py::arg("theSize"));
// cls_StepData_SelectType.def_static("operator delete_", (void (*)(void *)) &StepData_SelectType::operator delete, "None", py::arg("theAddress"));
// cls_StepData_SelectType.def_static("operator new[]_", (void * (*)(size_t)) &StepData_SelectType::operator new[], "None", py::arg("theSize"));
// cls_StepData_SelectType.def_static("operator delete[]_", (void (*)(void *)) &StepData_SelectType::operator delete[], "None", py::arg("theAddress"));
// cls_StepData_SelectType.def_static("operator new_", (void * (*)(size_t, void *)) &StepData_SelectType::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepData_SelectType.def_static("operator delete_", (void (*)(void *, void *)) &StepData_SelectType::operator delete, "None", py::arg(""), py::arg(""));
cls_StepData_SelectType.def("CaseNum", (Standard_Integer (StepData_SelectType::*)(const opencascade::handle<Standard_Transient> &) const) &StepData_SelectType::CaseNum, "Recognizes the Type of an Entity. Returns a positive Number which identifies the Type in the definition List of the SelectType. Returns Zero if its Type in not in this List.", py::arg("ent"));
cls_StepData_SelectType.def("Matches", (Standard_Boolean (StepData_SelectType::*)(const opencascade::handle<Standard_Transient> &) const) &StepData_SelectType::Matches, "Returns True if the Type of an Entity complies with the definition list of the SelectType. Also checks for a SelectMember Default Implementation looks for CaseNum or CaseMem positive", py::arg("ent"));
cls_StepData_SelectType.def("SetValue", (void (StepData_SelectType::*)(const opencascade::handle<Standard_Transient> &)) &StepData_SelectType::SetValue, "Stores an Entity. This allows to define a specific SelectType class with one read method per member Type, which returns the Value casted with the good Type.", py::arg("ent"));
cls_StepData_SelectType.def("Nullify", (void (StepData_SelectType::*)()) &StepData_SelectType::Nullify, "Nullifies the Stored Entity");
cls_StepData_SelectType.def("Value", (const opencascade::handle<Standard_Transient> & (StepData_SelectType::*)() const) &StepData_SelectType::Value, "Returns the Stored Entity. Can be used to define specific read methods (see above)");
cls_StepData_SelectType.def("IsNull", (Standard_Boolean (StepData_SelectType::*)() const) &StepData_SelectType::IsNull, "Returns True if there is no Stored Entity (i.e. it is Null)");
cls_StepData_SelectType.def("Type", (opencascade::handle<Standard_Type> (StepData_SelectType::*)() const) &StepData_SelectType::Type, "Returns the Effective (Dynamic) Type of the Stored Entity If it is Null, returns TYPE(Transient)");
cls_StepData_SelectType.def("CaseNumber", (Standard_Integer (StepData_SelectType::*)() const) &StepData_SelectType::CaseNumber, "Recognizes the Type of the stored Entity, or zero if it is Null or SelectMember. Calls the first method CaseNum on Value");
cls_StepData_SelectType.def("Description", (opencascade::handle<StepData_PDescr> (StepData_SelectType::*)() const) &StepData_SelectType::Description, "Returns the Description which corresponds to <me> Null if no specific description to give. This description is used to control reading an check validity. Default returns a Null Handle, i.e. undefined description It can suffice if CaseNum and CaseMem give enough control");
cls_StepData_SelectType.def("NewMember", (opencascade::handle<StepData_SelectMember> (StepData_SelectType::*)() const) &StepData_SelectType::NewMember, "Returns a preferred SelectMember. Default returns a Null By default, a SelectMember can be set according to data type and Name : it is a SelectNamed if Name is defined");
cls_StepData_SelectType.def("CaseMem", (Standard_Integer (StepData_SelectType::*)(const opencascade::handle<StepData_SelectMember> &) const) &StepData_SelectType::CaseMem, "Recognize a SelectMember (kind, name). Returns a positive value which identifies the case in the List of immediate cases (distinct from the List of Entity Types). Zero if not recognizes Default returns 0, saying that no immediate value is allowed", py::arg("ent"));
cls_StepData_SelectType.def("CaseMember", (Standard_Integer (StepData_SelectType::*)() const) &StepData_SelectType::CaseMember, "Returns the Type of the stored SelectMember, or zero if it is Null or Entity. Calls the method CaseMem on Value");
cls_StepData_SelectType.def("Member", (opencascade::handle<StepData_SelectMember> (StepData_SelectType::*)() const) &StepData_SelectType::Member, "Returns Value as a SelectMember. Null if not a SelectMember");
cls_StepData_SelectType.def("SelectName", (Standard_CString (StepData_SelectType::*)() const) &StepData_SelectType::SelectName, "Returns the type name of SelectMember. If no SelectMember or with no type name, returns an empty string To change it, pass through the SelectMember itself");
cls_StepData_SelectType.def("Int", (Standard_Integer (StepData_SelectType::*)() const) &StepData_SelectType::Int, "This internal method gives access to a value implemented by an Integer (to read it)");
cls_StepData_SelectType.def("SetInt", (void (StepData_SelectType::*)(const Standard_Integer)) &StepData_SelectType::SetInt, "This internal method gives access to a value implemented by an Integer (to set it) : a SelectMember MUST ALREADY BE THERE !", py::arg("val"));
cls_StepData_SelectType.def("Integer", (Standard_Integer (StepData_SelectType::*)() const) &StepData_SelectType::Integer, "Gets the value as an Integer");
cls_StepData_SelectType.def("SetInteger", [](StepData_SelectType &self, const Standard_Integer a0) -> void { return self.SetInteger(a0); });
cls_StepData_SelectType.def("SetInteger", (void (StepData_SelectType::*)(const Standard_Integer, const Standard_CString)) &StepData_SelectType::SetInteger, "Sets a new Integer value, with an optional type name Warning : If a SelectMember is already set, works on it : value and name must then be accepted by this SelectMember", py::arg("val"), py::arg("name"));
cls_StepData_SelectType.def("Boolean", (Standard_Boolean (StepData_SelectType::*)() const) &StepData_SelectType::Boolean, "None");
cls_StepData_SelectType.def("SetBoolean", [](StepData_SelectType &self, const Standard_Boolean a0) -> void { return self.SetBoolean(a0); });
cls_StepData_SelectType.def("SetBoolean", (void (StepData_SelectType::*)(const Standard_Boolean, const Standard_CString)) &StepData_SelectType::SetBoolean, "None", py::arg("val"), py::arg("name"));
cls_StepData_SelectType.def("Logical", (StepData_Logical (StepData_SelectType::*)() const) &StepData_SelectType::Logical, "None");
cls_StepData_SelectType.def("SetLogical", [](StepData_SelectType &self, const StepData_Logical a0) -> void { return self.SetLogical(a0); });
cls_StepData_SelectType.def("SetLogical", (void (StepData_SelectType::*)(const StepData_Logical, const Standard_CString)) &StepData_SelectType::SetLogical, "None", py::arg("val"), py::arg("name"));
cls_StepData_SelectType.def("Real", (Standard_Real (StepData_SelectType::*)() const) &StepData_SelectType::Real, "None");
cls_StepData_SelectType.def("SetReal", [](StepData_SelectType &self, const Standard_Real a0) -> void { return self.SetReal(a0); });
cls_StepData_SelectType.def("SetReal", (void (StepData_SelectType::*)(const Standard_Real, const Standard_CString)) &StepData_SelectType::SetReal, "None", py::arg("val"), py::arg("name"));

// Enums

}