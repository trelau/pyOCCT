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
#include <Geom2d_Curve.hxx>
#include <MAT_Side.hxx>
#include <Standard_TypeDef.hxx>
#include <Geom2d_TrimmedCurve.hxx>
#include <TColGeom2d_SequenceOfCurve.hxx>
#include <MAT2d_CutCurve.hxx>

void bind_MAT2d_CutCurve(py::module &mod){

py::class_<MAT2d_CutCurve, std::unique_ptr<MAT2d_CutCurve, Deleter<MAT2d_CutCurve>>> cls_MAT2d_CutCurve(mod, "MAT2d_CutCurve", "Cuts a curve at the extremas of curvature and at the inflections. Constructs a trimmed Curve for each interval.");

// Constructors
cls_MAT2d_CutCurve.def(py::init<>());
cls_MAT2d_CutCurve.def(py::init<const opencascade::handle<Geom2d_Curve> &>(), py::arg("C"));

// Fields

// Methods
// cls_MAT2d_CutCurve.def_static("operator new_", (void * (*)(size_t)) &MAT2d_CutCurve::operator new, "None", py::arg("theSize"));
// cls_MAT2d_CutCurve.def_static("operator delete_", (void (*)(void *)) &MAT2d_CutCurve::operator delete, "None", py::arg("theAddress"));
// cls_MAT2d_CutCurve.def_static("operator new[]_", (void * (*)(size_t)) &MAT2d_CutCurve::operator new[], "None", py::arg("theSize"));
// cls_MAT2d_CutCurve.def_static("operator delete[]_", (void (*)(void *)) &MAT2d_CutCurve::operator delete[], "None", py::arg("theAddress"));
// cls_MAT2d_CutCurve.def_static("operator new_", (void * (*)(size_t, void *)) &MAT2d_CutCurve::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_MAT2d_CutCurve.def_static("operator delete_", (void (*)(void *, void *)) &MAT2d_CutCurve::operator delete, "None", py::arg(""), py::arg(""));
cls_MAT2d_CutCurve.def("Perform", (void (MAT2d_CutCurve::*)(const opencascade::handle<Geom2d_Curve> &)) &MAT2d_CutCurve::Perform, "Cuts a curve at the extremas of curvature and at the inflections.", py::arg("C"));
// cls_MAT2d_CutCurve.def("Perform", (void (MAT2d_CutCurve::*)(const opencascade::handle<Geom2d_Curve> &, const MAT_Side)) &MAT2d_CutCurve::Perform, "Cuts a curve at the inflections, and at the extremas of curvature where the concavity is on <aSide>.", py::arg("C"), py::arg("aSide"));
// cls_MAT2d_CutCurve.def("PerformInf", (void (MAT2d_CutCurve::*)(const opencascade::handle<Geom2d_Curve> &)) &MAT2d_CutCurve::PerformInf, "Cuts a curve at the inflections.", py::arg("C"));
cls_MAT2d_CutCurve.def("UnModified", (Standard_Boolean (MAT2d_CutCurve::*)() const) &MAT2d_CutCurve::UnModified, "Returns True if the curve is not cut.");
cls_MAT2d_CutCurve.def("NbCurves", (Standard_Integer (MAT2d_CutCurve::*)() const) &MAT2d_CutCurve::NbCurves, "Returns the number of curves. it's allways greatest than 2.");
cls_MAT2d_CutCurve.def("Value", (opencascade::handle<Geom2d_TrimmedCurve> (MAT2d_CutCurve::*)(const Standard_Integer) const) &MAT2d_CutCurve::Value, "Returns the Indexth curve. raises if Index not in the range [1,NbCurves()]", py::arg("Index"));

// Enums

}