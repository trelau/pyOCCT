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
#include <TopExp_Explorer.hxx>
#include <TopoDS_Shape.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_OStream.hxx>
#include <TopAbs.hxx>
#include <TopOpeBRepTool_ShapeExplorer.hxx>

void bind_TopOpeBRepTool_ShapeExplorer(py::module &mod){

py::class_<TopOpeBRepTool_ShapeExplorer, std::unique_ptr<TopOpeBRepTool_ShapeExplorer, Deleter<TopOpeBRepTool_ShapeExplorer>>, TopExp_Explorer> cls_TopOpeBRepTool_ShapeExplorer(mod, "TopOpeBRepTool_ShapeExplorer", "Extends TopExp_Explorer by counting index of current item (for tracing and debug)");

// Constructors
cls_TopOpeBRepTool_ShapeExplorer.def(py::init<>());
cls_TopOpeBRepTool_ShapeExplorer.def(py::init<const TopoDS_Shape &, const TopAbs_ShapeEnum>(), py::arg("S"), py::arg("ToFind"));
cls_TopOpeBRepTool_ShapeExplorer.def(py::init<const TopoDS_Shape &, const TopAbs_ShapeEnum, const TopAbs_ShapeEnum>(), py::arg("S"), py::arg("ToFind"), py::arg("ToAvoid"));

// Fields

// Methods
cls_TopOpeBRepTool_ShapeExplorer.def("Init", [](TopOpeBRepTool_ShapeExplorer &self, const TopoDS_Shape & a0, const TopAbs_ShapeEnum a1) -> void { return self.Init(a0, a1); });
cls_TopOpeBRepTool_ShapeExplorer.def("Init", (void (TopOpeBRepTool_ShapeExplorer::*)(const TopoDS_Shape &, const TopAbs_ShapeEnum, const TopAbs_ShapeEnum)) &TopOpeBRepTool_ShapeExplorer::Init, "None", py::arg("S"), py::arg("ToFind"), py::arg("ToAvoid"));
cls_TopOpeBRepTool_ShapeExplorer.def("Next", (void (TopOpeBRepTool_ShapeExplorer::*)()) &TopOpeBRepTool_ShapeExplorer::Next, "Moves to the next Shape in the exploration.");
cls_TopOpeBRepTool_ShapeExplorer.def("Index", (Standard_Integer (TopOpeBRepTool_ShapeExplorer::*)() const) &TopOpeBRepTool_ShapeExplorer::Index, "Index of current sub-shape");
cls_TopOpeBRepTool_ShapeExplorer.def("DumpCurrent", (Standard_OStream & (TopOpeBRepTool_ShapeExplorer::*)(Standard_OStream &) const) &TopOpeBRepTool_ShapeExplorer::DumpCurrent, "Dump info on current shape to stream", py::arg("OS"));

// Enums

}