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
#include <StepData_EDescr.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <StepData_PDescr.hxx>
#include <StepData_ESDescr.hxx>
#include <TCollection_AsciiString.hxx>
#include <StepData_Described.hxx>
#include <Standard_Type.hxx>
#include <TColStd_HArray1OfTransient.hxx>
#include <NCollection_DataMap.hxx>

void bind_StepData_ESDescr(py::module &mod){

py::class_<StepData_ESDescr, opencascade::handle<StepData_ESDescr>, StepData_EDescr> cls_StepData_ESDescr(mod, "StepData_ESDescr", "This class is intended to describe the authorized form for a Simple (not Plex) Entity, as a list of fields");

// Constructors
cls_StepData_ESDescr.def(py::init<const Standard_CString>(), py::arg("name"));

// Fields

// Methods
cls_StepData_ESDescr.def("SetNbFields", (void (StepData_ESDescr::*)(const Standard_Integer)) &StepData_ESDescr::SetNbFields, "Sets a new count of fields Each one is described by a PDescr", py::arg("nb"));
cls_StepData_ESDescr.def("SetField", (void (StepData_ESDescr::*)(const Standard_Integer, const Standard_CString, const opencascade::handle<StepData_PDescr> &)) &StepData_ESDescr::SetField, "Sets a PDescr to describe a field A Field is designated by its rank and name", py::arg("num"), py::arg("name"), py::arg("descr"));
cls_StepData_ESDescr.def("SetBase", (void (StepData_ESDescr::*)(const opencascade::handle<StepData_ESDescr> &)) &StepData_ESDescr::SetBase, "Sets an ESDescr as based on another one Hence, if there are inherited fields, the derived ESDescr cumulates all them, while the base just records its own ones", py::arg("base"));
cls_StepData_ESDescr.def("SetSuper", (void (StepData_ESDescr::*)(const opencascade::handle<StepData_ESDescr> &)) &StepData_ESDescr::SetSuper, "Sets an ESDescr as 'super-type'. Applies an a base (non derived) ESDescr", py::arg("super"));
cls_StepData_ESDescr.def("TypeName", (Standard_CString (StepData_ESDescr::*)() const) &StepData_ESDescr::TypeName, "Returns the type name given at creation time");
cls_StepData_ESDescr.def("StepType", (const TCollection_AsciiString & (StepData_ESDescr::*)() const) &StepData_ESDescr::StepType, "Returns the type name as an AsciiString");
cls_StepData_ESDescr.def("Base", (opencascade::handle<StepData_ESDescr> (StepData_ESDescr::*)() const) &StepData_ESDescr::Base, "Returns the basic ESDescr, null if <me> is not derived");
cls_StepData_ESDescr.def("Super", (opencascade::handle<StepData_ESDescr> (StepData_ESDescr::*)() const) &StepData_ESDescr::Super, "Returns the super-type ESDescr, null if <me> is root");
cls_StepData_ESDescr.def("IsSub", (Standard_Boolean (StepData_ESDescr::*)(const opencascade::handle<StepData_ESDescr> &) const) &StepData_ESDescr::IsSub, "Tells if <me> is sub-type of (or equal to) another one", py::arg("other"));
cls_StepData_ESDescr.def("NbFields", (Standard_Integer (StepData_ESDescr::*)() const) &StepData_ESDescr::NbFields, "Returns the count of fields");
cls_StepData_ESDescr.def("Rank", (Standard_Integer (StepData_ESDescr::*)(const Standard_CString) const) &StepData_ESDescr::Rank, "Returns the rank of a field from its name. 0 if unknown", py::arg("name"));
cls_StepData_ESDescr.def("Name", (Standard_CString (StepData_ESDescr::*)(const Standard_Integer) const) &StepData_ESDescr::Name, "Returns the name of a field from its rank. empty if outofrange", py::arg("num"));
cls_StepData_ESDescr.def("Field", (opencascade::handle<StepData_PDescr> (StepData_ESDescr::*)(const Standard_Integer) const) &StepData_ESDescr::Field, "Returns the PDescr for the field <num> (or Null)", py::arg("num"));
cls_StepData_ESDescr.def("NamedField", (opencascade::handle<StepData_PDescr> (StepData_ESDescr::*)(const Standard_CString) const) &StepData_ESDescr::NamedField, "Returns the PDescr for the field named <name> (or Null)", py::arg("name"));
cls_StepData_ESDescr.def("Matches", (Standard_Boolean (StepData_ESDescr::*)(const Standard_CString) const) &StepData_ESDescr::Matches, "Tells if a ESDescr matches a step type : exact or super type", py::arg("steptype"));
cls_StepData_ESDescr.def("IsComplex", (Standard_Boolean (StepData_ESDescr::*)() const) &StepData_ESDescr::IsComplex, "Returns False");
cls_StepData_ESDescr.def("NewEntity", (opencascade::handle<StepData_Described> (StepData_ESDescr::*)() const) &StepData_ESDescr::NewEntity, "Creates a described entity (i.e. a simple one)");
cls_StepData_ESDescr.def_static("get_type_name_", (const char * (*)()) &StepData_ESDescr::get_type_name, "None");
cls_StepData_ESDescr.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepData_ESDescr::get_type_descriptor, "None");
cls_StepData_ESDescr.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepData_ESDescr::*)() const) &StepData_ESDescr::DynamicType, "None");

// Enums

}