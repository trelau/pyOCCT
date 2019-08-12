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
#include <Standard_GUID.hxx>
#include <XCAFPrs_Driver.hxx>
#include <Standard_Type.hxx>

void bind_XCAFPrs_Driver(py::module &mod){

py::class_<XCAFPrs_Driver, opencascade::handle<XCAFPrs_Driver>, TPrsStd_Driver> cls_XCAFPrs_Driver(mod, "XCAFPrs_Driver", "Implements a driver for presentation of shapes in DECAF document. Its the only purpose is to initialize and return XCAFPrs_AISObject object on request");

// Constructors

// Fields

// Methods
cls_XCAFPrs_Driver.def("Update", (Standard_Boolean (XCAFPrs_Driver::*)(const TDF_Label &, opencascade::handle<AIS_InteractiveObject> &)) &XCAFPrs_Driver::Update, "None", py::arg("L"), py::arg("ais"));
cls_XCAFPrs_Driver.def_static("GetID_", (const Standard_GUID & (*)()) &XCAFPrs_Driver::GetID, "returns GUID of the driver");
cls_XCAFPrs_Driver.def_static("get_type_name_", (const char * (*)()) &XCAFPrs_Driver::get_type_name, "None");
cls_XCAFPrs_Driver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XCAFPrs_Driver::get_type_descriptor, "None");
cls_XCAFPrs_Driver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XCAFPrs_Driver::*)() const) &XCAFPrs_Driver::DynamicType, "None");

// Enums

}