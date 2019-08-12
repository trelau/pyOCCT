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
#include <BRepTools_Modification.hxx>
#include <Standard_Handle.hxx>
#include <ShapeExtend_BasicMsgRegistrator.hxx>
#include <TopoDS_Shape.hxx>
#include <Message_Msg.hxx>
#include <Message_Gravity.hxx>
#include <ShapeCustom_Modification.hxx>
#include <Standard_Type.hxx>

void bind_ShapeCustom_Modification(py::module &mod){

py::class_<ShapeCustom_Modification, opencascade::handle<ShapeCustom_Modification>, BRepTools_Modification> cls_ShapeCustom_Modification(mod, "ShapeCustom_Modification", "A base class of Modification's from ShapeCustom. Implements message sending mechanism.");

// Fields

// Methods
cls_ShapeCustom_Modification.def("SetMsgRegistrator", (void (ShapeCustom_Modification::*)(const opencascade::handle<ShapeExtend_BasicMsgRegistrator> &)) &ShapeCustom_Modification::SetMsgRegistrator, "Sets message registrator", py::arg("msgreg"));
cls_ShapeCustom_Modification.def("MsgRegistrator", (opencascade::handle<ShapeExtend_BasicMsgRegistrator> (ShapeCustom_Modification::*)() const) &ShapeCustom_Modification::MsgRegistrator, "Returns message registrator");
cls_ShapeCustom_Modification.def("SendMsg", [](ShapeCustom_Modification &self, const TopoDS_Shape & a0, const Message_Msg & a1) -> void { return self.SendMsg(a0, a1); });
cls_ShapeCustom_Modification.def("SendMsg", (void (ShapeCustom_Modification::*)(const TopoDS_Shape &, const Message_Msg &, const Message_Gravity) const) &ShapeCustom_Modification::SendMsg, "Sends a message to be attached to the shape. Calls corresponding message of message registrator.", py::arg("shape"), py::arg("message"), py::arg("gravity"));
cls_ShapeCustom_Modification.def_static("get_type_name_", (const char * (*)()) &ShapeCustom_Modification::get_type_name, "None");
cls_ShapeCustom_Modification.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeCustom_Modification::get_type_descriptor, "None");
cls_ShapeCustom_Modification.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeCustom_Modification::*)() const) &ShapeCustom_Modification::DynamicType, "None");

// Enums

}