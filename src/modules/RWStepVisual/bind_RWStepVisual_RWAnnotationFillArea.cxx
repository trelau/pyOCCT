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
#include <StepData_StepReaderData.hxx>
#include <Standard_TypeDef.hxx>
#include <Interface_Check.hxx>
#include <StepVisual_AnnotationFillArea.hxx>
#include <StepData_StepWriter.hxx>
#include <Interface_EntityIterator.hxx>
#include <RWStepVisual_RWAnnotationFillArea.hxx>

void bind_RWStepVisual_RWAnnotationFillArea(py::module &mod){

py::class_<RWStepVisual_RWAnnotationFillArea, std::unique_ptr<RWStepVisual_RWAnnotationFillArea>> cls_RWStepVisual_RWAnnotationFillArea(mod, "RWStepVisual_RWAnnotationFillArea", "Read & Write Module for AnnotationFillArea");

// Constructors
cls_RWStepVisual_RWAnnotationFillArea.def(py::init<>());

// Fields

// Methods
// cls_RWStepVisual_RWAnnotationFillArea.def_static("operator new_", (void * (*)(size_t)) &RWStepVisual_RWAnnotationFillArea::operator new, "None", py::arg("theSize"));
// cls_RWStepVisual_RWAnnotationFillArea.def_static("operator delete_", (void (*)(void *)) &RWStepVisual_RWAnnotationFillArea::operator delete, "None", py::arg("theAddress"));
// cls_RWStepVisual_RWAnnotationFillArea.def_static("operator new[]_", (void * (*)(size_t)) &RWStepVisual_RWAnnotationFillArea::operator new[], "None", py::arg("theSize"));
// cls_RWStepVisual_RWAnnotationFillArea.def_static("operator delete[]_", (void (*)(void *)) &RWStepVisual_RWAnnotationFillArea::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepVisual_RWAnnotationFillArea.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepVisual_RWAnnotationFillArea::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepVisual_RWAnnotationFillArea.def_static("operator delete_", (void (*)(void *, void *)) &RWStepVisual_RWAnnotationFillArea::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepVisual_RWAnnotationFillArea.def("ReadStep", (void (RWStepVisual_RWAnnotationFillArea::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_AnnotationFillArea> &) const) &RWStepVisual_RWAnnotationFillArea::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepVisual_RWAnnotationFillArea.def("WriteStep", (void (RWStepVisual_RWAnnotationFillArea::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_AnnotationFillArea> &) const) &RWStepVisual_RWAnnotationFillArea::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepVisual_RWAnnotationFillArea.def("Share", (void (RWStepVisual_RWAnnotationFillArea::*)(const opencascade::handle<StepVisual_AnnotationFillArea> &, Interface_EntityIterator &) const) &RWStepVisual_RWAnnotationFillArea::Share, "None", py::arg("ent"), py::arg("iter"));

// Enums

}