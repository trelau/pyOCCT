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
#include <StepBasic_Document.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <Standard_TypeDef.hxx>
#include <StepBasic_DocumentType.hxx>
#include <StepBasic_CharacterizedObject.hxx>
#include <StepBasic_DocumentFile.hxx>
#include <Standard_Type.hxx>

void bind_StepBasic_DocumentFile(py::module &mod){

py::class_<StepBasic_DocumentFile, opencascade::handle<StepBasic_DocumentFile>, StepBasic_Document> cls_StepBasic_DocumentFile(mod, "StepBasic_DocumentFile", "Representation of STEP entity DocumentFile");

// Constructors
cls_StepBasic_DocumentFile.def(py::init<>());

// Fields

// Methods
cls_StepBasic_DocumentFile.def("Init", (void (StepBasic_DocumentFile::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_DocumentType> &, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_DocumentFile::Init, "Initialize all fields (own and inherited)", py::arg("aDocument_Id"), py::arg("aDocument_Name"), py::arg("hasDocument_Description"), py::arg("aDocument_Description"), py::arg("aDocument_Kind"), py::arg("aCharacterizedObject_Name"), py::arg("hasCharacterizedObject_Description"), py::arg("aCharacterizedObject_Description"));
cls_StepBasic_DocumentFile.def("CharacterizedObject", (opencascade::handle<StepBasic_CharacterizedObject> (StepBasic_DocumentFile::*)() const) &StepBasic_DocumentFile::CharacterizedObject, "Returns data for supertype CharacterizedObject");
cls_StepBasic_DocumentFile.def("SetCharacterizedObject", (void (StepBasic_DocumentFile::*)(const opencascade::handle<StepBasic_CharacterizedObject> &)) &StepBasic_DocumentFile::SetCharacterizedObject, "Set data for supertype CharacterizedObject", py::arg("CharacterizedObject"));
cls_StepBasic_DocumentFile.def_static("get_type_name_", (const char * (*)()) &StepBasic_DocumentFile::get_type_name, "None");
cls_StepBasic_DocumentFile.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_DocumentFile::get_type_descriptor, "None");
cls_StepBasic_DocumentFile.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_DocumentFile::*)() const) &StepBasic_DocumentFile::DynamicType, "None");

// Enums

}