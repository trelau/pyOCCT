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
#include <ShapeUpgrade_Tool.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Face.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Curve.hxx>
#include <Geom2d_Curve.hxx>
#include <ShapeUpgrade_SplitCurve3d.hxx>
#include <ShapeUpgrade_SplitCurve2d.hxx>
#include <ShapeExtend_Status.hxx>
#include <ShapeUpgrade_FixSmallCurves.hxx>
#include <Standard_Type.hxx>

void bind_ShapeUpgrade_FixSmallCurves(py::module &mod){

py::class_<ShapeUpgrade_FixSmallCurves, opencascade::handle<ShapeUpgrade_FixSmallCurves>, ShapeUpgrade_Tool> cls_ShapeUpgrade_FixSmallCurves(mod, "ShapeUpgrade_FixSmallCurves", "None");

// Constructors
cls_ShapeUpgrade_FixSmallCurves.def(py::init<>());

// Fields

// Methods
cls_ShapeUpgrade_FixSmallCurves.def("Init", (void (ShapeUpgrade_FixSmallCurves::*)(const TopoDS_Edge &, const TopoDS_Face &)) &ShapeUpgrade_FixSmallCurves::Init, "None", py::arg("theEdge"), py::arg("theFace"));
cls_ShapeUpgrade_FixSmallCurves.def("Approx", [](ShapeUpgrade_FixSmallCurves &self, opencascade::handle<Geom_Curve> & Curve3d, opencascade::handle<Geom2d_Curve> & Curve2d, opencascade::handle<Geom2d_Curve> & Curve2dR, Standard_Real & First, Standard_Real & Last){ Standard_Boolean rv = self.Approx(Curve3d, Curve2d, Curve2dR, First, Last); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, First, Last); }, "None", py::arg("Curve3d"), py::arg("Curve2d"), py::arg("Curve2dR"), py::arg("First"), py::arg("Last"));
cls_ShapeUpgrade_FixSmallCurves.def("SetSplitCurve3dTool", (void (ShapeUpgrade_FixSmallCurves::*)(const opencascade::handle<ShapeUpgrade_SplitCurve3d> &)) &ShapeUpgrade_FixSmallCurves::SetSplitCurve3dTool, "Sets the tool for splitting 3D curves.", py::arg("splitCurve3dTool"));
cls_ShapeUpgrade_FixSmallCurves.def("SetSplitCurve2dTool", (void (ShapeUpgrade_FixSmallCurves::*)(const opencascade::handle<ShapeUpgrade_SplitCurve2d> &)) &ShapeUpgrade_FixSmallCurves::SetSplitCurve2dTool, "Sets the tool for splitting pcurves.", py::arg("splitCurve2dTool"));
cls_ShapeUpgrade_FixSmallCurves.def("Status", (Standard_Boolean (ShapeUpgrade_FixSmallCurves::*)(const ShapeExtend_Status) const) &ShapeUpgrade_FixSmallCurves::Status, "Queries the status of last call to Perform OK : DONE1: DONE2: FAIL1:", py::arg("status"));
cls_ShapeUpgrade_FixSmallCurves.def_static("get_type_name_", (const char * (*)()) &ShapeUpgrade_FixSmallCurves::get_type_name, "None");
cls_ShapeUpgrade_FixSmallCurves.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeUpgrade_FixSmallCurves::get_type_descriptor, "None");
cls_ShapeUpgrade_FixSmallCurves.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeUpgrade_FixSmallCurves::*)() const) &ShapeUpgrade_FixSmallCurves::DynamicType, "None");

// Enums

}