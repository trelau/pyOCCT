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
#include <StepShape_FaceBound.hxx>
#include <StepData_StepWriter.hxx>
#include <Interface_EntityIterator.hxx>
#include <Interface_ShareTool.hxx>
#include <RWStepShape_RWFaceBound.hxx>

void bind_RWStepShape_RWFaceBound(py::module &mod){

py::class_<RWStepShape_RWFaceBound, std::unique_ptr<RWStepShape_RWFaceBound>> cls_RWStepShape_RWFaceBound(mod, "RWStepShape_RWFaceBound", "Read & Write Module for FaceBound Check added by CKY , 7-OCT-1996");

// Constructors
cls_RWStepShape_RWFaceBound.def(py::init<>());

// Fields

// Methods
// cls_RWStepShape_RWFaceBound.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWFaceBound::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWFaceBound.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWFaceBound::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWFaceBound.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWFaceBound::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWFaceBound.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWFaceBound::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWFaceBound.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWFaceBound::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWFaceBound.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWFaceBound::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWFaceBound.def("ReadStep", (void (RWStepShape_RWFaceBound::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_FaceBound> &) const) &RWStepShape_RWFaceBound::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWFaceBound.def("WriteStep", (void (RWStepShape_RWFaceBound::*)(StepData_StepWriter &, const opencascade::handle<StepShape_FaceBound> &) const) &RWStepShape_RWFaceBound::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepShape_RWFaceBound.def("Share", (void (RWStepShape_RWFaceBound::*)(const opencascade::handle<StepShape_FaceBound> &, Interface_EntityIterator &) const) &RWStepShape_RWFaceBound::Share, "None", py::arg("ent"), py::arg("iter"));
cls_RWStepShape_RWFaceBound.def("Check", (void (RWStepShape_RWFaceBound::*)(const opencascade::handle<StepShape_FaceBound> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const) &RWStepShape_RWFaceBound::Check, "None", py::arg("ent"), py::arg("shares"), py::arg("ach"));

// Enums

}