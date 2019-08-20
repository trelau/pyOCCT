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
#include <StepRepr_Tangent.hxx>
#include <StepData_StepWriter.hxx>
#include <Interface_EntityIterator.hxx>
#include <RWStepRepr_RWTangent.hxx>

void bind_RWStepRepr_RWTangent(py::module &mod){

py::class_<RWStepRepr_RWTangent, std::unique_ptr<RWStepRepr_RWTangent>> cls_RWStepRepr_RWTangent(mod, "RWStepRepr_RWTangent", "Read & Write tool for Tangent");

// Constructors
cls_RWStepRepr_RWTangent.def(py::init<>());

// Fields

// Methods
// cls_RWStepRepr_RWTangent.def_static("operator new_", (void * (*)(size_t)) &RWStepRepr_RWTangent::operator new, "None", py::arg("theSize"));
// cls_RWStepRepr_RWTangent.def_static("operator delete_", (void (*)(void *)) &RWStepRepr_RWTangent::operator delete, "None", py::arg("theAddress"));
// cls_RWStepRepr_RWTangent.def_static("operator new[]_", (void * (*)(size_t)) &RWStepRepr_RWTangent::operator new[], "None", py::arg("theSize"));
// cls_RWStepRepr_RWTangent.def_static("operator delete[]_", (void (*)(void *)) &RWStepRepr_RWTangent::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepRepr_RWTangent.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepRepr_RWTangent::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepRepr_RWTangent.def_static("operator delete_", (void (*)(void *, void *)) &RWStepRepr_RWTangent::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepRepr_RWTangent.def("ReadStep", (void (RWStepRepr_RWTangent::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_Tangent> &) const) &RWStepRepr_RWTangent::ReadStep, "Reads Tangent", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepRepr_RWTangent.def("WriteStep", (void (RWStepRepr_RWTangent::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_Tangent> &) const) &RWStepRepr_RWTangent::WriteStep, "Writes Tangent", py::arg("SW"), py::arg("ent"));
cls_RWStepRepr_RWTangent.def("Share", (void (RWStepRepr_RWTangent::*)(const opencascade::handle<StepRepr_Tangent> &, Interface_EntityIterator &) const) &RWStepRepr_RWTangent::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// Enums

}