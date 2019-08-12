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
#include <IGESSolid_RightAngularWedge.hxx>
#include <Standard_Type.hxx>

void bind_IGESSolid_RightAngularWedge(py::module &mod){

py::class_<IGESSolid_RightAngularWedge, opencascade::handle<IGESSolid_RightAngularWedge>, IGESData_IGESEntity> cls_IGESSolid_RightAngularWedge(mod, "IGESSolid_RightAngularWedge", "defines RightAngularWedge, Type <152> Form Number <0> in package IGESSolid A right angular wedge is a triangular/trapezoidal prism");

// Constructors
cls_IGESSolid_RightAngularWedge.def(py::init<>());

// Fields

// Methods
cls_IGESSolid_RightAngularWedge.def("Init", (void (IGESSolid_RightAngularWedge::*)(const gp_XYZ &, const Standard_Real, const gp_XYZ &, const gp_XYZ &, const gp_XYZ &)) &IGESSolid_RightAngularWedge::Init, "This method is used to set the fields of the class RightAngularWedge - aSize : the lengths along the local axes - lowX : the length at the smaller X-side - aCorner : the corner point coordinates default (0,0,0) - anXAxis : the unit vector defining local X-axis default (1,0,0) - anZAxis : the unit vector defining local Z-axis default (0,0,1)", py::arg("aSize"), py::arg("lowX"), py::arg("aCorner"), py::arg("anXAxis"), py::arg("anZAxis"));
cls_IGESSolid_RightAngularWedge.def("Size", (gp_XYZ (IGESSolid_RightAngularWedge::*)() const) &IGESSolid_RightAngularWedge::Size, "returns the size");
cls_IGESSolid_RightAngularWedge.def("XBigLength", (Standard_Real (IGESSolid_RightAngularWedge::*)() const) &IGESSolid_RightAngularWedge::XBigLength, "returns the length along the local X-axis");
cls_IGESSolid_RightAngularWedge.def("XSmallLength", (Standard_Real (IGESSolid_RightAngularWedge::*)() const) &IGESSolid_RightAngularWedge::XSmallLength, "returns the smaller length along the local X-direction at Y=LY");
cls_IGESSolid_RightAngularWedge.def("YLength", (Standard_Real (IGESSolid_RightAngularWedge::*)() const) &IGESSolid_RightAngularWedge::YLength, "returns the length along the local Y-axis");
cls_IGESSolid_RightAngularWedge.def("ZLength", (Standard_Real (IGESSolid_RightAngularWedge::*)() const) &IGESSolid_RightAngularWedge::ZLength, "returns the length along the local Z-axis");
cls_IGESSolid_RightAngularWedge.def("Corner", (gp_Pnt (IGESSolid_RightAngularWedge::*)() const) &IGESSolid_RightAngularWedge::Corner, "returns the corner point coordinates");
cls_IGESSolid_RightAngularWedge.def("TransformedCorner", (gp_Pnt (IGESSolid_RightAngularWedge::*)() const) &IGESSolid_RightAngularWedge::TransformedCorner, "returns the corner point coordinates after applying TransformationMatrix");
cls_IGESSolid_RightAngularWedge.def("XAxis", (gp_Dir (IGESSolid_RightAngularWedge::*)() const) &IGESSolid_RightAngularWedge::XAxis, "returns the direction defining the local X-axis");
cls_IGESSolid_RightAngularWedge.def("TransformedXAxis", (gp_Dir (IGESSolid_RightAngularWedge::*)() const) &IGESSolid_RightAngularWedge::TransformedXAxis, "returns the direction defining the local X-axis after applying the TransformationMatrix");
cls_IGESSolid_RightAngularWedge.def("YAxis", (gp_Dir (IGESSolid_RightAngularWedge::*)() const) &IGESSolid_RightAngularWedge::YAxis, "returns the direction defining the local Y-axis it is got by taking the cross product of ZAxis and XAxis");
cls_IGESSolid_RightAngularWedge.def("TransformedYAxis", (gp_Dir (IGESSolid_RightAngularWedge::*)() const) &IGESSolid_RightAngularWedge::TransformedYAxis, "returns the direction defining the local Y-axis after applying the TransformationMatrix");
cls_IGESSolid_RightAngularWedge.def("ZAxis", (gp_Dir (IGESSolid_RightAngularWedge::*)() const) &IGESSolid_RightAngularWedge::ZAxis, "returns the direction defining the local Z-axis");
cls_IGESSolid_RightAngularWedge.def("TransformedZAxis", (gp_Dir (IGESSolid_RightAngularWedge::*)() const) &IGESSolid_RightAngularWedge::TransformedZAxis, "returns the direction defining the local Z-axis after applying the TransformationMatrix");
cls_IGESSolid_RightAngularWedge.def_static("get_type_name_", (const char * (*)()) &IGESSolid_RightAngularWedge::get_type_name, "None");
cls_IGESSolid_RightAngularWedge.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSolid_RightAngularWedge::get_type_descriptor, "None");
cls_IGESSolid_RightAngularWedge.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSolid_RightAngularWedge::*)() const) &IGESSolid_RightAngularWedge::DynamicType, "None");

// Enums

}