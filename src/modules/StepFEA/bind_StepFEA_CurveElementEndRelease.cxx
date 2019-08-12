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
#include <Standard_Transient.hxx>
#include <StepFEA_CurveElementEndCoordinateSystem.hxx>
#include <Standard_Handle.hxx>
#include <StepElement_HArray1OfCurveElementEndReleasePacket.hxx>
#include <StepFEA_CurveElementEndRelease.hxx>
#include <Standard_Type.hxx>

void bind_StepFEA_CurveElementEndRelease(py::module &mod){

py::class_<StepFEA_CurveElementEndRelease, opencascade::handle<StepFEA_CurveElementEndRelease>, Standard_Transient> cls_StepFEA_CurveElementEndRelease(mod, "StepFEA_CurveElementEndRelease", "Representation of STEP entity CurveElementEndRelease");

// Constructors
cls_StepFEA_CurveElementEndRelease.def(py::init<>());

// Fields

// Methods
cls_StepFEA_CurveElementEndRelease.def("Init", (void (StepFEA_CurveElementEndRelease::*)(const StepFEA_CurveElementEndCoordinateSystem &, const opencascade::handle<StepElement_HArray1OfCurveElementEndReleasePacket> &)) &StepFEA_CurveElementEndRelease::Init, "Initialize all fields (own and inherited)", py::arg("aCoordinateSystem"), py::arg("aReleases"));
cls_StepFEA_CurveElementEndRelease.def("CoordinateSystem", (StepFEA_CurveElementEndCoordinateSystem (StepFEA_CurveElementEndRelease::*)() const) &StepFEA_CurveElementEndRelease::CoordinateSystem, "Returns field CoordinateSystem");
cls_StepFEA_CurveElementEndRelease.def("SetCoordinateSystem", (void (StepFEA_CurveElementEndRelease::*)(const StepFEA_CurveElementEndCoordinateSystem &)) &StepFEA_CurveElementEndRelease::SetCoordinateSystem, "Set field CoordinateSystem", py::arg("CoordinateSystem"));
cls_StepFEA_CurveElementEndRelease.def("Releases", (opencascade::handle<StepElement_HArray1OfCurveElementEndReleasePacket> (StepFEA_CurveElementEndRelease::*)() const) &StepFEA_CurveElementEndRelease::Releases, "Returns field Releases");
cls_StepFEA_CurveElementEndRelease.def("SetReleases", (void (StepFEA_CurveElementEndRelease::*)(const opencascade::handle<StepElement_HArray1OfCurveElementEndReleasePacket> &)) &StepFEA_CurveElementEndRelease::SetReleases, "Set field Releases", py::arg("Releases"));
cls_StepFEA_CurveElementEndRelease.def_static("get_type_name_", (const char * (*)()) &StepFEA_CurveElementEndRelease::get_type_name, "None");
cls_StepFEA_CurveElementEndRelease.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_CurveElementEndRelease::get_type_descriptor, "None");
cls_StepFEA_CurveElementEndRelease.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_CurveElementEndRelease::*)() const) &StepFEA_CurveElementEndRelease::DynamicType, "None");

// Enums

}