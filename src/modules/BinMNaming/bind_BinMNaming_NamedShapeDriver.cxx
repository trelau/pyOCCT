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
#include <BinMDF_ADriver.hxx>
#include <Standard_Handle.hxx>
#include <Message_Messenger.hxx>
#include <TDF_Attribute.hxx>
#include <Standard_TypeDef.hxx>
#include <BinObjMgt_Persistent.hxx>
#include <BinObjMgt_RRelocationTable.hxx>
#include <BinObjMgt_SRelocationTable.hxx>
#include <Standard_IStream.hxx>
#include <Standard_OStream.hxx>
#include <BinTools_LocationSet.hxx>
#include <BinMNaming_NamedShapeDriver.hxx>
#include <Standard_Type.hxx>
#include <BinTools_ShapeSet.hxx>

void bind_BinMNaming_NamedShapeDriver(py::module &mod){

py::class_<BinMNaming_NamedShapeDriver, opencascade::handle<BinMNaming_NamedShapeDriver>, BinMDF_ADriver> cls_BinMNaming_NamedShapeDriver(mod, "BinMNaming_NamedShapeDriver", "NamedShape Attribute Driver.");

// Constructors
cls_BinMNaming_NamedShapeDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Fields

// Methods
cls_BinMNaming_NamedShapeDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMNaming_NamedShapeDriver::*)() const) &BinMNaming_NamedShapeDriver::NewEmpty, "None");
cls_BinMNaming_NamedShapeDriver.def("Paste", (Standard_Boolean (BinMNaming_NamedShapeDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const) &BinMNaming_NamedShapeDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_BinMNaming_NamedShapeDriver.def("Paste", (void (BinMNaming_NamedShapeDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const) &BinMNaming_NamedShapeDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_BinMNaming_NamedShapeDriver.def("ReadShapeSection", (void (BinMNaming_NamedShapeDriver::*)(Standard_IStream &)) &BinMNaming_NamedShapeDriver::ReadShapeSection, "Input the shapes from Bin Document file", py::arg("theIS"));
cls_BinMNaming_NamedShapeDriver.def("WriteShapeSection", (void (BinMNaming_NamedShapeDriver::*)(Standard_OStream &)) &BinMNaming_NamedShapeDriver::WriteShapeSection, "Output the shapes into Bin Document file", py::arg("theOS"));
cls_BinMNaming_NamedShapeDriver.def("Clear", (void (BinMNaming_NamedShapeDriver::*)()) &BinMNaming_NamedShapeDriver::Clear, "Clear myShapeSet");
cls_BinMNaming_NamedShapeDriver.def("IsWithTriangles", (Standard_Boolean (BinMNaming_NamedShapeDriver::*)() const) &BinMNaming_NamedShapeDriver::IsWithTriangles, "Return true if shape should be stored with triangles.");
cls_BinMNaming_NamedShapeDriver.def("SetWithTriangles", (void (BinMNaming_NamedShapeDriver::*)(const Standard_Boolean)) &BinMNaming_NamedShapeDriver::SetWithTriangles, "set whether to store triangulation", py::arg("isWithTriangles"));
cls_BinMNaming_NamedShapeDriver.def("SetFormatNb", (void (BinMNaming_NamedShapeDriver::*)(const Standard_Integer)) &BinMNaming_NamedShapeDriver::SetFormatNb, "set the format of topology First : does not write CurveOnSurface UV Points into the file on reading calls Check() method. Second: stores CurveOnSurface UV Points.", py::arg("theFormat"));
cls_BinMNaming_NamedShapeDriver.def("GetFormatNb", (Standard_Integer (BinMNaming_NamedShapeDriver::*)() const) &BinMNaming_NamedShapeDriver::GetFormatNb, "get the format of topology");
cls_BinMNaming_NamedShapeDriver.def("GetShapesLocations", (BinTools_LocationSet & (BinMNaming_NamedShapeDriver::*)()) &BinMNaming_NamedShapeDriver::GetShapesLocations, "get the format of topology");
cls_BinMNaming_NamedShapeDriver.def_static("get_type_name_", (const char * (*)()) &BinMNaming_NamedShapeDriver::get_type_name, "None");
cls_BinMNaming_NamedShapeDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMNaming_NamedShapeDriver::get_type_descriptor, "None");
cls_BinMNaming_NamedShapeDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMNaming_NamedShapeDriver::*)() const) &BinMNaming_NamedShapeDriver::DynamicType, "None");

// Enums

}