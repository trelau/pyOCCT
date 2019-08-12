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
#include <TDocStd_SequenceOfDocument.hxx>
#include <TCollection_ExtendedString.hxx>
#include <Standard_OStream.hxx>
#include <Standard_Handle.hxx>
#include <TDocStd_ApplicationDelta.hxx>
#include <Standard_Type.hxx>

void bind_TDocStd_ApplicationDelta(py::module &mod){

py::class_<TDocStd_ApplicationDelta, opencascade::handle<TDocStd_ApplicationDelta>, Standard_Transient> cls_TDocStd_ApplicationDelta(mod, "TDocStd_ApplicationDelta", "None");

// Constructors
cls_TDocStd_ApplicationDelta.def(py::init<>());

// Fields

// Methods
cls_TDocStd_ApplicationDelta.def("GetDocuments", (TDocStd_SequenceOfDocument & (TDocStd_ApplicationDelta::*)()) &TDocStd_ApplicationDelta::GetDocuments, "None");
cls_TDocStd_ApplicationDelta.def("GetName", (const TCollection_ExtendedString & (TDocStd_ApplicationDelta::*)() const) &TDocStd_ApplicationDelta::GetName, "None");
cls_TDocStd_ApplicationDelta.def("SetName", (void (TDocStd_ApplicationDelta::*)(const TCollection_ExtendedString &)) &TDocStd_ApplicationDelta::SetName, "None", py::arg("theName"));
cls_TDocStd_ApplicationDelta.def("Dump", (void (TDocStd_ApplicationDelta::*)(Standard_OStream &) const) &TDocStd_ApplicationDelta::Dump, "None", py::arg("anOS"));
cls_TDocStd_ApplicationDelta.def_static("get_type_name_", (const char * (*)()) &TDocStd_ApplicationDelta::get_type_name, "None");
cls_TDocStd_ApplicationDelta.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDocStd_ApplicationDelta::get_type_descriptor, "None");
cls_TDocStd_ApplicationDelta.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDocStd_ApplicationDelta::*)() const) &TDocStd_ApplicationDelta::DynamicType, "None");

// Enums

}