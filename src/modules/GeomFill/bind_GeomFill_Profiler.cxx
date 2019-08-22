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
#include <Standard_TypeDef.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <TColGeom_SequenceOfCurve.hxx>
#include <GeomFill_Profiler.hxx>

void bind_GeomFill_Profiler(py::module &mod){

py::class_<GeomFill_Profiler> cls_GeomFill_Profiler(mod, "GeomFill_Profiler", "Evaluation of the common BSplineProfile of a group of curves from Geom. All the curves will have the same degree, the same knot-vector, so the same number of poles.");

// Constructors
cls_GeomFill_Profiler.def(py::init<>());

// Fields

// Methods
// cls_GeomFill_Profiler.def_static("operator new_", (void * (*)(size_t)) &GeomFill_Profiler::operator new, "None", py::arg("theSize"));
// cls_GeomFill_Profiler.def_static("operator delete_", (void (*)(void *)) &GeomFill_Profiler::operator delete, "None", py::arg("theAddress"));
// cls_GeomFill_Profiler.def_static("operator new[]_", (void * (*)(size_t)) &GeomFill_Profiler::operator new[], "None", py::arg("theSize"));
// cls_GeomFill_Profiler.def_static("operator delete[]_", (void (*)(void *)) &GeomFill_Profiler::operator delete[], "None", py::arg("theAddress"));
// cls_GeomFill_Profiler.def_static("operator new_", (void * (*)(size_t, void *)) &GeomFill_Profiler::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomFill_Profiler.def_static("operator delete_", (void (*)(void *, void *)) &GeomFill_Profiler::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomFill_Profiler.def("AddCurve", (void (GeomFill_Profiler::*)(const opencascade::handle<Geom_Curve> &)) &GeomFill_Profiler::AddCurve, "None", py::arg("Curve"));
cls_GeomFill_Profiler.def("Perform", (void (GeomFill_Profiler::*)(const Standard_Real)) &GeomFill_Profiler::Perform, "Converts all curves to BSplineCurves. Set them to the common profile. <PTol> is used to compare 2 knots.", py::arg("PTol"));
cls_GeomFill_Profiler.def("Degree", (Standard_Integer (GeomFill_Profiler::*)() const) &GeomFill_Profiler::Degree, "Raises if not yet perform");
cls_GeomFill_Profiler.def("IsPeriodic", (Standard_Boolean (GeomFill_Profiler::*)() const) &GeomFill_Profiler::IsPeriodic, "None");
cls_GeomFill_Profiler.def("NbPoles", (Standard_Integer (GeomFill_Profiler::*)() const) &GeomFill_Profiler::NbPoles, "Raises if not yet perform");
cls_GeomFill_Profiler.def("Poles", (void (GeomFill_Profiler::*)(const Standard_Integer, TColgp_Array1OfPnt &) const) &GeomFill_Profiler::Poles, "returns in <Poles> the poles of the BSplineCurve from index <Index> adjusting to the current profile. Raises if not yet perform Raises if <Index> not in the range [1,NbCurves] if the length of <Poles> is not equal to NbPoles().", py::arg("Index"), py::arg("Poles"));
cls_GeomFill_Profiler.def("Weights", (void (GeomFill_Profiler::*)(const Standard_Integer, TColStd_Array1OfReal &) const) &GeomFill_Profiler::Weights, "returns in <Weights> the weights of the BSplineCurve from index <Index> adjusting to the current profile. Raises if not yet perform Raises if <Index> not in the range [1,NbCurves] or if the length of <Weights> is not equal to NbPoles().", py::arg("Index"), py::arg("Weights"));
cls_GeomFill_Profiler.def("NbKnots", (Standard_Integer (GeomFill_Profiler::*)() const) &GeomFill_Profiler::NbKnots, "Raises if not yet perform");
cls_GeomFill_Profiler.def("KnotsAndMults", (void (GeomFill_Profiler::*)(TColStd_Array1OfReal &, TColStd_Array1OfInteger &) const) &GeomFill_Profiler::KnotsAndMults, "Raises if not yet perform Raises if the lengthes of <Knots> and <Mults> are not equal to NbKnots().", py::arg("Knots"), py::arg("Mults"));
cls_GeomFill_Profiler.def("Curve", (const opencascade::handle<Geom_Curve> & (GeomFill_Profiler::*)(const Standard_Integer) const) &GeomFill_Profiler::Curve, "None", py::arg("Index"));

// Enums

}