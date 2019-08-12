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
#include <TopoDS_TSolid.hxx>
#include <Standard_Type.hxx>

void bind_TopoDS_TSolid(py::module &mod){

py::class_<TopoDS_TSolid, opencascade::handle<TopoDS_TSolid>, TopoDS_TShape> cls_TopoDS_TSolid(mod, "TopoDS_TSolid", "A Topological part of 3D space, bounded by shells, edges and vertices.");

// Constructors
cls_TopoDS_TSolid.def(py::init<>());

// Fields

// Methods
cls_TopoDS_TSolid.def("ShapeType", (TopAbs_ShapeEnum (TopoDS_TSolid::*)() const) &TopoDS_TSolid::ShapeType, "returns SOLID.");
cls_TopoDS_TSolid.def("EmptyCopy", (opencascade::handle<TopoDS_TShape> (TopoDS_TSolid::*)() const) &TopoDS_TSolid::EmptyCopy, "Returns an empty TSolid.");
cls_TopoDS_TSolid.def_static("get_type_name_", (const char * (*)()) &TopoDS_TSolid::get_type_name, "None");
cls_TopoDS_TSolid.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TopoDS_TSolid::get_type_descriptor, "None");
cls_TopoDS_TSolid.def("DynamicType", (const opencascade::handle<Standard_Type> & (TopoDS_TSolid::*)() const) &TopoDS_TSolid::DynamicType, "None");

// Enums

}