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
#include <IFSelect_SelectExtract.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Transient.hxx>
#include <Interface_InterfaceModel.hxx>
#include <TCollection_HAsciiString.hxx>
#include <TCollection_AsciiString.hxx>
#include <IGESSelect_SelectName.hxx>
#include <Standard_Type.hxx>

void bind_IGESSelect_SelectName(py::module &mod){

py::class_<IGESSelect_SelectName, opencascade::handle<IGESSelect_SelectName>, IFSelect_SelectExtract> cls_IGESSelect_SelectName(mod, "IGESSelect_SelectName", "Selects Entities which have a given name. Consider Property Name if present, else Short Label, but not the Subscript Number First version : keeps exact name Later : regular expression");

// Constructors
cls_IGESSelect_SelectName.def(py::init<>());

// Fields

// Methods
cls_IGESSelect_SelectName.def("Sort", (Standard_Boolean (IGESSelect_SelectName::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &) const) &IGESSelect_SelectName::Sort, "Returns True if Name of Entity complies with Name Filter", py::arg("rank"), py::arg("ent"), py::arg("model"));
cls_IGESSelect_SelectName.def("SetName", (void (IGESSelect_SelectName::*)(const opencascade::handle<TCollection_HAsciiString> &)) &IGESSelect_SelectName::SetName, "Sets a Name as a criterium : IGES Entities which have this name are kept (without regular expression, there should be at most one). <name> can be regarded as a Text Parameter", py::arg("name"));
cls_IGESSelect_SelectName.def("Name", (opencascade::handle<TCollection_HAsciiString> (IGESSelect_SelectName::*)() const) &IGESSelect_SelectName::Name, "Returns the Name used as Filter");
cls_IGESSelect_SelectName.def("ExtractLabel", (TCollection_AsciiString (IGESSelect_SelectName::*)() const) &IGESSelect_SelectName::ExtractLabel, "Returns the Selection criterium : 'IGES Entity, Name : <name>'");
cls_IGESSelect_SelectName.def_static("get_type_name_", (const char * (*)()) &IGESSelect_SelectName::get_type_name, "None");
cls_IGESSelect_SelectName.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSelect_SelectName::get_type_descriptor, "None");
cls_IGESSelect_SelectName.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSelect_SelectName::*)() const) &IGESSelect_SelectName::DynamicType, "None");

// Enums

}