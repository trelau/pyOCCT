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
#include <StepElement_SurfaceElementProperty.hxx>
#include <StepData_StepWriter.hxx>
#include <Interface_EntityIterator.hxx>
#include <RWStepElement_RWSurfaceElementProperty.hxx>

void bind_RWStepElement_RWSurfaceElementProperty(py::module &mod){

py::class_<RWStepElement_RWSurfaceElementProperty, std::unique_ptr<RWStepElement_RWSurfaceElementProperty, Deleter<RWStepElement_RWSurfaceElementProperty>>> cls_RWStepElement_RWSurfaceElementProperty(mod, "RWStepElement_RWSurfaceElementProperty", "Read & Write tool for SurfaceElementProperty");

// Constructors
cls_RWStepElement_RWSurfaceElementProperty.def(py::init<>());

// Fields

// Methods
// cls_RWStepElement_RWSurfaceElementProperty.def_static("operator new_", (void * (*)(size_t)) &RWStepElement_RWSurfaceElementProperty::operator new, "None", py::arg("theSize"));
// cls_RWStepElement_RWSurfaceElementProperty.def_static("operator delete_", (void (*)(void *)) &RWStepElement_RWSurfaceElementProperty::operator delete, "None", py::arg("theAddress"));
// cls_RWStepElement_RWSurfaceElementProperty.def_static("operator new[]_", (void * (*)(size_t)) &RWStepElement_RWSurfaceElementProperty::operator new[], "None", py::arg("theSize"));
// cls_RWStepElement_RWSurfaceElementProperty.def_static("operator delete[]_", (void (*)(void *)) &RWStepElement_RWSurfaceElementProperty::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepElement_RWSurfaceElementProperty.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepElement_RWSurfaceElementProperty::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepElement_RWSurfaceElementProperty.def_static("operator delete_", (void (*)(void *, void *)) &RWStepElement_RWSurfaceElementProperty::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepElement_RWSurfaceElementProperty.def("ReadStep", (void (RWStepElement_RWSurfaceElementProperty::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepElement_SurfaceElementProperty> &) const) &RWStepElement_RWSurfaceElementProperty::ReadStep, "Reads SurfaceElementProperty", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepElement_RWSurfaceElementProperty.def("WriteStep", (void (RWStepElement_RWSurfaceElementProperty::*)(StepData_StepWriter &, const opencascade::handle<StepElement_SurfaceElementProperty> &) const) &RWStepElement_RWSurfaceElementProperty::WriteStep, "Writes SurfaceElementProperty", py::arg("SW"), py::arg("ent"));
cls_RWStepElement_RWSurfaceElementProperty.def("Share", (void (RWStepElement_RWSurfaceElementProperty::*)(const opencascade::handle<StepElement_SurfaceElementProperty> &, Interface_EntityIterator &) const) &RWStepElement_RWSurfaceElementProperty::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// Enums

}