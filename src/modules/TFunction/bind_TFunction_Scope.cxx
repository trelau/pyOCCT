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
#include <Standard_Handle.hxx>
#include <TFunction_Scope.hxx>
#include <TDF_Label.hxx>
#include <Standard_GUID.hxx>
#include <Standard_TypeDef.hxx>
#include <TFunction_Logbook.hxx>
#include <TDF_RelocationTable.hxx>
#include <Standard_OStream.hxx>
#include <TFunction_DoubleMapOfIntegerLabel.hxx>
#include <Standard_Type.hxx>

void bind_TFunction_Scope(py::module &mod){

py::class_<TFunction_Scope, opencascade::handle<TFunction_Scope>, TDF_Attribute> cls_TFunction_Scope(mod, "TFunction_Scope", "Keeps a scope of functions.");

// Constructors
cls_TFunction_Scope.def(py::init<>());

// Fields

// Methods
cls_TFunction_Scope.def_static("Set_", (opencascade::handle<TFunction_Scope> (*)(const TDF_Label &)) &TFunction_Scope::Set, "Static methods ============== Finds or Creates a TFunction_Scope attribute at the root label accessed by <Access>. Returns the attribute.", py::arg("Access"));
cls_TFunction_Scope.def_static("GetID_", (const Standard_GUID & (*)()) &TFunction_Scope::GetID, "Returns the GUID for Scope attribute. Instant methods =============== Constructor (empty).");
cls_TFunction_Scope.def("AddFunction", (Standard_Boolean (TFunction_Scope::*)(const TDF_Label &)) &TFunction_Scope::AddFunction, "Adds a function to the scope of functions.", py::arg("L"));
cls_TFunction_Scope.def("RemoveFunction", (Standard_Boolean (TFunction_Scope::*)(const TDF_Label &)) &TFunction_Scope::RemoveFunction, "Removes a function from the scope of functions.", py::arg("L"));
cls_TFunction_Scope.def("RemoveFunction", (Standard_Boolean (TFunction_Scope::*)(const Standard_Integer)) &TFunction_Scope::RemoveFunction, "Removes a function from the scope of functions.", py::arg("ID"));
cls_TFunction_Scope.def("RemoveAllFunctions", (void (TFunction_Scope::*)()) &TFunction_Scope::RemoveAllFunctions, "Removes all functions from the scope of functions.");
cls_TFunction_Scope.def("HasFunction", (Standard_Boolean (TFunction_Scope::*)(const Standard_Integer) const) &TFunction_Scope::HasFunction, "Returns true if the function exists with such an ID.", py::arg("ID"));
cls_TFunction_Scope.def("HasFunction", (Standard_Boolean (TFunction_Scope::*)(const TDF_Label &) const) &TFunction_Scope::HasFunction, "Returns true if the label contains a function of this scope.", py::arg("L"));
cls_TFunction_Scope.def("GetFunction", (Standard_Integer (TFunction_Scope::*)(const TDF_Label &) const) &TFunction_Scope::GetFunction, "Returns an ID of the function.", py::arg("L"));
cls_TFunction_Scope.def("GetFunction", (const TDF_Label & (TFunction_Scope::*)(const Standard_Integer) const) &TFunction_Scope::GetFunction, "Returns the label of the function with this ID.", py::arg("ID"));
cls_TFunction_Scope.def("GetLogbook", (opencascade::handle<TFunction_Logbook> (TFunction_Scope::*)() const) &TFunction_Scope::GetLogbook, "Returns the Logbook used in TFunction_Driver methods. Implementation of Attribute methods ===================================");
cls_TFunction_Scope.def("ID", (const Standard_GUID & (TFunction_Scope::*)() const) &TFunction_Scope::ID, "None");
cls_TFunction_Scope.def("Restore", (void (TFunction_Scope::*)(const opencascade::handle<TDF_Attribute> &)) &TFunction_Scope::Restore, "None", py::arg("with"));
cls_TFunction_Scope.def("Paste", (void (TFunction_Scope::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TFunction_Scope::Paste, "None", py::arg("into"), py::arg("RT"));
cls_TFunction_Scope.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TFunction_Scope::*)() const) &TFunction_Scope::NewEmpty, "None");
cls_TFunction_Scope.def("Dump", (Standard_OStream & (TFunction_Scope::*)(Standard_OStream &) const) &TFunction_Scope::Dump, "None", py::arg("anOS"));
cls_TFunction_Scope.def("GetFunctions", (const TFunction_DoubleMapOfIntegerLabel & (TFunction_Scope::*)() const) &TFunction_Scope::GetFunctions, "Returns the scope of functions.");
cls_TFunction_Scope.def("ChangeFunctions", (TFunction_DoubleMapOfIntegerLabel & (TFunction_Scope::*)()) &TFunction_Scope::ChangeFunctions, "Returns the scope of functions for modification. Warning: Don't use this method if You are not sure what You do!");
cls_TFunction_Scope.def("SetFreeID", (void (TFunction_Scope::*)(const Standard_Integer)) &TFunction_Scope::SetFreeID, "None", py::arg("ID"));
cls_TFunction_Scope.def("GetFreeID", (Standard_Integer (TFunction_Scope::*)() const) &TFunction_Scope::GetFreeID, "None");
cls_TFunction_Scope.def_static("get_type_name_", (const char * (*)()) &TFunction_Scope::get_type_name, "None");
cls_TFunction_Scope.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TFunction_Scope::get_type_descriptor, "None");
cls_TFunction_Scope.def("DynamicType", (const opencascade::handle<Standard_Type> & (TFunction_Scope::*)() const) &TFunction_Scope::DynamicType, "None");

// Enums

}