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
#include <V3d_Viewer.hxx>
#include <Aspect_CircularGrid.hxx>
#include <Standard_Handle.hxx>
#include <V3d_CircularGrid.hxx>
#include <Standard_Type.hxx>
#include <V3d_ViewerPointer.hxx>
#include <Quantity_Color.hxx>
#include <Standard_TypeDef.hxx>
#include <Graphic3d_Structure.hxx>
#include <Graphic3d_Group.hxx>
#include <gp_Ax3.hxx>
#include <Aspect_GridDrawMode.hxx>

void bind_V3d_CircularGrid(py::module &mod){

py::class_<V3d_CircularGrid, opencascade::handle<V3d_CircularGrid>, Aspect_CircularGrid> cls_V3d_CircularGrid(mod, "V3d_CircularGrid", "None");

// Constructors
cls_V3d_CircularGrid.def(py::init<const V3d_ViewerPointer &, const Quantity_Color &, const Quantity_Color &>(), py::arg("aViewer"), py::arg("aColor"), py::arg("aTenthColor"));

// Fields

// Methods
cls_V3d_CircularGrid.def_static("get_type_name_", (const char * (*)()) &V3d_CircularGrid::get_type_name, "None");
cls_V3d_CircularGrid.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &V3d_CircularGrid::get_type_descriptor, "None");
cls_V3d_CircularGrid.def("DynamicType", (const opencascade::handle<Standard_Type> & (V3d_CircularGrid::*)() const) &V3d_CircularGrid::DynamicType, "None");
cls_V3d_CircularGrid.def("SetColors", (void (V3d_CircularGrid::*)(const Quantity_Color &, const Quantity_Color &)) &V3d_CircularGrid::SetColors, "None", py::arg("aColor"), py::arg("aTenthColor"));
cls_V3d_CircularGrid.def("Display", (void (V3d_CircularGrid::*)()) &V3d_CircularGrid::Display, "None");
cls_V3d_CircularGrid.def("Erase", (void (V3d_CircularGrid::*)() const) &V3d_CircularGrid::Erase, "None");
cls_V3d_CircularGrid.def("IsDisplayed", (Standard_Boolean (V3d_CircularGrid::*)() const) &V3d_CircularGrid::IsDisplayed, "None");
cls_V3d_CircularGrid.def("GraphicValues", [](V3d_CircularGrid &self, Standard_Real & Radius, Standard_Real & OffSet){ self.GraphicValues(Radius, OffSet); return std::tuple<Standard_Real &, Standard_Real &>(Radius, OffSet); }, "None", py::arg("Radius"), py::arg("OffSet"));
cls_V3d_CircularGrid.def("SetGraphicValues", (void (V3d_CircularGrid::*)(const Standard_Real, const Standard_Real)) &V3d_CircularGrid::SetGraphicValues, "None", py::arg("Radius"), py::arg("OffSet"));

// Enums

}