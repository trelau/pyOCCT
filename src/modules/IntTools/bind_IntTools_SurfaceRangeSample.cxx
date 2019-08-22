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
#include <IntTools_CurveRangeSample.hxx>
#include <IntTools_SurfaceRangeSample.hxx>
#include <IntTools_Range.hxx>

void bind_IntTools_SurfaceRangeSample(py::module &mod){

py::class_<IntTools_SurfaceRangeSample> cls_IntTools_SurfaceRangeSample(mod, "IntTools_SurfaceRangeSample", "class for range index management of surface");

// Constructors
cls_IntTools_SurfaceRangeSample.def(py::init<>());
cls_IntTools_SurfaceRangeSample.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theIndexU"), py::arg("theDepthU"), py::arg("theIndexV"), py::arg("theDepthV"));
cls_IntTools_SurfaceRangeSample.def(py::init<const IntTools_CurveRangeSample &, const IntTools_CurveRangeSample &>(), py::arg("theRangeU"), py::arg("theRangeV"));
cls_IntTools_SurfaceRangeSample.def(py::init<const IntTools_SurfaceRangeSample &>(), py::arg("Other"));

// Fields

// Methods
// cls_IntTools_SurfaceRangeSample.def_static("operator new_", (void * (*)(size_t)) &IntTools_SurfaceRangeSample::operator new, "None", py::arg("theSize"));
// cls_IntTools_SurfaceRangeSample.def_static("operator delete_", (void (*)(void *)) &IntTools_SurfaceRangeSample::operator delete, "None", py::arg("theAddress"));
// cls_IntTools_SurfaceRangeSample.def_static("operator new[]_", (void * (*)(size_t)) &IntTools_SurfaceRangeSample::operator new[], "None", py::arg("theSize"));
// cls_IntTools_SurfaceRangeSample.def_static("operator delete[]_", (void (*)(void *)) &IntTools_SurfaceRangeSample::operator delete[], "None", py::arg("theAddress"));
// cls_IntTools_SurfaceRangeSample.def_static("operator new_", (void * (*)(size_t, void *)) &IntTools_SurfaceRangeSample::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntTools_SurfaceRangeSample.def_static("operator delete_", (void (*)(void *, void *)) &IntTools_SurfaceRangeSample::operator delete, "None", py::arg(""), py::arg(""));
cls_IntTools_SurfaceRangeSample.def("Assign", (IntTools_SurfaceRangeSample & (IntTools_SurfaceRangeSample::*)(const IntTools_SurfaceRangeSample &)) &IntTools_SurfaceRangeSample::Assign, "None", py::arg("Other"));
// cls_IntTools_SurfaceRangeSample.def("operator=", (IntTools_SurfaceRangeSample & (IntTools_SurfaceRangeSample::*)(const IntTools_SurfaceRangeSample &)) &IntTools_SurfaceRangeSample::operator=, "None", py::arg("Other"));
cls_IntTools_SurfaceRangeSample.def("SetRanges", (void (IntTools_SurfaceRangeSample::*)(const IntTools_CurveRangeSample &, const IntTools_CurveRangeSample &)) &IntTools_SurfaceRangeSample::SetRanges, "None", py::arg("theRangeU"), py::arg("theRangeV"));
cls_IntTools_SurfaceRangeSample.def("GetRanges", (void (IntTools_SurfaceRangeSample::*)(IntTools_CurveRangeSample &, IntTools_CurveRangeSample &) const) &IntTools_SurfaceRangeSample::GetRanges, "None", py::arg("theRangeU"), py::arg("theRangeV"));
cls_IntTools_SurfaceRangeSample.def("SetIndexes", (void (IntTools_SurfaceRangeSample::*)(const Standard_Integer, const Standard_Integer)) &IntTools_SurfaceRangeSample::SetIndexes, "None", py::arg("theIndexU"), py::arg("theIndexV"));
cls_IntTools_SurfaceRangeSample.def("GetIndexes", [](IntTools_SurfaceRangeSample &self, Standard_Integer & theIndexU, Standard_Integer & theIndexV){ self.GetIndexes(theIndexU, theIndexV); return std::tuple<Standard_Integer &, Standard_Integer &>(theIndexU, theIndexV); }, "None", py::arg("theIndexU"), py::arg("theIndexV"));
cls_IntTools_SurfaceRangeSample.def("GetDepths", [](IntTools_SurfaceRangeSample &self, Standard_Integer & theDepthU, Standard_Integer & theDepthV){ self.GetDepths(theDepthU, theDepthV); return std::tuple<Standard_Integer &, Standard_Integer &>(theDepthU, theDepthV); }, "None", py::arg("theDepthU"), py::arg("theDepthV"));
cls_IntTools_SurfaceRangeSample.def("SetSampleRangeU", (void (IntTools_SurfaceRangeSample::*)(const IntTools_CurveRangeSample &)) &IntTools_SurfaceRangeSample::SetSampleRangeU, "None", py::arg("theRangeSampleU"));
cls_IntTools_SurfaceRangeSample.def("GetSampleRangeU", (const IntTools_CurveRangeSample & (IntTools_SurfaceRangeSample::*)() const) &IntTools_SurfaceRangeSample::GetSampleRangeU, "None");
cls_IntTools_SurfaceRangeSample.def("SetSampleRangeV", (void (IntTools_SurfaceRangeSample::*)(const IntTools_CurveRangeSample &)) &IntTools_SurfaceRangeSample::SetSampleRangeV, "None", py::arg("theRangeSampleV"));
cls_IntTools_SurfaceRangeSample.def("GetSampleRangeV", (const IntTools_CurveRangeSample & (IntTools_SurfaceRangeSample::*)() const) &IntTools_SurfaceRangeSample::GetSampleRangeV, "None");
cls_IntTools_SurfaceRangeSample.def("SetIndexU", (void (IntTools_SurfaceRangeSample::*)(const Standard_Integer)) &IntTools_SurfaceRangeSample::SetIndexU, "None", py::arg("theIndexU"));
cls_IntTools_SurfaceRangeSample.def("GetIndexU", (Standard_Integer (IntTools_SurfaceRangeSample::*)() const) &IntTools_SurfaceRangeSample::GetIndexU, "None");
cls_IntTools_SurfaceRangeSample.def("SetIndexV", (void (IntTools_SurfaceRangeSample::*)(const Standard_Integer)) &IntTools_SurfaceRangeSample::SetIndexV, "None", py::arg("theIndexV"));
cls_IntTools_SurfaceRangeSample.def("GetIndexV", (Standard_Integer (IntTools_SurfaceRangeSample::*)() const) &IntTools_SurfaceRangeSample::GetIndexV, "None");
cls_IntTools_SurfaceRangeSample.def("SetDepthU", (void (IntTools_SurfaceRangeSample::*)(const Standard_Integer)) &IntTools_SurfaceRangeSample::SetDepthU, "None", py::arg("theDepthU"));
cls_IntTools_SurfaceRangeSample.def("GetDepthU", (Standard_Integer (IntTools_SurfaceRangeSample::*)() const) &IntTools_SurfaceRangeSample::GetDepthU, "None");
cls_IntTools_SurfaceRangeSample.def("SetDepthV", (void (IntTools_SurfaceRangeSample::*)(const Standard_Integer)) &IntTools_SurfaceRangeSample::SetDepthV, "None", py::arg("theDepthV"));
cls_IntTools_SurfaceRangeSample.def("GetDepthV", (Standard_Integer (IntTools_SurfaceRangeSample::*)() const) &IntTools_SurfaceRangeSample::GetDepthV, "None");
cls_IntTools_SurfaceRangeSample.def("GetRangeU", (IntTools_Range (IntTools_SurfaceRangeSample::*)(const Standard_Real, const Standard_Real, const Standard_Integer) const) &IntTools_SurfaceRangeSample::GetRangeU, "None", py::arg("theFirstU"), py::arg("theLastU"), py::arg("theNbSampleU"));
cls_IntTools_SurfaceRangeSample.def("GetRangeV", (IntTools_Range (IntTools_SurfaceRangeSample::*)(const Standard_Real, const Standard_Real, const Standard_Integer) const) &IntTools_SurfaceRangeSample::GetRangeV, "None", py::arg("theFirstV"), py::arg("theLastV"), py::arg("theNbSampleV"));
cls_IntTools_SurfaceRangeSample.def("IsEqual", (Standard_Boolean (IntTools_SurfaceRangeSample::*)(const IntTools_SurfaceRangeSample &) const) &IntTools_SurfaceRangeSample::IsEqual, "None", py::arg("Other"));
cls_IntTools_SurfaceRangeSample.def("GetRangeIndexUDeeper", (Standard_Integer (IntTools_SurfaceRangeSample::*)(const Standard_Integer) const) &IntTools_SurfaceRangeSample::GetRangeIndexUDeeper, "None", py::arg("theNbSampleU"));
cls_IntTools_SurfaceRangeSample.def("GetRangeIndexVDeeper", (Standard_Integer (IntTools_SurfaceRangeSample::*)(const Standard_Integer) const) &IntTools_SurfaceRangeSample::GetRangeIndexVDeeper, "None", py::arg("theNbSampleV"));

// Enums

}