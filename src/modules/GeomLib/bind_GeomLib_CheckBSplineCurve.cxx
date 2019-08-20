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
#include <Geom_BSplineCurve.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <GeomLib_CheckBSplineCurve.hxx>

void bind_GeomLib_CheckBSplineCurve(py::module &mod){

py::class_<GeomLib_CheckBSplineCurve, std::unique_ptr<GeomLib_CheckBSplineCurve>> cls_GeomLib_CheckBSplineCurve(mod, "GeomLib_CheckBSplineCurve", "Checks for the end tangents : wether or not those are reversed regarding the third or n-3rd control");

// Constructors
cls_GeomLib_CheckBSplineCurve.def(py::init<const opencascade::handle<Geom_BSplineCurve> &, const Standard_Real, const Standard_Real>(), py::arg("Curve"), py::arg("Tolerance"), py::arg("AngularTolerance"));

// Fields

// Methods
// cls_GeomLib_CheckBSplineCurve.def_static("operator new_", (void * (*)(size_t)) &GeomLib_CheckBSplineCurve::operator new, "None", py::arg("theSize"));
// cls_GeomLib_CheckBSplineCurve.def_static("operator delete_", (void (*)(void *)) &GeomLib_CheckBSplineCurve::operator delete, "None", py::arg("theAddress"));
// cls_GeomLib_CheckBSplineCurve.def_static("operator new[]_", (void * (*)(size_t)) &GeomLib_CheckBSplineCurve::operator new[], "None", py::arg("theSize"));
// cls_GeomLib_CheckBSplineCurve.def_static("operator delete[]_", (void (*)(void *)) &GeomLib_CheckBSplineCurve::operator delete[], "None", py::arg("theAddress"));
// cls_GeomLib_CheckBSplineCurve.def_static("operator new_", (void * (*)(size_t, void *)) &GeomLib_CheckBSplineCurve::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomLib_CheckBSplineCurve.def_static("operator delete_", (void (*)(void *, void *)) &GeomLib_CheckBSplineCurve::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomLib_CheckBSplineCurve.def("IsDone", (Standard_Boolean (GeomLib_CheckBSplineCurve::*)() const) &GeomLib_CheckBSplineCurve::IsDone, "None");
cls_GeomLib_CheckBSplineCurve.def("NeedTangentFix", [](GeomLib_CheckBSplineCurve &self, Standard_Boolean & FirstFlag, Standard_Boolean & SecondFlag){ self.NeedTangentFix(FirstFlag, SecondFlag); return std::tuple<Standard_Boolean &, Standard_Boolean &>(FirstFlag, SecondFlag); }, "None", py::arg("FirstFlag"), py::arg("SecondFlag"));
cls_GeomLib_CheckBSplineCurve.def("FixTangent", (void (GeomLib_CheckBSplineCurve::*)(const Standard_Boolean, const Standard_Boolean)) &GeomLib_CheckBSplineCurve::FixTangent, "None", py::arg("FirstFlag"), py::arg("LastFlag"));
cls_GeomLib_CheckBSplineCurve.def("FixedTangent", (opencascade::handle<Geom_BSplineCurve> (GeomLib_CheckBSplineCurve::*)(const Standard_Boolean, const Standard_Boolean)) &GeomLib_CheckBSplineCurve::FixedTangent, "modifies the curve by fixing the first or the last tangencies", py::arg("FirstFlag"), py::arg("LastFlag"));

// Enums

}