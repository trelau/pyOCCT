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
#include <Message_Alert.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <TopoDS_AlertWithShape.hxx>
#include <Standard_Type.hxx>

void bind_TopoDS_AlertWithShape(py::module &mod){

py::class_<TopoDS_AlertWithShape, opencascade::handle<TopoDS_AlertWithShape>, Message_Alert> cls_TopoDS_AlertWithShape(mod, "TopoDS_AlertWithShape", "Alert object storing TopoDS shape in its field");

// Constructors
cls_TopoDS_AlertWithShape.def(py::init<const TopoDS_Shape &>(), py::arg("theShape"));

// Fields

// Methods
cls_TopoDS_AlertWithShape.def("GetShape", (const TopoDS_Shape & (TopoDS_AlertWithShape::*)() const) &TopoDS_AlertWithShape::GetShape, "Returns contained shape");
cls_TopoDS_AlertWithShape.def("SupportsMerge", (Standard_Boolean (TopoDS_AlertWithShape::*)() const) &TopoDS_AlertWithShape::SupportsMerge, "Returns false.");
cls_TopoDS_AlertWithShape.def("Merge", (Standard_Boolean (TopoDS_AlertWithShape::*)(const opencascade::handle<Message_Alert> &)) &TopoDS_AlertWithShape::Merge, "Returns false.", py::arg("theTarget"));
cls_TopoDS_AlertWithShape.def_static("get_type_name_", (const char * (*)()) &TopoDS_AlertWithShape::get_type_name, "None");
cls_TopoDS_AlertWithShape.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TopoDS_AlertWithShape::get_type_descriptor, "None");
cls_TopoDS_AlertWithShape.def("DynamicType", (const opencascade::handle<Standard_Type> & (TopoDS_AlertWithShape::*)() const) &TopoDS_AlertWithShape::DynamicType, "None");

// Enums

}