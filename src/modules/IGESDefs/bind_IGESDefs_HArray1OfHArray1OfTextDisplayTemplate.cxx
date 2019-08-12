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
#include <Standard_Handle.hxx>
#include <IGESGraph_HArray1OfTextDisplayTemplate.hxx>
#include <IGESDefs_HArray1OfHArray1OfTextDisplayTemplate.hxx>
#include <Standard_Type.hxx>
#include <TColStd_Array1OfTransient.hxx>

void bind_IGESDefs_HArray1OfHArray1OfTextDisplayTemplate(py::module &mod){

py::class_<IGESDefs_HArray1OfHArray1OfTextDisplayTemplate, opencascade::handle<IGESDefs_HArray1OfHArray1OfTextDisplayTemplate>, Standard_Transient> cls_IGESDefs_HArray1OfHArray1OfTextDisplayTemplate(mod, "IGESDefs_HArray1OfHArray1OfTextDisplayTemplate", "None");

// Constructors
cls_IGESDefs_HArray1OfHArray1OfTextDisplayTemplate.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("low"), py::arg("up"));

// Fields

// Methods
cls_IGESDefs_HArray1OfHArray1OfTextDisplayTemplate.def("Lower", (Standard_Integer (IGESDefs_HArray1OfHArray1OfTextDisplayTemplate::*)() const) &IGESDefs_HArray1OfHArray1OfTextDisplayTemplate::Lower, "None");
cls_IGESDefs_HArray1OfHArray1OfTextDisplayTemplate.def("Upper", (Standard_Integer (IGESDefs_HArray1OfHArray1OfTextDisplayTemplate::*)() const) &IGESDefs_HArray1OfHArray1OfTextDisplayTemplate::Upper, "None");
cls_IGESDefs_HArray1OfHArray1OfTextDisplayTemplate.def("Length", (Standard_Integer (IGESDefs_HArray1OfHArray1OfTextDisplayTemplate::*)() const) &IGESDefs_HArray1OfHArray1OfTextDisplayTemplate::Length, "None");
cls_IGESDefs_HArray1OfHArray1OfTextDisplayTemplate.def("SetValue", (void (IGESDefs_HArray1OfHArray1OfTextDisplayTemplate::*)(const Standard_Integer, const opencascade::handle<IGESGraph_HArray1OfTextDisplayTemplate> &)) &IGESDefs_HArray1OfHArray1OfTextDisplayTemplate::SetValue, "None", py::arg("num"), py::arg("val"));
cls_IGESDefs_HArray1OfHArray1OfTextDisplayTemplate.def("Value", (opencascade::handle<IGESGraph_HArray1OfTextDisplayTemplate> (IGESDefs_HArray1OfHArray1OfTextDisplayTemplate::*)(const Standard_Integer) const) &IGESDefs_HArray1OfHArray1OfTextDisplayTemplate::Value, "None", py::arg("num"));
cls_IGESDefs_HArray1OfHArray1OfTextDisplayTemplate.def_static("get_type_name_", (const char * (*)()) &IGESDefs_HArray1OfHArray1OfTextDisplayTemplate::get_type_name, "None");
cls_IGESDefs_HArray1OfHArray1OfTextDisplayTemplate.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESDefs_HArray1OfHArray1OfTextDisplayTemplate::get_type_descriptor, "None");
cls_IGESDefs_HArray1OfHArray1OfTextDisplayTemplate.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESDefs_HArray1OfHArray1OfTextDisplayTemplate::*)() const) &IGESDefs_HArray1OfHArray1OfTextDisplayTemplate::DynamicType, "None");

// Enums

}