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
#include <TopoDS_Shape.hxx>
#include <ShapeExtend_Status.hxx>
#include <Standard_Handle.hxx>
#include <ShapeUpgrade_SplitSurface.hxx>
#include <ShapeUpgrade_WireDivide.hxx>
#include <ShapeUpgrade_FaceDivide.hxx>
#include <Standard_Type.hxx>

void bind_ShapeUpgrade_FaceDivide(py::module &mod){

py::class_<ShapeUpgrade_FaceDivide, opencascade::handle<ShapeUpgrade_FaceDivide>, ShapeUpgrade_Tool> cls_ShapeUpgrade_FaceDivide(mod, "ShapeUpgrade_FaceDivide", "Divides a Face (both edges in the wires, by splitting curves and pcurves, and the face itself, by splitting supporting surface) according to splitting criteria. * The domain of the face to divide is defined by the PCurves of the wires on the Face.");

// Constructors
cls_ShapeUpgrade_FaceDivide.def(py::init<>());
cls_ShapeUpgrade_FaceDivide.def(py::init<const TopoDS_Face &>(), py::arg("F"));

// Fields

// Methods
cls_ShapeUpgrade_FaceDivide.def("Init", (void (ShapeUpgrade_FaceDivide::*)(const TopoDS_Face &)) &ShapeUpgrade_FaceDivide::Init, "Initialize by a Face.", py::arg("F"));
cls_ShapeUpgrade_FaceDivide.def("SetSurfaceSegmentMode", (void (ShapeUpgrade_FaceDivide::*)(const Standard_Boolean)) &ShapeUpgrade_FaceDivide::SetSurfaceSegmentMode, "Purpose sets mode for trimming (segment) surface by wire UV bounds.", py::arg("Segment"));
cls_ShapeUpgrade_FaceDivide.def("Perform", (Standard_Boolean (ShapeUpgrade_FaceDivide::*)()) &ShapeUpgrade_FaceDivide::Perform, "Performs splitting and computes the resulting shell The context is used to keep track of former splittings in order to keep sharings. It is updated according to modifications made.");
cls_ShapeUpgrade_FaceDivide.def("SplitSurface", (Standard_Boolean (ShapeUpgrade_FaceDivide::*)()) &ShapeUpgrade_FaceDivide::SplitSurface, "Performs splitting of surface and computes the shell from source face.");
cls_ShapeUpgrade_FaceDivide.def("SplitCurves", (Standard_Boolean (ShapeUpgrade_FaceDivide::*)()) &ShapeUpgrade_FaceDivide::SplitCurves, "Performs splitting of curves of all the edges in the shape and divides these edges.");
cls_ShapeUpgrade_FaceDivide.def("Result", (TopoDS_Shape (ShapeUpgrade_FaceDivide::*)() const) &ShapeUpgrade_FaceDivide::Result, "Gives the resulting Shell, or Face, or Null shape if not done.");
cls_ShapeUpgrade_FaceDivide.def("Status", (Standard_Boolean (ShapeUpgrade_FaceDivide::*)(const ShapeExtend_Status) const) &ShapeUpgrade_FaceDivide::Status, "Queries the status of last call to Perform OK : no splitting was done (or no call to Perform) DONE1: some edges were splitted DONE2: surface was splitted DONE3: surface was modified without splitting FAIL1: some fails encountered during splitting wires FAIL2: face cannot be splitted", py::arg("status"));
cls_ShapeUpgrade_FaceDivide.def("SetSplitSurfaceTool", (void (ShapeUpgrade_FaceDivide::*)(const opencascade::handle<ShapeUpgrade_SplitSurface> &)) &ShapeUpgrade_FaceDivide::SetSplitSurfaceTool, "Sets the tool for splitting surfaces.", py::arg("splitSurfaceTool"));
cls_ShapeUpgrade_FaceDivide.def("SetWireDivideTool", (void (ShapeUpgrade_FaceDivide::*)(const opencascade::handle<ShapeUpgrade_WireDivide> &)) &ShapeUpgrade_FaceDivide::SetWireDivideTool, "Sets the tool for dividing edges on Face.", py::arg("wireDivideTool"));
cls_ShapeUpgrade_FaceDivide.def("GetSplitSurfaceTool", (opencascade::handle<ShapeUpgrade_SplitSurface> (ShapeUpgrade_FaceDivide::*)() const) &ShapeUpgrade_FaceDivide::GetSplitSurfaceTool, "Returns the tool for splitting surfaces. This tool must be already initialized.");
cls_ShapeUpgrade_FaceDivide.def("GetWireDivideTool", (opencascade::handle<ShapeUpgrade_WireDivide> (ShapeUpgrade_FaceDivide::*)() const) &ShapeUpgrade_FaceDivide::GetWireDivideTool, "Returns the tool for dividing edges on Face. This tool must be already initialized.");
cls_ShapeUpgrade_FaceDivide.def_static("get_type_name_", (const char * (*)()) &ShapeUpgrade_FaceDivide::get_type_name, "None");
cls_ShapeUpgrade_FaceDivide.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeUpgrade_FaceDivide::get_type_descriptor, "None");
cls_ShapeUpgrade_FaceDivide.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeUpgrade_FaceDivide::*)() const) &ShapeUpgrade_FaceDivide::DynamicType, "None");

// Enums

}