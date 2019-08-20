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
#include <Standard_Handle.hxx>
#include <Geom2d_Curve.hxx>
#include <Geom_Curve.hxx>
#include <gp_Pln.hxx>
#include <GeomAPI_ProjectPointOnCurve.hxx>
#include <GeomAPI_ProjectPointOnSurf.hxx>
#include <GeomAPI_ExtremaCurveCurve.hxx>
#include <GeomAPI_ExtremaCurveSurface.hxx>
#include <GeomAPI_ExtremaSurfaceSurface.hxx>
#include <GeomAPI_PointsToBSpline.hxx>
#include <GeomAPI_PointsToBSplineSurface.hxx>
#include <GeomAPI_Interpolate.hxx>
#include <GeomAPI_IntSS.hxx>
#include <GeomAPI_IntCS.hxx>
#include <GeomAPI.hxx>

void bind_GeomAPI(py::module &mod){

py::class_<GeomAPI, std::unique_ptr<GeomAPI>> cls_GeomAPI(mod, "GeomAPI", "The GeomAPI package provides an Application Programming Interface for the Geometry.");

// Constructors

// Fields

// Methods
// cls_GeomAPI.def_static("operator new_", (void * (*)(size_t)) &GeomAPI::operator new, "None", py::arg("theSize"));
// cls_GeomAPI.def_static("operator delete_", (void (*)(void *)) &GeomAPI::operator delete, "None", py::arg("theAddress"));
// cls_GeomAPI.def_static("operator new[]_", (void * (*)(size_t)) &GeomAPI::operator new[], "None", py::arg("theSize"));
// cls_GeomAPI.def_static("operator delete[]_", (void (*)(void *)) &GeomAPI::operator delete[], "None", py::arg("theAddress"));
// cls_GeomAPI.def_static("operator new_", (void * (*)(size_t, void *)) &GeomAPI::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomAPI.def_static("operator delete_", (void (*)(void *, void *)) &GeomAPI::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomAPI.def_static("To2d_", (opencascade::handle<Geom2d_Curve> (*)(const opencascade::handle<Geom_Curve> &, const gp_Pln &)) &GeomAPI::To2d, "This function builds (in the parametric space of the plane P) a 2D curve equivalent to the 3D curve C. The 3D curve C is considered to be located in the plane P. Warning The 3D curve C must be of one of the following types: - a line - a circle - an ellipse - a hyperbola - a parabola - a Bezier curve - a BSpline curve Exceptions Standard_NoSuchObject if C is not a defined type curve.", py::arg("C"), py::arg("P"));
cls_GeomAPI.def_static("To3d_", (opencascade::handle<Geom_Curve> (*)(const opencascade::handle<Geom2d_Curve> &, const gp_Pln &)) &GeomAPI::To3d, "Builds a 3D curve equivalent to the 2D curve C described in the parametric space defined by the local coordinate system of plane P. The resulting 3D curve is of the same nature as that of the curve C.", py::arg("C"), py::arg("P"));

// Enums

}