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
#include <Blend_RstRstFunction.hxx>
#include <Standard_TypeDef.hxx>
#include <Blend_AppFunction.hxx>
#include <math_Vector.hxx>
#include <Blend_Point.hxx>
#include <BRepBlend_AppFuncRstRst.hxx>
#include <Standard_Type.hxx>

void bind_BRepBlend_AppFuncRstRst(py::module &mod){

py::class_<BRepBlend_AppFuncRstRst, opencascade::handle<BRepBlend_AppFuncRstRst>, BRepBlend_AppFuncRoot> cls_BRepBlend_AppFuncRstRst(mod, "BRepBlend_AppFuncRstRst", "Function to approximate by AppSurface for Edge/Face (Curve/Curve contact).");

// Constructors
cls_BRepBlend_AppFuncRstRst.def(py::init<opencascade::handle<BRepBlend_Line> &, Blend_RstRstFunction &, const Standard_Real, const Standard_Real>(), py::arg("Line"), py::arg("Func"), py::arg("Tol3d"), py::arg("Tol2d"));

// Fields

// Methods
cls_BRepBlend_AppFuncRstRst.def("Point", (void (BRepBlend_AppFuncRstRst::*)(const Blend_AppFunction &, const Standard_Real, const math_Vector &, Blend_Point &) const) &BRepBlend_AppFuncRstRst::Point, "None", py::arg("Func"), py::arg("Param"), py::arg("Sol"), py::arg("Pnt"));
cls_BRepBlend_AppFuncRstRst.def("Vec", (void (BRepBlend_AppFuncRstRst::*)(math_Vector &, const Blend_Point &) const) &BRepBlend_AppFuncRstRst::Vec, "None", py::arg("Sol"), py::arg("Pnt"));
cls_BRepBlend_AppFuncRstRst.def_static("get_type_name_", (const char * (*)()) &BRepBlend_AppFuncRstRst::get_type_name, "None");
cls_BRepBlend_AppFuncRstRst.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepBlend_AppFuncRstRst::get_type_descriptor, "None");
cls_BRepBlend_AppFuncRstRst.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepBlend_AppFuncRstRst::*)() const) &BRepBlend_AppFuncRstRst::DynamicType, "None");

// Enums

}