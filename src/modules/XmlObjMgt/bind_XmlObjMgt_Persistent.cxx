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
#include <XmlObjMgt_Element.hxx>
#include <XmlObjMgt_DOMString.hxx>
#include <Standard_TypeDef.hxx>
#include <XmlObjMgt_Persistent.hxx>

void bind_XmlObjMgt_Persistent(py::module &mod){

py::class_<XmlObjMgt_Persistent> cls_XmlObjMgt_Persistent(mod, "XmlObjMgt_Persistent", "root for XML-persistence");

// Constructors
cls_XmlObjMgt_Persistent.def(py::init<>());
cls_XmlObjMgt_Persistent.def(py::init<const XmlObjMgt_Element &>(), py::arg("theElement"));
cls_XmlObjMgt_Persistent.def(py::init<const XmlObjMgt_Element &, const XmlObjMgt_DOMString &>(), py::arg("theElement"), py::arg("theRef"));

// Fields

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

// Enums

}