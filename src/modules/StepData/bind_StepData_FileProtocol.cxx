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
#include <StepData_Protocol.hxx>
#include <Standard_Handle.hxx>
#include <Standard_TypeDef.hxx>
#include <Interface_Protocol.hxx>
#include <Standard_Type.hxx>
#include <Interface_Graph.hxx>
#include <Interface_Check.hxx>
#include <StepData_FileProtocol.hxx>
#include <TColStd_SequenceOfTransient.hxx>

void bind_StepData_FileProtocol(py::module &mod){

py::class_<StepData_FileProtocol, opencascade::handle<StepData_FileProtocol>, StepData_Protocol> cls_StepData_FileProtocol(mod, "StepData_FileProtocol", "A FileProtocol is defined as the addition of several already existing Protocols. It corresponds to the definition of a SchemaName with several Names, each one being attached to a specific Protocol. Thus, a File defined with a compound Schema is processed as any other one, once built the equivalent compound Protocol, a FileProtocol");

// Constructors
cls_StepData_FileProtocol.def(py::init<>());

// Fields

// Methods
cls_StepData_FileProtocol.def("Add", (void (StepData_FileProtocol::*)(const opencascade::handle<StepData_Protocol> &)) &StepData_FileProtocol::Add, "Adds a Protocol to the definition list of the FileProtocol But ensures that each class of Protocol is present only once in this list", py::arg("protocol"));
cls_StepData_FileProtocol.def("NbResources", (Standard_Integer (StepData_FileProtocol::*)() const) &StepData_FileProtocol::NbResources, "Gives the count of Protocols used as Resource (can be zero) i.e. the count of Protocol recorded by calling the method Add");
cls_StepData_FileProtocol.def("Resource", (opencascade::handle<Interface_Protocol> (StepData_FileProtocol::*)(const Standard_Integer) const) &StepData_FileProtocol::Resource, "Returns a Resource, given a rank. Here, rank of calling Add", py::arg("num"));
cls_StepData_FileProtocol.def("TypeNumber", (Standard_Integer (StepData_FileProtocol::*)(const opencascade::handle<Standard_Type> &) const) &StepData_FileProtocol::TypeNumber, "Returns a Case Number, specific of each recognized Type Here, NO Type at all is recognized properly : all Types are recognized by the resources", py::arg("atype"));
cls_StepData_FileProtocol.def("GlobalCheck", (Standard_Boolean (StepData_FileProtocol::*)(const Interface_Graph &, opencascade::handle<Interface_Check> &) const) &StepData_FileProtocol::GlobalCheck, "Calls GlobalCheck for each of its recorded ressources", py::arg("G"), py::arg("ach"));
cls_StepData_FileProtocol.def("SchemaName", (Standard_CString (StepData_FileProtocol::*)() const) &StepData_FileProtocol::SchemaName, "Returns the Schema Name attached to each class of Protocol To be redefined by each sub-class Here, SchemaName returns '' (empty String) was C++ : return const");
cls_StepData_FileProtocol.def_static("get_type_name_", (const char * (*)()) &StepData_FileProtocol::get_type_name, "None");
cls_StepData_FileProtocol.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepData_FileProtocol::get_type_descriptor, "None");
cls_StepData_FileProtocol.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepData_FileProtocol::*)() const) &StepData_FileProtocol::DynamicType, "None");

// Enums

}