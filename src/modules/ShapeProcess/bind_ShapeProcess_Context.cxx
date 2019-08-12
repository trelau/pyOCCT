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
#include <Resource_Manager.hxx>
#include <TCollection_AsciiString.hxx>
#include <Message_Messenger.hxx>
#include <Message_ProgressIndicator.hxx>
#include <ShapeProcess_Context.hxx>
#include <Standard_Type.hxx>
#include <TColStd_HSequenceOfHAsciiString.hxx>

void bind_ShapeProcess_Context(py::module &mod){

py::class_<ShapeProcess_Context, opencascade::handle<ShapeProcess_Context>, Standard_Transient> cls_ShapeProcess_Context(mod, "ShapeProcess_Context", "Provides convenient interface to resource file Allows to load resource file and get values of attributes starting from some scope, for example if scope is defined as 'ToV4' and requested parameter is 'exec.op', value of 'ToV4.exec.op' parameter from the resource file will be returned");

// Constructors
cls_ShapeProcess_Context.def(py::init<>());
cls_ShapeProcess_Context.def(py::init<const Standard_CString>(), py::arg("file"));
cls_ShapeProcess_Context.def(py::init<const Standard_CString, const Standard_CString>(), py::arg("file"), py::arg("scope"));

// Fields

// Methods
cls_ShapeProcess_Context.def("Init", [](ShapeProcess_Context &self, const Standard_CString a0) -> Standard_Boolean { return self.Init(a0); });
cls_ShapeProcess_Context.def("Init", (Standard_Boolean (ShapeProcess_Context::*)(const Standard_CString, const Standard_CString)) &ShapeProcess_Context::Init, "Initialises a tool by loading resource file and (if specified) sets starting scope Returns False if resource file not found", py::arg("file"), py::arg("scope"));
cls_ShapeProcess_Context.def("LoadResourceManager", (opencascade::handle<Resource_Manager> (ShapeProcess_Context::*)(const Standard_CString)) &ShapeProcess_Context::LoadResourceManager, "Loading Resource_Manager object if this object not equal internal static Resource_Manager object or internal static Resource_Manager object is null", py::arg("file"));
cls_ShapeProcess_Context.def("ResourceManager", (const opencascade::handle<Resource_Manager> & (ShapeProcess_Context::*)() const) &ShapeProcess_Context::ResourceManager, "Returns internal Resource_Manager object");
cls_ShapeProcess_Context.def("SetScope", (void (ShapeProcess_Context::*)(const Standard_CString)) &ShapeProcess_Context::SetScope, "Set a new (sub)scope", py::arg("scope"));
cls_ShapeProcess_Context.def("UnSetScope", (void (ShapeProcess_Context::*)()) &ShapeProcess_Context::UnSetScope, "Go out of current scope");
cls_ShapeProcess_Context.def("IsParamSet", (Standard_Boolean (ShapeProcess_Context::*)(const Standard_CString) const) &ShapeProcess_Context::IsParamSet, "Returns True if parameter is defined in the resource file", py::arg("param"));
cls_ShapeProcess_Context.def("GetReal", [](ShapeProcess_Context &self, const Standard_CString param, Standard_Real & val){ Standard_Boolean rv = self.GetReal(param, val); return std::tuple<Standard_Boolean, Standard_Real &>(rv, val); }, "None", py::arg("param"), py::arg("val"));
cls_ShapeProcess_Context.def("GetInteger", [](ShapeProcess_Context &self, const Standard_CString param, Standard_Integer & val){ Standard_Boolean rv = self.GetInteger(param, val); return std::tuple<Standard_Boolean, Standard_Integer &>(rv, val); }, "None", py::arg("param"), py::arg("val"));
cls_ShapeProcess_Context.def("GetBoolean", [](ShapeProcess_Context &self, const Standard_CString param, Standard_Boolean & val){ Standard_Boolean rv = self.GetBoolean(param, val); return std::tuple<Standard_Boolean, Standard_Boolean &>(rv, val); }, "None", py::arg("param"), py::arg("val"));
cls_ShapeProcess_Context.def("GetString", (Standard_Boolean (ShapeProcess_Context::*)(const Standard_CString, TCollection_AsciiString &) const) &ShapeProcess_Context::GetString, "Get value of parameter as being of specific type Returns False if parameter is not defined or has a wrong type", py::arg("param"), py::arg("val"));
cls_ShapeProcess_Context.def("RealVal", (Standard_Real (ShapeProcess_Context::*)(const Standard_CString, const Standard_Real) const) &ShapeProcess_Context::RealVal, "None", py::arg("param"), py::arg("def"));
cls_ShapeProcess_Context.def("IntegerVal", (Standard_Integer (ShapeProcess_Context::*)(const Standard_CString, const Standard_Integer) const) &ShapeProcess_Context::IntegerVal, "None", py::arg("param"), py::arg("def"));
cls_ShapeProcess_Context.def("BooleanVal", (Standard_Boolean (ShapeProcess_Context::*)(const Standard_CString, const Standard_Boolean) const) &ShapeProcess_Context::BooleanVal, "None", py::arg("param"), py::arg("def"));
cls_ShapeProcess_Context.def("StringVal", (Standard_CString (ShapeProcess_Context::*)(const Standard_CString, const Standard_CString) const) &ShapeProcess_Context::StringVal, "Get value of parameter as being of specific type If parameter is not defined or does not have expected type, returns default value as specified", py::arg("param"), py::arg("def"));
cls_ShapeProcess_Context.def("SetMessenger", (void (ShapeProcess_Context::*)(const opencascade::handle<Message_Messenger> &)) &ShapeProcess_Context::SetMessenger, "Sets Messenger used for outputting messages.", py::arg("messenger"));
cls_ShapeProcess_Context.def("Messenger", (opencascade::handle<Message_Messenger> (ShapeProcess_Context::*)() const) &ShapeProcess_Context::Messenger, "Returns Messenger used for outputting messages.");
cls_ShapeProcess_Context.def("SetProgress", (void (ShapeProcess_Context::*)(const opencascade::handle<Message_ProgressIndicator> &)) &ShapeProcess_Context::SetProgress, "Sets Progress Indicator.", py::arg("theProgress"));
cls_ShapeProcess_Context.def("Progress", (opencascade::handle<Message_ProgressIndicator> (ShapeProcess_Context::*)() const) &ShapeProcess_Context::Progress, "Returns Progress Indicator.");
cls_ShapeProcess_Context.def("SetTraceLevel", (void (ShapeProcess_Context::*)(const Standard_Integer)) &ShapeProcess_Context::SetTraceLevel, "Sets trace level used for outputting messages - 0: no trace at all - 1: errors - 2: errors and warnings - 3: all messages Default is 1 : Errors traced", py::arg("tracelev"));
cls_ShapeProcess_Context.def("TraceLevel", (Standard_Integer (ShapeProcess_Context::*)() const) &ShapeProcess_Context::TraceLevel, "Returns trace level used for outputting messages.");
cls_ShapeProcess_Context.def_static("get_type_name_", (const char * (*)()) &ShapeProcess_Context::get_type_name, "None");
cls_ShapeProcess_Context.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeProcess_Context::get_type_descriptor, "None");
cls_ShapeProcess_Context.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeProcess_Context::*)() const) &ShapeProcess_Context::DynamicType, "None");

// Enums

}