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
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <Interface_Protocol.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Type.hxx>
#include <Interface_Graph.hxx>
#include <Interface_Check.hxx>
#include <Interface_InterfaceModel.hxx>

void bind_Interface_Protocol(py::module &mod){

py::class_<Interface_Protocol, opencascade::handle<Interface_Protocol>, Standard_Transient> cls_Interface_Protocol(mod, "Interface_Protocol", "General description of Interface Protocols. A Protocol defines a set of Entity types. This class provides also the notion of Active Protocol, as a working context, defined once then exploited by various Tools and Libraries.");

// Fields

// Methods
cls_Interface_Protocol.def_static("Active_", (opencascade::handle<Interface_Protocol> (*)()) &Interface_Protocol::Active, "Returns the Active Protocol, if defined (else, returns a Null Handle, which means 'no defined active protocol')");
cls_Interface_Protocol.def_static("SetActive_", (void (*)(const opencascade::handle<Interface_Protocol> &)) &Interface_Protocol::SetActive, "Sets a given Protocol to be the Active one (for the users of Active, see just above). Applies to every sub-type of Protocol", py::arg("aprotocol"));
cls_Interface_Protocol.def_static("ClearActive_", (void (*)()) &Interface_Protocol::ClearActive, "Erases the Active Protocol (hence it becomes undefined)");
cls_Interface_Protocol.def("NbResources", (Standard_Integer (Interface_Protocol::*)() const) &Interface_Protocol::NbResources, "Returns count of Protocol used as Resources (level one)");
cls_Interface_Protocol.def("Resource", (opencascade::handle<Interface_Protocol> (Interface_Protocol::*)(const Standard_Integer) const) &Interface_Protocol::Resource, "Returns a Resource, given its rank (between 1 and NbResources)", py::arg("num"));
cls_Interface_Protocol.def("CaseNumber", (Standard_Integer (Interface_Protocol::*)(const opencascade::handle<Standard_Transient> &) const) &Interface_Protocol::CaseNumber, "Returns a unique positive CaseNumber for each Recognized Object. By default, recognition is based on Type(1) By default, calls the following one which is deferred.", py::arg("obj"));
cls_Interface_Protocol.def("IsDynamicType", (Standard_Boolean (Interface_Protocol::*)(const opencascade::handle<Standard_Transient> &) const) &Interface_Protocol::IsDynamicType, "Returns True if type of <obj> is that defined from CDL This is the default but it may change according implementation", py::arg("obj"));
cls_Interface_Protocol.def("NbTypes", (Standard_Integer (Interface_Protocol::*)(const opencascade::handle<Standard_Transient> &) const) &Interface_Protocol::NbTypes, "Returns the count of DISTINCT types under which an entity may be processed. Each one is candidate to be recognized by TypeNumber, <obj> is then processed according it By default, returns 1 (the DynamicType)", py::arg("obj"));
cls_Interface_Protocol.def("Type", [](Interface_Protocol &self, const opencascade::handle<Standard_Transient> & a0) -> opencascade::handle<Standard_Type> { return self.Type(a0); });
cls_Interface_Protocol.def("Type", (opencascade::handle<Standard_Type> (Interface_Protocol::*)(const opencascade::handle<Standard_Transient> &, const Standard_Integer) const) &Interface_Protocol::Type, "Returns a type under which <obj> can be recognized and processed, according its rank in its definition list (see NbTypes). By default, returns DynamicType", py::arg("obj"), py::arg("nt"));
cls_Interface_Protocol.def("TypeNumber", (Standard_Integer (Interface_Protocol::*)(const opencascade::handle<Standard_Type> &) const) &Interface_Protocol::TypeNumber, "Returns a unique positive CaseNumber for each Recognized Type, Returns Zero for '<type> not recognized'", py::arg("atype"));
cls_Interface_Protocol.def("GlobalCheck", (Standard_Boolean (Interface_Protocol::*)(const Interface_Graph &, opencascade::handle<Interface_Check> &) const) &Interface_Protocol::GlobalCheck, "Evaluates a Global Check for a model (with its Graph) Returns True when done, False if data in model do not apply", py::arg("G"), py::arg("ach"));
cls_Interface_Protocol.def("NewModel", (opencascade::handle<Interface_InterfaceModel> (Interface_Protocol::*)() const) &Interface_Protocol::NewModel, "Creates an empty Model of the considered Norm");
cls_Interface_Protocol.def("IsSuitableModel", (Standard_Boolean (Interface_Protocol::*)(const opencascade::handle<Interface_InterfaceModel> &) const) &Interface_Protocol::IsSuitableModel, "Returns True if <model> is a Model of the considered Norm", py::arg("model"));
cls_Interface_Protocol.def("UnknownEntity", (opencascade::handle<Standard_Transient> (Interface_Protocol::*)() const) &Interface_Protocol::UnknownEntity, "Creates a new Unknown Entity for the considered Norm");
cls_Interface_Protocol.def("IsUnknownEntity", (Standard_Boolean (Interface_Protocol::*)(const opencascade::handle<Standard_Transient> &) const) &Interface_Protocol::IsUnknownEntity, "Returns True if <ent> is an Unknown Entity for the Norm, i.e. same Type as them created by method UnknownEntity (for an Entity out of the Norm, answer can be unpredicable)", py::arg("ent"));
cls_Interface_Protocol.def_static("get_type_name_", (const char * (*)()) &Interface_Protocol::get_type_name, "None");
cls_Interface_Protocol.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Interface_Protocol::get_type_descriptor, "None");
cls_Interface_Protocol.def("DynamicType", (const opencascade::handle<Standard_Type> & (Interface_Protocol::*)() const) &Interface_Protocol::DynamicType, "None");

// Enums

}