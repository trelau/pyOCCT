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
#include <IGESAppli_RegionRestriction.hxx>
#include <Standard_Type.hxx>

void bind_IGESAppli_RegionRestriction(py::module &mod){

py::class_<IGESAppli_RegionRestriction, opencascade::handle<IGESAppli_RegionRestriction>, IGESData_IGESEntity> cls_IGESAppli_RegionRestriction(mod, "IGESAppli_RegionRestriction", "defines RegionRestriction, Type <406> Form <2> in package IGESAppli Defines regions to set an application's restriction over a region.");

// Constructors
cls_IGESAppli_RegionRestriction.def(py::init<>());

// Fields

// Methods
cls_IGESAppli_RegionRestriction.def("Init", (void (IGESAppli_RegionRestriction::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer)) &IGESAppli_RegionRestriction::Init, "This method is used to set the fields of the class RegionRestriction - nbPropVal : Number of property values, always = 3 - aViasRest : Electrical Vias restriction - aCompoRest : Electrical components restriction - aCktRest : Electrical circuitry restriction", py::arg("nbPropVal"), py::arg("aViasRest"), py::arg("aCompoRest"), py::arg("aCktRest"));
cls_IGESAppli_RegionRestriction.def("NbPropertyValues", (Standard_Integer (IGESAppli_RegionRestriction::*)() const) &IGESAppli_RegionRestriction::NbPropertyValues, "is always 3");
cls_IGESAppli_RegionRestriction.def("ElectricalViasRestriction", (Standard_Integer (IGESAppli_RegionRestriction::*)() const) &IGESAppli_RegionRestriction::ElectricalViasRestriction, "returns the Electrical vias restriction is 0, 1 or 2");
cls_IGESAppli_RegionRestriction.def("ElectricalComponentRestriction", (Standard_Integer (IGESAppli_RegionRestriction::*)() const) &IGESAppli_RegionRestriction::ElectricalComponentRestriction, "returns the Electrical components restriction is 0, 1 or 2");
cls_IGESAppli_RegionRestriction.def("ElectricalCktRestriction", (Standard_Integer (IGESAppli_RegionRestriction::*)() const) &IGESAppli_RegionRestriction::ElectricalCktRestriction, "returns the Electrical circuitry restriction is 0, 1 or 2");
cls_IGESAppli_RegionRestriction.def_static("get_type_name_", (const char * (*)()) &IGESAppli_RegionRestriction::get_type_name, "None");
cls_IGESAppli_RegionRestriction.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESAppli_RegionRestriction::get_type_descriptor, "None");
cls_IGESAppli_RegionRestriction.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESAppli_RegionRestriction::*)() const) &IGESAppli_RegionRestriction::DynamicType, "None");

// Enums

}