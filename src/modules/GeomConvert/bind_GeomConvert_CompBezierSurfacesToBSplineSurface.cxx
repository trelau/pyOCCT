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
#include <TColGeom_Array2OfBezierSurface.hxx>
#include <Standard_TypeDef.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <GeomAbs_Shape.hxx>
#include <Standard_Handle.hxx>
#include <TColgp_HArray2OfPnt.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <TColStd_HArray1OfInteger.hxx>
#include <GeomConvert_CompBezierSurfacesToBSplineSurface.hxx>

void bind_GeomConvert_CompBezierSurfacesToBSplineSurface(py::module &mod){

py::class_<GeomConvert_CompBezierSurfacesToBSplineSurface, std::unique_ptr<GeomConvert_CompBezierSurfacesToBSplineSurface, Deleter<GeomConvert_CompBezierSurfacesToBSplineSurface>>> cls_GeomConvert_CompBezierSurfacesToBSplineSurface(mod, "GeomConvert_CompBezierSurfacesToBSplineSurface", "An algorithm to convert a grid of adjacent non-rational Bezier surfaces (with continuity CM) into a BSpline surface (with continuity CM). A CompBezierSurfacesToBSplineSurface object provides a framework for: - defining the grid of adjacent Bezier surfaces which is to be converted into a BSpline surface, - implementing the computation algorithm, and - consulting the results. Warning Do not attempt to convert rational Bezier surfaces using such an algorithm. Input is array of Bezier patch 1 2 3 4 -> VIndex [1, NbVPatches] -> VDirection ----------------------- 1 | | | | | ----------------------- 2 | | | | | ----------------------- 3 | | | | | ----------------------- UIndex [1, NbUPatches] Udirection");

// Constructors
cls_GeomConvert_CompBezierSurfacesToBSplineSurface.def(py::init<const TColGeom_Array2OfBezierSurface &>(), py::arg("Beziers"));
cls_GeomConvert_CompBezierSurfacesToBSplineSurface.def(py::init<const TColGeom_Array2OfBezierSurface &, const Standard_Real>(), py::arg("Beziers"), py::arg("Tolerance"));
cls_GeomConvert_CompBezierSurfacesToBSplineSurface.def(py::init<const TColGeom_Array2OfBezierSurface &, const Standard_Real, const Standard_Boolean>(), py::arg("Beziers"), py::arg("Tolerance"), py::arg("RemoveKnots"));
cls_GeomConvert_CompBezierSurfacesToBSplineSurface.def(py::init<const TColGeom_Array2OfBezierSurface &, const TColStd_Array1OfReal &, const TColStd_Array1OfReal &>(), py::arg("Beziers"), py::arg("UKnots"), py::arg("VKnots"));
cls_GeomConvert_CompBezierSurfacesToBSplineSurface.def(py::init<const TColGeom_Array2OfBezierSurface &, const TColStd_Array1OfReal &, const TColStd_Array1OfReal &, const GeomAbs_Shape>(), py::arg("Beziers"), py::arg("UKnots"), py::arg("VKnots"), py::arg("UContinuity"));
cls_GeomConvert_CompBezierSurfacesToBSplineSurface.def(py::init<const TColGeom_Array2OfBezierSurface &, const TColStd_Array1OfReal &, const TColStd_Array1OfReal &, const GeomAbs_Shape, const GeomAbs_Shape>(), py::arg("Beziers"), py::arg("UKnots"), py::arg("VKnots"), py::arg("UContinuity"), py::arg("VContinuity"));
cls_GeomConvert_CompBezierSurfacesToBSplineSurface.def(py::init<const TColGeom_Array2OfBezierSurface &, const TColStd_Array1OfReal &, const TColStd_Array1OfReal &, const GeomAbs_Shape, const GeomAbs_Shape, const Standard_Real>(), py::arg("Beziers"), py::arg("UKnots"), py::arg("VKnots"), py::arg("UContinuity"), py::arg("VContinuity"), py::arg("Tolerance"));

// Fields

// Methods
// cls_GeomConvert_CompBezierSurfacesToBSplineSurface.def_static("operator new_", (void * (*)(size_t)) &GeomConvert_CompBezierSurfacesToBSplineSurface::operator new, "None", py::arg("theSize"));
// cls_GeomConvert_CompBezierSurfacesToBSplineSurface.def_static("operator delete_", (void (*)(void *)) &GeomConvert_CompBezierSurfacesToBSplineSurface::operator delete, "None", py::arg("theAddress"));
// cls_GeomConvert_CompBezierSurfacesToBSplineSurface.def_static("operator new[]_", (void * (*)(size_t)) &GeomConvert_CompBezierSurfacesToBSplineSurface::operator new[], "None", py::arg("theSize"));
// cls_GeomConvert_CompBezierSurfacesToBSplineSurface.def_static("operator delete[]_", (void (*)(void *)) &GeomConvert_CompBezierSurfacesToBSplineSurface::operator delete[], "None", py::arg("theAddress"));
// cls_GeomConvert_CompBezierSurfacesToBSplineSurface.def_static("operator new_", (void * (*)(size_t, void *)) &GeomConvert_CompBezierSurfacesToBSplineSurface::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomConvert_CompBezierSurfacesToBSplineSurface.def_static("operator delete_", (void (*)(void *, void *)) &GeomConvert_CompBezierSurfacesToBSplineSurface::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomConvert_CompBezierSurfacesToBSplineSurface.def("NbUKnots", (Standard_Integer (GeomConvert_CompBezierSurfacesToBSplineSurface::*)() const) &GeomConvert_CompBezierSurfacesToBSplineSurface::NbUKnots, "Returns the number of knots in the U direction of the BSpline surface whose data is computed in this framework.");
cls_GeomConvert_CompBezierSurfacesToBSplineSurface.def("NbUPoles", (Standard_Integer (GeomConvert_CompBezierSurfacesToBSplineSurface::*)() const) &GeomConvert_CompBezierSurfacesToBSplineSurface::NbUPoles, "Returns number of poles in the U direction of the BSpline surface whose data is computed in this framework.");
cls_GeomConvert_CompBezierSurfacesToBSplineSurface.def("NbVKnots", (Standard_Integer (GeomConvert_CompBezierSurfacesToBSplineSurface::*)() const) &GeomConvert_CompBezierSurfacesToBSplineSurface::NbVKnots, "Returns the number of knots in the V direction of the BSpline surface whose data is computed in this framework.");
cls_GeomConvert_CompBezierSurfacesToBSplineSurface.def("NbVPoles", (Standard_Integer (GeomConvert_CompBezierSurfacesToBSplineSurface::*)() const) &GeomConvert_CompBezierSurfacesToBSplineSurface::NbVPoles, "Returns the number of poles in the V direction of the BSpline surface whose data is computed in this framework.");
cls_GeomConvert_CompBezierSurfacesToBSplineSurface.def("Poles", (const opencascade::handle<TColgp_HArray2OfPnt> & (GeomConvert_CompBezierSurfacesToBSplineSurface::*)() const) &GeomConvert_CompBezierSurfacesToBSplineSurface::Poles, "Returns the table of poles of the BSpline surface whose data is computed in this framework.");
cls_GeomConvert_CompBezierSurfacesToBSplineSurface.def("UKnots", (const opencascade::handle<TColStd_HArray1OfReal> & (GeomConvert_CompBezierSurfacesToBSplineSurface::*)() const) &GeomConvert_CompBezierSurfacesToBSplineSurface::UKnots, "Returns the knots table for the u parametric direction of the BSpline surface whose data is computed in this framework.");
cls_GeomConvert_CompBezierSurfacesToBSplineSurface.def("UDegree", (Standard_Integer (GeomConvert_CompBezierSurfacesToBSplineSurface::*)() const) &GeomConvert_CompBezierSurfacesToBSplineSurface::UDegree, "Returns the degree for the u parametric direction of the BSpline surface whose data is computed in this framework.");
cls_GeomConvert_CompBezierSurfacesToBSplineSurface.def("VKnots", (const opencascade::handle<TColStd_HArray1OfReal> & (GeomConvert_CompBezierSurfacesToBSplineSurface::*)() const) &GeomConvert_CompBezierSurfacesToBSplineSurface::VKnots, "Returns the knots table for the v parametric direction of the BSpline surface whose data is computed in this framework.");
cls_GeomConvert_CompBezierSurfacesToBSplineSurface.def("VDegree", (Standard_Integer (GeomConvert_CompBezierSurfacesToBSplineSurface::*)() const) &GeomConvert_CompBezierSurfacesToBSplineSurface::VDegree, "Returns the degree for the v parametric direction of the BSpline surface whose data is computed in this framework.");
cls_GeomConvert_CompBezierSurfacesToBSplineSurface.def("UMultiplicities", (const opencascade::handle<TColStd_HArray1OfInteger> & (GeomConvert_CompBezierSurfacesToBSplineSurface::*)() const) &GeomConvert_CompBezierSurfacesToBSplineSurface::UMultiplicities, "Returns the multiplicities table for the u parametric direction of the knots of the BSpline surface whose data is computed in this framework.");
cls_GeomConvert_CompBezierSurfacesToBSplineSurface.def("VMultiplicities", (const opencascade::handle<TColStd_HArray1OfInteger> & (GeomConvert_CompBezierSurfacesToBSplineSurface::*)() const) &GeomConvert_CompBezierSurfacesToBSplineSurface::VMultiplicities, "-- Returns the multiplicities table for the v parametric direction of the knots of the BSpline surface whose data is computed in this framework.");
cls_GeomConvert_CompBezierSurfacesToBSplineSurface.def("IsDone", (Standard_Boolean (GeomConvert_CompBezierSurfacesToBSplineSurface::*)() const) &GeomConvert_CompBezierSurfacesToBSplineSurface::IsDone, "Returns true if the conversion was successful. Unless an exception was raised at the time of construction, the conversion of the Bezier surface grid assigned to this algorithm is always carried out. IsDone returns false if the constraints defined at the time of construction cannot be respected. This occurs when there is an incompatibility between a required degree of continuity on the BSpline surface, and the maximum tolerance accepted for local deformations of the surface. In such a case the computed data does not satisfy all the initial constraints.");

// Enums

}