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
#include <Standard_Handle.hxx>
#include <XmlMDF_ADriverTable.hxx>
#include <Message_Messenger.hxx>
#include <XmlMFunction_FunctionDriver.hxx>
#include <XmlMFunction_ScopeDriver.hxx>
#include <XmlMFunction_GraphNodeDriver.hxx>
#include <XmlMFunction.hxx>
#include <XmlMDF_ADriver.hxx>
#include <TDF_Attribute.hxx>
#include <Standard_TypeDef.hxx>
#include <XmlObjMgt_Persistent.hxx>
#include <XmlObjMgt_RRelocationTable.hxx>
#include <XmlObjMgt_SRelocationTable.hxx>
#include <Standard_Type.hxx>

PYBIND11_MODULE(XmlMFunction, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.XmlMDF");
py::module::import("OCCT.Message");
py::module::import("OCCT.TDF");
py::module::import("OCCT.XmlObjMgt");

// CLASS: XMLMFUNCTION
py::class_<XmlMFunction> cls_XmlMFunction(mod, "XmlMFunction", "None");

// Methods
// cls_XmlMFunction.def_static("operator new_", (void * (*)(size_t)) &XmlMFunction::operator new, "None", py::arg("theSize"));
// cls_XmlMFunction.def_static("operator delete_", (void (*)(void *)) &XmlMFunction::operator delete, "None", py::arg("theAddress"));
// cls_XmlMFunction.def_static("operator new[]_", (void * (*)(size_t)) &XmlMFunction::operator new[], "None", py::arg("theSize"));
// cls_XmlMFunction.def_static("operator delete[]_", (void (*)(void *)) &XmlMFunction::operator delete[], "None", py::arg("theAddress"));
// cls_XmlMFunction.def_static("operator new_", (void * (*)(size_t, void *)) &XmlMFunction::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_XmlMFunction.def_static("operator delete_", (void (*)(void *, void *)) &XmlMFunction::operator delete, "None", py::arg(""), py::arg(""));
cls_XmlMFunction.def_static("AddDrivers_", (void (*)(const opencascade::handle<XmlMDF_ADriverTable> &, const opencascade::handle<Message_Messenger> &)) &XmlMFunction::AddDrivers, "Adds the attribute storage drivers to <aDriverTable>.", py::arg("aDriverTable"), py::arg("theMessageDriver"));

// CLASS: XMLMFUNCTION_FUNCTIONDRIVER
py::class_<XmlMFunction_FunctionDriver, opencascade::handle<XmlMFunction_FunctionDriver>, XmlMDF_ADriver> cls_XmlMFunction_FunctionDriver(mod, "XmlMFunction_FunctionDriver", "Attribute Driver.");

// Constructors
cls_XmlMFunction_FunctionDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Methods
cls_XmlMFunction_FunctionDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XmlMFunction_FunctionDriver::*)() const) &XmlMFunction_FunctionDriver::NewEmpty, "None");
cls_XmlMFunction_FunctionDriver.def("Paste", (Standard_Boolean (XmlMFunction_FunctionDriver::*)(const XmlObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, XmlObjMgt_RRelocationTable &) const) &XmlMFunction_FunctionDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMFunction_FunctionDriver.def("Paste", (void (XmlMFunction_FunctionDriver::*)(const opencascade::handle<TDF_Attribute> &, XmlObjMgt_Persistent &, XmlObjMgt_SRelocationTable &) const) &XmlMFunction_FunctionDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMFunction_FunctionDriver.def_static("get_type_name_", (const char * (*)()) &XmlMFunction_FunctionDriver::get_type_name, "None");
cls_XmlMFunction_FunctionDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlMFunction_FunctionDriver::get_type_descriptor, "None");
cls_XmlMFunction_FunctionDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlMFunction_FunctionDriver::*)() const) &XmlMFunction_FunctionDriver::DynamicType, "None");

// CLASS: XMLMFUNCTION_GRAPHNODEDRIVER
py::class_<XmlMFunction_GraphNodeDriver, opencascade::handle<XmlMFunction_GraphNodeDriver>, XmlMDF_ADriver> cls_XmlMFunction_GraphNodeDriver(mod, "XmlMFunction_GraphNodeDriver", "XML persistence driver for dependencies of a function.");

// Constructors
cls_XmlMFunction_GraphNodeDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Methods
cls_XmlMFunction_GraphNodeDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XmlMFunction_GraphNodeDriver::*)() const) &XmlMFunction_GraphNodeDriver::NewEmpty, "None");
cls_XmlMFunction_GraphNodeDriver.def("Paste", (Standard_Boolean (XmlMFunction_GraphNodeDriver::*)(const XmlObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, XmlObjMgt_RRelocationTable &) const) &XmlMFunction_GraphNodeDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMFunction_GraphNodeDriver.def("Paste", (void (XmlMFunction_GraphNodeDriver::*)(const opencascade::handle<TDF_Attribute> &, XmlObjMgt_Persistent &, XmlObjMgt_SRelocationTable &) const) &XmlMFunction_GraphNodeDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMFunction_GraphNodeDriver.def_static("get_type_name_", (const char * (*)()) &XmlMFunction_GraphNodeDriver::get_type_name, "None");
cls_XmlMFunction_GraphNodeDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlMFunction_GraphNodeDriver::get_type_descriptor, "None");
cls_XmlMFunction_GraphNodeDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlMFunction_GraphNodeDriver::*)() const) &XmlMFunction_GraphNodeDriver::DynamicType, "None");

// CLASS: XMLMFUNCTION_SCOPEDRIVER
py::class_<XmlMFunction_ScopeDriver, opencascade::handle<XmlMFunction_ScopeDriver>, XmlMDF_ADriver> cls_XmlMFunction_ScopeDriver(mod, "XmlMFunction_ScopeDriver", "XML persistence driver for a scope of functions.");

// Constructors
cls_XmlMFunction_ScopeDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Methods
cls_XmlMFunction_ScopeDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XmlMFunction_ScopeDriver::*)() const) &XmlMFunction_ScopeDriver::NewEmpty, "None");
cls_XmlMFunction_ScopeDriver.def("Paste", (Standard_Boolean (XmlMFunction_ScopeDriver::*)(const XmlObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, XmlObjMgt_RRelocationTable &) const) &XmlMFunction_ScopeDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMFunction_ScopeDriver.def("Paste", (void (XmlMFunction_ScopeDriver::*)(const opencascade::handle<TDF_Attribute> &, XmlObjMgt_Persistent &, XmlObjMgt_SRelocationTable &) const) &XmlMFunction_ScopeDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMFunction_ScopeDriver.def_static("get_type_name_", (const char * (*)()) &XmlMFunction_ScopeDriver::get_type_name, "None");
cls_XmlMFunction_ScopeDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlMFunction_ScopeDriver::get_type_descriptor, "None");
cls_XmlMFunction_ScopeDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlMFunction_ScopeDriver::*)() const) &XmlMFunction_ScopeDriver::DynamicType, "None");


}
