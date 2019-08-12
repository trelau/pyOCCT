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
#include <Interface_TypedValue.hxx>
#include <Standard_TypeDef.hxx>
#include <Interface_ParamType.hxx>
#include <Standard_Handle.hxx>
#include <Interface_Static.hxx>
#include <Message_Messenger.hxx>
#include <TColStd_HSequenceOfHAsciiString.hxx>
#include <Standard_Type.hxx>
#include <TCollection_AsciiString.hxx>
#include <TColStd_HArray1OfAsciiString.hxx>
#include <NCollection_DataMap.hxx>
#include <Interface_StaticSatisfies.hxx>
#include <TCollection_HAsciiString.hxx>
#include <Standard_Transient.hxx>

void bind_Interface_Static(py::module &mod){

py::class_<Interface_Static, opencascade::handle<Interface_Static>, Interface_TypedValue> cls_Interface_Static(mod, "Interface_Static", "This class gives a way to manage meaningfull static variables, used as 'global' parameters in various procedures.");

// Constructors
cls_Interface_Static.def(py::init<const Standard_CString, const Standard_CString>(), py::arg("family"), py::arg("name"));
cls_Interface_Static.def(py::init<const Standard_CString, const Standard_CString, const Interface_ParamType>(), py::arg("family"), py::arg("name"), py::arg("type"));
cls_Interface_Static.def(py::init<const Standard_CString, const Standard_CString, const Interface_ParamType, const Standard_CString>(), py::arg("family"), py::arg("name"), py::arg("type"), py::arg("init"));
cls_Interface_Static.def(py::init<const Standard_CString, const Standard_CString, const opencascade::handle<Interface_Static> &>(), py::arg("family"), py::arg("name"), py::arg("other"));

// Fields

// Methods
cls_Interface_Static.def("PrintStatic", (void (Interface_Static::*)(const opencascade::handle<Message_Messenger> &) const) &Interface_Static::PrintStatic, "Writes the properties of a parameter in the diagnostic file. These include: - Name - Family, - Wildcard (if it has one) - Current status (empty string if it was updated or if it is the original one) - Value", py::arg("S"));
cls_Interface_Static.def("Family", (Standard_CString (Interface_Static::*)() const) &Interface_Static::Family, "Returns the family. It can be : a resource name for applis, an internal name between : $e (environment variables), $l (other, purely local)");
cls_Interface_Static.def("SetWild", (void (Interface_Static::*)(const opencascade::handle<Interface_Static> &)) &Interface_Static::SetWild, "Sets a 'wild-card' static : its value will be considered if <me> is not properly set. (reset by set a null one)", py::arg("wildcard"));
cls_Interface_Static.def("Wild", (opencascade::handle<Interface_Static> (Interface_Static::*)() const) &Interface_Static::Wild, "Returns the wildcard static, which can be (is most often) null");
cls_Interface_Static.def("SetUptodate", (void (Interface_Static::*)()) &Interface_Static::SetUptodate, "Records a Static has 'uptodate', i.e. its value has been taken into account by a reinitialisation procedure This flag is reset at each successful SetValue");
cls_Interface_Static.def("UpdatedStatus", (Standard_Boolean (Interface_Static::*)() const) &Interface_Static::UpdatedStatus, "Returns the status 'uptodate'");
cls_Interface_Static.def_static("Init_", [](const Standard_CString a0, const Standard_CString a1, const Interface_ParamType a2) -> Standard_Boolean { return Interface_Static::Init(a0, a1, a2); });
cls_Interface_Static.def_static("Init_", (Standard_Boolean (*)(const Standard_CString, const Standard_CString, const Interface_ParamType, const Standard_CString)) &Interface_Static::Init, "Declares a new Static (by calling its constructor) If this name is already taken, does nothing and returns False Else, creates it and returns True For additional definitions, get the Static then edit it", py::arg("family"), py::arg("name"), py::arg("type"), py::arg("init"));
cls_Interface_Static.def_static("Init_", [](const Standard_CString a0, const Standard_CString a1, const Standard_Character a2) -> Standard_Boolean { return Interface_Static::Init(a0, a1, a2); });
cls_Interface_Static.def_static("Init_", (Standard_Boolean (*)(const Standard_CString, const Standard_CString, const Standard_Character, const Standard_CString)) &Interface_Static::Init, "As Init with ParamType, but type is given as a character This allows a simpler call Types : 'i' Integer, 'r' Real, 't' Text, 'e' Enum, 'o' Object '=' for same definition as, <init> gives the initial Static Returns False if <type> does not match this list", py::arg("family"), py::arg("name"), py::arg("type"), py::arg("init"));
cls_Interface_Static.def_static("Static_", (opencascade::handle<Interface_Static> (*)(const Standard_CString)) &Interface_Static::Static, "Returns a Static from its name. Null Handle if not present", py::arg("name"));
cls_Interface_Static.def_static("IsPresent_", (Standard_Boolean (*)(const Standard_CString)) &Interface_Static::IsPresent, "Returns True if a Static named <name> is present, False else", py::arg("name"));
cls_Interface_Static.def_static("CDef_", (Standard_CString (*)(const Standard_CString, const Standard_CString)) &Interface_Static::CDef, "Returns a part of the definition of a Static, as a CString The part is designated by its name, as a CString If the required value is not a string, it is converted to a CString then returned If <name> is not present, or <part> not defined for <name>, this function returns an empty string", py::arg("name"), py::arg("part"));
cls_Interface_Static.def_static("IDef_", (Standard_Integer (*)(const Standard_CString, const Standard_CString)) &Interface_Static::IDef, "Returns a part of the definition of a Static, as an Integer The part is designated by its name, as a CString If the required value is not a string, returns zero For a Boolean, 0 for false, 1 for true If <name> is not present, or <part> not defined for <name>, this function returns zero", py::arg("name"), py::arg("part"));
cls_Interface_Static.def_static("IsSet_", [](const Standard_CString a0) -> Standard_Boolean { return Interface_Static::IsSet(a0); });
cls_Interface_Static.def_static("IsSet_", (Standard_Boolean (*)(const Standard_CString, const Standard_Boolean)) &Interface_Static::IsSet, "Returns True if <name> is present AND set <proper> True (D) : considers this item only <proper> False : if not set and attached to a wild-card, considers this wild-card", py::arg("name"), py::arg("proper"));
cls_Interface_Static.def_static("CVal_", (Standard_CString (*)(const Standard_CString)) &Interface_Static::CVal, "Returns the value of the parameter identified by the string name. If the specified parameter does not exist, an empty string is returned. Example Interface_Static::CVal('write.step.schema'); which could return: 'AP214'", py::arg("name"));
cls_Interface_Static.def_static("IVal_", (Standard_Integer (*)(const Standard_CString)) &Interface_Static::IVal, "Returns the integer value of the translation parameter identified by the string name. Returns the value 0 if the parameter does not exist. Example Interface_Static::IVal('write.step.schema'); which could return: 3", py::arg("name"));
cls_Interface_Static.def_static("RVal_", (Standard_Real (*)(const Standard_CString)) &Interface_Static::RVal, "Returns the value of a static translation parameter identified by the string name. Returns the value 0.0 if the parameter does not exist.", py::arg("name"));
cls_Interface_Static.def_static("SetCVal_", (Standard_Boolean (*)(const Standard_CString, const Standard_CString)) &Interface_Static::SetCVal, "Modifies the value of the parameter identified by name. The modification is specified by the string val. false is returned if the parameter does not exist. Example Interface_Static::SetCVal ('write.step.schema','AP203') This syntax specifies a switch from the default STEP 214 mode to STEP 203 mode.", py::arg("name"), py::arg("val"));
cls_Interface_Static.def_static("SetIVal_", (Standard_Boolean (*)(const Standard_CString, const Standard_Integer)) &Interface_Static::SetIVal, "Modifies the value of the parameter identified by name. The modification is specified by the integer value val. false is returned if the parameter does not exist. Example Interface_Static::SetIVal ('write.step.schema', 3) This syntax specifies a switch from the default STEP 214 mode to STEP 203 mode.S", py::arg("name"), py::arg("val"));
cls_Interface_Static.def_static("SetRVal_", (Standard_Boolean (*)(const Standard_CString, const Standard_Real)) &Interface_Static::SetRVal, "Modifies the value of a translation parameter. false is returned if the parameter does not exist. The modification is specified by the real number value val.", py::arg("name"), py::arg("val"));
cls_Interface_Static.def_static("Update_", (Standard_Boolean (*)(const Standard_CString)) &Interface_Static::Update, "Sets a Static to be 'uptodate' Returns False if <name> is not present This status can be used by a reinitialisation procedure to rerun if a value has been changed", py::arg("name"));
cls_Interface_Static.def_static("IsUpdated_", (Standard_Boolean (*)(const Standard_CString)) &Interface_Static::IsUpdated, "Returns the status 'uptodate' from a Static Returns False if <name> is not present", py::arg("name"));
cls_Interface_Static.def_static("Items_", []() -> opencascade::handle<TColStd_HSequenceOfHAsciiString> { return Interface_Static::Items(); });
cls_Interface_Static.def_static("Items_", [](const Standard_Integer a0) -> opencascade::handle<TColStd_HSequenceOfHAsciiString> { return Interface_Static::Items(a0); });
cls_Interface_Static.def_static("Items_", (opencascade::handle<TColStd_HSequenceOfHAsciiString> (*)(const Standard_Integer, const Standard_CString)) &Interface_Static::Items, "Returns a list of names of statics : <mode> = 0 (D) : criter is for family <mode> = 1 : criter is regexp on names, takes final items (ignore wild cards) <mode> = 2 : idem but take only wilded, not final items <mode> = 3 : idem, take all items matching criter idem + 100 : takes only non-updated items idem + 200 : takes only updated items criter empty (D) : returns all names else returns names which match the given criter Remark : families beginning by '$' are not listed by criter '' they are listed only by criter '$'", py::arg("mode"), py::arg("criter"));
cls_Interface_Static.def_static("Standards_", (void (*)()) &Interface_Static::Standards, "Initializes all standard static parameters, which can be used by every function. statics specific of a norm or a function must be defined around it");
cls_Interface_Static.def_static("get_type_name_", (const char * (*)()) &Interface_Static::get_type_name, "None");
cls_Interface_Static.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Interface_Static::get_type_descriptor, "None");
cls_Interface_Static.def("DynamicType", (const opencascade::handle<Standard_Type> & (Interface_Static::*)() const) &Interface_Static::DynamicType, "None");

// Enums

}