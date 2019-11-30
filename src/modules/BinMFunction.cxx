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
#include <BinMDF_ADriverTable.hxx>
#include <Message_Messenger.hxx>
#include <BinMFunction_FunctionDriver.hxx>
#include <BinMFunction_GraphNodeDriver.hxx>
#include <BinMFunction_ScopeDriver.hxx>
#include <BinMFunction.hxx>
#include <BinMDF_ADriver.hxx>
#include <TDF_Attribute.hxx>
#include <Standard_TypeDef.hxx>
#include <BinObjMgt_Persistent.hxx>
#include <BinObjMgt_RRelocationTable.hxx>
#include <BinObjMgt_SRelocationTable.hxx>
#include <Standard_Std.hxx>
#include <Standard_Type.hxx>

PYBIND11_MODULE(BinMFunction, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.BinMDF");
py::module::import("OCCT.Message");
py::module::import("OCCT.TDF");
py::module::import("OCCT.BinObjMgt");

// CLASS: BINMFUNCTION
py::class_<BinMFunction> cls_BinMFunction(mod, "BinMFunction", "Storage and Retrieval drivers for TFunction modelling attributes.");

// Constructors
cls_BinMFunction.def(py::init<>());

// Methods
// cls_BinMFunction.def_static("operator new_", (void * (*)(size_t)) &BinMFunction::operator new, "None", py::arg("theSize"));
// cls_BinMFunction.def_static("operator delete_", (void (*)(void *)) &BinMFunction::operator delete, "None", py::arg("theAddress"));
// cls_BinMFunction.def_static("operator new[]_", (void * (*)(size_t)) &BinMFunction::operator new[], "None", py::arg("theSize"));
// cls_BinMFunction.def_static("operator delete[]_", (void (*)(void *)) &BinMFunction::operator delete[], "None", py::arg("theAddress"));
// cls_BinMFunction.def_static("operator new_", (void * (*)(size_t, void *)) &BinMFunction::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BinMFunction.def_static("operator delete_", (void (*)(void *, void *)) &BinMFunction::operator delete, "None", py::arg(""), py::arg(""));
cls_BinMFunction.def_static("AddDrivers_", (void (*)(const opencascade::handle<BinMDF_ADriverTable> &, const opencascade::handle<Message_Messenger> &)) &BinMFunction::AddDrivers, "Adds the attribute drivers to <theDriverTable>.", py::arg("theDriverTable"), py::arg("aMsgDrv"));

// CLASS: BINMFUNCTION_FUNCTIONDRIVER
py::class_<BinMFunction_FunctionDriver, opencascade::handle<BinMFunction_FunctionDriver>, BinMDF_ADriver> cls_BinMFunction_FunctionDriver(mod, "BinMFunction_FunctionDriver", "Function attribute Driver.");

// Constructors
cls_BinMFunction_FunctionDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Methods
cls_BinMFunction_FunctionDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMFunction_FunctionDriver::*)() const) &BinMFunction_FunctionDriver::NewEmpty, "None");
cls_BinMFunction_FunctionDriver.def("Paste", (Standard_Boolean (BinMFunction_FunctionDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const) &BinMFunction_FunctionDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_BinMFunction_FunctionDriver.def("Paste", (void (BinMFunction_FunctionDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const) &BinMFunction_FunctionDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_BinMFunction_FunctionDriver.def_static("get_type_name_", (const char * (*)()) &BinMFunction_FunctionDriver::get_type_name, "None");
cls_BinMFunction_FunctionDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMFunction_FunctionDriver::get_type_descriptor, "None");
cls_BinMFunction_FunctionDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMFunction_FunctionDriver::*)() const) &BinMFunction_FunctionDriver::DynamicType, "None");

// CLASS: BINMFUNCTION_GRAPHNODEDRIVER
py::class_<BinMFunction_GraphNodeDriver, opencascade::handle<BinMFunction_GraphNodeDriver>, BinMDF_ADriver> cls_BinMFunction_GraphNodeDriver(mod, "BinMFunction_GraphNodeDriver", "GraphNode attribute Driver.");

// Constructors
cls_BinMFunction_GraphNodeDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Methods
cls_BinMFunction_GraphNodeDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMFunction_GraphNodeDriver::*)() const) &BinMFunction_GraphNodeDriver::NewEmpty, "None");
cls_BinMFunction_GraphNodeDriver.def("Paste", (Standard_Boolean (BinMFunction_GraphNodeDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const) &BinMFunction_GraphNodeDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_BinMFunction_GraphNodeDriver.def("Paste", (void (BinMFunction_GraphNodeDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const) &BinMFunction_GraphNodeDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_BinMFunction_GraphNodeDriver.def_static("get_type_name_", (const char * (*)()) &BinMFunction_GraphNodeDriver::get_type_name, "None");
cls_BinMFunction_GraphNodeDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMFunction_GraphNodeDriver::get_type_descriptor, "None");
cls_BinMFunction_GraphNodeDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMFunction_GraphNodeDriver::*)() const) &BinMFunction_GraphNodeDriver::DynamicType, "None");

// CLASS: BINMFUNCTION_SCOPEDRIVER
py::class_<BinMFunction_ScopeDriver, opencascade::handle<BinMFunction_ScopeDriver>, BinMDF_ADriver> cls_BinMFunction_ScopeDriver(mod, "BinMFunction_ScopeDriver", "Scope attribute Driver.");

// Constructors
cls_BinMFunction_ScopeDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Methods
cls_BinMFunction_ScopeDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMFunction_ScopeDriver::*)() const) &BinMFunction_ScopeDriver::NewEmpty, "None");
cls_BinMFunction_ScopeDriver.def("Paste", (Standard_Boolean (BinMFunction_ScopeDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const) &BinMFunction_ScopeDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_BinMFunction_ScopeDriver.def("Paste", (void (BinMFunction_ScopeDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const) &BinMFunction_ScopeDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_BinMFunction_ScopeDriver.def_static("get_type_name_", (const char * (*)()) &BinMFunction_ScopeDriver::get_type_name, "None");
cls_BinMFunction_ScopeDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMFunction_ScopeDriver::get_type_descriptor, "None");
cls_BinMFunction_ScopeDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMFunction_ScopeDriver::*)() const) &BinMFunction_ScopeDriver::DynamicType, "None");


}
