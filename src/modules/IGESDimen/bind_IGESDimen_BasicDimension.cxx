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
#include <gp_XY.hxx>
#include <gp_Pnt2d.hxx>
#include <Standard_Handle.hxx>
#include <IGESDimen_BasicDimension.hxx>
#include <Standard_Type.hxx>

void bind_IGESDimen_BasicDimension(py::module &mod){

py::class_<IGESDimen_BasicDimension, opencascade::handle<IGESDimen_BasicDimension>, IGESData_IGESEntity> cls_IGESDimen_BasicDimension(mod, "IGESDimen_BasicDimension", "Defines IGES Basic Dimension, Type 406, Form 31, in package IGESDimen The basic Dimension Property indicates that the referencing dimension entity is to be displayed with a box around text.");

// Constructors
cls_IGESDimen_BasicDimension.def(py::init<>());

// Fields

// Methods
cls_IGESDimen_BasicDimension.def("Init", (void (IGESDimen_BasicDimension::*)(const Standard_Integer, const gp_XY &, const gp_XY &, const gp_XY &, const gp_XY &)) &IGESDimen_BasicDimension::Init, "None", py::arg("nbPropVal"), py::arg("lowerLeft"), py::arg("lowerRight"), py::arg("upperRight"), py::arg("upperLeft"));
cls_IGESDimen_BasicDimension.def("NbPropertyValues", (Standard_Integer (IGESDimen_BasicDimension::*)() const) &IGESDimen_BasicDimension::NbPropertyValues, "returns the number of properties = 8");
cls_IGESDimen_BasicDimension.def("LowerLeft", (gp_Pnt2d (IGESDimen_BasicDimension::*)() const) &IGESDimen_BasicDimension::LowerLeft, "returns coordinates of lower left corner");
cls_IGESDimen_BasicDimension.def("LowerRight", (gp_Pnt2d (IGESDimen_BasicDimension::*)() const) &IGESDimen_BasicDimension::LowerRight, "returns coordinates of lower right corner");
cls_IGESDimen_BasicDimension.def("UpperRight", (gp_Pnt2d (IGESDimen_BasicDimension::*)() const) &IGESDimen_BasicDimension::UpperRight, "returns coordinates of upper right corner");
cls_IGESDimen_BasicDimension.def("UpperLeft", (gp_Pnt2d (IGESDimen_BasicDimension::*)() const) &IGESDimen_BasicDimension::UpperLeft, "returns coordinates of upper left corner");
cls_IGESDimen_BasicDimension.def_static("get_type_name_", (const char * (*)()) &IGESDimen_BasicDimension::get_type_name, "None");
cls_IGESDimen_BasicDimension.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESDimen_BasicDimension::get_type_descriptor, "None");
cls_IGESDimen_BasicDimension.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESDimen_BasicDimension::*)() const) &IGESDimen_BasicDimension::DynamicType, "None");

// Enums

}