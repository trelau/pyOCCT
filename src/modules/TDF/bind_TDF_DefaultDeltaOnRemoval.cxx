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
#include <TDF_DeltaOnRemoval.hxx>
#include <Standard_Handle.hxx>
#include <TDF_Attribute.hxx>
#include <TDF_DefaultDeltaOnRemoval.hxx>
#include <Standard_Type.hxx>

void bind_TDF_DefaultDeltaOnRemoval(py::module &mod){

py::class_<TDF_DefaultDeltaOnRemoval, opencascade::handle<TDF_DefaultDeltaOnRemoval>, TDF_DeltaOnRemoval> cls_TDF_DefaultDeltaOnRemoval(mod, "TDF_DefaultDeltaOnRemoval", "This class provides a default implementation of a TDF_DeltaOnRemoval.");

// Constructors
cls_TDF_DefaultDeltaOnRemoval.def(py::init<const opencascade::handle<TDF_Attribute> &>(), py::arg("anAttribute"));

// Fields

// Methods
cls_TDF_DefaultDeltaOnRemoval.def("Apply", (void (TDF_DefaultDeltaOnRemoval::*)()) &TDF_DefaultDeltaOnRemoval::Apply, "Applies the delta to the attribute.");
cls_TDF_DefaultDeltaOnRemoval.def_static("get_type_name_", (const char * (*)()) &TDF_DefaultDeltaOnRemoval::get_type_name, "None");
cls_TDF_DefaultDeltaOnRemoval.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDF_DefaultDeltaOnRemoval::get_type_descriptor, "None");
cls_TDF_DefaultDeltaOnRemoval.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDF_DefaultDeltaOnRemoval::*)() const) &TDF_DefaultDeltaOnRemoval::DynamicType, "None");

// Enums

}