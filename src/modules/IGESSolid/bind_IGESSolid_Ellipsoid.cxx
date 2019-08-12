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
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <gp_Dir.hxx>
#include <Standard_Handle.hxx>
#include <IGESSolid_Ellipsoid.hxx>
#include <Standard_Type.hxx>

void bind_IGESSolid_Ellipsoid(py::module &mod){

py::class_<IGESSolid_Ellipsoid, opencascade::handle<IGESSolid_Ellipsoid>, IGESData_IGESEntity> cls_IGESSolid_Ellipsoid(mod, "IGESSolid_Ellipsoid", "defines Ellipsoid, Type <168> Form Number <0> in package IGESSolid The ellipsoid is a solid bounded by the surface defined by: X^2 Y^2 Z^2 ----- + ----- + ----- = 1 LX^2 LY^2 LZ^2");

// Constructors
cls_IGESSolid_Ellipsoid.def(py::init<>());

// Fields

// Methods
cls_IGESSolid_Ellipsoid.def("Init", (void (IGESSolid_Ellipsoid::*)(const gp_XYZ &, const gp_XYZ &, const gp_XYZ &, const gp_XYZ &)) &IGESSolid_Ellipsoid::Init, "This method is used to set the fields of the class Ellipsoid - aSize : Lengths in the local X,Y,Z directions - aCenter : Center point of ellipsoid (default (0,0,0)) - anXAxis : Unit vector defining local X-axis default (1,0,0) - anZAxis : Unit vector defining local Z-axis default (0,0,1)", py::arg("aSize"), py::arg("aCenter"), py::arg("anXAxis"), py::arg("anZAxis"));
cls_IGESSolid_Ellipsoid.def("Size", (gp_XYZ (IGESSolid_Ellipsoid::*)() const) &IGESSolid_Ellipsoid::Size, "returns the size");
cls_IGESSolid_Ellipsoid.def("XLength", (Standard_Real (IGESSolid_Ellipsoid::*)() const) &IGESSolid_Ellipsoid::XLength, "returns the length in the local X-direction");
cls_IGESSolid_Ellipsoid.def("YLength", (Standard_Real (IGESSolid_Ellipsoid::*)() const) &IGESSolid_Ellipsoid::YLength, "returns the length in the local Y-direction");
cls_IGESSolid_Ellipsoid.def("ZLength", (Standard_Real (IGESSolid_Ellipsoid::*)() const) &IGESSolid_Ellipsoid::ZLength, "returns the length in the local Z-direction");
cls_IGESSolid_Ellipsoid.def("Center", (gp_Pnt (IGESSolid_Ellipsoid::*)() const) &IGESSolid_Ellipsoid::Center, "returns the center of the ellipsoid");
cls_IGESSolid_Ellipsoid.def("TransformedCenter", (gp_Pnt (IGESSolid_Ellipsoid::*)() const) &IGESSolid_Ellipsoid::TransformedCenter, "returns the center of the ellipsoid after applying TransformationMatrix");
cls_IGESSolid_Ellipsoid.def("XAxis", (gp_Dir (IGESSolid_Ellipsoid::*)() const) &IGESSolid_Ellipsoid::XAxis, "returns the vector corresponding to the local X-direction");
cls_IGESSolid_Ellipsoid.def("TransformedXAxis", (gp_Dir (IGESSolid_Ellipsoid::*)() const) &IGESSolid_Ellipsoid::TransformedXAxis, "returns the vector corresponding to the local X-direction after applying TransformationMatrix");
cls_IGESSolid_Ellipsoid.def("YAxis", (gp_Dir (IGESSolid_Ellipsoid::*)() const) &IGESSolid_Ellipsoid::YAxis, "returns the vector corresponding to the local Y-direction which is got by taking cross product of ZAxis and XAxis");
cls_IGESSolid_Ellipsoid.def("TransformedYAxis", (gp_Dir (IGESSolid_Ellipsoid::*)() const) &IGESSolid_Ellipsoid::TransformedYAxis, "returns the vector corresponding to the local Y-direction (which is got by taking cross product of ZAxis and XAxis) after applying TransformationMatrix");
cls_IGESSolid_Ellipsoid.def("ZAxis", (gp_Dir (IGESSolid_Ellipsoid::*)() const) &IGESSolid_Ellipsoid::ZAxis, "returns the vector corresponding to the local Z-direction");
cls_IGESSolid_Ellipsoid.def("TransformedZAxis", (gp_Dir (IGESSolid_Ellipsoid::*)() const) &IGESSolid_Ellipsoid::TransformedZAxis, "returns the vector corresponding to the local Z-direction after applying TransformationMatrix");
cls_IGESSolid_Ellipsoid.def_static("get_type_name_", (const char * (*)()) &IGESSolid_Ellipsoid::get_type_name, "None");
cls_IGESSolid_Ellipsoid.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSolid_Ellipsoid::get_type_descriptor, "None");
cls_IGESSolid_Ellipsoid.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSolid_Ellipsoid::*)() const) &IGESSolid_Ellipsoid::DynamicType, "None");

// Enums

}