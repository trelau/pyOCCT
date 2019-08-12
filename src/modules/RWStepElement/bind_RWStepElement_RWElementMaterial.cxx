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
#include <StepElement_ElementMaterial.hxx>
#include <StepData_StepWriter.hxx>
#include <Interface_EntityIterator.hxx>
#include <RWStepElement_RWElementMaterial.hxx>

void bind_RWStepElement_RWElementMaterial(py::module &mod){

py::class_<RWStepElement_RWElementMaterial, std::unique_ptr<RWStepElement_RWElementMaterial, Deleter<RWStepElement_RWElementMaterial>>> cls_RWStepElement_RWElementMaterial(mod, "RWStepElement_RWElementMaterial", "Read & Write tool for ElementMaterial");

// Constructors
cls_RWStepElement_RWElementMaterial.def(py::init<>());

// Fields

// Methods
// cls_RWStepElement_RWElementMaterial.def_static("operator new_", (void * (*)(size_t)) &RWStepElement_RWElementMaterial::operator new, "None", py::arg("theSize"));
// cls_RWStepElement_RWElementMaterial.def_static("operator delete_", (void (*)(void *)) &RWStepElement_RWElementMaterial::operator delete, "None", py::arg("theAddress"));
// cls_RWStepElement_RWElementMaterial.def_static("operator new[]_", (void * (*)(size_t)) &RWStepElement_RWElementMaterial::operator new[], "None", py::arg("theSize"));
// cls_RWStepElement_RWElementMaterial.def_static("operator delete[]_", (void (*)(void *)) &RWStepElement_RWElementMaterial::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepElement_RWElementMaterial.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepElement_RWElementMaterial::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepElement_RWElementMaterial.def_static("operator delete_", (void (*)(void *, void *)) &RWStepElement_RWElementMaterial::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepElement_RWElementMaterial.def("ReadStep", (void (RWStepElement_RWElementMaterial::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepElement_ElementMaterial> &) const) &RWStepElement_RWElementMaterial::ReadStep, "Reads ElementMaterial", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepElement_RWElementMaterial.def("WriteStep", (void (RWStepElement_RWElementMaterial::*)(StepData_StepWriter &, const opencascade::handle<StepElement_ElementMaterial> &) const) &RWStepElement_RWElementMaterial::WriteStep, "Writes ElementMaterial", py::arg("SW"), py::arg("ent"));
cls_RWStepElement_RWElementMaterial.def("Share", (void (RWStepElement_RWElementMaterial::*)(const opencascade::handle<StepElement_ElementMaterial> &, Interface_EntityIterator &) const) &RWStepElement_RWElementMaterial::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// Enums

}