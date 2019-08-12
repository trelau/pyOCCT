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
#include <Standard_Handle.hxx>
#include <IGESSolid_Sphere.hxx>
#include <Standard_Type.hxx>

void bind_IGESSolid_Sphere(py::module &mod){

py::class_<IGESSolid_Sphere, opencascade::handle<IGESSolid_Sphere>, IGESData_IGESEntity> cls_IGESSolid_Sphere(mod, "IGESSolid_Sphere", "defines Sphere, Type <158> Form Number <0> in package IGESSolid This defines a sphere with a center and radius");

// Constructors
cls_IGESSolid_Sphere.def(py::init<>());

// Fields

// Methods
cls_IGESSolid_Sphere.def("Init", (void (IGESSolid_Sphere::*)(const Standard_Real, const gp_XYZ &)) &IGESSolid_Sphere::Init, "This method is used to set the fields of the class Sphere - aRadius : the radius of the sphere - aCenter : the center point coordinates (default (0,0,0))", py::arg("aRadius"), py::arg("aCenter"));
cls_IGESSolid_Sphere.def("Radius", (Standard_Real (IGESSolid_Sphere::*)() const) &IGESSolid_Sphere::Radius, "returns the radius of the sphere");
cls_IGESSolid_Sphere.def("Center", (gp_Pnt (IGESSolid_Sphere::*)() const) &IGESSolid_Sphere::Center, "returns the center of the sphere");
cls_IGESSolid_Sphere.def("TransformedCenter", (gp_Pnt (IGESSolid_Sphere::*)() const) &IGESSolid_Sphere::TransformedCenter, "returns the center of the sphere after applying TransformationMatrix");
cls_IGESSolid_Sphere.def_static("get_type_name_", (const char * (*)()) &IGESSolid_Sphere::get_type_name, "None");
cls_IGESSolid_Sphere.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSolid_Sphere::get_type_descriptor, "None");
cls_IGESSolid_Sphere.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSolid_Sphere::*)() const) &IGESSolid_Sphere::DynamicType, "None");

// Enums

}