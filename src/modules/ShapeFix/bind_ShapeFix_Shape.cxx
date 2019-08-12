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
#include <ShapeFix_Root.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Message_ProgressIndicator.hxx>
#include <ShapeFix_Solid.hxx>
#include <ShapeFix_Shell.hxx>
#include <ShapeFix_Face.hxx>
#include <ShapeFix_Wire.hxx>
#include <ShapeFix_Edge.hxx>
#include <ShapeExtend_Status.hxx>
#include <ShapeExtend_BasicMsgRegistrator.hxx>
#include <ShapeFix_Shape.hxx>
#include <Standard_Type.hxx>
#include <TopTools_MapOfShape.hxx>

void bind_ShapeFix_Shape(py::module &mod){

py::class_<ShapeFix_Shape, opencascade::handle<ShapeFix_Shape>, ShapeFix_Root> cls_ShapeFix_Shape(mod, "ShapeFix_Shape", "Fixing shape in general");

// Constructors
cls_ShapeFix_Shape.def(py::init<>());
cls_ShapeFix_Shape.def(py::init<const TopoDS_Shape &>(), py::arg("shape"));

// Fields

// Methods
cls_ShapeFix_Shape.def("Init", (void (ShapeFix_Shape::*)(const TopoDS_Shape &)) &ShapeFix_Shape::Init, "Initislises by shape.", py::arg("shape"));
cls_ShapeFix_Shape.def("Perform", [](ShapeFix_Shape &self) -> Standard_Boolean { return self.Perform(); });
cls_ShapeFix_Shape.def("Perform", (Standard_Boolean (ShapeFix_Shape::*)(const opencascade::handle<Message_ProgressIndicator> &)) &ShapeFix_Shape::Perform, "Iterates on sub- shape and performs fixes", py::arg("theProgress"));
cls_ShapeFix_Shape.def("Shape", (TopoDS_Shape (ShapeFix_Shape::*)() const) &ShapeFix_Shape::Shape, "Returns resulting shape");
cls_ShapeFix_Shape.def("FixSolidTool", (opencascade::handle<ShapeFix_Solid> (ShapeFix_Shape::*)() const) &ShapeFix_Shape::FixSolidTool, "Returns tool for fixing solids.");
cls_ShapeFix_Shape.def("FixShellTool", (opencascade::handle<ShapeFix_Shell> (ShapeFix_Shape::*)() const) &ShapeFix_Shape::FixShellTool, "Returns tool for fixing shells.");
cls_ShapeFix_Shape.def("FixFaceTool", (opencascade::handle<ShapeFix_Face> (ShapeFix_Shape::*)() const) &ShapeFix_Shape::FixFaceTool, "Returns tool for fixing faces.");
cls_ShapeFix_Shape.def("FixWireTool", (opencascade::handle<ShapeFix_Wire> (ShapeFix_Shape::*)() const) &ShapeFix_Shape::FixWireTool, "Returns tool for fixing wires.");
cls_ShapeFix_Shape.def("FixEdgeTool", (opencascade::handle<ShapeFix_Edge> (ShapeFix_Shape::*)() const) &ShapeFix_Shape::FixEdgeTool, "Returns tool for fixing edges.");
cls_ShapeFix_Shape.def("Status", (Standard_Boolean (ShapeFix_Shape::*)(const ShapeExtend_Status) const) &ShapeFix_Shape::Status, "Returns the status of the last Fix. This can be a combination of the following flags: ShapeExtend_DONE1: some free edges were fixed ShapeExtend_DONE2: some free wires were fixed ShapeExtend_DONE3: some free faces were fixed ShapeExtend_DONE4: some free shells were fixed ShapeExtend_DONE5: some free solids were fixed ShapeExtend_DONE6: shapes in compound(s) were fixed", py::arg("status"));
cls_ShapeFix_Shape.def("SetMsgRegistrator", (void (ShapeFix_Shape::*)(const opencascade::handle<ShapeExtend_BasicMsgRegistrator> &)) &ShapeFix_Shape::SetMsgRegistrator, "Sets message registrator", py::arg("msgreg"));
cls_ShapeFix_Shape.def("SetPrecision", (void (ShapeFix_Shape::*)(const Standard_Real)) &ShapeFix_Shape::SetPrecision, "Sets basic precision value (also to FixSolidTool)", py::arg("preci"));
cls_ShapeFix_Shape.def("SetMinTolerance", (void (ShapeFix_Shape::*)(const Standard_Real)) &ShapeFix_Shape::SetMinTolerance, "Sets minimal allowed tolerance (also to FixSolidTool)", py::arg("mintol"));
cls_ShapeFix_Shape.def("SetMaxTolerance", (void (ShapeFix_Shape::*)(const Standard_Real)) &ShapeFix_Shape::SetMaxTolerance, "Sets maximal allowed tolerance (also to FixSolidTool)", py::arg("maxtol"));
cls_ShapeFix_Shape.def("FixSolidMode", (Standard_Integer & (ShapeFix_Shape::*)()) &ShapeFix_Shape::FixSolidMode, "Returns (modifiable) the mode for applying fixes of ShapeFix_Solid, by default True.");
cls_ShapeFix_Shape.def("FixFreeShellMode", (Standard_Integer & (ShapeFix_Shape::*)()) &ShapeFix_Shape::FixFreeShellMode, "Returns (modifiable) the mode for applying fixes of ShapeFix_Shell, by default True.");
cls_ShapeFix_Shape.def("FixFreeFaceMode", (Standard_Integer & (ShapeFix_Shape::*)()) &ShapeFix_Shape::FixFreeFaceMode, "Returns (modifiable) the mode for applying fixes of ShapeFix_Face, by default True.");
cls_ShapeFix_Shape.def("FixFreeWireMode", (Standard_Integer & (ShapeFix_Shape::*)()) &ShapeFix_Shape::FixFreeWireMode, "Returns (modifiable) the mode for applying fixes of ShapeFix_Wire, by default True.");
cls_ShapeFix_Shape.def("FixSameParameterMode", (Standard_Integer & (ShapeFix_Shape::*)()) &ShapeFix_Shape::FixSameParameterMode, "Returns (modifiable) the mode for applying ShapeFix::SameParameter after all fixes, by default True.");
cls_ShapeFix_Shape.def("FixVertexPositionMode", (Standard_Integer & (ShapeFix_Shape::*)()) &ShapeFix_Shape::FixVertexPositionMode, "Returns (modifiable) the mode for applying ShapeFix::FixVertexPosition before all fixes, by default False.");
cls_ShapeFix_Shape.def("FixVertexTolMode", (Standard_Integer & (ShapeFix_Shape::*)()) &ShapeFix_Shape::FixVertexTolMode, "Returns (modifiable) the mode for fixing tolerances of vertices on whole shape after performing all fixes");
cls_ShapeFix_Shape.def_static("get_type_name_", (const char * (*)()) &ShapeFix_Shape::get_type_name, "None");
cls_ShapeFix_Shape.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeFix_Shape::get_type_descriptor, "None");
cls_ShapeFix_Shape.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeFix_Shape::*)() const) &ShapeFix_Shape::DynamicType, "None");

// Enums

}