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
#include <MoniTool_Element.hxx>
#include <Standard_Type.hxx>
#include <MoniTool_AttrList.hxx>

void bind_MoniTool_Element(py::module &mod){

py::class_<MoniTool_Element, opencascade::handle<MoniTool_Element>, Standard_Transient> cls_MoniTool_Element(mod, "MoniTool_Element", "a Element allows to map any kind of object as a Key for a Map. This works by defining, for a Hash Code, that of the real Key, not of the Element which acts only as an intermediate. When a Map asks for the HashCode of a Element, this one returns the code it has determined at creation time");

// Fields

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

// Enums

}