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
#include <TopoDS_Wire.hxx>
#include <TopoDS_Face.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Surface.hxx>
#include <TopoDS_Edge.hxx>
#include <TopLoc_Location.hxx>
#include <Standard_TypeDef.hxx>
#include <ShapeExtend_Status.hxx>
#include <ShapeUpgrade_SplitCurve3d.hxx>
#include <ShapeUpgrade_SplitCurve2d.hxx>
#include <ShapeAnalysis_TransferParameters.hxx>
#include <ShapeUpgrade_EdgeDivide.hxx>
#include <ShapeUpgrade_FixSmallCurves.hxx>
#include <ShapeUpgrade_WireDivide.hxx>
#include <Standard_Type.hxx>

void bind_ShapeUpgrade_WireDivide(py::module &mod){

py::class_<ShapeUpgrade_WireDivide, opencascade::handle<ShapeUpgrade_WireDivide>, ShapeUpgrade_Tool> cls_ShapeUpgrade_WireDivide(mod, "ShapeUpgrade_WireDivide", "Divides edges in the wire lying on the face or free wires or free edges with a criterion. Splits 3D curve and pcurve(s) of the edge on the face. Other pcurves which may be associated with the edge are simply copied. If 3D curve is splitted then pcurve on the face is splitted as well, and wice-versa. Input shape is not modified. The modifications made are recorded in external context (ShapeBuild_ReShape). This tool is applied to all edges before splitting them in order to keep sharing.");

// Constructors
cls_ShapeUpgrade_WireDivide.def(py::init<>());

// Fields

// Methods
cls_ShapeUpgrade_WireDivide.def("Init", (void (ShapeUpgrade_WireDivide::*)(const TopoDS_Wire &, const TopoDS_Face &)) &ShapeUpgrade_WireDivide::Init, "Initializes by wire and face", py::arg("W"), py::arg("F"));
cls_ShapeUpgrade_WireDivide.def("Init", (void (ShapeUpgrade_WireDivide::*)(const TopoDS_Wire &, const opencascade::handle<Geom_Surface> &)) &ShapeUpgrade_WireDivide::Init, "Initializes by wire and surface", py::arg("W"), py::arg("S"));
cls_ShapeUpgrade_WireDivide.def("Load", (void (ShapeUpgrade_WireDivide::*)(const TopoDS_Wire &)) &ShapeUpgrade_WireDivide::Load, "Loads working wire", py::arg("W"));
cls_ShapeUpgrade_WireDivide.def("Load", (void (ShapeUpgrade_WireDivide::*)(const TopoDS_Edge &)) &ShapeUpgrade_WireDivide::Load, "Creates wire of one edge and calls Load for wire", py::arg("E"));
cls_ShapeUpgrade_WireDivide.def("SetFace", (void (ShapeUpgrade_WireDivide::*)(const TopoDS_Face &)) &ShapeUpgrade_WireDivide::SetFace, "Sets supporting surface by face", py::arg("F"));
cls_ShapeUpgrade_WireDivide.def("SetSurface", (void (ShapeUpgrade_WireDivide::*)(const opencascade::handle<Geom_Surface> &)) &ShapeUpgrade_WireDivide::SetSurface, "Sets supporting surface", py::arg("S"));
cls_ShapeUpgrade_WireDivide.def("SetSurface", (void (ShapeUpgrade_WireDivide::*)(const opencascade::handle<Geom_Surface> &, const TopLoc_Location &)) &ShapeUpgrade_WireDivide::SetSurface, "Sets supporting surface with location", py::arg("S"), py::arg("L"));
cls_ShapeUpgrade_WireDivide.def("Perform", (void (ShapeUpgrade_WireDivide::*)()) &ShapeUpgrade_WireDivide::Perform, "Computes the resulting wire by splitting all the edges according to splitting criteria. All the modifications made are recorded in context (ShapeBuild_ReShape). This tool is applied to all edges before splitting them in order to keep sharings. If no supporting face or surface is defined, only 3d splitting criteria are used.");
cls_ShapeUpgrade_WireDivide.def("Wire", (const TopoDS_Wire & (ShapeUpgrade_WireDivide::*)() const) &ShapeUpgrade_WireDivide::Wire, "Gives the resulting Wire (equal to initial one if not done or Null if not loaded)");
cls_ShapeUpgrade_WireDivide.def("Status", (Standard_Boolean (ShapeUpgrade_WireDivide::*)(const ShapeExtend_Status) const) &ShapeUpgrade_WireDivide::Status, "Queries status of last call to Perform() OK - no edges were splitted, wire left untouched DONE1 - some edges were splitted FAIL1 - some edges have no 3d curve (skipped) FAIL2 - some edges have no pcurve (skipped)", py::arg("status"));
cls_ShapeUpgrade_WireDivide.def("SetSplitCurve3dTool", (void (ShapeUpgrade_WireDivide::*)(const opencascade::handle<ShapeUpgrade_SplitCurve3d> &)) &ShapeUpgrade_WireDivide::SetSplitCurve3dTool, "Sets the tool for splitting 3D curves.", py::arg("splitCurve3dTool"));
cls_ShapeUpgrade_WireDivide.def("SetSplitCurve2dTool", (void (ShapeUpgrade_WireDivide::*)(const opencascade::handle<ShapeUpgrade_SplitCurve2d> &)) &ShapeUpgrade_WireDivide::SetSplitCurve2dTool, "Sets the tool for splitting pcurves.", py::arg("splitCurve2dTool"));
cls_ShapeUpgrade_WireDivide.def("SetTransferParamTool", (void (ShapeUpgrade_WireDivide::*)(const opencascade::handle<ShapeAnalysis_TransferParameters> &)) &ShapeUpgrade_WireDivide::SetTransferParamTool, "Sets the tool for Transfer parameters between curves and pcurves.", py::arg("TransferParam"));
cls_ShapeUpgrade_WireDivide.def("SetEdgeDivideTool", (void (ShapeUpgrade_WireDivide::*)(const opencascade::handle<ShapeUpgrade_EdgeDivide> &)) &ShapeUpgrade_WireDivide::SetEdgeDivideTool, "Sets tool for splitting edge", py::arg("edgeDivideTool"));
cls_ShapeUpgrade_WireDivide.def("GetEdgeDivideTool", (opencascade::handle<ShapeUpgrade_EdgeDivide> (ShapeUpgrade_WireDivide::*)() const) &ShapeUpgrade_WireDivide::GetEdgeDivideTool, "returns tool for splitting edges");
cls_ShapeUpgrade_WireDivide.def("GetTransferParamTool", (opencascade::handle<ShapeAnalysis_TransferParameters> (ShapeUpgrade_WireDivide::*)()) &ShapeUpgrade_WireDivide::GetTransferParamTool, "Returns the tool for Transfer of parameters.");
cls_ShapeUpgrade_WireDivide.def("SetEdgeMode", (void (ShapeUpgrade_WireDivide::*)(const Standard_Integer)) &ShapeUpgrade_WireDivide::SetEdgeMode, "Sets mode for splitting 3d curves from edges. 0 - only curve 3d from free edges. 1 - only curve 3d from shared edges. 2 - all curve 3d.", py::arg("EdgeMode"));
cls_ShapeUpgrade_WireDivide.def("SetFixSmallCurveTool", (void (ShapeUpgrade_WireDivide::*)(const opencascade::handle<ShapeUpgrade_FixSmallCurves> &)) &ShapeUpgrade_WireDivide::SetFixSmallCurveTool, "Sets tool for fixing small curves with specified min tolerance;", py::arg("FixSmallCurvesTool"));
cls_ShapeUpgrade_WireDivide.def("GetFixSmallCurveTool", (opencascade::handle<ShapeUpgrade_FixSmallCurves> (ShapeUpgrade_WireDivide::*)() const) &ShapeUpgrade_WireDivide::GetFixSmallCurveTool, "Returns tool for fixing small curves");
cls_ShapeUpgrade_WireDivide.def_static("get_type_name_", (const char * (*)()) &ShapeUpgrade_WireDivide::get_type_name, "None");
cls_ShapeUpgrade_WireDivide.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeUpgrade_WireDivide::get_type_descriptor, "None");
cls_ShapeUpgrade_WireDivide.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeUpgrade_WireDivide::*)() const) &ShapeUpgrade_WireDivide::DynamicType, "None");

// Enums

}