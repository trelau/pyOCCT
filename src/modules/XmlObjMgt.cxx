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
#include <LDOM_MemManager.hxx>
#include <TColStd_DataMapOfIntegerTransient.hxx>
#include <Standard_Handle.hxx>
#include <Storage_HeaderData.hxx>
#include <Standard_TypeDef.hxx>
#include <XmlObjMgt_RRelocationTable.hxx>
#include <LDOM_Element.hxx>
#include <XmlObjMgt_Element.hxx>
#include <TColStd_IndexedMapOfTransient.hxx>
#include <XmlObjMgt_SRelocationTable.hxx>
#include <LDOM_Document.hxx>
#include <XmlObjMgt_Document.hxx>
#include <LDOMString.hxx>
#include <XmlObjMgt_DOMString.hxx>
#include <Standard.hxx>
#include <TCollection_ExtendedString.hxx>
#include <TCollection_AsciiString.hxx>
#include <XmlObjMgt_Persistent.hxx>
#include <XmlObjMgt_GP.hxx>
#include <XmlObjMgt_Array1.hxx>
#include <XmlObjMgt.hxx>
#include <gp_Trsf.hxx>
#include <gp_Mat.hxx>
#include <gp_XYZ.hxx>

PYBIND11_MODULE(XmlObjMgt, mod) {

py::module::import("OCCT.LDOM");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.Standard");
py::module::import("OCCT.Storage");
py::module::import("OCCT.LDOMString");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.gp");

// CLASS: XMLOBJMGT_RRELOCATIONTABLE
py::class_<XmlObjMgt_RRelocationTable, TColStd_DataMapOfIntegerTransient> cls_XmlObjMgt_RRelocationTable(mod, "XmlObjMgt_RRelocationTable", "Retrieval relocation table is modeled as a child class of TColStd_DataMapOfIntegerTransient that stores a handle to the file header section. With that attribute drivers have access to the file header section.");

// Methods
cls_XmlObjMgt_RRelocationTable.def("GetHeaderData", (const opencascade::handle<Storage_HeaderData> & (XmlObjMgt_RRelocationTable::*)() const) &XmlObjMgt_RRelocationTable::GetHeaderData, "Returns a handle to the header data of the file that is begin read");
cls_XmlObjMgt_RRelocationTable.def("SetHeaderData", (void (XmlObjMgt_RRelocationTable::*)(const opencascade::handle<Storage_HeaderData> &)) &XmlObjMgt_RRelocationTable::SetHeaderData, "Sets the storage header data.", py::arg("theHeaderData"));
cls_XmlObjMgt_RRelocationTable.def("Clear", [](XmlObjMgt_RRelocationTable &self) -> void { return self.Clear(); });
cls_XmlObjMgt_RRelocationTable.def("Clear", (void (XmlObjMgt_RRelocationTable::*)(const Standard_Boolean)) &XmlObjMgt_RRelocationTable::Clear, "None", py::arg("doReleaseMemory"));

// TYPEDEF: XMLOBJMGT_ELEMENT
py::class_<LDOM_Element, LDOM_Node> cls_XmlObjMgt_Element(mod, "XmlObjMgt_Element", "None", py::module_local());

// Constructors
cls_XmlObjMgt_Element.def(py::init<>());
cls_XmlObjMgt_Element.def(py::init<const LDOM_Element &>(), py::arg("anOther"));

// Methods
// cls_XmlObjMgt_Element.def("operator=", (LDOM_Element & (LDOM_Element::*)(const LDOM_Element &)) &LDOM_Element::operator=, "None", py::arg("anOther"));
// cls_XmlObjMgt_Element.def("operator=", (LDOM_Element & (LDOM_Element::*)(const LDOM_NullPtr *)) &LDOM_Element::operator=, "None", py::arg("aNull"));
cls_XmlObjMgt_Element.def("getTagName", (LDOMString (LDOM_Element::*)() const) &LDOM_Element::getTagName, "None");
cls_XmlObjMgt_Element.def("getAttribute", (LDOMString (LDOM_Element::*)(const LDOMString &) const) &LDOM_Element::getAttribute, "None", py::arg("aName"));
cls_XmlObjMgt_Element.def("getAttributeNode", (LDOM_Attr (LDOM_Element::*)(const LDOMString &) const) &LDOM_Element::getAttributeNode, "None", py::arg("aName"));
cls_XmlObjMgt_Element.def("getElementsByTagName", (LDOM_NodeList (LDOM_Element::*)(const LDOMString &) const) &LDOM_Element::getElementsByTagName, "None", py::arg("aName"));
cls_XmlObjMgt_Element.def("setAttribute", (void (LDOM_Element::*)(const LDOMString &, const LDOMString &)) &LDOM_Element::setAttribute, "None", py::arg("aName"), py::arg("aValue"));
cls_XmlObjMgt_Element.def("setAttributeNode", (void (LDOM_Element::*)(const LDOM_Attr &)) &LDOM_Element::setAttributeNode, "None", py::arg("aNewAttr"));
cls_XmlObjMgt_Element.def("removeAttribute", (void (LDOM_Element::*)(const LDOMString &)) &LDOM_Element::removeAttribute, "None", py::arg("aName"));
cls_XmlObjMgt_Element.def("GetChildByTagName", (LDOM_Element (LDOM_Element::*)(const LDOMString &) const) &LDOM_Element::GetChildByTagName, "None", py::arg("aTagName"));
cls_XmlObjMgt_Element.def("GetSiblingByTagName", (LDOM_Element (LDOM_Element::*)() const) &LDOM_Element::GetSiblingByTagName, "None");
cls_XmlObjMgt_Element.def("ReplaceElement", (void (LDOM_Element::*)(const LDOM_Element &)) &LDOM_Element::ReplaceElement, "None", py::arg("anOther"));
cls_XmlObjMgt_Element.def("GetAttributesList", (LDOM_NodeList (LDOM_Element::*)() const) &LDOM_Element::GetAttributesList, "None");

// CLASS: XMLOBJMGT_SRELOCATIONTABLE
py::class_<XmlObjMgt_SRelocationTable, TColStd_IndexedMapOfTransient> cls_XmlObjMgt_SRelocationTable(mod, "XmlObjMgt_SRelocationTable", "Stored relocation table is modeled as a child class of TColStd_DataMapOfIntegerTransient that stores a handle to the file header section. With that attribute drivers have access to the file header section.");

// Methods
cls_XmlObjMgt_SRelocationTable.def("GetHeaderData", (const opencascade::handle<Storage_HeaderData> & (XmlObjMgt_SRelocationTable::*)() const) &XmlObjMgt_SRelocationTable::GetHeaderData, "Returns a handle to the header data of the file that is begin read");
cls_XmlObjMgt_SRelocationTable.def("SetHeaderData", (void (XmlObjMgt_SRelocationTable::*)(const opencascade::handle<Storage_HeaderData> &)) &XmlObjMgt_SRelocationTable::SetHeaderData, "Sets the storage header data.", py::arg("theHeaderData"));
cls_XmlObjMgt_SRelocationTable.def("Clear", [](XmlObjMgt_SRelocationTable &self) -> void { return self.Clear(); });
cls_XmlObjMgt_SRelocationTable.def("Clear", (void (XmlObjMgt_SRelocationTable::*)(const Standard_Boolean)) &XmlObjMgt_SRelocationTable::Clear, "None", py::arg("doReleaseMemory"));

// TYPEDEF: XMLOBJMGT_DOCUMENT
py::class_<LDOM_Document> cls_XmlObjMgt_Document(mod, "XmlObjMgt_Document", "None", py::module_local());

// Constructors
cls_XmlObjMgt_Document.def(py::init<>());
cls_XmlObjMgt_Document.def(py::init<const LDOM_MemManager &>(), py::arg("aMemManager"));

// Methods
cls_XmlObjMgt_Document.def_static("createDocument_", (LDOM_Document (*)(const LDOMString &)) &LDOM_Document::createDocument, "None", py::arg("theQualifiedName"));
cls_XmlObjMgt_Document.def("createElement", (LDOM_Element (LDOM_Document::*)(const LDOMString &)) &LDOM_Document::createElement, "None", py::arg("theTagName"));
cls_XmlObjMgt_Document.def("createCDATASection", (LDOM_CDATASection (LDOM_Document::*)(const LDOMString &)) &LDOM_Document::createCDATASection, "None", py::arg("theData"));
cls_XmlObjMgt_Document.def("createComment", (LDOM_Comment (LDOM_Document::*)(const LDOMString &)) &LDOM_Document::createComment, "None", py::arg("theData"));
cls_XmlObjMgt_Document.def("createTextNode", (LDOM_Text (LDOM_Document::*)(const LDOMString &)) &LDOM_Document::createTextNode, "None", py::arg("theData"));
cls_XmlObjMgt_Document.def("getDocumentElement", (LDOM_Element (LDOM_Document::*)() const) &LDOM_Document::getDocumentElement, "None");
cls_XmlObjMgt_Document.def("getElementsByTagName", (LDOM_NodeList (LDOM_Document::*)(const LDOMString &) const) &LDOM_Document::getElementsByTagName, "None", py::arg("theTagName"));
// cls_XmlObjMgt_Document.def("__eq__", (Standard_Boolean (LDOM_Document::*)(const LDOM_Document &) const) &LDOM_Document::operator==, py::is_operator(), "None", py::arg("anOther"));
// cls_XmlObjMgt_Document.def("__ne__", (Standard_Boolean (LDOM_Document::*)(const LDOM_Document &) const) &LDOM_Document::operator!=, py::is_operator(), "None", py::arg("anOther"));
// cls_XmlObjMgt_Document.def("__eq__", (Standard_Boolean (LDOM_Document::*)(const LDOM_NullPtr *) const) &LDOM_Document::operator==, py::is_operator(), "None", py::arg(""));
// cls_XmlObjMgt_Document.def("__ne__", (Standard_Boolean (LDOM_Document::*)(const LDOM_NullPtr *) const) &LDOM_Document::operator!=, py::is_operator(), "None", py::arg(""));
cls_XmlObjMgt_Document.def("isNull", (Standard_Boolean (LDOM_Document::*)() const) &LDOM_Document::isNull, "None");
// cls_XmlObjMgt_Document.def("operator=", (LDOM_Document & (LDOM_Document::*)(const LDOM_NullPtr *)) &LDOM_Document::operator=, "None", py::arg(""));

// TYPEDEF: XMLOBJMGT_DOMSTRING
/*
py::class_<LDOMString, LDOMBasicString> cls_XmlObjMgt_DOMString(mod, "XmlObjMgt_DOMString", "None", py::module_local());

// Constructors
cls_XmlObjMgt_DOMString.def(py::init<>());
// cls_XmlObjMgt_DOMString.def(py::init<const LDOMString &>(), py::arg("anOther"));
cls_XmlObjMgt_DOMString.def(py::init<const Standard_Integer>(), py::arg("aValue"));
cls_XmlObjMgt_DOMString.def(py::init<const char *>(), py::arg("aValue"));

// Methods
cls_XmlObjMgt_DOMString.def("getOwnerDocument", (const LDOM_MemManager & (LDOMString::*)() const) &LDOMString::getOwnerDocument, "None", py::call_guard<ImportLDOM>());
// cls_XmlObjMgt_DOMString.def("operator=", (LDOMString & (LDOMString::*)(const LDOM_NullPtr *)) &LDOMString::operator=, "None", py::arg("aNull"));
// cls_XmlObjMgt_DOMString.def("operator=", (LDOMString & (LDOMString::*)(const LDOMString &)) &LDOMString::operator=, "None", py::arg("anOther"));
*/

// CLASS: XMLOBJMGT
py::class_<XmlObjMgt> cls_XmlObjMgt(mod, "XmlObjMgt", "This package defines services to manage the storage grain of data produced by applications and those classes to manage persistent extern reference.");

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

// CLASS: XMLOBJMGT_ARRAY1
py::class_<XmlObjMgt_Array1> cls_XmlObjMgt_Array1(mod, "XmlObjMgt_Array1", "The class Array1 represents unidimensionnal array of fixed size known at run time. The range of the index is user defined. Warning: Programs clients of such class must be independant of the range of the first element. Then, a C++ for loop must be written like this for (i = A->Lower(); i <= A->Upper(); i++)");

// Constructors
cls_XmlObjMgt_Array1.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("Low"), py::arg("Up"));
cls_XmlObjMgt_Array1.def(py::init<const XmlObjMgt_Element &, const XmlObjMgt_DOMString &>(), py::arg("theParent"), py::arg("theName"));

// Methods
// cls_XmlObjMgt_Array1.def_static("operator new_", (void * (*)(size_t)) &XmlObjMgt_Array1::operator new, "None", py::arg("theSize"));
// cls_XmlObjMgt_Array1.def_static("operator delete_", (void (*)(void *)) &XmlObjMgt_Array1::operator delete, "None", py::arg("theAddress"));
// cls_XmlObjMgt_Array1.def_static("operator new[]_", (void * (*)(size_t)) &XmlObjMgt_Array1::operator new[], "None", py::arg("theSize"));
// cls_XmlObjMgt_Array1.def_static("operator delete[]_", (void (*)(void *)) &XmlObjMgt_Array1::operator delete[], "None", py::arg("theAddress"));
// cls_XmlObjMgt_Array1.def_static("operator new_", (void * (*)(size_t, void *)) &XmlObjMgt_Array1::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_XmlObjMgt_Array1.def_static("operator delete_", (void (*)(void *, void *)) &XmlObjMgt_Array1::operator delete, "None", py::arg(""), py::arg(""));
cls_XmlObjMgt_Array1.def("CreateArrayElement", (void (XmlObjMgt_Array1::*)(XmlObjMgt_Element &, const XmlObjMgt_DOMString &)) &XmlObjMgt_Array1::CreateArrayElement, "Create DOM_Element representing the array, under 'theParent'", py::arg("theParent"), py::arg("theName"));
cls_XmlObjMgt_Array1.def("Element", (const XmlObjMgt_Element & (XmlObjMgt_Array1::*)() const) &XmlObjMgt_Array1::Element, "Returns the DOM element of <me>.");
cls_XmlObjMgt_Array1.def("Length", (Standard_Integer (XmlObjMgt_Array1::*)() const) &XmlObjMgt_Array1::Length, "Returns the number of elements of <me>.");
cls_XmlObjMgt_Array1.def("Lower", (Standard_Integer (XmlObjMgt_Array1::*)() const) &XmlObjMgt_Array1::Lower, "Returns the lower bound.");
cls_XmlObjMgt_Array1.def("Upper", (Standard_Integer (XmlObjMgt_Array1::*)() const) &XmlObjMgt_Array1::Upper, "Returns the upper bound.");
cls_XmlObjMgt_Array1.def("SetValue", (void (XmlObjMgt_Array1::*)(const Standard_Integer, XmlObjMgt_Element &)) &XmlObjMgt_Array1::SetValue, "Set the <Index>th element of the array to <Value>.", py::arg("Index"), py::arg("Value"));
cls_XmlObjMgt_Array1.def("Value", (XmlObjMgt_Element (XmlObjMgt_Array1::*)(const Standard_Integer) const) &XmlObjMgt_Array1::Value, "Returns the value of <Index>th element of the array.", py::arg("Index"));

// CLASS: XMLOBJMGT_GP
py::class_<XmlObjMgt_GP> cls_XmlObjMgt_GP(mod, "XmlObjMgt_GP", "Translation of gp (simple geometry) objects");

// Methods
// cls_XmlObjMgt_GP.def_static("operator new_", (void * (*)(size_t)) &XmlObjMgt_GP::operator new, "None", py::arg("theSize"));
// cls_XmlObjMgt_GP.def_static("operator delete_", (void (*)(void *)) &XmlObjMgt_GP::operator delete, "None", py::arg("theAddress"));
// cls_XmlObjMgt_GP.def_static("operator new[]_", (void * (*)(size_t)) &XmlObjMgt_GP::operator new[], "None", py::arg("theSize"));
// cls_XmlObjMgt_GP.def_static("operator delete[]_", (void (*)(void *)) &XmlObjMgt_GP::operator delete[], "None", py::arg("theAddress"));
// cls_XmlObjMgt_GP.def_static("operator new_", (void * (*)(size_t, void *)) &XmlObjMgt_GP::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_XmlObjMgt_GP.def_static("operator delete_", (void (*)(void *, void *)) &XmlObjMgt_GP::operator delete, "None", py::arg(""), py::arg(""));
cls_XmlObjMgt_GP.def_static("Translate_", (XmlObjMgt_DOMString (*)(const gp_Trsf &)) &XmlObjMgt_GP::Translate, "None", py::arg("aTrsf"));
cls_XmlObjMgt_GP.def_static("Translate_", (XmlObjMgt_DOMString (*)(const gp_Mat &)) &XmlObjMgt_GP::Translate, "None", py::arg("aMat"));
cls_XmlObjMgt_GP.def_static("Translate_", (XmlObjMgt_DOMString (*)(const gp_XYZ &)) &XmlObjMgt_GP::Translate, "None", py::arg("anXYZ"));
cls_XmlObjMgt_GP.def_static("Translate_", (Standard_Boolean (*)(const XmlObjMgt_DOMString &, gp_Trsf &)) &XmlObjMgt_GP::Translate, "None", py::arg("aStr"), py::arg("T"));
cls_XmlObjMgt_GP.def_static("Translate_", (Standard_Boolean (*)(const XmlObjMgt_DOMString &, gp_Mat &)) &XmlObjMgt_GP::Translate, "None", py::arg("aStr"), py::arg("T"));
cls_XmlObjMgt_GP.def_static("Translate_", (Standard_Boolean (*)(const XmlObjMgt_DOMString &, gp_XYZ &)) &XmlObjMgt_GP::Translate, "None", py::arg("aStr"), py::arg("T"));

// CLASS: XMLOBJMGT_PERSISTENT
py::class_<XmlObjMgt_Persistent> cls_XmlObjMgt_Persistent(mod, "XmlObjMgt_Persistent", "root for XML-persistence");

// Constructors
cls_XmlObjMgt_Persistent.def(py::init<>());
cls_XmlObjMgt_Persistent.def(py::init<const XmlObjMgt_Element &>(), py::arg("theElement"));
cls_XmlObjMgt_Persistent.def(py::init<const XmlObjMgt_Element &, const XmlObjMgt_DOMString &>(), py::arg("theElement"), py::arg("theRef"));

// Methods
// cls_XmlObjMgt_Persistent.def_static("operator new_", (void * (*)(size_t)) &XmlObjMgt_Persistent::operator new, "None", py::arg("theSize"));
// cls_XmlObjMgt_Persistent.def_static("operator delete_", (void (*)(void *)) &XmlObjMgt_Persistent::operator delete, "None", py::arg("theAddress"));
// cls_XmlObjMgt_Persistent.def_static("operator new[]_", (void * (*)(size_t)) &XmlObjMgt_Persistent::operator new[], "None", py::arg("theSize"));
// cls_XmlObjMgt_Persistent.def_static("operator delete[]_", (void (*)(void *)) &XmlObjMgt_Persistent::operator delete[], "None", py::arg("theAddress"));
// cls_XmlObjMgt_Persistent.def_static("operator new_", (void * (*)(size_t, void *)) &XmlObjMgt_Persistent::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_XmlObjMgt_Persistent.def_static("operator delete_", (void (*)(void *, void *)) &XmlObjMgt_Persistent::operator delete, "None", py::arg(""), py::arg(""));
cls_XmlObjMgt_Persistent.def("CreateElement", (void (XmlObjMgt_Persistent::*)(XmlObjMgt_Element &, const XmlObjMgt_DOMString &, const Standard_Integer)) &XmlObjMgt_Persistent::CreateElement, "myElement := <theType id='theID'/>", py::arg("theParent"), py::arg("theType"), py::arg("theID"));
cls_XmlObjMgt_Persistent.def("SetId", (void (XmlObjMgt_Persistent::*)(const Standard_Integer)) &XmlObjMgt_Persistent::SetId, "None", py::arg("theId"));
cls_XmlObjMgt_Persistent.def("Element", (const XmlObjMgt_Element & (XmlObjMgt_Persistent::*)() const) &XmlObjMgt_Persistent::Element, "return myElement");
cls_XmlObjMgt_Persistent.def("Element", (XmlObjMgt_Element & (XmlObjMgt_Persistent::*)()) &XmlObjMgt_Persistent::Element, "return myElement");
cls_XmlObjMgt_Persistent.def("Id", (Standard_Integer (XmlObjMgt_Persistent::*)() const) &XmlObjMgt_Persistent::Id, "None");


}
