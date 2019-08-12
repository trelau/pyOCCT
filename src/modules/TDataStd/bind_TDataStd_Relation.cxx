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
#include <TDataStd_Relation.hxx>
#include <TDF_Label.hxx>
#include <TCollection_ExtendedString.hxx>
#include <TDF_AttributeList.hxx>
#include <TDF_RelocationTable.hxx>
#include <Standard_OStream.hxx>
#include <Standard_Type.hxx>

void bind_TDataStd_Relation(py::module &mod){

py::class_<TDataStd_Relation, opencascade::handle<TDataStd_Relation>, TDF_Attribute> cls_TDataStd_Relation(mod, "TDataStd_Relation", "Relation attribute. ==================");

// Constructors
cls_TDataStd_Relation.def(py::init<>());

// Fields

// Methods
cls_TDataStd_Relation.def_static("GetID_", (const Standard_GUID & (*)()) &TDataStd_Relation::GetID, "class methods =============");
cls_TDataStd_Relation.def_static("Set_", (opencascade::handle<TDataStd_Relation> (*)(const TDF_Label &)) &TDataStd_Relation::Set, "Find, or create, an Relation attribute. Real methods ============", py::arg("label"));
cls_TDataStd_Relation.def("Name", (TCollection_ExtendedString (TDataStd_Relation::*)() const) &TDataStd_Relation::Name, "build and return the relation name");
cls_TDataStd_Relation.def("SetRelation", (void (TDataStd_Relation::*)(const TCollection_ExtendedString &)) &TDataStd_Relation::SetRelation, "None", py::arg("E"));
cls_TDataStd_Relation.def("GetRelation", (const TCollection_ExtendedString & (TDataStd_Relation::*)() const) &TDataStd_Relation::GetRelation, "None");
cls_TDataStd_Relation.def("GetVariables", (TDF_AttributeList & (TDataStd_Relation::*)()) &TDataStd_Relation::GetVariables, "None");
cls_TDataStd_Relation.def("ID", (const Standard_GUID & (TDataStd_Relation::*)() const) &TDataStd_Relation::ID, "None");
cls_TDataStd_Relation.def("Restore", (void (TDataStd_Relation::*)(const opencascade::handle<TDF_Attribute> &)) &TDataStd_Relation::Restore, "None", py::arg("With"));
cls_TDataStd_Relation.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TDataStd_Relation::*)() const) &TDataStd_Relation::NewEmpty, "None");
cls_TDataStd_Relation.def("Paste", (void (TDataStd_Relation::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TDataStd_Relation::Paste, "None", py::arg("Into"), py::arg("RT"));
cls_TDataStd_Relation.def("Dump", (Standard_OStream & (TDataStd_Relation::*)(Standard_OStream &) const) &TDataStd_Relation::Dump, "None", py::arg("anOS"));
cls_TDataStd_Relation.def_static("get_type_name_", (const char * (*)()) &TDataStd_Relation::get_type_name, "None");
cls_TDataStd_Relation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDataStd_Relation::get_type_descriptor, "None");
cls_TDataStd_Relation.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDataStd_Relation::*)() const) &TDataStd_Relation::DynamicType, "None");

// Enums

}