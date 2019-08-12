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
#include <TObj_TObject.hxx>
#include <TDF_Label.hxx>
#include <TObj_Object.hxx>
#include <TDF_RelocationTable.hxx>
#include <Standard_TypeDef.hxx>
#include <TDF_AttributeDelta.hxx>
#include <Standard_Type.hxx>

void bind_TObj_TObject(py::module &mod){

py::class_<TObj_TObject, opencascade::handle<TObj_TObject>, TDF_Attribute> cls_TObj_TObject(mod, "TObj_TObject", "Purpose: OCAF Attribute to storing objects (interfaces) of OCAF-based modelers in the OCAF tree. The persistency mechanism of the TObj_TObject allowes to save and restore objects of various subtypes without recompilation of the schema");

// Constructors
cls_TObj_TObject.def(py::init<>());

// Fields

// Methods
cls_TObj_TObject.def_static("GetID_", (const Standard_GUID & (*)()) &TObj_TObject::GetID, "This method is used in implementation of ID()");
cls_TObj_TObject.def("ID", (const Standard_GUID & (TObj_TObject::*)() const) &TObj_TObject::ID, "Returns the ID of TObj_TObject attribute.");
cls_TObj_TObject.def_static("Set_", (opencascade::handle<TObj_TObject> (*)(const TDF_Label &, const opencascade::handle<TObj_Object> &)) &TObj_TObject::Set, "Creates TObj_TObject attribute on given label", py::arg("theLabel"), py::arg("theElem"));
cls_TObj_TObject.def("Set", (void (TObj_TObject::*)(const opencascade::handle<TObj_Object> &)) &TObj_TObject::Set, "Sets the TObj_Object object", py::arg("theElem"));
cls_TObj_TObject.def("Get", (opencascade::handle<TObj_Object> (TObj_TObject::*)() const) &TObj_TObject::Get, "Returns the TObj_Object object");
cls_TObj_TObject.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TObj_TObject::*)() const) &TObj_TObject::NewEmpty, "Returns an new empty TObj_TObject attribute. It is used by the copy algorithm.");
cls_TObj_TObject.def("Restore", (void (TObj_TObject::*)(const opencascade::handle<TDF_Attribute> &)) &TObj_TObject::Restore, "Restores the backuped contents from <theWith> into this one. It is used when aborting a transaction.", py::arg("theWith"));
cls_TObj_TObject.def("Paste", (void (TObj_TObject::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TObj_TObject::Paste, "This method is used when copying an attribute from a source structure into a target structure.", py::arg("theInto"), py::arg("theRT"));
cls_TObj_TObject.def("BeforeForget", (void (TObj_TObject::*)()) &TObj_TObject::BeforeForget, "Tell TObj_Object to die, i.e. (myElem->IsAlive() == false) after that");
cls_TObj_TObject.def("AfterUndo", (Standard_Boolean (TObj_TObject::*)(const opencascade::handle<TDF_AttributeDelta> &, const Standard_Boolean)) &TObj_TObject::AfterUndo, "Tell TObj_Object to rise from the dead, i.e. (myElem->IsAlive() == true) after that", py::arg("anAttDelta"), py::arg("forceIt"));
cls_TObj_TObject.def_static("get_type_name_", (const char * (*)()) &TObj_TObject::get_type_name, "None");
cls_TObj_TObject.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TObj_TObject::get_type_descriptor, "None");
cls_TObj_TObject.def("DynamicType", (const opencascade::handle<Standard_Type> & (TObj_TObject::*)() const) &TObj_TObject::DynamicType, "None");

// Enums

}