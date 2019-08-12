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
#include <gp_XYZ.hxx>
#include <gp_Pnt.hxx>
#include <gp_Dir.hxx>
#include <Standard_Handle.hxx>
#include <IGESSolid_Torus.hxx>
#include <Standard_Type.hxx>

void bind_IGESSolid_Torus(py::module &mod){

py::class_<IGESSolid_Torus, opencascade::handle<IGESSolid_Torus>, IGESData_IGESEntity> cls_IGESSolid_Torus(mod, "IGESSolid_Torus", "defines Torus, Type <160> Form Number <0> in package IGESSolid A Torus is a solid formed by revolving a circular disc about a specified coplanar axis.");

// Constructors
cls_IGESSolid_Torus.def(py::init<>());

// Fields

// Methods
cls_IGESSolid_Torus.def("Init", (void (IGESSolid_Torus::*)(const Standard_Real, const Standard_Real, const gp_XYZ &, const gp_XYZ &)) &IGESSolid_Torus::Init, "This method is used to set the fields of the class Torus - R1 : distance from center of torus to center of circular disc to be revolved - R2 : radius of circular disc - aPoint : center point coordinates (default (0,0,0)) - anAxis : unit vector in axis direction (default (0,0,1))", py::arg("R1"), py::arg("R2"), py::arg("aPoint"), py::arg("anAxisdir"));
cls_IGESSolid_Torus.def("MajorRadius", (Standard_Real (IGESSolid_Torus::*)() const) &IGESSolid_Torus::MajorRadius, "returns the distance from the center of torus to the center of the disc to be revolved");
cls_IGESSolid_Torus.def("DiscRadius", (Standard_Real (IGESSolid_Torus::*)() const) &IGESSolid_Torus::DiscRadius, "returns the radius of the disc to be revolved");
cls_IGESSolid_Torus.def("AxisPoint", (gp_Pnt (IGESSolid_Torus::*)() const) &IGESSolid_Torus::AxisPoint, "returns the center of torus");
cls_IGESSolid_Torus.def("TransformedAxisPoint", (gp_Pnt (IGESSolid_Torus::*)() const) &IGESSolid_Torus::TransformedAxisPoint, "returns the center of torus after applying TransformationMatrix");
cls_IGESSolid_Torus.def("Axis", (gp_Dir (IGESSolid_Torus::*)() const) &IGESSolid_Torus::Axis, "returns direction of the axis");
cls_IGESSolid_Torus.def("TransformedAxis", (gp_Dir (IGESSolid_Torus::*)() const) &IGESSolid_Torus::TransformedAxis, "returns direction of the axis after applying TransformationMatrix");
cls_IGESSolid_Torus.def_static("get_type_name_", (const char * (*)()) &IGESSolid_Torus::get_type_name, "None");
cls_IGESSolid_Torus.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSolid_Torus::get_type_descriptor, "None");
cls_IGESSolid_Torus.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSolid_Torus::*)() const) &IGESSolid_Torus::DynamicType, "None");

// Enums

}