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
#include <IFSelect_Editor.hxx>
#include <TCollection_AsciiString.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <IFSelect_EditForm.hxx>
#include <TCollection_HAsciiString.hxx>
#include <Standard_Transient.hxx>
#include <Interface_InterfaceModel.hxx>
#include <STEPEdit_EditSDR.hxx>
#include <Standard_Type.hxx>

void bind_STEPEdit_EditSDR(py::module &mod){

py::class_<STEPEdit_EditSDR, opencascade::handle<STEPEdit_EditSDR>, IFSelect_Editor> cls_STEPEdit_EditSDR(mod, "STEPEdit_EditSDR", "EditSDR is an Editor fit for a Shape Definition Representation which designates a Product Definition");

// Constructors
cls_STEPEdit_EditSDR.def(py::init<>());

// Fields

// Methods
cls_STEPEdit_EditSDR.def("Label", (TCollection_AsciiString (STEPEdit_EditSDR::*)() const) &STEPEdit_EditSDR::Label, "None");
cls_STEPEdit_EditSDR.def("Recognize", (Standard_Boolean (STEPEdit_EditSDR::*)(const opencascade::handle<IFSelect_EditForm> &) const) &STEPEdit_EditSDR::Recognize, "None", py::arg("form"));
cls_STEPEdit_EditSDR.def("StringValue", (opencascade::handle<TCollection_HAsciiString> (STEPEdit_EditSDR::*)(const opencascade::handle<IFSelect_EditForm> &, const Standard_Integer) const) &STEPEdit_EditSDR::StringValue, "None", py::arg("form"), py::arg("num"));
cls_STEPEdit_EditSDR.def("Apply", (Standard_Boolean (STEPEdit_EditSDR::*)(const opencascade::handle<IFSelect_EditForm> &, const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &) const) &STEPEdit_EditSDR::Apply, "None", py::arg("form"), py::arg("ent"), py::arg("model"));
cls_STEPEdit_EditSDR.def("Load", (Standard_Boolean (STEPEdit_EditSDR::*)(const opencascade::handle<IFSelect_EditForm> &, const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &) const) &STEPEdit_EditSDR::Load, "None", py::arg("form"), py::arg("ent"), py::arg("model"));
cls_STEPEdit_EditSDR.def_static("get_type_name_", (const char * (*)()) &STEPEdit_EditSDR::get_type_name, "None");
cls_STEPEdit_EditSDR.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &STEPEdit_EditSDR::get_type_descriptor, "None");
cls_STEPEdit_EditSDR.def("DynamicType", (const opencascade::handle<Standard_Type> & (STEPEdit_EditSDR::*)() const) &STEPEdit_EditSDR::DynamicType, "None");

// Enums

}