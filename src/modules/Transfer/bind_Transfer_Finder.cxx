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
#include <Transfer_Finder.hxx>
#include <Standard_Type.hxx>
#include <Interface_ParamType.hxx>
#include <NCollection_DataMap.hxx>
#include <TCollection_AsciiString.hxx>

void bind_Transfer_Finder(py::module &mod){

py::class_<Transfer_Finder, opencascade::handle<Transfer_Finder>, Standard_Transient> cls_Transfer_Finder(mod, "Transfer_Finder", "a Finder allows to map any kind of object as a Key for a Map. This works by defining, for a Hash Code, that of the real Key, not of the Finder which acts only as an intermediate. When a Map asks for the HashCode of a Finder, this one returns the code it has determined at creation time");

// Fields

// Methods
cls_Transfer_Finder.def("GetHashCode", (Standard_Integer (Transfer_Finder::*)() const) &Transfer_Finder::GetHashCode, "Returns the HashCode which has been stored by SetHashCode (remark that HashCode could be deferred then be defined by sub-classes, the result is the same)");
cls_Transfer_Finder.def("Equates", (Standard_Boolean (Transfer_Finder::*)(const opencascade::handle<Transfer_Finder> &) const) &Transfer_Finder::Equates, "Specific testof equallity : to be defined by each sub-class, must be False if Finders have not the same true Type, else their contents must be compared", py::arg("other"));
cls_Transfer_Finder.def("ValueType", (opencascade::handle<Standard_Type> (Transfer_Finder::*)() const) &Transfer_Finder::ValueType, "Returns the Type of the Value. By default, returns the DynamicType of <me>, but can be redefined");
cls_Transfer_Finder.def("ValueTypeName", (Standard_CString (Transfer_Finder::*)() const) &Transfer_Finder::ValueTypeName, "Returns the name of the Type of the Value. Default is name of ValueType, unless it is for a non-handled object");
cls_Transfer_Finder.def("SetAttribute", (void (Transfer_Finder::*)(const Standard_CString, const opencascade::handle<Standard_Transient> &)) &Transfer_Finder::SetAttribute, "Adds an attribute with a given name (replaces the former one with the same name if already exists)", py::arg("name"), py::arg("val"));
cls_Transfer_Finder.def("RemoveAttribute", (Standard_Boolean (Transfer_Finder::*)(const Standard_CString)) &Transfer_Finder::RemoveAttribute, "Removes an attribute Returns True when done, False if this attribute did not exist", py::arg("name"));
cls_Transfer_Finder.def("GetAttribute", (Standard_Boolean (Transfer_Finder::*)(const Standard_CString, const opencascade::handle<Standard_Type> &, opencascade::handle<Standard_Transient> &) const) &Transfer_Finder::GetAttribute, "Returns an attribute from its name, filtered by a type If no attribute has this name, or if it is not kind of this type, <val> is Null and returned value is False Else, it is True", py::arg("name"), py::arg("type"), py::arg("val"));
cls_Transfer_Finder.def("Attribute", (opencascade::handle<Standard_Transient> (Transfer_Finder::*)(const Standard_CString) const) &Transfer_Finder::Attribute, "Returns an attribute from its name. Null Handle if not recorded (whatever Transient, Integer, Real ...)", py::arg("name"));
cls_Transfer_Finder.def("AttributeType", (Interface_ParamType (Transfer_Finder::*)(const Standard_CString) const) &Transfer_Finder::AttributeType, "Returns the type of an attribute : ParamInt , ParamReal , ParamText (String) , ParamIdent (any) or ParamVoid (not recorded)", py::arg("name"));
cls_Transfer_Finder.def("SetIntegerAttribute", (void (Transfer_Finder::*)(const Standard_CString, const Standard_Integer)) &Transfer_Finder::SetIntegerAttribute, "Adds an integer value for an attribute", py::arg("name"), py::arg("val"));
cls_Transfer_Finder.def("GetIntegerAttribute", [](Transfer_Finder &self, const Standard_CString name, Standard_Integer & val){ Standard_Boolean rv = self.GetIntegerAttribute(name, val); return std::tuple<Standard_Boolean, Standard_Integer &>(rv, val); }, "Returns an attribute from its name, as integer If no attribute has this name, or not an integer, <val> is 0 and returned value is False Else, it is True", py::arg("name"), py::arg("val"));
cls_Transfer_Finder.def("IntegerAttribute", (Standard_Integer (Transfer_Finder::*)(const Standard_CString) const) &Transfer_Finder::IntegerAttribute, "Returns an integer attribute from its name. 0 if not recorded", py::arg("name"));
cls_Transfer_Finder.def("SetRealAttribute", (void (Transfer_Finder::*)(const Standard_CString, const Standard_Real)) &Transfer_Finder::SetRealAttribute, "Adds a real value for an attribute", py::arg("name"), py::arg("val"));
cls_Transfer_Finder.def("GetRealAttribute", [](Transfer_Finder &self, const Standard_CString name, Standard_Real & val){ Standard_Boolean rv = self.GetRealAttribute(name, val); return std::tuple<Standard_Boolean, Standard_Real &>(rv, val); }, "Returns an attribute from its name, as real If no attribute has this name, or not a real <val> is 0.0 and returned value is False Else, it is True", py::arg("name"), py::arg("val"));
cls_Transfer_Finder.def("RealAttribute", (Standard_Real (Transfer_Finder::*)(const Standard_CString) const) &Transfer_Finder::RealAttribute, "Returns a real attribute from its name. 0.0 if not recorded", py::arg("name"));
cls_Transfer_Finder.def("SetStringAttribute", (void (Transfer_Finder::*)(const Standard_CString, const Standard_CString)) &Transfer_Finder::SetStringAttribute, "Adds a String value for an attribute", py::arg("name"), py::arg("val"));
// cls_Transfer_Finder.def("GetStringAttribute", [](Transfer_Finder &self, const Standard_CString name, Standard_CString & val){ Standard_Boolean rv = self.GetStringAttribute(name, val); return std::tuple<Standard_Boolean, Standard_CString &>(rv, val); }, "Returns an attribute from its name, as String If no attribute has this name, or not a String <val> is 0.0 and returned value is False Else, it is True", py::arg("name"), py::arg("val"));
cls_Transfer_Finder.def("StringAttribute", (Standard_CString (Transfer_Finder::*)(const Standard_CString) const) &Transfer_Finder::StringAttribute, "Returns a String attribute from its name. '' if not recorded", py::arg("name"));
cls_Transfer_Finder.def("AttrList", (NCollection_DataMap<TCollection_AsciiString, opencascade::handle<Standard_Transient> > & (Transfer_Finder::*)()) &Transfer_Finder::AttrList, "Returns the exhaustive list of attributes");
cls_Transfer_Finder.def("SameAttributes", (void (Transfer_Finder::*)(const opencascade::handle<Transfer_Finder> &)) &Transfer_Finder::SameAttributes, "Gets the list of attributes from <other>, as such, i.e. not copied : attributes are shared, any attribute edited, added, or removed in <other> is also in <me> and vice versa The former list of attributes of <me> is dropped", py::arg("other"));
cls_Transfer_Finder.def("GetAttributes", [](Transfer_Finder &self, const opencascade::handle<Transfer_Finder> & a0) -> void { return self.GetAttributes(a0); });
cls_Transfer_Finder.def("GetAttributes", [](Transfer_Finder &self, const opencascade::handle<Transfer_Finder> & a0, const Standard_CString a1) -> void { return self.GetAttributes(a0, a1); });
cls_Transfer_Finder.def("GetAttributes", (void (Transfer_Finder::*)(const opencascade::handle<Transfer_Finder> &, const Standard_CString, const Standard_Boolean)) &Transfer_Finder::GetAttributes, "Gets the list of attributes from <other>, by copying it By default, considers all the attributes from <other> If <fromname> is given, considers only the attributes with name beginning by <fromname>", py::arg("other"), py::arg("fromname"), py::arg("copied"));
cls_Transfer_Finder.def_static("get_type_name_", (const char * (*)()) &Transfer_Finder::get_type_name, "None");
cls_Transfer_Finder.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Transfer_Finder::get_type_descriptor, "None");
cls_Transfer_Finder.def("DynamicType", (const opencascade::handle<Standard_Type> & (Transfer_Finder::*)() const) &Transfer_Finder::DynamicType, "None");

// Enums

}