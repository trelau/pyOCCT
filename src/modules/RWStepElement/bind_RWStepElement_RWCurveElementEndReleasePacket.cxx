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
#include <StepElement_CurveElementEndReleasePacket.hxx>
#include <StepData_StepWriter.hxx>
#include <Interface_EntityIterator.hxx>
#include <RWStepElement_RWCurveElementEndReleasePacket.hxx>

void bind_RWStepElement_RWCurveElementEndReleasePacket(py::module &mod){

py::class_<RWStepElement_RWCurveElementEndReleasePacket> cls_RWStepElement_RWCurveElementEndReleasePacket(mod, "RWStepElement_RWCurveElementEndReleasePacket", "Read & Write tool for CurveElementEndReleasePacket");

// Constructors
cls_RWStepElement_RWCurveElementEndReleasePacket.def(py::init<>());

// Fields

// Methods
// cls_RWStepElement_RWCurveElementEndReleasePacket.def_static("operator new_", (void * (*)(size_t)) &RWStepElement_RWCurveElementEndReleasePacket::operator new, "None", py::arg("theSize"));
// cls_RWStepElement_RWCurveElementEndReleasePacket.def_static("operator delete_", (void (*)(void *)) &RWStepElement_RWCurveElementEndReleasePacket::operator delete, "None", py::arg("theAddress"));
// cls_RWStepElement_RWCurveElementEndReleasePacket.def_static("operator new[]_", (void * (*)(size_t)) &RWStepElement_RWCurveElementEndReleasePacket::operator new[], "None", py::arg("theSize"));
// cls_RWStepElement_RWCurveElementEndReleasePacket.def_static("operator delete[]_", (void (*)(void *)) &RWStepElement_RWCurveElementEndReleasePacket::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepElement_RWCurveElementEndReleasePacket.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepElement_RWCurveElementEndReleasePacket::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepElement_RWCurveElementEndReleasePacket.def_static("operator delete_", (void (*)(void *, void *)) &RWStepElement_RWCurveElementEndReleasePacket::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepElement_RWCurveElementEndReleasePacket.def("ReadStep", (void (RWStepElement_RWCurveElementEndReleasePacket::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepElement_CurveElementEndReleasePacket> &) const) &RWStepElement_RWCurveElementEndReleasePacket::ReadStep, "Reads CurveElementEndReleasePacket", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepElement_RWCurveElementEndReleasePacket.def("WriteStep", (void (RWStepElement_RWCurveElementEndReleasePacket::*)(StepData_StepWriter &, const opencascade::handle<StepElement_CurveElementEndReleasePacket> &) const) &RWStepElement_RWCurveElementEndReleasePacket::WriteStep, "Writes CurveElementEndReleasePacket", py::arg("SW"), py::arg("ent"));
cls_RWStepElement_RWCurveElementEndReleasePacket.def("Share", (void (RWStepElement_RWCurveElementEndReleasePacket::*)(const opencascade::handle<StepElement_CurveElementEndReleasePacket> &, Interface_EntityIterator &) const) &RWStepElement_RWCurveElementEndReleasePacket::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// Enums

}