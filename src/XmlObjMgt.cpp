/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC (info@laughlinresearch.com)

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
#include <pyOCCT_Common.hpp>

#include <XmlObjMgt_RRelocationTable.hxx>
#include <XmlObjMgt_Element.hxx>
#include <XmlObjMgt_SRelocationTable.hxx>
#include <XmlObjMgt_DOMString.hxx>
#include <Standard_TypeDef.hxx>
#include <XmlObjMgt_Persistent.hxx>
#include <XmlObjMgt_Document.hxx>
#include <gp_Trsf.hxx>
#include <gp_Mat.hxx>
#include <gp_XYZ.hxx>
#include <XmlObjMgt_GP.hxx>
#include <XmlObjMgt_Array1.hxx>
#include <TCollection_ExtendedString.hxx>
#include <TCollection_AsciiString.hxx>
#include <XmlObjMgt.hxx>
#include <NCollection_Templates.hpp>

PYBIND11_MODULE(XmlObjMgt, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.gp");
	py::module::import("OCCT.TCollection");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\XmlObjMgt_Persistent.hxx
	py::class_<XmlObjMgt_Persistent, std::unique_ptr<XmlObjMgt_Persistent, Deleter<XmlObjMgt_Persistent>>> cls_XmlObjMgt_Persistent(mod, "XmlObjMgt_Persistent", "root for XML-persistence");
	cls_XmlObjMgt_Persistent.def(py::init<>());
	cls_XmlObjMgt_Persistent.def(py::init<const XmlObjMgt_Element &>(), py::arg("theElement"));
	cls_XmlObjMgt_Persistent.def(py::init<const XmlObjMgt_Element &, const XmlObjMgt_DOMString &>(), py::arg("theElement"), py::arg("theRef"));
	cls_XmlObjMgt_Persistent.def("CreateElement", (void (XmlObjMgt_Persistent::*)(XmlObjMgt_Element &, const XmlObjMgt_DOMString &, const Standard_Integer)) &XmlObjMgt_Persistent::CreateElement, "myElement := <theType id='theID'/>", py::arg("theParent"), py::arg("theType"), py::arg("theID"));
	cls_XmlObjMgt_Persistent.def("SetId", (void (XmlObjMgt_Persistent::*)(const Standard_Integer)) &XmlObjMgt_Persistent::SetId, "None", py::arg("theId"));
	cls_XmlObjMgt_Persistent.def("Element", (const XmlObjMgt_Element & (XmlObjMgt_Persistent::*)() const ) &XmlObjMgt_Persistent::Element, "return myElement");
	cls_XmlObjMgt_Persistent.def("Element", (XmlObjMgt_Element & (XmlObjMgt_Persistent::*)()) &XmlObjMgt_Persistent::Element, "return myElement");
	cls_XmlObjMgt_Persistent.def("Id", (Standard_Integer (XmlObjMgt_Persistent::*)() const ) &XmlObjMgt_Persistent::Id, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\XmlObjMgt_GP.hxx
	py::class_<XmlObjMgt_GP, std::unique_ptr<XmlObjMgt_GP, Deleter<XmlObjMgt_GP>>> cls_XmlObjMgt_GP(mod, "XmlObjMgt_GP", "Translation of gp (simple geometry) objects");
	cls_XmlObjMgt_GP.def(py::init<>());
	cls_XmlObjMgt_GP.def_static("Translate_", (XmlObjMgt_DOMString (*)(const gp_Trsf &)) &XmlObjMgt_GP::Translate, "None", py::arg("aTrsf"));
	cls_XmlObjMgt_GP.def_static("Translate_", (XmlObjMgt_DOMString (*)(const gp_Mat &)) &XmlObjMgt_GP::Translate, "None", py::arg("aMat"));
	cls_XmlObjMgt_GP.def_static("Translate_", (XmlObjMgt_DOMString (*)(const gp_XYZ &)) &XmlObjMgt_GP::Translate, "None", py::arg("anXYZ"));
	cls_XmlObjMgt_GP.def_static("Translate_", (Standard_Boolean (*)(const XmlObjMgt_DOMString &, gp_Trsf &)) &XmlObjMgt_GP::Translate, "None", py::arg("aStr"), py::arg("T"));
	cls_XmlObjMgt_GP.def_static("Translate_", (Standard_Boolean (*)(const XmlObjMgt_DOMString &, gp_Mat &)) &XmlObjMgt_GP::Translate, "None", py::arg("aStr"), py::arg("T"));
	cls_XmlObjMgt_GP.def_static("Translate_", (Standard_Boolean (*)(const XmlObjMgt_DOMString &, gp_XYZ &)) &XmlObjMgt_GP::Translate, "None", py::arg("aStr"), py::arg("T"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\XmlObjMgt_Array1.hxx
	py::class_<XmlObjMgt_Array1, std::unique_ptr<XmlObjMgt_Array1, Deleter<XmlObjMgt_Array1>>> cls_XmlObjMgt_Array1(mod, "XmlObjMgt_Array1", "The class Array1 represents unidimensionnal array of fixed size known at run time. The range of the index is user defined. Warning: Programs clients of such class must be independant of the range of the first element. Then, a C++ for loop must be written like this for (i = A->Lower(); i <= A->Upper(); i++)");
	cls_XmlObjMgt_Array1.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("Low"), py::arg("Up"));
	cls_XmlObjMgt_Array1.def(py::init<const XmlObjMgt_Element &, const XmlObjMgt_DOMString &>(), py::arg("theParent"), py::arg("theName"));
	cls_XmlObjMgt_Array1.def("CreateArrayElement", (void (XmlObjMgt_Array1::*)(XmlObjMgt_Element &, const XmlObjMgt_DOMString &)) &XmlObjMgt_Array1::CreateArrayElement, "Create DOM_Element representing the array, under 'theParent'", py::arg("theParent"), py::arg("theName"));
	cls_XmlObjMgt_Array1.def("Element", (const XmlObjMgt_Element & (XmlObjMgt_Array1::*)() const ) &XmlObjMgt_Array1::Element, "Returns the DOM element of <me>.");
	cls_XmlObjMgt_Array1.def("Length", (Standard_Integer (XmlObjMgt_Array1::*)() const ) &XmlObjMgt_Array1::Length, "Returns the number of elements of <me>.");
	cls_XmlObjMgt_Array1.def("Lower", (Standard_Integer (XmlObjMgt_Array1::*)() const ) &XmlObjMgt_Array1::Lower, "Returns the lower bound.");
	cls_XmlObjMgt_Array1.def("Upper", (Standard_Integer (XmlObjMgt_Array1::*)() const ) &XmlObjMgt_Array1::Upper, "Returns the upper bound.");
	cls_XmlObjMgt_Array1.def("SetValue", (void (XmlObjMgt_Array1::*)(const Standard_Integer, XmlObjMgt_Element &)) &XmlObjMgt_Array1::SetValue, "Set the <Index>th element of the array to <Value>.", py::arg("Index"), py::arg("Value"));
	cls_XmlObjMgt_Array1.def("Value", (XmlObjMgt_Element (XmlObjMgt_Array1::*)(const Standard_Integer) const ) &XmlObjMgt_Array1::Value, "Returns the value of <Index>th element of the array.", py::arg("Index"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\XmlObjMgt.hxx
	py::class_<XmlObjMgt, std::unique_ptr<XmlObjMgt, Deleter<XmlObjMgt>>> cls_XmlObjMgt(mod, "XmlObjMgt", "This package defines services to manage the storage grain of data produced by applications and those classes to manage persistent extern reference.");
	cls_XmlObjMgt.def(py::init<>());
	cls_XmlObjMgt.def_static("IdString_", (const XmlObjMgt_DOMString & (*)()) &XmlObjMgt::IdString, "Define the name of XMLattribute 'ID' (to be used everywhere)");
	cls_XmlObjMgt.def_static("SetExtendedString_", (Standard_Boolean (*)(XmlObjMgt_Element &, const TCollection_ExtendedString &)) &XmlObjMgt::SetExtendedString, "Add attribute <theElement extstring='theString' ...>", py::arg("theElement"), py::arg("theString"));
	cls_XmlObjMgt.def_static("GetExtendedString_", (Standard_Boolean (*)(const XmlObjMgt_Element &, TCollection_ExtendedString &)) &XmlObjMgt::GetExtendedString, "Get attribute <theElement extstring='theString' ...>", py::arg("theElement"), py::arg("theString"));
	cls_XmlObjMgt.def_static("GetStringValue_", (XmlObjMgt_DOMString (*)(const XmlObjMgt_Element &)) &XmlObjMgt::GetStringValue, "Returns the first child text node", py::arg("theElement"));
	cls_XmlObjMgt.def_static("SetStringValue_", [](XmlObjMgt_Element & a0, const XmlObjMgt_DOMString & a1) -> void { return XmlObjMgt::SetStringValue(a0, a1); }, py::arg("theElement"), py::arg("theData"));
	cls_XmlObjMgt.def_static("SetStringValue_", (void (*)(XmlObjMgt_Element &, const XmlObjMgt_DOMString &, const Standard_Boolean)) &XmlObjMgt::SetStringValue, "Add theData as the last child text node to theElement isClearText(True) avoids analysis of the string and replacement of characters like '<' and '&' during XML file storage. Do NEVER set isClearText unless you have a hell of a reason", py::arg("theElement"), py::arg("theData"), py::arg("isClearText"));
	cls_XmlObjMgt.def_static("GetTagEntryString_", (Standard_Boolean (*)(const XmlObjMgt_DOMString &, TCollection_AsciiString &)) &XmlObjMgt::GetTagEntryString, "Convert XPath expression (DOMString) into TagEntry string returns False on Error", py::arg("theTarget"), py::arg("theTagEntry"));
	cls_XmlObjMgt.def_static("SetTagEntryString_", (void (*)(XmlObjMgt_DOMString &, const TCollection_AsciiString &)) &XmlObjMgt::SetTagEntryString, "Convert XPath expression (DOMString) into TagEntry string returns False on Error", py::arg("theSource"), py::arg("theTagEntry"));
	cls_XmlObjMgt.def_static("FindChildElement_", (XmlObjMgt_Element (*)(const XmlObjMgt_Element &, const Standard_Integer)) &XmlObjMgt::FindChildElement, "None", py::arg("theSource"), py::arg("theObjId"));
	cls_XmlObjMgt.def_static("FindChildByRef_", (XmlObjMgt_Element (*)(const XmlObjMgt_Element &, const XmlObjMgt_DOMString &)) &XmlObjMgt::FindChildByRef, "None", py::arg("theSource"), py::arg("theRefName"));
	cls_XmlObjMgt.def_static("FindChildByName_", (XmlObjMgt_Element (*)(const XmlObjMgt_Element &, const XmlObjMgt_DOMString &)) &XmlObjMgt::FindChildByName, "None", py::arg("theSource"), py::arg("theName"));
	// FIXME 	cls_XmlObjMgt.def_static("GetInteger_", [](Standard_CString & theString, Standard_Integer & theValue){ Standard_Boolean rv = XmlObjMgt::GetInteger(theString, theValue); return std::tuple<Standard_Boolean, Standard_CString &, Standard_Integer &>(rv, theString, theValue); }, "None", py::arg("theString"), py::arg("theValue"));
	// FIXME 	cls_XmlObjMgt.def_static("GetReal_", [](Standard_CString & theString, Standard_Real & theValue){ Standard_Boolean rv = XmlObjMgt::GetReal(theString, theValue); return std::tuple<Standard_Boolean, Standard_CString &, Standard_Real &>(rv, theString, theValue); }, "None", py::arg("theString"), py::arg("theValue"));
	// FIXME 	cls_XmlObjMgt.def_static("GetReal_", [](const XmlObjMgt_DOMString & theString, Standard_Real & theValue){ Standard_Boolean rv = XmlObjMgt::GetReal(theString, theValue); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theValue); }, "None", py::arg("theString"), py::arg("theValue"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\XmlObjMgt_RRelocationTable.hxx
	other_mod = py::module::import("OCCT.BinObjMgt");
	if (py::hasattr(other_mod, "BinObjMgt_RRelocationTable")) {
		mod.attr("XmlObjMgt_RRelocationTable") = other_mod.attr("BinObjMgt_RRelocationTable");
	}

	// C:\Miniconda\envs\occt\Library\include\opencascade\XmlObjMgt_Element.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\XmlObjMgt_SRelocationTable.hxx
	other_mod = py::module::import("OCCT.BinObjMgt");
	if (py::hasattr(other_mod, "BinObjMgt_SRelocationTable")) {
		mod.attr("XmlObjMgt_SRelocationTable") = other_mod.attr("BinObjMgt_SRelocationTable");
	}

	// C:\Miniconda\envs\occt\Library\include\opencascade\XmlObjMgt_Document.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\XmlObjMgt_DOMString.hxx

}
