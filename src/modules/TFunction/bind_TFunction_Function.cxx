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
#include <TDF_Attribute.hxx>
#include <Standard_Handle.hxx>
#include <TFunction_Function.hxx>
#include <TDF_Label.hxx>
#include <Standard_GUID.hxx>
#include <Standard_TypeDef.hxx>
#include <TDF_RelocationTable.hxx>
#include <TDF_DataSet.hxx>
#include <Standard_OStream.hxx>
#include <Standard_Type.hxx>

void bind_TFunction_Function(py::module &mod){

py::class_<TFunction_Function, opencascade::handle<TFunction_Function>, TDF_Attribute> cls_TFunction_Function(mod, "TFunction_Function", "Provides the following two services - a link to an evaluation driver - the means of providing a link between a function and an evaluation driver.");

// Constructors
cls_TFunction_Function.def(py::init<>());

// Fields

// Methods
cls_TFunction_Function.def_static("Set_", (opencascade::handle<TFunction_Function> (*)(const TDF_Label &)) &TFunction_Function::Set, "Static methods: ============== Finds or Creates a function attribute on the label <L>. Returns the function attribute.", py::arg("L"));
cls_TFunction_Function.def_static("Set_", (opencascade::handle<TFunction_Function> (*)(const TDF_Label &, const Standard_GUID &)) &TFunction_Function::Set, "Finds or Creates a function attribute on the label <L>. Sets a driver ID to the function. Returns the function attribute.", py::arg("L"), py::arg("DriverID"));
cls_TFunction_Function.def_static("GetID_", (const Standard_GUID & (*)()) &TFunction_Function::GetID, "Returns the GUID for functions. Returns a function found on the label. Instance methods: ================");
cls_TFunction_Function.def("GetDriverGUID", (const Standard_GUID & (TFunction_Function::*)() const) &TFunction_Function::GetDriverGUID, "Returns the GUID for this function's driver.");
cls_TFunction_Function.def("SetDriverGUID", (void (TFunction_Function::*)(const Standard_GUID &)) &TFunction_Function::SetDriverGUID, "Sets the driver for this function as that indentified by the GUID guid.", py::arg("guid"));
cls_TFunction_Function.def("Failed", (Standard_Boolean (TFunction_Function::*)() const) &TFunction_Function::Failed, "Returns true if the execution failed");
cls_TFunction_Function.def("SetFailure", [](TFunction_Function &self) -> void { return self.SetFailure(); });
cls_TFunction_Function.def("SetFailure", (void (TFunction_Function::*)(const Standard_Integer)) &TFunction_Function::SetFailure, "Sets the failed index.", py::arg("mode"));
cls_TFunction_Function.def("GetFailure", (Standard_Integer (TFunction_Function::*)() const) &TFunction_Function::GetFailure, "Returns an index of failure if the execution of this function failed. If this integer value is 0, no failure has occurred. Implementation of Attribute methods: ===================================");
cls_TFunction_Function.def("ID", (const Standard_GUID & (TFunction_Function::*)() const) &TFunction_Function::ID, "None");
cls_TFunction_Function.def("Restore", (void (TFunction_Function::*)(const opencascade::handle<TDF_Attribute> &)) &TFunction_Function::Restore, "None", py::arg("with"));
cls_TFunction_Function.def("Paste", (void (TFunction_Function::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TFunction_Function::Paste, "None", py::arg("into"), py::arg("RT"));
cls_TFunction_Function.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TFunction_Function::*)() const) &TFunction_Function::NewEmpty, "None");
cls_TFunction_Function.def("References", (void (TFunction_Function::*)(const opencascade::handle<TDF_DataSet> &) const) &TFunction_Function::References, "None", py::arg("aDataSet"));
cls_TFunction_Function.def("Dump", (Standard_OStream & (TFunction_Function::*)(Standard_OStream &) const) &TFunction_Function::Dump, "None", py::arg("anOS"));
cls_TFunction_Function.def_static("get_type_name_", (const char * (*)()) &TFunction_Function::get_type_name, "None");
cls_TFunction_Function.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TFunction_Function::get_type_descriptor, "None");
cls_TFunction_Function.def("DynamicType", (const opencascade::handle<Standard_Type> & (TFunction_Function::*)() const) &TFunction_Function::DynamicType, "None");

// Enums

}