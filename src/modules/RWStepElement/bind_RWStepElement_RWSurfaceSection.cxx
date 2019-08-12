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
#include <StepElement_SurfaceSection.hxx>
#include <StepData_StepWriter.hxx>
#include <Interface_EntityIterator.hxx>
#include <RWStepElement_RWSurfaceSection.hxx>

void bind_RWStepElement_RWSurfaceSection(py::module &mod){

py::class_<RWStepElement_RWSurfaceSection, std::unique_ptr<RWStepElement_RWSurfaceSection, Deleter<RWStepElement_RWSurfaceSection>>> cls_RWStepElement_RWSurfaceSection(mod, "RWStepElement_RWSurfaceSection", "Read & Write tool for SurfaceSection");

// Constructors
cls_RWStepElement_RWSurfaceSection.def(py::init<>());

// Fields

// Methods
// cls_RWStepElement_RWSurfaceSection.def_static("operator new_", (void * (*)(size_t)) &RWStepElement_RWSurfaceSection::operator new, "None", py::arg("theSize"));
// cls_RWStepElement_RWSurfaceSection.def_static("operator delete_", (void (*)(void *)) &RWStepElement_RWSurfaceSection::operator delete, "None", py::arg("theAddress"));
// cls_RWStepElement_RWSurfaceSection.def_static("operator new[]_", (void * (*)(size_t)) &RWStepElement_RWSurfaceSection::operator new[], "None", py::arg("theSize"));
// cls_RWStepElement_RWSurfaceSection.def_static("operator delete[]_", (void (*)(void *)) &RWStepElement_RWSurfaceSection::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepElement_RWSurfaceSection.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepElement_RWSurfaceSection::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepElement_RWSurfaceSection.def_static("operator delete_", (void (*)(void *, void *)) &RWStepElement_RWSurfaceSection::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepElement_RWSurfaceSection.def("ReadStep", (void (RWStepElement_RWSurfaceSection::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepElement_SurfaceSection> &) const) &RWStepElement_RWSurfaceSection::ReadStep, "Reads SurfaceSection", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepElement_RWSurfaceSection.def("WriteStep", (void (RWStepElement_RWSurfaceSection::*)(StepData_StepWriter &, const opencascade::handle<StepElement_SurfaceSection> &) const) &RWStepElement_RWSurfaceSection::WriteStep, "Writes SurfaceSection", py::arg("SW"), py::arg("ent"));
cls_RWStepElement_RWSurfaceSection.def("Share", (void (RWStepElement_RWSurfaceSection::*)(const opencascade::handle<StepElement_SurfaceSection> &, Interface_EntityIterator &) const) &RWStepElement_RWSurfaceSection::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// Enums

}