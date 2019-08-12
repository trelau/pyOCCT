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
#include <Interface_Protocol.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Transient.hxx>
#include <Standard_Type.hxx>
#include <Interface_InterfaceModel.hxx>
#include <StepData_EDescr.hxx>
#include <StepData_ESDescr.hxx>
#include <StepData_ECDescr.hxx>
#include <TColStd_SequenceOfAsciiString.hxx>
#include <StepData_PDescr.hxx>
#include <StepData_Protocol.hxx>
#include <Interface_DataMapOfTransientInteger.hxx>
#include <NCollection_DataMap.hxx>
#include <TCollection_AsciiString.hxx>

void bind_StepData_Protocol(py::module &mod){

py::class_<StepData_Protocol, opencascade::handle<StepData_Protocol>, Interface_Protocol> cls_StepData_Protocol(mod, "StepData_Protocol", "Description of Basic Protocol for Step The class Protocol from StepData itself describes a default Protocol, which recognizes only UnknownEntities. Sub-classes will redefine CaseNumber and, if necessary, NbResources and Resources.");

// Constructors
cls_StepData_Protocol.def(py::init<>());

// Fields

// Methods
cls_StepData_Protocol.def("NbResources", (Standard_Integer (StepData_Protocol::*)() const) &StepData_Protocol::NbResources, "Gives the count of Protocols used as Resource (can be zero) Here, No resource");
cls_StepData_Protocol.def("Resource", (opencascade::handle<Interface_Protocol> (StepData_Protocol::*)(const Standard_Integer) const) &StepData_Protocol::Resource, "Returns a Resource, given a rank. Here, none", py::arg("num"));
cls_StepData_Protocol.def("CaseNumber", (Standard_Integer (StepData_Protocol::*)(const opencascade::handle<Standard_Transient> &) const) &StepData_Protocol::CaseNumber, "Returns a unique positive number for any recognized entity Redefined to work by calling both TypeNumber and, for a Described Entity (late binding) DescrNumber", py::arg("obj"));
cls_StepData_Protocol.def("TypeNumber", (Standard_Integer (StepData_Protocol::*)(const opencascade::handle<Standard_Type> &) const) &StepData_Protocol::TypeNumber, "Returns a Case Number, specific of each recognized Type Here, only Unknown Entity is recognized", py::arg("atype"));
cls_StepData_Protocol.def("SchemaName", (Standard_CString (StepData_Protocol::*)() const) &StepData_Protocol::SchemaName, "Returns the Schema Name attached to each class of Protocol To be redefined by each sub-class Here, SchemaName returns '(DEFAULT)' was C++ : return const");
cls_StepData_Protocol.def("NewModel", (opencascade::handle<Interface_InterfaceModel> (StepData_Protocol::*)() const) &StepData_Protocol::NewModel, "Creates an empty Model for Step Norm");
cls_StepData_Protocol.def("IsSuitableModel", (Standard_Boolean (StepData_Protocol::*)(const opencascade::handle<Interface_InterfaceModel> &) const) &StepData_Protocol::IsSuitableModel, "Returns True if <model> is a Model of Step Norm", py::arg("model"));
cls_StepData_Protocol.def("UnknownEntity", (opencascade::handle<Standard_Transient> (StepData_Protocol::*)() const) &StepData_Protocol::UnknownEntity, "Creates a new Unknown Entity for Step (UndefinedEntity)");
cls_StepData_Protocol.def("IsUnknownEntity", (Standard_Boolean (StepData_Protocol::*)(const opencascade::handle<Standard_Transient> &) const) &StepData_Protocol::IsUnknownEntity, "Returns True if <ent> is an Unknown Entity for the Norm, i.e. Type UndefinedEntity, status Unknown", py::arg("ent"));
cls_StepData_Protocol.def("DescrNumber", (Standard_Integer (StepData_Protocol::*)(const opencascade::handle<StepData_EDescr> &) const) &StepData_Protocol::DescrNumber, "Returns a unique positive CaseNumber for types described by an EDescr (late binding) Warning : TypeNumber and DescrNumber must give together a unique positive case number for each distinct case, type or descr", py::arg("adescr"));
cls_StepData_Protocol.def("AddDescr", (void (StepData_Protocol::*)(const opencascade::handle<StepData_EDescr> &, const Standard_Integer)) &StepData_Protocol::AddDescr, "Records an EDescr with its case number Also records its name for an ESDescr (simple type): an ESDescr is then used, for case number, or for type name", py::arg("adescr"), py::arg("CN"));
cls_StepData_Protocol.def("HasDescr", (Standard_Boolean (StepData_Protocol::*)() const) &StepData_Protocol::HasDescr, "Tells if a Protocol brings at least one ESDescr, i.e. if it defines at least one entity description by ESDescr mechanism");
cls_StepData_Protocol.def("Descr", (opencascade::handle<StepData_EDescr> (StepData_Protocol::*)(const Standard_Integer) const) &StepData_Protocol::Descr, "Returns the description attached to a case number, or null", py::arg("num"));
cls_StepData_Protocol.def("Descr", [](StepData_Protocol &self, const Standard_CString a0) -> opencascade::handle<StepData_EDescr> { return self.Descr(a0); });
cls_StepData_Protocol.def("Descr", (opencascade::handle<StepData_EDescr> (StepData_Protocol::*)(const Standard_CString, const Standard_Boolean) const) &StepData_Protocol::Descr, "Returns a description according to its name <anylevel> True (D) : for <me> and its resources <anylevel> False : for <me> only", py::arg("name"), py::arg("anylevel"));
cls_StepData_Protocol.def("ESDescr", [](StepData_Protocol &self, const Standard_CString a0) -> opencascade::handle<StepData_ESDescr> { return self.ESDescr(a0); });
cls_StepData_Protocol.def("ESDescr", (opencascade::handle<StepData_ESDescr> (StepData_Protocol::*)(const Standard_CString, const Standard_Boolean) const) &StepData_Protocol::ESDescr, "Idem as Descr but cast to simple description", py::arg("name"), py::arg("anylevel"));
cls_StepData_Protocol.def("ECDescr", [](StepData_Protocol &self, const TColStd_SequenceOfAsciiString & a0) -> opencascade::handle<StepData_ECDescr> { return self.ECDescr(a0); });
cls_StepData_Protocol.def("ECDescr", (opencascade::handle<StepData_ECDescr> (StepData_Protocol::*)(const TColStd_SequenceOfAsciiString &, const Standard_Boolean) const) &StepData_Protocol::ECDescr, "Returns a complex description according to list of names <anylevel> True (D) : for <me> and its resources <anylevel> False : for <me> only", py::arg("names"), py::arg("anylevel"));
cls_StepData_Protocol.def("AddPDescr", (void (StepData_Protocol::*)(const opencascade::handle<StepData_PDescr> &)) &StepData_Protocol::AddPDescr, "Records an PDescr", py::arg("pdescr"));
cls_StepData_Protocol.def("PDescr", [](StepData_Protocol &self, const Standard_CString a0) -> opencascade::handle<StepData_PDescr> { return self.PDescr(a0); });
cls_StepData_Protocol.def("PDescr", (opencascade::handle<StepData_PDescr> (StepData_Protocol::*)(const Standard_CString, const Standard_Boolean) const) &StepData_Protocol::PDescr, "Returns a parameter description according to its name <anylevel> True (D) : for <me> and its resources <anylevel> False : for <me> only", py::arg("name"), py::arg("anylevel"));
cls_StepData_Protocol.def("AddBasicDescr", (void (StepData_Protocol::*)(const opencascade::handle<StepData_ESDescr> &)) &StepData_Protocol::AddBasicDescr, "Records an ESDescr, intended to build complex descriptions", py::arg("esdescr"));
cls_StepData_Protocol.def("BasicDescr", [](StepData_Protocol &self, const Standard_CString a0) -> opencascade::handle<StepData_EDescr> { return self.BasicDescr(a0); });
cls_StepData_Protocol.def("BasicDescr", (opencascade::handle<StepData_EDescr> (StepData_Protocol::*)(const Standard_CString, const Standard_Boolean) const) &StepData_Protocol::BasicDescr, "Returns a basic description according to its name <anylevel> True (D) : for <me> and its resources <anylevel> False : for <me> only", py::arg("name"), py::arg("anylevel"));
cls_StepData_Protocol.def_static("get_type_name_", (const char * (*)()) &StepData_Protocol::get_type_name, "None");
cls_StepData_Protocol.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepData_Protocol::get_type_descriptor, "None");
cls_StepData_Protocol.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepData_Protocol::*)() const) &StepData_Protocol::DynamicType, "None");

// Enums

}