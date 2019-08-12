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
#include <TopoDS_Face.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Edge.hxx>
#include <Standard_Handle.hxx>
#include <TColStd_HSequenceOfReal.hxx>
#include <ShapeUpgrade_SplitCurve2d.hxx>
#include <ShapeUpgrade_SplitCurve3d.hxx>
#include <ShapeUpgrade_EdgeDivide.hxx>
#include <Standard_Type.hxx>

void bind_ShapeUpgrade_EdgeDivide(py::module &mod){

py::class_<ShapeUpgrade_EdgeDivide, opencascade::handle<ShapeUpgrade_EdgeDivide>, ShapeUpgrade_Tool> cls_ShapeUpgrade_EdgeDivide(mod, "ShapeUpgrade_EdgeDivide", "None");

// Constructors
cls_ShapeUpgrade_EdgeDivide.def(py::init<>());

// Fields

// Methods
cls_ShapeUpgrade_EdgeDivide.def("Clear", (void (ShapeUpgrade_EdgeDivide::*)()) &ShapeUpgrade_EdgeDivide::Clear, "None");
cls_ShapeUpgrade_EdgeDivide.def("SetFace", (void (ShapeUpgrade_EdgeDivide::*)(const TopoDS_Face &)) &ShapeUpgrade_EdgeDivide::SetFace, "Sets supporting surface by face", py::arg("F"));
cls_ShapeUpgrade_EdgeDivide.def("Compute", (Standard_Boolean (ShapeUpgrade_EdgeDivide::*)(const TopoDS_Edge &)) &ShapeUpgrade_EdgeDivide::Compute, "None", py::arg("E"));
cls_ShapeUpgrade_EdgeDivide.def("HasCurve2d", (Standard_Boolean (ShapeUpgrade_EdgeDivide::*)() const) &ShapeUpgrade_EdgeDivide::HasCurve2d, "None");
cls_ShapeUpgrade_EdgeDivide.def("HasCurve3d", (Standard_Boolean (ShapeUpgrade_EdgeDivide::*)() const) &ShapeUpgrade_EdgeDivide::HasCurve3d, "None");
cls_ShapeUpgrade_EdgeDivide.def("Knots2d", (opencascade::handle<TColStd_HSequenceOfReal> (ShapeUpgrade_EdgeDivide::*)() const) &ShapeUpgrade_EdgeDivide::Knots2d, "None");
cls_ShapeUpgrade_EdgeDivide.def("Knots3d", (opencascade::handle<TColStd_HSequenceOfReal> (ShapeUpgrade_EdgeDivide::*)() const) &ShapeUpgrade_EdgeDivide::Knots3d, "None");
cls_ShapeUpgrade_EdgeDivide.def("SetSplitCurve2dTool", (void (ShapeUpgrade_EdgeDivide::*)(const opencascade::handle<ShapeUpgrade_SplitCurve2d> &)) &ShapeUpgrade_EdgeDivide::SetSplitCurve2dTool, "Sets the tool for splitting pcurves.", py::arg("splitCurve2dTool"));
cls_ShapeUpgrade_EdgeDivide.def("SetSplitCurve3dTool", (void (ShapeUpgrade_EdgeDivide::*)(const opencascade::handle<ShapeUpgrade_SplitCurve3d> &)) &ShapeUpgrade_EdgeDivide::SetSplitCurve3dTool, "Sets the tool for splitting 3D curves.", py::arg("splitCurve3dTool"));
cls_ShapeUpgrade_EdgeDivide.def("GetSplitCurve2dTool", (opencascade::handle<ShapeUpgrade_SplitCurve2d> (ShapeUpgrade_EdgeDivide::*)() const) &ShapeUpgrade_EdgeDivide::GetSplitCurve2dTool, "Returns the tool for splitting pcurves.");
cls_ShapeUpgrade_EdgeDivide.def("GetSplitCurve3dTool", (opencascade::handle<ShapeUpgrade_SplitCurve3d> (ShapeUpgrade_EdgeDivide::*)() const) &ShapeUpgrade_EdgeDivide::GetSplitCurve3dTool, "Returns the tool for splitting 3D curves.");
cls_ShapeUpgrade_EdgeDivide.def_static("get_type_name_", (const char * (*)()) &ShapeUpgrade_EdgeDivide::get_type_name, "None");
cls_ShapeUpgrade_EdgeDivide.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeUpgrade_EdgeDivide::get_type_descriptor, "None");
cls_ShapeUpgrade_EdgeDivide.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeUpgrade_EdgeDivide::*)() const) &ShapeUpgrade_EdgeDivide::DynamicType, "None");

// Enums

}