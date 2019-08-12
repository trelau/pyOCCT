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
#include <BRepTools_ReShape.hxx>
#include <Standard_TypeDef.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <TopoDS_Vertex.hxx>
#include <gp_Pnt.hxx>
#include <Standard_Handle.hxx>
#include <BRepTools_History.hxx>
#include <Standard_Type.hxx>
#include <NCollection_DataMap.hxx>
#include <TopTools_ShapeMapHasher.hxx>
#include <TopTools_MapOfShape.hxx>

void bind_BRepTools_ReShape(py::module &mod){

py::class_<BRepTools_ReShape, opencascade::handle<BRepTools_ReShape>, Standard_Transient> cls_BRepTools_ReShape(mod, "BRepTools_ReShape", "Rebuilds a Shape by making pre-defined substitutions on some of its components");

// Constructors
cls_BRepTools_ReShape.def(py::init<>());

// Fields

// Methods
cls_BRepTools_ReShape.def("Clear", (void (BRepTools_ReShape::*)()) &BRepTools_ReShape::Clear, "Clears all substitutions requests");
cls_BRepTools_ReShape.def("Remove", (void (BRepTools_ReShape::*)(const TopoDS_Shape &)) &BRepTools_ReShape::Remove, "Sets a request to Remove a Shape whatever the orientation", py::arg("shape"));
cls_BRepTools_ReShape.def("Replace", (void (BRepTools_ReShape::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &BRepTools_ReShape::Replace, "Sets a request to Replace a Shape by a new one.", py::arg("shape"), py::arg("newshape"));
cls_BRepTools_ReShape.def("IsRecorded", (Standard_Boolean (BRepTools_ReShape::*)(const TopoDS_Shape &) const) &BRepTools_ReShape::IsRecorded, "Tells if a shape is recorded for Replace/Remove", py::arg("shape"));
cls_BRepTools_ReShape.def("Value", (TopoDS_Shape (BRepTools_ReShape::*)(const TopoDS_Shape &) const) &BRepTools_ReShape::Value, "Returns the new value for an individual shape If not recorded, returns the original shape itself If to be Removed, returns a Null Shape Else, returns the replacing item", py::arg("shape"));
cls_BRepTools_ReShape.def("Status", [](BRepTools_ReShape &self, const TopoDS_Shape & a0, TopoDS_Shape & a1) -> Standard_Integer { return self.Status(a0, a1); });
cls_BRepTools_ReShape.def("Status", (Standard_Integer (BRepTools_ReShape::*)(const TopoDS_Shape &, TopoDS_Shape &, const Standard_Boolean)) &BRepTools_ReShape::Status, "Returns a complete substitution status for a shape 0 : not recorded, <newsh> = original <shape> < 0: to be removed, <newsh> is NULL > 0: to be replaced, <newsh> is a new item If <last> is False, returns status and new shape recorded in the map directly for the shape, if True and status > 0 then recursively searches for the last status and new shape.", py::arg("shape"), py::arg("newsh"), py::arg("last"));
cls_BRepTools_ReShape.def("Apply", [](BRepTools_ReShape &self, const TopoDS_Shape & a0) -> TopoDS_Shape { return self.Apply(a0); });
cls_BRepTools_ReShape.def("Apply", (TopoDS_Shape (BRepTools_ReShape::*)(const TopoDS_Shape &, const TopAbs_ShapeEnum)) &BRepTools_ReShape::Apply, "Applies the substitutions requests to a shape.", py::arg("shape"), py::arg("until"));
cls_BRepTools_ReShape.def("ModeConsiderLocation", (Standard_Boolean & (BRepTools_ReShape::*)()) &BRepTools_ReShape::ModeConsiderLocation, "Returns (modifiable) the flag which defines whether Location of shape take into account during replacing shapes.");
cls_BRepTools_ReShape.def("CopyVertex", [](BRepTools_ReShape &self, const TopoDS_Vertex & a0) -> TopoDS_Vertex { return self.CopyVertex(a0); });
cls_BRepTools_ReShape.def("CopyVertex", (TopoDS_Vertex (BRepTools_ReShape::*)(const TopoDS_Vertex &, const Standard_Real)) &BRepTools_ReShape::CopyVertex, "None", py::arg("theV"), py::arg("theTol"));
cls_BRepTools_ReShape.def("CopyVertex", (TopoDS_Vertex (BRepTools_ReShape::*)(const TopoDS_Vertex &, const gp_Pnt &, const Standard_Real)) &BRepTools_ReShape::CopyVertex, "None", py::arg("theV"), py::arg("theNewPos"), py::arg("aTol"));
cls_BRepTools_ReShape.def("IsNewShape", (Standard_Boolean (BRepTools_ReShape::*)(const TopoDS_Shape &) const) &BRepTools_ReShape::IsNewShape, "None", py::arg("theShape"));
cls_BRepTools_ReShape.def("History", (opencascade::handle<BRepTools_History> (BRepTools_ReShape::*)() const) &BRepTools_ReShape::History, "Returns the history of the substituted shapes.");
cls_BRepTools_ReShape.def_static("get_type_name_", (const char * (*)()) &BRepTools_ReShape::get_type_name, "None");
cls_BRepTools_ReShape.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepTools_ReShape::get_type_descriptor, "None");
cls_BRepTools_ReShape.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepTools_ReShape::*)() const) &BRepTools_ReShape::DynamicType, "None");

// Enums

}