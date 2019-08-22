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
#include <XmlObjMgt_Document.hxx>
#include <XmlObjMgt_Element.hxx>
#include <Standard_TypeDef.hxx>
#include <TopAbs_Orientation.hxx>
#include <TopoDS_Shape.hxx>
#include <XmlMNaming_Shape1.hxx>

void bind_XmlMNaming_Shape1(py::module &mod){

py::class_<XmlMNaming_Shape1> cls_XmlMNaming_Shape1(mod, "XmlMNaming_Shape1", "The XmlMNaming_Shape1 is the Persistent view of a TopoDS_Shape.");

// Constructors
cls_XmlMNaming_Shape1.def(py::init<XmlObjMgt_Document &>(), py::arg("Doc"));
cls_XmlMNaming_Shape1.def(py::init<const XmlObjMgt_Element &>(), py::arg("E"));

// Fields

// Methods
// cls_XmlMNaming_Shape1.def_static("operator new_", (void * (*)(size_t)) &XmlMNaming_Shape1::operator new, "None", py::arg("theSize"));
// cls_XmlMNaming_Shape1.def_static("operator delete_", (void (*)(void *)) &XmlMNaming_Shape1::operator delete, "None", py::arg("theAddress"));
// cls_XmlMNaming_Shape1.def_static("operator new[]_", (void * (*)(size_t)) &XmlMNaming_Shape1::operator new[], "None", py::arg("theSize"));
// cls_XmlMNaming_Shape1.def_static("operator delete[]_", (void (*)(void *)) &XmlMNaming_Shape1::operator delete[], "None", py::arg("theAddress"));
// cls_XmlMNaming_Shape1.def_static("operator new_", (void * (*)(size_t, void *)) &XmlMNaming_Shape1::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_XmlMNaming_Shape1.def_static("operator delete_", (void (*)(void *, void *)) &XmlMNaming_Shape1::operator delete, "None", py::arg(""), py::arg(""));
cls_XmlMNaming_Shape1.def("Element", (const XmlObjMgt_Element & (XmlMNaming_Shape1::*)() const) &XmlMNaming_Shape1::Element, "return myElement");
cls_XmlMNaming_Shape1.def("Element", (XmlObjMgt_Element & (XmlMNaming_Shape1::*)()) &XmlMNaming_Shape1::Element, "return myElement");
cls_XmlMNaming_Shape1.def("TShapeId", (Standard_Integer (XmlMNaming_Shape1::*)() const) &XmlMNaming_Shape1::TShapeId, "None");
cls_XmlMNaming_Shape1.def("LocId", (Standard_Integer (XmlMNaming_Shape1::*)() const) &XmlMNaming_Shape1::LocId, "None");
cls_XmlMNaming_Shape1.def("Orientation", (TopAbs_Orientation (XmlMNaming_Shape1::*)() const) &XmlMNaming_Shape1::Orientation, "None");
cls_XmlMNaming_Shape1.def("SetShape", (void (XmlMNaming_Shape1::*)(const Standard_Integer, const Standard_Integer, const TopAbs_Orientation)) &XmlMNaming_Shape1::SetShape, "None", py::arg("ID"), py::arg("LocID"), py::arg("Orient"));
cls_XmlMNaming_Shape1.def("SetVertex", (void (XmlMNaming_Shape1::*)(const TopoDS_Shape &)) &XmlMNaming_Shape1::SetVertex, "None", py::arg("theVertex"));

// Enums

}