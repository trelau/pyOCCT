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
#include <StepDimTol_CylindricityTolerance.hxx>
#include <StepData_StepWriter.hxx>
#include <Interface_EntityIterator.hxx>
#include <RWStepDimTol_RWCylindricityTolerance.hxx>

void bind_RWStepDimTol_RWCylindricityTolerance(py::module &mod){

py::class_<RWStepDimTol_RWCylindricityTolerance, std::unique_ptr<RWStepDimTol_RWCylindricityTolerance, Deleter<RWStepDimTol_RWCylindricityTolerance>>> cls_RWStepDimTol_RWCylindricityTolerance(mod, "RWStepDimTol_RWCylindricityTolerance", "Read & Write tool for CylindricityTolerance");

// Constructors
cls_RWStepDimTol_RWCylindricityTolerance.def(py::init<>());

// Fields

// Methods
// cls_RWStepDimTol_RWCylindricityTolerance.def_static("operator new_", (void * (*)(size_t)) &RWStepDimTol_RWCylindricityTolerance::operator new, "None", py::arg("theSize"));
// cls_RWStepDimTol_RWCylindricityTolerance.def_static("operator delete_", (void (*)(void *)) &RWStepDimTol_RWCylindricityTolerance::operator delete, "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWCylindricityTolerance.def_static("operator new[]_", (void * (*)(size_t)) &RWStepDimTol_RWCylindricityTolerance::operator new[], "None", py::arg("theSize"));
// cls_RWStepDimTol_RWCylindricityTolerance.def_static("operator delete[]_", (void (*)(void *)) &RWStepDimTol_RWCylindricityTolerance::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWCylindricityTolerance.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepDimTol_RWCylindricityTolerance::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepDimTol_RWCylindricityTolerance.def_static("operator delete_", (void (*)(void *, void *)) &RWStepDimTol_RWCylindricityTolerance::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepDimTol_RWCylindricityTolerance.def("ReadStep", (void (RWStepDimTol_RWCylindricityTolerance::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepDimTol_CylindricityTolerance> &) const) &RWStepDimTol_RWCylindricityTolerance::ReadStep, "Reads CylindricityTolerance", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepDimTol_RWCylindricityTolerance.def("WriteStep", (void (RWStepDimTol_RWCylindricityTolerance::*)(StepData_StepWriter &, const opencascade::handle<StepDimTol_CylindricityTolerance> &) const) &RWStepDimTol_RWCylindricityTolerance::WriteStep, "Writes CylindricityTolerance", py::arg("SW"), py::arg("ent"));
cls_RWStepDimTol_RWCylindricityTolerance.def("Share", (void (RWStepDimTol_RWCylindricityTolerance::*)(const opencascade::handle<StepDimTol_CylindricityTolerance> &, Interface_EntityIterator &) const) &RWStepDimTol_RWCylindricityTolerance::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// Enums

}