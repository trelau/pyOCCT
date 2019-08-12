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
#include <TDataStd_Integer.hxx>
#include <TDF_Label.hxx>
#include <Standard_TypeDef.hxx>
#include <TDF_RelocationTable.hxx>
#include <Standard_OStream.hxx>
#include <Standard_Type.hxx>

void bind_TDataStd_Integer(py::module &mod){

py::class_<TDataStd_Integer, opencascade::handle<TDataStd_Integer>, TDF_Attribute> cls_TDataStd_Integer(mod, "TDataStd_Integer", "The basis to define an integer attribute.");

// Constructors
cls_TDataStd_Integer.def(py::init<>());

// Fields

// Methods
cls_TDataStd_Integer.def_static("GetID_", (const Standard_GUID & (*)()) &TDataStd_Integer::GetID, "class methods ============= Returns the GUID for integers.");
cls_TDataStd_Integer.def_static("Set_", (opencascade::handle<TDataStd_Integer> (*)(const TDF_Label &, const Standard_Integer)) &TDataStd_Integer::Set, "Finds, or creates, an Integer attribute and sets <value> the Integer attribute is returned.", py::arg("label"), py::arg("value"));
cls_TDataStd_Integer.def_static("Set_", (opencascade::handle<TDataStd_Integer> (*)(const TDF_Label &, const Standard_GUID &, const Standard_Integer)) &TDataStd_Integer::Set, "Finds, or creates, an Integer attribute with explicit user defined <guid> and sets <value>. The Integer attribute is returned.", py::arg("label"), py::arg("guid"), py::arg("value"));
cls_TDataStd_Integer.def("Set", (void (TDataStd_Integer::*)(const Standard_Integer)) &TDataStd_Integer::Set, "Integer methods ===============", py::arg("V"));
cls_TDataStd_Integer.def("SetID", (void (TDataStd_Integer::*)(const Standard_GUID &)) &TDataStd_Integer::SetID, "Sets the explicit GUID (user defined) for the attribute.", py::arg("guid"));
cls_TDataStd_Integer.def("SetID", (void (TDataStd_Integer::*)()) &TDataStd_Integer::SetID, "Sets default GUID for the attribute.");
cls_TDataStd_Integer.def("Get", (Standard_Integer (TDataStd_Integer::*)() const) &TDataStd_Integer::Get, "Returns the integer value contained in the attribute.");
cls_TDataStd_Integer.def("IsCaptured", (Standard_Boolean (TDataStd_Integer::*)() const) &TDataStd_Integer::IsCaptured, "Returns True if there is a reference on the same label");
cls_TDataStd_Integer.def("ID", (const Standard_GUID & (TDataStd_Integer::*)() const) &TDataStd_Integer::ID, "None");
cls_TDataStd_Integer.def("Restore", (void (TDataStd_Integer::*)(const opencascade::handle<TDF_Attribute> &)) &TDataStd_Integer::Restore, "None", py::arg("With"));
cls_TDataStd_Integer.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TDataStd_Integer::*)() const) &TDataStd_Integer::NewEmpty, "None");
cls_TDataStd_Integer.def("Paste", (void (TDataStd_Integer::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TDataStd_Integer::Paste, "None", py::arg("Into"), py::arg("RT"));
cls_TDataStd_Integer.def("Dump", (Standard_OStream & (TDataStd_Integer::*)(Standard_OStream &) const) &TDataStd_Integer::Dump, "None", py::arg("anOS"));
cls_TDataStd_Integer.def_static("get_type_name_", (const char * (*)()) &TDataStd_Integer::get_type_name, "None");
cls_TDataStd_Integer.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDataStd_Integer::get_type_descriptor, "None");
cls_TDataStd_Integer.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDataStd_Integer::*)() const) &TDataStd_Integer::DynamicType, "None");

// Enums

}