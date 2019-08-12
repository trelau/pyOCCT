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
#include <TopTools_LocationSet.hxx>
#include <XmlMDF_ADriver.hxx>
#include <Standard_Handle.hxx>
#include <Message_Messenger.hxx>
#include <TDF_Attribute.hxx>
#include <Standard_TypeDef.hxx>
#include <XmlObjMgt_Persistent.hxx>
#include <XmlObjMgt_RRelocationTable.hxx>
#include <XmlObjMgt_SRelocationTable.hxx>
#include <TopLoc_Location.hxx>
#include <XmlObjMgt_Element.hxx>
#include <TopTools_LocationSetPtr.hxx>
#include <XmlMXCAFDoc_LocationDriver.hxx>
#include <Standard_Type.hxx>

void bind_XmlMXCAFDoc_LocationDriver(py::module &mod){

py::class_<XmlMXCAFDoc_LocationDriver, opencascade::handle<XmlMXCAFDoc_LocationDriver>, XmlMDF_ADriver> cls_XmlMXCAFDoc_LocationDriver(mod, "XmlMXCAFDoc_LocationDriver", "Attribute Driver.");

// Constructors
cls_XmlMXCAFDoc_LocationDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Fields

// Methods
cls_XmlMXCAFDoc_LocationDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XmlMXCAFDoc_LocationDriver::*)() const) &XmlMXCAFDoc_LocationDriver::NewEmpty, "None");
cls_XmlMXCAFDoc_LocationDriver.def("Paste", (Standard_Boolean (XmlMXCAFDoc_LocationDriver::*)(const XmlObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, XmlObjMgt_RRelocationTable &) const) &XmlMXCAFDoc_LocationDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMXCAFDoc_LocationDriver.def("Paste", (void (XmlMXCAFDoc_LocationDriver::*)(const opencascade::handle<TDF_Attribute> &, XmlObjMgt_Persistent &, XmlObjMgt_SRelocationTable &) const) &XmlMXCAFDoc_LocationDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMXCAFDoc_LocationDriver.def("Translate", (void (XmlMXCAFDoc_LocationDriver::*)(const TopLoc_Location &, XmlObjMgt_Element &, XmlObjMgt_SRelocationTable &) const) &XmlMXCAFDoc_LocationDriver::Translate, "Translate a non storable Location to a storable Location.", py::arg("theLoc"), py::arg("theParent"), py::arg("theMap"));
cls_XmlMXCAFDoc_LocationDriver.def("Translate", (Standard_Boolean (XmlMXCAFDoc_LocationDriver::*)(const XmlObjMgt_Element &, TopLoc_Location &, XmlObjMgt_RRelocationTable &) const) &XmlMXCAFDoc_LocationDriver::Translate, "Translate a storable Location to a non storable Location.", py::arg("theParent"), py::arg("theLoc"), py::arg("theMap"));
cls_XmlMXCAFDoc_LocationDriver.def("SetSharedLocations", (void (XmlMXCAFDoc_LocationDriver::*)(const TopTools_LocationSetPtr &)) &XmlMXCAFDoc_LocationDriver::SetSharedLocations, "None", py::arg("theLocations"));
cls_XmlMXCAFDoc_LocationDriver.def_static("get_type_name_", (const char * (*)()) &XmlMXCAFDoc_LocationDriver::get_type_name, "None");
cls_XmlMXCAFDoc_LocationDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlMXCAFDoc_LocationDriver::get_type_descriptor, "None");
cls_XmlMXCAFDoc_LocationDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlMXCAFDoc_LocationDriver::*)() const) &XmlMXCAFDoc_LocationDriver::DynamicType, "None");

// Enums

}