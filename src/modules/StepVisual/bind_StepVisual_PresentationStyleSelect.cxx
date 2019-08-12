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
#include <StepVisual_PointStyle.hxx>
#include <StepVisual_CurveStyle.hxx>
#include <StepVisual_NullStyleMember.hxx>
#include <StepVisual_SurfaceStyleUsage.hxx>
#include <StepVisual_PresentationStyleSelect.hxx>

void bind_StepVisual_PresentationStyleSelect(py::module &mod){

py::class_<StepVisual_PresentationStyleSelect, std::unique_ptr<StepVisual_PresentationStyleSelect, Deleter<StepVisual_PresentationStyleSelect>>, StepData_SelectType> cls_StepVisual_PresentationStyleSelect(mod, "StepVisual_PresentationStyleSelect", "None");

// Constructors
cls_StepVisual_PresentationStyleSelect.def(py::init<>());

// Fields

// Methods
// cls_StepVisual_PresentationStyleSelect.def_static("operator new_", (void * (*)(size_t)) &StepVisual_PresentationStyleSelect::operator new, "None", py::arg("theSize"));
// cls_StepVisual_PresentationStyleSelect.def_static("operator delete_", (void (*)(void *)) &StepVisual_PresentationStyleSelect::operator delete, "None", py::arg("theAddress"));
// cls_StepVisual_PresentationStyleSelect.def_static("operator new[]_", (void * (*)(size_t)) &StepVisual_PresentationStyleSelect::operator new[], "None", py::arg("theSize"));
// cls_StepVisual_PresentationStyleSelect.def_static("operator delete[]_", (void (*)(void *)) &StepVisual_PresentationStyleSelect::operator delete[], "None", py::arg("theAddress"));
// cls_StepVisual_PresentationStyleSelect.def_static("operator new_", (void * (*)(size_t, void *)) &StepVisual_PresentationStyleSelect::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepVisual_PresentationStyleSelect.def_static("operator delete_", (void (*)(void *, void *)) &StepVisual_PresentationStyleSelect::operator delete, "None", py::arg(""), py::arg(""));
cls_StepVisual_PresentationStyleSelect.def("CaseNum", (Standard_Integer (StepVisual_PresentationStyleSelect::*)(const opencascade::handle<Standard_Transient> &) const) &StepVisual_PresentationStyleSelect::CaseNum, "Recognizes a PresentationStyleSelect Kind Entity that is : 1 -> PointStyle 2 -> CurveStyle 3 -> SurfaceStyleUsage 4 -> SymbolStyle 5 -> FillAreaStyle 6 -> TextStyle 7 -> NullStyle 0 else", py::arg("ent"));
cls_StepVisual_PresentationStyleSelect.def("PointStyle", (opencascade::handle<StepVisual_PointStyle> (StepVisual_PresentationStyleSelect::*)() const) &StepVisual_PresentationStyleSelect::PointStyle, "returns Value as a PointStyle (Null if another type)");
cls_StepVisual_PresentationStyleSelect.def("CurveStyle", (opencascade::handle<StepVisual_CurveStyle> (StepVisual_PresentationStyleSelect::*)() const) &StepVisual_PresentationStyleSelect::CurveStyle, "returns Value as a CurveStyle (Null if another type)");
cls_StepVisual_PresentationStyleSelect.def("NullStyle", (opencascade::handle<StepVisual_NullStyleMember> (StepVisual_PresentationStyleSelect::*)() const) &StepVisual_PresentationStyleSelect::NullStyle, "returns Value as a NullStyleMember (Null if another type)");
cls_StepVisual_PresentationStyleSelect.def("SurfaceStyleUsage", (opencascade::handle<StepVisual_SurfaceStyleUsage> (StepVisual_PresentationStyleSelect::*)() const) &StepVisual_PresentationStyleSelect::SurfaceStyleUsage, "returns Value as a SurfaceStyleUsage (Null if another type)");

// Enums

}