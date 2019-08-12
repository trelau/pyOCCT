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
#include <BVH_PrimitiveSet3d.hxx>
#include <BRepExtrema_TriangleSet.hxx>
#include <Standard_TypeDef.hxx>
#include <BVH_Box.hxx>
#include <BVH_Types.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Type.hxx>

void bind_BRepExtrema_TriangleSet(py::module &mod){

py::class_<BRepExtrema_TriangleSet, std::unique_ptr<BRepExtrema_TriangleSet, Deleter<BRepExtrema_TriangleSet>>, BVH_PrimitiveSet3d> cls_BRepExtrema_TriangleSet(mod, "BRepExtrema_TriangleSet", "Triangle set corresponding to specific face.");

// Constructors
cls_BRepExtrema_TriangleSet.def(py::init<>());
cls_BRepExtrema_TriangleSet.def(py::init<const BRepExtrema_ShapeList &>(), py::arg("theFaces"));

// Fields

// Methods
cls_BRepExtrema_TriangleSet.def("Size", (Standard_Integer (BRepExtrema_TriangleSet::*)() const) &BRepExtrema_TriangleSet::Size, "Returns total number of triangles.");
cls_BRepExtrema_TriangleSet.def("Box", (BVH_Box<Standard_Real, 3> (BRepExtrema_TriangleSet::*)(const Standard_Integer) const) &BRepExtrema_TriangleSet::Box, "Returns AABB of the given triangle.", py::arg("theIndex"));
cls_BRepExtrema_TriangleSet.def("Center", (Standard_Real (BRepExtrema_TriangleSet::*)(const Standard_Integer, const Standard_Integer) const) &BRepExtrema_TriangleSet::Center, "Returns centroid position along specified axis.", py::arg("theIndex"), py::arg("theAxis"));
cls_BRepExtrema_TriangleSet.def("Swap", (void (BRepExtrema_TriangleSet::*)(const Standard_Integer, const Standard_Integer)) &BRepExtrema_TriangleSet::Swap, "Swaps indices of two specified triangles.", py::arg("theIndex1"), py::arg("theIndex2"));
cls_BRepExtrema_TriangleSet.def("Clear", (void (BRepExtrema_TriangleSet::*)()) &BRepExtrema_TriangleSet::Clear, "Clears triangle set data.");
cls_BRepExtrema_TriangleSet.def("Init", (Standard_Boolean (BRepExtrema_TriangleSet::*)(const BRepExtrema_ShapeList &)) &BRepExtrema_TriangleSet::Init, "Initializes triangle set.", py::arg("theFaces"));
cls_BRepExtrema_TriangleSet.def("GetVertices", (void (BRepExtrema_TriangleSet::*)(const Standard_Integer, BVH_Vec3d &, BVH_Vec3d &, BVH_Vec3d &) const) &BRepExtrema_TriangleSet::GetVertices, "Returns vertices of the given triangle.", py::arg("theIndex"), py::arg("theVertex1"), py::arg("theVertex2"), py::arg("theVertex3"));
cls_BRepExtrema_TriangleSet.def("GetFaceID", (Standard_Integer (BRepExtrema_TriangleSet::*)(const Standard_Integer) const) &BRepExtrema_TriangleSet::GetFaceID, "Returns face ID of the given triangle.", py::arg("theIndex"));
cls_BRepExtrema_TriangleSet.def_static("get_type_name_", (const char * (*)()) &BRepExtrema_TriangleSet::get_type_name, "None");
cls_BRepExtrema_TriangleSet.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepExtrema_TriangleSet::get_type_descriptor, "None");
cls_BRepExtrema_TriangleSet.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepExtrema_TriangleSet::*)() const) &BRepExtrema_TriangleSet::DynamicType, "None");

// Enums

}