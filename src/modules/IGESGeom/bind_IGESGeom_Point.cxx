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
#include <gp_XYZ.hxx>
#include <Standard_Handle.hxx>
#include <IGESBasic_SubfigureDef.hxx>
#include <gp_Pnt.hxx>
#include <Standard_TypeDef.hxx>
#include <IGESGeom_Point.hxx>
#include <Standard_Type.hxx>

void bind_IGESGeom_Point(py::module &mod){

py::class_<IGESGeom_Point, opencascade::handle<IGESGeom_Point>, IGESData_IGESEntity> cls_IGESGeom_Point(mod, "IGESGeom_Point", "defines IGESPoint, Type <116> Form <0> in package IGESGeom");

// Constructors
cls_IGESGeom_Point.def(py::init<>());

// Fields

// Methods
cls_IGESGeom_Point.def("Init", (void (IGESGeom_Point::*)(const gp_XYZ &, const opencascade::handle<IGESBasic_SubfigureDef> &)) &IGESGeom_Point::Init, "This method is used to set the fields of the class Point - aPoint : Coordinates of point - aSymbol : SubfigureDefinition entity specifying the display symbol if there exists one, or zero", py::arg("aPoint"), py::arg("aSymbol"));
cls_IGESGeom_Point.def("Value", (gp_Pnt (IGESGeom_Point::*)() const) &IGESGeom_Point::Value, "returns co-ordinates of the point");
cls_IGESGeom_Point.def("TransformedValue", (gp_Pnt (IGESGeom_Point::*)() const) &IGESGeom_Point::TransformedValue, "returns co-ordinates of the point after applying Transf. Matrix");
cls_IGESGeom_Point.def("HasDisplaySymbol", (Standard_Boolean (IGESGeom_Point::*)() const) &IGESGeom_Point::HasDisplaySymbol, "returns True if symbol exists");
cls_IGESGeom_Point.def("DisplaySymbol", (opencascade::handle<IGESBasic_SubfigureDef> (IGESGeom_Point::*)() const) &IGESGeom_Point::DisplaySymbol, "returns display symbol entity if it exists");
cls_IGESGeom_Point.def_static("get_type_name_", (const char * (*)()) &IGESGeom_Point::get_type_name, "None");
cls_IGESGeom_Point.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESGeom_Point::get_type_descriptor, "None");
cls_IGESGeom_Point.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESGeom_Point::*)() const) &IGESGeom_Point::DynamicType, "None");

// Enums

}