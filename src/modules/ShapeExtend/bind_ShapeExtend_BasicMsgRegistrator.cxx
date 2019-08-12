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
#include <Message_Msg.hxx>
#include <Message_Gravity.hxx>
#include <TopoDS_Shape.hxx>
#include <ShapeExtend_BasicMsgRegistrator.hxx>
#include <Standard_Type.hxx>

void bind_ShapeExtend_BasicMsgRegistrator(py::module &mod){

py::class_<ShapeExtend_BasicMsgRegistrator, opencascade::handle<ShapeExtend_BasicMsgRegistrator>, Standard_Transient> cls_ShapeExtend_BasicMsgRegistrator(mod, "ShapeExtend_BasicMsgRegistrator", "Abstract class that can be used for attaching messages to the objects (e.g. shapes). It is used by ShapeHealing algorithms to attach a message describing encountered case (e.g. removing small edge from a wire).");

// Constructors
cls_ShapeExtend_BasicMsgRegistrator.def(py::init<>());

// Fields

// Methods
cls_ShapeExtend_BasicMsgRegistrator.def("Send", (void (ShapeExtend_BasicMsgRegistrator::*)(const opencascade::handle<Standard_Transient> &, const Message_Msg &, const Message_Gravity)) &ShapeExtend_BasicMsgRegistrator::Send, "Sends a message to be attached to the object. Object can be of any type interpreted by redefined MsgRegistrator.", py::arg("object"), py::arg("message"), py::arg("gravity"));
cls_ShapeExtend_BasicMsgRegistrator.def("Send", (void (ShapeExtend_BasicMsgRegistrator::*)(const TopoDS_Shape &, const Message_Msg &, const Message_Gravity)) &ShapeExtend_BasicMsgRegistrator::Send, "Sends a message to be attached to the shape.", py::arg("shape"), py::arg("message"), py::arg("gravity"));
cls_ShapeExtend_BasicMsgRegistrator.def("Send", (void (ShapeExtend_BasicMsgRegistrator::*)(const Message_Msg &, const Message_Gravity)) &ShapeExtend_BasicMsgRegistrator::Send, "Calls Send method with Null Transient.", py::arg("message"), py::arg("gravity"));
cls_ShapeExtend_BasicMsgRegistrator.def_static("get_type_name_", (const char * (*)()) &ShapeExtend_BasicMsgRegistrator::get_type_name, "None");
cls_ShapeExtend_BasicMsgRegistrator.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeExtend_BasicMsgRegistrator::get_type_descriptor, "None");
cls_ShapeExtend_BasicMsgRegistrator.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeExtend_BasicMsgRegistrator::*)() const) &ShapeExtend_BasicMsgRegistrator::DynamicType, "None");

// Enums

}