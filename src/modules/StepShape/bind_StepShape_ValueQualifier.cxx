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
#include <StepShape_PrecisionQualifier.hxx>
#include <StepShape_TypeQualifier.hxx>
#include <StepShape_ValueFormatTypeQualifier.hxx>
#include <StepShape_ValueQualifier.hxx>

void bind_StepShape_ValueQualifier(py::module &mod){

py::class_<StepShape_ValueQualifier, std::unique_ptr<StepShape_ValueQualifier>, StepData_SelectType> cls_StepShape_ValueQualifier(mod, "StepShape_ValueQualifier", "Added for Dimensional Tolerances");

// Constructors
cls_StepShape_ValueQualifier.def(py::init<>());

// Fields

// Methods
// cls_StepShape_ValueQualifier.def_static("operator new_", (void * (*)(size_t)) &StepShape_ValueQualifier::operator new, "None", py::arg("theSize"));
// cls_StepShape_ValueQualifier.def_static("operator delete_", (void (*)(void *)) &StepShape_ValueQualifier::operator delete, "None", py::arg("theAddress"));
// cls_StepShape_ValueQualifier.def_static("operator new[]_", (void * (*)(size_t)) &StepShape_ValueQualifier::operator new[], "None", py::arg("theSize"));
// cls_StepShape_ValueQualifier.def_static("operator delete[]_", (void (*)(void *)) &StepShape_ValueQualifier::operator delete[], "None", py::arg("theAddress"));
// cls_StepShape_ValueQualifier.def_static("operator new_", (void * (*)(size_t, void *)) &StepShape_ValueQualifier::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepShape_ValueQualifier.def_static("operator delete_", (void (*)(void *, void *)) &StepShape_ValueQualifier::operator delete, "None", py::arg(""), py::arg(""));
cls_StepShape_ValueQualifier.def("CaseNum", (Standard_Integer (StepShape_ValueQualifier::*)(const opencascade::handle<Standard_Transient> &) const) &StepShape_ValueQualifier::CaseNum, "Recognizes a kind of ValueQualifier Select Type : 1 -> PrecisionQualifier from StepShape 2 -> TypeQualifier from StepShape 3 -> UnceraintyQualifier .. not yet implemented 4 -> ValueFormatTypeQualifier", py::arg("ent"));
cls_StepShape_ValueQualifier.def("PrecisionQualifier", (opencascade::handle<StepShape_PrecisionQualifier> (StepShape_ValueQualifier::*)() const) &StepShape_ValueQualifier::PrecisionQualifier, "Returns Value as PrecisionQualifier");
cls_StepShape_ValueQualifier.def("TypeQualifier", (opencascade::handle<StepShape_TypeQualifier> (StepShape_ValueQualifier::*)() const) &StepShape_ValueQualifier::TypeQualifier, "Returns Value as TypeQualifier");
cls_StepShape_ValueQualifier.def("ValueFormatTypeQualifier", (opencascade::handle<StepShape_ValueFormatTypeQualifier> (StepShape_ValueQualifier::*)() const) &StepShape_ValueQualifier::ValueFormatTypeQualifier, "Returns Value as ValueFormatTypeQualifier");

// Enums

}