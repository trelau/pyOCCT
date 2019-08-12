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
#include <IGESData_SingleParentEntity.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <IGESData_IGESEntity.hxx>
#include <IGESData_HArray1OfIGESEntity.hxx>
#include <IGESBasic_SingleParent.hxx>
#include <Standard_Type.hxx>

void bind_IGESBasic_SingleParent(py::module &mod){

py::class_<IGESBasic_SingleParent, opencascade::handle<IGESBasic_SingleParent>, IGESData_SingleParentEntity> cls_IGESBasic_SingleParent(mod, "IGESBasic_SingleParent", "defines SingleParent, Type <402> Form <9> in package IGESBasic It defines a logical structure of one independent (parent) entity and one or more subordinate (children) entities");

// Constructors
cls_IGESBasic_SingleParent.def(py::init<>());

// Fields

// Methods
cls_IGESBasic_SingleParent.def("Init", (void (IGESBasic_SingleParent::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &, const opencascade::handle<IGESData_HArray1OfIGESEntity> &)) &IGESBasic_SingleParent::Init, "This method is used to set the fields of the class SingleParent - nbParentEntities : Indicates number of Parents, always = 1 - aParentEntity : Used to hold the Parent Entity - allChildren : Used to hold the children", py::arg("nbParentEntities"), py::arg("aParentEntity"), py::arg("allChildren"));
cls_IGESBasic_SingleParent.def("NbParentEntities", (Standard_Integer (IGESBasic_SingleParent::*)() const) &IGESBasic_SingleParent::NbParentEntities, "returns the number of Parent Entities, which should be 1");
cls_IGESBasic_SingleParent.def("SingleParent", (opencascade::handle<IGESData_IGESEntity> (IGESBasic_SingleParent::*)() const) &IGESBasic_SingleParent::SingleParent, "Returns the Parent Entity (inherited method)");
cls_IGESBasic_SingleParent.def("NbChildren", (Standard_Integer (IGESBasic_SingleParent::*)() const) &IGESBasic_SingleParent::NbChildren, "returns the number of children of the Parent");
cls_IGESBasic_SingleParent.def("Child", (opencascade::handle<IGESData_IGESEntity> (IGESBasic_SingleParent::*)(const Standard_Integer) const) &IGESBasic_SingleParent::Child, "returns the specific child as indicated by Index raises exception if Index <= 0 or Index > NbChildren()", py::arg("Index"));
cls_IGESBasic_SingleParent.def_static("get_type_name_", (const char * (*)()) &IGESBasic_SingleParent::get_type_name, "None");
cls_IGESBasic_SingleParent.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESBasic_SingleParent::get_type_descriptor, "None");
cls_IGESBasic_SingleParent.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESBasic_SingleParent::*)() const) &IGESBasic_SingleParent::DynamicType, "None");

// Enums

}