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
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Curve.hxx>
#include <gp_Pnt.hxx>
#include <Geom_Surface.hxx>
#include <Geom2d_Curve.hxx>
#include <gp_Pnt2d.hxx>
#include <GeomLib_Tool.hxx>

void bind_GeomLib_Tool(py::module &mod){

py::class_<GeomLib_Tool, std::unique_ptr<GeomLib_Tool>> cls_GeomLib_Tool(mod, "GeomLib_Tool", "Provides various methods with Geom2d and Geom curves and surfaces. The methods of this class compute the parameter(s) of a given point on a curve or a surface. To get the valid result the point must be located rather close to the curve (surface) or at least to allow getting unambiguous result (do not put point at center of circle...), but choice of 'trust' distance between curve/surface and point is responcibility of user (parameter MaxDist). Return FALSE if the point is beyond the MaxDist limit or if computation fails.");

// Constructors

// Fields

// Methods
// cls_GeomLib_Tool.def_static("operator new_", (void * (*)(size_t)) &GeomLib_Tool::operator new, "None", py::arg("theSize"));
// cls_GeomLib_Tool.def_static("operator delete_", (void (*)(void *)) &GeomLib_Tool::operator delete, "None", py::arg("theAddress"));
// cls_GeomLib_Tool.def_static("operator new[]_", (void * (*)(size_t)) &GeomLib_Tool::operator new[], "None", py::arg("theSize"));
// cls_GeomLib_Tool.def_static("operator delete[]_", (void (*)(void *)) &GeomLib_Tool::operator delete[], "None", py::arg("theAddress"));
// cls_GeomLib_Tool.def_static("operator new_", (void * (*)(size_t, void *)) &GeomLib_Tool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomLib_Tool.def_static("operator delete_", (void (*)(void *, void *)) &GeomLib_Tool::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomLib_Tool.def_static("Parameter_", [](const opencascade::handle<Geom_Curve> & Curve, const gp_Pnt & Point, const Standard_Real MaxDist, Standard_Real & U){ Standard_Boolean rv = GeomLib_Tool::Parameter(Curve, Point, MaxDist, U); return std::tuple<Standard_Boolean, Standard_Real &>(rv, U); }, "Extracts the parameter of a 3D point lying on a 3D curve or at a distance less than the MaxDist value.", py::arg("Curve"), py::arg("Point"), py::arg("MaxDist"), py::arg("U"));
cls_GeomLib_Tool.def_static("Parameters_", [](const opencascade::handle<Geom_Surface> & Surface, const gp_Pnt & Point, const Standard_Real MaxDist, Standard_Real & U, Standard_Real & V){ Standard_Boolean rv = GeomLib_Tool::Parameters(Surface, Point, MaxDist, U, V); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, U, V); }, "Extracts the parameter of a 3D point lying on a surface or at a distance less than the MaxDist value.", py::arg("Surface"), py::arg("Point"), py::arg("MaxDist"), py::arg("U"), py::arg("V"));
cls_GeomLib_Tool.def_static("Parameter_", [](const opencascade::handle<Geom2d_Curve> & Curve, const gp_Pnt2d & Point, const Standard_Real MaxDist, Standard_Real & U){ Standard_Boolean rv = GeomLib_Tool::Parameter(Curve, Point, MaxDist, U); return std::tuple<Standard_Boolean, Standard_Real &>(rv, U); }, "Extracts the parameter of a 2D point lying on a 2D curve or at a distance less than the MaxDist value.", py::arg("Curve"), py::arg("Point"), py::arg("MaxDist"), py::arg("U"));

// Enums

}