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
#include <IGESBasic_Hierarchy.hxx>
#include <Standard_Type.hxx>

void bind_IGESBasic_Hierarchy(py::module &mod){

py::class_<IGESBasic_Hierarchy, opencascade::handle<IGESBasic_Hierarchy>, IGESData_IGESEntity> cls_IGESBasic_Hierarchy(mod, "IGESBasic_Hierarchy", "defines Hierarchy, Type <406> Form <10> in package IGESBasic Provides ability to control the hierarchy of each directory entry attribute.");

// Constructors
cls_IGESBasic_Hierarchy.def(py::init<>());

// Fields

// Methods
cls_IGESBasic_Hierarchy.def("Init", (void (IGESBasic_Hierarchy::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer)) &IGESBasic_Hierarchy::Init, "This method is used to set the fields of the class Hierarchy - nbPropVal : Number of Property values = 6 - aLineFont : indicates the line font - aView : indicates the view - aEntityLevel : indicates the entity level - aBlankStatus : indicates the blank status - aLineWt : indicates the line weight - aColorNum : indicates the color num aLineFont, aView, aEntityLevel, aBlankStatus, aLineWt and aColorNum can take 0 or 1. 0 : The directory entry attribute will apply to entities physically subordinate to this entity. 1 : The directory entry attribute of this entity will not apply to physically subordinate entities.", py::arg("nbPropVal"), py::arg("aLineFont"), py::arg("aView"), py::arg("anEntityLevel"), py::arg("aBlankStatus"), py::arg("aLineWt"), py::arg("aColorNum"));
cls_IGESBasic_Hierarchy.def("NbPropertyValues", (Standard_Integer (IGESBasic_Hierarchy::*)() const) &IGESBasic_Hierarchy::NbPropertyValues, "returns the number of property values, which should be 6");
cls_IGESBasic_Hierarchy.def("NewLineFont", (Standard_Integer (IGESBasic_Hierarchy::*)() const) &IGESBasic_Hierarchy::NewLineFont, "returns the line font");
cls_IGESBasic_Hierarchy.def("NewView", (Standard_Integer (IGESBasic_Hierarchy::*)() const) &IGESBasic_Hierarchy::NewView, "returns the view");
cls_IGESBasic_Hierarchy.def("NewEntityLevel", (Standard_Integer (IGESBasic_Hierarchy::*)() const) &IGESBasic_Hierarchy::NewEntityLevel, "returns the entity level");
cls_IGESBasic_Hierarchy.def("NewBlankStatus", (Standard_Integer (IGESBasic_Hierarchy::*)() const) &IGESBasic_Hierarchy::NewBlankStatus, "returns the blank status");
cls_IGESBasic_Hierarchy.def("NewLineWeight", (Standard_Integer (IGESBasic_Hierarchy::*)() const) &IGESBasic_Hierarchy::NewLineWeight, "returns the line weight");
cls_IGESBasic_Hierarchy.def("NewColorNum", (Standard_Integer (IGESBasic_Hierarchy::*)() const) &IGESBasic_Hierarchy::NewColorNum, "returns the color number");
cls_IGESBasic_Hierarchy.def_static("get_type_name_", (const char * (*)()) &IGESBasic_Hierarchy::get_type_name, "None");
cls_IGESBasic_Hierarchy.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESBasic_Hierarchy::get_type_descriptor, "None");
cls_IGESBasic_Hierarchy.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESBasic_Hierarchy::*)() const) &IGESBasic_Hierarchy::DynamicType, "None");

// Enums

}