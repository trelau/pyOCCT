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
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <XCAFDoc_Volume.hxx>
#include <TDF_Label.hxx>
#include <TDF_RelocationTable.hxx>
#include <Standard_OStream.hxx>
#include <Standard_Type.hxx>

void bind_XCAFDoc_Volume(py::module &mod){

py::class_<XCAFDoc_Volume, opencascade::handle<XCAFDoc_Volume>, TDF_Attribute> cls_XCAFDoc_Volume(mod, "XCAFDoc_Volume", "attribute to store volume");

// Constructors
cls_XCAFDoc_Volume.def(py::init<>());

// Fields

// Methods
cls_XCAFDoc_Volume.def_static("GetID_", (const Standard_GUID & (*)()) &XCAFDoc_Volume::GetID, "None");
cls_XCAFDoc_Volume.def("ID", (const Standard_GUID & (XCAFDoc_Volume::*)() const) &XCAFDoc_Volume::ID, "None");
cls_XCAFDoc_Volume.def("Set", (void (XCAFDoc_Volume::*)(const Standard_Real)) &XCAFDoc_Volume::Set, "Sets a value of volume", py::arg("vol"));
cls_XCAFDoc_Volume.def_static("Set_", (opencascade::handle<XCAFDoc_Volume> (*)(const TDF_Label &, const Standard_Real)) &XCAFDoc_Volume::Set, "Find, or create, an Volume attribute and set its value", py::arg("label"), py::arg("vol"));
cls_XCAFDoc_Volume.def("Get", (Standard_Real (XCAFDoc_Volume::*)() const) &XCAFDoc_Volume::Get, "None");
cls_XCAFDoc_Volume.def_static("Get_", [](const TDF_Label & label, Standard_Real & vol){ Standard_Boolean rv = XCAFDoc_Volume::Get(label, vol); return std::tuple<Standard_Boolean, Standard_Real &>(rv, vol); }, "Returns volume as argument returns false if no such attribute at the <label>", py::arg("label"), py::arg("vol"));
cls_XCAFDoc_Volume.def("Restore", (void (XCAFDoc_Volume::*)(const opencascade::handle<TDF_Attribute> &)) &XCAFDoc_Volume::Restore, "None", py::arg("With"));
cls_XCAFDoc_Volume.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XCAFDoc_Volume::*)() const) &XCAFDoc_Volume::NewEmpty, "None");
cls_XCAFDoc_Volume.def("Paste", (void (XCAFDoc_Volume::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &XCAFDoc_Volume::Paste, "None", py::arg("Into"), py::arg("RT"));
cls_XCAFDoc_Volume.def("Dump", (Standard_OStream & (XCAFDoc_Volume::*)(Standard_OStream &) const) &XCAFDoc_Volume::Dump, "None", py::arg("anOS"));
cls_XCAFDoc_Volume.def_static("get_type_name_", (const char * (*)()) &XCAFDoc_Volume::get_type_name, "None");
cls_XCAFDoc_Volume.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XCAFDoc_Volume::get_type_descriptor, "None");
cls_XCAFDoc_Volume.def("DynamicType", (const opencascade::handle<Standard_Type> & (XCAFDoc_Volume::*)() const) &XCAFDoc_Volume::DynamicType, "None");

// Enums

}