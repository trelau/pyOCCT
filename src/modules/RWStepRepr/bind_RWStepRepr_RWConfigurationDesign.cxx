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
#include <StepRepr_ConfigurationDesign.hxx>
#include <StepData_StepWriter.hxx>
#include <Interface_EntityIterator.hxx>
#include <RWStepRepr_RWConfigurationDesign.hxx>

void bind_RWStepRepr_RWConfigurationDesign(py::module &mod){

py::class_<RWStepRepr_RWConfigurationDesign, std::unique_ptr<RWStepRepr_RWConfigurationDesign, Deleter<RWStepRepr_RWConfigurationDesign>>> cls_RWStepRepr_RWConfigurationDesign(mod, "RWStepRepr_RWConfigurationDesign", "Read & Write tool for ConfigurationDesign");

// Constructors
cls_RWStepRepr_RWConfigurationDesign.def(py::init<>());

// Fields

// Methods
// cls_RWStepRepr_RWConfigurationDesign.def_static("operator new_", (void * (*)(size_t)) &RWStepRepr_RWConfigurationDesign::operator new, "None", py::arg("theSize"));
// cls_RWStepRepr_RWConfigurationDesign.def_static("operator delete_", (void (*)(void *)) &RWStepRepr_RWConfigurationDesign::operator delete, "None", py::arg("theAddress"));
// cls_RWStepRepr_RWConfigurationDesign.def_static("operator new[]_", (void * (*)(size_t)) &RWStepRepr_RWConfigurationDesign::operator new[], "None", py::arg("theSize"));
// cls_RWStepRepr_RWConfigurationDesign.def_static("operator delete[]_", (void (*)(void *)) &RWStepRepr_RWConfigurationDesign::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepRepr_RWConfigurationDesign.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepRepr_RWConfigurationDesign::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepRepr_RWConfigurationDesign.def_static("operator delete_", (void (*)(void *, void *)) &RWStepRepr_RWConfigurationDesign::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepRepr_RWConfigurationDesign.def("ReadStep", (void (RWStepRepr_RWConfigurationDesign::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_ConfigurationDesign> &) const) &RWStepRepr_RWConfigurationDesign::ReadStep, "Reads ConfigurationDesign", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepRepr_RWConfigurationDesign.def("WriteStep", (void (RWStepRepr_RWConfigurationDesign::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_ConfigurationDesign> &) const) &RWStepRepr_RWConfigurationDesign::WriteStep, "Writes ConfigurationDesign", py::arg("SW"), py::arg("ent"));
cls_RWStepRepr_RWConfigurationDesign.def("Share", (void (RWStepRepr_RWConfigurationDesign::*)(const opencascade::handle<StepRepr_ConfigurationDesign> &, Interface_EntityIterator &) const) &RWStepRepr_RWConfigurationDesign::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// Enums

}