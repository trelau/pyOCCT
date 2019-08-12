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
#include <TPrsStd_PointDriver.hxx>
#include <Standard_Type.hxx>

void bind_TPrsStd_PointDriver(py::module &mod){

py::class_<TPrsStd_PointDriver, opencascade::handle<TPrsStd_PointDriver>, TPrsStd_Driver> cls_TPrsStd_PointDriver(mod, "TPrsStd_PointDriver", "An implementation of TPrsStd_Driver for points.");

// Constructors
cls_TPrsStd_PointDriver.def(py::init<>());

// Fields

// Methods
cls_TPrsStd_PointDriver.def("Update", (Standard_Boolean (TPrsStd_PointDriver::*)(const TDF_Label &, opencascade::handle<AIS_InteractiveObject> &)) &TPrsStd_PointDriver::Update, "Build the AISObject (if null) or update it. No compute is done. Returns <True> if informations was found and AISObject updated.", py::arg("aLabel"), py::arg("anAISObject"));
cls_TPrsStd_PointDriver.def_static("get_type_name_", (const char * (*)()) &TPrsStd_PointDriver::get_type_name, "None");
cls_TPrsStd_PointDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TPrsStd_PointDriver::get_type_descriptor, "None");
cls_TPrsStd_PointDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (TPrsStd_PointDriver::*)() const) &TPrsStd_PointDriver::DynamicType, "None");

// Enums

}