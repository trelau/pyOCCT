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
#include <StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMod.hxx>
#include <StepData_StepWriter.hxx>
#include <Interface_EntityIterator.hxx>
#include <RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndGeoTolWthMod.hxx>

void bind_RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndGeoTolWthMod(py::module &mod){

py::class_<RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndGeoTolWthMod, std::unique_ptr<RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndGeoTolWthMod>> cls_RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndGeoTolWthMod(mod, "RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndGeoTolWthMod", "Read & Write Module for GeoTolAndGeoTolWthDatRefAndGeoTolWthMod");

// Constructors
cls_RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndGeoTolWthMod.def(py::init<>());

// Fields

// Methods
// cls_RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndGeoTolWthMod.def_static("operator new_", (void * (*)(size_t)) &RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndGeoTolWthMod::operator new, "None", py::arg("theSize"));
// cls_RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndGeoTolWthMod.def_static("operator delete_", (void (*)(void *)) &RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndGeoTolWthMod::operator delete, "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndGeoTolWthMod.def_static("operator new[]_", (void * (*)(size_t)) &RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndGeoTolWthMod::operator new[], "None", py::arg("theSize"));
// cls_RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndGeoTolWthMod.def_static("operator delete[]_", (void (*)(void *)) &RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndGeoTolWthMod::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndGeoTolWthMod.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndGeoTolWthMod::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndGeoTolWthMod.def_static("operator delete_", (void (*)(void *, void *)) &RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndGeoTolWthMod::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndGeoTolWthMod.def("ReadStep", (void (RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndGeoTolWthMod::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMod> &) const) &RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndGeoTolWthMod::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndGeoTolWthMod.def("WriteStep", (void (RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndGeoTolWthMod::*)(StepData_StepWriter &, const opencascade::handle<StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMod> &) const) &RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndGeoTolWthMod::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndGeoTolWthMod.def("Share", (void (RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndGeoTolWthMod::*)(const opencascade::handle<StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMod> &, Interface_EntityIterator &) const) &RWStepDimTol_RWGeoTolAndGeoTolWthDatRefAndGeoTolWthMod::Share, "None", py::arg("ent"), py::arg("iter"));

// Enums

}