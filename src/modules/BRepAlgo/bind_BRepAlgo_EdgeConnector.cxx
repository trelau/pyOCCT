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
#include <TopoDS_Edge.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <BRepAlgo_EdgeConnector.hxx>
#include <Standard_Type.hxx>
#include <BRepAlgo_DataMapOfShapeBoolean.hxx>
#include <TopOpeBRepBuild_BlockBuilder.hxx>

void bind_BRepAlgo_EdgeConnector(py::module &mod){

py::class_<BRepAlgo_EdgeConnector, opencascade::handle<BRepAlgo_EdgeConnector>, Standard_Transient> cls_BRepAlgo_EdgeConnector(mod, "BRepAlgo_EdgeConnector", "Used by DSAccess to reconstruct an EdgeSet of connected edges. The result produced by MakeBlock is a list of non-standard TopoDS_wire, which can present connexions of edge of order > 2 in certain vertex. The method IsWire indicates standard/non-standard character of all wire produced.");

// Constructors
cls_BRepAlgo_EdgeConnector.def(py::init<>());

// Fields

// Methods
cls_BRepAlgo_EdgeConnector.def("Add", (void (BRepAlgo_EdgeConnector::*)(const TopoDS_Edge &)) &BRepAlgo_EdgeConnector::Add, "None", py::arg("e"));
cls_BRepAlgo_EdgeConnector.def("Add", (void (BRepAlgo_EdgeConnector::*)(TopTools_ListOfShape &)) &BRepAlgo_EdgeConnector::Add, "None", py::arg("LOEdge"));
cls_BRepAlgo_EdgeConnector.def("AddStart", (void (BRepAlgo_EdgeConnector::*)(const TopoDS_Shape &)) &BRepAlgo_EdgeConnector::AddStart, "None", py::arg("e"));
cls_BRepAlgo_EdgeConnector.def("AddStart", (void (BRepAlgo_EdgeConnector::*)(TopTools_ListOfShape &)) &BRepAlgo_EdgeConnector::AddStart, "None", py::arg("LOEdge"));
cls_BRepAlgo_EdgeConnector.def("ClearStartElement", (void (BRepAlgo_EdgeConnector::*)()) &BRepAlgo_EdgeConnector::ClearStartElement, "None");
cls_BRepAlgo_EdgeConnector.def("MakeBlock", (TopTools_ListOfShape & (BRepAlgo_EdgeConnector::*)()) &BRepAlgo_EdgeConnector::MakeBlock, "returns a list of wire non standard");
cls_BRepAlgo_EdgeConnector.def("Done", (void (BRepAlgo_EdgeConnector::*)()) &BRepAlgo_EdgeConnector::Done, "None");
cls_BRepAlgo_EdgeConnector.def("IsDone", (Standard_Boolean (BRepAlgo_EdgeConnector::*)() const) &BRepAlgo_EdgeConnector::IsDone, "NYI returns true if proceeded to MakeBlock()");
cls_BRepAlgo_EdgeConnector.def("IsWire", (Standard_Boolean (BRepAlgo_EdgeConnector::*)(const TopoDS_Shape &)) &BRepAlgo_EdgeConnector::IsWire, "NYI returns true if W is a Wire standard. W must belong to the list returned by MakeBlock.", py::arg("W"));
cls_BRepAlgo_EdgeConnector.def_static("get_type_name_", (const char * (*)()) &BRepAlgo_EdgeConnector::get_type_name, "None");
cls_BRepAlgo_EdgeConnector.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepAlgo_EdgeConnector::get_type_descriptor, "None");
cls_BRepAlgo_EdgeConnector.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepAlgo_EdgeConnector::*)() const) &BRepAlgo_EdgeConnector::DynamicType, "None");

// Enums

}