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
#include <Aspect_CircularGrid.hxx>
#include <Standard_Type.hxx>
#include <Standard_TypeDef.hxx>

void bind_Aspect_CircularGrid(py::module &mod){

py::class_<Aspect_CircularGrid, opencascade::handle<Aspect_CircularGrid>, Aspect_Grid> cls_Aspect_CircularGrid(mod, "Aspect_CircularGrid", "None");

// Fields

// Methods
cls_Aspect_CircularGrid.def_static("get_type_name_", (const char * (*)()) &Aspect_CircularGrid::get_type_name, "None");
cls_Aspect_CircularGrid.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Aspect_CircularGrid::get_type_descriptor, "None");
cls_Aspect_CircularGrid.def("DynamicType", (const opencascade::handle<Standard_Type> & (Aspect_CircularGrid::*)() const) &Aspect_CircularGrid::DynamicType, "None");
cls_Aspect_CircularGrid.def("SetRadiusStep", (void (Aspect_CircularGrid::*)(const Standard_Real)) &Aspect_CircularGrid::SetRadiusStep, "defines the x step of the grid.", py::arg("aStep"));
cls_Aspect_CircularGrid.def("SetDivisionNumber", (void (Aspect_CircularGrid::*)(const Standard_Integer)) &Aspect_CircularGrid::SetDivisionNumber, "defines the step of the grid.", py::arg("aNumber"));
cls_Aspect_CircularGrid.def("SetGridValues", (void (Aspect_CircularGrid::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Real)) &Aspect_CircularGrid::SetGridValues, "None", py::arg("XOrigin"), py::arg("YOrigin"), py::arg("RadiusStep"), py::arg("DivisionNumber"), py::arg("RotationAngle"));
cls_Aspect_CircularGrid.def("Compute", [](Aspect_CircularGrid &self, const Standard_Real X, const Standard_Real Y, Standard_Real & gridX, Standard_Real & gridY){ self.Compute(X, Y, gridX, gridY); return std::tuple<Standard_Real &, Standard_Real &>(gridX, gridY); }, "returns the point of the grid the closest to the point X,Y", py::arg("X"), py::arg("Y"), py::arg("gridX"), py::arg("gridY"));
cls_Aspect_CircularGrid.def("RadiusStep", (Standard_Real (Aspect_CircularGrid::*)() const) &Aspect_CircularGrid::RadiusStep, "returns the x step of the grid.");
cls_Aspect_CircularGrid.def("DivisionNumber", (Standard_Integer (Aspect_CircularGrid::*)() const) &Aspect_CircularGrid::DivisionNumber, "returns the x step of the grid.");
cls_Aspect_CircularGrid.def("Init", (void (Aspect_CircularGrid::*)()) &Aspect_CircularGrid::Init, "None");

// Enums

}