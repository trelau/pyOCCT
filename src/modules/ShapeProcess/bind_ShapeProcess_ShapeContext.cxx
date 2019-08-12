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
#include <ShapeProcess_Context.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Shape.hxx>
#include <TopTools_DataMapOfShapeShape.hxx>
#include <Standard_Handle.hxx>
#include <ShapeExtend_MsgRegistrator.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <ShapeBuild_ReShape.hxx>
#include <BRepTools_Modifier.hxx>
#include <Message_Msg.hxx>
#include <Message_Gravity.hxx>
#include <GeomAbs_Shape.hxx>
#include <ShapeProcess_ShapeContext.hxx>
#include <Standard_Type.hxx>

void bind_ShapeProcess_ShapeContext(py::module &mod){

py::class_<ShapeProcess_ShapeContext, opencascade::handle<ShapeProcess_ShapeContext>, ShapeProcess_Context> cls_ShapeProcess_ShapeContext(mod, "ShapeProcess_ShapeContext", "Extends Context to handle shapes Contains map of shape-shape, and messages attached to shapes");

// Constructors
cls_ShapeProcess_ShapeContext.def(py::init<const Standard_CString>(), py::arg("file"));
cls_ShapeProcess_ShapeContext.def(py::init<const Standard_CString, const Standard_CString>(), py::arg("file"), py::arg("seq"));
cls_ShapeProcess_ShapeContext.def(py::init<const TopoDS_Shape &, const Standard_CString>(), py::arg("S"), py::arg("file"));
cls_ShapeProcess_ShapeContext.def(py::init<const TopoDS_Shape &, const Standard_CString, const Standard_CString>(), py::arg("S"), py::arg("file"), py::arg("seq"));

// Fields

// Methods
cls_ShapeProcess_ShapeContext.def("Init", (void (ShapeProcess_ShapeContext::*)(const TopoDS_Shape &)) &ShapeProcess_ShapeContext::Init, "Initializes tool by a new shape and clears all results", py::arg("S"));
cls_ShapeProcess_ShapeContext.def("Shape", (const TopoDS_Shape & (ShapeProcess_ShapeContext::*)() const) &ShapeProcess_ShapeContext::Shape, "Returns shape being processed");
cls_ShapeProcess_ShapeContext.def("Result", (const TopoDS_Shape & (ShapeProcess_ShapeContext::*)() const) &ShapeProcess_ShapeContext::Result, "Returns current result");
cls_ShapeProcess_ShapeContext.def("Map", (const TopTools_DataMapOfShapeShape & (ShapeProcess_ShapeContext::*)() const) &ShapeProcess_ShapeContext::Map, "Returns map of replacements shape -> shape This map is not recursive");
cls_ShapeProcess_ShapeContext.def("Messages", (const opencascade::handle<ShapeExtend_MsgRegistrator> & (ShapeProcess_ShapeContext::*)() const) &ShapeProcess_ShapeContext::Messages, "None");
cls_ShapeProcess_ShapeContext.def("Messages", (opencascade::handle<ShapeExtend_MsgRegistrator> & (ShapeProcess_ShapeContext::*)()) &ShapeProcess_ShapeContext::Messages, "Returns messages recorded during shape processing It can be nullified before processing in order to avoid recording messages");
cls_ShapeProcess_ShapeContext.def("SetDetalisation", (void (ShapeProcess_ShapeContext::*)(const TopAbs_ShapeEnum)) &ShapeProcess_ShapeContext::SetDetalisation, "None", py::arg("level"));
cls_ShapeProcess_ShapeContext.def("GetDetalisation", (TopAbs_ShapeEnum (ShapeProcess_ShapeContext::*)() const) &ShapeProcess_ShapeContext::GetDetalisation, "Set and get value for detalisation level Only shapes of types from TopoDS_COMPOUND and until specified detalisation level will be recorded in maps To cancel mapping, use TopAbs_SHAPE To force full mapping, use TopAbs_VERTEX The default level is TopAbs_FACE");
cls_ShapeProcess_ShapeContext.def("SetResult", (void (ShapeProcess_ShapeContext::*)(const TopoDS_Shape &)) &ShapeProcess_ShapeContext::SetResult, "Sets a new result shape NOTE: this method should be used very carefully to keep consistency of modifications It is recommended to use RecordModification() methods with explicit definition of mapping from current result to a new one", py::arg("S"));
cls_ShapeProcess_ShapeContext.def("RecordModification", [](ShapeProcess_ShapeContext &self, const TopTools_DataMapOfShapeShape & a0) -> void { return self.RecordModification(a0); });
cls_ShapeProcess_ShapeContext.def("RecordModification", (void (ShapeProcess_ShapeContext::*)(const TopTools_DataMapOfShapeShape &, const opencascade::handle<ShapeExtend_MsgRegistrator> &)) &ShapeProcess_ShapeContext::RecordModification, "None", py::arg("repl"), py::arg("msg"));
cls_ShapeProcess_ShapeContext.def("RecordModification", (void (ShapeProcess_ShapeContext::*)(const opencascade::handle<ShapeBuild_ReShape> &, const opencascade::handle<ShapeExtend_MsgRegistrator> &)) &ShapeProcess_ShapeContext::RecordModification, "None", py::arg("repl"), py::arg("msg"));
cls_ShapeProcess_ShapeContext.def("RecordModification", (void (ShapeProcess_ShapeContext::*)(const opencascade::handle<ShapeBuild_ReShape> &)) &ShapeProcess_ShapeContext::RecordModification, "None", py::arg("repl"));
cls_ShapeProcess_ShapeContext.def("RecordModification", [](ShapeProcess_ShapeContext &self, const TopoDS_Shape & a0, const BRepTools_Modifier & a1) -> void { return self.RecordModification(a0, a1); });
cls_ShapeProcess_ShapeContext.def("RecordModification", (void (ShapeProcess_ShapeContext::*)(const TopoDS_Shape &, const BRepTools_Modifier &, const opencascade::handle<ShapeExtend_MsgRegistrator> &)) &ShapeProcess_ShapeContext::RecordModification, "Records modifications and resets result accordingly NOTE: modification of resulting shape should be explicitly defined in the maps along with modifications of subshapes", py::arg("sh"), py::arg("repl"), py::arg("msg"));
cls_ShapeProcess_ShapeContext.def("AddMessage", [](ShapeProcess_ShapeContext &self, const TopoDS_Shape & a0, const Message_Msg & a1) -> void { return self.AddMessage(a0, a1); });
cls_ShapeProcess_ShapeContext.def("AddMessage", (void (ShapeProcess_ShapeContext::*)(const TopoDS_Shape &, const Message_Msg &, const Message_Gravity)) &ShapeProcess_ShapeContext::AddMessage, "Record a message for shape S Shape S should be one of subshapes of original shape (or whole one), but not one of intermediate shapes Records only if Message() is not Null", py::arg("S"), py::arg("msg"), py::arg("gravity"));
cls_ShapeProcess_ShapeContext.def("GetContinuity", (Standard_Boolean (ShapeProcess_ShapeContext::*)(const Standard_CString, GeomAbs_Shape &) const) &ShapeProcess_ShapeContext::GetContinuity, "Get value of parameter as being of the type GeomAbs_Shape Returns False if parameter is not defined or has a wrong type", py::arg("param"), py::arg("val"));
cls_ShapeProcess_ShapeContext.def("ContinuityVal", (GeomAbs_Shape (ShapeProcess_ShapeContext::*)(const Standard_CString, const GeomAbs_Shape) const) &ShapeProcess_ShapeContext::ContinuityVal, "Get value of parameter as being of the type GeomAbs_Shape If parameter is not defined or does not have expected type, returns default value as specified", py::arg("param"), py::arg("def"));
cls_ShapeProcess_ShapeContext.def("PrintStatistics", (void (ShapeProcess_ShapeContext::*)() const) &ShapeProcess_ShapeContext::PrintStatistics, "Prints statistics on Shape Processing onto the current Messenger.");
cls_ShapeProcess_ShapeContext.def("SetNonManifold", (void (ShapeProcess_ShapeContext::*)(Standard_Boolean)) &ShapeProcess_ShapeContext::SetNonManifold, "Set NonManifold flag", py::arg("theNonManifold"));
cls_ShapeProcess_ShapeContext.def("IsNonManifold", (Standard_Boolean (ShapeProcess_ShapeContext::*)()) &ShapeProcess_ShapeContext::IsNonManifold, "Get NonManifold flag");
cls_ShapeProcess_ShapeContext.def_static("get_type_name_", (const char * (*)()) &ShapeProcess_ShapeContext::get_type_name, "None");
cls_ShapeProcess_ShapeContext.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeProcess_ShapeContext::get_type_descriptor, "None");
cls_ShapeProcess_ShapeContext.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeProcess_ShapeContext::*)() const) &ShapeProcess_ShapeContext::DynamicType, "None");

// Enums

}