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
#include <Aspect_Grid.hxx>
#include <Standard_Handle.hxx>
#include <Aspect_RectangularGrid.hxx>
#include <Standard_Type.hxx>
#include <Standard_TypeDef.hxx>

void bind_Aspect_RectangularGrid(py::module &mod){

py::class_<Aspect_RectangularGrid, opencascade::handle<Aspect_RectangularGrid>, Aspect_Grid> cls_Aspect_RectangularGrid(mod, "Aspect_RectangularGrid", "None");

// Fields

// Methods
cls_Aspect_RectangularGrid.def_static("get_type_name_", (const char * (*)()) &Aspect_RectangularGrid::get_type_name, "None");
cls_Aspect_RectangularGrid.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Aspect_RectangularGrid::get_type_descriptor, "None");
cls_Aspect_RectangularGrid.def("DynamicType", (const opencascade::handle<Standard_Type> & (Aspect_RectangularGrid::*)() const) &Aspect_RectangularGrid::DynamicType, "None");
cls_Aspect_RectangularGrid.def("SetXStep", (void (Aspect_RectangularGrid::*)(const Standard_Real)) &Aspect_RectangularGrid::SetXStep, "defines the x step of the grid.", py::arg("aStep"));
cls_Aspect_RectangularGrid.def("SetYStep", (void (Aspect_RectangularGrid::*)(const Standard_Real)) &Aspect_RectangularGrid::SetYStep, "defines the y step of the grid.", py::arg("aStep"));
cls_Aspect_RectangularGrid.def("SetAngle", (void (Aspect_RectangularGrid::*)(const Standard_Real, const Standard_Real)) &Aspect_RectangularGrid::SetAngle, "defines the angle of the second network the fist angle is given relatively to the horizontal. the second angle is given relatively to the vertical.", py::arg("anAngle1"), py::arg("anAngle2"));
cls_Aspect_RectangularGrid.def("SetGridValues", (void (Aspect_RectangularGrid::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &Aspect_RectangularGrid::SetGridValues, "None", py::arg("XOrigin"), py::arg("YOrigin"), py::arg("XStep"), py::arg("YStep"), py::arg("RotationAngle"));
cls_Aspect_RectangularGrid.def("Compute", [](Aspect_RectangularGrid &self, const Standard_Real X, const Standard_Real Y, Standard_Real & gridX, Standard_Real & gridY){ self.Compute(X, Y, gridX, gridY); return std::tuple<Standard_Real &, Standard_Real &>(gridX, gridY); }, "returns the point of the grid the closest to the point X,Y", py::arg("X"), py::arg("Y"), py::arg("gridX"), py::arg("gridY"));
cls_Aspect_RectangularGrid.def("XStep", (Standard_Real (Aspect_RectangularGrid::*)() const) &Aspect_RectangularGrid::XStep, "returns the x step of the grid.");
cls_Aspect_RectangularGrid.def("YStep", (Standard_Real (Aspect_RectangularGrid::*)() const) &Aspect_RectangularGrid::YStep, "returns the x step of the grid.");
cls_Aspect_RectangularGrid.def("FirstAngle", (Standard_Real (Aspect_RectangularGrid::*)() const) &Aspect_RectangularGrid::FirstAngle, "returns the x Angle of the grid, relatively to the horizontal.");
cls_Aspect_RectangularGrid.def("SecondAngle", (Standard_Real (Aspect_RectangularGrid::*)() const) &Aspect_RectangularGrid::SecondAngle, "returns the y Angle of the grid, relatively to the vertical.");
cls_Aspect_RectangularGrid.def("Init", (void (Aspect_RectangularGrid::*)()) &Aspect_RectangularGrid::Init, "None");

// Enums

}