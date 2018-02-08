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

#include <XmlMDF_ADriver.hxx>
#include <Standard_Handle.hxx>
#include <CDM_MessageDriver.hxx>
#include <TDF_Attribute.hxx>
#include <Standard_TypeDef.hxx>
#include <XmlObjMgt_Persistent.hxx>
#include <XmlObjMgt_RRelocationTable.hxx>
#include <XmlObjMgt_SRelocationTable.hxx>
#include <XmlObjMgt_Element.hxx>
#include <TopTools_LocationSet.hxx>
#include <Standard_Type.hxx>
#include <XmlMNaming_NamedShapeDriver.hxx>
#include <XmlMNaming_NamingDriver.hxx>
#include <XmlObjMgt_Document.hxx>
#include <TopAbs_Orientation.hxx>
#include <TopoDS_Shape.hxx>
#include <XmlMNaming_Shape1.hxx>
#include <XmlMDF_ADriverTable.hxx>
#include <XmlMNaming.hxx>

PYBIND11_MODULE(XmlMNaming, mod) {

	// IMPORT
	py::module::import("OCCT.XmlMDF");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.CDM");
	py::module::import("OCCT.TDF");
	py::module::import("OCCT.XmlObjMgt");
	py::module::import("OCCT.TopTools");
	py::module::import("OCCT.TopAbs");
	py::module::import("OCCT.TopoDS");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\XmlMNaming_NamedShapeDriver.hxx
	py::class_<XmlMNaming_NamedShapeDriver, opencascade::handle<XmlMNaming_NamedShapeDriver>, XmlMDF_ADriver> cls_XmlMNaming_NamedShapeDriver(mod, "XmlMNaming_NamedShapeDriver", "None");
	cls_XmlMNaming_NamedShapeDriver.def(py::init<const opencascade::handle<CDM_MessageDriver> &>(), py::arg("aMessageDriver"));
	cls_XmlMNaming_NamedShapeDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XmlMNaming_NamedShapeDriver::*)() const ) &XmlMNaming_NamedShapeDriver::NewEmpty, "None");
	cls_XmlMNaming_NamedShapeDriver.def("Paste", (Standard_Boolean (XmlMNaming_NamedShapeDriver::*)(const XmlObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, XmlObjMgt_RRelocationTable &) const ) &XmlMNaming_NamedShapeDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
	cls_XmlMNaming_NamedShapeDriver.def("Paste", (void (XmlMNaming_NamedShapeDriver::*)(const opencascade::handle<TDF_Attribute> &, XmlObjMgt_Persistent &, XmlObjMgt_SRelocationTable &) const ) &XmlMNaming_NamedShapeDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
	cls_XmlMNaming_NamedShapeDriver.def("ReadShapeSection", (void (XmlMNaming_NamedShapeDriver::*)(const XmlObjMgt_Element &)) &XmlMNaming_NamedShapeDriver::ReadShapeSection, "Input the shapes from DOM element", py::arg("anElement"));
	cls_XmlMNaming_NamedShapeDriver.def("WriteShapeSection", (void (XmlMNaming_NamedShapeDriver::*)(XmlObjMgt_Element &)) &XmlMNaming_NamedShapeDriver::WriteShapeSection, "Output the shapes into DOM element", py::arg("anElement"));
	cls_XmlMNaming_NamedShapeDriver.def("Clear", (void (XmlMNaming_NamedShapeDriver::*)()) &XmlMNaming_NamedShapeDriver::Clear, "Clear myShapeSet");
	cls_XmlMNaming_NamedShapeDriver.def("GetShapesLocations", (TopTools_LocationSet & (XmlMNaming_NamedShapeDriver::*)()) &XmlMNaming_NamedShapeDriver::GetShapesLocations, "get the format of topology");
	cls_XmlMNaming_NamedShapeDriver.def_static("get_type_name_", (const char * (*)()) &XmlMNaming_NamedShapeDriver::get_type_name, "None");
	cls_XmlMNaming_NamedShapeDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlMNaming_NamedShapeDriver::get_type_descriptor, "None");
	cls_XmlMNaming_NamedShapeDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlMNaming_NamedShapeDriver::*)() const ) &XmlMNaming_NamedShapeDriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\XmlMNaming_NamingDriver.hxx
	py::class_<XmlMNaming_NamingDriver, opencascade::handle<XmlMNaming_NamingDriver>, XmlMDF_ADriver> cls_XmlMNaming_NamingDriver(mod, "XmlMNaming_NamingDriver", "None");
	cls_XmlMNaming_NamingDriver.def(py::init<const opencascade::handle<CDM_MessageDriver> &>(), py::arg("aMessageDriver"));
	cls_XmlMNaming_NamingDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XmlMNaming_NamingDriver::*)() const ) &XmlMNaming_NamingDriver::NewEmpty, "None");
	cls_XmlMNaming_NamingDriver.def("Paste", (Standard_Boolean (XmlMNaming_NamingDriver::*)(const XmlObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, XmlObjMgt_RRelocationTable &) const ) &XmlMNaming_NamingDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
	cls_XmlMNaming_NamingDriver.def("Paste", (void (XmlMNaming_NamingDriver::*)(const opencascade::handle<TDF_Attribute> &, XmlObjMgt_Persistent &, XmlObjMgt_SRelocationTable &) const ) &XmlMNaming_NamingDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
	cls_XmlMNaming_NamingDriver.def_static("get_type_name_", (const char * (*)()) &XmlMNaming_NamingDriver::get_type_name, "None");
	cls_XmlMNaming_NamingDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlMNaming_NamingDriver::get_type_descriptor, "None");
	cls_XmlMNaming_NamingDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlMNaming_NamingDriver::*)() const ) &XmlMNaming_NamingDriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\XmlMNaming_Shape1.hxx
	py::class_<XmlMNaming_Shape1, std::unique_ptr<XmlMNaming_Shape1, Deleter<XmlMNaming_Shape1>>> cls_XmlMNaming_Shape1(mod, "XmlMNaming_Shape1", "The XmlMNaming_Shape1 is the Persistent view of a TopoDS_Shape.");
	cls_XmlMNaming_Shape1.def(py::init<XmlObjMgt_Document &>(), py::arg("Doc"));
	cls_XmlMNaming_Shape1.def(py::init<const XmlObjMgt_Element &>(), py::arg("E"));
	cls_XmlMNaming_Shape1.def("Element", (const XmlObjMgt_Element & (XmlMNaming_Shape1::*)() const ) &XmlMNaming_Shape1::Element, "return myElement");
	cls_XmlMNaming_Shape1.def("Element", (XmlObjMgt_Element & (XmlMNaming_Shape1::*)()) &XmlMNaming_Shape1::Element, "return myElement");
	cls_XmlMNaming_Shape1.def("TShapeId", (Standard_Integer (XmlMNaming_Shape1::*)() const ) &XmlMNaming_Shape1::TShapeId, "None");
	cls_XmlMNaming_Shape1.def("LocId", (Standard_Integer (XmlMNaming_Shape1::*)() const ) &XmlMNaming_Shape1::LocId, "None");
	cls_XmlMNaming_Shape1.def("Orientation", (TopAbs_Orientation (XmlMNaming_Shape1::*)() const ) &XmlMNaming_Shape1::Orientation, "None");
	cls_XmlMNaming_Shape1.def("SetShape", (void (XmlMNaming_Shape1::*)(const Standard_Integer, const Standard_Integer, const TopAbs_Orientation)) &XmlMNaming_Shape1::SetShape, "None", py::arg("ID"), py::arg("LocID"), py::arg("Orient"));
	cls_XmlMNaming_Shape1.def("SetVertex", (void (XmlMNaming_Shape1::*)(const TopoDS_Shape &)) &XmlMNaming_Shape1::SetVertex, "None", py::arg("theVertex"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\XmlMNaming.hxx
	py::class_<XmlMNaming, std::unique_ptr<XmlMNaming, Deleter<XmlMNaming>>> cls_XmlMNaming(mod, "XmlMNaming", "None");
	cls_XmlMNaming.def(py::init<>());
	cls_XmlMNaming.def_static("AddDrivers_", (void (*)(const opencascade::handle<XmlMDF_ADriverTable> &, const opencascade::handle<CDM_MessageDriver> &)) &XmlMNaming::AddDrivers, "Adds the attribute drivers to <aDriverTable>.", py::arg("aDriverTable"), py::arg("aMessageDriver"));
	cls_XmlMNaming.def_static("SetDocumentVersion_", (void (*)(const Standard_Integer)) &XmlMNaming::SetDocumentVersion, "None", py::arg("DocVersion"));
	cls_XmlMNaming.def_static("DocumentVersion_", (Standard_Integer (*)()) &XmlMNaming::DocumentVersion, "None");


}
