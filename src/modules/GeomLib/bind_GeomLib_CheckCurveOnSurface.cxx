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
#include <Geom_Curve.hxx>
#include <Geom_Surface.hxx>
#include <Standard_TypeDef.hxx>
#include <Precision.hxx>
#include <Geom2d_Curve.hxx>
#include <GeomLib_CheckCurveOnSurface.hxx>

void bind_GeomLib_CheckCurveOnSurface(py::module &mod){

py::class_<GeomLib_CheckCurveOnSurface, std::unique_ptr<GeomLib_CheckCurveOnSurface, Deleter<GeomLib_CheckCurveOnSurface>>> cls_GeomLib_CheckCurveOnSurface(mod, "GeomLib_CheckCurveOnSurface", "Computes the max distance between 3D-curve and 2D-curve in some surface.");

// Constructors
cls_GeomLib_CheckCurveOnSurface.def(py::init<>());
cls_GeomLib_CheckCurveOnSurface.def(py::init<const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real>(), py::arg("theCurve"), py::arg("theSurface"), py::arg("theFirst"), py::arg("theLast"));
cls_GeomLib_CheckCurveOnSurface.def(py::init<const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("theCurve"), py::arg("theSurface"), py::arg("theFirst"), py::arg("theLast"), py::arg("theTolRange"));

// Fields

// Methods
// cls_GeomLib_CheckCurveOnSurface.def_static("operator new_", (void * (*)(size_t)) &GeomLib_CheckCurveOnSurface::operator new, "None", py::arg("theSize"));
// cls_GeomLib_CheckCurveOnSurface.def_static("operator delete_", (void (*)(void *)) &GeomLib_CheckCurveOnSurface::operator delete, "None", py::arg("theAddress"));
// cls_GeomLib_CheckCurveOnSurface.def_static("operator new[]_", (void * (*)(size_t)) &GeomLib_CheckCurveOnSurface::operator new[], "None", py::arg("theSize"));
// cls_GeomLib_CheckCurveOnSurface.def_static("operator delete[]_", (void (*)(void *)) &GeomLib_CheckCurveOnSurface::operator delete[], "None", py::arg("theAddress"));
// cls_GeomLib_CheckCurveOnSurface.def_static("operator new_", (void * (*)(size_t, void *)) &GeomLib_CheckCurveOnSurface::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomLib_CheckCurveOnSurface.def_static("operator delete_", (void (*)(void *, void *)) &GeomLib_CheckCurveOnSurface::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomLib_CheckCurveOnSurface.def("Init", [](GeomLib_CheckCurveOnSurface &self, const opencascade::handle<Geom_Curve> & a0, const opencascade::handle<Geom_Surface> & a1, const Standard_Real a2, const Standard_Real a3) -> void { return self.Init(a0, a1, a2, a3); });
cls_GeomLib_CheckCurveOnSurface.def("Init", (void (GeomLib_CheckCurveOnSurface::*)(const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const Standard_Real)) &GeomLib_CheckCurveOnSurface::Init, "Sets the data for the algorithm", py::arg("theCurve"), py::arg("theSurface"), py::arg("theFirst"), py::arg("theLast"), py::arg("theTolRange"));
cls_GeomLib_CheckCurveOnSurface.def("Init", (void (GeomLib_CheckCurveOnSurface::*)()) &GeomLib_CheckCurveOnSurface::Init, "Initializes all members by dafault values");
cls_GeomLib_CheckCurveOnSurface.def("Perform", [](GeomLib_CheckCurveOnSurface &self, const opencascade::handle<Geom2d_Curve> & a0) -> void { return self.Perform(a0); });
cls_GeomLib_CheckCurveOnSurface.def("Perform", (void (GeomLib_CheckCurveOnSurface::*)(const opencascade::handle<Geom2d_Curve> &, const Standard_Boolean)) &GeomLib_CheckCurveOnSurface::Perform, "Computes the max distance for the 3d curve <myCurve> and 2d curve <thePCurve> If isTheMultyTheadDisabled == TRUE then computation will be made without any parallelization.", py::arg("thePCurve"), py::arg("isTheMultyTheradDisabled"));
cls_GeomLib_CheckCurveOnSurface.def("Curve", (const opencascade::handle<Geom_Curve> & (GeomLib_CheckCurveOnSurface::*)() const) &GeomLib_CheckCurveOnSurface::Curve, "Returns my3DCurve");
cls_GeomLib_CheckCurveOnSurface.def("Surface", (const opencascade::handle<Geom_Surface> & (GeomLib_CheckCurveOnSurface::*)() const) &GeomLib_CheckCurveOnSurface::Surface, "Returns mySurface");
cls_GeomLib_CheckCurveOnSurface.def("Range", [](GeomLib_CheckCurveOnSurface &self, Standard_Real & theFirst, Standard_Real & theLast){ self.Range(theFirst, theLast); return std::tuple<Standard_Real &, Standard_Real &>(theFirst, theLast); }, "Returns first and last parameter of the curves (2D- and 3D-curves are considered to have same range)", py::arg("theFirst"), py::arg("theLast"));
cls_GeomLib_CheckCurveOnSurface.def("IsDone", (Standard_Boolean (GeomLib_CheckCurveOnSurface::*)() const) &GeomLib_CheckCurveOnSurface::IsDone, "Returns true if the max distance has been found");
cls_GeomLib_CheckCurveOnSurface.def("ErrorStatus", (Standard_Integer (GeomLib_CheckCurveOnSurface::*)() const) &GeomLib_CheckCurveOnSurface::ErrorStatus, "Returns error status The possible values are: 0 - OK; 1 - null curve or surface or 2d curve; 2 - invalid parametric range; 3 - error in calculations.");
cls_GeomLib_CheckCurveOnSurface.def("MaxDistance", (Standard_Real (GeomLib_CheckCurveOnSurface::*)() const) &GeomLib_CheckCurveOnSurface::MaxDistance, "Returns max distance");
cls_GeomLib_CheckCurveOnSurface.def("MaxParameter", (Standard_Real (GeomLib_CheckCurveOnSurface::*)() const) &GeomLib_CheckCurveOnSurface::MaxParameter, "Returns parameter in which the distance is maximal");

// Enums

}