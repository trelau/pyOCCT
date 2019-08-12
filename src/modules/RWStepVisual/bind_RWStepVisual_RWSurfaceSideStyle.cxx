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
#include <StepVisual_SurfaceSideStyle.hxx>
#include <StepData_StepWriter.hxx>
#include <Interface_EntityIterator.hxx>
#include <RWStepVisual_RWSurfaceSideStyle.hxx>

void bind_RWStepVisual_RWSurfaceSideStyle(py::module &mod){

py::class_<RWStepVisual_RWSurfaceSideStyle, std::unique_ptr<RWStepVisual_RWSurfaceSideStyle, Deleter<RWStepVisual_RWSurfaceSideStyle>>> cls_RWStepVisual_RWSurfaceSideStyle(mod, "RWStepVisual_RWSurfaceSideStyle", "Read & Write Module for SurfaceSideStyle");

// Constructors
cls_RWStepVisual_RWSurfaceSideStyle.def(py::init<>());

// Fields

// Methods
// cls_RWStepVisual_RWSurfaceSideStyle.def_static("operator new_", (void * (*)(size_t)) &RWStepVisual_RWSurfaceSideStyle::operator new, "None", py::arg("theSize"));
// cls_RWStepVisual_RWSurfaceSideStyle.def_static("operator delete_", (void (*)(void *)) &RWStepVisual_RWSurfaceSideStyle::operator delete, "None", py::arg("theAddress"));
// cls_RWStepVisual_RWSurfaceSideStyle.def_static("operator new[]_", (void * (*)(size_t)) &RWStepVisual_RWSurfaceSideStyle::operator new[], "None", py::arg("theSize"));
// cls_RWStepVisual_RWSurfaceSideStyle.def_static("operator delete[]_", (void (*)(void *)) &RWStepVisual_RWSurfaceSideStyle::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepVisual_RWSurfaceSideStyle.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepVisual_RWSurfaceSideStyle::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepVisual_RWSurfaceSideStyle.def_static("operator delete_", (void (*)(void *, void *)) &RWStepVisual_RWSurfaceSideStyle::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepVisual_RWSurfaceSideStyle.def("ReadStep", (void (RWStepVisual_RWSurfaceSideStyle::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepVisual_SurfaceSideStyle> &) const) &RWStepVisual_RWSurfaceSideStyle::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepVisual_RWSurfaceSideStyle.def("WriteStep", (void (RWStepVisual_RWSurfaceSideStyle::*)(StepData_StepWriter &, const opencascade::handle<StepVisual_SurfaceSideStyle> &) const) &RWStepVisual_RWSurfaceSideStyle::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepVisual_RWSurfaceSideStyle.def("Share", (void (RWStepVisual_RWSurfaceSideStyle::*)(const opencascade::handle<StepVisual_SurfaceSideStyle> &, Interface_EntityIterator &) const) &RWStepVisual_RWSurfaceSideStyle::Share, "None", py::arg("ent"), py::arg("iter"));

// Enums

}