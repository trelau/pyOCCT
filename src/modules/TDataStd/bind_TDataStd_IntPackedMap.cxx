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
#include <TDataStd_DeltaOnModificationOfIntPackedMap.hxx>
#include <Standard_Handle.hxx>
#include <TDataStd_IntPackedMap.hxx>
#include <Standard_Type.hxx>
#include <Standard_GUID.hxx>
#include <TDF_Label.hxx>
#include <Standard_TypeDef.hxx>
#include <TColStd_HPackedMapOfInteger.hxx>
#include <TColStd_PackedMapOfInteger.hxx>
#include <TDF_RelocationTable.hxx>
#include <Standard_OStream.hxx>
#include <TDF_DeltaOnModification.hxx>

void bind_TDataStd_IntPackedMap(py::module &mod){

py::class_<TDataStd_IntPackedMap, opencascade::handle<TDataStd_IntPackedMap>, TDF_Attribute> cls_TDataStd_IntPackedMap(mod, "TDataStd_IntPackedMap", "Attribute for storing TColStd_PackedMapOfInteger");

// Constructors
cls_TDataStd_IntPackedMap.def(py::init<>());

// Fields

// Methods
cls_TDataStd_IntPackedMap.def_static("get_type_name_", (const char * (*)()) &TDataStd_IntPackedMap::get_type_name, "None");
cls_TDataStd_IntPackedMap.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDataStd_IntPackedMap::get_type_descriptor, "None");
cls_TDataStd_IntPackedMap.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDataStd_IntPackedMap::*)() const) &TDataStd_IntPackedMap::DynamicType, "None");
cls_TDataStd_IntPackedMap.def_static("GetID_", (const Standard_GUID & (*)()) &TDataStd_IntPackedMap::GetID, "class methods ============= Returns the GUID of the attribute.");
cls_TDataStd_IntPackedMap.def_static("Set_", [](const TDF_Label & a0) -> opencascade::handle<TDataStd_IntPackedMap> { return TDataStd_IntPackedMap::Set(a0); });
cls_TDataStd_IntPackedMap.def_static("Set_", (opencascade::handle<TDataStd_IntPackedMap> (*)(const TDF_Label &, const Standard_Boolean)) &TDataStd_IntPackedMap::Set, "Finds or creates an integer map attribute on the given label. If <isDelta> == False, DefaultDeltaOnModification is used. If <isDelta> == True, DeltaOnModification of the current attribute is used. If attribute is already set, input parameter <isDelta> is refused and the found attribute returned. Attribute methods ===================", py::arg("label"), py::arg("isDelta"));
cls_TDataStd_IntPackedMap.def("ChangeMap", (Standard_Boolean (TDataStd_IntPackedMap::*)(const opencascade::handle<TColStd_HPackedMapOfInteger> &)) &TDataStd_IntPackedMap::ChangeMap, "None", py::arg("theMap"));
cls_TDataStd_IntPackedMap.def("ChangeMap", (Standard_Boolean (TDataStd_IntPackedMap::*)(const TColStd_PackedMapOfInteger &)) &TDataStd_IntPackedMap::ChangeMap, "None", py::arg("theMap"));
cls_TDataStd_IntPackedMap.def("GetMap", (const TColStd_PackedMapOfInteger & (TDataStd_IntPackedMap::*)() const) &TDataStd_IntPackedMap::GetMap, "None");
cls_TDataStd_IntPackedMap.def("GetHMap", (const opencascade::handle<TColStd_HPackedMapOfInteger> & (TDataStd_IntPackedMap::*)() const) &TDataStd_IntPackedMap::GetHMap, "None");
cls_TDataStd_IntPackedMap.def("Clear", (Standard_Boolean (TDataStd_IntPackedMap::*)()) &TDataStd_IntPackedMap::Clear, "None");
cls_TDataStd_IntPackedMap.def("Add", (Standard_Boolean (TDataStd_IntPackedMap::*)(const Standard_Integer)) &TDataStd_IntPackedMap::Add, "None", py::arg("theKey"));
cls_TDataStd_IntPackedMap.def("Remove", (Standard_Boolean (TDataStd_IntPackedMap::*)(const Standard_Integer)) &TDataStd_IntPackedMap::Remove, "None", py::arg("theKey"));
cls_TDataStd_IntPackedMap.def("Contains", (Standard_Boolean (TDataStd_IntPackedMap::*)(const Standard_Integer) const) &TDataStd_IntPackedMap::Contains, "None", py::arg("theKey"));
cls_TDataStd_IntPackedMap.def("Extent", (Standard_Integer (TDataStd_IntPackedMap::*)() const) &TDataStd_IntPackedMap::Extent, "None");
cls_TDataStd_IntPackedMap.def("IsEmpty", (Standard_Boolean (TDataStd_IntPackedMap::*)() const) &TDataStd_IntPackedMap::IsEmpty, "None");
cls_TDataStd_IntPackedMap.def("GetDelta", (Standard_Boolean (TDataStd_IntPackedMap::*)() const) &TDataStd_IntPackedMap::GetDelta, "None");
cls_TDataStd_IntPackedMap.def("SetDelta", (void (TDataStd_IntPackedMap::*)(const Standard_Boolean)) &TDataStd_IntPackedMap::SetDelta, "for internal use only!", py::arg("isDelta"));
cls_TDataStd_IntPackedMap.def("ID", (const Standard_GUID & (TDataStd_IntPackedMap::*)() const) &TDataStd_IntPackedMap::ID, "None");
cls_TDataStd_IntPackedMap.def("Restore", (void (TDataStd_IntPackedMap::*)(const opencascade::handle<TDF_Attribute> &)) &TDataStd_IntPackedMap::Restore, "None", py::arg("with"));
cls_TDataStd_IntPackedMap.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TDataStd_IntPackedMap::*)() const) &TDataStd_IntPackedMap::NewEmpty, "None");
cls_TDataStd_IntPackedMap.def("Paste", (void (TDataStd_IntPackedMap::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TDataStd_IntPackedMap::Paste, "None", py::arg("into"), py::arg("RT"));
cls_TDataStd_IntPackedMap.def("Dump", (Standard_OStream & (TDataStd_IntPackedMap::*)(Standard_OStream &) const) &TDataStd_IntPackedMap::Dump, "None", py::arg("anOS"));
cls_TDataStd_IntPackedMap.def("DeltaOnModification", (opencascade::handle<TDF_DeltaOnModification> (TDataStd_IntPackedMap::*)(const opencascade::handle<TDF_Attribute> &) const) &TDataStd_IntPackedMap::DeltaOnModification, "Makes a DeltaOnModification between <me> and <anOldAttribute>.", py::arg("anOldAttribute"));

// Enums

}