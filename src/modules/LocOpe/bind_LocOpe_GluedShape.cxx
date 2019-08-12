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
#include <LocOpe_GeneratedShape.hxx>
#include <TopoDS_Shape.hxx>
#include <TopoDS_Face.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Vertex.hxx>
#include <Standard_Handle.hxx>
#include <LocOpe_GluedShape.hxx>
#include <Standard_Type.hxx>
#include <TopTools_MapOfShape.hxx>
#include <TopTools_DataMapOfShapeShape.hxx>

void bind_LocOpe_GluedShape(py::module &mod){

py::class_<LocOpe_GluedShape, opencascade::handle<LocOpe_GluedShape>, LocOpe_GeneratedShape> cls_LocOpe_GluedShape(mod, "LocOpe_GluedShape", "None");

// Constructors
cls_LocOpe_GluedShape.def(py::init<>());
cls_LocOpe_GluedShape.def(py::init<const TopoDS_Shape &>(), py::arg("S"));

// Fields

// Methods
cls_LocOpe_GluedShape.def("Init", (void (LocOpe_GluedShape::*)(const TopoDS_Shape &)) &LocOpe_GluedShape::Init, "None", py::arg("S"));
cls_LocOpe_GluedShape.def("GlueOnFace", (void (LocOpe_GluedShape::*)(const TopoDS_Face &)) &LocOpe_GluedShape::GlueOnFace, "None", py::arg("F"));
cls_LocOpe_GluedShape.def("GeneratingEdges", (const TopTools_ListOfShape & (LocOpe_GluedShape::*)()) &LocOpe_GluedShape::GeneratingEdges, "None");
cls_LocOpe_GluedShape.def("Generated", (TopoDS_Edge (LocOpe_GluedShape::*)(const TopoDS_Vertex &)) &LocOpe_GluedShape::Generated, "Returns the edge created by the vertex <V>. If none, must return a null shape.", py::arg("V"));
cls_LocOpe_GluedShape.def("Generated", (TopoDS_Face (LocOpe_GluedShape::*)(const TopoDS_Edge &)) &LocOpe_GluedShape::Generated, "Returns the face created by the edge <E>. If none, must return a null shape.", py::arg("E"));
cls_LocOpe_GluedShape.def("OrientedFaces", (const TopTools_ListOfShape & (LocOpe_GluedShape::*)()) &LocOpe_GluedShape::OrientedFaces, "Returns the list of correctly oriented generated faces.");
cls_LocOpe_GluedShape.def_static("get_type_name_", (const char * (*)()) &LocOpe_GluedShape::get_type_name, "None");
cls_LocOpe_GluedShape.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &LocOpe_GluedShape::get_type_descriptor, "None");
cls_LocOpe_GluedShape.def("DynamicType", (const opencascade::handle<Standard_Type> & (LocOpe_GluedShape::*)() const) &LocOpe_GluedShape::DynamicType, "None");

// Enums

}