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
#include <Convert_ParameterisationType.hxx>
#include <Standard_Handle.hxx>
#include <Geom_BoundedCurve.hxx>
#include <Standard_TypeDef.hxx>
#include <Geom_BSplineCurve.hxx>
#include <GeomConvert_CompCurveToBSplineCurve.hxx>

void bind_GeomConvert_CompCurveToBSplineCurve(py::module &mod){

py::class_<GeomConvert_CompCurveToBSplineCurve> cls_GeomConvert_CompCurveToBSplineCurve(mod, "GeomConvert_CompCurveToBSplineCurve", "Algorithm converts and concat several curve in an BSplineCurve");

// Constructors
cls_GeomConvert_CompCurveToBSplineCurve.def(py::init<>());
cls_GeomConvert_CompCurveToBSplineCurve.def(py::init<const Convert_ParameterisationType>(), py::arg("Parameterisation"));
cls_GeomConvert_CompCurveToBSplineCurve.def(py::init<const opencascade::handle<Geom_BoundedCurve> &>(), py::arg("BasisCurve"));
cls_GeomConvert_CompCurveToBSplineCurve.def(py::init<const opencascade::handle<Geom_BoundedCurve> &, const Convert_ParameterisationType>(), py::arg("BasisCurve"), py::arg("Parameterisation"));

// Fields

// Methods
// cls_GeomConvert_CompCurveToBSplineCurve.def_static("operator new_", (void * (*)(size_t)) &GeomConvert_CompCurveToBSplineCurve::operator new, "None", py::arg("theSize"));
// cls_GeomConvert_CompCurveToBSplineCurve.def_static("operator delete_", (void (*)(void *)) &GeomConvert_CompCurveToBSplineCurve::operator delete, "None", py::arg("theAddress"));
// cls_GeomConvert_CompCurveToBSplineCurve.def_static("operator new[]_", (void * (*)(size_t)) &GeomConvert_CompCurveToBSplineCurve::operator new[], "None", py::arg("theSize"));
// cls_GeomConvert_CompCurveToBSplineCurve.def_static("operator delete[]_", (void (*)(void *)) &GeomConvert_CompCurveToBSplineCurve::operator delete[], "None", py::arg("theAddress"));
// cls_GeomConvert_CompCurveToBSplineCurve.def_static("operator new_", (void * (*)(size_t, void *)) &GeomConvert_CompCurveToBSplineCurve::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomConvert_CompCurveToBSplineCurve.def_static("operator delete_", (void (*)(void *, void *)) &GeomConvert_CompCurveToBSplineCurve::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomConvert_CompCurveToBSplineCurve.def("Add", [](GeomConvert_CompCurveToBSplineCurve &self, const opencascade::handle<Geom_BoundedCurve> & a0, const Standard_Real a1) -> Standard_Boolean { return self.Add(a0, a1); });
cls_GeomConvert_CompCurveToBSplineCurve.def("Add", [](GeomConvert_CompCurveToBSplineCurve &self, const opencascade::handle<Geom_BoundedCurve> & a0, const Standard_Real a1, const Standard_Boolean a2) -> Standard_Boolean { return self.Add(a0, a1, a2); });
cls_GeomConvert_CompCurveToBSplineCurve.def("Add", [](GeomConvert_CompCurveToBSplineCurve &self, const opencascade::handle<Geom_BoundedCurve> & a0, const Standard_Real a1, const Standard_Boolean a2, const Standard_Boolean a3) -> Standard_Boolean { return self.Add(a0, a1, a2, a3); });
cls_GeomConvert_CompCurveToBSplineCurve.def("Add", (Standard_Boolean (GeomConvert_CompCurveToBSplineCurve::*)(const opencascade::handle<Geom_BoundedCurve> &, const Standard_Real, const Standard_Boolean, const Standard_Boolean, const Standard_Integer)) &GeomConvert_CompCurveToBSplineCurve::Add, "Append a curve in the BSpline Return False if the curve is not G0 with the BSplineCurve. Tolerance is used to check continuity and decrease Multiplicity at the common Knot until MinM if MinM = 0, the common Knot can be removed", py::arg("NewCurve"), py::arg("Tolerance"), py::arg("After"), py::arg("WithRatio"), py::arg("MinM"));
cls_GeomConvert_CompCurveToBSplineCurve.def("BSplineCurve", (opencascade::handle<Geom_BSplineCurve> (GeomConvert_CompCurveToBSplineCurve::*)() const) &GeomConvert_CompCurveToBSplineCurve::BSplineCurve, "None");
cls_GeomConvert_CompCurveToBSplineCurve.def("Clear", (void (GeomConvert_CompCurveToBSplineCurve::*)()) &GeomConvert_CompCurveToBSplineCurve::Clear, "Clear a result curve");

// Enums

}