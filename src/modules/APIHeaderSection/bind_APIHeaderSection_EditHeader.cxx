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
#include <APIHeaderSection_EditHeader.hxx>
#include <Standard_Type.hxx>

void bind_APIHeaderSection_EditHeader(py::module &mod){

py::class_<APIHeaderSection_EditHeader, opencascade::handle<APIHeaderSection_EditHeader>, IFSelect_Editor> cls_APIHeaderSection_EditHeader(mod, "APIHeaderSection_EditHeader", "None");

// Constructors
cls_APIHeaderSection_EditHeader.def(py::init<>());

// Fields

// Methods
cls_APIHeaderSection_EditHeader.def("Label", (TCollection_AsciiString (APIHeaderSection_EditHeader::*)() const) &APIHeaderSection_EditHeader::Label, "None");
cls_APIHeaderSection_EditHeader.def("Recognize", (Standard_Boolean (APIHeaderSection_EditHeader::*)(const opencascade::handle<IFSelect_EditForm> &) const) &APIHeaderSection_EditHeader::Recognize, "None", py::arg("form"));
cls_APIHeaderSection_EditHeader.def("StringValue", (opencascade::handle<TCollection_HAsciiString> (APIHeaderSection_EditHeader::*)(const opencascade::handle<IFSelect_EditForm> &, const Standard_Integer) const) &APIHeaderSection_EditHeader::StringValue, "None", py::arg("form"), py::arg("num"));
cls_APIHeaderSection_EditHeader.def("Apply", (Standard_Boolean (APIHeaderSection_EditHeader::*)(const opencascade::handle<IFSelect_EditForm> &, const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &) const) &APIHeaderSection_EditHeader::Apply, "None", py::arg("form"), py::arg("ent"), py::arg("model"));
cls_APIHeaderSection_EditHeader.def("Load", (Standard_Boolean (APIHeaderSection_EditHeader::*)(const opencascade::handle<IFSelect_EditForm> &, const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &) const) &APIHeaderSection_EditHeader::Load, "None", py::arg("form"), py::arg("ent"), py::arg("model"));
cls_APIHeaderSection_EditHeader.def_static("get_type_name_", (const char * (*)()) &APIHeaderSection_EditHeader::get_type_name, "None");
cls_APIHeaderSection_EditHeader.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &APIHeaderSection_EditHeader::get_type_descriptor, "None");
cls_APIHeaderSection_EditHeader.def("DynamicType", (const opencascade::handle<Standard_Type> & (APIHeaderSection_EditHeader::*)() const) &APIHeaderSection_EditHeader::DynamicType, "None");

// Enums

}