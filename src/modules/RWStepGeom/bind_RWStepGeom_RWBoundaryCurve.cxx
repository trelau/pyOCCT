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
#include <StepGeom_BoundaryCurve.hxx>
#include <StepData_StepWriter.hxx>
#include <Interface_EntityIterator.hxx>
#include <RWStepGeom_RWBoundaryCurve.hxx>

void bind_RWStepGeom_RWBoundaryCurve(py::module &mod){

py::class_<RWStepGeom_RWBoundaryCurve> cls_RWStepGeom_RWBoundaryCurve(mod, "RWStepGeom_RWBoundaryCurve", "Read & Write Module for BoundaryCurve");

// Constructors
cls_RWStepGeom_RWBoundaryCurve.def(py::init<>());

// Fields

// Methods
// cls_RWStepGeom_RWBoundaryCurve.def_static("operator new_", (void * (*)(size_t)) &RWStepGeom_RWBoundaryCurve::operator new, "None", py::arg("theSize"));
// cls_RWStepGeom_RWBoundaryCurve.def_static("operator delete_", (void (*)(void *)) &RWStepGeom_RWBoundaryCurve::operator delete, "None", py::arg("theAddress"));
// cls_RWStepGeom_RWBoundaryCurve.def_static("operator new[]_", (void * (*)(size_t)) &RWStepGeom_RWBoundaryCurve::operator new[], "None", py::arg("theSize"));
// cls_RWStepGeom_RWBoundaryCurve.def_static("operator delete[]_", (void (*)(void *)) &RWStepGeom_RWBoundaryCurve::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepGeom_RWBoundaryCurve.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepGeom_RWBoundaryCurve::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepGeom_RWBoundaryCurve.def_static("operator delete_", (void (*)(void *, void *)) &RWStepGeom_RWBoundaryCurve::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepGeom_RWBoundaryCurve.def("ReadStep", (void (RWStepGeom_RWBoundaryCurve::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepGeom_BoundaryCurve> &) const) &RWStepGeom_RWBoundaryCurve::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepGeom_RWBoundaryCurve.def("WriteStep", (void (RWStepGeom_RWBoundaryCurve::*)(StepData_StepWriter &, const opencascade::handle<StepGeom_BoundaryCurve> &) const) &RWStepGeom_RWBoundaryCurve::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepGeom_RWBoundaryCurve.def("Share", (void (RWStepGeom_RWBoundaryCurve::*)(const opencascade::handle<StepGeom_BoundaryCurve> &, Interface_EntityIterator &) const) &RWStepGeom_RWBoundaryCurve::Share, "None", py::arg("ent"), py::arg("iter"));

// Enums

}