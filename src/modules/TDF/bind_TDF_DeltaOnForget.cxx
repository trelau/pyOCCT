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
#include <TDF_Attribute.hxx>
#include <TDF_DeltaOnForget.hxx>
#include <Standard_Type.hxx>

void bind_TDF_DeltaOnForget(py::module &mod){

py::class_<TDF_DeltaOnForget, opencascade::handle<TDF_DeltaOnForget>, TDF_AttributeDelta> cls_TDF_DeltaOnForget(mod, "TDF_DeltaOnForget", "This class provides default services for an AttributeDelta on an Forget action.");

// Constructors
cls_TDF_DeltaOnForget.def(py::init<const opencascade::handle<TDF_Attribute> &>(), py::arg("anAtt"));

// Fields

// Methods
cls_TDF_DeltaOnForget.def("Apply", (void (TDF_DeltaOnForget::*)()) &TDF_DeltaOnForget::Apply, "Applies the delta to the attribute.");
cls_TDF_DeltaOnForget.def_static("get_type_name_", (const char * (*)()) &TDF_DeltaOnForget::get_type_name, "None");
cls_TDF_DeltaOnForget.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDF_DeltaOnForget::get_type_descriptor, "None");
cls_TDF_DeltaOnForget.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDF_DeltaOnForget::*)() const) &TDF_DeltaOnForget::DynamicType, "None");

// Enums

}