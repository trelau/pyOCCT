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
#include <TDataStd_Name.hxx>
#include <TDF_Label.hxx>
#include <TCollection_ExtendedString.hxx>
#include <TDF_RelocationTable.hxx>
#include <Standard_OStream.hxx>
#include <Standard_Type.hxx>

void bind_TDataStd_Name(py::module &mod){

py::class_<TDataStd_Name, opencascade::handle<TDataStd_Name>, TDF_Attribute> cls_TDataStd_Name(mod, "TDataStd_Name", "Used to define a name attribute containing a string which specifies the name.");

// Constructors
cls_TDataStd_Name.def(py::init<>());

// Fields

// Methods
cls_TDataStd_Name.def_static("GetID_", (const Standard_GUID & (*)()) &TDataStd_Name::GetID, "class methods working on the name itself ======================================== Returns the GUID for name attributes.");
cls_TDataStd_Name.def_static("Set_", (opencascade::handle<TDataStd_Name> (*)(const TDF_Label &, const TCollection_ExtendedString &)) &TDataStd_Name::Set, "Creates (if does not exist) and sets the name in the name attribute. from any label <L> search in father labels (L is not concerned) the first name attribute.if found set it in <father>. class methods working on the name tree ====================================== Search in the whole TDF_Data the Name attribute which fit with <fullPath>. Returns True if found. Search under <currentLabel> a label which fit with <name>. Returns True if found. Shortcut which avoids building a ListOfExtendedStrin. Search in the whole TDF_Data the label which fit with name Returns True if found. tools methods to translate path <-> pathlist =========================================== move to draw For Draw test we may provide this tool method which convert a path in a sequence of string to call after the FindLabel methods. Example: if it's given 'Assembly:Part_1:Sketch_5' it will return in <pathlist> the list of 3 strings: 'Assembly','Part_1','Sketch_5'. move to draw from <pathlist> build the string path Name methods ============", py::arg("label"), py::arg("string"));
cls_TDataStd_Name.def_static("Set_", (opencascade::handle<TDataStd_Name> (*)(const TDF_Label &, const Standard_GUID &, const TCollection_ExtendedString &)) &TDataStd_Name::Set, "Finds, or creates, a Name attribute with explicit user defined <guid> and sets <string>. The Name attribute is returned.", py::arg("label"), py::arg("guid"), py::arg("string"));
cls_TDataStd_Name.def("Set", (void (TDataStd_Name::*)(const TCollection_ExtendedString &)) &TDataStd_Name::Set, "Sets <S> as name. Raises if <S> is not a valid name.", py::arg("S"));
cls_TDataStd_Name.def("SetID", (void (TDataStd_Name::*)(const Standard_GUID &)) &TDataStd_Name::SetID, "Sets the explicit user defined GUID to the attribute.", py::arg("guid"));
cls_TDataStd_Name.def("SetID", (void (TDataStd_Name::*)()) &TDataStd_Name::SetID, "Sets default GUID for the attribute.");
cls_TDataStd_Name.def("Get", (const TCollection_ExtendedString & (TDataStd_Name::*)() const) &TDataStd_Name::Get, "Returns the name contained in this name attribute.");
cls_TDataStd_Name.def("ID", (const Standard_GUID & (TDataStd_Name::*)() const) &TDataStd_Name::ID, "None");
cls_TDataStd_Name.def("Restore", (void (TDataStd_Name::*)(const opencascade::handle<TDF_Attribute> &)) &TDataStd_Name::Restore, "None", py::arg("with"));
cls_TDataStd_Name.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TDataStd_Name::*)() const) &TDataStd_Name::NewEmpty, "None");
cls_TDataStd_Name.def("Paste", (void (TDataStd_Name::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TDataStd_Name::Paste, "None", py::arg("into"), py::arg("RT"));
cls_TDataStd_Name.def("Dump", (Standard_OStream & (TDataStd_Name::*)(Standard_OStream &) const) &TDataStd_Name::Dump, "None", py::arg("anOS"));
cls_TDataStd_Name.def_static("get_type_name_", (const char * (*)()) &TDataStd_Name::get_type_name, "None");
cls_TDataStd_Name.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDataStd_Name::get_type_descriptor, "None");
cls_TDataStd_Name.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDataStd_Name::*)() const) &TDataStd_Name::DynamicType, "None");

// Enums

}