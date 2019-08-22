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
#include <StepRepr_ConfigurationEffectivity.hxx>
#include <StepData_StepWriter.hxx>
#include <Interface_EntityIterator.hxx>
#include <RWStepRepr_RWConfigurationEffectivity.hxx>

void bind_RWStepRepr_RWConfigurationEffectivity(py::module &mod){

py::class_<RWStepRepr_RWConfigurationEffectivity> cls_RWStepRepr_RWConfigurationEffectivity(mod, "RWStepRepr_RWConfigurationEffectivity", "Read & Write tool for ConfigurationEffectivity");

// Constructors
cls_RWStepRepr_RWConfigurationEffectivity.def(py::init<>());

// Fields

// Methods
// cls_RWStepRepr_RWConfigurationEffectivity.def_static("operator new_", (void * (*)(size_t)) &RWStepRepr_RWConfigurationEffectivity::operator new, "None", py::arg("theSize"));
// cls_RWStepRepr_RWConfigurationEffectivity.def_static("operator delete_", (void (*)(void *)) &RWStepRepr_RWConfigurationEffectivity::operator delete, "None", py::arg("theAddress"));
// cls_RWStepRepr_RWConfigurationEffectivity.def_static("operator new[]_", (void * (*)(size_t)) &RWStepRepr_RWConfigurationEffectivity::operator new[], "None", py::arg("theSize"));
// cls_RWStepRepr_RWConfigurationEffectivity.def_static("operator delete[]_", (void (*)(void *)) &RWStepRepr_RWConfigurationEffectivity::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepRepr_RWConfigurationEffectivity.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepRepr_RWConfigurationEffectivity::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepRepr_RWConfigurationEffectivity.def_static("operator delete_", (void (*)(void *, void *)) &RWStepRepr_RWConfigurationEffectivity::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepRepr_RWConfigurationEffectivity.def("ReadStep", (void (RWStepRepr_RWConfigurationEffectivity::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_ConfigurationEffectivity> &) const) &RWStepRepr_RWConfigurationEffectivity::ReadStep, "Reads ConfigurationEffectivity", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepRepr_RWConfigurationEffectivity.def("WriteStep", (void (RWStepRepr_RWConfigurationEffectivity::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_ConfigurationEffectivity> &) const) &RWStepRepr_RWConfigurationEffectivity::WriteStep, "Writes ConfigurationEffectivity", py::arg("SW"), py::arg("ent"));
cls_RWStepRepr_RWConfigurationEffectivity.def("Share", (void (RWStepRepr_RWConfigurationEffectivity::*)(const opencascade::handle<StepRepr_ConfigurationEffectivity> &, Interface_EntityIterator &) const) &RWStepRepr_RWConfigurationEffectivity::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// Enums

}