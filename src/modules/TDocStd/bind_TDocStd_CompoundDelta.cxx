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
#include <TDF_Delta.hxx>
#include <TDocStd_Document.hxx>
#include <Standard_Handle.hxx>
#include <TDocStd_CompoundDelta.hxx>
#include <Standard_Type.hxx>

void bind_TDocStd_CompoundDelta(py::module &mod){

py::class_<TDocStd_CompoundDelta, opencascade::handle<TDocStd_CompoundDelta>, TDF_Delta> cls_TDocStd_CompoundDelta(mod, "TDocStd_CompoundDelta", "A delta set is available at <aSourceTime>. If applied, it restores the TDF_Data in the state it was at <aTargetTime>.");

// Constructors
cls_TDocStd_CompoundDelta.def(py::init<>());

// Fields

// Methods
cls_TDocStd_CompoundDelta.def_static("get_type_name_", (const char * (*)()) &TDocStd_CompoundDelta::get_type_name, "None");
cls_TDocStd_CompoundDelta.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDocStd_CompoundDelta::get_type_descriptor, "None");
cls_TDocStd_CompoundDelta.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDocStd_CompoundDelta::*)() const) &TDocStd_CompoundDelta::DynamicType, "None");

// Enums

}