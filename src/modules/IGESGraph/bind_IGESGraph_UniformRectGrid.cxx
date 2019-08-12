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
#include <Standard_TypeDef.hxx>
#include <gp_XY.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Vec2d.hxx>
#include <Standard_Handle.hxx>
#include <IGESGraph_UniformRectGrid.hxx>
#include <Standard_Type.hxx>

void bind_IGESGraph_UniformRectGrid(py::module &mod){

py::class_<IGESGraph_UniformRectGrid, opencascade::handle<IGESGraph_UniformRectGrid>, IGESData_IGESEntity> cls_IGESGraph_UniformRectGrid(mod, "IGESGraph_UniformRectGrid", "defines IGESUniformRectGrid, Type <406> Form <22> in package IGESGraph");

// Constructors
cls_IGESGraph_UniformRectGrid.def(py::init<>());

// Fields

// Methods
cls_IGESGraph_UniformRectGrid.def("Init", (void (IGESGraph_UniformRectGrid::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const gp_XY &, const gp_XY &, const Standard_Integer, const Standard_Integer)) &IGESGraph_UniformRectGrid::Init, "This method is used to set the fields of the class UniformRectGrid - nbProps : Number of property values (NP = 9) - finite : Finite/Infinite grid flag - line : Line/Point grid flag - weighted : Weighted/Unweighted grid flag - aGridPoint : Point on the grid - aGridSpacing : Grid spacing - pointsX : No. of points/lines in X Direction - pointsY : No. of points/lines in Y Direction", py::arg("nbProps"), py::arg("finite"), py::arg("line"), py::arg("weighted"), py::arg("aGridPoint"), py::arg("aGridSpacing"), py::arg("pointsX"), py::arg("pointsY"));
cls_IGESGraph_UniformRectGrid.def("NbPropertyValues", (Standard_Integer (IGESGraph_UniformRectGrid::*)() const) &IGESGraph_UniformRectGrid::NbPropertyValues, "returns the number of property values in <me>.");
cls_IGESGraph_UniformRectGrid.def("IsFinite", (Standard_Boolean (IGESGraph_UniformRectGrid::*)() const) &IGESGraph_UniformRectGrid::IsFinite, "returns False if <me> is an infinite grid, True if <me> is a finite grid.");
cls_IGESGraph_UniformRectGrid.def("IsLine", (Standard_Boolean (IGESGraph_UniformRectGrid::*)() const) &IGESGraph_UniformRectGrid::IsLine, "returns False if <me> is a Point grid, True if <me> is a Line grid.");
cls_IGESGraph_UniformRectGrid.def("IsWeighted", (Standard_Boolean (IGESGraph_UniformRectGrid::*)() const) &IGESGraph_UniformRectGrid::IsWeighted, "returns False if <me> is a Weighted grid, True if <me> is not a Weighted grid.");
cls_IGESGraph_UniformRectGrid.def("GridPoint", (gp_Pnt2d (IGESGraph_UniformRectGrid::*)() const) &IGESGraph_UniformRectGrid::GridPoint, "returns coordinates of lower left corner, if <me> is a finite grid, coordinates of an arbitrary point, if <me> is an infinite grid.");
cls_IGESGraph_UniformRectGrid.def("GridSpacing", (gp_Vec2d (IGESGraph_UniformRectGrid::*)() const) &IGESGraph_UniformRectGrid::GridSpacing, "returns the grid-spacing in drawing coordinates.");
cls_IGESGraph_UniformRectGrid.def("NbPointsX", (Standard_Integer (IGESGraph_UniformRectGrid::*)() const) &IGESGraph_UniformRectGrid::NbPointsX, "returns the no. of points/lines in X direction (only applicable if IsFinite() = 1, i.e: a finite grid).");
cls_IGESGraph_UniformRectGrid.def("NbPointsY", (Standard_Integer (IGESGraph_UniformRectGrid::*)() const) &IGESGraph_UniformRectGrid::NbPointsY, "returns the no. of points/lines in Y direction (only applicable if IsFinite() = 1, i.e: a finite grid).");
cls_IGESGraph_UniformRectGrid.def_static("get_type_name_", (const char * (*)()) &IGESGraph_UniformRectGrid::get_type_name, "None");
cls_IGESGraph_UniformRectGrid.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESGraph_UniformRectGrid::get_type_descriptor, "None");
cls_IGESGraph_UniformRectGrid.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESGraph_UniformRectGrid::*)() const) &IGESGraph_UniformRectGrid::DynamicType, "None");

// Enums

}