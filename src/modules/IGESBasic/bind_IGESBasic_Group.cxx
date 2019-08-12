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
#include <IGESData_IGESEntity.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <IGESData_HArray1OfIGESEntity.hxx>
#include <Standard_Transient.hxx>
#include <IGESBasic_Group.hxx>
#include <Standard_Type.hxx>

void bind_IGESBasic_Group(py::module &mod){

py::class_<IGESBasic_Group, opencascade::handle<IGESBasic_Group>, IGESData_IGESEntity> cls_IGESBasic_Group(mod, "IGESBasic_Group", "defines Group, Type <402> Form <1> in package IGESBasic The Group Associativity allows a collection of a set of entities to be maintained as a single, logical entity");

// Constructors
cls_IGESBasic_Group.def(py::init<>());
cls_IGESBasic_Group.def(py::init<const Standard_Integer>(), py::arg("nb"));

// Fields

// Methods
cls_IGESBasic_Group.def("Init", (void (IGESBasic_Group::*)(const opencascade::handle<IGESData_HArray1OfIGESEntity> &)) &IGESBasic_Group::Init, "This method is used to set the fields of the class Group - allEntities : Used to store pointers to members of the Group.", py::arg("allEntities"));
cls_IGESBasic_Group.def("SetOrdered", (void (IGESBasic_Group::*)(const Standard_Boolean)) &IGESBasic_Group::SetOrdered, "Sets a Group to be, or not to be Ordered (according mode)", py::arg("mode"));
cls_IGESBasic_Group.def("SetWithoutBackP", (void (IGESBasic_Group::*)(const Standard_Boolean)) &IGESBasic_Group::SetWithoutBackP, "Sets a Group to be, or not to be WithoutBackP", py::arg("mode"));
cls_IGESBasic_Group.def("IsOrdered", (Standard_Boolean (IGESBasic_Group::*)() const) &IGESBasic_Group::IsOrdered, "Returns True if <me> is Ordered");
cls_IGESBasic_Group.def("IsWithoutBackP", (Standard_Boolean (IGESBasic_Group::*)() const) &IGESBasic_Group::IsWithoutBackP, "Returns True if <me> is WithoutBackP");
cls_IGESBasic_Group.def("SetUser", (void (IGESBasic_Group::*)(const Standard_Integer, const Standard_Integer)) &IGESBasic_Group::SetUser, "Enforce a new value for the type and form", py::arg("type"), py::arg("form"));
cls_IGESBasic_Group.def("SetNb", (void (IGESBasic_Group::*)(const Standard_Integer)) &IGESBasic_Group::SetNb, "Changes the count of item If greater, new items are null If lower, old items are lost", py::arg("nb"));
cls_IGESBasic_Group.def("NbEntities", (Standard_Integer (IGESBasic_Group::*)() const) &IGESBasic_Group::NbEntities, "returns the number of IGESEntities in the Group");
cls_IGESBasic_Group.def("Entity", (opencascade::handle<IGESData_IGESEntity> (IGESBasic_Group::*)(const Standard_Integer) const) &IGESBasic_Group::Entity, "returns the specific entity from the Group", py::arg("Index"));
cls_IGESBasic_Group.def("Value", (opencascade::handle<Standard_Transient> (IGESBasic_Group::*)(const Standard_Integer) const) &IGESBasic_Group::Value, "returns the specific entity from the Group", py::arg("Index"));
cls_IGESBasic_Group.def("SetValue", (void (IGESBasic_Group::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &)) &IGESBasic_Group::SetValue, "Sets a new value for item <Index>", py::arg("Index"), py::arg("ent"));
cls_IGESBasic_Group.def_static("get_type_name_", (const char * (*)()) &IGESBasic_Group::get_type_name, "None");
cls_IGESBasic_Group.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESBasic_Group::get_type_descriptor, "None");
cls_IGESBasic_Group.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESBasic_Group::*)() const) &IGESBasic_Group::DynamicType, "None");

// Enums

}