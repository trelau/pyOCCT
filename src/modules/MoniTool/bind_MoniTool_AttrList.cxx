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
#include <MoniTool_AttrList.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Transient.hxx>
#include <Standard_Type.hxx>
#include <MoniTool_ValueType.hxx>
#include <NCollection_DataMap.hxx>
#include <TCollection_AsciiString.hxx>

void bind_MoniTool_AttrList(py::module &mod){

py::class_<MoniTool_AttrList, std::unique_ptr<MoniTool_AttrList>> cls_MoniTool_AttrList(mod, "MoniTool_AttrList", "a AttrList allows to record a list of attributes as Transients which can be edited, changed ... Each one is identified by a name");

// Constructors
cls_MoniTool_AttrList.def(py::init<>());
cls_MoniTool_AttrList.def(py::init<const MoniTool_AttrList &>(), py::arg("other"));

// Fields

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

// Enums

}