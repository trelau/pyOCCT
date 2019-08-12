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
#include <MoniTool_ValueType.hxx>
#include <Standard_Handle.hxx>
#include <MoniTool_TypedValue.hxx>
#include <MoniTool_ValueInterpret.hxx>
#include <MoniTool_ValueSatisfies.hxx>
#include <NCollection_DataMap.hxx>
#include <TCollection_AsciiString.hxx>
#include <Message_Messenger.hxx>
#include <Standard_Type.hxx>
#include <TCollection_HAsciiString.hxx>
#include <TColStd_HSequenceOfAsciiString.hxx>
#include <TColStd_HArray1OfAsciiString.hxx>

void bind_MoniTool_TypedValue(py::module &mod){

py::class_<MoniTool_TypedValue, opencascade::handle<MoniTool_TypedValue>, Standard_Transient> cls_MoniTool_TypedValue(mod, "MoniTool_TypedValue", "This class allows to dynamically manage .. typed values, i.e. values which have an alphanumeric expression, but with controls. Such as 'must be an Integer' or 'Enumerative Text' etc");

// Constructors
cls_MoniTool_TypedValue.def(py::init<const Standard_CString>(), py::arg("name"));
cls_MoniTool_TypedValue.def(py::init<const Standard_CString, const MoniTool_ValueType>(), py::arg("name"), py::arg("type"));
cls_MoniTool_TypedValue.def(py::init<const Standard_CString, const MoniTool_ValueType, const Standard_CString>(), py::arg("name"), py::arg("type"), py::arg("init"));
cls_MoniTool_TypedValue.def(py::init<const opencascade::handle<MoniTool_TypedValue> &>(), py::arg("other"));

// Fields

// Methods
// cls_MoniTool_TypedValue.def("Internals", [](MoniTool_TypedValue &self, MoniTool_ValueInterpret & interp, MoniTool_ValueSatisfies & satisf, Standard_CString & satisname, NCollection_DataMap<TCollection_AsciiString, Standard_Integer> & enums){ self.Internals(interp, satisf, satisname, enums); return satisname; }, "Access to internal data which have no other access", py::arg("interp"), py::arg("satisf"), py::arg("satisname"), py::arg("enums"));
cls_MoniTool_TypedValue.def("Name", (Standard_CString (MoniTool_TypedValue::*)() const) &MoniTool_TypedValue::Name, "Returns the name");
cls_MoniTool_TypedValue.def("ValueType", (MoniTool_ValueType (MoniTool_TypedValue::*)() const) &MoniTool_TypedValue::ValueType, "Returns the type of the value");
cls_MoniTool_TypedValue.def("Definition", (TCollection_AsciiString (MoniTool_TypedValue::*)() const) &MoniTool_TypedValue::Definition, "Returns the Definition By priority, the enforced one, else an automatic one, computed from the specification");
cls_MoniTool_TypedValue.def("SetDefinition", (void (MoniTool_TypedValue::*)(const Standard_CString)) &MoniTool_TypedValue::SetDefinition, "Enforces a Definition", py::arg("deftext"));
cls_MoniTool_TypedValue.def("Print", (void (MoniTool_TypedValue::*)(const opencascade::handle<Message_Messenger> &) const) &MoniTool_TypedValue::Print, "Prints definition, specification, and actual status and value", py::arg("S"));
cls_MoniTool_TypedValue.def("PrintValue", (void (MoniTool_TypedValue::*)(const opencascade::handle<Message_Messenger> &) const) &MoniTool_TypedValue::PrintValue, "Prints only the Value", py::arg("S"));
cls_MoniTool_TypedValue.def("AddDef", (Standard_Boolean (MoniTool_TypedValue::*)(const Standard_CString)) &MoniTool_TypedValue::AddDef, "Completes the definition of a TypedValue by command <initext>, once created with its type Returns True if done, False if could not be interpreted <initext> may be : imin ival : minimum value for an integer imax ival : maximum value for an integer rmin rval : minimum value for a real rmax rval : maximum value for a real unit name : name of unit ematch i : enum from integer value i, match required enum i : enum from integer value i, match not required eval text : add an enumerative value (increments max by 1) eval ?? : add a non-authorised enum value (to be skipped) tmax l : maximum length for a text", py::arg("initext"));
cls_MoniTool_TypedValue.def("SetLabel", (void (MoniTool_TypedValue::*)(const Standard_CString)) &MoniTool_TypedValue::SetLabel, "Sets a label, which can then be displayed", py::arg("label"));
cls_MoniTool_TypedValue.def("Label", (Standard_CString (MoniTool_TypedValue::*)() const) &MoniTool_TypedValue::Label, "Returns the label, if set; else returns an empty string");
cls_MoniTool_TypedValue.def("SetMaxLength", (void (MoniTool_TypedValue::*)(const Standard_Integer)) &MoniTool_TypedValue::SetMaxLength, "Sets a maximum length for a text (active only for a free text)", py::arg("max"));
cls_MoniTool_TypedValue.def("MaxLength", (Standard_Integer (MoniTool_TypedValue::*)() const) &MoniTool_TypedValue::MaxLength, "Returns the maximum length, 0 if not set");
cls_MoniTool_TypedValue.def("SetIntegerLimit", (void (MoniTool_TypedValue::*)(const Standard_Boolean, const Standard_Integer)) &MoniTool_TypedValue::SetIntegerLimit, "Sets an Integer limit (included) to <val>, the upper limit if <max> is True, the lower limit if <max> is False", py::arg("max"), py::arg("val"));
cls_MoniTool_TypedValue.def("IntegerLimit", [](MoniTool_TypedValue &self, const Standard_Boolean max, Standard_Integer & val){ Standard_Boolean rv = self.IntegerLimit(max, val); return std::tuple<Standard_Boolean, Standard_Integer &>(rv, val); }, "Gives an Integer Limit (upper if <max> True, lower if <max> False). Returns True if this limit is defined, False else (in that case, gives the natural limit for Integer)", py::arg("max"), py::arg("val"));
cls_MoniTool_TypedValue.def("SetRealLimit", (void (MoniTool_TypedValue::*)(const Standard_Boolean, const Standard_Real)) &MoniTool_TypedValue::SetRealLimit, "Sets a Real limit (included) to <val>, the upper limit if <max> is True, the lower limit if <max> is False", py::arg("max"), py::arg("val"));
cls_MoniTool_TypedValue.def("RealLimit", [](MoniTool_TypedValue &self, const Standard_Boolean max, Standard_Real & val){ Standard_Boolean rv = self.RealLimit(max, val); return std::tuple<Standard_Boolean, Standard_Real &>(rv, val); }, "Gives an Real Limit (upper if <max> True, lower if <max> False). Returns True if this limit is defined, False else (in that case, gives the natural limit for Real)", py::arg("max"), py::arg("val"));
cls_MoniTool_TypedValue.def("SetUnitDef", (void (MoniTool_TypedValue::*)(const Standard_CString)) &MoniTool_TypedValue::SetUnitDef, "Sets (Clears if <def> empty) a unit definition, as an equation of dimensions. TypedValue just records this definition, does not exploit it, to be done as required by user applications", py::arg("def"));
cls_MoniTool_TypedValue.def("UnitDef", (Standard_CString (MoniTool_TypedValue::*)() const) &MoniTool_TypedValue::UnitDef, "Returns the recorded unit definition, empty if not set");
cls_MoniTool_TypedValue.def("StartEnum", [](MoniTool_TypedValue &self) -> void { return self.StartEnum(); });
cls_MoniTool_TypedValue.def("StartEnum", [](MoniTool_TypedValue &self, const Standard_Integer a0) -> void { return self.StartEnum(a0); });
cls_MoniTool_TypedValue.def("StartEnum", (void (MoniTool_TypedValue::*)(const Standard_Integer, const Standard_Boolean)) &MoniTool_TypedValue::StartEnum, "For an enumeration, precises the starting value (default 0) and the match condition : if True (D), the string value must match the definition, else it may take another value : in that case, the Integer Value will be Start - 1. (empty value remains allowed)", py::arg("start"), py::arg("match"));
cls_MoniTool_TypedValue.def("AddEnum", [](MoniTool_TypedValue &self) -> void { return self.AddEnum(); });
cls_MoniTool_TypedValue.def("AddEnum", [](MoniTool_TypedValue &self, const Standard_CString a0) -> void { return self.AddEnum(a0); });
cls_MoniTool_TypedValue.def("AddEnum", [](MoniTool_TypedValue &self, const Standard_CString a0, const Standard_CString a1) -> void { return self.AddEnum(a0, a1); });
cls_MoniTool_TypedValue.def("AddEnum", [](MoniTool_TypedValue &self, const Standard_CString a0, const Standard_CString a1, const Standard_CString a2) -> void { return self.AddEnum(a0, a1, a2); });
cls_MoniTool_TypedValue.def("AddEnum", [](MoniTool_TypedValue &self, const Standard_CString a0, const Standard_CString a1, const Standard_CString a2, const Standard_CString a3) -> void { return self.AddEnum(a0, a1, a2, a3); });
cls_MoniTool_TypedValue.def("AddEnum", [](MoniTool_TypedValue &self, const Standard_CString a0, const Standard_CString a1, const Standard_CString a2, const Standard_CString a3, const Standard_CString a4) -> void { return self.AddEnum(a0, a1, a2, a3, a4); });
cls_MoniTool_TypedValue.def("AddEnum", [](MoniTool_TypedValue &self, const Standard_CString a0, const Standard_CString a1, const Standard_CString a2, const Standard_CString a3, const Standard_CString a4, const Standard_CString a5) -> void { return self.AddEnum(a0, a1, a2, a3, a4, a5); });
cls_MoniTool_TypedValue.def("AddEnum", [](MoniTool_TypedValue &self, const Standard_CString a0, const Standard_CString a1, const Standard_CString a2, const Standard_CString a3, const Standard_CString a4, const Standard_CString a5, const Standard_CString a6) -> void { return self.AddEnum(a0, a1, a2, a3, a4, a5, a6); });
cls_MoniTool_TypedValue.def("AddEnum", [](MoniTool_TypedValue &self, const Standard_CString a0, const Standard_CString a1, const Standard_CString a2, const Standard_CString a3, const Standard_CString a4, const Standard_CString a5, const Standard_CString a6, const Standard_CString a7) -> void { return self.AddEnum(a0, a1, a2, a3, a4, a5, a6, a7); });
cls_MoniTool_TypedValue.def("AddEnum", [](MoniTool_TypedValue &self, const Standard_CString a0, const Standard_CString a1, const Standard_CString a2, const Standard_CString a3, const Standard_CString a4, const Standard_CString a5, const Standard_CString a6, const Standard_CString a7, const Standard_CString a8) -> void { return self.AddEnum(a0, a1, a2, a3, a4, a5, a6, a7, a8); });
cls_MoniTool_TypedValue.def("AddEnum", (void (MoniTool_TypedValue::*)(const Standard_CString, const Standard_CString, const Standard_CString, const Standard_CString, const Standard_CString, const Standard_CString, const Standard_CString, const Standard_CString, const Standard_CString, const Standard_CString)) &MoniTool_TypedValue::AddEnum, "Adds enumerative definitions. For more than 10, several calls", py::arg("v1"), py::arg("v2"), py::arg("v3"), py::arg("v4"), py::arg("v5"), py::arg("v6"), py::arg("v7"), py::arg("v8"), py::arg("v9"), py::arg("v10"));
cls_MoniTool_TypedValue.def("AddEnumValue", (void (MoniTool_TypedValue::*)(const Standard_CString, const Standard_Integer)) &MoniTool_TypedValue::AddEnumValue, "Adds an enumeration definition, by its string and numeric values. If it is the first setting for this value, it is recorded as main value. Else, it is recognized as alternate string for this numeric value", py::arg("val"), py::arg("num"));
cls_MoniTool_TypedValue.def("EnumDef", [](MoniTool_TypedValue &self, Standard_Integer & startcase, Standard_Integer & endcase, Standard_Boolean & match){ Standard_Boolean rv = self.EnumDef(startcase, endcase, match); return std::tuple<Standard_Boolean, Standard_Integer &, Standard_Integer &, Standard_Boolean &>(rv, startcase, endcase, match); }, "Gives the Enum definitions : start value, end value, match status. Returns True for an Enum, False else.", py::arg("startcase"), py::arg("endcase"), py::arg("match"));
cls_MoniTool_TypedValue.def("EnumVal", (Standard_CString (MoniTool_TypedValue::*)(const Standard_Integer) const) &MoniTool_TypedValue::EnumVal, "Returns the value of an enumerative definition, from its rank Empty string if out of range or not an Enum", py::arg("num"));
cls_MoniTool_TypedValue.def("EnumCase", (Standard_Integer (MoniTool_TypedValue::*)(const Standard_CString) const) &MoniTool_TypedValue::EnumCase, "Returns the case number which cooresponds to a string value Works with main and additionnal values Returns (StartEnum - 1) if not OK, -1 if not an Enum", py::arg("val"));
cls_MoniTool_TypedValue.def("SetObjectType", (void (MoniTool_TypedValue::*)(const opencascade::handle<Standard_Type> &)) &MoniTool_TypedValue::SetObjectType, "Sets type of which an Object TypedValue must be kind of Error for a TypedValue not an Object (Entity)", py::arg("typ"));
cls_MoniTool_TypedValue.def("ObjectType", (opencascade::handle<Standard_Type> (MoniTool_TypedValue::*)() const) &MoniTool_TypedValue::ObjectType, "Returns the type of which an Object TypedValue must be kind of Default is Standard_Transient Null for a TypedValue not an Object");
cls_MoniTool_TypedValue.def("SetInterpret", (void (MoniTool_TypedValue::*)(const MoniTool_ValueInterpret)) &MoniTool_TypedValue::SetInterpret, "Sets a specific Interpret function", py::arg("func"));
cls_MoniTool_TypedValue.def("HasInterpret", (Standard_Boolean (MoniTool_TypedValue::*)() const) &MoniTool_TypedValue::HasInterpret, "Tells if a TypedValue has an Interpret");
cls_MoniTool_TypedValue.def("SetSatisfies", (void (MoniTool_TypedValue::*)(const MoniTool_ValueSatisfies, const Standard_CString)) &MoniTool_TypedValue::SetSatisfies, "Sets a specific Satisfies function : it is added to the already defined criteria It must match the form : statisfies (val : HAsciiString) returns Boolean", py::arg("func"), py::arg("name"));
cls_MoniTool_TypedValue.def("SatisfiesName", (Standard_CString (MoniTool_TypedValue::*)() const) &MoniTool_TypedValue::SatisfiesName, "Returns name of specific satisfy, empty string if none");
cls_MoniTool_TypedValue.def("IsSetValue", (Standard_Boolean (MoniTool_TypedValue::*)() const) &MoniTool_TypedValue::IsSetValue, "Returns True if the value is set (not empty/not null object)");
cls_MoniTool_TypedValue.def("CStringValue", (Standard_CString (MoniTool_TypedValue::*)() const) &MoniTool_TypedValue::CStringValue, "Returns the value, as a cstring. Empty if not set.");
cls_MoniTool_TypedValue.def("HStringValue", (opencascade::handle<TCollection_HAsciiString> (MoniTool_TypedValue::*)() const) &MoniTool_TypedValue::HStringValue, "Returns the value, as a Handle (can then be shared) Null if not defined");
cls_MoniTool_TypedValue.def("Interpret", (opencascade::handle<TCollection_HAsciiString> (MoniTool_TypedValue::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean) const) &MoniTool_TypedValue::Interpret, "Interprets a value. <native> True : returns a native value <native> False : returns a coded value If the Interpret function is set, calls it Else, for an Enum, Native returns the Text, Coded returns the number STANDARD RETURNS : = hval means no specific interpretation Null means senseless Can also be redefined", py::arg("hval"), py::arg("native"));
cls_MoniTool_TypedValue.def("Satisfies", (Standard_Boolean (MoniTool_TypedValue::*)(const opencascade::handle<TCollection_HAsciiString> &) const) &MoniTool_TypedValue::Satisfies, "Returns True if a value statifies the specification (remark : does not apply to Entity : see ObjectType, for this type, the string is just a comment)", py::arg("hval"));
cls_MoniTool_TypedValue.def("ClearValue", (void (MoniTool_TypedValue::*)()) &MoniTool_TypedValue::ClearValue, "Clears the recorded Value : it is now unset");
cls_MoniTool_TypedValue.def("SetCStringValue", (Standard_Boolean (MoniTool_TypedValue::*)(const Standard_CString)) &MoniTool_TypedValue::SetCStringValue, "Changes the value. The new one must satisfy the specification Returns False (and did not set) if the new value does not satisfy the specification Can be redefined to be managed (in a subclass)", py::arg("val"));
cls_MoniTool_TypedValue.def("SetHStringValue", (Standard_Boolean (MoniTool_TypedValue::*)(const opencascade::handle<TCollection_HAsciiString> &)) &MoniTool_TypedValue::SetHStringValue, "Forces a new Handle for the Value It can be empty, else (if Type is not free Text), it must satisfy the specification. Not only the value is changed, but also the way it is shared Remark : for Type=Object, this value is not controlled, it can be set as a comment Returns False (and did not set) if the new value does not satisfy the specification Can be redefined to be managed (in a subclass)", py::arg("hval"));
cls_MoniTool_TypedValue.def("IntegerValue", (Standard_Integer (MoniTool_TypedValue::*)() const) &MoniTool_TypedValue::IntegerValue, "Returns the value as integer, i.e. : For type = Integer, the integer itself; 0 if not set For type = Enum, the designated rank (see Enum definition) StartEnum - 1 if not set or not in the definition Else, returns 0");
cls_MoniTool_TypedValue.def("SetIntegerValue", (Standard_Boolean (MoniTool_TypedValue::*)(const Standard_Integer)) &MoniTool_TypedValue::SetIntegerValue, "Changes the value as an integer, only for Integer or Enum", py::arg("ival"));
cls_MoniTool_TypedValue.def("RealValue", (Standard_Real (MoniTool_TypedValue::*)() const) &MoniTool_TypedValue::RealValue, "Returns the value as real, for a Real type TypedValue Else, returns 0.");
cls_MoniTool_TypedValue.def("SetRealValue", (Standard_Boolean (MoniTool_TypedValue::*)(const Standard_Real)) &MoniTool_TypedValue::SetRealValue, "Changes the value as a real, only for Real", py::arg("rval"));
cls_MoniTool_TypedValue.def("ObjectValue", (opencascade::handle<Standard_Transient> (MoniTool_TypedValue::*)() const) &MoniTool_TypedValue::ObjectValue, "Returns the value as Transient Object, only for Object/Entity Remark that the 'HString value' is IGNORED here Null if not set; remains to be casted");
cls_MoniTool_TypedValue.def("GetObjectValue", (void (MoniTool_TypedValue::*)(opencascade::handle<Standard_Transient> &) const) &MoniTool_TypedValue::GetObjectValue, "Same as ObjectValue, but avoids DownCast : the receiving variable is directly loaded. It is assumed that it complies with the definition of ObjectType ! Otherwise, big trouble", py::arg("val"));
cls_MoniTool_TypedValue.def("SetObjectValue", (Standard_Boolean (MoniTool_TypedValue::*)(const opencascade::handle<Standard_Transient> &)) &MoniTool_TypedValue::SetObjectValue, "Changes the value as Transient Object, only for Object/Entity Returns False if DynamicType does not satisfy ObjectType Can be redefined to be managed (in a subclass)", py::arg("obj"));
cls_MoniTool_TypedValue.def("ObjectTypeName", (Standard_CString (MoniTool_TypedValue::*)() const) &MoniTool_TypedValue::ObjectTypeName, "Returns the type name of the ObjectValue, or an empty string if not set");
cls_MoniTool_TypedValue.def_static("AddLib_", [](const opencascade::handle<MoniTool_TypedValue> & a0) -> Standard_Boolean { return MoniTool_TypedValue::AddLib(a0); });
cls_MoniTool_TypedValue.def_static("AddLib_", (Standard_Boolean (*)(const opencascade::handle<MoniTool_TypedValue> &, const Standard_CString)) &MoniTool_TypedValue::AddLib, "Adds a TypedValue in the library. It is recorded then will be accessed by its Name Its Definition may be imposed, else it is computed as usual By default it will be accessed by its Definition (string) Returns True if done, False if tv is Null or brings no Definition or <def> not defined", py::arg("tv"), py::arg("def"));
cls_MoniTool_TypedValue.def_static("Lib_", (opencascade::handle<MoniTool_TypedValue> (*)(const Standard_CString)) &MoniTool_TypedValue::Lib, "Returns the TypedValue bound with a given Name Null Handle if none recorded Warning : it is the original, not duplicated", py::arg("def"));
cls_MoniTool_TypedValue.def_static("FromLib_", (opencascade::handle<MoniTool_TypedValue> (*)(const Standard_CString)) &MoniTool_TypedValue::FromLib, "Returns a COPY of the TypedValue bound with a given Name Null Handle if none recorded", py::arg("def"));
cls_MoniTool_TypedValue.def_static("LibList_", (opencascade::handle<TColStd_HSequenceOfAsciiString> (*)()) &MoniTool_TypedValue::LibList, "Returns the list of names of items of the Library of Types -- Library of TypedValue as Valued Parameters, -- -- accessed by parameter name for use by management of Static Parameters");
cls_MoniTool_TypedValue.def_static("StaticValue_", (opencascade::handle<MoniTool_TypedValue> (*)(const Standard_CString)) &MoniTool_TypedValue::StaticValue, "Returns a static value from its name, null if unknown", py::arg("name"));
cls_MoniTool_TypedValue.def_static("get_type_name_", (const char * (*)()) &MoniTool_TypedValue::get_type_name, "None");
cls_MoniTool_TypedValue.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MoniTool_TypedValue::get_type_descriptor, "None");
cls_MoniTool_TypedValue.def("DynamicType", (const opencascade::handle<Standard_Type> & (MoniTool_TypedValue::*)() const) &MoniTool_TypedValue::DynamicType, "None");

// Enums

}