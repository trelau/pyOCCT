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
#include <TopoDS_TShape.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <Standard_Handle.hxx>
#include <TopoDS_TEdge.hxx>
#include <Standard_Type.hxx>

void bind_TopoDS_TEdge(py::module &mod){

py::class_<TopoDS_TEdge, opencascade::handle<TopoDS_TEdge>, TopoDS_TShape> cls_TopoDS_TEdge(mod, "TopoDS_TEdge", "A topological part of a curve in 2D or 3D, the boundary is a set of oriented Vertices.");

// Fields

// Methods
cls_TopoDS_TEdge.def("ShapeType", (TopAbs_ShapeEnum (TopoDS_TEdge::*)() const) &TopoDS_TEdge::ShapeType, "Returns EDGE.");
cls_TopoDS_TEdge.def_static("get_type_name_", (const char * (*)()) &TopoDS_TEdge::get_type_name, "None");
cls_TopoDS_TEdge.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TopoDS_TEdge::get_type_descriptor, "None");
cls_TopoDS_TEdge.def("DynamicType", (const opencascade::handle<Standard_Type> & (TopoDS_TEdge::*)() const) &TopoDS_TEdge::DynamicType, "None");

// Enums

}