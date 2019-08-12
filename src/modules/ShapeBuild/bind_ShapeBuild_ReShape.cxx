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
#include <BRepTools_ReShape.hxx>
#include <TopoDS_Shape.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <Standard_TypeDef.hxx>
#include <ShapeExtend_Status.hxx>
#include <Standard_Handle.hxx>
#include <ShapeBuild_ReShape.hxx>
#include <Standard_Type.hxx>

void bind_ShapeBuild_ReShape(py::module &mod){

py::class_<ShapeBuild_ReShape, opencascade::handle<ShapeBuild_ReShape>, BRepTools_ReShape> cls_ShapeBuild_ReShape(mod, "ShapeBuild_ReShape", "Rebuilds a Shape by making pre-defined substitutions on some of its components");

// Constructors
cls_ShapeBuild_ReShape.def(py::init<>());

// Fields

// Methods
cls_ShapeBuild_ReShape.def("Apply", (TopoDS_Shape (ShapeBuild_ReShape::*)(const TopoDS_Shape &, const TopAbs_ShapeEnum, const Standard_Integer)) &ShapeBuild_ReShape::Apply, "Applies the substitutions requests to a shape", py::arg("shape"), py::arg("until"), py::arg("buildmode"));
cls_ShapeBuild_ReShape.def("Apply", [](ShapeBuild_ReShape &self, const TopoDS_Shape & a0) -> TopoDS_Shape { return self.Apply(a0); });
cls_ShapeBuild_ReShape.def("Apply", (TopoDS_Shape (ShapeBuild_ReShape::*)(const TopoDS_Shape &, const TopAbs_ShapeEnum)) &ShapeBuild_ReShape::Apply, "Applies the substitutions requests to a shape.", py::arg("shape"), py::arg("until"));
cls_ShapeBuild_ReShape.def("Status", [](ShapeBuild_ReShape &self, const TopoDS_Shape & a0, TopoDS_Shape & a1) -> Standard_Integer { return self.Status(a0, a1); });
cls_ShapeBuild_ReShape.def("Status", (Standard_Integer (ShapeBuild_ReShape::*)(const TopoDS_Shape &, TopoDS_Shape &, const Standard_Boolean)) &ShapeBuild_ReShape::Status, "Returns a complete substitution status for a shape 0 : not recorded, <newsh> = original <shape> < 0: to be removed, <newsh> is NULL > 0: to be replaced, <newsh> is a new item If <last> is False, returns status and new shape recorded in the map directly for the shape, if True and status > 0 then recursively searches for the last status and new shape.", py::arg("shape"), py::arg("newsh"), py::arg("last"));
cls_ShapeBuild_ReShape.def("Status", (Standard_Boolean (ShapeBuild_ReShape::*)(const ShapeExtend_Status) const) &ShapeBuild_ReShape::Status, "Queries the status of last call to Apply(shape,enum) OK : no (sub)shapes replaced or removed DONE1: source (starting) shape replaced DONE2: source (starting) shape removed DONE3: some subshapes replaced DONE4: some subshapes removed FAIL1: some replacements not done because of bad type of subshape", py::arg("status"));
cls_ShapeBuild_ReShape.def_static("get_type_name_", (const char * (*)()) &ShapeBuild_ReShape::get_type_name, "None");
cls_ShapeBuild_ReShape.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeBuild_ReShape::get_type_descriptor, "None");
cls_ShapeBuild_ReShape.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeBuild_ReShape::*)() const) &ShapeBuild_ReShape::DynamicType, "None");

// Enums

}