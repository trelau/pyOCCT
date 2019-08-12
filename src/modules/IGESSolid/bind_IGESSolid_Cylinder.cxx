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
#include <IGESSolid_Cylinder.hxx>
#include <Standard_Type.hxx>

void bind_IGESSolid_Cylinder(py::module &mod){

py::class_<IGESSolid_Cylinder, opencascade::handle<IGESSolid_Cylinder>, IGESData_IGESEntity> cls_IGESSolid_Cylinder(mod, "IGESSolid_Cylinder", "defines Cylinder, Type <154> Form Number <0> in package IGESSolid This defines a solid cylinder");

// Constructors
cls_IGESSolid_Cylinder.def(py::init<>());

// Fields

// Methods
cls_IGESSolid_Cylinder.def("Init", (void (IGESSolid_Cylinder::*)(const Standard_Real, const Standard_Real, const gp_XYZ &, const gp_XYZ &)) &IGESSolid_Cylinder::Init, "This method is used to set the fields of the class Cylinder - aHeight : Cylinder height - aRadius : Cylinder radius - aCenter : First face center coordinates (default (0,0,0)) - anAxis : Unit vector in axis direction (default (0,0,1))", py::arg("aHeight"), py::arg("aRadius"), py::arg("aCenter"), py::arg("anAxis"));
cls_IGESSolid_Cylinder.def("Height", (Standard_Real (IGESSolid_Cylinder::*)() const) &IGESSolid_Cylinder::Height, "returns the cylinder height");
cls_IGESSolid_Cylinder.def("Radius", (Standard_Real (IGESSolid_Cylinder::*)() const) &IGESSolid_Cylinder::Radius, "returns the cylinder radius");
cls_IGESSolid_Cylinder.def("FaceCenter", (gp_Pnt (IGESSolid_Cylinder::*)() const) &IGESSolid_Cylinder::FaceCenter, "returns the first face center coordinates.");
cls_IGESSolid_Cylinder.def("TransformedFaceCenter", (gp_Pnt (IGESSolid_Cylinder::*)() const) &IGESSolid_Cylinder::TransformedFaceCenter, "returns the first face center after applying TransformationMatrix");
cls_IGESSolid_Cylinder.def("Axis", (gp_Dir (IGESSolid_Cylinder::*)() const) &IGESSolid_Cylinder::Axis, "returns the vector in axis direction");
cls_IGESSolid_Cylinder.def("TransformedAxis", (gp_Dir (IGESSolid_Cylinder::*)() const) &IGESSolid_Cylinder::TransformedAxis, "returns the vector in axis direction after applying TransformationMatrix");
cls_IGESSolid_Cylinder.def_static("get_type_name_", (const char * (*)()) &IGESSolid_Cylinder::get_type_name, "None");
cls_IGESSolid_Cylinder.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSolid_Cylinder::get_type_descriptor, "None");
cls_IGESSolid_Cylinder.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSolid_Cylinder::*)() const) &IGESSolid_Cylinder::DynamicType, "None");

// Enums

}