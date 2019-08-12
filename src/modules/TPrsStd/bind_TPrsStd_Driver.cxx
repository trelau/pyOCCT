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
#include <TDF_Label.hxx>
#include <Standard_Handle.hxx>
#include <AIS_InteractiveObject.hxx>
#include <TPrsStd_Driver.hxx>
#include <Standard_Type.hxx>

void bind_TPrsStd_Driver(py::module &mod){

py::class_<TPrsStd_Driver, opencascade::handle<TPrsStd_Driver>, Standard_Transient> cls_TPrsStd_Driver(mod, "TPrsStd_Driver", "Driver for AIS ============== An abstract class, which - in classes inheriting from it - allows you to update an AIS_InteractiveObject or create one if one does not already exist. For both creation and update, the interactive object is filled with information contained in attributes. These attributes are those found on the label given as an argument in the method Update. true is returned if the interactive object was modified by the update. This class provide an algorithm to Build with its default values (if Null) or Update (if !Null) an AIS_InteractiveObject . Resources are found in attributes associated to a given label.");

// Fields

// Methods
cls_TPrsStd_Driver.def("Update", (Standard_Boolean (TPrsStd_Driver::*)(const TDF_Label &, opencascade::handle<AIS_InteractiveObject> &)) &TPrsStd_Driver::Update, "Updates the interactive object ais with information found on the attributes associated with the label L.", py::arg("L"), py::arg("ais"));
cls_TPrsStd_Driver.def_static("get_type_name_", (const char * (*)()) &TPrsStd_Driver::get_type_name, "None");
cls_TPrsStd_Driver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TPrsStd_Driver::get_type_descriptor, "None");
cls_TPrsStd_Driver.def("DynamicType", (const opencascade::handle<Standard_Type> & (TPrsStd_Driver::*)() const) &TPrsStd_Driver::DynamicType, "None");

// Enums

}