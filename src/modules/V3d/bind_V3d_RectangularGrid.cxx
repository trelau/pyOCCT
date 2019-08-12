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
#include <Aspect_RectangularGrid.hxx>
#include <Standard_Handle.hxx>
#include <V3d_RectangularGrid.hxx>
#include <Standard_Type.hxx>
#include <V3d_ViewerPointer.hxx>
#include <Quantity_Color.hxx>
#include <Standard_TypeDef.hxx>
#include <Graphic3d_Structure.hxx>
#include <Graphic3d_Group.hxx>
#include <gp_Ax3.hxx>
#include <Aspect_GridDrawMode.hxx>

void bind_V3d_RectangularGrid(py::module &mod){

py::class_<V3d_RectangularGrid, opencascade::handle<V3d_RectangularGrid>, Aspect_RectangularGrid> cls_V3d_RectangularGrid(mod, "V3d_RectangularGrid", "None");

// Constructors
cls_V3d_RectangularGrid.def(py::init<const V3d_ViewerPointer &, const Quantity_Color &, const Quantity_Color &>(), py::arg("aViewer"), py::arg("aColor"), py::arg("aTenthColor"));

// Fields

// Methods
cls_V3d_RectangularGrid.def_static("get_type_name_", (const char * (*)()) &V3d_RectangularGrid::get_type_name, "None");
cls_V3d_RectangularGrid.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &V3d_RectangularGrid::get_type_descriptor, "None");
cls_V3d_RectangularGrid.def("DynamicType", (const opencascade::handle<Standard_Type> & (V3d_RectangularGrid::*)() const) &V3d_RectangularGrid::DynamicType, "None");
cls_V3d_RectangularGrid.def("SetColors", (void (V3d_RectangularGrid::*)(const Quantity_Color &, const Quantity_Color &)) &V3d_RectangularGrid::SetColors, "None", py::arg("aColor"), py::arg("aTenthColor"));
cls_V3d_RectangularGrid.def("Display", (void (V3d_RectangularGrid::*)()) &V3d_RectangularGrid::Display, "None");
cls_V3d_RectangularGrid.def("Erase", (void (V3d_RectangularGrid::*)() const) &V3d_RectangularGrid::Erase, "None");
cls_V3d_RectangularGrid.def("IsDisplayed", (Standard_Boolean (V3d_RectangularGrid::*)() const) &V3d_RectangularGrid::IsDisplayed, "None");
cls_V3d_RectangularGrid.def("GraphicValues", [](V3d_RectangularGrid &self, Standard_Real & XSize, Standard_Real & YSize, Standard_Real & OffSet){ self.GraphicValues(XSize, YSize, OffSet); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(XSize, YSize, OffSet); }, "None", py::arg("XSize"), py::arg("YSize"), py::arg("OffSet"));
cls_V3d_RectangularGrid.def("SetGraphicValues", (void (V3d_RectangularGrid::*)(const Standard_Real, const Standard_Real, const Standard_Real)) &V3d_RectangularGrid::SetGraphicValues, "None", py::arg("XSize"), py::arg("YSize"), py::arg("OffSet"));

// Enums

}