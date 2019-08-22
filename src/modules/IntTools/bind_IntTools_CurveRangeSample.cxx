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
#include <IntTools_BaseRangeSample.hxx>
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <IntTools_CurveRangeSample.hxx>
#include <IntTools_Range.hxx>

void bind_IntTools_CurveRangeSample(py::module &mod){

py::class_<IntTools_CurveRangeSample, IntTools_BaseRangeSample> cls_IntTools_CurveRangeSample(mod, "IntTools_CurveRangeSample", "class for range index management of curve");

// Constructors
cls_IntTools_CurveRangeSample.def(py::init<>());
cls_IntTools_CurveRangeSample.def(py::init<const Standard_Integer>(), py::arg("theIndex"));

// Fields

// Methods
// cls_IntTools_CurveRangeSample.def_static("operator new_", (void * (*)(size_t)) &IntTools_CurveRangeSample::operator new, "None", py::arg("theSize"));
// cls_IntTools_CurveRangeSample.def_static("operator delete_", (void (*)(void *)) &IntTools_CurveRangeSample::operator delete, "None", py::arg("theAddress"));
// cls_IntTools_CurveRangeSample.def_static("operator new[]_", (void * (*)(size_t)) &IntTools_CurveRangeSample::operator new[], "None", py::arg("theSize"));
// cls_IntTools_CurveRangeSample.def_static("operator delete[]_", (void (*)(void *)) &IntTools_CurveRangeSample::operator delete[], "None", py::arg("theAddress"));
// cls_IntTools_CurveRangeSample.def_static("operator new_", (void * (*)(size_t, void *)) &IntTools_CurveRangeSample::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntTools_CurveRangeSample.def_static("operator delete_", (void (*)(void *, void *)) &IntTools_CurveRangeSample::operator delete, "None", py::arg(""), py::arg(""));
cls_IntTools_CurveRangeSample.def("SetRangeIndex", (void (IntTools_CurveRangeSample::*)(const Standard_Integer)) &IntTools_CurveRangeSample::SetRangeIndex, "None", py::arg("theIndex"));
cls_IntTools_CurveRangeSample.def("GetRangeIndex", (Standard_Integer (IntTools_CurveRangeSample::*)() const) &IntTools_CurveRangeSample::GetRangeIndex, "None");
cls_IntTools_CurveRangeSample.def("IsEqual", (Standard_Boolean (IntTools_CurveRangeSample::*)(const IntTools_CurveRangeSample &) const) &IntTools_CurveRangeSample::IsEqual, "None", py::arg("Other"));
cls_IntTools_CurveRangeSample.def("GetRange", (IntTools_Range (IntTools_CurveRangeSample::*)(const Standard_Real, const Standard_Real, const Standard_Integer) const) &IntTools_CurveRangeSample::GetRange, "None", py::arg("theFirst"), py::arg("theLast"), py::arg("theNbSample"));
cls_IntTools_CurveRangeSample.def("GetRangeIndexDeeper", (Standard_Integer (IntTools_CurveRangeSample::*)(const Standard_Integer) const) &IntTools_CurveRangeSample::GetRangeIndexDeeper, "None", py::arg("theNbSample"));

// Enums

}