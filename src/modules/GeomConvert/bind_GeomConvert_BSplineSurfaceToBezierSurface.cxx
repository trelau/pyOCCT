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
#include <Geom_BSplineSurface.hxx>
#include <Standard_TypeDef.hxx>
#include <Geom_BezierSurface.hxx>
#include <TColGeom_Array2OfBezierSurface.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <GeomConvert_BSplineSurfaceToBezierSurface.hxx>

void bind_GeomConvert_BSplineSurfaceToBezierSurface(py::module &mod){

py::class_<GeomConvert_BSplineSurfaceToBezierSurface, std::unique_ptr<GeomConvert_BSplineSurfaceToBezierSurface>> cls_GeomConvert_BSplineSurfaceToBezierSurface(mod, "GeomConvert_BSplineSurfaceToBezierSurface", "This algorithm converts a B-spline surface into several Bezier surfaces. It uses an algorithm of knot insertion. A BSplineSurfaceToBezierSurface object provides a framework for: - defining the BSpline surface to be converted, - implementing the construction algorithm, and - consulting the results. References : Generating the Bezier points of B-spline curves and surfaces (Wolfgang Bohm) CAD volume 13 number 6 november 1981");

// Constructors
cls_GeomConvert_BSplineSurfaceToBezierSurface.def(py::init<const opencascade::handle<Geom_BSplineSurface> &>(), py::arg("BasisSurface"));
cls_GeomConvert_BSplineSurfaceToBezierSurface.def(py::init<const opencascade::handle<Geom_BSplineSurface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("BasisSurface"), py::arg("U1"), py::arg("U2"), py::arg("V1"), py::arg("V2"), py::arg("ParametricTolerance"));

// Fields

// Methods
// cls_GeomConvert_BSplineSurfaceToBezierSurface.def_static("operator new_", (void * (*)(size_t)) &GeomConvert_BSplineSurfaceToBezierSurface::operator new, "None", py::arg("theSize"));
// cls_GeomConvert_BSplineSurfaceToBezierSurface.def_static("operator delete_", (void (*)(void *)) &GeomConvert_BSplineSurfaceToBezierSurface::operator delete, "None", py::arg("theAddress"));
// cls_GeomConvert_BSplineSurfaceToBezierSurface.def_static("operator new[]_", (void * (*)(size_t)) &GeomConvert_BSplineSurfaceToBezierSurface::operator new[], "None", py::arg("theSize"));
// cls_GeomConvert_BSplineSurfaceToBezierSurface.def_static("operator delete[]_", (void (*)(void *)) &GeomConvert_BSplineSurfaceToBezierSurface::operator delete[], "None", py::arg("theAddress"));
// cls_GeomConvert_BSplineSurfaceToBezierSurface.def_static("operator new_", (void * (*)(size_t, void *)) &GeomConvert_BSplineSurfaceToBezierSurface::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomConvert_BSplineSurfaceToBezierSurface.def_static("operator delete_", (void (*)(void *, void *)) &GeomConvert_BSplineSurfaceToBezierSurface::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomConvert_BSplineSurfaceToBezierSurface.def("Patch", (opencascade::handle<Geom_BezierSurface> (GeomConvert_BSplineSurfaceToBezierSurface::*)(const Standard_Integer, const Standard_Integer)) &GeomConvert_BSplineSurfaceToBezierSurface::Patch, "Constructs and returns the Bezier surface of indices (UIndex, VIndex) to the patch grid computed on the BSpline surface analyzed by this algorithm. This Bezier surface has the same orientation as the BSpline surface analyzed in this framework. UIndex is an index common to a row in the patch grid. A row in the grid corresponds to a series of adjacent patches, all limited by the same two u-isoparametric curves of the surface. VIndex is an index common to a column in the patch grid. A column in the grid corresponds to a series of adjacent patches, all limited by the same two v-isoparametric curves of the surface. Exceptions Standard_OutOfRange if: - UIndex is less than 1 or greater than the number of rows in the patch grid computed on the BSpline surface analyzed by this algorithm (as returned by the function NbUPatches); or if - VIndex is less than 1 or greater than the number of columns in the patch grid computed on the BSpline surface analyzed by this algorithm (as returned by the function NbVPatches).", py::arg("UIndex"), py::arg("VIndex"));
cls_GeomConvert_BSplineSurfaceToBezierSurface.def("Patches", (void (GeomConvert_BSplineSurfaceToBezierSurface::*)(TColGeom_Array2OfBezierSurface &)) &GeomConvert_BSplineSurfaceToBezierSurface::Patches, "Constructs all the Bezier surfaces whose data is computed by this algorithm, and loads them into the Surfaces table. These Bezier surfaces have the same orientation as the BSpline surface analyzed in this framework. The Surfaces array is organised in the same way as the patch grid computed on the BSpline surface analyzed by this algorithm. A row in the array corresponds to a series of adjacent patches, all limited by the same two u-isoparametric curves of the surface. A column in the array corresponds to a series of adjacent patches, all limited by the same two v-isoparametric curves of the surface. Exceptions Standard_DimensionError if the Surfaces array was not created with the following bounds: - 1, and the number of adjacent patch series in the u parametric direction of the patch grid computed on the BSpline surface, analyzed by this algorithm (as given by the function NbUPatches) as row bounds, - 1, and the number of adjacent patch series in the v parametric direction of the patch grid computed on the BSpline surface, analyzed by this algorithm (as given by the function NbVPatches) as column bounds.", py::arg("Surfaces"));
cls_GeomConvert_BSplineSurfaceToBezierSurface.def("UKnots", (void (GeomConvert_BSplineSurfaceToBezierSurface::*)(TColStd_Array1OfReal &) const) &GeomConvert_BSplineSurfaceToBezierSurface::UKnots, "This methode returns the bspline's u-knots associated to the converted Patches Raised if the length of Curves is not equal to NbUPatches + 1.", py::arg("TKnots"));
cls_GeomConvert_BSplineSurfaceToBezierSurface.def("VKnots", (void (GeomConvert_BSplineSurfaceToBezierSurface::*)(TColStd_Array1OfReal &) const) &GeomConvert_BSplineSurfaceToBezierSurface::VKnots, "This methode returns the bspline's v-knots associated to the converted Patches Raised if the length of Curves is not equal to NbVPatches + 1.", py::arg("TKnots"));
cls_GeomConvert_BSplineSurfaceToBezierSurface.def("NbUPatches", (Standard_Integer (GeomConvert_BSplineSurfaceToBezierSurface::*)() const) &GeomConvert_BSplineSurfaceToBezierSurface::NbUPatches, "Returns the number of Bezier surfaces in the U direction. If at the creation time you have decomposed the basis Surface between the parametric values UFirst, ULast the number of Bezier surfaces in the U direction depends on the number of knots included inside the interval [UFirst, ULast]. If you have decomposed the whole basis B-spline surface the number of Bezier surfaces NbUPatches is equal to the number of UKnots less one.");
cls_GeomConvert_BSplineSurfaceToBezierSurface.def("NbVPatches", (Standard_Integer (GeomConvert_BSplineSurfaceToBezierSurface::*)() const) &GeomConvert_BSplineSurfaceToBezierSurface::NbVPatches, "Returns the number of Bezier surfaces in the V direction. If at the creation time you have decomposed the basis surface between the parametric values VFirst, VLast the number of Bezier surfaces in the V direction depends on the number of knots included inside the interval [VFirst, VLast]. If you have decomposed the whole basis B-spline surface the number of Bezier surfaces NbVPatches is equal to the number of VKnots less one.");

// Enums

}