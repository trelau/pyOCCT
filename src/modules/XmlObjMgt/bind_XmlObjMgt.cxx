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
#include <XmlObjMgt_DOMString.hxx>
#include <Standard_TypeDef.hxx>
#include <XmlObjMgt_Element.hxx>
#include <TCollection_ExtendedString.hxx>
#include <TCollection_AsciiString.hxx>
#include <XmlObjMgt_Persistent.hxx>
#include <XmlObjMgt_GP.hxx>
#include <XmlObjMgt_Array1.hxx>
#include <XmlObjMgt.hxx>

void bind_XmlObjMgt(py::module &mod){

py::class_<XmlObjMgt, std::unique_ptr<XmlObjMgt>> cls_XmlObjMgt(mod, "XmlObjMgt", "This package defines services to manage the storage grain of data produced by applications and those classes to manage persistent extern reference.");

// Constructors

// Fields

// Methods
// cls_XmlObjMgt.def_static("operator new_", (void * (*)(size_t)) &XmlObjMgt::operator new, "None", py::arg("theSize"));
// cls_XmlObjMgt.def_static("operator delete_", (void (*)(void *)) &XmlObjMgt::operator delete, "None", py::arg("theAddress"));
// cls_XmlObjMgt.def_static("operator new[]_", (void * (*)(size_t)) &XmlObjMgt::operator new[], "None", py::arg("theSize"));
// cls_XmlObjMgt.def_static("operator delete[]_", (void (*)(void *)) &XmlObjMgt::operator delete[], "None", py::arg("theAddress"));
// cls_XmlObjMgt.def_static("operator new_", (void * (*)(size_t, void *)) &XmlObjMgt::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_XmlObjMgt.def_static("operator delete_", (void (*)(void *, void *)) &XmlObjMgt::operator delete, "None", py::arg(""), py::arg(""));
cls_XmlObjMgt.def_static("IdString_", (const XmlObjMgt_DOMString & (*)()) &XmlObjMgt::IdString, "Define the name of XMLattribute 'ID' (to be used everywhere)");
cls_XmlObjMgt.def_static("SetExtendedString_", (Standard_Boolean (*)(XmlObjMgt_Element &, const TCollection_ExtendedString &)) &XmlObjMgt::SetExtendedString, "Add attribute <theElement extstring='theString' ...>", py::arg("theElement"), py::arg("theString"));
cls_XmlObjMgt.def_static("GetExtendedString_", (Standard_Boolean (*)(const XmlObjMgt_Element &, TCollection_ExtendedString &)) &XmlObjMgt::GetExtendedString, "Get attribute <theElement extstring='theString' ...>", py::arg("theElement"), py::arg("theString"));
cls_XmlObjMgt.def_static("GetStringValue_", (XmlObjMgt_DOMString (*)(const XmlObjMgt_Element &)) &XmlObjMgt::GetStringValue, "Returns the first child text node", py::arg("theElement"));
cls_XmlObjMgt.def_static("SetStringValue_", [](XmlObjMgt_Element & a0, const XmlObjMgt_DOMString & a1) -> void { return XmlObjMgt::SetStringValue(a0, a1); });
cls_XmlObjMgt.def_static("SetStringValue_", (void (*)(XmlObjMgt_Element &, const XmlObjMgt_DOMString &, const Standard_Boolean)) &XmlObjMgt::SetStringValue, "Add theData as the last child text node to theElement isClearText(True) avoids analysis of the string and replacement of characters like '<' and '&' during XML file storage. Do NEVER set isClearText unless you have a hell of a reason", py::arg("theElement"), py::arg("theData"), py::arg("isClearText"));
cls_XmlObjMgt.def_static("GetTagEntryString_", (Standard_Boolean (*)(const XmlObjMgt_DOMString &, TCollection_AsciiString &)) &XmlObjMgt::GetTagEntryString, "Convert XPath expression (DOMString) into TagEntry string returns False on Error", py::arg("theTarget"), py::arg("theTagEntry"));
cls_XmlObjMgt.def_static("SetTagEntryString_", (void (*)(XmlObjMgt_DOMString &, const TCollection_AsciiString &)) &XmlObjMgt::SetTagEntryString, "Convert XPath expression (DOMString) into TagEntry string returns False on Error", py::arg("theSource"), py::arg("theTagEntry"));
cls_XmlObjMgt.def_static("FindChildElement_", (XmlObjMgt_Element (*)(const XmlObjMgt_Element &, const Standard_Integer)) &XmlObjMgt::FindChildElement, "None", py::arg("theSource"), py::arg("theObjId"));
cls_XmlObjMgt.def_static("FindChildByRef_", (XmlObjMgt_Element (*)(const XmlObjMgt_Element &, const XmlObjMgt_DOMString &)) &XmlObjMgt::FindChildByRef, "None", py::arg("theSource"), py::arg("theRefName"));
cls_XmlObjMgt.def_static("FindChildByName_", (XmlObjMgt_Element (*)(const XmlObjMgt_Element &, const XmlObjMgt_DOMString &)) &XmlObjMgt::FindChildByName, "None", py::arg("theSource"), py::arg("theName"));
// cls_XmlObjMgt.def_static("GetInteger_", [](Standard_CString & theString, Standard_Integer & theValue){ Standard_Boolean rv = XmlObjMgt::GetInteger(theString, theValue); return std::tuple<Standard_Boolean, Standard_CString &, Standard_Integer &>(rv, theString, theValue); }, "None", py::arg("theString"), py::arg("theValue"));
// cls_XmlObjMgt.def_static("GetReal_", [](Standard_CString & theString, Standard_Real & theValue){ Standard_Boolean rv = XmlObjMgt::GetReal(theString, theValue); return std::tuple<Standard_Boolean, Standard_CString &, Standard_Real &>(rv, theString, theValue); }, "None", py::arg("theString"), py::arg("theValue"));
// cls_XmlObjMgt.def_static("GetReal_", [](const XmlObjMgt_DOMString & theString, Standard_Real & theValue){ Standard_Boolean rv = XmlObjMgt::GetReal(theString, theValue); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theValue); }, "None", py::arg("theString"), py::arg("theValue"));

// Enums

}