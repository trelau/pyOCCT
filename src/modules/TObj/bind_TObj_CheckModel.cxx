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
#include <Message_Algorithm.hxx>
#include <Standard_Handle.hxx>
#include <TObj_Model.hxx>
#include <Standard_TypeDef.hxx>
#include <TObj_CheckModel.hxx>
#include <Standard_Type.hxx>

void bind_TObj_CheckModel(py::module &mod){

py::class_<TObj_CheckModel, opencascade::handle<TObj_CheckModel>, Message_Algorithm> cls_TObj_CheckModel(mod, "TObj_CheckModel", "This class provides consistency check of the TObj model. It collects all inconsistencies in the status bits and prepaires messages to be sent using SendStatusMessages (SendMessages) method. It supports also the fix mode, in which some inconsistencies are corrected.");

// Constructors
cls_TObj_CheckModel.def(py::init<const opencascade::handle<TObj_Model> &>(), py::arg("theModel"));

// Fields

// Methods
cls_TObj_CheckModel.def("SetToFix", (void (TObj_CheckModel::*)(const Standard_Boolean)) &TObj_CheckModel::SetToFix, "Sets flag allowing fixing inconsistencies", py::arg("theToFix"));
cls_TObj_CheckModel.def("IsToFix", (Standard_Boolean (TObj_CheckModel::*)() const) &TObj_CheckModel::IsToFix, "Returns true if it is allowed to fix inconsistencies");
cls_TObj_CheckModel.def("GetModel", (const opencascade::handle<TObj_Model> & (TObj_CheckModel::*)() const) &TObj_CheckModel::GetModel, "Returns the checked model");
cls_TObj_CheckModel.def("Perform", (Standard_Boolean (TObj_CheckModel::*)()) &TObj_CheckModel::Perform, "Performs all checks. Descendants should call parent method before doing own checks. This implementation checks OCAF references and back references between objects of the model. Returns true if no inconsistencies found.");
cls_TObj_CheckModel.def_static("get_type_name_", (const char * (*)()) &TObj_CheckModel::get_type_name, "None");
cls_TObj_CheckModel.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TObj_CheckModel::get_type_descriptor, "None");
cls_TObj_CheckModel.def("DynamicType", (const opencascade::handle<Standard_Type> & (TObj_CheckModel::*)() const) &TObj_CheckModel::DynamicType, "None");

// Enums

}