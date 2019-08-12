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
#include <IGESGraph_Pick.hxx>
#include <Standard_Type.hxx>

void bind_IGESGraph_Pick(py::module &mod){

py::class_<IGESGraph_Pick, opencascade::handle<IGESGraph_Pick>, IGESData_IGESEntity> cls_IGESGraph_Pick(mod, "IGESGraph_Pick", "defines IGESPick, Type <406> Form <21> in package IGESGraph");

// Constructors
cls_IGESGraph_Pick.def(py::init<>());

// Fields

// Methods
cls_IGESGraph_Pick.def("Init", (void (IGESGraph_Pick::*)(const Standard_Integer, const Standard_Integer)) &IGESGraph_Pick::Init, "This method is used to set the fields of the class Pick - nbProps : Number of property values (NP = 1) - aPickStatus : Pick Flag", py::arg("nbProps"), py::arg("aPickStatus"));
cls_IGESGraph_Pick.def("NbPropertyValues", (Standard_Integer (IGESGraph_Pick::*)() const) &IGESGraph_Pick::NbPropertyValues, "returns the number of property values in <me>.");
cls_IGESGraph_Pick.def("PickFlag", (Standard_Integer (IGESGraph_Pick::*)() const) &IGESGraph_Pick::PickFlag, "returns 0 if <me> is pickable(default), 1 if <me> is not pickable.");
cls_IGESGraph_Pick.def("IsPickable", (Standard_Boolean (IGESGraph_Pick::*)() const) &IGESGraph_Pick::IsPickable, "returns True if thePick is 0.");
cls_IGESGraph_Pick.def_static("get_type_name_", (const char * (*)()) &IGESGraph_Pick::get_type_name, "None");
cls_IGESGraph_Pick.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESGraph_Pick::get_type_descriptor, "None");
cls_IGESGraph_Pick.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESGraph_Pick::*)() const) &IGESGraph_Pick::DynamicType, "None");

// Enums

}