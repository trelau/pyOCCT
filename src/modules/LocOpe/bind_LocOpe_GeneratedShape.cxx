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
#include <TopTools_ListOfShape.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Vertex.hxx>
#include <TopoDS_Face.hxx>
#include <Standard_Handle.hxx>
#include <LocOpe_GeneratedShape.hxx>
#include <Standard_Type.hxx>

void bind_LocOpe_GeneratedShape(py::module &mod){

py::class_<LocOpe_GeneratedShape, opencascade::handle<LocOpe_GeneratedShape>, Standard_Transient> cls_LocOpe_GeneratedShape(mod, "LocOpe_GeneratedShape", "None");

// Fields

// Methods
cls_LocOpe_GeneratedShape.def("GeneratingEdges", (const TopTools_ListOfShape & (LocOpe_GeneratedShape::*)()) &LocOpe_GeneratedShape::GeneratingEdges, "None");
cls_LocOpe_GeneratedShape.def("Generated", (TopoDS_Edge (LocOpe_GeneratedShape::*)(const TopoDS_Vertex &)) &LocOpe_GeneratedShape::Generated, "Returns the edge created by the vertex <V>. If none, must return a null shape.", py::arg("V"));
cls_LocOpe_GeneratedShape.def("Generated", (TopoDS_Face (LocOpe_GeneratedShape::*)(const TopoDS_Edge &)) &LocOpe_GeneratedShape::Generated, "Returns the face created by the edge <E>. If none, must return a null shape.", py::arg("E"));
cls_LocOpe_GeneratedShape.def("OrientedFaces", (const TopTools_ListOfShape & (LocOpe_GeneratedShape::*)()) &LocOpe_GeneratedShape::OrientedFaces, "Returns the list of correctly oriented generated faces.");
cls_LocOpe_GeneratedShape.def_static("get_type_name_", (const char * (*)()) &LocOpe_GeneratedShape::get_type_name, "None");
cls_LocOpe_GeneratedShape.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &LocOpe_GeneratedShape::get_type_descriptor, "None");
cls_LocOpe_GeneratedShape.def("DynamicType", (const opencascade::handle<Standard_Type> & (LocOpe_GeneratedShape::*)() const) &LocOpe_GeneratedShape::DynamicType, "None");

// Enums

}