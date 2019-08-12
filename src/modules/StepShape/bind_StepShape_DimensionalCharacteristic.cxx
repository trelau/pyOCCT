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
#include <StepShape_DimensionalLocation.hxx>
#include <StepShape_DimensionalSize.hxx>
#include <StepShape_DimensionalCharacteristic.hxx>

void bind_StepShape_DimensionalCharacteristic(py::module &mod){

py::class_<StepShape_DimensionalCharacteristic, std::unique_ptr<StepShape_DimensionalCharacteristic, Deleter<StepShape_DimensionalCharacteristic>>, StepData_SelectType> cls_StepShape_DimensionalCharacteristic(mod, "StepShape_DimensionalCharacteristic", "Representation of STEP SELECT type DimensionalCharacteristic");

// Constructors
cls_StepShape_DimensionalCharacteristic.def(py::init<>());

// Fields

// Methods
// cls_StepShape_DimensionalCharacteristic.def_static("operator new_", (void * (*)(size_t)) &StepShape_DimensionalCharacteristic::operator new, "None", py::arg("theSize"));
// cls_StepShape_DimensionalCharacteristic.def_static("operator delete_", (void (*)(void *)) &StepShape_DimensionalCharacteristic::operator delete, "None", py::arg("theAddress"));
// cls_StepShape_DimensionalCharacteristic.def_static("operator new[]_", (void * (*)(size_t)) &StepShape_DimensionalCharacteristic::operator new[], "None", py::arg("theSize"));
// cls_StepShape_DimensionalCharacteristic.def_static("operator delete[]_", (void (*)(void *)) &StepShape_DimensionalCharacteristic::operator delete[], "None", py::arg("theAddress"));
// cls_StepShape_DimensionalCharacteristic.def_static("operator new_", (void * (*)(size_t, void *)) &StepShape_DimensionalCharacteristic::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepShape_DimensionalCharacteristic.def_static("operator delete_", (void (*)(void *, void *)) &StepShape_DimensionalCharacteristic::operator delete, "None", py::arg(""), py::arg(""));
cls_StepShape_DimensionalCharacteristic.def("CaseNum", (Standard_Integer (StepShape_DimensionalCharacteristic::*)(const opencascade::handle<Standard_Transient> &) const) &StepShape_DimensionalCharacteristic::CaseNum, "Recognizes a kind of DimensionalCharacteristic select type 1 -> DimensionalLocation from StepShape 2 -> DimensionalSize from StepShape 0 else", py::arg("ent"));
cls_StepShape_DimensionalCharacteristic.def("DimensionalLocation", (opencascade::handle<StepShape_DimensionalLocation> (StepShape_DimensionalCharacteristic::*)() const) &StepShape_DimensionalCharacteristic::DimensionalLocation, "Returns Value as DimensionalLocation (or Null if another type)");
cls_StepShape_DimensionalCharacteristic.def("DimensionalSize", (opencascade::handle<StepShape_DimensionalSize> (StepShape_DimensionalCharacteristic::*)() const) &StepShape_DimensionalCharacteristic::DimensionalSize, "Returns Value as DimensionalSize (or Null if another type)");

// Enums

}