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
#include <TDF_TagSource.hxx>
#include <TDF_Label.hxx>
#include <Standard_TypeDef.hxx>
#include <TDF_RelocationTable.hxx>
#include <Standard_Type.hxx>

void bind_TDF_TagSource(py::module &mod){

py::class_<TDF_TagSource, opencascade::handle<TDF_TagSource>, TDF_Attribute> cls_TDF_TagSource(mod, "TDF_TagSource", "This attribute manage a tag provider to create child labels of a given one.");

// Constructors
cls_TDF_TagSource.def(py::init<>());

// Fields

// Methods
cls_TDF_TagSource.def_static("GetID_", (const Standard_GUID & (*)()) &TDF_TagSource::GetID, "class methods =============");
cls_TDF_TagSource.def_static("Set_", (opencascade::handle<TDF_TagSource> (*)(const TDF_Label &)) &TDF_TagSource::Set, "Find, or create, a TagSource attribute. the TagSource attribute is returned.", py::arg("label"));
cls_TDF_TagSource.def_static("NewChild_", (TDF_Label (*)(const TDF_Label &)) &TDF_TagSource::NewChild, "Find (or create) a tagSource attribute located at <L> and make a new child label. TagSource methods =================", py::arg("L"));
cls_TDF_TagSource.def("NewTag", (Standard_Integer (TDF_TagSource::*)()) &TDF_TagSource::NewTag, "None");
cls_TDF_TagSource.def("NewChild", (TDF_Label (TDF_TagSource::*)()) &TDF_TagSource::NewChild, "None");
cls_TDF_TagSource.def("Get", (Standard_Integer (TDF_TagSource::*)() const) &TDF_TagSource::Get, "None");
cls_TDF_TagSource.def("Set", (void (TDF_TagSource::*)(const Standard_Integer)) &TDF_TagSource::Set, "TDF_Attribute methods =====================", py::arg("T"));
cls_TDF_TagSource.def("ID", (const Standard_GUID & (TDF_TagSource::*)() const) &TDF_TagSource::ID, "None");
cls_TDF_TagSource.def("Restore", (void (TDF_TagSource::*)(const opencascade::handle<TDF_Attribute> &)) &TDF_TagSource::Restore, "None", py::arg("with"));
cls_TDF_TagSource.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TDF_TagSource::*)() const) &TDF_TagSource::NewEmpty, "None");
cls_TDF_TagSource.def("Paste", (void (TDF_TagSource::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TDF_TagSource::Paste, "None", py::arg("Into"), py::arg("RT"));
cls_TDF_TagSource.def_static("get_type_name_", (const char * (*)()) &TDF_TagSource::get_type_name, "None");
cls_TDF_TagSource.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDF_TagSource::get_type_descriptor, "None");
cls_TDF_TagSource.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDF_TagSource::*)() const) &TDF_TagSource::DynamicType, "None");

// Enums

}