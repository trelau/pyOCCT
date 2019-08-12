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
#include <TColgp_Array1OfPnt.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <GeomLib_InterpolationErrors.hxx>
#include <Standard_Handle.hxx>
#include <Geom_BSplineCurve.hxx>
#include <GeomLib_Interpolate.hxx>

void bind_GeomLib_Interpolate(py::module &mod){

py::class_<GeomLib_Interpolate, std::unique_ptr<GeomLib_Interpolate, Deleter<GeomLib_Interpolate>>> cls_GeomLib_Interpolate(mod, "GeomLib_Interpolate", "this class is used to construct a BSpline curve by interpolation of points at given parameters The continuity of the curve is degree - 1 and the method used when boundary condition are not given is to use odd degrees and null the derivatives on both sides from degree -1 down to (degree+1) / 2 When even degree is given the returned curve is of degree - 1 so that the degree of the curve is odd");

// Constructors
cls_GeomLib_Interpolate.def(py::init<const Standard_Integer, const Standard_Integer, const TColgp_Array1OfPnt &, const TColStd_Array1OfReal &>(), py::arg("Degree"), py::arg("NumPoints"), py::arg("Points"), py::arg("Parameters"));

// Fields

// Methods
// cls_GeomLib_Interpolate.def_static("operator new_", (void * (*)(size_t)) &GeomLib_Interpolate::operator new, "None", py::arg("theSize"));
// cls_GeomLib_Interpolate.def_static("operator delete_", (void (*)(void *)) &GeomLib_Interpolate::operator delete, "None", py::arg("theAddress"));
// cls_GeomLib_Interpolate.def_static("operator new[]_", (void * (*)(size_t)) &GeomLib_Interpolate::operator new[], "None", py::arg("theSize"));
// cls_GeomLib_Interpolate.def_static("operator delete[]_", (void (*)(void *)) &GeomLib_Interpolate::operator delete[], "None", py::arg("theAddress"));
// cls_GeomLib_Interpolate.def_static("operator new_", (void * (*)(size_t, void *)) &GeomLib_Interpolate::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomLib_Interpolate.def_static("operator delete_", (void (*)(void *, void *)) &GeomLib_Interpolate::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomLib_Interpolate.def("IsDone", (Standard_Boolean (GeomLib_Interpolate::*)() const) &GeomLib_Interpolate::IsDone, "returns if everything went OK");
cls_GeomLib_Interpolate.def("Error", (GeomLib_InterpolationErrors (GeomLib_Interpolate::*)() const) &GeomLib_Interpolate::Error, "returns the error type if any");
cls_GeomLib_Interpolate.def("Curve", (opencascade::handle<Geom_BSplineCurve> (GeomLib_Interpolate::*)() const) &GeomLib_Interpolate::Curve, "returns the interpolated curve of the requested degree");

// Enums

}