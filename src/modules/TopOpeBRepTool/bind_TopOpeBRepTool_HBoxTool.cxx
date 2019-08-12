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
#include <TopoDS_Shape.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <Bnd_Box.hxx>
#include <Standard_TypeDef.hxx>
#include <TopOpeBRepTool_IndexedDataMapOfShapeBox.hxx>
#include <Standard_Handle.hxx>
#include <TopOpeBRepTool_HBoxTool.hxx>
#include <Standard_Type.hxx>

void bind_TopOpeBRepTool_HBoxTool(py::module &mod){

py::class_<TopOpeBRepTool_HBoxTool, opencascade::handle<TopOpeBRepTool_HBoxTool>, Standard_Transient> cls_TopOpeBRepTool_HBoxTool(mod, "TopOpeBRepTool_HBoxTool", "None");

// Constructors
cls_TopOpeBRepTool_HBoxTool.def(py::init<>());

// Fields

// Methods
cls_TopOpeBRepTool_HBoxTool.def("Clear", (void (TopOpeBRepTool_HBoxTool::*)()) &TopOpeBRepTool_HBoxTool::Clear, "None");
cls_TopOpeBRepTool_HBoxTool.def("AddBoxes", [](TopOpeBRepTool_HBoxTool &self, const TopoDS_Shape & a0, const TopAbs_ShapeEnum a1) -> void { return self.AddBoxes(a0, a1); });
cls_TopOpeBRepTool_HBoxTool.def("AddBoxes", (void (TopOpeBRepTool_HBoxTool::*)(const TopoDS_Shape &, const TopAbs_ShapeEnum, const TopAbs_ShapeEnum)) &TopOpeBRepTool_HBoxTool::AddBoxes, "None", py::arg("S"), py::arg("TS"), py::arg("TA"));
cls_TopOpeBRepTool_HBoxTool.def("AddBox", (void (TopOpeBRepTool_HBoxTool::*)(const TopoDS_Shape &)) &TopOpeBRepTool_HBoxTool::AddBox, "None", py::arg("S"));
cls_TopOpeBRepTool_HBoxTool.def_static("ComputeBox_", (void (*)(const TopoDS_Shape &, Bnd_Box &)) &TopOpeBRepTool_HBoxTool::ComputeBox, "None", py::arg("S"), py::arg("B"));
cls_TopOpeBRepTool_HBoxTool.def_static("ComputeBoxOnVertices_", (void (*)(const TopoDS_Shape &, Bnd_Box &)) &TopOpeBRepTool_HBoxTool::ComputeBoxOnVertices, "None", py::arg("S"), py::arg("B"));
cls_TopOpeBRepTool_HBoxTool.def_static("DumpB_", (void (*)(const Bnd_Box &)) &TopOpeBRepTool_HBoxTool::DumpB, "None", py::arg("B"));
cls_TopOpeBRepTool_HBoxTool.def("Box", (const Bnd_Box & (TopOpeBRepTool_HBoxTool::*)(const TopoDS_Shape &)) &TopOpeBRepTool_HBoxTool::Box, "None", py::arg("S"));
cls_TopOpeBRepTool_HBoxTool.def("Box", (const Bnd_Box & (TopOpeBRepTool_HBoxTool::*)(const Standard_Integer) const) &TopOpeBRepTool_HBoxTool::Box, "None", py::arg("I"));
cls_TopOpeBRepTool_HBoxTool.def("HasBox", (Standard_Boolean (TopOpeBRepTool_HBoxTool::*)(const TopoDS_Shape &) const) &TopOpeBRepTool_HBoxTool::HasBox, "None", py::arg("S"));
cls_TopOpeBRepTool_HBoxTool.def("Shape", (const TopoDS_Shape & (TopOpeBRepTool_HBoxTool::*)(const Standard_Integer) const) &TopOpeBRepTool_HBoxTool::Shape, "None", py::arg("I"));
cls_TopOpeBRepTool_HBoxTool.def("Index", (Standard_Integer (TopOpeBRepTool_HBoxTool::*)(const TopoDS_Shape &) const) &TopOpeBRepTool_HBoxTool::Index, "None", py::arg("S"));
cls_TopOpeBRepTool_HBoxTool.def("Extent", (Standard_Integer (TopOpeBRepTool_HBoxTool::*)() const) &TopOpeBRepTool_HBoxTool::Extent, "None");
cls_TopOpeBRepTool_HBoxTool.def("ChangeIMS", (TopOpeBRepTool_IndexedDataMapOfShapeBox & (TopOpeBRepTool_HBoxTool::*)()) &TopOpeBRepTool_HBoxTool::ChangeIMS, "None");
cls_TopOpeBRepTool_HBoxTool.def("IMS", (const TopOpeBRepTool_IndexedDataMapOfShapeBox & (TopOpeBRepTool_HBoxTool::*)() const) &TopOpeBRepTool_HBoxTool::IMS, "None");
cls_TopOpeBRepTool_HBoxTool.def_static("get_type_name_", (const char * (*)()) &TopOpeBRepTool_HBoxTool::get_type_name, "None");
cls_TopOpeBRepTool_HBoxTool.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TopOpeBRepTool_HBoxTool::get_type_descriptor, "None");
cls_TopOpeBRepTool_HBoxTool.def("DynamicType", (const opencascade::handle<Standard_Type> & (TopOpeBRepTool_HBoxTool::*)() const) &TopOpeBRepTool_HBoxTool::DynamicType, "None");

// Enums

}