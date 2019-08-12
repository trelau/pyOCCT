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
#include <TPrsStd_Driver.hxx>
#include <Standard_TypeDef.hxx>
#include <TDF_Label.hxx>
#include <Standard_Handle.hxx>
#include <AIS_InteractiveObject.hxx>
#include <TPrsStd_GeometryDriver.hxx>
#include <Standard_Type.hxx>

void bind_TPrsStd_GeometryDriver(py::module &mod){

py::class_<TPrsStd_GeometryDriver, opencascade::handle<TPrsStd_GeometryDriver>, TPrsStd_Driver> cls_TPrsStd_GeometryDriver(mod, "TPrsStd_GeometryDriver", "This method is an implementation of TPrsStd_Driver for geometries.");

// Constructors
cls_TPrsStd_GeometryDriver.def(py::init<>());

// Fields

// Methods
cls_TPrsStd_GeometryDriver.def("Update", (Standard_Boolean (TPrsStd_GeometryDriver::*)(const TDF_Label &, opencascade::handle<AIS_InteractiveObject> &)) &TPrsStd_GeometryDriver::Update, "Build the AISObject (if null) or update it. No compute is done. Returns <True> if informations was found and AISObject updated.", py::arg("aLabel"), py::arg("anAISObject"));
cls_TPrsStd_GeometryDriver.def_static("get_type_name_", (const char * (*)()) &TPrsStd_GeometryDriver::get_type_name, "None");
cls_TPrsStd_GeometryDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TPrsStd_GeometryDriver::get_type_descriptor, "None");
cls_TPrsStd_GeometryDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (TPrsStd_GeometryDriver::*)() const) &TPrsStd_GeometryDriver::DynamicType, "None");

// Enums

}