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
#include <BRepExtrema_ElementFilter.hxx>
#include <BRepExtrema_OverlapTool.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Shape.hxx>
#include <BRepExtrema_MapOfIntegerPackedMapOfInteger.hxx>
#include <TopoDS_Face.hxx>
#include <Standard_Handle.hxx>
#include <BRepExtrema_TriangleSet.hxx>
#include <BVH_Types.hxx>
#include <BRepExtrema_SelfIntersection.hxx>

void bind_BRepExtrema_SelfIntersection(py::module &mod){

py::class_<BRepExtrema_SelfIntersection, std::unique_ptr<BRepExtrema_SelfIntersection, Deleter<BRepExtrema_SelfIntersection>>, BRepExtrema_ElementFilter> cls_BRepExtrema_SelfIntersection(mod, "BRepExtrema_SelfIntersection", "Tool class for detection of self-sections in the given shape. This class is based on BRepExtrema_OverlapTool and thus uses shape tessellation to detect incorrect mesh fragments (pairs of overlapped triangles belonging to different faces). Thus, a result depends critically on the quality of mesh generator (e.g., BREP mesh is not always a good choice, because it can contain gaps between adjacent face triangulations, which may not share vertices on common edge; thus false overlap can be detected). As a result, this tool can be used for relatively fast approximated test which provides sub-set of potentially overlapped faces.");

// Constructors
cls_BRepExtrema_SelfIntersection.def(py::init<>());
cls_BRepExtrema_SelfIntersection.def(py::init<const Standard_Real>(), py::arg("theTolerance"));
cls_BRepExtrema_SelfIntersection.def(py::init<const TopoDS_Shape &>(), py::arg("theShape"));
cls_BRepExtrema_SelfIntersection.def(py::init<const TopoDS_Shape &, const Standard_Real>(), py::arg("theShape"), py::arg("theTolerance"));

// Fields

// Methods
cls_BRepExtrema_SelfIntersection.def("Tolerance", (Standard_Real (BRepExtrema_SelfIntersection::*)() const) &BRepExtrema_SelfIntersection::Tolerance, "Returns tolerance value used for self-intersection test.");
cls_BRepExtrema_SelfIntersection.def("SetTolerance", (void (BRepExtrema_SelfIntersection::*)(const Standard_Real)) &BRepExtrema_SelfIntersection::SetTolerance, "Sets tolerance value used for self-intersection test.", py::arg("theTolerance"));
cls_BRepExtrema_SelfIntersection.def("LoadShape", (Standard_Boolean (BRepExtrema_SelfIntersection::*)(const TopoDS_Shape &)) &BRepExtrema_SelfIntersection::LoadShape, "Loads shape for detection of self-intersections.", py::arg("theShape"));
cls_BRepExtrema_SelfIntersection.def("Perform", (void (BRepExtrema_SelfIntersection::*)()) &BRepExtrema_SelfIntersection::Perform, "Performs detection of self-intersections.");
cls_BRepExtrema_SelfIntersection.def("IsDone", (Standard_Boolean (BRepExtrema_SelfIntersection::*)() const) &BRepExtrema_SelfIntersection::IsDone, "True if the detection is completed.");
cls_BRepExtrema_SelfIntersection.def("OverlapElements", (const BRepExtrema_MapOfIntegerPackedMapOfInteger & (BRepExtrema_SelfIntersection::*)() const) &BRepExtrema_SelfIntersection::OverlapElements, "Returns set of IDs of overlapped sub-shapes (started from 0).");
cls_BRepExtrema_SelfIntersection.def("GetSubShape", (const TopoDS_Face & (BRepExtrema_SelfIntersection::*)(const Standard_Integer) const) &BRepExtrema_SelfIntersection::GetSubShape, "Returns sub-shape from the shape for the given index (started from 0).", py::arg("theID"));
cls_BRepExtrema_SelfIntersection.def("ElementSet", (const opencascade::handle<BRepExtrema_TriangleSet> & (BRepExtrema_SelfIntersection::*)() const) &BRepExtrema_SelfIntersection::ElementSet, "Returns set of all the face triangles of the shape.");

// Enums

}