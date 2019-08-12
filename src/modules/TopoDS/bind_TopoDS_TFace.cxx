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
#include <TopoDS_TFace.hxx>
#include <Standard_Type.hxx>

void bind_TopoDS_TFace(py::module &mod){

py::class_<TopoDS_TFace, opencascade::handle<TopoDS_TFace>, TopoDS_TShape> cls_TopoDS_TFace(mod, "TopoDS_TFace", "A topological part of a surface or of the 2D space. The boundary is a set of wires and vertices.");

// Constructors
cls_TopoDS_TFace.def(py::init<>());

// Fields

// Methods
cls_TopoDS_TFace.def("ShapeType", (TopAbs_ShapeEnum (TopoDS_TFace::*)() const) &TopoDS_TFace::ShapeType, "returns FACE.");
cls_TopoDS_TFace.def("EmptyCopy", (opencascade::handle<TopoDS_TShape> (TopoDS_TFace::*)() const) &TopoDS_TFace::EmptyCopy, "Returns an empty TFace.");
cls_TopoDS_TFace.def_static("get_type_name_", (const char * (*)()) &TopoDS_TFace::get_type_name, "None");
cls_TopoDS_TFace.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TopoDS_TFace::get_type_descriptor, "None");
cls_TopoDS_TFace.def("DynamicType", (const opencascade::handle<Standard_Type> & (TopoDS_TFace::*)() const) &TopoDS_TFace::DynamicType, "None");

// Enums

}