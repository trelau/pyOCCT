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
#include <Bnd_Box.hxx>
#include <IntTools_ListOfCurveRangeSample.hxx>
#include <IntTools_MapOfCurveSample.hxx>
#include <IntTools_DataMapOfCurveSampleBox.hxx>
#include <IntTools_CurveRangeLocalizeData.hxx>

void bind_IntTools_CurveRangeLocalizeData(py::module &mod){

py::class_<IntTools_CurveRangeLocalizeData, std::unique_ptr<IntTools_CurveRangeLocalizeData, Deleter<IntTools_CurveRangeLocalizeData>>> cls_IntTools_CurveRangeLocalizeData(mod, "IntTools_CurveRangeLocalizeData", "None");

// Constructors
cls_IntTools_CurveRangeLocalizeData.def(py::init<const Standard_Integer, const Standard_Real>(), py::arg("theNbSample"), py::arg("theMinRange"));

// Fields

// Methods
// cls_IntTools_CurveRangeLocalizeData.def_static("operator new_", (void * (*)(size_t)) &IntTools_CurveRangeLocalizeData::operator new, "None", py::arg("theSize"));
// cls_IntTools_CurveRangeLocalizeData.def_static("operator delete_", (void (*)(void *)) &IntTools_CurveRangeLocalizeData::operator delete, "None", py::arg("theAddress"));
// cls_IntTools_CurveRangeLocalizeData.def_static("operator new[]_", (void * (*)(size_t)) &IntTools_CurveRangeLocalizeData::operator new[], "None", py::arg("theSize"));
// cls_IntTools_CurveRangeLocalizeData.def_static("operator delete[]_", (void (*)(void *)) &IntTools_CurveRangeLocalizeData::operator delete[], "None", py::arg("theAddress"));
// cls_IntTools_CurveRangeLocalizeData.def_static("operator new_", (void * (*)(size_t, void *)) &IntTools_CurveRangeLocalizeData::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntTools_CurveRangeLocalizeData.def_static("operator delete_", (void (*)(void *, void *)) &IntTools_CurveRangeLocalizeData::operator delete, "None", py::arg(""), py::arg(""));
cls_IntTools_CurveRangeLocalizeData.def("GetNbSample", (Standard_Integer (IntTools_CurveRangeLocalizeData::*)() const) &IntTools_CurveRangeLocalizeData::GetNbSample, "None");
cls_IntTools_CurveRangeLocalizeData.def("GetMinRange", (Standard_Real (IntTools_CurveRangeLocalizeData::*)() const) &IntTools_CurveRangeLocalizeData::GetMinRange, "None");
cls_IntTools_CurveRangeLocalizeData.def("AddOutRange", (void (IntTools_CurveRangeLocalizeData::*)(const IntTools_CurveRangeSample &)) &IntTools_CurveRangeLocalizeData::AddOutRange, "None", py::arg("theRange"));
cls_IntTools_CurveRangeLocalizeData.def("AddBox", (void (IntTools_CurveRangeLocalizeData::*)(const IntTools_CurveRangeSample &, const Bnd_Box &)) &IntTools_CurveRangeLocalizeData::AddBox, "None", py::arg("theRange"), py::arg("theBox"));
cls_IntTools_CurveRangeLocalizeData.def("FindBox", (Standard_Boolean (IntTools_CurveRangeLocalizeData::*)(const IntTools_CurveRangeSample &, Bnd_Box &) const) &IntTools_CurveRangeLocalizeData::FindBox, "None", py::arg("theRange"), py::arg("theBox"));
cls_IntTools_CurveRangeLocalizeData.def("IsRangeOut", (Standard_Boolean (IntTools_CurveRangeLocalizeData::*)(const IntTools_CurveRangeSample &) const) &IntTools_CurveRangeLocalizeData::IsRangeOut, "None", py::arg("theRange"));
cls_IntTools_CurveRangeLocalizeData.def("ListRangeOut", (void (IntTools_CurveRangeLocalizeData::*)(IntTools_ListOfCurveRangeSample &) const) &IntTools_CurveRangeLocalizeData::ListRangeOut, "None", py::arg("theList"));

// Enums

}