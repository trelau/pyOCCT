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
#include <STEPEdit_EditContext.hxx>
#include <Standard_Type.hxx>

void bind_STEPEdit_EditContext(py::module &mod){

py::class_<STEPEdit_EditContext, opencascade::handle<STEPEdit_EditContext>, IFSelect_Editor> cls_STEPEdit_EditContext(mod, "STEPEdit_EditContext", "EditContext is an Editor fit for Product Definition Context (one per Model) , i.e. : - ProductDefinition - ApplicationProtocolDefinition - ProductRelatedProductCategory");

// Constructors
cls_STEPEdit_EditContext.def(py::init<>());

// Fields

// Methods
cls_STEPEdit_EditContext.def("Label", (TCollection_AsciiString (STEPEdit_EditContext::*)() const) &STEPEdit_EditContext::Label, "None");
cls_STEPEdit_EditContext.def("Recognize", (Standard_Boolean (STEPEdit_EditContext::*)(const opencascade::handle<IFSelect_EditForm> &) const) &STEPEdit_EditContext::Recognize, "None", py::arg("form"));
cls_STEPEdit_EditContext.def("StringValue", (opencascade::handle<TCollection_HAsciiString> (STEPEdit_EditContext::*)(const opencascade::handle<IFSelect_EditForm> &, const Standard_Integer) const) &STEPEdit_EditContext::StringValue, "None", py::arg("form"), py::arg("num"));
cls_STEPEdit_EditContext.def("Apply", (Standard_Boolean (STEPEdit_EditContext::*)(const opencascade::handle<IFSelect_EditForm> &, const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &) const) &STEPEdit_EditContext::Apply, "None", py::arg("form"), py::arg("ent"), py::arg("model"));
cls_STEPEdit_EditContext.def("Load", (Standard_Boolean (STEPEdit_EditContext::*)(const opencascade::handle<IFSelect_EditForm> &, const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &) const) &STEPEdit_EditContext::Load, "None", py::arg("form"), py::arg("ent"), py::arg("model"));
cls_STEPEdit_EditContext.def_static("get_type_name_", (const char * (*)()) &STEPEdit_EditContext::get_type_name, "None");
cls_STEPEdit_EditContext.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &STEPEdit_EditContext::get_type_descriptor, "None");
cls_STEPEdit_EditContext.def("DynamicType", (const opencascade::handle<Standard_Type> & (STEPEdit_EditContext::*)() const) &STEPEdit_EditContext::DynamicType, "None");

// Enums

}