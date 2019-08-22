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
#include <IGESGeom_SplineCurve.hxx>
#include <Geom_BSplineCurve.hxx>
#include <Geom2d_BSplineCurve.hxx>
#include <IGESGeom_SplineSurface.hxx>
#include <Geom_BSplineSurface.hxx>
#include <IGESConvGeom_GeomBuilder.hxx>
#include <IGESConvGeom.hxx>

void bind_IGESConvGeom(py::module &mod){

py::class_<IGESConvGeom> cls_IGESConvGeom(mod, "IGESConvGeom", "This package is intended to gather geometric conversion which are not immediate but can be used for several purposes : mainly, standard conversion to and from CasCade geometric and topologic data, and adaptations of IGES files as required (as replacing Spline entities to BSpline equivalents).");

// Constructors

// Fields

// Methods
// cls_IGESConvGeom.def_static("operator new_", (void * (*)(size_t)) &IGESConvGeom::operator new, "None", py::arg("theSize"));
// cls_IGESConvGeom.def_static("operator delete_", (void (*)(void *)) &IGESConvGeom::operator delete, "None", py::arg("theAddress"));
// cls_IGESConvGeom.def_static("operator new[]_", (void * (*)(size_t)) &IGESConvGeom::operator new[], "None", py::arg("theSize"));
// cls_IGESConvGeom.def_static("operator delete[]_", (void (*)(void *)) &IGESConvGeom::operator delete[], "None", py::arg("theAddress"));
// cls_IGESConvGeom.def_static("operator new_", (void * (*)(size_t, void *)) &IGESConvGeom::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESConvGeom.def_static("operator delete_", (void (*)(void *, void *)) &IGESConvGeom::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESConvGeom.def_static("SplineCurveFromIGES_", (Standard_Integer (*)(const opencascade::handle<IGESGeom_SplineCurve> &, const Standard_Real, const Standard_Real, opencascade::handle<Geom_BSplineCurve> &)) &IGESConvGeom::SplineCurveFromIGES, "basic tool to build curves from IGESGeom (arrays of points, Transformations, evaluation of points in a datum) Converts a SplineCurve from IGES to a BSplineCurve from CasCade <epscoef> gives tolerance to consider coefficient to be nul <epsgeom> gives tolerance to consider poles to be equal The returned value is a status with these possible values : - 0 OK, done - 1 the result is not guaranteed to be C0 (with <epsgeom>) - 2 SplineType not processed (allowed : max 3) (no result produced) - 3 error during creation of control points (no result produced) - 4 polynomial equation is not correct (no result produced) - 5 less than one segment (no result produced)", py::arg("igesent"), py::arg("epscoef"), py::arg("epsgeom"), py::arg("result"));
cls_IGESConvGeom.def_static("IncreaseCurveContinuity_", [](const opencascade::handle<Geom_BSplineCurve> & a0, const Standard_Real a1) -> Standard_Integer { return IGESConvGeom::IncreaseCurveContinuity(a0, a1); });
cls_IGESConvGeom.def_static("IncreaseCurveContinuity_", (Standard_Integer (*)(const opencascade::handle<Geom_BSplineCurve> &, const Standard_Real, const Standard_Integer)) &IGESConvGeom::IncreaseCurveContinuity, "Tries to increase curve continuity with tolerance <epsgeom> <continuity> is the new desired continuity, can be 1 or 2 (more than 2 is considered as 2). Returns the new maximum continuity obtained on all knots. Remark that, for instance with <continuity> = 2, even if not all the knots can be passed to C2, all knots which can be are.", py::arg("curve"), py::arg("epsgeom"), py::arg("continuity"));
cls_IGESConvGeom.def_static("IncreaseCurveContinuity_", [](const opencascade::handle<Geom2d_BSplineCurve> & a0, const Standard_Real a1) -> Standard_Integer { return IGESConvGeom::IncreaseCurveContinuity(a0, a1); });
cls_IGESConvGeom.def_static("IncreaseCurveContinuity_", (Standard_Integer (*)(const opencascade::handle<Geom2d_BSplineCurve> &, const Standard_Real, const Standard_Integer)) &IGESConvGeom::IncreaseCurveContinuity, "None", py::arg("curve"), py::arg("epsgeom"), py::arg("continuity"));
cls_IGESConvGeom.def_static("SplineSurfaceFromIGES_", (Standard_Integer (*)(const opencascade::handle<IGESGeom_SplineSurface> &, const Standard_Real, const Standard_Real, opencascade::handle<Geom_BSplineSurface> &)) &IGESConvGeom::SplineSurfaceFromIGES, "Converts a SplineSurface from IGES to a BSplineSurface from CasCade <epscoef> gives tolerance to consider coefficient to be nul <epsgeom> gives tolerance to consider poles to be equal The returned value is a status with these possible values : - 0 OK, done - 1 the result is not guaranteed to be C0 (with <epsgeom>) - 2 degree is not compatible with code boundary type (warning) but C0 is OK - 3 idem but C0 is not guaranteed (warning) - 4 degree has been determined to be nul, either in U or V (no result produced) - 5 less than one segment in U or V (no result produced)", py::arg("igesent"), py::arg("epscoef"), py::arg("epsgeom"), py::arg("result"));
cls_IGESConvGeom.def_static("IncreaseSurfaceContinuity_", [](const opencascade::handle<Geom_BSplineSurface> & a0, const Standard_Real a1) -> Standard_Integer { return IGESConvGeom::IncreaseSurfaceContinuity(a0, a1); });
cls_IGESConvGeom.def_static("IncreaseSurfaceContinuity_", (Standard_Integer (*)(const opencascade::handle<Geom_BSplineSurface> &, const Standard_Real, const Standard_Integer)) &IGESConvGeom::IncreaseSurfaceContinuity, "Tries to increase Surface continuity with tolerance <epsgeom> <continuity> is the new desired continuity, can be 1 or 2 (more than 2 is considered as 2). Returns the new maximum continuity obtained on all knots. Remark that, for instance with <continuity> = 2, even if not all the knots can be passed to C2, all knots which can be are.", py::arg("surface"), py::arg("epsgeom"), py::arg("continuity"));

// Enums

}