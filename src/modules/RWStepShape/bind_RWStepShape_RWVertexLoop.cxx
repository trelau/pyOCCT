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
#include <StepShape_VertexLoop.hxx>
#include <StepData_StepWriter.hxx>
#include <Interface_EntityIterator.hxx>
#include <RWStepShape_RWVertexLoop.hxx>

void bind_RWStepShape_RWVertexLoop(py::module &mod){

py::class_<RWStepShape_RWVertexLoop, std::unique_ptr<RWStepShape_RWVertexLoop>> cls_RWStepShape_RWVertexLoop(mod, "RWStepShape_RWVertexLoop", "Read & Write Module for VertexLoop");

// Constructors
cls_RWStepShape_RWVertexLoop.def(py::init<>());

// Fields

// Methods
// cls_RWStepShape_RWVertexLoop.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWVertexLoop::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWVertexLoop.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWVertexLoop::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWVertexLoop.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWVertexLoop::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWVertexLoop.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWVertexLoop::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWVertexLoop.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWVertexLoop::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWVertexLoop.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWVertexLoop::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWVertexLoop.def("ReadStep", (void (RWStepShape_RWVertexLoop::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_VertexLoop> &) const) &RWStepShape_RWVertexLoop::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWVertexLoop.def("WriteStep", (void (RWStepShape_RWVertexLoop::*)(StepData_StepWriter &, const opencascade::handle<StepShape_VertexLoop> &) const) &RWStepShape_RWVertexLoop::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepShape_RWVertexLoop.def("Share", (void (RWStepShape_RWVertexLoop::*)(const opencascade::handle<StepShape_VertexLoop> &, Interface_EntityIterator &) const) &RWStepShape_RWVertexLoop::Share, "None", py::arg("ent"), py::arg("iter"));

// Enums

}