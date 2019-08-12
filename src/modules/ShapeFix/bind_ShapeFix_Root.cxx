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
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <ShapeFix_Root.hxx>
#include <ShapeBuild_ReShape.hxx>
#include <ShapeExtend_BasicMsgRegistrator.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Shape.hxx>
#include <Message_Msg.hxx>
#include <Message_Gravity.hxx>
#include <Standard_Type.hxx>

void bind_ShapeFix_Root(py::module &mod){

py::class_<ShapeFix_Root, opencascade::handle<ShapeFix_Root>, Standard_Transient> cls_ShapeFix_Root(mod, "ShapeFix_Root", "Root class for fixing operations Provides context for recording changes (optional), basic precision value and limit (minimal and maximal) values for tolerances, and message registrator");

// Constructors
cls_ShapeFix_Root.def(py::init<>());

// Fields

// Methods
cls_ShapeFix_Root.def("Set", (void (ShapeFix_Root::*)(const opencascade::handle<ShapeFix_Root> &)) &ShapeFix_Root::Set, "Copy all fields from another Root object", py::arg("Root"));
cls_ShapeFix_Root.def("SetContext", (void (ShapeFix_Root::*)(const opencascade::handle<ShapeBuild_ReShape> &)) &ShapeFix_Root::SetContext, "Sets context", py::arg("context"));
cls_ShapeFix_Root.def("Context", (opencascade::handle<ShapeBuild_ReShape> (ShapeFix_Root::*)() const) &ShapeFix_Root::Context, "Returns context");
cls_ShapeFix_Root.def("SetMsgRegistrator", (void (ShapeFix_Root::*)(const opencascade::handle<ShapeExtend_BasicMsgRegistrator> &)) &ShapeFix_Root::SetMsgRegistrator, "Sets message registrator", py::arg("msgreg"));
cls_ShapeFix_Root.def("MsgRegistrator", (opencascade::handle<ShapeExtend_BasicMsgRegistrator> (ShapeFix_Root::*)() const) &ShapeFix_Root::MsgRegistrator, "Returns message registrator");
cls_ShapeFix_Root.def("SetPrecision", (void (ShapeFix_Root::*)(const Standard_Real)) &ShapeFix_Root::SetPrecision, "Sets basic precision value", py::arg("preci"));
cls_ShapeFix_Root.def("Precision", (Standard_Real (ShapeFix_Root::*)() const) &ShapeFix_Root::Precision, "Returns basic precision value");
cls_ShapeFix_Root.def("SetMinTolerance", (void (ShapeFix_Root::*)(const Standard_Real)) &ShapeFix_Root::SetMinTolerance, "Sets minimal allowed tolerance", py::arg("mintol"));
cls_ShapeFix_Root.def("MinTolerance", (Standard_Real (ShapeFix_Root::*)() const) &ShapeFix_Root::MinTolerance, "Returns minimal allowed tolerance");
cls_ShapeFix_Root.def("SetMaxTolerance", (void (ShapeFix_Root::*)(const Standard_Real)) &ShapeFix_Root::SetMaxTolerance, "Sets maximal allowed tolerance", py::arg("maxtol"));
cls_ShapeFix_Root.def("MaxTolerance", (Standard_Real (ShapeFix_Root::*)() const) &ShapeFix_Root::MaxTolerance, "Returns maximal allowed tolerance");
cls_ShapeFix_Root.def("LimitTolerance", (Standard_Real (ShapeFix_Root::*)(const Standard_Real) const) &ShapeFix_Root::LimitTolerance, "Returns tolerance limited by [myMinTol,myMaxTol]", py::arg("toler"));
cls_ShapeFix_Root.def("SendMsg", [](ShapeFix_Root &self, const TopoDS_Shape & a0, const Message_Msg & a1) -> void { return self.SendMsg(a0, a1); });
cls_ShapeFix_Root.def("SendMsg", (void (ShapeFix_Root::*)(const TopoDS_Shape &, const Message_Msg &, const Message_Gravity) const) &ShapeFix_Root::SendMsg, "Sends a message to be attached to the shape. Calls corresponding message of message registrator.", py::arg("shape"), py::arg("message"), py::arg("gravity"));
cls_ShapeFix_Root.def("SendMsg", [](ShapeFix_Root &self, const Message_Msg & a0) -> void { return self.SendMsg(a0); });
cls_ShapeFix_Root.def("SendMsg", (void (ShapeFix_Root::*)(const Message_Msg &, const Message_Gravity) const) &ShapeFix_Root::SendMsg, "Sends a message to be attached to myShape. Calls previous method.", py::arg("message"), py::arg("gravity"));
cls_ShapeFix_Root.def("SendWarning", (void (ShapeFix_Root::*)(const TopoDS_Shape &, const Message_Msg &) const) &ShapeFix_Root::SendWarning, "Sends a warning to be attached to the shape. Calls SendMsg with gravity set to Message_Warning.", py::arg("shape"), py::arg("message"));
cls_ShapeFix_Root.def("SendWarning", (void (ShapeFix_Root::*)(const Message_Msg &) const) &ShapeFix_Root::SendWarning, "Calls previous method for myShape.", py::arg("message"));
cls_ShapeFix_Root.def("SendFail", (void (ShapeFix_Root::*)(const TopoDS_Shape &, const Message_Msg &) const) &ShapeFix_Root::SendFail, "Sends a fail to be attached to the shape. Calls SendMsg with gravity set to Message_Fail.", py::arg("shape"), py::arg("message"));
cls_ShapeFix_Root.def("SendFail", (void (ShapeFix_Root::*)(const Message_Msg &) const) &ShapeFix_Root::SendFail, "Calls previous method for myShape.", py::arg("message"));
cls_ShapeFix_Root.def_static("get_type_name_", (const char * (*)()) &ShapeFix_Root::get_type_name, "None");
cls_ShapeFix_Root.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeFix_Root::get_type_descriptor, "None");
cls_ShapeFix_Root.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeFix_Root::*)() const) &ShapeFix_Root::DynamicType, "None");

// Enums

}