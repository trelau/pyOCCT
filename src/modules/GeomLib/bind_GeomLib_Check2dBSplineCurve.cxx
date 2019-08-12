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
#include <Geom2d_BSplineCurve.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt2d.hxx>
#include <GeomLib_Check2dBSplineCurve.hxx>

void bind_GeomLib_Check2dBSplineCurve(py::module &mod){

py::class_<GeomLib_Check2dBSplineCurve, std::unique_ptr<GeomLib_Check2dBSplineCurve, Deleter<GeomLib_Check2dBSplineCurve>>> cls_GeomLib_Check2dBSplineCurve(mod, "GeomLib_Check2dBSplineCurve", "Checks for the end tangents : wether or not those are reversed");

// Constructors
cls_GeomLib_Check2dBSplineCurve.def(py::init<const opencascade::handle<Geom2d_BSplineCurve> &, const Standard_Real, const Standard_Real>(), py::arg("Curve"), py::arg("Tolerance"), py::arg("AngularTolerance"));

// Fields

// Methods
// cls_GeomLib_Check2dBSplineCurve.def_static("operator new_", (void * (*)(size_t)) &GeomLib_Check2dBSplineCurve::operator new, "None", py::arg("theSize"));
// cls_GeomLib_Check2dBSplineCurve.def_static("operator delete_", (void (*)(void *)) &GeomLib_Check2dBSplineCurve::operator delete, "None", py::arg("theAddress"));
// cls_GeomLib_Check2dBSplineCurve.def_static("operator new[]_", (void * (*)(size_t)) &GeomLib_Check2dBSplineCurve::operator new[], "None", py::arg("theSize"));
// cls_GeomLib_Check2dBSplineCurve.def_static("operator delete[]_", (void (*)(void *)) &GeomLib_Check2dBSplineCurve::operator delete[], "None", py::arg("theAddress"));
// cls_GeomLib_Check2dBSplineCurve.def_static("operator new_", (void * (*)(size_t, void *)) &GeomLib_Check2dBSplineCurve::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomLib_Check2dBSplineCurve.def_static("operator delete_", (void (*)(void *, void *)) &GeomLib_Check2dBSplineCurve::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomLib_Check2dBSplineCurve.def("IsDone", (Standard_Boolean (GeomLib_Check2dBSplineCurve::*)() const) &GeomLib_Check2dBSplineCurve::IsDone, "None");
cls_GeomLib_Check2dBSplineCurve.def("NeedTangentFix", [](GeomLib_Check2dBSplineCurve &self, Standard_Boolean & FirstFlag, Standard_Boolean & SecondFlag){ self.NeedTangentFix(FirstFlag, SecondFlag); return std::tuple<Standard_Boolean &, Standard_Boolean &>(FirstFlag, SecondFlag); }, "None", py::arg("FirstFlag"), py::arg("SecondFlag"));
cls_GeomLib_Check2dBSplineCurve.def("FixTangent", (void (GeomLib_Check2dBSplineCurve::*)(const Standard_Boolean, const Standard_Boolean)) &GeomLib_Check2dBSplineCurve::FixTangent, "None", py::arg("FirstFlag"), py::arg("LastFlag"));
cls_GeomLib_Check2dBSplineCurve.def("FixedTangent", (opencascade::handle<Geom2d_BSplineCurve> (GeomLib_Check2dBSplineCurve::*)(const Standard_Boolean, const Standard_Boolean)) &GeomLib_Check2dBSplineCurve::FixedTangent, "modifies the curve by fixing the first or the last tangencies", py::arg("FirstFlag"), py::arg("LastFlag"));

// Enums

}