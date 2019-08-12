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
#include <TDF_Attribute.hxx>
#include <Standard_GUID.hxx>
#include <Standard_Handle.hxx>
#include <XCAFDoc_Material.hxx>
#include <TDF_Label.hxx>
#include <TCollection_HAsciiString.hxx>
#include <Standard_TypeDef.hxx>
#include <TDF_RelocationTable.hxx>
#include <Standard_Type.hxx>

void bind_XCAFDoc_Material(py::module &mod){

py::class_<XCAFDoc_Material, opencascade::handle<XCAFDoc_Material>, TDF_Attribute> cls_XCAFDoc_Material(mod, "XCAFDoc_Material", "attribute to store material");

// Constructors
cls_XCAFDoc_Material.def(py::init<>());

// Fields

// Methods
cls_XCAFDoc_Material.def_static("GetID_", (const Standard_GUID & (*)()) &XCAFDoc_Material::GetID, "None");
cls_XCAFDoc_Material.def_static("Set_", (opencascade::handle<XCAFDoc_Material> (*)(const TDF_Label &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Real, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &)) &XCAFDoc_Material::Set, "None", py::arg("label"), py::arg("aName"), py::arg("aDescription"), py::arg("aDensity"), py::arg("aDensName"), py::arg("aDensValType"));
cls_XCAFDoc_Material.def("Set", (void (XCAFDoc_Material::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Real, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &)) &XCAFDoc_Material::Set, "None", py::arg("aName"), py::arg("aDescription"), py::arg("aDensity"), py::arg("aDensName"), py::arg("aDensValType"));
cls_XCAFDoc_Material.def("GetName", (opencascade::handle<TCollection_HAsciiString> (XCAFDoc_Material::*)() const) &XCAFDoc_Material::GetName, "None");
cls_XCAFDoc_Material.def("GetDescription", (opencascade::handle<TCollection_HAsciiString> (XCAFDoc_Material::*)() const) &XCAFDoc_Material::GetDescription, "None");
cls_XCAFDoc_Material.def("GetDensity", (Standard_Real (XCAFDoc_Material::*)() const) &XCAFDoc_Material::GetDensity, "None");
cls_XCAFDoc_Material.def("GetDensName", (opencascade::handle<TCollection_HAsciiString> (XCAFDoc_Material::*)() const) &XCAFDoc_Material::GetDensName, "None");
cls_XCAFDoc_Material.def("GetDensValType", (opencascade::handle<TCollection_HAsciiString> (XCAFDoc_Material::*)() const) &XCAFDoc_Material::GetDensValType, "None");
cls_XCAFDoc_Material.def("ID", (const Standard_GUID & (XCAFDoc_Material::*)() const) &XCAFDoc_Material::ID, "None");
cls_XCAFDoc_Material.def("Restore", (void (XCAFDoc_Material::*)(const opencascade::handle<TDF_Attribute> &)) &XCAFDoc_Material::Restore, "None", py::arg("With"));
cls_XCAFDoc_Material.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XCAFDoc_Material::*)() const) &XCAFDoc_Material::NewEmpty, "None");
cls_XCAFDoc_Material.def("Paste", (void (XCAFDoc_Material::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &XCAFDoc_Material::Paste, "None", py::arg("Into"), py::arg("RT"));
cls_XCAFDoc_Material.def_static("get_type_name_", (const char * (*)()) &XCAFDoc_Material::get_type_name, "None");
cls_XCAFDoc_Material.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XCAFDoc_Material::get_type_descriptor, "None");
cls_XCAFDoc_Material.def("DynamicType", (const opencascade::handle<Standard_Type> & (XCAFDoc_Material::*)() const) &XCAFDoc_Material::DynamicType, "None");

// Enums

}