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
#include <Standard.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <ShapeBuild_ReShape.hxx>
#include <ShapeExtend_BasicMsgRegistrator.hxx>
#include <Message_Msg.hxx>
#include <Message_Gravity.hxx>
#include <ShapeExtend_Status.hxx>
#include <ShapeUpgrade_FaceDivide.hxx>
#include <ShapeUpgrade_ShapeDivide.hxx>

void bind_ShapeUpgrade_ShapeDivide(py::module &mod){

py::class_<ShapeUpgrade_ShapeDivide, std::unique_ptr<ShapeUpgrade_ShapeDivide>> cls_ShapeUpgrade_ShapeDivide(mod, "ShapeUpgrade_ShapeDivide", "Divides a all faces in shell with given criteria Shell.");

// Constructors
cls_ShapeUpgrade_ShapeDivide.def(py::init<>());
cls_ShapeUpgrade_ShapeDivide.def(py::init<const TopoDS_Shape &>(), py::arg("S"));

// Fields

// Methods
// cls_ShapeUpgrade_ShapeDivide.def_static("operator new_", (void * (*)(size_t)) &ShapeUpgrade_ShapeDivide::operator new, "None", py::arg("theSize"));
// cls_ShapeUpgrade_ShapeDivide.def_static("operator delete_", (void (*)(void *)) &ShapeUpgrade_ShapeDivide::operator delete, "None", py::arg("theAddress"));
// cls_ShapeUpgrade_ShapeDivide.def_static("operator new[]_", (void * (*)(size_t)) &ShapeUpgrade_ShapeDivide::operator new[], "None", py::arg("theSize"));
// cls_ShapeUpgrade_ShapeDivide.def_static("operator delete[]_", (void (*)(void *)) &ShapeUpgrade_ShapeDivide::operator delete[], "None", py::arg("theAddress"));
// cls_ShapeUpgrade_ShapeDivide.def_static("operator new_", (void * (*)(size_t, void *)) &ShapeUpgrade_ShapeDivide::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_ShapeUpgrade_ShapeDivide.def_static("operator delete_", (void (*)(void *, void *)) &ShapeUpgrade_ShapeDivide::operator delete, "None", py::arg(""), py::arg(""));
cls_ShapeUpgrade_ShapeDivide.def("Init", (void (ShapeUpgrade_ShapeDivide::*)(const TopoDS_Shape &)) &ShapeUpgrade_ShapeDivide::Init, "Initialize by a Shape.", py::arg("S"));
cls_ShapeUpgrade_ShapeDivide.def("SetPrecision", (void (ShapeUpgrade_ShapeDivide::*)(const Standard_Real)) &ShapeUpgrade_ShapeDivide::SetPrecision, "Defines the spatial precision used for splitting", py::arg("Prec"));
cls_ShapeUpgrade_ShapeDivide.def("SetMaxTolerance", (void (ShapeUpgrade_ShapeDivide::*)(const Standard_Real)) &ShapeUpgrade_ShapeDivide::SetMaxTolerance, "Sets maximal allowed tolerance", py::arg("maxtol"));
cls_ShapeUpgrade_ShapeDivide.def("SetMinTolerance", (void (ShapeUpgrade_ShapeDivide::*)(const Standard_Real)) &ShapeUpgrade_ShapeDivide::SetMinTolerance, "Sets minimal allowed tolerance", py::arg("mintol"));
cls_ShapeUpgrade_ShapeDivide.def("SetSurfaceSegmentMode", (void (ShapeUpgrade_ShapeDivide::*)(const Standard_Boolean)) &ShapeUpgrade_ShapeDivide::SetSurfaceSegmentMode, "Purpose sets mode for trimming (segment) surface by wire UV bounds.", py::arg("Segment"));
cls_ShapeUpgrade_ShapeDivide.def("Perform", [](ShapeUpgrade_ShapeDivide &self) -> Standard_Boolean { return self.Perform(); });
cls_ShapeUpgrade_ShapeDivide.def("Perform", (Standard_Boolean (ShapeUpgrade_ShapeDivide::*)(const Standard_Boolean)) &ShapeUpgrade_ShapeDivide::Perform, "Performs splitting and computes the resulting shape If newContext is True (default), the internal context will be cleared at start, else previous substitutions will be acting.", py::arg("newContext"));
cls_ShapeUpgrade_ShapeDivide.def("Result", (TopoDS_Shape (ShapeUpgrade_ShapeDivide::*)() const) &ShapeUpgrade_ShapeDivide::Result, "Gives the resulting Shape, or Null shape if not done.");
cls_ShapeUpgrade_ShapeDivide.def("GetContext", (opencascade::handle<ShapeBuild_ReShape> (ShapeUpgrade_ShapeDivide::*)() const) &ShapeUpgrade_ShapeDivide::GetContext, "Returns context with all the modifications made during last call(s) to Perform() recorded");
cls_ShapeUpgrade_ShapeDivide.def("SetContext", (void (ShapeUpgrade_ShapeDivide::*)(const opencascade::handle<ShapeBuild_ReShape> &)) &ShapeUpgrade_ShapeDivide::SetContext, "Sets context with recorded modifications to be applied during next call(s) to Perform(shape,Standard_False)", py::arg("context"));
cls_ShapeUpgrade_ShapeDivide.def("SetMsgRegistrator", (void (ShapeUpgrade_ShapeDivide::*)(const opencascade::handle<ShapeExtend_BasicMsgRegistrator> &)) &ShapeUpgrade_ShapeDivide::SetMsgRegistrator, "Sets message registrator", py::arg("msgreg"));
cls_ShapeUpgrade_ShapeDivide.def("MsgRegistrator", (opencascade::handle<ShapeExtend_BasicMsgRegistrator> (ShapeUpgrade_ShapeDivide::*)() const) &ShapeUpgrade_ShapeDivide::MsgRegistrator, "Returns message registrator");
cls_ShapeUpgrade_ShapeDivide.def("SendMsg", [](ShapeUpgrade_ShapeDivide &self, const TopoDS_Shape & a0, const Message_Msg & a1) -> void { return self.SendMsg(a0, a1); });
cls_ShapeUpgrade_ShapeDivide.def("SendMsg", (void (ShapeUpgrade_ShapeDivide::*)(const TopoDS_Shape &, const Message_Msg &, const Message_Gravity) const) &ShapeUpgrade_ShapeDivide::SendMsg, "Sends a message to be attached to the shape. Calls corresponding message of message registrator.", py::arg("shape"), py::arg("message"), py::arg("gravity"));
cls_ShapeUpgrade_ShapeDivide.def("Status", (Standard_Boolean (ShapeUpgrade_ShapeDivide::*)(const ShapeExtend_Status) const) &ShapeUpgrade_ShapeDivide::Status, "Queries the status of last call to Perform OK : no splitting was done (or no call to Perform) DONE1: some edges were splitted DONE2: surface was splitted FAIL1: some errors occured", py::arg("status"));
cls_ShapeUpgrade_ShapeDivide.def("SetSplitFaceTool", (void (ShapeUpgrade_ShapeDivide::*)(const opencascade::handle<ShapeUpgrade_FaceDivide> &)) &ShapeUpgrade_ShapeDivide::SetSplitFaceTool, "Sets the tool for splitting faces.", py::arg("splitFaceTool"));
cls_ShapeUpgrade_ShapeDivide.def("SetEdgeMode", (void (ShapeUpgrade_ShapeDivide::*)(const Standard_Integer)) &ShapeUpgrade_ShapeDivide::SetEdgeMode, "Sets mode for splitting 3d curves from edges. 0 - only curve 3d from free edges. 1 - only curve 3d from shared edges. 2 - all curve 3d.", py::arg("aEdgeMode"));

// Enums

}