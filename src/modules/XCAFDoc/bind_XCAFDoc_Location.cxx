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
#include <XCAFDoc_Location.hxx>
#include <TDF_Label.hxx>
#include <TopLoc_Location.hxx>
#include <TDF_RelocationTable.hxx>
#include <Standard_Type.hxx>

void bind_XCAFDoc_Location(py::module &mod){

py::class_<XCAFDoc_Location, opencascade::handle<XCAFDoc_Location>, TDF_Attribute> cls_XCAFDoc_Location(mod, "XCAFDoc_Location", "attribute to store TopLoc_Location");

// Constructors
cls_XCAFDoc_Location.def(py::init<>());

// Fields

// Methods
cls_XCAFDoc_Location.def_static("GetID_", (const Standard_GUID & (*)()) &XCAFDoc_Location::GetID, "None");
cls_XCAFDoc_Location.def_static("Set_", (opencascade::handle<XCAFDoc_Location> (*)(const TDF_Label &, const TopLoc_Location &)) &XCAFDoc_Location::Set, "Find, or create, a Location attribute and set it's value the Location attribute is returned. Location methods ===============", py::arg("label"), py::arg("Loc"));
cls_XCAFDoc_Location.def("Set", (void (XCAFDoc_Location::*)(const TopLoc_Location &)) &XCAFDoc_Location::Set, "None", py::arg("Loc"));
cls_XCAFDoc_Location.def("Get", (const TopLoc_Location & (XCAFDoc_Location::*)() const) &XCAFDoc_Location::Get, "Returns True if there is a reference on the same label");
cls_XCAFDoc_Location.def("ID", (const Standard_GUID & (XCAFDoc_Location::*)() const) &XCAFDoc_Location::ID, "None");
cls_XCAFDoc_Location.def("Restore", (void (XCAFDoc_Location::*)(const opencascade::handle<TDF_Attribute> &)) &XCAFDoc_Location::Restore, "None", py::arg("With"));
cls_XCAFDoc_Location.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XCAFDoc_Location::*)() const) &XCAFDoc_Location::NewEmpty, "None");
cls_XCAFDoc_Location.def("Paste", (void (XCAFDoc_Location::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &XCAFDoc_Location::Paste, "None", py::arg("Into"), py::arg("RT"));
cls_XCAFDoc_Location.def_static("get_type_name_", (const char * (*)()) &XCAFDoc_Location::get_type_name, "None");
cls_XCAFDoc_Location.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XCAFDoc_Location::get_type_descriptor, "None");
cls_XCAFDoc_Location.def("DynamicType", (const opencascade::handle<Standard_Type> & (XCAFDoc_Location::*)() const) &XCAFDoc_Location::DynamicType, "None");

// Enums

}