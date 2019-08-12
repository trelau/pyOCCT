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
#include <XCAFDoc_Area.hxx>
#include <TDF_Label.hxx>
#include <TDF_RelocationTable.hxx>
#include <Standard_OStream.hxx>
#include <Standard_Type.hxx>

void bind_XCAFDoc_Area(py::module &mod){

py::class_<XCAFDoc_Area, opencascade::handle<XCAFDoc_Area>, TDF_Attribute> cls_XCAFDoc_Area(mod, "XCAFDoc_Area", "attribute to store area");

// Constructors
cls_XCAFDoc_Area.def(py::init<>());

// Fields

// Methods
cls_XCAFDoc_Area.def_static("GetID_", (const Standard_GUID & (*)()) &XCAFDoc_Area::GetID, "None");
cls_XCAFDoc_Area.def("ID", (const Standard_GUID & (XCAFDoc_Area::*)() const) &XCAFDoc_Area::ID, "None");
cls_XCAFDoc_Area.def("Set", (void (XCAFDoc_Area::*)(const Standard_Real)) &XCAFDoc_Area::Set, "Sets a value of volume", py::arg("vol"));
cls_XCAFDoc_Area.def_static("Set_", (opencascade::handle<XCAFDoc_Area> (*)(const TDF_Label &, const Standard_Real)) &XCAFDoc_Area::Set, "Find, or create, an Area attribute and set its value", py::arg("label"), py::arg("area"));
cls_XCAFDoc_Area.def("Get", (Standard_Real (XCAFDoc_Area::*)() const) &XCAFDoc_Area::Get, "None");
cls_XCAFDoc_Area.def_static("Get_", [](const TDF_Label & label, Standard_Real & area){ Standard_Boolean rv = XCAFDoc_Area::Get(label, area); return std::tuple<Standard_Boolean, Standard_Real &>(rv, area); }, "Returns volume of area as argument and succes status returns false if no such attribute at the <label>", py::arg("label"), py::arg("area"));
cls_XCAFDoc_Area.def("Restore", (void (XCAFDoc_Area::*)(const opencascade::handle<TDF_Attribute> &)) &XCAFDoc_Area::Restore, "None", py::arg("With"));
cls_XCAFDoc_Area.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XCAFDoc_Area::*)() const) &XCAFDoc_Area::NewEmpty, "None");
cls_XCAFDoc_Area.def("Paste", (void (XCAFDoc_Area::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &XCAFDoc_Area::Paste, "None", py::arg("Into"), py::arg("RT"));
cls_XCAFDoc_Area.def("Dump", (Standard_OStream & (XCAFDoc_Area::*)(Standard_OStream &) const) &XCAFDoc_Area::Dump, "None", py::arg("anOS"));
cls_XCAFDoc_Area.def_static("get_type_name_", (const char * (*)()) &XCAFDoc_Area::get_type_name, "None");
cls_XCAFDoc_Area.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XCAFDoc_Area::get_type_descriptor, "None");
cls_XCAFDoc_Area.def("DynamicType", (const opencascade::handle<Standard_Type> & (XCAFDoc_Area::*)() const) &XCAFDoc_Area::DynamicType, "None");

// Enums

}