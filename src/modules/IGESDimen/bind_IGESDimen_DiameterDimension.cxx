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
#include <Standard_Handle.hxx>
#include <IGESDimen_GeneralNote.hxx>
#include <IGESDimen_LeaderArrow.hxx>
#include <gp_XY.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt2d.hxx>
#include <IGESDimen_DiameterDimension.hxx>
#include <Standard_Type.hxx>

void bind_IGESDimen_DiameterDimension(py::module &mod){

py::class_<IGESDimen_DiameterDimension, opencascade::handle<IGESDimen_DiameterDimension>, IGESData_IGESEntity> cls_IGESDimen_DiameterDimension(mod, "IGESDimen_DiameterDimension", "defines DiameterDimension, Type <206> Form <0> in package IGESDimen Used for dimensioning diameters");

// Constructors
cls_IGESDimen_DiameterDimension.def(py::init<>());

// Fields

// Methods
cls_IGESDimen_DiameterDimension.def("Init", (void (IGESDimen_DiameterDimension::*)(const opencascade::handle<IGESDimen_GeneralNote> &, const opencascade::handle<IGESDimen_LeaderArrow> &, const opencascade::handle<IGESDimen_LeaderArrow> &, const gp_XY &)) &IGESDimen_DiameterDimension::Init, "This method is used to set the fields of the class DiameterDimension - aNote : General Note Entity - aLeader : First Leader Entity - anotherLeader : Second Leader Entity or a Null Handle. - aCenter : Arc center coordinates", py::arg("aNote"), py::arg("aLeader"), py::arg("anotherLeader"), py::arg("aCenter"));
cls_IGESDimen_DiameterDimension.def("Note", (opencascade::handle<IGESDimen_GeneralNote> (IGESDimen_DiameterDimension::*)() const) &IGESDimen_DiameterDimension::Note, "returns the General Note Entity");
cls_IGESDimen_DiameterDimension.def("FirstLeader", (opencascade::handle<IGESDimen_LeaderArrow> (IGESDimen_DiameterDimension::*)() const) &IGESDimen_DiameterDimension::FirstLeader, "returns the First Leader Entity");
cls_IGESDimen_DiameterDimension.def("HasSecondLeader", (Standard_Boolean (IGESDimen_DiameterDimension::*)() const) &IGESDimen_DiameterDimension::HasSecondLeader, "returns False if theSecondleader is a Null Handle.");
cls_IGESDimen_DiameterDimension.def("SecondLeader", (opencascade::handle<IGESDimen_LeaderArrow> (IGESDimen_DiameterDimension::*)() const) &IGESDimen_DiameterDimension::SecondLeader, "returns the Second Leader Entity");
cls_IGESDimen_DiameterDimension.def("Center", (gp_Pnt2d (IGESDimen_DiameterDimension::*)() const) &IGESDimen_DiameterDimension::Center, "returns the Arc Center co-ordinates as Pnt2d from package gp");
cls_IGESDimen_DiameterDimension.def("TransformedCenter", (gp_Pnt2d (IGESDimen_DiameterDimension::*)() const) &IGESDimen_DiameterDimension::TransformedCenter, "returns the Arc Center co-ordinates as Pnt2d from package gp after Transformation. (Z = 0.0 for Transformation)");
cls_IGESDimen_DiameterDimension.def_static("get_type_name_", (const char * (*)()) &IGESDimen_DiameterDimension::get_type_name, "None");
cls_IGESDimen_DiameterDimension.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESDimen_DiameterDimension::get_type_descriptor, "None");
cls_IGESDimen_DiameterDimension.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESDimen_DiameterDimension::*)() const) &IGESDimen_DiameterDimension::DynamicType, "None");

// Enums

}