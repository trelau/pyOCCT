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
#include <gp_Vec.hxx>
#include <Standard_Handle.hxx>
#include <IGESGeom_Direction.hxx>
#include <Standard_Type.hxx>

void bind_IGESGeom_Direction(py::module &mod){

py::class_<IGESGeom_Direction, opencascade::handle<IGESGeom_Direction>, IGESData_IGESEntity> cls_IGESGeom_Direction(mod, "IGESGeom_Direction", "defines IGESDirection, Type <123> Form <0> in package IGESGeom A direction entity is a non-zero vector in Euclidean 3-space that is defined by its three components (direction ratios) with respect to the coordinate axes. If x, y, z are the direction ratios then (x^2 + y^2 + z^2) > 0");

// Constructors
cls_IGESGeom_Direction.def(py::init<>());

// Fields

// Methods
cls_IGESGeom_Direction.def("Init", (void (IGESGeom_Direction::*)(const gp_XYZ &)) &IGESGeom_Direction::Init, "This method is used to set the fields of the class Direction - aDirection : Direction ratios, Z is 0 by default", py::arg("aDirection"));
cls_IGESGeom_Direction.def("Value", (gp_Vec (IGESGeom_Direction::*)() const) &IGESGeom_Direction::Value, "None");
cls_IGESGeom_Direction.def("TransformedValue", (gp_Vec (IGESGeom_Direction::*)() const) &IGESGeom_Direction::TransformedValue, "returns the Direction value after applying Transformation matrix");
cls_IGESGeom_Direction.def_static("get_type_name_", (const char * (*)()) &IGESGeom_Direction::get_type_name, "None");
cls_IGESGeom_Direction.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESGeom_Direction::get_type_descriptor, "None");
cls_IGESGeom_Direction.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESGeom_Direction::*)() const) &IGESGeom_Direction::DynamicType, "None");

// Enums

}