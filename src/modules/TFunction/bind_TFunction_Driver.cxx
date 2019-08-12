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
#include <TDF_Label.hxx>
#include <Standard_Handle.hxx>
#include <TFunction_Logbook.hxx>
#include <Standard_TypeDef.hxx>
#include <TDF_LabelList.hxx>
#include <TFunction_Driver.hxx>
#include <Standard_Type.hxx>

void bind_TFunction_Driver(py::module &mod){

py::class_<TFunction_Driver, opencascade::handle<TFunction_Driver>, Standard_Transient> cls_TFunction_Driver(mod, "TFunction_Driver", "This driver class provide services around function execution. One instance of this class is built for the whole session. The driver is bound to the DriverGUID in the DriverTable class. It allows you to create classes which inherit from this abstract class. These subclasses identify the various algorithms which can be applied to the data contained in the attributes of sub-labels of a model. A single instance of this class and each of its subclasses is built for the whole session.");

// Fields

// Methods
cls_TFunction_Driver.def("Init", (void (TFunction_Driver::*)(const TDF_Label &)) &TFunction_Driver::Init, "Initializes the label L for this function prior to its execution.", py::arg("L"));
cls_TFunction_Driver.def("Label", (TDF_Label (TFunction_Driver::*)() const) &TFunction_Driver::Label, "Returns the label of the driver for this function.");
cls_TFunction_Driver.def("Validate", (void (TFunction_Driver::*)(opencascade::handle<TFunction_Logbook> &) const) &TFunction_Driver::Validate, "Validates labels of a function in <log>. This function is the one initialized in this function driver. Warning In regeneration mode, the solver must call this method even if the function is not executed. execution of function =====================", py::arg("log"));
cls_TFunction_Driver.def("MustExecute", (Standard_Boolean (TFunction_Driver::*)(const opencascade::handle<TFunction_Logbook> &) const) &TFunction_Driver::MustExecute, "Analyzes the labels in the logbook log. Returns true if attributes have been modified. If the function label itself has been modified, the function must be executed.", py::arg("log"));
cls_TFunction_Driver.def("Execute", (Standard_Integer (TFunction_Driver::*)(opencascade::handle<TFunction_Logbook> &) const) &TFunction_Driver::Execute, "Executes the function in this function driver and puts the impacted labels in the logbook log. arguments & results of functions ================================", py::arg("log"));
cls_TFunction_Driver.def("Arguments", (void (TFunction_Driver::*)(TDF_LabelList &) const) &TFunction_Driver::Arguments, "The method fills-in the list by labels, where the arguments of the function are located.", py::arg("args"));
cls_TFunction_Driver.def("Results", (void (TFunction_Driver::*)(TDF_LabelList &) const) &TFunction_Driver::Results, "The method fills-in the list by labels, where the results of the function are located.", py::arg("res"));
cls_TFunction_Driver.def_static("get_type_name_", (const char * (*)()) &TFunction_Driver::get_type_name, "None");
cls_TFunction_Driver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TFunction_Driver::get_type_descriptor, "None");
cls_TFunction_Driver.def("DynamicType", (const opencascade::handle<Standard_Type> & (TFunction_Driver::*)() const) &TFunction_Driver::DynamicType, "None");

// Enums

}