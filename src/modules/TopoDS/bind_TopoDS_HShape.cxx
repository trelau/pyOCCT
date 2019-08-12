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
#include <Standard_Handle.hxx>
#include <TopoDS_HShape.hxx>
#include <Standard_Type.hxx>

void bind_TopoDS_HShape(py::module &mod){

py::class_<TopoDS_HShape, opencascade::handle<TopoDS_HShape>, Standard_Transient> cls_TopoDS_HShape(mod, "TopoDS_HShape", "Class to manipulate a Shape with handle.");

// Constructors
cls_TopoDS_HShape.def(py::init<>());
cls_TopoDS_HShape.def(py::init<const TopoDS_Shape &>(), py::arg("aShape"));

// Fields

// Methods
cls_TopoDS_HShape.def("Shape", (void (TopoDS_HShape::*)(const TopoDS_Shape &)) &TopoDS_HShape::Shape, "Loads this shape with the shape aShape", py::arg("aShape"));
cls_TopoDS_HShape.def("Shape", (const TopoDS_Shape & (TopoDS_HShape::*)() const) &TopoDS_HShape::Shape, "Returns a reference to a constant TopoDS_Shape based on this shape.");
cls_TopoDS_HShape.def("ChangeShape", (TopoDS_Shape & (TopoDS_HShape::*)()) &TopoDS_HShape::ChangeShape, "Exchanges the TopoDS_Shape object defining this shape for another one referencing the same underlying shape Accesses the list of shapes within the underlying shape referenced by the TopoDS_Shape object. Returns a reference to a TopoDS_Shape based on this shape. The TopoDS_Shape can be modified.");
cls_TopoDS_HShape.def_static("get_type_name_", (const char * (*)()) &TopoDS_HShape::get_type_name, "None");
cls_TopoDS_HShape.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TopoDS_HShape::get_type_descriptor, "None");
cls_TopoDS_HShape.def("DynamicType", (const opencascade::handle<Standard_Type> & (TopoDS_HShape::*)() const) &TopoDS_HShape::DynamicType, "None");

// Enums

}