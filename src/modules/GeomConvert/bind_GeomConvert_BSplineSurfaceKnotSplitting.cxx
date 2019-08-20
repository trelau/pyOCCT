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
#include <TColStd_Array1OfInteger.hxx>
#include <TColStd_HArray1OfInteger.hxx>
#include <GeomConvert_BSplineSurfaceKnotSplitting.hxx>

void bind_GeomConvert_BSplineSurfaceKnotSplitting(py::module &mod){

py::class_<GeomConvert_BSplineSurfaceKnotSplitting, std::unique_ptr<GeomConvert_BSplineSurfaceKnotSplitting>> cls_GeomConvert_BSplineSurfaceKnotSplitting(mod, "GeomConvert_BSplineSurfaceKnotSplitting", "An algorithm to determine isoparametric curves along which a BSpline surface should be split in order to obtain patches of the same continuity. The continuity order is given at the construction time. It is possible to compute the surface patches corresponding to the splitting with the method of package SplitBSplineSurface. For a B-spline surface the discontinuities are localised at the knot values. Between two knots values the B-spline is infinitely continuously differentiable. For each parametric direction at a knot of range index the continuity in this direction is equal to : Degree - Mult (Index) where Degree is the degree of the basis B-spline functions and Mult the multiplicity of the knot of range Index in the given direction. If for your computation you need to have B-spline surface with a minima of continuity it can be interesting to know between which knot values, a B-spline patch, has a continuity of given order. This algorithm computes the indexes of the knots where you should split the surface, to obtain patches with a constant continuity given at the construction time. If you just want to compute the local derivatives on the surface you don't need to create the BSpline patches, you can use the functions LocalD1, LocalD2, LocalD3, LocalDN of the class BSplineSurface from package Geom.");

// Constructors
cls_GeomConvert_BSplineSurfaceKnotSplitting.def(py::init<const opencascade::handle<Geom_BSplineSurface> &, const Standard_Integer, const Standard_Integer>(), py::arg("BasisSurface"), py::arg("UContinuityRange"), py::arg("VContinuityRange"));

// Fields

// Methods
// cls_GeomConvert_BSplineSurfaceKnotSplitting.def_static("operator new_", (void * (*)(size_t)) &GeomConvert_BSplineSurfaceKnotSplitting::operator new, "None", py::arg("theSize"));
// cls_GeomConvert_BSplineSurfaceKnotSplitting.def_static("operator delete_", (void (*)(void *)) &GeomConvert_BSplineSurfaceKnotSplitting::operator delete, "None", py::arg("theAddress"));
// cls_GeomConvert_BSplineSurfaceKnotSplitting.def_static("operator new[]_", (void * (*)(size_t)) &GeomConvert_BSplineSurfaceKnotSplitting::operator new[], "None", py::arg("theSize"));
// cls_GeomConvert_BSplineSurfaceKnotSplitting.def_static("operator delete[]_", (void (*)(void *)) &GeomConvert_BSplineSurfaceKnotSplitting::operator delete[], "None", py::arg("theAddress"));
// cls_GeomConvert_BSplineSurfaceKnotSplitting.def_static("operator new_", (void * (*)(size_t, void *)) &GeomConvert_BSplineSurfaceKnotSplitting::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomConvert_BSplineSurfaceKnotSplitting.def_static("operator delete_", (void (*)(void *, void *)) &GeomConvert_BSplineSurfaceKnotSplitting::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomConvert_BSplineSurfaceKnotSplitting.def("NbUSplits", (Standard_Integer (GeomConvert_BSplineSurfaceKnotSplitting::*)() const) &GeomConvert_BSplineSurfaceKnotSplitting::NbUSplits, "Returns the number of u-isoparametric curves along which the analysed BSpline surface should be split in order to obtain patches with the continuity required by this framework. The parameters which define these curves are knot values in the corresponding parametric direction. Note that the four curves which bound the surface are counted among these splitting curves.");
cls_GeomConvert_BSplineSurfaceKnotSplitting.def("NbVSplits", (Standard_Integer (GeomConvert_BSplineSurfaceKnotSplitting::*)() const) &GeomConvert_BSplineSurfaceKnotSplitting::NbVSplits, "Returns the number of v-isoparametric curves along which the analysed BSpline surface should be split in order to obtain patches with the continuity required by this framework. The parameters which define these curves are knot values in the corresponding parametric direction. Note that the four curves which bound the surface are counted among these splitting curves.");
cls_GeomConvert_BSplineSurfaceKnotSplitting.def("Splitting", (void (GeomConvert_BSplineSurfaceKnotSplitting::*)(TColStd_Array1OfInteger &, TColStd_Array1OfInteger &) const) &GeomConvert_BSplineSurfaceKnotSplitting::Splitting, "Loads the USplit and VSplit tables with the split knots values computed in this framework. Each value in these tables is an index in the knots table corresponding to the u or v parametric direction of the BSpline surface analysed by this algorithm. The USplit and VSplit values are given in ascending order and comprise the indices of the knots which give the first and last isoparametric curves of the surface in the corresponding parametric direction. Use two consecutive values from the USplit table and two consecutive values from the VSplit table as arguments of the global function SplitBSplineSurface (provided by the package GeomConvert) to split the surface. Exceptions Standard_DimensionError if: - the array USplit was not created with the following bounds: - 1 , and - the number of split knots in the u parametric direction computed in this framework (as given by the function NbUSplits); or - the array VSplit was not created with the following bounds: - 1 , and - the number of split knots in the v parametric direction computed in this framework (as given by the function NbVSplits).", py::arg("USplit"), py::arg("VSplit"));
cls_GeomConvert_BSplineSurfaceKnotSplitting.def("USplitValue", (Standard_Integer (GeomConvert_BSplineSurfaceKnotSplitting::*)(const Standard_Integer) const) &GeomConvert_BSplineSurfaceKnotSplitting::USplitValue, "Returns the split knot of index UIndex to the split knots table for the u parametric direction computed in this framework. The returned value is an index in the knots table relative to the u parametric direction of the BSpline surface analysed by this algorithm. Note: If UIndex is equal to 1, or to the number of split knots for the u parametric direction computed in this framework, the corresponding knot gives the parameter of one of the bounding curves of the surface. Exceptions Standard_RangeError if UIndex is less than 1 or greater than the number of split knots for the u parametric direction computed in this framework.", py::arg("UIndex"));
cls_GeomConvert_BSplineSurfaceKnotSplitting.def("VSplitValue", (Standard_Integer (GeomConvert_BSplineSurfaceKnotSplitting::*)(const Standard_Integer) const) &GeomConvert_BSplineSurfaceKnotSplitting::VSplitValue, "Returns the split knot of index VIndex to the split knots table for the v parametric direction computed in this framework. The returned value is an index in the knots table relative to the v parametric direction of the BSpline surface analysed by this algorithm. Note: If UIndex is equal to 1, or to the number of split knots for the v parametric direction computed in this framework, the corresponding knot gives the parameter of one of the bounding curves of the surface. Exceptions Standard_RangeError if VIndex is less than 1 or greater than the number of split knots for the v parametric direction computed in this framework.", py::arg("VIndex"));

// Enums

}