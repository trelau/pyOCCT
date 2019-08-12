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
#include <XCAFDoc_Centroid.hxx>
#include <TDF_Label.hxx>
#include <gp_Pnt.hxx>
#include <Standard_TypeDef.hxx>
#include <TDF_RelocationTable.hxx>
#include <Standard_OStream.hxx>
#include <Standard_Type.hxx>

void bind_XCAFDoc_Centroid(py::module &mod){

py::class_<XCAFDoc_Centroid, opencascade::handle<XCAFDoc_Centroid>, TDF_Attribute> cls_XCAFDoc_Centroid(mod, "XCAFDoc_Centroid", "attribute to store centroid");

// Constructors
cls_XCAFDoc_Centroid.def(py::init<>());

// Fields

// Methods
cls_XCAFDoc_Centroid.def_static("GetID_", (const Standard_GUID & (*)()) &XCAFDoc_Centroid::GetID, "None");
cls_XCAFDoc_Centroid.def_static("Set_", (opencascade::handle<XCAFDoc_Centroid> (*)(const TDF_Label &, const gp_Pnt &)) &XCAFDoc_Centroid::Set, "Find, or create, a Location attribute and set it's value the Location attribute is returned. Location methods ===============", py::arg("label"), py::arg("pnt"));
cls_XCAFDoc_Centroid.def("Set", (void (XCAFDoc_Centroid::*)(const gp_Pnt &)) &XCAFDoc_Centroid::Set, "None", py::arg("pnt"));
cls_XCAFDoc_Centroid.def("Get", (gp_Pnt (XCAFDoc_Centroid::*)() const) &XCAFDoc_Centroid::Get, "None");
cls_XCAFDoc_Centroid.def_static("Get_", (Standard_Boolean (*)(const TDF_Label &, gp_Pnt &)) &XCAFDoc_Centroid::Get, "Returns point as argument returns false if no such attribute at the <label>", py::arg("label"), py::arg("pnt"));
cls_XCAFDoc_Centroid.def("ID", (const Standard_GUID & (XCAFDoc_Centroid::*)() const) &XCAFDoc_Centroid::ID, "None");
cls_XCAFDoc_Centroid.def("Restore", (void (XCAFDoc_Centroid::*)(const opencascade::handle<TDF_Attribute> &)) &XCAFDoc_Centroid::Restore, "None", py::arg("With"));
cls_XCAFDoc_Centroid.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XCAFDoc_Centroid::*)() const) &XCAFDoc_Centroid::NewEmpty, "None");
cls_XCAFDoc_Centroid.def("Paste", (void (XCAFDoc_Centroid::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &XCAFDoc_Centroid::Paste, "None", py::arg("Into"), py::arg("RT"));
cls_XCAFDoc_Centroid.def("Dump", (Standard_OStream & (XCAFDoc_Centroid::*)(Standard_OStream &) const) &XCAFDoc_Centroid::Dump, "None", py::arg("anOS"));
cls_XCAFDoc_Centroid.def_static("get_type_name_", (const char * (*)()) &XCAFDoc_Centroid::get_type_name, "None");
cls_XCAFDoc_Centroid.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XCAFDoc_Centroid::get_type_descriptor, "None");
cls_XCAFDoc_Centroid.def("DynamicType", (const opencascade::handle<Standard_Type> & (XCAFDoc_Centroid::*)() const) &XCAFDoc_Centroid::DynamicType, "None");

// Enums

}