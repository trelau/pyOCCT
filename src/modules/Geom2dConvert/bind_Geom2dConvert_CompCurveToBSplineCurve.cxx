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
#include <Geom2d_BoundedCurve.hxx>
#include <Standard_TypeDef.hxx>
#include <Geom2d_BSplineCurve.hxx>
#include <Geom2dConvert_CompCurveToBSplineCurve.hxx>

void bind_Geom2dConvert_CompCurveToBSplineCurve(py::module &mod){

py::class_<Geom2dConvert_CompCurveToBSplineCurve> cls_Geom2dConvert_CompCurveToBSplineCurve(mod, "Geom2dConvert_CompCurveToBSplineCurve", "This algorithm converts and concat several curve in an BSplineCurve");

// Constructors
cls_Geom2dConvert_CompCurveToBSplineCurve.def(py::init<>());
cls_Geom2dConvert_CompCurveToBSplineCurve.def(py::init<const Convert_ParameterisationType>(), py::arg("Parameterisation"));
cls_Geom2dConvert_CompCurveToBSplineCurve.def(py::init<const opencascade::handle<Geom2d_BoundedCurve> &>(), py::arg("BasisCurve"));
cls_Geom2dConvert_CompCurveToBSplineCurve.def(py::init<const opencascade::handle<Geom2d_BoundedCurve> &, const Convert_ParameterisationType>(), py::arg("BasisCurve"), py::arg("Parameterisation"));

// Fields

// Methods
// cls_Geom2dConvert_CompCurveToBSplineCurve.def_static("operator new_", (void * (*)(size_t)) &Geom2dConvert_CompCurveToBSplineCurve::operator new, "None", py::arg("theSize"));
// cls_Geom2dConvert_CompCurveToBSplineCurve.def_static("operator delete_", (void (*)(void *)) &Geom2dConvert_CompCurveToBSplineCurve::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dConvert_CompCurveToBSplineCurve.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dConvert_CompCurveToBSplineCurve::operator new[], "None", py::arg("theSize"));
// cls_Geom2dConvert_CompCurveToBSplineCurve.def_static("operator delete[]_", (void (*)(void *)) &Geom2dConvert_CompCurveToBSplineCurve::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dConvert_CompCurveToBSplineCurve.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dConvert_CompCurveToBSplineCurve::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dConvert_CompCurveToBSplineCurve.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dConvert_CompCurveToBSplineCurve::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dConvert_CompCurveToBSplineCurve.def("Add", [](Geom2dConvert_CompCurveToBSplineCurve &self, const opencascade::handle<Geom2d_BoundedCurve> & a0, const Standard_Real a1) -> Standard_Boolean { return self.Add(a0, a1); });
cls_Geom2dConvert_CompCurveToBSplineCurve.def("Add", (Standard_Boolean (Geom2dConvert_CompCurveToBSplineCurve::*)(const opencascade::handle<Geom2d_BoundedCurve> &, const Standard_Real, const Standard_Boolean)) &Geom2dConvert_CompCurveToBSplineCurve::Add, "Append a curve in the BSpline Return False if the curve is not G0 with the BSplineCurve. Tolerance is used to check continuity and decrease Multiplicty at the common Knot After is usefull if BasisCurve is a closed curve .", py::arg("NewCurve"), py::arg("Tolerance"), py::arg("After"));
cls_Geom2dConvert_CompCurveToBSplineCurve.def("BSplineCurve", (opencascade::handle<Geom2d_BSplineCurve> (Geom2dConvert_CompCurveToBSplineCurve::*)() const) &Geom2dConvert_CompCurveToBSplineCurve::BSplineCurve, "None");
cls_Geom2dConvert_CompCurveToBSplineCurve.def("Clear", (void (Geom2dConvert_CompCurveToBSplineCurve::*)()) &Geom2dConvert_CompCurveToBSplineCurve::Clear, "Clear result curve");

// Enums

}