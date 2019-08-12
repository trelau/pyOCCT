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
#include <StepData_SelectType.hxx>
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Transient.hxx>
#include <StepDimTol_Datum.hxx>
#include <StepDimTol_HArray1OfDatumReferenceElement.hxx>
#include <StepDimTol_DatumOrCommonDatum.hxx>

void bind_StepDimTol_DatumOrCommonDatum(py::module &mod){

py::class_<StepDimTol_DatumOrCommonDatum, std::unique_ptr<StepDimTol_DatumOrCommonDatum, Deleter<StepDimTol_DatumOrCommonDatum>>, StepData_SelectType> cls_StepDimTol_DatumOrCommonDatum(mod, "StepDimTol_DatumOrCommonDatum", "None");

// Constructors
cls_StepDimTol_DatumOrCommonDatum.def(py::init<>());

// Fields

// Methods
// cls_StepDimTol_DatumOrCommonDatum.def_static("operator new_", (void * (*)(size_t)) &StepDimTol_DatumOrCommonDatum::operator new, "None", py::arg("theSize"));
// cls_StepDimTol_DatumOrCommonDatum.def_static("operator delete_", (void (*)(void *)) &StepDimTol_DatumOrCommonDatum::operator delete, "None", py::arg("theAddress"));
// cls_StepDimTol_DatumOrCommonDatum.def_static("operator new[]_", (void * (*)(size_t)) &StepDimTol_DatumOrCommonDatum::operator new[], "None", py::arg("theSize"));
// cls_StepDimTol_DatumOrCommonDatum.def_static("operator delete[]_", (void (*)(void *)) &StepDimTol_DatumOrCommonDatum::operator delete[], "None", py::arg("theAddress"));
// cls_StepDimTol_DatumOrCommonDatum.def_static("operator new_", (void * (*)(size_t, void *)) &StepDimTol_DatumOrCommonDatum::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepDimTol_DatumOrCommonDatum.def_static("operator delete_", (void (*)(void *, void *)) &StepDimTol_DatumOrCommonDatum::operator delete, "None", py::arg(""), py::arg(""));
cls_StepDimTol_DatumOrCommonDatum.def("CaseNum", (Standard_Integer (StepDimTol_DatumOrCommonDatum::*)(const opencascade::handle<Standard_Transient> &) const) &StepDimTol_DatumOrCommonDatum::CaseNum, "Recognizes a DatumOrCommonDatum Kind Entity that is : 1 -> Datum 2 -> CommonDatumList 0 else", py::arg("ent"));
cls_StepDimTol_DatumOrCommonDatum.def("Datum", (opencascade::handle<StepDimTol_Datum> (StepDimTol_DatumOrCommonDatum::*)() const) &StepDimTol_DatumOrCommonDatum::Datum, "returns Value as a Datum (Null if another type)");
cls_StepDimTol_DatumOrCommonDatum.def("CommonDatumList", (opencascade::handle<StepDimTol_HArray1OfDatumReferenceElement> (StepDimTol_DatumOrCommonDatum::*)() const) &StepDimTol_DatumOrCommonDatum::CommonDatumList, "returns Value as a CommonDatumList (Null if another type)");

// Enums

}