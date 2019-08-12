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
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Message_Alert.hxx>
#include <Standard_Type.hxx>

void bind_Message_Alert(py::module &mod){

py::class_<Message_Alert, opencascade::handle<Message_Alert>, Standard_Transient> cls_Message_Alert(mod, "Message_Alert", "Base class of the hierarchy of classes describing various situations occurring during execution of some algorithm or procedure.");

// Constructors

// Fields

// Methods
cls_Message_Alert.def("GetMessageKey", (Standard_CString (Message_Alert::*)() const) &Message_Alert::GetMessageKey, "Return a C string to be used as a key for generating text user messages describing this alert. The messages are generated with help of Message_Msg class, in Message_Report::Dump(). Base implementation returns dynamic type name of the instance.");
cls_Message_Alert.def("SupportsMerge", (Standard_Boolean (Message_Alert::*)() const) &Message_Alert::SupportsMerge, "Return true if this type of alert can be merged with other of the same type to avoid duplication. Basis implementation returns true.");
cls_Message_Alert.def("Merge", (Standard_Boolean (Message_Alert::*)(const opencascade::handle<Message_Alert> &)) &Message_Alert::Merge, "If possible, merge data contained in this alert to theTarget.", py::arg("theTarget"));
cls_Message_Alert.def_static("get_type_name_", (const char * (*)()) &Message_Alert::get_type_name, "None");
cls_Message_Alert.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Message_Alert::get_type_descriptor, "None");
cls_Message_Alert.def("DynamicType", (const opencascade::handle<Standard_Type> & (Message_Alert::*)() const) &Message_Alert::DynamicType, "None");

// Enums

}