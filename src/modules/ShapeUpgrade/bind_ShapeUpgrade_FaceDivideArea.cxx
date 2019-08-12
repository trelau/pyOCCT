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
#include <ShapeUpgrade_FaceDivide.hxx>
#include <TopoDS_Face.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <ShapeUpgrade_FaceDivideArea.hxx>
#include <Standard_Type.hxx>

void bind_ShapeUpgrade_FaceDivideArea(py::module &mod){

py::class_<ShapeUpgrade_FaceDivideArea, opencascade::handle<ShapeUpgrade_FaceDivideArea>, ShapeUpgrade_FaceDivide> cls_ShapeUpgrade_FaceDivideArea(mod, "ShapeUpgrade_FaceDivideArea", "Divides face by max area criterium.");

// Constructors
cls_ShapeUpgrade_FaceDivideArea.def(py::init<>());
cls_ShapeUpgrade_FaceDivideArea.def(py::init<const TopoDS_Face &>(), py::arg("F"));

// Fields

// Methods
cls_ShapeUpgrade_FaceDivideArea.def("Perform", (Standard_Boolean (ShapeUpgrade_FaceDivideArea::*)()) &ShapeUpgrade_FaceDivideArea::Perform, "Performs splitting and computes the resulting shell The context is used to keep track of former splittings");
cls_ShapeUpgrade_FaceDivideArea.def("MaxArea", (Standard_Real & (ShapeUpgrade_FaceDivideArea::*)()) &ShapeUpgrade_FaceDivideArea::MaxArea, "Set max area allowed for faces");
cls_ShapeUpgrade_FaceDivideArea.def_static("get_type_name_", (const char * (*)()) &ShapeUpgrade_FaceDivideArea::get_type_name, "None");
cls_ShapeUpgrade_FaceDivideArea.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeUpgrade_FaceDivideArea::get_type_descriptor, "None");
cls_ShapeUpgrade_FaceDivideArea.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeUpgrade_FaceDivideArea::*)() const) &ShapeUpgrade_FaceDivideArea::DynamicType, "None");

// Enums

}