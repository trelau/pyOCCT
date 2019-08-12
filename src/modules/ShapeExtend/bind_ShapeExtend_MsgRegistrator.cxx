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
#include <ShapeExtend_BasicMsgRegistrator.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Transient.hxx>
#include <Message_Msg.hxx>
#include <Message_Gravity.hxx>
#include <TopoDS_Shape.hxx>
#include <ShapeExtend_DataMapOfTransientListOfMsg.hxx>
#include <ShapeExtend_DataMapOfShapeListOfMsg.hxx>
#include <ShapeExtend_MsgRegistrator.hxx>
#include <Standard_Type.hxx>

void bind_ShapeExtend_MsgRegistrator(py::module &mod){

py::class_<ShapeExtend_MsgRegistrator, opencascade::handle<ShapeExtend_MsgRegistrator>, ShapeExtend_BasicMsgRegistrator> cls_ShapeExtend_MsgRegistrator(mod, "ShapeExtend_MsgRegistrator", "Attaches messages to the objects (generic Transient or shape). The objects of this class are transmitted to the Shape Healing algorithms so that they could collect messages occurred during processing.");

// Constructors
cls_ShapeExtend_MsgRegistrator.def(py::init<>());

// Fields

// Methods
cls_ShapeExtend_MsgRegistrator.def("Send", (void (ShapeExtend_MsgRegistrator::*)(const opencascade::handle<Standard_Transient> &, const Message_Msg &, const Message_Gravity)) &ShapeExtend_MsgRegistrator::Send, "Sends a message to be attached to the object. If the object is in the map then the message is added to the list, otherwise the object is firstly added to the map.", py::arg("object"), py::arg("message"), py::arg("gravity"));
cls_ShapeExtend_MsgRegistrator.def("Send", (void (ShapeExtend_MsgRegistrator::*)(const TopoDS_Shape &, const Message_Msg &, const Message_Gravity)) &ShapeExtend_MsgRegistrator::Send, "Sends a message to be attached to the shape. If the shape is in the map then the message is added to the list, otherwise the shape is firstly added to the map.", py::arg("shape"), py::arg("message"), py::arg("gravity"));
cls_ShapeExtend_MsgRegistrator.def("MapTransient", (const ShapeExtend_DataMapOfTransientListOfMsg & (ShapeExtend_MsgRegistrator::*)() const) &ShapeExtend_MsgRegistrator::MapTransient, "Returns a Map of objects and message list");
cls_ShapeExtend_MsgRegistrator.def("MapShape", (const ShapeExtend_DataMapOfShapeListOfMsg & (ShapeExtend_MsgRegistrator::*)() const) &ShapeExtend_MsgRegistrator::MapShape, "Returns a Map of shapes and message list");
cls_ShapeExtend_MsgRegistrator.def_static("get_type_name_", (const char * (*)()) &ShapeExtend_MsgRegistrator::get_type_name, "None");
cls_ShapeExtend_MsgRegistrator.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeExtend_MsgRegistrator::get_type_descriptor, "None");
cls_ShapeExtend_MsgRegistrator.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeExtend_MsgRegistrator::*)() const) &ShapeExtend_MsgRegistrator::DynamicType, "None");

// Enums

}