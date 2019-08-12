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
#include <TDF_AttributeDelta.hxx>
#include <Standard_Handle.hxx>
#include <TDF_DeltaOnRemoval.hxx>
#include <Standard_Type.hxx>
#include <TDF_Attribute.hxx>

void bind_TDF_DeltaOnRemoval(py::module &mod){

py::class_<TDF_DeltaOnRemoval, opencascade::handle<TDF_DeltaOnRemoval>, TDF_AttributeDelta> cls_TDF_DeltaOnRemoval(mod, "TDF_DeltaOnRemoval", "This class provides default services for an AttributeDelta on a REMOVAL action.");

// Fields

// Methods
cls_TDF_DeltaOnRemoval.def_static("get_type_name_", (const char * (*)()) &TDF_DeltaOnRemoval::get_type_name, "None");
cls_TDF_DeltaOnRemoval.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDF_DeltaOnRemoval::get_type_descriptor, "None");
cls_TDF_DeltaOnRemoval.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDF_DeltaOnRemoval::*)() const) &TDF_DeltaOnRemoval::DynamicType, "None");

// Enums

}