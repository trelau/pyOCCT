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
#include <TColStd_DataMapOfTransientTransient.hxx>
#include <Standard_Handle.hxx>
#include <Transfer_MapContainer.hxx>
#include <Standard_Type.hxx>

void bind_Transfer_MapContainer(py::module &mod){

py::class_<Transfer_MapContainer, opencascade::handle<Transfer_MapContainer>, Standard_Transient> cls_Transfer_MapContainer(mod, "Transfer_MapContainer", "None");

// Constructors
cls_Transfer_MapContainer.def(py::init<>());

// Fields

// Methods
cls_Transfer_MapContainer.def("SetMapObjects", (void (Transfer_MapContainer::*)(TColStd_DataMapOfTransientTransient &)) &Transfer_MapContainer::SetMapObjects, "Set map already translated geometry objects.", py::arg("theMapObjects"));
cls_Transfer_MapContainer.def("GetMapObjects", (TColStd_DataMapOfTransientTransient & (Transfer_MapContainer::*)()) &Transfer_MapContainer::GetMapObjects, "Get map already translated geometry objects.");
cls_Transfer_MapContainer.def_static("get_type_name_", (const char * (*)()) &Transfer_MapContainer::get_type_name, "None");
cls_Transfer_MapContainer.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Transfer_MapContainer::get_type_descriptor, "None");
cls_Transfer_MapContainer.def("DynamicType", (const opencascade::handle<Standard_Type> & (Transfer_MapContainer::*)() const) &Transfer_MapContainer::DynamicType, "None");

// Enums

}