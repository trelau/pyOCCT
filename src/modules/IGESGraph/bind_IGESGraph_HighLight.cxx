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
#include <IGESGraph_HighLight.hxx>
#include <Standard_Type.hxx>

void bind_IGESGraph_HighLight(py::module &mod){

py::class_<IGESGraph_HighLight, opencascade::handle<IGESGraph_HighLight>, IGESData_IGESEntity> cls_IGESGraph_HighLight(mod, "IGESGraph_HighLight", "defines IGESHighLight, Type <406> Form <20> in package IGESGraph");

// Constructors
cls_IGESGraph_HighLight.def(py::init<>());

// Fields

// Methods
cls_IGESGraph_HighLight.def("Init", (void (IGESGraph_HighLight::*)(const Standard_Integer, const Standard_Integer)) &IGESGraph_HighLight::Init, "This method is used to set the fields of the class HighLight - nbProps : Number of property values (NP = 1) - aHighLightStatus : HighLight Flag", py::arg("nbProps"), py::arg("aHighLightStatus"));
cls_IGESGraph_HighLight.def("NbPropertyValues", (Standard_Integer (IGESGraph_HighLight::*)() const) &IGESGraph_HighLight::NbPropertyValues, "returns the number of property values in <me>");
cls_IGESGraph_HighLight.def("HighLightStatus", (Standard_Integer (IGESGraph_HighLight::*)() const) &IGESGraph_HighLight::HighLightStatus, "returns 0 if <me> is not highlighted(default), 1 if <me> is highlighted");
cls_IGESGraph_HighLight.def("IsHighLighted", (Standard_Boolean (IGESGraph_HighLight::*)() const) &IGESGraph_HighLight::IsHighLighted, "returns True if entity is highlighted");
cls_IGESGraph_HighLight.def_static("get_type_name_", (const char * (*)()) &IGESGraph_HighLight::get_type_name, "None");
cls_IGESGraph_HighLight.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESGraph_HighLight::get_type_descriptor, "None");
cls_IGESGraph_HighLight.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESGraph_HighLight::*)() const) &IGESGraph_HighLight::DynamicType, "None");

// Enums

}