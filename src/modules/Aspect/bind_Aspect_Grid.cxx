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
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <Aspect_Grid.hxx>
#include <Standard_Type.hxx>
#include <Standard_TypeDef.hxx>
#include <Quantity_Color.hxx>
#include <Aspect_GridDrawMode.hxx>

void bind_Aspect_Grid(py::module &mod){

py::class_<Aspect_Grid, opencascade::handle<Aspect_Grid>, Standard_Transient> cls_Aspect_Grid(mod, "Aspect_Grid", "None");

// Fields

// Methods
cls_Aspect_Grid.def_static("get_type_name_", (const char * (*)()) &Aspect_Grid::get_type_name, "None");
cls_Aspect_Grid.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Aspect_Grid::get_type_descriptor, "None");
cls_Aspect_Grid.def("DynamicType", (const opencascade::handle<Standard_Type> & (Aspect_Grid::*)() const) &Aspect_Grid::DynamicType, "None");
cls_Aspect_Grid.def("SetXOrigin", (void (Aspect_Grid::*)(const Standard_Real)) &Aspect_Grid::SetXOrigin, "defines the x Origin of the grid.", py::arg("anOrigin"));
cls_Aspect_Grid.def("SetYOrigin", (void (Aspect_Grid::*)(const Standard_Real)) &Aspect_Grid::SetYOrigin, "defines the y Origin of the grid.", py::arg("anOrigin"));
cls_Aspect_Grid.def("SetRotationAngle", (void (Aspect_Grid::*)(const Standard_Real)) &Aspect_Grid::SetRotationAngle, "defines the orientation of the grid.", py::arg("anAngle"));
cls_Aspect_Grid.def("Rotate", (void (Aspect_Grid::*)(const Standard_Real)) &Aspect_Grid::Rotate, "Rotate the grid from a relative angle.", py::arg("anAngle"));
cls_Aspect_Grid.def("Translate", (void (Aspect_Grid::*)(const Standard_Real, const Standard_Real)) &Aspect_Grid::Translate, "Translate the grid from a relative distance.", py::arg("aDx"), py::arg("aDy"));
cls_Aspect_Grid.def("SetColors", (void (Aspect_Grid::*)(const Quantity_Color &, const Quantity_Color &)) &Aspect_Grid::SetColors, "Change the colors of the grid", py::arg("aColor"), py::arg("aTenthColor"));
cls_Aspect_Grid.def("Hit", [](Aspect_Grid &self, const Standard_Real X, const Standard_Real Y, Standard_Real & gridX, Standard_Real & gridY){ self.Hit(X, Y, gridX, gridY); return std::tuple<Standard_Real &, Standard_Real &>(gridX, gridY); }, "returns the point of the grid the closest to the point X,Y if the grid is active. If the grid is not active returns X,Y.", py::arg("X"), py::arg("Y"), py::arg("gridX"), py::arg("gridY"));
cls_Aspect_Grid.def("Compute", [](Aspect_Grid &self, const Standard_Real X, const Standard_Real Y, Standard_Real & gridX, Standard_Real & gridY){ self.Compute(X, Y, gridX, gridY); return std::tuple<Standard_Real &, Standard_Real &>(gridX, gridY); }, "returns the point of the grid the closest to the point X,Y", py::arg("X"), py::arg("Y"), py::arg("gridX"), py::arg("gridY"));
cls_Aspect_Grid.def("Activate", (void (Aspect_Grid::*)()) &Aspect_Grid::Activate, "activates the grid. The Hit method will return gridx and gridx computed according to the steps of the grid.");
cls_Aspect_Grid.def("Deactivate", (void (Aspect_Grid::*)()) &Aspect_Grid::Deactivate, "deactivates the grid. The hit method will return gridx and gridx as the enter value X & Y.");
cls_Aspect_Grid.def("XOrigin", (Standard_Real (Aspect_Grid::*)() const) &Aspect_Grid::XOrigin, "returns the x Origin of the grid.");
cls_Aspect_Grid.def("YOrigin", (Standard_Real (Aspect_Grid::*)() const) &Aspect_Grid::YOrigin, "returns the x Origin of the grid.");
cls_Aspect_Grid.def("RotationAngle", (Standard_Real (Aspect_Grid::*)() const) &Aspect_Grid::RotationAngle, "returns the x Angle of the grid.");
cls_Aspect_Grid.def("IsActive", (Standard_Boolean (Aspect_Grid::*)() const) &Aspect_Grid::IsActive, "Returns TRUE when the grid is active.");
cls_Aspect_Grid.def("Colors", (void (Aspect_Grid::*)(Quantity_Color &, Quantity_Color &) const) &Aspect_Grid::Colors, "Returns the colors of the grid.", py::arg("aColor"), py::arg("aTenthColor"));
cls_Aspect_Grid.def("SetDrawMode", (void (Aspect_Grid::*)(const Aspect_GridDrawMode)) &Aspect_Grid::SetDrawMode, "Change the grid aspect.", py::arg("aDrawMode"));
cls_Aspect_Grid.def("DrawMode", (Aspect_GridDrawMode (Aspect_Grid::*)() const) &Aspect_Grid::DrawMode, "Returns the grid aspect.");
cls_Aspect_Grid.def("Display", (void (Aspect_Grid::*)()) &Aspect_Grid::Display, "Display the grid at screen.");
cls_Aspect_Grid.def("Erase", (void (Aspect_Grid::*)() const) &Aspect_Grid::Erase, "Erase the grid from screen.");
cls_Aspect_Grid.def("IsDisplayed", (Standard_Boolean (Aspect_Grid::*)() const) &Aspect_Grid::IsDisplayed, "Returns TRUE when the grid is displayed at screen.");
cls_Aspect_Grid.def("Init", (void (Aspect_Grid::*)()) &Aspect_Grid::Init, "None");

// Enums

}