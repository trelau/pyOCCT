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
#include <IGESData_ViewKindEntity.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <IGESGeom_Plane.hxx>
#include <IGESData_TransfEntity.hxx>
#include <gp_XYZ.hxx>
#include <IGESDraw_View.hxx>
#include <Standard_Type.hxx>

void bind_IGESDraw_View(py::module &mod){

py::class_<IGESDraw_View, opencascade::handle<IGESDraw_View>, IGESData_ViewKindEntity> cls_IGESDraw_View(mod, "IGESDraw_View", "defines IGES View Entity, Type <410> Form <0> in package IGESDraw");

// Constructors
cls_IGESDraw_View.def(py::init<>());

// Fields

// Methods
cls_IGESDraw_View.def("Init", (void (IGESDraw_View::*)(const Standard_Integer, const Standard_Real, const opencascade::handle<IGESGeom_Plane> &, const opencascade::handle<IGESGeom_Plane> &, const opencascade::handle<IGESGeom_Plane> &, const opencascade::handle<IGESGeom_Plane> &, const opencascade::handle<IGESGeom_Plane> &, const opencascade::handle<IGESGeom_Plane> &)) &IGESDraw_View::Init, "This method is used to set fields of the class View - aViewNum : View number - aScale : Scale factor - aLeftPlane : Left plane of view volume - aTopPlane : Top plane of view volume - aRightPlane : Right plane of view volume - aBottomPlane : Bottom plane of view volume - aBackPlane : Back plane of view volume - aFrontPlane : Front plane of view volume", py::arg("aViewNum"), py::arg("aScale"), py::arg("aLeftPlane"), py::arg("aTopPlane"), py::arg("aRightPlane"), py::arg("aBottomPlane"), py::arg("aBackPlane"), py::arg("aFrontPlane"));
cls_IGESDraw_View.def("IsSingle", (Standard_Boolean (IGESDraw_View::*)() const) &IGESDraw_View::IsSingle, "Returns True (for a single view)");
cls_IGESDraw_View.def("NbViews", (Standard_Integer (IGESDraw_View::*)() const) &IGESDraw_View::NbViews, "Returns 1 (single view)");
cls_IGESDraw_View.def("ViewItem", (opencascade::handle<IGESData_ViewKindEntity> (IGESDraw_View::*)(const Standard_Integer) const) &IGESDraw_View::ViewItem, "For a single view, returns <me> whatever <num>", py::arg("num"));
cls_IGESDraw_View.def("ViewNumber", (Standard_Integer (IGESDraw_View::*)() const) &IGESDraw_View::ViewNumber, "returns integer number identifying view orientation");
cls_IGESDraw_View.def("ScaleFactor", (Standard_Real (IGESDraw_View::*)() const) &IGESDraw_View::ScaleFactor, "returns the scale factor(Default = 1.0)");
cls_IGESDraw_View.def("HasLeftPlane", (Standard_Boolean (IGESDraw_View::*)() const) &IGESDraw_View::HasLeftPlane, "returns False if left side of view volume is not present");
cls_IGESDraw_View.def("LeftPlane", (opencascade::handle<IGESGeom_Plane> (IGESDraw_View::*)() const) &IGESDraw_View::LeftPlane, "returns the left side of view volume, or null handle");
cls_IGESDraw_View.def("HasTopPlane", (Standard_Boolean (IGESDraw_View::*)() const) &IGESDraw_View::HasTopPlane, "returns False if top of view volume is not present");
cls_IGESDraw_View.def("TopPlane", (opencascade::handle<IGESGeom_Plane> (IGESDraw_View::*)() const) &IGESDraw_View::TopPlane, "returns the top of view volume, or null handle");
cls_IGESDraw_View.def("HasRightPlane", (Standard_Boolean (IGESDraw_View::*)() const) &IGESDraw_View::HasRightPlane, "returns False if right side of view volume is not present");
cls_IGESDraw_View.def("RightPlane", (opencascade::handle<IGESGeom_Plane> (IGESDraw_View::*)() const) &IGESDraw_View::RightPlane, "returns the right side of view volume, or null handle");
cls_IGESDraw_View.def("HasBottomPlane", (Standard_Boolean (IGESDraw_View::*)() const) &IGESDraw_View::HasBottomPlane, "returns False if bottom of view volume is not present");
cls_IGESDraw_View.def("BottomPlane", (opencascade::handle<IGESGeom_Plane> (IGESDraw_View::*)() const) &IGESDraw_View::BottomPlane, "returns the bottom of view volume, or null handle");
cls_IGESDraw_View.def("HasBackPlane", (Standard_Boolean (IGESDraw_View::*)() const) &IGESDraw_View::HasBackPlane, "returns False if back of view volume is not present");
cls_IGESDraw_View.def("BackPlane", (opencascade::handle<IGESGeom_Plane> (IGESDraw_View::*)() const) &IGESDraw_View::BackPlane, "returns the back of view volume, or null handle");
cls_IGESDraw_View.def("HasFrontPlane", (Standard_Boolean (IGESDraw_View::*)() const) &IGESDraw_View::HasFrontPlane, "returns False if front of view volume is not present");
cls_IGESDraw_View.def("FrontPlane", (opencascade::handle<IGESGeom_Plane> (IGESDraw_View::*)() const) &IGESDraw_View::FrontPlane, "returns the front of view volume, or null handle");
cls_IGESDraw_View.def("ViewMatrix", (opencascade::handle<IGESData_TransfEntity> (IGESDraw_View::*)() const) &IGESDraw_View::ViewMatrix, "returns the Transformation Matrix");
cls_IGESDraw_View.def("ModelToView", (gp_XYZ (IGESDraw_View::*)(const gp_XYZ &) const) &IGESDraw_View::ModelToView, "returns XYZ from the Model space to the View space by applying the View Matrix", py::arg("coords"));
cls_IGESDraw_View.def_static("get_type_name_", (const char * (*)()) &IGESDraw_View::get_type_name, "None");
cls_IGESDraw_View.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESDraw_View::get_type_descriptor, "None");
cls_IGESDraw_View.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESDraw_View::*)() const) &IGESDraw_View::DynamicType, "None");

// Enums

}