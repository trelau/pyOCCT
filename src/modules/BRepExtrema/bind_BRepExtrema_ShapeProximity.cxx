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
#include <Standard_TypeDef.hxx>
#include <TopoDS_Shape.hxx>
#include <BRepExtrema_MapOfIntegerPackedMapOfInteger.hxx>
#include <TopoDS_Face.hxx>
#include <Standard_Handle.hxx>
#include <BRepExtrema_TriangleSet.hxx>
#include <BRepExtrema_OverlapTool.hxx>
#include <BRepExtrema_ShapeProximity.hxx>

void bind_BRepExtrema_ShapeProximity(py::module &mod){

py::class_<BRepExtrema_ShapeProximity, std::unique_ptr<BRepExtrema_ShapeProximity, Deleter<BRepExtrema_ShapeProximity>>> cls_BRepExtrema_ShapeProximity(mod, "BRepExtrema_ShapeProximity", "Tool class for shape proximity detection. For two given shapes and given tolerance (offset from the mesh) the algorithm allows to determine whether or not they are overlapped. The algorithm input consists of any shapes which can be decomposed into individual faces (used as basic shape elements). High performance is achieved through the use of existing triangulation of faces. So poly triangulation (with the desired deflection) should already be built. Note that solution is approximate (and corresponds to the deflection used for triangulation).");

// Constructors
cls_BRepExtrema_ShapeProximity.def(py::init<>());
cls_BRepExtrema_ShapeProximity.def(py::init<const Standard_Real>(), py::arg("theTolerance"));
cls_BRepExtrema_ShapeProximity.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &>(), py::arg("theShape1"), py::arg("theShape2"));
cls_BRepExtrema_ShapeProximity.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &, const Standard_Real>(), py::arg("theShape1"), py::arg("theShape2"), py::arg("theTolerance"));

// Fields

// Methods
cls_BRepExtrema_ShapeProximity.def("Tolerance", (Standard_Real (BRepExtrema_ShapeProximity::*)() const) &BRepExtrema_ShapeProximity::Tolerance, "Returns tolerance value for overlap test (distance between shapes).");
cls_BRepExtrema_ShapeProximity.def("SetTolerance", (void (BRepExtrema_ShapeProximity::*)(const Standard_Real)) &BRepExtrema_ShapeProximity::SetTolerance, "Sets tolerance value for overlap test (distance between shapes).", py::arg("theTolerance"));
cls_BRepExtrema_ShapeProximity.def("LoadShape1", (Standard_Boolean (BRepExtrema_ShapeProximity::*)(const TopoDS_Shape &)) &BRepExtrema_ShapeProximity::LoadShape1, "Loads 1st shape into proximity tool.", py::arg("theShape1"));
cls_BRepExtrema_ShapeProximity.def("LoadShape2", (Standard_Boolean (BRepExtrema_ShapeProximity::*)(const TopoDS_Shape &)) &BRepExtrema_ShapeProximity::LoadShape2, "Loads 2nd shape into proximity tool.", py::arg("theShape2"));
cls_BRepExtrema_ShapeProximity.def("Perform", (void (BRepExtrema_ShapeProximity::*)()) &BRepExtrema_ShapeProximity::Perform, "Performs search of overlapped faces.");
cls_BRepExtrema_ShapeProximity.def("IsDone", (Standard_Boolean (BRepExtrema_ShapeProximity::*)() const) &BRepExtrema_ShapeProximity::IsDone, "True if the search is completed.");
cls_BRepExtrema_ShapeProximity.def("OverlapSubShapes1", (const BRepExtrema_MapOfIntegerPackedMapOfInteger & (BRepExtrema_ShapeProximity::*)() const) &BRepExtrema_ShapeProximity::OverlapSubShapes1, "Returns set of IDs of overlapped faces of 1st shape (started from 0).");
cls_BRepExtrema_ShapeProximity.def("OverlapSubShapes2", (const BRepExtrema_MapOfIntegerPackedMapOfInteger & (BRepExtrema_ShapeProximity::*)() const) &BRepExtrema_ShapeProximity::OverlapSubShapes2, "Returns set of IDs of overlapped faces of 2nd shape (started from 0).");
cls_BRepExtrema_ShapeProximity.def("GetSubShape1", (const TopoDS_Face & (BRepExtrema_ShapeProximity::*)(const Standard_Integer) const) &BRepExtrema_ShapeProximity::GetSubShape1, "Returns sub-shape from 1st shape with the given index (started from 0).", py::arg("theID"));
cls_BRepExtrema_ShapeProximity.def("GetSubShape2", (const TopoDS_Face & (BRepExtrema_ShapeProximity::*)(const Standard_Integer) const) &BRepExtrema_ShapeProximity::GetSubShape2, "Returns sub-shape from 1st shape with the given index (started from 0).", py::arg("theID"));
cls_BRepExtrema_ShapeProximity.def("ElementSet1", (const opencascade::handle<BRepExtrema_TriangleSet> & (BRepExtrema_ShapeProximity::*)() const) &BRepExtrema_ShapeProximity::ElementSet1, "Returns set of all the face triangles of the 1st shape.");
cls_BRepExtrema_ShapeProximity.def("ElementSet2", (const opencascade::handle<BRepExtrema_TriangleSet> & (BRepExtrema_ShapeProximity::*)() const) &BRepExtrema_ShapeProximity::ElementSet2, "Returns set of all the face triangles of the 2nd shape.");

// Enums

}