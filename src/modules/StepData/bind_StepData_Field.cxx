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
#include <StepData_Field.hxx>
#include <Standard_TypeDef.hxx>
#include <StepData_Logical.hxx>
#include <Standard_Handle.hxx>
#include <StepData_SelectMember.hxx>
#include <Standard_Transient.hxx>

void bind_StepData_Field(py::module &mod){

py::class_<StepData_Field, std::unique_ptr<StepData_Field>> cls_StepData_Field(mod, "StepData_Field", "Defines a generally defined Field for STEP data : can be used either in any kind of entity to implement it or in free format entities in a 'late-binding' mode A field can have : no value (or derived), a single value of any kind, a list of value : single or double list");

// Constructors
cls_StepData_Field.def(py::init<>());
cls_StepData_Field.def(py::init<const StepData_Field &>(), py::arg("other"));
cls_StepData_Field.def(py::init<const StepData_Field &, const Standard_Boolean>(), py::arg("other"), py::arg("copy"));

// Fields

// Methods
// cls_StepData_Field.def_static("operator new_", (void * (*)(size_t)) &StepData_Field::operator new, "None", py::arg("theSize"));
// cls_StepData_Field.def_static("operator delete_", (void (*)(void *)) &StepData_Field::operator delete, "None", py::arg("theAddress"));
// cls_StepData_Field.def_static("operator new[]_", (void * (*)(size_t)) &StepData_Field::operator new[], "None", py::arg("theSize"));
// cls_StepData_Field.def_static("operator delete[]_", (void (*)(void *)) &StepData_Field::operator delete[], "None", py::arg("theAddress"));
// cls_StepData_Field.def_static("operator new_", (void * (*)(size_t, void *)) &StepData_Field::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepData_Field.def_static("operator delete_", (void (*)(void *, void *)) &StepData_Field::operator delete, "None", py::arg(""), py::arg(""));
cls_StepData_Field.def("CopyFrom", (void (StepData_Field::*)(const StepData_Field &)) &StepData_Field::CopyFrom, "Gets the copy of the values of another field", py::arg("other"));
cls_StepData_Field.def("Clear", [](StepData_Field &self) -> void { return self.Clear(); });
cls_StepData_Field.def("Clear", (void (StepData_Field::*)(const Standard_Integer)) &StepData_Field::Clear, "Clears the field, to set it as 'no value defined' Just before SetList, predeclares it as 'any' A Kind can be directly set here to declare a type", py::arg("kind"));
cls_StepData_Field.def("SetDerived", (void (StepData_Field::*)()) &StepData_Field::SetDerived, "Codes a Field as derived (no proper value)");
cls_StepData_Field.def("SetInt", (void (StepData_Field::*)(const Standard_Integer)) &StepData_Field::SetInt, "Directly sets the Integer value, if its Kind matches Integer, Boolean, Logical, or Enum (does not change Kind)", py::arg("val"));
cls_StepData_Field.def("SetInteger", [](StepData_Field &self) -> void { return self.SetInteger(); });
cls_StepData_Field.def("SetInteger", (void (StepData_Field::*)(const Standard_Integer)) &StepData_Field::SetInteger, "Sets an Integer value (before SetList* declares it as Integer)", py::arg("val"));
cls_StepData_Field.def("SetBoolean", [](StepData_Field &self) -> void { return self.SetBoolean(); });
cls_StepData_Field.def("SetBoolean", (void (StepData_Field::*)(const Standard_Boolean)) &StepData_Field::SetBoolean, "Sets a Boolean value (or predeclares a list as boolean)", py::arg("val"));
cls_StepData_Field.def("SetLogical", [](StepData_Field &self) -> void { return self.SetLogical(); });
cls_StepData_Field.def("SetLogical", (void (StepData_Field::*)(const StepData_Logical)) &StepData_Field::SetLogical, "Sets a Logical Value (or predeclares a list as logical)", py::arg("val"));
cls_StepData_Field.def("SetReal", [](StepData_Field &self) -> void { return self.SetReal(); });
cls_StepData_Field.def("SetReal", (void (StepData_Field::*)(const Standard_Real)) &StepData_Field::SetReal, "Sets a Real Value (or predeclares a list as Real);", py::arg("val"));
cls_StepData_Field.def("SetString", [](StepData_Field &self) -> void { return self.SetString(); });
cls_StepData_Field.def("SetString", (void (StepData_Field::*)(const Standard_CString)) &StepData_Field::SetString, "Sets a String Value (or predeclares a list as String) Does not redefine the Kind if it is alread String or Enum", py::arg("val"));
cls_StepData_Field.def("SetEnum", [](StepData_Field &self) -> void { return self.SetEnum(); });
cls_StepData_Field.def("SetEnum", [](StepData_Field &self, const Standard_Integer a0) -> void { return self.SetEnum(a0); });
cls_StepData_Field.def("SetEnum", (void (StepData_Field::*)(const Standard_Integer, const Standard_CString)) &StepData_Field::SetEnum, "Sets an Enum Value (as its integer counterpart) (or predeclares a list as Enum) If <text> is given , also sets its textual expression <val> negative means unknown (known values begin at 0)", py::arg("val"), py::arg("text"));
cls_StepData_Field.def("SetSelectMember", (void (StepData_Field::*)(const opencascade::handle<StepData_SelectMember> &)) &StepData_Field::SetSelectMember, "Sets a SelectMember (for Integer,Boolean,Enum,Real,Logical) Hence, the value of the field is accessed through this member", py::arg("val"));
cls_StepData_Field.def("SetEntity", (void (StepData_Field::*)(const opencascade::handle<Standard_Transient> &)) &StepData_Field::SetEntity, "Sets an Entity Value", py::arg("val"));
cls_StepData_Field.def("SetEntity", (void (StepData_Field::*)()) &StepData_Field::SetEntity, "Predeclares a list as of entity");
cls_StepData_Field.def("SetList", [](StepData_Field &self, const Standard_Integer a0) -> void { return self.SetList(a0); });
cls_StepData_Field.def("SetList", (void (StepData_Field::*)(const Standard_Integer, const Standard_Integer)) &StepData_Field::SetList, "Declares a field as a list, with an initial size Initial lower is defaulted as 1, can be defined The list starts empty, typed by the last Set* If no Set* before, sets it as 'any' (transient/select)", py::arg("size"), py::arg("first"));
cls_StepData_Field.def("SetList2", [](StepData_Field &self, const Standard_Integer a0, const Standard_Integer a1) -> void { return self.SetList2(a0, a1); });
cls_StepData_Field.def("SetList2", [](StepData_Field &self, const Standard_Integer a0, const Standard_Integer a1, const Standard_Integer a2) -> void { return self.SetList2(a0, a1, a2); });
cls_StepData_Field.def("SetList2", (void (StepData_Field::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer)) &StepData_Field::SetList2, "Declares a field as an homogeneous square list, with initial sizes, and initial lowers", py::arg("siz1"), py::arg("siz2"), py::arg("f1"), py::arg("f2"));
cls_StepData_Field.def("Set", (void (StepData_Field::*)(const opencascade::handle<Standard_Transient> &)) &StepData_Field::Set, "Sets an undetermined value : can be String, SelectMember, HArray(1-2) ... else, an Entity In case of an HArray, determines and records its size(s)", py::arg("val"));
cls_StepData_Field.def("ClearItem", (void (StepData_Field::*)(const Standard_Integer)) &StepData_Field::ClearItem, "Declares an item of the list as undefined (ignored if list not defined as String,Entity or Any)", py::arg("num"));
cls_StepData_Field.def("SetInt", (void (StepData_Field::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer)) &StepData_Field::SetInt, "Internal access to an Integer Value for a list, plus its kind", py::arg("num"), py::arg("val"), py::arg("kind"));
cls_StepData_Field.def("SetInteger", (void (StepData_Field::*)(const Standard_Integer, const Standard_Integer)) &StepData_Field::SetInteger, "Sets an Integer Value for a list (rank num) (recognizes a SelectMember)", py::arg("num"), py::arg("val"));
cls_StepData_Field.def("SetBoolean", (void (StepData_Field::*)(const Standard_Integer, const Standard_Boolean)) &StepData_Field::SetBoolean, "None", py::arg("num"), py::arg("val"));
cls_StepData_Field.def("SetLogical", (void (StepData_Field::*)(const Standard_Integer, const StepData_Logical)) &StepData_Field::SetLogical, "None", py::arg("num"), py::arg("val"));
cls_StepData_Field.def("SetEnum", [](StepData_Field &self, const Standard_Integer a0, const Standard_Integer a1) -> void { return self.SetEnum(a0, a1); });
cls_StepData_Field.def("SetEnum", (void (StepData_Field::*)(const Standard_Integer, const Standard_Integer, const Standard_CString)) &StepData_Field::SetEnum, "Sets an Enum Value (Integer counterpart), also its text expression if known (if list has been set as 'any')", py::arg("num"), py::arg("val"), py::arg("text"));
cls_StepData_Field.def("SetReal", (void (StepData_Field::*)(const Standard_Integer, const Standard_Real)) &StepData_Field::SetReal, "None", py::arg("num"), py::arg("val"));
cls_StepData_Field.def("SetString", (void (StepData_Field::*)(const Standard_Integer, const Standard_CString)) &StepData_Field::SetString, "None", py::arg("num"), py::arg("val"));
cls_StepData_Field.def("SetEntity", (void (StepData_Field::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &)) &StepData_Field::SetEntity, "None", py::arg("num"), py::arg("val"));
cls_StepData_Field.def("IsSet", [](StepData_Field &self) -> Standard_Boolean { return self.IsSet(); });
cls_StepData_Field.def("IsSet", [](StepData_Field &self, const Standard_Integer a0) -> Standard_Boolean { return self.IsSet(a0); });
cls_StepData_Field.def("IsSet", (Standard_Boolean (StepData_Field::*)(const Standard_Integer, const Standard_Integer) const) &StepData_Field::IsSet, "None", py::arg("n1"), py::arg("n2"));
cls_StepData_Field.def("ItemKind", [](StepData_Field &self) -> Standard_Integer { return self.ItemKind(); });
cls_StepData_Field.def("ItemKind", [](StepData_Field &self, const Standard_Integer a0) -> Standard_Integer { return self.ItemKind(a0); });
cls_StepData_Field.def("ItemKind", (Standard_Integer (StepData_Field::*)(const Standard_Integer, const Standard_Integer) const) &StepData_Field::ItemKind, "Returns the kind of an item in a list or double list It is the kind of the list, except if it is 'Any', in such a case the true kind is determined and returned", py::arg("n1"), py::arg("n2"));
cls_StepData_Field.def("Kind", [](StepData_Field &self) -> Standard_Integer { return self.Kind(); });
cls_StepData_Field.def("Kind", (Standard_Integer (StepData_Field::*)(const Standard_Boolean) const) &StepData_Field::Kind, "Returns the kind of the field <type> True (D) : returns only the type itself else, returns the complete kind", py::arg("type"));
cls_StepData_Field.def("Arity", (Standard_Integer (StepData_Field::*)() const) &StepData_Field::Arity, "None");
cls_StepData_Field.def("Length", [](StepData_Field &self) -> Standard_Integer { return self.Length(); });
cls_StepData_Field.def("Length", (Standard_Integer (StepData_Field::*)(const Standard_Integer) const) &StepData_Field::Length, "None", py::arg("index"));
cls_StepData_Field.def("Lower", [](StepData_Field &self) -> Standard_Integer { return self.Lower(); });
cls_StepData_Field.def("Lower", (Standard_Integer (StepData_Field::*)(const Standard_Integer) const) &StepData_Field::Lower, "None", py::arg("index"));
cls_StepData_Field.def("Int", (Standard_Integer (StepData_Field::*)() const) &StepData_Field::Int, "None");
cls_StepData_Field.def("Integer", [](StepData_Field &self) -> Standard_Integer { return self.Integer(); });
cls_StepData_Field.def("Integer", [](StepData_Field &self, const Standard_Integer a0) -> Standard_Integer { return self.Integer(a0); });
cls_StepData_Field.def("Integer", (Standard_Integer (StepData_Field::*)(const Standard_Integer, const Standard_Integer) const) &StepData_Field::Integer, "None", py::arg("n1"), py::arg("n2"));
cls_StepData_Field.def("Boolean", [](StepData_Field &self) -> Standard_Boolean { return self.Boolean(); });
cls_StepData_Field.def("Boolean", [](StepData_Field &self, const Standard_Integer a0) -> Standard_Boolean { return self.Boolean(a0); });
cls_StepData_Field.def("Boolean", (Standard_Boolean (StepData_Field::*)(const Standard_Integer, const Standard_Integer) const) &StepData_Field::Boolean, "None", py::arg("n1"), py::arg("n2"));
cls_StepData_Field.def("Logical", [](StepData_Field &self) -> StepData_Logical { return self.Logical(); });
cls_StepData_Field.def("Logical", [](StepData_Field &self, const Standard_Integer a0) -> StepData_Logical { return self.Logical(a0); });
cls_StepData_Field.def("Logical", (StepData_Logical (StepData_Field::*)(const Standard_Integer, const Standard_Integer) const) &StepData_Field::Logical, "None", py::arg("n1"), py::arg("n2"));
cls_StepData_Field.def("Real", [](StepData_Field &self) -> Standard_Real { return self.Real(); });
cls_StepData_Field.def("Real", [](StepData_Field &self, const Standard_Integer a0) -> Standard_Real { return self.Real(a0); });
cls_StepData_Field.def("Real", (Standard_Real (StepData_Field::*)(const Standard_Integer, const Standard_Integer) const) &StepData_Field::Real, "None", py::arg("n1"), py::arg("n2"));
cls_StepData_Field.def("String", [](StepData_Field &self) -> Standard_CString { return self.String(); });
cls_StepData_Field.def("String", [](StepData_Field &self, const Standard_Integer a0) -> Standard_CString { return self.String(a0); });
cls_StepData_Field.def("String", (Standard_CString (StepData_Field::*)(const Standard_Integer, const Standard_Integer) const) &StepData_Field::String, "None", py::arg("n1"), py::arg("n2"));
cls_StepData_Field.def("Enum", [](StepData_Field &self) -> Standard_Integer { return self.Enum(); });
cls_StepData_Field.def("Enum", [](StepData_Field &self, const Standard_Integer a0) -> Standard_Integer { return self.Enum(a0); });
cls_StepData_Field.def("Enum", (Standard_Integer (StepData_Field::*)(const Standard_Integer, const Standard_Integer) const) &StepData_Field::Enum, "None", py::arg("n1"), py::arg("n2"));
cls_StepData_Field.def("EnumText", [](StepData_Field &self) -> Standard_CString { return self.EnumText(); });
cls_StepData_Field.def("EnumText", [](StepData_Field &self, const Standard_Integer a0) -> Standard_CString { return self.EnumText(a0); });
cls_StepData_Field.def("EnumText", (Standard_CString (StepData_Field::*)(const Standard_Integer, const Standard_Integer) const) &StepData_Field::EnumText, "None", py::arg("n1"), py::arg("n2"));
cls_StepData_Field.def("Entity", [](StepData_Field &self) -> opencascade::handle<Standard_Transient> { return self.Entity(); });
cls_StepData_Field.def("Entity", [](StepData_Field &self, const Standard_Integer a0) -> opencascade::handle<Standard_Transient> { return self.Entity(a0); });
cls_StepData_Field.def("Entity", (opencascade::handle<Standard_Transient> (StepData_Field::*)(const Standard_Integer, const Standard_Integer) const) &StepData_Field::Entity, "None", py::arg("n1"), py::arg("n2"));
cls_StepData_Field.def("Transient", (opencascade::handle<Standard_Transient> (StepData_Field::*)() const) &StepData_Field::Transient, "None");

// Enums

}