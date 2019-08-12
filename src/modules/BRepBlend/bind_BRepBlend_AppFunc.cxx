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
#include <BRepBlend_AppFuncRoot.hxx>
#include <Standard_Handle.hxx>
#include <BRepBlend_Line.hxx>
#include <Blend_Function.hxx>
#include <Standard_TypeDef.hxx>
#include <Blend_AppFunction.hxx>
#include <math_Vector.hxx>
#include <Blend_Point.hxx>
#include <BRepBlend_AppFunc.hxx>
#include <Standard_Type.hxx>

void bind_BRepBlend_AppFunc(py::module &mod){

py::class_<BRepBlend_AppFunc, opencascade::handle<BRepBlend_AppFunc>, BRepBlend_AppFuncRoot> cls_BRepBlend_AppFunc(mod, "BRepBlend_AppFunc", "Function to approximate by AppSurface for Surface/Surface contact.");

// Constructors
cls_BRepBlend_AppFunc.def(py::init<opencascade::handle<BRepBlend_Line> &, Blend_Function &, const Standard_Real, const Standard_Real>(), py::arg("Line"), py::arg("Func"), py::arg("Tol3d"), py::arg("Tol2d"));

// Fields

// Methods
cls_BRepBlend_AppFunc.def("Point", (void (BRepBlend_AppFunc::*)(const Blend_AppFunction &, const Standard_Real, const math_Vector &, Blend_Point &) const) &BRepBlend_AppFunc::Point, "None", py::arg("Func"), py::arg("Param"), py::arg("Sol"), py::arg("Pnt"));
cls_BRepBlend_AppFunc.def("Vec", (void (BRepBlend_AppFunc::*)(math_Vector &, const Blend_Point &) const) &BRepBlend_AppFunc::Vec, "None", py::arg("Sol"), py::arg("Pnt"));
cls_BRepBlend_AppFunc.def_static("get_type_name_", (const char * (*)()) &BRepBlend_AppFunc::get_type_name, "None");
cls_BRepBlend_AppFunc.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepBlend_AppFunc::get_type_descriptor, "None");
cls_BRepBlend_AppFunc.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepBlend_AppFunc::*)() const) &BRepBlend_AppFunc::DynamicType, "None");

// Enums

}