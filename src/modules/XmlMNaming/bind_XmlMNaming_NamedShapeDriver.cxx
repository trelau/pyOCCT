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
#include <XmlMDF_ADriver.hxx>
#include <Standard_Handle.hxx>
#include <Message_Messenger.hxx>
#include <TDF_Attribute.hxx>
#include <Standard_TypeDef.hxx>
#include <XmlObjMgt_Persistent.hxx>
#include <XmlObjMgt_RRelocationTable.hxx>
#include <XmlObjMgt_SRelocationTable.hxx>
#include <XmlObjMgt_Element.hxx>
#include <TopTools_LocationSet.hxx>
#include <XmlMNaming_NamedShapeDriver.hxx>
#include <Standard_Type.hxx>
#include <BRepTools_ShapeSet.hxx>

void bind_XmlMNaming_NamedShapeDriver(py::module &mod){

py::class_<XmlMNaming_NamedShapeDriver, opencascade::handle<XmlMNaming_NamedShapeDriver>, XmlMDF_ADriver> cls_XmlMNaming_NamedShapeDriver(mod, "XmlMNaming_NamedShapeDriver", "None");

// Constructors
cls_XmlMNaming_NamedShapeDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("aMessageDriver"));

// Fields

// Methods
cls_XmlMNaming_NamedShapeDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XmlMNaming_NamedShapeDriver::*)() const) &XmlMNaming_NamedShapeDriver::NewEmpty, "None");
cls_XmlMNaming_NamedShapeDriver.def("Paste", (Standard_Boolean (XmlMNaming_NamedShapeDriver::*)(const XmlObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, XmlObjMgt_RRelocationTable &) const) &XmlMNaming_NamedShapeDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
cls_XmlMNaming_NamedShapeDriver.def("Paste", (void (XmlMNaming_NamedShapeDriver::*)(const opencascade::handle<TDF_Attribute> &, XmlObjMgt_Persistent &, XmlObjMgt_SRelocationTable &) const) &XmlMNaming_NamedShapeDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
cls_XmlMNaming_NamedShapeDriver.def("ReadShapeSection", (void (XmlMNaming_NamedShapeDriver::*)(const XmlObjMgt_Element &)) &XmlMNaming_NamedShapeDriver::ReadShapeSection, "Input the shapes from DOM element", py::arg("anElement"));
cls_XmlMNaming_NamedShapeDriver.def("WriteShapeSection", (void (XmlMNaming_NamedShapeDriver::*)(XmlObjMgt_Element &)) &XmlMNaming_NamedShapeDriver::WriteShapeSection, "Output the shapes into DOM element", py::arg("anElement"));
cls_XmlMNaming_NamedShapeDriver.def("Clear", (void (XmlMNaming_NamedShapeDriver::*)()) &XmlMNaming_NamedShapeDriver::Clear, "Clear myShapeSet");
cls_XmlMNaming_NamedShapeDriver.def("GetShapesLocations", (TopTools_LocationSet & (XmlMNaming_NamedShapeDriver::*)()) &XmlMNaming_NamedShapeDriver::GetShapesLocations, "get the format of topology");
cls_XmlMNaming_NamedShapeDriver.def_static("get_type_name_", (const char * (*)()) &XmlMNaming_NamedShapeDriver::get_type_name, "None");
cls_XmlMNaming_NamedShapeDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlMNaming_NamedShapeDriver::get_type_descriptor, "None");
cls_XmlMNaming_NamedShapeDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlMNaming_NamedShapeDriver::*)() const) &XmlMNaming_NamedShapeDriver::DynamicType, "None");

// Enums

}