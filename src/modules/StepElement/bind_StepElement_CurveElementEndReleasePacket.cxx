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
#include <StepElement_CurveElementFreedom.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <StepElement_CurveElementEndReleasePacket.hxx>
#include <Standard_Type.hxx>

void bind_StepElement_CurveElementEndReleasePacket(py::module &mod){

py::class_<StepElement_CurveElementEndReleasePacket, opencascade::handle<StepElement_CurveElementEndReleasePacket>, Standard_Transient> cls_StepElement_CurveElementEndReleasePacket(mod, "StepElement_CurveElementEndReleasePacket", "Representation of STEP entity CurveElementEndReleasePacket");

// Constructors
cls_StepElement_CurveElementEndReleasePacket.def(py::init<>());

// Fields

// Methods
cls_StepElement_CurveElementEndReleasePacket.def("Init", (void (StepElement_CurveElementEndReleasePacket::*)(const StepElement_CurveElementFreedom &, const Standard_Real)) &StepElement_CurveElementEndReleasePacket::Init, "Initialize all fields (own and inherited)", py::arg("aReleaseFreedom"), py::arg("aReleaseStiffness"));
cls_StepElement_CurveElementEndReleasePacket.def("ReleaseFreedom", (StepElement_CurveElementFreedom (StepElement_CurveElementEndReleasePacket::*)() const) &StepElement_CurveElementEndReleasePacket::ReleaseFreedom, "Returns field ReleaseFreedom");
cls_StepElement_CurveElementEndReleasePacket.def("SetReleaseFreedom", (void (StepElement_CurveElementEndReleasePacket::*)(const StepElement_CurveElementFreedom &)) &StepElement_CurveElementEndReleasePacket::SetReleaseFreedom, "Set field ReleaseFreedom", py::arg("ReleaseFreedom"));
cls_StepElement_CurveElementEndReleasePacket.def("ReleaseStiffness", (Standard_Real (StepElement_CurveElementEndReleasePacket::*)() const) &StepElement_CurveElementEndReleasePacket::ReleaseStiffness, "Returns field ReleaseStiffness");
cls_StepElement_CurveElementEndReleasePacket.def("SetReleaseStiffness", (void (StepElement_CurveElementEndReleasePacket::*)(const Standard_Real)) &StepElement_CurveElementEndReleasePacket::SetReleaseStiffness, "Set field ReleaseStiffness", py::arg("ReleaseStiffness"));
cls_StepElement_CurveElementEndReleasePacket.def_static("get_type_name_", (const char * (*)()) &StepElement_CurveElementEndReleasePacket::get_type_name, "None");
cls_StepElement_CurveElementEndReleasePacket.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepElement_CurveElementEndReleasePacket::get_type_descriptor, "None");
cls_StepElement_CurveElementEndReleasePacket.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepElement_CurveElementEndReleasePacket::*)() const) &StepElement_CurveElementEndReleasePacket::DynamicType, "None");

// Enums

}