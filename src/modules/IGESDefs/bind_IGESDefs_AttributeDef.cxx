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
#include <TColStd_HArray1OfInteger.hxx>
#include <TColStd_HArray1OfTransient.hxx>
#include <IGESDefs_HArray1OfHArray1OfTextDisplayTemplate.hxx>
#include <IGESGraph_TextDisplayTemplate.hxx>
#include <Standard_Transient.hxx>
#include <IGESDefs_AttributeDef.hxx>
#include <Standard_Type.hxx>

void bind_IGESDefs_AttributeDef(py::module &mod){

py::class_<IGESDefs_AttributeDef, opencascade::handle<IGESDefs_AttributeDef>, IGESData_IGESEntity> cls_IGESDefs_AttributeDef(mod, "IGESDefs_AttributeDef", "defines IGES Attribute Table Definition Entity, Type <322> Form [0, 1, 2] in package IGESDefs. This is class is used to support the concept of well defined collection of attributes, whether it is a table or a single row of attributes.");

// Constructors
cls_IGESDefs_AttributeDef.def(py::init<>());

// Fields

// Methods
cls_IGESDefs_AttributeDef.def("Init", (void (IGESDefs_AttributeDef::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Integer, const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<TColStd_HArray1OfTransient> &, const opencascade::handle<IGESDefs_HArray1OfHArray1OfTextDisplayTemplate> &)) &IGESDefs_AttributeDef::Init, "None", py::arg("aName"), py::arg("aListType"), py::arg("attrTypes"), py::arg("attrValueDataTypes"), py::arg("attrValueCounts"), py::arg("attrValues"), py::arg("attrValuePointers"));
cls_IGESDefs_AttributeDef.def("HasTableName", (Standard_Boolean (IGESDefs_AttributeDef::*)() const) &IGESDefs_AttributeDef::HasTableName, "Returns True if a Table Name is defined");
cls_IGESDefs_AttributeDef.def("TableName", (opencascade::handle<TCollection_HAsciiString> (IGESDefs_AttributeDef::*)() const) &IGESDefs_AttributeDef::TableName, "returns the Attribute Table name, or comment (default = null, no name : seeHasTableName)");
cls_IGESDefs_AttributeDef.def("ListType", (Standard_Integer (IGESDefs_AttributeDef::*)() const) &IGESDefs_AttributeDef::ListType, "returns the Attribute List Type");
cls_IGESDefs_AttributeDef.def("NbAttributes", (Standard_Integer (IGESDefs_AttributeDef::*)() const) &IGESDefs_AttributeDef::NbAttributes, "returns the Number of Attributes");
cls_IGESDefs_AttributeDef.def("AttributeType", (Standard_Integer (IGESDefs_AttributeDef::*)(const Standard_Integer) const) &IGESDefs_AttributeDef::AttributeType, "returns the num'th Attribute Type raises exception if num <= 0 or num > NbAttributes()", py::arg("num"));
cls_IGESDefs_AttributeDef.def("AttributeValueDataType", (Standard_Integer (IGESDefs_AttributeDef::*)(const Standard_Integer) const) &IGESDefs_AttributeDef::AttributeValueDataType, "returns the num'th Attribute value data type raises exception if num <= 0 or num > NbAttributes()", py::arg("num"));
cls_IGESDefs_AttributeDef.def("AttributeValueCount", (Standard_Integer (IGESDefs_AttributeDef::*)(const Standard_Integer) const) &IGESDefs_AttributeDef::AttributeValueCount, "returns the num'th Attribute value count raises exception if num <= 0 or num > NbAttributes()", py::arg("num"));
cls_IGESDefs_AttributeDef.def("HasValues", (Standard_Boolean (IGESDefs_AttributeDef::*)() const) &IGESDefs_AttributeDef::HasValues, "returns false if Values are defined (i.e. for Form = 1 or 2)");
cls_IGESDefs_AttributeDef.def("HasTextDisplay", (Standard_Boolean (IGESDefs_AttributeDef::*)() const) &IGESDefs_AttributeDef::HasTextDisplay, "returns false if TextDisplays are defined (i.e. for Form = 2)");
cls_IGESDefs_AttributeDef.def("AttributeTextDisplay", (opencascade::handle<IGESGraph_TextDisplayTemplate> (IGESDefs_AttributeDef::*)(const Standard_Integer, const Standard_Integer) const) &IGESDefs_AttributeDef::AttributeTextDisplay, "None", py::arg("AttrNum"), py::arg("PointerNum"));
cls_IGESDefs_AttributeDef.def("AttributeList", (opencascade::handle<Standard_Transient> (IGESDefs_AttributeDef::*)(const Standard_Integer) const) &IGESDefs_AttributeDef::AttributeList, "Returns the List of Attributes <AttrNum>, as a Transient. Its effective Type depends of the Type of Attribute : HArray1OfInteger for Integer, Logical(0-1), HArray1OfReal for Real, HArray1OfHSaciiString for String, HArray1OfIGESEntity for Entity (Pointer) See methods AttributeAs... for an accurate access", py::arg("AttrNum"));
cls_IGESDefs_AttributeDef.def("AttributeAsInteger", (Standard_Integer (IGESDefs_AttributeDef::*)(const Standard_Integer, const Standard_Integer) const) &IGESDefs_AttributeDef::AttributeAsInteger, "Returns Attribute Value <AttrNum, rank ValueNum> as an Integer Error if Indices out of Range, or no Value defined, or not an Integer", py::arg("AttrNum"), py::arg("ValueNum"));
cls_IGESDefs_AttributeDef.def("AttributeAsReal", (Standard_Real (IGESDefs_AttributeDef::*)(const Standard_Integer, const Standard_Integer) const) &IGESDefs_AttributeDef::AttributeAsReal, "Returns Attribute Value <AttrNum, rank ValueNum> as a Real Error if Indices out of Range, or no Value defined, or not a Real", py::arg("AttrNum"), py::arg("ValueNum"));
cls_IGESDefs_AttributeDef.def("AttributeAsString", (opencascade::handle<TCollection_HAsciiString> (IGESDefs_AttributeDef::*)(const Standard_Integer, const Standard_Integer) const) &IGESDefs_AttributeDef::AttributeAsString, "Returns Attribute Value <AttrNum, rank ValueNum> as an Integer", py::arg("AttrNum"), py::arg("ValueNum"));
cls_IGESDefs_AttributeDef.def("AttributeAsEntity", (opencascade::handle<IGESData_IGESEntity> (IGESDefs_AttributeDef::*)(const Standard_Integer, const Standard_Integer) const) &IGESDefs_AttributeDef::AttributeAsEntity, "Returns Attribute Value <AttrNum, rank ValueNum> as an Entity Error if Indices out of Range, or no Value defined, or not a Entity", py::arg("AttrNum"), py::arg("ValueNum"));
cls_IGESDefs_AttributeDef.def("AttributeAsLogical", (Standard_Boolean (IGESDefs_AttributeDef::*)(const Standard_Integer, const Standard_Integer) const) &IGESDefs_AttributeDef::AttributeAsLogical, "Returns Attribute Value <AttrNum, rank ValueNum> as a Boolean Error if Indices out of Range, or no Value defined, or not a Logical", py::arg("AttrNum"), py::arg("ValueNum"));
cls_IGESDefs_AttributeDef.def_static("get_type_name_", (const char * (*)()) &IGESDefs_AttributeDef::get_type_name, "None");
cls_IGESDefs_AttributeDef.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESDefs_AttributeDef::get_type_descriptor, "None");
cls_IGESDefs_AttributeDef.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESDefs_AttributeDef::*)() const) &IGESDefs_AttributeDef::DynamicType, "None");

// Enums

}