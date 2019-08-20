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
#include <Standard_Handle.hxx>
#include <BRepExtrema_TriangleSet.hxx>
#include <Standard_TypeDef.hxx>
#include <BRepExtrema_MapOfIntegerPackedMapOfInteger.hxx>
#include <BRepExtrema_ElementFilter.hxx>
#include <BVH_Types.hxx>
#include <BRepExtrema_OverlapTool.hxx>

void bind_BRepExtrema_OverlapTool(py::module &mod){

py::class_<BRepExtrema_OverlapTool, std::unique_ptr<BRepExtrema_OverlapTool>> cls_BRepExtrema_OverlapTool(mod, "BRepExtrema_OverlapTool", "Tool class for for detection of overlapping of two BVH primitive sets. This tool is not intended to be used independently, and is integrated in other classes, implementing algorithms based on shape tessellation (BRepExtrema_ShapeProximity and BRepExtrema_SelfIntersection).");

// Constructors
// cls_BRepExtrema_OverlapTool.def(py::init<>());
// cls_BRepExtrema_OverlapTool.def(py::init<const opencascade::handle<BRepExtrema_TriangleSet> &, const opencascade::handle<BRepExtrema_TriangleSet> &>(), py::arg("theSet1"), py::arg("theSet2"));

// Fields

// Methods
// cls_BRepExtrema_OverlapTool.def("LoadTriangleSets", (void (BRepExtrema_OverlapTool::*)(const opencascade::handle<BRepExtrema_TriangleSet> &, const opencascade::handle<BRepExtrema_TriangleSet> &)) &BRepExtrema_OverlapTool::LoadTriangleSets, "Loads the given element sets into the overlap tool.", py::arg("theSet1"), py::arg("theSet2"));
// cls_BRepExtrema_OverlapTool.def("Perform", [](BRepExtrema_OverlapTool &self) -> void { return self.Perform(); });
// cls_BRepExtrema_OverlapTool.def("Perform", (void (BRepExtrema_OverlapTool::*)(const Standard_Real)) &BRepExtrema_OverlapTool::Perform, "Performs searching of overlapped mesh elements.", py::arg("theTolerance"));
cls_BRepExtrema_OverlapTool.def("IsDone", (Standard_Boolean (BRepExtrema_OverlapTool::*)() const) &BRepExtrema_OverlapTool::IsDone, "Is overlap test completed?");
cls_BRepExtrema_OverlapTool.def("MarkDirty", (void (BRepExtrema_OverlapTool::*)()) &BRepExtrema_OverlapTool::MarkDirty, "Marks test results as outdated.");
cls_BRepExtrema_OverlapTool.def("OverlapSubShapes1", (const BRepExtrema_MapOfIntegerPackedMapOfInteger & (BRepExtrema_OverlapTool::*)() const) &BRepExtrema_OverlapTool::OverlapSubShapes1, "Returns set of overlapped sub-shapes of 1st shape (currently only faces are detected).");
cls_BRepExtrema_OverlapTool.def("OverlapSubShapes2", (const BRepExtrema_MapOfIntegerPackedMapOfInteger & (BRepExtrema_OverlapTool::*)() const) &BRepExtrema_OverlapTool::OverlapSubShapes2, "Returns set of overlapped sub-shapes of 2nd shape (currently only faces are detected).");
cls_BRepExtrema_OverlapTool.def("SetElementFilter", (void (BRepExtrema_OverlapTool::*)(BRepExtrema_ElementFilter *)) &BRepExtrema_OverlapTool::SetElementFilter, "Sets filtering tool for preliminary checking pairs of mesh elements.", py::arg("theFilter"));

// Enums

}