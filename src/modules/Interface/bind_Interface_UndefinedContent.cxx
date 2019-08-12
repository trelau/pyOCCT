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
#include <Standard_TypeDef.hxx>
#include <Interface_ParamType.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <Interface_EntityList.hxx>
#include <Interface_UndefinedContent.hxx>
#include <Interface_CopyTool.hxx>
#include <Standard_Type.hxx>
#include <TColStd_HArray1OfInteger.hxx>
#include <Interface_HArray1OfHAsciiString.hxx>

void bind_Interface_UndefinedContent(py::module &mod){

py::class_<Interface_UndefinedContent, opencascade::handle<Interface_UndefinedContent>, Standard_Transient> cls_Interface_UndefinedContent(mod, "Interface_UndefinedContent", "Defines resources for an 'Undefined Entity' : such an Entity is used to describe an Entity which complies with the Norm, but of an Unknown Type : hence it is kept under a literal form (avoiding to loose data). UndefinedContent offers a way to store a list of Parameters, as literals or references to other Entities");

// Constructors
cls_Interface_UndefinedContent.def(py::init<>());

// Fields

// Methods
cls_Interface_UndefinedContent.def("NbParams", (Standard_Integer (Interface_UndefinedContent::*)() const) &Interface_UndefinedContent::NbParams, "Gives count of recorded parameters");
cls_Interface_UndefinedContent.def("NbLiterals", (Standard_Integer (Interface_UndefinedContent::*)() const) &Interface_UndefinedContent::NbLiterals, "Gives count of Literal Parameters");
cls_Interface_UndefinedContent.def("ParamData", (Standard_Boolean (Interface_UndefinedContent::*)(const Standard_Integer, Interface_ParamType &, opencascade::handle<Standard_Transient> &, opencascade::handle<TCollection_HAsciiString> &) const) &Interface_UndefinedContent::ParamData, "Returns data of a Parameter : its type, and the entity if it designates en entity ('ent') or its literal value else ('str') Returned value (Boolean) : True if it is an Entity, False else", py::arg("num"), py::arg("ptype"), py::arg("ent"), py::arg("val"));
cls_Interface_UndefinedContent.def("ParamType", (Interface_ParamType (Interface_UndefinedContent::*)(const Standard_Integer) const) &Interface_UndefinedContent::ParamType, "Returns the ParamType of a Param, given its rank Error if num is not between 1 and NbParams", py::arg("num"));
cls_Interface_UndefinedContent.def("IsParamEntity", (Standard_Boolean (Interface_UndefinedContent::*)(const Standard_Integer) const) &Interface_UndefinedContent::IsParamEntity, "Returns True if a Parameter is recorded as an entity Error if num is not between 1 and NbParams", py::arg("num"));
cls_Interface_UndefinedContent.def("ParamEntity", (opencascade::handle<Standard_Transient> (Interface_UndefinedContent::*)(const Standard_Integer) const) &Interface_UndefinedContent::ParamEntity, "Returns Entity corresponding to a Param, given its rank", py::arg("num"));
cls_Interface_UndefinedContent.def("ParamValue", (opencascade::handle<TCollection_HAsciiString> (Interface_UndefinedContent::*)(const Standard_Integer) const) &Interface_UndefinedContent::ParamValue, "Returns litteral value of a Parameter, given its rank", py::arg("num"));
cls_Interface_UndefinedContent.def("Reservate", (void (Interface_UndefinedContent::*)(const Standard_Integer, const Standard_Integer)) &Interface_UndefinedContent::Reservate, "Manages reservation for parameters (internal use) (nb : total count of parameters, nblit : count of literals)", py::arg("nb"), py::arg("nblit"));
cls_Interface_UndefinedContent.def("AddLiteral", (void (Interface_UndefinedContent::*)(const Interface_ParamType, const opencascade::handle<TCollection_HAsciiString> &)) &Interface_UndefinedContent::AddLiteral, "Adds a literal Parameter to the list", py::arg("ptype"), py::arg("val"));
cls_Interface_UndefinedContent.def("AddEntity", (void (Interface_UndefinedContent::*)(const Interface_ParamType, const opencascade::handle<Standard_Transient> &)) &Interface_UndefinedContent::AddEntity, "Adds a Parameter which references an Entity", py::arg("ptype"), py::arg("ent"));
cls_Interface_UndefinedContent.def("RemoveParam", (void (Interface_UndefinedContent::*)(const Standard_Integer)) &Interface_UndefinedContent::RemoveParam, "Removes a Parameter given its rank", py::arg("num"));
cls_Interface_UndefinedContent.def("SetLiteral", (void (Interface_UndefinedContent::*)(const Standard_Integer, const Interface_ParamType, const opencascade::handle<TCollection_HAsciiString> &)) &Interface_UndefinedContent::SetLiteral, "Sets a new value for the Parameter <num>, to a literal value (if it referenced formerly an Entity, this Entity is removed)", py::arg("num"), py::arg("ptype"), py::arg("val"));
cls_Interface_UndefinedContent.def("SetEntity", (void (Interface_UndefinedContent::*)(const Standard_Integer, const Interface_ParamType, const opencascade::handle<Standard_Transient> &)) &Interface_UndefinedContent::SetEntity, "Sets a new value for the Parameter <num>, to reference an Entity. To simply change the Entity, see the variant below", py::arg("num"), py::arg("ptype"), py::arg("ent"));
cls_Interface_UndefinedContent.def("SetEntity", (void (Interface_UndefinedContent::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &)) &Interface_UndefinedContent::SetEntity, "Changes the Entity referenced by the Parameter <num> (with same ParamType)", py::arg("num"), py::arg("ent"));
cls_Interface_UndefinedContent.def("EntityList", (Interface_EntityList (Interface_UndefinedContent::*)() const) &Interface_UndefinedContent::EntityList, "Returns globally the list of param entities. Note that it can be used as shared entity list for the UndefinedEntity");
cls_Interface_UndefinedContent.def("GetFromAnother", (void (Interface_UndefinedContent::*)(const opencascade::handle<Interface_UndefinedContent> &, Interface_CopyTool &)) &Interface_UndefinedContent::GetFromAnother, "Copies contents of undefined entities; deigned to be called by GetFromAnother method from Undefined entity of each Interface (the basic operation is the same regardless the norm)", py::arg("other"), py::arg("TC"));
cls_Interface_UndefinedContent.def_static("get_type_name_", (const char * (*)()) &Interface_UndefinedContent::get_type_name, "None");
cls_Interface_UndefinedContent.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Interface_UndefinedContent::get_type_descriptor, "None");
cls_Interface_UndefinedContent.def("DynamicType", (const opencascade::handle<Standard_Type> & (Interface_UndefinedContent::*)() const) &Interface_UndefinedContent::DynamicType, "None");

// Enums

}