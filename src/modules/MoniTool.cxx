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
#include <MoniTool_ValueType.hxx>
#include <Standard_Transient.hxx>
#include <Standard_TypeDef.hxx>
#include <TCollection_AsciiString.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Std.hxx>
#include <MoniTool_SignText.hxx>
#include <Standard_Type.hxx>
#include <TCollection_HAsciiString.hxx>
#include <MoniTool_TypedValue.hxx>
#include <MoniTool_ValueInterpret.hxx>
#include <MoniTool_ValueSatisfies.hxx>
#include <NCollection_DataMap.hxx>
#include <Message_Messenger.hxx>
#include <TColStd_HSequenceOfAsciiString.hxx>
#include <TColStd_HArray1OfAsciiString.hxx>
#include <Standard.hxx>
#include <MoniTool_AttrList.hxx>
#include <Standard_Failure.hxx>
#include <TopoDS_Shape.hxx>
#include <gp_XYZ.hxx>
#include <gp_XY.hxx>
#include <Message_Msg.hxx>
#include <MoniTool_CaseData.hxx>
#include <TColStd_SequenceOfTransient.hxx>
#include <TColStd_SequenceOfInteger.hxx>
#include <TColStd_SequenceOfAsciiString.hxx>
#include <MoniTool_DataInfo.hxx>
#include <TopTools_ShapeMapHasher.hxx>
#include <MoniTool_DataMapOfShapeTransient.hxx>
#include <MoniTool_MTHasher.hxx>
#include <MoniTool_Timer.hxx>
#include <MoniTool_DataMapOfTimer.hxx>
#include <MoniTool_Element.hxx>
#include <MoniTool_ElemHasher.hxx>
#include <NCollection_Sequence.hxx>
#include <MoniTool_SequenceOfElement.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <MoniTool_HSequenceOfElement.hxx>
#include <NCollection_IndexedDataMap.hxx>
#include <MoniTool_IndexedDataMapOfShapeTransient.hxx>
#include <MoniTool_IntVal.hxx>
#include <MoniTool_RealVal.hxx>
#include <MoniTool_SignShape.hxx>
#include <MoniTool_Stat.hxx>
#include <TColStd_HArray1OfInteger.hxx>
#include <OSD_Timer.hxx>
#include <Standard_OStream.hxx>
#include <MoniTool_TimerSentry.hxx>
#include <MoniTool_TransientElem.hxx>
#include <bind_NCollection_DataMap.hxx>
#include <bind_NCollection_Sequence.hxx>
#include <bind_NCollection_IndexedDataMap.hxx>

PYBIND11_MODULE(MoniTool, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.Message");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.gp");
py::module::import("OCCT.TopTools");
py::module::import("OCCT.OSD");

// ENUM: MONITOOL_VALUETYPE
py::enum_<MoniTool_ValueType>(mod, "MoniTool_ValueType", "None")
	.value("MoniTool_ValueMisc", MoniTool_ValueType::MoniTool_ValueMisc)
	.value("MoniTool_ValueInteger", MoniTool_ValueType::MoniTool_ValueInteger)
	.value("MoniTool_ValueReal", MoniTool_ValueType::MoniTool_ValueReal)
	.value("MoniTool_ValueIdent", MoniTool_ValueType::MoniTool_ValueIdent)
	.value("MoniTool_ValueVoid", MoniTool_ValueType::MoniTool_ValueVoid)
	.value("MoniTool_ValueText", MoniTool_ValueType::MoniTool_ValueText)
	.value("MoniTool_ValueEnum", MoniTool_ValueType::MoniTool_ValueEnum)
	.value("MoniTool_ValueLogical", MoniTool_ValueType::MoniTool_ValueLogical)
	.value("MoniTool_ValueSub", MoniTool_ValueType::MoniTool_ValueSub)
	.value("MoniTool_ValueHexa", MoniTool_ValueType::MoniTool_ValueHexa)
	.value("MoniTool_ValueBinary", MoniTool_ValueType::MoniTool_ValueBinary)
	.export_values();


// CLASS: MONITOOL_SIGNTEXT
py::class_<MoniTool_SignText, opencascade::handle<MoniTool_SignText>, Standard_Transient> cls_MoniTool_SignText(mod, "MoniTool_SignText", "Provides the basic service to get a text which identifies an object in a context It can be used for other classes (general signatures ...) It can also be used to build a message in which an object is to be identified");

// Methods
cls_MoniTool_SignText.def("Name", (Standard_CString (MoniTool_SignText::*)() const) &MoniTool_SignText::Name, "Returns an identification of the Signature (a word), given at initialization time");
cls_MoniTool_SignText.def("TextAlone", (TCollection_AsciiString (MoniTool_SignText::*)(const opencascade::handle<Standard_Transient> &) const) &MoniTool_SignText::TextAlone, "Gives a text as a signature for a transient object alone, i.e. without defined context. By default, calls Text with undefined context (Null Handle) and if empty, then returns DynamicType", py::arg("ent"));
cls_MoniTool_SignText.def("Text", (TCollection_AsciiString (MoniTool_SignText::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Standard_Transient> &) const) &MoniTool_SignText::Text, "Gives a text as a signature for a transient object in a context If the context is senseless, it can be given as Null Handle empty result if nothing to give (at least the DynamicType could be sent ?)", py::arg("ent"), py::arg("context"));
cls_MoniTool_SignText.def_static("get_type_name_", (const char * (*)()) &MoniTool_SignText::get_type_name, "None");
cls_MoniTool_SignText.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MoniTool_SignText::get_type_descriptor, "None");
cls_MoniTool_SignText.def("DynamicType", (const opencascade::handle<Standard_Type> & (MoniTool_SignText::*)() const) &MoniTool_SignText::DynamicType, "None");

// TYPEDEF: MONITOOL_VALUEINTERPRET

// TYPEDEF: MONITOOL_VALUESATISFIES

// CLASS: MONITOOL_TYPEDVALUE
py::class_<MoniTool_TypedValue, opencascade::handle<MoniTool_TypedValue>, Standard_Transient> cls_MoniTool_TypedValue(mod, "MoniTool_TypedValue", "This class allows to dynamically manage .. typed values, i.e. values which have an alphanumeric expression, but with controls. Such as 'must be an Integer' or 'Enumerative Text' etc");

// Constructors
cls_MoniTool_TypedValue.def(py::init<const Standard_CString>(), py::arg("name"));
cls_MoniTool_TypedValue.def(py::init<const Standard_CString, const MoniTool_ValueType>(), py::arg("name"), py::arg("type"));
cls_MoniTool_TypedValue.def(py::init<const Standard_CString, const MoniTool_ValueType, const Standard_CString>(), py::arg("name"), py::arg("type"), py::arg("init"));
cls_MoniTool_TypedValue.def(py::init<const opencascade::handle<MoniTool_TypedValue> &>(), py::arg("other"));

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

// CLASS: MONITOOL_ATTRLIST
py::class_<MoniTool_AttrList> cls_MoniTool_AttrList(mod, "MoniTool_AttrList", "a AttrList allows to record a list of attributes as Transients which can be edited, changed ... Each one is identified by a name");

// Constructors
cls_MoniTool_AttrList.def(py::init<>());
cls_MoniTool_AttrList.def(py::init<const MoniTool_AttrList &>(), py::arg("other"));

// Methods
// cls_MoniTool_AttrList.def_static("operator new_", (void * (*)(size_t)) &MoniTool_AttrList::operator new, "None", py::arg("theSize"));
// cls_MoniTool_AttrList.def_static("operator delete_", (void (*)(void *)) &MoniTool_AttrList::operator delete, "None", py::arg("theAddress"));
// cls_MoniTool_AttrList.def_static("operator new[]_", (void * (*)(size_t)) &MoniTool_AttrList::operator new[], "None", py::arg("theSize"));
// cls_MoniTool_AttrList.def_static("operator delete[]_", (void (*)(void *)) &MoniTool_AttrList::operator delete[], "None", py::arg("theAddress"));
// cls_MoniTool_AttrList.def_static("operator new_", (void * (*)(size_t, void *)) &MoniTool_AttrList::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_MoniTool_AttrList.def_static("operator delete_", (void (*)(void *, void *)) &MoniTool_AttrList::operator delete, "None", py::arg(""), py::arg(""));
cls_MoniTool_AttrList.def("SetAttribute", (void (MoniTool_AttrList::*)(const Standard_CString, const opencascade::handle<Standard_Transient> &)) &MoniTool_AttrList::SetAttribute, "Adds an attribute with a given name (replaces the former one with the same name if already exists)", py::arg("name"), py::arg("val"));
cls_MoniTool_AttrList.def("RemoveAttribute", (Standard_Boolean (MoniTool_AttrList::*)(const Standard_CString)) &MoniTool_AttrList::RemoveAttribute, "Removes an attribute Returns True when done, False if this attribute did not exist", py::arg("name"));
cls_MoniTool_AttrList.def("GetAttribute", (Standard_Boolean (MoniTool_AttrList::*)(const Standard_CString, const opencascade::handle<Standard_Type> &, opencascade::handle<Standard_Transient> &) const) &MoniTool_AttrList::GetAttribute, "Returns an attribute from its name, filtered by a type If no attribute has this name, or if it is not kind of this type, <val> is Null and returned value is False Else, it is True", py::arg("name"), py::arg("type"), py::arg("val"));
cls_MoniTool_AttrList.def("Attribute", (opencascade::handle<Standard_Transient> (MoniTool_AttrList::*)(const Standard_CString) const) &MoniTool_AttrList::Attribute, "Returns an attribute from its name. Null Handle if not recorded (whatever Transient, Integer, Real ...) Integer is recorded as IntVal Real is recorded as RealVal Text is recorded as HAsciiString", py::arg("name"));
cls_MoniTool_AttrList.def("AttributeType", (MoniTool_ValueType (MoniTool_AttrList::*)(const Standard_CString) const) &MoniTool_AttrList::AttributeType, "Returns the type of an attribute : ValueInt , ValueReal , ValueText (String) , ValueIdent (any) or ValueVoid (not recorded)", py::arg("name"));
cls_MoniTool_AttrList.def("SetIntegerAttribute", (void (MoniTool_AttrList::*)(const Standard_CString, const Standard_Integer)) &MoniTool_AttrList::SetIntegerAttribute, "Adds an integer value for an attribute", py::arg("name"), py::arg("val"));
cls_MoniTool_AttrList.def("GetIntegerAttribute", [](MoniTool_AttrList &self, const Standard_CString name, Standard_Integer & val){ Standard_Boolean rv = self.GetIntegerAttribute(name, val); return std::tuple<Standard_Boolean, Standard_Integer &>(rv, val); }, "Returns an attribute from its name, as integer If no attribute has this name, or not an integer, <val> is 0 and returned value is False Else, it is True", py::arg("name"), py::arg("val"));
cls_MoniTool_AttrList.def("IntegerAttribute", (Standard_Integer (MoniTool_AttrList::*)(const Standard_CString) const) &MoniTool_AttrList::IntegerAttribute, "Returns an integer attribute from its name. 0 if not recorded", py::arg("name"));
cls_MoniTool_AttrList.def("SetRealAttribute", (void (MoniTool_AttrList::*)(const Standard_CString, const Standard_Real)) &MoniTool_AttrList::SetRealAttribute, "Adds a real value for an attribute", py::arg("name"), py::arg("val"));
cls_MoniTool_AttrList.def("GetRealAttribute", [](MoniTool_AttrList &self, const Standard_CString name, Standard_Real & val){ Standard_Boolean rv = self.GetRealAttribute(name, val); return std::tuple<Standard_Boolean, Standard_Real &>(rv, val); }, "Returns an attribute from its name, as real If no attribute has this name, or not a real <val> is 0.0 and returned value is False Else, it is True", py::arg("name"), py::arg("val"));
cls_MoniTool_AttrList.def("RealAttribute", (Standard_Real (MoniTool_AttrList::*)(const Standard_CString) const) &MoniTool_AttrList::RealAttribute, "Returns a real attribute from its name. 0.0 if not recorded", py::arg("name"));
cls_MoniTool_AttrList.def("SetStringAttribute", (void (MoniTool_AttrList::*)(const Standard_CString, const Standard_CString)) &MoniTool_AttrList::SetStringAttribute, "Adds a String value for an attribute", py::arg("name"), py::arg("val"));
// cls_MoniTool_AttrList.def("GetStringAttribute", [](MoniTool_AttrList &self, const Standard_CString name, Standard_CString & val){ Standard_Boolean rv = self.GetStringAttribute(name, val); return std::tuple<Standard_Boolean, Standard_CString &>(rv, val); }, "Returns an attribute from its name, as String If no attribute has this name, or not a String <val> is 0.0 and returned value is False Else, it is True", py::arg("name"), py::arg("val"));
cls_MoniTool_AttrList.def("StringAttribute", (Standard_CString (MoniTool_AttrList::*)(const Standard_CString) const) &MoniTool_AttrList::StringAttribute, "Returns a String attribute from its name. '' if not recorded", py::arg("name"));
cls_MoniTool_AttrList.def("AttrList", (const NCollection_DataMap<TCollection_AsciiString, opencascade::handle<Standard_Transient> > & (MoniTool_AttrList::*)() const) &MoniTool_AttrList::AttrList, "Returns the exhaustive list of attributes");
cls_MoniTool_AttrList.def("SameAttributes", (void (MoniTool_AttrList::*)(const MoniTool_AttrList &)) &MoniTool_AttrList::SameAttributes, "Gets the list of attributes from <other>, as such, i.e. not copied : attributes are shared, any attribute edited, added, or removed in <other> is also in <me> and vice versa The former list of attributes of <me> is dropped", py::arg("other"));
cls_MoniTool_AttrList.def("GetAttributes", [](MoniTool_AttrList &self, const MoniTool_AttrList & a0) -> void { return self.GetAttributes(a0); });
cls_MoniTool_AttrList.def("GetAttributes", [](MoniTool_AttrList &self, const MoniTool_AttrList & a0, const Standard_CString a1) -> void { return self.GetAttributes(a0, a1); });
cls_MoniTool_AttrList.def("GetAttributes", (void (MoniTool_AttrList::*)(const MoniTool_AttrList &, const Standard_CString, const Standard_Boolean)) &MoniTool_AttrList::GetAttributes, "Gets the list of attributes from <other>, by copying it By default, considers all the attributes from <other> If <fromname> is given, considers only the attributes with name beginning by <fromname>", py::arg("other"), py::arg("fromname"), py::arg("copied"));

// CLASS: MONITOOL_CASEDATA
py::class_<MoniTool_CaseData, opencascade::handle<MoniTool_CaseData>, Standard_Transient> cls_MoniTool_CaseData(mod, "MoniTool_CaseData", "This class is intended to record data attached to a case to be exploited. Cases can be : * internal, i.e. for immediate debug for instance, on an abnormal exception, fill a CaseData in a DB (see class DB) then look at its content by XSDRAW * to record abnormal situation, which cause a warning or fail message, for instance during a transfer This will allow, firstly to build a more comprehensive message (with associated data), secondly to help seeing 'what happened' * to record data in order to fix a problem If a CASE is well defined and its fix is well known too, recording a CaseData which identifies the CASE will allow to furstherly call the appropriate fix routine");

// Constructors
cls_MoniTool_CaseData.def(py::init<>());
cls_MoniTool_CaseData.def(py::init<const Standard_CString>(), py::arg("caseid"));
cls_MoniTool_CaseData.def(py::init<const Standard_CString, const Standard_CString>(), py::arg("caseid"), py::arg("name"));

// Methods
cls_MoniTool_CaseData.def("SetCaseId", (void (MoniTool_CaseData::*)(const Standard_CString)) &MoniTool_CaseData::SetCaseId, "Sets a CaseId", py::arg("caseid"));
cls_MoniTool_CaseData.def("SetName", (void (MoniTool_CaseData::*)(const Standard_CString)) &MoniTool_CaseData::SetName, "Sets a Name", py::arg("name"));
cls_MoniTool_CaseData.def("CaseId", (Standard_CString (MoniTool_CaseData::*)() const) &MoniTool_CaseData::CaseId, "Returns the CaseId");
cls_MoniTool_CaseData.def("Name", (Standard_CString (MoniTool_CaseData::*)() const) &MoniTool_CaseData::Name, "Returns the Name");
cls_MoniTool_CaseData.def("IsCheck", (Standard_Boolean (MoniTool_CaseData::*)() const) &MoniTool_CaseData::IsCheck, "Tells if <me> is Check (Warning or Fail), else it is Info");
cls_MoniTool_CaseData.def("IsWarning", (Standard_Boolean (MoniTool_CaseData::*)() const) &MoniTool_CaseData::IsWarning, "Tells if <me> is Warning");
cls_MoniTool_CaseData.def("IsFail", (Standard_Boolean (MoniTool_CaseData::*)() const) &MoniTool_CaseData::IsFail, "Tells if <me> is Fail");
cls_MoniTool_CaseData.def("ResetCheck", (void (MoniTool_CaseData::*)()) &MoniTool_CaseData::ResetCheck, "Resets Check Status, i.e. sets <me> as Info");
cls_MoniTool_CaseData.def("SetWarning", (void (MoniTool_CaseData::*)()) &MoniTool_CaseData::SetWarning, "Sets <me> as Warning");
cls_MoniTool_CaseData.def("SetFail", (void (MoniTool_CaseData::*)()) &MoniTool_CaseData::SetFail, "Sets <me> as Fail");
cls_MoniTool_CaseData.def("SetChange", (void (MoniTool_CaseData::*)()) &MoniTool_CaseData::SetChange, "Sets the next Add... not to add but to change the data item designated by its name. If next Add... is not called with a name, SetChange is ignored Reset by next Add... , whatever <num> is correct or not");
cls_MoniTool_CaseData.def("SetReplace", (void (MoniTool_CaseData::*)(const Standard_Integer)) &MoniTool_CaseData::SetReplace, "Sets the next Add... not to add but to replace the data item <num>, if <num> is between 1 and NbData. Reset by next Add... , whatever <num> is correct or not", py::arg("num"));
cls_MoniTool_CaseData.def("AddData", [](MoniTool_CaseData &self, const opencascade::handle<Standard_Transient> & a0, const Standard_Integer a1) -> void { return self.AddData(a0, a1); });
cls_MoniTool_CaseData.def("AddData", (void (MoniTool_CaseData::*)(const opencascade::handle<Standard_Transient> &, const Standard_Integer, const Standard_CString)) &MoniTool_CaseData::AddData, "Unitary adding a data; rather internal", py::arg("val"), py::arg("kind"), py::arg("name"));
cls_MoniTool_CaseData.def("AddRaised", [](MoniTool_CaseData &self, const opencascade::handle<Standard_Failure> & a0) -> void { return self.AddRaised(a0); });
cls_MoniTool_CaseData.def("AddRaised", (void (MoniTool_CaseData::*)(const opencascade::handle<Standard_Failure> &, const Standard_CString)) &MoniTool_CaseData::AddRaised, "Adds the currently caught exception", py::arg("theException"), py::arg("name"));
cls_MoniTool_CaseData.def("AddShape", [](MoniTool_CaseData &self, const TopoDS_Shape & a0) -> void { return self.AddShape(a0); });
cls_MoniTool_CaseData.def("AddShape", (void (MoniTool_CaseData::*)(const TopoDS_Shape &, const Standard_CString)) &MoniTool_CaseData::AddShape, "Adds a Shape (recorded as a HShape)", py::arg("sh"), py::arg("name"));
cls_MoniTool_CaseData.def("AddXYZ", [](MoniTool_CaseData &self, const gp_XYZ & a0) -> void { return self.AddXYZ(a0); });
cls_MoniTool_CaseData.def("AddXYZ", (void (MoniTool_CaseData::*)(const gp_XYZ &, const Standard_CString)) &MoniTool_CaseData::AddXYZ, "Adds a XYZ", py::arg("aXYZ"), py::arg("name"));
cls_MoniTool_CaseData.def("AddXY", [](MoniTool_CaseData &self, const gp_XY & a0) -> void { return self.AddXY(a0); });
cls_MoniTool_CaseData.def("AddXY", (void (MoniTool_CaseData::*)(const gp_XY &, const Standard_CString)) &MoniTool_CaseData::AddXY, "Adds a XY", py::arg("aXY"), py::arg("name"));
cls_MoniTool_CaseData.def("AddReal", [](MoniTool_CaseData &self, const Standard_Real a0) -> void { return self.AddReal(a0); });
cls_MoniTool_CaseData.def("AddReal", (void (MoniTool_CaseData::*)(const Standard_Real, const Standard_CString)) &MoniTool_CaseData::AddReal, "Adds a Real", py::arg("val"), py::arg("name"));
cls_MoniTool_CaseData.def("AddReals", [](MoniTool_CaseData &self, const Standard_Real a0, const Standard_Real a1) -> void { return self.AddReals(a0, a1); });
cls_MoniTool_CaseData.def("AddReals", (void (MoniTool_CaseData::*)(const Standard_Real, const Standard_Real, const Standard_CString)) &MoniTool_CaseData::AddReals, "Adds two reals (for instance, two parameters)", py::arg("v1"), py::arg("v2"), py::arg("name"));
cls_MoniTool_CaseData.def("AddCPU", [](MoniTool_CaseData &self, const Standard_Real a0) -> void { return self.AddCPU(a0); });
cls_MoniTool_CaseData.def("AddCPU", [](MoniTool_CaseData &self, const Standard_Real a0, const Standard_Real a1) -> void { return self.AddCPU(a0, a1); });
cls_MoniTool_CaseData.def("AddCPU", (void (MoniTool_CaseData::*)(const Standard_Real, const Standard_Real, const Standard_CString)) &MoniTool_CaseData::AddCPU, "Adds the CPU time between lastCPU and now if <curCPU> is given, the CPU amount is curCPU-lastCPU else it is currently measured CPU - lastCPU lastCPU has been read by call to GetCPU See GetCPU to get amount, and LargeCPU to test large amount", py::arg("lastCPU"), py::arg("curCPU"), py::arg("name"));
cls_MoniTool_CaseData.def("GetCPU", (Standard_Real (MoniTool_CaseData::*)() const) &MoniTool_CaseData::GetCPU, "Returns the current amount of CPU This allows to laterly test and record CPU amount Its value has to be given to LargeCPU and AddCPU");
cls_MoniTool_CaseData.def("LargeCPU", [](MoniTool_CaseData &self, const Standard_Real a0, const Standard_Real a1) -> Standard_Boolean { return self.LargeCPU(a0, a1); });
cls_MoniTool_CaseData.def("LargeCPU", (Standard_Boolean (MoniTool_CaseData::*)(const Standard_Real, const Standard_Real, const Standard_Real) const) &MoniTool_CaseData::LargeCPU, "Tells if a CPU time amount is large <maxCPU> gives the amount over which an amount is large <lastCPU> gives the start CPU amount if <curCPU> is given, the tested CPU amount is curCPU-lastCPU else it is currently measured CPU - lastCPU", py::arg("maxCPU"), py::arg("lastCPU"), py::arg("curCPU"));
cls_MoniTool_CaseData.def("AddGeom", [](MoniTool_CaseData &self, const opencascade::handle<Standard_Transient> & a0) -> void { return self.AddGeom(a0); });
cls_MoniTool_CaseData.def("AddGeom", (void (MoniTool_CaseData::*)(const opencascade::handle<Standard_Transient> &, const Standard_CString)) &MoniTool_CaseData::AddGeom, "Adds a Geometric as a Transient (Curve, Surface ...)", py::arg("geom"), py::arg("name"));
cls_MoniTool_CaseData.def("AddEntity", [](MoniTool_CaseData &self, const opencascade::handle<Standard_Transient> & a0) -> void { return self.AddEntity(a0); });
cls_MoniTool_CaseData.def("AddEntity", (void (MoniTool_CaseData::*)(const opencascade::handle<Standard_Transient> &, const Standard_CString)) &MoniTool_CaseData::AddEntity, "Adds a Transient, as an Entity from an InterfaceModel for instance : it will then be printed with the help of a DBPE", py::arg("ent"), py::arg("name"));
cls_MoniTool_CaseData.def("AddText", [](MoniTool_CaseData &self, const Standard_CString a0) -> void { return self.AddText(a0); });
cls_MoniTool_CaseData.def("AddText", (void (MoniTool_CaseData::*)(const Standard_CString, const Standard_CString)) &MoniTool_CaseData::AddText, "Adds a Text (as HAsciiString)", py::arg("text"), py::arg("name"));
cls_MoniTool_CaseData.def("AddInteger", [](MoniTool_CaseData &self, const Standard_Integer a0) -> void { return self.AddInteger(a0); });
cls_MoniTool_CaseData.def("AddInteger", (void (MoniTool_CaseData::*)(const Standard_Integer, const Standard_CString)) &MoniTool_CaseData::AddInteger, "Adds an Integer", py::arg("val"), py::arg("name"));
cls_MoniTool_CaseData.def("AddAny", [](MoniTool_CaseData &self, const opencascade::handle<Standard_Transient> & a0) -> void { return self.AddAny(a0); });
cls_MoniTool_CaseData.def("AddAny", (void (MoniTool_CaseData::*)(const opencascade::handle<Standard_Transient> &, const Standard_CString)) &MoniTool_CaseData::AddAny, "Adds a Transient, with no more meaning", py::arg("val"), py::arg("name"));
cls_MoniTool_CaseData.def("RemoveData", (void (MoniTool_CaseData::*)(const Standard_Integer)) &MoniTool_CaseData::RemoveData, "Removes a Data from its rank. Does nothing if out of range", py::arg("num"));
cls_MoniTool_CaseData.def("NbData", (Standard_Integer (MoniTool_CaseData::*)() const) &MoniTool_CaseData::NbData, "Returns the count of data recorded to a set");
cls_MoniTool_CaseData.def("Data", (opencascade::handle<Standard_Transient> (MoniTool_CaseData::*)(const Standard_Integer) const) &MoniTool_CaseData::Data, "Returns a data item (n0 <nd> in the set <num>)", py::arg("nd"));
cls_MoniTool_CaseData.def("GetData", (Standard_Boolean (MoniTool_CaseData::*)(const Standard_Integer, const opencascade::handle<Standard_Type> &, opencascade::handle<Standard_Transient> &) const) &MoniTool_CaseData::GetData, "Returns a data item, under control of a Type If the data item is kind of this type, it is returned in <val> and the returned value is True Else, <val> is unchanged and the returned value is False", py::arg("nd"), py::arg("type"), py::arg("val"));
cls_MoniTool_CaseData.def("Kind", (Standard_Integer (MoniTool_CaseData::*)(const Standard_Integer) const) &MoniTool_CaseData::Kind, "Returns the kind of a data : KIND TYPE MEANING 0 ANY any (not one of the followings) 1 EX raised exception 2 EN entity 3 G geom 4 SH shape 5 XYZ XYZ 6 XY or UV XY 7 RR 2 reals 8 R 1 real 9 CPU CPU (1 real) 10 T text 11 I integer", py::arg("nd"));
cls_MoniTool_CaseData.def("Name", (const TCollection_AsciiString & (MoniTool_CaseData::*)(const Standard_Integer) const) &MoniTool_CaseData::Name, "Returns the name of a data. If it has no name, the string is empty (length = 0)", py::arg("nd"));
cls_MoniTool_CaseData.def("NameNum", (Standard_Integer (MoniTool_CaseData::*)(const Standard_CString) const) &MoniTool_CaseData::NameNum, "Returns the first suitable data rank for a given name Exact maching (exact case, no completion) is required Firstly checks the recorded names If not found, considers the name as follows : Name = 'TYPE' : search for the first item with this TYPE Name = 'TYPE:nn' : search for the nn.th item with this TYPE See allowed values in method Kind", py::arg("name"));
cls_MoniTool_CaseData.def("Shape", (TopoDS_Shape (MoniTool_CaseData::*)(const Standard_Integer) const) &MoniTool_CaseData::Shape, "Returns a data as a shape, Null if not a shape", py::arg("nd"));
cls_MoniTool_CaseData.def("XYZ", (Standard_Boolean (MoniTool_CaseData::*)(const Standard_Integer, gp_XYZ &) const) &MoniTool_CaseData::XYZ, "Returns a data as a XYZ (i.e. Geom_CartesianPoint) Returns False if not the good type", py::arg("nd"), py::arg("val"));
cls_MoniTool_CaseData.def("XY", (Standard_Boolean (MoniTool_CaseData::*)(const Standard_Integer, gp_XY &) const) &MoniTool_CaseData::XY, "Returns a data as a XY (i.e. Geom2d_CartesianPoint) Returns False if not the good type", py::arg("nd"), py::arg("val"));
cls_MoniTool_CaseData.def("Reals", [](MoniTool_CaseData &self, const Standard_Integer nd, Standard_Real & v1, Standard_Real & v2){ Standard_Boolean rv = self.Reals(nd, v1, v2); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, v1, v2); }, "Returns a couple of reals (stored in Geom2d_CartesianPoint)", py::arg("nd"), py::arg("v1"), py::arg("v2"));
cls_MoniTool_CaseData.def("Real", [](MoniTool_CaseData &self, const Standard_Integer nd, Standard_Real & val){ Standard_Boolean rv = self.Real(nd, val); return std::tuple<Standard_Boolean, Standard_Real &>(rv, val); }, "Returns a real or CPU amount (stored in Geom2d_CartesianPoint) (allows an Integer converted to a Real)", py::arg("nd"), py::arg("val"));
// cls_MoniTool_CaseData.def("Text", [](MoniTool_CaseData &self, const Standard_Integer nd, Standard_CString & text){ Standard_Boolean rv = self.Text(nd, text); return std::tuple<Standard_Boolean, Standard_CString &>(rv, text); }, "Returns a text (stored in TCollection_HAsciiString)", py::arg("nd"), py::arg("text"));
cls_MoniTool_CaseData.def("Integer", [](MoniTool_CaseData &self, const Standard_Integer nd, Standard_Integer & val){ Standard_Boolean rv = self.Integer(nd, val); return std::tuple<Standard_Boolean, Standard_Integer &>(rv, val); }, "Returns an Integer", py::arg("nd"), py::arg("val"));
cls_MoniTool_CaseData.def("Msg", (Message_Msg (MoniTool_CaseData::*)() const) &MoniTool_CaseData::Msg, "Returns a Msg from a CaseData : it is build from DefMsg, which gives the message code plus the designation of items of the CaseData to be added to the Msg Empty if no message attached");
cls_MoniTool_CaseData.def_static("SetDefWarning_", (void (*)(const Standard_CString)) &MoniTool_CaseData::SetDefWarning, "Sets a Code to give a Warning", py::arg("acode"));
cls_MoniTool_CaseData.def_static("SetDefFail_", (void (*)(const Standard_CString)) &MoniTool_CaseData::SetDefFail, "Sets a Code to give a Fail", py::arg("acode"));
cls_MoniTool_CaseData.def_static("DefCheck_", (Standard_Integer (*)(const Standard_CString)) &MoniTool_CaseData::DefCheck, "Returns Check Status for a Code : 0 non/info (default), 1 warning, 2 fail", py::arg("acode"));
cls_MoniTool_CaseData.def_static("SetDefMsg_", (void (*)(const Standard_CString, const Standard_CString)) &MoniTool_CaseData::SetDefMsg, "Attaches a message definition to a case code This definition includes the message code plus designation of items of the CaseData to be added to the message (this part not yet implemented)", py::arg("casecode"), py::arg("mesdef"));
cls_MoniTool_CaseData.def_static("DefMsg_", (Standard_CString (*)(const Standard_CString)) &MoniTool_CaseData::DefMsg, "Returns the message definition for a case code Empty if no message attached", py::arg("casecode"));
cls_MoniTool_CaseData.def_static("get_type_name_", (const char * (*)()) &MoniTool_CaseData::get_type_name, "None");
cls_MoniTool_CaseData.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MoniTool_CaseData::get_type_descriptor, "None");
cls_MoniTool_CaseData.def("DynamicType", (const opencascade::handle<Standard_Type> & (MoniTool_CaseData::*)() const) &MoniTool_CaseData::DynamicType, "None");

// CLASS: MONITOOL_DATAINFO
py::class_<MoniTool_DataInfo> cls_MoniTool_DataInfo(mod, "MoniTool_DataInfo", "Gives informations on an object Used as template to instantiate Elem, etc This class is for Transient");

// Constructors
cls_MoniTool_DataInfo.def(py::init<>());

// Methods
// cls_MoniTool_DataInfo.def_static("operator new_", (void * (*)(size_t)) &MoniTool_DataInfo::operator new, "None", py::arg("theSize"));
// cls_MoniTool_DataInfo.def_static("operator delete_", (void (*)(void *)) &MoniTool_DataInfo::operator delete, "None", py::arg("theAddress"));
// cls_MoniTool_DataInfo.def_static("operator new[]_", (void * (*)(size_t)) &MoniTool_DataInfo::operator new[], "None", py::arg("theSize"));
// cls_MoniTool_DataInfo.def_static("operator delete[]_", (void (*)(void *)) &MoniTool_DataInfo::operator delete[], "None", py::arg("theAddress"));
// cls_MoniTool_DataInfo.def_static("operator new_", (void * (*)(size_t, void *)) &MoniTool_DataInfo::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_MoniTool_DataInfo.def_static("operator delete_", (void (*)(void *, void *)) &MoniTool_DataInfo::operator delete, "None", py::arg(""), py::arg(""));
cls_MoniTool_DataInfo.def_static("Type_", (opencascade::handle<Standard_Type> (*)(const opencascade::handle<Standard_Transient> &)) &MoniTool_DataInfo::Type, "Returns the Type attached to an object Here, the Dynamic Type of a Transient. Null Type if unknown", py::arg("ent"));
cls_MoniTool_DataInfo.def_static("TypeName_", (Standard_CString (*)(const opencascade::handle<Standard_Transient> &)) &MoniTool_DataInfo::TypeName, "Returns Type Name (string) Allows to name type of non-handled objects", py::arg("ent"));

// TYPEDEF: MONITOOL_DATAMAPOFSHAPETRANSIENT
bind_NCollection_DataMap<TopoDS_Shape, opencascade::handle<Standard_Transient>, TopTools_ShapeMapHasher>(mod, "MoniTool_DataMapOfShapeTransient", py::module_local(false));

// TYPEDEF: MONITOOL_DATAMAPITERATOROFDATAMAPOFSHAPETRANSIENT

// CLASS: MONITOOL_MTHASHER
py::class_<MoniTool_MTHasher> cls_MoniTool_MTHasher(mod, "MoniTool_MTHasher", "The auxiliary class provides hash code for mapping objects");

// Constructors
cls_MoniTool_MTHasher.def(py::init<>());

// Methods
// cls_MoniTool_MTHasher.def_static("operator new_", (void * (*)(size_t)) &MoniTool_MTHasher::operator new, "None", py::arg("theSize"));
// cls_MoniTool_MTHasher.def_static("operator delete_", (void (*)(void *)) &MoniTool_MTHasher::operator delete, "None", py::arg("theAddress"));
// cls_MoniTool_MTHasher.def_static("operator new[]_", (void * (*)(size_t)) &MoniTool_MTHasher::operator new[], "None", py::arg("theSize"));
// cls_MoniTool_MTHasher.def_static("operator delete[]_", (void (*)(void *)) &MoniTool_MTHasher::operator delete[], "None", py::arg("theAddress"));
// cls_MoniTool_MTHasher.def_static("operator new_", (void * (*)(size_t, void *)) &MoniTool_MTHasher::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_MoniTool_MTHasher.def_static("operator delete_", (void (*)(void *, void *)) &MoniTool_MTHasher::operator delete, "None", py::arg(""), py::arg(""));
cls_MoniTool_MTHasher.def_static("HashCode_", (Standard_Integer (*)(Standard_CString, Standard_Integer)) &MoniTool_MTHasher::HashCode, "Returns hash code for the given string, in the range [1, theUpperBound]", py::arg("theString"), py::arg("theUpperBound"));
cls_MoniTool_MTHasher.def_static("IsEqual_", (Standard_Boolean (*)(const Standard_CString, const Standard_CString)) &MoniTool_MTHasher::IsEqual, "Returns True when the two CString are the same. Two same strings must have the same hashcode, the contrary is not necessary. Default Str1 == Str2", py::arg("Str1"), py::arg("Str2"));

// TYPEDEF: MONITOOL_DATAMAPOFTIMER
bind_NCollection_DataMap<const char *, opencascade::handle<MoniTool_Timer>, MoniTool_MTHasher>(mod, "MoniTool_DataMapOfTimer", py::module_local(false));

// TYPEDEF: MONITOOL_DATAMAPITERATOROFDATAMAPOFTIMER

// CLASS: MONITOOL_ELEMENT
py::class_<MoniTool_Element, opencascade::handle<MoniTool_Element>, Standard_Transient> cls_MoniTool_Element(mod, "MoniTool_Element", "a Element allows to map any kind of object as a Key for a Map. This works by defining, for a Hash Code, that of the real Key, not of the Element which acts only as an intermediate. When a Map asks for the HashCode of a Element, this one returns the code it has determined at creation time");

// Methods
cls_MoniTool_Element.def("GetHashCode", (Standard_Integer (MoniTool_Element::*)() const) &MoniTool_Element::GetHashCode, "Returns the HashCode which has been stored by SetHashCode (remark that HashCode could be deferred then be defined by sub-classes, the result is the same)");
cls_MoniTool_Element.def("Equates", (Standard_Boolean (MoniTool_Element::*)(const opencascade::handle<MoniTool_Element> &) const) &MoniTool_Element::Equates, "Specific testof equallity : to be defined by each sub-class, must be False if Elements have not the same true Type, else their contents must be compared", py::arg("other"));
cls_MoniTool_Element.def("ValueType", (opencascade::handle<Standard_Type> (MoniTool_Element::*)() const) &MoniTool_Element::ValueType, "Returns the Type of the Value. By default, returns the DynamicType of <me>, but can be redefined");
cls_MoniTool_Element.def("ValueTypeName", (Standard_CString (MoniTool_Element::*)() const) &MoniTool_Element::ValueTypeName, "Returns the name of the Type of the Value. Default is name of ValueType, unless it is for a non-handled object");
cls_MoniTool_Element.def("ListAttr", (const MoniTool_AttrList & (MoniTool_Element::*)() const) &MoniTool_Element::ListAttr, "Returns (readonly) the Attribute List");
cls_MoniTool_Element.def("ChangeAttr", (MoniTool_AttrList & (MoniTool_Element::*)()) &MoniTool_Element::ChangeAttr, "Returns (modifiable) the Attribute List");
cls_MoniTool_Element.def_static("get_type_name_", (const char * (*)()) &MoniTool_Element::get_type_name, "None");
cls_MoniTool_Element.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MoniTool_Element::get_type_descriptor, "None");
cls_MoniTool_Element.def("DynamicType", (const opencascade::handle<Standard_Type> & (MoniTool_Element::*)() const) &MoniTool_Element::DynamicType, "None");

// CLASS: MONITOOL_ELEMHASHER
py::class_<MoniTool_ElemHasher> cls_MoniTool_ElemHasher(mod, "MoniTool_ElemHasher", "ElemHasher defines HashCode for Element, which is : ask a Element its HashCode ! Because this is the Element itself which brings the HashCode for its Key");

// Constructors
cls_MoniTool_ElemHasher.def(py::init<>());

// Methods
// cls_MoniTool_ElemHasher.def_static("operator new_", (void * (*)(size_t)) &MoniTool_ElemHasher::operator new, "None", py::arg("theSize"));
// cls_MoniTool_ElemHasher.def_static("operator delete_", (void (*)(void *)) &MoniTool_ElemHasher::operator delete, "None", py::arg("theAddress"));
// cls_MoniTool_ElemHasher.def_static("operator new[]_", (void * (*)(size_t)) &MoniTool_ElemHasher::operator new[], "None", py::arg("theSize"));
// cls_MoniTool_ElemHasher.def_static("operator delete[]_", (void (*)(void *)) &MoniTool_ElemHasher::operator delete[], "None", py::arg("theAddress"));
// cls_MoniTool_ElemHasher.def_static("operator new_", (void * (*)(size_t, void *)) &MoniTool_ElemHasher::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_MoniTool_ElemHasher.def_static("operator delete_", (void (*)(void *, void *)) &MoniTool_ElemHasher::operator delete, "None", py::arg(""), py::arg(""));
cls_MoniTool_ElemHasher.def_static("HashCode_", (Standard_Integer (*)(const opencascade::handle<MoniTool_Element> &, Standard_Integer)) &MoniTool_ElemHasher::HashCode, "Returns hash code for the given element, in the range [1, theUpperBound]. Asks theElement its HashCode, then transforms it to be in the required range.", py::arg("theElement"), py::arg("theUpperBound"));
cls_MoniTool_ElemHasher.def_static("IsEqual_", (Standard_Boolean (*)(const opencascade::handle<MoniTool_Element> &, const opencascade::handle<MoniTool_Element> &)) &MoniTool_ElemHasher::IsEqual, "Returns True if two keys are the same. The test does not work on the Elements themselves but by calling their methods Equates", py::arg("K1"), py::arg("K2"));

// TYPEDEF: MONITOOL_SEQUENCEOFELEMENT
bind_NCollection_Sequence<opencascade::handle<MoniTool_Element> >(mod, "MoniTool_SequenceOfElement", py::module_local(false));

// CLASS: MONITOOL_HSEQUENCEOFELEMENT
py::class_<MoniTool_HSequenceOfElement, opencascade::handle<MoniTool_HSequenceOfElement>, Standard_Transient> cls_MoniTool_HSequenceOfElement(mod, "MoniTool_HSequenceOfElement", "None", py::multiple_inheritance());

// Constructors
cls_MoniTool_HSequenceOfElement.def(py::init<>());
cls_MoniTool_HSequenceOfElement.def(py::init<const MoniTool_SequenceOfElement &>(), py::arg("theOther"));

// Methods
// cls_MoniTool_HSequenceOfElement.def_static("operator new_", (void * (*)(size_t)) &MoniTool_HSequenceOfElement::operator new, "None", py::arg("theSize"));
// cls_MoniTool_HSequenceOfElement.def_static("operator delete_", (void (*)(void *)) &MoniTool_HSequenceOfElement::operator delete, "None", py::arg("theAddress"));
// cls_MoniTool_HSequenceOfElement.def_static("operator new[]_", (void * (*)(size_t)) &MoniTool_HSequenceOfElement::operator new[], "None", py::arg("theSize"));
// cls_MoniTool_HSequenceOfElement.def_static("operator delete[]_", (void (*)(void *)) &MoniTool_HSequenceOfElement::operator delete[], "None", py::arg("theAddress"));
// cls_MoniTool_HSequenceOfElement.def_static("operator new_", (void * (*)(size_t, void *)) &MoniTool_HSequenceOfElement::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_MoniTool_HSequenceOfElement.def_static("operator delete_", (void (*)(void *, void *)) &MoniTool_HSequenceOfElement::operator delete, "None", py::arg(""), py::arg(""));
// cls_MoniTool_HSequenceOfElement.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &MoniTool_HSequenceOfElement::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_MoniTool_HSequenceOfElement.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &MoniTool_HSequenceOfElement::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_MoniTool_HSequenceOfElement.def("Sequence", (const MoniTool_SequenceOfElement & (MoniTool_HSequenceOfElement::*)() const) &MoniTool_HSequenceOfElement::Sequence, "None");
cls_MoniTool_HSequenceOfElement.def("Append", (void (MoniTool_HSequenceOfElement::*)(const MoniTool_SequenceOfElement::value_type &)) &MoniTool_HSequenceOfElement::Append, "None", py::arg("theItem"));
cls_MoniTool_HSequenceOfElement.def("Append", (void (MoniTool_HSequenceOfElement::*)(MoniTool_SequenceOfElement &)) &MoniTool_HSequenceOfElement::Append, "None", py::arg("theSequence"));
cls_MoniTool_HSequenceOfElement.def("ChangeSequence", (MoniTool_SequenceOfElement & (MoniTool_HSequenceOfElement::*)()) &MoniTool_HSequenceOfElement::ChangeSequence, "None");
cls_MoniTool_HSequenceOfElement.def_static("get_type_name_", (const char * (*)()) &MoniTool_HSequenceOfElement::get_type_name, "None");
cls_MoniTool_HSequenceOfElement.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MoniTool_HSequenceOfElement::get_type_descriptor, "None");
cls_MoniTool_HSequenceOfElement.def("DynamicType", (const opencascade::handle<Standard_Type> & (MoniTool_HSequenceOfElement::*)() const) &MoniTool_HSequenceOfElement::DynamicType, "None");

// TYPEDEF: MONITOOL_INDEXEDDATAMAPOFSHAPETRANSIENT
bind_NCollection_IndexedDataMap<TopoDS_Shape, opencascade::handle<Standard_Transient>, TopTools_ShapeMapHasher>(mod, "MoniTool_IndexedDataMapOfShapeTransient", py::module_local(false));

// CLASS: MONITOOL_INTVAL
py::class_<MoniTool_IntVal, opencascade::handle<MoniTool_IntVal>, Standard_Transient> cls_MoniTool_IntVal(mod, "MoniTool_IntVal", "An Integer through a Handle (i.e. managed as TShared)");

// Constructors
cls_MoniTool_IntVal.def(py::init<>());
cls_MoniTool_IntVal.def(py::init<const Standard_Integer>(), py::arg("val"));

// Methods
cls_MoniTool_IntVal.def("Value", (Standard_Integer (MoniTool_IntVal::*)() const) &MoniTool_IntVal::Value, "None");
cls_MoniTool_IntVal.def("CValue", (Standard_Integer & (MoniTool_IntVal::*)()) &MoniTool_IntVal::CValue, "None");
cls_MoniTool_IntVal.def_static("get_type_name_", (const char * (*)()) &MoniTool_IntVal::get_type_name, "None");
cls_MoniTool_IntVal.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MoniTool_IntVal::get_type_descriptor, "None");
cls_MoniTool_IntVal.def("DynamicType", (const opencascade::handle<Standard_Type> & (MoniTool_IntVal::*)() const) &MoniTool_IntVal::DynamicType, "None");

// CLASS: MONITOOL_REALVAL
py::class_<MoniTool_RealVal, opencascade::handle<MoniTool_RealVal>, Standard_Transient> cls_MoniTool_RealVal(mod, "MoniTool_RealVal", "A Real through a Handle (i.e. managed as TShared)");

// Constructors
cls_MoniTool_RealVal.def(py::init<>());
cls_MoniTool_RealVal.def(py::init<const Standard_Real>(), py::arg("val"));

// Methods
cls_MoniTool_RealVal.def("Value", (Standard_Real (MoniTool_RealVal::*)() const) &MoniTool_RealVal::Value, "None");
cls_MoniTool_RealVal.def("CValue", (Standard_Real & (MoniTool_RealVal::*)()) &MoniTool_RealVal::CValue, "None");
cls_MoniTool_RealVal.def_static("get_type_name_", (const char * (*)()) &MoniTool_RealVal::get_type_name, "None");
cls_MoniTool_RealVal.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MoniTool_RealVal::get_type_descriptor, "None");
cls_MoniTool_RealVal.def("DynamicType", (const opencascade::handle<Standard_Type> & (MoniTool_RealVal::*)() const) &MoniTool_RealVal::DynamicType, "None");

// CLASS: MONITOOL_SIGNSHAPE
py::class_<MoniTool_SignShape, opencascade::handle<MoniTool_SignShape>, MoniTool_SignText> cls_MoniTool_SignShape(mod, "MoniTool_SignShape", "Signs HShape according to its real content (type of Shape) Context is not used");

// Constructors
cls_MoniTool_SignShape.def(py::init<>());

// Methods
cls_MoniTool_SignShape.def("Name", (Standard_CString (MoniTool_SignShape::*)() const) &MoniTool_SignShape::Name, "Returns 'SHAPE'");
cls_MoniTool_SignShape.def("Text", (TCollection_AsciiString (MoniTool_SignShape::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Standard_Transient> &) const) &MoniTool_SignShape::Text, "Returns for a HShape, the string of its ShapeEnum The Model is absolutely useless (may be null)", py::arg("ent"), py::arg("context"));
cls_MoniTool_SignShape.def_static("get_type_name_", (const char * (*)()) &MoniTool_SignShape::get_type_name, "None");
cls_MoniTool_SignShape.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MoniTool_SignShape::get_type_descriptor, "None");
cls_MoniTool_SignShape.def("DynamicType", (const opencascade::handle<Standard_Type> & (MoniTool_SignShape::*)() const) &MoniTool_SignShape::DynamicType, "None");

// CLASS: MONITOOL_STAT
py::class_<MoniTool_Stat> cls_MoniTool_Stat(mod, "MoniTool_Stat", "This class manages Statistics to be queried asynchronously.");

// Constructors
cls_MoniTool_Stat.def(py::init<>());
cls_MoniTool_Stat.def(py::init<const Standard_CString>(), py::arg("title"));
cls_MoniTool_Stat.def(py::init<const MoniTool_Stat &>(), py::arg("other"));

// Methods
// cls_MoniTool_Stat.def_static("operator new_", (void * (*)(size_t)) &MoniTool_Stat::operator new, "None", py::arg("theSize"));
// cls_MoniTool_Stat.def_static("operator delete_", (void (*)(void *)) &MoniTool_Stat::operator delete, "None", py::arg("theAddress"));
// cls_MoniTool_Stat.def_static("operator new[]_", (void * (*)(size_t)) &MoniTool_Stat::operator new[], "None", py::arg("theSize"));
// cls_MoniTool_Stat.def_static("operator delete[]_", (void (*)(void *)) &MoniTool_Stat::operator delete[], "None", py::arg("theAddress"));
// cls_MoniTool_Stat.def_static("operator new_", (void * (*)(size_t, void *)) &MoniTool_Stat::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_MoniTool_Stat.def_static("operator delete_", (void (*)(void *, void *)) &MoniTool_Stat::operator delete, "None", py::arg(""), py::arg(""));
cls_MoniTool_Stat.def_static("Current_", (MoniTool_Stat & (*)()) &MoniTool_Stat::Current, "None");
cls_MoniTool_Stat.def("Open", [](MoniTool_Stat &self) -> Standard_Integer { return self.Open(); });
cls_MoniTool_Stat.def("Open", (Standard_Integer (MoniTool_Stat::*)(const Standard_Integer)) &MoniTool_Stat::Open, "Opens a new counter with a starting count of items", py::arg("nb"));
cls_MoniTool_Stat.def("OpenMore", (void (MoniTool_Stat::*)(const Standard_Integer, const Standard_Integer)) &MoniTool_Stat::OpenMore, "Adds more items to be counted by Add... on current level", py::arg("id"), py::arg("nb"));
cls_MoniTool_Stat.def("Add", [](MoniTool_Stat &self) -> void { return self.Add(); });
cls_MoniTool_Stat.def("Add", (void (MoniTool_Stat::*)(const Standard_Integer)) &MoniTool_Stat::Add, "Directly addes items", py::arg("nb"));
cls_MoniTool_Stat.def("AddSub", [](MoniTool_Stat &self) -> void { return self.AddSub(); });
cls_MoniTool_Stat.def("AddSub", (void (MoniTool_Stat::*)(const Standard_Integer)) &MoniTool_Stat::AddSub, "Declares a count of items to be added later. If a sub-counter is opened, its percentage multiplies this sub-count to compute the percent of current level", py::arg("nb"));
cls_MoniTool_Stat.def("AddEnd", (void (MoniTool_Stat::*)()) &MoniTool_Stat::AddEnd, "Ends the AddSub and cumulates the sub-count to current level");
cls_MoniTool_Stat.def("Close", (void (MoniTool_Stat::*)(const Standard_Integer)) &MoniTool_Stat::Close, "None", py::arg("id"));
cls_MoniTool_Stat.def("Level", (Standard_Integer (MoniTool_Stat::*)() const) &MoniTool_Stat::Level, "None");
cls_MoniTool_Stat.def("Percent", [](MoniTool_Stat &self) -> Standard_Real { return self.Percent(); });
cls_MoniTool_Stat.def("Percent", (Standard_Real (MoniTool_Stat::*)(const Standard_Integer) const) &MoniTool_Stat::Percent, "None", py::arg("fromlev"));

// CLASS: MONITOOL_TIMER
py::class_<MoniTool_Timer, opencascade::handle<MoniTool_Timer>, Standard_Transient> cls_MoniTool_Timer(mod, "MoniTool_Timer", "Provides convenient service on global timers accessed by string name, mostly aimed for debugging purposes");

// Constructors
cls_MoniTool_Timer.def(py::init<>());

// Methods
cls_MoniTool_Timer.def("Timer", (const OSD_Timer & (MoniTool_Timer::*)() const) &MoniTool_Timer::Timer, "None");
cls_MoniTool_Timer.def("Timer", (OSD_Timer & (MoniTool_Timer::*)()) &MoniTool_Timer::Timer, "Return reference to embedded OSD_Timer");
cls_MoniTool_Timer.def("Start", (void (MoniTool_Timer::*)()) &MoniTool_Timer::Start, "None");
cls_MoniTool_Timer.def("Stop", (void (MoniTool_Timer::*)()) &MoniTool_Timer::Stop, "None");
cls_MoniTool_Timer.def("Reset", (void (MoniTool_Timer::*)()) &MoniTool_Timer::Reset, "Start, Stop and reset the timer In addition to doing that to embedded OSD_Timer, manage also counter of hits");
cls_MoniTool_Timer.def("Count", (Standard_Integer (MoniTool_Timer::*)() const) &MoniTool_Timer::Count, "Return value of hits counter (count of Start/Stop pairs)");
cls_MoniTool_Timer.def("IsRunning", (Standard_Integer (MoniTool_Timer::*)() const) &MoniTool_Timer::IsRunning, "Returns value of nesting counter");
cls_MoniTool_Timer.def("CPU", (Standard_Real (MoniTool_Timer::*)()) &MoniTool_Timer::CPU, "Return value of CPU time minus accumulated amendment");
cls_MoniTool_Timer.def("Amend", (Standard_Real (MoniTool_Timer::*)() const) &MoniTool_Timer::Amend, "Return value of accumulated amendment on CPU time");
cls_MoniTool_Timer.def("Dump", (void (MoniTool_Timer::*)(Standard_OStream &)) &MoniTool_Timer::Dump, "Dumps current state of a timer shortly (one-line output)", py::arg("ostr"));
cls_MoniTool_Timer.def_static("Timer_", (opencascade::handle<MoniTool_Timer> (*)(const Standard_CString)) &MoniTool_Timer::Timer, "Returns a timer from a dictionary by its name If timer not existed, creates a new one", py::arg("name"));
cls_MoniTool_Timer.def_static("Start_", (void (*)(const Standard_CString)) &MoniTool_Timer::Start, "None", py::arg("name"));
cls_MoniTool_Timer.def_static("Stop_", (void (*)(const Standard_CString)) &MoniTool_Timer::Stop, "Inline methods to conveniently start/stop timer by name Shortcut to Timer(name)->Start/Stop()", py::arg("name"));
cls_MoniTool_Timer.def_static("Dictionary_", (MoniTool_DataMapOfTimer & (*)()) &MoniTool_Timer::Dictionary, "Returns map of timers");
cls_MoniTool_Timer.def_static("ClearTimers_", (void (*)()) &MoniTool_Timer::ClearTimers, "Clears map of timers");
cls_MoniTool_Timer.def_static("DumpTimers_", (void (*)(Standard_OStream &)) &MoniTool_Timer::DumpTimers, "Dumps contents of the whole dictionary", py::arg("ostr"));
cls_MoniTool_Timer.def_static("ComputeAmendments_", (void (*)()) &MoniTool_Timer::ComputeAmendments, "Computes and remembers amendments for times to access, start, and stop of timer, and estimates second-order error measured by 10 nested timers");
cls_MoniTool_Timer.def_static("GetAmendments_", [](Standard_Real & Access, Standard_Real & Internal, Standard_Real & External, Standard_Real & Error10){ MoniTool_Timer::GetAmendments(Access, Internal, External, Error10); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(Access, Internal, External, Error10); }, "The computed amendmens are returned (for information only)", py::arg("Access"), py::arg("Internal"), py::arg("External"), py::arg("Error10"));
cls_MoniTool_Timer.def_static("get_type_name_", (const char * (*)()) &MoniTool_Timer::get_type_name, "None");
cls_MoniTool_Timer.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MoniTool_Timer::get_type_descriptor, "None");
cls_MoniTool_Timer.def("DynamicType", (const opencascade::handle<Standard_Type> & (MoniTool_Timer::*)() const) &MoniTool_Timer::DynamicType, "None");

// CLASS: MONITOOL_TIMERSENTRY
py::class_<MoniTool_TimerSentry> cls_MoniTool_TimerSentry(mod, "MoniTool_TimerSentry", "A tool to facilitate using MoniTool_Timer functionality by automatically ensuring consistency of start/stop actions");

// Constructors
cls_MoniTool_TimerSentry.def(py::init<const Standard_CString>(), py::arg("cname"));
cls_MoniTool_TimerSentry.def(py::init<const opencascade::handle<MoniTool_Timer> &>(), py::arg("timer"));

// Methods
// cls_MoniTool_TimerSentry.def_static("operator new_", (void * (*)(size_t)) &MoniTool_TimerSentry::operator new, "None", py::arg("theSize"));
// cls_MoniTool_TimerSentry.def_static("operator delete_", (void (*)(void *)) &MoniTool_TimerSentry::operator delete, "None", py::arg("theAddress"));
// cls_MoniTool_TimerSentry.def_static("operator new[]_", (void * (*)(size_t)) &MoniTool_TimerSentry::operator new[], "None", py::arg("theSize"));
// cls_MoniTool_TimerSentry.def_static("operator delete[]_", (void (*)(void *)) &MoniTool_TimerSentry::operator delete[], "None", py::arg("theAddress"));
// cls_MoniTool_TimerSentry.def_static("operator new_", (void * (*)(size_t, void *)) &MoniTool_TimerSentry::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_MoniTool_TimerSentry.def_static("operator delete_", (void (*)(void *, void *)) &MoniTool_TimerSentry::operator delete, "None", py::arg(""), py::arg(""));
cls_MoniTool_TimerSentry.def("Timer", (opencascade::handle<MoniTool_Timer> (MoniTool_TimerSentry::*)() const) &MoniTool_TimerSentry::Timer, "None");
cls_MoniTool_TimerSentry.def("Stop", (void (MoniTool_TimerSentry::*)()) &MoniTool_TimerSentry::Stop, "Manually stops the timer");

// CLASS: MONITOOL_TRANSIENTELEM
py::class_<MoniTool_TransientElem, opencascade::handle<MoniTool_TransientElem>, MoniTool_Element> cls_MoniTool_TransientElem(mod, "MoniTool_TransientElem", "an TransientElem defines an Element for a specific input class its definition includes the value of the Key to be mapped, and the HashCoder associated to the class of the Key");

// Constructors
cls_MoniTool_TransientElem.def(py::init<const opencascade::handle<Standard_Transient> &>(), py::arg("akey"));

// Methods
cls_MoniTool_TransientElem.def("Value", (const opencascade::handle<Standard_Transient> & (MoniTool_TransientElem::*)() const) &MoniTool_TransientElem::Value, "Returns the contained value");
cls_MoniTool_TransientElem.def("Equates", (Standard_Boolean (MoniTool_TransientElem::*)(const opencascade::handle<MoniTool_Element> &) const) &MoniTool_TransientElem::Equates, "Specific testof equallity : defined as False if <other> has not the same true Type, else contents are compared (by C++ operator ==)", py::arg("other"));
cls_MoniTool_TransientElem.def("ValueType", (opencascade::handle<Standard_Type> (MoniTool_TransientElem::*)() const) &MoniTool_TransientElem::ValueType, "Returns the Type of the Value. By default, returns the DynamicType of <me>, but can be redefined");
cls_MoniTool_TransientElem.def("ValueTypeName", (Standard_CString (MoniTool_TransientElem::*)() const) &MoniTool_TransientElem::ValueTypeName, "Returns the name of the Type of the Value. Default is name of ValueType, unless it is for a non-handled object");
cls_MoniTool_TransientElem.def_static("get_type_name_", (const char * (*)()) &MoniTool_TransientElem::get_type_name, "None");
cls_MoniTool_TransientElem.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MoniTool_TransientElem::get_type_descriptor, "None");
cls_MoniTool_TransientElem.def("DynamicType", (const opencascade::handle<Standard_Type> & (MoniTool_TransientElem::*)() const) &MoniTool_TransientElem::DynamicType, "None");


}
